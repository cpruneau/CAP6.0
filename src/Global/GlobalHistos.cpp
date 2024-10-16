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
#include "GlobalHistos.hpp"

ClassImp(CAP::GlobalHistos);

namespace CAP
{

GlobalHistos::GlobalHistos()
:
HistogramGroup(),
particleFilters(),
h_n(),
h_e(),
h_q(),
h_s(),
h_b(),
h_ptSum(),
h_ptAvg(),
h_nVsN(),
h_eVsN(),
h_qVsN(),
h_bVsN(),
h_ptSumVsN(),
h_ptAvgVsN(),
h_eVsE(),
h_qVsE(),
h_bVsE(),
h_qVsQ(),
h_bVsQ(),
h_bVsB(),
fill2D(false),
fillCorrelationHistos(false)
{
  appendClassName("GlobalHistos");
  setInstanceName("Global");
}

GlobalHistos::GlobalHistos(const GlobalHistos & group)
:
HistogramGroup(),
particleFilters(group.particleFilters),
h_n(),
h_e(),
h_q(),
h_s(),
h_b(),
h_ptSum(),
h_ptAvg(),
p_eVsN(),
p_qVsN(),
p_sVsN(),
p_bVsN(),
p_ptSumVsN(),
p_ptAvgVsN(),
h_nVsN(),
h_eVsN(),
h_qVsN(),
h_bVsN(),
h_ptSumVsN(),
h_ptAvgVsN(),
h_eVsE(),
h_qVsE(),
h_bVsE(),
h_qVsQ(),
h_bVsQ(),
h_bVsB(),
fill2D(group.fill2D),
fillCorrelationHistos(group.fillCorrelationHistos)
{
  //cloneAll(group);
}

GlobalHistos & GlobalHistos::operator=(const GlobalHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    particleFilters       = group.particleFilters;
    fill2D                = group.fill2D;
    fillCorrelationHistos = group.fillCorrelationHistos;
    //cloneAll(group);
    }
  return *this;
}


void GlobalHistos::cloneAll(const GlobalHistos & group)
{
  cloneHistoVector(group.h_n,h_n);
  cloneHistoVector(group.h_e,h_e);
  cloneHistoVector(group.h_q,h_q);
  cloneHistoVector(group.h_s,h_s);
  cloneHistoVector(group.h_b,h_b);
  cloneHistoVector(group.h_ptSum,h_ptSum);
  cloneHistoVector(group.h_ptAvg,h_ptAvg);
}


