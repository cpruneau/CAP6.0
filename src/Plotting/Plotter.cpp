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
CanvasGroup(),
canvasBaseName("CanvasBaseName"),
canvasName("CanvasName"),
outputPathNameBase("outputPathNameBase"),
outputFileNameBase("outputFileNameBase"),
outputPathName("outputPathName"),
outputFileName("outputFileName"),
plotOption(),
doPrint(false),
doPrintGif(false),
doPrintPdf(false),
doPrintSvg(false),
doPrintPng(false),
doPrintC(false),
useColor(true),
usePalette(1)
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
  addProperty("canvasBaseName",       canvasBaseName);
  addProperty("canvasName",           canvasName);
  addProperty("OutputPathNameBase",   outputPathNameBase);
  addProperty("OutputFileNameBase",   outputFileNameBase);
  addProperty("OutputPathName",       outputPathName);
  addProperty("OutputFileName",       outputFileName);
  addProperty("PlotOption",           plotOption);
  addProperty("DoPrint",      doPrint);
  addProperty("DoPrintGif",   doPrintGif);
  addProperty("DoPrintPdf",   doPrintPdf);
  addProperty("DoPrintSvg",   doPrintSvg);
  addProperty("DoPrintPng",   doPrintPng);
  addProperty("DoPrintC",     doPrintC);
  addProperty("UseColor",     useColor);
  addProperty("UsePalette",   usePalette);
}

//!
//! Configure  this analysis task
//!
void Plotter::configure()
{
  HistogramTask::configure();
  doPrint     = getValueBool("DoPrint");
  doPrintGif  = getValueBool("DoPrintGif");
  doPrintPdf  = getValueBool("DoPrintPdf");
  doPrintSvg  = getValueBool("DoPrintSvg");
  doPrintPng  = getValueBool("DoPrintPng");
  doPrintC    = getValueBool("DoPrintC");
  useColor    = getValueBool("UseColor");
  usePalette  = getValueInt("UsePalette");
  canvasBaseName     = getValueString("CanvasBaseName");
  canvasName         = getValueString("CanvasName");
  outputPathNameBase = getValueString("OutputPathNameBase");
  outputFileNameBase = getValueString("OutputFileNameBase");
  outputPathName     = getValueString("OutputPathName");
  outputFileName     = getValueString("OutputFileName");
}

