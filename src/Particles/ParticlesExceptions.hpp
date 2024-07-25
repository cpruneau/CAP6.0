#ifndef CAP_ParticlesExceptions
#define CAP_ParticlesExceptions
#include <iostream>
#include "Aliases.hpp"
#include "Exceptions.hpp"

namespace CAP
{
class EventIndexException : public Exception
{
public:
  EventIndexException(unsigned int _index, unsigned int _size, const String  & _source);
  virtual ~EventIndexException() {}
  virtual void print();
protected:
  unsigned int index;
  unsigned int size;
};

class EventOwnershipException : public Exception
{
public:
  EventOwnershipException(unsigned int _index, const String  & _source);
  virtual ~EventOwnershipException() {}
  virtual void print();
protected:
  unsigned int index;
};

class ExistingEventStreamException : public Exception
{
public:
  ExistingEventStreamException(const String  & _name, const String  & _source);
  virtual ~ExistingEventStreamException() {}
  virtual void print();
protected:
  String name;
};

class NonExistingEventStreamException : public Exception
{
public:
  NonExistingEventStreamException(const String  & _name, const String  & _source);
  virtual ~NonExistingEventStreamException() {}
  virtual void print();
protected:
  String name;
};

class ExistingFilterSetException : public Exception
{
public:
  ExistingFilterSetException(const String  & _name, const String  & _source);
  virtual ~ExistingFilterSetException() {}
  virtual void print();
protected:
  String name;
};


class NonExistingFilterSetException : public Exception
{
public:
  NonExistingFilterSetException(const String  & _name, const String  & _source);
  virtual ~NonExistingFilterSetException() {}
  virtual void print();
protected:
  String name;
};

} // namespace CAP

#endif
