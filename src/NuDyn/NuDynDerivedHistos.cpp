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
#include "NuDynDerivedHistos.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::NuDynDerivedHistos);

namespace CAP
{

NuDynDerivedHistos::NuDynDerivedHistos()
:
HistogramGroup(),
h_F2_evtClass(),
h_R2_evtClass(),
h_nudyn_evtClass()
{
  appendClassName("NuDynDerivedHistos");
  setInstanceName("NuDynDerivedHistos");
}

NuDynDerivedHistos::NuDynDerivedHistos(const NuDynDerivedHistos & group)
:
HistogramGroup(),
particleFilters(),
h_F2_evtClass(),
h_R2_evtClass(),
h_nudyn_evtClass()
{
  cloneAll(group);
}

NuDynDerivedHistos & NuDynDerivedHistos::operator=(const NuDynDerivedHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    particleFilters = group.particleFilters;
    cloneAll(group);
    }
  return *this;
}

void NuDynDerivedHistos::cloneAll(const NuDynDerivedHistos & group  __attribute__((unused)))
{
  if (reportStart(__FUNCTION__))  { /* no ops */ }
  // ony clone those that exist...
  //  if (group.h_n) h_n  = (TH1*) group.h_n->Clone();
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}


// for now use the same boundaries for eta and y histogram
void NuDynDerivedHistos::createHistograms()
{
  if (reportStart(__FUNCTION__))  { /* no ops */ }
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  String evtClassName  = configuration.getValueString(ptn,"EvtClassName");
  int nBins_EvtClass   = configuration.getValueInt(ptn,"nBins_EvtClass");
  double min_EvtClass  = configuration.getValueDouble(ptn,"Min_EvtClass");
  double max_EvtClass  = configuration.getValueDouble(ptn,"Max_EvtClass");
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn);
    printValue("Parent Path Name",ppn);
    printValue("Histo Base Name",bn);
    printValue("EvtClassName",evtClassName);
    printCR();
    }

  String name;
  String xTitle = "M";
  String yTitle;
  for (auto & particleFilter1 : particleFilters)
    {
    String pfn1 = particleFilter1->getName();
    String pft1 = particleFilter1->getTitle();
    for (auto & particleFilter2 : particleFilters)
      {
      String pfn2 = particleFilter2->getName();
      String pft2 = particleFilter2->getTitle();
      h_F2_evtClass.push_back(createHistogram(createName(bn,pfn1,pfn2,"F2"),
                                            nBins_EvtClass,min_EvtClass,max_EvtClass,
                                            xTitle,createTitle("F_{2}",pft1,pft2) ) );
      h_R2_evtClass.push_back(createHistogram(createName(bn,pfn1,pfn2,"R2"),
                                            nBins_EvtClass,min_EvtClass,max_EvtClass,
                                            xTitle,createTitle("R_{2}",pft1,pft2) ) );
      if (particleFilter1 == particleFilter2) continue;
      h_nudyn_evtClass.push_back(createHistogram(createName(bn,pfn1,pfn2,"NuDyn"),
                                               nBins_EvtClass,min_EvtClass,max_EvtClass,
                                               xTitle,createTitle("#nu_{Dyn}",pft1,pft2) ) );
      }
    }
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}

void NuDynDerivedHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__))  { /* no ops */ }
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  String evtClassName  = configuration.getValueInt(ptn,"EvtClassName");
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn);
    printValue("Parent Path Name",ppn);
    printValue("Histo Base Name.",bn);
    printValue("EvtClassName",evtClassName);
    printCR();
    }

  String name;
  String xTitle = "EvtClass";
  String title;

  for (auto & particleFilter1 : particleFilters)
    {
    String pfn1 = particleFilter1->getName();
    String pft1 = particleFilter1->getTitle();
    for (auto & particleFilter2 : particleFilters)
      {
      String pfn2 = particleFilter2->getName();
      String pft2 = particleFilter2->getTitle();
      h_F2_evtClass.push_back(importH1(inputFile,createName(bn,pfn1,pfn2,"F2")));
      h_R2_evtClass.push_back(importH1(inputFile,createName(bn,pfn1,pfn2,"R2")));
      h_nudyn_evtClass.push_back(importH1(inputFile,createName(bn,pfn1,pfn2,"NuDyn")));
      }
    }
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}

void NuDynDerivedHistos::calculateDerivedHistograms(NuDynHistos* baseHistos)
{
  if (reportStart(__FUNCTION__))  { /* no ops */ }

  NuDynHistos & source = *baseHistos;
  unsigned int nFilters = particleFilters.size();
  unsigned int nu12 = 0;
  for (unsigned int i1=0;   i1<nFilters; i1++)
    {
    for (unsigned int i2=0; i2<nFilters; i2++)
      {
      unsigned int i12 = i1*nFilters + i2;
      printValue("CalculateDerived() i1",i1);
      printValue("CalculateDerived() i2",i2);
      printValue("CalculateDerived() i12",i12);
      printValue("CalculateDerived() h_f1_evtClass[i1]",source.h_f1_evtClass[i1]->GetYaxis()->GetTitle());
      printValue("CalculateDerived() h_f1_evtClass[i2]",source.h_f1_evtClass[i2]->GetYaxis()->GetTitle());
      printValue("CalculateDerived() h_f2_evtClass[i12]",source.h_f2_evtClass[i12]->GetYaxis()->GetTitle());
      printValue("CalculateDerived() h_F2_evtClass[i12]",h_F2_evtClass[i12]->GetYaxis()->GetTitle());
      printValue("CalculateDerived() h_R2_evtClass[i12]",h_R2_evtClass[i12]->GetYaxis()->GetTitle());
      calculateF2R2(source.h_f1_evtClass[i1],
                    source.h_f1_evtClass[i2],
                    source.h_f2_evtClass[i12],
                    h_F2_evtClass[i12],
                    h_R2_evtClass[i12]);
      if (i1==i2) continue;
      printValue("CalculateDerived() nu12",nu12);
      printValue("CalculateDerived() h_nudyn_evtClass[nu12]",h_nudyn_evtClass[nu12]->GetYaxis()->GetTitle());
      calculateNudyn(h_R2_evtClass[i1*nFilters + i1],
                     h_R2_evtClass[i1*nFilters + i2],
                     h_R2_evtClass[i2*nFilters + i1],
                     h_R2_evtClass[i2*nFilters + i2],
                     h_nudyn_evtClass[nu12]);
      nu12++;
      }
    }
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}


void NuDynDerivedHistos::setParticleFilters(const vector<ParticleFilter*> & _particleFilters)
{
  particleFilters = _particleFilters;
}

vector<ParticleFilter*> & NuDynDerivedHistos::getParticleFilters()
{
  return particleFilters;
}

const vector<ParticleFilter*> & NuDynDerivedHistos::getParticleFilters() const
{
  return particleFilters;
}


} // namespace CAP
