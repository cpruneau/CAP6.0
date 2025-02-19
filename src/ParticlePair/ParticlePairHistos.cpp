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
#include "ParticlePairHistos.hpp"
#include "MathConstants.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticlePairHistos);

namespace CAP
{
ParticlePairHistos::ParticlePairHistos()
:
HistogramGroup(),
nBins_n2(0),
nBins_pt(0),
nBins_phi(0),
nBins_eta(0),
nBins_y(0),
min_n2(0),
max_n2(0),
min_pt(0),
max_pt(0),
min_phi(0),
max_phi(0),
min_eta(0),
max_eta(0),
min_y(0),
max_y(0),
scale_pt(0),
scale_phi(0),
scale_eta(0),
scale_y(0),
width_Dphi(0),
fillEta(false),
fillY(false),
fillP2(false),
h_n2(nullptr),
h_n2_ptpt(nullptr),
h_n2_etaeta(nullptr),
h_DptDpt_etaeta(nullptr),
h_n2_phiphi(nullptr),
h_DptDpt_phiphi(nullptr),
h_n2_yY(nullptr),
h_DptDpt_yY(nullptr),
h_n2_DetaDphi(nullptr),
h_DptDpt_DetaDphi(nullptr),
h_n2_DyDphi(nullptr),
h_DptDpt_DyDphi(nullptr)
{
  appendClassName("ParticlePairHistos");
  setInstanceName("Pair");
}

ParticlePairHistos::ParticlePairHistos(const ParticlePairHistos & group)
:
HistogramGroup(),
nBins_n2(group.nBins_n2),
nBins_pt(group.nBins_pt),
nBins_phi(group.nBins_phi),
nBins_eta(group.nBins_eta),
nBins_y(group.nBins_y),
min_n2(group.min_n2),
max_n2(group.max_n2),
min_pt(group.min_pt),
max_pt(group.max_pt),
min_phi(group.min_phi),
max_phi(group.max_phi),
min_eta(group.min_eta),
max_eta(group.max_eta),
min_y(group.min_y),
max_y(group.max_y),
scale_pt(group.scale_pt),
scale_phi(group.scale_phi),
scale_eta(group.scale_eta),
scale_y(group.scale_y),
width_Dphi(group.width_Dphi),
fillEta(group.fillEta),
fillY(group.fillY),
fillP2(group.fillP2),
h_n2(nullptr),
h_n2_ptpt(nullptr),
h_n2_etaeta(nullptr),
h_DptDpt_etaeta(nullptr),
h_n2_phiphi(nullptr),
h_DptDpt_phiphi(nullptr),
h_n2_yY(nullptr),
h_DptDpt_yY(nullptr),
h_n2_DetaDphi(nullptr),
h_DptDpt_DetaDphi(nullptr),
h_n2_DyDphi(nullptr),
h_DptDpt_DyDphi(nullptr)
{
  cloneAll(group);
}

ParticlePairHistos & ParticlePairHistos::operator=(const ParticlePairHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    nBins_n2    =  group.nBins_n2;
    nBins_pt    =  group.nBins_pt;
    nBins_phi   =  group.nBins_phi;
    nBins_eta   =  group.nBins_eta;
    nBins_y     =  group.nBins_y;
    min_n2      =  group.min_n2;
    max_n2      =  group.max_n2;
    min_pt      =  group.min_pt;
    max_pt      =  group.max_pt;
    min_phi     =  group.min_phi;
    max_phi     =  group.max_phi;
    min_eta     =  group.min_eta;
    max_eta     =  group.max_eta;
    min_y       =  group.min_y;
    max_y       =  group.max_y;
    scale_pt    =  group.scale_pt;
    scale_phi   =  group.scale_phi;
    scale_eta   =  group.scale_eta;
    scale_y     =  group.scale_y;
    width_Dphi  =  group.width_Dphi;
    fillEta     =  group.fillEta;
    fillY       =  group.fillY;
    fillP2      =  group.fillP2;
    cloneAll(group);
    }
  return *this;
}

