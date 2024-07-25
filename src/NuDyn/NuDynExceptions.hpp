#ifndef CAP_NuDynException
#define CAP_NuDynException
#include "Aliases.hpp"
#include "Exceptions.hpp"
namespace CAP
{

class NuDynException : public Exception
{
public:
  NuDynException(const String   & _message, const String  & _source);
  virtual ~NuDynException() {}
};

} // namespace CAP

#endif
