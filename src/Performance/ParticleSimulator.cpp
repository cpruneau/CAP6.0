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
#include "TRandom.h"
#include "ParticleSimulator.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticleSimulator);

namespace CAP
{

ParticleSimulator::ParticleSimulator()
:
HistogramGroup(),
filterIndex(0),
useSameSetForAll(true),
resolutionOption(0),
efficiencyOption(0),
biasPtHistogram(),
rmsPtHistogram(),
biasEtaHistogram(),
rmsEtaHistogram(),
biasPhiHistogram(),
rmsPhiHistogram(),
ptFunction(),
etaFunction(),
phiFunction()
{
  //  initialize();
}

void ParticleSimulator::setDefaultConfiguration()
{}

void ParticleSimulator::initialize()
{
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  useSameSetForAll = configuration.getValueBool(ptn,"useSameSetForAll");
  resolutionOption = configuration.getValueInt(ptn,"resolutionOption");
  efficiencyOption = configuration.getValueInt(ptn,"efficiencyOption");

  double biasAinv;
  double biasA0;
  double biasA1;
  double biasA2;
  double rmsAinv;
  double rmsA0;
  double rmsA1;
  double rmsA2;
  String baseName = "Filter";
  baseName += filterIndex;

  biasAinv = configuration.getValueDouble(ptn,baseName+"_PtBiasAinv");
  biasA0   = configuration.getValueDouble(ptn,baseName+"_PtBiasA0");
  biasA1   = configuration.getValueDouble(ptn,baseName+"_PtBiasA1");
  biasA2   = configuration.getValueDouble(ptn,baseName+"_PtBiasA2");
  rmsAinv  = configuration.getValueDouble(ptn,baseName+"_PtRmsAinv");
  rmsA0    = configuration.getValueDouble(ptn,baseName+"_PtRmsA0");
  rmsA1    = configuration.getValueDouble(ptn,baseName+"_PtRmsA1");
  rmsA2    = configuration.getValueDouble(ptn,baseName+"_PtRmsA2");

  biasAinv = configuration.getValueDouble(ptn,baseName+"_EtaBiasAinv");
  biasA0   = configuration.getValueDouble(ptn,baseName+"_EtaBiasA0");
  biasA1   = configuration.getValueDouble(ptn,baseName+"_EtaBiasA1");
  biasA2   = configuration.getValueDouble(ptn,baseName+"_EtaBiasA2");
  rmsAinv  = configuration.getValueDouble(ptn,baseName+"_EtaRmsAinv");
  rmsA0    = configuration.getValueDouble(ptn,baseName+"_EtaRmsA0");
  rmsA1    = configuration.getValueDouble(ptn,baseName+"_EtaRmsA1");
  rmsA2    = configuration.getValueDouble(ptn,baseName+"_EtaRmsA2");

  biasAinv = configuration.getValueDouble(ptn,baseName+"_PhiBiasAinv");
  biasA0   = configuration.getValueDouble(ptn,baseName+"_PhiBiasA0");
  biasA1   = configuration.getValueDouble(ptn,baseName+"_PhiBiasA1");
  biasA2   = configuration.getValueDouble(ptn,baseName+"_PhiBiasA2");
  rmsAinv  = configuration.getValueDouble(ptn,baseName+"_PhiRmsAinv");
  rmsA0    = configuration.getValueDouble(ptn,baseName+"_PhiRmsA0");
  rmsA1    = configuration.getValueDouble(ptn,baseName+"_PhiRmsA1");
  rmsA2    = configuration.getValueDouble(ptn,baseName+"_PhiRmsA2");

  double effPeakAmp = configuration.getValueDouble(ptn,baseName+"_EffPeakAmp");
  double effPeakPt  = configuration.getValueDouble(ptn,baseName+"_EffPeakPt");
  double effPeakRms = configuration.getValueDouble(ptn,baseName+"_EffPeakRms");
  double effA1      = configuration.getValueDouble(ptn,baseName+"_EffA1");
  double effA2      = configuration.getValueDouble(ptn,baseName+"_EffA2");

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printValue("useSameSetForAll",useSameSetForAll);
    printValue("resolutionOption",resolutionOption);
    printValue("efficiencyOption",efficiencyOption);
    printValue("useSameSetForAll",useSameSetForAll);
    printValue("resolutionOption",resolutionOption);
    printValue("efficiencyOption",efficiencyOption);
    printString("Pt Smearing");
    printValue("biasAinv",biasAinv);
    printValue("biasA0",biasA0);
    printValue("biasA1",biasA1);
    printValue("biasA2",biasA2);
    printValue("rmsAinv",rmsAinv);
    printValue("rmsA0",rmsA0);
    printValue("rmsA1",rmsA1);
    printValue("rmsA2",rmsA2);

    printString("eta smearer:");
    printValue("biasAinv",biasAinv);
    printValue("biasA0",biasA0);
    printValue("biasA1",biasA1);
    printValue("biasA2",biasA2);
    printValue("rmsAinv",rmsAinv);
    printValue("rmsA0",rmsA0);
    printValue("rmsA1",rmsA1);
    printValue("rmsA2",rmsA2);

    printString("phi smearer:");
    printValue("biasAinv",biasAinv);
    printValue("biasA0",biasA0);
    printValue("biasA1",biasA1);
    printValue("biasA2",biasA2);
    printValue("rmsAinv",rmsAinv);
    printValue("rmsA0",rmsA0);
    printValue("rmsA1",rmsA1);
    printValue("rmsA2",rmsA2);
    printCR();
    printString("Efficiency");
    printValue("effPeakAmp",effPeakAmp);
    printValue("effPeakPt",effPeakPt);
    printValue("effPeakRms",effPeakRms);
    printValue("effA1",effA1);
    printValue("effA2",effA2);
    }
  ptFunction  = new ResolutionFunction(0,biasAinv,biasA0,biasA1,biasA2,rmsAinv,rmsA0,rmsA1,rmsA2);
  etaFunction = new ResolutionFunction(1,biasAinv,biasA0,biasA1,biasA2,rmsAinv,rmsA0,rmsA1,rmsA2);
  phiFunction = new ResolutionFunction(0,biasAinv,biasA0,biasA1,biasA2,rmsAinv,rmsA0,rmsA1,rmsA2);
  efficiencyFunction = new EfficiencyFunction(effPeakAmp,effPeakPt,effPeakRms,effA1,effA2);
}

