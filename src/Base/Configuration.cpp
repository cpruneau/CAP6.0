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
#include "Configuration.hpp"

ClassImp(CAP::Configuration);

CAP::Configuration::Configuration()
:
Properties()
{  }

CAP::Configuration::Configuration(const CAP::Configuration & _configuration)
:
Properties(_configuration)
{  }


CAP::Configuration & CAP::Configuration::operator=(const CAP::Configuration & _configuration)
{
  if (this!= &_configuration)
    {
    Properties::operator=(_configuration);
    }
  return *this;
}



void CAP::Configuration::generateKeyValuePairs(const char *  keyBaseName, const char *  defaultValue, int nKeysToGenerate)
{
  CAP::String key;
  for (int k=0; k<nKeysToGenerate; k++)
    {
    key = keyBaseName; key += k;
    Properties::addProperty(key,defaultValue);
    }
}

void CAP::Configuration::generateKeyValuePairs(const char *  path, const char *  keyBaseName, const char *  defaultValue, int nKeysToGenerate)
{
  CAP::String sPath = path;
  CAP::String sKeyBaseName = keyBaseName;
  if (sPath.EndsWith(":"))
    generateKeyValuePairs(sPath+sKeyBaseName, defaultValue, nKeysToGenerate);
  else
    generateKeyValuePairs(sPath+CAP::String(":")+sKeyBaseName, defaultValue, nKeysToGenerate);
}

std::vector<CAP::String> CAP::Configuration::getSelectedValues(const char *  keyBaseName, const char *  defaultValue) const
{
  std::vector<CAP::String> selectedValues;
  for (auto & property : properties)
    {
    if (property.nameContains(keyBaseName) && !property.valueContains(defaultValue))
      selectedValues.push_back(property.getString());
    }
  return selectedValues;
}

std::vector<CAP::String> CAP::Configuration::getSelectedValues(const char *  path, const char *  keyBaseName, const char *  defaultValue) const
{
  CAP::String sPath = path;
  CAP::String sKeyBaseName = keyBaseName;
  if (sPath.EndsWith(":"))
    return getSelectedValues(sPath+sKeyBaseName, defaultValue);
  else
    return getSelectedValues(sPath+CAP::String(":")+sKeyBaseName, defaultValue);
}


int CAP::Configuration::getNPossibleValues(const char *  keyBaseName)  const
{
  int nPossible = 0;
  CAP::String sKeyBaseName = keyBaseName;
  for (auto & property : properties)
    {
    if (property.nameContains(keyBaseName))  nPossible++;
    }
  return nPossible;
}

int CAP::Configuration::getNPossibleValues(const char *  path, const char *  keyBaseName) const
{
  CAP::String sPath = path;
  CAP::String sKeyBaseName = keyBaseName;
  if (sPath.EndsWith(":"))
    return getNPossibleValues(sPath+sKeyBaseName);
  else
    return getNPossibleValues(sPath+CAP::String(":")+sKeyBaseName);
}


int CAP::Configuration::getNSelectedValues(const char *  keyBaseName, const char *  defaultValue)  const
{
  int nSelected = 0;
  CAP::String sKeyBaseName = keyBaseName;
  for (auto & property : properties)
    {
    if (property.nameContains(keyBaseName) && !property.valueContains(defaultValue) )  nSelected++;
    }
  return nSelected;
}


void CAP::Configuration::addSelectedValues(const char *  keyBaseName, const char *  defaultValue, const std::vector<CAP::String> & selectedValues)
{
  CAP::String key;
  int nSelected = getNSelectedValues(keyBaseName,defaultValue);
  for (unsigned int k=0; k<selectedValues.size(); k++)
    {
      CAP::String key = keyBaseName;
      int index = nSelected + k;
      key += index;
    Properties::addProperty(key,selectedValues[k]);
    }
}
