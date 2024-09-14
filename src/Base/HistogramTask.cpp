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
#include "HistogramTask.hpp"
#include "HistogramGroup.hpp"
#include "HistogramSet.hpp"
#include "RootHelpers.hpp"
#include "PrintHelpers.hpp"
#include "TSystem.h"
#include "TROOT.h"
#include "TFile.h"

ClassImp(CAP::HistogramTask);

namespace CAP
{
HistogramTask::HistogramTask()
:
Task(),
histogramScale              (false),
histogramForceRewrite       (false),
histogramImportPath         ("DEFAULT"),
histogramImportFile         ("DEFAULT"),
histogramExportPath         ("DEFAULT"),
histogramExportFile         ("DEFAULT"),
histogramExportPartial      (false),
histogramExportPartialCount (0),
histogramExportMaxPerPartial(0),
histogramSets()
{ /* no ops */ }

HistogramTask::HistogramTask(const HistogramTask & task)
:
Task(task),
histogramScale              (task.histogramScale),
histogramForceRewrite       (task.histogramForceRewrite),
histogramImportPath         (task.histogramImportPath),
histogramImportFile         (task.histogramImportFile),
histogramExportPath         (task.histogramExportPath),
histogramExportFile         (task.histogramExportFile),
histogramExportPartial      (task.histogramExportPartial),
histogramExportPartialCount (task.histogramExportPartialCount),
histogramExportMaxPerPartial(task.histogramExportMaxPerPartial),
histogramSets            (task.histogramSets)
{ /* no ops */ }

HistogramTask HistogramTask::operator=(const HistogramTask & task)
{
  if (this!=&task)
    {
    histogramScale              = task.histogramScale;
    histogramForceRewrite       = task.histogramForceRewrite;
    histogramImportPath         = task.histogramImportPath;
    histogramImportFile         = task.histogramImportFile;
    histogramExportPath         = task.histogramExportPath;
    histogramExportFile         = task.histogramExportFile;
    histogramExportPartial      = task.histogramExportPartial;
    histogramExportPartialCount = task.histogramExportPartialCount;
    histogramExportMaxPerPartial= task.histogramExportMaxPerPartial;
    histogramSets            = task.histogramSets;
    }
  return *this;
}

void HistogramTask::setDefaultConfiguration()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  Task::setDefaultConfiguration();
  addProperty("HistogramsScale",histogramScale);
  addProperty("HistogramsForceRewrite",histogramForceRewrite);
  addProperty("HistogramsImportPath",histogramImportPath);
  addProperty("HistogramsImportFile",histogramImportFile);
  addProperty("HistogramsExportPath",histogramExportPath);
  addProperty("HistogramsExportFile",histogramExportFile);
  addProperty("HistogramsExportPartial",histogramExportPartial);
  addProperty("HistogramsExportPartialCount",histogramExportPartialCount);
  addProperty("HistogramsExportMaxPerPartial",histogramExportMaxPerPartial);
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}


void HistogramTask::configure()
{
  Task::configure();
  histogramScale               = getValueBool(  "HistogramsScale");
  histogramForceRewrite        = getValueBool(  "HistogramsForceRewrite");
  histogramImportPath          = getValueString("HistogramsImportPath");
  histogramImportFile          = getValueString("HistogramsImportFile");
  histogramExportPath          = getValueString("HistogramsExportPath");
  histogramExportFile          = getValueString("HistogramsExportFile");
  histogramExportPartial       = getValueBool(  "HistogramsExportPartial");
  histogramExportPartialCount  = getValueInt(   "HistogramsExportPartialCount");
  histogramExportMaxPerPartial = getValueInt(   "HistogramsExportMaxPerPartial");
}

void HistogramTask::initialize()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  EnvironmentVariables::initialize();
  TaskAccountant::reset();
  if (hasSubTasks())  initializeSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void HistogramTask::createHistograms()
{
  throw TaskException("No derived implementation",__FUNCTION__);
}

void HistogramTask::reset()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  TaskAccountant::reset();
  resetHistograms();
  if (hasSubTasks()) resetSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void HistogramTask::clear()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  TaskAccountant::clear();
  clearHistograms();
  if (hasSubTasks()) clearSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void HistogramTask::finalize()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  exportHistograms();
  if (hasSubTasks()) finalizeSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void HistogramTask::clearSets()
{
  for (auto & set : histogramSets)
    {
    set->clearHistograms();
    delete set;
    }
  histogramSets.clear();
}

void HistogramTask::addSet(const String & name)
{
  if (name.Length()<2)
    throw TaskException("Selected name too short",__FUNCTION__);
  HistogramSet * newSet = new HistogramSet(name);
  histogramSets.push_back( newSet );
}

HistogramSet &  HistogramTask::getSetAt(unsigned int index)
{
  if (index >= histogramSets.size()) throw TaskException("Invalid index",__FUNCTION__);
  return *(histogramSets[index]);
}

void HistogramTask::addGroupInSet(unsigned int index, HistogramGroup * group)
{
  if (index>=histogramSets.size()) throw TaskException("index>=nSets",__FUNCTION__);
  histogramSets[index]->addGroup(group);
}

