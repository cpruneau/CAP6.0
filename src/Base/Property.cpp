/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   5/17/2024
 *
 * *********************************************************************/
#include <iomanip>
#include "Property.hpp"
using CAP::Property;
using CAP::String;
using std::ostream;
using std::endl;
using std::left;
using std::setfill;
using std::setw;

ClassImp(CAP::Property);

Property::Property()
:
pName(),
pValue()
{ }

Property::Property(const char * name, const char * value)
:
pName(name),
pValue(value)
{   }

Property::Property(const char * name, const String & value)
:
pName(name),
pValue(value)
{  }

Property::Property(const char * name, bool value)
:
pName(name),
pValue()
{
  pValue   = "";
  pValue   += value;
}

Property::Property(const char * name, int value)
:
pName(name),
pValue()
{
  pValue   = "";
  pValue   += value;
}

Property::Property(const char * name, long value)
:
pName(name),
pValue()
{
  pValue   = "";
  pValue   += value;
}

Property::Property(const char * name, double value)
:
pName(name),
pValue()
{
  pValue   = "";
  pValue   += value;
}

Property::Property(const Property & property)
:
pName(property.pName),
pValue(property.pValue)
{ }

Property::~Property()
{ }

const Property Property::operator=(const Property & property)
{
  if (this!=&property)
    {
    pName  = property.pName;
    pValue = property.pValue;
    }
  return *this;
}


const String & Property::name() const
{
  return pName;
}

const String & Property::value() const
{
  return pValue;
}

// name only

void Property::setName(const char * name)
{
  pName = name;
}

void Property::setName(const String & name)
{
  pName = name;
}

bool Property::isNamed() const
{
  return pName.Sizeof()>1;
}


bool Property::isNamed(const char * name) const
{
  return pName.EqualTo(name);
}

bool Property::isSet() const
{
  return pName.Sizeof()>1 && pValue.Sizeof()>1;
}

bool Property::sameNameAs(const Property rhs) const
{
  return pName.EqualTo(rhs.pName);
}

bool Property::sameValueAs(const Property rhs) const
{
  return pValue.EqualTo(rhs.pValue);
}

bool Property::nameEndsWith(const char * keyword) const
{
  return pName.EndsWith(keyword);
}

bool Property::nameContains(const char * keyword) const
{
  return pName.Contains(keyword);
}

bool Property::valueContains(const char * keyword) const
{
  return pValue.Contains(keyword);
}

bool Property::isEqualTo(const Property rhs) const
{
  return pName.EqualTo(rhs.pName) && pValue.EqualTo(rhs.pValue);
}

void Property::reset()
{
  pValue = "";
}

void Property::clear()
{
  pName  = "";
  pValue = "";
}

// values only

void Property::setValue(const char * value)
{
  pValue   = "";
  pValue   += value;
}

void Property::setValue(const String & value)
{
  pValue   = "";
  pValue   += value;
}

void Property::setValue(bool value)
{
  pValue   = "";
  pValue   += value;
}

void Property::setValue(int value)
{
  pValue   = "";
  pValue   += value;
}

void Property::setValue(long value)
{
  pValue   = "";
  pValue   += value;
}

void Property::setValue(double value)
{
  pValue   = "";
  pValue   += value;
}

// name & value

void Property::set(const char * name, const char * value)
{
  pName    = name;
  pValue   = "";
  pValue   += value;
}

void Property::set(const char * name, const String & value)
{
  pName    = name;
  pValue   = "";
  pValue   += value;
}

void Property::set(const char * name, bool value)
{
  pName    = name;
  pValue   = "";
  pValue   += value;
}

void Property::set(const char * name, int value)
{
  pName    = name;
  pValue   = "";
  pValue   += value;
}

void Property::set(const char * name, long value)
{
  pName    = name;
  pValue   = "";
  pValue   += value;
}

void Property::set(const char * name, double value)
{
  pName    = name;
  pValue   = "";
  pValue   += value;
}

// extract bool, int, long, double
// v.ToUpper();

bool  Property::isBool() const
{
  String v = pValue;
  if (v.EqualTo("0") || v.EqualTo("FALSE") || v.EqualTo("YES") ) return true;
  else if (v.EqualTo("1") || v.EqualTo("TRUE")  || v.EqualTo("NO")  ) return true;
  return false;
}

// not quite right... should return false if integer is too large
bool Property::isInt() const
{
  if (!pValue.IsDec()) return false;
  return true;
}

// not quite right...
bool Property::isLong() const
{
  if (!pValue.IsDec()) return false;
  return true;
}

bool Property::isDouble() const
{
  if (pValue.IsFloat()) return true;
  return false;
}

// always can be considered a string... not good?
bool Property::isString() const
{
  return true;
}

bool  Property::getBool() const
{
  String v = pValue;
  v.ToUpper();
  if (v.EqualTo("0") || v.EqualTo("FALSE") || v.EqualTo("YES") ) return false;
  else if (v.EqualTo("1") || v.EqualTo("TRUE")  || v.EqualTo("NO")  ) return true;
  else if (v.IsDec())
    {
    int vv = v.Atoi();
    return vv>0;
    }
  return false;
}

int Property::getInt() const
{
  String v = pValue;
  if (v.IsDec()) return v.Atoi();
  return -9999;
  //throw Exception("Property value not an integer","Property::getInt()");
}

long Property::getLong() const
{
  String v = pValue;
  if (!v.IsDec())
    {
    return -99999;
    }
  return v.Atoll();
}

double Property::getDouble() const
{
  String v = pValue;
  if (!v.IsFloat())
    {
    return -1.0E100;
    }
  return v.Atof();
}

const String Property::getString() const
{
  return pValue;
}

const String Property::getUpperString() const
{
  String v = pValue; v.ToUpper();
  return v;
}

const String Property::getLowerString() const
{
  String v = pValue; v.ToLower();
  return v;
}

bool Property::nameHasEndColon() const
{
  int last = pName.Last(':');
  int size = pName.Length() - 1;
  return (last>0 && last == size);
}

void Property::print(ostream & output,  int style, int size)  const
{
  switch (style)
    {
      case 0: output << "Property " <<  left << setw(size) << setfill('.') << pName << " : " << pValue << setfill(' ') << endl; break;
      case 1: output << "Property " <<  left << setw(size) << setfill(' ') << pName << " : " << pValue << setfill(' ') << endl; break;
      case 2: output << "Property " <<  left << setw(size) << setfill('-') << pName << " : " << pValue << setfill(' ') << endl; break;
      case 3: output << "Property " <<  left << setw(size) << setfill('_') << pName << " : " << pValue << setfill(' ') << endl; break;
      case 10: output << "Property " <<  left << setw(size) << setfill(' ')<< pName << "=" << pValue << setfill(' ') << endl; break;

    }
}


