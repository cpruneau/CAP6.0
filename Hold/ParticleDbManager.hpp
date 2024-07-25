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
#ifndef CAP__ParticleDbManager
#define CAP__ParticleDbManager
#include "Aliases.hpp"
#include "ParticleDb.hpp"

namespace CAP
{

//!
class ParticleDbManager
{
public:
  
  ParticleDbManager();
  ParticleDbManager(const ParticleDbManager & manager);
  ParticleDbManager & operator=(const ParticleDbManager & manager);
  virtual ~ParticleDbManager() {}

  void createParticleDb(const String & name);
  void useParticleDb(const  String &  name);
  bool ownsParticleDb(unsigned int index);
  void resetParticleDb(unsigned int index);
  void clearParticleDb(unsigned int index);
  void deleteParticleDb(unsigned int index);
  void resetParticleDb();
  void clearParticleDb();
  void deleteParticleDb();
  vector<EventFilter*> & getParticleDbs();
  const vector<EventFilter*> & getParticleDbs() const;
  EventFilter* getParticleDbNamed(const String & name);
  int getNParticleDbs()


  virtual  ParticleDb & getParticleDb();
  virtual  const ParticleDb & getParticleDb() const;




  static ParticleDb * createDefaultParticleDb(const String & name);
  static void setDefaultParticleDb(ParticleDb * particleDb);
  static bool isDbDefined(const String & name);
  static ParticleDb * getDefaultParticleDb();
  static void addParticleDb(ParticleDb * particleDb);
  static Size_t dbStoreSize();
  static ParticleDb* getParticleDbAt(unsigned int);
  static ParticleDb* getParticleDb(const String & name);
  static int findDb(const ParticleDb * db);
  static vector<ParticleDb*> getParticleDbs();
  static void removeDb(ParticleDb * particleDb);
  static void clearDbs();

  static void createStoreParticleDbNamed(const String & name);
  static ParticleDb* getStoreParticleDbNamed(const String & name);
  static int getNStoreDbs();

protected:

  // particle db used by derived task
  vector<String>       particleDbNames;
  vector<ParticleDb*>  particleDbs;
  vector<bool>         eventFilterOwnerships;

  // class wide members

  static ParticleDb * defaultParticleDb;
  static vector<ParticleDb*> particleDbStore;

  ClassDef(ParticleDbManager,0)
};

}

#endif /* CAP__ParticleDbManager */
