/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Victor Gonzalez   
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
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
}

PerformanceAnalyzer::PerformanceAnalyzer(const PerformanceAnalyzer & analyzer)
:
EventTask(analyzer)
{   }

PerformanceAnalyzer  & PerformanceAnalyzer::operator=(const PerformanceAnalyzer & analyzer)
{
  if (this!=&analyzer)
    {
    EventTask::operator=(analyzer);
    }
  return *this;
}


void PerformanceAnalyzer::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty( "HistogramBaseName","Closure");
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
}

void PerformanceAnalyzer::configure()
{
  EventTask::configure();
}

void PerformanceAnalyzer::initialize()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  EventTask::initialize();
  clearSets();
  addSet("Performance");
  createHistograms();
  if (reportEnd(__FUNCTION__)) { /* noops*/ };
}


void PerformanceAnalyzer::createHistograms()
{
  String bn = getValueString( "HistogramBaseName");
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printString("Creating Histogram(s)");
    printValue("nEventFilters",nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    }
  for (auto & eventFilter : eventFilters)
   {
    String efn = eventFilter->getName();
   for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      ParticlePerformanceHistos * histos = new ParticlePerformanceHistos();
      histos->setName(createName(bn,efn,pfn));
      histos->setConfiguration(configuration);
      histos->setParentTask(this);
      histos->createHistograms();
      addGroupInSet(0,histos);
      }
    }
}


void PerformanceAnalyzer::importHistograms(TFile & inputFile)
{
  String bn = getValueString( "HistogramBaseName");
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

void PerformanceAnalyzer::scaleHistograms()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  std::vector<long> & counts = getFilteredEventCounts();
  std::vector<double> factors;
  for (auto count : counts)
    {
    if (count>0)
      {
      double f = 1.0/double(count);
      printValue("Count",count);
      printValue("Scaling factor",f);
      factors.push_back(f);
      }
    else
      factors.push_back(1.0);
    }
  unsigned int nEventFilters    = Manager<EventFilter>::getNObjects();
  unsigned int nParticleFilters = Manager<ParticleFilter>::getNObjects();
  int index = 0;
  for (unsigned int iEventFilter=0; iEventFilter< nEventFilters; iEventFilter++)
    {
    for (unsigned int iParticleFilter=0; iParticleFilter< nParticleFilters; iParticleFilter++)
      {
      ParticlePerformanceHistos & group = (ParticlePerformanceHistos&) getGroupAt(0,index);
      printValue("Scaling factor",factors[iEventFilter]);

      group.scaleHistograms(factors[iEventFilter]);
      index++;
      }
    }
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}



} // namespace CAP
