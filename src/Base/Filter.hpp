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
#ifndef CAP__Filter
#define CAP__Filter
#include "Aliases.hpp"
#include "Exceptions.hpp"
#include "PrintHelpers.hpp"

using CAP::String;

namespace CAP
{

class Condition
{
public:

  String conditionType;
  String conditionSubtype;

  Condition(const String & _conditionType,const String & _conditionSubtype);
  Condition(const Condition & source);
  virtual ~Condition() {}
  const Condition & operator=(const Condition & source);
  const String & getConditionType() const;
  const String & getConditionSubtype() const;
  virtual bool accept(bool value __attribute__(( unused)) );
  virtual bool accept(int  value __attribute__(( unused)) );
  virtual bool accept(double  value __attribute__(( unused)) );
  virtual void print(std::ostream & os __attribute__(( unused)) ,
                     int style __attribute__(( unused)),
                     int size __attribute__(( unused)) );
};

class ConditionBool : public Condition
{
public:

  bool   requested;

  ConditionBool(const String & _conditionType,
                const String & _conditionSubtype,
                bool _requested);
  ConditionBool(const ConditionBool & source);
  virtual ~ConditionBool() {};
  const ConditionBool & operator=(const ConditionBool & source);
  virtual bool accept(bool value);
  virtual void print(std::ostream & os=std::cout, int style=0, int size=50);
};

class ConditionIntValue : public Condition
{
public:

  int value;

  ConditionIntValue(const String & _conditionType,
                    const String & _conditionSubtype,
                    int _value);
  ConditionIntValue(const ConditionIntValue & source);
  virtual ~ConditionIntValue() {}
  const ConditionIntValue & operator=(const ConditionIntValue & source);
  virtual bool accept(int value);
  virtual void print(std::ostream & os=std::cout, int style=0, int size=50);
};

class ConditionIntRange : public Condition
{
public:

  int minimum;
  int maximum;

  ConditionIntRange(const String & _conditionType,
                    const String & _conditionSubtype,
                    int _minimum,
                    int _maximum);
  ConditionIntRange(const ConditionIntRange & source);
  virtual ~ConditionIntRange() {}
  const ConditionIntRange & operator=(const ConditionIntRange & source);
  virtual bool accept(int value);
  virtual void print(std::ostream & os=std::cout, int style=0, int size=50);
};

class ConditionDouble : public Condition
{
public:

  double minimum;
  double maximum;

  ConditionDouble(const String & _conditionType,
                  const String & _conditionSubtype,
                  double _minimum,
                  double _maximum);
  ConditionDouble(const ConditionDouble & source);
  virtual ~ConditionDouble() {}
  const ConditionDouble & operator=(const ConditionDouble & source);
  virtual bool accept(double value);
  virtual void print(std::ostream & os=std::cout, int style=0, int size=50);
};

class ConditionOr : public ConditionDouble
{
public:

  double minimum2;
  double maximum2;

  ConditionOr(const String & _conditionType,
              const String & _conditionSubtype,
              double _minimum,
              double _maximum,
              double _minimum2,
              double _maximum2);
  ConditionOr(const ConditionOr & source);
  virtual ~ConditionOr() {}
  const ConditionOr & operator=(const ConditionOr & source);
  virtual void print(std::ostream & os=std::cout, int style=0, int size=50);
  virtual bool accept(double value);
};

//!
//!Generic filter
//!
template < class T >
class Filter
{
protected:

public:

