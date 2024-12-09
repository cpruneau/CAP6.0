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
#include "ConfigurationManager.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ConfigurationManager);

namespace CAP
{
ConfigurationManager::ConfigurationManager()
:
MessageLogger(),
configuration(),
requestedConfiguration(nullptr),
configurationPath("")
{
  setClassName("ConfigurationManager");
}

ConfigurationManager::ConfigurationManager(const ConfigurationManager & other)
:
MessageLogger(other),
configuration(other.configuration),
requestedConfiguration(other.requestedConfiguration),
configurationPath(other.configurationPath)
{
  setClassName("ConfigurationManager");
}

ConfigurationManager::~ConfigurationManager()
{  }

ConfigurationManager ConfigurationManager::operator=(const ConfigurationManager & other)
{
  if (this!=&other)
    {
    MessageLogger::operator=(other);
    configuration          = other.configuration;
    requestedConfiguration = other.requestedConfiguration;
    configurationPath      = other.configurationPath;
    }
  return *this;
}

const Configuration & ConfigurationManager::getConfiguration() const
{
  return configuration;
}

Configuration & ConfigurationManager::getConfiguration()
{
  return configuration;
}


void ConfigurationManager::setDefaultConfiguration()
{
  addProperty( "Severity","Info");
}

void ConfigurationManager::setRequestedConfiguration(Configuration & _requestedConfiguration)
{
  requestedConfiguration = & _requestedConfiguration;
}

void ConfigurationManager::loadRequestedConfiguration()
{
  if (!requestedConfiguration) throw Exception("!requestedConfiguration",__FUNCTION__);
  configuration.addProperties(*requestedConfiguration);
}


void ConfigurationManager::configure()
{
  setDefaultConfiguration();
  loadRequestedConfiguration();
  setSeverity();
}

bool ConfigurationManager::getValueBool(const char *  key)   const
{
  return configuration.getValueBool(configurationPath,key);
}

int ConfigurationManager::getValueInt(const char *  key)    const
{
  return configuration.getValueInt(configurationPath,key);
}

//!
//! Get the value of the parameter named 'name'
//!
long ConfigurationManager::getValueLong(const char *  key)    const
{
  return configuration.getValueLong(configurationPath,key);
}

//!
//! Get the value of the parameter named 'name'
//!
double ConfigurationManager::getValueDouble(const char *  key) const
{
  return configuration.getValueDouble(configurationPath,key);
}

String ConfigurationManager::getValueString(const char *  key) const
{
  return configuration.getValueString(configurationPath,key);
}

bool ConfigurationManager::getValueBool(const char * path, const char *  key)   const
{
  return configuration.getValueBool(path,key);
}

int ConfigurationManager::getValueInt(const char * path, const char *  key)    const
{
  return configuration.getValueInt(path,key);
}

//!
//! Get the value of the parameter named 'name'
//!
long ConfigurationManager::getValueLong(const char * path, const char *  key)    const
{
  return configuration.getValueLong(path,key);
}

double ConfigurationManager::getValueDouble(const char * path, const char *  key) const
{
  return configuration.getValueDouble(path,key);
}

String ConfigurationManager::getValueString(const char * path, const char *  key) const
{
  return configuration.getValueString(path,key);
}

void ConfigurationManager::addProperty(const char *  name, bool value)
{
  configuration.addProperty(configurationPath,name,value);
}

void ConfigurationManager::addProperty(const char *  name, int value)
{
  configuration.addProperty(configurationPath,name,value);
}

void ConfigurationManager::addProperty(const char *  name, long value)
{
  configuration.addProperty(configurationPath,name,value);
}

void ConfigurationManager::addProperty(const char *  name, double value)
{
  configuration.addProperty(configurationPath,name,value);
}

void ConfigurationManager::addProperty(const char *  name, const char *  value)
{
  configuration.addProperty(configurationPath,name,value);
}

void ConfigurationManager::addProperty(const char * path, const char * name, bool value)
{
  configuration.addProperty(path,name,value);
}

void ConfigurationManager::addProperty(const char * path, const char * name, int value)
{
  configuration.addProperty(path,name,value);
}

void ConfigurationManager::addProperty(const char * path, const char * name, long value)
{
  configuration.addProperty(path,name,value);
}

void ConfigurationManager::addProperty(const char * path, const char * name, double value)
{
  configuration.addProperty(path,name,value);
}

void ConfigurationManager::addProperty(const char * path, const char * name, const char * value)
{
  configuration.addProperty(path,name,value);
}

void ConfigurationManager::print(std::ostream & output,  int style, int size) const
{
  configuration.print(output,style,size);
}

void ConfigurationManager::printProperty(const char * keyword, std::ostream & output,  int style, int size) const
{
  const Property & property = configuration.getProperty(keyword);
  property.print(output, size, style);
}

void ConfigurationManager::generateKeyValuePairs(const char *  keyBaseName, const char *  defaultValue, int nKeysToGenerate)
{
  configuration.generateKeyValuePairs(configurationPath,keyBaseName,defaultValue,nKeysToGenerate);
}

void ConfigurationManager::generateKeyValuePairs(const char *  path, const char *  keyBaseName, const char *  defaultValue, int nKeysToGenerate)
{
  configuration.generateKeyValuePairs(path,keyBaseName,defaultValue,nKeysToGenerate);
}

VectorString  ConfigurationManager::getSelectedValues(const char *  keyBaseName, const char *  defaultValue) const
{
  return configuration.getSelectedValues(configurationPath,keyBaseName,defaultValue);
}

VectorString  ConfigurationManager::getSelectedValues(const char *  path, const char *  keyBaseName, const char *  defaultValue) const
{
  return configuration.getSelectedValues(path,keyBaseName,defaultValue);
}

int ConfigurationManager::getNSelectedValues(const char *  keyBaseName, const char *  defaultValue)  const
{
  return configuration.getNSelectedValues(configurationPath,keyBaseName,defaultValue);
}

int ConfigurationManager::getNSelectedValues(const char *  path, const char *  keyBaseName, const char *  defaultValue) const
{
  return configuration.getNSelectedValues(path,keyBaseName,defaultValue);
}

void ConfigurationManager::setSeverity()
{
  MessageLogger::Severity selectedLevel;
  String  logOption = getValueString("Severity");
  if (logOption.Contains("Debug"))        selectedLevel = MessageLogger::Debug;
  else if (logOption.Contains("Info"))    selectedLevel = MessageLogger::Info;
  else if (logOption.Contains("Warning")) selectedLevel = MessageLogger::Warning;
  else selectedLevel = MessageLogger::Info;
  setSeverityLevel(selectedLevel);
}

void ConfigurationManager::setConfigurationPath(const String _configurationPath)
{
  configurationPath = _configurationPath;
}

const String & ConfigurationManager::getConfigurationPath() const
{
  return configurationPath;
}





} // namespace CAP

