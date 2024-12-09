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
#include "ParticleSingleDerivedHistos.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::ParticleSingleDerivedHistos);

namespace CAP
{

ParticleSingleDerivedHistos::ParticleSingleDerivedHistos()
:
HistogramGroup(),
fillEta(false),
fillY(false),
fillP2(false),
nBins_n1(0),
min_n1(0.0),
max_n1(0.0),
nBins_pt(0),
min_pt(0.0),
max_pt(0.0),
scale_pt(0.0),
nBins_phi(0),
min_phi(0.0),
max_phi(0.0),
scale_phi(0.0),
nBins_eta(0),
min_eta(0.0),
max_eta(0.0),
range_eta(0.0),
nBins_y(0),
min_y(0.0),
max_y(0.0),
range_y(0.0),
h_n1_phi(nullptr),
h_n1_eta(nullptr),
h_n1_y(nullptr),
h_spt_phi(nullptr),
h_spt_eta(nullptr),
h_spt_y(nullptr),
h_pt_phi(nullptr),
h_pt_eta(nullptr),
h_pt_phiEta(nullptr),
h_pt_y(nullptr),
h_pt_phiY(nullptr)
{
  appendClassName("ParticleSingleDerivedHistos");
  setInstanceName("SingleDerived");
}

ParticleSingleDerivedHistos::ParticleSingleDerivedHistos(const ParticleSingleDerivedHistos & group)
:
HistogramGroup(group),
fillEta(group.fillEta ),
fillY(group.fillY ),
fillP2(group.fillP2 ),
nBins_n1(group.nBins_n1 ),
min_n1(group.min_n1 ),
max_n1(group.max_n1 ),
nBins_pt(group.nBins_pt ),
min_pt(group.min_pt ),
max_pt(group.max_pt ),
scale_pt(group.scale_pt ),
nBins_phi(group.nBins_phi ),
min_phi(group.min_phi ),
max_phi(group.max_phi ),
scale_phi(group.scale_phi ),
nBins_eta(group.nBins_eta ),
min_eta(group.min_eta ),
max_eta(group.max_eta ),
range_eta(group.range_eta ),
nBins_y(group.nBins_y ),
min_y(group.min_y ),
max_y(group.max_y ),
range_y(group.range_y ),
h_n1_phi(nullptr),
h_n1_eta(nullptr),
h_n1_y(nullptr),
h_spt_phi(nullptr),
h_spt_eta(nullptr),
h_spt_y(nullptr),
h_pt_phi(nullptr),
h_pt_eta(nullptr),
h_pt_phiEta(nullptr),
h_pt_y(nullptr),
h_pt_phiY(nullptr)
{
  cloneAll(group);
}

ParticleSingleDerivedHistos & ParticleSingleDerivedHistos::operator=(const ParticleSingleDerivedHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    fillEta   = group.fillEta;
    fillY     = group.fillY;
    fillP2    = group.fillP2;
    nBins_n1  = group.nBins_n1;
    min_n1    = group.min_n1;
    max_n1    = group.max_n1;
    nBins_pt  = group.nBins_pt;
    min_pt    = group.min_pt;
    max_pt    = group.max_pt;
    scale_pt  = group.scale_pt;
    nBins_phi = group.nBins_phi;
    min_phi   = group.min_phi;
    max_phi   = group.max_phi;
    scale_phi = group.scale_phi;
    nBins_eta = group.nBins_eta;
    min_eta   = group.min_eta;
    max_eta   = group.max_eta;
    range_eta = group.range_eta;
    nBins_y   = group.nBins_y;
    min_y     = group.min_y;
    max_y     = group.max_y;
    range_y   = group.range_y;
    cloneAll(group);
    }
  return *this;
}

void ParticleSingleDerivedHistos::cloneAll(const ParticleSingleDerivedHistos & group)
{
  // only clone those that exist...
  if (group.h_n1_phi) h_n1_phi       = (TH1*) group.h_n1_phi->Clone();
  if (group.h_n1_eta) h_n1_eta       = (TH1*) group.h_n1_eta->Clone();
  if (group.h_n1_y) h_n1_y           = (TH1*) group.h_n1_y->Clone();
  if (group.h_spt_phi) h_spt_phi     = (TH1*) group.h_spt_phi->Clone();
  if (group.h_spt_eta) h_spt_eta     = (TH1*) group.h_spt_eta->Clone();
  if (group.h_spt_y) h_spt_y         = (TH1*) group.h_spt_y->Clone();
  if (group.h_pt_phi) h_pt_phi       = (TH1*) group.h_pt_phi->Clone();
  if (group.h_pt_eta) h_pt_eta       = (TH1*) group.h_pt_eta->Clone();
  if (group.h_pt_phiEta) h_pt_phiEta = (TH2*) group.h_pt_phiEta->Clone();
  if (group.h_pt_y) h_pt_y           = (TH1*) group.h_pt_y->Clone();
  if (group.h_pt_phiY) h_pt_phiY     = (TH2*) group.h_pt_phiY->Clone();
}


