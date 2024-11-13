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
#ifndef CAP__ParticlePair3DDerivedHistos
#define CAP__ParticlePair3DDerivedHistos
#include "ParticleSingleHistos.hpp"
#include "ParticleSingleDerivedHistos.hpp"
#include "ParticlePair3DHistos.hpp"
#include "HistogramGroup.hpp"
#include "ParticlePairExceptions.hpp"

namespace CAP
{


//!
//! Two-Particle Correlation Function HistogramGroup
//!
class ParticlePair3DDerivedHistos : public  HistogramGroup
{
public:

  ParticlePair3DDerivedHistos();
  ParticlePair3DDerivedHistos(const ParticlePair3DDerivedHistos & group);
  ParticlePair3DDerivedHistos & operator=(const ParticlePair3DDerivedHistos & group);
  virtual ~ParticlePair3DDerivedHistos() {}
  //virtual void cloneAll(const ParticlePair3DDerivedHistos & group);
  virtual void importHistograms(TFile & inputFile);
  virtual void createHistograms();
  virtual void calculatePairDerivedHistograms(ParticleSingleHistos  & part1BaseHistos,
                                              ParticleSingleHistos  & part2BaseHistos,
                                              ParticlePair3DHistos  & partPair3DHistos);
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

  String n1n1_DeltaPs_name;
  String n1n1_DeltaPo_name;
  String n1n1_DeltaPl_name;

  String n2_DeltaPs_name;
  String n2_DeltaPo_name;
  String n2_DeltaPl_name;
  String c2_DeltaPs_name;
  String c2_DeltaPo_name;
  String c2_DeltaPl_name;
  String r2_DeltaPs_name;
  String r2_DeltaPo_name;
  String r2_DeltaPl_name;

  TH1 * h_n1n1_Qinv;
  TH3 * h_n1n1_DeltaP;
  TH1 * h_n1n1_DeltaPs;
  TH1 * h_n1n1_DeltaPo;
  TH1 * h_n1n1_DeltaPl;

  TH1 * h_n2_DeltaPs;
  TH1 * h_n2_DeltaPo;
  TH1 * h_n2_DeltaPl;

  
  TH1 * h_c2_Qinv;
  TH3 * h_c2_DeltaP;
  TH1 * h_c2_DeltaPs;
  TH1 * h_c2_DeltaPo;
  TH1 * h_c2_DeltaPl;

  
  TH1 * h_r2_Qinv;
  TH3 * h_r2_DeltaP;
  TH1 * h_r2_DeltaPs;
  TH1 * h_r2_DeltaPo;
  TH1 * h_r2_DeltaPl;

  TH1 * h_a12_Qinv;
  TH1 * h_a12_DeltaPs;
  TH1 * h_a12_DeltaPo;
  TH1 * h_a12_DeltaPl;

  TH1 * h_a21_Qinv;
  TH1 * h_a21_DeltaPs;
  TH1 * h_a21_DeltaPo;
  TH1 * h_a21_DeltaPl;


  double mass1;
  double mass2;

  ClassDef(ParticlePair3DDerivedHistos,1)

};

} // namespace CAP

#endif /* CAP__ParticlePair3DDerivedHistos */
