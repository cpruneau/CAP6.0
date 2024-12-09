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
#ifndef CAP__Filter
#define CAP__Filter
#include "Exceptions.hpp"
#include "Condition.hpp"
#include "PrintHelpers.hpp"

using CAP::String;

namespace CAP
{

class FilterException : public Exception
{
public:
  FilterException(const String  & _message,
                  const String  & _source);
  virtual ~FilterException() {}
};



template < class T >
class Filter
{

protected:

  String name;
  String title;
  std::vector<Condition*> conditions;

public:

  Filter()
  :
  name(""),
  title(""),
  conditions()
  { /* no ops */ }

  virtual ~Filter()
  {
  clear();
  }

  //!
  //! Test whether the given object is acceptable based on this filter's criteria.
  //!  The base class accepts all objects submitted.
  //!
  bool accept(const T & object __attribute__((unused)))
  {
  throw FilterException("Improper call to accept of base class","Filter::accept(const T & object __attribute__((unused)))");
  }

  //! Test whether the given objects are acceptable based on this filter's criteria.
  //!  The base class accepts all objects submitted.
  bool accept(const T & object1 __attribute__((unused)), const T & object2 __attribute__((unused)))
  {
  throw FilterException("Improper call to accept of base class","Filter::accept(const T & object1 __attribute__((unused)), const T & object2 __attribute__((unused)))");
  }


  String getName() const
  {
  return name;
  }

  String getTitle() const
  {
  return title;
  }

  virtual void print(std::ostream & os, int style, int size)
  {
  printValue("Filter name",name);
  printValue("Filter title",title);
  for (auto & condition : conditions) condition->print(os,style,size);
  }

  void setName(const String  & newName)
  {
  name = newName;
  }

  void setTitle(const String  & newTitle)
  {
  title = newTitle;
  }

  void addCondition(int _conditionSubtype,
                    bool _requested)
  {
  conditions.push_back(new ConditionBool(_conditionSubtype,_requested));
  }

  void addCondition(int _conditionSubtype,
                    int _requested)
  {
  conditions.push_back(new ConditionInteger(_conditionSubtype,_requested));
  }

  void addCondition(int _conditionSubtype,
                    int _minimum,
                    int _maximum)
  {
  conditions.push_back(new ConditionIntegerRange(_conditionSubtype,_minimum,_maximum));
  }

  void addCondition(int _conditionSubtype,
                    double _minimum,
                    double _maximum)
  {
  conditions.push_back(new ConditionDoubleRange(_conditionSubtype,_minimum,_maximum));
  }

  void addCondition(int _conditionSubtype,
                    double _minimum,
                    double _maximum,
                    double _minimum2,
                    double _maximum2)
  {
  conditions.push_back(new ConditionDoubleDualRange(_conditionSubtype,_minimum,_maximum,_minimum2,_maximum2));
  }

  unsigned int getNConditions() const
  {
  return conditions.size();
  }

  const std::vector<Condition*> & getConditions() const
  {
  return conditions;
  }

  std::vector<Condition*> & getConditions()
  {
  return conditions;
  }

  virtual void reset()
  {

  }

  void clear()
  {
  for (auto & condition : conditions) delete condition;
  conditions.clear();
  }

}; // Filter<T>

}// namespace CAP


#endif /* CAP__Filter  */

