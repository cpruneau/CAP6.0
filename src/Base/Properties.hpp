/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
 *
 * *********************************************************************/
#ifndef CAP__Properties
#define CAP__Properties
#include "Aliases.hpp"
#include "Property.hpp"

namespace CAP
{

class Properties
{
 public:
  Properties();
  Properties(const Properties & properties);
  virtual ~Properties();
  Properties & operator=(const Properties & _Properties);

  const Property & getProperty(const char* aKeyword) const;
  Property & getProperty(const char* aKeyword);

  std::vector<Property> & getProperties();
  const std::vector<Property> & getProperties() const;

  Size_t size() const;
  virtual void reset();
  virtual void clear();

  virtual bool isBool(const char * name) const;
  virtual bool isInt(const char * name) const;
  virtual bool isLong(const char * name) const;
  virtual bool isDouble(const char * name) const;
  virtual bool isString(const char * name) const;
  virtual bool isFound(const char * name) const;


  virtual bool    getValueBool(const char* aKeyword, bool useDefault=1, bool defaultValue=false) const;
  virtual int     getValueInt(const char* aKeyword,  bool useDefault=1, int defaultValue=0) const;
  virtual long    getValueLong(const char* aKeyword,  bool useDefault=1, long defaultValue=0) const;
  virtual double  getValueDouble(const char* aKeyword,  bool useDefault=1, double defaultValue=0) const;
  virtual String  getValueString(const char* aKeyword,  bool useDefault=1, const String defaultValue="NONE") const;

  String  standardize(   const char * path, const char* aKeyword) const;
  virtual bool    getValueBool(  const char * path, const char* aKeyword) const;
  virtual int     getValueInt (  const char * path, const char* aKeyword) const;
  virtual long    getValueLong(  const char * path, const char* aKeyword) const;
  virtual double  getValueDouble(const char * path, const char* aKeyword) const;
  virtual String  getValueString(const char * path, const char* aKeyword) const;

  virtual void addProperties(const Properties & Properties);
  virtual void addProperty(const Property & _property);
  virtual void addProperty(const char * name, bool value);
  virtual void addProperty(const char * name, int value);
  virtual void addProperty(const char * name, long value);
  virtual void addProperty(const char * name, double value);
  virtual void addProperty(const char * name, const char * value);
  virtual void addProperty(const char * name, const String & value);
  virtual void addProperty(const char * path, const char * name, bool value);
  virtual void addProperty(const char * path, const char * name, int value);
  virtual void addProperty(const char * path, const char * name, long value);
  virtual void addProperty(const char * path, const char * name, double value);
  virtual void addProperty(const char * path, const char * name, const char * value);
  virtual void addProperty(const char * path, const char * name, const String & value);

  bool hasEndColon(const char * path) const;


  void importProperties(const char * _path,
                        const char * _fileName,
                        const char * _extension=".ini");
  void exportProperties(const char * _path,
                        const char * _fileName,
                        const char * _extension="ini");
  void print(std::ostream & output=std::cout,  int style=0, int size=50) const;


protected:

  std::vector<Property> properties;

  ClassDef(Properties,0)
  
};

} // namespace CAP

#endif /* Properties_hpp */
