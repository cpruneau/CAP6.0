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
#include "ParticlePerformanceHistos.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::ParticlePerformanceHistos);

namespace CAP
{

ParticlePerformanceHistos::ParticlePerformanceHistos()
:
HistogramGroup(),
h_n1_dpt(nullptr),
h_n1_deta(nullptr),
h_n1_dphi(nullptr),
h_n1_dy(nullptr),
p_n1_dptVsPt(nullptr),
p_n1_dptVsEta(nullptr),
p_n1_detaVsPt(nullptr),
p_n1_detaVsEta(nullptr),
p_n1_dyVsPt(nullptr),
p_n1_dyVsEta(nullptr),
p_n1_dphiVsPt(nullptr),
p_n1_dphiVsEta(nullptr)
{
  appendClassName("ParticlePerformanceHistos");
}


// for now use the same boundaries for eta and y histogram
void ParticlePerformanceHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  const String & bn  = getName();
  const String & ptn = getParentName();

  int nBins_pt    = configuration.getValueInt(ptn,"nBins_pt");
  double min_pt   = configuration.getValueDouble(ptn,"Min_pt");
  double max_pt   = configuration.getValueDouble(ptn,"Max_pt");

  int nBins_dpt   = configuration.getValueInt(ptn,"nBins_dpt");
  double min_dpt  = configuration.getValueDouble(ptn,"Min_dpt");
  double max_dpt  = configuration.getValueDouble(ptn,"Max_dpt");

  int nBins_dphi  = configuration.getValueInt(ptn,"nBins_dphi");
  double min_dphi = configuration.getValueDouble(ptn,"Min_dphi");
  double max_dphi = configuration.getValueDouble(ptn,"Max_dphi");

  int nBins_eta   = configuration.getValueInt(ptn,"nBins_eta");
  double min_eta  = configuration.getValueDouble(ptn,"Min_eta");
  double max_eta  = configuration.getValueDouble(ptn,"Max_eta");

  int nBins_deta  = configuration.getValueInt(ptn,"nBins_deta");
  double min_deta = configuration.getValueDouble(ptn,"Min_deta");
  double max_deta = configuration.getValueDouble(ptn,"Max_deta");

  int nBins_dy    = configuration.getValueInt(ptn,"nBins_dy");
  double min_dy   = configuration.getValueDouble(ptn,"Min_dy");
  double max_dy   = configuration.getValueDouble(ptn,"Max_dy");

  h_n1_dpt        = createHistogram(createName(bn,"n1_dpt"),  nBins_dpt,  min_dpt,  max_dpt,   "#Delta p_{T}", "N");
  h_n1_deta       = createHistogram(createName(bn,"n1_deta"), nBins_deta, min_deta, max_deta,  "#Delta#eta",   "N");
  h_n1_dphi       = createHistogram(createName(bn,"n1_dphi"), nBins_dphi, min_dphi, max_dphi,  "#Delta#varphi","N");
  h_n1_dy         = createHistogram(createName(bn,"n1_dy"),   nBins_dy,   min_dy,   max_dy,    "#Delta y",     "N");
  p_n1_dptVsPt    = createProfile(createName(bn,"dptVsPt"),   nBins_pt,   min_pt,   max_pt,    "p_{T}","#Delta p_{T}");
  p_n1_detaVsPt   = createProfile(createName(bn,"detaVsPt"),  nBins_pt,   min_pt,   max_pt,    "p_{T}","#Delta#eta");
  p_n1_dyVsPt     = createProfile(createName(bn,"dyVsPt"),    nBins_pt,   min_pt,   max_pt,    "p_{T}","#Delta y");
  p_n1_dphiVsPt   = createProfile(createName(bn,"dphiVsPt"),  nBins_pt,   min_pt,   max_pt,    "p_{T}","#Delta#varphi");
  p_n1_dptVsEta   = createProfile(createName(bn,"dptVsEta"),  nBins_eta,  min_eta,  max_eta,   "#eta","#Delta p_{T}");
  p_n1_detaVsEta  = createProfile(createName(bn,"detaVsEta"), nBins_eta,  min_eta,  max_eta,   "#eta","#Delta#eta");
  p_n1_dyVsEta    = createProfile(createName(bn,"dyVsEta"),   nBins_eta,  min_eta,  max_eta,   "#eta","#Delta y");
  p_n1_dphiVsEta  = createProfile(createName(bn,"dphiVsEta"), nBins_eta,  min_eta,  max_eta,   "#eta","#Delta#varphi");

  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

void ParticlePerformanceHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  const String & bn  = getName();
  const String & ptn = getParentName();