  Filter();
  virtual ~Filter();
  virtual bool accept(const T & object __attribute__((unused)));
  virtual bool accept(const T & object1 __attribute__((unused)), const T & object2 __attribute__((unused)));
  String getName() const;
  String getTitle() const;
  virtual void print(std::ostream & os, int style=0, int size=20);
  void setName(const String  & newName);
  void setTitle(const String  & newTitle);
  void addCondition(const String & _conditionType,
                    const String & _conditionSubtype,
                    bool _requested);
  void addCondition(const String & _conditionType,
                    const String & _conditionSubtype,
                    int _value);
  void addCondition(const String & _conditionType,
                    const String & _conditionSubtype,
                    int _minimum,
                    int _maximum);
  void addCondition(const String & _conditionType,
                    const String & _conditionSubtype,
                    double _minimum,
                    double _maximum);
  void addCondition(const String & _conditionType,
                    const String & _conditionSubtype,
                    double _minimum,
                    double _maximum,
                    double _minimum2,
                    double _maximum2);
  unsigned int getNConditions() const;
  std::vector<Condition*> & getConditions();
  const std::vector<Condition*> & getConditions() const;
  void reset();
  void clear();

protected:

  String name;
  String title;
  std::vector<Condition*> conditions;

  ClassDef(Filter,0)
};



template < class T >
Filter<T>::Filter()
:
name(""),
title(""),
conditions()
{ /* no ops */ }

template < class T >
Filter<T>::~Filter()
{
  clear();
}

//!
//! Test whether the given object is acceptable based on this filter's criteria.
//!  The base class accepts all objects submitted.
//!
template < class T >
bool Filter<T>::accept(const T & object __attribute__((unused)))
{
  return true;
}

//! Test whether the given objects are acceptable based on this filter's criteria.
//!  The base class accepts all objects submitted.
template < class T >
bool Filter<T>::accept(const T & object1 __attribute__((unused)), const T & object2 __attribute__((unused)))
{
  return true;
}


template < class T >
String Filter<T>::getName() const
{
  return name;
}

template < class T >
String Filter<T>::getTitle() const
{
  return title;
}

template < class T >
void Filter<T>::print(std::ostream & os, int style, int size)
{
  printValue("Filter name",name);
  printValue("Filter title",title);
  for (auto & condition : conditions) condition->print(os,style,size);
}

template < class T >
void Filter<T>::setName(const String  & newName)
{
  name = newName;
}

template < class T >
void Filter<T>::setTitle(const String  & newTitle)
{
  title = newTitle;
}

template < class T >
void Filter<T>::addCondition(const String & _conditionType,
                             const String & _conditionSubtype,
                             bool _requested)
{
  conditions.push_back(new ConditionBool(_conditionType,_conditionSubtype,_requested));
}

template < class T >
void Filter<T>::addCondition(const String & _conditionType,
                             const String & _conditionSubtype,
                             int _requested)
{
  conditions.push_back(new ConditionIntValue(_conditionType,_conditionSubtype,_requested));
}


template < class T >
void Filter<T>::addCondition(const String & _conditionType,
                             const String & _conditionSubtype,
                             int _minimum,
                             int _maximum)
{
  conditions.push_back(new ConditionIntRange(_conditionType,_conditionSubtype,_minimum,_maximum));
}


template < class T >
void Filter<T>::addCondition(const String & _conditionType,
                             const String & _conditionSubtype,
                             double _minimum,
                             double _maximum)
{
  conditions.push_back(new ConditionDouble(_conditionType,_conditionSubtype,_minimum,_maximum));
}

template < class T >
void Filter<T>::addCondition(const String & _conditionType,
                             const String & _conditionSubtype,
                             double _minimum,
                             double _maximum,
                             double _minimum2,
                             double _maximum2)
{
  conditions.push_back(new ConditionOr(_conditionType,_conditionSubtype,_minimum,_maximum,_minimum2,_maximum2));
}

template < class T >
unsigned int Filter<T>::getNConditions() const
{
  return conditions.size();
}

template < class T >
const std::vector<Condition*> & Filter<T>::getConditions() const
{
  return conditions;
}

template < class T >
std::vector<Condition*> & Filter<T>::getConditions()
{
  return conditions;
}

template < class T >
void Filter<T>::reset()
{

}

template < class T >
void Filter<T>::clear()
{
  for (auto & condition : conditions) delete condition;
  conditions.clear();
}

} // namespace CAP


#endif /* CAP__Filter  */

