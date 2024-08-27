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
#include "TSystem.h"
#include "TSystemDirectory.h"
#include "TSystemFile.h"
#include "EnvironmentVariables.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::EnvironmentVariables);

namespace CAP
{

EnvironmentVariables::EnvironmentVariables()
:
variables()
{
  initialize();
}

EnvironmentVariables::EnvironmentVariables(const EnvironmentVariables & env)
:
variables(env.variables)
{    }

EnvironmentVariables & EnvironmentVariables::operator=(const EnvironmentVariables & env)
{
  if (this!=&env)
    {
    variables = env.variables;
    }
  return *this;
}

void EnvironmentVariables::initialize()
{
  // fetch required env variables from the system
  // store them for easy later retrieval
  variables.addProperty("CAP_DATABASE_PATH",      getenv("CAP_DATABASE_PATH"));
  variables.addProperty("CAP_PROJECTS_PATH",      getenv("CAP_PROJECTS_PATH"));
  variables.addProperty("CAP_DATA_IMPORT_PATH",   getenv("CAP_DATA_IMPORT_PATH"));
  variables.addProperty("CAP_DATA_EXPORT_PATH",   getenv("CAP_DATA_EXPORT_PATH"));
  variables.addProperty("CAP_HISTOS_IMPORT_PATH", getenv("CAP_HISTOS_IMPORT_PATH"));
  variables.addProperty("CAP_HISTOS_EXPORT_PATH", getenv("CAP_HISTOS_EXPORT_PATH"));
  variables.addProperty("CAP_CALIB_IMPORT_PATH",  getenv("CAP_CALIB_IMPORT_PATH"));
  variables.addProperty("CAP_CALIB_EXPORT_PATH",  getenv("CAP_CALIB_EXPORT_PATH"));
}

void EnvironmentVariables::print(std::ostream & os, int style, int size) const
{
  printValue("CAP_DATABASE_PATH",      variables.getValueString("CAP_DATABASE_PATH"),os,style,size);
  printValue("CAP_PROJECTS_PATH",      variables.getValueString("CAP_PROJECTS_PATH"),os,style,size);
  printValue("CAP_DATA_IMPORT_PATH",   variables.getValueString("CAP_DATA_IMPORT_PATH"),os,style,size);
  printValue("CAP_DATA_EXPORT_PATH",   variables.getValueString("CAP_DATA_EXPORT_PATH"),os,style,size);
  printValue("CAP_HISTOS_IMPORT_PATH", variables.getValueString("CAP_HISTOS_IMPORT_PATH"),os,style,size);
  printValue("CAP_HISTOS_EXPORT_PATH", variables.getValueString("CAP_HISTOS_EXPORT_PATH"),os,style,size);
  printValue("CAP_CALIB_IMPORT_PATH",  variables.getValueString("CAP_CALIB_IMPORT_PATH"),os,style,size);
  printValue("CAP_CALIB_EXPORT_PATH",  variables.getValueString("CAP_CALIB_EXPORT_PATH"),os,style,size);
} // namespace CAP

void  EnvironmentVariables::addEnvVariable(const char* aKeyword, const char* aValue)
{
  variables.addProperty(aKeyword, aValue);
}


String EnvironmentVariables::getEnvVariable(const char* aKeyword) const
{
  return variables.getValueString(aKeyword);
}

}

