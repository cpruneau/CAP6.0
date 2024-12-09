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
#ifndef CAP__NamedObject
#define CAP__NamedObject
#include "Exceptions.hpp"
namespace CAP
{
class NamedObject
{
protected:

  String  name;
  String  title;
  String  version;
  String  hash;

public:

  NamedObject();

  NamedObject(const String & _name,
              const String & _title,
              const String & _version="1.0",
              const String & _preHash="");

  NamedObject(const NamedObject & source);

  NamedObject & operator=(const NamedObject & source);

  virtual ~NamedObject(){}

  void setName(const String & _name)
  {
  name = _name;
  }

  void setTitle(const String & _title)
  {
  title = _title;
  }

  void setVersion(const String & _version)
  {
  version = _version;
  }

  void setHash(const String & _hash)
  {
  hash = _hash;
  }

  const String & getName() const
  {
  return name;
  }

  const String & getTitle() const
  {
  return title;
  }

  const String & getVersion() const
  {
  return version;
  }

  const String & getHash() const
  {
  return hash;
  }

  bool sameNameAs(const NamedObject & otherObject) const
  {
  return name.EqualTo(otherObject.name);
  }

  bool sameNameAs(NamedObject * otherObject) const
  {
  return name.EqualTo(otherObject->name);
  }

  String calculateHash(String preHash);
  
  void print(std::ostream & os=std::cout, int style=0, int size=50) const;

  ClassDef(NamedObject,0)
};

}



#endif /* CAP__NamedObject */
