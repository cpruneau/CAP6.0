#include "ParticlesExceptions.hpp"
#include "PrintHelpers.hpp"

namespace CAP
{

EventIndexException::EventIndexException(unsigned int _index, unsigned int _size, const String  & _source)
:
Exception("Invalid index value",_source,__FUNCTION__),
index(_index),
size(_size)
{   }


void EventIndexException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("Index",index);
  printValue("Size",size);
  printLine();
}

EventOwnershipException::EventOwnershipException(unsigned int _index, const String  & _source)
:
Exception("Task does not own event with given index",_source,__FUNCTION__),
index(_index)
{   }


void EventOwnershipException::print()
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

ExistingEventStreamException::ExistingEventStreamException(const String  & _name, const String  & _source)
:
Exception("Attemting to create an already existing event stream named",_source,__FUNCTION__),
name(_name)
{   }

void ExistingEventStreamException::print()
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


NonExistingEventStreamException::NonExistingEventStreamException(const String  & _name, const String  & _source)
:
Exception("No event stream named",_source,__FUNCTION__),
name(_name)
{   }

void NonExistingEventStreamException::print()
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


NonExistingFilterSetException::NonExistingFilterSetException(const String  & _name, const String  & _source)
:
Exception("No filter set named",_source,__FUNCTION__),
name(_name)
{   }

void NonExistingFilterSetException::print()
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

ExistingFilterSetException::ExistingFilterSetException(const String  & _name, const String  & _source)
:
Exception("No filter set named",_source,__FUNCTION__),
name(_name)
{   }

void ExistingFilterSetException::print()
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


} // namespace CAP

