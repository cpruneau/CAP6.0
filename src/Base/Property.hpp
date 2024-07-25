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
#ifndef CAP__Property
#define CAP__Property
#include <iostream>
#include "Aliases.hpp"

namespace CAP
{

class Property
{
protected:

  String pName;
  String pValue;

public:

  Property();
  Property(const char * name, const char * value);
  Property(const char * name, const String & value);
  Property(const char * name, bool value);
  Property(const char * name, int value);
  Property(const char * name, long value);
  Property(const char * name, double value);
  Property(const Property & property);
  virtual ~Property();
  const Property operator=(const Property & property);
  const String & name() const;
  const String & value() const;
  void setName(const char * name);
  void setName(const String & name);
  bool isNamed() const;
  bool isNamed(const char * name) const;
  bool isSet() const;
  bool sameNameAs(const Property rhs) const;
  bool sameValueAs(const Property rhs) const;
  bool nameEndsWith(const char * aKeyword) const;
  bool nameContains(const char * aKeyword) const;
  bool valueContains(const char * aKeyword) const;
  bool isEqualTo(const Property rhs) const;
  void reset();
  void clear();
  void setValue(const char * value);
  void setValue(const String & value);
  void setValue(bool value);
  void setValue(int value);
  void setValue(long value);
  void setValue(double value);
  void set(const char * name, const char * value);
  void set(const char * name, const String & value);
  void set(const char * name, bool value);
  void set(const char * name, int value);
  void set(const char * name, long value);
  void set(const char * name, double value);
  bool  isBool() const;
  bool isInt() const;
  bool isLong() const;
  bool isDouble() const;
  bool isString() const;
  bool  getBool() const;
  int getInt() const;
  long getLong() const;
  double getDouble() const;
  const String getString() const;
  const String getUpperString() const;
  const String getLowerString() const;
  bool nameHasEndColon() const;
  void print(std::ostream & output=std::cout, int style=0, int size=50) const;

  ClassDef(Property,0)


};

} // namespace CAP

#endif /* Property_hpp */
