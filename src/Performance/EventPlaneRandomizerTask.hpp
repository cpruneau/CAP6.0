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
#ifndef CAP__EventPlaneRandomizerTask
#define CAP__EventPlaneRandomizerTask
#include "EventTask.hpp"

namespace CAP
{


//!
//! This class implements a generic event plane randomizer. All particles composing an event are azimuthally rotated by a randome angle $\varphi$ generated event by event in the range $[0,2\pi]$.
//!  Event filters and particles filters may be used to tailor the bahvior of this randomizer.
//!
class EventPlaneRandomizerTask : public EventTask
{
public:
  EventPlaneRandomizerTask();
  virtual ~EventPlaneRandomizerTask() {}
  virtual void setDefaultConfiguration();
  virtual void execute();
  ClassDef(EventPlaneRandomizerTask,0)
};

} // namespace CAP

#endif /* CAP__EventPlaneRandomizerTask */
