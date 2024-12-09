/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Chun Shen
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 * This code is adapted from Chun Shen's code
 * for the purpose of computing hadronic resonance
 * correlations..
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
 *
 * *********************************************************************/
#include "ParticleDecayMode.hpp"
#include "ParticleDbExceptions.hpp"
#include "PrintHelpers.hpp"

//#include "SelectionGenerator.hpp"

ClassImp(CAP::ParticleDecayMode);

using CAP::ParticleDecayMode;
using CAP::ParticleType;
using CAP::ParticleDb;


ParticleDecayMode::ParticleDecayMode()
:
branchingRatio(1.0),
childrenPdgCodes(),
childrenTypes()
{
  childrenPdgCodes.clear();
  childrenTypes.clear();
}

ParticleDecayMode::ParticleDecayMode(const ParticleDecayMode & source)
:
branchingRatio(source.branchingRatio),
childrenPdgCodes(source.childrenPdgCodes),
childrenTypes(source.childrenTypes)
{  }

ParticleDecayMode::~ParticleDecayMode()
{
  childrenPdgCodes.clear();
  childrenTypes.clear();
}

ParticleDecayMode & ParticleDecayMode::operator=(const ParticleDecayMode & source)
{
  if (this!=&source)
    {
    branchingRatio    = source.branchingRatio;
    childrenPdgCodes  = source.childrenPdgCodes;
    childrenTypes     = source.childrenTypes;
    }
  return *this;
}

// Assumes the mode was defined based on pdg codes
// build the table for types
void ParticleDecayMode::resolveTypes(ParticleDb & particleDb)
{
  int n = childrenPdgCodes.size();
  if (n<1) return;
  ParticleType * type;
  for (int k=0; k<n; k++)
    {
    type = particleDb.findPdgCode( childrenPdgCodes[k] );
    if (type)
      {
      childrenTypes.push_back(type);
      }
    else
      {
      throw ParticleDecayException(" Unknown type  ",__FUNCTION__);
      }
    }
}

void   ParticleDecayMode::setBranchingRatio(double _branchingRatio)
{
  branchingRatio = _branchingRatio;
}

double ParticleDecayMode::getBranchingRatio() const
{
  return branchingRatio;
}

int    ParticleDecayMode::getNChildren() const
{
  return childrenPdgCodes.size();
}

void   ParticleDecayMode::addChild(int pdgCode)
{
  childrenPdgCodes.push_back(pdgCode);
}

void   ParticleDecayMode::addChild(ParticleType* type)
{
  childrenPdgCodes.push_back(type->getPdgCode());
  childrenTypes.push_back(type);
}

const vector<int> & ParticleDecayMode::getChildrenPdgCodes() const
{
  return childrenPdgCodes;
}


vector<int> & ParticleDecayMode::getChildrenPdgCodes()
{
  return childrenPdgCodes;
}

const vector<ParticleType*> & ParticleDecayMode::getChildrenTypes() const
{
  return childrenTypes;
}

vector<ParticleType*> & ParticleDecayMode::getChildrenTypes()
{
  return childrenTypes;
}

const ParticleType & ParticleDecayMode::getChildType(unsigned int index) const
{
  return * childrenTypes[index];
}

ParticleType & ParticleDecayMode::getChildType(unsigned int index)
{
  return * childrenTypes[index];
}


int ParticleDecayMode::getChildPdgCode(unsigned int index) const
{
  if (index<childrenPdgCodes.size())
    return childrenPdgCodes[index];
  else
    return -1;
}

int ParticleDecayMode::getChildPdgCode(unsigned int index)
{
  if (index<childrenPdgCodes.size())
    return childrenPdgCodes[index];
  else
    return -1;
}

void ParticleDecayMode::print(std::ostream & os, int style, int size)
{
  printValue("Br",branchingRatio,os,style,size);
  for (unsigned int k=0; k<childrenPdgCodes.size(); k++)
    printValue(childrenTypes[k]->getName(),childrenPdgCodes[k],os,style,size);
  printCR(os,1);
}

