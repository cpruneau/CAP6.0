/* **********************************************************************
 * Copyright (C) 2019-2022, Claude Pruneau
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2022
 *
 * *********************************************************************/
#include "MeasurementSimulator.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "TRandom.h"

ClassImp(CAP::MeasurementSimulator);

namespace CAP
{

MeasurementSimulator::MeasurementSimulator()
:
EventTask(),
resolutionOption(0),
efficiencyOption(0)
{
  appendClassName("MeasurementSimulator");
  setName("MeasurementSimulator");
  setTitle("MeasurementSimulator");
  setVersion("1.0");
}

void MeasurementSimulator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("ResolutionOption",  resolutionOption);
  addProperty("EfficiencyOption",  efficiencyOption);
}

void MeasurementSimulator::configure()
{
  EventTask::configure();
}


void MeasurementSimulator::initialize()
{
  EventTask::initialize();
  clearSets();
  addSet("Performance");
  resolutionOption = getValueInt("ResolutionOption");
  efficiencyOption = getValueInt("EfficiencyOption");
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printString("Initiating task with");
    printValue("nEventFilters",eventFilters.size());
    printValue("nParticleFilters",particleFilters.size());
    printValue("resolutionOption",resolutionOption);
    printValue("efficiencyOption",efficiencyOption);
    }
  createSmearers();
}

void MeasurementSimulator::createSmearers()
{
  String bn  = getName();
  String pfn = particleFilters[0]->getName();
  ParticleSimulator *sim = new ParticleSimulator();
  sim->setName(createName(bn,pfn));
  sim->setConfiguration(configuration);
  sim->setParentTask(this);
  // bug sim->initialize();
  addGroupInSet(0,sim);
}

void MeasurementSimulator::execute()
{
  Event & genEvent  = *Manager<Event>::getObjectAt(0);
  Event & recoEvent = *Manager<Event>::getObjectAt(1);
  std::vector<Particle*> & genParticles = genEvent.getParticles();
  std::vector<Particle*> & recoParticles = recoEvent.getParticles();
  if (!analyzeThisEvent(genEvent,eventFilters,eventFilterAccepted)) return;
  unsigned long nPartGen   = genParticles.size();
  unsigned long nPartReco  = recoParticles.size();
  if (nPartReco>nPartGen) throw Exception("nPartReco>nPartGen",__FUNCTION__);
  LorentzVector recoMomentum;
  ParticleSimulator & simulator = (ParticleSimulator &) getGroupAt(0,0);
  for (auto & genParticle : genParticles)
    {
    bool accept = false;
    for (auto & particleFilter : particleFilters)
      {
      if (particleFilter->accept(*genParticle))
        {
        accept = true;
        break;
        }
      }
    if (!accept) continue; // generator level not accepted.
    LorentzVector & genMomentum = genParticle->getMomentum();
    if (simulator.accept(genMomentum))
      {
      ParticleType * type = genParticle->getTypePtr();
      LorentzVector & genPosition = genParticle->getPosition();
      simulator.smearMomentum(genMomentum,recoMomentum);
      Particle * recoParticle = particleFactory->getNextObject();
      recoParticle->set(type,recoMomentum,genPosition,true);
      recoParticle->setTruth(genParticle);
      recoEvent.addParticle(recoParticle);
      } // particle accepted by smearer
    } // particle
}

} // namespace CAP
