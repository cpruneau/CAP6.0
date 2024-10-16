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
#ifndef CAP__PtPtDerivedHistos
#define CAP__PtPtDerivedHistos
#include "HistogramGroup.hpp"
#include "PtPtHistos.hpp"
#include "ParticleFilter.hpp"

namespace CAP
{

class PtPtDerivedHistos : public HistogramGroup
{
public:

  PtPtDerivedHistos();
  PtPtDerivedHistos(const PtPtDerivedHistos & group);
  PtPtDerivedHistos & operator=(const PtPtDerivedHistos & group);
  virtual ~PtPtDerivedHistos() {}
  void createHistograms();
  void importHistograms(TFile & inputFile);
  virtual void calculateDerivedHistograms(PtPtHistos* baseHistos);
  void setParticleFilters(const vector<ParticleFilter*> & particleFilters);
  vector<ParticleFilter*> & getParticleFilters();
  const vector<ParticleFilter*> & getParticleFilters() const;

protected:
  void cloneAll(const PtPtDerivedHistos & group);
  vector<TH1*> h_F1_evtClass;
  vector<TH1*> h_F2_evtClass;
  vector<TH1*> h_F3_evtClass;
  vector<TH1*> h_F4_evtClass;
  vector<TH1*> h_R2_evtClass;
  vector<TH1*> h_R3_evtClass;
  vector<TH1*> h_R4_evtClass;

  vector<TH1*> h_q1_evtClass;
  vector<TH1*> h_q1q1_evtClass;
  vector<TH1*> h_q1q1q1_evtClass;
  vector<TH1*> h_q1q1q1q1_evtClass;
  vector<TH1*> h_dq1dq1_evtClass;
  vector<TH1*> h_dq1dq1dq1_evtClass;
  vector<TH1*> h_dq1dq1dq1dq1_evtClass;
  
  vector<ParticleFilter*> particleFilters;
  ClassDef(PtPtDerivedHistos,0)
};

} // namespace CAP

#endif /* CAP__PtPtDerivedHistos  */



