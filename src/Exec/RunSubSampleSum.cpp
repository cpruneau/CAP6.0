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
#include "RunSubSampleSum.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "SubSampleStatCalculator.hpp"

ClassImp(CAP::RunSubSampleSum);

namespace CAP
{

RunSubSampleSum::RunSubSampleSum()
{   }

RunSubSampleSum::~RunSubSampleSum()
{   }


void RunSubSampleSum::run(String & histogramImportPathName,
                          String & histogramImportFileName,
                          String & histogramExportPathName,
                          String & histogramExportFileName,
                          bool verbose)
{
  printLine();
  printString("Executing RunSubSampleSum.run()");
  printValue("importPathName",histogramImportPathName);
  printValue("importFileName",histogramImportFileName);
  printValue("exportPathName",histogramExportPathName);
  printValue("exportPathName",histogramExportFileName);
  std::vector<String> directories = listDirsIn(histogramImportPathName,verbose);
  printValue("Number of folders found",directories.size());
    CAP::Configuration configuration;
  try
  {
    if (verbose) configuration.addProperty("SubSample:Severity","DEBUG");
    else configuration.addProperty("SubSample:Severity","INFO");
    configuration.addProperty("SubSample:HistogramsImportPath",       histogramImportPathName);
    configuration.addProperty("SubSample:HistogramsImportFile",       histogramImportFileName);
    configuration.addProperty("SubSample:HistogramsExportPath",       histogramExportPathName);
    configuration.addProperty("SubSample:HistogramsExportFile",       histogramExportFileName);
    CAP::Task * task = new CAP::SubSampleStatCalculator();
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
