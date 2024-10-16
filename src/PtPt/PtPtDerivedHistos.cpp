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
#include "PtPtDerivedHistos.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::PtPtDerivedHistos);

namespace CAP
{

PtPtDerivedHistos::PtPtDerivedHistos()
:
HistogramGroup(),
h_F1_evtClass(),
h_F2_evtClass(),
h_F3_evtClass(),
h_F4_evtClass(),
h_q1_evtClass(),
h_q1q1_evtClass(),
h_q1q1q1_evtClass(),
h_q1q1q1q1_evtClass(),
h_dq1dq1_evtClass(),
h_dq1dq1dq1_evtClass(),
h_dq1dq1dq1dq1_evtClass(),
particleFilters()
{
  appendClassName("PtPtDerivedHistos");
  setInstanceName("PtPtDerived");
}

PtPtDerivedHistos::PtPtDerivedHistos(const PtPtDerivedHistos & group)
:
HistogramGroup(),
h_F1_evtClass(),
h_F2_evtClass(),
h_F3_evtClass(),
h_F4_evtClass(),
h_q1_evtClass(),
h_q1q1_evtClass(),
h_q1q1q1_evtClass(),
h_q1q1q1q1_evtClass(),
h_dq1dq1_evtClass(),
h_dq1dq1dq1_evtClass(),
h_dq1dq1dq1dq1_evtClass(),
particleFilters()
{
  cloneAll(group);
}

PtPtDerivedHistos & PtPtDerivedHistos::operator=(const PtPtDerivedHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    particleFilters = group.particleFilters;
    cloneAll(group);
    }
  return *this;
}

void PtPtDerivedHistos::cloneAll(const PtPtDerivedHistos & group  __attribute__((unused)))
{
  if (reportStart(__FUNCTION__))  { /* no ops */ }
  // ony clone those that exist...
  //  if (group.h_f) h_f  = (TH1*) group.h_f->Clone();
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}


// for now use the same boundaries for eta and y histogram
void PtPtDerivedHistos::createHistograms()
{
  if (reportStart(__FUNCTION__))  { /* no ops */ }
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  String evtClassName = configuration.getValueString(ptn,"EvtClassName");
  int nBins_EvtClass   = configuration.getValueInt(ptn,"nBins_EvtClass");
  double min_EvtClass  = configuration.getValueDouble(ptn,"Min_EvtClass");
  double max_EvtClass  = configuration.getValueDouble(ptn,"Max_EvtClass");

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn);
    printValue("Parent Path Name",ppn);
    printValue("Histo Base Name.",bn);
    printValue("EvtClassName",evtClassName);
    printValue("nBins_EvtClass",nBins_EvtClass);
    printValue("Min_EvtClass",min_EvtClass);
    printValue("Max_EvtClass",max_EvtClass);
    printCR();
    }
  //  String name;
  String xTitle = "EvtClass";
  // use multiple filters -- but diagonnally only
  // no mixed species for now.
  for (auto & particleFilter1 : particleFilters)
    {
    String pfn = particleFilter1->getName();
    String pft = particleFilter1->getTitle();
    h_F1_evtClass.push_back( createHistogram(createName(bn,pfn,"F1"),nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("F_{1}",pft)) );
    h_F2_evtClass.push_back( createHistogram(createName(bn,pfn,"F2"),nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("F_{2}",pft)) );
    h_F3_evtClass.push_back( createHistogram(createName(bn,pfn,"F3"),nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("F_{3}",pft)) );
    h_F4_evtClass.push_back( createHistogram(createName(bn,pfn,"F4"),nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("F_{4}",pft)) );
    h_R2_evtClass.push_back( createHistogram(createName(bn,pfn,"R2"),nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("R_{2}",pft)) );
    h_R3_evtClass.push_back( createHistogram(createName(bn,pfn,"R3"),nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("R_{3}",pft)) );
    h_R4_evtClass.push_back( createHistogram(createName(bn,pfn,"R4"),nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("R_{4}",pft)) );

    h_q1_evtClass.push_back(           createHistogram(createName(bn,pfn,"q1"),          nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("q_{1}",pft)) );
    h_q1q1_evtClass.push_back(         createHistogram(createName(bn,pfn,"q1q1"),        nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("q_{1}q_{1}",pft)) );
    h_q1q1q1_evtClass.push_back(       createHistogram(createName(bn,pfn,"q1q1q1"),      nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("q_{1}q_{1}q_{1}",pft)) );
    h_q1q1q1q1_evtClass.push_back(     createHistogram(createName(bn,pfn,"q1q1q1q1"),    nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("q_{1}q_{1}q_{1}q_{1}",pft)) );
    h_dq1dq1_evtClass.push_back(       createHistogram(createName(bn,pfn,"dq1dq1"),      nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("#Delta q_{1}#Delta q_{1}",pft)) );
    h_dq1dq1dq1_evtClass.push_back(    createHistogram(createName(bn,pfn,"dq1dq1dq1"),   nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("#Delta q_{1}#Delta q_{1}#Delta q_{1}",pft)) );
    h_dq1dq1dq1dq1_evtClass.push_back( createHistogram(createName(bn,pfn,"dq1dq1dq1dq1"),nBins_EvtClass,min_EvtClass,max_EvtClass,xTitle,createTitle("#Delta q_{1}#Delta q_{1}#Delta q_{1}#Delta q_{1}",pft)) );
    }
}

void PtPtDerivedHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__))  { /* no ops */ }
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  String evtClassName  = configuration.getValueString(ptn,"EvtClassName");
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn);
    printValue("Parent Path Name",ppn);
    printValue("Histo Base Name.",bn);
    printValue("EvtClassName",evtClassName);
    printCR();
    }

  //String name;
  String xTitle = "M";
  //String title;

  for (auto & particleFilter1 : particleFilters)
    {
    String pfn = particleFilter1->getName();
    h_F1_evtClass.push_back( importProfile(inputFile,createName(bn,pfn,"F1") ));
    h_F2_evtClass.push_back( importProfile(inputFile,createName(bn,pfn,"F2") ));
    h_F3_evtClass.push_back( importProfile(inputFile,createName(bn,pfn,"F3") ));
    h_F4_evtClass.push_back( importProfile(inputFile,createName(bn,pfn,"F4") ));
    h_q1_evtClass.push_back( importProfile(inputFile,createName(bn,pfn,"q1") ));
    h_q1q1_evtClass.push_back( importProfile(inputFile,createName(bn,pfn,"q1q1") ));
    h_q1q1q1_evtClass.push_back( importProfile(inputFile,createName(bn,pfn,"q1q1q1") ));
    h_q1q1q1q1_evtClass.push_back( importProfile(inputFile,createName(bn,pfn,"q1q1q1q1") ));
    h_dq1dq1_evtClass.push_back( importProfile(inputFile,createName(bn,pfn,"dq1dq1") ));
    h_dq1dq1dq1_evtClass.push_back( importProfile(inputFile,createName(bn,pfn,"dq1dq1dq1") ));
    h_dq1dq1dq1dq1_evtClass.push_back( importProfile(inputFile,createName(bn,pfn,"dq1dq1dq1dq1") ));
    }
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}

void PtPtDerivedHistos::calculateDerivedHistograms(PtPtHistos* baseHistos)
{
  if (reportStart(__FUNCTION__))  { /* no ops */ }
  PtPtHistos & src = *baseHistos;
  unsigned int nFilters = particleFilters.size();
  for (unsigned int i1=0; i1<nFilters; i1++)
    {
    calculateF1(src.h_f1_evtClass[i1], h_F1_evtClass[i1]);
    calculateF2R2(src.h_f1_evtClass[i1], src.h_f1_evtClass[i1],
                  src.h_f2_evtClass[i1],
                  h_F2_evtClass[i1],
                  h_R2_evtClass[i1]);
    calculateF3R3(src.h_f1_evtClass[i1],src.h_f1_evtClass[i1],src.h_f1_evtClass[i1],
                  src.h_f2_evtClass[i1],src.h_f2_evtClass[i1],src.h_f2_evtClass[i1],
                  src.h_f3_evtClass[i1],
                  h_F3_evtClass[i1],
                  h_R3_evtClass[i1]);
    calculateF4R4(src.h_f1_evtClass[i1],src.h_f1_evtClass[i1],src.h_f1_evtClass[i1],src.h_f1_evtClass[i1],
                  src.h_f2_evtClass[i1],src.h_f2_evtClass[i1],src.h_f2_evtClass[i1],
                  src.h_f2_evtClass[i1],src.h_f2_evtClass[i1],src.h_f2_evtClass[i1],
                  src.h_f3_evtClass[i1],src.h_f3_evtClass[i1],src.h_f3_evtClass[i1],src.h_f3_evtClass[i1],
                  src.h_f4_evtClass[i1],
                  h_F4_evtClass[i1],h_R4_evtClass[i1]);

    }
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}

void PtPtDerivedHistos::setParticleFilters(const vector<ParticleFilter*> & _particleFilters)
{
  particleFilters = _particleFilters;
}

vector<ParticleFilter*> & PtPtDerivedHistos::getParticleFilters()
{
  return particleFilters;
}

const vector<ParticleFilter*> & PtPtDerivedHistos::getParticleFilters() const
{
  return particleFilters;
}


} // namespace CAP