  h_n1_dpt        = importH1(inputFile, createName(bn,"n1_dpPt"));
  h_n1_deta       = importH1(inputFile, createName(bn,"n1_deta"));
  h_n1_dphi       = importH1(inputFile, createName(bn,"n1_dphi"));
  h_n1_dy         = importH1(inputFile, createName(bn,"n1_dy"));

  p_n1_dptVsPt    = importProfile(inputFile, createName(bn,"dptVsPt"));
  p_n1_detaVsPt   = importProfile(inputFile, createName(bn,"detaVsPt"));
  p_n1_dyVsPt     = importProfile(inputFile, createName(bn,"dyVsPt"));
  p_n1_dphiVsPt   = importProfile(inputFile, createName(bn,"dphiVsPt"));
  p_n1_dptVsEta   = importProfile(inputFile, createName(bn,"dptVsEta"));
  p_n1_detaVsEta  = importProfile(inputFile, createName(bn,"detaVsEta"));
  p_n1_dyVsEta    = importProfile(inputFile, createName(bn,"dyVsEta"));
  p_n1_dphiVsEta  = importProfile(inputFile, createName(bn,"dphiVsEta"));
}

//!
//! Fiil  histograms of this class with differences between reco and gen particles..
//!
void ParticlePerformanceHistos::fill(Particle & recoParticle, double weight)
{
  Particle & genParticle  = *recoParticle.getTruth();
  LorentzVector & recoMomentum = recoParticle.getMomentum();
  LorentzVector & genMomentum  = genParticle.getMomentum();
  double recoPt   = recoMomentum.Pt();
  double recoEta  = recoMomentum.Eta();
  double recoY    = recoMomentum.Y();
  double recoPhi  = recoMomentum.Phi();
  double genPt    = genMomentum.Pt();
  double genPhi   = genMomentum.Phi();
  double genEta   = genMomentum.Eta();
  double genY     = genMomentum.Y();
  double dpt      = recoPt  - genPt;
  double dphi     = recoPhi - genPhi;
  double deta     = recoEta - genEta;
  double dy       = recoY   - genY;
//  printValue("ParticlePerformanceHistos::fill() genPt",genPt);
//  printValue("ParticlePerformanceHistos::fill() dpt",dpt);
//  printValue("ParticlePerformanceHistos::fill() deta",deta);
//  printValue("ParticlePerformanceHistos::fill() dphi",dphi);
//  printValue("ParticlePerformanceHistos::fill() dy",dy);
//  printValue("ParticlePerformanceHistos::fill() weight",weight);
  h_n1_dpt  ->Fill(dpt,weight);
  h_n1_deta ->Fill(deta,weight);
  h_n1_dphi ->Fill(dphi,weight);
  h_n1_dy   ->Fill(dy,weight);

  p_n1_dptVsPt  ->Fill(genPt, dpt,  weight);
  p_n1_detaVsPt ->Fill(genPt, deta, weight);
  p_n1_dyVsPt   ->Fill(genPt, dy,   weight);
  p_n1_dphiVsPt ->Fill(genPt, dphi, weight);
  p_n1_dptVsEta ->Fill(genEta,dpt,  weight);
  p_n1_detaVsEta->Fill(genEta,deta, weight);
  p_n1_dyVsEta  ->Fill(genEta,dy,   weight);
  p_n1_dphiVsEta->Fill(genEta,dphi, weight);
}

} // namespace CAP
