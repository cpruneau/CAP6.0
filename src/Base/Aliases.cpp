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

#include "Aliases.hpp"

namespace CAP
{

void setVerbose(bool _verbose)
{
  verbose = _verbose;
}

bool isVerbose()
{
  return verbose;
}


} // namespace CAP
