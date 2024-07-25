/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau,
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2022
 *
 * *********************************************************************/
#include "ParticleDbManager.hpp"
#include "ParticleDbExceptions.hpp"


using CAP::ParticleDb;
using CAP::ParticleDbManager;
using namespace std;

ClassImp(ParticleDbManager);

ParticleDbManager::ParticleDbManager()
:
particleDb(nullptr)
{  }

ParticleDbManager::ParticleDbManager(const ParticleDbManager & manager)
:
particleDb(manager.particleDb)
{ }

ParticleDbManager & ParticleDbManager::operator=(const ParticleDbManager & manager)
{
  if (this!=&manager)
    {
    particleDb = manager.particleDb;
    }
  return *this;
}

ParticleDb & ParticleDbManager::getParticleDb()
{
  if (!particleDb)
    {
    if (defaultParticleDb)
      particleDb = defaultParticleDb;
    else
      throw CAP::NoSelectedParticleDbException(__FUNCTION__);
    }
  return *particleDb;
}

const ParticleDb & ParticleDbManager::getParticleDb() const
{
  if (!particleDb) 
    throw CAP::NoSelectedParticleDbException(__FUNCTION__);
  return *particleDb;
}


void ParticleDbManager::selectParticleDb(const String & name)
{
  for (auto & particleDbCandidate : particleDbStore)
    {
    if (particleDbCandidate->getName().EqualTo(name))
      particleDb = particleDbCandidate;
    }
  throw CAP::NonExistingParticleDbException(name,__FUNCTION__);
}

// class wide member and functions (static)

ParticleDb * ParticleDbManager::defaultParticleDb = nullptr;
vector<ParticleDb*> ParticleDbManager::particleDbStore;

bool ParticleDbManager::isDbDefined(const String & name)
{
  for (auto & particleDb : particleDbStore)
    {
    if (particleDb->getName().EqualTo(name)) return true;
    }
  return false;
}

ParticleDb * ParticleDbManager::createDefaultParticleDb(const String & name)
{
  if (isDbDefined(name))
    throw CAP::ExistingParticleDbException(name,__FUNCTION__);
  defaultParticleDb = new ParticleDb();
  defaultParticleDb->setName(name);
  particleDbStore.push_back(defaultParticleDb);
  return defaultParticleDb;
}

ParticleDb * ParticleDbManager::getDefaultParticleDb()
{
  if (!defaultParticleDb)
    throw CAP::NonExistingParticleDbException("Default",__FUNCTION__);
  return defaultParticleDb;
}

void ParticleDbManager::setDefaultParticleDb(ParticleDb * particleDb)
{
  if (particleDb==nullptr)
    throw CAP::NullPtrParticleDbException(__FUNCTION__);
  defaultParticleDb = particleDb;
  if (findDb(particleDb)<0) particleDbStore.push_back(defaultParticleDb); // not quite right....
}

void ParticleDbManager::addParticleDb(ParticleDb * _particleDb)
{
  if (_particleDb==nullptr)
    throw CAP::NullPtrParticleDbException(__FUNCTION__);
  for (auto & particleDb : particleDbStore)
    {
    if (particleDb == _particleDb) 
      throw ExistingParticleDbException(_particleDb->getName(),__FUNCTION__);
    }
  particleDbStore.push_back(_particleDb);
}

CAP::Size_t ParticleDbManager::dbStoreSize()
{
  return particleDbStore.size();
}

ParticleDb* ParticleDbManager::getParticleDbAt(unsigned int index)
{
  if (index<particleDbStore.size()) return particleDbStore[index];
  else
  throw CAP::InvalidIndexParticleDbException(index,__FUNCTION__);
}

ParticleDb* ParticleDbManager::getParticleDb(const String & name)
{
  for (auto & particleDb : particleDbStore)
    {
    if (particleDb->getName().EqualTo(name)) return particleDb;
    }
  return nullptr;
}

int ParticleDbManager::findDb(const ParticleDb * db)
{
  int index = 0;
  for (auto & particleDb : particleDbStore)
    {
    if (particleDb==db) return index;
    index++;
    }
  return -1; // not found
}

vector<ParticleDb*> ParticleDbManager::getParticleDbs()
{
  return particleDbStore;
}

void ParticleDbManager::removeDb(ParticleDb * particleDb)
{
  int pos = findDb(particleDb);
  if (pos>=0)
    particleDbStore.erase(particleDbStore.begin()+pos);
  else
    throw CAP::UnknownParticleDbException(particleDb->getName(),__FUNCTION__);
}

void ParticleDbManager::clearDbs()
{
  for (auto & particleDb : particleDbStore)
    {
    particleDb->clear();
    delete particleDb;
    }
}
