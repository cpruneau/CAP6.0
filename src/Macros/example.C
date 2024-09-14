/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2022
 *
 * *********************************************************************/
bool doDraw = true;


class CanvasConfiguration
{
public:

  enum CanvasFormat   { PortraitTight, Portrait, PortraitWide, SquareTight, Square, SquareWide, LandscapeTight, Landscape, LandscapeWide, LandscapeXtop };
  enum CanvasAxes     { Linear, LogX, LogY, LogZ, LogXY, LogXZ, LogYZ, LogXYZ  };

  int windowXPosition;
  int windowYPosition;
  int windowWidth ;
  int windowHeight;
  float windowLeftMargin;
  float windowTopMargin;
  float windowRightMargin;
  float windowBottomMargin;
  bool  windowLogX;
  bool  windowLogY;
  bool  windowLogZ;
  float windowTheta;
  float windowPhi;
  bool  useTickx;
  bool  useTicky;
  bool  useGridx;
  bool  useGridy;

  int windowFillColor;
  int windowFillStyle;
  int windowBorderSize;
  int windowBorderMode;


  CanvasConfiguration();
  CanvasConfiguration(CanvasFormat format, CanvasAxes axes);

  void setDefaultConfiguration();
  void setFormat(CanvasFormat format);
  void setAxes(CanvasAxes axes);
  void setMargins(float left, float top, float right, float bottom);
  void setSize(int width, int heigh);
  void setPosition(int x, int y);

};


CanvasConfiguration::CanvasConfiguration()
{
  setDefaultConfiguration();
  setFormat(Landscape);
}



CanvasConfiguration::CanvasConfiguration(CanvasFormat format, CanvasAxes axes)
{
  setDefaultConfiguration();
  // chose the aspect ratio and the margin style (tight, regular, wide)
  setFormat(format);
  // chose the axes settings
  setAxes(axes);
}


//
// Assignment operator
//
//  CanvasConfiguration & CanvasConfiguration::operator=(const Configuration & config)
//  {
//  if (this!=&config) Configuration::operator=(config);
//  return *this;
//  }

void CanvasConfiguration::setDefaultConfiguration()
{
  windowXPosition    =  20;
  windowYPosition    =  20;
  windowWidth        =  700;
  windowHeight       =  700;
  windowLeftMargin   =  0.15;
  windowTopMargin    =  0.03;
  windowRightMargin  =  0.03;
  windowBottomMargin =  0.15;
  windowLogX         =  false;
  windowLogY         =  false;
  windowLogZ         =  false;
  windowTheta        =  35.0;
  windowPhi          =  25.0;
  useTickx           =  true;
  useTicky           =  true;
  useGridx           =  false;
  useGridy           =  false;

  windowFillColor    =  kWhite;
  windowFillStyle    =  1001;
  windowBorderSize   =  0;
  windowBorderMode   =  0;
}


