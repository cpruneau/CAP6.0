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
#include "RunAnalysis.hpp"
#include "ParticleDbTask.hpp"
#include "FilterCreator.hpp"
#include "EventIterator.hpp"
#include "FileIterator.hpp"
#include "DerivedHistoIterator.hpp"
#include "BalanceFunctionCalculator.hpp"
#include "SubSampleStatCalculator.hpp"
#include "ParticleDbTask.hpp"
#include "ClosureIterator.hpp"
#include "ClosureCalculator.hpp"
#include "PythiaEventGenerator.hpp"
#include "PythiaEventReader.hpp"
//#include "AmptEventReader.hpp"
#include "TherminatorGenerator.hpp"
//#include "ResonanceGenerator.hpp"
#include "MeasurementSimulator.hpp"
#include "PerformanceAnalyzer.hpp"
#include "GlobalAnalyzer.hpp"
#include "GlobalCalculator.hpp"
#include "SpherocityAnalyzer.hpp"
#include "SpherocityCalculator.hpp"
#include "ParticleSingleAnalyzer.hpp"
#include "ParticleSingleCalculator.hpp"
#include "ParticlePairAnalyzer.hpp"
#include "ParticlePairCalculator.hpp"
#include "NuDynAnalyzer.hpp"
#include "NuDynCalculator.hpp"
#include "PtPtAnalyzer.hpp"
#include "PtPtCalculator.hpp"
#include "Exceptions.hpp"
#include "MathExceptions.hpp"

ClassImp(CAP::RunAnalysis);

namespace CAP
{

RunAnalysis::RunAnalysis()
:
HistogramTask()
{  
  appendClassName("RunAnalysis");
  setName("Run");
  setTitle("Run");
  setVersion("1.0");
}

RunAnalysis::RunAnalysis(const RunAnalysis & task)
:
HistogramTask(task)
{    }


RunAnalysis & RunAnalysis::operator=(const RunAnalysis & task)
{
  if (this!=&task)
    {
    Task::operator=(task);
    }
  return *this;
}

void RunAnalysis::setDefaultConfiguration()
{
  HistogramTask::setDefaultConfiguration();
  addProperty("TaskName",        String("RunAnalysis"));
  addProperty("TaskClassName",   String("CAP::RunAnalysis"));
  addProperty("Severity",        String("Info"));
}

void RunAnalysis::configure()
{
  try {
    HistogramTask::configure();
  }
  catch (TaskException & te)
  {
  te.print(); exit(1);
  }
  catch (ConfigurationException & ce)
  {
  ce.print(); exit(1);
  }
  catch (MathException & me)
  {
  me.print(); exit(1);
  }
  catch (FileException & fe)
  {
  fe.print(); exit(1);
  }
  catch (MemoryException & mme)
  {
  mme.print(); exit(1);
  }
  catch (HistogramException & he)
  {
  he.print(); exit(1);
  }
  catch (FactoryException & ffe)
  {
  ffe.print(); exit(1);
  }
  catch (Exception & e)
  {
  e.print(); exit(1);
  }
}

void RunAnalysis::initialize()
{
  try {
    HistogramTask::initialize();
  }
  catch (TaskException & te)
  {
  te.print(); exit(1);
  }
  catch (ConfigurationException & ce)
  {
  ce.print(); exit(1);
  }
  catch (MathException & me)
  {
  me.print(); exit(1);
  }
  catch (FileException & fe)
  {
  fe.print(); exit(1);
  }
  catch (MemoryException & mme)
  {
  mme.print(); exit(1);
  }
  catch (HistogramException & he)
  {
  he.print(); exit(1);
  }
  catch (FactoryException & ffe)
  {
  ffe.print(); exit(1);
  }
  catch (Exception & e)
  {
  e.print(); exit(1);
  }
}

void RunAnalysis::execute()
{
  try
  {
  executeSubTasks();
  }
  catch (TaskException & te)
  {
  te.print(); exit(1);
  }
  catch (ConfigurationException & ce)
  {
  ce.print(); exit(1);
  }
  catch (MathException & me)
  {
  me.print(); exit(1);
  }
  catch (FileException & fe)
  {
  fe.print(); exit(1);
  }
  catch (MemoryException & mme)
  {
  mme.print(); exit(1);
  }
  catch (HistogramException & he)
  {
  he.print(); exit(1);
  }
  catch (FactoryException & ffe)
  {
  ffe.print(); exit(1);
  }
  catch (Exception & e)
  {
  e.print(); exit(1);
  }
}

void RunAnalysis::finalize()
{
  try {
    printString("RunAnalysis::finalize() starting");
    finalizeSubTasks();
    printString("RunAnalysis::finalize() done");
  }
  catch (TaskException & te)
  {
  te.print(); exit(1);
  }
  catch (ConfigurationException & ce)
  {
  ce.print(); exit(1);
  }
  catch (MathException & me)
  {
  me.print(); exit(1);
  }
  catch (FileException & fe)
  {
  fe.print(); exit(1);
  }
  catch (MemoryException & mme)
  {
  mme.print(); exit(1);
  }
  catch (HistogramException & he)
  {
  he.print(); exit(1);
  }
  catch (FactoryException & ffe)
  {
  ffe.print(); exit(1);
  }
  catch (Exception & e)
  {
  e.print(); exit(1);
  }
}

} // namespace CAP
