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
#include "NuDynHistos.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::NuDynHistos);

namespace CAP
{

NuDynHistos::NuDynHistos()
:
HistogramGroup(),
h_mult(),
h_f1_vsMult(),
h_f2_vsMult()
{
  appendClassName("NuDynHistos");
  setInstanceName("NuDyn");
}

NuDynHistos::NuDynHistos(const NuDynHistos & group)
:
HistogramGroup(group),
h_mult(),
h_f1_vsMult(),
h_f2_vsMult()
{
  cloneAll(group);
}

NuDynHistos & NuDynHistos::operator=(const NuDynHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group),
    cloneAll(group);
    }
  return *this;
}

void NuDynHistos::cloneAll(const NuDynHistos & group  __attribute__((unused)))
{
  if (reportStart(__FUNCTION__))  { /* no ops */ }
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}


// for now use the same boundaries for eta and y histogram
void NuDynHistos::createHistograms()
{
  if (reportStart(__FUNCTION__))  { /* no ops */ }
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  multName = configuration.getValueInt(ppn,"MultName");
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
    printValue("nBins_mult",nBins_mult);
    printValue("min_mult",min_mult);
    printValue("max_mult",max_mult);
    }
  h_mult = createHistogram(createName(bn,"mult"),nBins_mult,min_mult,max_mult,"M","Counts");
  for (auto & particleFilter1 : particleFilters)
    {
    String pName1 = particleFilter1->getName();
    h_f1_vsMult.push_back( createProfile(createName(bn,pName1,"f1"),nBins_mult,min_mult,max_mult,"M","f_{1}") );
    for (auto & particleFilter2 : particleFilters)
      {
      String pName2 = particleFilter2->getName();
      h_f2_vsMult.push_back( createProfile(createName(bn,pName1,pName2,"f2"),nBins_mult,min_mult,max_mult,"M","f_{2}") );
      }
    }
  if (reportEnd(__FUNCTION__))  {/* no ops */}
}

//________________________________________________________________________
void NuDynHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) {/* no ops */}

  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  multName = configuration.getValueInt(ppn,"MultName");
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
    printValue("nBins_mult",nBins_mult);
    printValue("min_mult",min_mult);
    printValue("max_mult",max_mult);
    }

  for (auto & particleFilter1 : particleFilters)
    {
    String pName1 = particleFilter1->getName();
    h_f1_vsMult.push_back( importProfile(inputFile,createName(bn,pName1,"f1") ));
    for (auto & particleFilter2 : particleFilters)
      {
      String pName2 = particleFilter2->getName();
      h_f2_vsMult.push_back( importProfile(inputFile,createName(bn,pName1,pName2,"f2") ));
      }
    }
  if (reportEnd(__FUNCTION__))  { /* no ops */ }
}


void NuDynHistos::fill(double mult,
                       vector<double> & n)
{
  unsigned int nFilters = n.size();
  unsigned int index = 0;
  for (unsigned int i1=0; i1<nFilters; i1++)
    {
    double n1 = n[i1];
    h_f1_vsMult[i1]->Fill(mult,n1);
    for (unsigned int i2=0; i2<nFilters; i2++)
      {
      if (i1==i2)
        h_f2_vsMult[index]->Fill(mult,n1*(n1-1));
      else
        h_f2_vsMult[index]->Fill(mult,n1*n[i2]);
      index++;
      }
    }
}

void NuDynHistos::setParticleFilters(const vector<ParticleFilter*> & _particleFilters)
{
  particleFilters = _particleFilters;
}

vector<ParticleFilter*> & NuDynHistos::getParticleFilters()
{
  return particleFilters;
}

const vector<ParticleFilter*> & NuDynHistos::getParticleFilters() const
{
  return particleFilters;
}


} // namespace CAP

