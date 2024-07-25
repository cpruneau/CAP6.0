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
#include "RunAnalysis.hpp"
#include "ParticleDbTask.hpp"
#include "FilterCreator.hpp"
#include "EventIterator.hpp"
#include "FileIterator.hpp"
#include "DerivedHistoIterator.hpp"
#include "BalanceFunctionCalculator.hpp"
#include "SubSampleStatCalculator.hpp"
#include "ParticleDbTask.hpp"
#include "ClosureIterator.hpp"
#include "ClosureCalculator.hpp"
#include "PythiaEventGenerator.hpp"
#include "PythiaEventReader.hpp"
//#include "AmptEventReader.hpp"
#include "TherminatorGenerator.hpp"
//#include "ResonanceGenerator.hpp"
#include "MeasurementSimulator.hpp"
#include "PerformanceAnalyzer.hpp"
#include "GlobalAnalyzer.hpp"
#include "GlobalCalculator.hpp"
#include "SpherocityAnalyzer.hpp"
#include "SpherocityCalculator.hpp"
#include "ParticleSingleAnalyzer.hpp"
#include "ParticleSingleCalculator.hpp"
#include "ParticlePairAnalyzer.hpp"
#include "ParticlePairCalculator.hpp"
#include "NuDynAnalyzer.hpp"
#include "NuDynCalculator.hpp"
#include "PtPtAnalyzer.hpp"
#include "PtPtCalculator.hpp"
#include "Exceptions.hpp"
#include "MathExceptions.hpp"

ClassImp(CAP::RunAnalysis);

