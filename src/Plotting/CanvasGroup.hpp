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
#ifndef CAP__CanvasGroup
#define CAP__CanvasGroup
#include "Aliases.hpp"
#include "TCanvas.h"
#include "TSystem.h"
#include "CanvasConfiguration.hpp"

namespace CAP
{

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

  void createDirectory(const String & dirName);
  TCanvas * createCanvas(const String & canvasName, const Configuration & canvasConfig, int inc=200);
  TCanvas * createCanvasXX(int nx, int ny, const String & canvasName, const Configuration & canvasConfig, int inc=30);

  void printCanvas(TCanvas * canvas,
                   const String & directoryName="./",
                   bool printGif=0,
                   bool printPdf=1,
                   bool printSvg=0,
                   bool printPng=0,
                   bool printC=0);
  void printAllCanvas(const String & outputPath,
                      bool printGif=0,
                      bool printPdf=1,
                      bool printSvg=0,
                      bool printPng=0,
                      bool printC=0);
  ClassDef(CanvasGroup,0)

};

} // namespace CAP

#endif /* CanvasGroup_hpp */
