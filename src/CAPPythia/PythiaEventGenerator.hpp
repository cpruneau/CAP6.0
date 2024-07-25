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
#ifndef CAP__PythiaEventGenerator
#define CAP__PythiaEventGenerator
#include "Pythia.h"
#include "EventTask.hpp"

namespace CAP
{

class PythiaEventGenerator : public EventTask
{
public:

  PythiaEventGenerator();
  PythiaEventGenerator(const PythiaEventGenerator & task);
  virtual ~PythiaEventGenerator() {}
  PythiaEventGenerator & operator=(const PythiaEventGenerator & task);
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void finalize();

protected:
  
  Pythia8::Pythia * pythia;

  ClassDef(PythiaEventGenerator,0)
};

}

#endif /* CAP__PythiaEventGenerator */
