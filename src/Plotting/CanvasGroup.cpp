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
#include "CanvasGroup.hpp"

ClassImp(CAP::CanvasGroup);

namespace CAP
{

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
void CanvasGroup::createDirectory(const String & dirName)
{
  gSystem->mkdir(dirName,1);
}

//!
//! Create a canvas
//!
TCanvas * CanvasGroup::createCanvas(const String & canvasName,
                                    const Configuration & configuration,
                                    int inc)
{
  int xInc = inc*size();
  TCanvas * canvas = new TCanvas(canvasName,
                                 canvasName,
                                 xInc+configuration.getValueInt("windowXPosition"),
                                 configuration.getValueInt("windowYPosition"),
                                 configuration.getValueInt("windowWidth"),
                                 configuration.getValueInt("windowHeight") );
  canvas->SetLogx(        configuration.getValueBool("windowLogX") );
  canvas->SetLogy(        configuration.getValueBool("windowLogY") );
  canvas->SetLogz(        configuration.getValueBool("windowLogZ") );
  canvas->SetRightMargin( configuration.getValueDouble("windowRightMargin") );
  canvas->SetLeftMargin(  configuration.getValueDouble("windowLeftMargin") );
  canvas->SetBottomMargin(configuration.getValueDouble("windowBottomMargin") );
  canvas->SetTopMargin(   configuration.getValueDouble("windowTopMargin") );
  canvas->SetTicky(       configuration.getValueBool("useTickx") );
  canvas->SetTickx(       configuration.getValueBool("useTicky") );
  canvas->SetGridx(       configuration.getValueBool("useGridx") );
  canvas->SetGridy(       configuration.getValueBool("useGridy") );
  canvas->SetTheta(       configuration.getValueDouble("windowTheta") );
  canvas->SetPhi(         configuration.getValueDouble("windowPhi") );
  canvas->SetFillColor(   configuration.getValueInt("windowFillColor") );
  canvas->SetFillStyle(   configuration.getValueInt("windowFillStyle") );
  canvas->SetBorderSize(  configuration.getValueInt("windowBorderSize") );
  canvas->SetBorderMode(  configuration.getValueInt("windowBorderMode") );
  canvas->SetTicky(1);
  canvas->SetTickx(1);
  canvases.push_back(canvas);
  return canvas;
}

////////////////////////////////////////////////////
// Create a canvas
////////////////////////////////////////////////////
TCanvas * CanvasGroup::createCanvasXX(int nx, int ny, const String & canvasName, const Configuration & configuration, int inc)
{
  int xInc = inc*size();
  TCanvas * canvas = new TCanvas(canvasName,
                                 canvasName,
                                 xInc+configuration.getValueInt("windowXPosition"),
                                 configuration.getValueInt("windowYPosition"),
                                 configuration.getValueInt("windowWidth"),
                                 configuration.getValueInt("windowHeight") );
  canvas->Divide(nx,ny,0,0);
  canvas->SetLogx(        configuration.getValueBool("windowLogX") );
  canvas->SetLogy(        configuration.getValueBool("windowLogY") );
  canvas->SetLogz(        configuration.getValueBool("windowLogZ") );
  canvas->SetRightMargin( configuration.getValueDouble("windowRightMargin") );
  canvas->SetLeftMargin(  configuration.getValueDouble("windowLeftMargin") );
  canvas->SetBottomMargin(configuration.getValueDouble("windowBottomMargin") );
  canvas->SetTopMargin(   configuration.getValueDouble("windowTopMargin") );
  canvas->SetTheta(       configuration.getValueDouble("windowTheta") );
  canvas->SetPhi(         configuration.getValueDouble("windowPhi") );

  canvas->SetFillColor(  configuration.getValueInt("windowFillColor") );
  canvas->SetFillStyle(  configuration.getValueInt("windowFillStyle") );
  canvas->SetBorderSize( configuration.getValueDouble("windowBorderSize") );
  canvas->SetBorderMode( configuration.getValueDouble("windowBorderMode") );
  canvases.push_back(canvas);
  return canvas;
}

//!
//! Print Canvas
//!
void CanvasGroup::printCanvas(TCanvas * canvas,
                              const String & outputPath,
                              bool printGif,
                              bool printPdf,
                              bool printSvg,
                              bool printPng,
                              bool printC)
{
  createDirectory(outputPath);
  String fileName = outputPath;
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
void CanvasGroup::printAllCanvas(const String & outputPath,
                                 bool printGif,
                                 bool printPdf,
                                 bool printSvg,
                                 bool printPng,
                                 bool printC)
{
  for (auto & canvas : canvases)
    printCanvas(canvas,outputPath,printGif,printPdf,printSvg,printPng,printC);
}


} // namespace CAP

