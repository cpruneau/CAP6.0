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
#ifndef CAP__EfficiencyFilter
#define CAP__EfficiencyFilter
#include "ParticleFilter.hpp"

namespace CAP
{

class EfficiencyFilter : public ParticleFilter
{
public:
  enum EfficiencyFilterType   { kEffNone, kEffVsPt, kEffVsPtEta };

  EfficiencyFilter();
  EfficiencyFilter(const EfficiencyFilter & otherFilter);
  EfficiencyFilter & operator=(const EfficiencyFilter & otherFilter);
  virtual ~EfficiencyFilter() {}
  virtual bool accept(const Particle & particle);
  void setFilterType(EfficiencyFilterType type);
  void setEffHisto(TH1 * effHisto);
  EfficiencyFilterType getFilterType() const;

protected:

  bool efficiencyAccept(const LorentzVector & momentum);

  EfficiencyFilterType efficiencyFilterType;
  TH1 * efficiencyHisto;

  ClassDef(EfficiencyFilter,0)
};

}

#endif /* CAP__EfficiencyFilter */

