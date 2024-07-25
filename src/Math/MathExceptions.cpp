#include "MathExceptions.hpp"


namespace CAP
{

MathException::MathException(const String & _message, const String & _source)
:
Exception(_message,_source, __FUNCTION__)
{   }

} // namespace CAP

