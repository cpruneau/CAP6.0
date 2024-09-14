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
#ifndef CAP__Factory
#define CAP__Factory

//!
//! Factory
//!
//! Generic base class for factory services.
//! A factory can be used to generate and own a large collection of objects of the same type "T". Objects are allocated on the heap and pointers "T*" to these
//! objects kept in a large array T ** objects. The array is nominally of fixed size but is enlarged whenever more objects are needed. The factory model is useful
//! when objects need to be repeatedly used and discarded (e.g., in data analysis of particles) because no malloc or destroy is required. The memory remains allocated
//! and so there is no time wasted creating and destroying the objects. The reset method is to be called on a factory to indicate that a new "event" is being considered.
//! It must evidently be possible to initialize the objects with "set" methods specific to the class "T". Use the  T * getNextObject() method to obtain an used object.
//!
#include "Aliases.hpp"
#include "Exceptions.hpp"

namespace CAP
{

template < class Object >
class Factory
{
protected:

  unsigned int defaultSizeIncrement;
  unsigned int last;
  std::vector<Object*> objects;

  public:

  Factory()
  :
  defaultSizeIncrement(10000),
  last(0),
  objects()
  {  /* no ops */  }

  virtual ~Factory()
  {
  clear();
  }

  void setDefaultSizeIncrement(long _defaultSizeIncrement)
  {
  defaultSizeIncrement = _defaultSizeIncrement;
  }

  void initialize()
  {
  increaseSize(defaultSizeIncrement);
  }

  void increaseSize(long sizeIncrement)
  {
  for (long k=0; k<sizeIncrement; k++) objects.push_back(new Object() );
  }

  void reset()
  {
  for (auto & object : objects) object->reset();
  last = 0;
  }

  void clear()
  {
  for (auto & object : objects)
    {
    object->reset();
    delete object;
    }
  objects.clear();
  }

  Object * getNextObject()
  {
  if ((last+1)>=objects.size()) increaseSize(defaultSizeIncrement);
  return objects[last++];
  }

  ClassDef(Factory,0)
};

} // namespace CAP

#endif /* Factory_hpp */
