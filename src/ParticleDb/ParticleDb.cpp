/* **********************************************************************
 * Copyright (C) 2019-2022, Claude Pruneau, Victor Gonzalez, Sumit Basu
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
 *
 * *********************************************************************/
#include "ParticleDb.hpp"
#include "Manager.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::ParticleDb);
ClassImp(CAP::Manager<CAP::ParticleDb>);

namespace CAP
{

ParticleDb::ParticleDb()
:
NamedObject(),
particleTypes()
{  }

ParticleDb::ParticleDb(const ParticleDb & db)
:
NamedObject(db),
particleTypes(db.particleTypes)
{   }

ParticleDb & ParticleDb::operator=(const ParticleDb & db)
{
  if (this!=&db)
  {
    NamedObject::operator=(db);
    cloneAll(db);
  }
  return *this;
}

void ParticleDb::cloneAll(const ParticleDb & db)
{
  for (auto & particleType : db.particleTypes)
    particleTypes.push_back( new CAP::ParticleType(*particleType) );
}

std::vector<ParticleType*> & ParticleDb::getParticleTypes()
{
  return particleTypes;
}

const std::vector<ParticleType*> & ParticleDb::getParticleTypes() const
{
  return particleTypes;
}

void ParticleDb::sortByMass()
{
  int n = size();
  for (int i = 1; i<n; i++)
    {
    int k = i;
    int j = i - 1;
    //m1 = objects[k]->getMass();
    //m2 = objects[j]->getMass();
    while (j >= 0 && (particleTypes[k]->getMass() < particleTypes[k]->getMass()) )
      {
      CAP::ParticleType* temp = particleTypes[j];
      particleTypes[j] = particleTypes[k];
      particleTypes[k] = temp;
      k--;
      j--;
      }
    }
}

void ParticleDb::resolveTypes()
{
  for (auto & particleType : particleTypes)
  {
    int nModes = particleType->getNDecayModes();
    for (int iMode = 0; iMode<nModes; iMode++)
      particleType->getDecayMode(iMode).resolveTypes(*this);
  }
}

void ParticleDb::setupDecayGenerator()
{
  for (auto & particleType : particleTypes)
  {
    if (particleType->hasDecayModes()) particleType->setupDecayGenerator();
  }
}


// ================================================================================================
// Extract a subset of this collection based on the given ctriterion
// option : types selected
//      0 : stable particle types
//      1 :
//      2 : unstable
//      3 : mesons
//      4 : baryons
//      5 : leptons
//      6 : fermions
//      7 : bosons
// ================================================================================================
ParticleDb *  ParticleDb::extractDb(int option)
{
  ParticleDb * db = new ParticleDb();
  for (auto & particleType : particleTypes)
  {
    bool selected = false;
    switch (option)
    {
      case 0:  if (particleType->isStable()&& !particleType->isPhoton()) selected = true; break;
      case 1:  if (particleType->isDecayDisabled()&& !particleType->isPhoton()) selected = true; break;
      case 2:  if (!particleType->isStable()) selected = true; break;
      case 3:  if (!particleType->isDecayDisabled()) selected = true; break;
      case 4:  if (particleType->isMeson()) selected = true; break;
      case 5:  if (particleType->isBaryon()) selected = true; break;
      case 6:  if (particleType->isLepton()) selected = true; break;
      case 7:  if (particleType->isFermion()) selected = true; break;
      case 8:  if (particleType->isBoson()) selected = true; break;
    }
    if (selected) db->addParticleType(particleType);
  }
  return db;
}

int ParticleDb::findIndexForType(CAP::ParticleType * type)
{
  int index = 0;
  for (auto & particleType : particleTypes)
  {
    if (type==particleType) return index;
    index++;
  }
  return -1;
}

int ParticleDb::findIndexForName(const CAP::String & name)
{
  int index = 0;
  for (auto & particleType : particleTypes)
  {
    if (particleType->getName().EqualTo(name)) return index;
    index++;
  }
  return -1;
}


int ParticleDb::findIndexForPdgCode(int pdgCode)
{
  int index = 0;
  for (auto & particleType : particleTypes)
  {
    if (pdgCode == particleType->getPdgCode()) return index;
    index++;
  }
  return -1;
}


int ParticleDb::findIndexForPrivateCode(int privateCode)
{
  int index = 0;
  for (auto & particleType : particleTypes)
  {
    if (privateCode == particleType->getPrivateCode()) return index;
    index++;
  }
  return -1;
}

bool ParticleDb::containsTypeNamed(const CAP::String & name)
{
  for (auto & particleType : particleTypes)
  {
    if (particleType->getName().EqualTo(name)) return true;
  }
  return false;
}

CAP::ParticleType * ParticleDb::findPdgCode(int pdgCode)
{
  for (auto & particleType : particleTypes)
  {
    if (pdgCode == particleType->getPdgCode()) return particleType;
  }
  // code not found in the current table.
  // create new type and add to the table.
  CAP::ParticleType * particleType = new CAP::ParticleType();
  particleType->setName("unknown");
  particleType->setTitle("unknown");
  particleType->setPdgCode(pdgCode);
  particleTypes.push_back(particleType);
  printCR();
  printValue("Added new type with pdgCode",pdgCode);
  return particleType;
}

CAP::ParticleType * ParticleDb::findPrivateCode(int privateCode)
{
  for (auto & particleType : particleTypes)
  {
    if (privateCode == particleType->getPdgCode()) return particleType;
  }
  return nullptr;
}

void ParticleDb::addParticleType(CAP::ParticleType * particleType)
{
  particleTypes.push_back(particleType);
}

CAP::ParticleType * ParticleDb::getParticleType(const CAP::String & name)
{
  for (auto & particleType : particleTypes)
    {
    if (particleType->getName().EqualTo(name)) return particleType;
    }
  throw UndefinedParticleDbException(name,__FUNCTION__);
}


CAP::ParticleType * ParticleDb::getParticleType(unsigned int index)
{
  if (index<particleTypes.size())
    return particleTypes[index];
  throw InvalidIndexParticleDbException(index,__FUNCTION__);
}

void ParticleDb::clear()
{
  for (auto & particleType : particleTypes) delete particleType;
  particleTypes.clear();
}

//!
//!Find the antiparticles of all particles in the DB and
//!store their DB index for fast retrieval in some functions.
//!(assumes no sorting is done after this operation)
//!Antiparticles have -pdgCode of their particle and viceversa
//!Particles that have no antiparticle will store -1 to indicates
//!they do not have an anti-particle.
//!
void ParticleDb::mapAntiParticleIndices()
{
  int index = 0;
  int indexBar = 0;
  for (auto & particleType : particleTypes)
  {
    indexBar = findIndexForPdgCode(-particleType->getPdgCode());
    if (indexBar>=0)
      particleType->setAntiParticleIndex(indexBar);
    else
      particleType->setAntiParticleIndex(index); // self (has no antiparticle)
    index++;
  }
}
// int value)


std::ostream & ParticleDb::print(std::ostream & os, int style, int size)
{
  printLine(os,style,size);
  printString("ParticleDb",os, style, size);
  os <<  fixed << setw(5)  << "k";
  os <<  fixed << setw(10) << "PDG";
  os <<  fixed << setw(10) << "Name";
  os <<  fixed << setw(12) << "Title";
  os <<  fixed << setw(12) << "Mass";
  os <<  fixed << setw(12) << "Width";
  os <<  fixed << setw(9)  << "Charge";
  os <<  fixed << setw(9)  << "Spin";
  os <<  fixed << setw(9)  << "Isospin";
  os <<  fixed << setw(9)  << "Isospin3";
  os <<  fixed << setw(5)  << "Nq";
  os <<  fixed << setw(5)  << "Naq";
  os <<  fixed << setw(5)  << "Ns";
  os <<  fixed << setw(5)  << "Nas";
  os <<  fixed << setw(5)  << "Nc";
  os <<  fixed << setw(5)  << "Nac";
  os <<  fixed << setw(5)  << "Nb";
  os <<  fixed << setw(5)  << "Nab";
  os <<  fixed << setw(5)  << "Nt";
  os <<  fixed << setw(5)  << "Nat";
  os <<  fixed << setw(5)  << "L(e)";
  os <<  fixed << setw(5)  << "L(m)";
  os <<  fixed << setw(5)  << "L(t)";
  os <<  fixed << setw(5)  << "S";
  os <<  fixed << setw(5)  << "W";
  printLine(os,style,size);
  for (auto & particleType : particleTypes) particleType->print(os,style,size);
  return os;
}

std::ostream & ParticleDb::printDecays(std::ostream & os, int style, int size)
{
  printLine(os,style,size);  os << std::setw(10) << "Pdg";
  os << setw(20) << "Title";
  os << setw(20) << "Mass(GeV/c2)";
  os << setw(20) << "Width(GeV/c2)" << endl;
  printLine(os,style,size);
  for (auto & particleType : particleTypes) particleType->printDecays(os,style,size);
  return os;
}


std::vector<int> ParticleDb::getListOfPdgCodes()
{
  std::vector<int> pdgCodes;
  for (auto & particleType : particleTypes)
    pdgCodes.push_back(particleType->getPdgCode());
  return pdgCodes;
}


} // namespace CAP
