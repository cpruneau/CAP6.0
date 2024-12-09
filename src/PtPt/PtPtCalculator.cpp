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
#include "PtPtCalculator.hpp"
#include "PtPtHistos.hpp"
#include "PtPtDerivedHistos.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"


ClassImp(CAP::PtPtCalculator);

namespace CAP
{

PtPtCalculator::PtPtCalculator()
:
EventTask()
{
  appendClassName("PtPtCalculator");
  setName("PtPt");
  setTitle("PtPt");
}

PtPtCalculator::PtPtCalculator(const PtPtCalculator & task)
:
EventTask(task)
{   }

PtPtCalculator & PtPtCalculator::operator=(const PtPtCalculator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}

PtPtCalculator::~PtPtCalculator()
{  }

void PtPtCalculator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName","PtPt");
  addProperty("nBins_EvtClass",        200);
  addProperty("Min_EvtClass",          0.0);
  addProperty("Max_EvtClass",          200.0);
}

void PtPtCalculator::configure()
{
  HistogramTask::configure();
}

void PtPtCalculator::initialize()
{
  if (reportStart(__FUNCTION__)) { /* */ }
  EventTask::initialize();
  unsigned int nEventFilters    = Manager<EventFilter>::getNObjects();
  unsigned int nParticleFilters = Manager<ParticleFilter>::getNObjects();
  if (nEventFilters<1 || nParticleFilters<1)
    throw TaskException("nEventFilters<1 || nParticleFilters<1",__FUNCTION__);
  clearSets();
  addSet("base");
  addSet("derived");
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("nEventFilters",nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    }
  HistogramTask::importHistograms();
  createHistograms();
}

void PtPtCalculator::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* no ops */ }
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  String bn = getValueString( "HistogramBaseName");
  for (auto & eventFilter : eventFilters)
    {
    String efn  = eventFilter->getName();
    PtPtHistos * histos = new PtPtHistos();
    histos->setConfiguration(configuration);
    histos->setParentTask(this);
    histos->setName(createName(bn,efn));
    histos->setParticleFilters(particleFilters);
    histos->importHistograms(inputFile);
    addGroupInSet(0,histos);
    }
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}

void PtPtCalculator::createHistograms()
{
  if (reportStart(__FUNCTION__))   { /* no ops */ }
  String bn = getValueString( "HistogramBaseName");
  String efn;
  String histoName;
  String pfn;
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  PtPtDerivedHistos * histos;
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    histos = new PtPtDerivedHistos();
    histos->setParentTask(this);
    histos->setConfiguration(configuration);
    histos->setName(createName(bn,efn));
    histos->setParticleFilters(particleFilters);
    histos->createHistograms();
    addGroupInSet(1,histos);
    }

}

void PtPtCalculator::execute()
{
  if (reportStart(__FUNCTION__))   { /* no ops */ }
  for (unsigned int iEventFilter=0; iEventFilter<eventFilters.size(); iEventFilter++ )
    {
    PtPtHistos & baseHistos = (PtPtHistos &) getGroupAt(0,iEventFilter);
    PtPtDerivedHistos & derivedHistos = (PtPtDerivedHistos &) getGroupAt(1,iEventFilter);
    derivedHistos.calculateDerivedHistograms(&baseHistos);
    }
  if (reportEnd(__FUNCTION__))   { /* no ops */ }
}

void PtPtCalculator::scaleHistograms()
{

}

}  // namespace CAP

