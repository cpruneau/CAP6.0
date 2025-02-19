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
#include "TROOT.h"
#include "TF1.h"
#include "TF2.h"
#include "FunctionGroup.hpp"
#include "PrintHelpers.hpp"

using CAP::FunctionGroup;

ClassImp(FunctionGroup);

FunctionGroup::FunctionGroup()
:
functions()
{
  /* no ops*/
}


FunctionGroup::FunctionGroup(const FunctionGroup & source)
:
functions(source.functions) // shallow copy
{
  /* no ops*/
}

FunctionGroup::~FunctionGroup()
{
  // root is in charge///
}

FunctionGroup & FunctionGroup::operator=(const FunctionGroup & source)
{
  if (this!=&source)
    {
    functions  = source.functions;
    }
  return *this;
}

void FunctionGroup::setDefaultOptions(bool color)
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

//!
//! Setting Function Properties
//!
void FunctionGroup::setFunctionProperties(TF1 * f,
                                          GraphConfiguration & graphConfiguration,
                                          bool verbose)
{
  if (verbose)
    {
    printCR();
    printValue("Setting properties of function",f->GetTitle());
    }
  //String name =
  f->SetLineColor(graphConfiguration.getValueInt("lineColor"));
  f->SetLineStyle(graphConfiguration.getValueInt("lineStyle"));
  f->SetLineWidth(graphConfiguration.getValueInt("lineWidth"));
  TAxis * xAxis = (TAxis *) f->GetXaxis();
  xAxis->SetNdivisions(graphConfiguration.getValueDouble("nXDivisions"));
  xAxis->SetTitleSize(graphConfiguration.getValueDouble("xTitleSize"));
  xAxis->SetTitleOffset(graphConfiguration.getValueDouble("xTitleOffset"));
  //xAxis->SetTitle(graphConfiguration.xTitle);
  xAxis->SetLabelSize(graphConfiguration.getValueDouble("xLabelSize"));
  xAxis->SetLabelOffset(graphConfiguration.getValueDouble("xLabelOffset"));
  TAxis * yAxis = (TAxis *) f->GetYaxis();
  yAxis->SetNdivisions(graphConfiguration.getValueInt("nYDivisions"));
  yAxis->SetTitleSize(graphConfiguration.getValueDouble("yTitleSize"));
  yAxis->SetTitleOffset(graphConfiguration.getValueDouble("yTitleOffset"));
  yAxis->SetLabelSize(graphConfiguration.getValueDouble("yLabelSize"));
  yAxis->SetLabelOffset(graphConfiguration.getValueDouble("yLabelOffset"));
  //yAxis->SetTitle(graphConfiguration.yTitle);
  if (f->IsA() == TF2::Class() )
    {
    TAxis * zAxis = (TAxis *) f->GetZaxis();
    zAxis->SetNdivisions(graphConfiguration.getValueInt("nZDivisions"));
    zAxis->SetTitleSize(graphConfiguration.getValueDouble("zTitleSize"));
    zAxis->SetTitleOffset(graphConfiguration.getValueDouble("zTitleOffset"));
    zAxis->SetLabelSize(graphConfiguration.getValueDouble("zLabelSize"));
    zAxis->SetLabelOffset(graphConfiguration.getValueDouble("zLabelOffset"));
    }
}

//!
//!Plot all functions if this group in separate canvases
//!
//void FunctionGroup::plotAllFunctions(const String & outputPath, bool doPrint)
//{
////  GraphConfiguration  * gc1D = new GraphConfiguration(1,0);
////  GraphConfiguration  * gc2D = new GraphConfiguration(2,0);
////  CanvasConfiguration * cc1D = new CanvasConfiguration();
////  CanvasConfiguration * cc2D = new CanvasConfiguration();
////  CanvasGroup    * canvasGroup = new CanvasGroup();
////  canvasGroup->createDirectory(outputPath);
////  String name;
////  for (auto & f : functions)
////    {
////    name = f->GetName();
////    if (f->IsA() == TF1::Class())
////      {
////      if (verbose)
////        {
////        printValue("Plotting 1D function named",f->GetTitle());
////        }
////      canvasGroup->createCanvas(name, *cc1D, 30);
////      setFunctionProperties(f, *gc1D);
////      f->Draw();
////      }
////    else if (f->IsA() == TF2::Class())
////      {
////      if (verbose)
////        {
////        printValue("Plotting 2D function named",f->GetTitle());
////        }
////      canvasGroup->createCanvas(name, *cc2D, 30);
////      setFunctionProperties(f, *gc2D);
////      f->Draw("SURF3");
////      }
////    }
////  if (doPrint) canvasGroup->printAllCanvas(outputPath);
//}


void FunctionGroup::push_back(TF1* function)
{
  if (!function) throw NullPointerException(__FUNCTION__);
  functions.push_back(function);
}

TF1* FunctionGroup::getFunctionAt(unsigned int index)
{
  if (index>=functions.size()) throw OutOfBoundException(__FUNCTION__);
  return functions[index];
}
const std::vector<TF1*> & FunctionGroup::getFunctions() const
{
  return functions;
}

std::vector<TF1*> & FunctionGroup::getFunctions()
{
  return functions;
}

int FunctionGroup::size()
{
  return functions.size();
}
