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
#ifndef CAP__EventVertexRandomizerTask
#define CAP__EventVertexRandomizerTask
#include "EventTask.hpp"

namespace CAP
{

//!
//! \class Task
//! \ingroup CAP

//! This class implements a generic event vertex  randomizer.
//! The event vertex is shifted arbitrary from its (0,0,0,0) nominal position, in the center of momentum frame of a collision, to a random location (t,x,y,z) chosen randomly
//! according to a specific randomization model (Gaussian) and determined by parameters selected at initialization.  The Gaussian randomization produces means
//! xAvg, yAvg, zAvg, and tAvg and assumes rms values xRms, yRms, zRms, tRms. These parameter values must be set using a configuration object submitted at construction
//! of a class instance.
//!
class EventVertexRandomizerTask : public EventTask
{
public:
  
  EventVertexRandomizerTask();
  virtual ~EventVertexRandomizerTask() {}
  virtual void setDefaultConfiguration();
  virtual void initialize();
  virtual void execute();
  
protected:
  
  double rConversion;
  double tConversion;
  double xAvg; //!< mean vertex position along the x-axis
  double yAvg; //!< mean vertex position along the y-axis
  double zAvg; //!< mean vertex position along the z-axis
  double tAvg; //!< mean vertex position along the t-axis
  double xRms; //!< rms of the vertex distribution along the x-axis
  double yRms; //!< rms of the vertex distribution along the y-axis
  double zRms; //!< rms of the vertex distribution along the z-axis
  double tRms; //!< rms of the vertex distribution along the t-axis
  
  ClassDef(EventVertexRandomizerTask,0)
};

} // namespace CAP

#endif /* CAP__EventVertexRandomizerTask */
