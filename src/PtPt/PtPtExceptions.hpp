#ifndef CAP_PtPtException
#define CAP_PtPtException
#include "Aliases.hpp"
#include "Exceptions.hpp"
namespace CAP
{

class PtPtException : public Exception
{
public:
  PtPtException(const String   & _message, const String  & _source);
  virtual ~PtPtException() {}
};

} // namespace CAP

#endif
