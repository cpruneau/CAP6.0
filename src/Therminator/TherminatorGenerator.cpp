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
#include "TherminatorGenerator.hpp"
#include "Model_BWA.hpp"
#include "Model_BlastWave.hpp"
#include "Model_KrakowSFO.hpp"
#include "Model_Lhyquid2DBI.hpp"
#include "Model_Lhyquid3D.hpp"
#include "Model_HadronGas.hpp"
#include "Hypersurface_Lhyquid2D.hpp"
#include "Hypersurface_Lhyquid3D.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "StreamHelpers.hpp"

ClassImp(CAP::TherminatorGenerator);

namespace CAP
{

//  if      (modelType == "KrakowSFO")    { sModel = 0;  tModelINI += "krakow.ini";  }
//  else if (modelType == "BlastWave")    { sModel = 1;  tModelINI += "blastwave.ini";  }
//  else if (tMomodelTypedel == "BWAVT")      { sModel = 2;  tModelINI += "bwa.ini";    }
//  else if (modelType == "BWAVTDelay")    { sModel = 3;  tModelINI += "bwa.ini";    }
//  else if (modelType == "BWAVLinear")    { sModel = 4;  tModelINI += "bwa.ini";    }
//  else if (modelType == "BWAVLinearDelay")  { sModel = 5;  tModelINI += "bwa.ini";    }
//  else if (modelType == "BWAVLinearForamption")  { sModel = 6;  tModelINI += "bwa.ini";    }
//  else if (modelType == "Lhyquid3D")    { sModel = 10; tModelINI += "lhyquid3d.ini";  }
//  else if (modelType == "Lhyquid2DBI")    { sModel = 11; tModelINI += "lhyquid2dbi.ini";  }


TherminatorGenerator::TherminatorGenerator()
:
EventTask::EventTask(),
modelType(1),
modelSubType(6),
modelInputPath(),
modelInputFile(),
modelOutputPath(),
modelOutputFile(),
hypersurfaceInputPath(),
hypersurfaceInputFile(),
hypersurfaceOutputPath(),
hypersurfaceOutputFile(),
multiplicitiesImport(false),
multiplicitiesExport(false),
multiplicitiesCreate(false),
multiplicitiesFluctType(0),
multiplicitiesInputPath(),
multiplicitiesInputFile(),
multiplicitiesOutputPath(),
multiplicitiesOutputFile(),
multiplicitiesFractionMin(0.5),
multiplicitiesFractionMax(1.0),
multiplicitiesFractionRange(0.5),
multiplicitiesForceZeroNetQ(0),
disablePhotons(true),
nSamplesIntegration(10000),
modelOnlyBackFlow(0),
decayRescaleChannels(0),
decayDisabled(false),
decayDisable2Prong(false),
decayDisable3Prong(false),
particleDecayer(),
model(nullptr),
averageMultiplicities(),
eventMultiplicities()
{
  appendClassName("TherminatorGenerator");
}

TherminatorGenerator::TherminatorGenerator(const TherminatorGenerator & task)
:
EventTask::EventTask(task),
modelType(task.modelType),
modelSubType(task.modelSubType),
modelInputPath(task.modelInputPath),
modelInputFile(task.modelInputFile),
modelOutputPath(task.modelOutputPath),
modelOutputFile(task.modelOutputFile),
hypersurfaceInputPath(task.hypersurfaceInputPath),
hypersurfaceInputFile(task.hypersurfaceInputFile),
hypersurfaceOutputPath(task.hypersurfaceOutputPath),
hypersurfaceOutputFile(task.hypersurfaceOutputFile),
multiplicitiesImport(task.multiplicitiesImport),
multiplicitiesExport(task.multiplicitiesExport),
multiplicitiesCreate(task.multiplicitiesCreate),
multiplicitiesFluctType(task.multiplicitiesFluctType),
multiplicitiesInputPath(task.multiplicitiesInputPath),
multiplicitiesInputFile(task.multiplicitiesInputFile),
multiplicitiesOutputPath(task.multiplicitiesOutputPath),
multiplicitiesOutputFile(task.multiplicitiesOutputFile),
multiplicitiesFractionMin(task.multiplicitiesFractionMin),
multiplicitiesFractionMax(task.multiplicitiesFractionMax),
multiplicitiesFractionRange(task.multiplicitiesFractionRange),
multiplicitiesForceZeroNetQ(task.multiplicitiesForceZeroNetQ),
disablePhotons(task.disablePhotons),
nSamplesIntegration(task.nSamplesIntegration),
modelOnlyBackFlow(task.modelOnlyBackFlow),
decayRescaleChannels(task.decayRescaleChannels),
decayDisabled(task.decayDisabled),
decayDisable2Prong(task.decayDisable2Prong),
decayDisable3Prong(task.decayDisable3Prong),
particleDecayer(),
model(task.model),
averageMultiplicities(task.averageMultiplicities),
eventMultiplicities(task.eventMultiplicities)
{   }

TherminatorGenerator TherminatorGenerator::operator=(const TherminatorGenerator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    modelType  =  task.modelType;
    modelSubType  =  task.modelSubType;
    modelInputPath  =  task.modelInputPath;
    modelInputFile  =  task.modelInputFile;
    modelOutputPath  =  task.modelOutputPath;
    modelOutputFile  =  task.modelOutputFile;
    hypersurfaceInputPath  =  task.hypersurfaceInputPath;
    hypersurfaceInputFile  =  task.hypersurfaceInputFile;
    hypersurfaceOutputPath  =  task.hypersurfaceOutputPath;
    hypersurfaceOutputFile  =  task.hypersurfaceOutputFile;
    multiplicitiesImport  =  task.multiplicitiesImport;
    multiplicitiesExport  =  task.multiplicitiesExport;
    multiplicitiesCreate  =  task.multiplicitiesCreate;
    multiplicitiesFluctType  =  task.multiplicitiesFluctType;
    multiplicitiesInputPath  =  task.multiplicitiesInputPath;
    multiplicitiesInputFile  =  task.multiplicitiesInputFile;
    multiplicitiesOutputPath  =  task.multiplicitiesOutputPath;
    multiplicitiesOutputFile  =  task.multiplicitiesOutputFile;
    multiplicitiesFractionMin  =  task.multiplicitiesFractionMin;
    multiplicitiesFractionMax  =  task.multiplicitiesFractionMax;
    multiplicitiesFractionRange  =  task.multiplicitiesFractionRange;
    multiplicitiesForceZeroNetQ  =  task.multiplicitiesForceZeroNetQ;
    disablePhotons  =  task.disablePhotons;
    nSamplesIntegration  =  task.nSamplesIntegration;
    modelOnlyBackFlow  =  task.modelOnlyBackFlow;
    decayRescaleChannels  =  task.decayRescaleChannels;
    decayDisabled  =  task.decayDisabled;
    decayDisable2Prong  =  task.decayDisable2Prong;
    decayDisable3Prong  =  task.decayDisable3Prong;
    model  =  task.model;
    averageMultiplicities  =  task.averageMultiplicities;
    eventMultiplicities  =  task.eventMultiplicities;
    }
  return *this;
}