void ParticleSimulator::smearMomentum(const LorentzVector &in, LorentzVector & out)
{
  double smearedPt  = 0.0;
  double smearedEta = 0.0;
  double smearedPhi = 0.0;
  double pt   = in.Pt();
  double phi  = in.Phi();
  double eta  = in.Eta();
  double mass = in.M();
  smearMomentum(pt,eta,phi,smearedPt,smearedEta,smearedPhi);
  if (smearedPt<0.001) smearedPt = 0.001;
  out.SetPtEtaPhiM(smearedPt,smearedEta,smearedPhi,mass);
}

void ParticleSimulator::smearMomentum(double pt, double eta, double phi,
                                                 double &smearedPt, double &smearedEta, double &smearedPhi)
{
  double bias;
  double rms;
  double zeroRms = 0.0001;
  
  smearFromFunction(pt, eta, phi, ptFunction, bias, rms);
  smearedPt  = gRandom->Gaus(pt+bias,rms);
  smearFromFunction(pt, eta, phi, etaFunction, bias, rms);
  smearedEta = gRandom->Gaus(eta+bias,rms);
  smearFromFunction(pt, eta, phi, phiFunction, bias, rms);
  smearedPhi = gRandom->Gaus(phi+bias,rms);
}

void ParticleSimulator::smearFromHisto(double pt, double eta, double phi,
                                                  TH1 * biasHisto, TH1 * rmsHisto,
                                                  double & bias, double & rms)
{
  int bin;
  if (biasHisto->IsA() == TH1::Class())
    {
    bin = biasHisto->FindBin(pt);
    bias = biasHisto->GetBinContent(bin);
    }
  else  if (biasHisto->IsA() == TH2::Class())
    {
    bin = biasHisto->FindBin(pt,eta);
    bias = biasHisto->GetBinContent(bin);
    }
  else if (biasHisto->IsA() == TH3::Class())
    {
    bin = biasHisto->FindBin(pt,eta,phi);
    bias = biasHisto->GetBinContent(bin);
    }
  if (rmsHisto->IsA() == TH1::Class())
    {
    bin = rmsHisto->FindBin(pt);
    rms = rmsHisto->GetBinContent(bin);
    }
  else  if (rmsHisto->IsA() == TH2::Class())
    {
    bin = rmsHisto->FindBin(pt,eta);
    rms = rmsHisto->GetBinContent(bin);
    }
  else if (rmsHisto->IsA() == TH3::Class())
    {
    bin = rmsHisto->FindBin(pt,eta,phi);
    rms = rmsHisto->GetBinContent(bin);
    }
}

void ParticleSimulator::smearFromFunction(double pt, double eta, double phi,
                                                     ResolutionFunction* f,
                                                     double & bias, double & rms)
{
  bias = f->getBias(pt,eta,phi);
  rms  = f->getRms(pt,eta,phi);
}


bool ParticleSimulator::accept(const LorentzVector& momentum)
{
  bool accepting = false;
  double pt  = momentum.Pt();
  double eta = momentum.Eta();
  double phi = momentum.Phi();
  switch (efficiencyOption)
    {
      default:
      case 0:
      accepting = true;
      break;
      case 1:
      accepting = acceptFromFunction(pt, eta, phi);
      break;
      case 2:
      accepting = acceptFromHisto(pt, eta, phi);
      break;
    }
  return accepting;
}


bool ParticleSimulator::accept(double pt, double eta, double phi)
{
  bool accepting = false;
  switch (efficiencyOption)
    {
      default:
      case 0:
      accepting = true;
      break;
      case 1:
      accepting = acceptFromFunction(pt, eta, phi);
      break;
      case 2:
      accepting = acceptFromHisto(pt, eta, phi);
      break;
    }
  return accepting;
}

bool ParticleSimulator::acceptFromHisto(double pt, double eta, double phi)
{
  int bin;
  double efficiency = 1.0;
  bool   accepting  = false;
  if (efficienyHistogram->IsA() == TH1::Class())
    {
    bin = efficienyHistogram->FindBin(pt);
    efficiency = efficienyHistogram->GetBinContent(bin);
    }
  else  if (efficienyHistogram->IsA() == TH2::Class())
    {
    bin = efficienyHistogram->FindBin(pt,eta);
    efficiency = efficienyHistogram->GetBinContent(bin);
    }
  else if (efficienyHistogram->IsA() == TH3::Class())
    {
    bin = efficienyHistogram->FindBin(pt,eta,phi);
    efficiency = efficienyHistogram->GetBinContent(bin);
    }
  if (gRandom->Rndm()<efficiency) accepting = true;
  return accepting;
}

bool ParticleSimulator::acceptFromFunction(double pt, double eta, double phi)
{
  bool   accepting  = false;
  double efficiency = efficiencyFunction->getEfficiency(pt,eta,phi);
  if (gRandom->Rndm()<efficiency) accepting = true;
  return accepting;
}


} // namespace CAP
