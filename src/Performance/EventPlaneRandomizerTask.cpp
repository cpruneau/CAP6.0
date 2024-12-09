/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
 *
 * *********************************************************************/
#include "EventPlaneRandomizerTask.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "MathConstants.hpp"

ClassImp(CAP::EventPlaneRandomizerTask);

namespace CAP
{

EventPlaneRandomizerTask::EventPlaneRandomizerTask()
:
EventTask()
{
  appendClassName("EventPlaneRandomizerTask");
  setName("EventPlaneRandomizerTask");
  setTitle("EventPlaneRandomizerTask");
}

void EventPlaneRandomizerTask::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
}

void EventPlaneRandomizerTask::execute()
{
  double eventAngle= CAP::Math::twoPi() * gRandom->Rndm();
  Event & event = *Manager<Event>::getObjectAt(0);
  vector<Particle*> particles = event.getParticles();
  for (auto & particle : particles)
    {
    particle->getPosition().RotateZ(eventAngle);
    particle->getMomentum().RotateZ(eventAngle);
    }
}

} // namespace CAP
