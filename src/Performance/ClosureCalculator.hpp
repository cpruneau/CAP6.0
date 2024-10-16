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
#ifndef CAP__ClosureCalculator
#define CAP__ClosureCalculator
#include "HistogramTask.hpp"


namespace CAP
{

class ClosureCalculator : public HistogramTask
{
  
public:
  
  ClosureCalculator();
  virtual ~ClosureCalculator() {}
  virtual void setDefaultConfiguration();
  virtual void execute();

protected:

  ClassDef(ClosureCalculator,0)
};

} // namespace CAP

#endif /* CAP__ClosureCalculator */
