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
#ifndef CAP__ParticleDb
#define CAP__ParticleDb
#include "ParticleDbExceptions.hpp"
#include "NamedObject.hpp"
#include "ParticleType.hpp"

namespace CAP
{

class ParticleType;

class ParticleDb : public NamedObject
{
public:

  // const String& _name, bool _ownership, Severity logLevel
  ParticleDb();
  ParticleDb(const ParticleDb & analyzer);
  ParticleDb & operator=(const ParticleDb & analyzer);

  virtual ~ParticleDb() {}
  void sortByMass();
  ParticleDb * extractDb(int option);
  int findIndexForType(ParticleType * type);
  int findIndexForName(const String & name);
  int findIndexForPdgCode(int pdgCode);
  int findIndexForPrivateCode(int privateCode);
  bool containsTypeNamed(const String & aName);

  Size_t size() { return particleTypes.size();}
  std::vector<ParticleType*> & getParticleTypes();
  const std::vector<ParticleType*> & getParticleTypes() const;

  void resolveTypes();
  void mapAntiParticleIndices();
  void setupDecayGenerator();
  ParticleType * findPdgCode(int pdgCode);
  ParticleType * findPrivateCode(int privateCode);

  void addParticleType(ParticleType * particleType);
  ParticleType * getParticleType(const String & name);
  ParticleType * getParticleType(unsigned int index);
  
  virtual void reset(){};
  virtual void clear();

  std::vector<int> getListOfPdgCodes();

  std::ostream & print(std::ostream & os=std::cout, int style=0, int size=12);
  std::ostream & printDecays(std::ostream & os=std::cout, int style=0, int size=12);

protected:
  void cloneAll(const ParticleDb & db);

  std::vector<ParticleType*> particleTypes;

  ClassDef(ParticleDb,0)
};

} //namespace CAP

#endif  // CAP__ParticleDb