void TherminatorGenerator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  // Therminator parameters
  addProperty( "ModelType",                    modelType);
  addProperty( "ModelSubType",                 modelSubType);
  addProperty( "ModelInputPath",               modelInputPath);
  addProperty( "ModelInputFile",               modelInputFile);
  addProperty( "ModelOutputPath",              modelOutputPath);
  addProperty( "ModelOutputFile",              modelOutputFile);
  addProperty( "HypersurfaceInputPath",        hypersurfaceInputPath);
  addProperty( "HypersurfaceInputFile",        hypersurfaceInputFile);
  addProperty( "HypersurfaceOutputPath",       hypersurfaceOutputPath);
  addProperty( "HypersurfaceOutputFile",       hypersurfaceOutputFile);
  addProperty( "MultiplicitiesImport",         multiplicitiesImport);
  addProperty( "MultiplicitiesExport",         multiplicitiesExport);
  addProperty( "MultiplicitiesCreate",         multiplicitiesCreate);
  addProperty( "MultiplicitiesFluctType",      multiplicitiesFluctType);
  addProperty( "MultiplicitiesInputPath",      multiplicitiesInputPath);
  addProperty( "MultiplicitiesInputFile",      multiplicitiesInputFile);
  addProperty( "MultiplicitiesOutputPath",     multiplicitiesOutputPath);
  addProperty( "MultiplicitiesOutputFile",     multiplicitiesOutputFile);
  addProperty( "MultiplicitiesFractionMin",    multiplicitiesFractionMin);
  addProperty( "MultiplicitiesFractionMax",    multiplicitiesFractionMax);
  addProperty( "MultiplicitiesForceZeroNetQ",  multiplicitiesForceZeroNetQ);

  addProperty( "DisablePhotons",               disablePhotons);
  addProperty( "nSamplesIntegration",          nSamplesIntegration);
  addProperty( "ModelOnlyBackFlow",            modelOnlyBackFlow);
  addProperty( "DecayRescaleChannels",         decayRescaleChannels);
  addProperty( "DecayDisabled",                decayDisabled);
  addProperty( "DecayDisable3Prong",           decayDisable3Prong);
  addProperty( "DecayDisable2Prong",           decayDisable2Prong);
  addProperty( "DecayNoWeakDecay",             decayNoWeakDecay);
  addProperty( "DecayStoreDecayedParts",       decayStoreDecayedParts);
}

