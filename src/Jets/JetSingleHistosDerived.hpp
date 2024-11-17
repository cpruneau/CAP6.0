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
#ifndef CAP__JetSingleHistosDerived
#define CAP__JetSingleHistosDerived
#include "JetSingleHistos.hpp"
#include "fastjet/ClusterSequence.hh"
#include "MathConstants.hpp"

using namespace fastjet;

namespace CAP
{

//!
//!Single particle histograms of particles within jets.
//!
class JetSingleHistosDerived : public JetSingleHistos
{
public:
  JetSingleHistosDerived();
  JetSingleHistosDerived(const JetSingleHistosDerived & group);
  JetSingleHistosDerived & operator=(const JetSingleHistosDerived & group);
	~JetSingleHistosDerived(){}

  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void calculateDerivedHistograms(const JetSingleHistos & jetSingleHistos);

  TH1 * h_jet_n1d_pt;
  TH1 * h_jet_n1d_phi;
  TH1 * h_jet_n1d_eta;
  TH1 * h_jet_n1d_th;
  TH1 * h_jet_n1d_jt;
  TH1 * h_jet_n1d_z;

  TH1 * h_jet_n1r_pt;
  TH1 * h_jet_n1r_phi;
  TH1 * h_jet_n1r_eta;
  TH1 * h_jet_n1r_th;
  TH1 * h_jet_n1r_jt;
  TH1 * h_jet_n1r_z;


  ClassDef(JetSingleHistosDerived,0)

};

} // namespace CAP
#endif // JetSingleHistos_HPP
