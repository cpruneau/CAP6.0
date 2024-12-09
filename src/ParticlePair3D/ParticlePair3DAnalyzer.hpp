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
#ifndef CAP__ParticlePair3DAnalyzer
#define CAP__ParticlePair3DAnalyzer
#include "EventTask.hpp"
#include "ParticlePairExceptions.hpp"

namespace CAP
{

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

} // namespace CAP

#endif /* CAP__ParticlePair3DAnalyzer */