void CanvasConfiguration::setFormat(CanvasFormat format)
{
  switch (format)
    {
      case PortraitTight:
      windowXPosition    =  20;
      windowYPosition    =  20;
      windowWidth        =  500;
      windowHeight       =  800;
      windowLeftMargin   =  0.10;
      windowTopMargin    =  0.03;
      windowRightMargin  =  0.03;
      windowBottomMargin =  0.10;
      break;

      case Portrait:
      windowXPosition   =  20;
      windowYPosition   =  20;
      windowWidth       =  500;
      windowHeight      =  800;
      windowLeftMargin  =  0.15;
      windowTopMargin   =  0.05;
      windowRightMargin =  0.05;
      windowBottomMargin = 0.15;
      break;

      case PortraitWide:
      windowXPosition     =  20;
      windowYPosition     =  20;
      windowWidth         =  500;
      windowHeight        =  800;
      windowLeftMargin    =  0.20;
      windowTopMargin     =  0.10;
      windowRightMargin   =  0.10;
      windowBottomMargin  =  0.20;
      break;

      case SquareTight:
      windowXPosition   =  20;
      windowYPosition   =  20;
      windowWidth       =  700;
      windowHeight      =  700;
      windowLeftMargin  =  0.10;
      windowTopMargin   =  0.03;
      windowRightMargin =  0.03;
      windowBottomMargin = 0.10;
      break;

      case Square:
      windowXPosition     =  20;
      windowYPosition     =  20;
      windowWidth         =  700;
      windowHeight        =  700;
      windowLeftMargin    = 0.15;
      windowTopMargin     = 0.05;
      windowRightMargin   = 0.05;
      windowBottomMargin  = 0.15;
      break;

      case SquareWide:
      windowXPosition     =  20;
      windowYPosition     =  20;
      windowWidth         =  700;
      windowHeight        =  700;
      windowLeftMargin    =  0.20;
      windowTopMargin     =  0.05;
      windowRightMargin   =  0.10;
      windowBottomMargin  =  0.20;
      break;

      case LandscapeTight:
      windowXPosition     =  20;
      windowYPosition     =  20;
      windowWidth         =  800;
      windowHeight        =  500;
      windowLeftMargin    =  0.10;
      windowTopMargin     =  0.03;
      windowRightMargin   =  0.03;
      windowBottomMargin  =  0.10;
      break;

      case Landscape:
      windowXPosition     =  20;
      windowYPosition     =  20;
      windowWidth         =  800;
      windowHeight        =  500;
      windowLeftMargin    =  0.15;
      windowTopMargin     =  0.05;
      windowRightMargin   =  0.10;
      windowBottomMargin  =  0.15;
      break;

      case LandscapeWide:
      windowXPosition   =  20;
      windowYPosition   =  20;
      windowWidth         = 800;
      windowHeight        = 500;
      windowLeftMargin    = 0.20;
      windowTopMargin     = 0.05;
      windowRightMargin   = 0.15;
      windowBottomMargin  = 0.15;
      break;

      case LandscapeXtop:
      windowXPosition     =  20;
      windowYPosition     =  20;
      windowWidth         = 800;
      windowHeight        = 600;
      windowLeftMargin    = 0.20;
      windowTopMargin     = 0.20;
      windowRightMargin   = 0.05;
      windowBottomMargin  = 0.15;
      break;

    };
}

void CanvasConfiguration::setAxes(CanvasAxes axes)
{
  switch (axes)
    {
      case Linear:
      windowLogX   =  false;
      windowLogY   =  false;
      windowLogZ   =  false;
      break;

      case LogX:
      windowLogX   =  true;
      windowLogY   =  false;
      windowLogZ   =  false;
      break;

      case LogY:
      windowLogX   =  false;
      windowLogY   =  true;
      windowLogZ   =  false;
      break;

      case LogZ:
      windowLogX   =  false;
      windowLogY   =  false;
      windowLogZ   =  true;
      break;

      case LogXY:
      windowLogX   =  true;
      windowLogY   =  true;
      windowLogZ   =  false;
      break;

      case LogXZ:
      windowLogX   =  true;
      windowLogY   =  false;
      windowLogZ   =  true;
      break;

      case LogYZ:
      windowLogX   =  false;
      windowLogY   =  true;
      windowLogZ   =  true;
      break;

      case LogXYZ:
      windowLogX   =  true;
      windowLogY   =  true;
      windowLogZ   =  true ;
      break;
    };
}

void CanvasConfiguration::setMargins(float left, float top, float right, float bottom)
{
  windowLeftMargin   =  left;
  windowTopMargin    =  top;
  windowRightMargin  =  right;
  windowBottomMargin =  bottom;
}

void CanvasConfiguration::setSize(int width, int heigh)
{
  windowWidth    =    width;
  windowHeight   =    heigh;
}

void CanvasConfiguration::setPosition(int x, int y)
{
  windowXPosition = x;
  windowYPosition = y;
}

class CanvasGroup
{

protected:

  std::vector<TCanvas*> canvases;

public:

  CanvasGroup();
  CanvasGroup(const CanvasGroup & source);
  virtual ~CanvasGroup() {}
  CanvasGroup & operator=(const CanvasGroup & source);

  int size();
  std::vector<TCanvas*> & getCanvases();
  const std::vector<TCanvas*> & getCanvases() const;

  void createDirectory(const  TString & dirName);
  TCanvas * createCanvas(const  TString & canvasName, const CanvasConfiguration & canvasConfig, int inc=200);
  TCanvas * createCanvasXX(int nx, int ny, const  TString & canvasName, const CanvasConfiguration & canvasConfig, int inc=30);

