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
  String histogramsImportPath  = getHistoImportPath();
  String histogramsImportFile  = getHistoImportFile();
  String histogramsExportPath  = getHistoExportPath();
  String histogramsExportFile  = getHistoExportFile();
  if (reportInfo(__FUNCTION__))
    {
    CAP::printCR();
    CAP::printLine();
    CAP::printValue("HistogramsImportPath",histogramsImportPath);
    CAP::printValue("HistogramsImportFile",histogramsImportFile);
    CAP::printValue("HistogramsExportPath",histogramsExportPath);
    CAP::printValue("HistogramsExportFile",histogramsExportFile);
    }
  bool prependPath = true;
  bool verbose = false;
  std::vector<String> directories = listDirsIn(histogramsImportPath,verbose);
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
  double nExecuted = 0;
  double nExecutedTotal = 0;
  for (auto & name : directories)
    {
    String path = histogramsImportPath; path += "/"; path += name;
    printValue("histogramsImportPath",path);
    printValue("histogramsImportFile",histogramsImportFile);
    printValue("File index",         iFile);
    if (iFile==0)
      {
      firstFile = openOldRootFile(path, histogramsImportFile);
      groupAverage->loadGroup(*firstFile);
      nExecuted = TaskAccountant::importNEexecutedTask(*firstFile);
      //EventAccountant::importEventsAccepted(*firstFile);
      }
    else
      {
      otherFile = openOldRootFile(path, histogramsImportFile);
      group = new HistogramGroup();
      group->loadGroup(*otherFile);
      nExecuted = TaskAccountant::importNEexecutedTask(*otherFile);
      //EventAccountant::importEventsAccepted(*otherFile);
      }
    nExecutedTotal = TaskAccountant::getNExecuted();
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

  TFile & rootOutputFile = *openRecreateRootFile(histogramsExportPath,histogramsExportFile);
  TaskAccountant::exportNEexecutedTask(rootOutputFile);
  //EventAccountant::exportEventsAccepted(rootOutputFile);
  groupAverage->exportHistograms(rootOutputFile);
  firstFile->Close();
  //groupAvg->setOwnership(0);
  delete groupAverage;
  rootOutputFile.Close();
}


} // namespace CAP

