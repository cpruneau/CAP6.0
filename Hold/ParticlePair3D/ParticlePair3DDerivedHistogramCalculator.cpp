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
#include "ParticlePair3DDerivedHistogramCalculator.hpp"



ClassImp(ParticlePair3DDerivedHistogramCalculator);

ParticlePair3DDerivedHistogramCalculator::ParticlePair3DDerivedHistogramCalculator(const String & _name,
                                                                                   const Configuration & _configuration,
                                                                                   vector<EventFilter*> & _eventFilters,
                                                                                   vector<ParticleFilter*> &_particleFilters)
:
DerivedHistogramCalculator(_name, _configuration, _eventFilters, _particleFilters)
{
  appendClassName("ParticlePair3DDerivedHistogramCalculator");
}

void ParticlePair3DDerivedHistogramCalculator::setDefaultConfiguration()
{
  Task::setDefaultConfiguration();
  addProperty("UseParticles",     true);
  addProperty("HistogramsCreate", true);
  addProperty("HistogramsImport",   true);
  addProperty("HistogramsExport",   true);
  addProperty("binCorrPP", 1.0);
  addProperty("fillEta",  true);
  addProperty("fillY",    false);
  addProperty("fillP2",   false);
  addProperty("nBins_n1",  100);
  addProperty("min_n1",    0.0);
  addProperty("max_n1",  100.0);
  addProperty("nBins_eTot",  100);
  addProperty("min_eTot",    0.0);
  addProperty("max_eTot",  100.0);
  addProperty("nBins_pt",   18);
  addProperty("min_pt",   0.20);
  addProperty("max_pt",   2.00);
  addProperty("nBins_phi",  72);
  addProperty("min_phi",   0.0);
  addProperty("max_phi", CAP::Math::twoPi());
  addProperty("nBins_eta",   20);
  addProperty("min_eta",   -1.0);
  addProperty("max_eta",    1.0);
  addProperty("nBins_y",     20);
  addProperty("min_y",     -1.0);
  addProperty("max_y",      1.0);
  addProperty("nBins_phiEta",    720);
  addProperty("nBins_phiEtaPt",  7200);
  addProperty("nBins_phiY",      720);
  addProperty("nBins_phiYPt",    7200);
  addProperty("nBins_n2",          100);
  addProperty("min_n2",            0.0);
  addProperty("max_n2",         1000.0);
  addProperty("nBins_DeltaPlong",   10);
  addProperty("min_DeltaPlong",   -1.0);
  addProperty("max_DeltaPlong",    1.0);
  addProperty("nBins_DeltaPside",   10);
  addProperty("min_DeltaPside",   -1.0);
  addProperty("max_DeltaPside",    1.0);
  addProperty("range_DeltaPside",  2.0);
  addProperty("nBins_DeltaPout",    10);
  addProperty("min_DeltaPout",    -1.0);
  addProperty("max_DeltaPout",     1.0);
  addProperty("range_DeltaPout",   2.0);
  addProperty("nBins_Dphi",         36);
  addProperty("min_Dphi",          0.0);
  addProperty("max_Dphi",CAP::Math::twoPi());
  addProperty("width_Dphi",CAP::Math::twoPi());
  addProperty("nBins_Dphi_shft",    36);
  addProperty("min_Dphi_shft",     0.0);
  addProperty("max_Dphi_shft",     0.0);
  addProperty("nBins_Deta",         39);
  addProperty("min_Deta",         -2.0);
  addProperty("max_Deta",          2.0);
  addProperty("width_Deta",   4.0/39.0);
  addProperty("nBins_Dy",           39);
  addProperty("min_Dy",           -2.0);
  addProperty("max_Dy",            2.0);
  addProperty("width_Dy",     4.0/39.0);
}