///
//TCanvas *  Plotter::plot(const String & canvasName,
//                         const CanvasConfiguration  & cc,
//                         const GraphConfiguration   & gc,
//                         LegendConfiguration  & lc,
//                         TH1 * h,
//                         const String & xTitle,  double xMin, double xMax,
//                         const String & yTitle,  double yMin, double yMax)
//{
//  if (reportDebug(__FUNCTION__)) cout << "Creating canvas named:" << canvasName << endl;
//  TCanvas * canvas  = createCanvas(canvasName,cc);
//  canvas->SetTicky(1);
//  canvas->SetTickx(1);
//  setProperties(h,gc,xTitle,yTitle);
//  h->SetMinimum(yMin);
//  h->SetMaximum(yMax);
//  if (xMin<xMax) h->GetXaxis()->SetRangeUser(xMin,xMax);
//  h->DrawCopy(plotOption);
//  if (lc.useLegend()) createLegend(h,lc);
//  if (lc.useLabels()) lc.drawLabels();
//  return canvas;
//}
//
//TCanvas *  Plotter::plot(const String & canvasName,
//                         const CanvasConfiguration  & cc,
//                         const GraphConfiguration   & gc,
//                         LegendConfiguration  & lc,
//                         TH2 * h,
//                         const String & xTitle,  double xMin, double xMax,
//                         const String & yTitle,  double yMin, double yMax,
//                         const String & zTitle,  double zMin, double zMax)
//{
//  if (reportDebug(__FUNCTION__)) cout << "Creating canvas named:" << canvasName << endl;
//  TCanvas * canvas  = createCanvas(canvasName,cc);
//  setProperties(h,gc,xTitle,yTitle,zTitle);
//  if (xMin < xMax) h->GetXaxis()->SetRangeUser(xMin,xMax);
//  if (yMin < yMax) h->GetYaxis()->SetRangeUser(yMin,yMax);
//  if (zMin < zMax)
//    {
//    h->SetMinimum(zMin);
//    h->SetMaximum(zMax);
//    }
//  h->DrawCopy(plotOption);
//  if (lc.useLegend()) createLegend(h,lc);
//  if (lc.useLabels()) lc.drawLabels();
//  return canvas;
//}
//
//TCanvas *  Plotter::plot(const String & canvasName,
//                         const CanvasConfiguration  & cc,
//                         const GraphConfiguration   & gc,
//                         LegendConfiguration  & lc,
//                         TGraph * graph,
//                         const String & xTitle,  double xMin, double xMax,
//                         const String & yTitle,  double yMin, double yMax)
//{
//  if (reportDebug(__FUNCTION__)) cout << "Creating canvas named:" << canvasName << endl;
//  TCanvas * canvas  = createCanvas(canvasName,cc);
//  canvas->SetTicky(1);
//  canvas->SetTickx(1);
//  setProperties(graph,gc,xTitle,yTitle);
//  graph->SetMinimum(yMin);
//  graph->SetMaximum(yMax);
//  if (xMin<xMax) graph->GetXaxis()->SetRangeUser(xMin,xMax);
//  graph->Draw(plotOption);
//
//  if (lc.useLegend()) createLegend(graph,lc);
//  if (lc.useLabels()) lc.drawLabels();
//  return canvas;
//}


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
                         int    canvasIndex)
{
  TCanvas * canvas = createCanvas(_canvasName,canvasPalette[canvasIndex]);
  String plotOption;
  int ixMin, ixMax;
  double yMin, yMax;
  setProperties(_histograms,graphPalette,_xTitle,_yTitle);
  yMin = _yMin;
  yMax = _yMax;
  if (yMax < yMin) findMinMax(_histograms,ixMin,yMin,ixMax,yMax);
  int k = 0;
  for (auto & histogram : _histograms)
    {
    histogram->SetMinimum(yMin);
    histogram->SetMaximum(yMax);
    if (_xMin<_xMax) histogram->GetXaxis()->SetRangeUser(_xMin,_xMax);
    if (k==0)
      histogram->Draw();
    else
      histogram->Draw("SAME");
    k++;
    }
  if (_createLegend)
    {
    createLegend(_histograms,_xLegendLeft,_xLegendRight,_yLegendLow,_yLegendHigh,_legendTextSize);
    }
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
                         int    canvasIndex)
{
  TCanvas * canvas = createCanvas(_canvasName,canvasPalette[canvasIndex]);
  String plotOption;
  int ixMin, ixMax;
  int iyMin, iyMax;
  double zMin, zMax;
  setProperties(_histograms,graphPalette,_xTitle,_yTitle,_zTitle);
  zMin = _zMin;
  zMax = _zMax;
  if (zMax < zMin) findMinMax(_histograms,ixMin,iyMin,zMin,ixMax,iyMax,zMax);
  int k = 0;
  for (auto & histogram : _histograms)
    {
    histogram->SetMinimum(zMin);
    histogram->SetMaximum(zMax);
    if (_xMin<_xMax) histogram->GetXaxis()->SetRangeUser(_xMin,_xMax);
    if (_yMin<_yMax) histogram->GetYaxis()->SetRangeUser(_yMin,_yMax);
    if (k==0)
      histogram->Draw("COLZ");
    else
      histogram->Draw("SAME");
    k++;
    }
//  if (_createLegend)
//    {
//    createLegend(_histograms,_xLegendLeft,_xLegendRight,_yLegendLow,_yLegendHigh,_legendTextSize);
//    }
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
    //GraphConfiguration * c = new GraphConfiguration(dimension, k);
    GraphConfiguration config;
    config.setPropertiesFor(nDimensions,k);
    graphPalette.push_back( config );
    }
}