void TherminatorGenerator::configure()
{
  printString("TherminatorGenerator::configure() GGRRRRRR 1");
  EventTask::configure();
  printString("TherminatorGenerator::configure() GGRRRRRR 1");
  modelType                   = getValueInt(    "ModelType");
  modelSubType                = getValueInt(    "ModelSubType");
  modelInputPath              = getValueString( "ModelInputPath");
  modelInputFile              = getValueString( "ModelInputFile");
  modelOutputPath             = getValueString( "ModelOutputPath");
  modelOutputFile             = getValueString( "ModelOutputFile");
  hypersurfaceInputPath       = getValueString( "HypersurfaceInputPath");
  hypersurfaceInputFile       = getValueString( "HypersurfaceInputFile");
  hypersurfaceOutputPath      = getValueString( "HypersurfaceOutputPath");
  hypersurfaceOutputFile      = getValueString( "HypersurfaceOutputFile");
  multiplicitiesImport        = getValueBool(   "MultiplicitiesImport");
  multiplicitiesExport        = getValueBool(   "MultiplicitiesExport");
  multiplicitiesCreate        = getValueBool(   "MultiplicitiesCreate");
  multiplicitiesFluctType     = getValueInt(    "MultiplicitiesFluctType");
  multiplicitiesInputPath     = getValueString( "MultiplicitiesInputPath");
  multiplicitiesInputFile     = getValueString( "MultiplicitiesInputFile");
  multiplicitiesOutputPath    = getValueString( "MultiplicitiesOutputPath");
  multiplicitiesOutputFile    = getValueString( "MultiplicitiesOutputFile");
  multiplicitiesFractionMin   = getValueDouble( "MultiplicitiesFractionMin");
  multiplicitiesFractionMax   = getValueDouble( "MultiplicitiesFractionMax");
  multiplicitiesFractionRange = multiplicitiesFractionMax - multiplicitiesFractionMin;
  multiplicitiesForceZeroNetQ = getValueBool(   "MultiplicitiesForceZeroNetQ");

  disablePhotons              = getValueBool(   "DisablePhotons");
  nSamplesIntegration         = getValueInt(    "nSamplesIntegration");
  modelOnlyBackFlow           = getValueBool(   "ModelOnlyBackFlow");
  decayRescaleChannels        = getValueBool(   "DecayRescaleChannels");
  decayDisabled               = getValueBool(   "DecayDisabled");
  decayDisable3Prong          = getValueBool(   "DecayDisable3Prong");
  decayDisable2Prong          = getValueBool(   "DecayDisable2Prong");
  decayNoWeakDecay            = getValueBool(   "DecayNoWeakDecay");
  decayStoreDecayedParts      = getValueBool(   "DecayStoreDecayedParts");

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue( "ModelType",                   modelType);
    printValue( "ModelSubType",                modelSubType);
    printValue( "ModelInputPath",              modelInputPath);
    printValue( "ModelInputFile",              modelInputFile);
    printValue( "ModelOutputPath",             modelOutputPath);
    printValue( "ModelOutputFile",             modelOutputFile);
    printValue( "HypersurfaceInputPath",       hypersurfaceInputPath);
    printValue( "HypersurfaceInputFile",       hypersurfaceInputFile);
    printValue( "HypersurfaceOutputPath",      hypersurfaceOutputPath);
    printValue( "HypersurfaceOutputFile",      hypersurfaceOutputFile);
    printValue( "MultiplicitiesImport",        multiplicitiesImport);
    printValue( "MultiplicitiesExport",        multiplicitiesExport);
    printValue( "MultiplicitiesCreate",        multiplicitiesCreate);
    printValue( "MultiplicitiesFluctType",     multiplicitiesFluctType);
    printValue( "MultiplicitiesInputPath",     multiplicitiesInputPath);
    printValue( "MultiplicitiesInputFile",     multiplicitiesInputFile);
    printValue( "MultiplicitiesOutputPath",    multiplicitiesOutputPath);
    printValue( "MultiplicitiesOutputFile",    multiplicitiesOutputFile);
    printValue( "MultiplicitiesFractionMin",   multiplicitiesFractionMin);
    printValue( "MultiplicitiesFractionMax",   multiplicitiesFractionMax);
    printValue( "MultiplicitiesFractionRange", multiplicitiesFractionRange);
    printValue( "MultiplicitiesForceZeroNetQ", multiplicitiesForceZeroNetQ);
    printValue( "DisablePhotons",              disablePhotons);
    printValue( "nSamplesIntegration",         nSamplesIntegration);
    printValue( "ModelOnlyBackFlow",           modelOnlyBackFlow);
    printValue( "DecayRescaleChannels",        decayRescaleChannels);
    printValue( "DecayDisabled",               decayDisabled);
    printValue( "DecayDisable3Prong",          decayDisable3Prong);
    printValue( "DecayDisable2Prong",          decayDisable2Prong);
    printValue( "DecayNoWeakDecay",            decayNoWeakDecay);
    printValue( "DecayStoreDecayedParts",      decayStoreDecayedParts);
    printLine();
    }
}

