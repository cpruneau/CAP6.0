
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
#ifndef CAP__JetFilterCreator
#define CAP__JetFilterCreator
#include "FilterCreator.hpp"

namespace CAP
{
class JetFilterCreator
:
public FilterCreator
{

public:
  
  JetFilterCreator();
  JetFilterCreator(const JetFilterCreator & task);
  JetFilterCreator & operator=(const JetFilterCreator & task);
  virtual ~JetFilterCreator() {}

  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void finalize();

protected:

  void createJetFilter(const String & name,
                         const String & title,
                         const vector<String>  & conditionTypes,
                         const vector<String>  & conditionSubypes,
                         const vector<double>  & conditionMinima,
                         const vector<double>  & conditionMaxima,
                         const vector<double>  & conditionMinima2,
                         const vector<double>  & conditionMaxima2);

  ClassDef(JetFilterCreator,0)
};

}

#endif /* CAP_JetFilterCreator */


