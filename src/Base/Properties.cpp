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
#include "Properties.hpp"
#include "PropertiesParser.hpp"
#include "Exceptions.hpp"


ClassImp(CAP::Properties);

CAP::Properties::Properties()
{
  properties.clear();
}

CAP::Properties::Properties(const CAP::Properties & _Properties)
{
  properties = _Properties.properties;
}

CAP::Properties & CAP::Properties::operator=(const CAP::Properties & source)
{
  if (this!= &source)
    {
    properties = source.properties;
    }
  return *this;
}

CAP::Properties::~Properties()
{
  properties.clear();
}


CAP::String  CAP::Properties::standardize(const char * path, const char* keyword) const
{
  CAP::String aKeyword = path;
  if (aKeyword.EndsWith(":")) aKeyword += keyword;
  else
    {
    aKeyword += ":";
    aKeyword += keyword;
    }
  return aKeyword;
}


const CAP::Property & CAP::Properties::getProperty(const char* keyword)  const
{
  for (auto & property : properties)
    {
    if (property.isNamed(keyword) ||
        property.nameEndsWith(keyword)) return property;
    }
  throw CAP::PropertyException(keyword,"Property not found!!!!!","Properties::getProperty(const char* keyword) ");
}

CAP::Property & CAP::Properties::getProperty(const char* keyword)
{
  for (auto & property : properties)
    {
    if (property.isNamed(keyword) ||
        property.nameEndsWith(keyword)) return property;
    }
  throw CAP::PropertyException(keyword,"Property not found!!!!!",__FUNCTION__);
}

bool  CAP::Properties::getValueBool(const char* keyword) const
{
  const Property & property = getProperty(keyword);
  return property.getBool();
}


int CAP::Properties::getValueInt(const char* keyword) const
{
  const Property & property = getProperty(keyword);
  return property.getInt();
}

long CAP::Properties::getValueLong(const char* keyword) const
{
  const Property & property = getProperty(keyword);
  return property.getLong();
}

double CAP::Properties::getValueDouble (const char* keyword) const
{
  const Property & property = getProperty(keyword);
  return property.getDouble();
}


CAP::String CAP::Properties::getValueString (const char* keyword) const
{
  const Property & property = getProperty(keyword);
  return property.getString();
}

bool    CAP::Properties::getValueBool(  const char * path, const char* keyword) const
{
  return Properties::getValueBool(standardize(path,keyword));
}

int     CAP::Properties::getValueInt (  const char * path, const char* keyword) const
{
  return Properties::getValueInt(standardize(path,keyword));
}

long    CAP::Properties::getValueLong(  const char * path, const char* keyword) const
{
  return Properties::getValueLong(standardize(path,keyword));
}

double  CAP::Properties::getValueDouble(const char * path, const char* keyword) const
{
  return Properties::getValueDouble(standardize(path,keyword));
}

CAP::String  CAP::Properties::getValueString(const char * path, const char* keyword) const
{
  return Properties::getValueString(standardize(path,keyword));
}


//!
//! Add a bool property to the configuration with the given name and value
//!
void CAP::Properties::addProperty(const char * path, const char * keyword, bool value)
{
  Properties::addProperty(standardize(path,keyword),value);
}

//!
//! Add an int property to the configuration with the given name and value
//!
void CAP::Properties::addProperty(const char * path, const char * keyword, int value)
{
  Properties::addProperty(standardize(path,keyword),value);
}

//!
//! Add an int property to the configuration with the given name and value
//!
void CAP::Properties::addProperty(const char * path, const char * keyword, long value)
{
  Properties::addProperty(standardize(path,keyword),value);
}

//!
//! Add a double property to the configuration with the given name and value
//!
void CAP::Properties::addProperty(const char * path, const char * keyword, double value)
{
  Properties::addProperty(standardize(path,keyword),value);
}

