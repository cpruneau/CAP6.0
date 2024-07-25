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
#ifndef CAP__Configuration
#define CAP__Configuration
#include "Properties.hpp"

namespace CAP
{

class Configuration : public Properties
{
 public:
  Configuration();
  Configuration(const Configuration & _configuration);
  virtual ~Configuration() {}
  Configuration & operator=(const Configuration & _configuration);

 
  //!
  //!Generates and stores in the configuration of this task a list of key,value properties based on the given properties.value
  //!The keys generated have the form keyBaseName## where keyBaseName is the base name of the keys and ## is an integer k
  //!from 0 to nKeysToGenerate-1 (inclusively)
  //!
  //!@param keyBaseName base name of the keys
  //!@param defaultValue default value given for all key,value pairs
  //!@param nKeysToGenerate number of key,value pairs to generate and add to this task configuration.
  //!
  virtual void generateKeyValuePairs(const char *  keyBaseName, const char *  defaultValue, int nKeysToGenerate);

  virtual void generateKeyValuePairs(const char *  path, const char *  keyBaseName, const char *  defaultValue, int nKeysToGenerate);

  //!
  //!Parse the configuration associated with task to find the key,value pairs that DO NOT feature the defaultValue
  //!
  //!@param keyBaseName base name of the keys
  //!@param defaultValue default value that is selected against
  //!
  virtual VectorString  getSelectedValues(const char *  keyBaseName, const char *  defaultValue) const;

  virtual VectorString  getSelectedValues(const char *  path, const char *  keyBaseName, const char *  defaultValue) const;

  //!
  //!Get  the number of key,value pairs with the given key base name  that DO NOT feature the defaultValue
  //!
  //!@param keyBaseName base name of the keys to be tested against.
  //!@param defaultValue default value that is selected against
  //!
  virtual int getNSelectedValues(const char *  keyBaseName, const char *  defaultValue)  const;

  virtual int getNSelectedValues(const char *  path, const char *  keyBaseName, const char *  defaultValue) const
  {
  String sPath = path;
  String sKeyBaseName = keyBaseName;
  return getNSelectedValues(sPath+String(":")+sKeyBaseName, defaultValue);
  }

  virtual int getNPossibleValues(const char *  keyBaseName) const;

  virtual int getNPossibleValues(const char *  path, const char *  keyBaseName) const;

  //!
  //!Add key,value pairs with the given key base name  and values provided in the selectedValues array.
  //!
  //!@param keyBaseName base name of the keys to be used
  //!@param defaultValue default value that is selected against
  //!@param selectedValues  number of key,value pairs to be checked
  //!
  virtual void addSelectedValues(const char *  keyBaseName, const char *  defaultValue, const VectorString  & selectedValues);

  virtual void addSelectedValues(const char * path, const char * keyBaseName, const char * defaultValue, const VectorString  & selectedValues)
  {
  String sPath = path;
  String sKeyBaseName = keyBaseName;
  addSelectedValues(sPath+String(":")+sKeyBaseName, defaultValue, selectedValues);
  }

protected:
  ClassDef(Configuration,0)
  
};

} // namespace CAP

#endif /* Configuration_hpp */
