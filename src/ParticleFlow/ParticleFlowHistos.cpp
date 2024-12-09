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
#include "ParticleFlowHistos.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticleFlowHistos);

namespace CAP
{

ParticleFlowHistos::ParticleFlowHistos()
:
HistogramGroup(),
fillEta(0),
fillY(0),
fillP2(0),
fillPtvsY(0),
fillPid(0),
useEffCorrection(0),
efficiencyOpt(0),
nBins_n1(0),
min_n1(0),
max_n1(0),
nBins_pt(0),
min_pt(0),
max_pt(0),
scale_pt(0),
nBins_phi(0),
min_phi(0),
max_phi(0),
scale_phi(0),
nBins_eta(0),
min_eta(0),
max_eta(0),
range_eta(0),
nBins_y(0),
min_y(0),
max_y(0),
range_y(0),
h_n1(nullptr),
h_n1_eTotal(nullptr),
h_n1_pt(nullptr),
h_n1_ptXS(nullptr),
h_n1_phiEta(nullptr),
h_spt_phiEta(nullptr),
h_n1_phiY(nullptr),
h_spt_phiY(nullptr),
h_n1_ptY(nullptr),
h_pdgId(nullptr)
{
  appendClassName("ParticleFlowHistos");
  setInstanceName("Flow");
}

ParticleFlowHistos::ParticleFlowHistos(const ParticleFlowHistos & group)
:
HistogramGroup(group),
fillEta(group.fillEta ),
fillY(group.fillY ),
fillP2(group.fillP2 ),
fillPtvsY(group.fillPtvsY ),
fillPid(group.fillPid ),
useEffCorrection(group.useEffCorrection ),
efficiencyOpt(group.efficiencyOpt ),
nBins_n1(group.nBins_n1 ),
min_n1(group.min_n1 ),
max_n1(group.max_n1 ),
nBins_pt(group.nBins_pt ),
min_pt(group.min_pt ),
max_pt(group.max_pt ),
scale_pt(group.scale_pt ),
nBins_phi(group.nBins_phi ),
min_phi(group.min_phi ),
max_phi(group.max_phi ),
scale_phi(group.scale_phi ),
nBins_eta(group.nBins_eta ),
min_eta(group.min_eta ),
max_eta(group.max_eta ),
range_eta(group.range_eta ),
nBins_y(group.nBins_y ),
min_y(group.min_y ),
max_y(group.max_y ),
range_y(group.range_y),
h_n1(nullptr),
h_n1_eTotal(nullptr),
h_n1_pt(nullptr),
h_n1_ptXS(nullptr),
h_n1_phiEta(nullptr),
h_spt_phiEta(nullptr),
h_n1_phiY(nullptr),
h_spt_phiY(nullptr),
h_n1_ptY(nullptr),
h_pdgId(nullptr)
{
  cloneAll(group);
}

ParticleFlowHistos & ParticleFlowHistos::operator=(const ParticleFlowHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    fillEta   =  group.fillEta;
    fillY     =  group.fillY;
    fillP2    =  group.fillP2;
    fillPtvsY =  group.fillPtvsY;
    fillPid   =  group.fillPid;
    useEffCorrection =  group.useEffCorrection;
    efficiencyOpt    =  group.efficiencyOpt;
    nBins_n1  =  group.nBins_n1;
    min_n1    =  group.min_n1;
    max_n1    =  group.max_n1;
    nBins_pt  =  group.nBins_pt;
    min_pt    =  group.min_pt;
    max_pt    =  group.max_pt;
    scale_pt  =  group.scale_pt;
    nBins_phi =  group.nBins_phi;
    min_phi   =  group.min_phi;
    max_phi   =  group.max_phi;
    scale_phi =  group.scale_phi;
    nBins_eta =  group.nBins_eta;
    min_eta   =  group.min_eta;
    max_eta   =  group.max_eta;
    range_eta =  group.range_eta;
    nBins_y   =  group.nBins_y;
    min_y     =  group.min_y;
    max_y     =  group.max_y;
    range_y   =  group.range_y;
    cloneAll(group);
    }
  return *this;
}

