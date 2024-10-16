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
#ifndef CAP__PtPtCalculator
#define CAP__PtPtCalculator
#include "EventTask.hpp"

namespace CAP
{
class PtPtCalculator : public EventTask
{
public:

  PtPtCalculator();
  PtPtCalculator(const PtPtCalculator & task);
  virtual ~PtPtCalculator();
  PtPtCalculator & operator=(const PtPtCalculator & task);
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void scaleHistograms();
 protected:
  ClassDef(PtPtCalculator,0)
};

} // namespace CAP

#endif /* CAP__PtPtCalculator */