  void printCanvas(TCanvas * canvas,
                   const  TString & directoryName="./",
                   bool printGif=0,
                   bool printPdf=1,
                   bool printSvg=0,
                   bool printPng=0,
                   bool printC=0);
  void printAllCanvas(const  TString & outputPath,
                      bool printGif=0,
                      bool printPdf=1,
                      bool printSvg=0,
                      bool printPng=0,
                      bool printC=0);
  ClassDef(CanvasGroup,0)

};

CanvasGroup::CanvasGroup()
:
canvases()
{
  /* no ops*/
}

CanvasGroup::CanvasGroup(const CanvasGroup & source)
:
canvases(source.canvases)
{
  /* no ops*/
}


CanvasGroup & CanvasGroup::operator=(const CanvasGroup & source)
{
  if (this!=&source)
    {
    canvases = source.canvases;
    }
  return *this;
}

int CanvasGroup::size()
{
  return canvases.size();
}

std::vector<TCanvas*> & CanvasGroup::getCanvases()
{
  return canvases;
}
const std::vector<TCanvas*> & CanvasGroup::getCanvases() const
{
  return canvases;
}

//!
//!Create a directory or folder in the file system
//!If the directory alearfy exists, do nothing.
//!
void CanvasGroup::createDirectory(const  TString & dirName)
{
  gSystem->mkdir(dirName,1);
}

//!
//! Create a canvas
//!
TCanvas * CanvasGroup::createCanvas(const  TString & canvasName,
                                    const CanvasConfiguration & configuration,
                                    int inc)
{
  int xInc = inc*size();
  TCanvas * canvas = new TCanvas(canvasName,
                                 canvasName,
                                 xInc+configuration.windowXPosition,
                                 configuration.windowYPosition,
                                 configuration.windowWidth,
                                 configuration.windowHeight);
  canvas->SetLogx(        configuration.windowLogX);
  canvas->SetLogy(        configuration.windowLogY);
  canvas->SetLogz(        configuration.windowLogZ);
  canvas->SetRightMargin( configuration.windowRightMargin);
  canvas->SetLeftMargin(  configuration.windowLeftMargin);
  canvas->SetBottomMargin(configuration.windowBottomMargin);
  canvas->SetTopMargin(   configuration.windowTopMargin);
  canvas->SetTicky(       configuration.useTickx);
  canvas->SetTickx(       configuration.useTicky);
  canvas->SetGridx(       configuration.useGridx);
  canvas->SetGridy(       configuration.useGridy);
  canvas->SetTheta(       configuration.windowTheta);
  canvas->SetPhi(         configuration.windowPhi);
  canvas->SetFillColor(   configuration.windowFillColor);
  canvas->SetFillStyle(   configuration.windowFillStyle);
  canvas->SetBorderSize(  configuration.windowBorderSize);
  canvas->SetBorderMode(  configuration.windowBorderMode);
  canvases.push_back(canvas);
  return canvas;
}

////////////////////////////////////////////////////
// Create a canvas
////////////////////////////////////////////////////
TCanvas * CanvasGroup::createCanvasXX(int nx, int ny, const  TString & canvasName, const CanvasConfiguration & configuration, int inc)
{
  int xInc = inc*size();
  TCanvas * canvas = new TCanvas(canvasName,
                                 canvasName,
                                 xInc+configuration.windowXPosition,
                                 configuration.windowYPosition,
                                 configuration.windowWidth,
                                 configuration.windowHeight);
  canvas->Divide(nx,ny,0,0);
  canvas->SetLogx(        configuration.windowLogX);
  canvas->SetLogy(        configuration.windowLogY);
  canvas->SetLogz(        configuration.windowLogZ);
  canvas->SetRightMargin( configuration.windowRightMargin);
  canvas->SetLeftMargin(  configuration.windowLeftMargin);
  canvas->SetBottomMargin(configuration.windowBottomMargin);
  canvas->SetTopMargin(   configuration.windowTopMargin);
  canvas->SetTheta(       configuration.windowTheta);
  canvas->SetPhi(         configuration.windowPhi);

  canvas->SetFillColor(  configuration.windowFillColor);
  canvas->SetFillStyle(  configuration.windowFillStyle);
  canvas->SetBorderSize( configuration.windowBorderSize);
  canvas->SetBorderMode( configuration.windowBorderMode);
  canvases.push_back(canvas);
  return canvas;
}