TLatex * Plotter::createLabel(const String & text, double x, double y, double angle, int color,  double fontSize, bool doDraw)
{
  TLatex * label = new TLatex(x,y,text);
  label->SetTextColor(color);
  label->SetTextAngle(angle);
  label->SetTextSize(fontSize);
  if (doDraw) label->Draw();
  return label;
}

TLegend * Plotter::createLegend(double x1, double y1, double x2, double y2, double fontSize)
{
  TLegend *legend = new TLegend(x1,y1,x2,y2);
  legend->SetTextSize(fontSize);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  return legend;
}

TLegend * Plotter::createLegend(TH1*histogram, const String & legendText, double x1, double y1, double x2, double y2, double fontSize, bool doDraw)
{
  TLegend *legend = new TLegend(x1,y1,x2,y2);
  legend->SetTextSize(fontSize);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->AddEntry(histogram,legendText);
  if (doDraw) legend->Draw();
  return legend;
}

TLegend * Plotter::createLegend(vector<TH1*> & histograms, double x1, double x2, double y1, double y2, double fontSize, bool doDraw)
{
  TLegend *legend = new TLegend(x1,y1,x2,y2);
  legend->SetTextSize(0.5);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  for (auto & histogram : histograms)
    {
//    printValue("histo name",histogram->GetName());
//    printValue("histo title",histogram->GetTitle());
    legend->AddEntry(histogram,histogram->GetTitle());
    }
  legend->Draw();
  return legend;
}


TLegend * Plotter::createLegend(vector<TH1*> & histograms, vector<TString> & legendTexts, double x1, double y1, double x2, double y2, double fontSize, bool doDraw)
{
  TLegend *legend = new TLegend(x1,y1,x2,y2);
  legend->SetTextSize(fontSize);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  int k=0;
  for (auto & histogram : histograms)
    {
    printValue("histo name",histogram->GetName());
    printValue("histo legend",legendTexts[k]);
    legend->AddEntry(histogram,legendTexts[k]);
    legend->Draw();
    k++;
    }
  return legend;
}

TLegend * Plotter::createLegend(vector<TGraph*> graphs, vector<TString> & legendTexts,double x1, double y1, double x2, double y2, double fontSize, bool doDraw)
{
  TLegend *legend = new TLegend(x1,y1,x2,y2);
  legend->SetTextSize(fontSize);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  int k=0;
  for (auto & graph : graphs)
    legend->AddEntry(graph,legendTexts[k++]);
  if (doDraw) legend->Draw();
  return legend;
}

TLegend * Plotter::createLegend(vector<DataGraph*> graphs,double x1, double y1, double x2, double y2, double fontSize, bool doDraw)
{
  TLegend *legend = new TLegend(x1,y1,x2,y2);
  legend->SetTextSize(fontSize);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  for (auto & graph : graphs) legend->AddEntry(graph,graph->getLegendText());
  if (doDraw) legend->Draw();
  return legend;
}

