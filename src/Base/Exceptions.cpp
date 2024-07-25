#include "Exceptions.hpp"
#include "PrintHelpers.hpp"

namespace CAP
{


Exception::Exception(const String & _message,
                     const String & _source,
                     const String  & _exceptionClass)
:
exception(_exceptionClass),
source(_source),
message(_message)
{   }

void Exception::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printLine();
}

NullPointerException::NullPointerException(const String & _source)
:
Exception("Null Pointer",_source,__FUNCTION__)
{   }

NullPointerException::NullPointerException(const String  & _comment, const String  & _source)
:
Exception(_comment,_source,__FUNCTION__)
{   }


OutOfBoundException::OutOfBoundException(const String & _source)
:
Exception("Index out of bound",_source,__FUNCTION__)
{   }

FactoryException::FactoryException(long _currentSize,
                                   long _requestedSize,
                                   const String & _message,
                                   const String & _source)
:
Exception(_message,_source,__FUNCTION__),
currentSize(_currentSize),
requestedSize(_requestedSize)
{   }

void FactoryException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Current Size",currentSize);
  printValue("Requested Size",requestedSize);
  printLine();
}

TaskException::TaskException(const String & _message, const String & _source)
:
Exception(_message,_source,__FUNCTION__)
{   }

UnknownTaskException::UnknownTaskException(const String & _name, const String & _source)
:
Exception("Unknown Task",_source,__FUNCTION__),
name(_name)
{   }

void UnknownTaskException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Name",   name);
  printLine();
}

MemoryException::MemoryException(const String & _message, const String & _source)
:
Exception(_message,_source,__FUNCTION__)
{   }

FileException::FileException(const String & _fileName, const String & _message, const String & _source)
:
Exception(_message,_source,__FUNCTION__),
pathName("nil"),
fileName(_fileName)
{   }

FileException::FileException(const String & _pathName, const String & _fileName, const String & _message, const String & _source)
:
Exception(_message,_source),
pathName(_pathName),
fileName(_fileName)
{   }

void FileException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Path name",pathName);
  printValue("File name",fileName);
  printLine();
}

HistogramException::HistogramException(const String & _histogramName, const String & _message, const String & _source)
:
Exception(_message,_source,__FUNCTION__),
histogramName(_histogramName)
{   }

void HistogramException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Histogram name",histogramName);
  printLine();
}

IncompatibleHistogramException::IncompatibleHistogramException(const String & _source)
:
Exception("Incompatible histogram dimensions",_source,__FUNCTION__)
{   }

IncompatibleGroupException::IncompatibleGroupException(const String & _source)
:
Exception("Incompatible group dimensions",_source,__FUNCTION__)
{   }

ConfigurationException::ConfigurationException(const String & _keyword, const String & _message, const String & _source)
:
Exception(_message,_source,__FUNCTION__),
keyword(_keyword)
{   }

void ConfigurationException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Keyword",keyword);
  printLine();
}

PropertyException::PropertyException(const String & _keyword, const String & _message, const String & _source)
:
Exception(_message,_source,__FUNCTION__),
keyword(_keyword)
{   }

void PropertyException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Keyword",keyword);
  printLine();
}


} // namespace CAP