void ParticlePair3DDerivedHistogramCalculator::HistogramsCreate()
{
  
  if (reportStart(__FUNCTION__))
    ;
  derivedSingleHistograms.clear();
  derivedPairHistograms.clear();
  const Configuration & configuration = getConfiguration();
  Severity debugLevel = getSeverityLevel();
  String bn  = getName();
  HistogramGroup * histos;
  if (reportDebug(__FUNCTION__))
    {
    cout << endl;
    cout << "       Creating HistogramGroup: " << bn << endl;
    cout << "             nEventFilters: " << nEventFilters << endl;
    cout << "          nParticleFilters: " << nParticleFilters << endl;
    cout << endl;
    }
  for (int iEventFilter=0; iEventFilter<nEventFilters; iEventFilter++ )
    {
    String efn = eventFilters[iEventFilter]->getName();
    if (reportDebug(__FUNCTION__)) cout << "Event filter:" << efn << endl;
    // singles
    for (int iParticleFilter1=0; iParticleFilter1<nParticleFilters; iParticleFilter1++ )
      {
      String pfn1 = particleFilters[iParticleFilter1]->getName();
      if (reportDebug(__FUNCTION__)) cout << "Particle with filter: " << pfn1 << endl;
      histos = new ParticleDerivedHistos(createName(bn,efn,pfn1),configuration);
      histos->HistogramsCreate();
      derivedSingleHistograms.push_back(histos);
      }
    // pairs
    for (int iParticleFilter1=0; iParticleFilter1<nParticleFilters; iParticleFilter1++ )
      {
      String pfn1 = particleFilters[iParticleFilter1]->getName();
      for (int iParticleFilter2=0; iParticleFilter2<nParticleFilters; iParticleFilter2++ )
        {
        String pfn2 = particleFilters[iParticleFilter2]->getName();
        if (reportDebug(__FUNCTION__)) cout << "Particle pairs with filter: " << pfn1 << " & " << pfn2 << endl;
        histos = new ParticlePair3DDerivedHistos(createName(bn,efn,pfn1,pfn2),configuration);
        histos->HistogramsCreate();
        derivedPairHistograms.push_back(histos);
        }
      }
    }
  if (reportEnd(__FUNCTION__))
    ;
}

void ParticlePair3DDerivedHistogramCalculator::HistogramsImport(TFile & inputFile)
{
  
  if (reportStart(__FUNCTION__))
    ;
  if (!ptrFileExist(inputFile)) return;
  
  baseSingleHistograms.clear();
  basePairHistograms.clear();
  const Configuration & configuration = getConfiguration();
  Severity debugLevel = getSeverityLevel();
  String bn  = getName();
   if (reportDebug(__FUNCTION__))
    {
    cout << endl;
    cout << "       Loading HistogramGroup: " << bn << endl;
    cout << "             nEventFilters: " << nEventFilters << endl;
    cout << "          nParticleFilters: " << nParticleFilters << endl;
    cout << endl;
    }
  baseSingleHistograms.clear();
  basePairHistograms.clear();
  for (int iEventFilter=0; iEventFilter<nEventFilters; iEventFilter++ )
    {
    String efn = eventFilters[iEventFilter]->getName();
    if (reportDebug(__FUNCTION__)) cout << "Event filter:" << efn << endl;
    // singles
    for (int iParticleFilter1=0; iParticleFilter1<nParticleFilters; iParticleFilter1++ )
      {
      String pfn1 = particleFilters[iParticleFilter1]->getName();
      if (reportDebug(__FUNCTION__)) cout << "Particle with filter: " << pfn1 << endl;
      ParticleHistos * histos = new ParticleHistos(createName(bn,efn,pfn1),configuration);
      histos->HistogramsImport(inputFile);
      baseSingleHistograms.push_back(histos);
      }
    // pairs
    for (int iParticleFilter1=0; iParticleFilter1<nParticleFilters; iParticleFilter1++ )
      {
      String pfn1 = particleFilters[iParticleFilter1]->getName();
      for (int iParticleFilter2=0; iParticleFilter2<nParticleFilters; iParticleFilter2++ )
        {
        String pfn2 = particleFilters[iParticleFilter2]->getName();
        if (reportDebug(__FUNCTION__)) cout << "Particle pairs with filter: " << pfn1 << " & " << pfn2 << endl;
        ParticlePair3DHistos * histos = new ParticlePair3DHistos(createName(bn,efn,pfn1,pfn2),configuration);
        histos->HistogramsImport(inputFile);
        basePairHistograms.push_back(histos);
        }
      }
    }
  if (reportEnd(__FUNCTION__))
    ;
}

