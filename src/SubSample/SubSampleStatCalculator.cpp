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

namespace CAP
{

SubSampleStatCalculator::SubSampleStatCalculator()
:
EventTask(),
nEventsProcessed(0),
sumEventsProcessed(0),
nEventsAccepted(nullptr),
sumEventsAccepted(nullptr)
{
  appendClassName("SubSampleStatCalculator");
  setName("SubSample");
}

void SubSampleStatCalculator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
 // configuration.print(cout);
}

void SubSampleStatCalculator::configure()
{
  EventTask::configure();
}

void SubSampleStatCalculator::execute()
{
  if (reportInfo(__FUNCTION__))
    {
    CAP::printCR();
    CAP::printLine();
    CAP::printValue("HistogramsImportPath",histogramImportPath);
    CAP::printValue("HistogramsImportFile",histogramImportFile);
    CAP::printValue("HistogramsExportPath",histogramExportPath);
    CAP::printValue("HistogramsExportFile",histogramExportFile);
    }
  bool prependPath = true;
  bool verbose = false;
  std::vector<String> directories = listDirsIn(histogramImportPath,verbose);
  int nDirectories = directories.size();
  if (directories.size()<2) throw TaskException("directories.size()<2",__FUNCTION__);
  if (reportInfo(__FUNCTION__))
    {
    CAP::printCR();
    CAP::printValue("directories.size()",nDirectories);
    }

  TFile * firstFile;
  TFile * otherFile;
  HistogramGroup * groupAverage  = new HistogramGroup();
  HistogramGroup * group;
  groupAverage->setName("Average");
  int iFile = 0;
  for (auto & name : directories)
    {
    printValue("HistogramImportPath",histogramImportPath+name);
    printValue("HistogramImportFile",histogramImportFile);
    printValue("File index",         iFile);
    if (iFile==0)
      {
      firstFile = openOldRootFile(histogramImportPath+name, histogramImportFile);
      groupAverage->loadGroup(*firstFile);
      }
    else
      {
      otherFile = openRootFile(histogramImportPath+name, histogramImportFile);
      group = new HistogramGroup();
      group->loadGroup(*otherFile);
      }

    double nExecuted = TaskAccountant::importNEexecutedTask(*otherFile);
    double nExecutedTotal = TaskAccountant::getNExecuted();
    EventAccountant::importEventsAccepted(*otherFile);

    printValue("nExecuted",          nExecuted);
    printValue("nExecutedTotal",     nExecutedTotal);
    if (iFile>0)
      {
      groupAverage->squareDifferenceGroup(*group, double(nExecutedTotal), double(nExecuted), (iFile==(nDirectories-1)) ? nDirectories-1 : -iFile);
      otherFile->Close();
      delete group;
      }
    iFile++;
    }

  TFile & rootOutputFile = *openRootFile(histogramExportPath, histogramExportFile, "RECREATE");
  TaskAccountant::exportNEexecutedTask(rootOutputFile);
  EventAccountant::exportEventsAccepted(rootOutputFile);
  groupAverage->exportHistograms(rootOutputFile);
  firstFile->Close();
  //groupAvg->setOwnership(0);
  delete groupAverage;
  rootOutputFile.Close();
}


} // namespace CAP

