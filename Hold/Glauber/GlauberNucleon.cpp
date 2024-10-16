#ifndef CAP__GlauberNucleon
#define CAP__GlauberNucleon
#include "GlauberNucleon.hpp"

ClassImp(CAP::GlauberNucleon)

GlauberNucleon::GlauberNucleon()
:
position(),
nucleonType(0),
inNucleusA(0),
nBinaryCollisions(0),
energy(0)
{ }

GlauberNucleon::GlauberNucleon(const GlauberNucleon & nucleon)
:
position(nucleon.position),
nucleonType(nucleon.nucleonType),
inNucleusA(nucleon.inNucleusA),
nBinaryCollisions(nucleon.nBinaryCollisions),
energy(nucleon.energy)
{   }

GlauberNucleon operator=(const GlauberNucleon & nucleon)
{
  if (this!=&nucleon)
  {
  position          = nucleon.position;
  nucleonType       = nucleon.nucleonType;
  inNucleusA        = nucleon.inNucleusA;
  nBinaryCollisions = nucleon.nBinaryCollisions;
  energy            = nucleon.energy;
  }
  return *this;
}



void GlauberNucleon::rotateXYZ(Double_t phi, Double_t theta)
{
  position.rotate(phi,theta);
}

void GlauberNucleon::rotateXYZ_3D(Double_t psiX, Double_t psiY, Double_t psiZ)
{
  position.rotate(psiX,psiY,psiZ);
}

void GlauberNucleon::setXYZ(Double_t x, Double_t y, Double_t z)
{
  position.set(x,y,z);
}

void GlauberNucleon::reset()
{
  position.setXYZ(0.0,0.0,0.0);
  inNucleusA  = 1;
  nBinaryCollisions = 0;
  energy = 0.0;
}

const Vector3 & GlauberNucleon::getPosition() const
{
  return position;
}

Vector3 & GlauberNucleon::getPosition()
{
  return position;
}


} // namespace CAP


