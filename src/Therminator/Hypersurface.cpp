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
#include "Hypersurface.hpp"
#include "Exceptions.hpp"
#include "PrintHelpers.hpp"

ClassImp(Hypersurface);

Hypersurface::Hypersurface()
:
ConfigurationManager(),
deviceName(""),
collidingSystem(""),
lambda(0.0),
momentumRapidityRange(0.0),
spatialRapidityRange(0.0),
tauI(0.0),
collidingEnergy(0.0),
centralityMin(0.0),
centralityMax(0.0),
impactParameter(0.0),
tempI(0.0),
zeta(0.0),
phiS(0.0),
Theta(0.0),
Tau(0.0),
rho(0.0),
rapidityS(0.0),
Dhs(0.0),
dDdPhi(0.0),
dDdZeta(0.0),
dDdTheta(0.0),
vT(0.0),
gammaT(0.0),
phiF(0.0),
thermodynamics(nullptr),
mDistance(nullptr),
mDistanceDPhi(nullptr),
mDistanceDZeta(nullptr)
{    }

Hypersurface::Hypersurface(Thermodynamics * _thermodynamics)
:
ConfigurationManager(),
deviceName(""),
collidingSystem(""),
lambda(0.0),
momentumRapidityRange(0.0),
spatialRapidityRange(0.0),
tauI(0.0),
collidingEnergy(0.0),
centralityMin(0.0),
centralityMax(0.0),
impactParameter(0.0),
tempI(0.0),
zeta(0.0),
phiS(0.0),
Theta(0.0),
Tau(0.0),
rho(0.0),
rapidityS(0.0),
Dhs(0.0),
dDdPhi(0.0),
dDdZeta(0.0),
dDdTheta(0.0),
thermodynamics(_thermodynamics),
mDistance(nullptr),
mDistanceDPhi(nullptr),
mDistanceDZeta(nullptr)
{     }

void Hypersurface::setDefaultConfiguration()
{
  ConfigurationManager::setDefaultConfiguration();
  addProperty("DeviceName",        deviceName);
  addProperty("CollidingSystem",   collidingSystem);
  addProperty("Lambda",            lambda);
  addProperty("RapPRange",         momentumRapidityRange);
  addProperty("RapSRange",         spatialRapidityRange);
  addProperty("TauI",              tauI);
  addProperty("CollidingEnergy",   collidingEnergy);
  addProperty("CentralityMin",     centralityMin);
  addProperty("CentralityMax",     centralityMax);
  addProperty("ImpactParameter",   impactParameter);
  addProperty("TempI",             tempI);
}

void Hypersurface::configure()
{
  ConfigurationManager::configure();
  deviceName           = getValueString("DeviceName");
  collidingSystem      = getValueString("CollidingSystem");
  lambda               = getValueDouble("Lambda");
  momentumRapidityRange= getValueDouble("RapPRange");
  spatialRapidityRange = getValueDouble("RapSRange");
  tauI                 = getValueDouble("TauI");
  collidingEnergy      = getValueDouble("CollidingEnergy");
  centralityMin        = getValueDouble("CentralityMin");
  centralityMax        = getValueDouble("CentralityMax");
  impactParameter      = getValueDouble("ImpactParameter");
  tempI                = getValueDouble("TempI");
  if (reportDebug(__FUNCTION__)) print(cout);
}

void Hypersurface::print(std::ostream & output,  int style, int size) const
{
  CAP::printCR(output);
  CAP::printLine(output,style,size);
  CAP::printLine(output,style,size);
  CAP::printString("Therminator 2",output,style,size);
  CAP::printString("Model BWA",output,style,size);
  CAP::printString("Release, 2.0.3, 1 February 2011 ",output,style,size);
  CAP::printLine(output,style,size);
  CAP::printString("Authors:",output,style,size);
  CAP::printString("Mikolaj Chojnacki   (Mikolaj.Chojnacki@ifj.edu.pl)",output,style,size);
  CAP::printString("Adam Kisiel         (kisiel@if.pw.edu.pl)",output,style,size);
  CAP::printString("Wojciech Broniowski (Wojciech.Broniowski@ifj.edu.pl)",output,style,size);
  CAP::printString("Wojciech Florkowski (Wojciech.Florkowski@ifj.edu.pl)",output,style,size);
  CAP::printLine(output,style,size);
  CAP::printString("Hypersurface Model Parameters",output,style,size);
  CAP::printValue("Severity",getSeverityName(),output,style,size);
  CAP::printValue("DeviceName",deviceName,output,style,size);
  CAP::printValue("CollidingSystem",collidingSystem,output,style,size);
  CAP::printValue("Lambda",lambda,output,style,size);
  CAP::printValue("RapPRange",momentumRapidityRange,output,style,size);
  CAP::printValue("RapSRange",spatialRapidityRange,output,style,size);
  CAP::printValue("TauI",tauI,output,style,size);
  CAP::printValue("CollidingEnergy",collidingEnergy,output,style,size);
  CAP::printValue("CentralityMin",centralityMin,output,style,size);
  CAP::printValue("CentralityMax",centralityMax,output,style,size);
  CAP::printValue("ImpactParameter",impactParameter,output,style,size);
  CAP::printValue("TempI",tempI,output,style,size);
  CAP::printValue("Temperature",thermodynamics->getTemperature(),output,style,size);
  CAP::printValue("MuB",thermodynamics->getMuB(),output,style,size);// [MeV]
  CAP::printValue("MuI",thermodynamics->getMuI(),output,style,size);// [MeV]
  CAP::printValue("MuS",thermodynamics->getMuS(),output,style,size);// [MeV]
  CAP::printValue("MuC",thermodynamics->getMuC(),output,style,size);// [MeV]
  CAP::printLine(output,style,size);
  CAP::printLine(output,style,size);
}

double Hypersurface::getHyperCubeSpatialVolume() const
{
  double sizeX = mDistance->getXMax() - mDistance->getXMin();
  double sizeY = mDistance->getYMax() - mDistance->getYMin();
  return sizeX * sizeY * momentumRapidityRange;
}

void   readFromXmlFile(const char * inputPath __attribute__((unused)),
                               const char * inputFileName __attribute__((unused)))
{
  throw CAP::Exception("Base class function not implemented",__FUNCTION__);
};

void   writeToXmlFile(const char * outputPath __attribute__((unused)),
                              const char * outputFileName __attribute__((unused)) )
{
  throw CAP::Exception("Base class function not implemented",__FUNCTION__);
};


