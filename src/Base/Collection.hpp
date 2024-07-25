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
#ifndef CAP__Collection
#define CAP__Collection

// ====================================================
//
// Collection of pointers to objects of type T
//
// Generic base class for Collection services.
// Set ownership with setOwn()
//
// ====================================================
#include <iostream>
#include "Aliases.hpp"
#include "NamedObject.hpp"

namespace CAP
{

template < class Object >
class Collection
:
public NamedObject
{
protected:
  std::vector<Object> objects;
  bool ownership;

public:

  Collection()
  :
  NamedObject(),
  objects(),
  ownership(false)
  {  }

  Collection(const Collection & source)
  :
  NamedObject(source),
  objects(),
  ownership(true)
  {
  deepCopy(source.objects);
  }


  virtual ~Collection()
  {
    clear();
  }

  Collection & operator=(const Collection source)
  {
  if (this==&source) return *this;
  NamedObject::operator=(source),
  clear();
  ownership = true;
  return *this;
  }

  bool hasOwnerShip() const
  {
  return ownership;
  }

  void setOwnership(bool owns = true)
  {
    ownership = owns;
  }

  void clear()
  {
  if (ownership)
    {
    //for (auto & object : objects) delete object;
    objects.clear();
    name = "";
    }
  }

  unsigned long size() const
  {
    return objects.size();
  }

 Object &  getObjectAt(unsigned int index)
  {
  return objects[index];
  }

 Object &  operator[](unsigned int index)
  {
  return objects[index];
  }

 Object & push_back(Object & object)
  {
  objects.push_back(object);
  return object;
  }

 Object & append(Object & object)
  {
  objects.push_back(object);
  return object;
  }

 Object & back()
  {
  return objects.back();
  }

  bool sameSizeAs(const Collection<Object> & other) const
  {
  return objects.size() == other.objects.size();
  }

  // Shallow copy (pointers only)
  void shallowCopy(const std::vector<Object*> & source)
  {
  ownership = false;
  for (auto & object : source) objects.push_back(object);
  }

  void deepCopy(const std::vector<Object> & source)
  {
  ownership = true;
  for (auto & object : source) objects.push_back(  * new Object(object) );
  }

  std::vector<Object> & getObjects()
  {
  return objects;
  }

  const std::vector<Object*> & getObjects() const
  {
  return objects;
  }

  ClassDef(Collection,1)
};

} // namespace CAP

#endif /* CAP__Collection */
