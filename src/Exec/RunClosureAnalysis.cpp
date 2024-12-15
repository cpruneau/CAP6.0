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
#include "RunClosureAnalysis.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "ClosureCalculator.hpp"

ClassImp(CAP::RunClosureAnalysis);

namespace CAP
{

RunClosureAnalysis::RunClosureAnalysis()
{   }

RunClosureAnalysis::~RunClosureAnalysis()
{   }


void RunClosureAnalysis::run(String & histogramImportPathName,
                     String & histogramImportGenFileName,
                     String & histogramImportRecoFileName,
                     String & histogramExportPathName,
                     String & histogramExportFileName,
                     bool verbose)
{
  printLine();
  printString("Executing RunClosure.run()");
  printValue("histogramImportPathName",histogramImportPathName);
  printValue("histogramImportGenFileName",histogramImportGenFileName);
  printValue("histogramImportRecoFileName",histogramImportRecoFileName);
  printValue("histogramExportPathName",histogramExportPathName);
  printValue("histogramExportFileName",histogramExportFileName);
  CAP::Configuration configuration;
  try
  {
  if (verbose) configuration.addProperty("ClosureCalculator:Severity","DEBUG");
  else configuration.addProperty("ClosureCalculator:Severity","INFO");
  configuration.addProperty("ClosureCalculator:HistogramsImportPath",     histogramImportPathName);
  configuration.addProperty("ClosureCalculator:HistogramsImportGenFile",  histogramImportGenFileName);
  configuration.addProperty("ClosureCalculator:HistogramsImportRecoFile", histogramImportGenFileName);
  configuration.addProperty("ClosureCalculator:HistogramsExportPath",     histogramExportPathName);
  configuration.addProperty("ClosureCalculator:HistogramsExportFile",     histogramExportFileName);
  CAP::Task * task = new CAP::ClosureCalculator();
  task->setDefaultConfiguration();
  task->setRequestedConfiguration(configuration);
  task->configure();
  task->execute();
  delete task;
  }
  catch (CAP::PropertyException & pe)
  {
  pe.print();
  }
  catch (CAP::TaskException & te)
  {
  te.print();
  }
}

} // namespace CAP
