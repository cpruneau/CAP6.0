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
#include "PythiaEventGenerator.hpp"

ClassImp(CAP::PythiaEventGenerator);

namespace CAP
{

PythiaEventGenerator::PythiaEventGenerator()
:
EventTask(),
pythia(nullptr),
saveFinalOnly(true),
savePhotons(false),
saveNeutrinos(false),
saveQuarks(false),
saveGaugeBosons(false)
{
  appendClassName("PythiaEventGenerator");
  setName("Pythia");
  setTitle("Pythia");
  setVersion("1.0");
}

PythiaEventGenerator::PythiaEventGenerator(const PythiaEventGenerator & task)
:
EventTask(task),
pythia(task.pythia),
saveFinalOnly(task.saveFinalOnly),
savePhotons(task.savePhotons),
saveNeutrinos(task.saveNeutrinos),
saveQuarks(task.saveQuarks),
saveGaugeBosons(task.saveGaugeBosons)
{ }

PythiaEventGenerator & PythiaEventGenerator::operator=(const PythiaEventGenerator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    pythia = task.pythia;
    saveFinalOnly    = task.saveFinalOnly;
    savePhotons      = task.savePhotons;
    saveNeutrinos    = task.saveNeutrinos;
    saveQuarks       = task.saveQuarks;
    saveGaugeBosons  = task.saveGaugeBosons;
    }
  return *this;
}

void PythiaEventGenerator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("StreamIndex0",0);
  addProperty("Print:Banner",     false);
  addProperty("Print:Statistics", false);
  addProperty("Print:NEvents",    0);
  addProperty("Beams:idA",        2212);
  addProperty("Beams:idB",        2212);
  addProperty("Beams:frameType",  2);
  addProperty("Beams:eCM",        2700.0);
  addProperty("Beams:eA",         1350.0);
  addProperty("Beams:eB",         1350.0);
  addProperty("SetSeed",          true);
  addProperty("SeedValue",        121211);
  addProperty("UseQCDCR",         true);
  addProperty("UseRopes",         false);
  addProperty("UseShoving",       false);
  addProperty("xmlInputPath",     String(""));
  addProperty("SaveFinalOnly",    true);
  addProperty("SavePhotons",      false);
  addProperty("SaveNeutrinos",    false);
  addProperty("SaveQuarks",       false);
  addProperty("SaveGaugeBosons",  false);

  for (int k=0; k<30; k++)
    {
    String key = "Option"; key += k;
    addProperty(key, String("none"));
    }
  // print(cout);
}

void PythiaEventGenerator::configure()
{
  EventTask::configure();
  if (reportDebug(__FUNCTION__)) print(cout);
}

