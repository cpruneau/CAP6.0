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
#include "ParticlePairBfCalculator.hpp"
#include "ParticlePairDerivedHistos.hpp"
#include "ParticlePairBfHistos.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticlePairBfCalculator);

namespace CAP
{

ParticlePairBfCalculator::ParticlePairBfCalculator()
:
EventTask()
{
  appendClassName("ParticlePairBfCalculator");
  setInstanceName("ParticlePairBfCalculator");
  setName("ParticlePairBfCalculator");
  setTitle("ParticlePairBfCalculator");
}

ParticlePairBfCalculator::ParticlePairBfCalculator(const ParticlePairBfCalculator & task)
:
EventTask(task)
{   }

ParticlePairBfCalculator & ParticlePairBfCalculator::operator=(const ParticlePairBfCalculator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}


void ParticlePairBfCalculator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName", "Pair");
  addProperty("FillEta",           fillEta);
  addProperty("FillY",             fillY);
  addProperty("FillP2",            fillP2);
  addProperty("nBins_n1",          100);
  addProperty("Min_n1",            0.0);
  addProperty("Max_n1",            100.0);
  addProperty("nBins_eTot",        100);
  addProperty("Min_eTot",          0.0);
  addProperty("Max_eTot",          100.0);
  addProperty("nBins_pt",          18);
  addProperty("Min_pt",            0.20);
  addProperty("Max_pt",            2.00);
  addProperty("nBins_phi",          72);
  addProperty("Min_phi",           0.0);
  addProperty("Max_phi",           CAP::Math::twoPi());
  addProperty("nBins_eta",           20);
  addProperty("Min_eta",           -1.0);
  addProperty("Max_eta",            1.0);
  addProperty("nBins_y",             20);
  addProperty("Min_y",             -1.0);
  addProperty("Max_y",              1.0);
  addProperty("nBins_phiEta",            720);
  addProperty("nBins_phiEtaPt",          7200);
  addProperty("nBins_phiY",              720);
  addProperty("nBins_phiYPt",            7200);
  addProperty("nBins_n2",                  100);
  addProperty("Min_n2",                    0.0);
  addProperty("Max_n2",                 1000.0);
  addProperty("nBins_Dphi",                 36);
  addProperty("Min_Dphi",                  0.0);
  addProperty("Max_Dphi",CAP::Math::twoPi());
  addProperty("Width_Dphi",CAP::Math::twoPi());
  addProperty("nBins_Dphi_shft",    36);
  addProperty("Min_Dphi_shft",     0.0);
  addProperty("Max_Dphi_shft",     0.0);
  addProperty("nBins_Deta",         39);
  addProperty("Min_Deta",         -2.0);
  addProperty("Max_Deta",          2.0);
  addProperty("Width_Deta",   4.0/39.0);
  addProperty("nBins_Dy",           39);
  addProperty("Min_Dy",           -2.0);
  addProperty("Max_Dy",            2.0);
  addProperty("Width_Dy",     4.0/39.0);
  addProperty("nBins_DeltaP",   10);
  addProperty("Min_DeltaP",   -4.0);
  addProperty("Max_DeltaP",    4.0);
  addProperty("binCorrPP",     1.0);
}

void ParticlePairBfCalculator::configure()
{
  EventTask::configure();
}

void ParticlePairBfCalculator::initialize()
{
  EventTask::initialize();
  clearSets();
  addSet("pairDerived");
  addSet("pairBf");
  HistogramTask::importHistograms();
  createHistograms();
}

void ParticlePairBfCalculator::importHistograms(TFile & inputFile)
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
        histos = new ParticlePairDerivedHistos();
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

void ParticlePairBfCalculator::createHistograms()
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
        histos = new ParticlePairBfHistos();
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


void ParticlePairBfCalculator::execute()
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
    printValue("ParticlePairBfCalculator::execute() basePair",basePair);
    printValue("ParticlePairBfCalculator::execute() basePairBf",basePairBf);

    for (int iParticleFilter1 = 0; iParticleFilter1<half;iParticleFilter1++)
      {
      for (int iParticleFilter2 = 0; iParticleFilter2<half;iParticleFilter2++)
        {
        int indexPairs21B  = basePair   + (iParticleFilter1+half)*nParticleFilters + iParticleFilter2;
        int indexPairs2B1B = basePair   + (iParticleFilter1+half)*nParticleFilters + iParticleFilter2 + half;
        int indexPairs2B1  = basePair   + iParticleFilter1*nParticleFilters + iParticleFilter2 + half;
        int indexPairs21   = basePairBf + iParticleFilter1*nParticleFilters + iParticleFilter2;
        int indexBf        = basePairBf + iParticleFilter1*half + iParticleFilter2;
        printValue("ParticlePairBfCalculator::execute() indexPairs21B",indexPairs21B);
        ParticlePairDerivedHistos & pair21B  = (ParticlePairDerivedHistos &) getGroupAt(0,indexPairs21B);
        printValue("ParticlePairBfCalculator::execute() indexPairs2B1B",indexPairs2B1B);
        ParticlePairDerivedHistos & pair2B1B = (ParticlePairDerivedHistos &) getGroupAt(0,indexPairs2B1B);
        printValue("ParticlePairBfCalculator::execute() indexPairs2B1",indexPairs2B1);
        ParticlePairDerivedHistos & pair2B1  = (ParticlePairDerivedHistos &) getGroupAt(0,indexPairs2B1);
        printValue("ParticlePairBfCalculator::execute() indexPairs21",indexPairs21);
        ParticlePairDerivedHistos & pair21   = (ParticlePairDerivedHistos &) getGroupAt(0,indexPairs21);
        printValue("ParticlePairBfCalculator::execute() indexBf",indexBf);
        ParticlePairBfHistos & bf = (ParticlePairBfHistos &) getGroupAt(1,indexBf);
        bf.calculateBfHistograms(pair21B,pair2B1B,pair2B1,pair21);
        } // calculateBfHistograms
      }
    }
  if (reportEnd(__FUNCTION__))   { /* */ };
}

void ParticlePairBfCalculator::scaleHistograms()
{
// no ops
}


} // namespace CAP
