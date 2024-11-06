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

#include "ParticleSingleHistos.hpp"
#include "ParticleSingleDerivedHistos.hpp"
#include "ParticlePairHistos.hpp"
#include "HistogramGroup.hpp"
#include "ParticlePairExceptions.hpp"
#include "ParticlePair3DDerivedHistos.hpp"
#include "RootHelpers.hpp"
#include "PrintHelpers.hpp"
#include "TRandom.h"

ClassImp(CAP::ParticlePair3DDerivedHistos);

namespace CAP
{
ParticlePair3DDerivedHistos::ParticlePair3DDerivedHistos()
:
HistogramGroup(),
h_n1n1_Qinv(nullptr),
h_n1n1_DeltaP(nullptr),
h_r2_Qinv(nullptr),
h_r2_DeltaP(nullptr),
h_r2_DeltaPs(nullptr),
h_r2_DeltaPo(nullptr),
h_r2_DeltaPl(nullptr),
mass1(0.13957039),
mass2(0.13957039)
{
  appendClassName("ParticlePair3DDerivedHistos");
}

ParticlePair3DDerivedHistos::ParticlePair3DDerivedHistos(const ParticlePair3DDerivedHistos & group)
:
HistogramGroup(group),
nBins_Qinv(group.nBins_Qinv),
min_Qinv(group.min_Qinv),
max_Qinv(group.max_Qinv),
nBins_DeltaPs(group.nBins_DeltaPs),
min_DeltaPs(group.min_DeltaPs),
max_DeltaPs(group.max_DeltaPs),
nBins_DeltaPo(group.nBins_DeltaPo),
min_DeltaPo(group.min_DeltaPo),
max_DeltaPo(group.max_DeltaPo),
nBins_DeltaPl(group.nBins_DeltaPl),
min_DeltaPl(group.min_DeltaPl),
max_DeltaPl(group.max_DeltaPl),
nEvents(group.nEvents),
n1n1_DeltaPs_name(group.n1n1_DeltaPs_name),
n1n1_DeltaPo_name(group.n1n1_DeltaPo_name),
n1n1_DeltaPl_name(group.n1n1_DeltaPl_name),
n2_DeltaPs_name(group.n2_DeltaPs_name),
n2_DeltaPo_name(group.n2_DeltaPo_name),
n2_DeltaPl_name(group.n2_DeltaPl_name),
c2_DeltaPs_name(group.c2_DeltaPs_name),
c2_DeltaPo_name(group.c2_DeltaPo_name),
c2_DeltaPl_name(group.c2_DeltaPl_name),
r2_DeltaPs_name(group.r2_DeltaPs_name),
r2_DeltaPo_name(group.r2_DeltaPo_name),
r2_DeltaPl_name(group.r2_DeltaPl_name),
h_n1n1_Qinv(nullptr),
h_n1n1_DeltaP(nullptr),
h_r2_Qinv(nullptr),
h_r2_DeltaP(nullptr),
h_r2_DeltaPs(nullptr),
h_r2_DeltaPo(nullptr),
h_r2_DeltaPl(nullptr),
mass1(group.mass1),
mass2(group.mass2)
{
  // implememtation is incomple...
}

ParticlePair3DDerivedHistos & ParticlePair3DDerivedHistos::operator=(const ParticlePair3DDerivedHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    nBins_Qinv     = group.nBins_Qinv;
    min_Qinv       = group.min_Qinv;
    max_Qinv       = group.max_Qinv;
    nBins_DeltaPs  = group.nBins_DeltaPs;
    min_DeltaPs    = group.min_DeltaPs;
    max_DeltaPs    = group.max_DeltaPs;
    nBins_DeltaPo  = group.nBins_DeltaPo;
    min_DeltaPo    = group.min_DeltaPo;
    max_DeltaPo    = group.max_DeltaPo;
    nBins_DeltaPl  = group.nBins_DeltaPl;
    min_DeltaPl    = group.min_DeltaPl;
    max_DeltaPl    = group.max_DeltaPl;
    nEvents        = group.nEvents;
    n1n1_DeltaPs_name  = group.n1n1_DeltaPs_name;
    n1n1_DeltaPo_name  = group.n1n1_DeltaPo_name;
    n1n1_DeltaPl_name  = group.n1n1_DeltaPl_name;
    n2_DeltaPs_name    = group.n2_DeltaPs_name;
    n2_DeltaPo_name    = group.n2_DeltaPo_name;
    n2_DeltaPl_name    = group.n2_DeltaPl_name;
    c2_DeltaPs_name    = group.c2_DeltaPs_name;
    c2_DeltaPo_name    = group.c2_DeltaPo_name;
    c2_DeltaPl_name    = group.c2_DeltaPl_name;
    r2_DeltaPs_name    = group.r2_DeltaPs_name;
    r2_DeltaPo_name    = group.r2_DeltaPo_name;
    r2_DeltaPl_name    = group.r2_DeltaPl_name;

    h_n1n1_Qinv   =  (TH1*) h_n1n1_Qinv->Clone();
    h_n1n1_DeltaP =  (TH3*) h_n1n1_DeltaP->Clone();
    h_r2_Qinv     =  (TH1*) h_r2_Qinv->Clone();
    h_r2_DeltaP   =  (TH3*) h_r2_DeltaP->Clone();
    h_r2_DeltaPs  =  (TH1*) h_r2_DeltaPs->Clone();
    h_r2_DeltaPo  =  (TH1*) h_r2_DeltaPo->Clone();
    h_r2_DeltaPl  =  (TH1*) h_r2_DeltaPl->Clone();
    mass1         =  group.mass1;
    mass2         =  group.mass2;
    }
  return *this;
}


