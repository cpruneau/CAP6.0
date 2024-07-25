#ifndef CAP_ParticleSingleExceptions
#define CAP_ParticleSingleExceptions
#include "Exceptions.hpp"

namespace CAP
{
class NoFilterParticleSingleException : public Exception
{
public:
  NoFilterParticleSingleException(unsigned int _nEventFilters,
                          unsigned int _nParticleFilters,
                          const String  & _source);
  virtual ~NoFilterParticleSingleException() {}

  virtual void print();

protected:

  unsigned int nEventFilters;
  unsigned int nParticleFilters;
};

} // namespace CAP

#endif
