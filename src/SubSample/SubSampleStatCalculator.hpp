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
#ifndef CAP__SubSampleStatCalculator
#define CAP__SubSampleStatCalculator
#include "EventTask.hpp"
using namespace std;

namespace CAP
{


class SubSampleStatCalculator : public EventTask
{
public:
  
  SubSampleStatCalculator();
  virtual ~SubSampleStatCalculator() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void execute();

protected:

  long nEventsProcessed;   //!< Number of events processed in the current file
  long sumEventsProcessed; //!< Sum of the number of events processes.
  long * nEventsAccepted;    //!< Number of events accepted in the current file for each event filter
  long * sumEventsAccepted;  //!< Cumulated number of events accepted for each event filter

  ClassDef(SubSampleStatCalculator,0)
};

} // namespace CAP

#endif /* CAP__SubSampleStatCalculator */
