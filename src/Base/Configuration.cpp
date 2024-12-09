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
#include "Configuration.hpp"

ClassImp(CAP::Configuration);

namespace CAP
{


Configuration::Configuration()
:
Properties()
{  }

Configuration::Configuration(const Configuration & _configuration)
:
Properties(_configuration)
{  }


Configuration & Configuration::operator=(const Configuration & _configuration)
{
  if (this!= &_configuration)
    {
    Properties::operator=(_configuration);
    }
  return *this;
}



void Configuration::generateKeyValuePairs(const char *  keyBaseName, const char *  defaultValue, int nKeysToGenerate)
{
  String key;
  for (int k=0; k<nKeysToGenerate; k++)
    {
    key = keyBaseName; key += k;
    Properties::addProperty(key,defaultValue);
    }
}

void Configuration::generateKeyValuePairs(const char *  path, const char *  keyBaseName, const char *  defaultValue, int nKeysToGenerate)
{
  String sPath = path;
  String sKeyBaseName = keyBaseName;
  if (sPath.EndsWith(":"))
    generateKeyValuePairs(sPath+sKeyBaseName, defaultValue, nKeysToGenerate);
  else
    generateKeyValuePairs(sPath+String(":")+sKeyBaseName, defaultValue, nKeysToGenerate);
}

std::vector<String> Configuration::getSelectedValues(const char *  keyBaseName, const char *  defaultValue) const
{
  std::vector<String> selectedValues;
  for (auto & property : properties)
    {
    if (property.nameContains(keyBaseName) && !property.valueContains(defaultValue))
      selectedValues.push_back(property.getString());
    }
  return selectedValues;
}

std::vector<String> Configuration::getSelectedValues(const char *  path, const char *  keyBaseName, const char *  defaultValue) const
{
  String sPath = path;
  String sKeyBaseName = keyBaseName;
  if (sPath.EndsWith(":"))
    return getSelectedValues(sPath+sKeyBaseName, defaultValue);
  else
    return getSelectedValues(sPath+String(":")+sKeyBaseName, defaultValue);
}


int Configuration::getNPossibleValues(const char *  keyBaseName)  const
{
  int nPossible = 0;
  String sKeyBaseName = keyBaseName;
  for (auto & property : properties)
    {
    if (property.nameContains(keyBaseName))  nPossible++;
    }
  return nPossible;
}

int Configuration::getNPossibleValues(const char *  path, const char *  keyBaseName) const
{
  String sPath = path;
  String sKeyBaseName = keyBaseName;
  if (sPath.EndsWith(":"))
    return getNPossibleValues(sPath+sKeyBaseName);
  else
    return getNPossibleValues(sPath+String(":")+sKeyBaseName);
}


int Configuration::getNSelectedValues(const char *  keyBaseName, const char *  defaultValue)  const
{
  int nSelected = 0;
  String sKeyBaseName = keyBaseName;
  for (auto & property : properties)
    {
    if (property.nameContains(keyBaseName) && !property.valueContains(defaultValue) )  nSelected++;
    }
  return nSelected;
}


void Configuration::addSelectedValues(const char *  keyBaseName, const char *  defaultValue, const std::vector<String> & selectedValues)
{
  String key;
  int nSelected = getNSelectedValues(keyBaseName,defaultValue);
  for (unsigned int k=0; k<selectedValues.size(); k++)
    {
      String key = keyBaseName;
      int index = nSelected + k;
      key += index;
    Properties::addProperty(key,selectedValues[k]);
    }
}


} // namespace CAP

