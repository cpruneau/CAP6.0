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
#ifndef CAP__ParticlePairBfCalculator
#define CAP__ParticlePairBfCalculator
#include "EventTask.hpp"
#include "ParticlePairExceptions.hpp"

namespace CAP
{
class ParticlePairBfCalculator : public EventTask
{
public:

  ParticlePairBfCalculator();
  ParticlePairBfCalculator(const ParticlePairBfCalculator & task);
  virtual ~ParticlePairBfCalculator() {}
  ParticlePairBfCalculator & operator=(const ParticlePairBfCalculator & task);
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void scaleHistograms();

protected:

  ClassDef(ParticlePairBfCalculator,0)
};

} // namespace CAP

#endif /* CAP__ParticlePair3DCalculator */