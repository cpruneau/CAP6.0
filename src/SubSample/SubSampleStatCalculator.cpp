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
#include "HistogramGroup.hpp"
#include "SubSampleStatCalculator.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::SubSampleStatCalculator);

using CAP::SubSampleStatCalculator;


SubSampleStatCalculator::SubSampleStatCalculator()
:
EventTask(),
nEventsProcessed(0),
sumEventsProcessed(0),
nEventsAccepted(nullptr),
sumEventsAccepted(nullptr)
{
  appendClassName("SubSampleStatCalculator");
}

void SubSampleStatCalculator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  cout << "setDefaultConfiguration() --- Name of this task:" << getName() << endl;
  String none  = "none";
  addProperty("HistogramsForceRewrite", true);
  addProperty("DefaultGroupSize",       100);
  addProperty("nInputFile",             0);
  addProperty("HistogramsImportPath",     none);
  addProperty("HistogramsExportPath",    none);
  addProperty("MaximumDepth",           2);
  generateKeyValuePairs("IncludedPattern",none,20);
  generateKeyValuePairs("ExcludedPattern",none,20);
  generateKeyValuePairs("InputFile",none,100);
}

void SubSampleStatCalculator::configure()
{
  EventTask::configure();
  setSeverity();
  nEventFilters = 0;
  cout << " Name of this task:" << getName() << endl;

  histosImportPath    = getValueString("HistogramsImportPath");
  histosExportPath    = getValueString("HistogramsExportPath");
  histosExportPath    = getValueString("HistogramsExportFile");
  histosExportFile    = getName();
  defaultGroupSize    = getValueInt(   "DefaultGroupSize");
  maximumDepth        = getValueInt(   "MaximumDepth");
  defaultGroupSize    = getValueInt(   "DefaultGroupSize");
}

void SubSampleStatCalculator::execute()
{
  if (reportInfo(__FUNCTION__)) cout << "Subsample analysis for task of type :" << getName() << endl;
  String none  = "none";
  print(cout);
  VectorString  includePatterns = getSelectedValues("IncludedPattern",none);
  VectorString  excludePatterns = getSelectedValues("ExcludedPattern",none);
  if (reportInfo(__FUNCTION__))
    {
    CAP::printCR();
    CAP::printValue("HistogramsImportPath",histosImportPath);
    CAP::printValue("HistogramsExportPath",histosExportPath);
    CAP::printValue("HistogramsExportFile",histosExportFile);
    CAP::printValue("DefaultGroupSize",    defaultGroupSize);
    CAP::printValue("MaximumDepth",        maximumDepth);
    for (auto & pattern : includePatterns) printValue("Included",pattern);
    for (auto & pattern : excludePatterns) printValue("Excluded",pattern);
    cout << endl;
    }
  bool prependPath = true;
  bool verbose = false;
  VectorString  allFilesToSum = listFilesInDir(histosImportPath,includePatterns,excludePatterns, prependPath, verbose, maximumDepth,0);
  int nFilesToSum = allFilesToSum.size();
  int groupSize = (nFilesToSum>defaultGroupSize) ? defaultGroupSize : nFilesToSum;
  int nGroups   = 1 + double(nFilesToSum-1)/double(groupSize);
  if (nFilesToSum<1) throw TaskException("nFilesToSum<1","SubSampleStatCalculator::execute()");
  if (reportInfo(__FUNCTION__))
    {
    CAP::printCR();
    CAP::printValue("nFilesToSum",          nFilesToSum);
    CAP::printValue("DefaultGroupSize",     defaultGroupSize);
    CAP::printValue("nGroups",              nGroups);
    CAP::printValue("HistogramsImportPath", histosImportPath);
    CAP::printValue("HistogramsExportPath", histosExportPath);
    CAP::printValue("HistogramsExportFile", histosExportFile);
    int iFile = 0;
    for (auto & name : allFilesToSum)
      cout << " " << iFile++ << " : " << name << endl;
    }
   
   for (int iGroup =0; iGroup<nGroups; iGroup++  )
    {
    int first = iGroup*groupSize;
    int last  = (iGroup+1)*groupSize;
    if (last>=nFilesToSum) last = nFilesToSum;
    if (reportInfo(__FUNCTION__))
      std::cout << "Summing files w/ index:" << first << " to " << last-1 << std::endl;
    String outputFileName = histosExportFile;
    outputFileName += "_Sum_";
    outputFileName += first;
    outputFileName += "TO";
    outputFileName += (last-1);
    sumEventsProcessed = 0.0;
    nEventsProcessed   = 0.0;
    HistogramGroup * groupAvg;
    HistogramGroup * group;
    String parameterName;

    int nInputFile = last - first+1;
    String histosImportFile = allFilesToSum[first];
    TFile & firstFile = *openRootFile("", histosImportFile, "READ");
    groupAvg  = new HistogramGroup();
    groupAvg->setName("Sum");
    groupAvg->loadGroup(firstFile);
    try
      {
      parameterName      = "nTaskExecuted";
      nEventsProcessed   = importParameter(firstFile,parameterName);
      }
    catch (...)
      {
      parameterName      = "taskExecuted";
      nEventsProcessed   = importParameter(firstFile,parameterName);
      }
    sumEventsProcessed = nEventsProcessed;
    parameterName      = "nEventFilters";
    nEventFilters      = importParameter(firstFile,parameterName);
    if (nEventFilters>0)
      {
      nEventsAccepted    = new long[nEventFilters];
      sumEventsAccepted  = new long[nEventFilters];
      for (int iFilter=0; iFilter<nEventFilters; iFilter++)
        {
        parameterName = "EventFilter";
        parameterName += iFilter;
        nEventsAccepted[iFilter]   = importParameter(firstFile,parameterName);
        sumEventsAccepted[iFilter] = nEventsAccepted[iFilter];
        }
      }
    else
      {
      throw TaskException("nEventFilters is null","SubSampleStatCalculator::execute()");
      }

    int iFile = 0;
    for (auto & histosImportFile : allFilesToSum)
      {
      TFile & inputFile = *openRootFile("", histosImportFile, "READ");
      group = new HistogramGroup();
      //group = new HistogramGroup(histosImportFile,getSeverityLevel());
      group->loadGroup(inputFile);
      TaskAccountant::importNEexecutedTask(inputFile);
      EventAccountant::importEventsAccepted(inputFile);
      sumEventsProcessed += nEventsProcessed;
      groupAvg->squareDifferenceGroup(*group, double(sumEventsProcessed), double(nEventsProcessed), (iFile==(last-1)) ? nInputFile : -iFile);

      delete group;
      inputFile.Close();
      if (reportInfo(__FUNCTION__))
        {
        CAP::printCR();
        CAP::printValue("File index",            iFile);
        CAP::printValue("HistosImportFile",      histosImportFile);
        CAP::printValue("nEventsProcessed",      nEventsProcessed);
        CAP::printValue("nEventsProcessed(Sum)", sumEventsProcessed);
        CAP::printCR();
        }
      }

    TFile & rootOutputFile = *openRootFile(histosExportPath, outputFileName, "RECREATE");
    parameterName    = "taskExecuted";
    TaskAccountant::exportNEexecutedTask(rootOutputFile);
    EventAccountant::exportEventsAccepted(rootOutputFile);
    groupAvg->exportHistograms(rootOutputFile);
    firstFile.Close();
    //groupAvg->setOwnership(0);
    delete groupAvg;
    rootOutputFile.Close();
    iFile++;
    }

}