//!
//! Print Canvas
//!
void CanvasGroup::printCanvas(TCanvas * canvas,
                              const  TString & outputPath,
                              bool printGif,
                              bool printPdf,
                              bool printSvg,
                              bool printPng,
                              bool printC)
{
  createDirectory(outputPath);
  TString fileName = outputPath;
  fileName += "/";
  fileName += canvas->GetName();
  if (printGif) canvas->Print(fileName+".gif");
  if (printPdf) canvas->Print(fileName+".pdf");
  if (printSvg) canvas->Print(fileName+".svg");
  if (printPng) canvas->Print(fileName+".png");
  if (printC)   canvas->Print(fileName+".C");
}

//!
//! Print All Canvases Owed by this group
//!
void CanvasGroup::printAllCanvas(const  TString & outputPath,
                                 bool printGif,
                                 bool printPdf,
                                 bool printSvg,
                                 bool printPng,
                                 bool printC)
{
  for (auto & canvas : canvases)
    printCanvas(canvas,outputPath,printGif,printPdf,printSvg,printPng,printC);
}





class GraphConfiguration
{
public:
  int npx;
  int npy;
  int lineColor;
  int lineStyle;
  int lineWidth;
  int markerColor;
  int markerStyle;
  float markerSize;
  int nXDivisions;
  float xTitleSize;
  float xTitleOffset;
  float xLabelSize;
  float xLabelOffset;
  int nYDivisions;
  float yTitleSize;
  float yTitleOffset;
  float yLabelSize;
  float yLabelOffset;
  int nZDivisions;
  float zTitleSize;
  float zTitleOffset;
  float zLabelSize;
  float zLabelOffset;

  GraphConfiguration();
};

GraphConfiguration::GraphConfiguration()
:
npx(100),
npy(100),
lineColor(1),
lineStyle(1),
lineWidth(1),
markerColor(1),
markerStyle(20),
markerSize(1.2),
nXDivisions(5),
xTitleSize(0.06),
xTitleOffset(0.8),
xLabelSize(0.06),
xLabelOffset(0.01),
nYDivisions(5),
yTitleSize(0.06),
yTitleOffset(0.8),
yLabelSize(0.06),
yLabelOffset(0.01),
nZDivisions(5),
zTitleSize(0.06),
zTitleOffset(0.8),
zLabelSize(0.06),
zLabelOffset(0.01)
{
  // no ops
}


void findMinMax(TH1* histogram, double & minimum, double & maximum)
{
  minimum = histogram->GetBinContent(histogram->GetMinimumBin());
  maximum = histogram->GetBinContent(histogram->GetMaximumBin());
}


TLatex * createLabel(const TString & text, double x, double y, double angle, int color,  double fontSize, bool doDraw)
{
  TLatex * label = new TLatex(x,y,text);
  label->SetTextColor(color);
  label->SetTextAngle(angle);
  label->SetTextSize(fontSize);
  if (doDraw) label->Draw();
  return label;
}

TLegend * createLegend(double x1, double y1, double x2, double y2, double fontSize)
{
  TLegend *legend = new TLegend(x1,y1,x2,y2);
  legend->SetTextSize(fontSize);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  return legend;
}

TLegend * createLegend(TH1*histogram, const TString & legendText, double x1, double y1, double x2, double y2, double fontSize, bool doDraw)
{
  TLegend *legend = new TLegend(x1,y1,x2,y2);
  legend->SetTextSize(fontSize);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->AddEntry(histogram,legendText);
  if (doDraw) legend->Draw();
  return legend;
}

TLegend * createLegend(vector<TH1*> histograms, vector<TString>   legendTexts, double x1, double y1, double x2, double y2, double fontSize, bool doDraw)
{
  TLegend *legend = new TLegend(x1,y1,x2,y2);
  legend->SetTextSize(fontSize);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  int k=0;
  for (auto & histogram : histograms)
    legend->AddEntry(histogram,legendTexts[k++]);
  if (doDraw) legend->Draw();
  return legend;
}

TLegend * createLegend(vector<TGraph*> graphs,vector<TString>   legendTexts,double x1, double y1, double x2, double y2, double fontSize, bool doDraw)
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

