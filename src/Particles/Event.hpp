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
class Event : public Properties
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

  friend Manager<Event>;

protected:

  String eventName;
  unsigned long eventIndex;
  unsigned long eventNumber;
  Particle projectileA;
  Particle projectileB;
  vector<Particle*> particles;

  ClassDef(Event,0)
};

} //namespace CAP

#endif /* Event */
