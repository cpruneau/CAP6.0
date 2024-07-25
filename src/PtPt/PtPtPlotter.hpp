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
#ifndef CAP__PtPtPlotter
#define CAP__PtPtPlotter
#include "Plotter.hpp"
#include "PtPtHistos.hpp"
#include "PtPtDerivedHistos.hpp"

namespace CAP
{


class PtPtPlotter : public Plotter
{
public:
  
  PtPtPlotter();
  virtual ~PtPtPlotter();
  void makePlots(const String & canvasNameBase,
                 PtPtHistos * PtPtHistosUsed,
                 PtPtDerivedHistos * PtPtDerivedHistosUsed,
                 CanvasConfiguration & canvasConfigurationUsed,
                 GraphConfiguration  ** graphConfigurationsUsed);

  void makeComparisonPlots(const String & canvasNameBase,
                           Configuration & canvasConfiguration,
                           int nGraphs,
                           PtPtHistos ** PtPtHistos,
                           PtPtDerivedHistos ** PtPtDerivedHistos,
                           String ** histLabels,
                           GraphConfiguration  ** graphConfigurations);

  void makePtPtComparisonPlots(const String & canvasNameBase,
                                Configuration & canvasConfiguration,
                                int nGraphs,
                                PtPtHistos ** PtPtHistos,
                                PtPtDerivedHistos ** PtPtDerivedHistos,
                                String ** histLabels,
                                GraphConfiguration  ** graphConfigurations);

  ClassDef(PtPtPlotter,0)
};


} // namespace CAP

#endif /* CAP__PtPtPlotter */
