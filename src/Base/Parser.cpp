/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Victor Gonzalez     
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
 *
 * *********************************************************************/
#include "Parser.hpp"
#include "Exceptions.hpp"

ClassImp(CAP::Parser);

namespace CAP
{

Parser::Parser()
{   }

Parser::Parser(const Parser & parser)
:
MessageLogger(parser)
{   }

Parser & Parser::operator=(const Parser & parser)
{
  if (this!=&parser)
    {
    MessageLogger::operator=(parser);
    }
  return *this;
}

} // namespace CAP
