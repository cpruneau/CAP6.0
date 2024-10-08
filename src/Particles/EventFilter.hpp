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

  ClassDef(EventFilter,0)
};

} // namespace CAP

#endif /* CAP__EventFilter */
