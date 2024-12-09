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
#ifndef CAP__TaskAccountant
#define CAP__TaskAccountant
#include "Aliases.hpp"
#include "TFile.h"

namespace CAP
{

class TaskAccountant
{
public:

  TaskAccountant();
  TaskAccountant(const TaskAccountant & analyzer);
  TaskAccountant & operator=(const TaskAccountant & task);
  virtual ~TaskAccountant();
  virtual void reset();
  virtual void clear();
  virtual void increment();
  virtual long getNExecuted() const;
  virtual void print(std::ostream & os=std::cout, int style=0, int size=50) const;

  virtual void exportNEexecutedTask(TFile & outputFile);
  virtual long importNEexecutedTask(TFile & inputFile);


protected:
  
  long nTaskExecuted;

  ClassDef(TaskAccountant,0)
};

} // namespace CAP

#endif /* CAP__TaskAccountant */
