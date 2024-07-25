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
#ifndef CAP__EventManager
#define CAP__EventManager
#include "Event.hpp"

namespace CAP
{

//!
//!Class manages events used by a task
//!
class EventManager
{
protected:

  vector<String> eventNames;
  vector<Event*> events;
  vector<bool>   eventOwnerships;

  static vector<Event*> eventStore;

public:

  EventManager(unsigned int nEventManaged=0);
  EventManager(const EventManager & manager);
  EventManager & operator=(const EventManager & manager);
  virtual ~EventManager();


  void createEvent(const String & name="Event");
  void useEvent(const String & name="Event");
  Event & getEvent(unsigned int eventIndex=0);
  bool ownsEvent(unsigned int index=0);
  void resetEvent(unsigned int index=0);
  void clearEvent(unsigned int index=0);
  void deleteEvent(unsigned int index=0);

  void resetEvents();
  void clearEvents();
  void deleteEvents();

  static Event * createStoreEventNamed(const String & name);
  static Event * getStoreEventNamed(const String & name);
  static unsigned int getNStoreEvents();


  ClassDef(EventManager,0)
};




} // namespace CAP

#endif /* CAP__EventTask */
