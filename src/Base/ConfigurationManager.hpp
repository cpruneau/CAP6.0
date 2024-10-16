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
#ifndef CAP__ConfigurationManager
#define CAP__ConfigurationManager
#include "MessageLogger.hpp"
#include "Configuration.hpp"
#include "Aliases.hpp"
#include <iomanip>

namespace CAP
{

class ConfigurationManager : public MessageLogger
{

public:
  ConfigurationManager();
  ConfigurationManager(const ConfigurationManager & other);
  virtual ~ConfigurationManager();
  ConfigurationManager operator=(const ConfigurationManager & manager);

  //!
  //! Returns a pointer to the Configuration object controlling the behavior of this task instance.
  //! @return pointer to the Configuration instance controlling this task instance.
  //!
  const Configuration & getConfiguration() const;
  Configuration & getConfiguration();
  virtual void setDefaultConfiguration();
  virtual void setRequestedConfiguration(Configuration & config);
  virtual void loadRequestedConfiguration();
  virtual void configure();
  virtual void setSeverity();

  virtual bool    getValueBool(const char* aKeyword) const;
  virtual int     getValueInt(const char* aKeyword) const;
  virtual long    getValueLong(const char* aKeyword) const;
  virtual double  getValueDouble (const char* aKeyword) const;
  virtual String  getValueString (const char* aKeyword) const;

  virtual bool    getValueBool(const char * path, const char* aKeyword) const;
  virtual int     getValueInt(const char * path, const char* aKeyword) const;
  virtual long    getValueLong(const char * path, const char* aKeyword) const;
  virtual double  getValueDouble (const char * path, const char* aKeyword) const;
  virtual String  getValueString (const char * path, const char* aKeyword) const;


  virtual void addProperty(const char * name, bool value);
  virtual void addProperty(const char * name, int value);
  virtual void addProperty(const char * name, long value);
  virtual void addProperty(const char * name, double value);
  virtual void addProperty(const char * name, const char * value);
  virtual void addProperty(const char * path, const char * name, bool value);
  virtual void addProperty(const char * path, const char * name, int value);
  virtual void addProperty(const char * path, const char * name, long value);
  virtual void addProperty(const char * path, const char * name, double value);
  virtual void addProperty(const char * path, const char * name, const char * value);

  virtual void print(std::ostream & output=std::cout,  int style=0, int size=50) const;

  void printProperty(const char * keyword, std::ostream & output=std::cout,  int style=0, int size=50) const;

  //!
  //!Generates and stores in the configuration of this task a list of key,value properties based on the given properties.value
  //!The keys generated have the form keyBaseName## where keyBaseName is the base name of the keys and ## is an integer k
  //!from 0 to nKeysToGenerate-1 (inclusively)
  //!
  //!@param keyBaseName base name of the keys
  //!@param defaultValue default value given for all key,value pairs
  //!@param nKeysToGenerate number of key,value pairs to generate and add to this task configuration.
  //!
  void generateKeyValuePairs(const char *  keyBaseName, const char *  defaultValue, int nKeysToGenerate);

  void generateKeyValuePairs(const char *  path, const char *  keyBaseName, const char *  defaultValue, int nKeysToGenerate);

  //!
  //!Parse the configuration associated with task to find the key,value pairs that DO NOT feature the defaultValue
  //!
  //!@param keyBaseName base name of the keys
  //!@param defaultValue default value that is selected against
  //!
  VectorString  getSelectedValues(const char *  keyBaseName, const char *  defaultValue) const;

  VectorString  getSelectedValues(const char *  path, const char *  keyBaseName, const char *  defaultValue) const;

  //!
  //!Get  the number of key,value pairs with the given key base name  that DO NOT feature the defaultValue
  //!
  //!@param keyBaseName base name of the keys to be tested against.
  //!@param defaultValue default value that is selected against
  //!
  int getNSelectedValues(const char *  keyBaseName, const char *  defaultValue)  const;

  int getNSelectedValues(const char *  path, const char *  keyBaseName, const char *  defaultValue) const;

  void setConfigurationPath(const String _configurationPath);
  const String & getConfigurationPath() const;

protected:

  Configuration configuration;
  Configuration * requestedConfiguration;
  String configurationPath;
  ClassDef(ConfigurationManager,0)
};

} // namespace CAP

#endif /* ConfigurationManager_hpp */
