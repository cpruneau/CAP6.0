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
#ifndef CAP__ParticleDbParser_CS
#define CAP__ParticleDbParser_CS
#include "PropertiesParser.hpp"
#include "ParticleDb.hpp"


namespace CAP
{

class ParticleDbParser_CS : public PropertiesParser
{
public:

  ParticleDbParser_CS();
  ParticleDbParser_CS(MessageLogger::Severity _severity);
  virtual ~ParticleDbParser_CS() {}
  virtual void readDb(ParticleDb   & _particleDb, ifstream & inputFile);


  ClassDef(ParticleDbParser_CS,0)

};

} // namespace CAP

#endif /* ParticleDbParser_CS_hpp */
