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
#ifndef CAP__ParticlePairDerivedHistos
#define CAP__ParticlePairDerivedHistos
#include "ParticleSingleHistos.hpp"
#include "ParticleSingleDerivedHistos.hpp"
#include "ParticlePairHistos.hpp"
#include "HistogramGroup.hpp"
#include "ParticlePairExceptions.hpp"

namespace CAP
{


//!
//! Two-Particle Correlation Function HistogramGroup
//!
class ParticlePairDerivedHistos : public  HistogramGroup
{
public:

  ParticlePairDerivedHistos();
  ParticlePairDerivedHistos(const ParticlePairDerivedHistos & group);
  ParticlePairDerivedHistos & operator=(const ParticlePairDerivedHistos & group);
  virtual ~ParticlePairDerivedHistos() {}
  virtual void cloneAll(const ParticlePairDerivedHistos & group);
  virtual void importHistograms(TFile & inputFile);
  virtual void createHistograms();
  virtual void calculatePairDerivedHistograms(ParticleSingleHistos         & part1BaseHistos,
                                              ParticleSingleHistos         & part2BaseHistos,
                                              ParticleSingleDerivedHistos  & part1DerivedHistos,
                                              ParticleSingleDerivedHistos  & part2DerivedHistos,
                                              ParticlePairHistos     & pairHistos,
                                              double bincorrection);

  void calculateOmegaFactor(TH2 * h_DyDphi, vector<double> & omegaFactor);
  void calculateAverageYbar(TH2 * h_DyDphi, TH2 * h_DyDphi_Avg, vector<double> & omegaFactor);

  int nBins_n2, nBins_pt, nBins_phi, nBins_eta, nBins_y, nBins_Deta, nBins_Dy, nBins_Dphi,nBins_Dphi_shft;
  double min_n2,  max_n2;
  double min_pt,  max_pt;
  double min_phi, max_phi;
  double min_eta, max_eta;
  double min_y, max_y;
  double min_Dphi, max_Dphi;
  double min_Deta, max_Deta;
  double min_Dy, max_Dy;
  double min_Dphi_shft, max_Dphi_shft;
  double max_yAcc;
  
  double scale_pt;
  double scale_phi;
  double scale_eta;
  double scale_y;
  double width_Dphi;

  bool fillEta;
  bool fillY;
  bool fillP2;

  TH2* h_n1n1_ptpt;
  TH2* h_C2_ptpt;
  TH2* h_C2N_ptpt;
  TH2* h_R2_ptpt;

  TH2* h_n1n1_phiphi;
  TH2* h_C2_phiphi;
  TH2* h_C2N_phiphi;
  TH2* h_R2_phiphi;
  TH2* h_P2_phiphi;
  TH2* h_G2_phiphi;
  TH2* h_DptDpt_phiphi;
  TH2* h_pt1pt1_phiphi;

  TH2* h_n1n1_etaeta;
  TH2* h_C2_etaeta;
  TH2* h_C2N_etaeta;
  TH2* h_R2_etaeta;
  TH2* h_G2_etaeta;
  TH2* h_P2_etaeta;
  TH2* h_DptDpt_etaeta;
  TH2* h_pt1pt1_etaeta;

  TH2* h_n1n1_yY;
  TH2* h_C2_yY;
  TH2* h_C2N_yY;
  TH2* h_R2_yY;
  TH2* h_G2_yY;
  TH2* h_P2_yY;
  TH2* h_DptDpt_yY;
  TH2* h_pt1pt1_yY;

  TH2* h_n1n1_DetaDphi;
  TH2* h_C2_DetaDphi;
  TH2* h_C2N_DetaDphi;
  TH2* h_C2O_DetaDphi;
  TH2* h_R2_DetaDphi;
  TH2* h_P2_DetaDphi;
  TH2* h_G2_DetaDphi;
  TH2* h_DptDpt_DetaDphi;
  TH2* h_pt1pt1_DetaDphi;

  TH2* h_n1n1_DetaDphi_shft;
  TH2* h_C2_DetaDphi_shft;
  TH2* h_C2N_DetaDphi_shft;
  TH2* h_C2O_DetaDphi_shft;
  TH2* h_R2_DetaDphi_shft;
  TH2* h_P2_DetaDphi_shft;
  TH2* h_G2_DetaDphi_shft;
  TH2* h_DptDpt_DetaDphi_shft;

  TH2* h_n1n1_DyDphi;
  TH2* h_C2_DyDphi;
  TH2* h_C2N_DyDphi;
  TH2* h_C2O_DyDphi;
  TH2* h_R2_DyDphi;
  TH2* h_P2_DyDphi;
  TH2* h_G2_DyDphi;
  TH2* h_DptDpt_DyDphi;
  TH2* h_pt1pt1_DyDphi;

  TH2* h_n1n1_DyDphi_shft;
  TH2* h_C2_DyDphi_shft;
  TH2* h_C2N_DyDphi_shft;
  TH2* h_C2O_DyDphi_shft;
  TH2* h_R2_DyDphi_shft;
  TH2* h_P2_DyDphi_shft;
  TH2* h_G2_DyDphi_shft;
  TH2* h_DptDpt_DyDphi_shft;
  
  ClassDef(ParticlePairDerivedHistos,1)

};

} // namespace CAP

#endif /* CAP__ParticlePairDerivedHistos */
