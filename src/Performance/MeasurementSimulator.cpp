/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
 *
 * *********************************************************************/
#include "MeasurementSimulator.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "TRandom.h"
#include "EfficiencyFilter.hpp"

ClassImp(CAP::MeasurementSimulator);

namespace CAP
{

MeasurementSimulator::MeasurementSimulator()
:
EventTask(),
ptFunction(),
etaFunction(),
phiFunction()
{
  appendClassName("MeasurementSimulator");
  setName("MeasurementSimulator");
  setTitle("MeasurementSimulator");
}

MeasurementSimulator::MeasurementSimulator(const MeasurementSimulator & task)
:
EventTask(task),
ptFunction(task.ptFunction),
etaFunction(task.etaFunction),
phiFunction(task.phiFunction)
{
  appendClassName("MeasurementSimulator");
  setName("MeasurementSimulator");
  setTitle("MeasurementSimulator");
}

MeasurementSimulator & MeasurementSimulator::operator=(const MeasurementSimulator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    ptFunction  = task.ptFunction;
    etaFunction = task.etaFunction;
    phiFunction = task.phiFunction;
    }
  return *this;
}


void MeasurementSimulator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();

  addProperty("nBins_pt",  200);
  addProperty("Min_pt",    0.00);
  addProperty("Max_pt",    10.00);
  addProperty("nBins_eta", 200 );
  addProperty("Min_eta",   -10.00);
  addProperty("Max_eta",    10.00);

  addProperty("PtBiasVsPtAinv",  0.00);
  addProperty("PtBiasVsPtA0",    0.00);
  addProperty("PtBiasVsPtA1",    0.00);
  addProperty("PtBiasVsPtA2",    0.00);
  addProperty("PtRmsVsPtAinv",   0.00);
  addProperty("PtRmsVsPtA0",     0.00);
  addProperty("PtRmsVsPtA1",     0.00);
  addProperty("PtRmsVsPtA2",     0.00);
  addProperty("PtBiasVsEtaA1",   0.00);
  addProperty("PtBiasVsEtaA2",   0.00);
  addProperty("PtRmsVsEtaA1",    0.00);
  addProperty("PtRmsVsEtaA2",    0.00);
  addProperty("EtaBiasVsPtAinv", 0.00);
  addProperty("EtaBiasVsPtA0",   0.00);
  addProperty("EtaBiasVsPtA1",   0.00);
  addProperty("EtaBiasVsPtA2",   0.00);
  addProperty("EtaRmsVsPtAinv",  0.00);
  addProperty("EtaRmsVsPtA0",    0.00);
  addProperty("EtaRmsVsPtA1",    0.00);
  addProperty("EtaRmsVsPtA2",    0.00);
  addProperty("EtaBiasVsEtaA1",  0.00);
  addProperty("EtaBiasVsEtaA2",  0.00);
  addProperty("EtaRmsVsEtaA1",   0.00);
  addProperty("EtaRmsVsEtaA2",   0.00);
  addProperty("PhiBiasVsPtAinv", 0.00);
  addProperty("PhiBiasVsPtA0",   0.00);
  addProperty("PhiBiasVsPtA1",   0.00);
  addProperty("PhiBiasVsPtA2",   0.00);
  addProperty("PhiRmsVsPtAinv",  0.00);
  addProperty("PhiRmsVsPtA0",    0.00);
  addProperty("PhiRmsVsPtA1",    0.00);
  addProperty("PhiRmsVsPtA2",    0.00);
  addProperty("PhiBiasVsEtaA1",  0.00);
  addProperty("PhiBiasVsEtaA2",  0.00);
  addProperty("PhiRmsVsEtaA1",   0.00);
  addProperty("PhiRmsVsEtaA2",   0.00);
}

void MeasurementSimulator::configure()
{
  EventTask::configure();
}


