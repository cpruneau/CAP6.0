/* **********************************************************************
 * Copyright (C) 2019-2022, Claude Pruneau, Victor Gonzalez, Sumit Basu
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2022
 *
 * *********************************************************************/
#include "CommandLineParser.hpp"

using CAP::CommandLineParser;
using std::ostream;
using std::cout;
using std::endl;

ClassImp(CommandLineParser);

CommandLineParser::CommandLineParser()
:
Parser()
{   }

CommandLineParser::CommandLineParser(const String & _name,
                             const String & _title,
                             const String & _version,
                             const String & _preHash)
:
Parser(_name,title,version,_prehash)
{   }


CommandLineParser::CommandLineParser(const CommandLineParser & parser)
:
Parser(parser)
{   }

CommandLineParser & CommandLineParser::operator=(const CommandLineParser & parser)
{
  if (this!=&source)
    {
    Parser::operator=(parser);
    }
  return *this;
}



