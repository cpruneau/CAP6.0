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
#ifndef CAP__EventTask
#define CAP__EventTask
#include "HistogramTask.hpp"
#include "Factory.hpp"
#include "Manager.hpp"
#include "ParticleDb.hpp"
#include "Event.hpp"
#include "EventFilter.hpp"
#include "ParticleFilter.hpp"
#include "EfficiencyFilter.hpp"
#include "JetFilter.hpp"
#include "TaskAccountant.hpp"
#include "EventAccountant.hpp"

namespace CAP
{

class EventTask
:
public HistogramTask,
public Manager<ParticleDb>,
public Manager<Event>,
public Manager<EventFilter>,
public Manager<ParticleFilter>,
public Manager<EfficiencyFilter>,
public Manager<JetFilter>,
public EventAccountant
{

public:

  EventTask();
  EventTask(const EventTask & analyzer);
  EventTask & operator=(const EventTask & task);
  virtual ~EventTask() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void finalize();
  virtual void reset();
  virtual void clear();
  virtual void print(std::ostream & os=std::cout,int style=0, int size=50) const;

  Factory<Particle> *  getParticleFactory()
  {
  return particleFactory;
  }

  ParticleDb *  getParticleDb()
  {
  return particleDb;
  }

  bool analyzeThisEvent(Event & event,
                        std::vector<EventFilter*> & eventFilters,
                        std::vector<bool> & eventAccepted);
  bool analyzeThisEvent(std::vector<Particle*>  & particles,
                        std::vector<ParticleFilter*> & particleFilters,
                        std::vector<bool> & particleFilterAccepted,
                        std::vector< std::vector<Particle*> > & allParticlesAccepted);

  bool analyzeThisEvent(std::vector<Particle*>  & particles,
                        std::vector<EfficiencyFilter*> & efficiencyFilters,
                        std::vector<bool> & efficiencyFilterAccepted,
                        std::vector< std::vector<Particle*> > & allParticlesAccepted);


  bool countParticles(std::vector<Particle*>  & particles,
                      std::vector<ParticleFilter*> & particleFilters,
                      std::vector<double> & particleFilterAccepted);

  bool countPtSum(std::vector<Particle*>  & particles,
                  std::vector<ParticleFilter*> & particleFilters,
                  std::vector<double> & particleFilterCount,
                  std::vector<double> & particleFilterPtSum,
                  std::vector<double> & particleFilterPt2Sum,
                  std::vector<double> & particleFilterPt3Sum,
                  std::vector<double> & particleFilterPt4Sum);

protected:

  //!
  //! Pointer to a factory of entities of type Particle.
  //!
  Factory<Particle> *  particleFactory;

  ParticleDb * particleDb;

  unsigned int nEventFilters;
  unsigned int nParticleFilters;
  unsigned int nEfficiencyFilters;
  unsigned int nJetFilters;
  std::vector<EventFilter*>      eventFilters;
  std::vector<ParticleFilter*>   particleFilters;
  std::vector<EfficiencyFilter*> efficiencyFilters;
  std::vector<JetFilter*>        jetFilters;
  std::vector<bool>   eventFilterAccepted;
  std::vector<bool>   particleFilterAccepted;
  std::vector<bool>   efficiencyFilterAccepted;
  std::vector<bool>   jetFilterAccepted;
  std::vector<double> particleFilterCount;
  std::vector<double> particleFilterPtSum;
  std::vector<double> particleFilterPt2Sum;
  std::vector<double> particleFilterPt3Sum;
  std::vector<double> particleFilterPt4Sum;
  std::vector< std::vector<Particle*> > allParticlesAccepted;

  ClassDef(EventTask,0)
};

} // namespace CAP

#endif /* CAP__EventTask */
