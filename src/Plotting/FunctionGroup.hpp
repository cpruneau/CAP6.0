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

#ifndef CAP__FunctionGroup
#define CAP__FunctionGroup
#include <stdio.h>
#include "TClass.h"
#include "TFile.h"
#include "TAxis.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TMath.h"
#include "TPad.h"
#include "TF1.h"
#include "TF2.h"
#include "TRandom.h"
#include "Aliases.hpp"
#include "TLatex.h"
#include "TLine.h"
#include "TArrow.h"
#include "TLegend.h"
#include "GraphConfiguration.hpp"
#include "CanvasConfiguration.hpp"
#include "CanvasGroup.hpp"
#include "Collection.hpp"
using namespace std;

namespace CAP
{


class FunctionGroup  // : public Collection<TF1>
{

protected:

  std::vector<TF1*> functions;

public:
  
  /////////////////////////////////////////////////////////////
  // Member functions
  /////////////////////////////////////////////////////////////
  FunctionGroup();
  FunctionGroup(const FunctionGroup & source);
  virtual ~FunctionGroup();
  FunctionGroup & operator=(const FunctionGroup & source);

  void setDefaultOptions(bool color=0);
  void setFunctionProperties(TF1 * f, GraphConfiguration & graphConfiguration);
  void plotAllFunctions(const String & outputPath, bool doPrint=false);

  void push_back(TF1* function);
  TF1* getFunctionAt(unsigned int index);
  const std::vector<TF1*> & getFunctions() const;
  std::vector<TF1*> & getFunctions();
  int size();
  
  ClassDef(FunctionGroup,0)
}; // FunctionGroup


} // namespace CAP

#endif /* FunctionGroup_hpp */
