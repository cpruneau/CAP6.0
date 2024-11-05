/* **********************************************************************
 * Copyright (C) 2019-2022, Claude Pruneau, Victor Gonzalez, Sumit Basu
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2022
 *
 * *********************************************************************/
#include "JetAnalyzer.hpp"
#include "JetHistos.hpp"
#include "JetSingleHistos.hpp"
#include "JetPairHistos.hpp"
#include "PrintHelpers.hpp"
#include "fastjet/ClusterSequence.hh"

ClassImp(CAP::JetAnalyzer);

namespace CAP
{

JetAnalyzer::JetAnalyzer()
:
EventTask(),
Manager<JetFilter>()
{
  appendClassName("JetAnalyzer");
  setInstanceName("Pair");
  setName("JetAnalyzer");
  setTitle("JetAnalyzer");
}

JetAnalyzer::JetAnalyzer(const JetAnalyzer & task)
:
EventTask(task),
Manager<JetFilter>(task)
{   }

JetAnalyzer & JetAnalyzer::operator=(const JetAnalyzer & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    Manager<JetFilter>::operator=(task);
    }
  return *this;
}


void JetAnalyzer::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName","Jet");

  addProperty("nBins_jet_n1",   100);
  addProperty("min_jet_n1",     0.0);
  addProperty("max_jet_n1",     100.0);
  addProperty("nBins_jet_p",    100);
  addProperty("min_jet_p",      0.0);
  addProperty("max_jet_p",      100.0);
  addProperty("nBins_jet_pt",   100);
  addProperty("min_jet_pt",     0.0);
  addProperty("max_jet_pt",     100.0);
  addProperty("nBins_jet_phi",  18);
  addProperty("min_jet_phi",    0.0);
  addProperty("max_jet_phi",    CAP::Math::twoPi());
  addProperty("nBins_jet_eta",   20);
  addProperty("min_jet_eta",     -1.0);
  addProperty("max_jet_eta",     1.0);
  addProperty("nBins_jet_netQ",  20);
  addProperty("min_jet_netQ",    -10.0);
  addProperty("max_jet_netQ",    10.0);
  addProperty("nBins_p",    100);
  addProperty("min_p",      0.0);
  addProperty("max_p",      10.0);
  addProperty("nBins_pt",   100);
  addProperty("min_pt",     0.0);
  addProperty("max_pt",     10.0);
  addProperty("nBins_phi",  36);
  addProperty("min_phi",    0.0);
  addProperty("max_phi",    CAP::Math::twoPi());
  addProperty("nBins_eta",  40);
  addProperty("min_eta",    -2.0);
  addProperty("max_eta",    2.0);
  addProperty("nBins_jt",   50);
  addProperty("min_jt",     0.0);
  addProperty("max_jt",     5.0);
  addProperty("nBins_th",   20);
  addProperty("min_th",     0.0);
  addProperty("max_th",     CAP::Math::pi()/4.0);
}

void JetAnalyzer::configure()
{
  EventTask::configure();
}

void JetAnalyzer::initialize()
{
  if (reportStart(__FUNCTION__)) {/* no ops */}
  EventTask::initialize();

  particleDb = Manager<ParticleDb>::getObjectAt(0);
  jetFilters  = Manager<JetFilter>::getObjects();
  nJetFilters = jetFilters.size();

  clearSets();
  addSet("JetHistos");
  addSet("JetSingleHistos");
  addSet("JetPairHistos");
  createHistograms();
  if (reportEnd(__FUNCTION__)) {/* no ops */}
}

void JetAnalyzer::createHistograms()
{
  if (reportStart(__FUNCTION__)) {/* no ops */};
  String bn = getValueString( "HistogramBaseName");
  JetHistos * jetHistos;
  JetSingleHistos * jetSingleHistos;
  JetPairHistos * jetPairHistos;

  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & jetFilter : jetFilters)
      {
      String jfn = jetFilter->getName();

      jetHistos = new JetHistos();
      jetHistos->setName(createName(bn,efn,jfn));
      jetHistos->setConfiguration(configuration);
      jetHistos->setParentTask(this);
      jetHistos->createHistograms();
//      jetHistos->setParticleDb();
      addGroupInSet(0,jetHistos);

      jetSingleHistos = new JetSingleHistos();
      jetSingleHistos->setName(createName(bn,efn,jfn));
      jetSingleHistos->setConfiguration(configuration);
      jetSingleHistos->setParentTask(this);
      jetSingleHistos->createHistograms();
      addGroupInSet(1,jetSingleHistos);

      jetPairHistos = new JetPairHistos();
      jetPairHistos->setName(createName(bn,efn,jfn));
      jetPairHistos->setConfiguration(configuration);
      jetPairHistos->setParentTask(this);
      jetPairHistos->createHistograms();
      addGroupInSet(1,jetPairHistos);
      }
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}