HistogramGroup & HistogramTask::getGroupAt(unsigned int iSet, unsigned int iGroup)
{
  printCR();
  printString("HistogramTask::getGroupAt(unsigned int iSet, unsigned int iGroup)");
  printValue("iSet",iSet);
  printValue("iGroup",iGroup);
  printValue("histogramSets.size()",histogramSets.size());
  printValue("histogramSets[iSet].size()",histogramSets[iSet]->size());
  return histogramSets[iSet]->getGroupAt(iGroup);
}

//!
//!Delete all histogramSets and their respective contents
//!
void HistogramTask::clearHistograms()
{
  for (auto & set : histogramSets) set->clearHistograms();
}

//!
//!Reset histograms of all histogramSets and all groups they contain
//!
void HistogramTask::resetHistograms()
{
  for (auto & set : histogramSets) set->resetHistograms();
}

void HistogramTask::scaleHistograms()
{
  if (reportFatal(__FUNCTION__))
    {
    printCR();
    printString("HistogramTask::scaleHistograms() improperly called");
    }
  throw TaskException("Function must be provided in derived class implementation",__FUNCTION__);
}


//!
//!Scale histograms of all histogramSets and all groups they contain by the given factor
//!
void HistogramTask::scaleHistograms(double factor)
{
  for (auto & set : histogramSets) set->scaleHistograms(factor);
}

//!
//!Scale histograms of all histogramSets and all groups they contain by the given factor
//!
void HistogramTask::scaleHistograms(vector<double> factor)
{
  for (auto & set : histogramSets) set->scaleHistograms(factor);
}




void HistogramTask::printHistograms()
{
/* no ops -- needs to be implemented */
}

String HistogramTask::getHistoImportPath()
{
  String CAP_HISTOS_IMPORT_PATH = getEnvVariable("CAP_HISTOS_IMPORT_PATH");
  String histoPath;
  if (histogramImportPath.EqualTo("DEFAULT"))
    histoPath = CAP_HISTOS_IMPORT_PATH;
  else if (histogramImportPath.BeginsWith("/"))
    histoPath = histogramImportPath;
  else
    {
    histoPath = CAP_HISTOS_IMPORT_PATH;
    histoPath += "/";
    histoPath += histogramImportPath;
    }
  return histoPath;
}


String HistogramTask::getHistoExportPath()
{
  String CAP_HISTOS_EXPORT_PATH = getEnvVariable("CAP_HISTOS_EXPORT_PATH");
  String histoPath;
  if (histogramExportPath.EqualTo("DEFAULT"))
    histoPath = CAP_HISTOS_EXPORT_PATH;
  else if (histogramExportPath.BeginsWith("/"))
    histoPath = histogramExportPath;
  else
    {
    histoPath = CAP_HISTOS_EXPORT_PATH;
    histoPath += "/";
    histoPath += histogramExportPath;
    }
  printCR();
  printValue("CAP_HISTOS_EXPORT_PATH",CAP_HISTOS_EXPORT_PATH);
  printValue("histogramExportPath",histogramExportPath);
  printValue("histoPath",histoPath);

  return histoPath;
}

void HistogramTask::importHistograms()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  String importPath = getHistoImportPath();
  String importFile = histogramImportFile;
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("importPath",importPath);
    printValue("importFile",importFile);
    printLine();
    }
  rootInputFile = openRootFile(importPath,importFile,"READ");
//  loadNEventsAccepted(*rootInputFile);
//  loadNEexecutedTask(*rootInputFile);
  importHistograms(*rootInputFile);
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

//!
//!Load histograms of all histogramSets and all groups they contain
//!
void HistogramTask::importHistograms(TFile & inputFile)
{
  for (auto & set : histogramSets) set->importHistograms(inputFile);
}

void HistogramTask::exportHistograms()
{
  exportHistograms(histogramExportPath,histogramExportFile);
}

void HistogramTask::exportHistograms(const String & exportPath, const String & exportFile)
{
  if (reportInfo(__FUNCTION__)) { /* no ops */ };
    {
    printCR();
    printLine();
    printValue("HistogramsExportPath",exportPath);
    printValue("HistogramsExportFile",exportFile);
    printLine();
    }
  if (exportPath.Length()>2) gSystem->mkdir(exportPath,1);
  if (exportFile.Length()<5)
    throw FileException(exportFile,"File name too short. Must have 5 character or more...",__FUNCTION__);
  String option = "NEW";
  if (histogramForceRewrite) option = "RECREATE";
  TFile * rootOutputFile = openRootFile(exportPath,exportFile,option);
  exportHistograms(*rootOutputFile);
  rootOutputFile->Close();
  rootOutputFile = nullptr;
}


//!
//!Save histograms of all histogramSets and all groups they contain
//!
void HistogramTask::exportHistograms(TFile & outputFile)
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  outputFile.cd();
  for (auto & set : histogramSets) set->exportHistograms(outputFile);
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

void HistogramTask::exportHistograms(ofstream & outputFile)
{
//  writeNEventsAccepted(outputFile);
//  writeNEexecutedTask(outputFile);
  for (auto & set : histogramSets) set->exportHistograms(outputFile);
}

} // namespace CAP

