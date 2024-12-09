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
#ifndef CAP__ParticleFlowHistos
#define CAP__ParticleFlowHistos
#include "HistogramGroup.hpp"
#include "Particle.hpp"
#include "MathConstants.hpp"

namespace CAP
{

class ParticleFlowHistos : public HistogramGroup
{
public:
  ParticleFlowHistos();
  ParticleFlowHistos(const ParticleFlowHistos & group);
  ParticleFlowHistos & operator=(const ParticleFlowHistos & group);
  virtual ~ParticleFlowHistos(){ }
  virtual void cloneAll(const ParticleFlowHistos & group);
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void loadCalibration(TFile & inputFile);
  virtual void fill(Particle & particle, double weight);


  ////////////////////////////////////////////////////////////////////////////
  // Data Members - HistogramGroup
  ////////////////////////////////////////////////////////////////////////////
  bool fillEta;
  bool fillY;
  bool useEffCorrection;

  unsigned int nBins_n1;
  float        min_n1;
  float        max_n1;
  unsigned int nBins_pt;
  float        min_pt;
  float        max_pt;
  float        scale_pt;
  unsigned int nBins_phi;
  float        min_phi;
  float        max_phi;
  float        scale_phi;
  unsigned int nBins_eta;
  float        min_eta;
  float        max_eta;
  float        range_eta;
  unsigned int nBins_y;
  float        min_y;
  float        max_y;
  float        range_y;
  unsigned int nBins_phiEta;
  unsigned int nBins_phiEtaPt;
  unsigned int nBins_phiY;
  unsigned int nBins_phiYPt;
  
  //! Primary histograms

  TH1 * h_n1;
  TH1 * h_n1_eTotal;
  TH1 * h_n1_pt;
  TH1 * h_n1_ptXS;  // 1/pt dN/dptdy

  TH2 * h_n1_phiEta;
  TH2 * h_spt_phiEta;

  TH2 * h_n1_phiY;
  TH2 * h_spt_phiY;
  TH2 * h_n1_ptY;

  TH1 * h_pdgId;

  TH1 * h_eff_pt;
  TH2 * h_eff_ptEta;
  TH2 * h_eff_ptY;
  TH3 * h_eff_ptPhiEta;
  TH3 * h_eff_ptPhiY;

    ClassDef(ParticleFlowHistos,0)

};

} // namespace CAP

#endif /* CAP__ParticleFlowHistos  */



