/* **********************************************************************
 * Copyright (C) 2019-2022, Claude Pruneau, Victor Gonzalez, Sumit Basu
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2022
 *
 * *********************************************************************/
#include "PerformanceAnalyzer.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::PerformanceAnalyzer);

namespace CAP
{

PerformanceAnalyzer::PerformanceAnalyzer()
:
EventTask(),
fillEta(true),
fillY(false)
{
  appendClassName("PerformanceAnalyzer");
  setName("PerformanceAnalyzer");
  setTitle("PerformanceAnalyzer");
  setVersion("1.0");
}

void PerformanceAnalyzer::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("nBins_pt",100);
  addProperty("Min_pt", 0.0);
  addProperty("Max_pt", 5.0);
  addProperty("nBins_dpt", 100);
  addProperty("Min_dpt",  -1.0);
  addProperty("Max_dpt",   1.0);
  addProperty("nBins_phi", 100);
  addProperty("Min_phi",  -1.0);
  addProperty("Max_phi",   1.0);
  addProperty("nBins_dphi", 100);
  addProperty("Min_dphi",  -1.0);
  addProperty("Max_dphi",   1.0);
  addProperty("nBins_eta", 100);
  addProperty("Min_eta",  -1.0);
  addProperty("Max_eta",   1.0);
  addProperty("nBins_deta", 100);
  addProperty("Min_deta",  -1.0);
  addProperty("Max_deta",   1.0);
  addProperty("nBins_y", 100);
  addProperty("Min_y",  -1.0);
  addProperty("Max_y",  -1.0);
  addProperty("nBins_dy", 100);
  addProperty("Min_dy",  -1.0);
  addProperty("Max_dy",   1.0);
  addProperty("FillEta",  fillEta);
  addProperty("FillY",    fillY);
}

void PerformanceAnalyzer::createHistograms()
{
  if (reportStart(__FUNCTION__)) {/* */};
  String bn = getName(); //bn += "_";
  fillEta = getValueBool("FillEta");
  fillY   = getValueBool("FillY");
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printString("Creating Histogram(s)");
    printValue("nEventFilters",nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    }
  clearSets();
  addSet("Performance");
  for (auto & eventFilter : eventFilters)
   {
    String efn = eventFilter->getName();
   for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      String histoName  = bn;
      histoName += "_";
      histoName += efn;
      histoName += "_";
      histoName += pfn;
      ParticlePerformanceHistos * histos = new ParticlePerformanceHistos();
      histos->setConfiguration(configuration);
      histos->setParentTask(this);
      histos->createHistograms();
      addGroupInSet(0,histos);
      }
    }
  if (reportEnd(__FUNCTION__)){/* */};
}


void PerformanceAnalyzer::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) {/* */};
  String bn = getName(); bn += "_";
  fillEta = getValueBool("FillEta");
  fillY   = getValueBool("FillY");
  addSet("Performance");
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      String name  = bn;
      name += efn;
      name += "_";
      name += pfn;
      ParticlePerformanceHistos * histos = new ParticlePerformanceHistos();
      histos->setConfiguration(configuration);
      histos->setName(name);
      histos->setParentTask(this);
      histos->importHistograms(inputFile);
      addGroupInSet(0,histos);
      }
    }
  if (reportEnd(__FUNCTION__)) {/* */};
}

void PerformanceAnalyzer::execute()
{
  Event & event = *Manager<Event>::getObjectAt(0);
  std::vector<Particle*> & particles = event.getParticles();
  if (!analyzeThisEvent(event,eventFilters,eventFilterAccepted)) return;
  if (!analyzeThisEvent(particles,particleFilters,particleFilterAccepted,allParticlesAccepted))  return;
  unsigned int iEventFilter = 0;
  for (auto accepted : eventFilterAccepted)
    {
    if (!accepted) continue;
    unsigned int  baseSingle   = iEventFilter*nParticleFilters;
    for (unsigned int iParticleFilter=0; iParticleFilter<nParticleFilters;iParticleFilter++)
      {
      ParticlePerformanceHistos & histos = (ParticlePerformanceHistos &) getGroupAt(0,baseSingle+iParticleFilter);
      std::vector<Particle*> & particlesSelected = allParticlesAccepted[iParticleFilter];
      for (auto & particle : particlesSelected) histos.fill(*particle,1.0);
      }
    iEventFilter++;
    }
}

} // namespace CAP
