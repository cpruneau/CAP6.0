/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Akash Raj
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau, Akash Raj,  Nov 2024
 *
 * *********************************************************************/
#include "JetPairHistosDerived.hpp"
#include "JetHelpers.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::JetPairHistosDerived);

namespace CAP
{

JetPairHistosDerived::JetPairHistosDerived()
:
JetPairHistos(),
h_jet_a2pp_ptpt(nullptr),
 h_jet_a2pp_phiphi(nullptr),
 h_jet_a2pp_etaeta(nullptr),
 h_jet_a2pp_thth(nullptr),
 h_jet_a2pp_jtjt(nullptr),
 h_jet_a2pp_zz(nullptr),

 h_jet_a2mp_ptpt(nullptr),
 h_jet_a2mp_phiphi(nullptr),
 h_jet_a2mp_etaeta(nullptr),
 h_jet_a2mp_thth(nullptr),
 h_jet_a2mp_jtjt(nullptr),
 h_jet_a2mp_zz(nullptr),

 h_jet_a2pm_ptpt(nullptr),
 h_jet_a2pm_phiphi(nullptr),
 h_jet_a2pm_etaeta(nullptr),
 h_jet_a2pm_thth(nullptr),
 h_jet_a2pm_jtjt(nullptr),
 h_jet_a2pm_zz(nullptr),

 h_jet_a2mm_ptpt(nullptr),
 h_jet_a2mm_phiphi(nullptr),
 h_jet_a2mm_etaeta(nullptr),
 h_jet_a2mm_thth(nullptr),
 h_jet_a2mm_jtjt(nullptr),
 h_jet_a2mm_zz(nullptr),

 h_jet_b2pm_ptpt(nullptr),
 h_jet_b2pm_phiphi(nullptr),
 h_jet_b2pm_etaeta(nullptr),
 h_jet_b2pm_thth(nullptr),
 h_jet_b2pm_jtjt(nullptr),
 h_jet_b2pm_zz(nullptr),

 h_jet_b2mp_ptpt(nullptr),
 h_jet_b2mp_phiphi(nullptr),
 h_jet_b2mp_etaeta(nullptr),
 h_jet_b2mp_thth(nullptr),
 h_jet_b2mp_jtjt(nullptr),
 h_jet_b2mp_zz(nullptr),

