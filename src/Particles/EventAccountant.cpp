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
filteredEventsAccepted(),
filteredParticlesAccepted()
{  /* no ops */ }

EventAccountant::EventAccountant(const EventAccountant & source)
:
filteredEventsAccepted(source.filteredEventsAccepted),
filteredParticlesAccepted(source.filteredParticlesAccepted)
{  /* no ops */ }

EventAccountant & EventAccountant::operator=(const EventAccountant & source)
{
  if (this!=&source)
    {
    filteredEventsAccepted    = source.filteredEventsAccepted;
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
  int k = 0;
  for (auto counts : filteredEventsAccepted)
    {
    String s = "Event Filter #"; s += k;
    printValue(s,counts,os,style,size);
    }
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
  filteredEventsAccepted.assign(nEventFilters,0);
}

void EventAccountant::incrementEventsAccepted(unsigned int iEventFilter)
{
  filteredEventsAccepted[iEventFilter]++;
}

void EventAccountant::resetEventsAccepted()
{
  for (auto & counts : filteredEventsAccepted)  counts = 0;
}

void EventAccountant::clearEventsAccepted()
{
  resetEventsAccepted();
  filteredEventsAccepted.clear();
}

//!
//! Compute and return the total number of events accepted.
//! This number is only meaningful if the filters used are mutually exclusive.
//! If the event filters are not mutually exclusive, there will be double counting.
//!
long EventAccountant::getTotalEventsAccepted() const
{
  long totalEventsAcccepted = 0;
  for (auto & counts : filteredEventsAccepted)  totalEventsAcccepted += counts;
  return totalEventsAcccepted;
}

std::vector<long> & EventAccountant::getFilteredEventCounts()
{
  return filteredEventsAccepted;
}

const std::vector<long> & EventAccountant::getFilteredEventCounts() const
{
  return filteredEventsAccepted;
}

//!
//!Create an array of nEventFilters x nParticleFilters elements to keep track of the number of partices for each type of event filter and each type of particles of interest.
//!
void EventAccountant::initializeParticlesAccepted(unsigned int nEventFilters, unsigned int nParticleFilters)
{
  std::vector<long> zero;
  zero.assign(nParticleFilters,0);
  filteredParticlesAccepted.assign(nEventFilters, zero);
}

//!
//!Increments the number of particles accepted for the given event filter index and particle index.
//!No bound checking is applied to improve code performance.
//!
void EventAccountant::incrementParticlesAccepted(unsigned int iEventFilter, unsigned int iParticleFilter)
{
  filteredParticlesAccepted[iEventFilter][iParticleFilter]++;
}

//!
//!Reset particle counters to zero
//!
void EventAccountant::resetParticlesAccepted()
{
  for (unsigned int k=0; k<filteredParticlesAccepted.size(); k++)
    {
    for (unsigned int j=0; j<filteredParticlesAccepted[k].size(); j++)
      filteredParticlesAccepted[k][j] = 0;
    }
}

//!
//!Reset particle counters to zero and delete counters
//!
void EventAccountant::clearParticlesAccepted()
{
  resetParticlesAccepted();
  filteredParticlesAccepted.clear();
}

//!
//!Compute and return the total number of particles accepted.
//!This number is meaningful only if the event filter and particle types are
//!mutually exclusive.
//!
long EventAccountant::getTotalParticlesAccepted() const
{
  long totalParticlesAcccepted = 0;
  for (unsigned int k=0; k<filteredParticlesAccepted.size(); k++)
    {
    for (unsigned int j=0; j<filteredParticlesAccepted[k].size(); j++)
      {
      totalParticlesAcccepted += filteredParticlesAccepted[k][j];
      }
    }
  return totalParticlesAcccepted;
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
  //
  // export meta information
  //
  String name = "nEventFilters";
  exportParameter(outputFile,name,nEventFilters);
  name = "nParticlesFilters";
  exportParameter(outputFile,name,nParticlesFilters);

  //
  // export event counts for each event filter
  //
  for (unsigned int iEventFilter=0; iEventFilter<nEventFilters; iEventFilter++)
    {
    name = "nEventsFilter"; name += iEventFilter;
    exportParameter(outputFile,name,filteredEventsAccepted[iEventFilter]);
    }

  //
  // export particle counts for each event and particle filters
  //
  for (unsigned int iEventFilter = 0; iEventFilter<nEventFilters; iEventFilter++)
    {
    for (unsigned int iParticleFilter = 0; iParticleFilter<nParticlesFilters;iParticleFilter++)
      {
      String name = "nParticlesFilter";
      name += iEventFilter;
      name += "_";
      name += iParticleFilter;
      exportParameter(outputFile,name,filteredParticlesAccepted[iEventFilter][iParticleFilter]);
      }
    }
}

void EventAccountant::importEventsAccepted(TFile & inputFile)
{
  unsigned int nEventFilters;
  unsigned int nParticleFilters;
  std::vector<long> eventsAccepted;
  std::vector< std::vector<long> > particlesAccepted;

  try
  {
  //
  // import meta information
  //
  String name;
  name = "nEventFilters";
  nEventFilters = importParameter(inputFile,name);
  name = "nParticlesFilters";
  nParticleFilters = importParameter(inputFile,name);

  //
  // import event counts
  //
  for (unsigned int iEventFilter=0; iEventFilter<nEventFilters; iEventFilter++)
    {
    name = "nEventsFilter"; name += iEventFilter;
    eventsAccepted.push_back( importParameter(inputFile,name) );
    }

  //
  // import particle counts
  //
  std::vector<long> partCounts;
  for (unsigned int iEventFilter = 0; iEventFilter<nEventFilters; iEventFilter++)
    {
    partCounts.clear();
    for (unsigned int iParticleFilter = 0; iParticleFilter<nParticleFilters;iParticleFilter++)
      {
      String name = "nParticlesFilter";
      name += iEventFilter;
      name += "_";
      name += iParticleFilter;
      partCounts.push_back( importParameter(inputFile,name) );
      }
    particlesAccepted.push_back( partCounts);
    }
  }
  catch (PropertyException & pe)
  {
  pe.print();
  throw TaskException("Event/Particle Count Parameter not found in input file",__FUNCTION__);
  }
  
  //
  // tally counts
  //
  for (unsigned int iEventFilter = 0; iEventFilter<nEventFilters; iEventFilter++)
    {
    filteredEventsAccepted[iEventFilter] += eventsAccepted[iEventFilter];

    for (unsigned int iParticleFilter = 0; iParticleFilter<nParticleFilters;iParticleFilter++)
      {
      filteredParticlesAccepted[iEventFilter][iParticleFilter] += particlesAccepted[iEventFilter][iParticleFilter];
      }
    }
}

} // namespace CAP