//!
//! Calculate Derived HistogramGroup
//!
// ====================================
void ParticlePair3DDerivedHistogramCalculator::execute()
{
  if (reportStart(__FUNCTION__))
    ;
   if (reportDebug(__FUNCTION__))
    {
    cout << endl;
    cout << "Computing derived histograms for: " << endl;
    printValue("nEventFilters",nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    printValue("nSingleHistos",getNBaseSingleHistograms());
    printValue("PairHistos",getNBasePairHistograms());
    printValue("nDerivedHistos",getNDerivedPairHistograms());
    }
  ParticleHistos        * bSingleHistos1;
  ParticleHistos        * bSingleHistos2;
  ParticlePair3DHistos    * bPairHistos;
  ParticleDerivedHistos * dSingleHistos1;
  ParticleDerivedHistos * dSingleHistos2;
  ParticlePair3DDerivedHistos * dPairHistos;
  
  for (int iEventFilter=0; iEventFilter<nEventFilters; iEventFilter++ )
    {
    if (reportDebug(__FUNCTION__))
      {
      cout << endl;
      printValue("iEventFilter",iEventFilter);
      }

    unsigned int index;
    unsigned int baseSingle        = iEventFilter*nParticleFilters;
    unsigned int basePair          = iEventFilter*nParticleFilters*nParticleFilters;
    //unsigned int baseDerivedPair   = basePair;
    
    //! Calculate derived spectra of singles
    for (int iParticleFilter1=0; iParticleFilter1<nParticleFilters; iParticleFilter1++)
      {
      String pfn1 = particleFilters[iParticleFilter1]->getName();
      index = baseSingle+iParticleFilter1;
      //if (reportDebug(__FUNCTION__))   cout << " (1) iParticleFilter1:" << iParticleFilter1 << " named " << pfn1 << " with index:" << index << endl;
      bSingleHistos1 = (ParticleHistos *) baseSingleHistograms[index];
      //if (reportDebug(__FUNCTION__))   cout << " (1a) iParticleFilter1:" << iParticleFilter1 << " named " << pfn1 << " with index:" << index << endl;
      dSingleHistos1 = (ParticleDerivedHistos *) derivedSingleHistograms[index];
      //if (reportDebug(__FUNCTION__))   cout << " (2) iParticleFilter1:" << iParticleFilter1 << " named " << pfn1 << " with index:" << index << endl;
      dSingleHistos1->calculateDerivedHistograms(bSingleHistos1);
      //if (reportDebug(__FUNCTION__))   cout << " (3) iParticleFilter1:" << iParticleFilter1 << " named " << pfn1 << " with index:" << index << endl;
      }
    
    //! Calculate derived spectra of pairs
    for (int iParticleFilter1=0; iParticleFilter1<nParticleFilters; iParticleFilter1++)
      {
      String pfn1 = particleFilters[iParticleFilter1]->getName();
      index = baseSingle+iParticleFilter1;
      bSingleHistos1 = (ParticleHistos *) baseSingleHistograms[index];
      dSingleHistos1 = (ParticleDerivedHistos *) derivedSingleHistograms[index];
      
      for (int iParticleFilter2=0; iParticleFilter2<nParticleFilters; iParticleFilter2++)
        {
        String pfn2 = particleFilters[iParticleFilter2]->getName();
//        if (reportDebug(__FUNCTION__))
//          cout << "  iParticleFilter1:" << iParticleFilter1 << " named " << pfn1 << ";  iParticleFilter2:" << iParticleFilter2<< " named " << pfn2  << endl;
        index = baseSingle+iParticleFilter2;
        bSingleHistos2 = (ParticleHistos *) baseSingleHistograms[index];
        dSingleHistos2 = (ParticleDerivedHistos *) derivedSingleHistograms[index];
        
        index = basePair+iParticleFilter1*nParticleFilters+iParticleFilter2;
        bPairHistos = (ParticlePair3DHistos *) basePairHistograms[index];
        dPairHistos = (ParticlePair3DDerivedHistos *) derivedPairHistograms[index];
        dPairHistos->calculatePairDerivedHistograms(*bSingleHistos1,*bSingleHistos2,*dSingleHistos1,*dSingleHistos2,*bPairHistos,
                                                    configuration.getValueDouble(getName(),"binCorrPP") );
        }
      }
    }
  if (reportEnd(__FUNCTION__))
    ;
}
