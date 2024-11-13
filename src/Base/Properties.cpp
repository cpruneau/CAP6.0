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

namespace CAP
{

Properties::Properties()
{
  properties.clear();
}

Properties::Properties(const Properties & _Properties)
{
  properties = _Properties.properties;
}

Properties & Properties::operator=(const Properties & source)
{
  if (this!= &source)
    {
    properties = source.properties;
    }
  return *this;
}

Properties::~Properties()
{
  properties.clear();
}


String  Properties::standardize(const char * path, const char* keyword) const
{
  String aKeyword = path;
  if (aKeyword.EndsWith(":")) aKeyword += keyword;
  else
    {
    aKeyword += ":";
    aKeyword += keyword;
    }
  return aKeyword;
}


const Property & Properties::getProperty(const char* keyword)  const
{
  for (auto & property : properties)
    {
    if (property.isNamed(keyword) ||
        property.nameEndsWith(keyword)) return property;
    }
  throw PropertyException(keyword,"Property not found!!!!!","Properties::getProperty(const char* keyword) ");
}

Property & Properties::getProperty(const char* keyword)
{
  for (auto & property : properties)
    {
    if (property.isNamed(keyword) ||
        property.nameEndsWith(keyword)) return property;
    }
  throw PropertyException(keyword,"Property not found!!!!!",__FUNCTION__);
}

bool  Properties::getValueBool(const char* keyword) const
{
  const Property & property = getProperty(keyword);
  return property.getBool();
}


int Properties::getValueInt(const char* keyword) const
{
  const Property & property = getProperty(keyword);
  return property.getInt();
}

long Properties::getValueLong(const char* keyword) const
{
  const Property & property = getProperty(keyword);
  return property.getLong();
}

double Properties::getValueDouble (const char* keyword) const
{
  const Property & property = getProperty(keyword);
  return property.getDouble();
}


String Properties::getValueString (const char* keyword) const
{
  const Property & property = getProperty(keyword);
  return property.getString();
}

bool    Properties::getValueBool(  const char * path, const char* keyword) const
{
  return Properties::getValueBool(standardize(path,keyword));
}

int     Properties::getValueInt (  const char * path, const char* keyword) const
{
  return Properties::getValueInt(standardize(path,keyword));
}

long    Properties::getValueLong(  const char * path, const char* keyword) const
{
  return Properties::getValueLong(standardize(path,keyword));
}

double  Properties::getValueDouble(const char * path, const char* keyword) const
{
  return Properties::getValueDouble(standardize(path,keyword));
}

String  Properties::getValueString(const char * path, const char* keyword) const
{
  return Properties::getValueString(standardize(path,keyword));
}


//!
//! Add a bool property to the configuration with the given name and value
//!
void Properties::addProperty(const char * path, const char * keyword, bool value)
{
  Properties::addProperty(standardize(path,keyword),value);
}

//!
//! Add an int property to the configuration with the given name and value
//!
void Properties::addProperty(const char * path, const char * keyword, int value)
{
  Properties::addProperty(standardize(path,keyword),value);
}

//!
//! Add an int property to the configuration with the given name and value
//!
void Properties::addProperty(const char * path, const char * keyword, long value)
{
  Properties::addProperty(standardize(path,keyword),value);
}

//!
//! Add a double property to the configuration with the given name and value
//!
void Properties::addProperty(const char * path, const char * keyword, double value)
{
  Properties::addProperty(standardize(path,keyword),value);
}

//!
//! Add a const char *  property to the configuration with the given name and value
//!
void Properties::addProperty(const char * path, const char * keyword, const char * value)
{
  Properties::addProperty(standardize(path,keyword),value);
}

//!
//! Add a string property to the configuration with the given name and value
//!
void Properties::addProperty(const char * path, const char * keyword, const String & value)
{
  Properties::addProperty(standardize(path,keyword),value);
}


bool Properties::hasEndColon(const char * path) const
{
  String s = path;
  int last = s.Last(':');
  int size = s.Length() - 1;
  return (last>0 && last == size);
}

std::vector<Property> & Properties::getProperties()
{
  return properties;
}

const std::vector<Property> & Properties::getProperties() const
{
  return properties;
}

Size_t  Properties::size() const
{
  return properties.size();
}

void Properties::addProperties(const Properties & source)
{
  for (auto & property : source.properties) addProperty(property);
}

void Properties::addProperty(const Property& _property)
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

void Properties::addProperty(const char * name, bool value)
{
  Property p(name,value);
  addProperty(p);
}

//!
//! Add an int property to the Properties with the given name and value
//!
void Properties::addProperty(const char * name, int value)
{
  Property p(name,value);
  addProperty(p);
}


//!
//! Add an int property to the Properties with the given name and value
//!
void Properties::addProperty(const char * name, long value)
{
  Property p(name,value);
  addProperty(p);
}

//!
//! Add a double property to the Properties with the given name and value
//!
void Properties::addProperty(const char * name, double value)
{
  Property p(name,value);
  addProperty(p);
}

//!
//! Add a string property to the Properties with the given name and value
//!
void Properties::addProperty(const char * keyword, const char * value)
{
  Property p(keyword,value);
  addProperty(p);
}

//!
//! Add a string property to the Properties with the given name and value
//!
void Properties::addProperty(const char * keyword, const String & value)
{
  Property p(keyword,value);
  addProperty(p);
}

void Properties::print(std::ostream & output,  int style, int size) const
{
  for (auto & property : properties) property.print(output,style,size);
}

bool Properties::isBool(const char * keyword) const
{
  const Property & property = getProperty(keyword);
  return property.isBool();
}


bool Properties::isInt(const char * keyword) const
{
  const Property & property = getProperty(keyword);
  return property.isInt();
}

bool Properties::isLong(const char * keyword) const
{
  const Property & property = getProperty(keyword);
  return property.isLong();
}

bool Properties::isDouble(const char * keyword) const
{
  const Property & property = getProperty(keyword);
  return property.isDouble();
}


bool Properties::isString(const char * keyword) const
{
  const Property & property = getProperty(keyword);
  return property.isString();
}

bool Properties::isFound(const char * keyword) const
{
  for (auto & property : properties)
    {
    if (property.isNamed(keyword) ||
        property.nameEndsWith(keyword)) return true;
    }
  return false;
}


void Properties::reset()
{
  for (auto & property : properties) property.reset();
}

void Properties::clear()
{
  properties.clear();
}

void Properties::importProperties(const char * _path,
                                       const char * _fileName,
                                       const char * _extension)
{
  PropertiesParser parser;
  parser.read(*this,_path,_fileName,_extension);
}

void Properties::exportProperties(const char * _path      __attribute__((unused)),
                                       const char * _fileName  __attribute__((unused)),
                                       const char * _extension __attribute__((unused)) )
{
  PropertiesParser parser;
  parser.write(*this,_path,_fileName,_extension);
}

} // namespace CAP
