#ifndef CAP__JetPairHistos
#define CAP__JetPairHistos
#include "HistogramGroup.hpp"
#include "fastjet/ClusterSequence.hh"
#include "MathConstants.hpp"

using namespace fastjet;

namespace CAP
{


class JetPairHistos : public HistogramGroup
{
public:
  JetPairHistos();
  JetPairHistos(const JetPairHistos & group);
  JetPairHistos & operator=(const JetPairHistos & group);
  ~JetPairHistos(){}
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void fill(PseudoJet&  J);

protected:

  TH2 *h_jet_n2_ptpt;    // pt
  TH2 *h_jet_n2_phiphi;  // phi - azimuth relative to z axis
  TH2 *h_jet_n2_etaeta;  // rapidity or eta
  TH2 *h_jet_n2_thth;    // angle relative to jet axis
  TH2 *h_jet_n2_jtjt;    // particle momentum perp to jet axis.
  TH2 *h_jet_n2_zz;      // part_p/jet_p

  ClassDef(JetPairHistos,0)

};

} //  namespace CAP

#endif
