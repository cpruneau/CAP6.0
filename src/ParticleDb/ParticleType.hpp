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
#ifndef CAP__ParticleType
#define CAP__ParticleType
#include "Aliases.hpp"
#include "SelectionGenerator.hpp"
#include "ParticleDecayMode.hpp"
#include "PhysicsConstants.hpp"

using namespace std;
using namespace CAP::Physics;

namespace CAP
{

class ParticleDecayMode;

//!
//!This class defines the notion of particle type used in CAP.  Virtually all elementary particle properties
//!are represented and stored. Property values are stored and read from a particle property file. Property values are based on
//!the particle data book maintained by the particle data group (PDG).
//!
class ParticleType
{
protected:

  int    index;          //!<Sequential index on import
  String name;           //!<ParticleType name: e.g., pip
  String title;          //!<ParticleType title: e.g., #pi^{+}
  int    privateCode;    //!<Code used in this package only (convenience)
  int    pdgCode;        //!<Monte-Carlo number according PDG
  double mass;           //!<ParticleType mass (GeV)
  double charge;         //!<charge
  double width;          //!<decay width
  double spin;           //!<spin
  double isospin;        //!<isospin
  double isospin3;       //!<isospin 3rd component
  int    strangeness;   //!<net strangeness
  int    charm;       //!<net charm
  int    bottom;      //!<net beauty/bottomness
  int    baryon;      //!<net baryon
  int    nq;             //!<number of light quarks (u,d)
  int    naq;            //!<number of anti-light quarks (u-bar, d-bar)
  int    ns;             //!<number of strange quarks (s)
  int    nas;            //!<number of anti-strange quarks (s-bar)
  int    nc;             //!<number of charm quarks (c)
  int    nac;            //!<number of anti-charm quarks (c-bar)
  int    nb;             //!<number of bottom quarks (b)
  int    nab;            //!<number of anti-bottom quarks (b-bar)
  int    nt;             //!<number of top  quarks (t)
  int    nat;            //!<number of anti-top quarks (t-bar)
  int    leptonElectron; //!<Electron lepton number
  int    leptonMuon;     //!<Muon lepton number
  int    leptonTau;      //!<Tau lepton number
  //bool   stable;         //!<defines whether this ParticleType is stable
  bool   enabled;        //!<particle declared not used
  bool   decayEnabled;   //!<particle decays are turned off externally
  int    antiParticleIndex; //!< index (in the active DB) of the antiparticle of this particle.
  std::vector<ParticleDecayMode> decayModes; //!<Array of decay modes
  SelectionGenerator decayRndmSelector;

  double spinFactor;     //! spin degeneracy
  double isospinFactor;  //! isospin degeneracy
  double statistics;     //! fermion or boson
  double beta;           //! GlauberNucleus deformation parameter

public:

  ParticleType();
  ParticleType(const ParticleType & source);
  virtual ~ParticleType();
  ParticleType & operator=(const ParticleType & source);
  void setupDecayGenerator();
  void generateDecay(int &n, int * pid);

  int getIndex() const
  {
  return index;
  }

  //!
  //! Get the name of the particle
  //!
  String getName() const
  {
  return name;
  }

  //!
  //! Get the title  of the particle
  //!
  String getTitle() const
  {
  return title;
  }


  //!
  //! Get the PDG code of the antiparticle of this particle.
  //!
  int getAntiParticlePdgCode() const
  {
  return (baryon==0 &&
          charge==0 &&
          strangeness==0 &&
          charm==0)?pdgCode :-pdgCode;
  }

  //!
  //! Get the PDG code of this particle.
  //!
  int getPdgCode() const
  {
  return pdgCode;
  }

  //!
  //! Get the private  code of this particle (user defined).
  //!
  int getPrivateCode() const
  {
  return privateCode;
  }



  //!
  //! Get the mass of this particle in GeV/c^2.
  //!
  inline double getMass() const
  {
  return mass;  // GeV
  }

  //!
  //! Get the mass of this particle in kilograms.
  //!
  inline double getMassInKg() const
  {
  return mass*1.79E-27;
  }


  //!
  //! Get the decay width of this particle in GeV/c^2.
  //!
  inline double getWidth() const
  {
  return width;
  }

  //!
  //! Get the spin of this particle in h-bar units
  //!
  inline double getSpin() const
  {
  return spin; // hbar units
  }

  //!
  //! Get the mean life time of this particle in seconds.
  //! hBar is in GeV.s;  width is GeV.
  //! life time is in seconds.
  //! 
  inline double getLifeTime() const
  {
  return (width>0.0) ? (hBar()/width) : protonLifetime_SI();
  }


  //!
  //! Get the baryon number of this particle.
  //!
  inline double getBaryonNumber() const
  {
  return baryon;
  }

  //!
  //! Set the net baryon of this particle.
  //!
  inline void setBaryonNumber(int _baryon)
  {
  baryon = _baryon;
  }

  //!
  //! Get the electric charge of this particle.
  //!
  inline double getCharge() const
  {
  return charge;
  }

