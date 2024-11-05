#ifndef CAP__JetHistos
#define CAP__JetHistos
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
class JetHistos : public HistogramGroup
{
public:
  JetHistos();
  JetHistos(const JetHistos & group);
  JetHistos & operator=(const JetHistos & group);
  ~JetHistos(){}

  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void fill(PseudoJet&  J);
  virtual void scale();

  void setParticleDb(ParticleDb * selectedParticleDb)
  {
  particleDb = selectedParticleDb;
  }

protected:

  ParticleDb * particleDb;

  //
  // jet global properties
  //
  TH1 *h_jet_mult; // number of jets of the selected type
  TH1 *h_jet_p;    // momentum of jets of the selected type
  TH1 *h_jet_pt;   // pt
  TH1 *h_jet_phi;  // phi
  TH1 *h_jet_eta;   // rapidity or eta
  TH2 *h_jet_etaPt; // rapidity vs pt
  TH1 *h_jet_n;    // multiplicity of constituent particles
  TH1 *h_jet_np;   // multiplicity of +ve constituent particles
  TH1 *h_jet_nm;   // multiplicity of -ve particles
  TH1 *h_jet_n0;   // multiplicity of neutral particles
  TH1 *h_jet_netQ; // multiplicity of neutral particles
  TProfile *p_jet_n;    // multiplicity of constituent particles vs jet p
  TProfile *p_jet_np;   // multiplicity of +ve constituent particles vs jet p
  TProfile *p_jet_nm;   // multiplicity of -ve particles vs jet p
  TProfile *p_jet_n0;   // multiplicity of neutral particles vs jet p
  TProfile *p_jet_npSq; // multiplicity of +ve constituent particles vs jet p
  TProfile *p_jet_nmSq; // multiplicity of -ve particles vs jet p
  TProfile *p_jet_n0Sq; // multiplicity of neutral particles vs jet p
  TProfile *p_jet_npnm; // multiplicity of pairs of +ve and -ve
  TProfile *p_jet_npn0; // multiplicity of pairs of +ve and 0
  TProfile *p_jet_nmn0; // multiplicity of neutral particles vs jet p
  TProfile *p_jet_netQ; // multiplicity of neutral particles vs jet p
  TProfile *p_jet_netQSq; // multiplicity of neutral particles vs jet p

  ClassDef(JetHistos,0)

};

} // namespace CAP
#endif // JetHistos_HPP
