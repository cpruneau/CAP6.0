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
#include "NuDynAnalyzer.hpp"
#include "NuDynHistos.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::NuDynAnalyzer);

namespace CAP
{

NuDynAnalyzer::NuDynAnalyzer()
:
EventTask(),
multName("Mult")
{
  appendClassName("NuDynAnalyzer");
  setName("NuDyn");
  setTitle("NuDyn");
  setVersion("1.0");
}

NuDynAnalyzer::NuDynAnalyzer(const NuDynAnalyzer & task)
:
EventTask(task),
multName(task.multName)
{   }

NuDynAnalyzer & NuDynAnalyzer::operator=(const NuDynAnalyzer & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    multName = task.multName;
    }
  return *this;
}

void NuDynAnalyzer::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("MultName",   String("All_All_MULT"));
  addProperty("nBins_mult", 200);
  addProperty("Min_mult",   0.0);
  addProperty("Max_mult",   200.0);
}

void NuDynAnalyzer::configure()
{
  EventTask::configure();
  multName  = getValueString("MultName");
}

void NuDynAnalyzer::initialize()
{
  EventTask::initialize();
  clearSets();
  addSet("base");
  createHistograms();
}

void NuDynAnalyzer::createHistograms()
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
    NuDynHistos * histos = new NuDynHistos();
    histos->setConfiguration(configuration);
    histos->setParentTask(this);
    histos->setName(createName(bn,efn));
    histos->setParticleFilters(particleFilters);
    histos->createHistograms();
    addGroupInSet(0,histos); // singles in set 0
    }
  if (reportEnd(__FUNCTION__)) { /* no ops */ }
}

void NuDynAnalyzer::execute()
{
  Event & event = *Manager<Event>::getObjectAt(0);
  std::vector<Particle*> & particles = event.getParticles();
  if (!analyzeThisEvent(event,eventFilters,eventFilterAccepted)) return;
  if (!countParticles(particles,particleFilters,particleFilterCount))  return;
  double mult = event.getValueDouble(multName);
  for (unsigned int iEventFilter=0; iEventFilter<nEventFilters;iEventFilter++)
    {
    if (!eventFilterAccepted[iEventFilter]) continue;
    NuDynHistos & nuDynHistos = (NuDynHistos &) getGroupAt(0,iEventFilter);
    nuDynHistos.fill(mult,particleFilterCount);
    }
}

void NuDynAnalyzer::scaleHistograms()
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
    printValue("NuDynAnalyzer::scaleHistograms()",iEventFilter);
    getGroupAt(0,iEventFilter).scaleHistograms(factors[iEventFilter]);
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}


} // namespace CAP

