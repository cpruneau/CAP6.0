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
#ifndef CAP__ParticleDecayerTask
#define CAP__ParticleDecayerTask
#include "ParticleDecayer.hpp"
#include "EventTask.hpp"
#include "Event.hpp"
#include "Particle.hpp"
#include "ParticleType.hpp"

namespace CAP
{

//!
//! Task handles the decay of all decayable particles in the incoming event stream. At execution time, i.e., for each event encountered,
//! each particle of the input stream is examined to determine whether it should be decayed. Particle deemed decayable are passed to the
//! decay handler (decayer) and decayed.  Currently, the decayer handles two and three particle decays. Decayed particles are kept in the
//! event stream but tagged as decayed. Child particles are inserted in the stream and tagged as "live" (undecayed).  Child particles that
//! are themselves decayable are decayed iteratively. 
//!
class ParticleDecayerTask : public EventTask
{
public:

  ParticleDecayerTask();
  virtual ~ParticleDecayerTask() {}
  virtual void setDefaultConfiguration();
  virtual void execute();
  
  //!
  //!Get the decay handle (decayer) used by this task.
  //!
  ParticleDecayer & getParticleDecayer() { return decayer;}


protected:

  ParticleDecayer decayer; //!< Particle decay handler



  ClassDef(ParticleDecayerTask,0)
};

}

#endif /* CAP__ParticleDecayerTask */
