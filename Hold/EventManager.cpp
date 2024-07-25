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
#include "EventManager.hpp"
#include "ParticlesExceptions.hpp"

ClassImp(CAP::EventManager);

namespace CAP
{

EventManager::EventManager(unsigned int nEventManaged)
:
events(),
ownEvents()
{
  allocateEvents(nEventManaged);
}

EventManager::EventManager(const EventManager & manager)
:
events(manager.events),
ownEvents(manager.ownEvents)
{   }

EventManager & EventManager::operator=(const EventManager & manager)
{
  if (this!=&manager)
    {
    events    = manager.events;
    ownEvents = manager.ownEvents;
    }
  return *this;
}


EventManager::~EventManager()
{
  deleteEvents();
}

void EventManager::setEventNames(const vector<String> & _eventNames)
{
  eventNames = _eventNames;
}

void EventManager::createEvent(const String & name)
{
  Event * event = EventManager::createEventStream(name);
  if (!event) throw NonExistingEventStreamException(name,__FUNCTION__);
  events.push_back(event);
  eventOwnerships.push_back(true);
}

void EventManager::useEvent(const  String &  name)
{
  Event * event = EventManager::getEventStream(name);
  if (!event) throw NonExistingEventStreamException(name,__FUNCTION__);
  events.push_back(event);
  eventOwnerships.push_back(false);
}

Event & EventManager::getEvent(unsigned int eventIndex)
{
  if (eventIndex>=events.size()) throw EventIndexException(eventIndex,events.size(),__FUNCTION__);
  return *(events[eventIndex]);
}

bool EventManager::ownsEvent(unsigned int index)
{
  if (index>=nEventStreams) throw EventIndexException(index,events.size(),__FUNCTION__);
  return eventOwnerships[index];
}


void EventManager::resetEvent(unsigned int index)
{
  if (!ownsEvent(index)) throw EventOwnershipException(index,__FUNCTION__);
  events[index]->reset();
}

void EventManager::clearEvent(unsigned int index)
{
  if (!ownsEvent(index)) throw EventOwnershipException(index,__FUNCTION__);
  events[index]->clear();
}

void EventManager::deleteEvent(unsigned int index)
{
  if (!ownsEvent(index)) throw EventOwnershipException(index,__FUNCTION__);
  events[index]->clear();
  events.erase(events.begin()+index);
}

void EventManager::resetEvents()
{
  for (unsigned int index = 0; index<events.size();index++)
    {
    if (ownsEvent(index)) resetEvent(index);
    }
}


void EventManager::clearEvents()
{
  for (unsigned int index = 0; index<events.size();index++)
    {
    if (ownsEvent(index)) clearEvent(index);
    }
}

void EventManager::deleteEvents()
{
  for (unsigned int index = 0; index<events.size();index++)
    {
    if (ownsEvent(index)) deleteEvent(index);
    }
}


// ----------------------------------------------------
// static variables and functions...
// ----------------------------------------------------

unsigned int EventManager::nEventStreams = 0;
vector<Event*> EventManager::eventStreams;

Event * EventManager::createEventStream(const String & name)
{
  Event * event = getEventStream(name);
  if (event) throw ExistingEventStreamException(name,__FUNCTION__);
  event = new Event();
  event->setName(name);
  eventStreams.push_back(event);
  return event;
}

Event * EventManager::getEventStream(const String & name)
{
  for (auto & eventStream : eventStreams)
    {
    if (eventStream->getName().EqualTo(name)) return eventStream;
    }
  return nullptr;
}

unsigned int EventManager::getNEventStreams()
{
  return nEventStreams;
}

} // namespace CAP



