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
#include "JetCalculator.hpp"
#include "JetHistos.hpp"
#include "JetSingleHistos.hpp"
#include "JetPairHistos.hpp"
#include "JetHistosDerived.hpp"
#include "JetSingleHistosDerived.hpp"
#include "JetPairHistosDerived.hpp"
#include "PrintHelpers.hpp"
#include "fastjet/ClusterSequence.hh"

ClassImp(CAP::JetCalculator);

namespace CAP
{

JetCalculator::JetCalculator()
:
EventTask()
{
  appendClassName("JetCalculator");
  setInstanceName("Pair");
  setName("JetCalculator");
  setTitle("JetCalculator");
}

JetCalculator::JetCalculator(const JetCalculator & task)
:
EventTask(task)
{   }

JetCalculator & JetCalculator::operator=(const JetCalculator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}


void JetCalculator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName","Jet");

  addProperty("JetRadius",      0.4);
  addProperty("JetPtMin",       10.0);
  addProperty("nBins_jet_n1",   100);
  addProperty("min_jet_n1",     0.0);
  addProperty("max_jet_n1",     100.0);
  addProperty("nBins_jet_p",    100);
  addProperty("min_jet_p",      0.0);
  addProperty("max_jet_p",      100.0);
  addProperty("nBins_jet_pt",   100);
  addProperty("min_jet_pt",     0.0);
  addProperty("max_jet_pt",     100.0);
  addProperty("nBins_jet_phi",  32);
  addProperty("min_jet_phi",    0.0);
  addProperty("max_jet_phi",    CAP::Math::twoPi());
  addProperty("nBins_jet_eta",   20);
  addProperty("min_jet_eta",     -2.0);
  addProperty("max_jet_eta",     2.0);
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
  addProperty("nBins_z",   50);
  addProperty("min_z",     0.0);
  addProperty("max_z",     1.0);
}

void JetCalculator::configure()
{
  EventTask::configure();
}

void JetCalculator::initialize()
{
  if (reportStart(__FUNCTION__)) {/* no ops */}
  EventTask::initialize();
  particleDb = Manager<ParticleDb>::getObjectAt(0);
  clearSets();
  addSet("JetHistos");
  addSet("JetSingleHistos");
  addSet("JetPairHistos");
  addSet("JetHistosDerived");
  addSet("JetSingleHistosDerived");
  addSet("JetPairHistosDerived");
  HistogramTask::importHistograms();
  createHistograms();
  if (reportEnd(__FUNCTION__)) {/* no ops */}
}

void JetCalculator::importHistograms(TFile & inputFile)
{
  if (reportStart(__FUNCTION__)) {/* no ops */};
  String bn = getValueString("HistogramBaseName");
  JetHistos        * jetHistos;
  JetSingleHistos  * jetSingleHistos;
  JetPairHistos    * jetPairHistos;

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
      jetHistos->importHistograms(inputFile);
      addGroupInSet(0,jetHistos);

      jetSingleHistos = new JetSingleHistos();
      jetSingleHistos->setName(createName(bn,efn,jfn));
      jetSingleHistos->setConfiguration(configuration);
      jetSingleHistos->setParentTask(this);
      jetSingleHistos->importHistograms(inputFile);
      addGroupInSet(1,jetSingleHistos);

      jetPairHistos = new JetPairHistos();
      jetPairHistos->setName(createName(bn,efn,jfn));
      jetPairHistos->setConfiguration(configuration);
      jetPairHistos->setParentTask(this);
      jetPairHistos->importHistograms(inputFile);
      addGroupInSet(2,jetPairHistos);
      }
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}

void JetCalculator::createHistograms()
{
  if (reportStart(__FUNCTION__)) {/* no ops */};
  String bn = getValueString("HistogramBaseName");
  JetHistosDerived * jetHistosDerived;
  JetSingleHistosDerived * jetSingleHistosDerived;
  JetPairHistosDerived   * jetPairHistosDerived;

  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & jetFilter : jetFilters)
      {
      String jfn = jetFilter->getName();

      jetHistosDerived = new JetHistosDerived();
      jetHistosDerived->setName(createName(bn,efn,jfn));
      jetHistosDerived->setConfiguration(configuration);
      jetHistosDerived->setParentTask(this);
      jetHistosDerived->createHistograms();
      addGroupInSet(3,jetHistosDerived);

      jetSingleHistosDerived = new JetSingleHistosDerived();
      jetSingleHistosDerived->setName(createName(bn,efn,jfn));
      jetSingleHistosDerived->setConfiguration(configuration);
      jetSingleHistosDerived->setParentTask(this);
      jetSingleHistosDerived->createHistograms();
      addGroupInSet(4,jetSingleHistosDerived);

      jetPairHistosDerived = new JetPairHistosDerived();
      jetPairHistosDerived->setName(createName(bn,efn,jfn));
      jetPairHistosDerived->setConfiguration(configuration);
      jetPairHistosDerived->setParentTask(this);
      jetPairHistosDerived->createHistograms();
      addGroupInSet(5,jetPairHistosDerived);
      }
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}

void JetCalculator::execute()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  std::vector<JetFilter*> & jetFilters = Manager<JetFilter>::getObjects();
  int nEventFilters    = eventFilters.size();
  int nParticleFilters = particleFilters.size();
  int nJetFilters      = jetFilters.size();

  for (unsigned int iEventFilter=0;iEventFilter<eventFilters.size();iEventFilter++)
    {
    int index = 0;
    for (unsigned int iJetFilter=0;iJetFilter<jetFilters.size();iJetFilter++)
      {
      printLine();
      printLine();
      printLine();
      printLine();
      JetHistos & jetHistos = (JetHistos &) getGroupAt(0,index);
      JetHistosDerived & jetHistosDerived = (JetHistosDerived &)  getGroupAt(3,index);
      jetHistosDerived.calculateDerivedHistograms(jetHistos);

      JetSingleHistos & jetSingleHistos = (JetSingleHistos &) getGroupAt(1,index);
      JetSingleHistosDerived & jetSingleHistosDerived = (JetSingleHistosDerived &)  getGroupAt(4,index);
      jetSingleHistosDerived.calculateDerivedHistograms(jetSingleHistos);

      JetPairHistos & jetPairHistos = (JetPairHistos &) getGroupAt(2,index);
      JetPairHistosDerived & jetPairHistosDerived = (JetPairHistosDerived &)  getGroupAt(5,index);
      jetPairHistosDerived.calculateDerivedHistograms(jetSingleHistos,jetPairHistos);
      index++;
      }
    }
}

void JetCalculator::scaleHistograms()
{

}



} // namespace CAP
