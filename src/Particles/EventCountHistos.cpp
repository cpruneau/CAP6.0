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
#include "EventCountHistos.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::EventCountHistos);

using CAP::EventCountHistos;
using CAP::String;
using CAP::Configuration;

EventCountHistos::EventCountHistos()
:
HistogramGroup(),
h_taskExecuted(nullptr),
h_eventAccepted(nullptr),
h_particleAccepted(nullptr)
{
  appendClassName("EventCountHistos");
}


EventCountHistos::EventCountHistos(const EventCountHistos & group)
:
HistogramGroup(group),
h_taskExecuted(nullptr),
h_eventAccepted(nullptr),
h_particleAccepted(nullptr),
eventFilters(),
particleFilters()
{
  cloneAll(group);
}

EventCountHistos & EventCountHistos::operator=(const EventCountHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    cloneAll(group);
    }
  return *this;
}

void EventCountHistos::cloneAll(const EventCountHistos & group)
{
  // ony clone those that exist...
  if (group.h_taskExecuted)     h_taskExecuted = (TH1*) group.h_taskExecuted->Clone();
  if (group.h_eventAccepted)    h_eventAccepted = (TH1*) group.h_eventAccepted->Clone();
  if (group.h_particleAccepted) h_particleAccepted = (TH1*) group.h_particleAccepted->Clone();
  eventFilters    = group.eventFilters;
  particleFilters = group.particleFilters;
}

// for now use the same boundaries for eta and y histogram
void EventCountHistos::createHistograms()
{
  if (reportStart(__FUNCTION__))  { /* no ops */   }
  //setOwnership(true);
  int ne = eventFilters.size();
  int np = particleFilters.size();
  int n = ne*np;
  String bn = getParentName();
  h_taskExecuted     = createHistogram(createName(bn,"taskExecuted"),1,-0.5, 0.5, "taskExecuted", "Count") ;
  h_eventAccepted    = createHistogram(createName(bn,"nEventAccepted"),ne,-0.5, -0.5+double(ne), "event filter", "Count");
  h_particleAccepted = createHistogram(createName(bn,"nParticleAccepted"),n,-0.5, -0.5+double(n), "event x particle filter", "Count");
  if (reportEnd(__FUNCTION__))  { /* no ops */   }
 }

//________________________________________________________________________
void EventCountHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__))  { /* no ops */   }
  String bn = getParentName();
  h_taskExecuted     = importH1(inputFile,createName(bn,"taskExecuted"));
  h_eventAccepted    = importH1(inputFile,createName(bn,"nEventAccepted"));
  h_particleAccepted = importH1(inputFile,createName(bn,"nParticleAccepted"));
  if (reportEnd(__FUNCTION__))  { /* no ops */   }
}

// This fills the event count histogram. Should be called once per histo file save.
void EventCountHistos::fill(long taskExecuted,
                            vector<long> & nEventsAccepted,
                            vector<long> & nParticleAccepted)
{
  if (reportStart(__FUNCTION__))  { /* no ops */   }
  h_taskExecuted->Fill(0.0, double(taskExecuted));
  int ne = eventFilters.size();
  int np = particleFilters.size();
  for (int iEventFilter=0; iEventFilter<ne; iEventFilter++)
    {
    h_eventAccepted->Fill(double(iEventFilter),double(nEventsAccepted[iEventFilter]));
    for (int iParticleFilter=0; iParticleFilter<np; iParticleFilter++)
      {
      int index = iEventFilter*np + iParticleFilter;
      h_particleAccepted->Fill(double(index),double(nParticleAccepted[index]));
      }
    }
  if (reportEnd(__FUNCTION__))  { /* no ops */   }
}

