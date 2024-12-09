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
#ifndef CAP__ParticlePerformanceHistos
#define CAP__ParticlePerformanceHistos
#include "HistogramGroup.hpp"
#include "Particle.hpp"
#include "Configuration.hpp"

namespace CAP
{


class ParticlePerformanceHistos : public HistogramGroup
{
public:
  
  ParticlePerformanceHistos();
  virtual ~ParticlePerformanceHistos() {}
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void fill(Particle & particle, double weight);
  
  
protected:

  TH1 * h_n1_dpt;
  TH1 * h_n1_deta;
  TH1 * h_n1_dphi;
  TH1 * h_n1_dy;

  TProfile * p_n1_dptVsPt;
  TProfile * p_n1_dptVsEta;
  TProfile * p_n1_detaVsPt;
  TProfile * p_n1_detaVsEta;
  TProfile * p_n1_dyVsPt;
  TProfile * p_n1_dyVsEta;
  TProfile * p_n1_dphiVsPt;
  TProfile * p_n1_dphiVsEta;

  ClassDef(ParticlePerformanceHistos,0)

};

} // namespace CAP

#endif /* CAP__ParticlePerformanceHistos  */