void TherminatorGenerator::execute()
{
  Event & event = *Manager<Event>::getObjectAt(0);
  event.reset();
  particleFactory->reset();
  // generate multiplicities for this event
  unsigned int nTypes = particleDb->size();
  if (averageMultiplicities.size() < 1)
    {
    String s = "Array averageMultiplicities is not initialized.";
    throw TaskException(s,__FUNCTION__);
    }
  double multiplicitiesFraction = 1.0;
  if (multiplicitiesFractionRange>0 || multiplicitiesFractionMin<1)
    {
    multiplicitiesFraction = multiplicitiesFractionMin + multiplicitiesFractionRange*gRandom->Rndm();
    }
  int    mult  = 0;
  double mean  = 0;
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (unsigned int iType=0; iType<nTypes; iType++)
    {
    ParticleType * type = particleTypes[iType];
    // Use type->disable() to disable a particle type.
    // This eliminates the generation of particles that are not of interest
    // The simulation can then proceed much faster.
    if (type->isDisabled())
      {
      mult = 0;
      }
    else
      {
      switch (multiplicitiesFluctType)
        {
          case 0: // Poisson fluctuations
          {
          mean  = multiplicitiesFraction * averageMultiplicities[iType].multiplicity;
          mult  = gRandom->Poisson(mean);
          }
          break;
          case 1: // Negative Binomial  fluctuations
          {
          mult = 0; // HOW?
          }
          break;
          default:
          case 2: // Gaussian fluctuations
          {
          mean  = multiplicitiesFraction * averageMultiplicities[iType].multiplicity;
          mult  = TMath::Max(0, int(gRandom->Gaus(mean,sqrt(mean))));
          }
          break;
          case 3:  // Poisson or Gaussian fluctuations
          {
          mean  = multiplicitiesFraction * averageMultiplicities[iType].multiplicity;
          if (mean>20)
            mult = TMath::Max(0, int(gRandom->Gaus(mean,sqrt(mean))));
          else
            mult = TMath::Max(0, int(gRandom->Poisson(mean)));
          }
        }
      }
    eventMultiplicities[iType] = mult;
    }

  if (multiplicitiesForceZeroNetQ)
    {
    for (unsigned int iType=0; iType<nTypes; iType++)
      {
      ParticleType * particleType = particleDb->getParticleType(iType);
      int     pdg     = particleType->getPdgCode();
      //      double  charge  = particleType->getCharge();
      //      double  strange = particleType->getStrangeness();
      //      double  baryon  = particleType->getBaryonNumber();
      if (pdg<0) // a particle
        {
        int antiTypeIndex = particleType->getAntiParticleIndex();
        if (antiTypeIndex==int(iType)) continue;
        if (antiTypeIndex<0) throw TaskException("Charge>0 but antiTypeIndex<0",__FUNCTION__);
        eventMultiplicities[antiTypeIndex] = eventMultiplicities[iType];
        }
      }
    }

  int      multiplicity;
  //int      antiMultiplicity;
  double   maxIntegrand;
  double   value;
  double   valueTest;
  //bool flag = false;

  //  double totalQ = 0.0;
  //  double totalS = 0.0;
  //  double totalB = 0.0;
  //  double  charge;
  //  double  strange;
  //  double  baryon;


  for (unsigned int iType=0; iType<nTypes; iType++)
    {
    ParticleType * particleType = particleDb->getParticleType(iType);
    //    charge  = particleType->getCharge();
    //    strange = particleType->getStrangeness();
    //    baryon  = particleType->getBaryonNumber();
    maxIntegrand = averageMultiplicities[iType].integral;
    multiplicity = eventMultiplicities[iType];
    if (particleType->isPhoton() && disablePhotons) continue;

    //    totalQ += charge  * double(multiplicity);
    //    totalS += strange  * double(multiplicity);
    //    totalB += baryon  * double(multiplicity);


    int iParticle = 0;
    while (iParticle < multiplicity)
      {
      value     = model->getIntegrand(*particleType);
      valueTest = gRandom->Rndm() * maxIntegrand;
      if (valueTest<value)
        {
        Particle * particle = particleFactory->getNextObject();
        particle->setType(particleType);
        particle->setLive(true);
        model->setParticlePX(*particle);
        iParticle++;
        if (decayDisabled || particleType->isStable())
          {
          if (accept(*particle)) event.addParticle(particle);
          }
        else
          decayParticle(event, *particle);
        }
      }
    }
}

