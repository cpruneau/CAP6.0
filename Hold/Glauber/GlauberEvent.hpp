/*
 Adapted from runGlauber by C. Pruneau

 $Id: runglauber.C 186 2019-01-13 17:33:43Z loizides $
 -------------------------------------------------------------------------------------
 Latest documentation: https://arxiv.org/abs/1710.07098
 -------------------------------------------------------------------------------------
 To run the code, you need to have the ROOT (http://root.cern.ch/drupal/)
 environment. On the root prompt, then enter
 root [0] gSystem->Load("libMathMore")
 root [1] .L runglauber_X.Y.C+
 (where X.Y denotes the version number).
 If you do not have libMathMore comment out "#define HAVE_MATHMORE" below.
 See the documentation for more information.
 -------------------------------------------------------------------------------------
 v3.2: Incorporates changes from v2.7
 -------------------------------------------------------------------------------------
 v3.1:
  Fixes related to spherical nuclei, as well as consistent set of reweighted profiles 
  for Cu, Au and Xe, see https://arxiv.org/abs/1710.07098v2
 -------------------------------------------------------------------------------------
 v3.0:
  Major update to include separate profile for protons and neutrons, placement of nucleon 
  dof on lattice, as well as reweighted profiles for recentering, 
  see https://arxiv.org/abs/1710.07098v1
 -------------------------------------------------------------------------------------
 v2.7: 
  New macro "runAndOutputLemonTree" for IP-Jazma input (1808.01276), as well as nucleon 
  configurations for He4, C, and O from wavefunction calculations, clarified use of useHulthen
  for deuteron, harmonic oscillator param for O, and new mode to use GlauberGribov also 
  in AA (enable with setCalcAAGG)
 -------------------------------------------------------------------------------------
 v2.6:
  Includes runAndCalcDens macro, as well as definition for Al, and fixes beta4 for Si2,
  see https://arxiv.org/abs/1408.2549v8
 -------------------------------------------------------------------------------------
 v2.5:
  Include core/corona determination in nParticipants, and if requested for area from mc and eccentricity,
  as well as various Xe parameterizations including deformation,
  see https://arxiv.org/abs/1408.2549v7
 -------------------------------------------------------------------------------------
 v2.4: 
  Minor update to include Xenon and fix of the GlauberMC::Draw function,
  see https://arxiv.org/abs/1408.2549v4
 -------------------------------------------------------------------------------------
 v2.3: 
  Small bugfixes, see https://arxiv.org/abs/1408.2549v3
 -------------------------------------------------------------------------------------
 v2.2:
  Minor update to provide higher harmonic eccentricities up to n=5, and the average
  nucleon--nucleon impact parameter (bNN) in tree output. 
 -------------------------------------------------------------------------------------
 v2.1: 
  Minor update to include more proton pdfs, see https://arxiv.org/abs/1408.2549v2
 -------------------------------------------------------------------------------------
 v2.0: 
  First major update with inclusion of Tritium, Helium-3, and Uranium, as well as the 
  treatment of deformed nuclei and Glauber-Gribov fluctuations of the proton in p+A 
  collisions, see https://arxiv.org/abs/1408.2549v1
 -------------------------------------------------------------------------------------
 v1.1: 
  First public release of the PHOBOS MC Glauber, see https://arxiv.org/abs/0805.4411
 -------------------------------------------------------------------------------------

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#ifndef CAP__GlauberTask
#define CAP__GlauberTask
#include <TObject.h>
namespace CAP
{

class Moments2D
{
public:

  double sum;
  double xSum;
  double ySum;
  double x2Sum;
  double y2Sum;
  double xySum;

  double meanX;
  double meanY;
  double meanX2;
  double meanY2;
  double meanXY;
  double varX;
  double varY;
  double varXY;

  Moments2D();
  Moments2D(const Moments2D & source);
  Moments2D operator=(const Moments2D & source);
  ~Moments2D();
  void fill(double x, double y, double weight);
  void calculateMoments();
};

class GlauberEventStat
{
  public:
  GlauberEventStat();
  GlauberEventStat(const GlauberEventStat & event);
  GlauberEventStat & operator=const GlauberEventStat & event);
  virtual ~GlauberEventStat() {}
  virtual void print(std::ofstream & output, int option);

    Float_t nParticipants;  //Number of wounded (participating) nucleons in current event
    Float_t nCollisions;    //Number of binary collisions in current event
    Float_t nHardCollisions; //Number of hard collisions in current event (based on fHardFrac)
    Float_t B;           //[0,0,16] Impact parameter (b)
    Float_t BNN;         //[0,0,16] Average NN impact parameter
    Float_t nCollisions_pp;     //nCollisions pp
    Float_t nCollisions_pn;     //nCollisions pn
    Float_t nCollisions_nn;     //nCollisions nn
  Float_t nParticipantsA;      //Number of wounded (participating) nucleons in Nucleus A
  Float_t nParticipantsB;      //Number of wounded (participating) nucleons in Nucleus B
  Float_t nParticipants0;      //Number of singly-wounded (participating) nucleons

  Moments2D systemMoments; //wounded nucleons

  Float_t AreaW;       //[0,0,16] area defined by width of participants
    Float_t Psi1;        //[0,0,16] psi1
    Float_t Ecc1;        //[0,0,16] eps1
    Float_t Psi2;        //[0,0,16] psi2
    Float_t Ecc2;        //[0,0,16] eps2
    Float_t Psi3;        //[0,0,16] psi3
    Float_t Ecc3;        //[0,0,16] eps3
    Float_t Psi4;        //[0,0,16] psi4
    Float_t Ecc4;        //[0,0,16] eps4
    Float_t Psi5;        //[0,0,16] psi5
    Float_t Ecc5;        //[0,0,16] eps5
    Float_t AreaA;       //[0,0,16] area defined by "and" of participants
    Float_t AreaO;       //[0,0,16] area defined by "or" of participants
    Float_t X0;          //[0,0,16] production point in x
    Float_t Y0;          //[0,0,16] production point in y
    Float_t Phi0;        //[0,0,16] direction in phi
    Float_t Length;      //[0,0,16] length in phi0

  } // order must match that given in vars below
    ClassDef(GlauberMC::GlauberEventStat, 1)
};





#endif



