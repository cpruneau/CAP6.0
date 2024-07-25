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
Properties(),
eventName(),
eventIndex(0),
eventNumber(0),
projectileA(),
projectileB(),
particles()
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
  Properties::clear();
}

//!
// Call before generating new event
//!
void Event::reset()
{
  eventIndex++;
  eventNumber   = 0;
  particles.clear();
  Properties::reset();
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
  Properties::print(output,style,size);
  printParticles(output,style,size);
  printLine(output,style,100);
  printCR(output,2);
}


} // namespace CAP
