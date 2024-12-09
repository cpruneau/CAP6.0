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
#ifndef CAP__Aliases
#define CAP__Aliases
#include <vector>
#include "TString.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TLorentzVector.h"

namespace CAP
{
using Size_t        = unsigned int;
using String        = TString;
using Histogram1D   = TH1;
using Histogram2D   = TH2;
using Histogram3D   = TH3;
using LorentzVector = TLorentzVector;
using VectorString  = std::vector<String>;

static bool verbose = false;
void setVerbose(bool _verbose);
bool isVerbose();
}

#endif /* CAP__Aliases */