void ParticleFlowHistos::cloneAll(const ParticleFlowHistos & group)
{
  // ony clone those that exist...
  if (group.h_n1)         h_n1         = (TH1*) group.h_n1->Clone();
  if (group.h_n1_eTotal)  h_n1_eTotal  = (TH1*) group.h_n1_eTotal->Clone();
  if (group.h_n1_pt)      h_n1_pt      = (TH1*) group.h_n1_pt->Clone();
  if (group.h_n1_ptXS)    h_n1_ptXS    = (TH1*) group.h_n1_ptXS->Clone();
  if (group.h_n1_phiEta)  h_n1_phiEta  = (TH2*) group.h_n1_phiEta->Clone();
  if (group.h_spt_phiEta) h_spt_phiEta = (TH2*) group.h_spt_phiEta->Clone();
  if (group.h_n1_phiY)    h_n1_phiY    = (TH2*) group.h_n1_phiY->Clone();
  if (group.h_spt_phiY)   h_spt_phiY   = (TH2*) group.h_spt_phiY->Clone();
  if (group.h_n1_ptY)     h_n1_ptY     = (TH2*) group.h_n1_ptY->Clone();
  if (group.h_pdgId)      h_pdgId      = (TH1*) group.h_pdgId->Clone();
}

// for now use the same boundaries for eta and y histogram
void ParticleFlowHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
//  printString("ParticleFlowHistos::createHistograms() -- 1 -- ");
//  printValue("bn",bn);
//  printValue("ptn",ptn);
//  printValue("ppn",ppn);
//  configuration.print();
  nBins_n1 = configuration.getValueInt(ptn,"nBins_n1");
  min_n1   = configuration.getValueDouble(ptn,"Min_n1");
  max_n1   = configuration.getValueDouble(ptn,"Max_n1");

  nBins_pt = configuration.getValueInt(ptn,"nBins_pt");
  min_pt   = configuration.getValueDouble(ptn,"Min_pt");
  max_pt   = configuration.getValueDouble(ptn,"Max_pt");
  scale_pt = max_pt - min_pt;
  
  nBins_phi = configuration.getValueInt(ptn,"nBins_phi");
  min_phi   = configuration.getValueDouble(ptn,"Min_phi");
  max_phi   = configuration.getValueDouble(ptn,"Max_phi");
  scale_phi = max_phi - min_phi;
  
  nBins_eta = configuration.getValueInt(ptn,"nBins_eta");
  min_eta   = configuration.getValueDouble(ptn,"Min_eta");
  max_eta   = configuration.getValueDouble(ptn,"Max_eta");
  range_eta = max_eta - min_eta;
  
  nBins_y = configuration.getValueInt(ptn,"nBins_y");
  min_y   = configuration.getValueDouble(ptn,"Min_y");
  max_y   = configuration.getValueDouble(ptn,"Max_y");
  range_y = max_y - min_y;
  
  fillEta   = configuration.getValueBool(ptn,"FillEta");
  fillY     = configuration.getValueBool(ptn,"FillY");
  fillP2    = configuration.getValueBool(ptn,"FillP2");
  fillPid   = configuration.getValueBool(ptn,"FillPid");
  fillPtvsY = configuration.getValueBool(ptn,"FillPtvsY");

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("Flow:Parent Task Name",   ptn);
    printValue("Flow:Parent Path Name",   ppn);
    printValue("Flow:Histo Base Name",   bn);
    printValue("Flow:FillEta",    fillEta);
    printValue("Flow:FillY",      fillY  );
    printValue("Flow:FillP2",     fillP2 );
    printValue("Flow:FillPtvsY",  fillPtvsY );
    printValue("Flow:nBins_n1",   int(nBins_n1));
    printValue("Flow:Min_n1",     min_n1);
    printValue("Flow:Max_n1",     max_n1);
    printValue("Flow:nBins_pt",   int(nBins_pt));
    printValue("Flow:Min_pt",     min_pt);
    printValue("Flow:Max_pt",     max_pt);
    printValue("Flow:scale_pt",   scale_pt);
    printValue("Flow:nBins_phi",  int(nBins_phi));
    printValue("Flow:Min_phi",    min_phi);
    printValue("Flow:Max_phi",    max_phi);
    printValue("Flow:scale_phi",  scale_phi);
    printValue("Flow:nBins_eta",  int(nBins_eta));
    printValue("Flow:Min_eta",    min_eta);
    printValue("Flow:Max_eta",    max_eta);
    printValue("Flow:range_eta",  range_eta);
    printValue("Flow:nBins_y",    int(nBins_y));
    printValue("Flow:Min_y",      min_y);
    printValue("Flow:Max_y",      max_y);
    printValue("Flow:range_y",    range_y);
    printLine();
    printCR();
    }
  h_n1         = createHistogram(createName(bn,"n1"),           nBins_n1,  min_n1,  max_n1,  "n_1","N");
  h_n1_eTotal  = createHistogram(createName(bn,"n1_eTotal"),    nBins_n1,  min_n1,  10.0*max_n1,  "n1_eTotal","N");
  h_n1_pt      = createHistogram(createName(bn,"n1_pt"),        nBins_pt,  min_pt,  max_pt,  "p_{T}","N");
  h_n1_ptXS    = createHistogram(createName(bn,"n1_ptXS"),      nBins_pt,  min_pt,  max_pt,  "p_{T}","1/p_{T} dN/p_{T}");

  if (fillEta)
    {
    h_n1_phiEta  = createHistogram(createName(bn,"n1_phiEta"),  nBins_eta, min_eta, max_eta, nBins_phi, min_phi, max_phi, "#eta", "#varphi","N");
    if (fillP2)
      {
      h_spt_phiEta  = createHistogram(createName(bn,"spt_phiEta"),  nBins_eta, min_eta, max_eta, nBins_phi, min_phi, max_phi, "#eta", "#varphi","N");
      }
    }
  if (fillY)
    {
    h_n1_phiY  = createHistogram(createName(bn,"n1_phiY"),     nBins_y,   min_y,   max_y, nBins_phi, min_phi, max_phi, "y", "#varphi","N");
    if (fillP2)
      {
      h_spt_phiY  = createHistogram(createName(bn,"spt_phiY"),  nBins_y,   min_y,   max_y, nBins_phi, min_phi, max_phi, "y", "#varphi","N");
      }
    }

  if (fillPtvsY)
    {
    h_n1_ptY  = createHistogram(createName(bn,"n1_ptY"),     nBins_y,   min_y,   max_y, nBins_pt, min_pt, max_pt, "y", "p_{T}","N");
    }


  if (fillPid)
    h_pdgId  = createHistogram(createName(bn,"n1_indexId"),  6000,  -3000.5, 2999.5, "Index", "N");

  if ( reportEnd(__FUNCTION__)) { /* noops*/ };
}

void ParticleFlowHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();

  printValue("ParticleFlowHistos::importHistograms() - bn",bn);

  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  setSeverityLevel(MessageLogger::Debug);
  if (reportDebug(__FUNCTION__))
    {
    cout << endl;
    printValue("Flow:Parent Task Name",   ptn);
    printValue("Flow:Parent Path Name",   ppn);
    printValue("Flow:Histo Base Name.",   bn);
    printValue("Flow:FillEta",            fillEta);
    printValue("Flow:FillY",              fillY  );
    printValue("Flow:FillP2",             fillP2 );
    printValue("Flow:FillPid",            fillPid );
    }

  fillEta      = configuration.getValueBool(ptn,"FillEta");
  fillY        = configuration.getValueBool(ptn,"FillY");
  fillP2       = configuration.getValueBool(ptn,"FillP2");
  fillPid      = configuration.getValueBool(ptn,"FillPid");
  fillPtvsY    = configuration.getValueBool(ptn,"FillPtvsY");

  h_n1         = importH1(inputFile,  createName(bn,"n1"));
  h_n1_eTotal  = importH1(inputFile,  createName(bn,"n1_eTotal"));
  h_n1_pt      = importH1(inputFile,  createName(bn,"n1_pt"));
  h_n1_ptXS    = importH1(inputFile,  createName(bn,"n1_ptXS"));


  if (fillEta)
    {
     h_n1_phiEta  = importH2(inputFile,createName(bn,"n1_phiEta"));
    if (fillP2)
      {
      h_spt_phiEta  = importH2(inputFile,  createName(bn,"spt_phiEta"));
      }
    }
  if (fillY)
    {

    h_n1_phiY  = importH2(inputFile,  createName(bn,"n1_phiY"));
    if (fillP2)
      {
      h_spt_phiY  = importH2(inputFile,  createName(bn,"spt_phiY"));
      }
    }
  if (fillPtvsY)
    {
    h_n1_ptY  = importH2(inputFile,  createName(bn,"n1_ptY"));
    }

  if (fillPid)
    h_pdgId  = importH1(inputFile,  createName(bn,"n1_indexId"));

  if (reportEnd(__FUNCTION__)) { /* noops*/ };
}

