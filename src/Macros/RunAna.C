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
#include <iostream>
#include <fstream>
#include <TStyle.h>
#include <TROOT.h>
void loadBase(const TString & includeBasePath);
void loadMath(const TString & includeBasePath);
void loadParticleDb(const TString & includeBasePath);
void loadParticles(const TString & includeBasePath);
void loadPythia(const TString & includeBasePath);
void loadPerformance(const TString & includeBasePath);
void loadGlobal(const TString & includeBasePath);
void loadSpherocity(const TString & includeBasePath);
void loadSingle(const TString & includeBasePath);
void loadPair(const TString & includeBasePath);
void loadNuDyn(const TString & includeBasePath);
void loadSubSample(const TString & includeBasePath);
void loadExec(const TString & includeBasePath);
void loadTherminator(const TString & includeBasePath);

//!
//! Run generic data analysis based on the configuration listed in 'configFile'
//!
//! configFile     :  configuration file (.ini) describing the task(s) to be done
//! outputPath   :  output path used for all files created
//! seed            :  provided by slurm (grid job engine) or directly by user
//! isGrid          :   must be true for jobs running on grid
//! nEventsPerSubbunch : number of events to run per bunch  (actual on grid or simulated on a single node)
//! nSubbunchesPerBunch : number of sub-bunches  (must be 1 on grid)
//! nBunches :  number of bunches  (must be 1 on grid)
//!

int RunAna(TString configFile="Pythia/pp_13.7TeV/RunAna.ini",
           TString histogramPath="./pythiaTest/",
           long seed=1121331,
           bool isGrid=false,
           long nEventsPerSubbunch=10,
           int  nSubbunchesPerBunch=1,
           int  nBunches=1)
{
  TString includeBasePath = getenv("CAP_SRC_PATH");
  loadBase(includeBasePath);
  loadMath(includeBasePath);
  loadParticleDb(includeBasePath);
  loadParticles(includeBasePath);
  loadGlobal(includeBasePath);
  loadSpherocity(includeBasePath);

  loadSingle(includeBasePath);
  loadPair(includeBasePath);
  loadNuDyn(includeBasePath);
  loadSubSample(includeBasePath);
  loadPythia(includeBasePath);
  loadTherminator(includeBasePath);
  loadExec(includeBasePath);
  loadPerformance(includeBasePath);

  try
  {
  if (isGrid || seed!=0)  gRandom->SetSeed(seed);

  CAP::Configuration configuration;
  TString configurationPath = getenv("CAP_PROJECTS_PATH");
  TString configurationFile = configFile;
  CAP::printCR();
  CAP::printLine();
  CAP::printString("RunAna()");
  CAP::printLine();
  CAP::printValue("Configuration path",configurationPath);
  CAP::printValue("Configuration file",configurationFile);
  CAP::printValue("Run:Analysis:isGrid",isGrid);
  CAP::printValue("Run:Analysis:HistogramsImportPath",histogramPath);
  CAP::printValue("Run:Analysis:HistogramsExportPath",histogramPath);
  CAP::printValue("Run:Analysis:nEventsPerSubbunch",nEventsPerSubbunch);
  CAP::printValue("Run:Analysis:nBunches",nBunches);

  configuration.importProperties(configurationPath,configurationFile);
  configuration.addProperty("Run:Analysis:isGrid",                  isGrid);
  configuration.addProperty("Run:HistogramsImportPath",             histogramPath);
  configuration.addProperty("Run:HistogramsExportPath",             histogramPath);
  configuration.addProperty("Run:Analysis:HistogramsImportPath",    histogramPath);
  configuration.addProperty("Run:Analysis:HistogramsExportPath",    histogramPath);
  configuration.addProperty("Run:Analysis:nEventsPerSubbunch",      nEventsPerSubbunch);
  configuration.addProperty("Run:Analysis:nSubbunchesPerBunch",     nSubbunchesPerBunch);
  configuration.addProperty("Run:Analysis:nBunches",                nBunches);
  configuration.print(cout);
  CAP::printString("Instantiate RunAnalysis");
  CAP::RunAnalysis * analysis = new CAP::RunAnalysis();
  analysis->setRequestedConfiguration(configuration);
  CAP::printLine();
  CAP::printString("Configure RunAnalysis starting");
  analysis->configure();
  CAP::printString("Configure RunAnalysis done");
  CAP::printString("Execute RunAnalysis");
  CAP::printLine();
  analysis->execute();
  CAP::printLine();
  CAP::printString("RunAnalysis completed successfully");
  CAP::printLine();
  return 1;
  }
  catch (CAP::TaskException & exception)
  {
  exception.print();
  //exit(1);
  }
  catch (CAP::FileException  & exception)
  {
  exception.print();
  //exit(1);
  }
//  catch (CAP::MathException exception)
//  {
//  exception.print();
//  // exit(1);
//  }
  catch (CAP::Exception  &  exception)
  {
  exception.print();
  //exit(1);
  }
  CAP::printLine();
  CAP::printString("RunAnalysis NOT completed");
  CAP::printLine();
  return 0;
}

