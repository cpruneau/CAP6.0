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
#ifndef CAP__ParticlePairBfHistos
#define CAP__ParticlePairBfHistos
#include "ParticleSingleHistos.hpp"
#include "ParticleSingleDerivedHistos.hpp"
#include "ParticlePairHistos.hpp"
#include "ParticlePairDerivedHistos.hpp"
#include "HistogramGroup.hpp"
#include "ParticlePairExceptions.hpp"

namespace CAP
{


//!
//! Two-Particle Correlation Function HistogramGroup
//!
class ParticlePairBfHistos : public  HistogramGroup
{
public:

  ParticlePairBfHistos();
  ParticlePairBfHistos(const ParticlePairBfHistos & group);
  ParticlePairBfHistos & operator=(const ParticlePairBfHistos & group);
  virtual ~ParticlePairBfHistos() {}
  //virtual void cloneAll(const ParticlePairBfHistos & group);
  virtual void importHistograms(TFile & inputFile);
  virtual void createHistograms();
  virtual void calculateBfHistograms(ParticlePairDerivedHistos  & pair11,
                                     ParticlePairDerivedHistos  & pair12,
                                     ParticlePairDerivedHistos  & pair21,
                                     ParticlePairDerivedHistos  & pair22);

protected:

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

  TH2* h_C2_CD_ptpt;
  TH2* h_C2_CI_ptpt;
  TH2* h_C2N_B12_ptpt;
  TH2* h_C2N_B21_ptpt;
  TH2* h_C2N_Bs_ptpt;
  TH2* h_R2_B12_ptpt;
  TH2* h_R2_B21_ptpt;
  TH2* h_R2_Bs_ptpt;

  TH2* h_C2_CD_phiphi;
  TH2* h_C2_CI_phiphi;
  TH2* h_C2N_B12_phiphi;
  TH2* h_C2N_B21_phiphi;
  TH2* h_C2N_Bs_phiphi;
  TH2* h_R2_B12_phiphi;
  TH2* h_R2_B21_phiphi;
  TH2* h_R2_Bs_phiphi;

  TH2* h_C2_CD_etaeta;
  TH2* h_C2_CI_etaeta;
  TH2* h_C2N_B12_etaeta;
  TH2* h_C2N_B21_etaeta;
  TH2* h_C2N_Bs_etaeta;
  TH2* h_R2_B12_etaeta;
  TH2* h_R2_B21_etaeta;
  TH2* h_R2_Bs_etaeta;

  TH2* h_C2_CD_yY;
  TH2* h_C2_CI_yY;
  TH2* h_C2N_B12_yY;
  TH2* h_C2N_B21_yY;
  TH2* h_C2N_Bs_yY;
  TH2* h_R2_B12_yY;
  TH2* h_R2_B21_yY;
  TH2* h_R2_Bs_yY;

  TH2* h_C2_CD_DetaDphi;
  TH2* h_C2_CI_DetaDphi;
  TH2* h_C2N_B12_DetaDphi;
  TH2* h_C2N_B21_DetaDphi;
  TH2* h_C2N_Bs_DetaDphi;
  TH2* h_R2_B12_DetaDphi;
  TH2* h_R2_B21_DetaDphi;
  TH2* h_R2_Bs_DetaDphi;

  TH2* h_C2_CD_DyDphi;
  TH2* h_C2_CI_DyDphi;
  TH2* h_C2N_B12_DyDphi;
  TH2* h_C2N_B21_DyDphi;
  TH2* h_C2N_Bs_DyDphi;
  TH2* h_R2_B12_DyDphi;
  TH2* h_R2_B21_DyDphi;
  TH2* h_R2_Bs_DyDphi;

  ClassDef(ParticlePairBfHistos,1)

};

} // namespace CAP

#endif /* CAP__ParticlePairDerivedHistos */
