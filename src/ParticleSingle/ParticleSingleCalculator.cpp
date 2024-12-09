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
#include "ParticleSingleCalculator.hpp"
#include "MathConstants.hpp"
#include "ParticleSingleHistos.hpp"
#include "ParticleSingleDerivedHistos.hpp"

ClassImp(CAP::ParticleSingleCalculator);

namespace CAP
{

ParticleSingleCalculator::ParticleSingleCalculator()
:
EventTask()
{
  appendClassName("ParticleSingleCalculator");
  setName("Single");
  setTitle("Single");
}

ParticleSingleCalculator::ParticleSingleCalculator(const ParticleSingleCalculator & task)
:
EventTask(task)
{   }

ParticleSingleCalculator & ParticleSingleCalculator::operator=(const ParticleSingleCalculator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}

void ParticleSingleCalculator::setDefaultConfiguration()
{
  HistogramTask::setDefaultConfiguration();
  addProperty( "HistogramBaseName","Single");

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
}

void ParticleSingleCalculator::configure()
{
  EventTask::configure();
}

void ParticleSingleCalculator::initialize()
{
  if (reportStart(__FUNCTION__)) { /* */ }
  EventTask::initialize();
  unsigned int nEventFilters    = Manager<EventFilter>::getNObjects();
  unsigned int nParticleFilters = Manager<ParticleFilter>::getNObjects();
  if (nEventFilters<1 || nParticleFilters<1)
    throw NoFilterParticleSingleException(nEventFilters,nParticleFilters,__FUNCTION__);
  clearSets();
  addSet("single");
  addSet("derived");
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("nEventFilters",nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    }
  HistogramTask::importHistograms();
  createHistograms();
  if (reportEnd(__FUNCTION__)) { /* */ }
}

void ParticleSingleCalculator::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* */ }
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  String bn = getValueString( "HistogramBaseName");
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      ParticleSingleHistos * histos = new ParticleSingleHistos();
      histos->setParentTask(this);
      histos->setConfiguration(configuration);
      histos->setName(createName(bn,efn,pfn));
      histos->importHistograms(inputFile);
      addGroupInSet(0,histos);
      }
    }
  if (reportEnd(__FUNCTION__)) { /* */ }
}

void ParticleSingleCalculator::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* */ };
  String bn = getValueString( "HistogramBaseName");
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      ParticleSingleDerivedHistos * histos = new ParticleSingleDerivedHistos();
      histos->setParentTask(this);
      histos->setConfiguration(configuration);
      histos->setName(createName(bn,efn,pfn));
      histos->createHistograms();
      addGroupInSet(1,histos);
      }
    }
  if (reportEnd(__FUNCTION__)) { /* */ };
}


void ParticleSingleCalculator::execute()
{
  if (reportStart(__FUNCTION__)) { /* */ };
  unsigned int index = 0;
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  for (unsigned int iEventFilter=0;iEventFilter<eventFilters.size();iEventFilter++)
    {
    for (unsigned int iParticleFilter=0;iParticleFilter<particleFilters.size();iParticleFilter++)
      {
      ParticleSingleHistos & baseHistos = (ParticleSingleHistos &) getGroupAt(0,index);
      ParticleSingleDerivedHistos & derivedHistos = (ParticleSingleDerivedHistos &)  getGroupAt(1,index);
      derivedHistos.calculateDerivedHistograms(baseHistos);
      index++;
      }
    }
    if (reportEnd(__FUNCTION__)){ /* */ };
}

void ParticleSingleCalculator::scaleHistograms()
{

}

} // namespace CAP
