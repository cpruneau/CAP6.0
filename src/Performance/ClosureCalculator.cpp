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
#include "ClosureCalculator.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "HistogramGroup.hpp"

ClassImp(CAP::ClosureCalculator);

namespace CAP
{

ClosureCalculator::ClosureCalculator()
:
HistogramTask(),
selectedMethod(0)
{
  appendClassName("ClosureCalculator");
}

void ClosureCalculator::setDefaultConfiguration()
{
  HistogramTask::setDefaultConfiguration();
  addProperty("SelectedMethod",selectedMethod);
}

void ClosureCalculator::execute()
{
  String histosGeneratorFileName = "";
  String histosDetectorFileName  = "";
  String histosClosureFileName   = "";

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printString("Starting closure test calculation");
    printValue("HistoInputPath",histogramImportPath);
    printValue("HistoGeneratorFileName",histosGeneratorFileName);
    printValue("HistoDetectorFileName",histosDetectorFileName);
    printValue("HistogramsExportPath",histogramExportPath);
    printValue("HistogramsClosureFileName",histosClosureFileName);
    switch (selectedMethod)
      {
        default:
        case 0: printValue("SelectedMethod","Difference"); break;
        case 1: printValue("SelectedMethod","Ratio");      break;
      }
    }
  String option = "NEW";
  if (histogramForceRewrite) option = "RECREATE";
  TFile & generatorFile = *openRootFile("", histosGeneratorFileName, "READ");
  TFile & detectorFile  = *openRootFile("", histosDetectorFileName,  "READ");
  TFile & closureFile   = *openRootFile("", histosClosureFileName,option);
  HistogramGroup * generator = new HistogramGroup();
  HistogramGroup * detector  = new HistogramGroup();
  HistogramGroup * closure   = new HistogramGroup();
  generator->setParentTask(this);
  generator->setName("GeneratorLevel");
  generator->loadGroup(generatorFile);
  generator->setOwnership(false);
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
  closure->exportHistograms(closureFile);
  generatorFile.Close();
  detectorFile.Close();
  closureFile.Close();
  delete generator;
  delete detector;
  delete closure;
  if (reportInfo (__FUNCTION__)) cout << "Closure Test Completed." << endl;
}

} // namespace CAP
