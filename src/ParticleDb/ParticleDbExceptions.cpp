#include "ParticleDbExceptions.hpp"
#include "PrintHelpers.hpp"


namespace CAP
{


ParticleDecayException::ParticleDecayException(const String & _message, const String & _source)
:
Exception(_message,_source,__FUNCTION__)
{   }

InvalidIndexParticleDbException::InvalidIndexParticleDbException(int _index, const String & _source)
:
Exception("Invalid Index",_source,__FUNCTION__),
index(_index)
{   }

void InvalidIndexParticleDbException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Index",index);
  printLine();
}


UndefinedParticleDbException::UndefinedParticleDbException(const String  & _name, const String & _source)
:
Exception("Name Not Found",_source,__FUNCTION__),
name(_name)
{   }

void UndefinedParticleDbException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Name",name);
  printLine();
}


NoSelectedParticleDbException::NoSelectedParticleDbException(const String & _source)
:
Exception("particleDb==0 or defaultParticleDb==0",_source,__FUNCTION__)
{   }

NonExistingParticleDbException::NonExistingParticleDbException(const String  & _name, const String & _source)
:
Exception("Db not defined",_source,__FUNCTION__),
name(_name)
{   }

void NonExistingParticleDbException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Name",name);
  printLine();
}


ExistingParticleDbException::ExistingParticleDbException(const String  & _name, const String & _source)
:
Exception("Db already defined",_source,__FUNCTION__),
name(_name)
{   }

void ExistingParticleDbException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Name",name);
  printLine();
}

NullPtrParticleDbException::NullPtrParticleDbException(const String & _source)
:
Exception("Null pointer",_source,__FUNCTION__)
{   }

UnknownParticleDbException::UnknownParticleDbException(const String  & _name, const String & _source)
:
Exception("Unknown particle",_source,__FUNCTION__),
name(_name)
{   }

void UnknownParticleDbException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Name",name);
  printLine();
}

NotFoundFileParticleDbException::NotFoundFileParticleDbException(const String  & _pathName,
                                                                 const String  & _fileName,
                                                                 const String  & _source)
:
Exception("Db File Not Found",_source),
pathName(_pathName),
fileName(_fileName)
{   }

void NotFoundFileParticleDbException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("pathName",pathName);
  printValue("fileName",fileName);
  printLine();
}



} // namespace CAP

