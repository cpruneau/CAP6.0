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
#include "BasicEventGen.hpp"
#include "MathConstants.hpp"

ClassImp(CAP::BasicEventGen);

namespace CAP
{

BasicEventGen::BasicEventGen()
:
EventTask(),
pdgSelected(113),
multMin(2.0),
multMax(20.0),
rapidityMin(-2.0),
rapidityMax(2.0),
ptSlope(.5),
mass(0),
massSq(0)
{
  appendClassName("BasicEventGen");
  setName("BasicEventGen");
  setTitle("BasicEventGen");
}

BasicEventGen::BasicEventGen(const BasicEventGen & task)
:
EventTask(task)
{ }

BasicEventGen & BasicEventGen::operator=(const BasicEventGen & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}

void BasicEventGen::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("MultMin",     multMin);
  addProperty("MultMax",     multMax);
  addProperty("PdgSelected", pdgSelected);
  addProperty("RapidityMin", rapidityMin);
  addProperty("RapidityMax", rapidityMax);
  addProperty("PtSlope",     ptSlope);
}

void BasicEventGen::configure()
{
  EventTask::configure();
}

void BasicEventGen::initialize()
{
  EventTask::initialize();
  if (getValueDouble("SetSeed"))
    {
    String  seedValueString = "Random:seed = ";
    seedValueString += getValueLong("SeedValue");
    }
  multMin     = configuration.getValueDouble("MultMin");
  multMax     = configuration.getValueDouble("MultMax");
  rapidityMin = configuration.getValueDouble("RapidityMin");
  rapidityMax = configuration.getValueDouble("RapidityMax");
  ptSlope     = configuration.getValueDouble("PtSlope");
  pdgSelected = configuration.getValueInt("PdgSelected");
  typeSelected = particleDb->findPdgCode(pdgSelected);
  if (typeSelected==nullptr) throw NullPointerException("particleType==nullptr",__FUNCTION__);
  mass   = typeSelected->getMass();
  massSq = mass*mass;

  typeSelected1 = particleDb->findPdgCode(211);
  if (typeSelected1==nullptr) throw NullPointerException("particleType1==nullptr",__FUNCTION__);
  mass1   = typeSelected1->getMass();
  mass1Sq = mass1*mass1;

  typeSelected2 = particleDb->findPdgCode(-211);
  if (typeSelected2==nullptr) throw NullPointerException("particleType1==nullptr",__FUNCTION__);
  mass2   = typeSelected2->getMass();
  mass2Sq = mass1*mass1;

  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

void BasicEventGen::execute()
{
  Event & event = *Manager<Event>::getObjectAt(0);
  event.reset();
  particleFactory->reset();

  double phi;
  double rapidity;
  double pt;
  double mt;
  double r;
  LorentzVector momentum;
  LorentzVector position;
  position.SetXYZT(0.0, 0.0, 0.0, 0.0);

//  r = gRandom->Rndm();
  int nParticles; // = int(4.0*r);

//  for (int i = 0; i < nParticles; i++)
//    {
//    phi      = Math::twoPi() * gRandom->Rndm();
//    r        = gRandom->Rndm();
//    rapidity = rapidityMin + r*(rapidityMax-rapidityMin);
//    pt       = gRandom->Exp(ptSlope);
//    mt       = sqrt(massSq + pt*pt);
//    momentum.SetXYZT(pt*cos(phi),pt*sin(phi),mt*sinh(rapidity),mt*cosh(rapidity));
//    Particle & particle = *particleFactory->getNextObject();
//    particle.setType(typeSelected);
//    particle.setLive(1);
//    particle.setMomentum(momentum);
//    particle.setPosition(position);
//    event.addParticle(&particle);
//    }

  // background 211
  r = gRandom->Rndm();
  nParticles = int(5.0 + r*25.0);
  for (int i = 0; i < nParticles; i++)
    {
    phi      = Math::twoPi() * gRandom->Rndm();
    r        = gRandom->Rndm();
    rapidity = -4.0 + r*8.0;
    pt       = gRandom->Exp(0.3);
    mt       = sqrt(mass1Sq + pt*pt);
    momentum.SetXYZT(pt*cos(phi),pt*sin(phi),mt*sinh(rapidity),mt*cosh(rapidity));
    Particle & particle = *particleFactory->getNextObject();
    particle.setType(typeSelected1);
    particle.setLive(1);
    particle.setMomentum(momentum);
    particle.setPosition(position);
    event.addParticle(&particle);

//    printValue("1 - rapidity",rapidity);
//    printValue("1 - particle.getMomentum().Rapidity()",particle.getMomentum().Rapidity());

    }

  // background -211
  r = gRandom->Rndm();
  nParticles = int(5.0 + r*25.0);;
  for (int i = 0; i < nParticles; i++)
    {
    phi      = Math::twoPi() * gRandom->Rndm();
    r        = gRandom->Rndm();
    rapidity = -4.0 + r*8.0;
    pt       = gRandom->Exp(0.3);
    mt       = sqrt(mass2Sq + pt*pt);
    momentum.SetXYZT(pt*cos(phi),pt*sin(phi),mt*sinh(rapidity),mt*cosh(rapidity));
    Particle & particle = *particleFactory->getNextObject();
    particle.setType(typeSelected2);
    particle.setLive(1);
    particle.setMomentum(momentum);
    particle.setPosition(position);
    event.addParticle(&particle);

//    printValue("2 - rapidity",rapidity);
//    printValue("2 - momentum.Rapidity()",momentum.Rapidity());


    }


  EventAccountant::incrementEventsAccepted(0);
  TaskAccountant::increment();
}

void BasicEventGen::finalize()
{
  // no ops
}

} // namespace CAP
