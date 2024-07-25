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
#include "Particle.hpp"
#include "SpherocityHistos.hpp"

ClassImp(CAP::SpherocityHistos);

namespace CAP
{

SpherocityHistos::SpherocityHistos()
:
HistogramGroup(),
fillS0(true),
fillS1(false),
fillS1VsS0(false),
fillCorrelationHistos(false),
particleFilters(),
h_s0(),
h_s1(),
h_s1VsS0(),
h_s0VsS0()
{
  appendClassName("SpherocityHistos");
  setInstanceName("Spherocity");
}

SpherocityHistos::SpherocityHistos(const SpherocityHistos & group)
:
HistogramGroup(group),
fillS0(group.fillS0),
fillS1(group.fillS1),
fillS1VsS0(group.fillS1VsS0),
fillCorrelationHistos(group.fillCorrelationHistos),
particleFilters(group.particleFilters),
h_s0(),
h_s1(),
h_s1VsS0(),
h_s0VsS0()
{
  cloneAll(group);
}

SpherocityHistos & SpherocityHistos::operator=(const SpherocityHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    fillS0     = group.fillS0;
    fillS1     = group.fillS1;
    fillS1VsS0 = group.fillS1VsS0;
    fillCorrelationHistos = group.fillCorrelationHistos;
    particleFilters       = group.particleFilters;
    cloneAll(group);
    }
  return *this;
}

void SpherocityHistos::cloneAll(const SpherocityHistos & group)
{
  cloneHistoVector(group.h_s0,h_s0);
  cloneHistoVector(group.h_s1,h_s1);
  cloneHistoVector(group.h_s1VsS0,h_s1VsS0);
  cloneHistoVector(group.h_s0VsS0,h_s0VsS0);
}

void SpherocityHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* no ops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  fillS0     = configuration.getValueBool(ppn,"FillS0");
  fillS1     = configuration.getValueBool(ppn,"FillS1");
  fillS1VsS0 = configuration.getValueBool(ppn,"FillS1VsS0");
  fillCorrelationHistos   = configuration.getValueBool(ppn,"FillCorrelationHistos");
  int nBins_spherocity    = configuration.getValueInt(ppn,"nBins_spherocity");
  double min_spherocity   = configuration.getValueDouble(ppn,"Min_spherocity");
  double max_spherocity   = configuration.getValueDouble(ppn,"Max_spherocity");
  int nParticleFilters = particleFilters.size();

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn);
    printValue("Parent Path Name",ppn);
    printValue("Histo Base Name",bn);
    printValue("nParticleFilters",nParticleFilters);
    printValue("fillS0",fillS0);
    printValue("fillS1",fillS1);
    printValue("fillS1VsS0",fillS1VsS0);
    printValue("nBins_spherocity",nBins_spherocity);
    printValue("min_spherocity",min_spherocity);
    printValue("max_spherocity",max_spherocity);
    printCR();
    }

  for (int iPartFilter1=0; iPartFilter1<nParticleFilters; iPartFilter1++ )
    {
    String pfn1 = particleFilters[iPartFilter1]->getName();
    if (fillS0) h_s0.push_back( createHistogram(createName(bn,pfn1,"S0"), nBins_spherocity,min_spherocity,max_spherocity,"S_{0}","N"));
    if (fillS1) h_s1.push_back( createHistogram(createName(bn,pfn1,"S1"), nBins_spherocity,min_spherocity,max_spherocity,"S_{1}","N"));
    if (fillS1VsS0)
      h_s1VsS0.push_back( createHistogram(createName(bn,pfn1,"S1VsS0"),
                                          nBins_spherocity,min_spherocity,max_spherocity,nBins_spherocity,min_spherocity,max_spherocity,
                                          "S_{0}","S_{1}","N"));
    if (fillCorrelationHistos)
      printValue("fillCorrelationHistos IS ON w/ nParticleFilters",nParticleFilters);
    else
      printString("fillCorrelationHistos IS OFF");

    if (fillCorrelationHistos)
      {
      for (int iPartFilter2=iPartFilter1+1; iPartFilter2<nParticleFilters; iPartFilter2++ )
          {
          String pfn2 = particleFilters[iPartFilter2]->getName();
          h_s0VsS0.push_back( createHistogram(createName(bn,pfn1,"S0VsS0"),
                                              nBins_spherocity,min_spherocity,max_spherocity,
                                              nBins_spherocity,min_spherocity,max_spherocity,
                                              "S_{0}","S_{0}","N"));
          }
      }
    }
  if ( reportEnd(__FUNCTION__)) { /* no ops*/ };
}

