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
#include "ParticlePairCalculator.hpp"
#include "ParticleSingleHistos.hpp"
#include "ParticlePairHistos.hpp"
#include "ParticlePairDerivedHistos.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticlePairCalculator);

namespace CAP
{

ParticlePairCalculator::ParticlePairCalculator()
:
EventTask(),
fillEta(true),
fillY(false),
fillP2(false)
{
  appendClassName("ParticlePairCalculator");
  setInstanceName("Pair");
  setName("Pair");
  setTitle("Pair");
  setVersion("1.0");
}

ParticlePairCalculator::ParticlePairCalculator(const ParticlePairCalculator & task)
:
EventTask(task),
fillEta(task.fillEta),
fillY(task.fillY),
fillP2(task.fillP2)
{   }

ParticlePairCalculator & ParticlePairCalculator::operator=(const ParticlePairCalculator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    fillEta =  task.fillEta;
    fillY   =  task.fillY;
    fillP2  =  task.fillP2;
    }
  return *this;
}


void ParticlePairCalculator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName", "Pair");
  addProperty("FillEta",           fillEta);
  addProperty("FillY",             fillY);
  addProperty("FillP2",            fillP2);
  addProperty("nBins_n1",          100);
  addProperty("Min_n1",            0.0);
  addProperty("Max_n1",            100.0);
  addProperty("nBins_eTot",        100);
  addProperty("Min_eTot",          0.0);
  addProperty("Max_eTot",          100.0);
  addProperty("nBins_pt",          18);
  addProperty("Min_pt",            0.20);
  addProperty("Max_pt",            2.00);
  addProperty("nBins_phi",          72);
  addProperty("Min_phi",           0.0);
  addProperty("Max_phi",           CAP::Math::twoPi());
  addProperty("nBins_eta",           20);
  addProperty("Min_eta",           -1.0);
  addProperty("Max_eta",            1.0);
  addProperty("nBins_y",             20);
  addProperty("Min_y",             -1.0);
  addProperty("Max_y",              1.0);
  addProperty("nBins_phiEta",            720);
  addProperty("nBins_phiEtaPt",          7200);
  addProperty("nBins_phiY",              720);
  addProperty("nBins_phiYPt",            7200);
  addProperty("nBins_n2",                  100);
  addProperty("Min_n2",                    0.0);
  addProperty("Max_n2",                 1000.0);
  addProperty("nBins_Dphi",                 36);
  addProperty("Min_Dphi",                  0.0);
  addProperty("Max_Dphi",CAP::Math::twoPi());
  addProperty("Width_Dphi",CAP::Math::twoPi());
  addProperty("nBins_Dphi_shft",    36);
  addProperty("Min_Dphi_shft",     0.0);
  addProperty("Max_Dphi_shft",     0.0);
  addProperty("nBins_Deta",         39);
  addProperty("Min_Deta",         -2.0);
  addProperty("Max_Deta",          2.0);
  addProperty("Width_Deta",   4.0/39.0);
  addProperty("nBins_Dy",           39);
  addProperty("Min_Dy",           -2.0);
  addProperty("Max_Dy",            2.0);
  addProperty("Width_Dy",     4.0/39.0);
  addProperty("nBins_DeltaP",   10);
  addProperty("Min_DeltaP",   -4.0);
  addProperty("Max_DeltaP",    4.0);
  addProperty("binCorrPP",     1.0);
}

void ParticlePairCalculator::configure()
{
  EventTask::configure();
  fillEta = getValueBool("FillEta");
  fillY   = getValueBool("FillY");
  fillP2  = getValueBool("FillP2");
//  if (reportInfo(__FUNCTION__))
//    {
//    cout << endl;
//    printValue("FillEta",fillEta);
//    printValue("FillY",fillY);
//    printValue("FillP2",fillP2);
//    printValue("nBins_n1");
//    printValue("Min_n1");
//    printValue("Max_n1");
//    printValue("nBins_eTot");
//    printValue("Min_eTot");
//    printValue("Max_eTot");
//    printValue("nBins_pt");
//    printValue("Min_pt");
//    printValue("Max_pt");
//    printValue("nBins_eta");
//    printValue("Min_eta");
//    printValue("Max_eta");
//    printValue("nBins_y");
//    printValue("Min_y");
//    printValue("Max_y");
//    printValue("nBins_phi");
//    printValue("Min_phi");
//    printValue("Max_phi");
//    printValue("nBins_n2");
//    printValue("Min_n2");
//    printValue("Max_n2");
//    printValue("nBins_Dphi");
//    printValue("Min_Dphi");
//    printValue("Max_Dphi");
//    printValue("Width_Dphi");
//    printValue("nBins_Dphi_shft");
//    printValue("Min_Dphi_shft");
//    printValue("Max_Dphi_shft");
//    printValue("nBins_Deta");
//    printValue("Min_Deta");
//    printValue("Max_Deta");
//    printValue("Width_Deta");
//    printValue("nBins_Dy");
//    printValue("Min_Dy");
//    printValue("Max_Dy");
//    printValue("Width_Dy");
//    printValue("nBins_DeltaP");
//    printValue("Min_DeltaP");
//    printValue("Max_DeltaP");
//    cout << endl;
//    }
}

void ParticlePairCalculator::initialize()
{
  EventTask::initialize();
  clearSets();
  addSet("single");
  addSet("pair");
  addSet("singleDerived");
  addSet("pairDerived");
  HistogramTask::importHistograms();
  createHistograms();
}