void loadBase(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/Base/";
  gSystem->Load(includePath+"Configuration.hpp");
  gSystem->Load(includePath+"Timer.hpp");
  gSystem->Load(includePath+"PrintHelpers.hpp");
  gSystem->Load(includePath+"RootHelpers.hpp");
  gSystem->Load(includePath+"MessageLogger.hpp");
  gSystem->Load(includePath+"Task.hpp");
  gSystem->Load(includePath+"Exceptions.hpp");
  gSystem->Load(includePath+"HistogramGroup.hpp");
  gSystem->Load(includePath+"DerivedHistoIterator.hpp");
  gSystem->Load("libBase.dylib");
}

void loadMath(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/Math/";
  gSystem->Load(includePath+"MathExceptions.hpp");
  gSystem->Load(includePath+"MathConstants.hpp");
  gSystem->Load("libMath.dylib");
}

void loadParticleDb(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/ParticleDb/";
  gSystem->Load(includePath+"ParticleDb.hpp");
  gSystem->Load(includePath+"ParticleDbExceptions.hpp");
  gSystem->Load(includePath+"ParticleDbParser.hpp");
  gSystem->Load(includePath+"ParticleDbParser_CS.hpp");
  gSystem->Load(includePath+"ParticleDbTask.hpp");
  gSystem->Load(includePath+"ParticleDecayMode.hpp");
  gSystem->Load(includePath+"ParticlePartition.hpp");
  gSystem->Load(includePath+"ParticleType.hpp");
  gSystem->Load("libParticleDb.dylib");
}

void loadParticles(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/Particles/";
  gSystem->Load(includePath+"Event.hpp");
  gSystem->Load(includePath+"Particle.hpp");
  gSystem->Load(includePath+"EventTask.hpp");
  gSystem->Load(includePath+"EventIterator.hpp");
  gSystem->Load("libParticles.dylib");
}



void loadPythia(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/CAPPythia/";
  gSystem->Load(includePath+"PythiaEventGenerator.hpp");
  gSystem->Load(includePath+"PythiaEventReader.hpp");
  gSystem->Load("libCAPPythia.dylib");
}

void loadPerformance(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/Performance/";
  gSystem->Load(includePath+"ClosureCalculator.hpp");
  gSystem->Load(includePath+"ClosureIterator.hpp");
  gSystem->Load(includePath+"MeasurementSimulator.hpp");
  gSystem->Load(includePath+"ParticleSimulator.hpp");
  gSystem->Load(includePath+"PerformanceAnalyzer.hpp");
  gSystem->Load(includePath+"ParticlePerformanceHistos.hpp");
  gSystem->Load("libPerformance.dylib");
}

