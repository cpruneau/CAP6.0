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
#ifndef CAP__DerivedHistoIterator
#define CAP__DerivedHistoIterator
#include "HistogramTask.hpp"

namespace CAP
{

class DerivedHistoIterator : public HistogramTask
{
protected:

  long nEventsProcessed;   //!< Number of events processed in the current file
  long sumEventsProcessed; //!< Sum of the number of events processes.
  long * nEventsAccepted;    //!< Number of events accepted in the current file for each event filter
  long * sumEventsAccepted;  //!< Cumulated number of events accepted for each event filter


  String appendedString;
  int    defaultGroupSize;
  int    nInputFile;
  int    maximumDepth;
  int    nEventFilters;

 // bool   histogramForceRewrite;


public:
  
  DerivedHistoIterator();
  virtual ~DerivedHistoIterator() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void execute();

  ClassDef(DerivedHistoIterator,0)
};

} // namespace CAP

#endif /* CAP__DerivedHistoIterator */
