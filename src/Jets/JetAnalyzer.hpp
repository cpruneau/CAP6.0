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
#ifndef CAP__JetAnalyzer
#define CAP__JetAnalyzer
#include "EventTask.hpp"

namespace CAP
{

class JetAnalyzer : public EventTask
{
public:

  JetAnalyzer();
  JetAnalyzer(const JetAnalyzer & task);
  JetAnalyzer & operator=(const JetAnalyzer & task);
  virtual ~JetAnalyzer() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void scaleHistograms();

protected:

  double jetRadius;

  ParticleDb * particleDb;

  ClassDef(JetAnalyzer,0)
};

} // namespace CAP

#endif /* CAP__JetAnalyzer */
