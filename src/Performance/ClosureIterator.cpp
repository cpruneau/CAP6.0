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
//#include "HistogramCollection.hpp"
#include "ClosureIterator.hpp"
#include "ClosureCalculator.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::ClosureIterator);

namespace CAP
{

ClosureIterator::ClosureIterator()
:
HistogramTask()
{
  appendClassName("ClosureIterator");
  setName("ClosureIterator");
  setTitle("ClosureIterator");
  setVersion("1.0");
}

void ClosureIterator::setDefaultConfiguration()
{
  HistogramTask::setDefaultConfiguration();
  String none  = "none";
  addProperty("SelectedMethod",          1);
  generateKeyValuePairs("IncludedPattern",none,20);
  generateKeyValuePairs("ExcludedPattern",none,20);
}

void ClosureIterator::execute()
{
  if (reportStart(__FUNCTION__)) { /* no ops*/ };
  String none  = "none";
  String appendedString        = String("_Closure");
  String histogramsImportPath  = getValueString("HistogramsImportPath");
  String histogramsExportPath  = getValueString("HistogramsExportPath");
  bool histogramForceRewrite      = getValueBool(  "HistogramsForceRewrite");
  int selectedMethod           = getValueInt(   "SelectedMethod");

  unsigned int nSubTasks = subTasks.size();
  for (auto & task : subTasks)
    {
    Task & subTask     = *task;
    String subTaskName = subTask.getName();
    VectorString  includedPatterns = getSelectedValues("IncludedPattern",none);
    VectorString  excludedPatterns = getSelectedValues("ExcludedPattern",none);
    excludedPatterns.push_back("Reco");
    VectorString  allFilesToProcess = listFilesInDir(histogramsImportPath,includedPatterns,excludedPatterns);
    int nFilesToProcess = allFilesToProcess.size();
    if (nFilesToProcess<1) throw TaskException("No selected files","ClosureIterator::execute()");
    if (reportInfo(__FUNCTION__))
      {
      printCR();
      printLine();
      printValue("SubTask Name",subTaskName);
      printValue("HistogramsImportPath",histogramsImportPath);
      printValue("HistogramsExportPath",histogramsExportPath);
      printValue("nFilesToProcess",nFilesToProcess);
      printValue("appendedString",appendedString);
      printLine();
      }
      for (auto & name : allFilesToProcess)
      {
      String histoGeneratorFileName = removeRootExtension(name);
      String histoDetectorFileName  = substitute(histoGeneratorFileName, "_Gen", "_Reco");
      String histoClosureFileName   = substitute(histoGeneratorFileName, "_Gen", "_Closure");

      if (reportInfo(__FUNCTION__))
        {
        printCR();
        printLine();
        printValue("Generator File Name",histoGeneratorFileName);
        printValue("Detector File Name",histoDetectorFileName);
        printValue("Closure File Name",histoClosureFileName);
        }
      Configuration closureConfig;
      closureConfig.addProperty("HistogramsImportPath",   histogramsImportPath);
      closureConfig.addProperty("HistogramsExportPath",   histogramsExportPath);
      closureConfig.addProperty("AppendedString",         appendedString);
      closureConfig.addProperty("HistogramsForceRewrite", histogramForceRewrite);
      closureConfig.addProperty("SelectedMethod",         selectedMethod);
      closureConfig.addProperty("HistoGeneratorFileName", histoGeneratorFileName);
      closureConfig.addProperty("HistoDetectorFileName",  histoDetectorFileName);
      closureConfig.addProperty("HistoClosureFileName",   histoClosureFileName);
      ClosureCalculator calculator;
      calculator.setName("Closure");
      // BUG calculator.setRequestedConfiguration(&closureConfig);
      } // file loop
    } // task loop
  if (reportEnd(__FUNCTION__)) { /* no ops*/ };
}

} // namespace CAP

