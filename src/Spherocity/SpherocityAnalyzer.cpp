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
#include "SpherocityAnalyzer.hpp"
#include "MathConstants.hpp"

ClassImp(CAP::SpherocityAnalyzer);

namespace CAP
{
SpherocityAnalyzer::SpherocityAnalyzer()
:
EventTask(),
setEvent(true),
fillS0(true),
fillS1(false),
nSteps(360),
stepSize(CAP::Math::twoPi()/360.0)
{
  appendClassName("SpherocityAnalyzer");
  setName("Spherocity");
  setTitle("Spherocity");
  setVersion("1.0");
}

SpherocityAnalyzer::SpherocityAnalyzer(const SpherocityAnalyzer & analyzer)
:
EventTask(analyzer),
setEvent(analyzer.setEvent),
fillS0(analyzer.fillS0),
fillS1(analyzer.fillS1),
nSteps(analyzer.nSteps),
stepSize(analyzer.stepSize)
{    }

SpherocityAnalyzer & SpherocityAnalyzer::operator=(const SpherocityAnalyzer & analyzer)
{
  if (this!=&analyzer)
    {
    EventTask::operator=(analyzer),
    setEvent   = analyzer.setEvent;
    fillS0     = analyzer.fillS0;
    fillS1     = analyzer.fillS1;
    nSteps     = analyzer.nSteps;
    stepSize   = analyzer.stepSize;
    }
  return *this;
}

void SpherocityAnalyzer::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("HistogramBaseName", "Spherocity");
  addProperty("SetEvent",          true);
  addProperty("FillS0",            true);
  addProperty("FillS1",            false);
  addProperty("FillS1VsS0",        false);
  addProperty("nSteps",            1000);
  addProperty("nBins_spherocity",  100);
  addProperty("Min_spherocity",    0.0);
  addProperty("Max_spherocity",    1.0);
}

void SpherocityAnalyzer::configure()
{
  EventTask::configure();
  setEvent   = getValueBool("SetEvent");
  fillS0     = getValueBool("FillS0");
  fillS1     = getValueBool("FillS1");
  fillS1VsS0 = getValueBool("FillS1VsS0");
  int nSteps = getValueInt("nSteps");
  int nBins_spherocity = getValueInt("nBins_spherocity");
  double min_spherocity = getValueInt("Min_spherocity");
  double max_spherocity = getValueInt("Max_spherocity");
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("SetEvent",setEvent);
    printValue("FillS0",fillS0);
    printValue("FillS1",fillS1);
    printValue("FillS1VsS0",fillS1VsS0);
    printValue("nSteps",nSteps);
    printValue("nBins_spherocity",nBins_spherocity);
    printValue("Min_spherocity",min_spherocity);
    printValue("Max_spherocity",max_spherocity);
    printCR();
    }
}

void SpherocityAnalyzer::initialize()
{
  if (reportStart(__FUNCTION__)){ /* no ops */ };
  EventTask::initialize();
  unsigned int nEventFilters    = Manager<EventFilter>::getNObjects();
  unsigned int nParticleFilters = Manager<ParticleFilter>::getNObjects();
  if (nEventFilters<1 || nParticleFilters<1)
    throw NoFilterSpherocityException(nEventFilters,nParticleFilters,__FUNCTION__);
  clearSets();
  addSet("spherocity");
  addSet("derived");
  String bn  = getName( );

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Creating HistogramGroup for",bn);
    printValue("nEventFilters",nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    }
  s0Filtered.assign(nParticleFilters,0.0);
  s1Filtered.assign(nParticleFilters,0.0);
  createHistograms();
  if (reportEnd(__FUNCTION__)){ /* no ops */ };
}

void SpherocityAnalyzer::createHistograms()
{
  if (reportStart(__FUNCTION__)){ /* no ops */ };
  String bn = getValueString( "HistogramBaseName");
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  for (auto & eventFilter : eventFilters)
    {
    String efn = eventFilter->getName();
    String name = bn;
    name += "_";
    name += efn;
    SpherocityHistos * histos = new SpherocityHistos();
    histos->setName(createName(bn,efn));
    histos->setConfiguration(configuration);
    histos->setParentTask(this);
    histos->setParticleFilters(particleFilters);
    histos->createHistograms();
    addGroupInSet(0,histos);
    }
  if (reportEnd(__FUNCTION__)){ /* no ops */ };
}



void SpherocityAnalyzer::execute()
{
  TaskAccountant::increment();
  static double factor = CAP::Math::pi()*CAP::Math::pi()/4.0;
  Event & event = *Manager<Event>::getObjectAt(0);
  std::vector<Particle*> & particles = event.getParticles();
  if (!analyzeThisEvent(event,eventFilters,eventFilterAccepted)) return;
  if (!analyzeThisEvent(particles,particleFilters,particleFilterAccepted,allParticlesAccepted))  return;
  String spheroName = getName();
  String eventFilterName;
  String particleFilterName;
  unsigned int iEventFilter = 0;
  for (auto accepted : eventFilterAccepted)
    {
    if (!accepted) continue;
    String evfName = eventFilters[iEventFilter]->getName();
    //unsigned int  baseSingle = iEventFilter*nParticleFilters;
    s0Filtered.assign(nParticleFilters,0.0);
    s1Filtered.assign(nParticleFilters,0.0);
    for (unsigned int iParticleFilter=0; iParticleFilter<nParticleFilters; iParticleFilter++ )
      {
      std::vector<Particle*> & particlesSelected = allParticlesAccepted[iParticleFilter];
      double  s0 = 1.0E10;
      double  s1 = 1.0E10;
      double  num0, num1, nx, ny, px, py, pt;
      double  denom0 = 0;
      double  denom1 = 0;
      double  refPhi  = 0.0;
      for(int k = 0; k < nSteps; k++)
        {
        nx = cos(refPhi); // x component of a unitary vector n
        ny = sin(refPhi); // y component of a unitary vector n
        num0 = 0;
        num1 = 0;
        for (auto particleSelected : particlesSelected)
          {
          if (!particleSelected) continue;
          LorentzVector & momentum = particleSelected->getMomentum();
          pt = momentum.Pt();
          px = momentum.Px();
          py = momentum.Py();
          if (fillS0)
            {
            num0 += TMath::Abs(ny*px - nx*py);
            if(k==0) denom0 += pt;
            }
          if (fillS1)
            {
            double  ax = px/pt;
            double  ay = py/pt;
            num1 += TMath::Abs(ny*ax - nx*ay);
            if(k==0) denom1 += 1;
            }
          }
        if (fillS0)
          {
          double ratio = num0/denom0;
          double r2 = ratio*ratio;
          if (r2 < s0) s0 = r2;
          }
        if (fillS1)
          {
          double ratio = num1/denom1;
          double r2 = ratio*ratio;
          if (r2 < s1) s1 = r2;
          }
        refPhi += stepSize;
        }
        if (fillS0) s0Filtered[iParticleFilter] = s0*factor;
        if (fillS1) s1Filtered[iParticleFilter] = s1*factor;
        }
    SpherocityHistos & histos = (SpherocityHistos &) getGroupAt(0,iEventFilter);
    histos.fill(s0Filtered,s1Filtered,1.0);
  }
  }

}
