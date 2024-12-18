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
#ifndef CAP__Particle
#define CAP__Particle
#include "Aliases.hpp"
#include "Factory.hpp"
#include "ParticleType.hpp"
using namespace std;

namespace CAP
{

//!
//!This class encapsualtes the notion of particles as encounted in particle and nuclear physics simulations of
//!elementary particle collisions or GlauberNucleus-GlauberNucleus collisions. Particle object can be created and handled on their
//!own or in small aggregates but they are better handled based on a particle factory that keeps track and handle
//!the memory used for the storage of particles.
//!
//!Particle described by this class have the following properties and attributes:
//! - type : A pointer to a ParticleTy[e object that described the type of this particle,
//! - position: The position implemented as TLorentVector where this particle originates from. The position can be chosen to be a macroscopic  vertex position or the microscopic location, within the emitting system, where it was
//! produced. The usage depends on the speficities of the simulations.
//! - momentum: The momentum of the particle in the reference frame of interest (usually the laboratory frame of reference).
//! -user type: optionally, a user type can be supplied to identify the species or type of the particle.
//! - live status: the particle can be considered "live" and thus active as part of the set of particles apprehended by the measurement
//! device or dead/decayed/interacted and thus not to be considered as measurable by detection devices.
//! - parent: A parent particle or process
//! - children: The particle can be a decaying particle that is decayed , an interaction that has produced children particles, or a GlauberNucleus
//!  with nucleons. Either way, it shall be known either as having or not having children. It shall also, optionally,
//!  hold a list of said children.
//!
//!This class features a number of methods to identify its nature, i.e., whether it represents an interaction
//! (and which kind of interaction),  an elementary particle (specified by its type), a GlauberNucleus (also identified by its type), or an interaction.
//!
//!The class features a number of helper methods to compute such properties as the distance to another particle
//! (either in the transverse plane or in three dimensions).
//!
//! The particle can also hold a pointer to a "truth" particle or reference particle. This is used, in particular, in simple one-to-one simulation studies of the performance of a detection device (i.e., resolution and efficiency studies, closure test, etc).
//!
class Particle
{
public:
  
  Particle();
  virtual ~Particle(){}
  Particle(const Particle& other);
  Particle & operator=(const Particle & other);

  //!
  //!Print the properties of this particle on the given output stream. The output properties do not
  //!include decay properties.
  //!
  void print(ostream & output=cout, int style=0, int size=20);

  //!
  //! Clear all variables held by this particle
  //!
  void clear();
  
  //!
  //! Reset this particle
  //!
  void reset();

  //!
  //! Set the ParticleType of this particle.
  //!
  void setType(ParticleType * _type) { type = _type;   }
  
  
  //!
  //! Get the ParticleType of this particle.
  //!
  ParticleType & getType() const     { return *type;   }

  ParticleType * getTypePtr() const     { return type;   }

  
  //!
  //! Set the ParticleType of this particle, its 4-momentum and 4-position of origin, as well as whether the particle
  //! is live or "decayed"
  //!
  //! @param type: Pointer to the type of this particle (ParticleType)
  //! @param p_x : momentum of the particle along the x-axis
  //! @param p_y : momentum of the particle along the y-axis
  //! @param p_z : momentum of the particle along the z-axis
  //! @param p_e : energy of the particle
  //! @param x : position  of the origin of the particle along the x-axis
  //! @param y : position  of the origin of the particle along the y-axis
  //! @param z : position  of the origin of the particle along the z-axis
  //! @param t : time when the particle was created/produced.
  //! @param live: whether the particle is considered "live" or "dead" (decayed)
  //!
  void set(ParticleType * type,
           double p_x, double p_y, double p_z, double p_e,
           double x,   double y,   double z,   double t,
           bool live=true);

  //!
  //! Set the ParticleType of this particle, its 4-momentum and 4-position of origin, as well as whether the particle
  //! is live or "decayed"
  //! @param type: Pointer to the type of this particle (ParticleType)
  //! @param momentum : 4-momentum of the particle
  //! @param position : 4-position  of the origin of the particle
  //! @param live: whether the particle is considered "live" or "dead" (decayed)
  //!
  void set(ParticleType * type,
           LorentzVector & momentum,
           LorentzVector & position,
           bool live=true);

  //!
  //! Set the ParticleType of this particle, its 4-momentum,  an array of pointers to its parent, as well as  a live or "decayed"
  //! status.
  //!
  //! @param type: Pointer to the type of this particle (ParticleType)
  //! @param momentum: 4-momentum of the particle
  //! @param parent:  pointer to the parent of this particle if from decay.
  //! @param live: whether the particle is considered "live" or "dead" (decayed)
  //!
  void set(ParticleType * type,
           LorentzVector & momentum,
           Particle* parent,
           bool live=true);

