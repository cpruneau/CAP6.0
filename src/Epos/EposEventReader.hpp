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
#ifndef CAP__EposEventReader
#define CAP__EposEventReader
#include "EventTask.hpp"
#include "RootChainManager.hpp"

namespace CAP
{


//!
//! Task to compute to read EPOS events and make them available for analysis in CAP. .
//!
//!
class EposEventReader : public EventTask, public RootChainManager
{
public:

  EposEventReader();
  virtual ~EposEventReader() {}
  void setDefaultConfiguration();
  void configure();
  virtual void initialize();
  void execute();

protected:
  
  static const int arraySize = 40000;

   // Declaration of leaf types
   Int_t           events;
   Int_t           nParticles;
   Float_t         impact;
   Int_t           pid[arraySize];   //[Mult]
   Float_t         px[arraySize];   //[Mult]
   Float_t         py[arraySize];   //[Mult]
   Float_t         pz[arraySize];   //[Mult]
   Float_t         e[arraySize];   //[Mult]

   // List of branches
   TBranch        *b_Events;   //!
   TBranch        *b_Mult;   //!
   TBranch        *b_Impact;   //!
   TBranch        *b_PID;   //!
   TBranch        *b_Px;   //!
   TBranch        *b_Py;   //!
   TBranch        *b_Pz;   //!
   TBranch        *b_E;   //!
 
  ClassDef(EposEventReader,0)
};

}


#endif /* CAP__EposEventReader */
