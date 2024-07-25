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
#ifndef CAP__Plotter
#define CAP__Plotter
#include "TSystem.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TLine.h"
#include "TArrow.h"

#include "CanvasGroup.hpp"
#include "GraphConfiguration.hpp"
#include "LegendConfiguration.hpp"
#include "DataGraph.hpp"
#include "HistogramTask.hpp"
#include "HistogramGroup.hpp"

namespace CAP
{


class Plotter 
:
public HistogramTask,
public CanvasGroup
{
public:

  Plotter();
  Plotter(const Plotter & task);
  Plotter operator=(const Plotter & task);
  virtual ~Plotter() {}

  //!
  //! Initialize the configuration parameter of the task to their default value;
  //!
  virtual void setDefaultConfiguration();

  //!
  //! Configure  this analysis task
  //!
  virtual void configure();

  TCanvas *  plot(const String & canvasName,
                  const CanvasConfiguration  & cc,
                  const GraphConfiguration   & gc,
                  LegendConfiguration  & lc,
                  TH1 * h,
                  const String & xTitle,  double xMin, double xMax,
                  const String & yTitle,  double yMin, double yMax);

  TCanvas *  plot(const String & canvasName,
                  const CanvasConfiguration  & cc,
                  const GraphConfiguration   & gc,
                  LegendConfiguration  & lc,
                  TH2 * h,
                  const String & xTitle,  double xMin, double xMax,
                  const String & yTitle,  double yMin, double yMax,
                  const String & zTitle,  double zMin, double zMax);

  TCanvas *  plot(const String & canvasName,
                  const CanvasConfiguration  & cc,
                  const GraphConfiguration   & gc,
                  LegendConfiguration  & lc,
                  TGraph * h,
                  const String & xTitle,  double xMin, double xMax,
                  const String & yTitle,  double yMin, double yMax);

  TCanvas *  plot(const String & canvasName,
                  const CanvasConfiguration  & cc,
                  const vector<GraphConfiguration*> & gc,
                  LegendConfiguration  & lc,
                  vector<TH1*> histograms,
                  const String & xTitle,  double xMin, double xMax,
                  const String & yTitle,  double yMin, double yMax);

  TCanvas *  plot(const String & canvasName,
                  const CanvasConfiguration  & cc,
                  const vector<GraphConfiguration*> & gc,
                  LegendConfiguration  & lc,
                  vector<TGraph*> graphs,
                  const String & xTitle,  double xMin, double xMax,
                  const String & yTitle,  double yMin, double yMax);

  //  // ================================================================================================
  //  // Function to plot nHists 1D histogram
  //  // h       : vector of nHists pointers to histograms
  //  // legends : vector of nHists pointers to labels used as legends in the body of the plot
  //  // ================================================================================================
  //  TCanvas *  plot(String  canvasName, Configuration & cc, vector<GraphConfiguration*> gc,
  //                  String  xTitle,  double xMin, double xMax,
  //                  String  yTitle,  double yMin, double yMax,
  //                  vector<TH1*> histograms,
  //                  VectorString  legends,
  //                  double xMinLeg, double yMinLeg, double xMaxLeg, double yMaxLeg,double legendSize,
  //                  bool label1=0, String text1="", double x1=0.0, double y1=0.0, int color1=1,  double fontSize1=0.05,
  //                  bool label2=0, String text2="", double x2=0.0, double y2=0.0, int color2=1,  double fontSize2=0.05);
  //
  //  TCanvas * plot(String  canvasName, Configuration & cc,
  //                 String  xTitle,  double xMin, double xMax,
  //                 String  yTitle,  double yMin, double yMax,
  //                 vector<DataGraph*> graphs,
  //                 double xMinLeg, double yMinLeg, double xMaxLeg, double yMaxLeg,double legendSize);

  ////////////////////////////////////////////////////////////////////////
  // Setting Histogram Properties
  ////////////////////////////////////////////////////////////////////////

  void findMinMax(TH1* histogram, double & minimum, double & maximum);

  void setProperties(TH1 * h, 
                     const GraphConfiguration & graphConfiguration,
                     const String & xTitle="none",
                     const String & yTitle="none",
                     const String & zTitle="none");
  
  void setProperties(vector<TH1*> histograms,
                     const vector<GraphConfiguration*> & graphConfigurations,
                     const String & xTitle="none",
                     const String & yTitle="none",
                     const String & zTitle="none");


  void setProperties(TGraph * g,
                     const GraphConfiguration & graphConfiguration,
                     const String & xTitle="none",
                     const String & yTitle="none");

  void setProperties(vector<TGraph*> & graphs,
                     const vector<GraphConfiguration*> & graphConfigurations,
                     const String & xTitle="none",
                     const String & yTitle="none");


  TLatex  * createLabel(const String & text, double x, double y, double angle, int color,  double fontSize, bool doDraw=true);
  TLegend * createLegend(double x1, double y1, double x2, double y2, double fontSize);
  TLegend * createLegend(TH1*histogram, const String & legendText, double x1, double y1, double x2, double y2, double fontSize, bool doDraw=true);
  TLegend * createLegend(vector<TH1*> h,VectorString  legendTexts,double x1, double y1, double x2, double y2, double fontSize, bool doDraw=true);
  TLegend * createLegend(vector<TGraph*> h,VectorString  legendTexts,double x1, double y1, double x2, double y2, double fontSize, bool doDraw=true);
  TLegend * createLegend(vector<DataGraph*> graphs,double x1, double y1, double x2, double y2, double fontSize, bool doDraw=true);

  TLegend * createLegend(const LegendConfiguration & legendConfig);
  TLegend * createLegend(TH1*histogram, const LegendConfiguration & legendConfig);
  TLegend * createLegend(vector<TH1*> h,const LegendConfiguration & legendConfig);
  TLegend * createLegend(TGraph*graph, const LegendConfiguration & legendConfig);
  TLegend * createLegend(vector<TGraph*> h,const LegendConfiguration & legendConfig);
  TLegend * createLegend(vector<DataGraph*> graphs,const LegendConfiguration & legendConfig);

  TLine   * createLine(float x1, float y1, float x2, float y2, int style, int color, int width, bool doDraw=true);
  TArrow  * createArrow(float x1, float y1, float x2, float y2, float arrowSize, Option_t* option, int style, int color, int width, bool doDraw=true);
  void setDefaultOptions(bool color);

  double findHistoMinimum(TH1 * h);
  double findHistoMaximum(TH1 * h);
  double findHistoMinimum2D(TH2 * h);
  double findHistoMaximum2D(TH2 * h);
  double findGraphMinimum(TGraph * h);
  double findGraphMaximum(TGraph * h);
  double findMinimum(vector<double> & values);
  double findMaximum(vector<double> & values);


  TGraph * makeGraph(vector<double> vx,
                     vector<double> vex,
                     vector<double> vy,
                     vector<double> vey);

  vector<CAP::GraphConfiguration*> createGraphConfigurationPalette(int n, int dim);

  TGraph * sumGraphs(TGraph * g1, TGraph * g2);


  TGraph* calculateIntegral1D(TH1* h,
                            double etaLow,
                            double etaHigh,
                            double etaStep,
                            int size=500);

  TGraph* calculateIntegral(TH2* h2,
                            double etaLow,
                            double etaHigh,
                            double etaStep,
                            int size=500);

  void calculateRmsWidth(TH2 * h,
                         double xLowEdge, double xHighEdge,
                         double yLowEdge, double yHighEdge,
                         double & mean, double & meanError,
                         double & rmsWidth, double & rmsWidthError,
                         int direction=1);

  double GeneralizedGaussian(double *x, double *par);


protected:

  String canvasBaseName;
  String canvasName;
  String outputPathNameBase;
  String outputFileNameBase;
  String outputPathName;
  String outputFileName;
  String plotOption;
  bool doPrint;
  bool doPrintGif;
  bool doPrintPdf;
  bool doPrintSvg;
  bool doPrintPng;
  bool doPrintC;
  bool useColor;
  int  usePalette;

  ClassDef(Plotter,0)
};

} // namespace CAP

#endif /* CAP__Plotter */
