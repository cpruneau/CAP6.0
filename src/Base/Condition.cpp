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
#include "Condition.hpp"

namespace CAP
{

ConditionException::ConditionException(const String  & _message,
                                       const String  & _source)
:
Exception(_message,_source,__FUNCTION__)
{
// no ops
}


Condition::Condition(int _conditionSubtype)
:
conditionSubtype(_conditionSubtype)
{}

Condition::Condition(const Condition & source)
:
conditionSubtype(source.conditionSubtype)
{}

const Condition & Condition::operator=(const Condition & source)
{
  if (this!=&source)
    {
    conditionSubtype = source.conditionSubtype;
    }
  return *this;
}

Condition::ConditionType Condition::getConditionType() const
{
  return kCondition;
}

String Condition::getConditionTypeName() const
{
  return String("Condition");
}

int Condition::getConditionSubtype() const
{
  return conditionSubtype;
}

bool Condition::accept(bool value __attribute__(( unused)) )
{
  throw Exception("Bad Condition",__FUNCTION__);
}

bool Condition::accept(int  value __attribute__(( unused)) )
{
  throw ConditionException("Improper call to Condition::accept(int)",__FUNCTION__);
}

bool Condition::accept(double  value __attribute__(( unused)) )
{
  throw ConditionException("Improper call to Condition::accept(double)",__FUNCTION__);
}

void Condition::print(std::ostream & os __attribute__(( unused)) ,
                      int style __attribute__(( unused)),
                      int size __attribute__(( unused)) )
{
  throw ConditionException("Improper call to Condition::print(int)",__FUNCTION__);
}

ConditionBool::ConditionBool(int _conditionSubtype,
                             bool _requestedValue)
:
Condition(_conditionSubtype),
requested(_requestedValue)
{}

ConditionBool::ConditionBool(const ConditionBool & source)
:
Condition(source),
requested(source.requested)
{}

const ConditionBool & ConditionBool::operator=(const ConditionBool & source)
{
  if (this!=&source)
    {
    Condition::operator=(source);
    requested = source.requested;
    }
  return *this;
}

Condition::ConditionType ConditionBool::getConditionType() const
{
  return kConditionBool;
}

String ConditionBool::getConditionTypeName() const
{
  return String("ConditionBool");
}

bool ConditionBool::accept(bool value)
{
  return (value == requested);
}

void ConditionBool::print(std::ostream & os, int style, int size)
{
  String s = "Type:ConditionBool  Subtype:"; s += conditionSubtype;
  printValue(s,requested, os, style, size);
}

///
///

ConditionInteger::ConditionInteger(int _conditionSubtype,
                                   int _requestedValue)
:
Condition(_conditionSubtype),
value(_requestedValue)
{}

ConditionInteger::ConditionInteger(const ConditionInteger & source)
:
Condition(source),
value(source.value)
{}

const ConditionInteger & ConditionInteger::operator=(const ConditionInteger & source)
{
  if (this!=&source)
    {
    Condition::operator=(source);
    value = source.value;
    }
  return *this;
}

Condition::ConditionType ConditionInteger::getConditionType() const
{
  return kConditionInteger;
}

String ConditionInteger::getConditionTypeName() const
{
  return String("ConditionInteger");
}

bool ConditionInteger::accept(int _value)
{
  return (value == _value);
}

void ConditionInteger::print(std::ostream & os, int style, int size)
{
  String s = "Type:ConditionInteger  Subtype:"; s += conditionSubtype;
  printValue(s,value, os, style, size);
}

// ===
ConditionIntegerRange::ConditionIntegerRange(int _conditionSubtype,
                                             int _minimum,
                                             int _maximum)
:
Condition(_conditionSubtype),
minimum(_minimum),
maximum(_maximum)
{}

ConditionIntegerRange::ConditionIntegerRange(const ConditionIntegerRange & source)
:
Condition(source),
minimum(source.minimum),
maximum(source.maximum)
{}

const ConditionIntegerRange & ConditionIntegerRange::operator=(const ConditionIntegerRange & source)
{
  if (this!=&source)
    {
    Condition::operator=(source);
    minimum = source.minimum;
    maximum = source.maximum;
    }
  return *this;
}

Condition::ConditionType ConditionIntegerRange::getConditionType() const
{
  return kConditionIntegerRange;
}

String ConditionIntegerRange::getConditionTypeName() const
{
  return String("ConditionIntegerRange");
}

bool ConditionIntegerRange::accept(int value)
{
  return (value>=minimum && value<=maximum);
}

void ConditionIntegerRange::print(std::ostream & os, int style, int size)
{
  String s = "Type:ConditionIntegerRange  Subtype:"; s += conditionSubtype;
  printRange(s,minimum,maximum, os, style, size);
}

ConditionDoubleRange::ConditionDoubleRange(int _conditionSubtype,
                                           double _minimum,
                                           double _maximum)
:
Condition(_conditionSubtype),
minimum(_minimum),
maximum(_maximum)
{}

ConditionDoubleRange::ConditionDoubleRange(const ConditionDoubleRange & source)
:
Condition(source),
minimum(source.minimum),
maximum(source.maximum)
{}

const ConditionDoubleRange & ConditionDoubleRange::operator=(const ConditionDoubleRange & source)
{
  if (this!=&source)
    {
    Condition::operator=(source);
    minimum = source.minimum;
    maximum = source.maximum;
    }
  return *this;
}

Condition::ConditionType ConditionDoubleRange::getConditionType() const
{
  return kConditionDoubleRange;
}

String ConditionDoubleRange::getConditionTypeName() const
{
  return String("ConditionDoubleRange");
}

bool ConditionDoubleRange::accept(double value)
{
  return (value>=minimum && value<maximum);
}

void ConditionDoubleRange::print(std::ostream & os, int style, int size)
{
  String s = "Type:ConditionDoubleRange  Subtype:"; s += conditionSubtype;
  printRange(s,minimum,maximum, os, style, size);
}


ConditionDoubleDualRange::ConditionDoubleDualRange(int _conditionSubtype,
                                                   double _minimum,
                                                   double _maximum,
                                                   double _minimum2,
                                                   double _maximum2)
:
ConditionDoubleRange(_conditionSubtype,_minimum,_maximum),
minimum2(_minimum2),
maximum2(_maximum2)
{}

ConditionDoubleDualRange::ConditionDoubleDualRange(const ConditionDoubleDualRange & source)
:
ConditionDoubleRange(source),
minimum2(source.minimum2),
maximum2(source.maximum2)
{}

const ConditionDoubleDualRange & ConditionDoubleDualRange::operator=(const ConditionDoubleDualRange & source)
{
  if (this!=&source)
    {
    ConditionDoubleRange::operator=(source);
    minimum2 = source.minimum2;
    maximum2 = source.maximum2;
    }
  return *this;
}

void ConditionDoubleDualRange::print(std::ostream & os, int style, int size)
{
  String s = "Type:ConditionDoubleDualRange  Subtype:"; s += conditionSubtype;
  printDualRange(s,minimum,maximum,minimum2,maximum2, os, style, size);
}

Condition::ConditionType ConditionDoubleDualRange::getConditionType() const
{
  return kConditionDoubleDualRange;
}

String ConditionDoubleDualRange::getConditionTypeName() const
{
  return String("ConditionDoubleDualRange");
}

bool ConditionDoubleDualRange::accept(double value)
{
  return (value>=minimum && value<maximum) || (value>=minimum2 && value<maximum2);
}

} // namespace CAP

