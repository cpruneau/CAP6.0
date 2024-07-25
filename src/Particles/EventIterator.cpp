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
#include "EventIterator.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::EventIterator);

namespace CAP
{

EventIterator::EventIterator()
:
Task::Task(),
isGrid(false),
nEventsPerSubbunch(1),
nSubbunchesPerBunch(1),
nBunches(1),
nEventsRequested(1),
nEventsReport(10),
bunchLabel("BUNCH"),
subbunchLabel(""),
iEvent(0),
iSubBunch(0),
iBunch(0)
{
  appendClassName("EventIterator");
  setName("EventIterator");
  setTitle("EventIterator");
  setVersion("1.0");
}

EventIterator::EventIterator(const EventIterator & task)
:
Task::Task(task),
isGrid(task.isGrid),
nEventsPerSubbunch(task.nEventsPerSubbunch),
nSubbunchesPerBunch(task.nSubbunchesPerBunch),
nBunches(task.nBunches),
nEventsRequested(task.nEventsRequested),
nEventsReport(task.nEventsReport),
bunchLabel(task.bunchLabel),
subbunchLabel(task.subbunchLabel),
iEvent(task.iEvent),
iSubBunch(task.iSubBunch),
iBunch(task.iBunch)
{  /* no ops */ }

EventIterator EventIterator::operator=(const EventIterator & task)
{
  if (this!=&task)
    {
    Task::operator=(task);
    isGrid              = task.isGrid;
    nEventsPerSubbunch  = task.nEventsPerSubbunch;
    nSubbunchesPerBunch = task.nSubbunchesPerBunch;
    nBunches            = task.nBunches;
    nEventsRequested    = task.nEventsRequested;
    nEventsReport       = task.nEventsReport;
    bunchLabel          = task.bunchLabel;
    subbunchLabel       = task.subbunchLabel;
    iEvent              = task.iEvent;
    iSubBunch           = task.iSubBunch;
    iBunch              = task.iBunch;
    }
  return *this;
}

void EventIterator::setDefaultConfiguration()
{
  printString("EventIterator::setDefaultConfiguration() -1-");

  Task::setDefaultConfiguration();
  printString("EventIterator::setDefaultConfiguration() -2-");

  addProperty("isGrid",                  isGrid);
  addProperty("nEventsPerSubbunch",      nEventsPerSubbunch);
  addProperty("nSubbunchesPerBunch",     nSubbunchesPerBunch);
  addProperty("nBunches",                nBunches);
  addProperty("nEventsRequested",        nEventsRequested);
  addProperty("nEventsReport",           nEventsReport);
  addProperty("BunchLabel",              bunchLabel);
  addProperty("SubbunchLabel",           subbunchLabel);
}

void EventIterator::configure()
{
  printString("EventIterator::configure() -1-");
  Task::configure();
  printString("EventIterator::configure() -1-");
  isGrid                 = getValueBool(  "isGrid");
  nEventsPerSubbunch     = getValueInt(   "nEventsPerSubbunch");
  nSubbunchesPerBunch    = getValueInt(   "nSubbunchesPerBunch");
  nBunches               = getValueInt(   "nBunches");
  nEventsRequested       = getValueLong(  "nEventsRequested");
  nEventsReport          = getValueLong(  "nEventsReport");
  bunchLabel             = getValueString("BunchLabel");
  subbunchLabel          = getValueString("SubbunchLabel");

  if (isGrid) // just doing a sub bunch
    {
    // nEventsPerSubbunch is past to RunAna.C via the launching script.
    nEventsRequested = nEventsPerSubbunch;
    }

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("isGrid" ,isGrid);
    printValue("nEventsPerSubbunch",nEventsPerSubbunch);
    printValue("nSubbunchesPerBunch",nSubbunchesPerBunch);
    printValue("nBunches",nBunches);
    printValue("nEventsRequested",nEventsRequested);
    printValue("nEventsReport",nEventsReport);
    printValue("bunchLabel",bunchLabel);
    printValue("subbunchLabel",subbunchLabel);
    printLine();
    }
  printString("EventIterator::configure() -LAST-");

}

