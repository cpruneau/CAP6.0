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
#ifndef CAP__SubSampleStatCalculator
#define CAP__SubSampleStatCalculator
#include "EventTask.hpp"
using namespace std;

namespace CAP
{

//!\brief Calculation of statistical errors with the subsample technique
//!
//!\details
//!# SubSampleStatCalculator
//!
//!\author C. Pruneau
//!\version 1.0
//!\date May 18, 2022
//!
//!Task calculates the statistical errors of all histograms of the selected files based on the subsample method.
//!The input file are selected based on a name template. All files read are assumed to have the same histogram structure (named objects).
//!They are read sequentially and added into a new histogram collection. The summed collection is then used to computed rms deviates
//!which are then set as errors in the histograms saved on output. The name of the output file is generated based on the template name
//!and a selected appendString name. This class should NOT be run as a subtask of a more complex task in its current form.
//!
//!
//!
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

  int    defaultGroupSize;
  int    nInputFile;
  int    maximumDepth;
  int    nEventFilters;
  ClassDef(SubSampleStatCalculator,0)
};

} // namespace CAP

#endif /* CAP__SubSampleStatCalculator */
