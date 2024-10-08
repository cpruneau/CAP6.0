/********************************************************************************
 *                                                                              *
 *             THERMINATOR 2: THERampl heavy-IoN generATOR 2                     *
 *                                                                              *
 * Version:                                                                     *
 *      Release, 2.0.3, 1 February 2011                                         *
 *                                                                              *
 * Authors:                                                                     *
 *      Mikolaj Chojnacki   (Mikolaj.Chojnacki@ifj.edu.pl)                      *
 *      Adam Kisiel         (kisiel@if.pw.edu.pl)                               *
 *      Wojciech Broniowski (Wojciech.Broniowski@ifj.edu.pl)                    *
 *      Wojciech Florkowski (Wojciech.Florkowski@ifj.edu.pl)                    *
 *                                                                              *
 * Project homepage:                                                            *
 *      http://therminator2.ifj.edu.pl/                                         *
 *                                                                              *
 * For the detailed description of the program and further references           *
 * to the description of the model please refer to                              *
 * http://arxiv.org/abs/1102.0273                                               *
 *                                                                              *
 * This code can be freely used and redistributed. However if you decide to     *
 * ampke modifications to the code, please, inform the authors.                  *
 * Any publication of results obtained using this code must include the         *
 * reference to arXiv:1102.0273 and the published version of it, when           *
 * available.                                                                   *
 *                                                                              *
 ********************************************************************************/
#include "Configuration.hpp"
#include "XmlParser.hpp"
#include "XmlVectorField.hpp"
#include "Hypersurface_Lhyquid3D.hpp"
#include "PrintHelpers.hpp"

using namespace CAP::Math;
using CAP::Configuration;
using CAP::XmlParser;
using CAP::XmlVectorField;
using CAP::TaskException;

ClassImp(Hypersurface_Lhyquid3D);


Hypersurface_Lhyquid3D::Hypersurface_Lhyquid3D(Thermodynamics * _thermodynamics)
:
Hypersurface(_thermodynamics),
Ux(0.),
Uy(0.),
RapF(0.),
mDistanceDTheta(nullptr),
mFluidUx(nullptr),
mFluidUy(nullptr),
mFluidRapidity(nullptr)
{  }

double Hypersurface_Lhyquid3D::getDSigmaP(double aMt, double aPt, double aPhiP, double aRapP)
{
  return
  Dhs * Dhs * sin(Theta) *
  ( Tau / lambda * (
                    dDdZeta * cos(zeta)							* (-aMt * cos(zeta) * cosh(aRapP - rapidityS) + aPt * sin(zeta) * cos(phiS - aPhiP))
                    + (Dhs * sin(Theta) - dDdTheta * cos(Theta)) * cos(zeta) * sin(Theta)	* ( aMt * sin(zeta) * cosh(aRapP - rapidityS) + aPt * cos(zeta) * cos(phiS - aPhiP))
                    + dDdPhi * aPt * sin(phiS - aPhiP)
                    )
   +   (Dhs * cos(Theta) + dDdTheta * sin(Theta)) 		 * sin(Theta)	*   aMt * cos(zeta) * sinh(aRapP - rapidityS)
   );
}

double Hypersurface_Lhyquid3D::getPdotU(double aMt, double aPt, double aPhiP, double aRapP)
{
  return sqrt(1 + Ux * Ux + Uy * Uy) * aMt * cosh(RapF - aRapP) - aPt * (Ux * cos(aPhiP) + Uy * sin(aPhiP));
}

double Hypersurface_Lhyquid3D::getHyperCubeSpatialVolume()  const
{
  double xRange = mDistance->getXMax() - mDistance->getXMin();
  double yRange = mDistance->getYMax() - mDistance->getYMin();
  double zRange = mDistance->getZMax() - mDistance->getZMin();
  return  xRange*yRange*zRange;
}

