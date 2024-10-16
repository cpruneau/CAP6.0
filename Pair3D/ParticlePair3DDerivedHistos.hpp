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
  virtual void cloneAll(const ParticlePair3DDerivedHistos & group);
  virtual void importHistograms(TFile & inputFile);
  virtual void createHistograms();
  virtual void calculatePairDerivedHistograms(ParticleSingleHistos         & part1BaseHistos,
                                              ParticleSingleHistos         & part2BaseHistos,
                                              ParticleSingleDerivedHistos  & part1DerivedHistos,
                                              ParticleSingleDerivedHistos  & part2DerivedHistos,
                                              ParticlePair3DHistos     & pairHistos,
                                              double bincorrection);

  TH1 * h_n1n1_Qinv;
  TH3 * h_n1n1_DeltaP;
  TH1 * h_r2_Qinv;
  TH3 * h_r2_DeltaP;
  TH1 * h_r2_DeltaPs;
  TH1 * h_r2_DeltaPo;
  TH1 * h_r2_DeltaPl;

  ClassDef(ParticlePair3DDerivedHistos,1)

};

} // namespace CAP

#endif /* CAP__ParticlePair3DDerivedHistos */
