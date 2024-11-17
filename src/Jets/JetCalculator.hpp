/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Akash Raj
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau, Akash Raj,  Nov 2024
 *
 * *********************************************************************/
#ifndef CAP__JetCalculator
#define CAP__JetCalculator
#include "EventTask.hpp"

namespace CAP
{

class JetCalculator : public EventTask
{
public:

  JetCalculator();
  JetCalculator(const JetCalculator & task);
  JetCalculator & operator=(const JetCalculator & task);
  virtual ~JetCalculator() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void scaleHistograms();

protected:

  ClassDef(JetCalculator,0)
};

} // namespace CAP

#endif /* CAP__JetCalculator */