void Hypersurface_Lhyquid3D::setPositionOnHypersurface(LorentzVector & position)
{
  zeta    = mDistance->getXMin() + (mDistance->getXMax() - mDistance->getXMin()) * gRandom->Rndm();
  phiS    = mDistance->getYMin() + (mDistance->getYMax() - mDistance->getYMin()) * gRandom->Rndm();
  Theta   = mDistance->getZMin() + (mDistance->getZMax() - mDistance->getZMin()) * gRandom->Rndm();
  Dhs     = mDistance      ->interpolate(zeta, phiS, Theta);
  dDdZeta = mDistanceDZeta ->interpolate(zeta, phiS, Theta);
  dDdPhi  = mDistanceDPhi  ->interpolate(zeta, phiS, Theta);
  dDdTheta= mDistanceDTheta->interpolate(zeta, phiS, Theta);
  Ux	    = mFluidUx       ->interpolate(zeta, phiS, Theta);
  Uy	    = mFluidUy       ->interpolate(zeta, phiS, Theta);
  RapF	  = mFluidRapidity ->interpolate(zeta, phiS, Theta);
  Tau     = tauI + Dhs * sin(Theta) * sin(zeta);
  rho     = Dhs * sin(Theta) * cos(zeta);
  rapidityS	  = Dhs * cos(Theta) / lambda;
  position.SetXYZT(rho*cos(phiS),rho*sin(phiS),Tau*sinh(rapidityS),Tau*cosh(rapidityS));
}

void Hypersurface_Lhyquid3D::readFromXmlFile(const char * _inputPath,
                                             const char * _inputFileName)
{
  double temperature, muB, muI, muS, muC;

  if (reportInfo(__FUNCTION__))
    {
    CAP::printCR();
    CAP::printValue("Reading from xml file named",_inputFileName);
    CAP::printValue("from path named",_inputPath);
    }
  XmlParser parser;
  XmlVectorField xmlDoc;
  parser.read(xmlDoc,_inputPath,_inputFileName);
  try
  {
  xmlDoc.getXmlTag("PARAMETER","name","Tau_i");
  tauI            = xmlDoc.getXmlContent().Atof() / CAP::Physics::hBarC();       // [GeV^-1]
  xmlDoc.getXmlTag("PARAMETER","name","Temperature");
  temperature     = xmlDoc.getXmlContent().Atof() * 0.001;  // [GeV]
  xmlDoc.getXmlTag("PARAMETER","name","Mu_B");
  muB             = xmlDoc.getXmlContent().Atof() * 0.001;
  xmlDoc.getXmlTag("PARAMETER","name","Mu_I");
  muI             = xmlDoc.getXmlContent().Atof() * 0.001;
  xmlDoc.getXmlTag("PARAMETER","name","Mu_S");
  muS             = xmlDoc.getXmlContent().Atof() * 0.001;
  xmlDoc.getXmlTag("PARAMETER","name","Mu_C");
  muC             = xmlDoc.getXmlContent().Atof() * 0.001;        // [GeV]
  xmlDoc.getXmlTag("PARAMETER","name","colliding_energy");
  collidingEnergy = xmlDoc.getXmlContent().Atof();    // [GeV]
  xmlDoc.getXmlTag("PARAMETER","name","centrality_min");
  centralityMin   = xmlDoc.getXmlContent().Atof();      // [%]
  xmlDoc.getXmlTag("PARAMETER","name","centrality_ampx");
  centralityMax   = xmlDoc.getXmlContent().Atof();     // [%]
  xmlDoc.getXmlTag("PARAMETER","name","impact_parameter");
  impactParameter = xmlDoc.getXmlContent().Atof();    // [fm]
  xmlDoc.getXmlTag("PARAMETER","name","temperature_at_center");
  tempI           = xmlDoc.getXmlContent().Atof();  // [MeV]
  xmlDoc.getXmlTag("PARAMETER","name","device");
  deviceName      = xmlDoc.getXmlContent().Data();
  xmlDoc.getXmlTag("PARAMETER","name","colliding_system");
  collidingSystem = xmlDoc.getXmlContent().Data();
  xmlDoc.getXmlTag("VECTOR3D", "name","Distance");
  mDistance       = xmlDoc.getXmlVectorField();      // [GeV^-1]
  xmlDoc.getXmlTag("VECTOR3D", "name","FluidUx");
  mFluidUx        = xmlDoc.getXmlVectorField();      // [1]
  xmlDoc.getXmlTag("VECTOR3D", "name","FluidUy");
  mFluidUy        = xmlDoc.getXmlVectorField();      // [1]
  xmlDoc.getXmlTag("VECTOR3D", "name","FluidRap");
  mFluidRapidity  = xmlDoc.getXmlVectorField();      // [1]
  }
  catch (int exceptionIndex)
  {
  throw TaskException("I/O Error",__FUNCTION__);
  }
  thermodynamics->setTemperature(temperature);  // [GeV]
  thermodynamics->setChemistry(muB,muI,muS,muC);

  // mDistance derivatives
  try
  {
  xmlDoc.getXmlTag("VECTOR3D","name","DistanceDZeta");
  mDistanceDZeta = xmlDoc.getXmlVectorField();    // [GeV^-1/rad]
  }
  catch (int exceptionIndex)
  {
  throw TaskException("I/O Error",__FUNCTION__);
  }

  try
  {
  xmlDoc.getXmlTag("VECTOR3D","name","DistanceDPhi");
  mDistanceDPhi = xmlDoc.getXmlVectorField();    // [GeV^-1/rad]
  }
  catch (int exceptionIndex)
  {
  throw TaskException("I/O Error",__FUNCTION__);
  }

  try
  {
  xmlDoc.getXmlTag("VECTOR3D","name","DistanceDTheta");
  mDistanceDTheta = xmlDoc.getXmlVectorField();    // [GeV^-1/rad]
  }
  catch (int exceptionIndex)
  {
  throw TaskException("I/O Error",__FUNCTION__);
  }
}

