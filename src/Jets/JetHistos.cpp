#include "JetHistos.hpp"
#include "JetHelpers.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "ParticleType.hpp"

ClassImp(CAP::JetHistos);

namespace CAP
{
JetHistos::JetHistos()
:
HistogramGroup(),
h_jet_mult(nullptr),
h_jet_pt(nullptr),
h_jet_eta(nullptr),
h_jet_etaPt(nullptr),
h_jet_n(nullptr),
h_jet_np(nullptr),
h_jet_nm(nullptr),
h_jet_n0(nullptr),
h_jet_netQ(nullptr),
p_jet_n(nullptr),
p_jet_np(nullptr),
p_jet_nm(nullptr),
p_jet_n0(nullptr),
p_jet_npSq(nullptr),
p_jet_nmSq(nullptr),
p_jet_n0Sq(nullptr),
p_jet_npnm(nullptr),
p_jet_npn0(nullptr),
p_jet_nmn0(nullptr),
p_jet_netQ(nullptr),
p_jet_netQSq(nullptr)
{
  appendClassName("JetHistos");
  setInstanceName("JetHistos");
}


JetHistos::JetHistos(const JetHistos & group)
:
HistogramGroup(group),
h_jet_mult(nullptr),
h_jet_pt(nullptr),
h_jet_eta(nullptr),
h_jet_etaPt(nullptr),
h_jet_n(nullptr),
h_jet_np(nullptr),
h_jet_nm(nullptr),
h_jet_n0(nullptr),
h_jet_netQ(nullptr),
p_jet_n(nullptr),
p_jet_np(nullptr),
p_jet_nm(nullptr),
p_jet_n0(nullptr),
p_jet_npSq(nullptr),
p_jet_nmSq(nullptr),
p_jet_n0Sq(nullptr),
p_jet_npnm(nullptr),
p_jet_npn0(nullptr),
p_jet_nmn0(nullptr),
p_jet_netQ(nullptr),
p_jet_netQSq(nullptr)
{ }

JetHistos & JetHistos::operator=(const JetHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    }
  return *this;
}


void JetHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();

  int nBins_jet_n1   = configuration.getValueInt(ptn,"nBins_jet_n1");
  double min_jet_n1  = configuration.getValueDouble(ptn,"min_jet_n1");
  double max_jet_n1  = configuration.getValueDouble(ptn,"max_jet_n1");
  int nBins_jet_p    = configuration.getValueInt(ptn,"nBins_jet_p");
  double min_jet_p   = configuration.getValueDouble(ptn,"min_jet_p");
  double max_jet_p   = configuration.getValueDouble(ptn,"max_jet_p");
  int nBins_jet_pt   = configuration.getValueInt(ptn,"nBins_jet_pt");
  double min_jet_pt  = configuration.getValueDouble(ptn,"min_jet_pt");
  double max_jet_pt  = configuration.getValueDouble(ptn,"max_jet_pt");
  int nBins_jet_phi  = configuration.getValueInt(ptn,"nBins_jet_phi");
  double min_jet_phi = configuration.getValueDouble(ptn,"min_jet_phi");
  double max_jet_phi = configuration.getValueDouble(ptn,"max_jet_phi");
  int nBins_jet_eta  = configuration.getValueInt(ptn,"nBins_jet_eta");
  double min_jet_eta = configuration.getValueDouble(ptn,"min_jet_eta");
  double max_jet_eta = configuration.getValueDouble(ptn,"max_jet_eta");
  int nBins_jet_netQ = configuration.getValueInt(ptn,"nBins_jet_netQ");
  double min_jet_netQ = configuration.getValueDouble(ptn,"min_jet_netQ");
  double max_jet_netQ = configuration.getValueDouble(ptn,"max_jet_netQ");

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("Parent Task Name",   ptn);
    printValue("Histo Base Name",    bn);
    printValue("nBins_jet_n1",   nBins_jet_n1);
    printValue("min_jet_n1",     min_jet_n1);
    printValue("max_jet_n1",     max_jet_n1);
    printValue("nBins_jet_p",    nBins_jet_p);
    printValue("min_jet_p",      min_jet_p);
    printValue("max_jet_p",      max_jet_p);
    printValue("nBins_jet_pt",   nBins_jet_pt);
    printValue("min_jet_pt",     min_jet_pt);
    printValue("max_jet_pt",     max_jet_pt);
    printValue("nBins_jet_phi",  nBins_jet_phi);
    printValue("min_jet_phi",    min_jet_phi);
    printValue("max_jet_phi",    max_jet_phi);
    printValue("nBins_jet_eta",  nBins_jet_eta);
    printValue("min_jet_eta",    min_jet_eta);
    printValue("max_jet_eta",    max_jet_eta);
    printValue("nBins_jet_eta",  nBins_jet_eta);
    printValue("min_jet_eta",    min_jet_eta);
    printValue("max_jet_eta",    max_jet_eta);
    printValue("nBins_jet_netQ", nBins_jet_netQ);
    printValue("min_jet_netQ",   min_jet_netQ);
    printValue("max_jet_netQ",   max_jet_netQ);
    printLine();
    printCR();
    }

  h_jet_mult   = createHistogram(createName(bn,"jet_mult"),   1,  0.0,  2.0,  "mult","N");
  h_jet_pt     = createHistogram(createName(bn,"jet_pt"),     nBins_jet_pt, min_jet_pt, max_jet_pt,  "pt (GeV/c)","N");
  h_jet_phi    = createHistogram(createName(bn,"jet_phi"),    nBins_jet_phi,min_jet_phi,max_jet_phi, "#varphi","N");
  h_jet_eta    = createHistogram(createName(bn,"jet_eta"),    nBins_jet_eta,min_jet_eta,max_jet_eta, "#eta","N");
  h_jet_etaPt  = createHistogram(createName(bn,"jet_etaPt"),  nBins_jet_eta,min_jet_eta,max_jet_eta, nBins_jet_pt, min_jet_pt, max_jet_pt,"rapidity", "p (GeV/c)","N");
  h_jet_n      = createHistogram(createName(bn,"jet_n"),      nBins_jet_n1, min_jet_n1, max_jet_n1,  "n_{part}","N");
  h_jet_np     = createHistogram(createName(bn,"jet_np"),     nBins_jet_n1, min_jet_n1, max_jet_n1,  "n_{+}","N");
  h_jet_nm     = createHistogram(createName(bn,"jet_nm"),     nBins_jet_n1, min_jet_n1, max_jet_n1,  "n_{-}","N");
  h_jet_n0     = createHistogram(createName(bn,"jet_n0"),     nBins_jet_n1, min_jet_n1, max_jet_n1,  "n_{0}","N");
  h_jet_netQ   = createHistogram(createName(bn,"jet_netQ"),   nBins_jet_n1, min_jet_netQ, min_jet_netQ,  "Q","N");
  p_jet_n      = createProfile(createName(bn,"jet_n_p"),      nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<n_{part}>");
  p_jet_np     = createProfile(createName(bn,"jet_np_p"),     nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<n_{+}>");
  p_jet_nm     = createProfile(createName(bn,"jet_nm_p"),     nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<n_{-}>");
  p_jet_n0     = createProfile(createName(bn,"jet_n0_p"),     nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<n_{0}>");
  p_jet_npSq   = createProfile(createName(bn,"jet_npSq_p"),   nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<n_{+}(n_{+}-1)>");
  p_jet_nmSq   = createProfile(createName(bn,"jet_nmSq_p"),   nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<n_{-}(n_{-}-1)>");
  p_jet_n0Sq   = createProfile(createName(bn,"jet_n0Sq_p"),   nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<n_{0}(n_{0}-1)>");
  p_jet_npnm   = createProfile(createName(bn,"jet_npnm_p"),   nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<n_{p}n_{m}>");
  p_jet_npn0   = createProfile(createName(bn,"jet_npn0_p"),   nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<n_{p}n_{0}>");
  p_jet_nmn0   = createProfile(createName(bn,"jet_nmn0_p"),   nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<n_{m}n_{0}>");
  p_jet_netQ   = createProfile(createName(bn,"jet_netQ_p"),   nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<Q>");
  p_jet_netQSq = createProfile(createName(bn,"jet_netQSq_p"), nBins_jet_pt,  min_jet_pt,  max_jet_pt,   "p (GeV/c)","<Q^2>");
}

void JetHistos::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
  h_jet_mult   = loadH1(inputFile,createName(bn,"jet_mult"));
  h_jet_pt     = loadH1(inputFile,createName(bn,"jet_pt"));
  h_jet_phi    = loadH1(inputFile,createName(bn,"jet_phi"));
  h_jet_eta    = loadH1(inputFile,createName(bn,"jet_eta"));
  h_jet_etaPt  = loadH2(inputFile,createName(bn,"jet_etaPt"));
  h_jet_n      = loadH1(inputFile,createName(bn,"jet_n"));
  h_jet_np     = loadH1(inputFile,createName(bn,"jet_np"));
  h_jet_nm     = loadH1(inputFile,createName(bn,"jet_nm"));
  h_jet_n0     = loadH1(inputFile,createName(bn,"jet_n0"));
  h_jet_netQ   = loadH1(inputFile,createName(bn,"jet_netQ"));
  p_jet_n      = loadProfile(inputFile,createName(bn,"jet_n_p"));
  p_jet_np     = loadProfile(inputFile,createName(bn,"jet_np_p"));
  p_jet_nm     = loadProfile(inputFile,createName(bn,"jet_nm_p"));
  p_jet_n0     = loadProfile(inputFile,createName(bn,"jet_n0_p"));
  p_jet_npSq   = loadProfile(inputFile,createName(bn,"jet_npSq_p"));
  p_jet_nmSq   = loadProfile(inputFile,createName(bn,"jet_nmSq_p"));
  p_jet_n0Sq   = loadProfile(inputFile,createName(bn,"jet_n0Sq_p"));
  p_jet_npnm   = loadProfile(inputFile,createName(bn,"jet_npnm_p"));
  p_jet_npn0   = loadProfile(inputFile,createName(bn,"jet_npn0_p"));
  p_jet_nmn0   = loadProfile(inputFile,createName(bn,"jet_nmn0_p"));
  p_jet_netQ   = loadProfile(inputFile,createName(bn,"jet_netQ_p"));
  p_jet_netQSq = loadProfile(inputFile,createName(bn,"jet_netQSq_p"));
}

void JetHistos::fill(PseudoJet& jet)
{
  double jet_phi = jet.phi();
  double jet_pt  = jet.perp();
  double jet_eta = jet.pseudorapidity();

//  printCR();
//  printLine();
//  printValue("jet_pt",jet_pt);
//  printValue("jet_phi",jet_phi);
//  printValue("jet_eta",jet_eta);

  h_jet_mult->Fill(1.0);
  h_jet_pt->Fill(jet_pt);
  h_jet_phi->Fill(jet_phi);
  h_jet_eta->Fill(jet_eta);
  h_jet_etaPt->Fill(jet_eta, jet_pt);

  double n  = 0;
  double np = 0;
  double nm = 0;
  double n0 = 0;
  double netQ = 0;
  double q;
  int pdgId;

  // Constituents of the passed Jet
  vector<PseudoJet> constituents = jet.constituents();
  n = jet.constituents().size();
  for (const auto & constituent : constituents)
    {
    pdgId = constituent.user_index();
    ParticleType * type = particleDb->findPdgCode(pdgId);
    q = type->getCharge();
    netQ += q;
    if (q>0) np += 1.0;
    else if (q<0) nm += 1.0;
    else n0 += 1.0;
    }

  h_jet_n->Fill(n);
  h_jet_np->Fill(np);
  h_jet_nm->Fill(nm);
  h_jet_n0->Fill(n0);
  h_jet_netQ->Fill(netQ);
  p_jet_n->Fill(jet_pt,n);
  p_jet_np->Fill(jet_pt,np);
  p_jet_nm->Fill(jet_pt,nm);
  p_jet_n0->Fill(jet_pt,n0);
  p_jet_npSq->Fill(jet_pt,np*(np-1.0));
  p_jet_nmSq->Fill(jet_pt,nm*(nm-1.0));
  p_jet_n0Sq->Fill(jet_pt,n0*(n0-1.0));
  p_jet_npnm->Fill(jet_pt,np*nm);
  p_jet_npn0->Fill(jet_pt,nm*n0);
  p_jet_nmn0->Fill(jet_pt,nm*n0);
  p_jet_netQ->Fill(jet_pt,netQ);
  p_jet_netQSq->Fill(jet_pt,netQ*netQ);

//  printValue("jet_n",n);
//  printValue("jet_np",np);
//  printValue("jet_nm",nm);
//  printValue("jet_n0",n0);
//  printValue("np*(np-1.0)",np*(np-1.0));
//  printValue("nm*(nm-1.0)",nm*(nm-1.0));
//  printValue("n0*(n0-1.0)",n0*(n0-1.0));
//  printValue("nm*np",nm*np);
//  printValue("netQ",netQ);
//  printValue("netQSq",netQ*netQ);

}

void JetHistos::scale()
{
  double counts = h_jet_mult->GetBinContent(1);
  if (counts>0)
    {
    double scale = 1.0/counts;
    h_jet_n->Scale(scale);
    h_jet_np->Scale(scale);
    h_jet_nm->Scale(scale);
    h_jet_n0->Scale(scale);
    h_jet_netQ->Scale(scale);
    }
}

} // namespace CAP