//!
//!Accept the particle if any of the filter accepts it or if not filters were provided.
//!
bool TherminatorGenerator::accept(Particle & particle)
{
  vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();
  if (particleFilters.size()<1) return true;
  for (auto & particleFilter : particleFilters)
    {
    if (particleFilter->accept(particle)) return true;
    }
  return false;
}

void TherminatorGenerator::decayParticle(Event & event, Particle & parent)
{
  ParticleType      & parentType = parent.getType();

  //  cout << " parent type name: " <<  parentType.getName() << endl;
  //  cout << " parent mass     : " <<  parentType.getMass() << endl;
  //  cout << " parent width    : " <<  parentType.getWidth() << endl;
  //  cout << " parent stable   : " <<  parentType.isStable() << endl;
  //  cout << " parent n modes  : " <<  parentType.getNDecayModes() << endl;

  //  bool flag = false;
  //  int pdg = std::fabs(parentType.getPdgCode());
  //if (pdg==3112 || pdg==3212 || pdg==3222)
  //    if (pdg==3112 || pdg==3212)
  //    {
  //    cout << "Trying to decay pdg:" << pdg << endl;
  //    flag = true;
  //    }
  // double parentB = parentType.getBaryonNumber();

  ParticleDecayMode & decayMode  = parentType.generateDecayMode();
  int nChildren = decayMode.getNChildren();
  if (nChildren<2)  return;
  if ((nChildren==2 && decayDisable2Prong) ||
      (nChildren==3 && decayDisable3Prong))
    {
    event.addParticle(&parent);
    return;
    }
  LorentzVector & parentMomentum  = parent.getMomentum();
  LorentzVector & parentPosition  = parent.getPosition();
  switch (nChildren)
    {
      case 1:
      {
      String s = "Single particle decay for ";
      s += parent.getName();
      throw TaskException(s,__FUNCTION__);
      }
      break;

      case 2:
      {
      Particle * child1 = particleFactory->getNextObject();
      Particle * child2 = particleFactory->getNextObject();
      ParticleType  & childType1 = decayMode.getChildType(0); child1->setType(&childType1); child1->setLive(true);
      ParticleType  & childType2 = decayMode.getChildType(1); child2->setType(&childType2); child2->setLive(true);

      //      double childType1B = childType1.getBaryonNumber();
      //      double childType2B = childType2.getBaryonNumber();
      //      if (parentB != (childType1B+childType2B ))
      //        {
      //        cout << "Parent:" << parentType.getName << " C1: " << childType1.getName() << " C2: "<< childType1.getName() << "  "
      //        << "parentB: " << parentB << " childType1B+childType2B" << childType1B+childType2B << endl;
      //        exit(1);
      //        }

      LorentzVector & p1 = child1->getMomentum();
      LorentzVector & r1 = child1->getPosition();
      LorentzVector & p2 = child2->getMomentum();
      LorentzVector & r2 = child2->getPosition();
      particleDecayer.decay2(parentType,
                             parentMomentum,
                             parentPosition,
                             childType1,p1,r1,
                             childType2,p2,r2);
      parent.setDecayed(true);
      if (decayStoreDecayedParts) event.addParticle(&parent);
      if (child1->isStable())
        {
        if (accept(*child1))
          {
          event.addParticle(child1);
          }
        //        else
        //          cout << "not accepted:" << childType1.getName() << endl;
        }
      else
        decayParticle(event, *child1);

      if (child2->isStable())
        {
        if (accept(*child2))
          {
          event.addParticle(child2);
          }
        //        else
        //          cout << "not accepted:" << childType2.getName() << endl;
        }
      else
        decayParticle(event, *child2);
      break;
      }

      case 3:
      {
      Particle * child1 = particleFactory->getNextObject();
      Particle * child2 = particleFactory->getNextObject();
      Particle * child3 = particleFactory->getNextObject();
      ParticleType  & childType1 = decayMode.getChildType(0); child1->setType(&childType1); child1->setLive(true);
      ParticleType  & childType2 = decayMode.getChildType(1); child2->setType(&childType2); child2->setLive(true);
      ParticleType  & childType3 = decayMode.getChildType(2); child3->setType(&childType3); child3->setLive(true);
      LorentzVector & p1 = child1->getMomentum();
      LorentzVector & r1 = child1->getPosition();
      LorentzVector & p2 = child2->getMomentum();
      LorentzVector & r2 = child2->getPosition();
      LorentzVector & p3 = child3->getMomentum();
      LorentzVector & r3 = child3->getPosition();
      particleDecayer.decay3(parentType,
                             parentMomentum,
                             parentPosition,
                             childType1,p1,r1,
                             childType2,p2,r2,
                             childType3,p3,r3);
      parent.setDecayed(true);
      if (decayStoreDecayedParts) event.addParticle(&parent);
      if (child1->isStable())
        {
        if (accept(*child1))
          {
          event.addParticle(child1);
          }
        //        else
        //          cout << "not accepted:" << childType1.getName() << endl;
        }
      else
        decayParticle(event, *child1);
      if (child2->isStable())
        {
        if (accept(*child2))
          {
          event.addParticle(child2);
          }
        //        else
        //          cout << "not accepted:" << childType2.getName() << endl;
        }
      else
        decayParticle(event, *child2);

      if (child3->isStable())
        {
        if (accept(*child3))
          {
          event.addParticle(child3);
          }
        //        else
        //          cout << "not accepted:" << childType3.getName() << endl;
        }
      else
        decayParticle(event, *child3);
      break;
      }

      default:
      case 4:
      {
      throw TaskException("4- or more body decay should not happen",__FUNCTION__);

      //        Particle * child1 = particleFactory->getNextObject();
      //        Particle * child2 = particleFactory->getNextObject();
      //        Particle * child3 = particleFactory->getNextObject();
      //        Particle * child4 = particleFactory->getNextObject();
      //        ParticleType   & childType1 = decayMode.getChildType(0); child1->setType(&childType1); child1->setLive(true);
      //        ParticleType   & childType2 = decayMode.getChildType(1); child2->setType(&childType2); child2->setLive(true);
      //        ParticleType   & childType3 = decayMode.getChildType(2); child3->setType(&childType3); child3->setLive(true);
      //        ParticleType   & childType4 = decayMode.getChildType(3); child4->setType(&childType4); child4->setLive(true);
      //        LorentzVector & p1 = child1->getMomentum();
      //        LorentzVector & r1 = child1->getPosition();
      //        LorentzVector & p2 = child2->getMomentum();
      //        LorentzVector & r2 = child2->getPosition();
      //        LorentzVector & p3 = child3->getMomentum();
      //        LorentzVector & r3 = child3->getPosition();
      //        LorentzVector & p4 = child4->getMomentum();
      //        LorentzVector & r4 = child4->getPosition();
      //        decayer.decay4(parentType,
      //                       parentMomentum,
      //                       parentPosition,
      //                       childType1,p1,r1,
      //                       childType2,p2,r2,
      //                       childType3,p3,r3,
      //                       childType4,p4,r4);
      //      parent.setDecayed(true);
      //      if (decayStoreDecayedParts) event.addParticle(&parent);
      //      if (child1->isStable() && accept(*child1))
      //        event.addParticle(child1);
      //      else
      //        decayParticle(event, *child1);
      //      if (child2->isStable() && accept(*child2))
      //        event.addParticle(child2);
      //      else
      //        decayParticle(event, *child2);
      //      if (child3->isStable() && accept(*child3))
      //        event.addParticle(child3);
      //      else
      //        decayParticle(event, *child3);
      //      if (child4->isStable() && accept(*child4))
      //        event.addParticle(child4);
      //      else
      //        decayParticle(event, *child4);
      //      break;
      break;
      }
    }
}