TLegend * Plotter::createLegend(const LegendConfiguration & legendConfig)
{
  int    nColumns    = legendConfig.getValueInt("nColumns");
  int    borderColor = legendConfig.getValueInt("borderColor");
  int    borderSize  = legendConfig.getValueInt("borderSize");
  int    fillColor   = legendConfig.getValueInt("fillColor");
  int    fillStyle   = legendConfig.getValueInt("fillStyle");
  int    fontIndex   = legendConfig.getValueInt("textIndex");
  int    textColor   = legendConfig.getValueInt("textColor");
  double textSize    = legendConfig.getValueDouble("textSize");
  int    textAlign   = legendConfig.getValueInt("textAlign");
  double xLeft       = legendConfig.getValueDouble("xLeft");
  double xRight      = legendConfig.getValueDouble("xRight");
  double yLow        = legendConfig.getValueDouble("yLow");
  double yHigh       = legendConfig.getValueDouble("yHigh");
  String header      = legendConfig.getValueString("header");
  bool   useNDC      = legendConfig.getValueBool("useNDC");

  TLegend *legend;
  if (useNDC)
    {
    cout << " -- useNDC -- " << endl;
    legend = new TLegend(xLeft,yLow,xRight,yHigh,header,"NDC");
    }
  else
    {
    cout << " -- usePAD -- " << endl;
    legend = new TLegend(xLeft,yLow,xRight,yHigh,header,"PAD");
    }

  if (nColumns>1) legend->SetNColumns(nColumns);
  legend->SetLineColor(borderColor);
  legend->SetBorderSize(borderSize);
  legend->SetFillColor(fillColor);
  legend->SetFillStyle(fillStyle);
  legend->SetTextFont(fontIndex);
  legend->SetTextColor(textColor);
  legend->SetTextSize(textSize);
  legend->SetTextAlign(textAlign);
  if (header.Length()>0) legend->SetHeader(header);
  return legend;
}

TLegend * Plotter::createLegend(TH1*histogram, const LegendConfiguration & legendConfig)
{
  TLegend * legend = createLegend(legendConfig);
  if (legendConfig.getValueBool("useTitles"))
    legend->AddEntry(histogram,histogram->GetTitle());
  else
    legend->AddEntry(histogram,legendConfig.getLegendAt(0));
  if (legendConfig.getValueBool("drawLegend")) legend->Draw();
  return legend;
}


TLegend * Plotter::createLegend(vector<TH1*> histograms,const LegendConfiguration & legendConfig)
{
  TLegend * legend = createLegend(legendConfig);
  int k=0;
  for (auto & histogram : histograms)
    {
    if (legendConfig.getValueBool("UseTitles"))
      legend->AddEntry(histogram,histograms[k]->GetTitle());
    else
      legend->AddEntry(histogram,legendConfig.getLegendAt(k));
    }
  //if (legendConfig.getValueBool("DrawLegend"))
    legend->Draw();
  return legend;
}

TLegend * Plotter::createLegend(TGraph*graph, const LegendConfiguration & legendConfig)
{
  TLegend * legend = createLegend(legendConfig);
  if (legendConfig.getValueBool("useTitles"))
    legend->AddEntry(graph,graph->GetTitle());
  else
    legend->AddEntry(graph,legendConfig.getLegendAt(0));
  if (legendConfig.getValueBool("drawLegend")) legend->Draw();
  return legend;
}

TLegend * Plotter::createLegend(vector<TGraph*> graphs,const LegendConfiguration & legendConfig)
{
  TLegend * legend = createLegend(legendConfig);
  int k=0;
  for (auto & graph : graphs)
    {
    if (legendConfig.getValueBool("useTitles"))
      legend->AddEntry(graph,graph->GetTitle());
    else
      legend->AddEntry(graph,legendConfig.getLegendAt(k));
    }
  if (legendConfig.getValueBool("drawLegend")) legend->Draw();
  return legend;
}

TLegend * Plotter::createLegend(vector<DataGraph*> graphs,const LegendConfiguration & legendConfig)
{
  TLegend * legend = createLegend(legendConfig);
  int k=0;
  for (auto & graph : graphs)
    {
    if (legendConfig.getValueBool("useTitles"))
      legend->AddEntry(graph->getDataGraph(),graph->getLegendText());
    else
      legend->AddEntry(graph->getDataGraph(),legendConfig.getLegendAt(k));
    }
  if (legendConfig.getValueBool("drawLegend")) legend->Draw();
  return legend;
}


