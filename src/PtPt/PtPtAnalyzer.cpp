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
#include "PtPtAnalyzer.hpp"
#include "PtPtHistos.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::PtPtAnalyzer);

namespace CAP
{

PtPtAnalyzer::PtPtAnalyzer()
:
EventTask(),
multName("Mult")
{
  appendClassName("PtPtAnalyzer");
  setName("PtPt");
  setTitle("PtPt");
  setVersion("1.0");
}

PtPtAnalyzer::PtPtAnalyzer(const PtPtAnalyzer & task)
:
EventTask(task),
multName(task.multName)
{   }

PtPtAnalyzer & PtPtAnalyzer::operator=(const PtPtAnalyzer & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    multName = task.multName;
    }
  return *this;
}

void PtPtAnalyzer::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("MultName",   String("All_All_MULT"));
  addProperty("nBins_mult", 200);
  addProperty("Min_mult",   0.0);
  addProperty("Max_mult",   200.0);
}

void PtPtAnalyzer::configure()
{
  EventTask::configure();
  multName  = getValueString("MultName");
}

void PtPtAnalyzer::initialize()
{
  EventTask::initialize();
  clearSets();
  addSet("base");
  createHistograms();
}

void PtPtAnalyzer::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ }
  String bn  = getName();
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  if (reportInfo(__FUNCTION__))
    {
    cout << endl;
    printValue("Creating HistogramGroup","");
    printValue("nEventFilters",    int(nEventFilters));
    printValue("nParticleFilters", int(nParticleFilters));
    cout << endl;
    }
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    PtPtHistos * histos = new PtPtHistos();
    histos->setName(createName(bn,efn));
    histos->setConfiguration(configuration);
    histos->setParentTask(this);
    histos->setParticleFilters(particleFilters);
    histos->createHistograms();
    addGroupInSet(0,histos); // singles in set 0
    }
  if (reportEnd(__FUNCTION__)) { /* no ops */ }
}

void PtPtAnalyzer::execute()
{
  Event & event = *Manager<Event>::getObjectAt(0);
  std::vector<Particle*> & particles = event.getParticles();
  if (!analyzeThisEvent(event,eventFilters,eventFilterAccepted)) return;
  if (!countPtSum(particles,particleFilters,
                  particleFilterCount,
                  particleFilterPtSum,
                  particleFilterPt2Sum,
                  particleFilterPt3Sum,
                  particleFilterPt4Sum) )  return;
  double mult = event.getValueDouble(multName);
  for (unsigned int iEventFilter=0; iEventFilter<nEventFilters;iEventFilter++)
    {
    if (!eventFilterAccepted[iEventFilter]) continue;
    PtPtHistos & histos = (PtPtHistos &) getGroupAt(0,iEventFilter);
    histos.fill(mult,
                particleFilterCount,
                particleFilterPtSum,
                particleFilterPt2Sum,
                particleFilterPt3Sum,
                particleFilterPt4Sum);
    }
}

void PtPtAnalyzer::scaleHistograms()
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
  for (unsigned int iEventFilter=0; iEventFilter< nEventFilters; iEventFilter++)
    {
    printValue("PtPtAnalyzer::scaleHistograms()",iEventFilter);
    getGroupAt(0,iEventFilter).scaleHistograms(factors[iEventFilter]);
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}


} // namespace CAP

