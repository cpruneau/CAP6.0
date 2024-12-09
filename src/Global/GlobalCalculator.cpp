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
#include "GlobalCalculator.hpp"
#include "GlobalHistos.hpp"
#include "GlobalDerivedHistos.hpp"

ClassImp(CAP::GlobalCalculator);

namespace CAP
{

GlobalCalculator::GlobalCalculator()
:
EventTask()
{
  appendClassName("GlobalCalculator");
  setName("Global");
  setTitle("Global");
  setVersion("1.0");
}

GlobalCalculator::GlobalCalculator(const GlobalCalculator & analyzer)
:
EventTask(analyzer)
{   }

GlobalCalculator & GlobalCalculator::operator=(const GlobalCalculator & analyzer)
{
  if (this!=&analyzer)
    {
    EventTask::operator=(analyzer);
    }
  return *this;
}

void GlobalCalculator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName","Global");
  addProperty("FillCorrelationHistos",false);
  addProperty("Fill2D",               false);
  addProperty("nBins_n",              500);
  addProperty("nBins_n2",              50);
  addProperty("Min_n",                0.0);
  addProperty("Max_n",                5000.0);
  addProperty("nBins_e",              500);
  addProperty("nBins_e2",              50);
  addProperty("Min_e",                0.0);
  addProperty("Max_e",                10000.0);
  addProperty("nBins_q",              200);
  addProperty("nBins_q2",              20);
  addProperty("Min_q",                -100.0);
  addProperty("Max_q",                100.0);
  addProperty("nBins_s",              200);
  addProperty("nBins_s2",              20);
  addProperty("Min_s",                -100.0);
  addProperty("Max_s",                100.0);
  addProperty("nBins_b",              200);
  addProperty("nBins_b2",              20);
  addProperty("Min_b",                -100.0);
  addProperty("Max_b",                100.0);
  addProperty("nBins_ptSum",           100.0);
  addProperty("nBins_ptSum2",          10.0);
  addProperty("Min_ptSum",             0.0);
  addProperty("Max_ptSum",             10000.0);
  addProperty("nBins_ptAvg",           100.0);
  addProperty("nBins_ptAvg2",          10.0);
  addProperty("Min_ptAvg",             0.0);
  addProperty("Max_ptAvg",             10.0);
}

void GlobalCalculator::configure()
{
  EventTask::configure();
}

void GlobalCalculator::initialize()
{
  EventTask::initialize();
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  unsigned int nEventFilters    = eventFilters.size();;
  unsigned int nParticleFilters = particleFilters.size();
  if (nEventFilters<1 || nParticleFilters<1)
    throw NoFilterGlobalException(nEventFilters,nParticleFilters,__FUNCTION__);
  clearSets();
  addSet("global");
  addSet("derived");
  HistogramTask::importHistograms();
  createHistograms();
}

void GlobalCalculator::importHistograms(TFile & inputFile)
{
  String bn = getValueString( "HistogramBaseName");
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    String name = bn;
    name += "_";
    name += efn;
    GlobalHistos * histos = new GlobalHistos();
    histos->setName(name);
    histos->setConfiguration(configuration);
    histos->setParentTask(this);
    histos->setParticleFilters(particleFilters);
    histos->importHistograms(inputFile);
    addGroupInSet(0,histos);
    }
  //if (reportEnd(__FUNCTION__)) { /* no ops */  };
}

void GlobalCalculator::createHistograms()
{
//  printCR();
//  printString("GlobalCalculator::createHistograms()");
  String bn = getValueString( "HistogramBaseName");
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    String name = bn;
    name += "_";
    name += efn;
    GlobalDerivedHistos * histos = new GlobalDerivedHistos();
    histos->setName(name);
    histos->setConfiguration(configuration);
    histos->setParticleFilters(particleFilters);
    histos->setParentTask(this);
    histos->createHistograms();
    addGroupInSet(1,histos);
    }
  //if (reportEnd(__FUNCTION__)) { /* no ops */  };
}

void GlobalCalculator::execute()
{
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printString("Nothing to do");
    }
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  for (unsigned int iEventFilter = 0; iEventFilter<eventFilters.size(); iEventFilter++)
    {
    GlobalHistos & baseHistos = (GlobalHistos &) getGroupAt(0,iEventFilter);
    GlobalDerivedHistos & derivedHistos = (GlobalDerivedHistos &) getGroupAt(1,iEventFilter);
    derivedHistos.calculateDerivedHistograms(baseHistos);
    }
}

void GlobalCalculator::scaleHistograms()
{

}


} // namespace CAP

