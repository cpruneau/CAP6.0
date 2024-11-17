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
#ifndef CAP__JetSingleHistos
#define CAP__JetSingleHistos
#include "HistogramGroup.hpp"
#include "fastjet/ClusterSequence.hh"
#include "MathConstants.hpp"
#include "ParticleDb.hpp"

using namespace fastjet;

namespace CAP
{

//!
//!Single particle histograms of particles within jets.
//!
class JetSingleHistos : public HistogramGroup
{
public:

  friend class JetSingleHistosDerived;

	JetSingleHistos();
  JetSingleHistos(const JetSingleHistos & group);
  JetSingleHistos & operator=(const JetSingleHistos & group);
	~JetSingleHistos(){}

  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void fill(PseudoJet&  J);
  virtual void scaleHistograms(double value);

  void setParticleDb(ParticleDb * selectedParticleDb)
  {
  particleDb = selectedParticleDb;
  }


//private:
  ParticleDb * particleDb;

  TH1 *h_jet_n1_pt;    // pt
  TH1 *h_jet_n1_phi;   // phi - azimuth relative to z axis
  TH1 *h_jet_n1_eta;   // rapidity or eta
  TH1 *h_jet_n1_th;    // angle relative to jet axis
  TH1 *h_jet_n1_jt;    // particle momentum perp to jet axis.
  TH1 *h_jet_n1_z;     // part_p/jet_p

  TH1 *h_jet_n1p_pt;    // pt
  TH1 *h_jet_n1p_phi;   // phi - azimuth relative to z axis
  TH1 *h_jet_n1p_eta;   // rapidity or eta
  TH1 *h_jet_n1p_th;    // angle relative to jet axis
  TH1 *h_jet_n1p_jt;    // particle momentum perp to jet axis.
  TH1 *h_jet_n1p_z;     // part_p/jet_p

  TH1 *h_jet_n1m_pt;    // pt
  TH1 *h_jet_n1m_phi;   // phi - azimuth relative to z axis
  TH1 *h_jet_n1m_eta;   // rapidity or eta
  TH1 *h_jet_n1m_th;    // angle relative to jet axis
  TH1 *h_jet_n1m_jt;    // particle momentum perp to jet axis.
  TH1 *h_jet_n1m_z;     // part_p/jet_p

  
  ClassDef(JetSingleHistos,0)

};

} // namespace CAP
#endif // JetSingleHistos_HPP
