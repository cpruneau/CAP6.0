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
#include "ParticlePair3DBfCalculator.hpp"
#include "ParticlePair3DDerivedHistos.hpp"
#include "ParticlePair3DBfHistos.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticlePair3DBfCalculator);

namespace CAP
{

ParticlePair3DBfCalculator::ParticlePair3DBfCalculator()
:
EventTask()
{
  appendClassName("ParticlePair3DBfCalculator");
  setInstanceName("ParticlePair3DBfCalculator");
  setName("ParticlePair3DBfCalculator");
  setTitle("ParticlePair3DBfCalculator");
}

ParticlePair3DBfCalculator::ParticlePair3DBfCalculator(const ParticlePair3DBfCalculator & task)
:
EventTask(task)
{   }

ParticlePair3DBfCalculator & ParticlePair3DBfCalculator::operator=(const ParticlePair3DBfCalculator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}


void ParticlePair3DBfCalculator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName","Pair3D");

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

void ParticlePair3DBfCalculator::configure()
{
  EventTask::configure();
}

void ParticlePair3DBfCalculator::initialize()
{
  EventTask::initialize();
  clearSets();
  addSet("pair3DDerived");
  addSet("pair3DBf");
  HistogramTask::importHistograms();
  createHistograms();
}

void ParticlePair3DBfCalculator::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* */ };
  String bn = getValueString( "HistogramBaseName");
  HistogramGroup * histos;
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    if (reportDebug(__FUNCTION__)) printValue("Event filter",efn);
    for (auto & particleFilter1 : particleFilters)
      {
      String pfn1 = particleFilter1->getName();
      if (reportDebug(__FUNCTION__)) printValue("Particle filter 1",pfn1);
      for (auto & particleFilter2 : particleFilters)
        {
        String pfn2 = particleFilter2->getName();
        if (reportDebug(__FUNCTION__)) printValue("Particle filter 2",pfn2);
        histos = new ParticlePair3DDerivedHistos();
        histos->setName(createName(bn,efn,pfn1,pfn2));
        histos->setConfiguration(configuration);
        histos->setParentTask(this);
        histos->importHistograms(inputFile);
        addGroupInSet(0,histos);
        }
      }
    }
  if (reportEnd(__FUNCTION__))  { /* */ };
}

void ParticlePair3DBfCalculator::createHistograms()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  String bn = getValueString( "HistogramBaseName");
  HistogramGroup * histos;
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();

  if (true)
    {
    printCR();
    printValue("Creating BF HistogramGroup",bn);
    printValue("nEventFilters",eventFilters.size());
    printValue("nParticleFilters",particleFilters.size());
    printCR();
    }

  // -----------------------------------------------------------------------------
  // particle 2 is considered to be the trigger or reference particle.
  // -----------------------------------------------------------------------------

  int half = nParticleFilters/2;
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (int iParticleFilter1 = 0;iParticleFilter1<half;iParticleFilter1++)
      {
      ParticleFilter* particleFilter1 = particleFilters[iParticleFilter1];
      String pfn1 = particleFilter1->getName();
      for (int iParticleFilter2 = 0; iParticleFilter2<half;iParticleFilter2++)
        {
        ParticleFilter* particleFilter2 = particleFilters[iParticleFilter2];
        String pfn2 = particleFilter2->getName();
        histos = new ParticlePair3DBfHistos();
        histos->setConfiguration(configuration);
        histos->setParentTask(this);
        histos->setName(createName(bn,efn,pfn1,pfn2));
        histos->createHistograms();
        addGroupInSet(1,histos);
        }
      }
    }
  if (reportEnd(__FUNCTION__))   { /* */ };
}


void ParticlePair3DBfCalculator::execute()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  int nEventFilters    = eventFilters.size();
  int nParticleFilters = particleFilters.size();
  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printValue("nEventFilters",   nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    }
  int half = nParticleFilters/2;
  for (int iEventFilter = 0; iEventFilter<nEventFilters;iEventFilter++)
    {
    unsigned int  basePair     = iEventFilter*nParticleFilters*nParticleFilters;
    unsigned int  basePairBf   = iEventFilter*half*half;
    printValue("ParticlePair3DBfCalculator::execute() basePair",basePair);
    printValue("ParticlePair3DBfCalculator::execute() basePairBf",basePairBf);

    // -----------------------------------------------------------------------------
    // particle 2 is considered to be the trigger or reference particle.
    // -----------------------------------------------------------------------------

    for (int iParticleFilter1 = 0; iParticleFilter1<half;iParticleFilter1++)
      {
      for (int iParticleFilter2 = 0; iParticleFilter2<half;iParticleFilter2++)
        {
        int indexPairs12    = basePairBf + iParticleFilter1*nParticleFilters + iParticleFilter2;
        int indexPairs12B   = basePair   + iParticleFilter1*nParticleFilters + iParticleFilter2 + half;
        int indexPairs1B2   = basePair   + (iParticleFilter1+half)*nParticleFilters + iParticleFilter2;
        int indexPairs1B2B  = basePair   + (iParticleFilter1+half)*nParticleFilters + iParticleFilter2 + half;
        int indexBf         = basePairBf + iParticleFilter1 + iParticleFilter2*half;
        ParticlePair3DDerivedHistos & pair12   = (ParticlePair3DDerivedHistos &) getGroupAt(0,indexPairs12);
        ParticlePair3DDerivedHistos & pair12B  = (ParticlePair3DDerivedHistos &) getGroupAt(0,indexPairs12B);
        ParticlePair3DDerivedHistos & pair1B2  = (ParticlePair3DDerivedHistos &) getGroupAt(0,indexPairs1B2);
        ParticlePair3DDerivedHistos & pair1B2B = (ParticlePair3DDerivedHistos &) getGroupAt(0,indexPairs1B2B);
        ParticlePair3DBfHistos & bf = (ParticlePair3DBfHistos &) getGroupAt(1,indexBf);
        bf.calculateBfHistograms(pair12, pair12B,pair1B2,pair1B2B);  // ++, +-, -+, --
        } // calculateBfHistograms
      }
    }
  if (reportEnd(__FUNCTION__))   { /* */ };
}

void ParticlePair3DBfCalculator::scaleHistograms()
{
// no ops
}


} // namespace CAP