void SpherocityHistos::importHistograms(TFile & inputFile)
{
  if ( reportStart(__FUNCTION__)) { /* no ops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  fillS0     = configuration.getValueBool(ppn,"FillS0");
  fillS1     = configuration.getValueBool(ppn,"FillS1");
  fillS1VsS0 = configuration.getValueBool(ppn,"FillS1VsS0");
  fillCorrelationHistos = configuration.getValueBool(ppn,"FillCorrelationHistos");
  int nParticleFilters = particleFilters.size();
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn);
    printValue("Parent Path Name",ppn);
    printValue("Histo Base Name",bn);
    printValue("nParticleFilters",nParticleFilters);
    printValue("fillS0",fillS0);
    printValue("fillS1",fillS1);
    printValue("fillS1VsS0",fillS1VsS0);
    printCR();
    }
  for (int iPartFilter1=0; iPartFilter1<nParticleFilters; iPartFilter1++ )
    {
    String pfn1 = particleFilters[iPartFilter1]->getName();
    if (fillS0) h_s0.push_back( importH1(inputFile, createName(bn,pfn1,"S0")));
    if (fillS1) h_s1.push_back( importH1(inputFile, createName(bn,pfn1,"S1")));
    if (fillS1VsS0) h_s1VsS0.push_back( importH2(inputFile, createName(bn,pfn1,"S1VsS0")));
    if (fillCorrelationHistos)
      {
      for (int iPartFilter2=iPartFilter1+1; iPartFilter2<nParticleFilters; iPartFilter2++ )
          {
          String pfn2 = particleFilters[iPartFilter2]->getName();
          h_s0VsS0.push_back( importH2(inputFile, createName(bn,pfn1,pfn2,"S0VsS0")));
          }
      }
    }
  if ( reportEnd(__FUNCTION__)) { /* no ops*/ };
}

//!
//! Fiil  single particle histograms of this class with the particles contained in the given list.
//!
void SpherocityHistos::fill(vector<double> & s0, vector<double> & s1, double weight)
{
  int k = 0;
  int nParticleFilters = particleFilters.size();
  for (int iPartFilter1=0; iPartFilter1<nParticleFilters; iPartFilter1++ )
    {
    if (fillS0) h_s0[iPartFilter1]->Fill(s0[iPartFilter1],weight);
    if (fillS1) h_s1[iPartFilter1]->Fill(s1[iPartFilter1],weight);
    if (fillS1VsS0) h_s1VsS0[iPartFilter1]->Fill(s0[iPartFilter1],s1[iPartFilter1],weight);
    if (fillCorrelationHistos)
      {
      for (int iPartFilter2=iPartFilter1+1; iPartFilter2<nParticleFilters; iPartFilter2++ )
          {
          h_s0VsS0[k]->Fill(s0[iPartFilter1],s0[iPartFilter2],weight);
          k++;
          }
      }
    }
}

void SpherocityHistos::setParticleFilters(const vector<ParticleFilter*> & _particleFilters)
{
  particleFilters = _particleFilters;
}

vector<ParticleFilter*> & SpherocityHistos::getParticleFilters()
{
  return particleFilters;
}

const vector<ParticleFilter*> & SpherocityHistos::getParticleFilters() const
{
  return particleFilters;
}


} // namespace CAP
