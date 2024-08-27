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
#include "EventFilter.hpp"
#include "Manager.hpp"
ClassImp(CAP::Manager<CAP::Event>);
ClassImp(CAP::Filter<CAP::Event>);
ClassImp(CAP::EventFilter);

namespace CAP
{

EventFilter::EventFilter()
:
Filter<Event>()
{ /* no ops */}

EventFilter::EventFilter(const EventFilter & source)
:
Filter<Event>(source)
{ /* no ops */}

EventFilter & EventFilter::operator=(const EventFilter & source)
{
  if (this!=&source)
    {
    Filter<Event>::operator=(source);
    }
  return *this;
}


EventFilter::~EventFilter()
{ /* no ops */}

//!
//! accept/reject the given Event based on filter parameter
//!
bool EventFilter::accept(const Event & event)
{
//  printCR();
//  printCR();
//  printLine();
//  printValue("EventFilter::accept() filter name",getName());
//  printValue("EventFilter::accept() N properties",event.getProperties().size());
//  for (auto & property : event.getProperties())
//    {
//    property.print();
//    }
//  printValue("EventFilter::accept() getNConditions()",getNConditions());

  if (getNConditions()<1) return true;
  bool accepting = false;

  for (auto & condition : conditions)
    {
    const String & filterType    = condition->conditionType;
    const String & filterSubType = condition->conditionSubtype;
    if (filterType.EqualTo("GLOBAL"))
      {
      String keyword = "All_All_GLOBAL_";
      if (filterSubType.EqualTo("N"))
        accepting = condition->accept( event.getValueDouble(keyword+"N") );
      else if (filterSubType.EqualTo("E"))
        accepting = condition->accept( event.getValueDouble(keyword+"E") );
      else if (filterSubType.EqualTo("Q"))
        accepting = condition->accept( event.getValueDouble(keyword+"Q") );
      else if (filterSubType.EqualTo("S"))
        accepting = condition->accept( event.getValueDouble(keyword+"S") );
      else if (filterSubType.EqualTo("B"))
        accepting = condition->accept( event.getValueDouble(keyword+"B") );
      else if (filterSubType.EqualTo("PTSUM"))
        accepting = condition->accept( event.getValueDouble(keyword+"PTSUM") );
      }
    if (!accepting)  return false;
    }
    return true;
}

} // namespace CAP
