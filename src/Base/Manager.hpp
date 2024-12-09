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
#ifndef CAP__Manager
#define CAP__Manager
#include "Aliases.hpp"
#include "Exceptions.hpp"
#include "PrintHelpers.hpp"

namespace CAP
{
class ManagerException : public Exception
{
public:
  ManagerException(const String  & _name, const String  & _message, const String  & _source);
  ManagerException(int index, const String  & _message, const String  & _source);
  virtual ~ManagerException() {}
  virtual void print();
protected:
  String name;
  int    index;
};

template < class Object >
class Manager
{

public:

  Manager()
  :
  objectNames(),
  objects(),
  objectOwnerships()
  {
    objectNames.clear();
    objects.clear();
    objectOwnerships.clear();
  }

  Manager(const Manager & manager);
  Manager & operator=(const Manager & manager);
  virtual ~Manager();

  void setNames(const std::vector<String> & _objectNames)
  {
  printCR();
  printCR();
  objectNames.clear();
  objects.clear();
  objectOwnerships.clear();
  objectNames = _objectNames;
  }

  Object * create(const String & name);
  Object * use(const  String &  name);
  bool owns(unsigned int index);
  virtual void resetObjectAt(unsigned int index);
  virtual void clearObjectAt(unsigned int index);
  virtual void eraseObjectAt(unsigned int index);
  virtual void reset();
  virtual void clear();
  virtual void erase();
  std::vector<Object*> & getObjects();
  const std::vector<Object*> & getObjects() const;
  Object * getObjectNamed(const String & name);
  Object * getObjectAt(unsigned int index);
  int getNObjects();


  // static methods

  static Object* createStoreObjectNamed(const String & name);
  static Object* getStoreObjectNamed(const String & name);
  static int getNObjectStore();

protected:

  std::vector<String>  objectNames;
  std::vector<Object*> objects;
  std::vector<bool>    objectOwnerships;

  static std::vector<String>  objectStoreNames;
  static std::vector<Object*> objectStore;

  ClassDef(Manager,0)
};



template < class Object >
Manager<Object>::Manager(const Manager & source)
:
objectNames(source.objectNames),
objects(source.objects),
objectOwnerships(source.objectOwnerships)
{    }

template < class Object >
Manager<Object> & Manager<Object>::operator=(const Manager<Object> & source)
{
  if (this!=&source)
    {
    objectNames.clear();
    objects.clear();
    objectOwnerships.clear();
    objectNames      = source.objectNames;
    objects          = source.objects;
    objectOwnerships = source.objectOwnerships;
    }
  return *this;
}

template < class Object >
Manager<Object>::~Manager()
{
 // clear();
}




template < class Object >
Object *   Manager<Object>::create(const String & name)
{
  Object * object = Manager<Object>::createStoreObjectNamed(name);
  if (!object) throw ManagerException(name,"Object Not Created",__FUNCTION__);
  objectNames.push_back(name);
  objects.push_back(object);
  objectOwnerships.push_back(true);
  return object;
}

template < class Object >
Object *  Manager<Object>::use(const  String &  name)
{
  Object * object = Manager<Object>::getStoreObjectNamed(name);
  if (!object) throw ManagerException(name,"Unknown object",__FUNCTION__);
  objectNames.push_back(name);
  objects.push_back(object);
  objectOwnerships.push_back(false);
  return object;
}

template < class Object >
bool Manager<Object>::owns(unsigned int index)
{
  if (index>=objects.size()) throw ManagerException(index,"Invalid Index",__FUNCTION__);
  return objectOwnerships[index];
}

template < class Object >
void Manager<Object>::resetObjectAt(unsigned int index)
{
  if (!owns(index)) throw ManagerException(index,"Invalid Index",__FUNCTION__);
  objects[index]->reset();
}

template < class Object >
void Manager<Object>::clearObjectAt(unsigned int index)
{
  if (!owns(index)) throw ManagerException(index,"Invalid Index",__FUNCTION__);
  objects[index]->clear();
}

template < class Object >
void Manager<Object>::eraseObjectAt(unsigned int index)
{
  if (!owns(index)) throw ManagerException(index,"Invalid Index",__FUNCTION__);
  //clearObjectAt(index);
  objects.erase(objects.begin()+index);
}

template < class Object >
void Manager<Object>::reset()
{
  for (unsigned int index = 0; index<objects.size();index++)
    {
    if (owns(index)) resetObjectAt(index);
    }
}

template < class Object >
void Manager<Object>::clear()
{
  for (unsigned int index = 0; index<objects.size();index++)
    {
    if (owns(index)) clearObjectAt(index);
    }
}

template < class Object >
void Manager<Object>::erase()
{
  for (unsigned int index = 0; index<objects.size();index++)
    {
    if (owns(index)) eraseObjectAt(index);
    }
}

template < class Object >
std::vector<Object*> & Manager<Object>::getObjects()
{
  return objects;
}

template < class Object >
const std::vector<Object*> & Manager<Object>::getObjects() const
{
  return objects;
}

template < class Object >
Object * Manager<Object>::getObjectNamed(const String & name)
{
  if (objects.size()<1) throw ManagerException(name,"objects.size()<1",__FUNCTION__);
  for (auto & object : objects)
    {
    if (object->getName().EqualTo(name)) return object;
    }
  throw ManagerException(name,"Unknown filter", __FUNCTION__);
}

template < class Object >
Object * Manager<Object>::getObjectAt(unsigned int index)
{
  unsigned int n = objects.size();
  if (n<1) 
    throw ManagerException(index,"objects.size()<1",__FUNCTION__);
  else if (index>=n)
    throw ManagerException(index,"index>=objects.size()",__FUNCTION__);
  else
    return objects[index];
}


template < class Object >
int Manager<Object>::getNObjects()
{
  return objects.size();
}

// static

template <class Object>
std::vector<String> Manager<Object>::objectStoreNames;

template <class Object>
std::vector<Object*> Manager<Object>::objectStore;

template <class Object>
Object* Manager<Object>::createStoreObjectNamed(const String & newName)
{
  for (auto & name : objectStoreNames)
    {
    if (name.EqualTo(newName))
      throw ManagerException(name,"Object already exist",__FUNCTION__);
    }
  Object * object = new Object();
  //object->setName(name);
  objectStoreNames.push_back(newName);
  objectStore.push_back(object);
  return object;
}

template <class Object>
Object* Manager<Object>::getStoreObjectNamed(const String & requestedName)
{
  //printValue("Store Size Name", objectStoreNames.size());
  //printValue("Store Size Obje", objectStore.size());
  unsigned int index=0;
  for (auto & name : objectStoreNames)
    {
    //printValue("Store Name",name);
    if (name.EqualTo(requestedName)) return objectStore[index];
    index++;
    }
  throw ManagerException(requestedName,"Object does not exist",__FUNCTION__);
}

template <class Object>
int Manager<Object>::getNObjectStore()
{
  return objectStore.size();
}

}

#endif /* CAP_Manager */


