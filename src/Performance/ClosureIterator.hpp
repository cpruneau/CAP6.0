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
#ifndef CAP__ClosureIterator
#define CAP__ClosureIterator
#include "HistogramTask.hpp"

namespace CAP
{

//!
//!Task performs a closure test
//!
class ClosureIterator : public HistogramTask
{
public:
  ClosureIterator();
  virtual ~ClosureIterator() {}
  virtual void setDefaultConfiguration();
  virtual void execute();
  ClassDef(ClosureIterator,0)
};

} // namespace CAP

#endif /* CAP__ClosureIterator */
