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


ClassImp(CAP::HistogramTask);

namespace CAP
{
HistogramTask::HistogramTask()
:
Task(),
histosScale              (false),
histosForceRewrite       (false),
histosImportPath         ("DEFAULT"),
histosImportFile         ("DEFAULT"),
histosExportPath         ("DEFAULT"),
histosExportFile         ("DEFAULT"),
histosExportPartial      (false),
histosExportPartialCount (0),
histosExportMaxPerPartial(0),
histogramSets()
{ /* no ops */ }

HistogramTask::HistogramTask(const HistogramTask & task)
:
Task(task),
histosScale              (task.histosScale),
histosForceRewrite       (task.histosForceRewrite),
histosImportPath         (task.histosImportPath),
histosImportFile         (task.histosImportFile),
histosExportPath         (task.histosExportPath),
histosExportFile         (task.histosExportFile),
histosExportPartial      (task.histosExportPartial),
histosExportPartialCount (task.histosExportPartialCount),
histosExportMaxPerPartial(task.histosExportMaxPerPartial),
histogramSets            (task.histogramSets)
{ /* no ops */ }

HistogramTask HistogramTask::operator=(const HistogramTask & task)
{
  if (this!=&task)
    {
    histosScale              = task.histosScale;
    histosForceRewrite       = task.histosForceRewrite;
    histosImportPath         = task.histosImportPath;
    histosImportFile         = task.histosImportFile;
    histosExportPath         = task.histosExportPath;
    histosExportFile         = task.histosExportFile;
    histosExportPartial      = task.histosExportPartial;
    histosExportPartialCount = task.histosExportPartialCount;
    histosExportMaxPerPartial= task.histosExportMaxPerPartial;
    histogramSets            = task.histogramSets;
    }
  return *this;
}

void HistogramTask::setDefaultConfiguration()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  Task::setDefaultConfiguration();
  addProperty("HistogramsScale",histosScale);
  addProperty("HistogramsForceRewrite",histosForceRewrite);
  addProperty("HistogramsImportPath",histosImportPath);
  addProperty("HistogramsImportFile",histosImportFile);
  addProperty("HistogramsExportPath",histosExportPath);
  addProperty("HistogramsExportFile",histosExportPartial);
  addProperty("HistogramsExportPartial",histosExportPartial);
  addProperty("HistogramsExportPartialCount",histosExportPartialCount);
  addProperty("HistogramsExportMaxPerPartial",histosExportMaxPerPartial);
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}


void HistogramTask::configure()
{
  Task::configure();
  histosScale               = getValueBool("HistogramsScale");
  histosForceRewrite        = getValueBool("HistogramsForceRewrite");
  histosImportPath          = getValueString("HistogramsImportPath");
  histosImportFile          = getValueString("HistogramsImportFile");
  histosExportPath          = getValueString("HistogramsExportPath");
  histosExportFile          = getValueString("HistogramsExportFile");
  histosExportPartial       = getValueBool("HistogramsExportPartial");
  histosExportPartialCount  = getValueInt("HistogramsExportPartialCount");
  histosExportMaxPerPartial = getValueInt("HistogramsExportMaxPerPartial");
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
  if (histosImportPath.EqualTo("DEFAULT"))
    histoPath = CAP_HISTOS_IMPORT_PATH;
  else if (histosImportPath.BeginsWith("/"))
    histoPath = histosImportPath;
  else
    {
    histoPath = CAP_HISTOS_IMPORT_PATH;
    histoPath += "/";
    histoPath += histosImportPath;
    }
  return histoPath;
}


String HistogramTask::getHistoExportPath()
{
  String CAP_HISTOS_EXPORT_PATH = getEnvVariable("CAP_HISTOS_EXPORT_PATH");
  String histoPath;
  if (histosExportPath.EqualTo("DEFAULT"))
    histoPath = CAP_HISTOS_EXPORT_PATH;
  else if (histosExportPath.BeginsWith("/"))
    histoPath = histosExportPath;
  else
    {
    histoPath = CAP_HISTOS_EXPORT_PATH;
    histoPath += "/";
    histoPath += histosExportPath;
    }
  printCR();
  printValue("CAP_HISTOS_EXPORT_PATH",CAP_HISTOS_EXPORT_PATH);
  printValue("histosExportPath",histosExportPath);
  printValue("histoPath",histoPath);

  return histoPath;
}




void HistogramTask::importHistograms()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  String importPath = getHistoImportPath();
  String importFile = histosImportFile;
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
  exportHistograms(histosExportPath,histosExportFile);
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
  if (histosForceRewrite) option = "RECREATE";
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

