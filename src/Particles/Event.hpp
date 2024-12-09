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
#ifndef CAP__Event
#define CAP__Event
#include "Aliases.hpp"
#include "Exceptions.hpp"
#include "Particle.hpp"
#include "Properties.hpp"
#include "Manager.hpp"
namespace CAP
{

class Event;

template <class Event> class Manager;

//!
//! Class encupsalting all components of events (real data or monte carlo)
//!
class Event
{
protected:

  //!
  //! Constructor is protected. Use the static function getEventStream() to obtain instances of this class.
  //!
  Event();

  public:

  virtual ~Event();

  //!
  //! Clear the event as an empty event
  //!
  virtual void clear();

  //!
  //! Reset the event as an empty event
  //!
  virtual void reset();

  //!
  //! Add the given particle to this  event
  //!
  virtual void addParticle(Particle * particle);

  //!
  //! Return a vector of all the particles stored in this event.
  //!
  vector<Particle*> & getParticles();

  //!
  //! Return a constant vector of all the particles stored in this event.
  //!
  const vector<Particle*> & getParticles() const;

  //!
  //! Return to the particle at position "index" in this event. A null pointer is returned is index exceeds the
  //!  number of particles in this event.
  //!
  Particle * getParticleAt(unsigned long index);

  void printParticles(ostream & output=std::cout, int style=0, int size=20) const;

  void print(ostream & output=std::cout, int style=0, int size=20);


  //!
  //! Return the index of this event. The event index might correspond to the position of the event
  //! in the production or input stream.
  //!
  unsigned long getEventIndex() const      { return eventIndex;  }

  //!
  //! Return the name of this event. The name might be used for retrival. Common event stream names
  //! might be Generator, PYTHIA, RECO etc. The names are set by the user.
  //!
  String getEventName() const      { return eventName;  }

  //!
  //! Return the event number of this event. The event number might correspond to a tag or index given
  //! to this event externally by some other  production or input stream.
  //!
  unsigned long getEventNumber() const     { return eventNumber; }

  //!
  //! Return the number of particles stored in this event.
  //!
  unsigned long  getNParticles() { return particles.size();}

  Particle & getProjectileA() { return projectileA; }
  Particle & getProjectileB() { return projectileB; }


  //!
  //! Increment the index of this event.
  //!
  void incrementEventIndex()      { eventIndex++;       }

  //!
  //! Set the index of this event.
  //!
  void setEventIndex(unsigned long index)  { eventIndex  = index;}

  //!
  //! Set the event number of this event.
  //!
  void setEventNumber(unsigned long number){ eventNumber = number;}

  double getCl0() const { return cl0; }
  double getCl1() const { return cl1; }
  double getCl2() const { return cl2; }
  double getCl3() const { return cl3; }
  double getCl4() const { return cl4; }
  double getMult0() const { return mult0; }
  double getMult1() const { return mult1; }
  double getMult2() const { return mult2; }
  double getMult3() const { return mult3; }
  double getMult4() const { return mult4; }
  double getSpherocity0() const { return spherocity0; }
  double getSpherocity1() const { return spherocity1; }
  double getSpherocity2() const { return spherocity2; }
  double getSpherocity3() const { return spherocity3; }
  double getSpherocity4() const { return spherocity4; }
  double getEnergy0() const { return energy0; }
  double getEnergy1() const { return energy1; }
  double getEnergy2() const { return energy2; }
  double getEnergy3() const { return energy3; }
  double getEnergy4() const { return energy4; }


  void setCl0(double value) { cl0 = value; }
  void setCl1(double value) { cl1 = value; }
  void setCl2(double value) { cl2 = value; }
  void setCl3(double value) { cl3 = value; }
  void setCl4(double value) { cl4 = value; }
  void setMult0(double value) { mult0 = value; }
  void setMult1(double value) { mult1 = value; }
  void setMult2(double value) { mult2 = value; }
  void setMult3(double value) { mult3 = value; }
  void setMult4(double value) { mult4 = value; }
  void setSpherocity0(double value) { spherocity0 = value; }
  void setSpherocity1(double value) { spherocity1 = value; }
  void setSpherocity2(double value) { spherocity2 = value; }
  void setSpherocity3(double value) { spherocity3 = value; }
  void setSpherocity4(double value) { spherocity4 = value; }
  void setEnergy0(double value) { energy0 = value; }
  void setEnergy1(double value) { energy1 = value; }
  void setEnergy2(double value) { energy2 = value; }
  void setEnergy3(double value) { energy3 = value; }
  void setEnergy4(double value) { energy4 = value; }

  friend Manager<Event>;

protected:

  String eventName;
  unsigned long eventIndex;
  unsigned long eventNumber;
  Particle projectileA;
  Particle projectileB;
  vector<Particle*> particles;

  double cl0, cl1, cl2, cl3, cl4;
  double mult0, mult1, mult2, mult3, mult4;
  double spherocity0, spherocity1, spherocity2, spherocity3, spherocity4;
  double energy0, energy1, energy2, energy3, energy4;

  ClassDef(Event,0)
};

} //namespace CAP

#endif /* Event */
