#ifndef CAP__JetSingleHistos
#define CAP__JetSingleHistos
#include "HistogramGroup.hpp"
#include "fastjet/ClusterSequence.hh"
#include "MathConstants.hpp"

using namespace fastjet;

namespace CAP
{

//!
//!Single particle histograms of particles within jets.
//!
class JetSingleHistos : public HistogramGroup
{
public:
	JetSingleHistos();
  JetSingleHistos(const JetSingleHistos & group);
  JetSingleHistos & operator=(const JetSingleHistos & group);
	~JetSingleHistos(){}

  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void fill(PseudoJet&  J);
  //void Set_ClusterSequence(ClusterSequence* ptr);
  //ClusterSequence* Get_ClusterSequence();

private: 

  TH1 *h_jet_n1_p;     // momentum of jets of the selected type
  TH1 *h_jet_n1_pt;    // pt
  TH1 *h_jet_n1_phi;   // phi - azimuth relative to z axis
  TH1 *h_jet_n1_eta;   // rapidity or eta
  TH1 *h_jet_n1_th;    // angle relative to jet axis
  TH1 *h_jet_n1_jt;    // particle momentum perp to jet axis.
  TH1 *h_jet_n1_z;     // part_p/jet_p
  TH2 *h_jet_n1_etaPt; // rapidity vs pt

  ClassDef(JetSingleHistos,0)

};

} // namespace CAP
#endif // JetSingleHistos_HPP
