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
#include "JetSingleHistos.hpp"
#include "JetHelpers.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::JetSingleHistos);

namespace CAP
{

JetSingleHistos::JetSingleHistos()
:
HistogramGroup(),
particleDb(nullptr),
h_jet_n1_pt(nullptr),
h_jet_n1_phi(nullptr),
h_jet_n1_eta(nullptr),
h_jet_n1_th(nullptr),
h_jet_n1_jt(nullptr),
h_jet_n1_z(nullptr),

h_jet_n1p_pt(nullptr),
h_jet_n1p_phi(nullptr),
h_jet_n1p_eta(nullptr),
h_jet_n1p_th(nullptr),
h_jet_n1p_jt(nullptr),
h_jet_n1p_z(nullptr),

h_jet_n1m_pt(nullptr),
h_jet_n1m_phi(nullptr),
h_jet_n1m_eta(nullptr),
h_jet_n1m_th(nullptr),
h_jet_n1m_jt(nullptr),
h_jet_n1m_z(nullptr)
{
  appendClassName("JetSingleHistos");
  setInstanceName("JetSingleHistos");
}

JetSingleHistos::JetSingleHistos(const JetSingleHistos & group)
:
HistogramGroup(group),
particleDb(nullptr),
h_jet_n1_pt(nullptr),
h_jet_n1_phi(nullptr),
h_jet_n1_eta(nullptr),
h_jet_n1_th(nullptr),
h_jet_n1_jt(nullptr),
h_jet_n1_z(nullptr),

h_jet_n1p_pt(nullptr),
h_jet_n1p_phi(nullptr),
h_jet_n1p_eta(nullptr),
h_jet_n1p_th(nullptr),
h_jet_n1p_jt(nullptr),
h_jet_n1p_z(nullptr),

h_jet_n1m_pt(nullptr),
h_jet_n1m_phi(nullptr),
h_jet_n1m_eta(nullptr),
h_jet_n1m_th(nullptr),
h_jet_n1m_jt(nullptr),
h_jet_n1m_z(nullptr)
{
  appendClassName("JetSingleHistos");
  setInstanceName("JetSingleHistos");
}

JetSingleHistos & JetSingleHistos::operator=(const JetSingleHistos & group)
{
  if (this!=&group)
  {
    HistogramGroup::operator=(group);
    particleDb = group.particleDb;
  }
  return *this;
}

void JetSingleHistos::createHistograms()
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
  h_jet_n1_pt    = createHistogram(createName(bn,"jet_n1_pt"),    nBins_pt,    min_pt,    max_pt,     "pt","N_1");
  h_jet_n1_phi   = createHistogram(createName(bn,"jet_n1_phi"),   nBins_phi,   min_phi,   max_phi,    "phi","N_1");
  h_jet_n1_eta   = createHistogram(createName(bn,"jet_n1_eta"),   nBins_eta,   min_eta,   max_eta,    "#eta","N_1");
  h_jet_n1_th    = createHistogram(createName(bn,"jet_n1_th"),    nBins_th,    min_th,    max_th,     "#theta","N_1");
  h_jet_n1_jt    = createHistogram(createName(bn,"jet_n1_jt"),    nBins_jt,    min_jt,    max_jt,     "j_{t}","N_1");
  h_jet_n1_z     = createHistogram(createName(bn,"jet_n1_z"),     nBins_z,     min_z,     max_z,      "p_{t}","N_1");
  
  h_jet_n1p_pt    = createHistogram(createName(bn,"jet_n1p_pt"),    nBins_pt,    min_pt,    max_pt,     "pt","N_1^{+}");
  h_jet_n1p_phi   = createHistogram(createName(bn,"jet_n1p_phi"),   nBins_phi,   min_phi,   max_phi,    "phi","N_1^{+}");
  h_jet_n1p_eta   = createHistogram(createName(bn,"jet_n1p_eta"),   nBins_eta,   min_eta,   max_eta,    "#eta","N_1^{+}");
  h_jet_n1p_th    = createHistogram(createName(bn,"jet_n1p_th"),    nBins_th,    min_th,    max_th,     "#theta","N_1^{+}");
  h_jet_n1p_jt    = createHistogram(createName(bn,"jet_n1p_jt"),    nBins_jt,    min_jt,    max_jt,     "j_{t}","N_1^{+}");
  h_jet_n1p_z     = createHistogram(createName(bn,"jet_n1p_z"),     nBins_z,     min_z,     max_z,      "p_{t}","N_1^{+}");
  
  h_jet_n1m_pt    = createHistogram(createName(bn,"jet_n1m_pt"),    nBins_pt,    min_pt,    max_pt,     "pt","N_1^{-}");
  h_jet_n1m_phi   = createHistogram(createName(bn,"jet_n1m_phi"),   nBins_phi,   min_phi,   max_phi,    "phi","N_1^{-}");
  h_jet_n1m_eta   = createHistogram(createName(bn,"jet_n1m_eta"),   nBins_eta,   min_eta,   max_eta,    "#eta","N_1^{-}");
  h_jet_n1m_th    = createHistogram(createName(bn,"jet_n1m_th"),    nBins_th,    min_th,    max_th,     "#theta","N_1^{-}");
  h_jet_n1m_jt    = createHistogram(createName(bn,"jet_n1m_jt"),    nBins_jt,    min_jt,    max_jt,     "j_{t}","N_1^{-}");
  h_jet_n1m_z     = createHistogram(createName(bn,"jet_n1m_z"),     nBins_z,     min_z,     max_z,      "p_{t}","N_1^{-}");
  
  
}

void JetSingleHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  h_jet_n1_pt    = loadH1(inputFile,createName(bn,"jet_n1_pt"));
  h_jet_n1_phi   = loadH1(inputFile,createName(bn,"jet_n1_phi"));
  h_jet_n1_eta   = loadH1(inputFile,createName(bn,"jet_n1_eta"));
  h_jet_n1_th    = loadH1(inputFile,createName(bn,"jet_n1_th"));
  h_jet_n1_jt    = loadH1(inputFile,createName(bn,"jet_n1_jt"));
  h_jet_n1_z     = loadH1(inputFile,createName(bn,"jet_n1_z"));
  
  h_jet_n1p_pt    = loadH1(inputFile,createName(bn,"jet_n1p_pt"));
  h_jet_n1p_phi   = loadH1(inputFile,createName(bn,"jet_n1p_phi"));
  h_jet_n1p_eta   = loadH1(inputFile,createName(bn,"jet_n1p_eta"));
  h_jet_n1p_th    = loadH1(inputFile,createName(bn,"jet_n1p_th"));
  h_jet_n1p_jt    = loadH1(inputFile,createName(bn,"jet_n1p_jt"));
  h_jet_n1p_z     = loadH1(inputFile,createName(bn,"jet_n1p_z"));
  
  h_jet_n1m_pt    = loadH1(inputFile,createName(bn,"jet_n1m_pt"));
  h_jet_n1m_phi   = loadH1(inputFile,createName(bn,"jet_n1m_phi"));
  h_jet_n1m_eta   = loadH1(inputFile,createName(bn,"jet_n1m_eta"));
  h_jet_n1m_th    = loadH1(inputFile,createName(bn,"jet_n1m_th"));
  h_jet_n1m_jt    = loadH1(inputFile,createName(bn,"jet_n1m_jt"));
  h_jet_n1m_z     = loadH1(inputFile,createName(bn,"jet_n1m_z"));
}

void JetSingleHistos::fill(PseudoJet&  jet)
{
  double jet_phi = jet.phi();
  double jet_pt  = jet.perp();
  double jet_eta = jet.pseudorapidity();
  
  // Constituents of the passed Jet
  const std::vector<PseudoJet> & constituents = jet.constituents();
  for (const auto & part : constituents)
  {
    int pdgId = part.user_index();
    ParticleType * type = particleDb->findPdgCode(pdgId);
    double q = type->getCharge();
    
    double part_phi = part.phi();
    double part_pt  = part.perp();
    double part_eta = part.pseudorapidity();
    
    double part_z   = part_pt/jet_pt;
    double part_jt  = 0;
    double part_th  = 0;
    //calculateJtTheta(jet_px,jet_py,jet_pz,jet_p,part_px,part_py,part_pz,part_p,part_jt,part_th);
    h_jet_n1_pt->Fill(part_pt);
    h_jet_n1_phi->Fill(part_phi);
    h_jet_n1_eta->Fill(part_eta);
    h_jet_n1_th->Fill(part_th);
    h_jet_n1_jt->Fill(part_jt);
    h_jet_n1_z->Fill(part_z);
    
    if (q>0)
    {
      h_jet_n1p_pt->Fill(part_pt);
      h_jet_n1p_phi->Fill(part_phi);
      h_jet_n1p_eta->Fill(part_eta);
      h_jet_n1p_th->Fill(part_th);
      h_jet_n1p_jt->Fill(part_jt);
      h_jet_n1p_z->Fill(part_z);
    }
    else
    {
      h_jet_n1m_pt->Fill(part_pt);
      h_jet_n1m_phi->Fill(part_phi);
      h_jet_n1m_eta->Fill(part_eta);
      h_jet_n1m_th->Fill(part_th);
      h_jet_n1m_jt->Fill(part_jt);
      h_jet_n1m_z->Fill(part_z);
    }
  }
}

void JetSingleHistos::scaleHistograms(double value)
{
  h_jet_n1_pt->Scale(value);
  h_jet_n1_phi->Scale(value);
  h_jet_n1_eta->Scale(value);
  h_jet_n1_th->Scale(value);
  h_jet_n1_jt->Scale(value);
  h_jet_n1_z->Scale(value);
  
  h_jet_n1p_pt->Scale(value);
  h_jet_n1p_phi->Scale(value);
  h_jet_n1p_eta->Scale(value);
  h_jet_n1p_th->Scale(value);
  h_jet_n1p_jt->Scale(value);
  h_jet_n1p_z->Scale(value);
  
  h_jet_n1m_pt->Scale(value);
  h_jet_n1m_phi->Scale(value);
  h_jet_n1m_eta->Scale(value);
  h_jet_n1m_th->Scale(value);
  h_jet_n1m_jt->Scale(value);
  h_jet_n1m_z->Scale(value);
}

} // namespace CAP





