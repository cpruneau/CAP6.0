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
#include "GlobalAnalyzer.hpp"
#include "GlobalHistos.hpp"

ClassImp(CAP::GlobalAnalyzer);

namespace CAP
{

GlobalAnalyzer::GlobalAnalyzer()
:
EventTask(),
n(),
e(),
q(),
s(),
b(),
ptSum()
{
  appendClassName("GlobalAnalyzer");
  setInstanceName("GlobalAnalyzer");
  setName("GlobalAnalyzer");
  setTitle("GlobalAnalyzer");
}

GlobalAnalyzer::GlobalAnalyzer(const GlobalAnalyzer & analyzer)
:
EventTask(analyzer),
n(analyzer.n),
e(analyzer.e),
q(analyzer.q),
s(analyzer.s),
b(analyzer.b),
ptSum(analyzer.ptSum)
{   }

GlobalAnalyzer & GlobalAnalyzer::operator=(const GlobalAnalyzer & analyzer)
{
  if (this!=&analyzer)
    {
    EventTask::operator=(analyzer);
    n = analyzer.n;
    e = analyzer.e;
    q = analyzer.q;
    s = analyzer.s;
    b = analyzer.b;
    ptSum = analyzer.ptSum;
    }
  return *this;
}

//!
//!
void GlobalAnalyzer::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName","Global");

  addProperty("FillCorrelationHistos",false);
  addProperty("Fill2D",               false);
  addProperty("nBins_n",              500);
  addProperty("nBins_n2",              50);
  addProperty("Min_n",                0.0);
  addProperty("Max_n",                5000.0);
  addProperty("nBins_e",              500);
  addProperty("nBins_e2",              50);
  addProperty("Min_e",                0.0);
  addProperty("Max_e",                10000.0);
  addProperty("nBins_q",              200);
  addProperty("nBins_q2",              20);
  addProperty("Min_q",                -100.0);
  addProperty("Max_q",                100.0);
  addProperty("nBins_s",              200);
  addProperty("nBins_s2",              20);
  addProperty("Min_s",                -100.0);
  addProperty("Max_s",                100.0);
  addProperty("nBins_b",              200);
  addProperty("nBins_b2",              20);
  addProperty("Min_b",                -100.0);
  addProperty("Max_b",                100.0);
  addProperty("nBins_ptSum",           100.0);
  addProperty("nBins_ptSum2",          10.0);
  addProperty("Min_ptSum",             0.0);
  addProperty("Max_ptSum",             10000.0);
  addProperty("nBins_ptAvg",           100.0);
  addProperty("nBins_ptAvg2",          10.0);
  addProperty("Min_ptAvg",             0.0);
  addProperty("Max_ptAvg",             10.0);
}

void GlobalAnalyzer::configure()
{
  EventTask::configure();
}

void GlobalAnalyzer::initialize()
{
  if (reportStart(__FUNCTION__)) {  /* no ops */ };
  EventTask::initialize();
  clearSets();
  addSet("global");
  addSet("derived");
  if (nEventFilters<1 || nParticleFilters<1)
    throw NoFilterGlobalException(nEventFilters,nParticleFilters,__FUNCTION__);
  String bn  = getName( );

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Creating HistogramGroup for",bn);
    printValue("nEventFilters",nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    }
  n.assign(nParticleFilters,0.0);
  ptSum.assign(nParticleFilters,0.0);
  e.assign(nParticleFilters,0.0);
  q.assign(nParticleFilters,0.0);
  s.assign(nParticleFilters,0.0);
  b.assign(nParticleFilters,0.0);
  createHistograms();
  if (reportEnd(__FUNCTION__))  {  /* no ops */ };
}

void GlobalAnalyzer::createHistograms()
{
  if (reportStart(__FUNCTION__)) {  /* no ops */ };
  String bn = getValueString( "HistogramBaseName");
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  GlobalHistos * histos;
   for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    histos = new GlobalHistos();
    histos->setName(createName(bn,efn));
    histos->setConfiguration(configuration);
    histos->setParentTask(this);
    histos->setParticleFilters(particleFilters);
    histos->createHistograms();
    addGroupInSet(0,histos);
    }
  if (reportEnd(__FUNCTION__)) {  /* no ops */ };
}

