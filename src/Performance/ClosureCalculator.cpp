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
  if (reportInfo (__FUNCTION__)) cout << "Closure Test Beginning." << endl;
  // needs fix...
  String histosGeneratorFileName;
  String histosDetectorFileName;
  String histosClosureFileName;
  TFile & generatorFile = *openOldRootFile(histosGeneratorFileName);
  TFile & detectorFile  = *openOldRootFile(histosDetectorFileName);
  TFile * closureFile;
  if (histogramsForceRewrite())
    closureFile = openRecreateRootFile(histosClosureFileName);
  else
    closureFile = openNewRootFile(histosClosureFileName);

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
  int selectedMethod = getValueInt("SelectedMethod");
  switch (selectedMethod)
    {
      case 0: closure->differenceGroup(*detector,*generator,true); break;
      case 1: closure->ratioGroup(*detector,*generator,true); break;
    }
  closure->exportHistograms(*closureFile);
  generatorFile.Close();
  detectorFile.Close();
  closureFile-> Close();
  delete generator;
  delete detector;
  delete closure;
  if (reportInfo (__FUNCTION__)) cout << "Closure Test Completed." << endl;
}

} // namespace CAP
