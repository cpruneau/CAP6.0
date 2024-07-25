#include "GlobalExceptions.hpp"
#include "PrintHelpers.hpp"

namespace CAP
{

NoFilterGlobalException::NoFilterGlobalException(unsigned int _nEventFilters,
                                                 unsigned int _nParticleFilters,
                                                 const String  & _source)
:
Exception("Missing filters",_source,__FUNCTION__),
nEventFilters(_nEventFilters),
nParticleFilters(_nParticleFilters)
{   }

void NoFilterGlobalException::print()
{
  printCR();
  printLine();
  printValue("Exception Type",exception);
  printLine();
  printValue("Source",source);
  printValue("Message",message);
  printValue("nEventFilters",nEventFilters);
  printValue("nParticleFilters",nParticleFilters);
  printLine();
}


} // namespace CAP

