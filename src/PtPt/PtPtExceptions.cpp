#include "PtPtExceptions.hpp"
#include "PrintHelpers.hpp"

namespace CAP
{
PtPtException::PtPtException(const String & _message, const String & _source)
:
Exception(_message,_source,__FUNCTION__)
{   }

} // namespace CAP