//void EventIterator::partial(const String & outputPathBase)
void EventIterator::partial()
{
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printString("Partial save of histograms");
    }
  String outputPath;//  = outputPathBase;
  if (!isGrid)
    {
    outputPath += "/";
    outputPath += bunchLabel;
    outputPath += Form("%02d",iBunch);
    outputPath += "/";
    outputPath += subbunchLabel;
    outputPath +=  Form("%02d",iSubBunch);
    outputPath += "/";
    }
  for (auto & subTask : subTasks)  subTask->partial();
}

void EventIterator::execute()
{
  //taskHistosImportPath
//  String histosImportPath = getValueString("HistogramsImportPath");
//  String histosExportPath = getValueString("HistogramsExportPath");
//  if (histosImportPath.EqualTo("DEFAULT"))
//    {
//    histosImportPath = taskHistosImportPath;
//    }
//  else if (!histosImportPath.BeginsWith("/"))
//    {
//    String temp = taskHistosImportPath;
//    temp += "/";
//    temp += histosImportPath;
//    histosImportPath = temp;
//    }
//  if (histosExportPath.EqualTo("DEFAULT"))
//    {
//    histosExportPath = taskHistosExportPath;
//    }
//  else if (!histosExportPath.BeginsWith("/"))
//    {
//    String temp = taskHistosImportPath;
//    temp += "/";
//    temp += histosExportPath;
//    histosExportPath = temp;
//    }
//  addProperty("HistogramsImportPath",histosImportPath);
//  addProperty("HistogramsExportFile",histosExportPath);

//  printCR();
//  printLine();
//  printString("EventIterator::execute()");
//  printLine();
//  exit(1);
  int n = subTasks.size();
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("isGrid",isGrid);
    printValue("nEventsRequested",nEventsRequested);
    printValue("nEventsReport",nEventsReport);
    printValue("nBunches",nBunches);
    printValue("nSubbunchesPerBunch",nSubbunchesPerBunch);
    printValue("nEventsPerSubbunch",nEventsPerSubbunch);
    printValue("Number of subtasks",n);
    for (auto & subTask : subTasks) printValue("Subtask name",subTask->getName());
    }
  start();
  iEvent           = 0;
  iSubBunch        = 0;
  iBunch           = 0;
  bool working     = true;
  while (working)
    {
    for (auto & subTask : subTasks)  subTask->execute();
    iEvent++;
    if (iEvent%nEventsReport == 0) printValue("iEvent",iEvent);
//    if (isTaskEod())
//      {
//      working = false; break;
//      }
    if (iEvent>=nEventsRequested)
      {
      if (reportInfo(__FUNCTION__))
        {
        cout << endl;
        printValue("iEvent",iEvent);
        printValue("nEventsRequested",nEventsRequested);
        cout << endl;
        }
      working = false; break;
      }

    // in local mode, with partial saves on
    //
//    if (histosExportPartial  && !isGrid)
//      {
//      if (iEvent%(nBunches*nSubbunchesPerBunch*nEventsPerSubbunch)==0)
//        {
//        // subbunch is completed
//        //partial(histosExportPath);
//        partial();
//        iSubBunch++;
//        if (iSubBunch==nSubbunchesPerBunch)
//          {
//          // bunch is completed
//          iSubBunch=0;
//          iBunch++;
//          if (iBunch==nBunches) working = false;
//          }
//        }
//      }
    }
  stop();
  finalize();
  clear(); // should delete everything..
}


void EventIterator::finalize()
{
  finalizeSubTasks();
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("Task named",           getName());
    printValue("isGrid",               isGrid);
    printValue("nEventsPerSubbunch",   nEventsPerSubbunch);
    printValue("nSubbunchesPerBunch",  nSubbunchesPerBunch);
    printValue("nBunches",             nBunches);
    printValue("nEventsRequested",     nEventsRequested);
    printValue("bunchLabel",           bunchLabel);
    printValue("subbunchLabel",        subbunchLabel);
    printValue("event completed",      iEvent);
    printValue("subBunches completed", iSubBunch);
    printValue("bunches completed",    iBunch);
    printTimeInfo(cout);
    printLine();
    }
}


} // namespace CAP
