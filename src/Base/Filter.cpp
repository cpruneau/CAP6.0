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
#include "Filter.hpp"

namespace CAP
{

Condition::Condition(const String & _conditionType,
                     const String & _conditionSubtype)
:
conditionType(_conditionType),
conditionSubtype(_conditionSubtype)
{}

Condition::Condition(const Condition & source)
:
conditionType(source.conditionType),
conditionSubtype(source.conditionSubtype)
{}

const Condition & Condition::operator=(const Condition & source)
{
  if (this!=&source)
    {
    conditionType    = source.conditionType;
    conditionSubtype = source.conditionSubtype;
    }
  return *this;
}

const String & Condition::getConditionType() const
{
  return conditionType;
}

const String & Condition::getConditionSubtype() const
{
  return conditionSubtype;
}

bool Condition::accept(bool value __attribute__(( unused)) )
{
  throw Exception("Bad Condition",__FUNCTION__);
}

bool Condition::accept(int  value __attribute__(( unused)) )
{
  throw Exception("Bad Condition",__FUNCTION__);
}

bool Condition::accept(double  value __attribute__(( unused)) )
{
  throw Exception("Bad Condition",__FUNCTION__);
}

void Condition::print(std::ostream & os __attribute__(( unused)) ,
                      int style __attribute__(( unused)),
                      int size __attribute__(( unused)) )
{
  throw Exception("Bad Condition",__FUNCTION__);
}

ConditionBool::ConditionBool(const String & _conditionType,
                             const String & _conditionSubtype,
                             bool _requested)
:
Condition(_conditionType,_conditionSubtype),
requested(_requested)
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

bool ConditionBool::accept(bool value)
{
  return (value == requested);
}

void ConditionBool::print(std::ostream & os, int style, int size)
{
  String s = "Type:"; s += conditionType; s += " Subtype:"; s += conditionSubtype;
  printValue(s,requested, os, style, size);
}

///
///

ConditionIntValue::ConditionIntValue(const String & _conditionType,
                           const String & _conditionSubtype,
                           int _value)
:
Condition(_conditionType,_conditionSubtype),
value(_value)
{}

ConditionIntValue::ConditionIntValue(const ConditionIntValue & source)
:
Condition(source),
value(source.value)
{}

const ConditionIntValue & ConditionIntValue::operator=(const ConditionIntValue & source)
{
  if (this!=&source)
    {
    Condition::operator=(source);
    value = source.value;
    }
  return *this;
}

bool ConditionIntValue::accept(int _value)
{
  return (value == _value);
}

void ConditionIntValue::print(std::ostream & os, int style, int size)
{
  String s = "Type:"; s += conditionType; s += " Subtype:"; s += conditionSubtype;
  printValue(s,value, os, style, size);
}

// ===
ConditionIntRange::ConditionIntRange(const String & _conditionType,
                           const String & _conditionSubtype,
                           int _minimum,
                           int _maximum)
:
Condition(_conditionType,_conditionSubtype),
minimum(_minimum),
maximum(_maximum)
{}

ConditionIntRange::ConditionIntRange(const ConditionIntRange & source)
:
Condition(source),
minimum(source.minimum),
maximum(source.maximum)
{}

const ConditionIntRange & ConditionIntRange::operator=(const ConditionIntRange & source)
{
  if (this!=&source)
    {
    Condition::operator=(source);
    minimum = source.minimum;
    maximum = source.maximum;
    }
  return *this;
}

bool ConditionIntRange::accept(int value)
{
  return (value>=minimum && value<=maximum);
}

void ConditionIntRange::print(std::ostream & os, int style, int size)
{
  String s = "Type:"; s += conditionType; s += " Subtype:"; s += conditionSubtype;
  printRange(s,minimum,maximum, os, style, size);
}

ConditionDouble::ConditionDouble(const String & _conditionType,
                                 const String & _conditionSubtype,
                                 double _minimum,
                                 double _maximum)
:
Condition(_conditionType,_conditionSubtype),
minimum(_minimum),
maximum(_maximum)
{}

ConditionDouble::ConditionDouble(const ConditionDouble & source)
:
Condition(source),
minimum(source.minimum),
maximum(source.maximum)
{}

const ConditionDouble & ConditionDouble::operator=(const ConditionDouble & source)
{
  if (this!=&source)
    {
    Condition::operator=(source);
    minimum = source.minimum;
    maximum = source.maximum;
    }
  return *this;
}

bool ConditionDouble::accept(double value)
{
  return (value>=minimum && value<maximum);
}

void ConditionDouble::print(std::ostream & os, int style, int size)
{
  String s = "Type:"; s += conditionType; s += " Subtype:"; s += conditionSubtype;
  printRange(s,minimum,maximum, os, style, size);
}


ConditionOr::ConditionOr(const String & _conditionType,
                         const String & _conditionSubtype,
                         double _minimum,
                         double _maximum,
                         double _minimum2,
                         double _maximum2)
:
ConditionDouble(_conditionType,_conditionSubtype,_minimum,_maximum),
minimum2(_minimum2),
maximum2(_maximum2)
{}

ConditionOr::ConditionOr(const ConditionOr & source)
:
ConditionDouble(source),
minimum2(source.minimum2),
maximum2(source.maximum2)
{}

const ConditionOr & ConditionOr::operator=(const ConditionOr & source)
{
  if (this!=&source)
    {
    ConditionDouble::operator=(source);
    minimum2 = source.minimum2;
    maximum2 = source.maximum2;
    }
  return *this;
}

void ConditionOr::print(std::ostream & os, int style, int size)
{
  String s = "Type:"; s += conditionType; s += " Subtype:"; s += conditionSubtype;
  printRangeOr(s,minimum,maximum,minimum2,maximum2, os, style, size);
}

bool ConditionOr::accept(double value)
{
  return (value>=minimum && value<maximum) || (value>=minimum2 && value<maximum2);
}

} // namespace CAP

