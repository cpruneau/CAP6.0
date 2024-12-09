/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
 *
 * *********************************************************************/
#ifndef CAP__RootChainManager
#define CAP__RootChainManager
#include "TChain.h"
#include "TTree.h"
#include "TBranch.h"
#include "Aliases.hpp"

namespace CAP
{

class RootChainManager
{

public:

  RootChainManager();
  RootChainManager(const RootChainManager & manager);
  RootChainManager operator=(const RootChainManager & manager);
  virtual ~RootChainManager() {}

  int getClonesMaxArraySize() const;
  void getClonesMaxArraySize(int value);
  void Show(Long64_t entry);
  Int_t GetEntry(Long64_t entry);
  Long64_t LoadTree(Long64_t entry);

  //!
  //!Get pointer to the root input chain
  //!
  TChain  * getChain();
  void setTreeIndex(int value);
  int getTreeIndex() const;
  void initializeImportTree(const String & treeName);
  void initializeExportTree(const String & treeName);
  void importEvent();
  void exportEvent();

protected:

  TChain  *chain;     //!pointer to the analyzed (input)  TTree or TChain
  Int_t    treeIndex; //!current Tree number in an input  TChain
  TFile   *dataFile;
  Long64_t nEntries; //! number of entries in an input TTree or TChain
  Long64_t nBytes;
  Long64_t nb;
  long entryIndex;
  int  clonesMaxArraySize;

  ClassDef(RootChainManager,0)

};

}
#endif /* CAP_RootTreeReader */
