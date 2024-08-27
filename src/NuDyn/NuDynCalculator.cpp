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
#include "NuDynCalculator.hpp"
#include "NuDynHistos.hpp"
#include "NuDynDerivedHistos.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"


ClassImp(CAP::NuDynCalculator);

namespace CAP
{

NuDynCalculator::NuDynCalculator()
:
EventTask(),
multiplicityType(0)
{
  appendClassName("NuDynCalculator");
  setName("NuDyn");
  setTitle("NuDyn");
  setVersion("1.0");
}

NuDynCalculator::NuDynCalculator(const NuDynCalculator & task)
:
EventTask(task),
multiplicityType(task.multiplicityType)
{   }

NuDynCalculator & NuDynCalculator::operator=(const NuDynCalculator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    multiplicityType = task.multiplicityType;
    }
  return *this;
}

NuDynCalculator::~NuDynCalculator()
{  }

void NuDynCalculator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  //addProperty("InputType",         multiplicityType);
  addProperty("nBins_mult",        200);
  addProperty("Min_mult",          0.0);
  addProperty("Max_mult",          200.0);
  addProperty("nBins_rapidity",    99);
  addProperty("Min_rapidity",      0.100);
  addProperty("Max_rapidity",      10.00);
}

void NuDynCalculator::configure()
{
  HistogramTask::configure();
}

void NuDynCalculator::initialize()
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
  if (reportEnd(__FUNCTION__)) { /* */ }
}

void NuDynCalculator::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* no ops */ }
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  String bn = getName();
  for (auto & eventFilter : eventFilters)
    {
    String efn  = eventFilter->getName();
    NuDynHistos * histos = new NuDynHistos();
    histos->setConfiguration(configuration);
    histos->setParentTask(this);
    histos->setName(createName(bn,efn));
    histos->setParticleFilters(particleFilters);
    histos->importHistograms(inputFile);
    addGroupInSet(0,histos);
    }
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}

void NuDynCalculator::createHistograms()
{
  if (reportStart(__FUNCTION__))   { /* no ops */ }
  String bn = getName(); bn += "_";
  String efn;
  String histoName;
  String pfn;
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  NuDynDerivedHistos * histos;
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    histos = new NuDynDerivedHistos();
    histos->setParentTask(this);
    histos->setConfiguration(configuration);
    histos->setName(createName(bn,efn));
    histos->setParticleFilters(particleFilters);
    histos->createHistograms();
    addGroupInSet(1,histos);
    }
  if (reportEnd(__FUNCTION__))   { /* no ops */ }
}

void NuDynCalculator::execute()
{
  if (reportStart(__FUNCTION__))   { /* no ops */ }
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  //std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  for (unsigned int iEventFilter=0; iEventFilter<eventFilters.size(); iEventFilter++ )
    {
      NuDynHistos & baseHistos    = (NuDynHistos &) getGroupAt(0,iEventFilter);
      NuDynDerivedHistos & derivedHistos = (NuDynDerivedHistos &) getGroupAt(1,iEventFilter);
      derivedHistos.calculateDerivedHistograms(&baseHistos);
    }
  if (reportEnd(__FUNCTION__))   { /* no ops */ }
}

}  // namespace CAP

