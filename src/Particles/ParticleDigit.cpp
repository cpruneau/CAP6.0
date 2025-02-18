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
#include <ostream>
#include "ParticleDigit.hpp"
#include "Factory.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::Factory<ParticleDigit>);
ClassImp(CAP::ParticleDigit);

namespace CAP
{

ParticleDigit::ParticleDigit()
:
iY(0),
iEta(0),
iPhi(0),
iPt(0),
pt(0),
phi(0),
eta(0),
y(0),
e(0)
{  }

ParticleDigit::ParticleDigit(unsigned int _iY,
                             unsigned int _iEta,
                             unsigned int _iPhi,
                             unsigned int _iPt,
                             float       _pt,
                             float       _phi,
                             float       _eta,
                             float       _y,
                             float       _e)
:
iY(_iY),
iEta(_iEta),
iPhi(_iPhi),
iPt(_iPt),
pt(_pt),
phi(_phi),
eta(_eta),
y(_y),
e(_e)
{  }

ParticleDigit::~ParticleDigit()
{  }

ParticleDigit::ParticleDigit(const ParticleDigit& other)
:
iY(other.iY),
iEta(other.iEta),
iPhi(other.iPhi),
iPt(other.iPt),
pt(other.pt),
phi(other.phi),
eta(other.eta),
y(other.y),
e(other.e)
{  }

ParticleDigit & ParticleDigit::operator=(const ParticleDigit & other)
{
  if (&other != this)
    {
    iY   = other.iY;
    iEta = other.iEta;
    iPhi = other.iPhi;
    iPt  = other.iPt;
    pt   = other.pt;
    phi  = other.phi;
    eta  = other.eta;
    y    = other.y;
    e    = other.e;
    }
  return *this;
}



void ParticleDigit::reset()
{
  iY   = 0;
  iEta = 0;
  iPhi = 0;
  iPt  = 0;
  pt   = 0.0;
  phi  = 0.0;
  eta  = 0.0;
  y    = 0.0;
  e    = 0.0;
}



//!
//! Print the properties of this ParticleDigit at the given output
//!
void ParticleDigit::print(ostream & output)
{
  output << "-------------------------------------" << endl;
  output << "              iY: " << iY << endl;
  output << "            iEta: " << iEta << endl;
  output << "            iPhi: " << iPhi << endl;
  output << "             iPt: " << iPt << endl;
  output << "              pt: " << pt << endl;
  output << "             phi: " << phi << endl;
  output << "             eta: " << eta << endl;
  output << "               y: " << y << endl;
  output << "               e: " << e  << endl;
}


int ParticleDigit::factorySize = 5000;
Factory<ParticleDigit> * ParticleDigit::factory = 0;
Factory<ParticleDigit> * ParticleDigit::getFactory()
{
  if (!factory)
    {
    factory = new Factory<ParticleDigit>();
    factory->initialize(factorySize);
    }
  return factory;
}
} // namespace cap
