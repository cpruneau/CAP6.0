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
#ifndef CAP__ParticlePair3DAnalyzer
#define CAP__ParticlePair3DAnalyzer
#include "EventTask.hpp"
#include "ParticlePairExceptions.hpp"

class ParticlePair3DAnalyzer : public EventTask
{
public:

  ParticlePair3DAnalyzer();
  ParticlePair3DAnalyzer(const ParticlePair3DAnalyzer & task);
  ParticlePair3DAnalyzer & operator=(const ParticlePair3DAnalyzer & task);
  virtual ~ParticlePair3DAnalyzer() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void scaleHistograms();

protected:

   ClassDef(ParticlePair3DAnalyzer,0)
};


#endif /* CAP__ParticlePair3DAnalyzer */