// for now use the same boundaries for eta and y histogram
void GlobalHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* */ };
  unsigned int nParticleFilters = particleFilters.size();
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  fillCorrelationHistos = configuration.getValueBool(ptn,"FillCorrelationHistos");
  fill2D                = configuration.getValueBool(ptn,"Fill2D");
  int nBins_n           = configuration.getValueInt(ptn,"nBins_n");
  int nBins_n2          = configuration.getValueInt(ptn,"nBins_n2");
  double min_n          = configuration.getValueDouble(ptn,"Min_n");
  double max_n          = configuration.getValueDouble(ptn,"Max_n");
  int nBins_e           = configuration.getValueInt(ptn,"nBins_e");
  int nBins_e2          = configuration.getValueInt(ptn,"nBins_e2");
  double min_e          = configuration.getValueDouble(ptn,"Min_e");
  double max_e          = configuration.getValueDouble(ptn,"Max_e");
  int nBins_q           = configuration.getValueInt(ptn,"nBins_q");
  int nBins_q2          = configuration.getValueInt(ptn,"nBins_q2");
  double min_q          = configuration.getValueDouble(ptn,"Min_q");
  double max_q          = configuration.getValueDouble(ptn,"Max_q");
  int nBins_b           = configuration.getValueInt(ptn,"nBins_b");
  int nBins_b2          = configuration.getValueInt(ptn,"nBins_b2");
  double min_b          = configuration.getValueDouble(ptn,"Min_b");
  double max_b          = configuration.getValueDouble(ptn,"Max_b");
  int nBins_s           = configuration.getValueInt(ptn,"nBins_s");
  double min_s          = configuration.getValueDouble(ptn,"Min_s");
  double max_s          = configuration.getValueDouble(ptn,"Max_s");
  int nBins_ptSum       = configuration.getValueInt(ptn,"nBins_ptSum");
  int nBins_ptSum2      = configuration.getValueInt(ptn,"nBins_ptSum2");
  double min_ptSum      = configuration.getValueDouble(ptn,"Min_ptSum");
  double max_ptSum      = configuration.getValueDouble(ptn,"Max_ptSum");
  int nBins_ptAvg       = configuration.getValueInt(ptn,"nBins_ptAvg");
  int nBins_ptAvg2      = configuration.getValueInt(ptn,"nBins_ptAvg2");
  double min_ptAvg      = configuration.getValueDouble(ptn,"Min_ptAvg");
  double max_ptAvg      = configuration.getValueDouble(ptn,"Max_ptAvg");

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn );
    printValue("Parent Path Name",ppn );
    printValue("Histo Base Name",bn );
    printValue("nParticleFilters",nParticleFilters );
    printValue("FillCorrelationHistos",fillCorrelationHistos );
    printValue("Fill2D",fill2D );
    printValue("nBins_n",nBins_n );
    printValue("nBins_n2",nBins_n2 );
    printValue("Min_n",min_n );
    printValue("Max_n",max_n );
    printValue("nBins_e",nBins_e );
    printValue("nBins_e2",nBins_e2 );
    printValue("Min_e",min_e );
    printValue("Max_e",max_e );
    printValue("nBins_q",nBins_q );
    printValue("nBins_q2",nBins_q2 );
    printValue("Min_q",min_q );
    printValue("Max_q",max_q );
    printValue("nBins_b",nBins_b );
    printValue("nBins_b2",nBins_b2 );
    printValue("Min_b",min_b );
    printValue("Max_b",max_b );
    printValue("nBins_s",nBins_s );
    printValue("Min_s",min_s );
    printValue("Max_s",max_s );
    printValue("nBins_ptSum",nBins_ptSum );
    printValue("nBins_ptSum2",nBins_ptSum2 );
    printValue("Min_ptSum",min_ptSum );
    printValue("Max_ptSum",max_ptSum );
    printValue("nBins_ptAvg",nBins_ptAvg );
    printValue("nBins_ptAvg2",nBins_ptAvg2 );
    printValue("Min_ptAvg",min_ptAvg );
    printValue("Max_ptAvg",max_ptAvg );
    printCR();
    }
  for (unsigned int k1=0; k1<nParticleFilters; k1++)
  {
  String name;
  String pfName1 = particleFilters[k1]->getName();
  h_n.push_back(     createHistogram(createName(bn,pfName1,"n"), nBins_n, min_n,  max_n, "n","N") );
  h_e.push_back(     createHistogram(createName(bn,pfName1,"e"), nBins_e, min_e,  max_e, "e","N") );
  h_q.push_back(     createHistogram(createName(bn,pfName1,"q"), nBins_q, min_q,  max_q, "q","N") );
  h_s.push_back(     createHistogram(createName(bn,pfName1,"s"), nBins_s, min_s,  max_s, "s","N") );
  h_b.push_back(     createHistogram(createName(bn,pfName1,"b"), nBins_b, min_b,  max_b, "b","N") );
  h_ptSum.push_back( createHistogram(createName(bn,pfName1,"ptSum"), nBins_ptSum, min_ptSum,  max_ptSum, "ptSum","N") );
  h_ptAvg.push_back( createHistogram(createName(bn,pfName1,"ptAvg"), nBins_ptAvg, min_ptAvg,  max_ptAvg, "ptAvg","N") );
  p_eVsN.push_back(  createProfile(createName(bn,pfName1,String("n"),pfName1,String("eProf")),nBins_n, min_n, max_n, "n", "e"));
  p_qVsN.push_back(  createProfile(createName(bn,pfName1,String("n"),pfName1,String("qProf")),nBins_n, min_n, max_n, "n", "q"));
  p_sVsN.push_back(  createProfile(createName(bn,pfName1,String("n"),pfName1,String("sProf")),nBins_n, min_n, max_n, "n", "s"));
  p_bVsN.push_back(  createProfile(createName(bn,pfName1,String("n"),pfName1,String("bProf")),nBins_n, min_n, max_n, "n", "b"));
  p_ptSumVsN.push_back( createProfile(createName(bn,pfName1,String("n"),pfName1,String("ptSumProf")),nBins_n, min_n, max_n, "n", "ptSum"));
  p_ptAvgVsN.push_back( createProfile(createName(bn,pfName1,String("n"),pfName1,String("ptAvgProf")),nBins_n, min_n, max_n, "n", "ptAvg"));
  if ( fill2D )
    {
    h_ptSumVsN.push_back( createHistogram(createName(bn,pfName1,String("n"),pfName1,String("ptSum")), nBins_n2, min_n, max_n, nBins_ptSum2, min_ptSum,  max_ptSum, "n", "ptSum", "N") );
    h_ptAvgVsN.push_back( createHistogram(createName(bn,pfName1,String("n"),pfName1,String("ptAvg")), nBins_n2, min_n, max_n, nBins_ptAvg2, min_ptAvg,  max_ptAvg, "n", "ptAvg", "N") );
    h_eVsN.push_back(     createHistogram(createName(bn,pfName1,String("n"),pfName1,String("e")),     nBins_n2, min_n, max_n, nBins_e2, min_e,  max_e, "n", "e", "N") );
    h_qVsN.push_back(     createHistogram(createName(bn,pfName1,String("n"),pfName1,String("q")),     nBins_n2, min_n, max_n, nBins_q2, min_q,  max_q, "n", "q", "N") );
    h_bVsN.push_back(     createHistogram(createName(bn,pfName1,String("n"),pfName1,String("b")),     nBins_n2, min_n, max_n, nBins_b2, min_b,  max_b, "n", "b", "N") );
    }

  if ( fillCorrelationHistos )
    {
    for (unsigned int k2=k1; k2<nParticleFilters; k2++)
      {
      String pfName2 = particleFilters[k2]->getName();
      if (k1!=k2)
        {
        h_nVsN.push_back( createHistogram(createName(bn,pfName1,"n",pfName2,"n"), nBins_n2, min_n, max_n, nBins_n2, min_n,  max_n, "n", "n", "N") );
        h_eVsE.push_back( createHistogram(createName(bn,pfName1,"e",pfName2,"e"), nBins_e2, min_e, max_e, nBins_e2, min_e,  max_e, "e", "e", "N") );
        h_qVsQ.push_back( createHistogram(createName(bn,pfName1,"q",pfName2,"q"), nBins_q2, min_q, max_q, nBins_q2, min_q,  max_q, "q", "q", "N") );
        h_bVsB.push_back( createHistogram(createName(bn,pfName1,"b",pfName2,"b"), nBins_b2, min_b, max_b, nBins_b2, min_b,  max_b, "b", "b", "N") );
        h_eVsN.push_back( createHistogram(createName(bn,pfName1,"n",pfName2,"e"), nBins_n2, min_n, max_n, nBins_e2, min_e,  max_e, "n", "e", "N") );
        h_qVsN.push_back( createHistogram(createName(bn,pfName1,"n",pfName2,"q"), nBins_n2, min_n, max_n, nBins_q2, min_q,  max_q, "n", "q", "N") );
        h_bVsN.push_back( createHistogram(createName(bn,pfName1,"n",pfName2,"b"), nBins_n2, min_n, max_n, nBins_b2, min_b,  max_b, "n", "b", "N") );
        h_qVsE.push_back( createHistogram(createName(bn,pfName1,"e",pfName2,"q"), nBins_e2, min_e, max_e, nBins_q2, min_q,  max_q, "e", "q", "N") );
        h_bVsE.push_back( createHistogram(createName(bn,pfName1,"e",pfName2,"b"), nBins_e2, min_e, max_e, nBins_b2, min_b,  max_b, "e", "b", "N") );
        h_bVsQ.push_back( createHistogram(createName(bn,pfName1,"q",pfName2,"b"), nBins_q2, min_q, max_q, nBins_b2, min_b,  max_b, "q", "b", "N") );
        }
      }
    }
  }
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void GlobalHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* */ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  fillCorrelationHistos = configuration.getValueBool(ptn,"FillCorrelationHistos");
  fill2D                = configuration.getValueBool(ptn,"Fill2D");
  unsigned int nParticleFilters = particleFilters.size();
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Parent Task Name",ptn );
    printValue("Parent Path Name",ppn );
    printValue("Histo Base Name",bn );
    printValue("nParticleFilters",nParticleFilters );
    printValue("FillCorrelationHistos",fillCorrelationHistos );
    printValue("Fill2D",fill2D );
    printCR();
    }

  for (unsigned int k1=0; k1<nParticleFilters; k1++)
  {
  String pfName1 = particleFilters[k1]->getName();
  h_n.push_back( importH1(inputFile, createName(bn,pfName1,"n")) );
  h_e.push_back( importH1(inputFile, createName(bn,pfName1,"e")) );
  h_q.push_back( importH1(inputFile, createName(bn,pfName1,"q")) );
  h_s.push_back( importH1(inputFile, createName(bn,pfName1,"s")) );
  h_b.push_back( importH1(inputFile, createName(bn,pfName1,"b")) );
  h_ptSum.push_back( importH1(inputFile, createName(bn,pfName1,"ptSum")));
  h_ptAvg.push_back( importH1(inputFile, createName(bn,pfName1,"ptAvg")));

  p_eVsN.push_back(     importProfile(inputFile, createName(bn,pfName1,"n",pfName1,"eProf")));
  p_qVsN.push_back(     importProfile(inputFile, createName(bn,pfName1,"n",pfName1,"qProf")));
  p_sVsN.push_back(     importProfile(inputFile, createName(bn,pfName1,"n",pfName1,"sProf")));
  p_bVsN.push_back(     importProfile(inputFile, createName(bn,pfName1,"n",pfName1,"bProf")));
  p_ptSumVsN.push_back( importProfile(inputFile, createName(bn,pfName1,"n",pfName1,"ptSumProf")));
  p_ptAvgVsN.push_back( importProfile(inputFile, createName(bn,pfName1,"n",pfName1,"ptAvgProf")));

  if ( fill2D )
    {
    h_ptSumVsN.push_back( importH2(inputFile, createName(bn,pfName1,"n",pfName1,"ptSum")));
    h_ptAvgVsN.push_back( importH2(inputFile, createName(bn,pfName1,"n",pfName1,"ptAvg")));
    h_eVsN.push_back(     importH2(inputFile, createName(bn,pfName1,"n",pfName1,"e")));
    h_qVsN.push_back(     importH2(inputFile, createName(bn,pfName1,"n",pfName1,"q")));
    h_bVsN.push_back(     importH2(inputFile, createName(bn,pfName1,"n",pfName1,"b")));
    }

  if ( fillCorrelationHistos )
    {
    for (unsigned int k2=k1; k2<nParticleFilters; k2++)
      {
      String pfName2 = particleFilters[k2]->getName();
      if (k1!=k2)
        {
        h_nVsN.push_back( importH2(inputFile, createName(bn,pfName1,"n",pfName2,"n")) );
        h_eVsE.push_back( importH2(inputFile, createName(bn,pfName1,"e",pfName2,"e")) );
        h_qVsQ.push_back( importH2(inputFile, createName(bn,pfName1,"q",pfName2,"q")) );
        h_bVsB.push_back( importH2(inputFile, createName(bn,pfName1,"b",pfName2,"b")) );
        h_eVsN.push_back( importH2(inputFile, createName(bn,pfName1,"n",pfName2,"e")) );
        h_qVsN.push_back( importH2(inputFile, createName(bn,pfName1,"n",pfName2,"q")) );
        h_bVsN.push_back( importH2(inputFile, createName(bn,pfName1,"n",pfName2,"b")) );
        h_qVsE.push_back( importH2(inputFile, createName(bn,pfName1,"e",pfName2,"q")) );
        h_bVsE.push_back( importH2(inputFile, createName(bn,pfName1,"e",pfName2,"b")) );
        h_bVsQ.push_back( importH2(inputFile, createName(bn,pfName1,"q",pfName2,"b")) );
        }
      }
    }
  }
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void GlobalHistos::fill(vector<double> & n, 
                        vector<double> & ptSum,
                        vector<double> & e,
                        vector<double> & q,
                        vector<double> & s,
                        vector<double> & b,
                        double weight)
{
  unsigned int nParticleFilters = particleFilters.size();
  for (unsigned int k1=0; k1<nParticleFilters; k1++)
  {
  double nPart = n[k1];
  double pts = ptSum[k1];
  double ptAvg = 0.0;
  if (nPart>0) ptAvg = pts/nPart;
  //cout,"nPart:",nPart," pts:",pts," ptAvGlobal:",ptAvg );
  h_n[k1]->Fill(n[k1],weight);
  h_e[k1]->Fill(e[k1],weight);
  h_q[k1]->Fill(q[k1],weight);
  h_s[k1]->Fill(s[k1],weight);
  h_b[k1]->Fill(b[k1],weight);
  h_ptSum[k1]->Fill(pts, weight);
  if (nPart>0)
    {
    h_ptAvg[k1]->Fill(ptAvg, weight);
    p_eVsN[k1]->Fill(nPart,e[k1]);
    p_qVsN[k1]->Fill(nPart,q[k1]);
    p_sVsN[k1]->Fill(nPart,s[k1]);
    p_bVsN[k1]->Fill(nPart,b[k1]);
    p_ptSumVsN[k1]->Fill(nPart,pts);
    p_ptAvgVsN[k1]->Fill(nPart,ptAvg);
    }

  if (fill2D)
    {
    h_ptSumVsN[k1]->Fill(n[k1],pts,weight);
    if (nPart>0) h_ptAvgVsN[k1]->Fill(nPart,ptAvg, weight);
    h_eVsN[k1]->Fill(nPart,e[k1],weight);
    h_qVsN[k1]->Fill(nPart,q[k1],weight);
    h_bVsN[k1]->Fill(nPart,b[k1],weight);
    }

  if ( fillCorrelationHistos )
    {
    //unsigned int n2 = nParticleFilters-k1;
    unsigned int nND   = 0; // non diagonal only
    for (unsigned int k2=k1; k2<nParticleFilters; k2++)
      {
      if (k1!=k2)
        {
        h_nVsN[nND]->Fill(n[k1],n[k2],weight);
        h_eVsE[nND]->Fill(e[k1],e[k2],weight);
        h_qVsQ[nND]->Fill(q[k1],q[k2],weight);
        h_bVsB[nND]->Fill(b[k1],b[k2],weight);
        h_eVsN[nND]->Fill(n[k1],e[k2],weight);
        h_qVsN[nND]->Fill(n[k1],q[k2],weight);
        h_bVsN[nND]->Fill(n[k1],b[k2],weight);
        h_qVsE[nND]->Fill(e[k1],q[k2],weight);
        h_bVsE[nND]->Fill(e[k1],b[k2],weight);
        h_bVsQ[nND]->Fill(q[k1],b[k2],weight);
        nND++;
        }
      }
    }
  }
}

void GlobalHistos::setParticleFilters(const vector<ParticleFilter*> & _particleFilters)
{
  particleFilters = _particleFilters;
}

vector<ParticleFilter*> & GlobalHistos::getParticleFilters()
{
  return particleFilters;
}

const vector<ParticleFilter*> & GlobalHistos::getParticleFilters() const
{
  return particleFilters;
}

} // namespace CAP
