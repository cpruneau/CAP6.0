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
#include "JetHistosDerived.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::JetHistosDerived);

namespace CAP
{
JetHistosDerived::JetHistosDerived()
:
JetHistos(),
h_jet_R200_pt(nullptr),
h_jet_R2pp_pt(nullptr),
h_jet_R2pm_pt(nullptr),
h_jet_R2mm_pt(nullptr),
h_jet_nudyn_pt(nullptr),
h_jet_netQrms_pt(nullptr)
{
  appendClassName("JetHistos");
  setInstanceName("JetHistos");
}


JetHistosDerived::JetHistosDerived(const JetHistosDerived & group)
:
JetHistos(group),
h_jet_R200_pt(nullptr),
h_jet_R2pp_pt(nullptr),
h_jet_R2pm_pt(nullptr),
h_jet_R2mm_pt(nullptr),
h_jet_nudyn_pt(nullptr),
h_jet_netQrms_pt(nullptr)
{ }

JetHistosDerived & JetHistosDerived::operator=(const JetHistosDerived & group)
{
  if (this!=&group)
    {
      JetHistos::operator=(group);
    }
  return *this;
}


void JetHistosDerived::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  
  int nBins_jet_pt   = configuration.getValueInt(ptn,"nBins_jet_pt");
  double min_jet_pt  = configuration.getValueDouble(ptn,"min_jet_pt");
  double max_jet_pt  = configuration.getValueDouble(ptn,"max_jet_pt");
  if (reportDebug(__FUNCTION__))
  {
    printCR();
    printLine();
    printValue("Parent Task Name", ptn);
    printValue("Histo Base Name",  bn);
    printValue("nBins_jet_pt",     nBins_jet_pt);
    printValue("min_jet_pt",       min_jet_pt);
    printValue("max_jet_pt",       max_jet_pt);
    printLine();
    printCR();
  }
  
  h_jet_R200_pt    = createHistogram(createName(bn,"jet_R200_pt"),    nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p_{T} (GeV/c)","R_{2}^{00}");
  h_jet_R2pp_pt    = createHistogram(createName(bn,"jet_R2pp_pt"),    nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p_{T} (GeV/c)","R_{2}^{00}");
  h_jet_R2pm_pt    = createHistogram(createName(bn,"jet_R2pm_pt"),    nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p_{T} (GeV/c)","R_{2}^{00}");
  h_jet_R2mm_pt    = createHistogram(createName(bn,"jet_R2mm_pt"),    nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p_{T} (GeV/c)","R_{2}^{00}");
  h_jet_nudyn_pt   = createHistogram(createName(bn,"jet_nudyn_pt"),   nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p_{T} (GeV/c)","#nu_{dyn}");
  h_jet_netQrms_pt = createHistogram(createName(bn,"jet_netQrms_pt"), nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p_{T} (GeV/c)","<#Delta Q^2>");
}

void JetHistosDerived::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  
  h_jet_R200_pt    = loadH1(inputFile,createName(bn,"jet_R200_pt"));
  h_jet_R2pp_pt    = loadH1(inputFile,createName(bn,"jet_R2pp_pt"));
  h_jet_R2pm_pt    = loadH1(inputFile,createName(bn,"jet_R2pm_pt"));
  h_jet_R2mm_pt    = loadH1(inputFile,createName(bn,"jet_R2mm_pt"));
  h_jet_nudyn_pt   = loadH1(inputFile,createName(bn,"jet_nudyn_pt"));
  h_jet_netQrms_pt = loadH1(inputFile,createName(bn,"jet_netQrms_pt"));
}

void calculateR2_P1P1P1H1(const TProfile * n2_12, const TProfile * n1_1, const TProfile * n1_2, TH1 * R2_12)
{
  if (!ptrExist(__FUNCTION__,n2_12,n1_1,n1_2,R2_12))  throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n2_12,n1_1,n1_2,R2_12))  throw IncompatibleHistogramException(__FUNCTION__);
  int n_x = n2_12->GetNbinsX();
  double v_12,v_1,v_2,r2,er2;
  for (int i1=1; i1<=n_x;++i1)
  {
    v_12  = n2_12->GetBinContent(i1); //ev_12 = n2_12->GetBinError(i1);
    v_1   = n1_1->GetBinContent(i1);  //ev_1  = n1_1->GetBinError(i1);
    v_2   = n1_2->GetBinContent(i1);  //ev_2  = n1_2->GetBinError(i1);
    if (v_1>0 && v_2>0)
    {
      r2   = v_12/(v_1 * v_2) - 1.0;
      er2  = 0;
    }
    else
    {
    r2 = 0; er2 = 0;
    }
    R2_12->SetBinContent(i1,r2); R2_12->SetBinError(i1,er2);
  }
}

void calculateRms(const TH1 * valueSqVsX, const TH1 * valueVsX, TH1 * rmsVsX)
{
  int n_x = valueSqVsX->GetNbinsX();
  double vSq, v, rmsSq, rms;
  for (int i1=1; i1<=n_x;++i1)
  {
    vSq  = valueSqVsX->GetBinContent(i1);
    v    = valueVsX->GetBinContent(i1);
    rmsSq  = vSq - v*v;
    if (rms>0.0)
      rms = sqrt(rmsSq);
    else
      rms = 0.0;
    rmsVsX->SetBinContent(i1,rms); rmsVsX->SetBinError(i1,0.0);
  }
}

void JetHistosDerived::calculateDerivedHistograms(const JetHistos & baseHistos)
{
  calculateR2_P1P1P1H1(baseHistos.p_jet_n0Sq,baseHistos.p_jet_n0,baseHistos.p_jet_n0,h_jet_R200_pt);
  calculateR2_P1P1P1H1(baseHistos.p_jet_npSq,baseHistos.p_jet_np,baseHistos.p_jet_np,h_jet_R2pp_pt);
  calculateR2_P1P1P1H1(baseHistos.p_jet_nmSq,baseHistos.p_jet_nm,baseHistos.p_jet_nm,h_jet_R2mm_pt);
  calculateR2_P1P1P1H1(baseHistos.p_jet_npnm,baseHistos.p_jet_np,baseHistos.p_jet_nm,h_jet_R2pm_pt);
  calculateNudyn(h_jet_R2pp_pt,h_jet_R2pm_pt,h_jet_R2pm_pt,h_jet_R2mm_pt,h_jet_nudyn_pt);
  calculateRms(baseHistos.p_jet_netQSq,baseHistos.p_jet_netQ,h_jet_netQrms_pt);
}

} // namespace CAP
