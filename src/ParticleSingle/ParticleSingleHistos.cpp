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
#include "ParticleSingleHistos.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticleSingleHistos);

namespace CAP
{

ParticleSingleHistos::ParticleSingleHistos()
:
HistogramGroup(),
fillEta(0),
fillY(0),
fillP2(0),
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
h_pdgId(nullptr)
{
  appendClassName("ParticleSingleHistos");
  setInstanceName("Single");
}

ParticleSingleHistos::ParticleSingleHistos(const ParticleSingleHistos & group)
:
HistogramGroup(group),
fillEta(group.fillEta ),
fillY(group.fillY ),
fillP2(group.fillP2 ),
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
h_pdgId(nullptr)
{
  cloneAll(group);
}

ParticleSingleHistos & ParticleSingleHistos::operator=(const ParticleSingleHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    fillEta =  group.fillEta;
    fillY   =  group.fillY;
    fillP2  =  group.fillP2;
    fillPid =  group.fillPid;
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

void ParticleSingleHistos::cloneAll(const ParticleSingleHistos & group)
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
  if (group.h_pdgId)      h_pdgId      = (TH1*) group.h_pdgId->Clone();
}

// for now use the same boundaries for eta and y histogram
void ParticleSingleHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
//  printString("ParticleSingleHistos::createHistograms() -- 1 -- ");
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
  
  fillEta = configuration.getValueBool(ptn,"FillEta");
  fillY   = configuration.getValueBool(ptn,"FillY");
  fillP2  = configuration.getValueBool(ptn,"FillP2");
  fillPid = configuration.getValueBool(ptn,"FillPid");

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("Single:Parent Task Name",   ptn);
    printValue("Single:Parent Path Name",   ppn);
    printValue("Single:Histo Base Name",   bn);
    printValue("Single:FillEta",    fillEta);
    printValue("Single:FillY",      fillY  );
    printValue("Single:FillP2",     fillP2 );
    printValue("Single:nBins_n1",   int(nBins_n1));
    printValue("Single:Min_n1",     min_n1);
    printValue("Single:Max_n1",     max_n1);
    printValue("Single:nBins_pt",   int(nBins_pt));
    printValue("Single:Min_pt",     min_pt);
    printValue("Single:Max_pt",     max_pt);
    printValue("Single:scale_pt",   scale_pt);
    printValue("Single:nBins_phi",  int(nBins_phi));
    printValue("Single:Min_phi",    min_phi);
    printValue("Single:Max_phi",    max_phi);
    printValue("Single:scale_phi",  scale_phi);
    printValue("Single:nBins_eta",  int(nBins_eta));
    printValue("Single:Min_eta",    min_eta);
    printValue("Single:Max_eta",    max_eta);
    printValue("Single:range_eta",  range_eta);
    printValue("Single:nBins_y",    int(nBins_y));
    printValue("Single:Min_y",      min_y);
    printValue("Single:Max_y",      max_y);
    printValue("Single:range_y",    range_y);
    printValue("Single:FillEta",    fillEta);
    printValue("Single:FillY",      fillY);
    printValue("Single:FillP2",     fillP2);
    printValue("Single:FillPid",     fillPid);
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
  if (fillPid)
    h_pdgId  = createHistogram(createName(bn,"n1_indexId"),  6000,  -3000.5, 2999.5, "Index", "N");

  if ( reportEnd(__FUNCTION__)) { /* noops*/ };
}

void ParticleSingleHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();

  printValue("ParticleSingleHistos::importHistograms() - bn",bn);

  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  setSeverityLevel(MessageLogger::Debug);
  if (reportDebug(__FUNCTION__))
    {
    cout << endl;
    printValue("Single:Parent Task Name",   ptn);
    printValue("Single:Parent Path Name",   ppn);
    printValue("Single:Histo Base Name.",   bn);
    printValue("Single:FillEta",            fillEta);
    printValue("Single:FillY",              fillY  );
    printValue("Single:FillP2",             fillP2 );
    printValue("Single:FillPid",            fillPid );
    }

  fillEta      = configuration.getValueBool(ptn,"FillEta");
  fillY        = configuration.getValueBool(ptn,"FillY");
  fillP2       = configuration.getValueBool(ptn,"FillP2");
  fillPid      = configuration.getValueBool(ptn,"FillPid");
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
  if (fillPid)
    h_pdgId  = importH1(inputFile,  createName(bn,"n1_indexId"));

  if (reportEnd(__FUNCTION__)) { /* noops*/ };
}