void ParticlePairHistos::cloneAll(const ParticlePairHistos & group)
{
  // ony clone those that exist...
  if (group.h_n2)              h_n2              = (TH1*) group.h_n2->Clone();
  if (group.h_n2_ptpt)         h_n2_ptpt         = (TH2*) group.h_n2_ptpt->Clone();
  if (group.h_n2_etaeta)       h_n2_etaeta       = (TH2*) group.h_n2_etaeta->Clone();
  if (group.h_DptDpt_etaeta)   h_DptDpt_etaeta   = (TH2*) group.h_DptDpt_etaeta->Clone();
  if (group.h_n2_phiphi)       h_n2_phiphi       = (TH2*) group.h_n2_phiphi->Clone();
  if (group.h_DptDpt_phiphi)   h_DptDpt_phiphi   = (TH2*) group.h_DptDpt_phiphi->Clone();
  if (group.h_n2_yY)           h_n2_yY           = (TH2*) group.h_n2_yY->Clone();
  if (group.h_DptDpt_yY)       h_DptDpt_yY       = (TH2*) group.h_DptDpt_yY->Clone();
  if (group.h_n2_DetaDphi)     h_n2_DetaDphi     = (TH2*) group.h_n2_DetaDphi->Clone();
  if (group.h_DptDpt_DetaDphi) h_DptDpt_DetaDphi = (TH2*) group.h_DptDpt_DetaDphi->Clone();
  if (group.h_n2_DyDphi)       h_n2_DyDphi       = (TH2*) group.h_n2_DyDphi->Clone();
  if (group.h_DptDpt_DyDphi)   h_DptDpt_DyDphi   = (TH2*) group.h_DptDpt_DyDphi->Clone();
}

void ParticlePairHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  nBins_n2  = configuration.getValueInt(ptn,   "nBins_n2");
  min_n2    = configuration.getValueDouble(ptn,"Min_n2");
  max_n2    = configuration.getValueDouble(ptn,"Max_n2");
  nBins_pt  = configuration.getValueInt(ptn,   "nBins_pt");
  min_pt    = configuration.getValueDouble(ptn,"Min_pt");
  max_pt    = configuration.getValueDouble(ptn,"Max_pt");
  nBins_phi = configuration.getValueInt(ptn,   "nBins_phi");
  min_phi   = configuration.getValueDouble(ptn,"Min_phi");
  max_phi   = configuration.getValueDouble(ptn,"Max_phi");
  nBins_eta = configuration.getValueInt(ptn,   "nBins_eta");
  min_eta   = configuration.getValueDouble(ptn,"Min_eta");
  max_eta   = configuration.getValueDouble(ptn,"Max_eta");
  nBins_y   = configuration.getValueInt(ptn,   "nBins_y");
  min_y     = configuration.getValueDouble(ptn,"Min_y");
  max_y     = configuration.getValueDouble(ptn,"Max_y");
  fillEta   = configuration.getValueBool(ptn,"FillEta");
  fillY     = configuration.getValueBool(ptn,"FillY");
  fillP2    = configuration.getValueBool(ptn,"FillP2");

  int nBins_Dphi          = nBins_phi;
  double min_Dphi         = 0.0; //-width_Dphi/2.;
  double max_Dphi         = CAP::Math::twoPi(); // - width_Dphi/2.;