//!
//! Initialize generator
//! pythia->Initialize(2212 /* p */, 2212 /* p */, 14000. /* GeV */);
//!
void PythiaEventGenerator::initialize()
{
  EventTask::initialize();
  pythia = new Pythia8::Pythia(getValueString("xmlInputPath").Data(), getValueBool("Print:Banner"));
  pythia->settings.mode("Beams:idA",       getValueInt(   "Beams:idA"));
  pythia->settings.mode("Beams:idB",       getValueInt(   "Beams:idB"));
  pythia->settings.mode("Beams:frameType", getValueInt(   "Beams:frameType"));
  switch (getValueInt("Beams:frameType"))
    {
      default:
      case 1:
      pythia->settings.parm("Beams:eCM",     getValueDouble("Beams:eCM"));
      break;
      case 2:
      pythia->settings.parm("Beams:eA",      getValueDouble("Beams:eA"));
      pythia->settings.parm("Beams:eB",      getValueDouble("Beams:eB"));
      break;
    }
  saveFinalOnly   = getValueBool("SaveFinalOnly");
  savePhotons     = getValueBool("SavePhotons");
  saveNeutrinos   = getValueBool("SaveNeutrinos");
  saveQuarks      = getValueBool("SaveQuarks");
  saveGaugeBosons = getValueBool("SaveGaugeBosons");

  if (getValueDouble("SetSeed"))
    {
    String  seedValueString = "Random:seed = ";
    seedValueString += getValueLong("SeedValue");
    pythia->readString("Random:setSeed = on");
    pythia->readString(seedValueString.Data());
    printValue("Pythia:Random:setSeed","ON");
    printValue("Pythia:Random:SeedValue",seedValueString);
    }
  for (int k=0; k<30; k++)
    {
    String key = "Option"; key += k;
    String  value = getValueString(key);
    if (!value.Contains("none") )
      {
      String s = "Pythia:"; s+=key;
      printValue(s,value);
      pythia->readString(value.Data());
      }
    }
  if(getValueBool(  "UseQCDCR"))
    {
    printValue("Pythia:UseQCDCR","ON");
    pythia->readString("MultiPartonInteractions:pT0Ref = 2.15");
    pythia->readString("BeamRemnants:remnantMode = 1");
    pythia->readString("BeamRemnants:saturation = 5");
    pythia->readString("ColourReconnection:mode = 1");
    pythia->readString("ColourReconnection:allowDoubleJunRem = off");
    pythia->readString("ColourReconnection:m0 = 0.3");
    pythia->readString("ColourReconnection:allowJunctions = on");
    pythia->readString("ColourReconnection:junctionCorrection = 1.2");
    pythia->readString("ColourReconnection:timeDilationMode = 2");
    pythia->readString("ColourReconnection:timeDilationPar = 0.18");
    if(!getValueBool("UseRopes")) pythia->readString("Ropewalk:RopeHadronization = off");
    }
  if(getValueBool("UseQCDCR") && getValueBool(  "UseRopes"))
    {
    printValue("Pythia:UseQCDCR","ON");
    printValue("Pythia:UseRopes","ON");
    pythia->readString("Ropewalk:RopeHadronization = on");
    pythia->readString("Ropewalk:doShoving = on");
    pythia->readString("Ropewalk:doFlavour = on");
    pythia->readString("Ropewalk:tInit = 1.5");
    pythia->readString("Ropewalk:deltat = 0.05");
    pythia->readString("Ropewalk:tShove = 0.1");
    pythia->readString("Ropewalk:gAmplitude = 0.");// # Set shoving strength to 0 explicitly
    pythia->readString("Ropewalk:r0 = 0.5");
    pythia->readString("Ropewalk:m0 = 0.2");
    pythia->readString("Ropewalk:beta = 0.1");
    pythia->readString("PartonVertex:setVertex = on");
    pythia->readString("PartonVertex:protonRadius = 0.7");
    pythia->readString("PartonVertex:emissionWidth = 0.1");
  }
  if(!getValueBool("UseQCDCR") && getValueBool(  "UseRopes"))
    throw TaskException("ropes w/o the necessary junctions! Flip kQCDCR=kTRUE",__FUNCTION__);
  if(getValueBool("UseShoving"))
    {
    printValue("Pythia:UseShoving","ON");
    pythia->readString("Ropewalk:RopeHadronization = on");
    pythia->readString("Ropewalk:doShoving = on");
    pythia->readString("Ropewalk:doFlavour = off");
    pythia->readString("Ropewalk:tInit = 1.5");
    pythia->readString("Ropewalk:rCutOff = 10.0");
    pythia->readString("Ropewalk:limitMom =  on");
    pythia->readString("Ropewalk:pTcut = 2.0");
    pythia->readString("Ropewalk:deltat = 0.1");
    pythia->readString("Ropewalk:deltay = 0.1");
    pythia->readString("Ropewalk:tShove = 1.");
    pythia->readString("Ropewalk:deltat = 0.1");
    pythia->readString("Ropewalk:gAmplitude = 10.0");
    pythia->readString("Ropewalk:gExponent = 1.0");
    pythia->readString("Ropewalk:r0 = 0.41");
    pythia->readString("Ropewalk:m0 = 0.2");
    pythia->readString("PartonVertex:setVertex = on");
    pythia->readString("PartonVertex:protonRadius = 0.7");
    pythia->readString("PartonVertex:emissionWidth = 0.1");
    }
  pythia->init();
//  if (reportDebug(__FUNCTION__))
//    {
//    pythia->settings.listAll();
//    pythia->settings.listChanged();
//    }
  if (reportEnd(__FUNCTION__)) { /* no ops */ };
}

void PythiaEventGenerator::execute()
{
  Event & event = *Manager<Event>::getObjectAt(0);
  event.reset();
  particleFactory->reset();
  pythia->next();
  int nParticleToCopy   = pythia->event.size();
  if (pythia->event[0].id() == 90)
    {
    nParticleToCopy--;
    }

  for (int i = 1; i <= nParticleToCopy; i++)
    {
    int pdg = pythia->event[i].id();
    if (saveFinalOnly    && !pythia->event[i].isFinal()) continue;
    if (!saveQuarks      && abs(pdg)<10) continue; // skip quarks, gluons, etc
    if (!saveNeutrinos   && (abs(pdg)==12 || abs(pdg)==14  || abs(pdg)==16 || abs(pdg)==18)) continue;
    if (!savePhotons     && pdg==22) continue;
    if (!saveGaugeBosons && (abs(pdg)>22 && abs(pdg)<40)) continue;
    ParticleType * particleType = particleDb->findPdgCode(pdg);
    if (particleType==nullptr) throw NullPointerException("particleType==nullptr",__FUNCTION__);
    Particle & particle = *particleFactory->getNextObject();
    particle.setType(particleType);
    particle.setLive(1);
    particle.setPxPyPzE(pythia->event[i].px(),pythia->event[i].py(),pythia->event[i].pz(),pythia->event[i].e());
    particle.setXYZT(pythia->event[i].xProd(),pythia->event[i].yProd(),pythia->event[i].zProd(),pythia->event[i].tProd());
    event.addParticle(&particle);
    }
  EventAccountant::incrementEventsAccepted(0);
  TaskAccountant::increment();
}

void PythiaEventGenerator::finalize()
{
  if (reportDebug(__FUNCTION__))
    {
    //&& getValueBool("Print:Statistics")
    printCR();
    printLine();
    pythia->stat();
    printLine();
    printCR();
    }
  delete pythia;
  if (reportEnd(__FUNCTION__)) { /* no ops */};
}
} // namespace CAP
