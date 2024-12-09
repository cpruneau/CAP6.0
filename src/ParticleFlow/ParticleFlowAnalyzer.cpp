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
#include "ParticleFlowAnalyzer.hpp"
#include "ParticleFlowHistos.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticleFlowAnalyzer);

namespace CAP
{

ParticleFlowAnalyzer::ParticleFlowAnalyzer()
:
EventTask()
{
  appendClassName("ParticleFlowAnalyzer");
  setInstanceName("Flow");
  setName("Flow");
  setTitle("Flow");
}

ParticleFlowAnalyzer::ParticleFlowAnalyzer(const ParticleFlowAnalyzer & analyzer)
:
EventTask(analyzer)
{   }

ParticleFlowAnalyzer  & ParticleFlowAnalyzer::operator=(const ParticleFlowAnalyzer & analyzer)
{
  if (this!=&analyzer)
    {
    EventTask::operator=(analyzer);
    }
  return *this;
}

void ParticleFlowAnalyzer::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty( "HistogramBaseName","Flow");
  addProperty( "nBins_n1",  100);
  addProperty( "Min_n1",    0.0);
  addProperty( "Max_n1",  100.0);

  addProperty( "nBins_eTot",  100);
  addProperty( "Min_eTot",    0.0);
  addProperty( "Max_eTot",  100.0);

  addProperty( "nBins_pt",  100);
  addProperty( "Min_pt",    0.0);
  addProperty( "Max_pt",  100.0);

  addProperty( "nBins_eta",  20);
  addProperty( "Min_eta",   -1.0);
  addProperty( "Max_eta",    1.0);

  addProperty( "nBins_y",  20);
  addProperty( "Min_y",   -1.0);
  addProperty( "Max_y",    1.0);

  addProperty( "nBins_phi",  36);
  addProperty( "Min_phi",    0.0);
  addProperty( "Max_phi",    CAP::Math::twoPi());

  addProperty( "nBins_phiEta",    720);
  addProperty( "nBins_phiEtaPt",  7200);
  addProperty( "nBins_phiY",      720);
  addProperty( "nBins_phiYPt",    7200);
  addProperty( "FillEta",         true);
  addProperty( "FillY",           false);
  addProperty( "FillP2",          false);
  addProperty( "FillPid",         false);
}

void ParticleFlowAnalyzer::configure()
{
  EventTask::configure();
}

void ParticleFlowAnalyzer::initialize()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  EventTask::initialize();
  clearSets();
  addSet("Flow");
  addSet("derived");
  createHistograms();
  if (reportEnd(__FUNCTION__)) { /* noops*/ };
}

void ParticleFlowAnalyzer::createHistograms()
{
  if (reportStart(__FUNCTION__)) {  /* no ops */ };
  String bn = getValueString( "HistogramBaseName");
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      ParticleFlowHistos * histos = new ParticleFlowHistos();
      histos->setName(createName(bn,efn,pfn));
//      printCR();
//      printValue("efn",efn);
//      printValue("pfn",pfn);

      histos->setConfiguration(configuration);
      histos->setParentTask(this);
      histos->createHistograms();
      addGroupInSet(0,histos);
      }
    }
//  printLine();
//  exit(1);

  if (reportEnd(__FUNCTION__))  {  /* no ops */ };
}

void ParticleFlowAnalyzer::execute()
{
  TaskAccountant::increment();
  Event & event = *Manager<Event>::getObjectAt(0);
  std::vector<Particle*>       & particles       = event.getParticles();
  if (!analyzeThisEvent(event,eventFilters,eventFilterAccepted)) return;
  if (!analyzeThisEvent(particles,particleFilters,particleFilterAccepted,allParticlesAccepted))  return;
  unsigned int iEventFilter = 0;
  for (auto accepted : eventFilterAccepted)
    {
    if (!accepted) continue;
    unsigned int  baseFlow   = iEventFilter*nParticleFilters;
    for (unsigned int iParticleFilter=0; iParticleFilter<nParticleFilters;iParticleFilter++)
      {
      ParticleFlowHistos & histosFlow = (ParticleFlowHistos &) getGroupAt(0,baseFlow+iParticleFilter);
      std::vector<Particle*> & particlesSelected = allParticlesAccepted[iParticleFilter];
      double multiplicityAccepted = 0.0;
      double energyAccepted = 0.0;
      for (auto & particle : particlesSelected)
        {
        multiplicityAccepted++;
        energyAccepted += particle->getMomentum().E();
        histosFlow.fill(*particle,1.0);
        }
      histosFlow.fillMultiplicity(multiplicityAccepted,energyAccepted,1.0);
      }
    iEventFilter++;
    }
}

//!
//! Scale (all) the histograms held in all the histogram groups owned by this Task instance. This operation is executed automatically within the finalize() method call if
//! and only if the HistogramsScale parameter of the Configuration instance controlling this Task is set to "true".
//!
void ParticleFlowAnalyzer::scaleHistograms()
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
      ParticleFlowHistos & group = (ParticleFlowHistos&) getGroupAt(0,index);
      group.scaleHistograms(factors[iEventFilter]);
      index++;
      }
    }
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

} // namespace CAP