//  int nBins_Dphi_shft     = int(double(nBins_Dphi)/4.0);
//  double min_Dphi_shft    = min_Dphi - width_Dphi*double(nBins_Dphi_shft);
//  double max_Dphi_shft    = max_Dphi - width_Dphi*double(nBins_Dphi_shft);

  int nBins_Deta     = 2*nBins_eta-1;
  double min_Deta    = -(max_eta-min_eta);
  double max_Deta    = max_eta-min_eta;
  int nBins_Dy       = 2*nBins_y-1;
  double min_Dy      = -(max_y-min_y);
  double max_Dy      = max_y-min_y;

  scale_pt  = double(nBins_pt)/(max_pt-min_pt);
  scale_phi = double(nBins_phi)/(max_phi-min_phi);
  scale_eta = double(nBins_eta)/(max_eta-min_eta);
  scale_y   = double(nBins_y)/(max_y-min_y);

  h_n2          = createHistogram(createName(bn,"n2"),         nBins_n2,  min_n2,  max_n2, "n_{2}", "Yield");
  h_n2_ptpt     = createHistogram(createName(bn,"n2_ptpt"),    nBins_pt,  min_pt,  max_pt, nBins_pt, min_pt, max_pt,   "p_{T,1}",  "p_{T,2}", "N_{2}");
  h_n2_phiphi   = createHistogram(createName(bn,"n2_phiphi"),  nBins_phi, min_phi, max_phi, nBins_phi, min_phi, max_phi, "#varphi_{1}", "#varphi_{2}", "N_{2}");

  if (fillP2)
    {
    h_DptDpt_phiphi = createHistogram(createName(bn,"ptpt_phiphi"),   nBins_phi, min_phi, max_phi, nBins_phi, min_phi, max_phi, "#varphi_{1}", "#varphi_{2}", "p_{T}xp_{T}");
    }

  if (fillEta)
    {
    h_n2_etaeta   = createHistogram(createName(bn,"n2_etaeta"),   nBins_eta,  min_eta, max_eta, nBins_eta, min_eta, max_eta, "#eta_{1}", "#eta_{2}", "N_{2}");
    h_n2_DetaDphi = createHistogram(createName(bn,"n2_DetaDphi"), nBins_Deta, min_Deta, max_Deta, nBins_Dphi, min_Dphi, max_Dphi, "#Delta#eta", "#Delta#phi", "N_{2}");
    if (fillP2)
      {
      h_DptDpt_etaeta = createHistogram(createName(bn,"ptpt_etaeta"), nBins_eta, min_eta, max_eta, nBins_eta, min_eta, max_eta, "#eta_{1}", "#eta_{2}", "p_{T}xp_{T}");
      h_DptDpt_DetaDphi = createHistogram(createName(bn,"ptpt_DetaDphi"),nBins_Deta, min_Deta, max_Deta, nBins_Dphi, min_Dphi, max_Dphi, "#Delta#eta", "#Delta#phi", "ptpt");
      }
    }

  if (fillY)
    {
    h_n2_yY     = createHistogram(createName(bn,"n2_yY"),     nBins_y,  min_y,  max_y,  nBins_y, min_y, max_y, "y_{1}","y_{2}", "N_{2}");
    h_n2_DyDphi = createHistogram(createName(bn,"n2_DyDphi"), nBins_Dy, min_Dy, max_Dy, nBins_Dphi, min_Dphi, max_Dphi, "#Delta y", "#Delta#phi", "N_{2}");
    if (fillP2)
      {
      h_DptDpt_yY    = createHistogram(createName(bn,"ptpt_yY"),  nBins_y,  min_y, max_y, nBins_y, min_y, max_y, "y_{1}","y_{2}", "p_{T}xp_{T}");
      h_DptDpt_DyDphi = createHistogram(createName(bn,"ptpt_DyDphi"),nBins_Dy, min_Dy, max_Dy, nBins_Dphi, min_Dphi, max_Dphi, "#Delta y", "#Delta#phi", "ptpt");
      }
    }
  if (reportEnd(__FUNCTION__)) { /* noops*/ };
}

