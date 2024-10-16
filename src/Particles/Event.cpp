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
#include "Event.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::Event);
ClassImp(CAP::Manager<CAP::Event>);

namespace CAP
{

//!
//! CTOR
//!
Event::Event()
:
eventName(),
eventIndex(0),
eventNumber(0),
projectileA(),
projectileB(),
particles(),
cl0(0.0), cl1(0.0), cl2(0.0), cl3(0.0), cl4(0.0),
mult0(0.0), mult1(0.0), mult2(0.0), mult3(0.0), mult4(0.0),
spherocity0(0.0), spherocity1(0.0), spherocity2(0.0), spherocity3(0.0), spherocity4(0.0),
energy0(0.0), energy1(0.0), energy2(0.0), energy3(0.0), energy4(0.0)
{  /* no ops */ }

//!
//! DTOR
//!
Event::~Event()
{
  particles.clear();
}

//!
// Call before (re)starting simulation
//!
void Event::clear()
{
  eventIndex      = 0;
  eventNumber     = 0;
  particles.clear();
}

//!
// Call before generating new event
//!
void Event::reset()
{
  eventIndex++;
  eventNumber   = 0;
  particles.clear();
  cl0 = 0.0; cl1 = 0.0; cl2 = 0.0; cl3 = 0.0; cl4 = 0.0;
  mult0 = 0.0; mult1 = 0.0; mult2 = 0.0; mult3 = 0.0; mult4 = 0.0;
  spherocity0 = 0.0; spherocity1 = 0.0; spherocity2 = 0.0; spherocity3 = 0.0; spherocity4 = 0.0;
  energy0 = 0.0; energy1 = 0.0; energy2 = 0.0; energy3 = 0.0; energy4 = 0.0;
}


void Event::addParticle(Particle * particle)
{
  particles.push_back(particle);
}

vector<Particle*> & Event::getParticles()
{
  return particles;
}

const vector<Particle*> & Event::getParticles() const
{
  return particles;
}

Particle * Event::getParticleAt(unsigned long index)
{
  if (index>=particles.size() )
    throw Exception("index out of bounds","Event::getParticleAt(unsigned long index)");
  return particles[index];
}

void Event::printParticles(ostream & output, int style, int size) const
{
  for (auto & particle : particles) particle->print(output,style,size);
}


void Event::print(ostream & output, int style, int size)
{
  printCR(output,2);
  printLine(output,style,100);
  printValue("Event Name",eventName,output,style,size);
  printValue("Event Index",eventIndex,output,style,size);
  printValue("Event Number",eventNumber,output,style,size);
  printString("Projectile A",output,style,size);
  projectileA.print(output,style,size);
  printString("Projectile B",output,style,size);
  projectileB.print(output,style,size);

  printValue("Cl0",cl0);
  printValue("Cl1",cl1);
  printValue("Cl2",cl2);
  printValue("Cl3",cl3);
  printValue("Cl4",cl4);
  printValue("Mult0",mult0);
  printValue("Mult1",mult1);
  printValue("Mult2",mult2);
  printValue("Mult3",mult3);
  printValue("Mult4",mult4);
  printValue("Spherocity0",spherocity0);
  printValue("Spherocity1",spherocity1);
  printValue("Spherocity2",spherocity2);
  printValue("Spherocity3",spherocity3);
  printValue("Spherocity4",spherocity4);
  printValue("Energy0",energy0);
  printValue("Energy1",energy1);
  printValue("Energy2",energy2);
  printValue("Energy3",energy3);
  printValue("Energy4",energy4);
  printParticles(output,style,size);
  printLine(output,style,100);
  printCR(output,2);
}


} // namespace CAP
