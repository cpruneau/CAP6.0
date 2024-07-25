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
#ifndef CAP__EventCountHistos
#define CAP__EventCountHistos
#include "HistogramGroup.hpp"
#include "Configuration.hpp"
#include "EventFilter.hpp"
#include "ParticleFilter.hpp"

namespace CAP
{

class EventCountHistos : public HistogramGroup
{
public:

  EventCountHistos();

  EventCountHistos(const EventCountHistos & group);

  EventCountHistos & operator=(const EventCountHistos & group);

  void cloneAll(const EventCountHistos & group);

  virtual ~EventCountHistos(){}
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void fill(long taskExecuted,
                    vector<long> & nEventsAccepted,
                    vector<long> & nParticleAccepted);

protected:

  TH1 * h_taskExecuted;
  TH1 * h_eventAccepted;
  TH1 * h_particleAccepted;

  vector<EventFilter*> eventFilters;
  vector<ParticleFilter*> particleFilters;

  ClassDef(EventCountHistos,0)

};

} // namespace CAP

#endif /* CAP__EventCountHistos  */



