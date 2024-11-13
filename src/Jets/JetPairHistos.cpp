#include "JetPairHistos.hpp"
#include "JetHelpers.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::JetPairHistos);

namespace CAP
{

JetPairHistos::JetPairHistos()
:
HistogramGroup(),
h_jet_n2_pp(nullptr),
h_jet_n2_ptpt(nullptr),
h_jet_n2_phiphi(nullptr),
h_jet_n2_etaeta(nullptr),
h_jet_n2_thth(nullptr),
h_jet_n2_jtjt(nullptr),
h_jet_n2_zz(nullptr)
{
  appendClassName("JetPairHistos");
  setInstanceName("JetPairHistos");
}

JetPairHistos::JetPairHistos(const JetPairHistos & group)
:
HistogramGroup(group),
h_jet_n2_pp(nullptr),
h_jet_n2_ptpt(nullptr),
h_jet_n2_phiphi(nullptr),
h_jet_n2_etaeta(nullptr),
h_jet_n2_thth(nullptr),
h_jet_n2_jtjt(nullptr),
h_jet_n2_zz(nullptr)
{
  appendClassName("JetPairHistos");
  setInstanceName("JetPairHistos");
}

JetPairHistos & JetPairHistos::operator=(const JetPairHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    }
  return *this;
}

void JetPairHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();

  int nBins_p    = configuration.getValueInt(ptn,    "nBins_p");
  double min_p   = configuration.getValueDouble(ptn, "min_p");
  double max_p   = configuration.getValueDouble(ptn, "max_p");
  int nBins_pt   = configuration.getValueInt(ptn,    "nBins_pt");
  double min_pt  = configuration.getValueDouble(ptn, "min_pt");
  double max_pt  = configuration.getValueDouble(ptn, "max_pt");
  int nBins_phi  = configuration.getValueInt(ptn,    "nBins_phi");
  double min_phi = configuration.getValueDouble(ptn, "min_phi");
  double max_phi = configuration.getValueDouble(ptn, "max_phi");
  int nBins_eta  = configuration.getValueInt(ptn,    "nBins_eta");
  double min_eta = configuration.getValueDouble(ptn, "min_eta");
  double max_eta = configuration.getValueDouble(ptn, "max_eta");
  int nBins_jt  = configuration.getValueInt(ptn,    "nBins_jt");
  double min_jt = configuration.getValueDouble(ptn, "min_jt");
  double max_jt = configuration.getValueDouble(ptn, "max_jt");
  int nBins_th  = configuration.getValueInt(ptn,    "nBins_th");
  double min_th = configuration.getValueDouble(ptn, "min_th");
  double max_th = configuration.getValueDouble(ptn, "max_th");
  int nBins_z   = configuration.getValueInt(ptn,    "nBins_z");
  double min_z  = configuration.getValueDouble(ptn, "min_z");
  double max_z  = configuration.getValueDouble(ptn, "max_z");

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("Parent Task Name",   ptn);
    printValue("Histo Base Name",    bn);
    printValue("nBins_p",     nBins_p);
    printValue("min_p",       min_p);
    printValue("max_p",       max_p);
    printValue("nBins_pt",    nBins_pt);
    printValue("min_pt",      min_pt);
    printValue("max_pt",      max_pt);
    printValue("nBins_phi",   nBins_phi);
    printValue("min_phi",     min_phi);
    printValue("max_phi",     max_phi);
    printValue("nBins_eta",   nBins_eta);
    printValue("min_eta",     min_eta);
    printValue("max_eta",     max_eta);
    printValue("nBins_jt",    nBins_jt);
    printValue("min_jt",      min_jt);
    printValue("max_jt",      max_jt);
    printValue("nBins_th",    nBins_th);
    printValue("min_th",      min_th);
    printValue("max_th",      max_th);
    printLine();
    printCR();
    }
  h_jet_n2_pp      = createHistogram(createName(bn,"jet_n2_pp"),  nBins_p,min_p,max_p,    nBins_p,min_p,max_p,"p_{1}","p_{2}","N");
  h_jet_n2_ptpt    = createHistogram(createName(bn,"jet_n2_ptpt"),nBins_pt,min_pt,max_pt, nBins_pt,min_pt,max_pt,"p_{T,1}","p_{T,2}","N");
  h_jet_n2_phiphi  = createHistogram(createName(bn,"jet_n2_phiphi"),nBins_phi,min_phi,max_phi, nBins_phi,min_phi,max_phi,"#varphi_{1}","#varphi_{2}","N");
  h_jet_n2_etaeta  = createHistogram(createName(bn,"jet_n2_etaeta"),nBins_eta,min_eta,max_eta, nBins_eta,min_eta,max_eta,"#eta_{1}","#eta_{2}","N");
  h_jet_n2_thth    = createHistogram(createName(bn,"jet_n2_thth"),nBins_th,min_th,max_th, nBins_th,min_th,max_th,"#theta_{1}","#theta_{2}","N");
  h_jet_n2_jtjt    = createHistogram(createName(bn,"jet_n2_jtjt"),nBins_jt,min_jt,max_jt, nBins_jt,min_jt,max_jt,"j_{T,1}","j_{T,2}","N");
  h_jet_n2_zz      = createHistogram(createName(bn,"jet_n2_zz"),nBins_z,min_z,max_z, nBins_z,min_z,max_z,"z_{1}","z_{2}","N");
}

void JetPairHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  h_jet_n2_pp      = loadH2(inputFile,createName(bn,"jet_n2_pp"));
  h_jet_n2_ptpt    = loadH2(inputFile,createName(bn,"jet_n2_ptpt"));
  h_jet_n2_phiphi  = loadH2(inputFile,createName(bn,"jet_n2_phiphi"));
  h_jet_n2_etaeta  = loadH2(inputFile,createName(bn,"jet_n2_etaeta"));
  h_jet_n2_thth    = loadH2(inputFile,createName(bn,"jet_n2_thth"));
  h_jet_n2_jtjt    = loadH2(inputFile,createName(bn,"jet_n2_jtjt"));
  h_jet_n2_zz      = loadH2(inputFile,createName(bn,"jet_n2_zz"));
}

void JetPairHistos::fill(PseudoJet&  jet)
{
  double jet_px = jet.px();
  double jet_py = jet.py();
  double jet_pz = jet.pz();
  double jet_p  = sqrt(jet_px*jet_px + jet_py*jet_py + jet_pz*jet_pz);

  // Constituents of the passed Jet
  const std::vector<PseudoJet> & constituents = jet.constituents();
  for (const auto & part1 : constituents)
    {
    double part1_px  = part1.px();
    double part1_py  = part1.py();
    double part1_pz  = part1.pz();
    double part1_eta = part1.eta();
    double part1_phi = atan2(part1_py,part1_px);
    double part1_pt  = sqrt(part1_px*part1_px + part1_py*part1_py);
    double part1_p   = sqrt(part1_pt*part1_pt + part1_pz*part1_pz);
    double part1_z   = part1_p/jet_p;
    double part1_jt  = 0;
    double part1_th  = 0;
    calculateJtTheta(jet_px,jet_py,jet_pz,jet_p,part1_px,part1_py,part1_pz,part1_p,part1_jt,part1_th);
    for (const auto & part2 : constituents)
      {
      double part2_px  = part2.px();
      double part2_py  = part2.py();
      double part2_pz  = part2.pz();
      double part2_eta = part2.eta();
      double part2_phi = atan2(part2_py,part2_px);
      double part2_pt  = sqrt(part2_px*part2_px + part2_py*part2_py);
      double part2_p   = sqrt(part2_pt*part2_pt + part2_pz*part2_pz);
      double part2_z   = part2_p/jet_p;
      double part2_jt  = 0;
      double part2_th  = 0;
      calculateJtTheta(jet_px,jet_py,jet_pz,jet_p,part1_px,part2_py,part2_pz,part2_p,part2_jt,part2_th);

      h_jet_n2_pp->Fill(part1_p,part2_p);
      h_jet_n2_ptpt->Fill(part1_pt,part2_pt);
      h_jet_n2_phiphi->Fill(part1_phi,part2_phi);
      h_jet_n2_etaeta->Fill(part1_eta,part2_eta);
      h_jet_n2_thth->Fill(part1_th,part2_th);
      h_jet_n2_jtjt->Fill(part1_jt,part2_jt);
      h_jet_n2_zz->Fill(part1_z,part2_z);
    }
}
}

} // namespace CAP