void ParticleSingleDerivedHistos::createHistograms()
{
  if ( reportStart(__FUNCTION__))  {/* no ops */};
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  fillEta   = configuration.getValueBool(ptn,"FillEta");
  fillY     = configuration.getValueBool(ptn,"FillY");
  fillP2    = configuration.getValueBool(ptn,"FillP2");
  nBins_pt  = configuration.getValueInt(ptn,"nBins_pt");
  min_pt    = configuration.getValueDouble(ptn,"Min_pt");
  max_pt    = configuration.getValueDouble(ptn,"Max_pt");
  nBins_phi = configuration.getValueInt(ptn,"nBins_phi");
  min_phi   = configuration.getValueDouble(ptn,"Min_phi");
  max_phi   = configuration.getValueDouble(ptn,"Max_phi");
  nBins_eta = configuration.getValueInt(ptn,"nBins_eta");
  min_eta   = configuration.getValueDouble(ptn,"Min_eta");
  max_eta   = configuration.getValueDouble(ptn,"Max_eta");
  nBins_y   = configuration.getValueInt(ptn,"nBins_y");
  min_y     = configuration.getValueDouble(ptn,"Min_y");
  max_y     = configuration.getValueDouble(ptn,"Max_y");

  if (reportInfo(__FUNCTION__))
    {
    cout << endl;
    printValue("Single:Parent Task Name",    ptn);
    printValue("Single:Parent Path Name",    ppn);
    printValue("Single:Histo Base Name.",    bn);
    printValue("Single:nBins_pt",            int(nBins_pt));
    printValue("Single:Min_pt",              min_pt);
    printValue("Single:Max_pt",              max_pt);
    printValue("Single:nBins_phi",           int(nBins_phi));
    printValue("Single:Min_phi",             min_phi);
    printValue("Single:Max_phi",             max_phi);
    printValue("Single:nBins_eta",           int(nBins_eta));
    printValue("Single:Min_eta",             min_eta);
    printValue("Single:Max_eta.",            max_eta);
    printValue("Single:nBins_y",             int(nBins_y));
    printValue("Single:Min_y",               min_y);
    printValue("Single:Max_y",               max_y);
    printValue("Single:FillEta",             fillEta);
    printValue("Single:FillY",               fillY);
    printValue("Single:FillP2",              fillP2);
    }
//  printValue(" ParticleSingleDerivedHistos::createHistograms() h_n1_phi",createName(bn,"n1_phi"));
//  exit(1);
  h_n1_phi     = createHistogram(createName(bn,"n1_phi"), nBins_phi, min_phi, max_phi, "#varphi","#rho_{1}(#varphi)");
  if (fillP2)
    {
    h_spt_phi    = createHistogram(createName(bn,"sumpt1_phi"), nBins_phi, min_phi, max_phi, "#varphi","#sum p_{T}");
    h_pt_phi     = createHistogram(createName(bn,"pt_phi"),     nBins_phi, min_phi, max_phi, "#varphi","<p_{T}>");
    }

  if (fillEta)
    {
    h_n1_eta     = createHistogram(createName(bn,"n1_eta"),     nBins_eta, min_eta, max_eta, "#eta",   "#rho_{1}(#eta)");
    if (fillP2)
      {
      h_spt_eta     = createHistogram(createName(bn,"sumpt1_eta"),  nBins_eta, min_eta, max_eta, "#eta",   "#sum p_{T}");
      h_pt_eta     = createHistogram(createName(bn,"pt_eta"),     nBins_eta, min_eta, max_eta, "#eta",   "<p_{T}>");
      h_pt_phiEta  = createHistogram(createName(bn,"pt_phiEta"),  nBins_eta, min_eta, max_eta, nBins_phi, min_phi, max_phi, "#eta", "#varphi","N");
      }
    }
  if (fillY)
    {
    h_n1_y      = createHistogram(createName(bn,"n1_y"),     nBins_y, min_y,   max_y, "y",   "#rho_{1}(y)");
    if (fillP2)
      {
      h_spt_y     = createHistogram(createName(bn,"sumpt1_y"), nBins_y, min_y,   max_y, "y",   "#sum p_{T}");
      h_pt_y      = createHistogram(createName(bn,"pt_y"),     nBins_y, min_y,   max_y, "y",   "<p_{T}>");
      h_pt_phiY   = createHistogram(createName(bn,"pt_phiY"),  nBins_y, min_y,   max_y, nBins_phi, min_phi, max_phi, "y", "#varphi","N");
      }
    }
  if ( reportEnd(__FUNCTION__))  {/* no ops */};
}

