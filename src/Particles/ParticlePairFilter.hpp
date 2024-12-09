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
#ifndef CAP__ParticlePairFilter
#define CAP__ParticlePairFilter
#include "Filter.hpp"
#include "Particle.hpp"

namespace CAP
{

//!
//! Two Particle Filter
//!
class ParticlePairFilter : public Filter<Particle>
{
public:

  //!
  //! CTOR
  //!
  ParticlePairFilter();
  virtual ~ParticlePairFilter(){}
  
  //!
  //!Accept/reject the given pair of particles
  //!
  virtual bool accept(const Particle & particle1, const Particle &  particle2);

protected:
  
  double min_dpt;
  double max_dpt;
  double min_dphi;
  double max_dphi;
  double min_deta;
  double max_deta;

  ClassDef(ParticlePairFilter,0)
};

} // namespace CAP

#endif /* CAP__ParticlePairFilter */
