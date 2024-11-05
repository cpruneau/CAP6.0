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
#ifndef CAP__ParticlePairHistos
#define CAP__ParticlePairHistos
#include "HistogramGroup.hpp"
#include "Particle.hpp"
#include "ParticleDigit.hpp"
#include "ParticlePairExceptions.hpp"


namespace CAP
{

class ParticlePairHistos : public HistogramGroup
{
public:

  friend class ParticlePairDerivedHistos;

  ParticlePairHistos();
  ParticlePairHistos(const ParticlePairHistos & group);
  ParticlePairHistos & operator=(const ParticlePairHistos & group);
  virtual ~ParticlePairHistos() {}

  virtual void cloneAll(const ParticlePairHistos & group);

  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  //virtual void fill(vector<ParticleDigit*> & particle1, vector<ParticleDigit*> & particle2, bool same, double weight);
  virtual void fill(Particle & particle1, Particle & particle2, double weight);

  inline int getPtBinFor(float v) const
  {
  int index = 0; // indicates a value out of bounds
  if (v<min_pt || v>=max_pt) return index;
  index = 1+int(scale_pt*(v-min_pt));
  return index;
  }

  inline int getPhiBinFor(float v) const
  {
  int index = 0; // indicates a value out of bounds
  if (v<min_phi || v>=max_phi) return index;
  index = 1+int(scale_phi*(v-min_phi));
  return index;
  }

  inline int getEtaBinFor(float v) const
  {
  int index = 0; // indicates a value out of bounds
  if (v<min_eta || v>=max_eta) return index;
  index = 1+int(scale_eta*(v-min_eta));
  return index;
  }

  inline int getYBinFor(float v) const
  {
  int index = 0; // indicates a value out of bounds
  if (v<min_y || v>=max_y) return index;
  index = 1+int(scale_y*(v-min_y));
  return index;
  }

protected:

  int nBins_n2, nBins_pt, nBins_phi, nBins_eta, nBins_y;
  double min_n2,  max_n2;
  double min_pt,  max_pt;
  double min_phi, max_phi;
  double min_eta, max_eta;
  double min_y, max_y;
  double scale_pt;
  double scale_phi;
  double scale_eta;
  double scale_y;
  double width_Dphi;


  bool fillEta;
  bool fillY;
  bool fillP2;

  TH1 * h_n2;
  TH2 * h_n2_ptpt;

  TH2 * h_n2_etaeta;
  TH2 * h_DptDpt_etaeta;

  TH2 * h_n2_phiphi;
  TH2 * h_DptDpt_phiphi;
  
  TH2 * h_n2_yY;
  TH2 * h_DptDpt_yY;

  TH2* h_n2_DetaDphi;
  TH2* h_DptDpt_DetaDphi;

  TH2* h_n2_DyDphi;
  TH2* h_DptDpt_DyDphi;

  ClassDef(ParticlePairHistos,0)
};

} // namespace CAP

#endif /* CAP__ParticlePairHistos  */
