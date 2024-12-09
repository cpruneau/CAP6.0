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
#include "ParticleFlowCalculator.hpp"
#include "MathConstants.hpp"
#include "ParticleFlowHistos.hpp"
#include "ParticleFlowDerivedHistos.hpp"

ClassImp(CAP::ParticleFlowCalculator);

namespace CAP
{

ParticleFlowCalculator::ParticleFlowCalculator()
:
EventTask()
{
  appendClassName("ParticleFlowCalculator");
  setName("Flow");
  setTitle("Flow");
}

ParticleFlowCalculator::ParticleFlowCalculator(const ParticleFlowCalculator & task)
:
EventTask(task)
{   }

ParticleFlowCalculator & ParticleFlowCalculator::operator=(const ParticleFlowCalculator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}

void ParticleFlowCalculator::setDefaultConfiguration()
{
  HistogramTask::setDefaultConfiguration();
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
}

void ParticleFlowCalculator::configure()
{
  EventTask::configure();
}

void ParticleFlowCalculator::initialize()
{
  if (reportStart(__FUNCTION__)) { /* */ }
  EventTask::initialize();
  unsigned int nEventFilters    = Manager<EventFilter>::getNObjects();
  unsigned int nParticleFilters = Manager<ParticleFilter>::getNObjects();
  if (nEventFilters<1 || nParticleFilters<1)
    throw NoFilterParticleFlowException(nEventFilters,nParticleFilters,__FUNCTION__);
  clearSets();
  addSet("Flow");
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

void ParticleFlowCalculator::importHistograms(TFile & inputFile)
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
      ParticleFlowHistos * histos = new ParticleFlowHistos();
      histos->setParentTask(this);
      histos->setConfiguration(configuration);
      histos->setName(createName(bn,efn,pfn));
      histos->importHistograms(inputFile);
      addGroupInSet(0,histos);
      }
    }
  if (reportEnd(__FUNCTION__)) { /* */ }
}

void ParticleFlowCalculator::createHistograms()
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
      ParticleFlowDerivedHistos * histos = new ParticleFlowDerivedHistos();
      histos->setParentTask(this);
      histos->setConfiguration(configuration);
      histos->setName(createName(bn,efn,pfn));
      histos->createHistograms();
      addGroupInSet(1,histos);
      }
    }
  if (reportEnd(__FUNCTION__)) { /* */ };
}


void ParticleFlowCalculator::execute()
{
  if (reportStart(__FUNCTION__)) { /* */ };
  unsigned int index = 0;
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  for (unsigned int iEventFilter=0;iEventFilter<eventFilters.size();iEventFilter++)
    {
    for (unsigned int iParticleFilter=0;iParticleFilter<particleFilters.size();iParticleFilter++)
      {
      ParticleFlowHistos & baseHistos = (ParticleFlowHistos &) getGroupAt(0,index);
      ParticleFlowDerivedHistos & derivedHistos = (ParticleFlowDerivedHistos &)  getGroupAt(1,index);
      derivedHistos.calculateDerivedHistograms(baseHistos);
      index++;
      }
    }
    if (reportEnd(__FUNCTION__)){ /* */ };
}

void ParticleFlowCalculator::scaleHistograms()
{

}

} // namespace CAP