void ParticlePair3DDerivedHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();

  nBins_Qinv     = configuration.getValueInt(ptn,   "nBins_Qinv");
  min_Qinv       = configuration.getValueDouble(ptn,"Min_Qinv");
  max_Qinv       = configuration.getValueDouble(ptn,"Max_Qinv");
  nBins_DeltaPs  = configuration.getValueInt(ptn,   "nBins_DeltaPs");
  min_DeltaPs    = configuration.getValueDouble(ptn,"Min_DeltaPs");
  max_DeltaPs    = configuration.getValueDouble(ptn,"Max_DeltaPs");
  nBins_DeltaPo  = configuration.getValueInt(ptn,   "nBins_DeltaPo");
  min_DeltaPo    = configuration.getValueDouble(ptn,"Min_DeltaPo");
  max_DeltaPo    = configuration.getValueDouble(ptn,"Max_DeltaPo");
  nBins_DeltaPl  = configuration.getValueInt(ptn,   "nBins_DeltaPl");
  min_DeltaPl    = configuration.getValueDouble(ptn,"Min_DeltaPl");
  max_DeltaPl    = configuration.getValueDouble(ptn,"Max_DeltaPl");

  n2_DeltaPs_name = createName(bn,"n2_DeltaPs");
  n2_DeltaPo_name = createName(bn,"n2_DeltaPo");
  n2_DeltaPl_name = createName(bn,"n2_DeltaPl");
  h_n2_DeltaPs= createHistogram(n2_DeltaPs_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{s}","n_{2}");
  h_n2_DeltaPo= createHistogram(n2_DeltaPo_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{o}","n_{2}");
  h_n2_DeltaPl= createHistogram(n2_DeltaPl_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{l}","n_{2}");


  h_n1n1_Qinv   = createHistogram(createName(bn,"n1n1_Qinv"),nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","n_{1}n_{1}");
  h_n1n1_DeltaP = createHistogram(createName(bn,"n1n1_DeltaP"),
                                   nBins_DeltaPs,  min_DeltaPs, max_DeltaPs,
                                   nBins_DeltaPo,  min_DeltaPo, max_DeltaPo,
                                   nBins_DeltaPl,  min_DeltaPl, max_DeltaPl,
                                   "p_{s}","p_{o}", "p_{l}");
  n1n1_DeltaPs_name = createName(bn,"n1n1_DeltaPs");
  n1n1_DeltaPo_name = createName(bn,"n1n1_DeltaPo");
  n1n1_DeltaPl_name = createName(bn,"n1n1_DeltaPl");
  h_n1n1_DeltaPs= createHistogram(n1n1_DeltaPs_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{s}","n_{1}n_{1}");
  h_n1n1_DeltaPo= createHistogram(n1n1_DeltaPo_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{o}","n_{1}n_{1}");
  h_n1n1_DeltaPl= createHistogram(n1n1_DeltaPl_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{l}","n_{1}n_{1}");

  h_c2_Qinv   = createHistogram(createName(bn,"c2_Qinv"), nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","c_{2}");
  h_c2_DeltaP = createHistogram(createName(bn,"c2_DeltaP"),
                                nBins_DeltaPs,  min_DeltaPs, max_DeltaPs,
                                nBins_DeltaPo,  min_DeltaPo, max_DeltaPo,
                                nBins_DeltaPl,  min_DeltaPl, max_DeltaPl,
                                "p_{s}","p_{o}", "p_{l}");
  c2_DeltaPs_name = createName(bn,"c2_DeltaPs");
  c2_DeltaPo_name = createName(bn,"c2_DeltaPo");
  c2_DeltaPl_name = createName(bn,"c2_DeltaPl");
  h_c2_DeltaPs= createHistogram(c2_DeltaPs_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{s}","c_{2}");
  h_c2_DeltaPo= createHistogram(c2_DeltaPo_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{o}","c_{2}");
  h_c2_DeltaPl= createHistogram(c2_DeltaPl_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{l}","c_{2}");

  
  h_r2_Qinv   = createHistogram(createName(bn,"r2_Qinv"), nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","r_{2}");
  h_r2_DeltaP = createHistogram(createName(bn,"r2_DeltaP"),
                                nBins_DeltaPs,  min_DeltaPs, max_DeltaPs,
                                nBins_DeltaPo,  min_DeltaPo, max_DeltaPo,
                                nBins_DeltaPl,  min_DeltaPl, max_DeltaPl,
                                "p_{s}","p_{o}", "p_{l}");
  r2_DeltaPs_name = createName(bn,"r2_DeltaPs");
  r2_DeltaPo_name = createName(bn,"r2_DeltaPo");
  r2_DeltaPl_name = createName(bn,"r2_DeltaPl");
  h_r2_DeltaPs= createHistogram(r2_DeltaPs_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{s}","r_{2}");
  h_r2_DeltaPo= createHistogram(r2_DeltaPo_name,nBins_DeltaPo,min_DeltaPo, max_DeltaPo,"p_{o}","r_{2}");
  h_r2_DeltaPl= createHistogram(r2_DeltaPl_name,nBins_DeltaPl,min_DeltaPl, max_DeltaPl,"p_{l}","r_{2}");

//  h_B12_Qinv      = createHistogram(createName(bn,"B12_Qinv"),    nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","B_{12}");
//  h_B12_DeltaPs   = createHistogram(createName(bn,"B12_DeltaPs"), nBins_DeltaPs,min_DeltaPs, max_DeltaPs, "p_{s}","B_{12}");
//  h_B12_DeltaPo   = createHistogram(createName(bn,"B12_DeltaPo"), nBins_DeltaPo,min_DeltaPo, max_DeltaPo, "p_{o}","B_{12}");
//  h_B12_DeltaPl   = createHistogram(createName(bn,"B12_DeltaPl"), nBins_DeltaPl,min_DeltaPl, max_DeltaPl, "p_{l}","B_{12}");
//  h_B21_Qinv      = createHistogram(createName(bn,"B21_Qinv"),    nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","B_{21}");
//  h_B21_DeltaPs   = createHistogram(createName(bn,"B21_DeltaPs"), nBins_DeltaPs,min_DeltaPs, max_DeltaPs, "p_{s}","B_{21}");
//  h_B21_DeltaPo   = createHistogram(createName(bn,"B21_DeltaPo"), nBins_DeltaPo,min_DeltaPo, max_DeltaPo, "p_{o}","B_{21}");
//  h_B21_DeltaPl   = createHistogram(createName(bn,"B21_DeltaPl"), nBins_DeltaPl,min_DeltaPl, max_DeltaPl, "p_{l}","B_{21}");

}

void ParticlePair3DDerivedHistos::importHistograms(TFile & inputFile)
{
  const String & bn  = getName();
  const String & ptn = getParentName();

  n2_DeltaPs_name = createName(bn,"n2_DeltaPs");
  n2_DeltaPo_name = createName(bn,"n2_DeltaPo");
  n2_DeltaPl_name = createName(bn,"n2_DeltaPl");
  h_n2_DeltaPs = loadH1(inputFile,createName(bn,"n2_DeltaPs"));
  h_n2_DeltaPo = loadH1(inputFile,createName(bn,"n2_DeltaPo"));
  h_n2_DeltaPl = loadH1(inputFile,createName(bn,"n2_DeltaPl"));

  h_n1n1_Qinv   = loadH1(inputFile,createName(bn,"n1n1_Qinv"));
  h_n1n1_DeltaP = loadH3(inputFile,createName(bn,"n1n1_DeltaP"));
  h_n1n1_DeltaPs= loadH1(inputFile,createName(bn,"n1n1_DeltaPs"));
  h_n1n1_DeltaPo= loadH1(inputFile,createName(bn,"n1n1_DeltaPo"));
  h_n1n1_DeltaPl= loadH1(inputFile,createName(bn,"n1n1_DeltaPl"));

  h_c2_Qinv   = loadH1(inputFile,createName(bn,"c2_Qinv"));
  h_c2_DeltaP = loadH3(inputFile,createName(bn,"c2_DeltaP"));
  h_c2_DeltaPs= loadH1(inputFile,createName(bn,"c2_DeltaPs"));
  h_c2_DeltaPo= loadH1(inputFile,createName(bn,"c2_DeltaPo"));
  h_c2_DeltaPl= loadH1(inputFile,createName(bn,"c2_DeltaPl"));

  h_r2_Qinv   = loadH1(inputFile,createName(bn,"r2_Qinv"));
  h_r2_DeltaP = loadH3(inputFile,createName(bn,"r2_DeltaP"));
  h_r2_DeltaPs= loadH1(inputFile,createName(bn,"r2_DeltaPs"));
  h_r2_DeltaPo= loadH1(inputFile,createName(bn,"r2_DeltaPo"));
  h_r2_DeltaPl= loadH1(inputFile,createName(bn,"r2_DeltaPl"));
}

// HistogramGroup from ParticlePair3DDerivedHistos must be normalized "per event" before calling this function
void ParticlePair3DDerivedHistos::calculatePairDerivedHistograms(ParticleSingleHistos  & part1BaseHistos,
                                                                 ParticleSingleHistos  & part2BaseHistos,
                                                                 ParticlePair3DHistos  & partPair3DHistos)
{
  // to calculate n1n1, we fold n1 by n1 using an MC technique.
  double y1, pt1, mt1, phi1;
  double y2, pt2, mt2, phi2;
  double pt,s,Mlong,roots;
  double weight=1.0;
  double pa[4], pb[4], ptot[4],q[4];
//  const double m1 = 0.13957039;
//  const double m2 = 0.13957039;
  const double g[4]={1.0,-1.0,-1.0,-1.0};
  double qinv, qside, qlong, qout;
  int nParticle1 = part1BaseHistos.h_n1_ptY->Integral();
  int nParticle2 = part2BaseHistos.h_n1_ptY->Integral();
  nEvents = 1000000;
  double scale = 1.0/double(nEvents);
  for (long iEvent=0; iEvent<nEvents; iEvent++)
    {
    for (long iParticle1=0; iParticle1<nParticle1; iParticle1++)
      {
      phi1 = CAP::Math::twoPi() * gRandom->Rndm();
      mt1 = sqrt(mass1*mass1+pt1*pt1);
      part1BaseHistos.h_n1_ptY->GetRandom2(y1,pt1);
      //cout << "y1:" << y1 << "  pt1:" << pt1 << endl;
      for (long iParticle2=0; iParticle2<nParticle2; iParticle2++)
        {
        phi2 = CAP::Math::twoPi() * gRandom->Rndm();
        //cout << "y2:" << y1 << "  pt2:" << pt2 << endl;
        part2BaseHistos.h_n1_ptY->GetRandom2(y2,pt2);
        mt2 = sqrt(mass2*mass2+pt2*pt2);
        pa[0] = mt1*cosh(y1);
        pa[1] = pt1*cos(phi1);
        pa[2] = pt1*sin(phi1);
        pa[3] = mt1*sinh(y1);
        pb[0] = mt2*cosh(y2);
        pb[1] = pt2*cos(phi2);
        pb[2] = pt2*sin(phi2);
        pb[3] = mt2*sinh(y2);
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
        h_n1n1_Qinv->Fill(qinv,weight);
        h_n1n1_DeltaP->Fill(qside,qout,qlong,weight);
        }
      }
    }
  h_n1n1_Qinv->Scale(scale);
  h_n1n1_DeltaP->Scale(scale);
  h_n1n1_DeltaP->ProjectionX(n1n1_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
  h_n1n1_DeltaPs->Scale(1.0/double(nBins_DeltaPo*nBins_DeltaPl));
  h_n1n1_DeltaP->ProjectionY(n1n1_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
  h_n1n1_DeltaPo->Scale(1.0/double(nBins_DeltaPs*nBins_DeltaPl));
  h_n1n1_DeltaP->ProjectionZ(n1n1_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
  h_n1n1_DeltaPl->Scale(1.0/double(nBins_DeltaPs*nBins_DeltaPo));

  partPair3DHistos.h_n2_DeltaP->ProjectionX(n2_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
  //h_n2_DeltaPs->Scale(1.0/double(nBins_DeltaPo*nBins_DeltaPl));
  partPair3DHistos.h_n2_DeltaP->ProjectionY(n2_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
  //h_n2_DeltaPo->Scale(1.0/double(nBins_DeltaPs*nBins_DeltaPl));
  partPair3DHistos.h_n2_DeltaP->ProjectionZ(n2_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
  //h_n2_DeltaPl->Scale(1.0/double(nBins_DeltaPs*nBins_DeltaPo));

  calculateC2_H1H1H1(partPair3DHistos.h_n2_Qinv,h_n1n1_Qinv,h_c2_Qinv);
  calculateC2_H3H3H3(partPair3DHistos.h_n2_DeltaP,h_n1n1_DeltaP,h_c2_DeltaP);
  h_c2_DeltaP->ProjectionX(c2_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
  //h_c2_DeltaPs->Scale(1.0/double(nBins_DeltaPo*nBins_DeltaPl));
  h_c2_DeltaP->ProjectionY(c2_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
  //h_c2_DeltaPo->Scale(1.0/double(nBins_DeltaPs*nBins_DeltaPl));
  h_c2_DeltaP->ProjectionZ(c2_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
  //h_c2_DeltaPl->Scale(1.0/double(nBins_DeltaPs*nBins_DeltaPo));

  calculateR2_H1H1H1(partPair3DHistos.h_n2_Qinv,h_n1n1_Qinv,h_r2_Qinv);
  calculateR2_H3H3H3(partPair3DHistos.h_n2_DeltaP,h_n1n1_DeltaP,h_r2_DeltaP);
  h_r2_DeltaP->ProjectionX(r2_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
  //h_r2_DeltaPs->Scale(1.0/double(nBins_DeltaPo*nBins_DeltaPl));
  h_r2_DeltaP->ProjectionY(r2_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
  //h_r2_DeltaPo->Scale(1.0/double(nBins_DeltaPs*nBins_DeltaPl));
  h_r2_DeltaP->ProjectionZ(r2_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
  //h_r2_DeltaPl->Scale(1.0/double(nBins_DeltaPs*nBins_DeltaPo));
}

//! set the masses to be used in the calculation of q_inv
//! The default value set at construction are the pion+ mass.
//!
void ParticlePair3DDerivedHistos::setMasses(double m1, double m2)
{
  mass1 = m1;
  mass2 = m2;
}


} //  namespace CAP