namespace CAP
{

RunAnalysis::RunAnalysis()
:
HistogramTask()
{  
  appendClassName("RunAnalysis");
  setName("Run");
  setTitle("Run");
  setVersion("1.0");
}

RunAnalysis::RunAnalysis(const RunAnalysis & task)
:
HistogramTask(task)
{    }


RunAnalysis & RunAnalysis::operator=(const RunAnalysis & task)
{
  if (this!=&task)
    {
    Task::operator=(task);
    }
  return *this;
}

void RunAnalysis::setDefaultConfiguration()
{
  HistogramTask::setDefaultConfiguration();
  addProperty("Name",      String("Run"));
  addProperty("Type",      String("RunAnalysis"));
  addProperty("Severity",  String("Info"));
  addProperty("nSubtasks",       0);
  addProperty("nEventsStreams",  0);
  addProperty("nEventFilters",   0);
  addProperty("nParticleFilters",0);
}

Task * RunAnalysis::createTask(const String & taskTypeName)
{
  Task * task = nullptr;
  if (taskTypeName.EqualTo("ParticleDb")) task = new ParticleDbTask(); 
  else if (taskTypeName.EqualTo("FilterCreator"))        task = new FilterCreator(); 
  else if (taskTypeName.EqualTo("EventIterator"))        task = new EventIterator();
  else if (taskTypeName.EqualTo("FileIterator"))         task = new FileIterator();
  else if (taskTypeName.EqualTo("ClosureIterator"))      task = new ClosureIterator();
  //else if (taskTypeName.EqualTo("DerivedHisto"))         task = new DerivedHistoIterator();
  else if (taskTypeName.EqualTo("Pythia"))               task = new PythiaEventGenerator();
  else if (taskTypeName.EqualTo("PythiaReader"))         task = new PythiaEventReader();
  //else if (taskTypeName.EqualTo("AmptReader"))           task = new AmptReaderReader();
  else if (taskTypeName.EqualTo("Therminator"))          task = new TherminatorGenerator();
  else if (taskTypeName.EqualTo("PerformanceSim"))       task = new MeasurementSimulator();
  else if (taskTypeName.EqualTo("FilterCreator"))        task = new ParticleDbTask();
  else if (taskTypeName.EqualTo("GlobalAnalyzer"))       task = new GlobalAnalyzer(); 
  else if (taskTypeName.EqualTo("SpherocityAnalyzer"))   task = new SpherocityAnalyzer(); 
  else if (taskTypeName.EqualTo("SingleAnalyzer"))       task = new ParticleSingleAnalyzer(); 
  else if (taskTypeName.EqualTo("PairAnalyzer"))         task = new ParticlePairAnalyzer(); 
  else if (taskTypeName.EqualTo("NuDynAnalyzer"))        task = new NuDynAnalyzer();
  else if (taskTypeName.EqualTo("PtPtAnalyzer"))         task = new PtPtAnalyzer();
  else if (taskTypeName.EqualTo("GlobalCalculator"))     task = new GlobalCalculator();
  else if (taskTypeName.EqualTo("SpherocityCalculator")) task = new SpherocityCalculator(); 
  else if (taskTypeName.EqualTo("SingleCalculator"))     task = new ParticleSingleCalculator(); 
  else if (taskTypeName.EqualTo("PairCalculator"))       task = new ParticlePairCalculator(); 
  else if (taskTypeName.EqualTo("NuDynCalculator"))      task = new NuDynCalculator();
  else if (taskTypeName.EqualTo("PtPtCalculator"))       task = new PtPtCalculator();
  else if (taskTypeName.EqualTo("BalanceFctCalculator")) task = new BalanceFunctionCalculator();
  else if (taskTypeName.EqualTo("ClosureCalculator"))    task = new ClosureCalculator();
  else if (taskTypeName.EqualTo("SubSampleStatCalculator")) task = new SubSampleStatCalculator();
  else
    throw UnknownTaskException(taskTypeName,__FUNCTION__);
  return task;
}

Task * RunAnalysis::createTask(Task *parent,
                               const String & taskReferenceName,
                               Configuration & requestedConfiguration)
{
  String taskName;
  String taskTypeName;
  int    nSubtasks;
  int    nParticleDbs;
  int    nEventsStreams;
  int    nEventFilters;
  int    nParticleFilters;
  Task * task;

  if (parent==nullptr)
    {
    taskName         = getValueString("Name");
    taskTypeName     = getValueString("Type");
    nSubtasks        = getValueInt("nSubtasks");
    nParticleDbs     = getValueInt("nParticleDbs");
    nEventsStreams   = getValueInt("nEventsStreams");
    nEventFilters    = getValueInt("nEventFilters");
    nParticleFilters = getValueInt("nParticleFilters");
    task = this;
    task->setName(taskName);
    if (reportInfo(__FUNCTION__))
      {
      printCR();
      printValue("taskName",         taskName);
      printValue("taskTypeName",     taskTypeName);
      printValue("nSubtasks",        nSubtasks);
      printValue("nParticleDbs",     nParticleDbs);
      printValue("nEventsStreams",   nEventsStreams);
      printValue("nEventFilters",    nEventFilters);
      printValue("nParticleFilters", nParticleFilters);
      }
    }
  else
    {
    taskName         = getValueString(taskReferenceName+"Name");
    taskTypeName     = getValueString(taskReferenceName+"Type");
    nSubtasks        = getValueInt(taskReferenceName+"nSubtasks");
    nParticleDbs     = getValueInt(taskReferenceName+"nParticleDbs");
    nEventsStreams   = getValueInt(taskReferenceName+"nEventsStreams");
    nEventFilters    = getValueInt(taskReferenceName+"nEventFilters");
    nParticleFilters = getValueInt(taskReferenceName+"nParticleFilters");
    if (reportInfo(__FUNCTION__))
      {
      printCR();
      printValue("taskName",         taskName);
      printValue("taskTypeName",     taskTypeName);
      printValue("nSubtasks",        nSubtasks);
      printValue("nParticleDbs",     nParticleDbs);
      printValue("nEventsStreams",   nEventsStreams);
      printValue("nEventFilters",    nEventFilters);
      printValue("nParticleFilters", nParticleFilters);
      }
    task = createTask(taskTypeName);
    task->setName(taskName);
    task->setRequestedConfiguration(requestedConfiguration);
    parent->addSubTask(task);
    }

  if (nParticleDbs>0)
    {
    for (int k=0; k<nParticleDbs; k++)
      {
      String referenceName = taskReferenceName;
      referenceName += "ParticleDbName";
      referenceName += k;
      String name = getValueString(referenceName);
      referenceName = taskReferenceName;
      referenceName += "ParticleDbOwner";
      referenceName += k;
      bool owner = getValueBool(referenceName);
      if (reportDebug(__FUNCTION__))
        {
        printCR();
        printValue("ParticleDb Index",k);
        printValue("ParticleDb Name",name);
        printValue("ParticleDb Owner",owner);
        }
      if (owner)
        dynamic_cast<Manager<ParticleDb>*>(task)->create(name);
      else
        dynamic_cast<Manager<ParticleDb>*>(task)->use(name);      }
    }

  if (nEventsStreams>0)
    {
    for (int k=0; k<nEventsStreams; k++) 
      {
      String referenceName = taskReferenceName;
      referenceName += "StreamName";
      referenceName += k;
      String name = getValueString(referenceName);
      referenceName = taskReferenceName;
      referenceName += "StreamOwner";
      referenceName += k;
      bool owner = getValueBool(referenceName);
      if (reportDebug(__FUNCTION__))
        {
        printCR();
        printValue("Stream Index",k);
        printValue("Stream Name",name);
        printValue("Stream Owner",owner);
        }
      if (owner)
        dynamic_cast<Manager<Event>*>(task)->create(name);
      else
        dynamic_cast<Manager<Event>*>(task)->use(name);      }
    }

  if (nEventFilters>0)
    {
    for (int k=0; k<nEventFilters; k++)
      {
      String referenceName = taskReferenceName;
      referenceName += "EventFilterName";
      referenceName += k;
      String name = getValueString(referenceName);
      referenceName = taskReferenceName;
      referenceName += "EventFilterOwner";
      referenceName += k;
      bool owner = getValueBool(referenceName);
      if (reportDebug(__FUNCTION__))
        {
        printCR(); printValue("EventFilter Index",k);
        printValue("EventFilter Name",name);
        printValue("EventFilter Owner",owner);
        }
      if (owner)
        dynamic_cast<Manager<EventFilter>*>(task)->create(name);
      else
        dynamic_cast<Manager<EventFilter>*>(task)->use(name);
      }
    }
  if (nParticleFilters>0)
    {
    for (int k=0; k<nParticleFilters; k++)
      {
      String referenceName = taskReferenceName;
      referenceName += "ParticleFilterName";
      referenceName += k;
      String name = getValueString(referenceName);
      referenceName = taskReferenceName;
      referenceName += "ParticleFilterOwner";
      referenceName += k;
      bool owner = getValueBool(referenceName);  
      if (reportDebug(__FUNCTION__))
        {
        printCR();
        printValue("ParticleFilter Index",k);
        printValue("ParticleFilter Name",name);
        printValue("ParticleFilter Owner",owner);
        }
      if (owner)
        dynamic_cast<Manager<ParticleFilter>*>(task)->create(name);
      else
        dynamic_cast<Manager<ParticleFilter>*>(task)->use(name);      }
    }
  if (task != this) task->configure();

  if (nSubtasks>0)
    {
    for (int k=0; k<nSubtasks; k++)
      {
      String subtaskReferenceName = taskReferenceName;
      subtaskReferenceName += "Subtask";
      subtaskReferenceName += k;
      subtaskReferenceName += ":";
      createTask(task,subtaskReferenceName,requestedConfiguration);
      }
    }
  return task;
}

void RunAnalysis::configure()
{
  try {
    HistogramTask::configure();
    createTask(nullptr,"",*requestedConfiguration);
    printLine();
    printLine();
  }
  catch (TaskException & te)
  {
  te.print(); exit(1);
  }
  catch (ConfigurationException & ce)
  {
  ce.print(); exit(1);
  }
  catch (MathException & me)
  {
  me.print(); exit(1);
  }
  catch (FileException & fe)
  {
  fe.print(); exit(1);
  }
  catch (MemoryException & mme)
  {
  mme.print(); exit(1);
  }
  catch (HistogramException & he)
  {
  he.print(); exit(1);
  }
  catch (FactoryException & ffe)
  {
  ffe.print(); exit(1);
  }
  catch (Exception & e)
  {
  e.print(); exit(1);
  }

  if (reportInfo(__FUNCTION__)) printString("Configuration completed.");
}

void RunAnalysis::execute()
{
  try
  {
  initializeSubTasks();
  executeSubTasks();
  }
  catch (TaskException & te)
  {
  te.print(); exit(1);
  }
  catch (ConfigurationException & ce)
  {
  ce.print(); exit(1);
  }
  catch (MathException & me)
  {
  me.print(); exit(1);
  }
  catch (FileException & fe)
  {
  fe.print(); exit(1);
  }
  catch (MemoryException & mme)
  {
  mme.print(); exit(1);
  }
  catch (HistogramException & he)
  {
  he.print(); exit(1);
  }
  catch (FactoryException & ffe)
  {
  ffe.print(); exit(1);
  }
  catch (Exception & e)
  {
  e.print(); exit(1);
  }
}


} // namespace CAP
