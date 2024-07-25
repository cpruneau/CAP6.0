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
#ifndef CAP__SpherocityCalculator
#define CAP__SpherocityCalculator
#include "EventTask.hpp"
#include "SpherocityExceptions.hpp"

namespace CAP
{

//!
//!Task performing a transverse spherocity analysis of events of the incoming event stream.
//!
class SpherocityCalculator : public EventTask
{
public:
  
  SpherocityCalculator();
  SpherocityCalculator(const SpherocityCalculator & calculator);
  virtual ~SpherocityCalculator() {}
  SpherocityCalculator & operator=(const SpherocityCalculator & calculator);
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);

protected:
  
  bool fillS0;     //!< Whether the regular spherocity observable S0 should be analyzed and filled by this task.
  bool fillS1;     //!< Whether the unit vector spherocity observable S1 should be analyzed and filled by this task.
  bool fillS1VsS0; //!< Whether two-dimensional S1 vs S0 histograms should be filled.
  int    nSteps;   //!< Number of azimuthal steps used in the calculation of the transverse spherocity.
  double stepSize; //!< Two-pi/nSteps.

  ClassDef(SpherocityCalculator,0)
};

} //namespace CAP


#endif /* CAP__SpherocityCalculator */
