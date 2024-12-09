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
#include "ParticlePair3DHistos.hpp"
#include "MathConstants.hpp"
#include "RootHelpers.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticlePair3DHistos);

namespace CAP
{

ParticlePair3DHistos::ParticlePair3DHistos()
:
HistogramGroup()
{
  appendClassName("ParticlePair3DHistos");
}

ParticlePair3DHistos::ParticlePair3DHistos(const ParticlePair3DHistos & group)
:
HistogramGroup(group),
h_n2_Qinv(nullptr),
h_n2_DeltaP(nullptr)
{  }

ParticlePair3DHistos & ParticlePair3DHistos::operator=(const ParticlePair3DHistos & group)
{
  if (this!=&group)
    {
    h_n2_Qinv   = nullptr;
    h_n2_DeltaP = nullptr;
    }
  return *this;
}


void ParticlePair3DHistos::createHistograms()
{
  const String & bn  = getName();
  const String & ptn = getParentName();

  int    nBins_Qinv     = configuration.getValueInt(ptn,   "nBins_Qinv");
  double min_Qinv       = configuration.getValueDouble(ptn,"Min_Qinv");
  double max_Qinv       = configuration.getValueDouble(ptn,"Max_Qinv");
  int    nBins_DeltaPs  = configuration.getValueInt(ptn,   "nBins_DeltaPs");
  double min_DeltaPs    = configuration.getValueDouble(ptn,"Min_DeltaPs");
  double max_DeltaPs    = configuration.getValueDouble(ptn,"Max_DeltaPs");
  int    nBins_DeltaPo  = configuration.getValueInt(ptn,   "nBins_DeltaPo");
  double min_DeltaPo    = configuration.getValueDouble(ptn,"Min_DeltaPo");
  double max_DeltaPo    = configuration.getValueDouble(ptn,"Max_DeltaPo");
  int    nBins_DeltaPl  = configuration.getValueInt(ptn,   "nBins_DeltaPl");
  double min_DeltaPl    = configuration.getValueDouble(ptn,"Min_DeltaPl");
  double max_DeltaPl    = configuration.getValueDouble(ptn,"Max_DeltaPl");

  h_n2_Qinv   = createHistogram(createName(bn,"n2_Qinv"),nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","n_{2}",2);
  h_n2_DeltaP = createHistogram(createName(bn,"n2_DeltaP"),
                                nBins_DeltaPs,  min_DeltaPs, max_DeltaPs,
                                nBins_DeltaPo,  min_DeltaPo, max_DeltaPo,
                                nBins_DeltaPl,  min_DeltaPl, max_DeltaPl,
                                "p_{s}","p_{o}", "p_{l}");
}

//________________________________________________________________________
void ParticlePair3DHistos::importHistograms(TFile & inputFile)
{
  const String & bn = getName();
  h_n2_Qinv   = loadH1(inputFile, createName(bn,"n2_Qinv"));
  h_n2_DeltaP = loadH3(inputFile, createName(bn,"n2_DeltaP"));
}

void ParticlePair3DHistos::fill(Particle & particle1, Particle & particle2, double weight)
{
  //decompose(double *pa,double *pb,double &qlong,double &qout,double &qside,double &qinv)
  // ====================================================================================
  // Method from Scott Pratt to do three dimensional qinv components
  // ====================================================================================
  double pt,s,Mlong,roots;
  double pa[4], pb[4], ptot[4],q[4];
  const int g[4]={1,-1,-1,-1};
  double qinv, qside, qlong, qout;

  LorentzVector & momentumA = particle1.getMomentum();
  LorentzVector & momentumB = particle2.getMomentum();
  pa[0] = momentumA.E();
  pa[1] = momentumA.Px();
  pa[2] = momentumA.Py();
  pa[3] = momentumA.Pz();

  pb[0] = momentumB.E();
  pb[1] = momentumB.Px();
  pb[2] = momentumB.Py();
  pb[3] = momentumB.Pz();

  qinv=0.0;
  s=0.0;
  for(int alpha=0;alpha<4;alpha++)
    {
    ptot[alpha]=pa[alpha]+pb[alpha];
    s+=g[alpha]*ptot[alpha]*ptot[alpha];
    q[alpha]=pa[alpha]-pb[alpha];
    qinv-=g[alpha]*q[alpha]*q[alpha];
    }
  pt=sqrt(ptot[1]*ptot[1]+ptot[2]*ptot[2]);
  Mlong=sqrt(s+pt*pt);
  roots=sqrt(s);

  qside=(ptot[1]*q[2]-ptot[2]*q[1])/pt;
  qlong=(ptot[0]*q[3]-ptot[3]*q[0])/Mlong;
  qout=(roots/Mlong)*(ptot[1]*q[1]+ptot[2]*q[2])/pt;
  qinv=sqrt(qinv);

  h_n2_Qinv->Fill(qinv,weight);
  h_n2_DeltaP->Fill(qside,qout,qlong,weight);
}


}  //  namespace CAP