//________________________________________________________________________
void ParticlePairHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  fillEta       = configuration.getValueBool(ptn,"FillEta");
  fillY         = configuration.getValueBool(ptn,"FillY");
  fillP2        = configuration.getValueBool(ptn,"FillP2");
  if (reportInfo(__FUNCTION__))
    {
    cout << endl;
    printValue("Histo Base Name",    bn);
    printValue("Parent Task Name",   ptn);
    printValue("FillEta",            fillEta);
    printValue("FillY",              fillY);
    printValue("FillP2",             fillP2);
    }
  h_n2          = importH1(inputFile, CAP::createName(bn,"n2"));
  h_n2_ptpt     = importH2(inputFile, CAP::createName(bn,"n2_ptpt"));
  h_n2_phiphi   = importH2(inputFile, CAP::createName(bn,"n2_phiphi"));

  if (fillP2)
    {
    h_DptDpt_phiphi = importH2(inputFile, CAP::createName(bn,"ptpt_phiphi"));
    }

  if (fillEta)
    {
    h_n2_etaeta   = importH2(inputFile, CAP::createName(bn,"n2_etaeta"));
    h_n2_DetaDphi = importH2(inputFile, CAP::createName(bn,"n2_DetaDphi"));
    if (fillP2)
      {
      h_DptDpt_etaeta   = importH2(inputFile, CAP::createName(bn,"ptpt_etaeta"));
      h_DptDpt_DetaDphi = importH2(inputFile, CAP::createName(bn,"ptpt_DetaDphi"));
      }
    }
  if (fillY)
    {
    h_n2_yY     = importH2(inputFile, CAP::createName(bn,"n2_yY"));
    h_n2_DyDphi = importH2(inputFile, CAP::createName(bn,"n2_DyDphi"));
    if (fillP2)
      {
      h_DptDpt_yY     = importH2(inputFile, CAP::createName(bn,"ptpt_yY"));
      h_DptDpt_DyDphi = importH2(inputFile, CAP::createName(bn,"ptpt_DyDphi"));
      }
    }
  if (reportEnd(__FUNCTION__)) { /* noops*/ };
}


