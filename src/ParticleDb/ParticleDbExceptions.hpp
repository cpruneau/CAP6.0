#ifndef CAP_ParticleDbExceptions
#define CAP_ParticleDbExceptions
#include "Aliases.hpp"
#include "Exceptions.hpp"
namespace CAP
{

class ParticleDecayException : public Exception
{
public:
  ParticleDecayException(const String   & _message, const String  & _source);
  virtual ~ParticleDecayException() {}
};

class InvalidIndexParticleDbException : public Exception
{
public:
  InvalidIndexParticleDbException(int index, const String  & _source);
  virtual ~InvalidIndexParticleDbException() {}
  virtual void print();

protected:
  int index;
};

class UndefinedParticleDbException : public Exception
  {
  public:
  UndefinedParticleDbException(const String  & name, const String  & _source);
  virtual ~UndefinedParticleDbException() {}
  virtual void print();

  protected:
  String name;
  };


class NoSelectedParticleDbException : public Exception
{
public:
  NoSelectedParticleDbException(const String  & _source);
  virtual ~NoSelectedParticleDbException() {}
};

class NonExistingParticleDbException : public Exception
{
public:
  NonExistingParticleDbException(const String  & name, const String  & _source);
  virtual ~NonExistingParticleDbException() {}
  virtual void print();

protected:
  String name;
};

class ExistingParticleDbException : public Exception
{
public:
  ExistingParticleDbException(const String  & name, const String  & _source);
  virtual ~ExistingParticleDbException() {}
  virtual void print();

protected:
  String name;
};

class NullPtrParticleDbException : public Exception
{
public:
  NullPtrParticleDbException(const String  & _source);
  virtual ~NullPtrParticleDbException() {}
};

class UnknownParticleDbException : public Exception
{
public:
  UnknownParticleDbException(const String  & _name,const String  & _source);
  virtual ~UnknownParticleDbException() {}
  virtual void print();

protected:
  String name;
};

class NotFoundFileParticleDbException : public Exception
{
public:
  NotFoundFileParticleDbException(const String  & _pathName,
                                  const String  & _fileName,
                                  const String  & _source);
  virtual ~NotFoundFileParticleDbException() {}
  virtual void print();

protected:
  String pathName;
  String fileName;
};


} // namespace CAP

#endif
