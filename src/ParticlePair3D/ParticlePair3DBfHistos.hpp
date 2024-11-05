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
#include "ParticlePair3DHistos.hpp"
#include "ParticlePair3DDerivedHistos.hpp"
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

  int    nBins_Qinv;
  double min_Qinv;
  double max_Qinv;
  int    nBins_DeltaPs;
  double min_DeltaPs;
  double max_DeltaPs;
  int    nBins_DeltaPo;
  double min_DeltaPo;
  double max_DeltaPo;
  int    nBins_DeltaPl;
  double min_DeltaPl;
  double max_DeltaPl;
  long   nEvents;

//  String n1n1_DeltaPs_name;
//  String n1n1_DeltaPo_name;
//  String n1n1_DeltaPl_name;
//
//  String n2_DeltaPs_name;
//  String n2_DeltaPo_name;
//  String n2_DeltaPl_name;
//  String c2_DeltaPs_name;
//  String c2_DeltaPo_name;
//  String c2_DeltaPl_name;
//  String r2_DeltaPs_name;
//  String r2_DeltaPo_name;
//  String r2_DeltaPl_name;

  TH1 * h_B12_Qinv;
  TH1 * h_B12_DeltaPs;
  TH1 * h_B12_DeltaPo;
  TH1 * h_B12_DeltaPl;

  TH1 * h_B21_Qinv;
  TH1 * h_B21_DeltaPs;
  TH1 * h_B21_DeltaPo;
  TH1 * h_B21_DeltaPl;

  TH1 * h_Bs_Qinv;
  TH1 * h_Bs_DeltaPs;
  TH1 * h_Bs_DeltaPo;
  TH1 * h_Bs_DeltaPl;

  double mass1;
  double mass2;

  ClassDef(ParticlePair3DBfHistos,1)

};

} // namespace CAP

#endif /* CAP__ParticlePair3DDerivedHistos */
