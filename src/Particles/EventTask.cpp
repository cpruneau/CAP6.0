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
#include "EventTask.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::EventTask);

namespace CAP
{

EventTask::EventTask()
:
HistogramTask(),
Manager<ParticleDb>(),
Manager<Event>(),
Manager<EventFilter>(),
Manager<ParticleFilter>(),
EventAccountant(),
particleFactory(nullptr),
particleDb(nullptr),
nEventFilters(0),
nParticleFilters(0),
eventFilterAccepted(),
particleFilterAccepted(),
particleFilterCount(),
particleFilterPtSum(),
allParticlesAccepted()
{
  appendClassName("EventTask");
  setName("EventTask");
  setTitle("EventTask");
  setVersion("1.0");
}

EventTask::EventTask(const EventTask & task)
:
HistogramTask(task),
Manager<ParticleDb>(task),
Manager<Event>(task),
Manager<EventFilter>(task),
Manager<ParticleFilter>(task),
EventAccountant(task),
particleFactory(task.particleFactory),
particleDb(nullptr),
nEventFilters(0),
nParticleFilters(0),
eventFilterAccepted(),
particleFilterAccepted(),
particleFilterCount(),
particleFilterPtSum(),
allParticlesAccepted()
{   }

EventTask & EventTask::operator=(const EventTask & task)
{
  if (this!=&task)
    {
    HistogramTask::operator=(task);
    Manager<ParticleDb>::operator=(task);
    Manager<Event>::operator=(task);
    Manager<EventFilter>::operator=(task);
    Manager<ParticleFilter>::operator=(task);
    EventAccountant::operator=(task);
    particleFactory      = task.particleFactory;
    particleDb           = task.particleDb;
    nEventFilters        = task.nEventFilters;
    nParticleFilters     = task.nParticleFilters;
    eventFilterAccepted  = task.eventFilterAccepted;
    particleFilterAccepted = task.particleFilterAccepted;
    particleFilterCount  = task.particleFilterCount;
    particleFilterPtSum  = task.particleFilterPtSum;
    allParticlesAccepted = task.allParticlesAccepted;
    }
  return *this;
}

//!
//! Initialize the configuration parameter of the EventTask to their default value;
//!
void EventTask::setDefaultConfiguration()
{
  HistogramTask::setDefaultConfiguration();
}

//!
//! Set configuration parameters of this EventTask to values in the given config;
//!
void EventTask::configure()
{
  HistogramTask::configure();
}

//!
//! Initialize this EventTask instance. Implement this method in a derived class if the functionality provided in this base class is insufficient.
//!
void EventTask::initialize()
{
  if (reportDebug(__FUNCTION__))
    { /* no ops */  };
  HistogramTask::initialize();
  TaskAccountant::reset();
  particleFactory = Particle::getFactory();
  particleDb = Manager<ParticleDb>::getObjectAt(0);
  eventFilters     = Manager<EventFilter>::getObjects();
  particleFilters  = Manager<ParticleFilter>::getObjects();
  nEventFilters    = eventFilters.size();
  nParticleFilters = particleFilters.size();
  if (nEventFilters<1) throw TaskException("nEventFilters<1",__FUNCTION__);
  if (nParticleFilters<1) throw TaskException("nParticleFilters<1",__FUNCTION__);
  EventAccountant::initialize(nEventFilters,nParticleFilters);
  eventFilterAccepted.assign(nEventFilters,false);
  particleFilterAccepted.assign(nParticleFilters,false);
  particleFilterCount.assign(nParticleFilters,0);
  particleFilterPtSum.assign(nParticleFilters,0);
  particleFilterPt2Sum.assign(nParticleFilters,0);
  particleFilterPt3Sum.assign(nParticleFilters,0);
  particleFilterPt4Sum.assign(nParticleFilters,0);
  std::vector<Particle*> dummy;
  dummy.reserve(4000);
  allParticlesAccepted.assign(nParticleFilters,dummy);
  if (reportEnd(__FUNCTION__)) { /* no ops */ }
}


//!
//! Finalize this Task instance. Implement this method in a derived class if the functionality provided in this base class is insufficient.
//!
void EventTask::finalize()
{
  bool scaleHistos = getValueBool("HistogramsScale");
  if (scaleHistos) scaleHistograms();
  String exportPath = getHistoExportPath();
  String exportFile = getHistoExportFile();
  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("Histos Export Path",exportPath);
    printValue("Histos Export File",exportFile);
    printLine();
    }
  if (exportPath.Length()>2) createDirectory(exportPath);
  if (exportFile.Length()<5)
    throw FileException(exportFile,"File name too short. Must have 5 character or more...",__FUNCTION__);
  TFile * rootOutputFile;
  if (histogramsForceRewrite())
    rootOutputFile = openRecreateRootFile(exportPath,exportFile);
  else
    rootOutputFile = openNewRootFile(exportPath,exportFile);
  exportHistograms(*rootOutputFile);
  exportNEexecutedTask(*rootOutputFile);
  exportEventsAccepted(*rootOutputFile);
  rootOutputFile->Close();
  if (reportDebug(__FUNCTION__)) print();
  TaskAccountant::clear();
  EventAccountant::clear();
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

//!
//! Reset this Task instance. Implement this method in a derived class if the functionality provided in this base class is insufficient.
//!
void EventTask::reset()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  TaskAccountant::reset();
  EventAccountant::reset();
  Manager<Event>::reset();
  resetHistograms();
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

//!
//! Clear this Task instance. Implement this method in a derived class if the functionality provided in this base class is insufficient.
//!
void EventTask::clear()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ }
  TaskAccountant::clear();
  EventAccountant::clear();
  Manager<Event>::clear();
  Manager<EventFilter>::clear();
  Manager<ParticleFilter>::clear();
  clearHistograms();
  if (hasSubTasks()) clearSubTasks();
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

