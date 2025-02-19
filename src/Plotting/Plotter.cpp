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
#include "Plotter.hpp"
#include "PrintHelpers.hpp"
#include "NameHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::Plotter);

namespace CAP
{

Plotter::Plotter()
:
HistogramTask(),
CanvasGroup()
{
  appendClassName("Plotter");
}

Plotter::Plotter(const Plotter & task)
:
HistogramTask(task),
CanvasGroup(task)
{  /* no ops */  }

Plotter Plotter::operator=(const Plotter & task)
{
  if (this!=&task)
    {
    HistogramTask::operator=(task);
    CanvasGroup::operator=(task);
    }
  return *this;
}


void Plotter::setDefaultConfiguration()
{
  HistogramTask::setDefaultConfiguration();
}

//!
//! Configure  this analysis task
//!
void Plotter::configure()
{
  HistogramTask::configure();
}


TCanvas *  Plotter::plot(const String & _canvasName,
                         vector<TH1*> _histograms,
                         const String & _xTitle,  double _xMin, double _xMax,
                         const String & _yTitle,  double _yMin, double _yMax,
                         bool   _createLegend,
                         double _xLegendLeft,
                         double _xLegendRight,
                         double _yLegendLow,
                         double _yLegendHigh,
                         double _legendTextSize,
                         int    _canvasIndex,
                         bool   _overlay)
{
  TCanvas * canvas = nullptr;
  setProperties(_histograms,graphPalette,_xTitle,_yTitle);
  if (_yMax > _yMin)
    setLimits(_histograms,_xMin,_xMax,_yMin,_yMax);
  else
    {
    int ixMin, ixMax;
    double yMin, yMax;
    findMinMax(_histograms,ixMin,yMin,ixMax,yMax);
    setLimits(_histograms,_xMin,_xMax,yMin,yMax);
    }
  int k = 0;
  for (auto & histogram : _histograms)
    {
    if (_overlay)
      {
      canvas = createCanvas(_canvasName,canvasPalette[_canvasIndex]);
      if (k==0)
        histogram->Draw();
      else
        histogram->Draw("SAME");
      }
    else
      {
      String name = _canvasName;
      name += "_";
      name += histogram->GetName();
      canvas = createCanvas(name,canvasPalette[_canvasIndex]);
      histogram->Draw();
      if (_createLegend)
        createLegend(histogram,histogram->GetTitle(),
                     _xLegendLeft,_xLegendRight,_yLegendLow,_yLegendHigh,
                     _legendTextSize);
      }
    k++;
    }
  if (_overlay && _createLegend)
    createLegend(_histograms,_xLegendLeft,_xLegendRight,_yLegendLow,_yLegendHigh,_legendTextSize);
  return canvas;
}


TCanvas *  Plotter::plot(const String & _canvasName,
                         vector<TH2*> _histograms,
                         const String & _xTitle,  double _xMin, double _xMax,
                         const String & _yTitle,  double _yMin, double _yMax,
                         const String & _zTitle,  double _zMin, double _zMax,
                         bool   _createLegend,
                         double _xLegendLeft,
                         double _xLegendRight,
                         double _yLegendLow,
                         double _yLegendHigh,
                         double _legendTextSize,
                         int    _canvasIndex)
{
  TCanvas * canvas = nullptr;
  setProperties(_histograms,graphPalette,_xTitle,_yTitle,_zTitle);
  if (_zMax > _zMin)
    setLimits(_histograms,_xMin,_xMax,_yMin,_yMax,_zMin,_zMax);
  else
    {
    int ixMin, ixMax, iyMin, iyMax;
    double zMin, zMax;
    findMinMax(_histograms,ixMin,iyMin,zMin,ixMax,iyMax,zMax);
    setLimits(_histograms,_xMin,_xMax,_yMin,_yMax,zMin,zMax);
    }
  for (auto & histogram : _histograms)
    {
    String name = _canvasName;
    name += "_";
    name += histogram->GetName();
    canvas = createCanvas(name,canvasPalette[_canvasIndex]);
    histogram->Draw();
    if (_createLegend)
      createLegend(histogram,histogram->GetTitle(),_xLegendLeft,_xLegendRight,_yLegendLow,_yLegendHigh,_legendTextSize);
    }
  return canvas;
}



//enum CanvasFormat   { PortraitTight, Portrait, PortraitWide, SquareTight, Square, SquareWide, LandscapeTight, Landscape, LandscapeWide, LandscapeXtop };
//enum CanvasAxes     { Linear, LogX, LogY, LogZ, LogXY, LogXZ, LogYZ, LogXYZ  };
void  Plotter::addCanvasConfiguartion(CanvasConfiguration::CanvasFormat format,
                                      CanvasConfiguration::CanvasAxes axes)
{
  CanvasConfiguration canvas(format,axes);
  canvasPalette.push_back(canvas);
}

void  Plotter::addGraphConfiguration(unsigned int n, unsigned int nDimensions)
{
  for (unsigned int k=0; k<n; k++)
    {
    GraphConfiguration config;
    config.setPropertiesFor(nDimensions,k);
    graphPalette.push_back( config );
    }
}


//!
//! Setting Histogram Properties
//!
void Plotter::setProperties(TH1 * h,
                            const GraphConfiguration & graphConfiguration,
                            const String & xTitle,
                            const String & yTitle,
                            const String & zTitle)
{
  printCR();
  printValue("Setting properties of histo",h->GetName());
  h->SetLineColor(graphConfiguration.getValueInt("lineColor"));
  h->SetLineStyle(graphConfiguration.getValueInt("lineStyle"));
  h->SetLineWidth(graphConfiguration.getValueInt("lineWidth"));
  h->SetMarkerColor(graphConfiguration.getValueInt("markerColor"));
  h->SetMarkerStyle(graphConfiguration.getValueInt("markerStyle"));
  h->SetMarkerSize (graphConfiguration.getValueDouble("markerSize"));
  TAxis * xAxis = (TAxis *) h->GetXaxis();
  xAxis->SetNdivisions(graphConfiguration.getValueInt("nXDivisions"));
  xAxis->SetTitleSize(graphConfiguration.getValueDouble("xTitleSize"));
  xAxis->SetTitleOffset(graphConfiguration.getValueDouble("xTitleOffset"));
  xAxis->SetLabelSize(graphConfiguration.getValueDouble("xLabelSize"));
  xAxis->SetLabelOffset(graphConfiguration.getValueDouble("xLabelOffset"));
  if (!xTitle.EqualTo("none")) xAxis->SetTitle(xTitle);
  TAxis * yAxis = (TAxis *) h->GetYaxis();
  yAxis->SetNdivisions(graphConfiguration.getValueInt("nYDivisions"));
  yAxis->SetTitleSize(graphConfiguration.getValueDouble("yTitleSize"));
  yAxis->SetTitleOffset(graphConfiguration.getValueDouble("yTitleOffset"));
  yAxis->SetLabelSize(graphConfiguration.getValueDouble("yLabelSize"));
  yAxis->SetLabelOffset(graphConfiguration.getValueDouble("yLabelOffset"));
  if (yTitle.EqualTo("none"))   yAxis->SetTitle(yTitle);

  if (h->IsA() == TH2::Class()  || h->IsA() == TH2F::Class() || h->IsA() == TH2F::Class() )
    {
    if (reportDebug(__FUNCTION__)) cout << "Setting properties as 2D histo: " << h->GetTitle() << endl;
    TAxis * zAxis = (TAxis *) h->GetZaxis();
    zAxis->SetNdivisions(graphConfiguration.getValueInt("nZDivisions"));
    zAxis->SetTitleSize(graphConfiguration.getValueDouble("zTitleSize"));
    zAxis->SetTitleOffset(graphConfiguration.getValueDouble("zTitleOffset"));
    zAxis->SetLabelSize(graphConfiguration.getValueDouble("zLabelSize"));
    zAxis->SetLabelOffset(graphConfiguration.getValueDouble("zLabelOffset"));
    if (zTitle.EqualTo("none"))  zAxis->SetTitle(zTitle);
    }
}

void Plotter::setProperties(const vector<TH1*> & histograms,
                            const vector<GraphConfiguration> & graphConfigurations,
                            const String & xTitle,
                            const String & yTitle)
{
  int k = 0;
  for (auto & histogram : histograms)
    setProperties(histogram,graphConfigurations[k++],xTitle,yTitle);
}

void Plotter::setProperties(const vector<TH2*> & histograms,
                            const vector<GraphConfiguration> & graphConfigurations,
                            const String & xTitle,
                            const String & yTitle,
                            const String & zTitle)
{
  int k = 0;
  for (auto & histogram : histograms)
    setProperties(histogram,graphConfigurations[k],xTitle,yTitle,zTitle);
}


void Plotter::setProperties(TGraph * g,
                            const GraphConfiguration & graphConfiguration,
                            const String & xTitle,
                            const String & yTitle)
{
  if (reportDebug(__FUNCTION__))
    {
    cout << endl;
    printValue("Setting properties of graph",g->GetTitle());
    }
  g->SetLineColor(graphConfiguration.getValueInt("lineColor"));
  g->SetLineStyle(graphConfiguration.getValueInt("lineStyle"));
  g->SetLineWidth(graphConfiguration.getValueInt("lineWidth"));
  g->SetMarkerColor(graphConfiguration.getValueInt("markerColor"));
  g->SetMarkerStyle(graphConfiguration.getValueInt("markerStyle"));
  g->SetMarkerSize (graphConfiguration.getValueDouble("markerSize"));
  TAxis * xAxis = (TAxis *) g->GetXaxis();
  xAxis->SetNdivisions(graphConfiguration.getValueInt("nXDivisions"));
  xAxis->SetTitleSize(graphConfiguration.getValueDouble("xTitleSize"));
  xAxis->SetTitleOffset(graphConfiguration.getValueDouble("xTitleOffset"));
  xAxis->SetLabelSize(graphConfiguration.getValueDouble("xLabelSize"));
  xAxis->SetLabelOffset(graphConfiguration.getValueDouble("xLabelOffset"));
  if (!xTitle.EqualTo("none")) xAxis->SetTitle(xTitle);
  TAxis * yAxis = (TAxis *) g->GetYaxis();
  yAxis->SetNdivisions(graphConfiguration.getValueInt("nYDivisions"));
  yAxis->SetTitleSize(graphConfiguration.getValueDouble("yTitleSize"));
  yAxis->SetTitleOffset(graphConfiguration.getValueDouble("yTitleOffset"));
  yAxis->SetLabelSize(graphConfiguration.getValueDouble("yLabelSize"));
  yAxis->SetLabelOffset(graphConfiguration.getValueDouble("yLabelOffset"));
  if (yTitle.EqualTo("none"))   yAxis->SetTitle(yTitle);
}

void Plotter::setProperties(const vector<TGraph*> & graphs,
                            const vector<GraphConfiguration> & graphConfigurations,
                            const String & xTitle,
                            const String & yTitle)
{
  int k = 0;
  for (auto & graph : graphs)
    setProperties(graph,graphConfigurations[k++],xTitle,yTitle);
}


//!
//! Set Default Style for Plots
//!
void Plotter::setDefaultOptions(bool color)
{
  if (color)
    gStyle->SetPalette(1,0);
  else
    gStyle->SetPalette(7,0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetOptDate(0);
  gStyle->SetOptTitle(0);
  gStyle->SetPadBorderMode(0);

}






vector<GraphConfiguration> Plotter::createGraphConfigurationPalette(int n, int dim)
{
  vector<GraphConfiguration> gc = CAP::GraphConfiguration::createConfigurationPalette(n,dim);
  for (int k=0;k<n;k++)
    {

    //gc[k]->addPropertiesWith(1, k);

    //    gc[k]->addProperty("xTitleSize",   double(0.08));
    //    gc[k]->addProperty("xTitleOffset", double(0.8));
    //    gc[k]->addProperty("yTitleSize",   double(0.08));
    //    gc[k]->addProperty("yTitleOffset", double(0.8));
    //    gc[k]->addProperty("xLabelSize",   double(0.07));
    //    gc[k]->addProperty("yLabelSize",   double(0.07));
    //    gc[k]->addProperty("lineColor",    int(21+2*k));
    //    gc[k]->addProperty("markerColor",  int(21+2*k));
    if (k==1)
      {
      gc[k].addProperty("markerStyle",  int(kFullCircle));
      gc[k].addProperty("markerSize",   double(1.9));
      }
    }
  return gc;
}






} // namespace CAP