//________________________________________________________________________
void ParticleSingleDerivedHistos::importHistograms(TFile & inputFile)
{
  if ( reportStart(__FUNCTION__))  {/* no ops */};
  const String & bn  = getName();
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  fillEta  = configuration.getValueBool(ptn,"FillEta");
  fillY    = configuration.getValueBool(ptn,"FillY");
  fillP2   = configuration.getValueBool(ptn,"FillP2");
  if (reportInfo(__FUNCTION__))
    {
    cout << endl;
    printValue("Single:FillEta",fillEta);
    printValue("Single:FillY",fillY);
    printValue("Single:FillP2",fillP2);
    }
  printValue("ParticleSingleDerivedHistos::importHistograms() h_n1_phi",createName(bn,"n1_phi"));
  exit(1);
  h_n1_phi  = importH1(inputFile,  createName(bn,"n1_phi"));
  h_spt_phi = importH1(inputFile,  createName(bn,"spt_phi"));
  h_pt_phi  = importH1(inputFile,  createName(bn,"pt_phi"));

  if (fillEta)
    {
    h_n1_eta     = importH1(inputFile,  createName(bn,"n1_eta"));
    if (fillP2)
      {
      h_spt_eta     = importH1(inputFile,  createName(bn,"spt_eta"));
      h_pt_eta      = importH1(inputFile,  createName(bn,"pt_eta"));
      h_pt_phiEta   = importH2(inputFile,  createName(bn,"pt_phiEta"));
      }
    }
  if (fillY)
    {
    h_n1_y     = importH1(inputFile,  createName(bn,"n1_y"));
    if (fillP2)
      {
      h_spt_y     = importH1(inputFile,  createName(bn,"spt_y"));
      h_pt_y      = importH1(inputFile,  createName(bn,"pt_y"));
      h_pt_phiY   = importH2(inputFile,  createName(bn,"pt_phiY"));
      }
    }
  if ( reportEnd(__FUNCTION__))  {/* no ops */};
}

//!
//! Calculates derived histograms. This is currently limited to pt averages vs eta and phi.
//!
void ParticleSingleDerivedHistos::calculateDerivedHistograms(ParticleSingleHistos & baseHistos)
{
  if (reportStart(__FUNCTION__)) {/* no ops */};
  String bn = getParentName();
  TH1* hTemp;

  if (baseHistos.h_n1_phiEta)
    {
    if (reportInfo(__FUNCTION__)) cout << "Compute h_n1_phi" << endl;
    hTemp = baseHistos.h_n1_phiEta->ProjectionY();
    h_n1_phi->Add(hTemp);
    delete hTemp;

    if (reportInfo(__FUNCTION__)) cout << "Compute h_n1_eta" << endl;
    hTemp = baseHistos.h_n1_phiEta->ProjectionX();
    h_n1_eta->Add(hTemp);
    delete hTemp;

    if (fillP2)
      {
      if (reportInfo(__FUNCTION__)) cout << "Compute sumpt1_phi" << endl;
      hTemp = baseHistos.h_spt_phiEta->ProjectionY();
      h_spt_phi->Add(hTemp);
      delete hTemp;

      if (reportInfo(__FUNCTION__)) cout << "Compute pt_phi" << endl;
      calculateAveragePt(h_spt_phi, h_n1_phi, h_pt_phi);

      if (reportInfo(__FUNCTION__)) cout << "Compute h_spt_eta" << endl;
      hTemp = baseHistos.h_spt_phiEta->ProjectionX();
      h_spt_eta->Add(hTemp);
      delete hTemp;

      if (reportInfo(__FUNCTION__)) cout << "Compute h_pt_eta" << endl;
      calculateAveragePt(h_spt_eta, h_n1_eta, h_pt_eta);
      }
    }

  if (baseHistos.h_n1_phiY)
    {
    if (reportInfo(__FUNCTION__)) cout << "Compute h_n1_phi" << endl;
    hTemp = baseHistos.h_n1_phiY->ProjectionY();
    h_n1_phi->Reset();
    h_n1_phi->Add(hTemp);
    delete hTemp;

    if (reportInfo(__FUNCTION__)) cout << "Compute h_n1_y" << endl;
    hTemp = baseHistos.h_n1_phiY->ProjectionX();
    h_n1_y->Add(hTemp);
    delete hTemp;

    if (fillP2)
      {
      if (baseHistos.h_spt_phiY)
        {
        if (reportInfo(__FUNCTION__)) cout << "Compute h_spt_phi" << endl;
        hTemp = baseHistos.h_spt_phiY->ProjectionY();
        h_spt_phi->Add(hTemp);
        delete hTemp;

        if (reportInfo(__FUNCTION__)) cout << "Compute h_pt_phi" << endl;
        calculateAveragePt(h_spt_phi, h_n1_phi, h_pt_phi);
        }

      if (reportInfo(__FUNCTION__)) cout << "Compute h_spt_y" << endl;
      hTemp = baseHistos.h_spt_phiY->ProjectionX();
      h_spt_y->Add(hTemp);
      delete hTemp;

      if (reportInfo(__FUNCTION__)) cout << "Compute h_pt_y" << endl;
      calculateAveragePt(h_spt_y, h_n1_y, h_pt_y);
      }
    }
  if ( reportEnd(__FUNCTION__))  {/* no ops */};
}

} // namespace cap

