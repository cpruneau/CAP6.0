/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Akash Raj
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau, Akash Raj,  Nov 2024
 *
 * *********************************************************************/
#ifndef CAP__JetHistosDerived
#define CAP__JetHistosDerived
#include "JetHistos.hpp"
#include "fastjet/ClusterSequence.hh"
#include "MathConstants.hpp"
#include "ParticleDb.hpp"

using namespace fastjet;

namespace CAP
{

//!
//!Single particle histograms of particles within jets.
//!
class JetHistosDerived : public JetHistos
{
public:
  JetHistosDerived();
  JetHistosDerived(const JetHistosDerived & group);
  JetHistosDerived & operator=(const JetHistosDerived & group);
  ~JetHistosDerived(){}

  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void calculateDerivedHistograms(const JetHistos & baseHistos);

//protected:

  TH1 *h_jet_R200_pt;
  TH1 *h_jet_R2pp_pt;
  TH1 *h_jet_R2pm_pt;
  TH1 *h_jet_R2mm_pt;
  TH1 *h_jet_nudyn_pt;
  TH1 *h_jet_netQrms_pt;


  ClassDef(JetHistos,0)

};

} // namespace CAP
#endif // JetHistos_HPP
