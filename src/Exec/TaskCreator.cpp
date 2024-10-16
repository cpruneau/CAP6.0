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
#include "TaskCreator.hpp"
#include "TClass.h"
#include "ParticleDb.hpp"
#include "Event.hpp"
#include "EventFilter.hpp"
#include "ParticleFilter.hpp"


ClassImp(CAP::TaskCreator);

namespace CAP
{

TaskCreator::TaskCreator()
:
Task(),
targetTaskName("RunAnalysis:"),
targetTask(nullptr)

{
  appendClassName("TaskCreator");
  setName("TaskCreator");
  setTitle("TaskCreator");
}

TaskCreator::TaskCreator(const TaskCreator & task)
:
Task(task)
{    }


TaskCreator & TaskCreator::operator=(const TaskCreator & task)
{
  if (this!=&task)
    {
    Task::operator=(task);
    }
  return *this;
}

void TaskCreator::setDefaultConfiguration()
{
  Task::setDefaultConfiguration();
  configuration.addProperty("TaskCreator:Severity","Info");
 }

void TaskCreator::configure()
{
  Task::configure();
}

Task * TaskCreator::createTask(const String & taskClassName)
{
  TClass *taskClass = TClass::GetClass(taskClassName);
  if (!taskClass) throw UnknownTaskException(taskClassName,__FUNCTION__);
  return (Task*)taskClass->New();
}

void TaskCreator::configureDbs(Task * task,
                               const String  & taskReferenceName,
                               Configuration & requestedConfiguration)
{
  int nParticleDbs = requestedConfiguration.getValueInt(taskReferenceName+"nParticleDbs");
  for (int k=0; k<nParticleDbs; k++)
    {
    String referenceName = taskReferenceName;
    referenceName += "ParticleDbName";
    referenceName += k;
    String name = requestedConfiguration.getValueString(referenceName);
    referenceName = taskReferenceName;
    referenceName += "ParticleDbOwner";
    referenceName += k;
    bool owner = requestedConfiguration.getValueBool(referenceName);
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

void TaskCreator::configureEventsStreams(Task * task,
                                         const String  & taskReferenceName,
                                         Configuration & requestedConfiguration)
{
  int nEventsStreams = requestedConfiguration.getValueInt(taskReferenceName+"nEventsStreams");
  for (int k=0; k<nEventsStreams; k++)
    {
    String referenceName = taskReferenceName;
    referenceName += "StreamName";
    referenceName += k;
    String name = requestedConfiguration.getValueString(referenceName);
    referenceName = taskReferenceName;
    referenceName += "StreamOwner";
    referenceName += k;
    bool owner = requestedConfiguration.getValueBool(referenceName);
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

void TaskCreator::configureEventFilters(Task * _task,
                                        const String  & taskReferenceName,
                                        Configuration & requestedConfiguration)
{
  int nEventFilters = requestedConfiguration.getValueInt(taskReferenceName+"nEventFilters");
  for (int k=0; k<nEventFilters; k++)
    {
    String referenceName = taskReferenceName;
    referenceName += "EventFilterName";
    referenceName += k;
    String name = requestedConfiguration.getValueString(referenceName);
    referenceName = taskReferenceName;
    referenceName += "EventFilterOwner";
    referenceName += k;
    bool owner = requestedConfiguration.getValueBool(referenceName);
    if (reportDebug(__FUNCTION__))
      {
      printCR(); printValue("EventFilter Index",k);
      printValue("EventFilter Name",name);
      printValue("EventFilter Owner",owner);
      }
    if (owner)
      dynamic_cast<Manager<EventFilter>*>(_task)->create(name);
    else
      dynamic_cast<Manager<EventFilter>*>(_task)->use(name);
    }
}

void TaskCreator::configureParticleFilters(Task * _task,
                                           const String  & taskReferenceName,
                                           Configuration & requestedConfiguration)
{
  int nParticleFilters = requestedConfiguration.getValueInt(taskReferenceName+"nParticleFilters");
  for (int k=0; k<nParticleFilters; k++)
    {
    String referenceName = taskReferenceName;
    referenceName += "ParticleFilterName";
    referenceName += k;
    String name = requestedConfiguration.getValueString(referenceName);
    referenceName = taskReferenceName;
    referenceName += "ParticleFilterOwner";
    referenceName += k;
    bool owner = requestedConfiguration.getValueBool(referenceName);
    if (reportDebug(__FUNCTION__))
      {
      printCR();
      printValue("ParticleFilter Index",k);
      printValue("ParticleFilter Name",name);
      printValue("ParticleFilter Owner",owner);
      }
    if (owner)
      dynamic_cast<Manager<ParticleFilter>*>(_task)->create(name);
    else
      dynamic_cast<Manager<ParticleFilter>*>(_task)->use(name);      }
}

void TaskCreator::configureSubtasks(Task * _task,
                                    const String  & taskReferenceName,
                                    Configuration & requestedConfiguration)
{
  int nSubtasks = requestedConfiguration.getValueInt(taskReferenceName+"nSubtasks");
  for (int k=0; k<nSubtasks; k++)
    {
    String subtaskReferenceName = taskReferenceName;
    subtaskReferenceName += "Subtask";
    subtaskReferenceName += k;
    subtaskReferenceName += ":";
    createTask(_task,subtaskReferenceName,requestedConfiguration);
    }
}

//!
//!  Instantiate a task within the given parent, based on the given taksReferenceName, the given requested configuration, and the given option.
//!
Task * TaskCreator::createTask(Task * parentTask,
                               const String  & taskReferenceName,
                               Configuration & requestedConfiguration)
{
  String taskName        = requestedConfiguration.getValueString(taskReferenceName+"TaskName");
  String taskClassName   = requestedConfiguration.getValueString(taskReferenceName+"TaskClassName");
  String severity        = requestedConfiguration.getValueString(taskReferenceName+"Severity");
  requestedConfiguration.addProperty(taskName+":Severity",severity);

  String defaultExportHistograms = getEnvVariable("CAP_HISTOS_EXPORT_PATH");
  bool  importHistograms = requestedConfiguration.getValueBool(taskReferenceName+"ImportHistograms");
  bool  exportHistograms = requestedConfiguration.getValueBool(taskReferenceName+"ExportHistograms");
  if (importHistograms)
    {
    String histogramsImportPath = requestedConfiguration.getValueString(taskReferenceName+"HistogramsImportPath");
    if (histogramsImportPath.EqualTo("Default"))  histogramsImportPath = getEnvVariable("CAP_HISTOS_IMPORT_PATH");
    String histogramsImportFile = requestedConfiguration.getValueString(taskReferenceName+"HistogramsImportFile");
    requestedConfiguration.addProperty(taskName+":HistogramsImportPath",histogramsImportPath);
    requestedConfiguration.addProperty(taskName+":HistogramsImportFile",histogramsImportFile);
    }
  if (taskName.EqualTo("GlobalCalculator"))
    {
    cout << "FOund global calculator " << endl;
    cout << " HistogramsImportFile : " << requestedConfiguration.getValueString("GlobalCalculator:HistogramsImportFile") << endl;
   // exit(1);
    }
  if (exportHistograms)
    {
    String histogramsExportPath = requestedConfiguration.getValueString(taskReferenceName+"HistogramsExportPath");
    if (histogramsExportPath.EqualTo("Default"))  histogramsExportPath = getEnvVariable("CAP_HISTOS_EXPORT_PATH");
    String histogramsExportFile = requestedConfiguration.getValueString(taskReferenceName+"HistogramsExportFile");
    requestedConfiguration.addProperty(taskName+":HistogramsExportPath",histogramsExportPath);
    requestedConfiguration.addProperty(taskName+":HistogramsExportFile",histogramsExportFile);
    }

  Task* task = createTask(taskClassName);
  if (parentTask) parentTask->addSubTask(task);
  task->setName(taskName);
  task->setRequestedConfiguration(requestedConfiguration);
  task->configure();
//  if (taskName.EqualTo("GlobalCalculator"))
//    {
//    Configuration & conf = task->getConfiguration();
//    cout << " HistogramsImportFile : " << conf.getValueString("GlobalCalculator:HistogramsImportFile") << endl;
//    exit(1);
//    }


  configureDbs(task,taskReferenceName,requestedConfiguration);
  configureEventsStreams(task,taskReferenceName,requestedConfiguration);
  configureEventFilters(task,taskReferenceName,requestedConfiguration);
  configureParticleFilters(task,taskReferenceName,requestedConfiguration);
  configureSubtasks(task,taskReferenceName,requestedConfiguration);
  return task;
}

void TaskCreator::setTargetTaskName(const String & _targetTaskName)
{
  targetTaskName = _targetTaskName;
  if (!targetTaskName.EndsWith(":")) targetTaskName += ":";
}

Task * TaskCreator::getCreatedTask()
{
  return targetTask;
}

void TaskCreator::execute()
{
  try
  {
  targetTask = createTask(nullptr,targetTaskName,configuration);
  }
  catch (UnknownTaskException & ute)
  {
  ute.print(); exit(1);
  }
  catch (TaskException & te)
  {
  te.print(); exit(1);
  }
  catch (ConfigurationException & ce)
  {
  ce.print(); exit(1);
  }
  catch (Exception & e)
  {
  e.print(); exit(1);
  }
}

} // namespace CAP
