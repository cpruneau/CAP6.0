/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Victor Gonzalez   
 * Copyright (C) 2016, Chun Shen
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
 *
 * *********************************************************************/
#include "ParticleType.hpp"
#include "SelectionGenerator.hpp"
#include "ParticleDb.hpp"
#include "PhysicsConstants.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticleType);

namespace CAP
{


//!
//! Default CTOR
//!
ParticleType::ParticleType()
:
index(0),
name(""),
title(""),
privateCode(0),
pdgCode(0),
mass(0.0),
charge(0.0),
width(0.0),
spin(0.0),
isospin(0.0),
isospin3(0.0),
strangeness(0),
charm(0),
bottom(0),
baryon(0),
nq(0),
naq(0),
ns(0),
nas(0),
nc(0),
nac(0),
nb(0),
nab(0),
nt(0),
nat(0),
leptonElectron(0),
leptonMuon(0),
leptonTau(0),
enabled(1),
decayEnabled(0),
antiParticleIndex(-1),
decayModes(),
decayRndmSelector(),
spinFactor(1.0),
isospinFactor(1.0),
statistics(-1.0),
beta(0.0)
{
  decayModes.clear();
}

//!
//! DTOR
//!
ParticleType::~ParticleType()
{   }

//!
//! COPY CTOR
//!
ParticleType::ParticleType(const ParticleType & source)
:
index(source.index),
name(source.name),
title(source.title),
privateCode(source.privateCode),
pdgCode(source.pdgCode),
mass(source.mass),
charge(source.charge),
width(source.width),
spin(source.spin),
isospin(source.isospin),
isospin3(source.isospin3),
strangeness(source.strangeness),
charm(source.charm),
bottom(source.bottom),
baryon(source.baryon),
nq(source.nq),
naq(source.naq),
ns(source.ns),
nas(source.nas),
nc(source.nc),
nac(source.nac),
nb(source.nb),
nab(source.nab),
nt(source.nt),
nat(source.nat),
leptonElectron(source.leptonElectron),
leptonMuon(source.leptonMuon),
leptonTau(source.leptonTau),
enabled(source.enabled),
decayEnabled(source.decayEnabled),
antiParticleIndex(-1),
decayModes(source.decayModes),
decayRndmSelector(source.decayRndmSelector),
spinFactor(source.spinFactor),
isospinFactor(source.isospinFactor),
statistics(source.statistics),
beta(source.beta)
{
// no ops
}

//!
//! Assignment operator. Copies all the properties of the source particle into this.
//!
ParticleType & ParticleType::operator=(const ParticleType & source)
{
  if (this!=&source)
    {
    index              =  source.index;
    name               =  source.name;
    title              =  source.title;
    privateCode        =  source.privateCode;
    pdgCode            =  source.pdgCode;
    mass               =  source.mass;
    charge             =  source.charge;
    width              =  source.width;
    spin               =  source.spin;
    isospin            =  source.isospin;
    isospin3           =  source.isospin3;
    strangeness       =  source.strangeness;
    charm           =  source.charm;
    bottom          =  source.bottom;
    baryon          =  source.baryon;
    nq                 =  source.nq;
    naq                =  source.naq;
    ns                 =  source.ns;
    nas                =  source.nas;
    nc                 =  source.nc;
    nac                =  source.nac;
    nb                 =  source.nb;
    nab                =  source.nab;
    nt                 =  source.nt;
    nat                =  source.nat;
    leptonElectron     =  source.leptonElectron;
    leptonMuon         =  source.leptonMuon;
    leptonTau          =  source.leptonTau;
    enabled            =  source.enabled;
    decayEnabled       =  source.decayEnabled;
    antiParticleIndex  =  source.antiParticleIndex;
    decayModes         =  source.decayModes;
    decayRndmSelector  =  source.decayRndmSelector;
    spinFactor         =  source.spinFactor;
    isospinFactor      =  source.isospinFactor;
    statistics         =  source.statistics;
    beta               =  source.beta;
    }
  return *this;
}


bool ParticleType::isStable() const
{
  return decayModes.size()<1;
}

bool ParticleType::isDisabled() const {  return !enabled; }

bool ParticleType::isEnabled() const {  return enabled; }

int ParticleType::getNDecayModes() const
{
  return decayModes.size();
}

bool  ParticleType::hasDecayModes() const
{
  return decayModes.size()>0;
}

ParticleDecayMode & ParticleType::getDecayMode(int index)
{
  return decayModes[index];
}

//!
//! Add a decay mode to this particle type based on the given branching fraction (branching ratio) and the given array of children
//! @param branchingRatio : fraction of all decays of this particle type into the given children
//! @param children : array of particle type index corresponding to the particle type this particle decays into.
//!
void ParticleType::addDecayMode(double branchingRatio,
                                std::vector<int> children)
{
  if (branchingRatio<0.0  || branchingRatio>1.0)
    {
    throw ParticleDecayException("branchingRatio<0.0||branchingRatio>1.0",__FUNCTION__);
    }
  if (children.size()<2)
    {
    throw ParticleDecayException("Decay mode with no or only one particle",__FUNCTION__);
    }
  ParticleDecayMode decayMode;
  decayMode.setBranchingRatio(branchingRatio);
  for (int k=0; k<int(children.size()); k++) decayMode.addChild(children[k]);
  addDecayMode(decayMode);
}

//!
//! Add a decay mode to this particle type based on the given decayModel object
//! @param decayMode : decay mode object encapsulating the branching fraction and the list of particle types this particle decays into.
//!
//!  When a decay is added to a particle type, that type is automatically
//!  considered unstable and decay enabled. Both flags can however be altered
//!  as needed.
//!
void ParticleType::addDecayMode(ParticleDecayMode &decayMode)
{
  decayModes.push_back(decayMode);
  decayEnabled = true;
}

void ParticleType::setupDecayGenerator()
{
  int nDecayModes = decayModes.size();
  if (nDecayModes<1)
    throw ParticleDecayException("nDecayModes<1",__FUNCTION__);
  vector<double> decayBranchingRatios;
  for (int k=0; k<nDecayModes; k++)
  {
  decayBranchingRatios.push_back(decayModes[k].getBranchingRatio());
  }
  decayRndmSelector.initializeWith(decayBranchingRatios);
}

//!
//! Generate decay mode of  this particle
//!
ParticleDecayMode & ParticleType::generateDecayMode()
{
  int index = decayRndmSelector.generate();
  if (index<0 || index>= int(decayModes.size()))
    {
    printString("ParticleType::generateDecayMode() index<0 ");
    printValue("Bad index",index);
    printValue("particle name",name);
    printValue("decayEnabled",decayEnabled);
    printValue("width",width);
    printValue("n modes",decayModes.size());
    throw ParticleDecayException("Bad index",__FUNCTION__);
    }
  return decayModes[index];
}

void ParticleType::setStatistics(double _spin)
{
  statistics = (_spin - static_cast<int>(_spin) ) < 0.01 ? -1.0 : +1.0;
}

void ParticleType::setIndex(int _index)
{
  index = _index;
}

//!
//! Set the name of this particle.
//!
void ParticleType::setName(const String & _name)  { name    = _name;}

//!
//! Set the 'title'' of this particle.
//!
void ParticleType::setTitle(const String & _title){ title   = _title;}

void ParticleType::setSpin(double _spin)
{
  spin       = _spin;
  spinFactor = 2.0*spin + 1;
  setStatistics(spin);
}

void ParticleType::setIsospin(double _isospin)
{
  isospin       = _isospin;
  isospinFactor = 2.0*isospin + 1;
}

void ParticleType::setIsospin3(double _isospin3)
{
  isospin3 = _isospin3;
}


//!
//! Set the PDG code of this particle.
//!
void ParticleType::setPdgCode(int value)
{
  pdgCode = value;
}

//!
//! Set the private (user defined) code of this particle.
//!
void ParticleType::setPrivateCode(int value)
{
  privateCode = value;
}

//!
//! Set the mass of this particle in GeV/c^2.
//!
void ParticleType::setMass(double _mass)
{
  mass = _mass;
}

//!
//! Set the width of this particle in GeV/c^2.
//!
void ParticleType::setWidth(double _width)
{
  width = _width;
}

void ParticleType::setLifeTime(double _lifeTime)
{
  width = (_lifeTime<1.0E37) ? (6.582E-25/_lifeTime) : 0.0;
}


//!
//! Set the electron lepton value of this particle
//!
void ParticleType::setLeptonElectron(int value)
{ leptonElectron = value;}

//!
//! Set the muon lepton value of this particle
//!
void ParticleType::setLeptonMuon(int value)
{ leptonMuon   = value;}

//!
//! Set the tau lepton value of this particle
//!
void ParticleType::setLeptonTau(int value)
{ leptonTau    = value;}

//!
//! Set the spin dengeneracy factor  of this particle.
//!
void ParticleType::setSpinFactor(double _gSpin)
{
  spin  = (_gSpin-1.0)/2.0;
}

//!
//! Set the isospin dengeneracy factor  of this particle.
//!
void ParticleType::setIsoSpinFactor(double _gIsospin)
{
  isospin  = (_gIsospin-1.0)/2.0;
}

void  ParticleType::setNumberQ(int  value) { nq  = value;}
void  ParticleType::setNumberAQ(int value) { naq = value;}
void  ParticleType::setNumberS(int  value) { ns  = value;}
void  ParticleType::setNumberAS(int value) { nas = value;}
void  ParticleType::setNumberC(int  value) { nc  = value;}
void  ParticleType::setNumberAC(int value) { nac = value;}
void  ParticleType::setNumberB(int  value) { nb  = value;}
void  ParticleType::setNumberAB(int value) { nab = value;}
void  ParticleType::setNumberT(int  value) { nt = value;}
void  ParticleType::setNumberAT(int value) { nat = value;}

void  ParticleType::setAntiParticleIndex(int value)
{
  antiParticleIndex = value;
}


//!
//! Return true if this particle is a Higgs  boson
//!
bool ParticleType::isHiggs() const           { return 0; }

//!
//! Return true if this particle is a fermion
//!
bool ParticleType::isFermion() const
{
  return fabs(spin - static_cast<int>(spin)) > 0.01;
}

//!
//! Return true if this particle is a  boson
//!
bool ParticleType::isBoson() const
{
  return fabs(spin - static_cast<int>(spin)) < 0.01;
}

//!
//! Return true if this particle is a gluon
//!
bool ParticleType::isGluon() const           { return pdgCode==21; }

//!
//! Return true if this particle is a photon
//!
bool ParticleType::isPhoton() const          { return pdgCode==22; }

//!
//! Return true if this particle is a Z boson
//!
bool ParticleType::isZBoson() const          { return pdgCode==23; }

//!
//! Return true if this particle is a W boson
//!
bool ParticleType::isWBoson() const          { return pdgCode==24; }

//!
//! Return true if this particle is a Higgs gauge boson
//!
bool ParticleType::isHiggsBoson() const      { return pdgCode==25; }

//!
//! Return true if this particle is a gauge boson
//!
bool ParticleType::isGaugeBoson() const      { return pdgCode==21 || pdgCode==22 || pdgCode==23 || pdgCode==24; }

//!
//! Return true if this particle is a lepton
//!
bool ParticleType::isLepton() const          { return leptonElectron!=0 || leptonMuon!=0 || leptonTau!=0; }

//!
//! Return true if this particle is an electron
//!
bool ParticleType::isElectron() const        { return pdgCode== 11; }

//!
//! Return true if this particle is a positron
//!
bool ParticleType::isPositron() const        { return pdgCode== 11; }

//!
//! Return true if this particle is a muon lepton
//!
bool ParticleType::isMuon() const            { return pdgCode==13;  }

//!
//! Return true if this particle is an anti muon lepton
//!
bool  ParticleType::isAntiMuon() const        { return pdgCode==13; }

//!
//! Return true if this particle is a  tau lepton
//!
bool ParticleType::isTau() const             { return pdgCode==15; }

//!
//! Return true if this particle is an anti tau lepton
//!
bool ParticleType::isAntiTau() const         { return pdgCode==-15; }

//!
//! Return true if this particle is a meson
//!
bool ParticleType::isMeson() const
{
  return (nq == naq ||
          nq == nas ||
          nq == nac ||
          nq == nab ||
          nq == nat ||

          ns == naq ||
          ns == nas ||
          ns == nac ||
          ns == nab ||
          ns == nat ||

          nc == naq ||
          nc == nas ||
          nc == nac ||
          nc == nab ||
          nc == nat ||

          nb == naq ||
          nb == nas ||
          nb == nac ||
          nb == nab ||
          nb == nat ||

          nt == naq ||
          nt == nas ||
          nt == nac ||
          nt == nab ||
          nt == nat);
}

//!
//! Return true if this particle is a  pion
//!
bool ParticleType::isPion() const            { return pdgCode ==211 || pdgCode==111 || pdgCode==-211;  }

//!
//! Return true if this particle is a positive pion
//!
bool ParticleType::isPionP() const           { return pdgCode ==211;   }

//!
//! Return true if this particle is a negative pion
//!
bool ParticleType::isPionM() const           { return pdgCode ==-211;  }

//!
//! Return true if this particle is a neutral pion
//!
bool ParticleType::isPion0() const           { return pdgCode ==111;   }

//!
//! Return true if this particle is a  kaon
//!
bool ParticleType::isKaon() const            { return pdgCode ==321 || pdgCode==-321 || pdgCode==311 || pdgCode==-311 || pdgCode==130 || pdgCode==310; }

//!
//! Return true if this particle is a positive kaon.
//!
bool ParticleType::isKaonP() const           { return pdgCode ==321; }

//!
//! Return true if this particle is a negative kaon
//!
bool ParticleType::isKaonM() const           { return pdgCode ==-321; }

//!
//! Return true if this particle is kaon (neutral)
//!
bool ParticleType::isKaon0() const           { return pdgCode ==311; }

//!
//! Return true if this particle is anti-kaon (neutral)
//!
bool ParticleType::isKaon0Bar() const        { return pdgCode ==-311; }

//!
//! Return true if this particle is kaon short.
//!
bool ParticleType::isKaon0S() const          { return pdgCode ==310; }

//!
//! Return true if this particle is kaon long.
//!
bool ParticleType::isKaon0L() const          { return pdgCode ==130; }

//!
//! Return true if this particle is electrically charged (non zero net charge).
//!
bool ParticleType::isCharged() const         { return charge!=0;     }

//!
//! Return true if this particle is electrically neutral (zero net charge).
//!
bool ParticleType::isNeutral() const         { return charge==0;     }


//!
//! Return true if this particle is a baryon (i.e., has a non zero baryon number)
//!
bool ParticleType::isBaryon() const
{
  return getBaryonNumber()!=0;
}

//!
//! Return true if this particle is a positive  baryon
//!
bool ParticleType::isBaryonPlus() const
{
  return getBaryonNumber()>0;
}

//!
//! Return true if this particle is a negative baryon
//!
bool ParticleType::isBaryonMinus() const
{
  return getBaryonNumber()<0;
}

//!
//! Return true if this particle is a hadron
//!
bool ParticleType::isHadron() const
{
  return isBaryon() || isMeson();
}

//!
//! Return true if this particle has a non-zero net strangeness
//!
bool ParticleType::isStrange() const
{
  return (ns>0 || nas>0) && ns!=nas;
}

//!
//! Return true if this particle has a positive strangeness
//!
bool ParticleType::isStrangePlus()  const
{
  return ns>0 && nas==0;
}

//!
//! Return true if this particle has a negative strangeness
//!
bool ParticleType::isStrangeMinus() const
{
  return nas>0 && ns==0;
}
//!
//! Return true if this particle contains a charm quark.
//!
bool ParticleType::isCharm() const
{
  return (nc>0 || nac>0) && nc!=nac;
}

//!
//! Return true if this particle has a positive net charm
//!
bool ParticleType::isCharmPlus()  const
{
  return nc>0 && nac==0;
}

//!
//! Return true if this particle has a negative net charm
//!
bool ParticleType::isCharmMinus()  const
{
  return nac>0 && nc==0;
}

//!
//! Return true if this particle has a net non zero bottomness
//!
bool ParticleType::isBottom() const
{
  return (nb>0 || nab>0) && nb!=nab;
}

//!
//! Return true if this particle has a positive net bottomness
//!
bool ParticleType::isBottomPlus() const
{
  return nb>0 && nab==0;
}

//!
//! Return true if this particle has a negative net bottomness
//!
bool ParticleType::isBottomMinus() const
{
  return nab>0 && nb==0;
}

//!
//! Return true if this particle has a non zero net topness
//!
bool ParticleType::isTop() const
{
  return (nt>0 || nat>0) && nt!=nat;
}

//!
//! Return true if this particle has a positive net topness
//!
bool ParticleType::isTopPlus() const
{
  return nt>0 && nat==0;
}

//!
//! Return true if this particle has a negative net topness
//!
bool ParticleType::isTopMinus() const
{
  return nat>0 && nt==0;
}

//!
//! Return true if this particle is a quark
//!
bool ParticleType::isQuark() const
{
  return pdgCode==1 || pdgCode==2 || pdgCode==3 || pdgCode==4 || pdgCode==5 || pdgCode==6;
}

//!
//! Return true if this particle is a proton
//!
bool ParticleType::isProton() const
{ return pdgCode==2212;  }

//!
//! Return true if this particle is a neutron
//!
bool ParticleType::isNeutron() const
{ return pdgCode==2112;  }

//!
//! Return true if this particle is a nucleon (i.e., either a proton or neutron)
//!
bool ParticleType::isNucleon() const
{ return pdgCode==2212 || pdgCode==2112;  }

//!
//! Return true if this particle is an anti-proton
//!
bool ParticleType::isAntiProton() const
{ return pdgCode==-2212;  }

//!
//! Return true if this particle is a anti-neutron
//!
bool ParticleType::isAntiNeutron() const
{ return pdgCode==-2112;  }

//!
//! Return true if this particle is an anti-nucleon
//!
bool ParticleType::isAntiNucleon() const
{ return pdgCode==-2212 || pdgCode==-2112;  }

//!
//! Return true if this particle is a decay mode
//!
bool ParticleType::isDecay() const
{ return pdgCode==1000001;  }

//!
//! Return true if this particle is an interaction vextex
//!
bool ParticleType::isInteraction() const
{ return pdgCode==1000010;  }

//!
//! Return true if this particle is a proton-proton interaction
//!
bool ParticleType::isPPInteraction() const
{ return pdgCode==1000011;  }

//!
//! Return true if this particle is a proton-neutron interaction
//!
bool ParticleType::isPNInteraction() const
{ return pdgCode==1000012;  }

//!
//! Return true if this particle is a neutron-neutron interaction
//!
bool ParticleType::isNNInteraction() const
{ return pdgCode==1000013;  }

//!
//! Return true if this particle is a Lambda baryon
//!
bool ParticleType::isLambda() const
{ return pdgCode== 3122;    }

//!
//! Return true if this particle is a anti-lambda baryon
//!
bool ParticleType::isAntiLambda() const
{ return pdgCode==-3122;    }

//!
//! Return true if this particle is a Sigma+ baryon
//!
bool ParticleType::isSigmaP() const
{ return pdgCode== 3222;    }

//!
//! Return true if this particle is a Sigma0 baryon
//!
bool ParticleType::isSigma0() const
{ return pdgCode== 3212;    }

//!
//! Return true if this particle is a Sigma- baryon
//!
bool ParticleType::isSigmaM() const
{ return pdgCode== 3112;    }

//!
//! Return true if this particle is a anti-Sigma+ (anti)baryon
//!
bool ParticleType::isAntiSigmaP() const
{ return pdgCode== -3222;   }

//!
//! Return true if this particle is a anti-Sigma0 (anti)baryon
//!
bool ParticleType::isAntiSigma0() const
{ return pdgCode== -3212;   }

//!
//! Return true if this particle is a anti-Sigma- (anti)baryon
//!
bool ParticleType::isAntiSigmaM() const
{ return pdgCode== -3112;   }

//!
//! Return true if this particle is a Xi0 baryon (Neutral Cascade)
//!
bool ParticleType::isXi0() const
{ return pdgCode== 3322;    }

//!
//! Return true if this particle is a Xi- baryon (Negative Cascade)
//!
bool ParticleType::isXiM() const
{ return pdgCode== 3312;    }

//!
//! Return true if this particle is a anti-Xi- baryon (Neutral anti-cascade)
//!
bool ParticleType::isAntiXi0() const
{ return pdgCode== -3322;    }

//!
//! Return true if this particle is a Xi- baryon (Negative Cascade)
//!
bool ParticleType::isAntiXiM() const
{ return pdgCode== -3312;    }

//!
//! Return true if this particle is an Omega- baryon
//!
bool ParticleType::isOmegaM() const
{ return pdgCode== 3334;     }

//!
//! Return true if this particle is an anti-Omega- (anti)baryon
//!
bool ParticleType::isAntiOmegaM() const
{ return pdgCode== -3334;    }


//!
//! Print the properties of this particle on the given stream and return a reference to that stream.
//!
ostream & ParticleType::print(ostream & os, int style, int size)
{
  switch (style)
    {
      case 0:
      {
      //scientific
      os <<  fixed << setw(10) << setprecision(8) << pdgCode;         // Monte-Carlo number according PDG
      os <<  setw(size) << name;   // ParticleType name
      os <<  setw(size) << title;   // ParticleType title
      os <<  scientific << setw(size) << setprecision(4) <<  mass;
      os <<  scientific << setw(size) << setprecision(4) <<  width;
      os <<  fixed << setw(9) << setprecision(2) <<  charge;
      os <<  fixed << setw(9) << setprecision(2) <<  spin;
      os <<  fixed << setw(9) << setprecision(2) <<  isospin;
      os <<  fixed << setw(9) << setprecision(2) <<  isospin3;
      os <<  fixed << setw(5) << setprecision(1) <<  nq;
      os <<  fixed << setw(5) << setprecision(1) <<  naq;
      os <<  fixed << setw(5) << setprecision(1) <<  ns;
      os <<  fixed << setw(5) << setprecision(1) <<  nas;
      os <<  fixed << setw(5) << setprecision(1) <<  nc;
      os <<  fixed << setw(5) << setprecision(1) <<  nac;
      os <<  fixed << setw(5) << setprecision(1) <<  nb;
      os <<  fixed << setw(5) << setprecision(1) <<  nab;
      os <<  fixed << setw(5) << setprecision(1) <<  nt;
      os <<  fixed << setw(5) << setprecision(1) <<  nat;
      os <<  fixed << setw(5) << setprecision(1) <<  leptonElectron;
      os <<  fixed << setw(5) << setprecision(1) <<  leptonMuon;
      os <<  fixed << setw(5) << setprecision(1) <<  leptonTau;
      os <<  fixed << setw(5) << setprecision(1) <<  decayEnabled;
      os <<  fixed << setw(5) << setprecision(1) <<  enabled;
      os <<  endl;
      for (int k=0;k<int(decayModes.size());k++)
        {
        decayModes[k].print(os);
        }
      break;
      }
      case 1:
      {
      printCR(os);
      printValue("Name",name);
      printValue("title",title);   // ParticleType title
      printValue("pdgCode",pdgCode);         // Monte-Carlo number according PDG
      printValue("mass",mass);
      printValue("width",width);
      printValue("charge",charge);
      printValue("spin",spin);
      printValue("isospin",isospin);
      printValue("isospin3",isospin3);
      printValue("nq",nq);
      printValue("naq",naq);
      printValue("ns",ns);
      printValue("nas",nas);
      printValue("nc",nc);
      printValue("nac",nac);
      printValue("nb",nb);
      printValue("nab",nab);
      printValue("nt",nt);
      printValue("nat",nat);
      printValue("leptonElectron",leptonElectron);
      printValue("leptonMuon",leptonMuon);
      printValue("leptonTau",leptonTau);
      printValue("decayEnabled",decayEnabled);
      printValue("enabled",enabled);
      printLine(os);
      break;
      }
    }
  return os;
}

//!
//! Print the decay properties of this particle on the given stream and return a reference to that stream.
//!
ostream & ParticleType::printDecays(ostream & os, int style, int size)
{
  switch (style)
    {
      case 0:
      {
      os <<  setw(size) << name;   // ParticleType name
      os <<  setw(size) << title;   // ParticleType title
      os <<  scientific << setw(size) << setprecision(4) <<  mass;
      os <<  scientific << setw(size) << setprecision(4) <<  width;
      os <<  fixed << setw(size) << setprecision(2) <<  charge;
      os <<  fixed << setw(size) << setprecision(2) <<  spin;
      unsigned int nModes = decayModes.size();
      for (unsigned int k=0;k<nModes;k++)
        {
        if (pdgCode != decayModes[0].getChildPdgCode(0))
          {
          os << "      " << k << " Br:" << scientific << setw(size) << setprecision(4) << (100.0*decayModes[k].getBranchingRatio()) << " to ";
          unsigned int nChildren = decayModes[k].getNChildren();
          for (unsigned int iChild=0; iChild<nChildren; iChild++)
            {
            ParticleType & type = decayModes[k].getChildType(iChild);
            os << type.getTitle();
            if (iChild < nChildren-1)  os << "+";
            }
          os << endl;
          }
        }
      }
      case 1:
      {
      ///
      }
    }
  return os;
}

//!
//!  Set the enabled flag to true. Particle types  are considered
//!  "enabled" when created. They can be disabled if not required or of
//!  interest in a particular simulation.
//!
void   ParticleType::enable() { enabled = true; }

//!
//!  Set the enabled flag to false. Particle types  are considered
//!  "enabled" when created. They can be disabled if not required or of
//!  interest in a particular simulation.
//!
void   ParticleType::disable() { enabled = false; }

bool ParticleType::isDecayEnabled()  const
{
  return decayEnabled;
}

bool ParticleType::isDecayDisabled() const
{
  return !decayEnabled;
}

void ParticleType::enableDecay()
{
  if (decayModes.size()>0)
    decayEnabled = true;
}

void ParticleType::disableDecay()
{
  decayEnabled = false;
}

std::vector<ParticleDecayMode> & ParticleType::getDecayModes()
{
  return decayModes; //!<Array of decay modes
}

//!
//! Get atomic number
//!
double ParticleType::getZ() const
{
  return getAtomicNumber();
}

//!
//! Get atomic number
//! Must contain at least one proton or antiproton
//!
double ParticleType::getAtomicNumber() const
{
  if (isBaryon())
    return fabs(charge);
  else
    return 0;
}

//!
//! Get mass number
//!
double ParticleType::getA() const
{
  return getMassNumber();
}

//!
//! Get mass number
//!  Must contain at least one proton or antiproton
//!
double ParticleType::getMassNumber() const
{
  return fabs(getBaryonNumber()) && charge!=0;
}

//!
//! Get neutron number
//!
double ParticleType::getN() const
{
  double z = getAtomicNumber();
  double a = getMassNumber();
  return a-z;
}

//!
//! Get neutron number
//!
double ParticleType::getNeutronNumber() const
{
  double z = getAtomicNumber();
  double a = getMassNumber();
  return a-z;
}

double ParticleType::getBeta() const
{
  return beta;
}

double ParticleType::getDeformationBeta() const
{
  return beta;
}

void ParticleType::setZ(double _atomicNumber)
{
  charge = _atomicNumber;
}

void ParticleType::setAtomicNumber(double _atomicNumber)
{
  charge = _atomicNumber;
}

void ParticleType::setA(double _massNumber)
{
  baryon = _massNumber;
}

void ParticleType::setMassNumber(double _massNumber)
{
  baryon = _massNumber;
}

void ParticleType::setS(double _strangenessNumber)
{
  strangeness = _strangenessNumber;
}


void ParticleType::setStrangeness(double _strangenessNumber)
{
  strangeness = _strangenessNumber;
}


void ParticleType::setBeta(double _deformationBeta)
{
  beta = _deformationBeta;
}

void ParticleType::setDeformationBeta(double _deformationBeta)
{
  beta = _deformationBeta;
}

//!
//! Get the binding  of this GlauberNucleus  in GeV/c^2.
//!
double ParticleType::getBindingEnergy() const
{
  double z = fabs(charge);
  double a = getMassNumber();
  double bindingE = mass - fabs(z*Physics::protonMass() + (a-z)*Physics::neutronMass());
  return bindingE;
}

//!
//! Return true if the object is a GlauberNucleus
//! i.e., has at least one proton.
//!
//bool ParticleType::isGlauberNucleus() const
//{
//  double a = getMassNumber();
//  return a>0 && charge>0;
//}
//
//bool ParticleType::isAntiGlauberNucleus() const
//{
//  double a = getMassNumber();
//  return a<0 && charge<0;
//}


ParticleType * ParticleType::createNucleus(const String & name)
{
  ParticleType * type = new ParticleType;
  if (name.EqualTo("Proton"))
    {
    type->setName("Proton");
    type->setTitle("p");
    type->setAtomicNumber(1);
    type->setMassNumber(1);
    type->setMass(Physics::protonMass() );
    type->setSpin(0.5);
    type->setLifeTime(Physics::protonLifetime_SI());
    type->setBeta(0.0);

    }
  else if (name.EqualTo("Neutron"))
    {
    type->setName("Neutron");
    type->setTitle("n");
    type->setAtomicNumber(0);
    type->setMassNumber(1);
    type->setMass(Physics::neutronMass() );
    type->setSpin(0.5);
    type->setLifeTime(887.7); // seconds
    type->setBeta(0.0);

    }
  else if (name.EqualTo("Deuteron"))
    {
    type->setName("Deuteron");
    type->setTitle("d");
    type->setAtomicNumber(1);
    type->setMassNumber(2);
    type->setMass(Physics::deuteronMass() );
    type->setSpin(1.0);
    type->setLifeTime(Physics::protonLifetime_SI()); // seconds
    type->setBeta(0.0);
    }
  else if (name.EqualTo("Triton"))
    {
    type->setName("Triton");
    type->setTitle("t");
    type->setAtomicNumber(1);
    type->setMassNumber(3);
    type->setMass(Physics::tritonMass() );
    type->setSpin(0.5);
    type->setLifeTime(12.32*Physics::yearToSecond()); // seconds
    type->setBeta(0.0);
    }
  else if (name.EqualTo("Helium3"))
    {
    type->setName("Helium3");
    type->setTitle("3He");
    type->setAtomicNumber(2);
    type->setMassNumber(3);
    type->setMass(Physics::helium3Mass() );
    type->setSpin(0.5);
    type->setLifeTime(Physics::protonLifetime_SI()); // seconds
    type->setBeta(0.0);
    }
  else if (name.EqualTo("Helium4"))
    {
    type->setName("Helium4");
    type->setTitle("4He");
    type->setAtomicNumber(2);
    type->setMassNumber(4);
    type->setMass(Physics::helium4Mass() );
    type->setSpin(0.0);
    type->setLifeTime(Physics::protonLifetime_SI()); // seconds
    type->setBeta(0.0);
    }
  else if (name.EqualTo("Gold197"))
    {
    type->setName("Gold197");
    type->setTitle("197Au");
    type->setAtomicNumber(79);
    type->setMassNumber(100);
    type->setMass(Physics::au197Mass() );
    type->setSpin(1.5);
    type->setLifeTime(Physics::protonLifetime_SI()); // seconds
    type->setBeta(0.0);
    }
  else if (name.EqualTo("Lead208"))
    {
    type->setName("Lead208");
    type->setTitle("208Pb");
    type->setAtomicNumber(82);
    type->setMassNumber(126);
    type->setMass(Physics::pb208Mass() );
    type->setSpin(1.5);
    type->setLifeTime(Physics::protonLifetime_SI()); // seconds
    type->setBeta(0.0);
    }
  if (name.EqualTo("AntiProton"))
    {
    type->setName("AntiProton");
    type->setTitle("#bar{p}");
    type->setAtomicNumber(-1);
    type->setMassNumber(-1);
    type->setMass(Physics::protonMass() );
    type->setSpin(0.5);
    type->setLifeTime(1.0E34);
    type->setBeta(0.0);

    }
  else if (name.EqualTo("AntiNeutron"))
    {
    type->setName("AntiNeutron");
    type->setTitle("#bar{n}");
    type->setAtomicNumber(0);
    type->setMassNumber(-1);
    type->setMass(Physics::neutronMass() );
    type->setSpin(0.5);
    type->setLifeTime(887.7); // seconds
    type->setBeta(0.0);

    }
  else if (name.EqualTo("AntiDeuteron"))
    {
    type->setName("AntiDeuteron");
    type->setTitle("#bar{d}");
    type->setAtomicNumber(-1);
    type->setMassNumber(-2);
    type->setMass(Physics::deuteronMass() );
    type->setSpin(1.0);
    type->setLifeTime(Physics::protonLifetime_SI()); // seconds
    type->setBeta(0.0);
    }
  else if (name.EqualTo("AntiTriton"))
    {
    type->setName("AntiTriton");
    type->setTitle("#bar{t}");
    type->setAtomicNumber(-1);
    type->setMassNumber(-3);
    type->setMass(Physics::tritonMass() );
    type->setSpin(0.5);
    type->setLifeTime(12.32*Physics::yearToSecond()); // seconds
    type->setBeta(0.0);
    }
  else if (name.EqualTo("AntiHelium3"))
    {
    type->setName("AntiHelium3");
    type->setTitle("3#bar{He}");
    type->setAtomicNumber(-2);
    type->setMassNumber(-3);
    type->setMass(Physics::helium3Mass() );
    type->setSpin(0.5);
    type->setLifeTime(Physics::protonLifetime_SI()); // seconds
    type->setBeta(0.0);
    }
  else if (name.EqualTo("AntiHelium4"))
    {
    type->setName("AntiHelium4");
    type->setTitle("4#bar{He}");
    type->setAtomicNumber(-2);
    type->setMassNumber(-4);
    type->setMass(Physics::helium4Mass() );
    type->setSpin(0.0);
    type->setLifeTime(Physics::protonLifetime_SI()); // seconds
    type->setBeta(0.0);
    }
  return type;
}

ParticleType * ParticleType::protonType   = ParticleType::createNucleus("Proton");
ParticleType * ParticleType::neutronType  = ParticleType::createNucleus("Neutron");
ParticleType * ParticleType::deuteronType = ParticleType::createNucleus("Deuteron");
ParticleType * ParticleType::tritonType   = ParticleType::createNucleus("Triton");
ParticleType * ParticleType::he3Type      = ParticleType::createNucleus("Helium3");
ParticleType * ParticleType::he4Type      = ParticleType::createNucleus("Helium4");
ParticleType * ParticleType::auType       = ParticleType::createNucleus("Gold");
ParticleType * ParticleType::pbType       = ParticleType::createNucleus("Lead");

ParticleType * ParticleType::antiProtonType   = ParticleType::createNucleus("AntiProton");
ParticleType * ParticleType::antiNeutronType  = ParticleType::createNucleus("AntiNeutron");
ParticleType * ParticleType::antiDeuteronType = ParticleType::createNucleus("AntiDeuteron");
ParticleType * ParticleType::antiTritonType   = ParticleType::createNucleus("AntiTriton");
ParticleType * ParticleType::antiHe3Type      = ParticleType::createNucleus("AntiHelium3");
ParticleType * ParticleType::antiHe4Type      = ParticleType::createNucleus("AntiHelium4");

} // namespace CAP
