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
#ifndef CAP__Condition
#define CAP__Condition
#include "Aliases.hpp"
#include "Exceptions.hpp"
#include "PrintHelpers.hpp"

using CAP::String;

namespace CAP
{

class ConditionException : public Exception
{
public:
  ConditionException(const String  & _message,
                     const String  & _source);
  virtual ~ConditionException() {}
};


class Condition
{
public:

  enum ConditionType   { kCondition, kConditionBool, kConditionInteger, kConditionIntegerRange, kConditionDoubleRange, kConditionDoubleDualRange};

  Condition(int _conditionSubtype);
  Condition(const Condition & source);
  virtual ~Condition() {}
  const Condition & operator=(const Condition & source);
  virtual ConditionType getConditionType() const;
  virtual String getConditionTypeName() const;
  virtual int  getConditionSubtype() const;
  virtual bool accept(bool value __attribute__(( unused)) );
  virtual bool accept(int  value __attribute__(( unused)) );
  virtual bool accept(double  value __attribute__(( unused)) );
  virtual void print(std::ostream & os __attribute__(( unused)) ,
                     int style __attribute__(( unused)),
                     int size __attribute__(( unused)) );

  int  conditionSubtype;

};

class ConditionBool : public Condition
{
public:

  bool   requested;

  ConditionBool(int _conditionSubtype,
                bool _requestedValue);
  ConditionBool(const ConditionBool & source);
  virtual ~ConditionBool() {};
  const ConditionBool & operator=(const ConditionBool & source);
  virtual ConditionType getConditionType() const;
  virtual String getConditionTypeName() const;
  virtual bool accept(bool value);
  virtual void print(std::ostream & os=std::cout, int style=0, int size=50);
};

class ConditionInteger : public Condition
{
public:

  int value;

  ConditionInteger(int _conditionSubtype,
                   int _requestedValue);
  ConditionInteger(const ConditionInteger & source);
  virtual ~ConditionInteger() {}
  const ConditionInteger & operator=(const ConditionInteger & source);
  virtual ConditionType getConditionType() const;
  virtual String getConditionTypeName() const;
  virtual bool accept(int value);
  virtual void print(std::ostream & os=std::cout, int style=0, int size=50);
};

class ConditionIntegerRange : public Condition
{
public:

  int minimum;
  int maximum;

  ConditionIntegerRange(int _conditionSubtype,
                        int _minimum,
                        int _maximum);
  ConditionIntegerRange(const ConditionIntegerRange & source);
  virtual ~ConditionIntegerRange() {}
  const ConditionIntegerRange & operator=(const ConditionIntegerRange & source);
  virtual ConditionType getConditionType() const;
  virtual String getConditionTypeName() const;
  virtual bool accept(int value);
  virtual void print(std::ostream & os=std::cout, int style=0, int size=50);
};

class ConditionDoubleRange : public Condition
{
public:

  double minimum;
  double maximum;

  ConditionDoubleRange(int _conditionSubtype,
                       double _minimum,
                       double _maximum);
  ConditionDoubleRange(const ConditionDoubleRange & source);
  virtual ~ConditionDoubleRange() {}
  const ConditionDoubleRange & operator=(const ConditionDoubleRange & source);
  virtual ConditionType getConditionType() const;
  virtual String getConditionTypeName() const;
  virtual bool accept(double value);
  virtual void print(std::ostream & os=std::cout, int style=0, int size=50);
};

class ConditionDoubleDualRange : public ConditionDoubleRange
{
public:

  double minimum2;
  double maximum2;

  ConditionDoubleDualRange(int _conditionSubtype,
                           double _minimum,
                           double _maximum,
                           double _minimum2,
                           double _maximum2);
  ConditionDoubleDualRange(const ConditionDoubleDualRange & source);
  virtual ~ConditionDoubleDualRange() {}
  const ConditionDoubleDualRange & operator=(const ConditionDoubleDualRange & source);
  virtual ConditionType getConditionType() const;
  virtual String getConditionTypeName() const;
  virtual bool accept(double value);
  virtual void print(std::ostream & os=std::cout, int style=0, int size=50);
};



#endif /* CAP__Filter  */


}

