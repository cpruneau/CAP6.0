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
#include "EventVertexRandomizerTask.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::EventVertexRandomizerTask);

namespace CAP
{
EventVertexRandomizerTask::EventVertexRandomizerTask()
:
EventTask(),
rConversion(0), tConversion(0),
xAvg(0), yAvg(0), zAvg(0), tAvg(0),
xRms(0), yRms(0), zRms(0), tRms(0)
{
  appendClassName("EventVertexRandomizerTask");
  setName("EventVertexRandomizerTask");
  setTitle("EventVertexRandomizerTask");
  setVersion("1.0");
}

//!
//! vertex position and size supplied in micro-meters.
//! vertex time is nanosecond relative to nominal crossing time
//! convert to fm for internal use: 1  micro-meter = 1E9 fm
//!
void EventVertexRandomizerTask::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("EventsUseStream0", true);
  addProperty("rConversion",      1.0E9);
  addProperty("tConversion",      1.0E9);
  addProperty("xAvg", 0.0);
  addProperty("yAvg", 0.0);
  addProperty("zAvg", 0.0);
  addProperty("tAvg", 0.0);
  addProperty("xRms", 100.0);
  addProperty("yRms", 100.0);
  addProperty("zRms", 5.0);
  addProperty("tRms", 10.0);
}

void EventVertexRandomizerTask::initialize()
{
  rConversion = configuration.getValueDouble(getName(),"rConversion");
  tConversion = configuration.getValueDouble(getName(),"tConversion");
  xAvg = configuration.getValueDouble(getName(),"xAvg");
  yAvg = configuration.getValueDouble(getName(),"yAvg");
  zAvg = configuration.getValueDouble(getName(),"zAvg");
  tAvg = configuration.getValueDouble(getName(),"tAvg");
  xRms = configuration.getValueDouble(getName(),"xRms");
  yRms = configuration.getValueDouble(getName(),"yRms");
  zRms = configuration.getValueDouble(getName(),"zRms");
  tRms = configuration.getValueDouble(getName(),"tRms");
}

void EventVertexRandomizerTask::execute()
{
  double eventX = gRandom->Gaus(rConversion*xAvg, rConversion*xRms);
  double eventY = gRandom->Gaus(rConversion*yAvg, rConversion*yRms);
  double eventZ = gRandom->Gaus(rConversion*zAvg, rConversion*zRms);
  double eventT = gRandom->Gaus(tConversion*tAvg, tConversion*tRms);
  Event & event = *Manager<Event>::getObjectAt(0);
  vector<Particle*> particles = event.getParticles();
  for (auto & particle : particles) particle->shift(eventX,eventY,eventZ,eventT);
}

} // namespace CAP
