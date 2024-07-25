#include "TherminatorExceptions.hpp"

namespace CAP
{
NoModelImpTherminatorException::NoModelImpTherminatorException(const String & _message, const String & _source)
:
Exception(_message,_source,__FUNCTION__)
{   }

} // namespace CAP

