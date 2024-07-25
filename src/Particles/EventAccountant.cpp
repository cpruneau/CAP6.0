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
#include "EventAccountant.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::EventAccountant);

namespace CAP
{

EventAccountant::EventAccountant()
:
eventsAccepted(0),
filteredEventsAccepted(),
particlesAccepted(0),
filteredParticlesAccepted()
{  /* no ops */ }

EventAccountant::EventAccountant(const EventAccountant & source)
:
eventsAccepted(source.eventsAccepted),
filteredEventsAccepted(source.filteredEventsAccepted),
particlesAccepted(source.particlesAccepted),
filteredParticlesAccepted(source.filteredParticlesAccepted)
{  /* no ops */ }

EventAccountant & EventAccountant::operator=(const EventAccountant & source)
{
  if (this!=&source)
    {
    eventsAccepted            = source.eventsAccepted;
    filteredEventsAccepted    = source.filteredEventsAccepted;
    particlesAccepted         = source.particlesAccepted;
    filteredParticlesAccepted = source.filteredParticlesAccepted;
    }
  return *this;
}

EventAccountant::~EventAccountant()
{
  clear();
}

void EventAccountant::initialize(unsigned int nEventFilters, unsigned int nParticleFilters)
{
  initializeEventsAccepted(nEventFilters);
  initializeParticlesAccepted(nEventFilters,nParticleFilters);
}

void EventAccountant::reset()
{
  resetEventsAccepted();
  resetParticlesAccepted();
}

void EventAccountant::clear()
{
  clearEventsAccepted();
  clearParticlesAccepted();
}

void EventAccountant::print(std::ostream & os, int style, int size) const
{
  printCR(os);
  printLine(os);
  printValue("Total Events Accepted",eventsAccepted,os,style,size);
  int k = 0;
  for (auto counts : filteredEventsAccepted)
    {
    String s = "Event Filter #"; s += k;
    printValue(s,counts,os,style,size);
    }
  printValue("Total Particles Accepted",particlesAccepted);

  for (unsigned int k = 0; k<filteredParticlesAccepted.size(); k++)
    {
    for (unsigned int j = 0; j<filteredParticlesAccepted[k].size(); j++)
      {
      String s = "Event Filter #"; s += k;
      s += " Particles Filter #"; s += j;
      printValue(s,filteredParticlesAccepted[k][j],os,style,size);
      }
    }
}

void EventAccountant::initializeEventsAccepted(unsigned int nEventFilters)
{
  eventsAccepted = 0;
  filteredEventsAccepted.assign(nEventFilters,0);
}

void EventAccountant::incrementEventsAccepted(unsigned int iEventFilter)
{
  eventsAccepted++;
  filteredEventsAccepted[iEventFilter]++;
}

void EventAccountant::resetEventsAccepted()
{
  eventsAccepted = 0;
  for (auto & counts : filteredEventsAccepted)  counts = 0;
}

void EventAccountant::clearEventsAccepted()
{
  resetEventsAccepted();
  filteredEventsAccepted.clear();
}

long EventAccountant::getTotalEventsAccepted() const
{
  return eventsAccepted;
}

std::vector<long> & EventAccountant::getFilteredEventCounts()
{
  return filteredEventsAccepted;
}

const std::vector<long> & EventAccountant::getFilteredEventCounts() const
{
  return filteredEventsAccepted;
}

void EventAccountant::initializeParticlesAccepted(unsigned int nEventFilters, unsigned int nParticleFilters)
{
  particlesAccepted = 0;
  std::vector<long> zero;
  zero.assign(nParticleFilters,0);
  filteredParticlesAccepted.assign(nEventFilters, zero);
}

void EventAccountant::incrementParticlesAccepted(unsigned int iEventFilter, unsigned int iParticleFilter)
{
  particlesAccepted++;
  filteredParticlesAccepted[iEventFilter][iParticleFilter]++;
}

void EventAccountant::resetParticlesAccepted()
{
  for (unsigned int k=0; k<filteredParticlesAccepted.size(); k++)
    {
    for (unsigned int j=0; j<filteredParticlesAccepted[k].size(); j++)
      filteredParticlesAccepted[k][j] = 0;
    }
}

void EventAccountant::clearParticlesAccepted()
{
  resetParticlesAccepted();
  filteredParticlesAccepted.clear();
}

long EventAccountant::getTotalParticlesAccepted() const
{
  return particlesAccepted;
}

std::vector< std::vector<long> > & EventAccountant::getFilteredParticleCounts()
{
  return filteredParticlesAccepted;
}

const std::vector< std::vector<long> > & EventAccountant::getFilteredParticleCounts() const
{
  return filteredParticlesAccepted;
}

void EventAccountant::exportEventsAccepted(TFile & outputFile)
{
  unsigned int nEventFilters = filteredEventsAccepted.size();
  unsigned int nParticlesFilters = filteredParticlesAccepted[0].size();
  String name = "nEventFilters";
  exportParameter(outputFile,name,nEventFilters);
  name = "nParticlesFilters";
  exportParameter(outputFile,name,nParticlesFilters);
  for (unsigned int iEventFilter=0; iEventFilter<nEventFilters; iEventFilter++)
    {
    name = "nEvents_Filter_"; name += iEventFilter;
    exportParameter(outputFile,name,filteredEventsAccepted[iEventFilter]);
    }
  for (unsigned int iEventFilter = 0; iEventFilter<nEventFilters; iEventFilter++)
    {
    for (unsigned int iParticleFilter = 0; iParticleFilter<nParticlesFilters;iParticleFilter++)
      {
      String name = "nParticles_Filter_";
      name += iEventFilter;
      name += "_";
      name += iParticleFilter;
      exportParameter(outputFile,name,filteredParticlesAccepted[iEventFilter][iParticleFilter]);
      }
    }
}

void EventAccountant::importEventsAccepted(TFile & inputFile)
{
  String name = "nEventFilters";
  unsigned int nEventFilters = importParameter(inputFile,name);
  name = "nParticlesFilters";
  unsigned int nParticlesFilters = importParameter(inputFile,name);

  filteredEventsAccepted.clear();
  filteredParticlesAccepted.clear();
  for (unsigned int iEventFilter=0; iEventFilter<nEventFilters; iEventFilter++)
    {
    name = "nEvents_Filter_"; name += iEventFilter;
    filteredEventsAccepted.push_back( importParameter(inputFile,name) );
    }
  std::vector<long> partCounts;
  for (unsigned int iEventFilter = 0; iEventFilter<nEventFilters; iEventFilter++)
    {
    partCounts.clear();
    for (unsigned int iParticleFilter = 0; iParticleFilter<nParticlesFilters;iParticleFilter++)
      {
      String name = "nParticles_Filter_";
      name += iEventFilter;
      name += "_";
      name += iParticleFilter;
      partCounts.push_back( importParameter(inputFile,name) );
      }
    filteredParticlesAccepted.push_back( partCounts);
    }
}

} // namespace CAP