// Create simple line
//
TLine * createLine(float x1, float y1, float x2, float y2, int style, int color, int width, bool doDraw)
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
TArrow * createArrow(float x1, float y1, float x2, float y2, float arrowSize, Option_t* option, int style, int color, int width, bool doDraw)
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
void setProperties(TH1 * h,
                   const GraphConfiguration & graphConfiguration,
                   const TString & xTitle,
                   const TString & yTitle,
                   const TString & zTitle)
{
  h->SetLineColor(graphConfiguration.lineColor);
  h->SetLineStyle(graphConfiguration.lineStyle);
  h->SetLineWidth(graphConfiguration.lineWidth);
  h->SetMarkerColor(graphConfiguration.markerColor);
  h->SetMarkerStyle(graphConfiguration.markerStyle);
  h->SetMarkerSize (graphConfiguration.markerSize);
  TAxis * xAxis = (TAxis *) h->GetXaxis();
  xAxis->SetNdivisions(graphConfiguration.nXDivisions);
  xAxis->SetTitleSize(graphConfiguration.xTitleSize);
  xAxis->SetTitleOffset(graphConfiguration.xTitleOffset);
  xAxis->SetLabelSize(graphConfiguration.xLabelSize);
  xAxis->SetLabelOffset(graphConfiguration.xLabelOffset);
  if (!xTitle.EqualTo("none")) xAxis->SetTitle(xTitle);
  TAxis * yAxis = (TAxis *) h->GetYaxis();
  yAxis->SetNdivisions(graphConfiguration.nYDivisions);
  yAxis->SetTitleSize(graphConfiguration.yTitleSize);
  yAxis->SetTitleOffset(graphConfiguration.yTitleOffset);
  yAxis->SetLabelSize(graphConfiguration.yLabelSize);
  yAxis->SetLabelOffset(graphConfiguration.yLabelOffset);
  if (yTitle.EqualTo("none"))   yAxis->SetTitle(yTitle);

  if (h->IsA() == TH2::Class()  || h->IsA() == TH2F::Class() || h->IsA() == TH2F::Class() )
    {
    TAxis * zAxis = (TAxis *) h->GetZaxis();
    zAxis->SetNdivisions(graphConfiguration.nZDivisions);
    zAxis->SetTitleSize(graphConfiguration.zTitleSize);
    zAxis->SetTitleOffset(graphConfiguration.zTitleOffset);
    zAxis->SetLabelSize(graphConfiguration.zLabelSize);
    zAxis->SetLabelOffset(graphConfiguration.zLabelOffset);
    if (zTitle.EqualTo("none"))  zAxis->SetTitle(zTitle);
    }
}

void setProperties(vector<TH1*> histograms,
                   const vector<GraphConfiguration*> & graphConfigurations,
                   const TString & xTitle,
                   const TString & yTitle,
                   const TString & zTitle)
{
  int k = 0;
  for (auto & histogram : histograms)
    setProperties(histogram, *(graphConfigurations[k++]),xTitle,yTitle,zTitle);
}

void setProperties(TGraph * g,
                   const GraphConfiguration & graphConfiguration,
                   const TString & xTitle,
                   const TString & yTitle)
{
  g->SetLineColor(graphConfiguration.lineColor);
  g->SetLineStyle(graphConfiguration.lineStyle);
  g->SetLineWidth(graphConfiguration.lineWidth);
  g->SetMarkerColor(graphConfiguration.markerColor);
  g->SetMarkerStyle(graphConfiguration.markerStyle);
  g->SetMarkerSize (graphConfiguration.markerSize);
  TAxis * xAxis = (TAxis *) g->GetXaxis();
  xAxis->SetNdivisions(graphConfiguration.nXDivisions);
  xAxis->SetTitleSize(graphConfiguration.xTitleSize);
  xAxis->SetTitleOffset(graphConfiguration.xTitleOffset);
  xAxis->SetLabelSize(graphConfiguration.xLabelSize);
  xAxis->SetLabelOffset(graphConfiguration.xLabelOffset);
  if (!xTitle.EqualTo("none")) xAxis->SetTitle(xTitle);
  TAxis * yAxis = (TAxis *) g->GetYaxis();
  yAxis->SetNdivisions(graphConfiguration.nYDivisions);
  yAxis->SetTitleSize(graphConfiguration.yTitleSize);
  yAxis->SetTitleOffset(graphConfiguration.yTitleOffset);
  yAxis->SetLabelSize(graphConfiguration.yLabelSize);
  yAxis->SetLabelOffset(graphConfiguration.yLabelOffset);
  if (yTitle.EqualTo("none"))   yAxis->SetTitle(yTitle);
}

