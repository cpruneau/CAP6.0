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
#ifndef CAP__ResolutionFunction
#define CAP__ResolutionFunction
#include "HistogramGroup.hpp"

namespace CAP
{

class ResolutionFunction
{
public:
   
  ResolutionFunction(int    _option,
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
                     double _a2EtaRms);
  ResolutionFunction(const ResolutionFunction & f);
  ResolutionFunction operator=(const ResolutionFunction & f);
  ~ResolutionFunction() {}
  double smear(double pt, double eta, double phi, double & output);

protected:

  int option;
  double aInvPtBias;
  double a0Bias;
  double a1PtBias;
  double a2PtBias;
  double a1EtaBias;
  double a2EtaBias;

  double aInvPtRms;
  double a0Rms;
  double a1PtRms;
  double a2PtRms;
  double a1EtaRms;
  double a2EtaRms;
};

} // namespace CAP

#endif /* CAP__ResolutionFunction */
