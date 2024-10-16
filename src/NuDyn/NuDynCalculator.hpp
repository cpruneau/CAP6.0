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
#ifndef CAP__NuDynCalculator
#define CAP__NuDynCalculator
#include "EventTask.hpp"

namespace CAP
{
class NuDynCalculator : public EventTask
{
public:

  NuDynCalculator();
  NuDynCalculator(const NuDynCalculator & task);
  virtual ~NuDynCalculator();
  NuDynCalculator & operator=(const NuDynCalculator & task);
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void scaleHistograms();

 protected:
  ClassDef(NuDynCalculator,0)
};

} // namespace CAP

#endif /* CAP__NuDynCalculator */
