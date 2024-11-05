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
#include "ParticlePair3DAnalyzer.hpp"
#include "ParticleSingleHistos.hpp"
#include "ParticlePair3DHistos.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticlePair3DAnalyzer);

namespace CAP
{

ParticlePair3DAnalyzer::ParticlePair3DAnalyzer()
:
EventTask()
{
  appendClassName("ParticlePair3DAnalyzer");
  setInstanceName("ParticlePair3DAnalyzer");
  setName("ParticlePair3DAnalyzer");
  setTitle("ParticlePair3DAnalyzer");
}

ParticlePair3DAnalyzer::ParticlePair3DAnalyzer(const ParticlePair3DAnalyzer & task)
:
EventTask(task)
{   }

ParticlePair3DAnalyzer & ParticlePair3DAnalyzer::operator=(const ParticlePair3DAnalyzer & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}


void ParticlePair3DAnalyzer::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName","Pair3D");
  addProperty("nBins_n1",          100);
  addProperty("Min_n1",            0.0);
  addProperty("Max_n1",            100.0);
  addProperty("nBins_eTot",        100);
  addProperty("Min_eTot",          0.0);
  addProperty("Max_eTot",          100.0);
  addProperty( "nBins_pt",  100);
  addProperty( "Min_pt",    0.0);
  addProperty( "Max_pt",  100.0);

  addProperty( "nBins_y",  200);
  addProperty( "Min_y",   -10.0);
  addProperty( "Max_y",    10.0);

  addProperty( "nBins_phi",  36);
  addProperty( "Min_phi",    0.0);
  addProperty( "Max_phi",    CAP::Math::twoPi());

  addProperty( "nBins_phiEta",    720);
  addProperty( "nBins_phiEtaPt",  7200);
  addProperty( "nBins_phiY",      720);
  addProperty( "nBins_phiYPt",    7200);
  addProperty( "FillEta",         false);
  addProperty( "FillY",           true);
  addProperty( "FillP2",          false);
  addProperty( "FillPid",         false);
  addProperty( "FillPtvsY",       true); // needed for n1n1 calculation

  addProperty("nBins_Qinv",     90);     // q invariant
  addProperty("Min_Qinv",       0.0);
  addProperty("Max_Qinv",       1.8);
  addProperty("nBins_DeltaPs",  60);     // q invariant side
  addProperty("Min_DeltaPs",    0.0);
  addProperty("Max_DeltaPs",    1.2);
  addProperty("nBins_DeltaPo",  60);     // q invariant out
  addProperty("Min_DeltaPo",    0.0);
  addProperty("Max_DeltaPo",    1.2);
  addProperty("nBins_DeltaPl",  60);     // q invariant long
  addProperty("Min_DeltaPl",    0.0);
  addProperty("Max_DeltaPl",    1.2);
}

void ParticlePair3DAnalyzer::configure()
{
  EventTask::configure();
}

void ParticlePair3DAnalyzer::initialize()
{
  if (reportStart(__FUNCTION__)) {/* no ops */}
  EventTask::initialize();
  clearSets();
  addSet("single");
  addSet("pair");
  createHistograms();
  if (reportEnd(__FUNCTION__)) {/* no ops */}
}

void ParticlePair3DAnalyzer::createHistograms()
{
  if (reportStart(__FUNCTION__)) {/* no ops */};
  String bn = getValueString( "HistogramBaseName");
  HistogramGroup * histos;
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      histos = new ParticleSingleHistos();
      histos->setName(createName(bn,efn,pfn));
      histos->setConfiguration(configuration);
      histos->setParentTask(this);
      histos->createHistograms();
      addGroupInSet(0,histos); // singles in set 0
      }
    }

  // pairs
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & particleFilter1 : particleFilters)
      {
      String pfn1 = particleFilter1->getName();
      for (auto & particleFilter2 : particleFilters)
        {
        String pfn2 = particleFilter2->getName();
        histos = new ParticlePair3DHistos();
        histos->setName(createName(bn,efn,pfn1,pfn2));
        histos->setConfiguration(configuration);
        histos->setParentTask(this);
        histos->createHistograms();
        addGroupInSet(1,histos);
        }
      }
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}

void ParticlePair3DAnalyzer::execute()
{
  TaskAccountant::increment();
  Event & event = *Manager<Event>::getObjectAt(0);
  std::vector<Particle*> & particles = event.getParticles();
  if (!analyzeThisEvent(event,eventFilters,eventFilterAccepted)) return;
  if (!analyzeThisEvent(particles,particleFilters,particleFilterAccepted,allParticlesAccepted))  return;
  unsigned int iEventFilter = 0;
  for (auto accepted : eventFilterAccepted)
    {
    if (!accepted) continue;
    unsigned int  baseSingle   = iEventFilter*nParticleFilters;
    unsigned int  basePair     = iEventFilter*nParticleFilters*nParticleFilters;

    for (unsigned int iParticleFilter1=0; iParticleFilter1<nParticleFilters;iParticleFilter1++)
      {
      ParticleSingleHistos & histosSingle = (ParticleSingleHistos &) getGroupAt(0,baseSingle+iParticleFilter1);
      std::vector<Particle*> & particleSelected1 = allParticlesAccepted[iParticleFilter1];
      for (auto & particle1 : particleSelected1) histosSingle.fill(*particle1,1.0);

      for (unsigned int iParticleFilter2=0; iParticleFilter2<nParticleFilters;iParticleFilter2++)
        {
        std::vector<Particle*> & particleSelected2 = allParticlesAccepted[iParticleFilter2];
        ParticlePair3DHistos & histosPair = (ParticlePair3DHistos &) getGroupAt(1,basePair + iParticleFilter1*nParticleFilters + iParticleFilter2);
        for (auto & particle1 : particleSelected1)
          {
          for (auto & particle2 : particleSelected2)
            {
            if (particle1 == particle2) continue;
            histosPair.fill(*particle1,*particle2,1.0);
            }
          }
        }
      }
    iEventFilter++;
    }
}

void ParticlePair3DAnalyzer::scaleHistograms()
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
  unsigned int index;
  unsigned int baseSingle;
  unsigned int basePair;

  for (unsigned int iEventFilter=0; iEventFilter< nEventFilters; iEventFilter++)
    {
    baseSingle = iEventFilter*nParticleFilters;
    basePair   = iEventFilter*nParticleFilters*nParticleFilters;
    for (unsigned int iParticleFilter1=0; iParticleFilter1< nParticleFilters; iParticleFilter1++)
      {
      index = baseSingle + iParticleFilter1;
      getGroupAt(0,index).scaleHistograms(factors[iEventFilter]);
      for (unsigned int iParticleFilter2=0; iParticleFilter2<nParticleFilters; iParticleFilter2++ )
        {
        index = basePair + iParticleFilter1*nParticleFilters + iParticleFilter2;
        getGroupAt(1,index).scaleHistograms(factors[iEventFilter]);
        }
      }
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}

} // namespace CAP