////////////////////////////////////////////////////
// Create simple line
////////////////////////////////////////////////////
TLine * Plotter::createLine(float x1, float y1, float x2, float y2, int style, int color, int width, bool doDraw)
{
  TLine *line = new TLine(x1,y1,x2,y2);
  line->SetLineStyle(style);
  line->SetLineColor(color);
  line->SetLineWidth(width);
  if (doDraw) line->Draw();
  return line;
}

////////////////////////////////////////////////////
// Create Arrow Line
////////////////////////////////////////////////////
TArrow * Plotter::createArrow(float x1, float y1, float x2, float y2, float arrowSize, Option_t* option, int style, int color, int width, bool doDraw)
{
  TArrow *line = new TArrow(x1,y1,x2,y2,arrowSize,option);
  line->SetLineStyle(style);
  line->SetLineColor(color);
  line->SetLineWidth(width);
  if (doDraw) line->Draw();
  return line;
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
  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printValue("Setting properties of histo",h->GetName());
    }
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

double Plotter::findHistoMinimum(TH1 * h)
{
  return h->GetBinContent(h->GetMinimumBin());
}

double Plotter::findHistoMaximum(TH1 * h)
{
  return h->GetBinContent(h->GetMaximumBin());
}

double Plotter::findHistoMinimum2D(TH2 * h)
{
  int x, y, z;
  h->GetMinimumBin(x,y,z);
  return h->GetBinContent(x,y);
}

double Plotter::findHistoMaximum2D(TH2 * h)
{
  int x, y, z;
  h->GetMaximumBin(x,y,z);
  return h->GetBinContent(x,y);
}

double Plotter::findGraphMinimum(TGraph * h)
{
  double min = 1.0E100;
  int n = h->GetN();
  for (int k=0; k<n; k++)
    {
    double x, y;
    h->GetPoint(k,x,y);
    if (y<min) min = y;
    }
  return min;
}

double Plotter::findGraphMaximum(TGraph * h)
{
  double max = -1.0E100;
  int n = h->GetN();
  for (int k=0; k<n; k++)
    {
    double x, y;
    h->GetPoint(k,x,y);
    if (y>max) max = y;
    }
  return max;
}

double Plotter::findMinimum(vector<double> & values)
{
  double min = 1.0E100;
  for (Size_t k=0; k<values.size(); k++)
    {
    if (values[k]<min) min = values[k];
    cout << "k   " << k << " v: " << values[k] << " min: " << min << endl;
    }
  return min;
}

double Plotter::findMaximum(vector<double> & values)
{
  double max = -1.0E100;
  for (Size_t k=0; k<values.size(); k++)
    {
    if (values[k]>max) max = values[k];
    cout << "k   " << k << " v: " << values[k] << " max: " << max << endl;
    }
  return max;
}

