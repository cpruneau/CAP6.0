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
#include "JetSingleHistosDerived.hpp"
#include "JetHelpers.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::JetSingleHistosDerived);

namespace CAP
{

JetSingleHistosDerived::JetSingleHistosDerived()
:
JetSingleHistos(),
h_jet_n1d_pt(nullptr), // differences
h_jet_n1d_phi(nullptr),
h_jet_n1d_eta(nullptr),
h_jet_n1d_th(nullptr),
h_jet_n1d_jt(nullptr),
h_jet_n1d_z(nullptr),
h_jet_n1r_pt(nullptr), // ratios
h_jet_n1r_phi(nullptr),
h_jet_n1r_eta(nullptr),
h_jet_n1r_th(nullptr),
h_jet_n1r_jt(nullptr),
h_jet_n1r_z(nullptr)
{
  appendClassName("JetSingleHistos");
  setInstanceName("JetSingleHistos");
}

JetSingleHistosDerived::JetSingleHistosDerived(const JetSingleHistosDerived & group)
:
JetSingleHistos(group),
h_jet_n1d_pt(nullptr),
h_jet_n1d_phi(nullptr),
h_jet_n1d_eta(nullptr),
h_jet_n1d_th(nullptr),
h_jet_n1d_jt(nullptr),
h_jet_n1d_z(nullptr),
h_jet_n1r_pt(nullptr), // ratios
h_jet_n1r_phi(nullptr),
h_jet_n1r_eta(nullptr),
h_jet_n1r_th(nullptr),
h_jet_n1r_jt(nullptr),
h_jet_n1r_z(nullptr)
{
  appendClassName("JetSingleHistos");
  setInstanceName("JetSingleHistos");
}

JetSingleHistosDerived & JetSingleHistosDerived::operator=(const JetSingleHistosDerived & group)
{
  if (this!=&group)
  {
    JetSingleHistos::operator=(group);
  }
  return *this;
}

void JetSingleHistosDerived::createHistograms()
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
  int nBins_jt   = configuration.getValueInt(ptn,    "nBins_jt");
  double min_jt  = configuration.getValueDouble(ptn, "min_jt");
  double max_jt  = configuration.getValueDouble(ptn, "max_jt");
  int nBins_th   = configuration.getValueInt(ptn,    "nBins_th");
  double min_th  = configuration.getValueDouble(ptn, "min_th");
  double max_th  = configuration.getValueDouble(ptn, "max_th");
  int nBins_z    = configuration.getValueInt(ptn,    "nBins_z");
  double min_z   = configuration.getValueDouble(ptn, "min_z");
  double max_z   = configuration.getValueDouble(ptn, "max_z");
  
  
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
    printValue("nBins_z",     nBins_z);
    printValue("min_z",       min_z);
    printValue("max_z",       max_z);
    
    printLine();
    printCR();
  }
  // difference (+)-(-)
  h_jet_n1d_pt    = createHistogram(createName(bn,"jet_n1d_pt"),    nBins_pt,    min_pt,    max_pt,     "pt","N_1^{+}-N_1^{+}");
  h_jet_n1d_phi   = createHistogram(createName(bn,"jet_n1d_phi"),   nBins_phi,   min_phi,   max_phi,    "phi","N_1^{+}-N_1^{+}");
  h_jet_n1d_eta   = createHistogram(createName(bn,"jet_n1d_eta"),   nBins_eta,   min_eta,   max_eta,    "#eta","N_1^{+}-N_1^{+}");
  h_jet_n1d_th    = createHistogram(createName(bn,"jet_n1d_th"),    nBins_th,    min_th,    max_th,     "#theta","N_1^{+}-N_1^{+}");
  h_jet_n1d_jt    = createHistogram(createName(bn,"jet_n1d_jt"),    nBins_jt,    min_jt,    max_jt,     "j_{t}","N_1^{+}-N_1^{+}");
  h_jet_n1d_z     = createHistogram(createName(bn,"jet_n1d_z"),     nBins_z,     min_z,     max_z,      "p_{t}","N_1^{+}-N_1^{+}");

  // ratios (+)/(-)
  h_jet_n1r_pt    = createHistogram(createName(bn,"jet_n1r_pt"),    nBins_pt,    min_pt,    max_pt,     "pt","N_1^{+}/N_1^{+}");
  h_jet_n1r_phi   = createHistogram(createName(bn,"jet_n1r_phi"),   nBins_phi,   min_phi,   max_phi,    "phi","N_1^{+}/N_1^{+}");
  h_jet_n1r_eta   = createHistogram(createName(bn,"jet_n1r_eta"),   nBins_eta,   min_eta,   max_eta,    "#eta","N_1^{+}/N_1^{+}");
  h_jet_n1r_th    = createHistogram(createName(bn,"jet_n1r_th"),    nBins_th,    min_th,    max_th,     "#theta","N_1^{+}/N_1^{+}");
  h_jet_n1r_jt    = createHistogram(createName(bn,"jet_n1r_jt"),    nBins_jt,    min_jt,    max_jt,     "j_{t}","N_1^{+}/N_1^{+}");
  h_jet_n1r_z     = createHistogram(createName(bn,"jet_n1r_z"),     nBins_z,     min_z,     max_z,      "p_{t}","N_1^{+}/N_1^{+}");

}

