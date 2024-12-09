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
#ifndef CAP__Plotter
#define CAP__Plotter
#include "TSystem.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TLine.h"
#include "TArrow.h"

#include "CanvasGroup.hpp"
#include "CanvasConfiguration.hpp"
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

  TCanvas *  plot(const String & _canvasName,
                  vector<TH1*> _histograms,
                  const String & _xTitle="",  double _xMin=1.0, double _xMax=0.0,
                  const String & _yTitle="",  double _yMin=1.0, double _yMax=0.0,
                  bool   _createLegend=false,
                  double _xLegendLeft=0.1,
                  double _xLegendRight=0.2,
                  double _yLegendLow=0.4,
                  double _yLegendHigh=0.5,
                  double _legendTextSize=0.05,
                  int    canvasIndex=0);

  TCanvas *  plot(const String & _canvasName,
                  vector<TH2*> _histograms,
                  const String & _xTitle="",  double _xMin=1.0, double _xMax=0.0,
                  const String & _yTitle="",  double _yMin=1.0, double _yMax=0.0,
                  const String & _zTitle="",  double _zMin=1.0, double _zMax=0.0,
                  bool   _createLegend=false,
                  double _xLegendLeft=0.1,
                  double _xLegendRight=0.2,
                  double _yLegendLow=0.4,
                  double _yLegendHigh=0.5,
                  double _legendTextSize=0.05,
                  int    canvasIndex=0);


  void setProperties(TH1 * h,
                     const GraphConfiguration & graphConfiguration,
                     const String & xTitle="none",
                     const String & yTitle="none",
                     const String & zTitle="none");

  void setProperties(const vector<TH1*> & histograms,
                     const vector<GraphConfiguration> & graphConfigurations,
                     const String & xTitle="none",
                     const String & yTitle="none");

  void setProperties(const vector<TH2*> & histograms,
                     const vector<GraphConfiguration> & graphConfigurations,
                     const String & xTitle="none",
                     const String & yTitle="none",
                     const String & zTitle="none");

  void setProperties(TGraph * g,
                     const GraphConfiguration & graphConfiguration,
                     const String & xTitle="none",
                     const String & yTitle="none");

  void setProperties(const vector<TGraph*> & graphs,
                     const vector<GraphConfiguration> & graphConfigurations,
                     const String & xTitle="none",
                     const String & yTitle="none");


  TLatex  * createLabel(const String & text, double x, double y, double angle, int color,  double fontSize, bool doDraw=true);
  TLegend * createLegend(double x1, double y1, double x2, double y2, double fontSize);
  TLegend * createLegend(TH1*histogram, const String & legendText, double x1, double y1, double x2, double y2, double fontSize, bool doDraw=true);
  TLegend * createLegend(vector<TH1*> & histograms,double x1, double x2, double y1, double y2, double fontSize, bool doDraw=true);
  TLegend * createLegend(vector<TH1*> & histograms, vector<TString> &legendTexts,double x1, double x2, double y1, double y2, double fontSize, bool doDraw=true);
  TLegend * createLegend(vector<TGraph*> graphs, vector<TString> & legendTexts,double x1, double x2, double y1, double y2, double fontSize, bool doDraw=true);
  TLegend * createLegend(vector<DataGraph*> graphs,double x1, double x2, double y1, double y2, double fontSize, bool doDraw=true);

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

  vector<GraphConfiguration> createGraphConfigurationPalette(int n, int dim);

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

  void addCanvasConfiguartion(CanvasConfiguration::CanvasFormat format,
                              CanvasConfiguration::CanvasAxes axes);
  void addGraphConfiguration(unsigned int n, unsigned int nDimensions);



protected:

  vector<CanvasConfiguration> canvasPalette;
  vector<GraphConfiguration> graphPalette;

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