TGraph * Plotter::makeGraph(vector<double> vx,
                            vector<double> vex,
                            vector<double> vy,
                            vector<double> vey)
{
  auto n = vx.size();
  if ( vex.size()!=n || vy.size()!=n || vey.size()!=n )
    throw TaskException("Arguments provided have incompatible sizes","makeGraph(vx,vex,vy,vey)");
  double * x  = new double[n];
  double * ex = new double[n];
  double * y  = new double[n];
  double * ey = new double[n];
  for (unsigned long k=0;k<n;k++)
    {
    x[k]  = vx[k];
    ex[k] = vex[k];
    y[k]  = vy[k];
    ey[k] = vey[k];
    }
  return new TGraphErrors(n,x,y,ex,ey);
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


TGraph *  Plotter::sumGraphs(TGraph * g1, TGraph * g2)
{
  if (reportInfo(__FUNCTION__)) cout << "Summing two graphs" << endl;
  int  n1 = g1->GetN();
  int  n2 = g2->GetN();
  if (n1 != n2)
    throw TaskException("Args do not have same number of points","sumGraphs(TGraph * g1, TGraph * g2)");
  double * x  = new double[n1];
  double * ex = new double[n1];
  double * y  = new double[n1];
  double * ey = new double[n1];
  double x1, ex1, y1, ey1, x2, y2, ey2;

  for (int index=0; index<n1; index++)
    {
    g1->GetPoint(index,x1,y1);
    ex1 = g1->GetErrorX(index);
    ey1 = g1->GetErrorY(index);
    g2->GetPoint(index,x2,y2);
    ey2 = g2->GetErrorY(index);
    if (x1!=x2)
      {
      //cout << "sumGraphs(TGraph * g1, TGraph * g2, TGraph * gSum) x1 ne x2" << endl;
      delete[] x;
      delete[] ex;
      delete[] y;
      delete[] ey;
      return nullptr;
      }
    x[index]  = x1;
    ex[index] = ex1;
    y[index]  = y1 + y2;
    ey[index] = sqrt(ey1*ey1 + ey2*ey2);
    }
  TGraph * g = new TGraphErrors(n1, x,y,ex,ey);
  //cout << "sumGraphs(...) Ends" << endl;
  return g;
}

TGraph* Plotter::calculateIntegral1D(TH1* h,
                                     double etaLow,
                                     double etaHigh,
                                     double etaStep,
                                     int size)
{
  if (!h)
    throw TaskException("Given h is a null ptr","calculateIntegral1D(TH1* h,...)");
  if (reportInfo(__FUNCTION__))
    {
    cout << endl;
    printValue("Histo Name", h->GetName());
    printValue("etaLow", etaLow);
    printValue("etaHigh",etaHigh);
    printValue("etaStep",etaStep);
    printValue("size", size);
    }
  double * x  = new double[size];
  double * ex = new double[size];
  double * y  = new double[size];
  double * ey = new double[size];

  const TAxis * xAxis  = h->GetXaxis();
  int xLow;
  int xHigh;
  int nPoints = 0;
  double sum  = 0;
  double esum = 0;
  for (double eta=etaLow; eta<etaHigh; eta+=etaStep)
    {
    xLow  = xAxis->FindBin(-eta);
    xHigh = xAxis->FindBin( eta);
    sum = h->IntegralAndError(xLow,xHigh,esum,"WIDTH");
    x[nPoints]  = eta;
    ex[nPoints] = 0.001;
    y[nPoints]  = sum; ///TMath::TwoPi();
    ey[nPoints] = esum; ///TMath::TwoPi();
    nPoints++;
    }
  TGraph * g = new TGraphErrors(nPoints, x,y,ex,ey);
  return g;
}


TGraph* Plotter::calculateIntegral(TH2* h2,
                                   double etaLow,
                                   double etaHigh,
                                   double etaStep,
                                   int size)
{
  if (!h2)
    throw TaskException("Given h2 is a null ptr","calculateIntegral1D(TH2* h,...)");
  if (reportInfo(__FUNCTION__))
    {
    cout << endl;
    printValue("Histo Name", h2->GetName());
    printValue("etaLow", etaLow);
    printValue("etaHigh",etaHigh);
    printValue("etaStep",etaStep);
    printValue("size", size);
    }
  double * x  = new double[size];
  double * ex = new double[size];
  double * y  = new double[size];
  double * ey = new double[size];

  const TAxis * xAxis  = h2->GetXaxis();
  const TAxis * yAxis  = h2->GetYaxis();
  int xLow;
  int xHigh;
  int yLow  = yAxis->GetXmin();
  int yHigh = yAxis->GetXmax();
  int nPoints = 0;
  double sum  = 0;
  double esum = 0;
  for (double eta=etaLow; eta<etaHigh; eta+=etaStep)
    {
    xLow  = xAxis->FindBin(-eta);
    xHigh = xAxis->FindBin( eta);
    // this needs to be fixed...
    //double factor = 1-eta/xHigh;
    sum = h2->IntegralAndError(xLow,xHigh,yLow,yHigh,esum,"WIDTH");
    x[nPoints]  = eta;
    ex[nPoints] = 0.001;
    y[nPoints]  = sum; ///TMath::TwoPi();
    ey[nPoints] = esum; ///TMath::TwoPi();
    nPoints++;
    }
  TGraph * g = new TGraphErrors(nPoints, x,y,ex,ey);
  return g;
}

// ============================================================================================================
// 4 parameters function
// ============================================================================================================
// 0  : a        : peak amplitude
// 1  : omegaEta : longitudinal peak width (eta)
// 2  : gammaEta : generalized gaussian exponent -- eta
// 3  : a0       : constant offset
// ============================================================================================================
double Plotter::GeneralizedGaussian(double *x, double *par)
{
  double eta = x[0];
  //double etaSq = eta*eta;
  double a        = par[0];
  double omegaEta = par[1];
  double gammaEta = par[2];
  double a0       = par[3];

  // generalized gaussian peak
  double norm   = gammaEta/2.0/omegaEta/TMath::Gamma(1.0/gammaEta);
  double arg1   = TMath::Abs(eta/omegaEta);
  double peak   = norm * TMath::Exp(-(TMath::Power(arg1,gammaEta) ));
  double result = a*peak;
  result += a0;
  return result;
}


void Plotter::calculateRmsWidth(TH2 * h,
                                double xLowEdge, double xHighEdge,
                                double yLowEdge, double yHighEdge,
                                double & mean, double & meanError,
                                double & rmsWidth,
                                double & rmsWidthError,
                                int direction)
{
  int nx = h->GetXaxis()->GetNbins();
  int xLowBin  = h->GetXaxis()->FindBin(xLowEdge);
  int xHighBin = h->GetXaxis()->FindBin(xHighEdge);
  if (xLowBin<1) xLowBin = 1;
  if (xHighBin>nx)  xHighBin = nx;

  int ny = h->GetNbinsY();
  int yLowBin  = h->GetYaxis()->FindBin(yLowEdge);
  int yHighBin = h->GetYaxis()->FindBin(yHighEdge);
  if (yLowBin<1) yLowBin = 1;
  if (yHighBin>ny)  yHighBin = ny;

  double sum    = 0.0;
  double xSum   = 0.0;
  double x2Sum  = 0.0;
  //  double eXSum  = 0.0;
  //  double eX2Sum = 0.0;
  double m1  = 0.0;
  double m2  = 0.0;
  mean       = 0.0;
  meanError  = 0.0;
  rmsWidth   = 0.0;
  rmsWidthError  = 0.0;
  double c, v, ev, arg;


  // two passes: pass 1 to get the mean, pass 2 to get the rms error,
  for (int iY=yLowBin; iY<=yHighBin; iY++)
    {
    for (int  iX=xLowBin; iX<xHighBin; iX++ )
      {
      switch (direction)
        {
          case 1: c = h->GetXaxis()->GetBinCenter(iX); break;
          case 2: c = h->GetYaxis()->GetBinCenter(iY); break;
        }
      v  = h->GetBinContent(iX,iY);
      sum   += v;
      xSum  += c*v;
      x2Sum += c*c*v;
      }
    }

  if (sum>0)
    {
    m1 = xSum/sum;
    m2 = x2Sum/sum - m1*m1;
    if (m2>0.0) rmsWidth = sqrt(m2);

    for (int iY=yLowBin; iY<=yHighBin; iY++)
      {
      for (int iX=xLowBin; iX<xHighBin; iX++ )
        {
        switch (direction)
          {
            case 1: c = h->GetXaxis()->GetBinCenter(iX); break;
            case 2: c = h->GetYaxis()->GetBinCenter(iY); break;
          }
        v  = h->GetBinContent(iX,iY);
        ev  = h->GetBinError(iX,iY);
        xSum  += c*c*ev*ev;
        x2Sum += c*c*v;
        arg = c*c - 2*m1*c;
        x2Sum += arg*arg * ev*ev;
        }
      }
    // need to compute and output error
    }
}
} // namespace CAP