void EventTask::print(std::ostream & os,int style, int size) const
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  printCR(os);
  printLine(os);
  TaskAccountant::print(os,style,size);
  EventAccountant::print(os,style,size);
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

//!
//!Preview whether the given event should be analyze based on the event filter provided.
//!An array of bools is produced on output which indicates what filters are satisfied by the event.
//!
bool EventTask::analyzeThisEvent(Event & event,
                      std::vector<EventFilter*> & eventFilters,
                      std::vector<bool> & eventFilterAccepted)
{
  bool analyzeEvent = false;
  unsigned int iEventFilter=0;
  for (auto & eventFilter : eventFilters)
    {
    if (eventFilter->accept(event))
      {
      incrementEventsAccepted(iEventFilter);
      eventFilterAccepted[iEventFilter] = true;
      analyzeEvent = true;
      }
    else
      {
      eventFilterAccepted[iEventFilter] = false;
      }
    iEventFilter++;
    }
  return analyzeEvent;
}

//!
//!Preview whether the given event should be analyze based on the particle filter provided.
//!An array of bools is produced on output which indicates what particles satisfy the particle filters.
//!
bool EventTask::analyzeThisEvent(std::vector<Particle*>  & particles,
                      std::vector<ParticleFilter*> & particleFilters,
                      std::vector<bool> & particleFilterAccepted,
                      std::vector< std::vector<Particle*> > & allParticlesAccepted)
{
  bool analyzeEvent = false;
  unsigned int iParticleFilter = 0;
  for (auto & particleFilter : particleFilters)
    {
    bool useThisFilter = false;
    std::vector<Particle*> & particlesAccepted = allParticlesAccepted[iParticleFilter];
    particlesAccepted.clear();
    for (auto & particle : particles)
      {
      if (particleFilter->accept(*particle))
        {
        useThisFilter = true; // at least one particle accepted
        particlesAccepted.push_back(particle);
        }
      }
    particleFilterAccepted[iParticleFilter] = useThisFilter;
    if (useThisFilter) analyzeEvent = true;
    iParticleFilter++;
    }
  return analyzeEvent;
}

//!
//!Preview whether the given event should be analyze based on the particle filter provided.
//!and count particles for type of filter given.
//!
bool EventTask::countParticles(std::vector<Particle*>  & particles,
                               std::vector<ParticleFilter*> & particleFilters,
                               std::vector<double> & particleFilterCount)
{
  bool analyzeEvent = false;
  unsigned int iParticleFilter = 0;
  for (auto & particleFilter : particleFilters)
    {
    unsigned int count = 0;
    for (auto & particle : particles)
      {
      if (particleFilter->accept(*particle)) count++;
      }
    particleFilterCount[iParticleFilter] = count;
    if (count>0) analyzeEvent = true;
    iParticleFilter++;
    }
  return analyzeEvent;
}


//!
//!Preview whether the given event should be analyze based on the particle filter provided.
//!and count particles for type of filter given.
//!
bool EventTask::countPtSum(std::vector<Particle*>  & particles,
                           std::vector<ParticleFilter*> & particleFilters,
                           std::vector<double> & particleFilterCount,
                           std::vector<double> & particleFilterPtSum,
                           std::vector<double> & particleFilterPt2Sum,
                           std::vector<double> & particleFilterPt3Sum,
                           std::vector<double> & particleFilterPt4Sum)
{
  bool analyzeEvent = false;
  unsigned int iParticleFilter = 0;
  for (auto & particleFilter : particleFilters)
    {
    unsigned int count = 0;
    double pt, pt2, pt3, pt4;
    double ptSum = 0.0;
    double pt2Sum = 0.0;
    double pt3Sum = 0.0;
    double pt4Sum = 0.0;
    for (auto & particle : particles)
      {
      if (particleFilter->accept(*particle)) 
        { 
        count++;
        pt = particle->getMomentum().Pt();
        pt2 = pt*pt;
        pt3 = pt2*pt;
        pt4 = pt3*pt;
        ptSum  += pt;
        pt2Sum += pt2;
        pt3Sum += pt3;
        pt4Sum += pt4;
        }
      }
    particleFilterCount[iParticleFilter]  = count;
    particleFilterPtSum[iParticleFilter]  = ptSum;
    particleFilterPt2Sum[iParticleFilter] = pt2Sum;
    particleFilterPt3Sum[iParticleFilter] = pt3Sum;
    particleFilterPt4Sum[iParticleFilter] = pt4Sum;
    if (count>0) analyzeEvent = true;
    iParticleFilter++;
    }
  return analyzeEvent;
}



} // namespace CAP



