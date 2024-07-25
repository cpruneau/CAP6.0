#include "NuDynExceptions.hpp"
#include "PrintHelpers.hpp"

namespace CAP
{
NuDynException::NuDynException(const String & _message, const String & _source)
:
Exception(_message,_source,__FUNCTION__)
{   }

} // namespace CAP

