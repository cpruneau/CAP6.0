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
#include "GlobalDerivedHistos.hpp"
#include "RootHelpers.hpp"
ClassImp(CAP::GlobalDerivedHistos);

namespace CAP
{

GlobalDerivedHistos::GlobalDerivedHistos()
:
HistogramGroup(),
particleFilters(),
h_ptAvgInc(),
h_ptAvgIncVsN()
{
  appendClassName("GlobalDerivedHistos");
}

// for now use the same boundaries for eta and y histogram
void GlobalDerivedHistos::createHistograms()
{
  if ( reportStart(__FUNCTION__)) { /* no ops */ };
  const String & bn  = getName();
  const String & ptn = getParentName( );
  const String & ppn = getParentPathName();
  int nBins_n  = configuration.getValueInt(ptn,"nBins_n");
  double min_n = configuration.getValueDouble(ptn,"Min_n");
  double max_n = configuration.getValueDouble(ptn,"Max_n");
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn);
    printValue("Parent Path Name",ppn);
    printValue("Histo Base Name",bn);
    printValue("Derived:nBins_n",nBins_n);
    printValue("Derived:Min_n",min_n);
    printValue("Derived:Max_n",max_n);
    printValue("nParticleFilters",particleFilters.size());
    printCR();
    }
  for (auto & particleFilter : particleFilters)
    {
    String pfName1 = particleFilter->getName();
    h_ptAvgInc.push_back(    createHistogram(createName(bn,pfName1,"nWB",pfName1,"ptAvgIncl"),  1,       min_n,  max_n,"n","ptAvgIncl")  );
    h_ptAvgIncVsN.push_back( createHistogram(createName(bn,pfName1,"n",  pfName1,"ptAvgIncl"),  nBins_n, min_n,  max_n,"n","ptAvgIncl") );
    }
  if ( reportEnd(__FUNCTION__)) { /* no ops */ };
}

//________________________________________________________________________
void GlobalDerivedHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)){ /* no ops */  };
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn);
    printValue("Parent Path Name",ppn);
    printValue("Histo Base Name",bn);
    printValue("nParticleFilters",particleFilters.size());
    printCR();
    }
  for (auto & particleFilter : particleFilters)
    {
    String pfName1 = particleFilter->getName();
    h_ptAvgInc.push_back(    importH1(inputFile, createName(bn,pfName1,"nWB",pfName1,"ptAvgIncl")));
    h_ptAvgIncVsN.push_back( importH1(inputFile, createName(bn,pfName1,"n",  pfName1,"ptAvgIncl")));
    }
  if ( reportEnd(__FUNCTION__)){ /* no ops */  };
}

//!
//! Calculates derived histograms. This is currently limited to pt averages vs eta and phi.
//!
void GlobalDerivedHistos::calculateDerivedHistograms(GlobalHistos & baseHistos __attribute__((unused)))
{
  if (reportStart(__FUNCTION__)) { /* no ops */  };
  if (reportEnd(__FUNCTION__)) { /* no ops */  };
}

void GlobalDerivedHistos::setParticleFilters(const vector<ParticleFilter*> & _particleFilters)
{
  particleFilters = _particleFilters;
}

vector<ParticleFilter*> & GlobalDerivedHistos::getParticleFilters()
{
  return particleFilters;
}

const vector<ParticleFilter*> & GlobalDerivedHistos::getParticleFilters() const
{
  return particleFilters;
}


} // namespace CAP