  //!
  //! Set the electric charge of this particle.
  //!
  void setCharge(int value)
  { charge  = value;}


  //!
  //! Get the net strangeness of this particle.
  //!
  inline double getStrangeness() const
  {
  return strangeness;
  }

  //!
  //! Set the net strangeness of this particle.
  //!
  inline void setStrangeness(int _strangeness)
  {
    strangeness = _strangeness;
  }


  //!
  //! Get the net charm of this particle.
  //!
  inline double getCharm() const
  {
  return charm;
  }

  //!
  //! Set the net charm of this particle.
  //!
  inline void setCharm(int _charm)
  {
  charm = _charm;
  }


  //!
  //! Get the net bottomness  of this particle.
  //!
  inline double getBottomNumber() const
  {
  return bottom;
  }

  //!
  //! Set the net Bottom of this particle.
  //!
  inline void setBottomNumber(int _bottom)
  {
  bottom = _bottom;
  }



  //!
  //! Get the net topness  of this particle.
  //!
  inline double getNetTop() const
  {
  return (nt-nat);
  }


  //!
  //! Get the lepton number (electron)  of this particle.
  //!
  inline double getLeptonElectron() const
  {
  return leptonElectron;
  }

  //!
  //! Get the lepton number (muon)  of this particle.
  //!
  inline double getLeptonMuon() const
  {
  return leptonMuon;
  }

  //!
  //! Get the lepton number (tau)  of this particle.
  //!
  inline double getLeptonTau() const
  {
  return leptonTau;
  }

  //!
  //! Get the number of light quarks (u,d) composing this particle
  //!
  inline int getNumberQ()    const
  { return nq;  }

  //!
  //! Get the number of light anti-quarks (u-bar,d-bar) composing this particle
  //!
  inline int getNumberAQ()   const
  { return naq; }

  //!
  //! Get the number of strange quarks (s) composing this particle
  //!
  inline int getNumberS()    const
  { return ns;  }

  //!
  //! Get the number of anti-strange quarks (s-bar) composing this particle
  //!
  inline int getNumberAS()   const
  { return nas; }

  //!
  //! Get the number of charm quarks (c) composing this particle
  //!
  inline int getNumberC()    const
  { return nc;  }

  //!
  //! Get the number of anti-charm quarks (c-bar) composing this particle
  //!
  inline int getNumberAC()   const
  { return nac; }

  //!
  //! Get the number of bottom quarks (b) composing this particle
  //!
  inline int getNumberB()    const
  { return nb;  }

  //!
  //! Get the number of anti-bottom quarks (b-bar) composing this particle
  //!
  inline int getNumberAB()    const
  { return nab; }

  //!
  //! Get the number of bottom quarks (b) composing this particle
  //!
  inline int getNumberT()    const
  { return nt;  }

  //!
  //! Get the number of anti-bottom quarks (b-bar) composing this particle
  //!
  inline int getNumberAT()    const
  { return nat; }



  //!
  //! Get the spin degeneracy factor of this particle.
  //!
  inline double getSpinFactor() const
  {
  return spinFactor;
  }

  //!
  //! Get the isopsin  of this particle.
  //!
  inline double getIsospin()   const
  {
  return isospin;
  }

  //!
  //! Get the 3rd component of the isopsin  of this particle.
  //!
  inline double getIsospin3()  const
  {
  return isospin3;
  }

  //!
  //! Get the isospin degeneracy factor of this particle.
  //!
  inline double getIsoSpinFactor() const
  {
    return isospinFactor;
  }

  //!
  //! Get the statistics of this particle used in the expression of the particle density (+ or -).
  //!
  inline double getStatistics() const
  {
  return statistics;
  }


  inline int getAntiParticleIndex() const
  {
  return antiParticleIndex;
  }


  void setIndex(int _index);
  void setName(const String & _name);
  void setTitle(const String & _title);
  void setSpin(double _spin);
  void setIsospin(double _isospin);
  void setIsospin3(double _isospdecaymodein3);
  void setStatistics(double _spin);
  void setPdgCode(int value);
  void setPrivateCode(int value);
  void setMass(double value);
  void setWidth(double value);
  void setLifeTime(double value);
  void setLeptonElectron(int value);
  void setLeptonMuon(int value);
  void setLeptonTau(int value);
  void setSpinFactor(double _gSpin);
  void setIsoSpinFactor(double _gIsospin);
  void setNumberQ(int  value);
  void setNumberAQ(int value);
  void setNumberS(int  value);
  void setNumberAS(int value);
  void setNumberC(int  value);
  void setNumberAC(int value);
  void setNumberB(int  value);
  void setNumberAB(int value);
  void setNumberT(int  value);
  void setNumberAT(int value);
  void setAntiParticleIndex(int value);