//!
//! Add a const char *  property to the configuration with the given name and value
//!
void CAP::Properties::addProperty(const char * path, const char * keyword, const char * value)
{
  Properties::addProperty(standardize(path,keyword),value);
}

//!
//! Add a string property to the configuration with the given name and value
//!
void CAP::Properties::addProperty(const char * path, const char * keyword, const String & value)
{
  Properties::addProperty(standardize(path,keyword),value);
}


bool CAP::Properties::hasEndColon(const char * path) const
{
  CAP::String s = path;
  int last = s.Last(':');
  int size = s.Length() - 1;
  return (last>0 && last == size);
}

std::vector<CAP::Property> & CAP::Properties::getProperties()
{
  return properties;
}

const std::vector<CAP::Property> & CAP::Properties::getProperties() const
{
  return properties;
}

CAP::Size_t  CAP::Properties::size() const
{
  return properties.size();
}

void CAP::Properties::addProperties(const Properties & source)
{
  for (auto & property : source.properties) addProperty(property);
}

void CAP::Properties::addProperty(const Property& _property)
{
  for (auto & property : properties)
    { 
    if (property.sameNameAs(_property))
      {
      property.setValue(_property.getString());
      return;
      }
    }
  properties.push_back(_property);
}

void CAP::Properties::addProperty(const char * name, bool value)
{
  Property p(name,value);
  addProperty(p);
}

//!
//! Add an int property to the Properties with the given name and value
//!
void CAP::Properties::addProperty(const char * name, int value)
{
  Property p(name,value);
  addProperty(p);
}


//!
//! Add an int property to the Properties with the given name and value
//!
void CAP::Properties::addProperty(const char * name, long value)
{
  Property p(name,value);
  addProperty(p);
}

//!
//! Add a double property to the Properties with the given name and value
//!
void CAP::Properties::addProperty(const char * name, double value)
{
  Property p(name,value);
  addProperty(p);
}

//!
//! Add a string property to the Properties with the given name and value
//!
void CAP::Properties::addProperty(const char * keyword, const char * value)
{
  Property p(keyword,value);
  addProperty(p);
}

//!
//! Add a string property to the Properties with the given name and value
//!
void CAP::Properties::addProperty(const char * keyword, const String & value)
{
  Property p(keyword,value);
  addProperty(p);
}

void CAP::Properties::print(std::ostream & output,  int style, int size) const
{
  for (auto & property : properties) property.print(output,style,size);
}

bool CAP::Properties::isBool(const char * keyword) const
{
  const Property & property = getProperty(keyword);
  return property.isBool();
}


bool CAP::Properties::isInt(const char * keyword) const
{
  const Property & property = getProperty(keyword);
  return property.isInt();
}

bool CAP::Properties::isLong(const char * keyword) const
{
  const Property & property = getProperty(keyword);
  return property.isLong();
}

bool CAP::Properties::isDouble(const char * keyword) const
{
  const Property & property = getProperty(keyword);
  return property.isDouble();
}


bool CAP::Properties::isString(const char * keyword) const
{
  const Property & property = getProperty(keyword);
  return property.isString();
}

bool CAP::Properties::isFound(const char * keyword) const
{
  for (auto & property : properties)
    {
    if (property.isNamed(keyword) ||
        property.nameEndsWith(keyword)) return true;
    }
  return false;
}


void CAP::Properties::reset()
{
  for (auto & property : properties) property.reset();
}

void CAP::Properties::clear()
{
  properties.clear();
}

void CAP::Properties::importProperties(const char * _path,
                                       const char * _fileName,
                                       const char * _extension)
{
  CAP::PropertiesParser parser;
  parser.read(*this,_path,_fileName,_extension);
}

void CAP::Properties::exportProperties(const char * _path      __attribute__((unused)),
                                       const char * _fileName  __attribute__((unused)),
                                       const char * _extension __attribute__((unused)) )
{
  CAP::PropertiesParser parser;
  parser.write(*this,_path,_fileName,_extension);
}

