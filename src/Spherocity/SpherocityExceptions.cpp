#include "SpherocityExceptions.hpp"
#include "PrintHelpers.hpp"

namespace CAP
{
NoFilterSpherocityException::NoFilterSpherocityException(unsigned int _nEventFilters,
                                                         unsigned int _nParticleFilters,
                                                         const String  & _source)
:
Exception("Missing filters",_source,__FUNCTION__),
nEventFilters(_nEventFilters),
nParticleFilters(_nParticleFilters)
{   }

void NoFilterSpherocityException::print()
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

