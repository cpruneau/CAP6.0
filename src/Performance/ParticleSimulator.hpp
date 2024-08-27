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
#ifndef CAP__ParticlePerformanceSimulator
#define CAP__ParticlePerformanceSimulator
#include "HistogramGroup.hpp"

namespace CAP
{

class EfficiencyFunction;
class ResolutionFunction;
//!
//!Smears the momentum of particles  based on user defined configuration parameters provided at construction
//!of instances of this class.
//!
//!This class assumes the particles detected are either charged electrons, muons, pions, kaons, or protons (or either
//!positive or negative charge). The following (arbitrary) identifiers are used internally to select which histograms or
//!functions are used to compute resolution parameters (bias and rms) of particles. Subclass this class to add
//!particle types as needed. 
//!
//!
class ParticleSimulator : public HistogramGroup
{
public:
  
  ParticleSimulator();
  virtual ~ParticleSimulator(){}
  virtual void setDefaultConfiguration();
  virtual void initialize();
  virtual void smearMomentum(const LorentzVector &in, LorentzVector & out);
  virtual void smearMomentum(double pt, double eta, double phi,
                             double &smearedPt, double &smearedEta, double &smearedPhi);
//  virtual void smearFromHisto(double pt, double eta, double phi,
//                              TH1 * biasHisto, TH1 * rmsHisto,
//                              double & bias, double & rms);
//  virtual void smearFromFunction(double pt, double eta, double phi,
//                                 ResolutionFunction* f,
//                                 double & bias, double & rms);
  
  bool accept(const LorentzVector& momentum);
  bool accept(double pt, double eta, double phi);
  
  
protected:
  
  int  filterIndex;
  bool useSameSetForAll;
  int  resolutionOption;
  int  efficiencyOption;
  
//  TH1 *biasPtHistogram;
//  TH1 *rmsPtHistogram;
//  TH1 *biasEtaHistogram;
//  TH1 *rmsEtaHistogram;
//  TH1 *biasPhiHistogram;
//  TH1 *rmsPhiHistogram;
//  TH1 *efficienyHistogram;
  
  
  ResolutionFunction* ptFunction;
  ResolutionFunction* etaFunction;
  ResolutionFunction* phiFunction;
  EfficiencyFunction* efficiencyFunction;
  
  ClassDef(ParticleSimulator,0)
};

} // namespace CAP

#endif /* CAP__ParticlePerformanceSimulator */
