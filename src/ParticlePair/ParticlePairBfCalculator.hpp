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

  bool fillEta; //!< whether to fill pseudorapidity histograms (set from configuration at initialization)
  bool fillY;   //!< whether to fill rapidity histograms (set from configuration at initialization)
  bool fillP2;  //!< whether to fill P2 and G2 related histograms  (set from configuration at initialization)

  ClassDef(ParticlePairBfCalculator,0)
};

} // namespace CAP

#endif /* CAP__ParticlePair3DCalculator */
