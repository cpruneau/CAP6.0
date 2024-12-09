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
#ifndef CAP__PtPtHistos
#define CAP__PtPtHistos
#include "HistogramGroup.hpp"
#include "ParticleFilter.hpp"
#include "Configuration.hpp"

namespace CAP
{

class PtPtDerivedHistos;

class PtPtHistos : public HistogramGroup
{
public:

  PtPtHistos();
  PtPtHistos(const PtPtHistos & group);
  PtPtHistos & operator=(const PtPtHistos & group);
  virtual ~PtPtHistos(){ }
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void fill(double mult,
                    vector<double> & counts,
                    vector<double> & q1Sum,
                    vector<double> & q2Sum,
                    vector<double> & q3Sum,
                    vector<double> & q4Sum);
  void setParticleFilters(const vector<ParticleFilter*> & particleFilters);
  vector<ParticleFilter*> & getParticleFilters();
  const vector<ParticleFilter*> & getParticleFilters() const;

  friend PtPtDerivedHistos;

protected:
  void cloneAll(const PtPtHistos & group);

  String evtClassName;
  TH1 * h_evtClass;
  vector<TProfile*> h_f1_evtClass;
  vector<TProfile*> h_f2_evtClass;
  vector<TProfile*> h_f3_evtClass;
  vector<TProfile*> h_f4_evtClass;
  vector<TProfile*> h_Q1_evtClass;
  vector<TProfile*> h_Q1Q1_evtClass;
  vector<TProfile*> h_Q1Q1Q1_evtClass;
  vector<TProfile*> h_Q1Q1Q1Q1_evtClass;
  vector<TProfile*> h_Q2_evtClass;
  vector<TProfile*> h_Q2Q1_evtClass;
  vector<TProfile*> h_Q2Q1Q1_evtClass;
  vector<TProfile*> h_Q2Q2_evtClass;
  vector<TProfile*> h_Q3_evtClass;
  vector<TProfile*> h_Q3Q1_evtClass;
  vector<TProfile*> h_Q4_evtClass;
  vector<ParticleFilter*> particleFilters;

  ClassDef(PtPtHistos,0)
};

} // namespace CAP

#endif /* CAP__PtPtHistos  */



