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
#include "ResolutionFunction.hpp"
#include "EfficiencyFunction.hpp"

ClassImp(CAP::ParticleSimulator);

namespace CAP
{

ParticleSimulator::ParticleSimulator()
:
HistogramGroup(),
filterIndex(0),
useSameSetForAll(true),
resolutionOption(0),
efficiencyOption(0)
{
  //  initialize();
}

void ParticleSimulator::setDefaultConfiguration()
{

}

void ParticleSimulator::initialize()
{
  // const String & bn  = getName();
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
//  ptFunction  = new ResolutionFunction(0,biasAinv,biasA0,biasA1,biasA2,rmsAinv,rmsA0,rmsA1,rmsA2);
//  etaFunction = new ResolutionFunction(1,biasAinv,biasA0,biasA1,biasA2,rmsAinv,rmsA0,rmsA1,rmsA2);
//  phiFunction = new ResolutionFunction(0,biasAinv,biasA0,biasA1,biasA2,rmsAinv,rmsA0,rmsA1,rmsA2);
//  efficiencyFunction = new EfficiencyFunction(effPeakAmp,effPeakPt,effPeakRms,effA1,effA2);
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
  ptFunction ->smear(pt, eta, phi, smearedPt);
  etaFunction->smear(pt, eta, phi, smearedEta);
  phiFunction->smear(pt, eta, phi, smearedPhi);
}

//  smearedPt  = gRandom->Gaus(pt+bias,rms);
//  smearFromFunction(pt, eta, phi, etaFunction, bias, rms);
//  smearedEta = gRandom->Gaus(eta+bias,rms);
//  smearFromFunction(pt, eta, phi, phiFunction, bias, rms);
//  smearedPhi = gRandom->Gaus(phi+bias,rms);




bool ParticleSimulator::accept(const LorentzVector& momentum)
{
  double pt  = momentum.Pt();
  double eta = momentum.Eta();
  double phi = momentum.Phi();
  return accept(pt, eta, phi);
}


bool ParticleSimulator::accept(double pt, 
                               double eta,
                               double phi)
{
  bool accepting = true;
  return accepting;
}


} // namespace CAP
