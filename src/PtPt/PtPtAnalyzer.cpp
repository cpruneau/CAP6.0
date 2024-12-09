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
evtClassType(0)
{
  appendClassName("PtPtAnalyzer");
  setName("PtPt");
  setTitle("PtPt");
}

PtPtAnalyzer::PtPtAnalyzer(const PtPtAnalyzer & task)
:
EventTask(task),
evtClassType(task.evtClassType)
{   }

PtPtAnalyzer & PtPtAnalyzer::operator=(const PtPtAnalyzer & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    evtClassType = task.evtClassType;
    }
  return *this;
}

void PtPtAnalyzer::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName","PtPt");
  addProperty("EvtClassName",   String("ALL"));
  addProperty("nBins_EvtClass", 200);
  addProperty("Min_EvtClass",   0.0);
  addProperty("Max_EvtClass",   200.0);
}

void PtPtAnalyzer::configure()
{
  EventTask::configure();
}

void PtPtAnalyzer::initialize()
{
  EventTask::initialize();
  clearSets();
  addSet("base");
  String evtClassName  = getValueString("EvtClassName");
  if (evtClassName.EqualTo("ALL") || evtClassName.EqualTo("All"))
    evtClassType = EventFilter::kAll;
  else if (evtClassName.EqualTo("MB"))
    evtClassType = EventFilter::kMB;
  else if (evtClassName.EqualTo("CL_0"))
    evtClassType = EventFilter::kCl0;
  else if (evtClassName.EqualTo("CL_1"))
    evtClassType = EventFilter::kCl1;
  else if (evtClassName.EqualTo("CL_2"))
    evtClassType = EventFilter::kCl2;
  else if (evtClassName.EqualTo("CL_3"))
    evtClassType = EventFilter::kCl3;
  else if (evtClassName.EqualTo("CL_4"))
    evtClassType = EventFilter::kCl4;
  else if (evtClassName.EqualTo("Mult_0"))
    evtClassType = EventFilter::kMult0;
  else if (evtClassName.EqualTo("Mult_1"))
    evtClassType = EventFilter::kMult1;
  else if (evtClassName.EqualTo("Mult_2"))
    evtClassType = EventFilter::kMult2;
  else if (evtClassName.EqualTo("Mult_3"))
    evtClassType = EventFilter::kMult3;
  else if (evtClassName.EqualTo("Mult_4"))
    evtClassType = EventFilter::kMult4;
  else if (evtClassName.EqualTo("SPHERO_0"))
    evtClassType = EventFilter::kSphero0;
  else if (evtClassName.EqualTo("SPHERO_1"))
    evtClassType = EventFilter::kSphero1;
  else if (evtClassName.EqualTo("SPHERO_2"))
    evtClassType = EventFilter::kSphero2;
  else if (evtClassName.EqualTo("SPHERO_3"))
    evtClassType = EventFilter::kSphero3;
  else if (evtClassName.EqualTo("SPHERO_4"))
    evtClassType = EventFilter::kSphero4;
  else if (evtClassName.EqualTo("ENERGY_0"))
    evtClassType = EventFilter::kEnergy0;
  else if (evtClassName.EqualTo("ENERGY_1"))
    evtClassType = EventFilter::kEnergy1;
  else if (evtClassName.EqualTo("ENERGY_2"))
    evtClassType = EventFilter::kEnergy2;
  else if (evtClassName.EqualTo("ENERGY_3"))
    evtClassType = EventFilter::kEnergy3;
  else if (evtClassName.EqualTo("ENERGY_4"))
    evtClassType = EventFilter::kEnergy4;
  else
    throw TaskException("Unknown evtClassName",__FUNCTION__);


  createHistograms();
}

void PtPtAnalyzer::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ }
  String bn = getValueString( "HistogramBaseName");
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
  double mult = getEvtClassValue();
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

double PtPtAnalyzer::getEvtClassValue()
{
  Event & event = *Manager<Event>::getObjectAt(0);
  switch (evtClassType)
    {
      case EventFilter::kAll: return event.getMult0(); break;
      case EventFilter::kMB:  return event.getMult0(); break;
      case EventFilter::kCl0:  return event.getCl0(); break;
      case EventFilter::kCl1:  return event.getCl1(); break;
      case EventFilter::kCl2:  return event.getCl2(); break;
      case EventFilter::kCl3:  return event.getCl3(); break;
      case EventFilter::kCl4:  return event.getCl4(); break;
      case EventFilter::kMult0:  return event.getMult0(); break;
      case EventFilter::kMult1:  return event.getMult1(); break;
      case EventFilter::kMult2:  return event.getMult2(); break;
      case EventFilter::kMult3:  return event.getMult3(); break;
      case EventFilter::kMult4:  return event.getMult4(); break;
      case EventFilter::kSphero0:  return event.getSpherocity0(); break;
      case EventFilter::kSphero1:  return event.getSpherocity1(); break;
      case EventFilter::kSphero2:  return event.getSpherocity2(); break;
      case EventFilter::kSphero3:  return event.getSpherocity3(); break;
      case EventFilter::kSphero4:  return event.getSpherocity4(); break;
      case EventFilter::kEnergy0:  return event.getEnergy0(); break;
      case EventFilter::kEnergy1:  return event.getEnergy1(); break;
      case EventFilter::kEnergy2:  return event.getEnergy2(); break;
      case EventFilter::kEnergy3:  return event.getEnergy3(); break;
      case EventFilter::kEnergy4:  return event.getEnergy4(); break;
      default: throw TaskException("Unknown evtClassType",__FUNCTION__);
    }
  return 0;
}




} // namespace CAP

