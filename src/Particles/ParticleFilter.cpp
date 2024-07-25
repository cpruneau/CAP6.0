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
//  printCR();
//  printValue("ParticleFilter::accept(const Particle & particle) Name",getName());
//  printValue("ParticleFilter::accept(const Particle & particle) getNConditions()",getNConditions());


  if (getNConditions()<1) return true;
  bool   accepting = false;
  for (auto & condition : conditions)
    {
    const String & filterType    = condition->conditionType;
    if (filterType.EqualTo("KINE"))
      {
      const String & filterSubType   = condition->conditionSubtype;
      const LorentzVector & momentum = particle.getMomentum();
      if (filterSubType.EqualTo("PT"))
        accepting = condition->accept(momentum.Pt());
      else if (filterSubType.EqualTo("ETA"))
        accepting = condition->accept(momentum.Eta());
      else if (filterSubType.EqualTo("RAPIDITY"))
        accepting = condition->accept(momentum.Rapidity());
      else if (filterSubType.EqualTo("PHI"))
        accepting = condition->accept(momentum.Phi());
      else if (filterSubType.EqualTo("P"))
        accepting = condition->accept(momentum.P());
      else if (filterSubType.EqualTo("E"))
        accepting = condition->accept(momentum.E());
      else if (filterSubType.EqualTo("PX"))
        accepting = condition->accept(momentum.Px());
      else if (filterSubType.EqualTo("PY"))
        accepting = condition->accept(momentum.Py());
      else if (filterSubType.EqualTo("PZ"))
        accepting = condition->accept(momentum.Pz());
      }
    else if (filterType.EqualTo("PDG"))
      {
      ParticleType & type = particle.getType();
      //printValue("PDG",type.getPdgCode());
      accepting = condition->accept(type.getPdgCode());
      //printValue("accepting",accepting);
      }
    else if (filterType.EqualTo("CHARGE"))
      {
      ParticleType & type = particle.getType();
      int charge = type.getCharge();
      accepting = condition->accept(charge);;
      }
    else if (filterType.EqualTo("STRANGE"))
      {
      ParticleType & type = particle.getType();
      int strangeness = type.getStrangeness();
      accepting = condition->accept(strangeness);;
      }
    else if (filterType.EqualTo("BARYON"))
      {
      ParticleType & type = particle.getType();
      int baryon = type.getBaryonNumber();
      accepting = condition->accept(baryon);
      }
    else if (filterType.EqualTo("CHARM"))
      {
      ParticleType & type = particle.getType();
      int charm = type.getCharm();
      accepting = condition->accept(charm);
      }
//    else if (filterType.EqualTo("USER"))
//      {
//      ParticleType & type = particle.getType();
//      accepting = condition->accept(type.getUserCode());
//      }
    else if (filterType.EqualTo("LIVE"))
      {
      accepting = condition->accept(particle.isLive());
      }
    else if (filterType.EqualTo("ENABLED"))
      {
      ParticleType & type = particle.getType();
      accepting = condition->accept(type.isEnabled());
      }
    if (!accepting)  return false;
    }
  return true;
}

} // namespace CAP
