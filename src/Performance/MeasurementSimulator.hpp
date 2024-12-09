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
#ifndef CAP__MeasurementSimulator
#define CAP__MeasurementSimulator
#include "EventTask.hpp"
#include "ResolutionFunction.hpp"

namespace CAP
{


//!
//! Task used to (fast) simulate the performance of measurement devices.
//! This is NOT a full performance simulator such as GEANT.  Instead, it uses
//! simplified models of (a) the efficiency of detection for the particles of interest in the measurement(s) and
//! (b) it simulates the measurement performance, i.e., the bias and resolution of the measurements
//! with fast simulators. The task first reviews which particles are accepted and considered "measured" using filters  implementing
//! the ParticleFilterEfficiency class. If accepted, particles are submitted to a smearer implementing the ParticleSimulator
//! class and the momentum (pt, eta, and phi) of each accepted/detected particle is then smeared.
//! Particles that are accepted and smeared are inserted in event stream 1 (generator level particles are in stream 0).
//! It is then possible for performance analysis tasks to direct compare particles of the two stream,
//! carry out closure tests and so on.
//!
//!Configuration parameters of the MeasurementSimulator class are as follows
//!
//!
//!
class MeasurementSimulator : public EventTask
{
public:
  
  MeasurementSimulator();
  MeasurementSimulator(const MeasurementSimulator & task);
  MeasurementSimulator & operator=(const MeasurementSimulator & task);
  virtual ~MeasurementSimulator() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void smearMomentum(const LorentzVector &in, LorentzVector & out);
  virtual void scaleHistograms();

protected:

 

  ResolutionFunction ptFunction;
  ResolutionFunction etaFunction;
  ResolutionFunction phiFunction;

  ClassDef(MeasurementSimulator,0)
};

} // namespace CAP


#endif /* CAP__MeasurementSimulator */