void TherminatorGenerator::printIntroMessage(const String & option __attribute__ (( unused)) )  const
{
  printCR();
  printCR();
  printCR();
  printCR();
  printLine();
  //  printValue("THERMINATOR 2 EVENTS version",_THERMINATOR2_VERSION_);
  //  printCR();
  //  printString("Authors: M.Chojnacki, A.Kisiel, W.Florkowski, W.Broniowski");
  //  printString("Cite as: arXiv:1102.0273");
  //  printString("webpage: http://therminator2.ifj.edu.pl/");
  //  printLine();
  printCR();
  printCR();
}

void TherminatorGenerator::printHelp(const String & option __attribute__ (( unused)) ) const
{
  printCR();
  printLine();
  printString("Usage");
  printString("therm2_events [EVENTS_INI] [PPID] [HYPER_XML]");
  printString("therm2_events [OPTION]");
  printString("  [EVENTS_INI]\t\tampin settings file;\t\tdefault: events.ini");
  printString("  [PPID]\t\tparent's system process ID;\tdefault: 0");
  printString("  [HYPER_XML]\tlocation of the hypersurface XML file;\tdefault:");
  printString("  [OPTION]");
  printString("    -h | --help\t\tthis screen");
  printString("    -v | --version\tversion inforamption");
  printLine();
  printCR();
}