void JetAnalyzer::execute()
{
  Event & event = *Manager<Event>::getObjectAt(0);
  std::vector<Particle*> & particles = event.getParticles();
  if (!analyzeThisEvent(event,eventFilters,eventFilterAccepted)) return;

  std::vector<JetFilter*> & jetFilters = Manager<JetFilter>::getObjects();
  std::vector<PseudoJet> pseudoJetsInput;
  pseudoJetsInput.clear();
  for (auto & particle : particles)
    {
    int pid = particle->getType().getPdgCode();
    LorentzVector & momentum = particle->getMomentum();
    PseudoJet pseudoJet (momentum.Px(),momentum.Px(),momentum.Px(),momentum.E());
    pseudoJet.set_user_index(pid);
    pseudoJetsInput.push_back(pseudoJet);
    }

  JetDefinition jetDef(antikt_algorithm,jetRadius);
  ClusterSequence * clusterSequence = new ClusterSequence(pseudoJetsInput, jetDef);
  std::vector<PseudoJet> clusteredJets = sorted_by_pt( clusterSequence->inclusive_jets() );
  unsigned int iEventFilter = 0;
  for (auto accepted : eventFilterAccepted)
    {
    if (!accepted) continue;
    unsigned int  baseSingle   = iEventFilter*nJetFilters;
    for (unsigned int iJetFilter=0; iJetFilter<nJetFilters;iJetFilter++)
      {
      int index = baseSingle+iJetFilter;
      JetHistos & jetHistos = (JetHistos &) getGroupAt(0,index);
      JetSingleHistos & jetSingleHistos = (JetSingleHistos &) getGroupAt(1,index);
      JetPairHistos & jetPairHistos     = (JetPairHistos &) getGroupAt(2,index);
      for (auto jet : clusteredJets)
        {
        if (jetFilters[iJetFilter]->accept(jet))
          {
          jetHistos.fill(jet);
          jetSingleHistos.fill(jet);
          jetPairHistos.fill(jet);
          }
        }
      }
    iEventFilter++;
    }
  TaskAccountant::increment();
  delete clusterSequence;
}

void JetAnalyzer::scaleHistograms()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
//  std::vector<long> & counts = getFilteredEventCounts();
//  std::vector<double> factors;
//  for (auto count : counts)
//    {
//    if (count>0)
//      {
//      double f = 1.0/double(count);
//      printValue("Count",count);
//      printValue("Scaling factor",f);
//      factors.push_back(f);
//      }
//    else
//      factors.push_back(1.0);
//    }
//  unsigned int nEventFilters = Manager<EventFilter>::getNObjects();
//  unsigned int nJetFilters   = Manager<JetFilter>::getNObjects();
//  unsigned int index;
//  unsigned int baseSingle;
//  unsigned int basePair;
//
//  for (unsigned int iEventFilter=0; iEventFilter< nEventFilters; iEventFilter++)
//    {
//    baseSingle = iEventFilter*nJetFilters;
//    basePair   = iEventFilter*nJetFilters*nJetFilters;
//    for (unsigned int iJetFilter1=0; iJetFilter1< nJetFilters; iJetFilter1++)
//      {
//      index = baseSingle + iJetFilter1;
//      getGroupAt(0,index).scaleHistograms(factors[iEventFilter]);
//      for (unsigned int iJetFilter2=0; iJetFilter2<nJetFilters; iJetFilter2++ )
//        {
//        index = basePair + iJetFilter1*nJetFilters + iJetFilter2;
//        getGroupAt(1,index).scaleHistograms(factors[iEventFilter]);
//        }
//      }
//    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}

} // namespace CAP