 h_jet_b2s_ptpt(nullptr),
 h_jet_b2s_phiphi(nullptr),
 h_jet_b2s_etaeta(nullptr),
 h_jet_b2s_thth(nullptr),
 h_jet_b2s_jtjt(nullptr),
 h_jet_b2s_zz(nullptr)
{
  appendClassName("JetPairHistosDerived");
  setInstanceName("JetPairHistosDerived");
}

JetPairHistosDerived::JetPairHistosDerived(const JetPairHistosDerived & group)
:
JetPairHistos(group),
h_jet_a2pp_ptpt(nullptr),
h_jet_a2pp_phiphi(nullptr),
h_jet_a2pp_etaeta(nullptr),
h_jet_a2pp_thth(nullptr),
h_jet_a2pp_jtjt(nullptr),
h_jet_a2pp_zz(nullptr),

h_jet_a2mp_ptpt(nullptr),
h_jet_a2mp_phiphi(nullptr),
h_jet_a2mp_etaeta(nullptr),
h_jet_a2mp_thth(nullptr),
h_jet_a2mp_jtjt(nullptr),
h_jet_a2mp_zz(nullptr),

h_jet_a2pm_ptpt(nullptr),
h_jet_a2pm_phiphi(nullptr),
h_jet_a2pm_etaeta(nullptr),
h_jet_a2pm_thth(nullptr),
h_jet_a2pm_jtjt(nullptr),
h_jet_a2pm_zz(nullptr),

h_jet_a2mm_ptpt(nullptr),
h_jet_a2mm_phiphi(nullptr),
h_jet_a2mm_etaeta(nullptr),
h_jet_a2mm_thth(nullptr),
h_jet_a2mm_jtjt(nullptr),
h_jet_a2mm_zz(nullptr),

h_jet_b2pm_ptpt(nullptr),
h_jet_b2pm_phiphi(nullptr),
h_jet_b2pm_etaeta(nullptr),
h_jet_b2pm_thth(nullptr),
h_jet_b2pm_jtjt(nullptr),
h_jet_b2pm_zz(nullptr),

h_jet_b2mp_ptpt(nullptr),
h_jet_b2mp_phiphi(nullptr),
h_jet_b2mp_etaeta(nullptr),
h_jet_b2mp_thth(nullptr),
h_jet_b2mp_jtjt(nullptr),
h_jet_b2mp_zz(nullptr),

h_jet_b2s_ptpt(nullptr),
h_jet_b2s_phiphi(nullptr),
h_jet_b2s_etaeta(nullptr),
h_jet_b2s_thth(nullptr),
h_jet_b2s_jtjt(nullptr),
h_jet_b2s_zz(nullptr)
{
  appendClassName("JetPairHistosDerived");
  setInstanceName("JetPairHistosDerived");
}

JetPairHistosDerived & JetPairHistosDerived::operator=(const JetPairHistosDerived & group)
{
  if (this!=&group)
    {
    JetPairHistos::operator=(group);
    }
  return *this;
}

void JetPairHistosDerived::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  int nBins_pt   = configuration.getValueInt(ptn,    "nBins_pt");
  double min_pt  = configuration.getValueDouble(ptn, "min_pt");
  double max_pt  = configuration.getValueDouble(ptn, "max_pt");
  int nBins_phi  = configuration.getValueInt(ptn,    "nBins_phi");
  double min_phi = configuration.getValueDouble(ptn, "min_phi");
  double max_phi = configuration.getValueDouble(ptn, "max_phi");
  int nBins_eta  = configuration.getValueInt(ptn,    "nBins_eta");
  double min_eta = configuration.getValueDouble(ptn, "min_eta");
  double max_eta = configuration.getValueDouble(ptn, "max_eta");
  int nBins_jt  = configuration.getValueInt(ptn,    "nBins_jt");
  double min_jt = configuration.getValueDouble(ptn, "min_jt");
  double max_jt = configuration.getValueDouble(ptn, "max_jt");
  int nBins_th  = configuration.getValueInt(ptn,    "nBins_th");
  double min_th = configuration.getValueDouble(ptn, "min_th");
  double max_th = configuration.getValueDouble(ptn, "max_th");
  int nBins_z   = configuration.getValueInt(ptn,    "nBins_z");
  double min_z  = configuration.getValueDouble(ptn, "min_z");
  double max_z  = configuration.getValueDouble(ptn, "max_z");

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("Parent Task Name",   ptn);
    printValue("Histo Base Name",    bn);
    printValue("nBins_pt",    nBins_pt);
    printValue("min_pt",      min_pt);
    printValue("max_pt",      max_pt);
    printValue("nBins_phi",   nBins_phi);
    printValue("min_phi",     min_phi);
    printValue("max_phi",     max_phi);
    printValue("nBins_eta",   nBins_eta);
    printValue("min_eta",     min_eta);
    printValue("max_eta",     max_eta);
    printValue("nBins_jt",    nBins_jt);
    printValue("min_jt",      min_jt);
    printValue("max_jt",      max_jt);
    printValue("nBins_th",    nBins_th);
    printValue("min_th",      min_th);
    printValue("max_th",      max_th);
    printLine();
    printCR();
    }
  h_jet_a2pp_ptpt   = createHistogram(createName(bn,"jet_a2pp_ptpt"),  nBins_pt,min_pt,max_pt,    nBins_pt,min_pt,max_pt,    "p_{T,1}",    "p_{T,2}",    "A_{2}^{++}");
  h_jet_a2pp_phiphi = createHistogram(createName(bn,"jet_a2pp_phiphi"),nBins_phi,min_phi,max_phi, nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{1}","A_{2}^{++}");
  h_jet_a2pp_etaeta = createHistogram(createName(bn,"jet_a2pp_etaet"), nBins_eta,min_eta,max_eta, nBins_eta,min_eta,max_eta, "#eta_{1}",   "#eta_{2}",   "A_{2}^{++}");
  h_jet_a2pp_thth   = createHistogram(createName(bn,"jet_a2pp_thth"),  nBins_th,min_th,max_th,    nBins_th,min_th,max_th,    "#theta_{1}", "#theta_{1}", "A_{2}^{++}");
  h_jet_a2pp_jtjt   = createHistogram(createName(bn,"jet_a2pp_jtjt"),  nBins_jt,min_jt,max_jt,    nBins_jt,min_jt,max_jt,    "j_{T,1}",    "j_{T,2}",    "A_{2}^{++}");
  h_jet_a2pp_zz     = createHistogram(createName(bn,"jet_a2pp_zz"),    nBins_z,min_z,max_z,       nBins_z,min_z,max_z,       "z_{1}",      "z_{2}",      "A_{2}^{++}");

  h_jet_a2mp_ptpt   = createHistogram(createName(bn,"jet_a2mp_ptpt"),  nBins_pt,min_pt,max_pt,    nBins_pt,min_pt,max_pt,    "p_{T,1}",    "p_{T,2}",    "A_{2}^{-+}");
  h_jet_a2mp_phiphi = createHistogram(createName(bn,"jet_a2mp_phiphi"),nBins_phi,min_phi,max_phi, nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{1}","A_{2}^{-+}");
  h_jet_a2mp_etaeta = createHistogram(createName(bn,"jet_a2mp_etaeta"),nBins_eta,min_eta,max_eta, nBins_eta,min_eta,max_eta, "#eta_{1}",   "#eta_{2}",   "A_{2}^{-+}");
  h_jet_a2mp_thth   = createHistogram(createName(bn,"jet_a2mp_thth"),  nBins_th,min_th,max_th,    nBins_th,min_th,max_th,    "#theta_{1}", "#theta_{1}", "A_{2}^{-+}");
  h_jet_a2mp_jtjt   = createHistogram(createName(bn,"jet_a2mp_jtjt"),  nBins_jt,min_jt,max_jt,    nBins_jt,min_jt,max_jt,    "j_{T,1}",    "j_{T,2}",    "A_{2}^{-+}");
  h_jet_a2mp_zz     = createHistogram(createName(bn,"jet_a2mp_zz"),    nBins_z,min_z,max_z,       nBins_z,min_z,max_z,       "z_{1}",      "z_{2}",      "A_{2}^{-+}");

  h_jet_a2pm_ptpt   = createHistogram(createName(bn,"jet_a2pm_ptpt"),  nBins_pt,min_pt,max_pt,    nBins_pt,min_pt,max_pt,    "p_{T,1}",    "p_{T,2}",    "A_{2}^{+-}");
  h_jet_a2pm_phiphi = createHistogram(createName(bn,"jet_a2pm_phiphi"),nBins_phi,min_phi,max_phi, nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{1}","A_{2}^{+-}");
  h_jet_a2pm_etaeta = createHistogram(createName(bn,"jet_a2pm_etaeta"),nBins_eta,min_eta,max_eta, nBins_eta,min_eta,max_eta, "#eta_{1}",   "#eta_{2}",   "A_{2}^{+-}");
  h_jet_a2pm_thth   = createHistogram(createName(bn,"jet_a2pm_thth"),  nBins_th,min_th,max_th,    nBins_th,min_th,max_th,    "#theta_{1}", "#theta_{1}", "A_{2}^{+-}");
  h_jet_a2pm_jtjt   = createHistogram(createName(bn,"jet_a2pm_jtjt"),  nBins_jt,min_jt,max_jt,    nBins_jt,min_jt,max_jt,    "j_{T,1}",    "j_{T,2}",    "A_{2}^{+-}");
  h_jet_a2pm_zz     = createHistogram(createName(bn,"jet_a2pm_zz"),    nBins_z,min_z,max_z,       nBins_z,min_z,max_z,       "z_{1}",      "z_{2}",      "A_{2}^{+-}");

  h_jet_a2mm_ptpt   = createHistogram(createName(bn,"jet_a2mm_ptpt"),  nBins_pt,min_pt,max_pt,    nBins_pt,min_pt,max_pt,    "p_{T,1}",    "p_{T,2}",    "A_{2}^{--}");
  h_jet_a2mm_phiphi = createHistogram(createName(bn,"jet_a2mm_phiphi"),nBins_phi,min_phi,max_phi, nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{1}","A_{2}^{--}");
  h_jet_a2mm_etaeta = createHistogram(createName(bn,"jet_a2mm_etaeta"),nBins_eta,min_eta,max_eta, nBins_eta,min_eta,max_eta, "#eta_{1}",   "#eta_{2}",   "A_{2}^{--}");
  h_jet_a2mm_thth   = createHistogram(createName(bn,"jet_a2mm_thth"),  nBins_th,min_th,max_th,    nBins_th,min_th,max_th,    "#theta_{1}", "#theta_{1}", "A_{2}^{--}");
  h_jet_a2mm_jtjt   = createHistogram(createName(bn,"jet_a2mm_jtjt"),  nBins_jt,min_jt,max_jt,    nBins_jt,min_jt,max_jt,    "j_{T,1}",    "j_{T,2}",    "A_{2}^{--}");
  h_jet_a2mm_zz     = createHistogram(createName(bn,"jet_a2mm_zz"),    nBins_z,min_z,max_z,       nBins_z,min_z,max_z,       "z_{1}",      "z_{2}",      "A_{2}^{--}");

  h_jet_b2pm_ptpt   = createHistogram(createName(bn,"jet_b2pm_ptpt"),  nBins_pt,min_pt,max_pt,    nBins_pt,min_pt,max_pt,    "p_{T,1}",    "p_{T,2}",    "B_{2}^{+-}");
  h_jet_b2pm_phiphi = createHistogram(createName(bn,"jet_b2pm_phiphi"),nBins_phi,min_phi,max_phi, nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{1}","B_{2}^{+-}");
  h_jet_b2pm_etaeta = createHistogram(createName(bn,"jet_b2pm_etaeta"),nBins_eta,min_eta,max_eta, nBins_eta,min_eta,max_eta, "#eta_{1}",   "#eta_{2}",   "B_{2}^{+-}");
  h_jet_b2pm_thth   = createHistogram(createName(bn,"jet_b2pm_thth"),  nBins_th,min_th,max_th,    nBins_th,min_th,max_th,    "#theta_{1}", "#theta_{1}", "B_{2}^{+-}");
  h_jet_b2pm_jtjt   = createHistogram(createName(bn,"jet_b2pm_jtjt"),  nBins_jt,min_jt,max_jt,    nBins_jt,min_jt,max_jt,    "j_{T,1}",    "j_{T,2}",    "B_{2}^{+-}");
  h_jet_b2pm_zz     = createHistogram(createName(bn,"jet_b2pm_zz"),    nBins_z,min_z,max_z,       nBins_z,min_z,max_z,       "z_{1}",      "z_{2}",      "B_{2}^{+-}");

  h_jet_b2mp_ptpt   = createHistogram(createName(bn,"jet_b2mp_ptpt"),  nBins_pt,min_pt,max_pt,    nBins_pt,min_pt,max_pt,    "p_{T,1}",    "p_{T,2}",    "B_{2}^{-+}");
  h_jet_b2mp_phiphi = createHistogram(createName(bn,"jet_b2mp_phiphi"),nBins_phi,min_phi,max_phi, nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{1}","B_{2}^{-+}");
  h_jet_b2mp_etaeta = createHistogram(createName(bn,"jet_b2mp_etaeta"),nBins_eta,min_eta,max_eta, nBins_eta,min_eta,max_eta, "#eta_{1}",   "#eta_{2}",   "B_{2}^{-+}");
  h_jet_b2mp_thth   = createHistogram(createName(bn,"jet_b2mp_thth"),  nBins_th,min_th,max_th,    nBins_th,min_th,max_th,    "#theta_{1}", "#theta_{1}", "B_{2}^{-+}");
  h_jet_b2mp_jtjt   = createHistogram(createName(bn,"jet_b2mp_jtjt"),  nBins_jt,min_jt,max_jt,    nBins_jt,min_jt,max_jt,    "j_{T,1}",    "j_{T,2}",    "B_{2}^{-+}");
  h_jet_b2mp_zz     = createHistogram(createName(bn,"jet_b2mp_zz"),    nBins_z,min_z,max_z,       nBins_z,min_z,max_z,       "z_{1}",      "z_{2}",      "B_{2}^{-+}");

  h_jet_b2s_ptpt    = createHistogram(createName(bn,"jet_b2s_ptpt "),  nBins_pt,min_pt,max_pt,    nBins_pt,min_pt,max_pt,    "p_{T,1}",    "p_{T,2}",    "B_{2}^{s}");
  h_jet_b2s_phiphi  = createHistogram(createName(bn,"jet_b2s_phiphi"), nBins_phi,min_phi,max_phi, nBins_phi,min_phi,max_phi, "#varphi_{1}","#varphi_{1}","B_{2}^{s}");
  h_jet_b2s_etaeta  = createHistogram(createName(bn,"jet_b2s_etaeta"), nBins_eta,min_eta,max_eta, nBins_eta,min_eta,max_eta, "#eta_{1}",   "#eta_{2}",   "B_{2}^{s}");
  h_jet_b2s_thth    = createHistogram(createName(bn,"jet_b2s_thth"),   nBins_th,min_th,max_th,    nBins_th,min_th,max_th,    "#theta_{1}", "#theta_{1}", "B_{2}^{s}");
  h_jet_b2s_jtjt    = createHistogram(createName(bn,"jet_b2s_jtjt"),   nBins_jt,min_jt,max_jt,    nBins_jt,min_jt,max_jt,    "j_{T,1}",    "j_{T,2}",    "B_{2}^{s}");
  h_jet_b2s_zz      = createHistogram(createName(bn,"jet_b2s_zz"),     nBins_z,min_z,max_z,       nBins_z,min_z,max_z,       "z_{1}",      "z_{2}",      "B_{2}^{s}");

}

void JetPairHistosDerived::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  //  h_jet_n2_ptpt    = loadH2(inputFile,createName(bn,"jet_n2_ptpt"));
  h_jet_a2pp_ptpt   =  loadH2(inputFile,createName(bn,"jet_a2pp_ptpt"));
  h_jet_a2pp_phiphi =  loadH2(inputFile,createName(bn,"jet_a2pp_phiphi"));
  h_jet_a2pp_etaeta =  loadH2(inputFile,createName(bn,"jet_a2pp_etaet"));
  h_jet_a2pp_thth   =  loadH2(inputFile,createName(bn,"jet_a2pp_thth"));
  h_jet_a2pp_jtjt   =  loadH2(inputFile,createName(bn,"jet_a2pp_jtjt"));
  h_jet_a2pp_zz     =  loadH2(inputFile,createName(bn,"jet_a2pp_zz"));

  h_jet_a2mp_ptpt   =  loadH2(inputFile,createName(bn,"jet_a2mp_ptpt"));
  h_jet_a2mp_phiphi =  loadH2(inputFile,createName(bn,"jet_a2mp_phiphi"));
  h_jet_a2mp_etaeta =  loadH2(inputFile,createName(bn,"jet_a2mp_etaeta"));
  h_jet_a2mp_thth   =  loadH2(inputFile,createName(bn,"jet_a2mp_thth"));
  h_jet_a2mp_jtjt   =  loadH2(inputFile,createName(bn,"jet_a2mp_jtjt"));
  h_jet_a2mp_zz     =  loadH2(inputFile,createName(bn,"jet_a2mp_zz"));

  h_jet_a2pm_ptpt   =  loadH2(inputFile,createName(bn,"jet_a2pm_ptpt"));
  h_jet_a2pm_phiphi =  loadH2(inputFile,createName(bn,"jet_a2pm_phiphi"));
  h_jet_a2pm_etaeta =  loadH2(inputFile,createName(bn,"jet_a2pm_etaeta"));
  h_jet_a2pm_thth   =  loadH2(inputFile,createName(bn,"jet_a2pm_thth"));
  h_jet_a2pm_jtjt   =  loadH2(inputFile,createName(bn,"jet_a2pm_jtjt"));
  h_jet_a2pm_zz     =  loadH2(inputFile,createName(bn,"jet_a2pm_zz"));

  h_jet_a2mm_ptpt   =  loadH2(inputFile,createName(bn,"jet_a2mm_ptpt"));
  h_jet_a2mm_phiphi =  loadH2(inputFile,createName(bn,"jet_a2mm_phiphi"));
  h_jet_a2mm_etaeta =  loadH2(inputFile,createName(bn,"jet_a2mm_etaeta"));
  h_jet_a2mm_thth   =  loadH2(inputFile,createName(bn,"jet_a2mm_thth"));
  h_jet_a2mm_jtjt   =  loadH2(inputFile,createName(bn,"jet_a2mm_jtjt"));
  h_jet_a2mm_zz     =  loadH2(inputFile,createName(bn,"jet_a2mm_zz"));

  h_jet_b2pm_ptpt   =  loadH2(inputFile,createName(bn,"jet_b2pm_ptpt"));
  h_jet_b2pm_phiphi =  loadH2(inputFile,createName(bn,"jet_b2pm_phiphi"));
  h_jet_b2pm_etaeta =  loadH2(inputFile,createName(bn,"jet_b2pm_etaeta"));
  h_jet_b2pm_thth   =  loadH2(inputFile,createName(bn,"jet_b2pm_thth"));
  h_jet_b2pm_jtjt   =  loadH2(inputFile,createName(bn,"jet_b2pm_jtjt"));
  h_jet_b2pm_zz     =  loadH2(inputFile,createName(bn,"jet_b2pm_zz"));

  h_jet_b2mp_ptpt   =  loadH2(inputFile,createName(bn,"jet_b2mp_ptpt"));
  h_jet_b2mp_phiphi =  loadH2(inputFile,createName(bn,"jet_b2mp_phiphi"));
  h_jet_b2mp_etaeta =  loadH2(inputFile,createName(bn,"jet_b2mp_etaeta"));
  h_jet_b2mp_thth   =  loadH2(inputFile,createName(bn,"jet_b2mp_thth"));
  h_jet_b2mp_jtjt   =  loadH2(inputFile,createName(bn,"jet_b2mp_jtjt"));
  h_jet_b2mp_zz     =  loadH2(inputFile,createName(bn,"jet_b2mp_zz"));

  h_jet_b2s_ptpt    =  loadH2(inputFile,createName(bn,"jet_b2s_ptpt "));
  h_jet_b2s_phiphi  =  loadH2(inputFile,createName(bn,"jet_b2s_phiphi"));
  h_jet_b2s_etaeta  =  loadH2(inputFile,createName(bn,"jet_b2s_etaeta"));
  h_jet_b2s_thth    =  loadH2(inputFile,createName(bn,"jet_b2s_thth"));
  h_jet_b2s_jtjt    =  loadH2(inputFile,createName(bn,"jet_b2s_jtjt"));
  h_jet_b2s_zz      =  loadH2(inputFile,createName(bn,"jet_b2s_zz"));

}

void JetPairHistosDerived::calculateDerivedHistograms(const JetSingleHistos & singleHistos, const JetPairHistos & pairHistos)
{
  double pIntegral = singleHistos.h_jet_n1p_phi->Integral();
  double mIntegral = singleHistos.h_jet_n1m_phi->Integral();
  double pScale = (pIntegral>0) ? 1.0/pIntegral : -1.0;  // -1 indicate error or no statistics
  double mScale = (mIntegral>0) ? 1.0/mIntegral : -1.0;  // -1 indicate error or no statistics

  printString("jet_a2pp");
  h_jet_a2pp_ptpt  ->Add(pairHistos.h_jet_n2pp_ptpt);   h_jet_a2pp_ptpt->Scale(pScale);
  h_jet_a2pp_phiphi->Add(pairHistos.h_jet_n2pp_phiphi); h_jet_a2pp_phiphi->Scale(pScale);
  h_jet_a2pp_etaeta->Add(pairHistos.h_jet_n2pp_etaeta); h_jet_a2pp_etaeta->Scale(pScale);
  h_jet_a2pp_thth  ->Add(pairHistos.h_jet_n2pp_thth);   h_jet_a2pp_thth->Scale(pScale);
  h_jet_a2pp_jtjt  ->Add(pairHistos.h_jet_n2pp_jtjt);   h_jet_a2pp_jtjt->Scale(pScale);
  h_jet_a2pp_zz    ->Add(pairHistos.h_jet_n2pp_zz);     h_jet_a2pp_zz->Scale(pScale);

  printString("jet_a2mp");
  h_jet_a2mp_ptpt  ->Add(pairHistos.h_jet_n2pm_ptpt);   h_jet_a2mp_ptpt->Scale(pScale);
  h_jet_a2mp_phiphi->Add(pairHistos.h_jet_n2pm_phiphi); h_jet_a2mp_phiphi->Scale(pScale);
  h_jet_a2mp_etaeta->Add(pairHistos.h_jet_n2pm_etaeta); h_jet_a2mp_etaeta->Scale(pScale);
  h_jet_a2mp_thth  ->Add(pairHistos.h_jet_n2pm_thth);   h_jet_a2mp_thth->Scale(pScale);
  h_jet_a2mp_jtjt  ->Add(pairHistos.h_jet_n2pm_jtjt);   h_jet_a2mp_jtjt->Scale(pScale);
  h_jet_a2mp_zz    ->Add(pairHistos.h_jet_n2pm_zz);     h_jet_a2mp_zz->Scale(pScale);

  printString("jet_a2pm");
  h_jet_a2pm_ptpt  ->Add(pairHistos.h_jet_n2pm_ptpt);   h_jet_a2pm_ptpt->Scale(mScale);
  h_jet_a2pm_phiphi->Add(pairHistos.h_jet_n2pm_phiphi); h_jet_a2pm_phiphi->Scale(mScale);
  h_jet_a2pm_etaeta->Add(pairHistos.h_jet_n2pm_etaeta); h_jet_a2pm_etaeta->Scale(mScale);
  h_jet_a2pm_thth  ->Add(pairHistos.h_jet_n2pm_thth);   h_jet_a2pm_thth->Scale(mScale);
  h_jet_a2pm_jtjt  ->Add(pairHistos.h_jet_n2pm_jtjt);   h_jet_a2pm_jtjt->Scale(mScale);
  h_jet_a2pm_zz    ->Add(pairHistos.h_jet_n2pm_zz);     h_jet_a2pm_zz->Scale(mScale);

  printString("jet_a2mm");
  h_jet_a2mm_ptpt  ->Add(pairHistos.h_jet_n2mm_ptpt);   h_jet_a2mm_ptpt->Scale(mScale);
  h_jet_a2mm_phiphi->Add(pairHistos.h_jet_n2mm_phiphi); h_jet_a2mm_phiphi->Scale(mScale);
  h_jet_a2mm_etaeta->Add(pairHistos.h_jet_n2mm_etaeta); h_jet_a2mm_etaeta->Scale(mScale);
  h_jet_a2mm_thth  ->Add(pairHistos.h_jet_n2mm_thth);   h_jet_a2mm_thth->Scale(mScale);
  h_jet_a2mm_jtjt  ->Add(pairHistos.h_jet_n2mm_jtjt);   h_jet_a2mm_jtjt->Scale(mScale);
  h_jet_a2mm_zz    ->Add(pairHistos.h_jet_n2mm_zz);     h_jet_a2mm_zz->Scale(mScale);

  printString("jet_b2pm");
  h_jet_b2pm_ptpt   ->Add(h_jet_a2pm_ptpt,   h_jet_a2mm_ptpt,    1.0, -1.0);
  h_jet_b2pm_phiphi ->Add(h_jet_a2pm_phiphi, h_jet_a2mm_phiphi,  1.0, -1.0);
  h_jet_b2pm_etaeta ->Add(h_jet_a2pm_etaeta, h_jet_a2mm_etaeta,  1.0, -1.0);
  h_jet_b2pm_thth   ->Add(h_jet_a2pm_thth,   h_jet_a2mm_thth,    1.0, -1.0);
  h_jet_b2pm_jtjt   ->Add(h_jet_a2pm_jtjt,   h_jet_a2mm_jtjt,    1.0, -1.0);
  h_jet_b2pm_zz     ->Add(h_jet_a2pm_zz,     h_jet_a2mm_zz,      1.0, -1.0);

  printString("jet_b2mp");
  h_jet_b2mp_ptpt   ->Add(h_jet_a2mp_ptpt,   h_jet_a2pp_ptpt,    1.0, -1.0);
  h_jet_b2mp_phiphi ->Add(h_jet_a2mp_phiphi, h_jet_a2pp_phiphi,  1.0, -1.0);
  h_jet_b2mp_etaeta ->Add(h_jet_a2mp_etaeta, h_jet_a2pp_etaeta,  1.0, -1.0);
  h_jet_b2mp_thth   ->Add(h_jet_a2mp_thth,   h_jet_a2pp_thth,    1.0, -1.0);
  h_jet_b2mp_jtjt   ->Add(h_jet_a2mp_jtjt,   h_jet_a2pp_jtjt,    1.0, -1.0);
  h_jet_b2mp_zz     ->Add(h_jet_a2mp_zz,     h_jet_a2pp_zz,      1.0, -1.0);

  printString("jet_b2s");
  h_jet_b2s_ptpt   ->Add(h_jet_b2mp_ptpt,   h_jet_b2pm_ptpt,    0.5, 0.5);
  h_jet_b2s_phiphi ->Add(h_jet_b2mp_phiphi, h_jet_b2pm_phiphi,  0.5, 0.5);
  h_jet_b2s_etaeta ->Add(h_jet_b2mp_etaeta, h_jet_b2pm_etaeta,  0.5, 0.5);
  h_jet_b2s_thth   ->Add(h_jet_b2mp_thth,   h_jet_b2pm_thth,    0.5, 0.5);
  h_jet_b2s_jtjt   ->Add(h_jet_b2mp_jtjt,   h_jet_b2pm_jtjt,    0.5, 0.5);
  h_jet_b2s_zz     ->Add(h_jet_b2mp_zz,     h_jet_b2pm_zz,      0.5, 0.5);
}


} // namespace CAP
