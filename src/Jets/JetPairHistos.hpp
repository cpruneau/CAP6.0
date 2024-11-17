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
#ifndef CAP__JetPairHistos
#define CAP__JetPairHistos
#include "HistogramGroup.hpp"
#include "fastjet/ClusterSequence.hh"
#include "MathConstants.hpp"
#include "ParticleDb.hpp"

using namespace fastjet;

namespace CAP
{


class JetPairHistos : public HistogramGroup
{
public:

  friend class JetPairHistosDerived;


  JetPairHistos();
  JetPairHistos(const JetPairHistos & group);
  JetPairHistos & operator=(const JetPairHistos & group);
  ~JetPairHistos(){}
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void fill(PseudoJet&  J);
  virtual void scaleHistograms(double scale);

  void setParticleDb(ParticleDb * selectedParticleDb)
  {
  particleDb = selectedParticleDb;
  }

//protected:

  ParticleDb * particleDb;
  
  TH2 *h_jet_n2_ptpt;    // pt
  TH2 *h_jet_n2_phiphi;  // phi - azimuth relative to z axis
  TH2 *h_jet_n2_etaeta;  // rapidity or eta
  TH2 *h_jet_n2_thth;    // angle relative to jet axis
  TH2 *h_jet_n2_jtjt;    // particle momentum perp to jet axis.
  TH2 *h_jet_n2_zz;      // part_p/jet_p

  TH2 *h_jet_n2pp_ptpt;    // pt
  TH2 *h_jet_n2pp_phiphi;  // phi - azimuth relative to z axis
  TH2 *h_jet_n2pp_etaeta;  // rapidity or eta
  TH2 *h_jet_n2pp_thth;    // angle relative to jet axis
  TH2 *h_jet_n2pp_jtjt;    // particle momentum perp to jet axis.
  TH2 *h_jet_n2pp_zz;      // part_p/jet_p

  TH2 *h_jet_n2pm_ptpt;    // pt
  TH2 *h_jet_n2pm_phiphi;  // phi - azimuth relative to z axis
  TH2 *h_jet_n2pm_etaeta;  // rapidity or eta
  TH2 *h_jet_n2pm_thth;    // angle relative to jet axis
  TH2 *h_jet_n2pm_jtjt;    // particle momentum perp to jet axis.
  TH2 *h_jet_n2pm_zz;      // part_p/jet_p

  TH2 *h_jet_n2mm_ptpt;    // pt
  TH2 *h_jet_n2mm_phiphi;  // phi - azimuth relative to z axis
  TH2 *h_jet_n2mm_etaeta;  // rapidity or eta
  TH2 *h_jet_n2mm_thth;    // angle relative to jet axis
  TH2 *h_jet_n2mm_jtjt;    // particle momentum perp to jet axis.
  TH2 *h_jet_n2mm_zz;      // part_p/jet_p

  ClassDef(JetPairHistos,0)

};

} //  namespace CAP

#endif
