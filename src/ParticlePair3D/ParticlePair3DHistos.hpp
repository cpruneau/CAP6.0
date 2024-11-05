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
#ifndef CAP__ParticlePair3DHistos
#define CAP__ParticlePair3DHistos
#include "HistogramGroup.hpp"
#include "Particle.hpp"
#include "ParticleDigit.hpp"
#include "ParticlePairExceptions.hpp"


namespace CAP
{
class ParticlePair3DHistos : public HistogramGroup
{
public:

  friend class ParticlePair3DDerivedHistos;

  ParticlePair3DHistos();
  ParticlePair3DHistos(const ParticlePair3DHistos & group);
  ParticlePair3DHistos & operator=(const ParticlePair3DHistos & group);
  virtual ~ParticlePair3DHistos() {}
  virtual void createHistograms();
  virtual void fill(Particle & particle1, Particle & particle2, double weight);
  virtual void importHistograms(TFile & inputFile);

  TH1 * h_n2_Qinv;
  TH3 * h_n2_DeltaP;

  ClassDef(ParticlePair3DHistos,0)
};

} // namespace CAP

#endif /* CAP__ParticlePair3DHistos  */