void ParticleFlowHistos::loadCalibration(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  useEffCorrection = true;
  efficiencyOpt    = configuration.getValueInt(ptn,"efficientOpt");
  if (reportDebug(__FUNCTION__))
    {
    cout << endl;
    printValue("Flow:Parent Task Name",   ptn);
    printValue("Flow:Parent Path Name",   ppn);
    printValue("Flow:Histo Base Name",    bn);
    printValue("Flow:useEffCorrection",   useEffCorrection);
    printValue("Flow:efficiencyOpt",      efficiencyOpt  );
    }

  switch (efficiencyOpt)
    {
      case 0: // pT dependence only
      h_eff_pt = importH1(inputFile,  createName(bn,"eff_pt"));
      break;

      case 1: // pT vs eta dependence
      h_eff_ptEta = importH2(inputFile,  createName(bn,"eff_ptEta"));
      break;

      case 2: // pT vs y dependence
      h_eff_ptY   = importH2(inputFile,  createName(bn,"eff_ptY"));
      break;

      case 3: // pT vs vs phi vs eta dependence
      h_eff_ptPhiEta = importH3(inputFile,  createName(bn,"eff_ptPhiEta"));

      case 4: // pT vs vs phi vs y dependence
      h_eff_ptPhiY = importH3(inputFile,  createName(bn,"eff_ptPhiY"));
      break;

    }
  if ( reportEnd(__FUNCTION__)) { /* noops*/ };
}

//!
//! Fiil  Flow particle histograms of this class with the particles contained in the given list.
//!
void ParticleFlowHistos::fill(Particle & particle, double weight)
{
  LorentzVector & momentum = particle.getMomentum();
  float pt   = momentum.Pt();
  float eta  = momentum.Eta();
  float phi  = momentum.Phi();
  float rapidity = momentum.Rapidity();
  if (phi<0) phi += CAP::Math::twoPi();



  h_n1_pt  ->Fill(pt,weight);
  h_n1_ptXS->Fill(pt,weight/pt);
  if (fillEta)
    {
    h_n1_phiEta->Fill(eta,phi,weight);
    if (fillP2) h_spt_phiEta->Fill(eta,phi,weight*pt);
    }
  if (fillY)
    {
    h_n1_phiY->Fill(rapidity,phi,weight);
    if (fillP2) h_spt_phiY->Fill(rapidity,phi,weight*pt);
    }
  if (fillPtvsY)
    {
    h_n1_ptY->Fill(rapidity,pt);
    }


  if (fillPid)
    {
    int pdgIndex = particle.getType().getPdgCode();
    h_pdgId->Fill(pdgIndex);
    }
}

//!
//! Fiil the global histogram for the multiplicity and the total energy of an event.
//! Call this function only once per event.
//!
void ParticleFlowHistos::fillMultiplicity(double nAccepted, double totalEnergy, double weight)
{
  h_n1->Fill(nAccepted, weight);
  h_n1_eTotal->Fill(totalEnergy, weight);
}

} // namespace CAP
