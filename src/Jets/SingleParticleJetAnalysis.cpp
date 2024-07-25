0#include <iostream>
#include "Pythia8/Pythia.h"
#include "fastjet/ClusterSequence.hh"
#include <cmath>
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2.h"
#include "TF1.h"
#include "TMath.h"
#include <cstdlib>
#include "TCanvas.h"
#include "TLatex.h"
#include <map>
#include <stdexcept>
#include "class_charge.hpp"

using namespace fastjet;
using namespace std;
using namespace Pythia8;

namespace  CAP
{

class SingleParticleJetAnalysis : HistogramGroup
{
protected:

  TString baseJetClassName;
  unsigned int nJets;      // number of jets used
  unsigned int nParticles; // number of particles in the jet
  unsigned int nSelectedParticles; // number of selected particles in the jet
  int selectionOption;   // what kind of particles are used to fill the jet

  TH1 * h_nParticles;
  TH1 * h_nSelectedParticles;
  TH1 * h_jetE;   // spectrum of the jet energy
  TH1 * h_jetPt;  // spectrum of the jet pT
  TH1 * h_jetPhi; // spectrum of the jet phi angle
  TH1 * h_jetY;   // spectrum of the jet rapidity or pseudo rapidity

  TH1 * h_pt;     // spectrum of the particles pT in the jet
  TH1 * h_jt;     // spectrum of the particles jT in the jet
  TH1 * h_z;

  public:

  SingleParticleJetAnalysis(const TString baseJetClassName & _baseJetClassName);
  virtual ~SingleParticleJetAnalysis();
  virtual void createHistograms();
  virtual void fillHistograms();
  virtual void scaleHistograms();
  virtual void saveHistograms();

}

SingleParticleJetAnalysis::SingleParticleJetAnalysis()
:
baseJetClassName("NAME"),
nJets(0),
nParticles(0),
nSelectedParticles(_selectionOption),
selectionOption(0),
h_nParticles(nullptr),
h_nSelectedParticles(nullptr),
h_jetE(nullptr),
h_jetPt(nullptr),
h_jetPhi(nullptr),
h_jetY(nullptr),
h_pt(nullptr),
h_jt(nullptr),
h_z(nullptr)
{   }

SingleParticleJetAnalysis::~JetAnalysis()
{
  // delte stuff here
  }

SingleParticleJetAnalysis::createHistograms()
{
  TString hName;
  TString bn = baseJetClassName; // base name of histograms
  bn += "_";
  hName = bn; hName += "nParticles";
  h_nParticles = new TH1D(hName,hName,50,0.0,50.0);
  hName = bn; hName += "nSelectedParticles";
  h_nSelectedParticles = new TH1D(hName,hName,50,0.0,50.0);
  hName = bn; hName += "jetE";
  h_jetE = new TH1D(hName,hName,50,0.0,200.0);
  hName = bn; hName += "jetPt";
  h_jetPt = new TH1D(hName,hName,50,0.0,200.0);
  hName = bn; hName += "jetPhi";
  h_jetPhi = new TH1D(hName,hName,36,0.0,2.0*3.1415927);
  hName = bn; hName += "jetY";
  h_jetY = new TH1D(hName,hName,20,-5.0,5.0);
  hName = bn; hName += "pt";
  h_pt = new TH1D(hName,hName,50,0.0,50.0);
  hName = bn; hName += "jt";
  h_jt = new TH1D(hName,hName,50,0.0,10.0);
  hName = bn; hName += "z";
  h_z = new TH1D(hName,hName,100,0.0,1.0);

}


SingleParticleJetAnalysis::fillHistograms(Jet & jet);
{
  nJets++;
  nParticles = jet.size();
  h_jetE->Fill(jet.E());
  h_jetPt->Fill(jet.Pt());
  h_jetPhi->Fill(jet.Phi());
  h_jetY->Fill(jet.Y());

  nSelectedParticles = 0;
  vector<PseudoJet> particles = jets.constituents();
  for (auto & particle : particles+)
    {
    bool selected = false;
    switch (selectionOption)
      {
        case  0: selected = true; break;
        case  1: if (particle->charge > 0) selected = true; break;
        case -1: if (particle->charge < 0) selected = true; break;
        // could also use pT criteria here....
      }
    if (selected)
      {
      h_pt->Fill(particle.Pt());
      h_jt->Fill(particle.Jt());
      h_z->Fill(particle.z());
      nSelectedParticles++;
      }
    }
  h_nParticles->fill(double(nParticles));
  h_nSelectedParticles->fill(double(nSelectedParticles));
}


void SingleParticleJetAnalysis::scaleHistograms()
{
  double scalingFactor = 1.0/double(nJets);
  h_jetE->Scale(scalingFactor);
  h_jetPt->Scale(scalingFactor);
  h_jetPhi->Scale(scalingFactor);
  h_jetY->Scale(scalingFactor);
  h_pt->Scale(scalingFactor);
  h_jt->Scale(scalingFactor);
  h_z->Scale(scalingFactor);
  h_nParticles->Scale(scalingFactor);
  h_nSelectedParticles->Scale(scalingFactor);
}

void SingleParticleJetAnalysis::saveHistograms(TFile & outputFile)
{
  outputFile.cd();
  h_jetE->Write();
  h_jetPt->Write();
  h_jetPhi->Write();
  h_jetY->Write();
  h_pt->Write();
  h_jt->Write();
  h_z->Write();
  h_nParticles->Write();
  h_nSelectedParticles->Write();
}

void SingleParticleJetAnalysis::resetHistograms()
{
  h_jetE->Reset();
  h_jetPt->Reset();
  h_jetPhi->Reset();
  h_jetY->Reset();
  h_pt->Reset();
  h_jt->Reset();
  h_z->Reset();
  h_nParticles->Reset();
  h_nSelectedParticles->Reset();
}



void createHistograms()
{
  vector<SingleParticleJetAnalysis*> singleJetHistograms;
  vector<PairParticleJetAnalysis*> pairJetHistograms;

  jetHistograms.push_back(new SingleParticleJetAnalysis("All_10_20GeV",0));  all particles in jets in the 10 - 20 GeV range
  jetHistograms.push_back(new SingleParticleJetAnalysis("All_20_40GeV",0));
  jetHistograms.push_back(new SingleParticleJetAnalysis("All_40_200GeV",0));
  jetHistograms.push_back(new SingleParticleJetAnalysis("Neg_10_20GeV",-1));  all negative particles jets in the 10 - 20 GeV range
  jetHistograms.push_back(new SingleParticleJetAnalysis("Neg_20_40GeV",-1));
  jetHistograms.push_back(new SingleParticleJetAnalysis("Neg_40_200GeV",-1));

  jetHistograms.push_back(new SingleParticleJetAnalysis("Pos_10_20GeV", 1));  all positive particles jets in the 10 - 20 GeV range
  jetHistograms.push_back(new SingleParticleJetAnalysis("Pos_20_40GeV", 1));
  jetHistograms.push_back(new SingleParticleJetAnalysis("Pos_40_200GeV", 1));

  /// bla bla bla
  ///
  ///

  vector<double> minima;
  vector<double> maxima;
  for (int k=0; k<nClasses; k+)


  here you have a jet
  // all charges
  if (jetEnergy>= minima[k]  && maxima[k]>= 20)
    jetHistograms[0]->fill(jet);
  else if (jetEnergy>= 20  && jetEnergy>= 40)
    jetHistograms[1]->fill(jet);
  else
    jetHistograms[2]->fill(jet);

  // negative particles only
  if (jetEnergy>= 10  && jetEnergy>= 20)
    jetHistograms[3]->fill(jet);
  else if (jetEnergy>= 20  && jetEnergy>= 40)
    jetHistograms[4]->fill(jet);
  else
    jetHistograms[5]->fill(jet);

  // positive particles only
  if (jetEnergy>= 10  && jetEnergy>= 20)
    jetHistograms[6]->fill(jet);
  else if (jetEnergy>= 20  && jetEnergy>= 40)
    jetHistograms[7]->fill(jet);
  else
    jetHistograms[8]->fill(jet);



    }

} // namespace CAP


