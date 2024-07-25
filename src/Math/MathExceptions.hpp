#ifndef CAP_MathExceptions
#define CAP_MathExceptions
#include "Exceptions.hpp"
namespace CAP
{
class MathException : public Exception
{
public:
  MathException(const String  & _message, const String  & _source);
  virtual ~MathException() {}
};

} // namespace CAP

#endif
