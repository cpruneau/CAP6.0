#ifndef CAP_ParticlePairExceptions
#define CAP_ParticlePairExceptions
#include "Exceptions.hpp"
namespace CAP
{

class NoFilterParticlePairException : public Exception
{
public:
  NoFilterParticlePairException(unsigned int _nEventFilters,
                                  unsigned int _nParticleFilters,
                                  const String  & _source);
  virtual ~NoFilterParticlePairException() {}

  virtual void print();

protected:

  unsigned int nEventFilters;
  unsigned int nParticleFilters;
};

} // namespace CAP

#endif
