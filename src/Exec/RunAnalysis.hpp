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
#ifndef CAP__RunAnalysis
#define CAP__RunAnalysis
#include "HistogramTask.hpp"
using std::vector;

namespace CAP
{
class RunAnalysis : public HistogramTask
{
public:
  
  RunAnalysis();
  RunAnalysis(const RunAnalysis & task);
  virtual ~RunAnalysis() {}
  RunAnalysis & operator=(const RunAnalysis & task);
  virtual void setDefaultConfiguration();
  virtual void configure();
  void execute();

protected:

  Task * createTask(const String & taskTypeName);

  Task * createTask(Task *parent,
                    const String & taskReferenceName,
                    Configuration & requestedConfiguration);

  ClassDef(RunAnalysis,0)
};

}

#endif /* CAP_RunAnalysis */