//void loadAmpt(const TString & includeBasePath)
//{
//  TString includePath = includeBasePath + "/Ampt/";
//  gSystem->Load(includePath+"AmptEventReader.hpp");
//  gSystem->Load("libAmpt.dylib");
//}
//
//void loadEpos(const TString & includeBasePath)
//{
//  TString includePath = includeBasePath + "/Epos/";
//  gSystem->Load(includePath+"EposEventReader.hpp");
//  gSystem->Load("libEpos.dylib");
//}
//
//void loadHijing(const TString & includeBasePath)
//{
//  TString includePath = includeBasePath + "/Hijing/";
//  gSystem->Load(includePath+"HijingEventReader.hpp");
//  gSystem->Load("libHijing.dylib");
//}

//void loadHerwig(const TString & includeBasePath)
//{
//  TString includePath = includeBasePath + "/Herwig/";
//  gSystem->Load(includePath+"HerwigEventReader.hpp");
//  gSystem->Load("libHerwig.dylib");
//}
//
//void loadUrqmd(const TString & includeBasePath)
//{
//  TString includePath = includeBasePath + "/Urqmd/";
//  gSystem->Load(includePath+"UrqmdEventReader.hpp");
//  gSystem->Load("libUrqmd.dylib");
//}
//
//
//void loadBasicGen(const TString & includeBasePath)
//{
//  TString includePath = includeBasePath + "/BasicGen/";
//  gSystem->Load(includePath+"GaussianGeneratorTask.hpp");
//  gSystem->Load(includePath+"RadialBoostHistos.hpp");
//  gSystem->Load(includePath+"RadialBoostTask.hpp");
//  gSystem->Load(includePath+"RapidityGenerator.hpp");
//  gSystem->Load("libBasicGen.dylib");
//}

void loadGlobal(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/Global/";
  gSystem->Load(includePath+"GlobalAnalyzer.hpp");
  gSystem->Load(includePath+"GlobalCalculator.hpp");
  gSystem->Load(includePath+"GlobalHistos.hpp");
  gSystem->Load("libGlobal.dylib");
}

void loadSpherocity(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/Spherocity/";
  gSystem->Load(includePath+"SpherocityAnalyzer.hpp");
  gSystem->Load(includePath+"SpherocityCalculator.hpp");
  gSystem->Load(includePath+"SpherocityHistos.hpp");
  gSystem->Load("libSpherocity.dylib");
}


void loadSingle(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/ParticleSingle/";
  gSystem->Load(includePath+"ParticleSingleHistos.hpp");
  gSystem->Load(includePath+"ParticleSingleDerivedHistos.hpp");
  gSystem->Load(includePath+"ParticleSingleAnalyzer.hpp");
  gSystem->Load(includePath+"ParticleSingleCalculator.hpp");
  gSystem->Load("libParticleSingle.dylib");
}

void loadPair(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/ParticlePair/";
  gSystem->Load(includePath+"ParticlePairAnalyzer.hpp");
  gSystem->Load(includePath+"ParticlePairCalculator.hpp");
  gSystem->Load(includePath+"ParticlePairHistos.hpp");
  gSystem->Load(includePath+"ParticlePairDerivedHistos.hpp");
  gSystem->Load(includePath+"BalanceFunctionCalculator.hpp");
  gSystem->Load("libParticlePair.dylib");
}

void loadNuDyn(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/NuDyn/";
  gSystem->Load(includePath+"NuDynAnalyzer.hpp");
  gSystem->Load(includePath+"NuDynCalculator.hpp");
  gSystem->Load(includePath+"NuDynDerivedHistos.hpp");
  gSystem->Load(includePath+"NuDynHistos.hpp");
  gSystem->Load("libNuDyn.dylib");
}

void loadSubSample(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/SubSample/";
  gSystem->Load(includePath+"SubSampleStatCalculator.hpp");
  gSystem->Load("libSubSample.dylib");
}

void loadExec(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/Exec/";
  gSystem->Load(includePath+"RunAnalysis.hpp");
  gSystem->Load("libExec.dylib");
}

void loadTherminator(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/Therminator/";
  gSystem->Load(includePath+"Model.hpp");
  gSystem->Load("libTherminator.dylib");
}
