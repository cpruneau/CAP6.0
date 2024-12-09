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
#ifndef CAP__NuDynDerivedHistos
#define CAP__NuDynDerivedHistos
#include "HistogramGroup.hpp"
#include "NuDynHistos.hpp"
#include "ParticleFilter.hpp"

namespace CAP
{

class NuDynDerivedHistos : public HistogramGroup
{
public:

  NuDynDerivedHistos();
  NuDynDerivedHistos(const NuDynDerivedHistos & group);
  NuDynDerivedHistos & operator=(const NuDynDerivedHistos & group);
  virtual ~NuDynDerivedHistos() {}
  void createHistograms();
  void importHistograms(TFile & inputFile);
  virtual void calculateDerivedHistograms(NuDynHistos* baseHistos);
  void setParticleFilters(const vector<ParticleFilter*> & particleFilters);
  vector<ParticleFilter*> & getParticleFilters();
  const vector<ParticleFilter*> & getParticleFilters() const;

protected:
  void cloneAll(const NuDynDerivedHistos & group);
  vector<ParticleFilter*> particleFilters;
  vector<TH1 *> h_F2_evtClass;
  vector<TH1 *> h_R2_evtClass;
  vector<TH1 *> h_nudyn_evtClass;

  ClassDef(NuDynDerivedHistos,0)
};

} // namespace CAP

#endif /* CAP__NuDynDerivedHistos  */



