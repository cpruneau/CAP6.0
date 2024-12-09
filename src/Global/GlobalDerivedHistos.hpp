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
#ifndef CAP__GlobalDerivedHistos
#define CAP__GlobalDerivedHistos
#include "HistogramGroup.hpp"
#include "ParticleFilter.hpp"
#include "GlobalHistos.hpp"

namespace CAP
{

class GlobalDerivedHistos : public HistogramGroup
{
public:

  GlobalDerivedHistos();
  virtual ~GlobalDerivedHistos() {} 
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void calculateDerivedHistograms(GlobalHistos & baseHistos);

  void setParticleFilters(const vector<ParticleFilter*> & particleFilters);
  vector<ParticleFilter*> & getParticleFilters();
  const vector<ParticleFilter*> & getParticleFilters() const;


protected:

  vector<ParticleFilter*> particleFilters;

  vector<TH1*>  h_ptAvgInc;    //! Inclusive average pT vs multiplicity computed from ratio of ptSum profile average by average number of particles at given mul
  vector<TH1*>  h_ptAvgIncVsN; //! Inclusive average pT vs multiplicity computed from ratio of ptSum profile average by average number of particles at given mul

  ClassDef(GlobalDerivedHistos,0)

};

}

#endif /* CAP__GlobalDerivedHistos  */



