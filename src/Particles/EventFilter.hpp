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
#ifndef CAP__EventFilter
#define CAP__EventFilter
#include "Event.hpp"
#include "Filter.hpp"

namespace CAP
{
class EventFilter : public Filter<Event>
{
public:
  EventFilter();
  EventFilter(const EventFilter & source);
  EventFilter & operator=(const EventFilter & source);
  virtual ~EventFilter();
  virtual bool accept(const Event & event);
  virtual void reset() {}
  virtual void clear() {}

  enum EventFilterType      { kAll, kMB, kCl0, kCl1, kCl2,  kCl3, kCl4, kMult0, kMult1, kMult2, kMult3, kMult4, kSphero0,kSphero1,kSphero2,kSphero3,kSphero4,kEnergy0,kEnergy1,kEnergy2,kEnergy3,kEnergy4};

  ClassDef(EventFilter,0)
};

} // namespace CAP

#endif /* CAP__EventFilter */
