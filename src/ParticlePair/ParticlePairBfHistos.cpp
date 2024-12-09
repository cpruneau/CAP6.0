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
#include "ParticlePairBfHistos.hpp"
#include "RootHelpers.hpp"
#include "PrintHelpers.hpp"
#include "TRandom.h"

ClassImp(CAP::ParticlePairBfHistos);

namespace CAP
{

ParticlePairBfHistos::ParticlePairBfHistos()
:
HistogramGroup(),
fillEta(false),
fillY(false),
fillP2(false)
{
  appendClassName("ParticlePairBfHistos");
}

ParticlePairBfHistos::ParticlePairBfHistos(const ParticlePairBfHistos & group)
: HistogramGroup(group),
fillEta(group.fillEta),
fillY(group.fillY),
fillP2(group.fillP2)
{

}

ParticlePairBfHistos & ParticlePairBfHistos::operator=(const ParticlePairBfHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    }
  return *this;
}


void ParticlePairBfHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();

  nBins_n2  = configuration.getValueInt(ptn,"nBins_n2");
  min_n2    = configuration.getValueDouble(ptn,"Min_n2");
  max_n2    = configuration.getValueDouble(ptn,"Max_n2");
  nBins_pt  = configuration.getValueInt(ptn,"nBins_pt");
  min_pt    = configuration.getValueDouble(ptn,"Min_pt");
  max_pt    = configuration.getValueDouble(ptn,"Max_pt");
  nBins_phi = configuration.getValueInt(ptn,"nBins_phi");
  min_phi   = configuration.getValueDouble(ptn,"Min_phi");
  max_phi   = configuration.getValueDouble(ptn,"Max_phi");
  nBins_eta = configuration.getValueInt(ptn,"nBins_eta");
  min_eta   = configuration.getValueDouble(ptn,"Min_eta");
  max_eta   = configuration.getValueDouble(ptn,"Max_eta");
  nBins_y   = configuration.getValueInt(ptn,"nBins_y");
  min_y     = configuration.getValueDouble(ptn,"Min_y");
  max_y     = configuration.getValueDouble(ptn,"Max_y");
  max_yAcc  = configuration.getValueDouble(ptn,"Max_yAcc");

  fillEta    = configuration.getValueBool(ptn,"FillEta");
  fillY      = configuration.getValueBool(ptn,"FillY");
  fillP2     = configuration.getValueBool(ptn,"FillP2");

  nBins_Dphi       = nBins_phi;
  min_Dphi         = 0.0; //-width_Dphi/2.;
  max_Dphi         = CAP::Math::twoPi(); // - width_Dphi/2.;
  nBins_Dphi_shft  = int(double(nBins_Dphi)/4.0);
  width_Dphi       = (max_phi-min_phi)/double(nBins_phi);
  min_Dphi_shft    = min_Dphi - width_Dphi*double(nBins_Dphi_shft);
  max_Dphi_shft    = max_Dphi - width_Dphi*double(nBins_Dphi_shft);

  nBins_Deta = 2*nBins_eta-1;
  min_Deta   = -(max_eta-min_eta);
  max_Deta   = max_eta-min_eta;
  nBins_Dy   = 2*nBins_y-1;
  min_Dy     = -(max_y - min_y);
  max_Dy     = max_y - min_y;

  h_C2_CD_ptpt    = createHistogram(createName(bn,"C2_CD_ptpt"),    nBins_pt,min_pt,max_pt,nBins_pt,min_pt,max_pt, "p_{T,1}","p_{T,2}", "C_{2}^{CD}");
  h_C2_CI_ptpt    = createHistogram(createName(bn,"C2_CI_ptpt"),    nBins_pt,min_pt,max_pt,nBins_pt,min_pt,max_pt, "p_{T,1}","p_{T,2}", "C_{2}^{CI}");
  h_C2N_B12_ptpt  = createHistogram(createName(bn,"C2N_B12_ptpt"),  nBins_pt,min_pt,max_pt,nBins_pt,min_pt,max_pt, "p_{T,1}","p_{T,2}", "B_{C2N}^{12}");
  h_C2N_B21_ptpt  = createHistogram(createName(bn,"C2N_B21_ptpt"),  nBins_pt,min_pt,max_pt,nBins_pt,min_pt,max_pt, "p_{T,1}","p_{T,2}", "B_{C2N}^{21}");
  h_C2N_Bs_ptpt   = createHistogram(createName(bn,"C2N_Bs_ptpt"),   nBins_pt,min_pt,max_pt,nBins_pt,min_pt,max_pt, "p_{T,1}","p_{T,2}", "B_{C2N}^{s}");
  h_R2_B12_ptpt   = createHistogram(createName(bn,"R2_B12_ptpt"),   nBins_pt,min_pt,max_pt,nBins_pt,min_pt,max_pt, "p_{T,1}","p_{T,2}", "B_{R2}^{12}");
  h_R2_B21_ptpt   = createHistogram(createName(bn,"R2_B21_ptpt"),   nBins_pt,min_pt,max_pt,nBins_pt,min_pt,max_pt, "p_{T,1}","p_{T,2}", "B_{R2}^{21}");
  h_R2_Bs_ptpt    = createHistogram(createName(bn,"R2_Bs_ptpt"),    nBins_pt,min_pt,max_pt,nBins_pt,min_pt,max_pt, "p_{T,1}","p_{T,2}", "B_{R2}^{s}");

  h_C2_CD_phiphi   = createHistogram(createName(bn,"C2_CD_phiphi"),     nBins_phi,min_phi,max_phi,nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{2}", "C_{2}^{CD}");
  h_C2_CI_phiphi   = createHistogram(createName(bn,"C2_CI_phiphi"),   nBins_phi,min_phi,max_phi,nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{2}", "C_{2}^{CI}");
  h_C2N_B12_phiphi = createHistogram(createName(bn,"C2N_B12_phiphi"), nBins_phi,min_phi,max_phi,nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{2}", "B_{C2N}^{12}");
  h_C2N_B21_phiphi = createHistogram(createName(bn,"C2N_B21_phiphi"), nBins_phi,min_phi,max_phi,nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{2}", "B_{C2N}^{21}");
  h_C2N_Bs_phiphi  = createHistogram(createName(bn,"C2N_Bs_phiphi"),  nBins_phi,min_phi,max_phi,nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{2}", "B_{C2N}^{s}");
  h_R2_B12_phiphi  = createHistogram(createName(bn,"R2_B12_phiphi"),  nBins_phi,min_phi,max_phi,nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{2}", "B_{R2}^{12}");
  h_R2_B21_phiphi  = createHistogram(createName(bn,"R2_B21_phiphi"),  nBins_phi,min_phi,max_phi,nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{2}", "B_{R2}^{21}");
  h_R2_Bs_phiphi   = createHistogram(createName(bn,"R2_Bs_phiphi"),   nBins_phi,min_phi,max_phi,nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{2}", "B_{R2}^{s}");

if (fillEta)
  {
  h_C2_CD_etaeta   = createHistogram(createName(bn,"C2_CD_etaeta"),   nBins_eta,min_eta,max_eta,nBins_eta,min_eta,max_eta, "#eta_{1}","#eta_{2}", "C_{2}^{CD}");
  h_C2_CI_etaeta   = createHistogram(createName(bn,"C2_CI_etaeta"),   nBins_eta,min_eta,max_eta,nBins_eta,min_eta,max_eta, "#eta_{1}","#eta_{2}", "C_{2}^{CI}");
  h_C2N_B12_etaeta = createHistogram(createName(bn,"C2N_B12_etaeta"), nBins_eta,min_eta,max_eta,nBins_eta,min_eta,max_eta, "#eta_{1}","#eta_{2}", "B_{C2N}^{12}");
  h_C2N_B21_etaeta = createHistogram(createName(bn,"C2N_B21_etaeta"), nBins_eta,min_eta,max_eta,nBins_eta,min_eta,max_eta, "#eta_{1}","#eta_{2}", "B_{C2N}^{21}");
  h_C2N_Bs_etaeta  = createHistogram(createName(bn,"C2N_Bs_etaeta"),  nBins_eta,min_eta,max_eta,nBins_eta,min_eta,max_eta, "#eta_{1}","#eta_{2}", "B_{C2N}^{s}");
  h_R2_B12_etaeta  = createHistogram(createName(bn,"R2_B12_etaeta"),  nBins_eta,min_eta,max_eta,nBins_eta,min_eta,max_eta, "#eta_{1}","#eta_{2}", "B_{R2}^{12}");
  h_R2_B21_etaeta  = createHistogram(createName(bn,"R2_B21_etaeta"),  nBins_eta,min_eta,max_eta,nBins_eta,min_eta,max_eta, "#eta_{1}","#eta_{2}", "B_{R2}^{21}");
  h_R2_Bs_etaeta   = createHistogram(createName(bn,"R2_Bs_etaeta"),   nBins_eta,min_eta,max_eta,nBins_eta,min_eta,max_eta, "#eta_{1}","#eta_{2}", "B_{R2}^{s}");

  h_C2_CD_DetaDphi    = createHistogram(createName(bn,"C2_CD_DetaDphi"),    nBins_Deta,min_Deta,max_Deta,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta#eta","#Delta#phi", "C_{2}^{CD}");
  h_C2_CI_DetaDphi    = createHistogram(createName(bn,"C2_CI_DetaDphi"),    nBins_Deta,min_Deta,max_Deta,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta#eta","#Delta#phi", "C_{2}^{CI}");
  h_C2N_B12_DetaDphi  = createHistogram(createName(bn,"C2N_B12_DetaDphi"),  nBins_Deta,min_Deta,max_Deta,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta#eta","#Delta#phi", "B_{C2N}^{12}");
  h_C2N_B21_DetaDphi  = createHistogram(createName(bn,"C2N_B21_DetaDphi"),  nBins_Deta,min_Deta,max_Deta,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta#eta","#Delta#phi", "B_{C2N}^{21}");
  h_C2N_Bs_DetaDphi   = createHistogram(createName(bn,"C2N_Bs_DetaDphi"),   nBins_Deta,min_Deta,max_Deta,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta#eta","#Delta#phi", "B_{C2N}^{s}");
  h_R2_B12_DetaDphi   = createHistogram(createName(bn,"R2_B12_DetaDphi"),   nBins_Deta,min_Deta,max_Deta,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta#eta","#Delta#phi", "B_{R2}^{12}");
  h_R2_B21_DetaDphi   = createHistogram(createName(bn,"R2_B21_DetaDphi"),   nBins_Deta,min_Deta,max_Deta,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta#eta","#Delta#phi", "B_{R2}^{21}");
  h_R2_Bs_DetaDphi    = createHistogram(createName(bn,"R2_Bs_DetaDphi"),    nBins_Deta,min_Deta,max_Deta,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta#eta","#Delta#phi", "B_{R2}^{s}");
  }

  if (fillY)
    {
    h_C2_CD_yY     = createHistogram(createName(bn,"C2_CD_yY"),    nBins_y,min_y,max_y,nBins_y,min_y,max_y, "y_{1}","y_{2}", "C_{2}^{CD}");
    h_C2_CI_yY     = createHistogram(createName(bn,"C2_CI_yY"),    nBins_y,min_y,max_y,nBins_y,min_y,max_y, "y_{1}","y_{2}", "C_{2}^{CI}");
    h_C2N_B12_yY   = createHistogram(createName(bn,"C2N_B12_yY"),  nBins_y,min_y,max_y,nBins_y,min_y,max_y, "y_{1}","y_{2}", "B_{C2N}^{12}");
    h_C2N_B21_yY   = createHistogram(createName(bn,"C2N_B21_yY"),  nBins_y,min_y,max_y,nBins_y,min_y,max_y, "y_{1}","y_{2}", "B_{C2N}^{21}");
    h_C2N_Bs_yY    = createHistogram(createName(bn,"C2N_Bs_yY"),   nBins_y,min_y,max_y,nBins_y,min_y,max_y, "y_{1}","y_{2}", "B_{C2N}^{s}");
    h_R2_B12_yY    = createHistogram(createName(bn,"R2_B12_yY"),   nBins_y,min_y,max_y,nBins_y,min_y,max_y, "y_{1}","y_{2}", "B_{R2}^{12}");
    h_R2_B21_yY    = createHistogram(createName(bn,"R2_B21_yY"),   nBins_y,min_y,max_y,nBins_y,min_y,max_y, "y_{1}","y_{2}", "B_{R2}^{21}");
    h_R2_Bs_yY     = createHistogram(createName(bn,"R2_Bs_yY"),    nBins_y,min_y,max_y,nBins_y,min_y,max_y, "y_{1}","y_{2}", "B_{R2}^{s}");

    h_C2_CD_DyDphi     = createHistogram(createName(bn,"C2_CD_DyDphi"),    nBins_Dy,min_Dy,max_Dy,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta y","#Delta#phi", "C_{2}^{CD}");
    h_C2_CI_DyDphi     = createHistogram(createName(bn,"C2_CI_DyDphi"),    nBins_Dy,min_Dy,max_Dy,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta y","#Delta#phi", "C_{2}^{CI}");
    h_C2N_B12_DyDphi   = createHistogram(createName(bn,"C2N_B12_DyDphi"),  nBins_Dy,min_Dy,max_Dy,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta y","#Delta#phi", "B_{C2N}^{12}");
    h_C2N_B21_DyDphi   = createHistogram(createName(bn,"C2N_B21_DyDphi"),  nBins_Dy,min_Dy,max_Dy,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta y","#Delta#phi", "B_{C2N}^{21}");
    h_C2N_Bs_DyDphi    = createHistogram(createName(bn,"C2N_Bs_DyDphi"),   nBins_Dy,min_Dy,max_Dy,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta y","#Delta#phi", "B_{C2N}^{s}");
    h_R2_B12_DyDphi    = createHistogram(createName(bn,"R2_B12_DyDphi"),   nBins_Dy,min_Dy,max_Dy,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta y","#Delta#phi", "B_{R2}^{12}");
    h_R2_B21_DyDphi    = createHistogram(createName(bn,"R2_B21_DyDphi"),   nBins_Dy,min_Dy,max_Dy,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta y","#Delta#phi", "B_{R2}^{21}");
    h_R2_Bs_DyDphi     = createHistogram(createName(bn,"R2_Bs_DyDphi"),    nBins_Dy,min_Dy,max_Dy,nBins_Dphi,min_Dphi_shft,max_Dphi_shft, "#Delta y","#Delta#phi", "B_{R2}^{s}");
    }
}


void ParticlePairBfHistos::importHistograms(TFile & inputFile)
{
  const String & bn  = getName();
  const String & ptn = getParentName();

  fillEta    = configuration.getValueBool(ptn,"FillEta");
  fillY      = configuration.getValueBool(ptn,"FillY");
  fillP2     = configuration.getValueBool(ptn,"FillP2");

  h_C2_CD_ptpt    = loadH2(inputFile,createName(bn,"C2_CD_ptpt"));
  h_C2_CI_ptpt    = loadH2(inputFile,createName(bn,"C2_CI_ptpt"));
  h_C2N_B12_ptpt  = loadH2(inputFile,createName(bn,"C2N_B12_ptpt"));
  h_C2N_B21_ptpt  = loadH2(inputFile,createName(bn,"C2N_B21_ptpt"));
  h_C2N_Bs_ptpt   = loadH2(inputFile,createName(bn,"C2N_Bs_ptpt"));
  h_R2_B12_ptpt   = loadH2(inputFile,createName(bn,"R2_B12_ptpt"));
  h_R2_B21_ptpt   = loadH2(inputFile,createName(bn,"R2_B21_ptpt"));
  h_R2_Bs_ptpt    = loadH2(inputFile,createName(bn,"R2_Bs_ptpt"));

  h_C2_CD_phiphi   = loadH2(inputFile,createName(bn,"C2_CD_phiphi"));
  h_C2_CI_phiphi   = loadH2(inputFile,createName(bn,"C2_CI_phiphi"));
  h_C2N_B12_phiphi = loadH2(inputFile,createName(bn,"C2N_B12_phiphi"));
  h_C2N_B21_phiphi = loadH2(inputFile,createName(bn,"C2N_B21_phiphi"));
  h_C2N_Bs_phiphi  = loadH2(inputFile,createName(bn,"C2N_Bs_phiphi"));
  h_R2_B12_phiphi  = loadH2(inputFile,createName(bn,"R2_B12_phiphi"));
  h_R2_B21_phiphi  = loadH2(inputFile,createName(bn,"R2_B21_phiphi"));
  h_R2_Bs_phiphi   = loadH2(inputFile,createName(bn,"R2_Bs_phiphi"));

  if (fillEta)
    {
    h_C2_CD_etaeta   = loadH2(inputFile,createName(bn,"C2_CD_etaeta"));
    h_C2_CI_etaeta   = loadH2(inputFile,createName(bn,"C2_CI_etaeta"));
    h_C2N_B12_etaeta = loadH2(inputFile,createName(bn,"C2N_B12_etaeta"));
    h_C2N_B21_etaeta = loadH2(inputFile,createName(bn,"C2N_B21_etaeta"));
    h_C2N_Bs_etaeta  = loadH2(inputFile,createName(bn,"C2N_Bs_etaeta"));
    h_R2_B12_etaeta  = loadH2(inputFile,createName(bn,"R2_B12_etaeta"));
    h_R2_B21_etaeta  = loadH2(inputFile,createName(bn,"R2_B21_etaeta"));
    h_R2_Bs_etaeta   = loadH2(inputFile,createName(bn,"R2_Bs_etaeta"));

    h_C2_CD_DetaDphi    = loadH2(inputFile,createName(bn,"C2_CD_DetaDphi_shft"));
    h_C2_CI_DetaDphi    = loadH2(inputFile,createName(bn,"C2_CI_DetaDphi_shft"));
    h_C2N_B12_DetaDphi  = loadH2(inputFile,createName(bn,"C2N_B12_DetaDphi_shft"));
    h_C2N_B21_DetaDphi  = loadH2(inputFile,createName(bn,"C2N_B21_DetaDphi_shft"));
    h_C2N_Bs_DetaDphi   = loadH2(inputFile,createName(bn,"C2N_Bs_DetaDphi_shft"));
    h_R2_B12_DetaDphi   = loadH2(inputFile,createName(bn,"R2_B12_DetaDphi_shft"));
    h_R2_B21_DetaDphi   = loadH2(inputFile,createName(bn,"R2_B21_DetaDphi_shft"));
    h_R2_Bs_DetaDphi    = loadH2(inputFile,createName(bn,"R2_Bs_DetaDphi_shft"));

    }

  if (fillY)
    {
    h_C2_CD_yY     = loadH2(inputFile,createName(bn,"C2_CD_yY"));
    h_C2_CI_yY     = loadH2(inputFile,createName(bn,"C2_CI_yY"));
    h_C2N_B12_yY   = loadH2(inputFile,createName(bn,"C2N_B12_yY"));
    h_C2N_B21_yY   = loadH2(inputFile,createName(bn,"C2N_B21_yY"));
    h_C2N_Bs_yY    = loadH2(inputFile,createName(bn,"C2N_Bs_yY"));
    h_R2_B12_yY    = loadH2(inputFile,createName(bn,"R2_B12_yY"));
    h_R2_B21_yY    = loadH2(inputFile,createName(bn,"R2_B21_yY"));
    h_R2_Bs_yY     = loadH2(inputFile,createName(bn,"R2_Bs_yY"));

    h_C2_CD_DyDphi     = loadH2(inputFile,createName(bn,"C2_CD_DyDphi_shft"));
    h_C2_CI_DyDphi     = loadH2(inputFile,createName(bn,"C2_CI_DyDphi_shft"));
    h_C2N_B12_DyDphi   = loadH2(inputFile,createName(bn,"C2N_B12_DyDphi_shft"));
    h_C2N_B21_DyDphi   = loadH2(inputFile,createName(bn,"C2N_B21_DyDphi_shft"));
    h_C2N_Bs_DyDphi    = loadH2(inputFile,createName(bn,"C2N_Bs_DyDphi_shft"));
    h_R2_B12_DyDphi    = loadH2(inputFile,createName(bn,"R2_B12_DyDphi_shft"));
    h_R2_B21_DyDphi    = loadH2(inputFile,createName(bn,"R2_B21_DyDphi_shft"));
    h_R2_Bs_DyDphi     = loadH2(inputFile,createName(bn,"R2_Bs_DyDphi_shft"));
    }
}

//!
//! HistogramGroup from ParticlePairBfHistos must be normalized "per event" before calling this function
//!
void ParticlePairBfHistos::calculateBfHistograms(ParticlePairDerivedHistos & pair21B,
                                                 ParticlePairDerivedHistos & pair2B1B,
                                                 ParticlePairDerivedHistos & pair2B1,
                                                 ParticlePairDerivedHistos & pair21)
{
  printString("ParticlePairBfHistos::calculateBfHistograms -- 1 --");
  if (pair21B.h_C2_ptpt)
    {
    h_C2_CD_ptpt    ->Add(pair21B.h_C2_ptpt,pair2B1B.h_C2_ptpt,1.0,-1.0);
    h_C2_CD_ptpt    ->Add(pair2B1.h_C2_ptpt,+1.0);
    h_C2_CD_ptpt    ->Add(pair21.h_C2_ptpt, -1.0);
    printString("ParticlePairBfHistos::calculateBfHistograms -- 21 --");
    h_C2_CI_ptpt    ->Add(pair2B1.h_C2_ptpt,pair2B1B.h_C2_ptpt,1.0,+1.0);
    h_C2_CI_ptpt    ->Add(pair2B1.h_C2_ptpt);
    h_C2_CI_ptpt    ->Add(pair21.h_C2_ptpt);
    printString("ParticlePairBfHistos::calculateBfHistograms -- 3 --");
    h_C2N_B12_ptpt  ->Add(pair21B.h_C2_ptpt,pair2B1B.h_C2_ptpt,1.0,-1.0);
    h_C2N_B21_ptpt  ->Add(pair2B1.h_C2_ptpt,pair21.h_C2_ptpt,1.0,-1.0);
    h_C2N_Bs_ptpt   ->Add(h_C2N_B12_ptpt,h_C2N_B21_ptpt,0.5,0.5);
    printString("ParticlePairBfHistos::calculateBfHistograms -- 4 --");
    h_R2_B12_ptpt   ->Add(pair21B.h_R2_ptpt,pair2B1B.h_R2_ptpt,1.0,-1.0);
    h_R2_B21_ptpt   ->Add(pair2B1.h_R2_ptpt,pair21.h_R2_ptpt,1.0,-1.0);
    h_R2_Bs_ptpt    ->Add(h_R2_B12_ptpt,h_R2_B21_ptpt,0.5,0.5);
    }
  printString("ParticlePairBfHistos::calculateBfHistograms -- 5 --");

  if (pair21B.h_C2_phiphi)
    {
    h_C2_CD_phiphi   ->Add(pair21B.h_C2_phiphi,pair2B1B.h_C2_phiphi,1.0,-1.0);
    h_C2_CD_phiphi   ->Add(pair2B1.h_C2_phiphi,+1.0);
    h_C2_CD_phiphi   ->Add(pair21.h_C2_phiphi, -1.0);
    printString("ParticlePairBfHistos::calculateBfHistograms -- 6 --");
    h_C2_CI_phiphi   ->Add(pair21B.h_C2_phiphi,pair2B1B.h_C2_phiphi,1.0,1.0);
    h_C2_CI_phiphi   ->Add(pair2B1.h_C2_phiphi,+1.0);
    h_C2_CI_phiphi   ->Add(pair21.h_C2_phiphi, +1.0);
    h_C2N_B12_phiphi ->Add(pair21B.h_C2_phiphi,pair2B1B.h_C2_phiphi,1.0,-1.0);
    h_C2N_B21_phiphi ->Add(pair2B1.h_C2_phiphi,pair21.h_C2_phiphi,1.0,-1.0);
    h_C2N_Bs_phiphi  ->Add(h_C2N_B12_phiphi,h_C2N_B21_phiphi,0.5,0.5);
    h_R2_B12_phiphi  ->Add(pair21B.h_R2_phiphi,pair2B1B.h_R2_phiphi,1.0,-1.0);
    h_R2_B21_phiphi  ->Add(pair2B1.h_R2_phiphi,pair21.h_R2_phiphi,1.0,-1.0);
    h_R2_Bs_phiphi   ->Add(h_R2_B12_phiphi,h_R2_B21_phiphi,0.5,0.5);
    }
  printString("ParticlePairBfHistos::calculateBfHistograms -- 7 --");

  if (pair21B.h_C2_etaeta)
    {
    h_C2_CD_etaeta   ->Add(pair21B.h_C2_etaeta,pair2B1B.h_C2_etaeta,1.0,-1.0);
    h_C2_CD_etaeta   ->Add(pair2B1.h_C2_etaeta,+1.0);
    h_C2_CD_etaeta   ->Add(pair21.h_C2_etaeta, -1.0);
    h_C2_CI_etaeta   ->Add(pair21B.h_C2_etaeta,pair2B1B.h_C2_etaeta,1.0,1.0);
    h_C2_CI_etaeta   ->Add(pair2B1.h_C2_etaeta,+1.0);
    h_C2_CI_etaeta   ->Add(pair21.h_C2_etaeta, +1.0);
    printString("ParticlePairBfHistos::calculateBfHistograms -- 8 --");
    h_C2N_B12_etaeta ->Add(pair21B.h_C2_etaeta,pair2B1B.h_C2_etaeta,1.0,-1.0);
    h_C2N_B21_etaeta ->Add(pair2B1.h_C2_etaeta,pair21.h_C2_etaeta,1.0,-1.0);
    h_C2N_Bs_etaeta  ->Add(h_C2N_B12_etaeta,h_C2N_B21_etaeta,0.5,0.5);
    h_R2_B12_etaeta  ->Add(pair21B.h_R2_etaeta,pair2B1B.h_R2_etaeta,1.0,-1.0);
    h_R2_B21_etaeta  ->Add(pair2B1.h_R2_etaeta,pair21.h_R2_etaeta,1.0,-1.0);
    h_R2_Bs_etaeta   ->Add(h_R2_B12_etaeta,h_R2_B21_etaeta,0.5,0.5);
    }
  printString("ParticlePairBfHistos::calculateBfHistograms -- 9 --");

  if (pair21B.h_C2_yY)
    {
    h_C2_CD_yY   ->Add(pair21B.h_C2_yY,pair2B1B.h_C2_yY,1.0,-1.0);
    h_C2_CD_yY   ->Add(pair2B1.h_C2_yY,+1.0);
    h_C2_CD_yY   ->Add(pair21.h_C2_yY, -1.0);
    h_C2_CI_yY   ->Add(pair21B.h_C2_yY,pair2B1B.h_C2_yY,1.0,1.0);
    h_C2_CI_yY   ->Add(pair2B1.h_C2_yY,+1.0);
    h_C2_CI_yY   ->Add(pair21.h_C2_yY, +1.0);
    h_C2N_B12_yY ->Add(pair21B.h_C2_yY,pair2B1B.h_C2_yY,1.0,-1.0);
    h_C2N_B21_yY ->Add(pair2B1.h_C2_yY,pair21.h_C2_yY,1.0,-1.0);
    h_C2N_Bs_yY  ->Add(h_C2N_B12_yY,h_C2N_B21_yY,0.5,0.5);
    h_R2_B12_yY  ->Add(pair21B.h_R2_yY,pair2B1B.h_R2_yY,1.0,-1.0);
    h_R2_B21_yY  ->Add(pair2B1.h_R2_yY,pair21.h_R2_yY,1.0,-1.0);
    h_R2_Bs_yY   ->Add(h_R2_B12_yY,h_R2_B21_yY,0.5,0.5);
    }
  printString("ParticlePairBfHistos::calculateBfHistograms -- 10 --");

  if (pair21B.h_C2_DetaDphi)
    {
    h_C2_CD_DetaDphi   ->Add(pair21B.h_C2_DetaDphi_shft, pair2B1B.h_C2_DetaDphi_shft,1.0,-1.0);
    h_C2_CD_DetaDphi   ->Add(pair2B1.h_C2_DetaDphi_shft, +1.0);
    h_C2_CD_DetaDphi   ->Add(pair21.h_C2_DetaDphi_shft,  -1.0);
    h_C2_CI_DetaDphi   ->Add(pair21B.h_C2_DetaDphi_shft, pair2B1B.h_C2_DetaDphi_shft,1.0,1.0);
    h_C2_CI_DetaDphi   ->Add(pair2B1.h_C2_DetaDphi_shft, +1.0);
    h_C2_CI_DetaDphi   ->Add(pair21.h_C2_DetaDphi_shft,  +1.0);
    h_C2N_B12_DetaDphi ->Add(pair21B.h_C2_DetaDphi_shft, pair2B1B.h_C2_DetaDphi_shft,1.0,-1.0);
    h_C2N_B21_DetaDphi ->Add(pair2B1.h_C2_DetaDphi_shft, pair21.h_C2_DetaDphi_shft,1.0,-1.0);
    h_C2N_Bs_DetaDphi  ->Add(h_C2N_B12_DetaDphi,         h_C2N_B21_DetaDphi,0.5,0.5);
    h_R2_B12_DetaDphi  ->Add(pair21B.h_R2_DetaDphi_shft, pair2B1B.h_R2_DetaDphi_shft,1.0,-1.0);
    h_R2_B21_DetaDphi  ->Add(pair2B1.h_R2_DetaDphi_shft, pair21.h_R2_DetaDphi_shft,1.0,-1.0);
    h_R2_Bs_DetaDphi   ->Add(h_R2_B12_DetaDphi,          h_R2_B21_DetaDphi,0.5,0.5);
    }
  printString("ParticlePairBfHistos::calculateBfHistograms -- 11 --");

  if (pair21B.h_C2_DyDphi)
    {
    h_C2_CD_DyDphi   ->Add(pair21B.h_C2_DyDphi_shft, pair2B1B.h_C2_DyDphi_shft,1.0,-1.0);
    h_C2_CD_DyDphi   ->Add(pair2B1.h_C2_DyDphi_shft, +1.0);
    h_C2_CD_DyDphi   ->Add(pair21.h_C2_DyDphi_shft,  -1.0);
    h_C2_CI_DyDphi   ->Add(pair21B.h_C2_DyDphi_shft, pair2B1B.h_C2_DyDphi_shft,1.0,1.0);
    h_C2_CI_DyDphi   ->Add(pair2B1.h_C2_DyDphi_shft, +1.0);
    h_C2_CI_DyDphi   ->Add(pair21.h_C2_DyDphi_shft,  +1.0);
    h_C2N_B12_DyDphi ->Add(pair21B.h_C2_DyDphi_shft, pair2B1B.h_C2_DyDphi_shft,1.0,-1.0);
    h_C2N_B21_DyDphi ->Add(pair2B1.h_C2_DyDphi_shft, pair21.h_C2_DyDphi_shft,1.0,-1.0);
    h_C2N_Bs_DyDphi  ->Add(h_C2N_B12_DyDphi,         h_C2N_B21_DyDphi,0.5,0.5);
    h_R2_B12_DyDphi  ->Add(pair21B.h_R2_DyDphi_shft, pair2B1B.h_R2_DyDphi_shft,1.0,-1.0);
    h_R2_B21_DyDphi  ->Add(pair2B1.h_R2_DyDphi_shft, pair21.h_R2_DyDphi_shft,1.0,-1.0);
    h_R2_Bs_DyDphi   ->Add(h_R2_B12_DyDphi,          h_R2_B21_DyDphi,0.5,0.5);
    }
}


} //  namespace CAP