  //!
  //! Set the pid of this particle and  its 4-momentum components.
  //!
  //! @param pid: The type id of this particle
  //! @param p_x : momentum of the particle along the x-axis
  //! @param p_y : momentum of the particle along the y-axis
  //! @param p_z : momentum of the particle along the z-axis
  //! @param p_e : energy of the particle
  //!
  void setPidPxPyPzE(long _Pid, double p_x, double p_y, double p_z, double p_e);

  //!
  //! Get the 4-momentum of this particle (as a LorentzVector reference)
  //!
  const LorentzVector & getMomentum() const { return momentum;  }

  //!
  //! Get a changeable reference to the  4-momentum vector of this particle (as a LorentzVector reference)
  //!
  LorentzVector & getMomentum() { return momentum;  }
  
  //!
  //! Set the  4-momentum vector of this particle based on its four components.
  //!
  void setPxPyPzE(double p_x, double p_y, double p_z, double p_e)
  {  momentum.SetPxPyPzE(p_x,p_y,p_z,p_e);  }

  //!
  //! Set the  4-momentum vector of this particle based on a LorentzVector object
  //!
  void setPxPyPzE(const LorentzVector & _momentum)           { momentum = _momentum;  }
  
  //!
  //! Set the  4-momentum vector of this particle based on a LorentzVector object
  //!
  void setMomentum(const LorentzVector & _momentum)          { momentum = _momentum;  }

  //!
  //! Get the  4-position  vector of this particle as a changeable LorentzVector object
  //!
  LorentzVector & getPosition()     { return position;  }

  //!
  //! Get the  4-position  vector of this particle as a read only LorentzVector object
  //!
  const LorentzVector & getPosition() const{ return position;  }

  //!
  //! Set the  4-position  vector of this particle based on its components x, y, z, and t.
  //!
  void setXYZT(double x, double y, double z, double t)  { position.SetPxPyPzE(x,y,z,t); }

  //!
  //! Set the  4-position  vector of this particle based on the given LorentzVector.
  //!
  void setXYZT(const LorentzVector & _position)        { position = _position; }

  //!
  //! Set the  4-position  vector of this particle based on the given LorentzVector.
  //!
  void setPosition(const LorentzVector & _position)    { position = _position; }

  //!
  //! Set the  4-position  vector of this particle based on the given radius (distance from origin), polar angle
  //! theta, azimuth phi and time t.
  //!
  void setRThetaPhiT(double _r, double _theta, double _phi,double _t);

  //!
  //! Set the  4-position  vector of this particle based on the given radius (distance from origin), cosine of the polar angle
  //! theta, azimuth phi and time t.
  //!
  void setRCosThetaPhiT(double _r, double _cosTheta, double _phi,double _t);

  //!
  //! Shift the 4-position coordinates of origin of this particle by the given (LorentzVector) vector.
  //!
  void shift(const LorentzVector & dX)                 { position += dX;}

  //!
  //! Shift the 4-position coordinates of origin of this particle by the four given components.
  //!
  void shift(double dx, double dy, double dz, double dt)
  {
  LorentzVector dX(dx,dy,dz,dt);
  position += dX;
  }

  //!
  //!Set the PID of this particle according to the given identifier.
  //!
  void setPid(long _pid)             { pid = _pid;        }


  //!
  //!Get the PID of this particle.
  //!
  long getPid() const                { return pid;        }

  //!
  //!Set the decayed (live status) of this particle.
  //!
  void setDecayed(bool decayed)      { live = !decayed;   }

  //!
  //!Return "true" if this particle has decayed.
  //!
  bool isDecayed() const { return !live;      }

  //!
  //!Return "true" if this particle is stable for the intent and purpose of the simulation in progress
  //!
  bool isStable() const { if (type) return type->isStable(); else return true; }

  //!
  //!Return "true" if this particle is disabled for the intent and purpose of the simulation in progress
  //!
  bool isDisabled() const { if (type) return type->isStable(); else return true; }



  //!
  //!Set this particle as "wounded", i.e., meaning that it has interacting and is thus removed from the pool of
  //!measurable particles.
  //!
  void setWounded(bool wounded)      { live = !wounded;   }

  //!
  //!Set this particle as "wounded", i.e., meaning that it has interacting and is thus removed from the pool of
  //!measurable particles.
  //!
  void setInteracted(bool interacted){ live = !interacted;}

  //!
  //!Return "true" if this particle is considered wounded and is thus no longer measurable.
  //!
  bool isWounded() const             { return !live;      }

  //!
  //!Return "true" if this particle is considered to have interacted and is thus no longer measurable.
  //!
  bool hasInteracted() const         { return !live;      }

  //!
  //!Return "true" if this particle is considered measurable.
  //!
  bool isLive() const                { return live;       }

  //!
  //!Set the live status of this particle to true if it  is considered measurable.
  //!
  void setLive(bool _live)           { live =_live;       }


  //!
  //!Set the index of the source of this particle to the given value.
  //!
  void setSourceIndex(int _sourceIndex) { sourceIndex = _sourceIndex; }