  bool isHiggs() const;
  bool isFermion() const;
  bool isBoson() const;
  bool isGluon() const;
  bool isPhoton() const;
  bool isZBoson() const;
  bool isWBoson() const;
  bool isHiggsBoson() const;
  bool isGaugeBoson() const;
  bool isLepton() const;
  bool isElectron() const;
  bool isPositron() const;
  bool isMuon() const;
  bool isAntiMuon() const;
  bool isTau() const;
  bool isAntiTau() const;
  bool isMeson() const;
  bool isPion() const;
  bool isPionP() const;
  bool isPionM() const;
  bool isPion0() const;
  bool isKaon() const;
  bool isKaonP() const;
  bool isKaonM() const;
  bool isKaon0() const;
  bool isKaon0Bar() const;
  bool isKaon0S() const;
  bool isKaon0L() const;
  bool isCharged() const;
  bool isNeutral() const;

  bool isBaryon() const;
  bool isBaryonPlus() const;
  bool isBaryonMinus() const;
  bool isHadron() const;
  bool isStrange() const;
  bool isStrangePlus() const;
  bool isStrangeMinus() const;
  bool isCharm() const;
  bool isCharmPlus() const;
  bool isCharmMinus() const;
  bool isBottom() const;
  bool isBottomPlus() const;
  bool isBottomMinus() const;
  bool isTop()  const;
  bool isTopPlus()  const;
  bool isTopMinus()   const;
  bool isQuark() const;
  bool isProton() const;
  bool isNeutron() const;
  bool isNucleon() const;
  bool isAntiProton() const;
  bool isAntiNeutron() const;
  bool isAntiNucleon() const;
  bool isDecay() const;
  bool isInteraction() const;
  bool isPPInteraction() const;
  bool isPNInteraction() const;
  bool isNNInteraction() const;
  bool isLambda() const;
  bool isAntiLambda() const;
  bool isSigmaP() const;
  bool isSigma0() const;
  bool isSigmaM() const;
  bool isAntiSigmaP() const;
  bool isAntiSigma0() const;
  bool isAntiSigmaM() const;
  bool isXi0() const;
  bool isXiM() const;
  bool isAntiXi0() const;
  bool isAntiXiM() const;
  bool isOmegaM() const;
  bool isAntiOmegaM() const;

  //!
  //! Return true if this particle is 'stable'
  //!
  bool isStable() const;

  //!
  //! Return true if this particle has been declared disabled.
  //!
  bool isDisabled() const;
  bool isEnabled() const;
  void enable();
  void disable();

  double getZ() const;
  double getAtomicNumber() const;
  double getA() const;
  double getMassNumber() const;
  double getN() const;
  double getNeutronNumber() const;
  double getBeta() const;
  double getDeformationBeta() const;

  void setZ(double _atomicNumber);
  void setAtomicNumber(double _atomicNumber);
  void setA(double _massNumber);
  void setMassNumber(double _massNumber);
  void setS(double _strangenessNumber);
  void setStrangeness(double _strangenessNumber);

  void setBeta(double _deformationBeta);
  void setDeformationBeta(double _deformationBeta);
  double getBindingEnergy() const;

//  bool isGlauberNucleus() const;
//  bool isAntiGlauberNucleus() const;



  void addDecayMode(double branchingRatio, std::vector<int> children);
  void addDecayMode(ParticleDecayMode &decayMode);

  //!
  //! Return the number of distinct decay modes of this particle
  //!
  int getNDecayModes() const;
  bool hasDecayModes() const;
  bool isDecayEnabled()  const;
  bool isDecayDisabled() const;
  void enableDecay();
  void disableDecay();



  ParticleDecayMode & getDecayMode(int index);
  ParticleDecayMode & generateDecayMode();
  std::vector<ParticleDecayMode> & getDecayModes();
  ostream & print(ostream & os, int style=0, int size=12);
  ostream & printDecays(ostream & os, int style=0, int size=12);

  static  ParticleType * createNucleus(const String & name);
  static  ParticleType * protonType;      //!< Pointer to a singleton object coding a proton type
  static  ParticleType * neutronType;     //!< Pointer to a singleton object coding a neutron type
  static  ParticleType * deuteronType;    //!< Pointer to a singleton object coding a deuteron type
  static  ParticleType * tritonType;      //!< Pointer to a singleton object coding a triton type
  static  ParticleType * he3Type;         //!< Pointer to a singleton object coding a 3He GlauberNucleus type
  static  ParticleType * he4Type;         //!< Pointer to a singleton object coding a 4He GlauberNucleus type
  static  ParticleType * auType;          //!< Pointer to a singleton object coding an 197Au (gold) GlauberNucleus type
  static  ParticleType * pbType;          //!< Pointer to a singleton object coding a 208Pb  (lead) GlauberNucleus type

  static  ParticleType * antiProtonType;      //!< Pointer to a singleton object coding a proton type
  static  ParticleType * antiNeutronType;     //!< Pointer to a singleton object coding a neutron type
  static  ParticleType * antiDeuteronType;    //!< Pointer to a singleton object coding a deuteron type
  static  ParticleType * antiTritonType;      //!< Pointer to a singleton object coding a triton type
  static  ParticleType * antiHe3Type;         //!< Pointer to a singleton object coding a 3He GlauberNucleus type
  static  ParticleType * antiHe4Type;

  ClassDef(ParticleType,0)
};

}
#endif  

