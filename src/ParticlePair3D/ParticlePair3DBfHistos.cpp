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

#include "ParticleSingleHistos.hpp"
#include "ParticleSingleDerivedHistos.hpp"
#include "ParticlePairHistos.hpp"
#include "HistogramGroup.hpp"
#include "ParticlePairExceptions.hpp"
#include "ParticlePair3DBfHistos.hpp"
#include "RootHelpers.hpp"
#include "PrintHelpers.hpp"
#include "TRandom.h"

ClassImp(CAP::ParticlePair3DBfHistos);

namespace CAP
{

ParticlePair3DBfHistos::ParticlePair3DBfHistos()
:
HistogramGroup(),
nBins_Qinv(0),
min_Qinv(0),
max_Qinv(0),
nBins_DeltaPs(0),
min_DeltaPs(0),
max_DeltaPs(0),
nBins_DeltaPo(0),
min_DeltaPo(0),
max_DeltaPo(0),
nBins_DeltaPl(0),
min_DeltaPl(0),
max_DeltaPl(0),
nEvents(0),
//n1n1_DeltaPs_name(""),
//n1n1_DeltaPo_name(""),
//n1n1_DeltaPl_name(""),
//n2_DeltaPs_name(""),
//n2_DeltaPo_name(""),
//n2_DeltaPl_name(""),
//c2_DeltaPs_name(""),
//c2_DeltaPo_name(""),
//c2_DeltaPl_name(""),
//r2_DeltaPs_name(""),
//r2_DeltaPo_name(""),
//r2_DeltaPl_name(""),
h_B12_Qinv(nullptr),
h_B12_DeltaPs(nullptr),
h_B12_DeltaPo(nullptr),
h_B12_DeltaPl(nullptr),
h_B21_Qinv(nullptr),
h_B21_DeltaPs(nullptr),
h_B21_DeltaPo(nullptr),
h_B21_DeltaPl(nullptr),
h_Bs_Qinv(nullptr),
h_Bs_DeltaPs(nullptr),
h_Bs_DeltaPo(nullptr),
h_Bs_DeltaPl(nullptr),
mass1(0.13957039),
mass2(0.13957039)
{
  appendClassName("ParticlePair3DBfHistos");
}

ParticlePair3DBfHistos::ParticlePair3DBfHistos(const ParticlePair3DBfHistos & group)
: HistogramGroup(group),
nBins_Qinv(group.nBins_Qinv),
min_Qinv(group.min_Qinv),
max_Qinv(group.max_Qinv),
nBins_DeltaPs(group.nBins_DeltaPs),
min_DeltaPs(group.min_DeltaPs),
max_DeltaPs(group.max_DeltaPs),
nBins_DeltaPo(group.nBins_DeltaPo),
min_DeltaPo(group.min_DeltaPo),
max_DeltaPo(group.max_DeltaPo),
nBins_DeltaPl(group.nBins_DeltaPl),
min_DeltaPl(group.min_DeltaPl),
max_DeltaPl(group.max_DeltaPl),
nEvents(group.nEvents),

h_B12_Qinv(nullptr),
h_B12_DeltaPs(nullptr),
h_B12_DeltaPo(nullptr),
h_B12_DeltaPl(nullptr),

h_B21_Qinv(nullptr),
h_B21_DeltaPs(nullptr),
h_B21_DeltaPo(nullptr),
h_B21_DeltaPl(nullptr),

h_Bs_Qinv(nullptr),
h_Bs_DeltaPs(nullptr),
h_Bs_DeltaPo(nullptr),
h_Bs_DeltaPl(nullptr),
mass1(group.mass1),
mass2(group.mass2)
{

}

ParticlePair3DBfHistos & ParticlePair3DBfHistos::operator=(const ParticlePair3DBfHistos & group)
{
  if (this!=&group)
    {
    HistogramGroup::operator=(group);
    nBins_Qinv     = group.nBins_Qinv;
    min_Qinv       = group.min_Qinv;
    max_Qinv       = group.max_Qinv;
    nBins_DeltaPs  = group.nBins_DeltaPs;
    min_DeltaPs    = group.min_DeltaPs;
    max_DeltaPs    = group.max_DeltaPs;
    nBins_DeltaPo  = group.nBins_DeltaPo;
    min_DeltaPo    = group.min_DeltaPo;
    max_DeltaPo    = group.max_DeltaPo;
    nBins_DeltaPl  = group.nBins_DeltaPl;
    min_DeltaPl    = group.min_DeltaPl;
    max_DeltaPl    = group.max_DeltaPl;
    nEvents        = group.nEvents;
//    n1n1_DeltaPs_name  = group.n1n1_DeltaPs_name;
//    n1n1_DeltaPo_name  = group.n1n1_DeltaPo_name;
//    n1n1_DeltaPl_name  = group.n1n1_DeltaPl_name;
//    n2_DeltaPs_name    = group.n2_DeltaPs_name;
//    n2_DeltaPo_name    = group.n2_DeltaPo_name;
//    n2_DeltaPl_name    = group.n2_DeltaPl_name;
//    c2_DeltaPs_name    = group.c2_DeltaPs_name;
//    c2_DeltaPo_name    = group.c2_DeltaPo_name;
//    c2_DeltaPl_name    = group.c2_DeltaPl_name;
//    r2_DeltaPs_name    = group.r2_DeltaPs_name;
//    r2_DeltaPo_name    = group.r2_DeltaPo_name;
//    r2_DeltaPl_name    = group.r2_DeltaPl_name;
    // implementation incomplete...
    h_B12_Qinv     = nullptr;
    h_B12_DeltaPs  = nullptr;
    h_B12_DeltaPo  = nullptr;
    h_B12_DeltaPl  = nullptr;
    h_B21_Qinv     = nullptr;
    h_B21_DeltaPs  = nullptr;
    h_B21_DeltaPo  = nullptr;
    h_B21_DeltaPl  = nullptr;
    h_Bs_Qinv      = nullptr;
    h_Bs_DeltaPs   = nullptr;
    h_Bs_DeltaPo   = nullptr;
    h_Bs_DeltaPl   = nullptr;
    mass1          = group.mass1;
    mass2          = group.mass2;
    }
  return *this;
}


void ParticlePair3DBfHistos::createHistograms()
{
  if (reportStart(__FUNCTION__)) { /* noops*/ };
  const String & bn  = getName();
  const String & ptn = getParentName();
//  printValue("ParticlePair3DBfHistos::createHistograms() bn",  bn );
//  printValue("ParticlePair3DBfHistos::createHistograms() ptn", ptn );
  nBins_Qinv     = configuration.getValueInt(ptn,   "nBins_Qinv");
  min_Qinv       = configuration.getValueDouble(ptn,"Min_Qinv");
  max_Qinv       = configuration.getValueDouble(ptn,"Max_Qinv");
  nBins_DeltaPs  = configuration.getValueInt(ptn,   "nBins_DeltaPs");
  min_DeltaPs    = configuration.getValueDouble(ptn,"Min_DeltaPs");
  max_DeltaPs    = configuration.getValueDouble(ptn,"Max_DeltaPs");
  nBins_DeltaPo  = configuration.getValueInt(ptn,   "nBins_DeltaPo");
  min_DeltaPo    = configuration.getValueDouble(ptn,"Min_DeltaPo");
  max_DeltaPo    = configuration.getValueDouble(ptn,"Max_DeltaPo");
  nBins_DeltaPl  = configuration.getValueInt(ptn,   "nBins_DeltaPl");
  min_DeltaPl    = configuration.getValueDouble(ptn,"Min_DeltaPl");
  max_DeltaPl    = configuration.getValueDouble(ptn,"Max_DeltaPl");

  h_B12_Qinv      = createHistogram(createName(bn,"B12_Qinv"),    nBins_Qinv,   min_Qinv,    max_Qinv,    "Q_{inv}","B_{12}", 2);
  h_B12_DeltaPs   = createHistogram(createName(bn,"B12_DeltaPs"), nBins_DeltaPs,min_DeltaPs, max_DeltaPs, "p_{s}","B_{12}");
  h_B12_DeltaPo   = createHistogram(createName(bn,"B12_DeltaPo"), nBins_DeltaPo,min_DeltaPo, max_DeltaPo, "p_{o}","B_{12}");
  h_B12_DeltaPl   = createHistogram(createName(bn,"B12_DeltaPl"), nBins_DeltaPl,min_DeltaPl, max_DeltaPl, "p_{l}","B_{12}");
  h_B21_Qinv      = createHistogram(createName(bn,"B21_Qinv"),    nBins_Qinv,   min_Qinv,    max_Qinv,    "Q_{inv}","B_{21}", 2);
  h_B21_DeltaPs   = createHistogram(createName(bn,"B21_DeltaPs"), nBins_DeltaPs,min_DeltaPs, max_DeltaPs, "p_{s}","B_{21}");
  h_B21_DeltaPo   = createHistogram(createName(bn,"B21_DeltaPo"), nBins_DeltaPo,min_DeltaPo, max_DeltaPo, "p_{o}","B_{21}");
  h_B21_DeltaPl   = createHistogram(createName(bn,"B21_DeltaPl"), nBins_DeltaPl,min_DeltaPl, max_DeltaPl, "p_{l}","B_{21}");
  h_Bs_Qinv       = createHistogram(createName(bn,"Bs_Qinv"),     nBins_Qinv,   min_Qinv,    max_Qinv,    "Q_{inv}","B_{s}", 2);
  h_Bs_DeltaPs    = createHistogram(createName(bn,"Bs_DeltaPs"),  nBins_DeltaPs,min_DeltaPs, max_DeltaPs, "p_{s}","B_{s}");
  h_Bs_DeltaPo    = createHistogram(createName(bn,"Bs_DeltaPo"),  nBins_DeltaPo,min_DeltaPo, max_DeltaPo, "p_{o}","B_{s}");
  h_Bs_DeltaPl    = createHistogram(createName(bn,"Bs_DeltaPl"),  nBins_DeltaPl,min_DeltaPl, max_DeltaPl, "p_{l}","B_{s1}");
}

void ParticlePair3DBfHistos::importHistograms(TFile & inputFile)
{
  const String & bn  = getName();
  const String & ptn = getParentName();

  h_B12_Qinv    = loadH1(inputFile,createName(bn,"B12_Qinv"));
  h_B12_DeltaPs = loadH1(inputFile,createName(bn,"B12_DeltaPs"));
  h_B12_DeltaPo = loadH1(inputFile,createName(bn,"B12_DeltaPo"));
  h_B12_DeltaPl = loadH1(inputFile,createName(bn,"B12_DeltaPl"));

  h_B21_Qinv    = loadH1(inputFile,createName(bn,"B21_Qinv"));
  h_B21_DeltaPs = loadH1(inputFile,createName(bn,"B21_DeltaPs"));
  h_B21_DeltaPo = loadH1(inputFile,createName(bn,"B21_DeltaPo"));
  h_B21_DeltaPl = loadH1(inputFile,createName(bn,"B21_DeltaPl"));

  h_Bs_Qinv    = loadH1(inputFile,createName(bn,"Bs_Qinv"));
  h_Bs_DeltaPs = loadH1(inputFile,createName(bn,"Bs_DeltaPs"));
  h_Bs_DeltaPo = loadH1(inputFile,createName(bn,"Bs_DeltaPo"));
  h_Bs_DeltaPl = loadH1(inputFile,createName(bn,"Bs_DeltaPl"));
}

//!
//! HistogramGroup from ParticlePair3DBfHistos must be normalized "per event" before calling this function
//!
void ParticlePair3DBfHistos::calculateBfHistograms(ParticlePair3DDerivedHistos & pair21B,
                                                   ParticlePair3DDerivedHistos & pair2B1B,
                                                   ParticlePair3DDerivedHistos & pair2B1,
                                                   ParticlePair3DDerivedHistos & pair21)
{
//  printValue("pair21B.h_c2_Qinv", pair21B.h_c2_Qinv->GetXaxis()->GetNbins());
//  printValue("pair2B1B.h_c2_Qinv",pair21B.h_c2_Qinv->GetXaxis()->GetNbins());
//  printValue("this.h_B12_Qinv",   h_B12_Qinv->GetXaxis()->GetNbins());

  h_B12_Qinv   ->Add(pair21B.h_a12_Qinv,   pair2B1B.h_a12_Qinv,   1.0,-1.0);
  h_B12_DeltaPs->Add(pair21B.h_a12_DeltaPs,pair2B1B.h_a12_DeltaPs,1.0,-1.0);
  h_B12_DeltaPo->Add(pair21B.h_a12_DeltaPo,pair2B1B.h_a12_DeltaPo,1.0,-1.0);
  h_B12_DeltaPl->Add(pair21B.h_a12_DeltaPl,pair2B1B.h_a12_DeltaPl,1.0,-1.0);

  h_B21_Qinv   ->Add(pair2B1.h_a21_Qinv,   pair21.h_a21_Qinv,   1.0,-1.0);
  h_B21_DeltaPs->Add(pair2B1.h_a21_DeltaPs,pair21.h_a21_DeltaPs,1.0,-1.0);
  h_B21_DeltaPo->Add(pair2B1.h_a21_DeltaPo,pair21.h_a21_DeltaPo,1.0,-1.0);
  h_B21_DeltaPl->Add(pair2B1.h_a21_DeltaPl,pair21.h_a21_DeltaPl,1.0,-1.0);

  h_Bs_Qinv    ->Add(h_B12_Qinv,    h_B21_Qinv,      0.5, 0.5);
  h_Bs_DeltaPs ->Add(h_B12_DeltaPs, h_B12_DeltaPs,   0.5, 0.5);
  h_Bs_DeltaPo ->Add(h_B12_DeltaPo, h_B12_DeltaPo,   0.5, 0.5);
  h_Bs_DeltaPl ->Add(h_B12_DeltaPl, h_B12_DeltaPl,   0.5, 0.5);
}


//! set the masses to be used in the calculation of q_inv
//! The default value set at construction are the pion+ mass.
//!
void ParticlePair3DBfHistos::setMasses(double m1, double m2)
{
  mass1 = m1;
  mass2 = m2;
}


} //  namespace CAP
