/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Victor Gonzalez   
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
 *
 * *********************************************************************/
#include "EposEventReader.hpp"

ClassImp(CAP::EposEventReader);

namespace CAP
{


EposEventReader::EposEventReader(const String & _name,
                                 const Configuration & _configuration)
:
EventTask(_name,_configuration),
RootChainManager()
{
  appendClassName("EposEventReader");
  setName("Epos");
  setTitle("Epos");
  setVersion("1.0");
}

void EposEventReader::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
}

void EposEventReader::configure()
{
  EventTask::configure();
}


void EposEventReader::execute()
{
  ParticleFilter & particleFilter = * particleFilters[0];
  Event & event = *Manager<Event>::getObjectAt(0);
  event.reset();
  particleFactory->reset();
  // resetParticleCounters();
  Particle * parentInteraction;
  parentInteraction = particleFactory->getNextObject();
  parentInteraction->reset();
  parentInteraction->setType( ParticleType::getInteractionType());
  parentInteraction->setXYZT(0.0, 0.0, 0.0, 0.0);
  event.add(parentInteraction);
  Long64_t ientry = LoadTree(entryIndex);
  if (ientry < 0)
    {
    postTaskEod();  return;
    }
  nb = rootInputTreeChain()->GetEntry(entryIndex++);
  nBytes += nb;
  if (nParticles > arraySize)
    {
    if (reportError(__FUNCTION__)) cout<< "nParticles: " << nParticles << "  exceeds capacity " << arraySize << endl;
    throw TaskException("nParticles > arraySize","EposEventReader::execute()");
    }
  double eventPhi;
  double cosPhi;
  double sinPhi;
  if (useRandomizeEventPlane())
    {
    eventPhi = getRandomEventPlaneAngle();
    cosPhi = cos(eventPhi);
    sinPhi = sin(eventPhi);
    }
  
  LorentzVector & sourcePosition = parentInteraction->getPosition();
  double r_x = sourcePosition.X();
  double r_y = sourcePosition.Y();
  double r_z = sourcePosition.Z();
  double r_t = sourcePosition.T();
  ParticleType * type;
  
  for (int iParticle=0; iParticle<nParticles; iParticle++)
    {
    int pdgCode = pid[iParticle];
    type = ParticleDb::getDefaultParticleDb()->findPdgCode(pdgCode);
    if (type==nullptr)
      {
      if (reportWarning(__FUNCTION__)) cout << "Encountered unknown pdgCode: " << pdgCode << " Particle not added to event." << endl;
      continue;
      }

    Particle * particle = particleFactory->getNextObject();
    double p_x, p_y, p_z, p_e;
    double mass = type->getMass();
    if (useRandomizeEventPlane())
      {
      p_x  = cosPhi*px[iParticle] - sinPhi*py[iParticle];
      p_y  = sinPhi*px[iParticle] + cosPhi*py[iParticle];
      }
    else
      {
      p_x  = px[iParticle];
      p_y  = py[iParticle];
      }
    p_z  = pz[iParticle];
    p_e  = sqrt(p_x*p_x + p_y*p_y + p_z*p_z + mass*mass);
    particle->set(type,p_x,p_y,p_z,p_e,r_x,r_y,r_z,r_t,true);
    if (!particleFilter.accept(*particle)) continue;
    incrementNParticlesAccepted();
    event.add(particle);
    }
  event.setEventNumber(events);
  EventProperties & eventProperties = * event.getEventProperties();
  eventProperties.zProjectile           = 0;
  eventProperties.aProjectile           = 0;
  eventProperties.nPartProjectile       = 0;
  eventProperties.zTarget               = 0;
  eventProperties.aTarget               = 0;
  eventProperties.nPartTarget           = 0;
  eventProperties.nParticipantsTotal    = 0;
  eventProperties.nBinaryTotal          = 0;
  eventProperties.impactParameter       = impact;
  eventProperties.fractionalXSection    = -99999;
//  eventProperties.refMultiplicity = getNParticlesAccepted();
//  eventProperties.particlesCounted      = getNParticlesCounted();
//  eventProperties.particlesAccepted     = getNParticlesAccepted();
  incrementNEventsAccepted(0);
}

void EposEventReader::initialize()
{
  TTree * tree = rootInputTreeChain();
  tree->SetMakeClass(1);
  tree->SetBranchAddress("Events", &events,   &b_Events);
  tree->SetBranchAddress("Mult", &nParticles, &b_Mult);
  tree->SetBranchAddress("Impact", &impact,   &b_Impact);
  tree->SetBranchAddress("PID", pid, &b_PID);
  tree->SetBranchAddress("Px", px, &b_Px);
  tree->SetBranchAddress("Py", py, &b_Py);
  tree->SetBranchAddress("Pz", pz, &b_Pz);
  tree->SetBranchAddress("E", e, &b_E);
}


} // namespace CAP