void ParticlePairCalculator::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* */ };
  String bn = getValueString( "HistogramBaseName");
  fillEta = getValueBool("FillEta");
  fillY   = getValueBool("FillY");
  fillP2  = getValueBool("FillP2");
  HistogramGroup * histos;
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();

  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    if (reportDebug(__FUNCTION__)) printValue("Event filter",efn);
    for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      if (reportDebug(__FUNCTION__)) printValue("Particle filter",pfn);
      histos = new ParticleSingleHistos();
      histos->setParentTask(this);
      histos->setConfiguration(configuration);
      histos->setName(createName(bn,efn,pfn));
      histos->importHistograms(inputFile);
      addGroupInSet(0,histos);
      }
    for (auto & particleFilter1 : particleFilters)
      {
      String pfn1 = particleFilter1->getName();
      if (reportDebug(__FUNCTION__)) printValue("Particle filter 1",pfn1);
      for (auto & particleFilter2 : particleFilters)
        {
        String pfn2 = particleFilter2->getName();
        if (reportDebug(__FUNCTION__)) printValue("Particle filter 2",pfn2);
        histos = new ParticlePairHistos();
        histos->setParentTask(this);
        histos->setConfiguration(configuration);
        histos->setName(createName(bn,efn,pfn1,pfn2));
        histos->importHistograms(inputFile);
        addGroupInSet(1,histos);
        }
      }
    }
  if (reportEnd(__FUNCTION__))  { /* */ };
}

void ParticlePairCalculator::createHistograms()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  String bn = getValueString( "HistogramBaseName");
  HistogramGroup * histos;
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printValue("Creating Derived HistogramGroup",bn);
    printValue("nEventFilters",eventFilters.size());
    printValue("nParticleFilters",particleFilters.size());
    printCR();
    }
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      histos = new ParticleSingleDerivedHistos();
      histos->setConfiguration(configuration);
      histos->setParentTask(this);
      histos->setName(createName(bn,efn,pfn));
      histos->createHistograms();
      addGroupInSet(2,histos);
      }
    for (auto & particleFilter1 : particleFilters)
      {
      String pfn1 = particleFilter1->getName();
      for (auto & particleFilter2 : particleFilters)
        {
        String pfn2 = particleFilter2->getName();
        histos = new ParticlePairDerivedHistos();
        histos->setName(createName(bn,efn,pfn1,pfn2));
        histos->setConfiguration(configuration);
        histos->setParentTask(this);
        histos->createHistograms();
        addGroupInSet(3,histos);
        }
      }
    }
  if (reportEnd(__FUNCTION__))   { /* */ };
}

void ParticlePairCalculator::execute()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  int nEventFilters    = eventFilters.size();
  int nParticleFilters = particleFilters.size();

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printValue("nEventFilters",nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    }

  for (int iEventFilter = 0; iEventFilter<nEventFilters;iEventFilter++)
    {
    unsigned int  baseSingle   = iEventFilter*nParticleFilters;
    unsigned int  basePair     = iEventFilter*nParticleFilters*nParticleFilters;
    for (int iParticleFilter1 = 0; iParticleFilter1<nParticleFilters;iParticleFilter1++)
      {
      int indexSingle1 = baseSingle + iParticleFilter1;
      ParticleSingleHistos & bSingleHistos1 = (ParticleSingleHistos &) getGroupAt(0,indexSingle1);
      ParticleSingleDerivedHistos &dSingleHistos1 = (ParticleSingleDerivedHistos &)  getGroupAt(2,indexSingle1);
      dSingleHistos1.calculateDerivedHistograms(bSingleHistos1);
      }

    for (int iParticleFilter1 = 0; iParticleFilter1<nParticleFilters;iParticleFilter1++)
      {
      int indexSingle1 = baseSingle + iParticleFilter1;
      ParticleSingleHistos & bSingleHistos1 = (ParticleSingleHistos &) getGroupAt(0,indexSingle1);
      ParticleSingleDerivedHistos & dSingleHistos1 = (ParticleSingleDerivedHistos &) getGroupAt(2,indexSingle1);
      for (int iParticleFilter2 = 0; iParticleFilter2<nParticleFilters;iParticleFilter2++)
        {
        int indexSingle2 = baseSingle + iParticleFilter2;
        int indexPairs12 = basePair   + iParticleFilter1*nParticleFilters + iParticleFilter2;
        ParticleSingleHistos &bSingleHistos2 = (ParticleSingleHistos &)        getGroupAt(0,indexSingle2);
        ParticleSingleDerivedHistos &dSingleHistos2 = (ParticleSingleDerivedHistos &) getGroupAt(2,indexSingle2);
        ParticlePairHistos &bPairHistos = (ParticlePairHistos &) getGroupAt(1,indexPairs12);
        ParticlePairDerivedHistos & dPairHistos = (ParticlePairDerivedHistos &) getGroupAt(3,indexPairs12);
        dPairHistos.calculatePairDerivedHistograms(bSingleHistos1,bSingleHistos2,dSingleHistos1,dSingleHistos2,bPairHistos,1.0);
        }
      }
    }

  if (reportEnd(__FUNCTION__))   { /* */ };
}

void ParticlePairCalculator::scaleHistograms()
{
  
}


} // namespace CAP
