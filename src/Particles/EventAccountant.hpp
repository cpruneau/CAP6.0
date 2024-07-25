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
#ifndef CAP__EventAccountant
#define CAP__EventAccountant
#include "Aliases.hpp"
#include "Exceptions.hpp"
#include "TFile.h"

namespace CAP
{
class EventAccountant
{
public:

  EventAccountant();
  EventAccountant(const EventAccountant & analyzer);
  EventAccountant & operator=(const EventAccountant & task);
  virtual ~EventAccountant();
  void initialize(unsigned int nEventFilters=1, unsigned int nParticleFilters=1);
  void reset();
  void clear();
  void print(std::ostream & os=std::cout, int style=0, int size=50) const;

  void initializeEventsAccepted(unsigned int nEventFilters=1);
  void incrementEventsAccepted(unsigned int iEventFilter=0);
  void resetEventsAccepted();
  void clearEventsAccepted();
  long getTotalEventsAccepted() const;
  std::vector<long> & getFilteredEventCounts();
  const std::vector<long> & getFilteredEventCounts() const;
  void exportEventsAccepted(TFile & outputFile);
  void importEventsAccepted(TFile & inputFile);

  void initializeParticlesAccepted(unsigned int nEventFilters=1, unsigned int nParticleFilters=1);
  void incrementParticlesAccepted(unsigned int iEventFilter=0, unsigned int iParticleFilter=0);
  void resetParticlesAccepted();
  void clearParticlesAccepted();
  long getTotalParticlesAccepted() const;
  std::vector< std::vector<long> > & getFilteredParticleCounts();
  const std::vector< std::vector<long> > & getFilteredParticleCounts() const;

protected:
  
  long eventsAccepted;
  std::vector<long> filteredEventsAccepted;

  long particlesAccepted;
  std::vector< std::vector<long> > filteredParticlesAccepted;

  ClassDef(EventAccountant,0)
};

} // namespace CAP

#endif /* CAP__EventAccountant */
