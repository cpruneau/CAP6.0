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
#include "ParticlePair3DAnalyzer.hpp"
#include "ParticleSingleHistos.hpp"
#include "ParticlePair3DHistos.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticlePair3DAnalyzer);

namespace CAP
{

ParticlePair3DAnalyzer::ParticlePair3DAnalyzer()
:
EventTask()
{
  appendClassName("ParticlePair3DAnalyzer");
  setInstanceName("ParticlePair3DAnalyzer");
  setName("ParticlePair3DAnalyzer");
  setTitle("ParticlePair3DAnalyzer");
}

ParticlePair3DAnalyzer::ParticlePair3DAnalyzer(const ParticlePair3DAnalyzer & task)
:
EventTask(task)
{   }

ParticlePair3DAnalyzer & ParticlePair3DAnalyzer::operator=(const ParticlePair3DAnalyzer & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}


void ParticlePair3DAnalyzer::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName","Pair");
  addProperty("nBins_pt",          18);
  addProperty("Min_pt",            0.20);
  addProperty("Max_pt",            2.00);
  addProperty("nBins_phi",          72);
  addProperty("Min_phi",           0.0);
  addProperty("Max_phi",           CAP::Math::twoPi());
  addProperty("nBins_eta",           20);
  addProperty("Min_eta",           -1.0);
  addProperty("Max_eta",            1.0);
  addProperty("nBins_y",             20);
  addProperty("Min_y",             -1.0);
  addProperty("Max_y",              1.0);
  addProperty("nBins_phiEta",      720);
  addProperty("nBins_phiEtaPt",    7200);
  addProperty("nBins_phiY",        720);
  addProperty("nBins_phiYPt",       7200);
  addProperty("nBins_n2",           100);
  addProperty("Min_n2",             0.0);
  addProperty("Max_n2",            1000.0);
  addProperty("nBins_Dphi",         36);
  addProperty("Min_Dphi",             0.0);
  addProperty("Max_Dphi",          CAP::Math::twoPi());
  addProperty("Width_Dphi",        CAP::Math::twoPi());
  addProperty("nBins_Dphi_shft",    36);
  addProperty("Min_Dphi_shft",     0.0);
  addProperty("Max_Dphi_shft",     0.0);
  addProperty("nBins_Deta",         39);
  addProperty("Min_Deta",         -2.0);
  addProperty("Max_Deta",          2.0);
  addProperty("Width_Deta",   4.0/39.0);
  addProperty("nBins_Dy",           39);
  addProperty("Min_Dy",           -2.0);
  addProperty("Max_Dy",            2.0);
  addProperty("Width_Dy",     4.0/39.0);
  addProperty("nBins_DeltaP",   10);
  addProperty("Min_DeltaP",   -4.0);
  addProperty("Max_DeltaP",    4.0);
  addProperty("binCorrPP",     1.0);
}

void ParticlePair3DAnalyzer::configure()
{
  EventTask::configure();
}

void ParticlePair3DAnalyzer::initialize()
{
  if (reportStart(__FUNCTION__)) {/* no ops */}
  EventTask::initialize();
  clearSets();
  addSet("single");
  addSet("pair");
  createHistograms();
  if (reportEnd(__FUNCTION__)) {/* no ops */}
}

void ParticlePair3DAnalyzer::createHistograms()
{
  if (reportStart(__FUNCTION__)) {/* no ops */};
  String bn = getValueString( "HistogramBaseName");
  HistogramGroup * histos;
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & particleFilter : particleFilters)
      {
      String pfn = particleFilter->getName();
      histos = new ParticleSingleHistos();
      histos->setName(createName(bn,efn,pfn));
      histos->setConfiguration(configuration);
      histos->setParentTask(this);
      histos->createHistograms();
      addGroupInSet(0,histos); // singles in set 0
      }
    }

  // pairs
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    for (auto & particleFilter1 : particleFilters)
      {
      String pfn1 = particleFilter1->getName();
      for (auto & particleFilter2 : particleFilters)
        {
        String pfn2 = particleFilter2->getName();
        histos = new ParticlePair3DHistos();
        histos->setName(createName(bn,efn,pfn1,pfn2));
        histos->setConfiguration(configuration);
        histos->setParentTask(this);
        histos->createHistograms();
        addGroupInSet(1,histos);
        }
      }
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}

void ParticlePair3DAnalyzer::execute()
{
  Event & event = *Manager<Event>::getObjectAt(0);
  std::vector<Particle*> & particles = event.getParticles();
  if (!analyzeThisEvent(event,eventFilters,eventFilterAccepted)) return;
  if (!analyzeThisEvent(particles,particleFilters,particleFilterAccepted,allParticlesAccepted))  return;
  unsigned int iEventFilter = 0;
  for (auto accepted : eventFilterAccepted)
    {
    if (!accepted) continue;
    unsigned int  baseSingle   = iEventFilter*nParticleFilters;
    unsigned int  basePair     = iEventFilter*nParticleFilters*nParticleFilters;

    for (unsigned int iParticleFilter1=0; iParticleFilter1<nParticleFilters;iParticleFilter1++)
      {
      ParticleSingleHistos & histosSingle = (ParticleSingleHistos &) getGroupAt(0,baseSingle+iParticleFilter1);
      std::vector<Particle*> & particleSelected1 = allParticlesAccepted[iParticleFilter1];
      for (auto & particle1 : particleSelected1) histosSingle.fill(*particle1,1.0);

      for (unsigned int iParticleFilter2=0; iParticleFilter2<nParticleFilters;iParticleFilter2++)
        {
        std::vector<Particle*> & particleSelected2 = allParticlesAccepted[iParticleFilter2];
        ParticlePair3DHistos & histosPair = (ParticlePair3DHistos &) getGroupAt(1,basePair + iParticleFilter1*nParticleFilters + iParticleFilter2);
        for (auto & particle1 : particleSelected1)
          {
          for (auto & particle2 : particleSelected2)
            {
            if (particle1 == particle2) continue;
            histosPair.fill(*particle1,*particle2,1.0);
            }
          }
        }
      }
    iEventFilter++;
    }
}

void ParticlePair3DAnalyzer::scaleHistograms()
{
  if (reportStart(__FUNCTION__)) { /* no ops */ };
  std::vector<long> & counts = getFilteredEventCounts();
  std::vector<double> factors;
  for (auto count : counts)
    {
    if (count>0)
      {
      double f = 1.0/double(count);
      printValue("Count",count);
      printValue("Scaling factor",f);
      factors.push_back(f);
      }
    else
      factors.push_back(1.0);
    }
  unsigned int nEventFilters    = Manager<EventFilter>::getNObjects();
  unsigned int nParticleFilters = Manager<ParticleFilter>::getNObjects();
  unsigned int index;
  unsigned int baseSingle;
  unsigned int basePair;

  for (unsigned int iEventFilter=0; iEventFilter< nEventFilters; iEventFilter++)
    {
    baseSingle = iEventFilter*nParticleFilters;
    basePair   = iEventFilter*nParticleFilters*nParticleFilters;
    for (unsigned int iParticleFilter1=0; iParticleFilter1< nParticleFilters; iParticleFilter1++)
      {
      index = baseSingle + iParticleFilter1;
      getGroupAt(0,index).scaleHistograms(factors[iEventFilter]);
      for (unsigned int iParticleFilter2=0; iParticleFilter2<nParticleFilters; iParticleFilter2++ )
        {
        index = basePair + iParticleFilter1*nParticleFilters + iParticleFilter2;
        getGroupAt(1,index).scaleHistograms(factors[iEventFilter]);
        }
      }
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}

} // namespace CAP