void TherminatorGenerator::printVersion(const String & option __attribute__ (( unused)) ) const
{
  printCR();
  printLine();
  // printValue("version:\tTHERMINATOR 2 EVENTS version " << _THERMINATOR2_VERSION_);
  //  printValue("compiled with:\t",_CXX_VER_);
  //  printValue("ROOT version",_ROOT_VER_);
  printLine();
  printCR();
}


void TherminatorGenerator::initialize()
{
  if (reportDebug(__FUNCTION__))
    {
    printString("TherminatorGenerator::initialize() Started");
    }
  EventTask::initialize();
  if (!particleDb)
    throw TaskException("No particle database",__FUNCTION__);
  //particleDb = ParticleDb::getDefaultParticleDb();
  if (particleDb->size()<1)
    throw TaskException("Particle Database is not initialized. Waky Waky!!!!!",__FUNCTION__);
  switch (modelType)
    {
      default:
      throw TaskException("Unknown model requested",__FUNCTION__);
      case 0:  model = new Model_KrakowSFO();   break;
      case 1:  model = new Model_BlastWave();   break;
      case 5:  model = new Model_HadronGas();   break;
      case 6:  model = new Model_BWA();         break;
      case 10: model = new Model_Lhyquid3D();   break;
      case 11: model = new Model_Lhyquid2DBI(); break;
    };
  model->setConfigurationPath(getFullTaskPath());
  model->setRequestedConfiguration(*requestedConfiguration);
  model->initialize();
  if (multiplicitiesImport)
    {
    importMultiplicities();
    }
  else if (multiplicitiesCreate)
    {
    calculateMultiplicities();
    }
  else
    {
    throw TaskException("Not loading or creating multiplicities",__FUNCTION__);
    }
  if (multiplicitiesExport && !multiplicitiesImport)
    {
    exportMultiplicities();
    }
  eventMultiplicities.assign(averageMultiplicities.size(),0.0);
}


void TherminatorGenerator::finalize()
{
  if (model) delete model;
  averageMultiplicities.clear();
  eventMultiplicities.clear();
  TaskAccountant::clear();
  EventAccountant::clear();
}

void TherminatorGenerator::importMultiplicities()
{
  String dbPath = getEnvVariable("CAP_DATABASE_PATH");
  dbPath += "/";
  dbPath += multiplicitiesInputPath;

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("multiplicitiesInputPath",multiplicitiesInputPath);
    printValue("dbPath",dbPath);
    printValue("multiplicitiesInputFile",multiplicitiesInputFile);
    }
  // initialize the multiplicity array
  averageMultiplicities.clear();
  int nPartTypes = particleDb->size();
  if (reportDebug(__FUNCTION__)) printValue("nPartTypes",nPartTypes);
  for (int iPartType=0; iPartType<nPartTypes; iPartType++)
    {
    ParticleMultiplicity pm;
    ParticleType * particleType = particleDb->getParticleType(iPartType);
    pm.name         = particleType->getName();
    pm.integral     = 0.0;
    pm.multiplicity = 0.0;
    averageMultiplicities.push_back(pm);
    }
  ifstream & inputFile = openInputAsciiFile(dbPath,multiplicitiesInputFile,".txt");
  try {
    {
    int count = 0;
    String name;
    double integral;
    double multiplicity;
    while (!inputFile.eof())
      {
      inputFile >> name >> integral >> multiplicity;
      if (reportDebug(__FUNCTION__))
        {
        printCR();
        std::cout << "i:" << count <<  " name: " << name << " integral: " << integral << " multiplicity: " << multiplicity <<  std::endl;
        }
      int index = particleDb->findIndexForName(name);
      if (index<0)
        {
        if (reportWarning(__FUNCTION__))  std::cout << "Name not found (skipping):" << name <<  std::endl;
        continue;
        }
      averageMultiplicities[index].integral     = integral;
      averageMultiplicities[index].multiplicity = multiplicity;
      count++;
      }
    if (reportDebug(__FUNCTION__))
      {
      cout << endl;
      cout << "Read in " << count << " records."  << endl;
      }
    inputFile.close();
    }
  }
  catch (...)
  {
  throw FileException(multiplicitiesInputFile,"Error reading multiplicity file.","TherminatorGenerator::importMultiplicities()");
  }
}

