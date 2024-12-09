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
#ifndef CAP__EnvironmentVariables
#define CAP__EnvironmentVariables
#include "TClass.h"
#include "Aliases.hpp"
#include "Properties.hpp"

namespace CAP
{

class EnvironmentVariables
{
public:

  EnvironmentVariables();
  EnvironmentVariables(const EnvironmentVariables & task);
  EnvironmentVariables & operator=(const EnvironmentVariables & task);
  virtual ~EnvironmentVariables() {}
  void initialize();
  void print(std::ostream & os=std::cout, int style=0, int size=50) const;
  String getEnvVariable(const char* aKeyword) const;
  void  addEnvVariable(const char* aKeyword, const char* aValue);

protected:

  Properties variables;

  ClassDef(EnvironmentVariables,0)
};

}

#endif /* CAP__Task */
