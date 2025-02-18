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
  virtual void printJets (const vector<fastjet::PseudoJet> & jets);

protected:

  double jetRadius;
  double jetPtMin;

  ParticleDb * particleDb;

  ClassDef(JetAnalyzer,0)
};

} // namespace CAP

#endif /* CAP__JetAnalyzer */
