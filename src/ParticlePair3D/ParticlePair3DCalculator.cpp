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
#include "ParticlePair3DCalculator.hpp"
#include "ParticleSingleHistos.hpp"
#include "ParticlePair3DHistos.hpp"
#include "ParticlePair3DDerivedHistos.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticlePair3DCalculator);

namespace CAP
{

ParticlePair3DCalculator::ParticlePair3DCalculator()
:
EventTask()
{
  appendClassName("ParticlePair3DCalculator");
  setInstanceName("Pair");
  setName("Pair");
  setTitle("Pair");
}

ParticlePair3DCalculator::ParticlePair3DCalculator(const ParticlePair3DCalculator & task)
:
EventTask(task)
{   }

ParticlePair3DCalculator & ParticlePair3DCalculator::operator=(const ParticlePair3DCalculator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}


void ParticlePair3DCalculator::setDefaultConfiguration()
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

void ParticlePair3DCalculator::configure()
{
  EventTask::configure();
}

void ParticlePair3DCalculator::initialize()
{
  EventTask::initialize();
  clearSets();
  addSet("single");
  addSet("pair");
  addSet("singleDerived");
  addSet("pairDerived");
  HistogramTask::importHistograms();
  createHistograms();
}

void ParticlePair3DCalculator::importHistograms(TFile & inputFile)
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
    for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      if (reportDebug(__FUNCTION__)) printValue("Particle filter",pfn);
      histos = new ParticleSingleHistos();
      histos->setParentTask(this);
      histos->setConfiguration(configuration);
      histos->setName(createName(bn,efn,pfn));
      histos->importHistograms(inputFile);
      addGroupInSet(0,histos);
      }
    for (auto & particleFilter1 : particleFilters)
      {
      String pfn1 = particleFilter1->getName();
      if (reportDebug(__FUNCTION__)) printValue("Particle filter 1",pfn1);
      for (auto & particleFilter2 : particleFilters)
        {
        String pfn2 = particleFilter2->getName();
        if (reportDebug(__FUNCTION__)) printValue("Particle filter 2",pfn2);
        histos = new ParticlePair3DHistos();
        histos->setName(createName(bn,efn,pfn1,pfn2));
        histos->setConfiguration(configuration);
        histos->setParentTask(this);
        histos->importHistograms(inputFile);
        addGroupInSet(1,histos);
        }
      }
    }
  if (reportEnd(__FUNCTION__))  { /* */ };
}

void ParticlePair3DCalculator::createHistograms()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  String bn = getValueString( "HistogramBaseName");
  HistogramGroup * histos;
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printValue("Creating Derived HistogramGroup",bn);
    printValue("nEventFilters",eventFilters.size());
    printValue("nParticleFilters",particleFilters.size());
    printCR();
    }
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      histos = new ParticleSingleDerivedHistos();
      histos->setConfiguration(configuration);
      histos->setParentTask(this);
      histos->setName(createName(bn,efn,pfn));
      histos->createHistograms();
      addGroupInSet(2,histos);
      }
    for (auto & particleFilter1 : particleFilters)
      {
      String pfn1 = particleFilter1->getName();
      for (auto & particleFilter2 : particleFilters)
        {
        String pfn2 = particleFilter2->getName();
        histos = new ParticlePair3DDerivedHistos();
        histos->setName(createName(bn,efn,pfn1,pfn2));
        histos->setConfiguration(configuration);
        histos->setParentTask(this);
        histos->createHistograms();
        addGroupInSet(3,histos);
        }
      }
    }
  if (reportEnd(__FUNCTION__))   { /* */ };
}

int ParticlePair3DCalculator::getPidFor(ParticleFilter* pf)
{
  std::vector<Condition*> pf->getConditions();
  for (auto & condition : conditions)
    {
    int filterSubType = condition->conditionSubtype;
    if (filterSubType == ParticleFilter::kPdg)
      {
      return (dynamic_cast<ConditionInteger*> condition)->value; //PDG requested
      }
    }
}

double ParticlePair3DCalculator::getMassFor(ParticleFilter* pf)
{
  int pdgCode = getPidFor(pf);
  particleDb = Manager<ParticleDb>::getObjectAt(0);
  ParticleType * particleType = particleDb->findPdgCode(pdgCode);
  return particleType->getMass();

void ParticlePair3DCalculator::execute()
{
  if (reportStart(__FUNCTION__))  { /* */ };


  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  int nEventFilters    = eventFilters.size();
  int nParticleFilters = particleFilters.size();

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printValue("nEventFilters",nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    }
  vector<double> masses;
  for (auto particleFilter : particleFilters)
    {
    masses.push_back(getMassFor(particleFilter));
    }


  for (int iEventFilter = 0; iEventFilter<nEventFilters;iEventFilter++)
    {
    unsigned int  baseSingle   = iEventFilter*nParticleFilters;
    unsigned int  basePair     = iEventFilter*nParticleFilters*nParticleFilters;
    for (int iParticleFilter1 = 0; iParticleFilter1<nParticleFilters;iParticleFilter1++)
      {
      int indexSingle1 = baseSingle + iParticleFilter1;
      ParticleSingleHistos & bSingleHistos1 = (ParticleSingleHistos &) getGroupAt(0,indexSingle1);
      ParticleSingleDerivedHistos &dSingleHistos1 = (ParticleSingleDerivedHistos &)  getGroupAt(2,indexSingle1);
      dSingleHistos1.calculateDerivedHistograms(bSingleHistos1);
      }

    for (int iParticleFilter1 = 0; iParticleFilter1<nParticleFilters;iParticleFilter1++)
      {
      int indexSingle1 = baseSingle + iParticleFilter1;
      ParticleSingleHistos & bSingleHistos1 = (ParticleSingleHistos &) getGroupAt(0,indexSingle1);
      //ParticleSingleDerivedHistos & dSingleHistos1 = (ParticleSingleDerivedHistos &) getGroupAt(2,indexSingle1);
      for (int iParticleFilter2 = 0; iParticleFilter2<nParticleFilters;iParticleFilter2++)
        {
        int indexSingle2 = baseSingle + iParticleFilter2;
        int indexPairs12 = basePair   + iParticleFilter1*nParticleFilters + iParticleFilter2;
        ParticleSingleHistos &bSingleHistos2 = (ParticleSingleHistos &)        getGroupAt(0,indexSingle2);
        //ParticleSingleDerivedHistos &dSingleHistos2 = (ParticleSingleDerivedHistos &) getGroupAt(2,indexSingle2);
        ParticlePair3DHistos &bPairHistos = (ParticlePair3DHistos &) getGroupAt(1,indexPairs12);
        ParticlePair3DDerivedHistos & dPairHistos = (ParticlePair3DDerivedHistos &) getGroupAt(3,indexPairs12);
        dpairHistos.setMasses(masses[iParticleFilter1],masses[iParticleFilter2]);
        dPairHistos.calculatePairDerivedHistograms(bSingleHistos1,bSingleHistos2,bPairHistos);
        }
      }
    }

  if (reportEnd(__FUNCTION__))   { /* */ };
}

void ParticlePair3DCalculator::scaleHistograms()
{
// no ops
}


} // namespace CAP
