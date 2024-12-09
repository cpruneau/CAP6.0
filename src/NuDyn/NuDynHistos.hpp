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
#ifndef CAP__NuDynHistos
#define CAP__NuDynHistos
#include "HistogramGroup.hpp"
#include "ParticleFilter.hpp"
#include "Configuration.hpp"

namespace CAP
{


//!
//! Calculate lowest moments up to order 4
//! The calculation is carried out for N distinct types (species) of particles (N distinct filters)
//!
//! Let the species be: a, b, c, etc
//! First order moments:  f_1(a), f_1(b), f_1(c), etc
//! Second order moments: f_2(a,a), f_2(a,b), f_2(a,c), .., f_2(b,b), f_2(b,c), etc
//! Third order moments: f_3(a,a,a), f_3(a,a,b), f_3(a,a,c), f(a,a,d), f(a,b,b), etc
//! Fourth order moments: f_4(a,a,a,a), f_(a,a,a,b), f_4(a,a,b,b), etc
//!
//!// ================================================================================
// Naming convention
// ================================================================================
// fk_i     : factorial moments of order "k" for particle "i" (i.e., accepted by filter 1)
// Fk_i.j  : factorial cumulants of order "k" for particles "i, .., j" (i.e., accepted by filter i.j)
// rk_i     : ratio of factorial moments of order "k" for particle "i" (i.e., accepted by filter 1)
//            to product of f1_i
//

// n1 number of particles satisfying filter 1
// n2 number of particles satisfying filter 2
// h_f1_1 = <n1>
// h_f1_2 = <n2>
// h_f2_11 = <n1(n1-1)>
// h_f2_22 = <n2(n2-1)>
// h_f2_12 = <n2(n2-1)>
// h_r2_11 = <n1(n1-1)>/<n1><n1>
// h_r2_22 = <n2(n2-1)>/<n2><n2>
// h_r2_12 = <n1(n2-1)>/<n1><n2>
// h_nudyn_12 = h_r2_11 + h_r2_22 -2*h_r2_12
// etc

class NuDynDerivedHistos;

class NuDynHistos : public HistogramGroup
{
public:

  NuDynHistos();
  NuDynHistos(const NuDynHistos & group);
  NuDynHistos & operator=(const NuDynHistos & group);
  virtual ~NuDynHistos(){ }
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void fill(double mult, vector<double> & singles);
  void setParticleFilters(const vector<ParticleFilter*> & particleFilters);
  vector<ParticleFilter*> & getParticleFilters();
  const vector<ParticleFilter*> & getParticleFilters() const;

  friend NuDynDerivedHistos;

protected:
  void cloneAll(const NuDynHistos & group);

  String evtClassName;
  TH1 * h_evtClass;
  vector<TProfile*> h_f1_evtClass;
  vector<TProfile*> h_f2_evtClass;
  vector<ParticleFilter*> particleFilters;

  ClassDef(NuDynHistos,0)
};

} // namespace CAP

#endif /* CAP__NuDynHistos  */



