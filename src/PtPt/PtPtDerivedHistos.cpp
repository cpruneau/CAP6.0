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
h_F1_vsMult(),
h_F2_vsMult(),
h_F3_vsMult(),
h_F4_vsMult(),
h_q1_vsMult(),
h_q1q1_vsMult(),
h_q1q1q1_vsMult(),
h_q1q1q1q1_vsMult(),
h_dq1dq1_vsMult(),
h_dq1dq1dq1_vsMult(),
h_dq1dq1dq1dq1_vsMult(),
particleFilters()
{
  appendClassName("PtPtDerivedHistos");
  setInstanceName("PtPtDerived");
}

PtPtDerivedHistos::PtPtDerivedHistos(const PtPtDerivedHistos & group)
:
HistogramGroup(),
h_F1_vsMult(),
h_F2_vsMult(),
h_F3_vsMult(),
h_F4_vsMult(),
h_q1_vsMult(),
h_q1q1_vsMult(),
h_q1q1q1_vsMult(),
h_q1q1q1q1_vsMult(),
h_dq1dq1_vsMult(),
h_dq1dq1dq1_vsMult(),
h_dq1dq1dq1dq1_vsMult(),
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
  String multName = configuration.getValueInt(ppn,"MultName");
  int nBins_mult   = configuration.getValueInt(ppn,"nBins_mult");
  double min_mult  = configuration.getValueInt(ppn,"Min_mult");
  double max_mult  = configuration.getValueInt(ppn,"Max_mult");

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn);
    printValue("Parent Path Name",ppn);
    printValue("Histo Base Name.",bn);
    printValue("multName",multName);
    printCR();
    }
//  String name;
  String xTitle = "M";
  // use multiple filters -- but diagonnally only
  // no mixed species for now.
  for (auto & particleFilter1 : particleFilters)
    {
    String pfn = particleFilter1->getName();
    String pft = particleFilter1->getTitle();
    h_F1_vsMult.push_back( createHistogram(createName(bn,pfn,"F1"),nBins_mult,min_mult,max_mult,xTitle,createTitle("F_{1}",pft)) );
    h_F2_vsMult.push_back( createHistogram(createName(bn,pfn,"F2"),nBins_mult,min_mult,max_mult,xTitle,createTitle("F_{2}",pft)) );
    h_F3_vsMult.push_back( createHistogram(createName(bn,pfn,"F3"),nBins_mult,min_mult,max_mult,xTitle,createTitle("F_{3}",pft)) );
    h_F4_vsMult.push_back( createHistogram(createName(bn,pfn,"F4"),nBins_mult,min_mult,max_mult,xTitle,createTitle("F_{4}",pft)) );
    h_R2_vsMult.push_back( createHistogram(createName(bn,pfn,"R2"),nBins_mult,min_mult,max_mult,xTitle,createTitle("R_{2}",pft)) );
    h_R3_vsMult.push_back( createHistogram(createName(bn,pfn,"R3"),nBins_mult,min_mult,max_mult,xTitle,createTitle("R_{3}",pft)) );
    h_R4_vsMult.push_back( createHistogram(createName(bn,pfn,"R4"),nBins_mult,min_mult,max_mult,xTitle,createTitle("R_{4}",pft)) );

    h_q1_vsMult.push_back(           createHistogram(createName(bn,pfn,"q1"),          nBins_mult,min_mult,max_mult,xTitle,createTitle("q_{1}",pft)) );
    h_q1q1_vsMult.push_back(         createHistogram(createName(bn,pfn,"q1q1"),        nBins_mult,min_mult,max_mult,xTitle,createTitle("q_{1}q_{1}",pft)) );
    h_q1q1q1_vsMult.push_back(       createHistogram(createName(bn,pfn,"q1q1q1"),      nBins_mult,min_mult,max_mult,xTitle,createTitle("q_{1}q_{1}q_{1}",pft)) );
    h_q1q1q1q1_vsMult.push_back(     createHistogram(createName(bn,pfn,"q1q1q1q1"),    nBins_mult,min_mult,max_mult,xTitle,createTitle("q_{1}q_{1}q_{1}q_{1}",pft)) );
    h_dq1dq1_vsMult.push_back(       createHistogram(createName(bn,pfn,"dq1dq1"),      nBins_mult,min_mult,max_mult,xTitle,createTitle("#Delta q_{1}#Delta q_{1}",pft)) );
    h_dq1dq1dq1_vsMult.push_back(    createHistogram(createName(bn,pfn,"dq1dq1dq1"),   nBins_mult,min_mult,max_mult,xTitle,createTitle("#Delta q_{1}#Delta q_{1}#Delta q_{1}",pft)) );
    h_dq1dq1dq1dq1_vsMult.push_back( createHistogram(createName(bn,pfn,"dq1dq1dq1dq1"),nBins_mult,min_mult,max_mult,xTitle,createTitle("#Delta q_{1}#Delta q_{1}#Delta q_{1}#Delta q_{1}",pft)) );

    }
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}

void PtPtDerivedHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__))  { /* no ops */ }
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  String multName  = configuration.getValueInt(ppn,"MultName");
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn);
    printValue("Parent Path Name",ppn);
    printValue("Histo Base Name.",bn);
    printValue("multName",multName);
    printCR();
    }

  //String name;
  String xTitle = "M";
  //String title;

  for (auto & particleFilter1 : particleFilters)
    {
    String pfn = particleFilter1->getName();
    h_F1_vsMult.push_back( importProfile(inputFile,createName(bn,pfn,"F1") ));
    h_F2_vsMult.push_back( importProfile(inputFile,createName(bn,pfn,"F2") ));
    h_F3_vsMult.push_back( importProfile(inputFile,createName(bn,pfn,"F3") ));
    h_F4_vsMult.push_back( importProfile(inputFile,createName(bn,pfn,"F4") ));
    h_q1_vsMult.push_back( importProfile(inputFile,createName(bn,pfn,"q1") ));
    h_q1q1_vsMult.push_back( importProfile(inputFile,createName(bn,pfn,"q1q1") ));
    h_q1q1q1_vsMult.push_back( importProfile(inputFile,createName(bn,pfn,"q1q1q1") ));
    h_q1q1q1q1_vsMult.push_back( importProfile(inputFile,createName(bn,pfn,"q1q1q1q1") ));
    h_dq1dq1_vsMult.push_back( importProfile(inputFile,createName(bn,pfn,"dq1dq1") ));
    h_dq1dq1dq1_vsMult.push_back( importProfile(inputFile,createName(bn,pfn,"dq1dq1dq1") ));
    h_dq1dq1dq1dq1_vsMult.push_back( importProfile(inputFile,createName(bn,pfn,"dq1dq1dq1dq1") ));
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
    calculateF1(src.h_f1_vsMult[i1], h_F1_vsMult[i1]);
    calculateF2R2(src.h_f1_vsMult[i1], src.h_f1_vsMult[i1],
                  src.h_f2_vsMult[i1],
                  h_F2_vsMult[i1],
                  h_R2_vsMult[i1]);
    calculateF3R3(src.h_f1_vsMult[i1],src.h_f1_vsMult[i1],src.h_f1_vsMult[i1],
                  src.h_f2_vsMult[i1],src.h_f2_vsMult[i1],src.h_f2_vsMult[i1],
                  src.h_f3_vsMult[i1],
                  h_F3_vsMult[i1],
                  h_R3_vsMult[i1]);
    calculateF4R4(src.h_f1_vsMult[i1],src.h_f1_vsMult[i1],src.h_f1_vsMult[i1],src.h_f1_vsMult[i1],
                  src.h_f2_vsMult[i1],src.h_f2_vsMult[i1],src.h_f2_vsMult[i1],
                  src.h_f2_vsMult[i1],src.h_f2_vsMult[i1],src.h_f2_vsMult[i1],
                  src.h_f3_vsMult[i1],src.h_f3_vsMult[i1],src.h_f3_vsMult[i1],src.h_f3_vsMult[i1],
                  src.h_f4_vsMult[i1],
                  h_F4_vsMult[i1],h_R4_vsMult[i1]);

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
