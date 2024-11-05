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
#ifndef CAP__ParticlePair3DBfCalculator
#define CAP__ParticlePair3DBfCalculator
#include "EventTask.hpp"
#include "ParticlePairExceptions.hpp"

namespace CAP
{
class ParticlePair3DBfCalculator : public EventTask
{
public:

  ParticlePair3DBfCalculator();
  ParticlePair3DBfCalculator(const ParticlePair3DBfCalculator & task);
  virtual ~ParticlePair3DBfCalculator() {}
  ParticlePair3DBfCalculator & operator=(const ParticlePair3DBfCalculator & task);
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void scaleHistograms();

protected:

  ClassDef(ParticlePair3DBfCalculator,0)
};

} // namespace CAP

#endif /* CAP__ParticlePair3DCalculator */
