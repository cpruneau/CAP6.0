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
  if (getNConditions()<1) return true;
  bool accepting = false;

  for (auto & condition : conditions)
    {
    int  subtype = condition->conditionSubtype;
    switch (subtype)
      {
        case kCl0:  accepting = condition->accept( event.getCl0() );     break;
        case kCl1:  accepting = condition->accept( event.getCl1() );     break;
        case kCl2:  accepting = condition->accept( event.getCl2() );     break;
        case kCl3:  accepting = condition->accept( event.getCl3() );     break;
        case kCl4:  accepting = condition->accept( event.getCl4() );     break;
        case kMult0:  accepting = condition->accept( event.getMult0() );     break;
        case kMult1:  accepting = condition->accept( event.getMult1() );     break;
        case kMult2:  accepting = condition->accept( event.getMult2() );     break;
        case kMult3:  accepting = condition->accept( event.getMult3() );     break;
        case kMult4:  accepting = condition->accept( event.getMult4() );     break;
        case kSphero0:  accepting = condition->accept( event.getSpherocity0() );     break;
        case kSphero1:  accepting = condition->accept( event.getSpherocity1() );     break;
        case kSphero2:  accepting = condition->accept( event.getSpherocity2() );     break;
        case kSphero3:  accepting = condition->accept( event.getSpherocity3() );     break;
        case kSphero4:  accepting = condition->accept( event.getSpherocity4() );     break;
        case kEnergy0:  accepting = condition->accept( event.getEnergy0() );     break;
        case kEnergy1:  accepting = condition->accept( event.getEnergy1() );     break;
        case kEnergy2:  accepting = condition->accept( event.getEnergy2() );     break;
        case kEnergy3:  accepting = condition->accept( event.getEnergy3() );     break;
        case kEnergy4:  accepting = condition->accept( event.getEnergy4() );     break;
      }
    if (!accepting)  return false;
    }
    return true;
}

} // namespace CAP
