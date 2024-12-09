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
#ifndef CAP__ParticlePair3DCalculator
#define CAP__ParticlePair3DCalculator
#include "EventTask.hpp"
#include "ParticlePairExceptions.hpp"

namespace CAP
{

class ParticlePair3DCalculator : public EventTask
{
public:

  ParticlePair3DCalculator();
  ParticlePair3DCalculator(const ParticlePair3DCalculator & task);
  virtual ~ParticlePair3DCalculator() {}
  ParticlePair3DCalculator & operator=(const ParticlePair3DCalculator & task);
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void scaleHistograms();

  virtual int getPidFor(ParticleFilter* pf);
  virtual double getMassFor(ParticleFilter* pf);

protected:

  ClassDef(ParticlePair3DCalculator,0)
};

} // namespace CAP

#endif /* CAP__ParticlePair3DCalculator */
