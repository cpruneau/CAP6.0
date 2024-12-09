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
#include "Factory.hpp"
#include "Particle.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::Particle);
ClassImp(CAP::Factory<CAP::Particle>);


namespace CAP
{

Particle::Particle()
:
momentum (),
position (),
type     (nullptr),
parent   (nullptr),
children (),
truth    (nullptr),
live     (false),
pid      (-1),
sourceIndex(-1),
ixEtaPhi (0),
ixYPhi   (0)
{  }

Particle::Particle(const Particle& other)
:
momentum (other.momentum),
position (other.position),
type     (other.type),
parent   (other.parent),
children (other.children),
truth    (other.truth),
live     (other.live),
pid      (other.pid),
sourceIndex(other.sourceIndex),
ixEtaPhi(other.ixEtaPhi),
ixYPhi(other.ixYPhi)
{  }

Particle & Particle::operator=(const Particle & other)
{
  if (&other != this)
    {
    ixEtaPhi    = other.ixEtaPhi;
    ixYPhi      = other.ixYPhi;
    momentum    = other.momentum;
    position    = other.position;
    type        = other.type;
    parent      = other.parent;
    children    = other.children;
    truth       = other.truth;
    live        = other.live;
    pid         = other.pid;
    sourceIndex = other.sourceIndex;
    }
  return *this;
}

void Particle::clear()
{
  type       = nullptr;
  live       = false;
  pid        = -1;
  ixEtaPhi   = -1;
  ixYPhi     = -1;
  momentum.SetPxPyPzE (0.0,0.0,0.0,0.0);
  position.SetXYZT    (0.0,0.0,0.0,0.0);
  parent = nullptr;
  children.clear();
  truth = nullptr;
}

void Particle::reset()
{
  live       = false;
  pid        = -1;
  ixEtaPhi   = -1;
  ixYPhi     = -1;
  momentum.SetPxPyPzE (0.0,0.0,0.0,0.0);
  position.SetXYZT    (0.0,0.0,0.0,0.0);
  parent = nullptr;
  children.clear();
  truth = nullptr;
}

void Particle::set(ParticleType * _type,
                   double p_x, double p_y, double p_z, double p_e,
                   double _x,  double _y,  double _z,  double _t,
                   bool _live)
{
  //clear();
  type = _type;
  momentum.SetPxPyPzE (p_x,p_y,p_z,p_e);
  position.SetXYZT    (_x,_y,_z,_t);
  live       = _live;
  parent = nullptr;
  children.clear();
  truth = nullptr;
}

void Particle::set(ParticleType * _type,
                   LorentzVector & _momentum,
                   LorentzVector & _position,
                   bool _live)
{
  clear();
  type       = _type;
  momentum   = _momentum;
  position   = _position;
  live       = _live;
}

void Particle::set(ParticleType * _type,
                   LorentzVector & _momentum,
                   Particle* _parent,
                   bool _live)
{
  clear();
  type       = _type;
  momentum   = _momentum;
  live       = _live;
  parent     = _parent;
}

//!
//! Print the properties of this Particle at the given output
//!
void Particle::print(ostream & output, int style, int size)
{
  switch (style)
    {
      case 0:
      {
      printLine(output,style,size);
      printValue("PDG",type->getPdgCode(),output,style,size);
      printValue("Private",type->getPrivateCode(),output,style,size);
      printValue("Name",type->getName(),output,style,size);
      printValue("title",type->getTitle(),output,style,size);
      printValue("charge",type->getCharge(),output,style,size);
      printValue("px",momentum.Px(),output,style,size);
      printValue("py",momentum.Py(),output,style,size);
      printValue("pt",momentum.Pt(),output,style,size);
      printValue("pz",momentum.Pz(),output,style,size);
      printValue("e",momentum.E(),output,style,size);
      printValue("Y",momentum.Rapidity(),output,style,size);
      printValue("eta",momentum.Eta(),output,style,size);
      printValue("phi",momentum.Phi(),output,style,size);
      printValue("x",position.X(),output,style,size);
      printValue("y",position.Y(),output,style,size);
      printValue("z",position.Z(),output,style,size);
      printValue("t",position.T(),output,style,size);
      printValue("live",live,output,style,size);
      printValue("pid",pid,output,style,size);
      printValue("ixEtaPhi",ixEtaPhi,output,style,size);
      printValue("ixYPhi",ixYPhi,output,style,size);
      break;
      }
      case 1:
      {
      printValue("PDG",type->getPdgCode(),output,style,size);
      printValue("px",momentum.Px(),output,style,size);
      printValue("py",momentum.Py(),output,style,size);
      printValue("pt",momentum.Pt(),output,style,size);
      printValue("pz",momentum.Pz(),output,style,size);
      printValue("e",momentum.E(),output,style,size);
      break;
      }
      case 2:
      {
      printValue("PDG",type->getPdgCode(),output,style,size);
      printValue("pt",momentum.Pt(),output,style,size);
      printValue("Y",momentum.Rapidity(),output,style,size);
      printValue("phi",momentum.Phi(),output,style,size);
      break;
      }
    }
}


void Particle::setPidPxPyPzE(long _pid, double p_x, double p_y, double p_z, double p_e)
{
  pid = _pid;
  momentum.SetPxPyPzE (p_x,p_y,p_z,p_e);
}

void Particle::setRThetaPhiT(double r, double theta, double phi,double t)
{
  double rsinTh = r*sin(theta);
  double x = rsinTh*cos(phi);
  double y = rsinTh*sin(phi);
  double z = r*cos(theta);
  position.SetXYZT (x,y,z,t);
}

void Particle::setRCosThetaPhiT(double r, double cosTheta, double phi,double t)
{
  double rsinTh = r*sqrt(1.0-cosTheta*cosTheta);
  double x = rsinTh*cos(phi);
  double y = rsinTh*sin(phi);
  double z = r*cosTheta;
  position.SetXYZT (x,y,z,t);
}

void Particle::boost(double ax, double ay, double az)
{
  momentum.Boost(ax,ay,az);
  unsigned int nChildren = children.size();
  for (unsigned int iChildren=0; iChildren<nChildren; iChildren++)
    {
    children[iChildren]->boost(ax,ay,az);
    }
}

void Particle::boostRapidity(double boost)
{
  double rapidity = momentum.Rapidity();
  rapidity += boost;
  double px = momentum.Px();
  double py = momentum.Py();
  double pz = momentum.Pz();
  double e  = momentum.E();
  double mt = sqrt(e*e - pz*pz);
  pz = mt * sinh(rapidity);
  e  = mt * cosh(rapidity);
  momentum.SetPxPyPzE (px,py,pz,e);
  unsigned int nChildren = children.size();
  for (unsigned int iChildren=0; iChildren<nChildren; iChildren++)
    {
    children[iChildren]->boostRapidity(boost);
    }
}


double Particle::distanceXYZSq(Particle * otherParticle)  const
{
  double dx = position.X() - otherParticle->position.X();
  double dy = position.Y() - otherParticle->position.Y();
  double dz = position.Z() - otherParticle->position.Z();
  return dx*dx + dy*dy + dz*dz;
}

double Particle::distanceXYZ(Particle * otherParticle)  const
{
  return sqrt(distanceXYZSq(otherParticle));
}


double Particle::distanceXYSq(Particle * otherParticle)  const
{
  double dx = position.X() - otherParticle->position.X();
  double dy = position.Y() - otherParticle->position.Y();
  return dx*dx + dy*dy;
}

double Particle::distanceXY(Particle * otherParticle)  const
{
  return sqrt(distanceXYSq(otherParticle));
}

int Particle::factorySize = 5000;
Factory<Particle> * Particle::factory = 0;
Factory<Particle> * Particle::getFactory()
{
  if (!factory)
    {
    factory = new Factory<Particle>();
    factory->setDefaultSizeIncrement(factorySize);
    factory->initialize();
    }
  return factory;
}

void Particle::resetFactory()
{
  factory->reset();
}

void Particle::clearFactory()
{
  factory->clear();
  delete factory;
}


// Particle Interaction 1->1
// Considered a decay vertex
void Particle::setParent(Particle * _parent)
{
  parent = _parent;
}

void Particle::addChild(Particle* child)
{
  children.push_back(child); child->setPosition(position);
}

void Particle::addChildren(Particle* child1, Particle* child2)
{
  children.push_back(child1); child1->setPosition(position);
  children.push_back(child2); child2->setPosition(position);
}

void Particle::addChildren(Particle* child1, Particle* child2, Particle* child3)
{
  children.push_back(child1); child1->setPosition(position);
  children.push_back(child2); child2->setPosition(position);
  children.push_back(child3); child3->setPosition(position);
}

void Particle::addChildren(const vector<Particle*> &  newChildren)
{
  for (auto & newChild : newChildren)
    {
    newChild->setPosition(position);
    children.push_back(newChild);
    }
}


Particle * Particle::getProton()
{
  Particle * particle = new Particle();
  particle->setType(ParticleType::protonType);
  return particle;
}

Particle * Particle::getNeutron()
{
  Particle * particle = new Particle();
  particle->setType(ParticleType::neutronType);
  return particle;
}

bool Particle::isPrimary() const
{
  bool result = true;
  if (parent) result = false;
  return result;
}

bool Particle::isSecondary() const
{
  bool result = false;
  if (parent) result = true;
  return result;
}

} // namespace CAP
