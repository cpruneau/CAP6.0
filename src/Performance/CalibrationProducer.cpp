/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Victor Gonzalez   
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   07/17/2024
 *
 * *********************************************************************/
#include "CalibrationProducer.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::CalibrationProducer);
namespace CAP
{


CalibrationProducer::CalibrationProducer()
:
HistogramTask(_name, _configuration)
{
  appendClassName("CalibrationProducer");
  setName("CalibrationProducer");
  setTitle("CalibrationProducer");
  setVersion("1.0");
}

void CalibrationProducer::setDefaultConfiguration()
{
  HistogramTask::setDefaultConfiguration();
  addProperty("EfficiencyOpt",           0);
  addProperty("HistogramsImportPath",    TString("./"));
  addProperty("HistoRatioFileName",      TString("none"));
  addProperty("HistogramsExportPath",    TString("./"));
  addProperty("HistoEffFileName",        TString("none"));
}

void CalibrationProducer::configure()
{
  HistogramTask::configure();
}

void CalibrationProducer::initialize()
{}

void CalibrationProducer::execute()
{
  incrementTaskExecuted();
  bool   histogramForceRewrite     = getValueBool(  "HistogramsForceRewrite");
  int    efficiencyOpt          = getValueInt(   "EfficiencyOpt");
  String histoInputPath         = getValueString("HistogramsImportPath");
  String histoRatioFileName     = getValueString("HistoRatioFileName");
  String HistogramsExportPath   = getValueString("HistogramsExportPath");
  String histoEffFileName       = getValueString("HistoEffFileName");
    
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printString("Starting Calibration Producer");
    printValue("histoInputPath",histoInputPath);
    printValue("histoRatioFileName",histoRatioFileName);
    printValue("histoDetectorFileName",histoDetectorFileName);
    printValue("HistogramsExportPath",HistogramsExportPath);
    printValue("histoEffFileName",histoEffFileName);
    switch (efficiencyOpt)
      {
        case 0: printString("efficiencyOpt: eff vs. pt"); break;
        case 1: printString("efficiencyOpt: eff vs. pt vs eta"); break;
        case 2: printString("efficiencyOpt: eff vs. pt vs y"); break;
        case 3: printString("efficiencyOpt: eff vs. pt vs phi vs eta"); break;
        case 4: printString("efficiencyOpt: eff vs. pt vs phi vs y"); break;
      }
    }

  TFile * inputFile = openRootFile(histoInputPath, histoRatioFileName, "READ");
  TFile * outputFile;
  if (HistogramsForceRewrite)
    outputFile   = openRootFile(HistogramsExportPath,histoEffFileName,"RECREATE");
  else
    outputFile   = openRootFile(HistogramsExportPath,histoEffFileName,"NEW");

  if (!inputFile || !outputFile) return;
  
  HistogramCollection * inputCollection = new HistogramCollection("Input",getSeverityLevel());
  HistogramCollection * outputCollection  = new HistogramCollection("Output", getSeverityLevel());
  inputCollection->loadCollection(inputFile);
  inputCollection->setOwnership(false);
  outputCollection->setOwnership(false);
  switch (selectedMethod)
  {
    case 0:
    break;
    case 1:
    break;
  }
  outputCollection->exportHistograms(closureFile);
  generatorFile->Close();
  detectorFile->Close();
  closureFile->Close();
  delete generatorCollection;
  delete detectorCollection;
  delete closureCollection;
  if (reportInfo (__FUNCTION__)) cout << "Closure Test Completed." << endl;
}


} // namespace CAP
