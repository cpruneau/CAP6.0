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
histogramSets(),
rootInputFile(nullptr), // do we really need this
rootOutputFile(nullptr) // do we really need this
{ /* no ops */ }

HistogramTask::HistogramTask(const HistogramTask & task)
:
Task(task),
histogramSets(task.histogramSets),
rootInputFile(nullptr), // do we really need this
rootOutputFile(nullptr) // do we really need this
{ /* no ops */ }

HistogramTask HistogramTask::operator=(const HistogramTask & task)
{
  if (this!=&task)
    {
    Task::operator=(task);
    histogramSets  = task.histogramSets;
    rootInputFile  = nullptr;
    rootOutputFile = nullptr;
    }
  return *this;
}

void HistogramTask::setDefaultConfiguration()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  Task::setDefaultConfiguration();
  String defaultLocation = "Default";
  addProperty("HistogramsScale",        true);
  addProperty("HistogramsForceRewrite", true);
  addProperty("HistogramsImportPath",   defaultLocation);
  addProperty("HistogramsImportFile",   defaultLocation);
  addProperty("HistogramsExportPath",   defaultLocation);
  addProperty("HistogramsExportFile",   defaultLocation);
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

void HistogramTask::configure()
{
  Task::configure();
}

void HistogramTask::initialize()
{
  Task::initialize();
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
//  if (reportDebug(__FUNCTION__))
//    {
//    printCR();
//    printString("HistogramTask::getGroupAt(unsigned int iSet, unsigned int iGroup)");
//    printValue("iSet",iSet);
//    printValue("iGroup",iGroup);
//    printValue("histogramSets.size()",histogramSets.size());
//    printValue("histogramSets[iSet].size()",histogramSets[iSet]->size());
//    printCR();
//    }
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
  throw TaskException("scaleHistograms() function must be provided in derived class implementation",__FUNCTION__);
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
  String path;
  String histogramsImportPath = getValueString("HistogramsImportPath");
  if (histogramsImportPath.EqualTo("DEFAULT") ||
      histogramsImportPath.EqualTo("Default"))
    path = getEnvVariable("CAP_HISTOS_IMPORT_PATH");
  else if (histogramsImportPath.BeginsWith("/"))
    path = histogramsImportPath;
  else
    {
    path = getEnvVariable("CAP_HISTOS_IMPORT_PATH");
    path += "/";
    path += histogramsImportPath;
    }
  return path;
}


String HistogramTask::getHistoExportPath()
{
  String path;
  String histogramsExportPath = getValueString("HistogramsExportPath");
  if (histogramsExportPath.EqualTo("DEFAULT") ||
      histogramsExportPath.EqualTo("Default"))
    path = getEnvVariable("CAP_HISTOS_EXPORT_PATH");
  else if (histogramsExportPath.BeginsWith("/"))
    path = histogramsExportPath;
  else
    {
    path = getEnvVariable("CAP_HISTOS_EXPORT_PATH");
    path += "/";
    path += histogramsExportPath;
    }
  return path;
}

String HistogramTask::getHistoImportFile()
{
  String name = getValueString("HistogramsImportFile");
  return name;
}

String HistogramTask::getHistoExportFile()
{
  String name = getValueString("HistogramsExportFile");
  return name;
}

void HistogramTask::importHistograms()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  String importPath = getHistoImportPath();
  String importFile = getHistoImportFile();
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("importPath",importPath);
    printValue("importFile",importFile);
    printLine();
    }
  rootInputFile = openOldRootFile(importPath,importFile);
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
  String path = getHistoExportPath();
  String name = getHistoExportFile();
  exportHistograms(path,name);
}

void HistogramTask::exportHistograms(const String & exportPath, const String & exportFile)
{
  if (reportInfo(__FUNCTION__))
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
  TFile * rootOutputFile;
  if (histogramsForceRewrite())
    rootOutputFile = openRecreateRootFile(exportPath,exportFile);
  else
    rootOutputFile = openNewRootFile(exportPath,exportFile);
  exportHistograms(*rootOutputFile);
  rootOutputFile->Close();
  rootOutputFile = nullptr;
}


bool HistogramTask::histogramsForceRewrite()
{
  return getValueBool("HistogramsForceRewrite");
}

//!
//!Save histograms of all histogramSets and all groups they contain
//!
void HistogramTask::exportHistograms(TFile & outputFile)
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  outputFile.cd();
  if (reportInfo(__FUNCTION__))
    printValue("histogramSets.size()",histogramSets.size());
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

