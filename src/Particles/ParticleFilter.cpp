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
#include "ParticleFilter.hpp"
#include "Manager.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::Filter<CAP::Particle>);
ClassImp(CAP::ParticleFilter);

namespace CAP
{

ParticleFilter::ParticleFilter()
:
Filter<Particle>()
{ /* no ops */}

ParticleFilter::ParticleFilter(const ParticleFilter & source)
:
Filter<Particle>(source)
{ /* no ops */}

ParticleFilter & ParticleFilter::operator=(const ParticleFilter & source)
{
  if (this!=&source)
    {
    Filter<Particle>::operator=(source);
    }
  return *this;
}


bool ParticleFilter::accept(const Particle & particle)
{
  if (getNConditions()<1) return true;
  bool   accepting = false;
  for (auto & condition : conditions)
    {
    int filterSubType = condition->conditionSubtype;
    switch (filterSubType)
      {
        case kPt:       accepting = condition->accept(particle.getMomentum().Pt());  break;
        case kPx:       accepting = condition->accept(particle.getMomentum().Px());  break;
        case kPy:       accepting = condition->accept(particle.getMomentum().Py());  break;
        case kPz:       accepting = condition->accept(particle.getMomentum().Pz());  break;
        case kEnergy:   accepting = condition->accept(particle.getMomentum().E());   break;
        case kEta:      accepting = condition->accept(particle.getMomentum().Eta()); break;
        case kRapidity: accepting = condition->accept(particle.getMomentum().Rapidity()); break;
        case kPhi:      accepting = condition->accept(particle.getMomentum().Phi()); break;
        case kPdg:      accepting = condition->accept(particle.getType().getPdgCode()); break;
        case kCharge:   accepting = condition->accept(particle.getType().getCharge()); break;
        case kStrange:  accepting = condition->accept(particle.getType().getStrangeness()); break;
        case kBaryon:   accepting = condition->accept(particle.getType().getBaryonNumber()); break;
        case kCharm:    accepting = condition->accept(particle.getType().getCharm()); break;
        //case kBeauty:   accepting = condition->accept(particle.getType().getBeauty()); break;
        case kLive:     accepting = condition->accept(particle.isLive()); break;
        case kEnabled:  accepting = condition->accept(particle.getType().isEnabled());
      }
    if (!accepting)  return false;
    }
  return true;
}


void ParticleFilter::reset()
{

}

} // namespace CAP