void MeasurementSimulator::initialize()
{
  EventTask::initialize();

  vector<double> biasVsPt;
  vector<double> biasVsEta;
  vector<double> rmsVsPt;
  vector<double> rmsVsEta;

  biasVsPt.push_back(configuration.getValueDouble("PtBiasVsPtAinv"));
  biasVsPt.push_back(configuration.getValueDouble("PtBiasVsPtA0"));
  biasVsPt.push_back(configuration.getValueDouble("PtBiasVsPtA1"));
  biasVsPt.push_back(configuration.getValueDouble("PtBiasVsPtA2"));

  rmsVsPt.push_back(configuration.getValueDouble("PtRmsVsPtAinv"));
  rmsVsPt.push_back(configuration.getValueDouble("PtRmsVsPtA0"));
  rmsVsPt.push_back(configuration.getValueDouble("PtRmsVsPtA1"));
  rmsVsPt.push_back(configuration.getValueDouble("PtRmsVsPtA2"));

  biasVsEta.push_back(configuration.getValueDouble("PtBiasVsEtaA1"));
  biasVsEta.push_back(configuration.getValueDouble("PtBiasVsEtaA2"));

  rmsVsEta.push_back(configuration.getValueDouble("PtRmsVsEtaA1"));
  rmsVsEta.push_back(configuration.getValueDouble("PtRmsVsEtaA2"));

  ptFunction.setCoefficients(0,biasVsPt,biasVsEta,rmsVsPt,rmsVsEta);


  biasVsPt.clear();
  biasVsEta.clear();
  rmsVsPt.clear();
  rmsVsEta.clear();

  biasVsPt.push_back(configuration.getValueDouble("EtaBiasVsPtAinv"));
  biasVsPt.push_back(configuration.getValueDouble("EtaBiasVsPtA0"));
  biasVsPt.push_back(configuration.getValueDouble("EtaBiasVsPtA1"));
  biasVsPt.push_back(configuration.getValueDouble("EtaBiasVsPtA2"));
  rmsVsPt.push_back(configuration.getValueDouble("EtaRmsVsPtAinv"));
  rmsVsPt.push_back(configuration.getValueDouble("EtaRmsVsPtA0"));
  rmsVsPt.push_back(configuration.getValueDouble("EtaRmsVsPtA1"));
  rmsVsPt.push_back(configuration.getValueDouble("EtaRmsVsPtA2"));
  biasVsEta.push_back(configuration.getValueDouble("EtaBiasVsEtaA1"));
  biasVsEta.push_back(configuration.getValueDouble("EtaBiasVsEtaA2"));
  rmsVsEta.push_back(configuration.getValueDouble("EtaRmsVsEtaA1"));
  rmsVsEta.push_back(configuration.getValueDouble("EtaRmsVsEtaA2"));
  etaFunction.setCoefficients(1,biasVsPt,biasVsEta,rmsVsPt,rmsVsEta);

  biasVsPt.clear();
  biasVsEta.clear();
  rmsVsPt.clear();
  rmsVsEta.clear();

  biasVsPt.push_back(configuration.getValueDouble("PhiBiasVsPtAinv"));
  biasVsPt.push_back(configuration.getValueDouble("PhiBiasVsPtA0"));
  biasVsPt.push_back(configuration.getValueDouble("PhiBiasVsPtA1"));
  biasVsPt.push_back(configuration.getValueDouble("PhiBiasVsPtA2"));
  rmsVsPt.push_back(configuration.getValueDouble("PhiRmsVsPtAinv"));
  rmsVsPt.push_back(configuration.getValueDouble("PhiRmsVsPtA0"));
  rmsVsPt.push_back(configuration.getValueDouble("PhiRmsVsPtA1"));
  rmsVsPt.push_back(configuration.getValueDouble("PhiRmsVsPtA2"));
  biasVsEta.push_back(configuration.getValueDouble("PhiBiasVsEtaA1"));
  biasVsEta.push_back(configuration.getValueDouble("PhiBiasVsEtaA2"));
  rmsVsEta.push_back(configuration.getValueDouble("PhiRmsVsEtaA1"));
  rmsVsEta.push_back(configuration.getValueDouble("PhiRmsVsEtaA2"));
  phiFunction.setCoefficients(2,biasVsPt,biasVsEta,rmsVsPt,rmsVsEta);

  biasVsPt.clear();
  biasVsEta.clear();
  rmsVsPt.clear();
  rmsVsEta.clear();
}

void MeasurementSimulator::execute()
{
  Event & genEvent  = *Manager<Event>::getObjectAt(0);
  Event & recoEvent = *Manager<Event>::getObjectAt(1);
  recoEvent.reset();
  std::vector<Particle*> & genParticles = genEvent.getParticles();
  if (!analyzeThisEvent(genEvent,eventFilters,eventFilterAccepted)) return;
  if (!analyzeThisEvent(genParticles,efficiencyFilters,particleFilterAccepted,allParticlesAccepted))  return;
  for (auto accepted : eventFilterAccepted)
    {
    if (!accepted) continue;
    for (unsigned int iParticleFilter=0; iParticleFilter<nEfficiencyFilters;iParticleFilter++)
      {
      std::vector<Particle*> & genParticlesSelected = allParticlesAccepted[iParticleFilter];
      for (auto & genParticle : genParticlesSelected)
        {
        ParticleType * type = genParticle->getTypePtr();
        LorentzVector & genPosition = genParticle->getPosition();
        LorentzVector & genMomentum = genParticle->getMomentum();
        LorentzVector recoMomentum;
        smearMomentum(genMomentum,recoMomentum);
        Particle * recoParticle = particleFactory->getNextObject();
        recoParticle->set(type,recoMomentum,genPosition,true);
        //recoParticle->set(type,genMomentum,genPosition,true);
        recoParticle->setTruth(genParticle);
        recoEvent.addParticle(recoParticle);
        }
      }
    }
}

void MeasurementSimulator::smearMomentum(const LorentzVector &in, LorentzVector & out)
{
  double smearedPt  = 0.0;
  double smearedEta = 0.0;
  double smearedPhi = 0.0;
  double pt   = in.Pt();
  double phi  = in.Phi();
  double eta  = in.Eta();
  double mass = in.M();
  ptFunction.smear(pt,  eta, phi, smearedPt);
  etaFunction.smear(pt, eta, phi, smearedEta);
  phiFunction.smear(pt, eta, phi, smearedPhi);
  if (smearedPt<0.001) smearedPt = 0.001;
  out.SetPtEtaPhiM(smearedPt,smearedEta,smearedPhi,mass);
}

void MeasurementSimulator::scaleHistograms()
{
  //  no ops...
}



} // namespace CAP