void ParticleSingleHistos::loadCalibration(TFile & inputFile)
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
    printValue("Single:Parent Task Name",   ptn);
    printValue("Single:Parent Path Name",   ppn);
    printValue("Single:Histo Base Name",    bn);
    printValue("Single:useEffCorrection",   useEffCorrection);
    printValue("Single:efficiencyOpt",      efficiencyOpt  );
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
//! Fiil  single particle histograms of this class with the particles contained in the given list.
//!
void ParticleSingleHistos::fill(vector<ParticleDigit*> & particles, double weight)
{
  double nSingles      = 0;
  double nSinglesEta   = 0;
  double nSinglesY     = 0;
  double totalEnergy   = 0;
  for (auto & particle : particles)
    {
    float        e    = particle->e;
    float        pt   = particle->pt;
    float        eta  = particle->eta;
    float        phi  = particle->phi;
    float        y    = particle->y;
    unsigned int iPt  = particle->iPt;
    unsigned int iPhi = particle->iPhi;
    unsigned int iEta = particle->iEta;
    unsigned int iY   = particle->iY;

    if (useEffCorrection)
      {
      int k = 0;
      double eff = 0.0;
      switch (efficiencyOpt)
        {
          case 0:
          k = h_eff_pt->FindBin(pt);
          eff = h_eff_pt->GetBinContent(k);
          break;

          case 1:
          k = h_eff_ptEta->FindBin(eta,pt);
          eff = h_eff_ptEta->GetBinContent(k);
          break;

          case 2:
          k = h_eff_ptY->FindBin(y,pt);
          eff = h_eff_ptY->GetBinContent(k);
          break;

          case 3:
          k = h_eff_ptPhiEta->FindBin(eta,phi,pt);
          eff = h_eff_ptPhiEta->GetBinContent(k);
          break;

          case 4:
          k = h_eff_ptPhiY->FindBin(y,phi,pt);
          eff = h_eff_ptPhiY->GetBinContent(k);
          break;
        }
      if (eff>0) weight /= eff;
      }

    nSingles++;
    totalEnergy += e;

    int iG = h_n1_pt->GetBin(iPt);
    h_n1_pt  ->AddBinContent(iG,weight);
    h_n1_ptXS->AddBinContent(iG,weight/pt);

    if (fillEta)
      {
      iG = h_n1_phiEta->GetBin(iEta,iPhi);
      if (iG<=0)
        {
        cout << "iG:" << iG << endl;
        }
      nSinglesEta++;
      h_n1_phiEta->AddBinContent(iG,weight);
      if (fillP2) h_spt_phiEta->AddBinContent(iG,weight*pt);
      }

    if (fillY)
      {
      iG = h_n1_phiY->GetBin(iY,iPhi);
      if (iG<=0)
        {
        cout << "iG:" << iG << endl;
        }
      nSinglesY++;
      h_n1_phiY->AddBinContent(iG,weight);
      if (fillP2) h_spt_phiY->AddBinContent(iG,weight*pt);
      }
    }
  h_n1_pt->SetEntries(h_n1_pt->GetEntries()+nSingles);
  h_n1_ptXS->SetEntries(h_n1_ptXS->GetEntries()+nSingles);
  if (fillEta)
    {
    h_n1_phiEta->SetEntries(h_n1_phiEta->GetEntries()+nSinglesEta);
    if (fillP2) h_spt_phiEta->SetEntries(h_spt_phiEta->GetEntries()+nSinglesEta);
    }
  if (fillY)
    {
    h_n1_phiY->SetEntries(h_n1_phiY->GetEntries()+nSinglesY);
    if (fillP2) h_spt_phiY->SetEntries(h_spt_phiY->GetEntries()+nSinglesY);
    }
  h_n1->Fill(nSingles, weight);
  h_n1_eTotal->Fill(totalEnergy, weight);
}

//!
//! Fiil  single particle histograms of this class with the particles contained in the given list.
//!
void ParticleSingleHistos::fill(Particle & particle, double weight)
{
  LorentzVector & momentum = particle.getMomentum();
  float pt   = momentum.Pt();
  float eta  = momentum.Eta();
  float phi  = momentum.Phi();
  float rapidity = momentum.Rapidity();
  if (phi<0) phi += CAP::Math::twoPi();

//  if (useEffCorrection)
//    {
//    int k = 0;
//    double eff = 0.0;
//    switch (efficiencyOpt)
//      {
//        case 0:
//        k = h_eff_pt->FindBin(pt);
//        eff = h_eff_pt->GetBinContent(k);
//        break;
//
//        case 1:
//        k = h_eff_ptEta->FindBin(eta,pt);
//        eff = h_eff_ptEta->GetBinContent(k);
//        break;
//
//        case 2:
//        k = h_eff_ptY->FindBin(rapidity,pt);
//        eff = h_eff_ptY->GetBinContent(k);
//        break;
//
//        case 3:
//        k = h_eff_ptPhiEta->FindBin(eta,phi,pt);
//        eff = h_eff_ptPhiEta->GetBinContent(k);
//        break;
//
//        case 4:
//        k = h_eff_ptPhiY->FindBin(rapidity,phi,pt);
//        eff = h_eff_ptPhiY->GetBinContent(k);
//        break;
//      }
//    if (eff>0) weight /= eff;
//    }

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
void ParticleSingleHistos::fillMultiplicity(double nAccepted, double totalEnergy, double weight)
{
  h_n1->Fill(nAccepted, weight);
  h_n1_eTotal->Fill(totalEnergy, weight);
}

} // namespace CAP