  //!
  //!Get the index of the source of this particle.
  //!
  int  getSourceIndex()  const       { return sourceIndex; }

  //!
  //!Boost the velocity of this particle according to the given components of a velocity 3-vector.
  //!
  void boost(double ax, double ay, double az);

  //!
  //!Boost the velocity of this particle along the beam direction based on the given boost value.
  //!
  void boostRapidity(double boost);

  //!
  //!Compute and return the square of the 3D distance to the given particle.
  //!
  virtual double distanceXYZSq(Particle * otherParticle) const;

  //!
  //!Compute and return the   3D distance to the given particle.
  //!
  virtual double distanceXYZ(Particle * otherParticle) const;
  
  //!
  //!Compute and return the square of the 2D transverse distance to the given particle.
  //!
  virtual double distanceXYSq(Particle * otherParticle) const;
 
  //!
  //!Compute and return the  2D transverse distance to the given particle.
  //!
  virtual double distanceXY(Particle * otherParticle) const;

  //!
  //!Return true if this particle is a primary particle (i.e., not  produced by the decay of another particle).
  //!
  bool isPrimary() const;

  //!
  //!Return true if this particle is a secondary particle (i.e., produced by the decay of another particle).
  //!
  bool isSecondary() const;

  //!
  //!Return true if this object instance  is either a  neutron or a proton (i.e., a nucleon)
  //!
  bool isNucleon()  const        { return type->isNucleon();        }

  //!
  //!Return true if this object instance  is either a proton.
  //!
  bool isProton()  const         { return type->isProton();         }

  //!
  //!Return true if this object instance  is either a neutron.
  //!
  bool isNeutron()  const        { return type->isNeutron();        }

  //!
  //!Return true if this object instance  is either a photon.
  //!
  bool isPhoton()  const         { return type->isPhoton();         }

  //!
  //!Get the name of this particle (object)
  //!
  String getName()
  {
  if (type)
    return type->getName();
  else
    return "UnknownType";
  }

  //!
  //!Return true if this particle  has a parent.
  //!
  bool hasParent() const
  {
  return parent!=nullptr;
  }


  //!
  //!Set the parent of this particle.
  //!
  void setParent(Particle * parent);

  //!
  //!Return true if this particle has children.
  //!
  bool hasChildren() const
  {
  return children.size()>0;
  }

  //!
  //!Return the number of children this particle has spawned.
  //!
  unsigned int getNChildren() const
  {
  return children.size();
  }

  //!
  //!Return a pointer to the child at the given index.
  //!
  Particle * getChildAt(unsigned int index)
  {
  if (index < children.size())
    return children[index];
  else
    return nullptr;
  }

  //!
  //!Get an immutable array of children produced by this particle.
  //!
  const vector<Particle*> & getChildren() const
  {
    return children;
  }

  //!
  //!Get a mutable array of children produced by this particle.
  //!
  vector<Particle*> & getChildren()
  {
  return children;
  }

  //!
  //!Add the given particle as one of the children of this particle.
  //!
  void addChild(Particle* child);

  //!
  //!Add the given two given particles as children of this particle.
  //!
  void addChildren(Particle* child1, Particle* child2);

  //!
  //!Add the given three given particles as children of this particle.
  //!
  void addChildren(Particle* child1, Particle* child2, Particle* child3);

  //!
  //!Add the given the given array of particles  as children of this particle.
  //!
  void addChildren(const vector<Particle*> &  children);

  //!
  //!Identify the true particle represented by this particle as the given particle. This is useful in simulations of the performance
  //!of a detection device.
  //!
  void setTruth(Particle * _truth)  { truth = _truth;         }

  //!
  //!Get the true particle this particle is mimicing.
  //!
  Particle * getTruth() const       { return truth;           }


  //!
  //!Return true is this particle has a "parent" true particle.
  //!
  bool hasTruth() const             { return truth!=nullptr;  }

protected:

  LorentzVector momentum;   //!< 4-momentum of the particle
  LorentzVector position;   //!< 4-position of the particle
  ParticleType * type;      //!< type of this particle
  Particle* parent;         //!< if from decay
  vector<Particle*> children; //!< array containing the children of this particle.
  Particle * truth;  //!< pointer to the truth particle corresponding to this particle.
  bool live; //!< whether this particle is live or dead (measurable or not)
  long pid;  //!< used defined identified used in some applications
  int  sourceIndex;  //!<  source index  used in some applications

public:
  int   ixEtaPhi, ixYPhi;

public:
  static int factorySize;
  static Factory<Particle> * factory;
  static Factory<Particle> * getFactory();
  static void resetFactory();
  static void clearFactory();

  //!
  //!Get a proton object singleton
  //!
  static Particle * getProton();

  //!
  //!Get a neutron  object singleton
  //!
  static Particle * getNeutron();

  ClassDef(Particle,0)

};

} // namespace CAP

#endif /* CAP__Particle */