//void Hypersurface_Lhyquid3D::writeToXmlFile(const char * outputPath     __attribute__((unused)),
//                                            const char * outputFileName __attribute__((unused)) )
//{
//  throw Exception("",__FUNCTION__);
//}

void Hypersurface_Lhyquid3D::setDefaultConfiguration()
{
  Hypersurface::setDefaultConfiguration();
  addProperty("RapPRange", momentumRapidityRange);
  addProperty("RapSRange", spatialRapidityRange);
}

void Hypersurface_Lhyquid3D::configure()
{
  Hypersurface::configure();
  momentumRapidityRange  = getValueDouble("RapPRange");
  spatialRapidityRange   = getValueDouble("RapSRange");
}

void Hypersurface_Lhyquid3D::print(std::ostream & output,  int style, int size) const
{
  Hypersurface::print(output,style,size);
}

//  output << std::endl;
//  output << "=================================================================" << std::endl;
//  output << "=================================================================" << std::endl;
//  output << "Therminator 2" << std::endl;
//  output << "Model BWA" << std::endl;
//  output << "Release, 2.0.3, 1 February 2011 " << std::endl;
//  output << std::endl;
//  output << "Authors:" << std::endl;
//  output << "    Mikolaj Chojnacki   (Mikolaj.Chojnacki@ifj.edu.pl)" << std::endl;
//  output << "    Adam Kisiel         (kisiel@if.pw.edu.pl)" << std::endl;
//  output << "    Wojciech Broniowski (Wojciech.Broniowski@ifj.edu.pl)" << std::endl;
//  output << "    Wojciech Florkowski (Wojciech.Florkowski@ifj.edu.pl)" << std::endl;
//  output << std::endl;
//  output << "Hypersurface Model Parameters:" << std::endl;
//  output << "    Severity...........: " << getSeverityName() << std::endl;
//  output << "    DeviceName.........: " << deviceName << std::endl;
//  output << "    CollidingSystem....: " << collidingSystem << std::endl;
//  output << "    Lambda.............: " << lambda << std::endl;
//  output << "    RapPRange..........: " << momentumRapidityRange << std::endl;
//  output << "    RapSRange..........: " << spatialRapidityRange << std::endl;
//  output << "    TauI...............: " << tauI;
//  output << "    ollidingEnergy.....: " << collidingEnergy;
//  output << "    CentralityMin......: " << centralityMin;
//  output << "    CentralityMax......: " << centralityMax;
//  output << "    ImpactParameter....: " << impactParameter;
//  output << "    TempI..............: " << tempI;
//  output << "    Temperature........: " << thermodynamics->getTemperature() << std::endl; // [MeV]
//  output << "    MuB................: " << thermodynamics->getMuB() << std::endl;// [MeV]
//  output << "    MuI................: " << thermodynamics->getMuI() << std::endl;// [MeV]
//  output << "    MuS................: " << thermodynamics->getMuS() << std::endl;// [MeV]
//  output << "    MuC................: " << thermodynamics->getMuC() << std::endl;// [MeV]
//  output << "=================================================================" << std::endl;
//  output << "=================================================================" << std::endl;
// }