void JetSingleHistosDerived::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  h_jet_n1d_pt    = loadH1(inputFile,createName(bn,"jet_n1d_pt"));
  h_jet_n1d_phi   = loadH1(inputFile,createName(bn,"jet_n1d_phi"));
  h_jet_n1d_eta   = loadH1(inputFile,createName(bn,"jet_n1d_eta"));
  h_jet_n1d_th    = loadH1(inputFile,createName(bn,"jet_n1d_th"));
  h_jet_n1d_jt    = loadH1(inputFile,createName(bn,"jet_n1d_jt"));
  h_jet_n1d_z     = loadH1(inputFile,createName(bn,"jet_n1d_z"));

  h_jet_n1r_pt    = loadH1(inputFile,createName(bn,"jet_n1r_pt"));
  h_jet_n1r_phi   = loadH1(inputFile,createName(bn,"jet_n1r_phi"));
  h_jet_n1r_eta   = loadH1(inputFile,createName(bn,"jet_n1r_eta"));
  h_jet_n1r_th    = loadH1(inputFile,createName(bn,"jet_n1r_th"));
  h_jet_n1r_jt    = loadH1(inputFile,createName(bn,"jet_n1r_jt"));
  h_jet_n1r_z     = loadH1(inputFile,createName(bn,"jet_n1r_z"));

}

void JetSingleHistosDerived::calculateDerivedHistograms(const JetSingleHistos & s)
{
  h_jet_n1d_pt   ->Add(s.h_jet_n1p_pt,   s.h_jet_n1m_pt, 1.0, -10.0);
  h_jet_n1d_phi  ->Add(s.h_jet_n1p_phi,  s.h_jet_n1m_phi,1.0, -10.0);
  h_jet_n1d_eta  ->Add(s.h_jet_n1p_eta,  s.h_jet_n1m_eta,1.0, -10.0);
  h_jet_n1d_th   ->Add(s.h_jet_n1p_th,   s.h_jet_n1m_th, 1.0, -10.0);
  h_jet_n1d_jt   ->Add(s.h_jet_n1p_jt,   s.h_jet_n1m_jt, 1.0, -10.0);
  h_jet_n1d_z    ->Add(s.h_jet_n1p_z,    s.h_jet_n1m_z,  1.0, -10.0);

  // ratios (+)/(-)
  h_jet_n1r_pt  ->Add(s.h_jet_n1p_pt);  h_jet_n1r_pt  ->Divide(s.h_jet_n1m_pt);
  h_jet_n1r_phi ->Add(s.h_jet_n1p_phi); h_jet_n1r_phi ->Divide(s.h_jet_n1m_phi);
  h_jet_n1r_eta ->Add(s.h_jet_n1p_eta); h_jet_n1r_eta ->Divide(s.h_jet_n1m_eta);
  h_jet_n1r_th  ->Add(s.h_jet_n1p_th);  h_jet_n1r_th  ->Divide(s.h_jet_n1m_th);
  h_jet_n1r_jt  ->Add(s.h_jet_n1p_jt);  h_jet_n1r_jt  ->Divide(s.h_jet_n1m_jt);
  h_jet_n1r_z   ->Add(s.h_jet_n1p_z);   h_jet_n1r_z   ->Divide(s.h_jet_n1m_z);
}


} // namespace CAP