void ParticlePairHistos::fill(Particle & particle1, Particle & particle2, double weight)
{
  int iPhi1, iPt1, iEta1, iY1;
  int iPhi2, iPt2, iEta2, iY2;
  int iGptpt;
  int iGphiphi;
  int iGetaeta;
  int iGYY;
  int iGDeltaEtaDeltaPhi;
  int iGDeltaYDeltaPhi;

  LorentzVector & momentum1 = particle1.getMomentum();
  double pt1   = momentum1.Pt();        iPt1 = getPtBinFor(pt1);
  double phi1  = momentum1.Phi();       if (phi1<0.0) phi1 += CAP::Math::twoPi(); iPhi1 = getPhiBinFor(phi1);
  double eta1  = momentum1.Eta();       iEta1 = fillEta ? getEtaBinFor(eta1) : 0;
  double y1    = momentum1.Rapidity();  iY1   = fillY   ? getYBinFor(y1)     : 0;

  LorentzVector & momentum2 = particle2.getMomentum();
  double pt2   = momentum2.Pt();        iPt2 = getPtBinFor(pt2);
  double phi2  = momentum2.Phi();       if (phi2<0.0) phi2 += CAP::Math::twoPi(); iPhi2 = getPhiBinFor(phi2);
  double eta2  = momentum2.Eta();       iEta2 = fillEta ? getEtaBinFor(eta2) : 0;
  double y2    = momentum2.Rapidity();  iY2   = fillY   ? getYBinFor(y2)     : 0;

//  cout <<  "pt1:" << pt1 << " phi1:" << phi1 << " y1:" << y1 << " iPt1: " << iPt1 << " iPhi1:" <<  iPhi1 << " iY1:" <<  iY1 << endl;
//  cout <<  "pt2:" << pt2 << " phi2:" << phi2 << " y2:" << y2 << " iPt2: " << iPt2 << " iPhi2:" <<  iPhi2 << " iY2:" <<  iY2 << endl;

  if (iPt1==0  || iPt2==0)  return;
  if (iPhi1==0 || iPhi1==0) return;
  if (iEta1==0 && iY1==0) return;
  if (iEta2==0 && iY2==0) return;
  int iDeltaEta  = iEta1-iEta2 + nBins_eta-1;
  int iDeltaY    = iY1-iY2 + nBins_y-1;
  int iDeltaPhi  = iPhi1-iPhi2;
  if (iDeltaPhi < 0) iDeltaPhi += nBins_phi;
  //cout <<  "iDeltaY:" << iDeltaY << " iDeltaPhi: " << iDeltaPhi << endl;
  fillP2 = false;
  fillY  = true;

  iGptpt   = h_n2_ptpt->GetBin(iPt1,iPt2);
  iGphiphi = h_n2_phiphi->GetBin(iPhi1,iPhi2);

  h_n2_ptpt   ->AddBinContent(iGptpt,    weight);  h_n2_ptpt  ->SetEntries(h_n2_ptpt  ->GetEntries()+1);
  h_n2_phiphi ->AddBinContent(iGphiphi,  weight);  h_n2_phiphi->SetEntries(h_n2_phiphi->GetEntries()+1);

  if (fillP2)
    {
    h_DptDpt_phiphi->AddBinContent(iGphiphi,weight*pt1*pt2);
    h_DptDpt_phiphi->SetEntries(h_DptDpt_phiphi->GetEntries()+1);
    }

  if (fillEta && iEta1!=0 && iEta2!=0 )
    {
    iGetaeta           = h_n2_etaeta->GetBin(iEta1,iEta2);
    iGDeltaEtaDeltaPhi = h_n2_DetaDphi->GetBin(iDeltaEta+1,iDeltaPhi+1);
    h_n2_etaeta->AddBinContent(iGetaeta,weight);             h_n2_etaeta  ->SetEntries(h_n2_etaeta  ->GetEntries()+1);
    h_n2_DetaDphi->AddBinContent(iGDeltaEtaDeltaPhi,weight); h_n2_DetaDphi->SetEntries(h_n2_DetaDphi->GetEntries()+1);

    if (fillP2)
      {
      h_DptDpt_etaeta   ->AddBinContent(iGetaeta,           weight*pt1*pt2); h_DptDpt_etaeta->SetEntries(h_DptDpt_etaeta    ->GetEntries()+1);
      h_DptDpt_DetaDphi ->AddBinContent(iGDeltaEtaDeltaPhi, weight*pt1*pt2); h_DptDpt_DetaDphi->SetEntries(h_DptDpt_DetaDphi->GetEntries()+1);
      }
    }

  if (fillY && iY1!=0 && iY2!=0 )
    {
    iGYY             = h_n2_yY->GetBin(iY1,iY2);
    iGDeltaYDeltaPhi = h_n2_DyDphi->GetBin(iDeltaY+1,iDeltaPhi+1);
    h_n2_yY      ->AddBinContent(iGYY,weight);              h_n2_yY      ->SetEntries(h_n2_yY      ->GetEntries()+1);
    h_n2_DyDphi  ->AddBinContent(iGDeltaYDeltaPhi,weight);  h_n2_DyDphi  ->SetEntries(h_n2_DyDphi  ->GetEntries()+1);
    if (fillP2)
      {
      h_DptDpt_yY     ->AddBinContent(iGYY, weight*pt1*pt2);               h_DptDpt_yY ->SetEntries(   h_DptDpt_yY     ->GetEntries()+1);
      h_DptDpt_DyDphi ->AddBinContent(iGDeltaEtaDeltaPhi, weight*pt1*pt2); h_DptDpt_DyDphi->SetEntries(h_DptDpt_DyDphi->GetEntries()+1);
      }
    }
}

void ParticlePairHistos::fillMultiplicity(double nPairs, double weight)
{
  h_n2->Fill(nPairs, weight);
}


} // namespace CAP
