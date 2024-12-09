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
#include "RootChainManager.hpp"
#include "ParticlesExceptions.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::RootChainManager);

namespace CAP
{

RootChainManager::RootChainManager()
:
chain(nullptr),
treeIndex(0),
dataFile(nullptr),
nEntries(0),
nBytes(0),
nb(0),
entryIndex(0),
clonesMaxArraySize(10000)
{
  /* no ops */
}

RootChainManager::RootChainManager(const RootChainManager & manager)
:
chain(manager.chain),
treeIndex(manager.treeIndex),
dataFile(manager.dataFile),
nEntries(manager.nEntries),
nBytes(manager.nBytes),
nb(manager.nb),
entryIndex(manager.entryIndex),
clonesMaxArraySize(manager.clonesMaxArraySize)
{
  /* no ops */
}

RootChainManager RootChainManager::operator=(const RootChainManager & manager)
{
  if (this!=&manager)
    {
    chain      = manager.chain;
    treeIndex  = manager.treeIndex;
    dataFile   = manager.dataFile;
    nEntries   = manager.nEntries;
    nBytes     = manager.nBytes;
    nb         = manager.nb;
    entryIndex = manager.entryIndex;
    clonesMaxArraySize = manager.clonesMaxArraySize;
    }
  return *this;
}

int RootChainManager::getClonesMaxArraySize() const
{
  return clonesMaxArraySize;
}

void RootChainManager::getClonesMaxArraySize(int value)
{
  clonesMaxArraySize = value;
}

void RootChainManager::Show(Long64_t entry)
{
  if (!chain) throw TaskException("No chain","RootChainManager::Show(Long64_t entry)");
  chain->Show(entry);
}

Int_t RootChainManager::GetEntry(Long64_t entry)
{
  if (!chain) throw TaskException("No chain","RootChainManager::GetEntry(Long64_t entry)");
  return chain->GetEntry(entry);
}


Long64_t RootChainManager::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!chain) throw TaskException("No chain","RootChainManager::LoadTree(Long64_t entry)");
  Long64_t centry = chain->LoadTree(entry);
  if (centry < 0) return centry;
  if (chain->GetTreeNumber() != treeIndex)
    {
    treeIndex = chain->GetTreeNumber();
    }
  return centry;
}

//!
//!Get pointer to the root input chain
//!
TChain  * RootChainManager::getChain()
{
  return chain;
}


inline void RootChainManager::setTreeIndex(int value)
{
  treeIndex = value;
}

inline int RootChainManager::getTreeIndex() const
{
  return treeIndex;
}

void RootChainManager::initializeImportTree(const String & treeName)
{
  chain = new TChain(treeName);
  if (!chain) throw TaskException("No chain",__FUNCTION__);
}

void RootChainManager::initializeExportTree(const String & treeName __attribute__((unused)) )
{
  throw TaskException("No chain",__FUNCTION__);
}


void RootChainManager::importEvent()
{
  setTreeIndex(-1);
  entryIndex = 0;
  nEntries = chain->GetEntriesFast();
  if (nEntries < 1) throw TaskException("nEntries < 1",__FUNCTION__);
  nBytes = 0;
  nb = 0;
}


void RootChainManager::exportEvent()
{
  throw TaskException("Not available",__FUNCTION__);
}
} // namespace CAP
