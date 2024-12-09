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
#ifndef CAP__ParticleFlowAnalyzer
#define CAP__ParticleFlowAnalyzer
#include "EventTask.hpp"

namespace CAP
{

class ParticleFlowAnalyzer : public EventTask
{
public:
  
  ParticleFlowAnalyzer();
  ParticleFlowAnalyzer(const ParticleFlowAnalyzer & analyzer);
  ParticleFlowAnalyzer & operator=(const ParticleFlowAnalyzer & analyzer);
  virtual ~ParticleFlowAnalyzer() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void scaleHistograms();

protected:
  
  ClassDef(ParticleFlowAnalyzer,0)
};

} // namespace CAP

#endif /* CAP__ParticleFlowAnalyzer */
