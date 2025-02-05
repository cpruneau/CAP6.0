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
  
  nBins_pt       = configuration.getValueInt(ptn,"nBins_pt");
  min_pt         = configuration.getValueDouble(ptn,"Min_pt");
  max_pt         = configuration.getValueDouble(ptn,"Max_pt");
  
  nBins_y        = configuration.getValueInt(ptn,"nBins_y");
  min_y          = configuration.getValueDouble(ptn,"Min_y");
  max_y          = configuration.getValueDouble(ptn,"Max_y");



  n2_DeltaPs_name = createName(bn,"n2_DeltaPs");
  n2_DeltaPo_name = createName(bn,"n2_DeltaPo");
  n2_DeltaPl_name = createName(bn,"n2_DeltaPl");
  h_n2_DeltaPs= createHistogram(n2_DeltaPs_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{s}","n_{2}",2);
  h_n2_DeltaPo= createHistogram(n2_DeltaPo_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{o}","n_{2}",2);
  h_n2_DeltaPl= createHistogram(n2_DeltaPl_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{l}","n_{2}",2);
  
  
  h_n1n1_Qinv   = createHistogram(createName(bn,"n1n1_Qinv"),nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","n_{1}n_{1}",2);
  h_n1n1_DeltaP = createHistogram(createName(bn,"n1n1_DeltaP"),
                                  nBins_DeltaPs,  min_DeltaPs, max_DeltaPs,
                                  nBins_DeltaPo,  min_DeltaPo, max_DeltaPo,
                                  nBins_DeltaPl,  min_DeltaPl, max_DeltaPl,
                                  "p_{s}","p_{o}", "p_{l}");
  n1n1_DeltaPs_name = createName(bn,"n1n1_DeltaPs");
  n1n1_DeltaPo_name = createName(bn,"n1n1_DeltaPo");
  n1n1_DeltaPl_name = createName(bn,"n1n1_DeltaPl");
  h_n1n1_DeltaPs= createHistogram(n1n1_DeltaPs_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{s}","n_{1}n_{1}",2);
  h_n1n1_DeltaPo= createHistogram(n1n1_DeltaPo_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{o}","n_{1}n_{1}",2);
  h_n1n1_DeltaPl= createHistogram(n1n1_DeltaPl_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{l}","n_{1}n_{1}",2);
  
  h_c2_Qinv   = createHistogram(createName(bn,"c2_Qinv"), nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","c_{2}",2);
  h_c2_DeltaP = createHistogram(createName(bn,"c2_DeltaP"),
                                nBins_DeltaPs,  min_DeltaPs, max_DeltaPs,
                                nBins_DeltaPo,  min_DeltaPo, max_DeltaPo,
                                nBins_DeltaPl,  min_DeltaPl, max_DeltaPl,
                                "p_{s}","p_{o}", "p_{l}");
  c2_DeltaPs_name = createName(bn,"c2_DeltaPs");
  c2_DeltaPo_name = createName(bn,"c2_DeltaPo");
  c2_DeltaPl_name = createName(bn,"c2_DeltaPl");
  h_c2_DeltaPs= createHistogram(c2_DeltaPs_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{s}","c_{2}",2);
  h_c2_DeltaPo= createHistogram(c2_DeltaPo_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{o}","c_{2}",2);
  h_c2_DeltaPl= createHistogram(c2_DeltaPl_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{l}","c_{2}",2);
  
  
  h_r2_Qinv   = createHistogram(createName(bn,"r2_Qinv"), nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","r_{2}",2);
  h_r2_DeltaP = createHistogram(createName(bn,"r2_DeltaP"),
                                nBins_DeltaPs,  min_DeltaPs, max_DeltaPs,
                                nBins_DeltaPo,  min_DeltaPo, max_DeltaPo,
                                nBins_DeltaPl,  min_DeltaPl, max_DeltaPl,
                                "p_{s}","p_{o}", "p_{l}");
  r2_DeltaPs_name = createName(bn,"r2_DeltaPs");
  r2_DeltaPo_name = createName(bn,"r2_DeltaPo");
  r2_DeltaPl_name = createName(bn,"r2_DeltaPl");
  h_r2_DeltaPs= createHistogram(r2_DeltaPs_name,nBins_DeltaPs,min_DeltaPs, max_DeltaPs,"p_{s}","r_{2}",2);
  h_r2_DeltaPo= createHistogram(r2_DeltaPo_name,nBins_DeltaPo,min_DeltaPo, max_DeltaPo,"p_{o}","r_{2}",2);
  h_r2_DeltaPl= createHistogram(r2_DeltaPl_name,nBins_DeltaPl,min_DeltaPl, max_DeltaPl,"p_{l}","r_{2}",2);
  
  h_a12_Qinv      = createHistogram(createName(bn,"A12_Qinv"),    nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","A_{12}",2);
  h_a12_DeltaPs   = createHistogram(createName(bn,"A12_DeltaPs"), nBins_DeltaPs,min_DeltaPs, max_DeltaPs, "p_{s}","A_{12}",2);
  h_a12_DeltaPo   = createHistogram(createName(bn,"A12_DeltaPo"), nBins_DeltaPo,min_DeltaPo, max_DeltaPo, "p_{o}","A_{12}",2);
  h_a12_DeltaPl   = createHistogram(createName(bn,"A12_DeltaPl"), nBins_DeltaPl,min_DeltaPl, max_DeltaPl, "p_{l}","A_{12}",2);
  h_a21_Qinv      = createHistogram(createName(bn,"A21_Qinv"),    nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","A_{21}",2);
  h_a21_DeltaPs   = createHistogram(createName(bn,"A21_DeltaPs"), nBins_DeltaPs,min_DeltaPs, max_DeltaPs, "p_{s}","A_{21}",2);
  h_a21_DeltaPo   = createHistogram(createName(bn,"A21_DeltaPo"), nBins_DeltaPo,min_DeltaPo, max_DeltaPo, "p_{o}","A_{21}",2);
  h_a21_DeltaPl   = createHistogram(createName(bn,"A21_DeltaPl"), nBins_DeltaPl,min_DeltaPl, max_DeltaPl, "p_{l}","A_{21}",2);

  h_n1_1_pt       = createHistogram(createName(bn,"n1_1_pt"), nBins_pt, min_pt, max_pt,"p_{T}",   "#rho_{1}^{1}(p_{T})");
  h_n1_2_pt       = createHistogram(createName(bn,"n1_2_pt"), nBins_pt, min_pt, max_pt,"p_{T}",   "#rho_{1}^{2}(p_{T})");
  h_n1_1_y        = createHistogram(createName(bn,"n1_1_y"),  nBins_y, min_y,   max_y, "y",   "#rho_{1}^{1}(y)");
  h_n1_2_y        = createHistogram(createName(bn,"n1_2_y"),  nBins_y, min_y,   max_y, "y",   "#rho_{1}^{2}(y)");

  h_n1_1_pt_mc  = createHistogram(createName(bn,"n1_1_pt_mc"), nBins_pt,min_pt, max_pt, "p_{T}","N",2);
  h_n1_2_pt_mc  = createHistogram(createName(bn,"n1_2_pt_mc"), nBins_pt,min_pt, max_pt, "p_{T}","N",2);
  h_n1_1_y_mc   = createHistogram(createName(bn,"n1_1_y_mc"),  nBins_y,min_y, max_y, "y","N",2);
  h_n1_2_y_mc   = createHistogram(createName(bn,"n1_2_y_mc"),  nBins_y,min_y, max_y, "y","N",2);
  h_n1_1_ptY_mc = createHistogram(createName(bn,"n1_1_ptY_mc"),     nBins_y,   min_y,   max_y, nBins_pt, min_pt, max_pt, "y","p_{T}","N");
  h_n1_2_ptY_mc = createHistogram(createName(bn,"n1_2_ptY_mc"),     nBins_y,   min_y,   max_y, nBins_pt, min_pt, max_pt, "y","p_{T}","N");

  h_n1r_1_pt_mc  = createHistogram(createName(bn,"n1r_1_pt_mc"), nBins_pt,min_pt, max_pt, "p_{T}","N",2);
  h_n1r_2_pt_mc  = createHistogram(createName(bn,"n1r_2_pt_mc"), nBins_pt,min_pt, max_pt, "p_{T}","N",2);
  h_n1r_1_y_mc   = createHistogram(createName(bn,"n1r_1_y_mc"),  nBins_y,min_y, max_y, "y","N",2);
  h_n1r_2_y_mc   = createHistogram(createName(bn,"n1r_2_y_mc"),  nBins_y,min_y, max_y, "y","N",2);
  h_n1r_1_ptY_mc = createHistogram(createName(bn,"n1r_1_ptY_mc"),nBins_y,   min_y,   max_y, nBins_pt, min_pt, max_pt, "y","p_{T}","N");
  h_n1r_2_ptY_mc = createHistogram(createName(bn,"n1r_2_ptY_mc"),nBins_y,   min_y,   max_y, nBins_pt, min_pt, max_pt, "y","p_{T}","N");
  
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
  
  h_a12_Qinv      = loadH1(inputFile,createName(bn,"A12_Qinv"));
  h_a12_DeltaPs   = loadH1(inputFile,createName(bn,"A12_DeltaPs"));
  h_a12_DeltaPo   = loadH1(inputFile,createName(bn,"A12_DeltaPo"));
  h_a12_DeltaPl   = loadH1(inputFile,createName(bn,"A12_DeltaPl"));
  h_a21_Qinv      = loadH1(inputFile,createName(bn,"A21_Qinv"));
  h_a21_DeltaPs   = loadH1(inputFile,createName(bn,"A21_DeltaPs"));
  h_a21_DeltaPo   = loadH1(inputFile,createName(bn,"A21_DeltaPo"));
  h_a21_DeltaPl   = loadH1(inputFile,createName(bn,"A21_DeltaPl"));

  h_n1_1_pt_mc  = loadH1(inputFile,createName(bn,"n1_1_pt_mc"));
  h_n1_2_pt_mc  = loadH1(inputFile,createName(bn,"n1_2_pt_mc"));
  h_n1_1_y_mc   = loadH1(inputFile,createName(bn,"n1_1_y_mc"));
  h_n1_2_y_mc   = loadH1(inputFile,createName(bn,"n1_2_y_mc"));


  h_n1_1_ptY_mc = loadH2(inputFile,createName(bn,"n1_1_ptY_mc"));
  h_n1_2_ptY_mc = loadH2(inputFile,createName(bn,"n1_2_ptY_mc"));
  h_n1r_1_ptY_mc = loadH2(inputFile,createName(bn,"n1r_1_ptY_mc"));
  h_n1r_2_ptY_mc = loadH2(inputFile,createName(bn,"n1r_2_ptY_mc"));
  
}

// HistogramGroup from ParticlePair3DDerivedHistos must be normalized "per event" before calling this function
void ParticlePair3DDerivedHistos::calculatePairDerivedHistograms(ParticleSingleHistos  & part1BaseHistos,
                                                                 ParticleSingleHistos  & part2BaseHistos,
                                                                 ParticlePair3DHistos  & partPair3DHistos,
                                                                 bool same)
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

  TH1 * part1_n1 = part1BaseHistos.h_n1;
  TH1 * part2_n1 = part2BaseHistos.h_n1;

  TH2 * part1_ptY = part1BaseHistos.h_n1_ptY;
  TH2 * part2_ptY = part2BaseHistos.h_n1_ptY;

  double v1 = part1_n1->GetBinContent(2);
  part1_n1->SetBinContent(1,v1);
  double v2 = part2_n1->GetBinContent(2);
  part2_n1->SetBinContent(1,v2);
  double nParticle1 = part1_n1->GetMean();
  double nParticle2 = part2_n1->GetMean();
//    double nParticle1 = part1_ptY->Integral();
//    double nParticle2 = part2_ptY->Integral();
  printValue("nParticle1",nParticle1);
  printValue("nParticle2",nParticle2);

  int nPart1 = nParticle1;
  int nPart2 = nParticle2;


  //  const String & bn  = getName();
  const String & ptn = getParentName();
  long nMcSimEvents  = configuration.getValueInt(ptn,   "nMcSimEvents");
  double scale = 1.0/double(nMcSimEvents);
  printValue("nMcSimEvents",nMcSimEvents);
  printValue("scale",scale);

// projections
  TH1* hTemp;
  hTemp = part1_ptY->ProjectionX();
  h_n1_1_y->Add(hTemp);
  delete hTemp;

  hTemp = part2_ptY->ProjectionX();
  h_n1_2_y->Add(hTemp);
  delete hTemp;

  hTemp = part1_ptY->ProjectionY();
  h_n1_1_pt->Add(hTemp);
  delete hTemp;

  hTemp = part2_ptY->ProjectionY();
  h_n1_2_pt->Add(hTemp);
  delete hTemp;


  vector<double> evPhi1;
  vector<double> evPt1;
  vector<double> evY1;
  vector<double> evPhi2;
  vector<double> evPt2;
  vector<double> evY2;

  //nMcSimEvents = 10000;
  for (long iEvent=0; iEvent<nMcSimEvents; iEvent++)
    {
    // create event
    evPhi1.clear();
    evPt1.clear();
    evY1.clear();
    evPhi2.clear();
    evPt2.clear();
    evY2.clear();

    for (int iParticle1=0; iParticle1<nPart1; iParticle1++)
      {
      phi1 = CAP::Math::twoPi() * gRandom->Rndm();
      part1_ptY->GetRandom2(y1,pt1);
      h_n1_1_pt_mc->Fill(pt1);
      h_n1_1_y_mc->Fill(y1);
      h_n1_1_ptY_mc->Fill(y1,pt1);
      evPhi1.push_back(phi1);
      evPt1.push_back(pt1);
      evY1.push_back(y1);
      }
    if (!same)
      {
      for (int iParticle2=0; iParticle2<nPart2; iParticle2++)
        {
        phi2 = CAP::Math::twoPi() * gRandom->Rndm();
        part2_ptY->GetRandom2(y2,pt2);
        h_n1_2_pt_mc->Fill(pt2);
        h_n1_2_y_mc->Fill(y2);
        h_n1_2_ptY_mc->Fill(y2,pt2);
        evPhi2.push_back(phi2);
        evPt2.push_back(pt2);
        evY2.push_back(y2);
        }
      }
    else
      {
      evPhi2 = evPhi1;
      evPt2  = evPt1;
      evY2   = evY1;
      }

    // analyze pairs
    if (evPhi1.size() != nPart1) { printString("WTF 1"); exit(1); }
    if (evPhi2.size() != nPart2) { printString("WTF 2"); exit(1); }

    for (unsigned long iParticle1=0; iParticle1<evPhi1.size(); iParticle1++)
      {
      phi1 = evPhi1[iParticle1];
      pt1  = evPt1[iParticle1];
      y1   = evY1[iParticle1];
      mt1  = sqrt(mass1*mass1+pt1*pt1);
      pa[0] = mt1*cosh(y1);
      pa[1] = pt1*cos(phi1);
      pa[2] = pt1*sin(phi1);
      pa[3] = mt1*sinh(y1);

      for (unsigned long iParticle2=0; iParticle2<evPhi2.size(); iParticle2++)
        {
        if (same && iParticle1==iParticle2) continue;
        phi2 = evPhi2[iParticle2];
        pt2  = evPt2[iParticle2];
        y2   = evY2[iParticle2];
        mt2  = sqrt(mass2*mass2+pt2*pt2);
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

  h_n1_1_pt_mc->Scale(scale);
  h_n1_1_y_mc->Scale(scale);
  h_n1_2_pt_mc->Scale(scale);
  h_n1_2_y_mc->Scale(scale);
  h_n1_1_ptY_mc->Scale(scale);
  h_n1_2_ptY_mc->Scale(scale);

  double nParticle1_mc = h_n1_1_pt_mc->Integral();
  double nParticle2_mc = h_n1_2_pt_mc->Integral();
  double tweak1;
  double tweak2;

  tweak1= nParticle1/nParticle1_mc;
  if (same)
    {
    nParticle2_mc = nParticle1_mc;
    tweak2 = tweak1;
    h_n1_2_y_mc->Add(h_n1_1_y_mc);
    h_n1_2_pt_mc->Add(h_n1_1_pt_mc);
    h_n1_2_ptY_mc->Add(h_n1_1_ptY_mc);
    }
  else
    tweak2= nParticle2/nParticle2_mc;

  printValue("nPart1",nPart1);
  printValue("nParticle1",nParticle1);
  printValue("nParticle1_mc",nParticle1_mc);
  printValue("nPart21",nPart2);
  printValue("nParticle2",nParticle2);
  printValue("nParticle2_mc",nParticle2_mc);
  printValue("tweak1",tweak1);
  printValue("tweak2",tweak2);

  h_n1_1_pt_mc->Scale(tweak1);
  h_n1_1_y_mc->Scale(tweak1);
  h_n1_2_pt_mc->Scale(tweak2);
  h_n1_2_y_mc->Scale(tweak2);
  h_n1_1_ptY_mc->Scale(tweak1*tweak2);
  h_n1_2_ptY_mc->Scale(tweak1*tweak2);

  h_n1r_1_pt_mc->Divide(h_n1_1_pt_mc, h_n1_1_pt);
  h_n1r_1_y_mc->Divide(h_n1_1_y_mc,   h_n1_1_y);
  h_n1r_2_pt_mc->Divide(h_n1_2_pt_mc, h_n1_2_pt);
  h_n1r_2_y_mc->Divide(h_n1_2_y_mc,   h_n1_2_y);
  h_n1r_1_ptY_mc->Divide(h_n1_1_ptY_mc, part1_ptY);
  h_n1r_2_ptY_mc->Divide(h_n1_2_ptY_mc, part2_ptY);

  h_n1n1_Qinv->Scale(scale*tweak1*tweak2);
  h_n1n1_DeltaP->Scale(scale*tweak1*tweak2);
  h_n1n1_DeltaP->ProjectionX(n1n1_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
  h_n1n1_DeltaP->ProjectionY(n1n1_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
  h_n1n1_DeltaP->ProjectionZ(n1n1_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
  
  partPair3DHistos.h_n2_DeltaP->ProjectionX(n2_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
  partPair3DHistos.h_n2_DeltaP->ProjectionY(n2_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
  partPair3DHistos.h_n2_DeltaP->ProjectionZ(n2_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
  
  calculateC2_H1H1H1(partPair3DHistos.h_n2_Qinv,h_n1n1_Qinv,h_c2_Qinv);
  calculateC2_H3H3H3(partPair3DHistos.h_n2_DeltaP,h_n1n1_DeltaP,h_c2_DeltaP);
  h_c2_DeltaP->ProjectionX(c2_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
  h_c2_DeltaP->ProjectionY(c2_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
  h_c2_DeltaP->ProjectionZ(c2_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
  
  calculateR2_H1H1H1(partPair3DHistos.h_n2_Qinv,h_n1n1_Qinv,h_r2_Qinv);
  calculateR2_H3H3H3(partPair3DHistos.h_n2_DeltaP,h_n1n1_DeltaP,h_r2_DeltaP);
  h_r2_DeltaP->ProjectionX(r2_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
  h_r2_DeltaP->ProjectionY(r2_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
  h_r2_DeltaP->ProjectionZ(r2_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
  
  double invN1 = 1.0/nParticle1;
  double invN2 = 1.0/nParticle2;
  h_a12_Qinv    ->Add(h_c2_Qinv,invN2);
  h_a12_DeltaPs ->Add(h_c2_DeltaPs,invN2);
  h_a12_DeltaPo ->Add(h_c2_DeltaPo,invN2);
  h_a12_DeltaPl ->Add(h_c2_DeltaPl,invN2);
  h_a21_Qinv    ->Add(h_c2_Qinv,invN1);
  h_a21_DeltaPs ->Add(h_c2_DeltaPs,invN1);
  h_a21_DeltaPo ->Add(h_c2_DeltaPo,invN1);
  h_a21_DeltaPl ->Add(h_c2_DeltaPl,invN1);
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


//void ParticlePair3DDerivedHistos::calculatePairDerivedHistograms(ParticleSingleHistos  & part1BaseHistos,
//                                                                 ParticleSingleHistos  & part2BaseHistos,
//                                                                 ParticlePair3DHistos  & partPair3DHistos,
//                                                                 bool same)
//{
//  // to calculate n1n1, we fold n1 by n1 using an MC technique.
//  double y1, pt1, mt1, phi1;
//  double y2, pt2, mt2, phi2;
//  double pt,s,Mlong,roots;
//  double weight=1.0;
//  double pa[4], pb[4], ptot[4],q[4];
//  //  const double m1 = 0.13957039;
//  //  const double m2 = 0.13957039;
//  const double g[4]={1.0,-1.0,-1.0,-1.0};
//  double qinv, qside, qlong, qout;
//
//  TH2 * part1 = part1BaseHistos.h_n1_ptY;
//  TH2 * part2 = part2BaseHistos.h_n1_ptY;
//
//  double nParticle1 = part1->Integral();
//  double nParticle2 = part2->Integral();
//  int nPart1 = nParticle1;
//  int nPart2 = nParticle2;
//  double scaleTweak1 = nParticle1/double(nPart1);
//  double scaleTweak2 = nParticle2/double(nPart2);
//
//  printValue("nParticle1",nParticle1);
//  printValue("nPart1",nPart1);
//  printValue("nParticle2",nParticle2);
//  printValue("nPart",nPart2);
//  printValue("scaleTweak1", scaleTweak1);
//  printValue("scaleTweak2", scaleTweak2);
//
//  //  const String & bn  = getName();
//  const String & ptn = getParentName();
//  long nMcSimEvents  = configuration.getValueInt(ptn,   "nMcSimEvents");
//  double scale = 1.0/double(nMcSimEvents);
//  printValue("nMcSimEvents",nMcSimEvents);
//  printValue("scale",scale);
//
//  vector<double> evPhi1;
//  vector<double> evPt1;
//  vector<double> evY1;
//  vector<double> evPhi2;
//  vector<double> evPt2;
//  vector<double> evY2;
//
//  for (long iEvent=0; iEvent<nMcSimEvents; iEvent++)
//    {
//    // create event
//    evPhi1.clear();
//    evPt1.clear();
//    evY1.clear();
//    evPhi2.clear();
//    evPt2.clear();
//    evY2.clear();
//
//    // generate event
//
//    for (int iParticle1=0; iParticle1<nPart1; iParticle1++)
//      {
//      phi1 = CAP::Math::twoPi() * gRandom->Rndm();
//      part1->GetRandom2(y1,pt1);
//      h_n1_1_ptY_mc->Fill(y1,pt1);
//      evPhi1.push_back(phi1);
//      evPt1.push_back(pt1);
//      evY1.push_back(y1);
//      }
//
//    if (same)
//      {
//      evPhi2 = evPhi1;
//      evPt2  = evPt1;
//      evY2   = evY1;
//      }
//    else
//      {
//      for (int iParticle2=0; iParticle2<nPart2; iParticle2++)
//        {
//        phi2 = CAP::Math::twoPi() * gRandom->Rndm();
//        part2->GetRandom2(y2,pt2);
//        h_n1_2_ptY_mc->Fill(y2,pt2);
//        evPhi2.push_back(phi2);
//        evPt2.push_back(pt2);
//        evY2.push_back(y2);
//        }
//      }
//
//    // analyze pairs
//
//    for (unsigned long iParticle1=0; iParticle1<evPhi1.size(); iParticle1++)
//      {
//      phi1 = evPhi1[iParticle1];
//      pt1  = evPt1[iParticle1];
//      y1   = evY1[iParticle1];
//      mt1  = sqrt(mass1*mass1+pt1*pt1);
//      pa[0] = mt1*cosh(y1);
//      pa[1] = pt1*cos(phi1);
//      pa[2] = pt1*sin(phi1);
//      pa[3] = mt1*sinh(y1);
//
//      for (unsigned long iParticle2=0; iParticle2<evPhi2.size(); iParticle2++)
//        {
//        if (same && iParticle1==iParticle2) continue;
//        phi2 = evPhi2[iParticle2];
//        pt2  = evPt2[iParticle2];
//        y2   = evY2[iParticle2];
//        mt2  = sqrt(mass2*mass2+pt2*pt2);
//        pb[0] = mt2*cosh(y2);
//        pb[1] = pt2*cos(phi2);
//        pb[2] = pt2*sin(phi2);
//        pb[3] = mt2*sinh(y2);
//        qinv=0.0;
//        s=0.0;
//        for(int alpha=0;alpha<4;alpha++)
//          {
//          ptot[alpha]=pa[alpha]+pb[alpha];
//          s+=g[alpha]*ptot[alpha]*ptot[alpha];
//          q[alpha]=pa[alpha]-pb[alpha];
//          qinv-=g[alpha]*q[alpha]*q[alpha];
//          }
//        pt=sqrt(ptot[1]*ptot[1]+ptot[2]*ptot[2]);
//        Mlong=sqrt(s+pt*pt);
//        roots=sqrt(s);
//
//        qside=(ptot[1]*q[2]-ptot[2]*q[1])/pt;
//        qlong=(ptot[0]*q[3]-ptot[3]*q[0])/Mlong;
//        qout=(roots/Mlong)*(ptot[1]*q[1]+ptot[2]*q[2])/pt;
//        qinv=sqrt(qinv);
//        h_n1n1_Qinv->Fill(qinv,weight);
//        h_n1n1_DeltaP->Fill(qside,qout,qlong,weight);
//        }
//      }
//    }
//
//  // part1BaseHistos.h_n1_ptY
//
//
//  h_n1_1_ptY_mc->Scale(scale*scaleTweak1);
//  h_n1_2_ptY_mc->Scale(scale*scaleTweak2);
//  h_n1r_1_ptY_mc->Divide(h_n1_1_ptY_mc, part1);
//  h_n1r_2_ptY_mc->Divide(h_n1_2_ptY_mc, part2);
//
//  h_n1n1_Qinv->Scale(scale*scaleTweak1*scaleTweak2);
//  h_n1n1_DeltaP->Scale(scale*scaleTweak1*scaleTweak2);
//  h_n1n1_DeltaP->ProjectionX(n1n1_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
//  h_n1n1_DeltaP->ProjectionY(n1n1_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
//  h_n1n1_DeltaP->ProjectionZ(n1n1_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
//
//  partPair3DHistos.h_n2_DeltaP->ProjectionX(n2_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
//  partPair3DHistos.h_n2_DeltaP->ProjectionY(n2_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
//  partPair3DHistos.h_n2_DeltaP->ProjectionZ(n2_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
//
//  calculateC2_H1H1H1(partPair3DHistos.h_n2_Qinv,h_n1n1_Qinv,h_c2_Qinv);
//  calculateC2_H3H3H3(partPair3DHistos.h_n2_DeltaP,h_n1n1_DeltaP,h_c2_DeltaP);
//  h_c2_DeltaP->ProjectionX(c2_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
//  h_c2_DeltaP->ProjectionY(c2_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
//  h_c2_DeltaP->ProjectionZ(c2_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
//
//  calculateR2_H1H1H1(partPair3DHistos.h_n2_Qinv,h_n1n1_Qinv,h_r2_Qinv);
//  calculateR2_H3H3H3(partPair3DHistos.h_n2_DeltaP,h_n1n1_DeltaP,h_r2_DeltaP);
//  h_r2_DeltaP->ProjectionX(r2_DeltaPs_name,1,nBins_DeltaPo,1,nBins_DeltaPl,"e");
//  h_r2_DeltaP->ProjectionY(r2_DeltaPo_name,1,nBins_DeltaPs,1,nBins_DeltaPl,"e");
//  h_r2_DeltaP->ProjectionZ(r2_DeltaPl_name,1,nBins_DeltaPs,1,nBins_DeltaPo,"e");
//
//  double invN1 = 1.0/nParticle1;
//  double invN2 = 1.0/nParticle2;
//  h_a12_Qinv    ->Add(h_c2_Qinv,invN2);
//  h_a12_DeltaPs ->Add(h_c2_DeltaPs,invN2);
//  h_a12_DeltaPo ->Add(h_c2_DeltaPo,invN2);
//  h_a12_DeltaPl ->Add(h_c2_DeltaPl,invN2);
//  h_a21_Qinv    ->Add(h_c2_Qinv,invN1);
//  h_a21_DeltaPs ->Add(h_c2_DeltaPs,invN1);
//  h_a21_DeltaPo ->Add(h_c2_DeltaPo,invN1);
//  h_a21_DeltaPl ->Add(h_c2_DeltaPl,invN1);
//}
