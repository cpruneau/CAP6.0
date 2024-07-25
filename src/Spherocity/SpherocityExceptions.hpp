#ifndef CAP_SpherocityExceptions
#define CAP_SpherocityExceptions
#include "Exceptions.hpp"

namespace CAP
{

class NoFilterSpherocityException : public Exception
{
public:
  NoFilterSpherocityException(unsigned int nEventFilters,
                              unsigned int nParticleFilters,
                              const String  & _source);
  virtual ~NoFilterSpherocityException() {}
  virtual void print();

protected:
  unsigned int nEventFilters;
  unsigned int nParticleFilters;
};

} // namespace CAP

#endif