void GlobalAnalyzer::execute()
{
  // printValue("GlobalAnalyzer::execute()",1);
  Event & event = *Manager<Event>::getObjectAt(0);
  std::vector<Particle*>  & particles = event.getParticles();
  // printValue("GlobalAnalyzer::execute()",2);
  if (!analyzeThisEvent(event,eventFilters,eventFilterAccepted)) return;
  // printValue("GlobalAnalyzer::execute()",3);
  if (!analyzeThisEvent(particles,particleFilters,particleFilterAccepted,allParticlesAccepted))  return;
  // printValue("GlobalAnalyzer::execute()",7);

  //String globalName = getName();
  for (unsigned int iEventFilter = 0;iEventFilter<nEventFilters;iEventFilter++)
    {
   // printValue("GlobalAnalyzer::execute()",8);
    String evfName = eventFilters[iEventFilter]->getName();
    // printValue("GlobalAnalyzer::execute()",9);
    n.assign(nParticleFilters,0.0);
    e.assign(nParticleFilters,0.0);
    q.assign(nParticleFilters,0.0);
    s.assign(nParticleFilters,0.0);
    b.assign(nParticleFilters,0.0);
    ptSum.assign(nParticleFilters,0.0);
    // printValue("GlobalAnalyzer::execute()",10);
    if (eventFilterAccepted[iEventFilter])
      {
      // printValue("GlobalAnalyzer::execute()",11);

      for (unsigned int iParticleFilter = 0; iParticleFilter<nParticleFilters; iParticleFilter++)
        {
         // printValue("GlobalAnalyzer::execute()",12);

        if (particleFilterAccepted[iParticleFilter])
          {
          // printValue("GlobalAnalyzer::execute()",13);
          std::vector<Particle*> & particlesSelected = allParticlesAccepted[iParticleFilter];
          // printValue("GlobalAnalyzer::execute()",14);

          for (auto & particle : particlesSelected)
            {
            // printValue("GlobalAnalyzer::execute()",15);

            incrementParticlesAccepted(iEventFilter,iParticleFilter);
            // printValue("GlobalAnalyzer::execute()",16);

            ParticleType & type = particle->getType();
            LorentzVector & momentum = particle->getMomentum();
            n[iParticleFilter]++;
            e[iParticleFilter] += momentum.E();
            q[iParticleFilter] += type.getCharge();
            s[iParticleFilter] += type.getStrangeness();
            b[iParticleFilter] += type.getBaryonNumber();
            ptSum[iParticleFilter] += momentum.Pt();
            }
          }
        else
          {
          n[iParticleFilter] = 0.0;
          e[iParticleFilter] = 0.0;
          q[iParticleFilter] = 0.0;
          s[iParticleFilter] = 0.0;
          b[iParticleFilter] = 0.0;
          ptSum[iParticleFilter] = 0.0;
          }

        switch (iParticleFilter)
          {
            case 0:
            {
            event.setCl0(0.0); // needs fix
            event.setMult0(n[0]);
            event.setEnergy0(e[0]);
            }
            break;

            case 1:
            {
            event.setCl1(0.0);
            event.setMult1(n[1]);
            event.setEnergy1(e[1]);
            }
            break;

            case 2:
            {
            event.setCl2(0.0);
            event.setMult2(n[2]);
            event.setEnergy2(e[2]);
            }
            break;

            case 3:
            {
            event.setCl3(0.0);
            event.setMult3(n[3]);
            event.setEnergy3(e[3]);
            }
            break;

            case 4:
            {
            event.setCl4(0.0);
            event.setMult4(n[4]);
            event.setEnergy4(e[4]);
            }
            break;
            default: break; // not stored.
          }
        }
      GlobalHistos & globalHistos = (GlobalHistos &) getGroupAt(0,iEventFilter);
      globalHistos.fill(n,ptSum,e,q,s,b,1.0);
      }
    }
  // printValue("GlobalAnalyzer::execute()",100);
  TaskAccountant::increment();
}

void GlobalAnalyzer::scaleHistograms()
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
  for (unsigned int iEventFilter=0; iEventFilter<counts.size(); iEventFilter++ )
    {
    getGroupAt(0,iEventFilter).scaleHistograms(factors[iEventFilter]);
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */};
}


} // namespace CAP
