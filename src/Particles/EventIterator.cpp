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
#include "EventIterator.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::EventIterator);

namespace CAP
{

EventIterator::EventIterator()
:
Task::Task(),
nEventsRequested(1),
nEventsReport(10)
{
  appendClassName("EventIterator");
  setName("EventIterator");
  setTitle("EventIterator");
}

EventIterator::EventIterator(const EventIterator & task)
:
Task::Task(task),
nEventsRequested(task.nEventsRequested),
nEventsReport(task.nEventsReport)
{  /* no ops */ }

EventIterator EventIterator::operator=(const EventIterator & task)
{
  if (this!=&task)
    {
    Task::operator=(task);
    nEventsRequested    = task.nEventsRequested;
    nEventsReport       = task.nEventsReport;
    }
  return *this;
}

void EventIterator::setDefaultConfiguration()
{
  Task::setDefaultConfiguration();
  String path = "./";
  addProperty("HistogramsImportPath",path);
  addProperty("HistogramsExportPath",path);
  addProperty("nEventsRequested",    nEventsRequested);
  addProperty("nEventsReport",       nEventsReport);
}

void EventIterator::configure()
{
  Task::configure();
  nEventsRequested       = getValueLong(  "nEventsRequested");
  nEventsReport          = getValueLong(  "nEventsReport");
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("nEventsRequested",nEventsRequested);
    printValue("nEventsReport",nEventsReport);
    printLine();
    }
}

void EventIterator::execute()
{
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("nEventsRequested",nEventsRequested);
    printValue("nEventsReport",nEventsReport);
    for (auto & subTask : subTasks) printValue("Subtask name",subTask->getName());
    }
  start();
  for (long iEvent = 0; iEvent<nEventsRequested; iEvent++)
    {
    for (auto & subTask : subTasks)  subTask->execute();
    if (iEvent%nEventsReport == 0) printValue("iEvent",iEvent);
    }
  stop();
  printCR();
  printLine();
  printLine();
  printTimeInfo(cout);
  printLine();
  printLine();
  printCR();
}

void EventIterator::initialize()
{
  initializeSubTasks();
}



void EventIterator::finalize()
{
  finalizeSubTasks();
}


} // namespace CAP
