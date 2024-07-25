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
#include "TaskAccountant.hpp"
#include "RootHelpers.hpp"
#include "PrintHelpers.hpp"
#include "Exceptions.hpp"

ClassImp(CAP::TaskAccountant);

namespace CAP
{

TaskAccountant::TaskAccountant()
:
nTaskExecuted(0)
{  /* no ops */ }

TaskAccountant::TaskAccountant(const TaskAccountant & source)
:
nTaskExecuted(source.nTaskExecuted)
{  /* no ops */ }

TaskAccountant & TaskAccountant::operator=(const TaskAccountant & source)
{
  if (this!=&source)
    {
    nTaskExecuted = source.nTaskExecuted;
    }
  return *this;
}

TaskAccountant::~TaskAccountant()
{
  clear();
}

void TaskAccountant::reset()
{
  nTaskExecuted = 0;
}

void TaskAccountant::clear()
{
  reset();
}

void TaskAccountant::increment()
{
  nTaskExecuted++;
}

long TaskAccountant::getNExecuted() const
{
  return nTaskExecuted;
}

void TaskAccountant::print(std::ostream & os, int style, int size) const
{
  printCR(os);
  printLine(os);
  printValue("Task executed",nTaskExecuted,os,style,size);
}

void TaskAccountant::exportNEexecutedTask(TFile & outputFile)
{
  String name = "nTaskExecuted";
  exportParameter(outputFile,name,nTaskExecuted);
}

long TaskAccountant::importNEexecutedTask(TFile & inputFile)
{
  String parameterName;
  parameterName  = "nTaskExecuted";
  nTaskExecuted   = importParameter(inputFile,parameterName);
  return nTaskExecuted;
}


} // namespace CAP



