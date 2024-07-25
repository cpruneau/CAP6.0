#ifndef CAP_TherminatorExceptions
#define CAP_TherminatorExceptions
#include "Exceptions.hpp"

namespace CAP
{
class NoModelImpTherminatorException : public Exception
{
public:
  NoModelImpTherminatorException(const String   & _message, const String  & _source);
  virtual ~NoModelImpTherminatorException() {}
};

} // namespace CAP

#endif
