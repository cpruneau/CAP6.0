#ifndef CAP_Exceptions
#define CAP_Exceptions
#include <iostream>
#include "Aliases.hpp"
#include "NameHelpers.hpp"

namespace CAP
{

class Exception
{
public:
  Exception(const String  & _message,
            const String  & _source,
            const String  & _exceptionClass="Exception");
  virtual ~Exception() {}
  virtual void print();

protected:
  const String  exception;
  const String  source;
  const String  message;
};

class NullPointerException : public Exception
{
public:
  NullPointerException(const String  & _source);
  NullPointerException(const String  & _comment, const String  & _source);
  virtual ~NullPointerException() {}
};

class OutOfBoundException : public Exception
{
public:
  OutOfBoundException(const String  & _source);
  virtual ~OutOfBoundException() {}
};

class MemoryException : public Exception
{
public:
  MemoryException(const String  & _message, const String  & _source);
  virtual ~MemoryException() {}
};

class FactoryException : public Exception
{
public:
  FactoryException(long _currentSize,
                   long _requestedSize,
                   const String  & _message,
                   const String  & _source);
  virtual ~FactoryException() {}
  virtual void print();
protected:
  long currentSize;
  long requestedSize;
};

class TaskException : public Exception
{
public:
  TaskException(const String  & _message, const String  & _source);
  virtual ~TaskException() {}
};

class UnknownTaskException : public Exception
{
public:
  UnknownTaskException(const String  & _name, const String  & _source);
  virtual ~UnknownTaskException() {}
  virtual void print();
protected:
  const String  name;
};


class FileException : public Exception
{
public:
  FileException(const String  & _fileName, const String  & _message, const String  & _source);
  FileException(const String  & _pathName, const String  & _fileName, const String  & _message, const String  & _source);
  virtual ~FileException() {}
  virtual void print();
protected:
  const String  pathName;
  const String  fileName;
};


class HistogramException : public Exception
{
public:
  HistogramException(const String  & _histogramName, const String  & _message, const String  & _source);
  virtual ~HistogramException() {}
  virtual void print();
protected:
  const String  histogramName;
};

class IncompatibleHistogramException : public Exception
{
public:
  IncompatibleHistogramException(const String  & _source);
  virtual ~IncompatibleHistogramException() {}
};

class IncompatibleGroupException : public Exception
{
public:
  IncompatibleGroupException(const String  & _source);
  virtual ~IncompatibleGroupException() {}
};



class PropertyException : public Exception
{
public:
  PropertyException(const String  & _name, const String  & _message, const String  & _source);
  virtual ~PropertyException() {}
  virtual void print();
protected:
  const String  keyword;
};

class ConfigurationException : public Exception
{
public:
  ConfigurationException(const String  & _histogramName, const String  & _message, const String  & _source);
  virtual ~ConfigurationException() {}
  virtual void print();
protected:
  const String  keyword;
};


} // namespace CAP

#endif