void TherminatorGenerator::exportMultiplicities()
{
  String dbPath = getEnvVariable("CAP_DATABASE_PATH");
  dbPath += "/";
  dbPath += multiplicitiesOutputPath;

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("multiplicitiesOutputPath",multiplicitiesOutputPath);
    printValue("dbPath",dbPath);
    printValue("multiplicitiesOutputFile",multiplicitiesOutputFile);
    }

  // create the outputpath if it does not exist...
  createDirectory(dbPath);
  ofstream & outputFile = openOutputAsciiFile(dbPath,multiplicitiesOutputFile,".txt");
  unsigned int nTypes = averageMultiplicities.size();
  for (unsigned int iType=0; iType<nTypes; iType++)
    {
    ParticleMultiplicity & pm = averageMultiplicities[iType];
    outputFile << pm.name << "    " << pm.integral << "    " << pm.multiplicity <<  std::endl;
    //3cout  << pm.name << "    " << pm.integral << "    " << pm.multiplicity << endl;
    //if (iType>10) exit(1);
    }
  outputFile.close();
}

void TherminatorGenerator::calculateMultiplicities()
{
  int nPartTypes = particleDb->size();
  if (reportDebug(__FUNCTION__))
    {
    cout << endl;
    cout << " nPartTypes : " << nPartTypes << endl<< endl;
    }
  if (nPartTypes<1)
    throw TaskException("nPartTypes<1",__FUNCTION__);
  for (int iPartType = 0; iPartType<nPartTypes; iPartType++)
    {
    ParticleType & particleType = *particleDb->getParticleType(iPartType);
    double maxIntegrand  = 0.0;
    double multiplicity  = 0.0;
    double integrand     = 0.0;
    ParticleMultiplicity particleMultiplicity;
    particleMultiplicity.name         = particleType.getName();
    if (particleType.isPhoton() && disablePhotons)
      {
      particleMultiplicity.integral     = 0.0;
      particleMultiplicity.multiplicity = 0.0;
      }
    else
      {
      for (int iParticle = 0; iParticle < nSamplesIntegration; iParticle++)
        {
        integrand = model->getIntegrand(particleType);
        //if (integrand<0.0) continue;
        if (integrand>maxIntegrand) maxIntegrand = integrand;
        multiplicity += integrand;
        }
      //multiplicity *= 1.0/ double(nSamplesIntegration);
      //cout << "iPartType:" << iPartType << " maxIntegrand: " << maxIntegrand << " multiplicity:" << multiplicity << endl;
      //cout << "            volume: " << model->getHyperCubeVolume() <<  " nSamplesIntegration:" << nSamplesIntegration << endl;
      multiplicity *= model->getHyperCubeVolume() / double(nSamplesIntegration);
      //cout << "            multiplicity: "  <<  multiplicity << endl;
      particleMultiplicity.integral     = maxIntegrand;
      particleMultiplicity.multiplicity = multiplicity;
      }
    averageMultiplicities.push_back(particleMultiplicity);
    }
  if (reportDebug(__FUNCTION__)) printMultiplicities();
}

void TherminatorGenerator::printMultiplicities()
{
  printCR();
  printValue("ParticleDb Name",particleDb->getName());
  printValue("Model Name",model->getName());
  printString("Average Multiplicities vs. Species");
  printCR();
  std::cout << std::fixed << std::setw(5)  <<  "Index";
  std::cout << std::fixed << std::setw(12) <<  "Name";
  std::cout << std::fixed << std::setw(16) <<  "Integral";
  std::cout << std::fixed << std::setw(16) <<  "Multiplicity";
  std::cout << std::endl;
  unsigned int nTypes = averageMultiplicities.size();
  for (unsigned int iType=0; iType<nTypes; iType++)
    {
    ParticleType & type = *particleDb->getParticleType(iType);
    ParticleMultiplicity & pm = averageMultiplicities[iType];
    std::cout
    << std::fixed << std::setw(5) <<  iType
    << std::fixed << std::setw(12)  << type.getName()
    << std::scientific << std::setw(16) << std::setprecision(6) <<  pm.integral
    << std::scientific << std::setw(16) << std::setprecision(6) <<  pm.multiplicity << std::endl;
    }
  printCR();
  printCR();
  printCR();
}

} // namespace CAP;
