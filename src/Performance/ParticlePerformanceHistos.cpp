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
#include "ParticlePerformanceHistos.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::ParticlePerformanceHistos);

namespace CAP
{

ParticlePerformanceHistos::ParticlePerformanceHistos()
:
HistogramGroup(),
fillEta(0),
fillY(0),
nBins_pt(0),
min_pt(0),
max_pt(0),
nBins_phi(0),
min_phi(0),
max_phi(0),
nBins_eta(0),
min_eta(0),
max_eta(0),
nBins_y(0),
min_y(0),
max_y(0),
h_n1_dPt(nullptr),
h_n1_dEta(nullptr),
h_n1_dY(nullptr),
h_n1_dPhi(nullptr),
h_n1_dPtVsPt(nullptr),
h_n1_dEtaVsEta(nullptr),
h_n1_dYVsY(nullptr),
h_n1_dPhiVsPt(nullptr)
{
  appendClassName("ParticlePerformanceHistos");
}


// for now use the same boundaries for eta and y histogram
void ParticlePerformanceHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  fillEta    = configuration.getValueBool(ppn,"FillEta");
  fillY      = configuration.getValueBool(ppn,"FillY");
  
  nBins_pt   = configuration.getValueInt(ppn,"nBins_pt");
  min_pt     = configuration.getValueDouble(ppn,"Min_pt");
  max_pt     = configuration.getValueDouble(ppn,"Max_pt");
  
  nBins_dpt  = configuration.getValueInt(ppn,"nBins_dpt");
  min_dpt    = configuration.getValueDouble(ppn,"Min_dpt");
  max_dpt    = configuration.getValueDouble(ppn,"Max_dpt");
  
  nBins_phi = configuration.getValueInt(ppn,"nBins_phi");
  min_phi   = configuration.getValueDouble(ppn,"Min_phi");
  max_phi   = configuration.getValueDouble(ppn,"Max_phi");
  
  nBins_dphi = configuration.getValueInt(ppn,"nBins_dphi");
  min_dphi   = configuration.getValueDouble(ppn,"Min_dphi");
  max_dphi   = configuration.getValueDouble(ppn,"Max_dphi");
  
  nBins_eta = configuration.getValueInt(ppn,"nBins_eta");
  min_eta   = configuration.getValueDouble(ppn,"Min_eta");
  max_eta   = configuration.getValueDouble(ppn,"Max_eta");
  
  nBins_deta = configuration.getValueInt(ppn,"nBins_deta");
  min_deta   = configuration.getValueDouble(ppn,"Min_deta");
  max_deta   = configuration.getValueDouble(ppn,"Max_deta");
  
  nBins_y = configuration.getValueInt(ppn,"nBins_y");
  min_y   = configuration.getValueDouble(ppn,"Min_y");
  max_y   = configuration.getValueDouble(ppn,"Max_y");
  
  nBins_dy = configuration.getValueInt(ppn,"nBins_dy");
  min_dy   = configuration.getValueDouble(ppn,"Min_dy");
  max_dy   = configuration.getValueDouble(ppn,"Max_dy");
  
  h_n1_dPt        = createHistogram(createName(bn,"n1_dPt"),  nBins_dpt,  min_dpt,  max_dpt,  "#Delta p_{T}","N");
  h_n1_dPhi       = createHistogram(createName(bn,"n1_dPhi"), nBins_dphi, min_dphi, max_dphi, "#Delta #varphi","N");
  h_n1_dPtVsPt    = createHistogram(createName(bn,"n1_dPtVsPt"), nBins_pt,min_pt,   max_pt,   nBins_dpt,  min_dpt,  max_dpt, "p_{T}", "#Delta p_{T}","N");
  h_n1_dPhiVsPt   = createHistogram(createName(bn,"n1_dPhiVsPt"),nBins_pt,min_pt,   max_pt,   nBins_dphi, min_dphi, max_dphi,"p_{T}", "#Delta #phi","N");
  
  if (fillEta)
    {
    h_n1_dEta       = createHistogram(createName(bn,"n1_dEta"),      nBins_deta,  min_deta,  max_deta,  "#Delta#eta","N");
    h_n1_dEtaVsEta  = createHistogram(createName(bn,"n1_dEtaVsEta"), nBins_eta,   min_eta,   max_eta,   nBins_deta,  min_deta,  max_deta, "#eta", "#Delta#eta","N");
    }
  
  if (fillY)
    {
    h_n1_dY       = createHistogram(createName(bn,"n1_dY"),      nBins_dy,   min_dy,  max_dy,  "#Delta y","N");
    h_n1_dYVsY    = createHistogram(createName(bn,"n1_dYVsY"),   nBins_y,    min_y,   max_y,   nBins_dy,  min_dy,  max_dy, "y", "#Delta y","N");
    }
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

void ParticlePerformanceHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  fillEta    = configuration.getValueBool(ppn,"FillEta");
  fillY      = configuration.getValueBool(ppn,"FillY");
  
  h_n1_dPt        = importH1(inputFile, createName(bn,"n1_dpt"));
  h_n1_dPhi       = importH1(inputFile, createName(bn,"n1_dPhi"));
  h_n1_dPtVsPt    = importH2(inputFile, createName(bn,"n1_dpt"));
  h_n1_dPhiVsPt   = importH2(inputFile, createName(bn,"n1_dpt"));
  
  if (fillEta)
    {
    h_n1_dEta       = importH1(inputFile, createName(bn,"n1_deta"));
    h_n1_dEtaVsEta  = importH2(inputFile, createName(bn,"n1_dEtaVsEta"));
    }
  
  if (fillY)
    {
    h_n1_dY       = importH1(inputFile, createName(bn,"n1_dY"));
    h_n1_dYVsY    = importH2(inputFile, createName(bn,"n1_dYVsY"));
    }
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

//!
//! Fiil  histograms of this class with differences between reco and gen particles..
//!
void ParticlePerformanceHistos::fill(Particle & recoParticle, double weight)
{
  Particle & genParticle  = *recoParticle.getTruth();
  LorentzVector & recoMomentum = recoParticle.getMomentum();
  LorentzVector & genMomentum  = genParticle.getMomentum();
  double recoPt, recoEta, recoY, recoPhi;
  double genPt, genEta, genY, genPhi;
  double dPt, dPhi, dEta, dY;
  recoPt   = recoMomentum.Pt();
  recoEta  = recoMomentum.Eta();
  if (fillY) recoY = recoMomentum.Y();
  recoPhi  = recoMomentum.Phi();
  genPt   = genMomentum.Pt();
  genPhi  = genMomentum.Phi();
  if (fillEta) genEta  = genMomentum.Eta();
  if (fillY)   genY    = genMomentum.Y();
  dPt  = recoPt  - genPt;
  dPhi = recoPhi - genPhi;
  if (fillEta) dEta = recoEta - genEta;
  if (fillY)   dY   = recoY   - genY;
  h_n1_dPt->Fill(dPt,weight);
  h_n1_dPhi->Fill(dPhi,weight);
  h_n1_dPtVsPt->Fill(genPt,dPt,weight);
  h_n1_dPhiVsPt->Fill(genPt,dPhi,weight);
  if (fillEta)
    {
    h_n1_dEta->Fill(dEta,weight);
    h_n1_dEtaVsEta->Fill(genEta,dEta,weight);
    }
  if (fillY)
    {
    h_n1_dY->Fill(dY,weight);
    h_n1_dYVsY->Fill(genY,dY,weight);
    }
}

} // namespace CAP
