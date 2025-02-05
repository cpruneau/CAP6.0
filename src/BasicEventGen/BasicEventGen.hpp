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
#ifndef CAP__BasicEventGen
#define CAP__BasicEventGen
#include "EventTask.hpp"

namespace CAP
{

class BasicEventGen : public EventTask
{
public:

  BasicEventGen();
  BasicEventGen(const BasicEventGen & task);
  virtual ~BasicEventGen() {}
  BasicEventGen & operator=(const BasicEventGen & task);
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void finalize();

protected:

  int    pdgSelected;
  double multMin;
  double multMax;
  double rapidityMin;
  double rapidityMax;
  double ptSlope;
  double mass;
  double massSq;

  ParticleType * typeSelected;


  ClassDef(BasicEventGen,0)
};

}

#endif /* CAP__BasicEventGen */
