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
#include "ResolutionFunction.hpp"
#include "PrintHelpers.hpp"
#include "TRandom.h"

ClassImp(CAP::ResolutionFunction);

namespace CAP
{

ResolutionFunction::ResolutionFunction(int    _option,
                                       double _aInvPtBias,
                                       double _a0Bias,
                                       double _a1PtBias,
                                       double _a2PtBias,
                                       double _a1EtaBias,
                                       double _a2EtaBias,
                                       double _aInvPtRms,
                                       double _a0Rms,
                                       double _a1PtRms,
                                       double _a2PtRms,
                                       double _a1EtaRms,
                                       double _a2EtaRms)
:
option(_option),
aInvPtBias(_aInvPtBias),
a0Bias(_a0Bias),
a1PtBias(_a1PtBias),
a2PtBias(_a2PtBias),
a1EtaBias(_a1EtaBias),
a2EtaBias(_a2EtaBias),
aInvPtRms(_aInvPtRms),
a0Rms(_a0Rms),
a1PtRms(_a1PtRms),
a2PtRms(_a2PtRms),
a1EtaRms(_a1EtaRms),
a2EtaRms(_a2EtaRms)
{    }

ResolutionFunction::ResolutionFunction(const ResolutionFunction & f)
:
option(f.option),
aInvPtBias(f.aInvPtBias),
a0Bias(f.a0Bias),
a1PtBias(f.a1PtBias),
a2PtBias(f.a2PtBias),
a1EtaBias(f.a1EtaBias),
a2EtaBias(f.a2EtaBias),
aInvPtRms(f.aInvPtRms),
a0Rms(f.a0Rms),
a1PtRms(f.a1PtRms),
a2PtRms(f.a2PtRms),
a1EtaRms(f.a1EtaRms),
a2EtaRms(f.a2EtaRms)
{    }

ResolutionFunction ResolutionFunction::operator=(const ResolutionFunction & f)
{
  if (this!=&f)
  {
    option       =  f.option;
    aInvPtBias   =  f.aInvPtBias;
    a0Bias       =  f.a0Bias;
    a1PtBias     =  f.a1PtBias;
    a2PtBias     =  f.a2PtBias;
    a1EtaBias    =  f.a1EtaBias;
    a2EtaBias    =  f.a2EtaBias;
    aInvPtRms    =  f.aInvPtRms;
    a0Rms        =  f.a0Rms;
    a1PtRms      =  f.a1PtRms;
    a2PtRms      =  f.a2PtRms;
    a1EtaRms     =  f.a1EtaRms;
    a2EtaRms     =  f.a2EtaRms;
  }
  return *this;
}


double ResolutionFunction::smear(double pt, double eta, double phi, double & output)
{
  double ptSq = pt*pt;
  double etaSq = eta*eta;
  double bias = aInvPtBias/pt + a0Bias + a1PtBias*pt + a2PtBias*ptSq + a1EtaBias*eta + a2EtaBias*etaSq;
  double rms  = aInvPtRms/pt  + a0Rms  + a1PtRms*pt  + a2PtRms*ptSq  + a1EtaBias*eta + a2EtaBias*etaSq;
  switch (option)
    {
      case 0: output = gRandom->Gaus(pt+bias,rms);   break;
      case 1: output = gRandom->Gaus(eta+bias,rms); break;
      case 2: output = gRandom->Gaus(phi+bias,rms); break;
    }
  return output;
}

} // namespace CAP