void setProperties(vector<TGraph*> & graphs,
                   const vector<GraphConfiguration*> & graphConfigurations,
                   const TString & xTitle,
                   const TString & yTitle)
{
  int k = 0;
  for (auto & graph : graphs)
    setProperties(graph, *(graphConfigurations[k++]),xTitle,yTitle);
}


//!
//! Set Default Style for Plots
//!
void setDefaultOptions(bool color)
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

double findHistoMinimum(TH1 * h)
{
  return h->GetBinContent(h->GetMinimumBin());
}

double findHistoMaximum(TH1 * h)
{
  return h->GetBinContent(h->GetMaximumBin());
}

double findHistoMinimum2D(TH2 * h)
{
  int x, y, z;
  h->GetMinimumBin(x,y,z);
  return h->GetBinContent(x,y);
}

double findHistoMaximum2D(TH2 * h)
{
  int x, y, z;
  h->GetMaximumBin(x,y,z);
  return h->GetBinContent(x,y);
}

double findGraphMinimum(TGraph * h)
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

double findGraphMaximum(TGraph * h)
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

double findMinimum(vector<double> & values)
{
  double min = 1.0E100;
  for (Size_t k=0; k<values.size(); k++)
    {
    if (values[k]<min) min = values[k];
    cout << "k   " << k << " v: " << values[k] << " min: " << min << endl;
    }
  return min;
}

double findMaximum(vector<double> & values)
{
  double max = -1.0E100;
  for (Size_t k=0; k<values.size(); k++)
    {
    if (values[k]>max) max = values[k];
    cout << "k   " << k << " v: " << values[k] << " max: " << max << endl;
    }
  return max;
}

TGraph * makeGraph(vector<double> vx,
                   vector<double> vex,
                   vector<double> vy,
                   vector<double> vey)
{
  auto n = vx.size();
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


TGraph *  sumGraphs(TGraph * g1, TGraph * g2)
{
  int  n1 = g1->GetN();
  int  n2 = g2->GetN();
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

TGraph* calculateIntegral1D(TH1* h,
                            double etaLow,
                            double etaHigh,
                            double etaStep,
                            int size)
{

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


TGraph* calculateIntegral(TH2* h2,
                          double etaLow,
                          double etaHigh,
                          double etaStep,
                          int size)
{

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


void calculateRmsWidth(TH2 * h,
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

int example()
{

  // create and fill histograms...

  TH1 * h1 = new TH1D("h1","Example1",100, 0.0, 100.0);
  TH1 * h2 = new TH1D("h2","Example2",100, 0.0, 100.0);
  for (int k=0; k<1000; k++)
    {
    h1->Fill(gRandom->Gaus(50.0,5.0));
    h2->Fill(gRandom->Exp(5.0));
    }

// create canvas and draw histograms.

  CanvasGroup  canvasGroup;


  void createDirectory(const  TString & dirName);
  TCanvas * createCanvas(const  TString & canvasName, const CanvasConfiguration & canvasConfig, int inc=200);

  CanvasConfiguration clin(CanvasConfiguration::Portrait,CanvasConfiguration::Linear);
  CanvasConfiguration clog(CanvasConfiguration::Landscape,CanvasConfiguration::LogY);

  GraphConfiguration g1;
  GraphConfiguration g2;
  g1.lineColor = 2;
  g2.lineWidth = 3;

  g2.lineColor = 4;
  g2.lineStyle = 5;
  g2.lineWidth = 10;


  setProperties(h1,g1,"MyXtitle","MyYtitle","");
  setProperties(h2,g2,"AnotherXtitle","AnotherYYtitle","");


  TCanvas *c1 = canvasGroup.createCanvas("H1",clin);
  h1->Draw();

  TCanvas *c2 = canvasGroup.createCanvas("H2",clog);
  h2->Draw();


  canvasGroup.printAllCanvas("MyOutputDirectory");

  return 0;

}
