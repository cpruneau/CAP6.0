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
//#include "HistogramCollection.hpp"
#include "ClosureCalculator.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "HistogramGroup.hpp"

ClassImp(CAP::ClosureCalculator);

namespace CAP
{

ClosureCalculator::ClosureCalculator()
:
HistogramTask()
{
  appendClassName("ClosureCalculator");
}

void ClosureCalculator::setDefaultConfiguration()
{
  HistogramTask::setDefaultConfiguration();
  addProperty("SelectedMethod",int(0));
}

void ClosureCalculator::execute()
{
  String histogramsImportPath             = getHistoImportPath();
  String histogramsImportGenFileName      = getValueString("HistogramsImportGenFile");
  String histogramsImportRecoFileName     = getValueString("HistogramsImportRecoFile");
  String histogramsExportPath             = getHistoExportPath();
  String histogramsExportClosureFileName  = getValueString("HistogramsImportClosureFile");
  int selectedMethod = configuration.getValueInt("SelectedMethod");

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("HistogramsImportPath",histogramsImportPath);
    printValue("histogramsImportGenFileName",histogramsImportGenFileName);
    printValue("histogramsImportRecoFileName",histogramsImportRecoFileName);
    printValue("HistogramsExportPath",histogramsExportPath);
    printValue("histogramsExportClosureFileName",histogramsExportClosureFileName);
    }

  TFile & generatorFile = *openOldRootFile(histogramsImportPath,histogramsImportGenFileName);
  TFile & detectorFile  = *openOldRootFile(histogramsImportPath,histogramsImportRecoFileName);
  TFile * closureFile;
  if (histogramsForceRewrite())
    closureFile = openRecreateRootFile(histogramsImportPath,histogramsExportClosureFileName);
  else
    closureFile = openNewRootFile(histogramsImportPath,histogramsExportClosureFileName);

  HistogramGroup * generator = new HistogramGroup();
  HistogramGroup * detector  = new HistogramGroup();
  HistogramGroup * closure   = new HistogramGroup();
  generator->setParentTask(this);
  generator->setName("GeneratorLevel");
  generator->loadGroup(generatorFile);
  generator->setOwnership(false);
  long nExecuted = TaskAccountant::importNEexecutedTask(generatorFile);

  detector->setParentTask(this);
  detector->setName("DetectorLevel");
  detector->loadGroup(detectorFile);
  detector->setOwnership(false);
  closure->setName("Closure");
  closure->setParentTask(this);
  closure->setOwnership(false);
  switch (selectedMethod)
    {
      case 0: closure->differenceGroup(*detector,*generator,true); break;
      case 1: closure->ratioGroup(*detector,*generator,true); break;
    }
  closure->exportHistograms(*closureFile);
  TaskAccountant::exportNEexecutedTask(*closureFile);

  generatorFile.Close();
  detectorFile.Close();
  closureFile-> Close();
  delete generator;
  delete detector;
  delete closure;
  if (reportInfo (__FUNCTION__)) cout << "Closure Test Completed." << endl;
}

} // namespace CAP
