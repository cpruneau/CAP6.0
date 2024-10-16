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
#include "SpherocityCalculator.hpp"
#include "SpherocityHistos.hpp"
#include "MathConstants.hpp"
//#include "SpherocityDerivedHistos.hpp"

ClassImp(CAP::SpherocityCalculator);

namespace CAP
{

SpherocityCalculator::SpherocityCalculator()
:
EventTask(),
fillS0(true),
fillS1(false),
fillS1VsS0(false),
nSteps(360),
stepSize(CAP::Math::twoPi()/360.0)
{
  appendClassName("SpherocityCalculator");
  setName("Spherocity");
  setTitle("Spherocity");
  setVersion("1.0");
}

SpherocityCalculator::SpherocityCalculator(const SpherocityCalculator & analyzer)
:
EventTask(analyzer),
fillS0(analyzer.fillS0),
fillS1(analyzer.fillS1),
fillS1VsS0(analyzer.fillS1VsS0),
nSteps(analyzer.nSteps),
stepSize(analyzer.stepSize)
{   }

SpherocityCalculator & SpherocityCalculator::operator=(const SpherocityCalculator & analyzer)
{
  if (this!=&analyzer)
    {
    EventTask::operator=(analyzer);
    fillS0     = analyzer.fillS0;
    fillS1     = analyzer.fillS1;
    fillS1VsS0 = analyzer.fillS1VsS0;
    nSteps     = analyzer.nSteps;
    stepSize   = analyzer.stepSize;
    }
  return *this;
}


void SpherocityCalculator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName",    "Spherocity");
  addProperty("FillCorrelationHistos",false);
  addProperty("FillS0",              true);
  addProperty("FillS1",              false);
  addProperty("FillS1VsS0",          false);
  addProperty("nSteps",              1000);
  addProperty("nBins_spherocity",    100);
  addProperty("Min_spherocity",      0.0);
  addProperty("Max_spherocity",      1.0);
}

void SpherocityCalculator::configure()
{
  HistogramTask::configure();
  fillS0     = getValueBool("FillS0");
  fillS1     = getValueBool("FillS1");
  fillS1VsS0 = getValueBool("FillS1VsS0");
}

void SpherocityCalculator::initialize()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  EventTask::initialize();
  clearSets();
  addSet("Spherocity");
  addSet("derived");
  unsigned int nEventFilters    = Manager<EventFilter>::getNObjects();
  unsigned int nParticleFilters = Manager<ParticleFilter>::getNObjects();
  if (nEventFilters<1 || nParticleFilters<1)
    throw NoFilterSpherocityException(nEventFilters,nParticleFilters,__FUNCTION__);
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("fillS0",fillS0);
    printValue("fillS1",fillS1);
    printValue("fillS1VsS0",fillS1VsS0);
    printCR();
    }
  if (reportEnd(__FUNCTION__)) { /* noops*/ };
}

void SpherocityCalculator::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  String bn = getValueString( "HistogramBaseName");
  //std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  //std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
//  for (auto & eventFilter : eventFilters)
//    {
//    ;
////    SpherocityDerivedHistos * histos = new SpherocityDerivedHistos();
////    histos->setName(prefixName+eventFilter->getName());
////    histos->setConfiguration(configuration);
////    histos->setParentTask(this);
////    histos->setParticleFilters(particleFilters);
////    histos->createHistograms();
////    addGroupInSet(1,histos);
//    }
  if (reportEnd(__FUNCTION__)) { /* noops*/ };
}

void SpherocityCalculator::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  String bn = getValueString( "HistogramBaseName");
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printValue("HistogramGroup for ",bn);
    printValue("Loading HistogramGroup for",bn);
    printValue("nEventFilters",eventFilters.size());
    printValue("nParticleFilters",particleFilters.size());
    printCR();
    }
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    SpherocityHistos * histos = new SpherocityHistos();
    histos->setName(createName(bn,efn));
    histos->setConfiguration(configuration);
    histos->setParentTask(this);
    histos->importHistograms(inputFile);
    addGroupInSet(0,histos);
    }
  if (reportEnd(__FUNCTION__)) { /* noops*/ };
}

void SpherocityCalculator::execute()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  /* needs to be implemented */
  if (reportEnd(__FUNCTION__)) { /* noops*/ };
}

void SpherocityCalculator::scaleHistograms()
{

}

}  // namespace CAP

