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
#include "DerivedHistoIterator.hpp"
#include "RootHelpers.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::DerivedHistoIterator);

namespace CAP
{

DerivedHistoIterator::DerivedHistoIterator()
:
HistogramTask()
{
  appendClassName("DerivedHistoIterator");
  setName("DerivedHistoIterator");
  setTitle("DerivedHistoIterator");
  setVersion("1.0");
}

void DerivedHistoIterator::setDefaultConfiguration()
{
  if (reportStart(__FUNCTION__)) {/* no ops */};
  HistogramTask::setDefaultConfiguration();
  String none  = "none";
  generateKeyValuePairs("IncludedPattern", none,20);
  generateKeyValuePairs("ExcludedPattern", none,20);
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}

void DerivedHistoIterator::configure()
{
  if (reportStart(__FUNCTION__)) {/* no ops */};
  HistogramTask::configure();
  setSeverity();
  nEventFilters = 0;
  if (reportInfo(__FUNCTION__)) 
    {
    printCR();
    printValue("Configuring task",getName());
    }
  histogramForceRewrite  = getValueBool(  "HistogramsForceRewrite");
  histogramImportPath    = getValueString("HistogramsImportPath");
  histogramExportPath    = getValueString("HistogramsExportPath");
  histogramExportFile    = getName();
  maximumDepth        = 1; //getValueInt(   "MaximumDepth");
  defaultGroupSize    = 50; //getValueInt(   "DefaultGroupSize");

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("HistogramsImportPath",histogramImportPath);
    printValue("HistogramsExportPath",histogramExportPath);
    printValue("HistogramsExportFile",histogramExportFile);
    printValue("DefaultGroupSize",    defaultGroupSize);
    printValue("MaximumDepth",        maximumDepth);
    printLine();
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}

void DerivedHistoIterator::execute()
{
  if (reportStart(__FUNCTION__)) {/* no ops */};
  String none("none");
  String analyzerName;
  unsigned int nSubTasks = subTasks.size();

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue(" SubTasks Count",int(nSubTasks));
    }
  for (auto & task : subTasks)
    {
    if (!(task->IsA()==HistogramTask::Class()) ) continue;
    HistogramTask * subTask = (HistogramTask * ) task;
    analyzerName = subTask->getName();
    VectorString  includePatterns = getSelectedValues("IncludedPattern", "none");
    VectorString  excludePatterns = getSelectedValues("ExcludedPattern", "none");
    includePatterns.push_back(analyzerName);
    bool isReco = analyzerName.Contains("Reco");
    if (isReco)  includePatterns.push_back(String("Reco"));
    if (!isReco) excludePatterns.push_back(String("Reco"));
    excludePatterns.push_back(String("Derived"));

    if (reportInfo(__FUNCTION__))
      {
      printCR();
      printLine();
      printValue("SubTask Name",analyzerName);
      printValue("HistogramsImportPath",histogramImportPath);
      printValue("HistogramsExportPath",histogramExportPath);
      for (auto & pattern : includePatterns) printValue("Include Pattern",pattern);
      for (auto & pattern : excludePatterns) printValue("Exclude Pattern",pattern);
      printLine();
      }
    bool prependPath = true;
    bool verbose = false;
    int  maximumDepth = 2;
    VectorString  allFilesToProcess = listFilesInDir(histogramImportPath,includePatterns,excludePatterns, prependPath, verbose, maximumDepth,0);
    if (allFilesToProcess.size()<1) throw TaskException("No files to analyze","DerivedHistoIterator::execute()");
    for (auto & histogramImportFile : allFilesToProcess)
      {
      histogramExportFile  = removeRootExtension(histogramImportFile);
      histogramExportFile += "_Derived";
      if (reportDebug(__FUNCTION__))
        {
        printCR();
        printLine();
        printValue("Input file",histogramImportFile);
        printValue("Output file",histogramExportFile);
        }
      String nullString = "";
      subTask->setHistosImportPath(nullString);
      subTask->setHistosImportFile(histogramImportFile);
      subTask->setHistosForceRewrite(true);
      if (reportDebug(__FUNCTION__))
        {
        printCR();
        printLine();
        printValue("Task",subTask->getName());
        }
      subTask->initialize();
      subTask->execute();
      subTask->exportHistograms();
      subTask->clearHistograms();
//      subTask->closeRootInputFiles();
//      subTask->closeRootOutputFiles();
      }
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}

} // namespace CAP
