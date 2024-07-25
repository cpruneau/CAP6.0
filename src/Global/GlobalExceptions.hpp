#ifndef CAP_GlobalException
#define CAP_GlobalException
#include "Exceptions.hpp"
namespace CAP
{

class NoFilterGlobalException : public Exception
{
public:
  NoFilterGlobalException(unsigned int _nEventFilters,
                          unsigned int _nParticleFilters,
                          const String  & _source);
  virtual ~NoFilterGlobalException() {}

  virtual void print();


protected:

  unsigned int nEventFilters;
  unsigned int nParticleFilters;
};

} // namespace CAP

#endif
