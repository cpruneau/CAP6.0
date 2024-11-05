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
#ifndef CAP__ParticlePair3DBfHistos
#define CAP__ParticlePair3DBfHistos
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
class ParticlePair3DBfHistos : public  HistogramGroup
{
public:

  ParticlePair3DBfHistos();
  ParticlePair3DBfHistos(const ParticlePair3DBfHistos & group);
  ParticlePair3DBfHistos & operator=(const ParticlePair3DBfHistos & group);
  virtual ~ParticlePair3DBfHistos() {}
  //virtual void cloneAll(const ParticlePair3DBfHistos & group);
  virtual void importHistograms(TFile & inputFile);
  virtual void createHistograms();
  virtual void calculateBfHistograms(ParticlePair3DDerivedHistos  & pair11,
                                     ParticlePair3DDerivedHistos  & pair12,
                                     ParticlePair3DDerivedHistos  & pair21,
                                     ParticlePair3DDerivedHistos  & pair22);
  virtual void setMasses(double m1, double m2);


protected:

  int    nBins_n1;
  double min_n1;
  double max_n1;

  int    nBins_n2;
  double min_n2;
  double max_n2;

  int    nBins_pt;
  double min_pt;
  double max_pt;
  double range_pt;
  double scale_pt;

  int    nBins_phi;
  double min_phi;
  double max_phi;
  double range_phi;
  double scale_phi;

  int    nBins_eta;
  double min_eta;
  double max_eta;
  double range_eta;
  double scale_eta;

  int    nBins_y;
  double min_y;
  double max_y;
  double range_y;
  double scale_y;
  double max_yAcc;

  int    nBins_Dphi;
  double min_Dphi;
  double max_Dphi;
  double width_Dphi;

  int    nBins_Deta;
  double min_Deta;
  double max_Deta;
  int    nBins_Dy;
  double min_Dy;
  double max_Dy;

  int    nBins_Dphi_shft;
  double min_Dphi_shft;
  double max_Dphi_shft;

  bool fillEta;
  bool fillY;
  bool fillP2;

  TH2* h_A2_ptpt;
  TH2* h_B2_ptpt;
  TH2* h_C2_ptpt;
  TH2* h_R2_ptpt;

  TH2* h_A2_phiPhi;
  TH2* h_B2_phiPhi;
  TH2* h_C2_phiPhi;
  TH2* h_R2_phiPhi;

  TH2* h_A2_etaEta;
  TH2* h_B2_etaEta;
  TH2* h_C2_etaEta;
  TH2* h_R2_etaEta;

  TH2* h_A2_yY;
  TH2* h_B2_yY;
  TH2* h_C2_yY;
  TH2* h_R2_yY;

  TH2* h_A2_DetaDphi;
  TH2* h_B2_DetaDphi;
  TH2* h_C2_DetaDphi;
  TH2* h_D2_DetaDphi;
  TH2* h_R2_DetaDphi;

  TH2* h_A2_DetaDphi_shft;
  TH2* h_B2_DetaDphi_shft;
  TH2* h_C2_DetaDphi_shft;
  TH2* h_D2_DetaDphi_shft;
  TH2* h_R2_DetaDphi_shft;

  TH2* h_A2_DyDphi;
  TH2* h_B2_DyDphi;
  TH2* h_C2_DyDphi;
  TH2* h_D2_DyDphi;
  TH2* h_R2_DyDphi;

  TH2* h_A2_DyDphi_shft;
  TH2* h_B2_DyDphi_shft;
  TH2* h_C2_DyDphi_shft;
  TH2* h_D2_DyDphi_shft;
  TH2* h_R2_DyDphi_shft;

  ClassDef(ParticlePair3DBfHistos,1)

};

} // namespace CAP

#endif /* CAP__ParticlePair3DDerivedHistos */
