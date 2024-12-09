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
#ifndef CAP__SpherocityHistos
#define CAP__SpherocityHistos
#include "HistogramGroup.hpp"
#include "ParticleFilter.hpp"

namespace CAP
{
      
class SpherocityHistos: public HistogramGroup
{
public:
  SpherocityHistos();
  SpherocityHistos(const SpherocityHistos & group);
  SpherocityHistos & operator=(const SpherocityHistos & group);

  virtual ~SpherocityHistos() {}
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void fill(vector<double> & s0, vector<double> & s1, double weight);
  
  void cloneAll(const SpherocityHistos & group);
  void setParticleFilters(const vector<ParticleFilter*> & particleFilters);
  vector<ParticleFilter*> & getParticleFilters();
  const vector<ParticleFilter*> & getParticleFilters() const;

protected:
  bool   fillS0;
  bool   fillS1;
  bool   fillS1VsS0;
  bool   fillCorrelationHistos;
  vector<ParticleFilter*> particleFilters;
  vector<TH1 *> h_s0;
  vector<TH1 *> h_s1;
  vector<TH2 *> h_s1VsS0;
  vector<TH2 *> h_s0VsS0;
  
  ClassDef(SpherocityHistos, 1);
};

} // namespace CAP


#endif
