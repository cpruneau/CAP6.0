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

#include "HistogramSet.hpp"
#include "Task.hpp"

ClassImp(CAP::HistogramSet);

namespace CAP
{

HistogramSet::HistogramSet()
:
name("UnnamedSet"),
groups()
{ }

HistogramSet::HistogramSet(const String & name)
:
name(name),
groups()
{ }

HistogramSet::HistogramSet(const HistogramSet & set)
:
name(set.name),
groups(set.groups) // shallow copy
{ }

HistogramSet HistogramSet::operator=(const HistogramSet & set)
{
  if (this!=&set)
    {
    name = set.name;
    groups = set.groups;
    }
  return *this;
}

Size_t HistogramSet::size() const
{
  return groups.size();
}


void HistogramSet::addGroup(HistogramGroup* group)
{
  groups.push_back(group);
}

HistogramGroup & HistogramSet::getGroupAt(unsigned int index)
{
  Size_t n = groups.size();
  if (index<0 || index>=n) throw OutOfBoundException(__FUNCTION__);
  return *(groups[index]);
}

void HistogramSet::setParentTask(Task * parentTask)
{
  for (auto & group : groups) group->setParentTask(parentTask);
}

void HistogramSet::setConfiguration(const Configuration & config)
{
  for (auto & group : groups) group->setConfiguration(config);
}

vector<HistogramGroup*> & HistogramSet::getGroups()
{
  return groups;
}

const vector<HistogramGroup*> & HistogramSet::getGroups() const
{
  return groups;
}

//!
//!Reset all histograms to zero
//!
void HistogramSet::resetHistograms()
{
  for (auto & group : groups) group->resetHistograms();
}

//!
//!Delete all histograms
//!
void HistogramSet::clearHistograms()
{
  for (auto & group : groups) 
    {
    group->clearHistograms();
    delete group;
    }
  groups.clear();
}

//!
//! Create all histograms from the given file
//!
void HistogramSet::createHistograms()
{
  for (auto & group : groups) group->createHistograms();
}

//!
//! Load all histograms from the given file
//!
void HistogramSet::importHistograms(TFile & file)
{
  for (auto & group : groups) group->importHistograms(file);
}

//!
//! Save all histograms to the given file
//!
void HistogramSet::exportHistograms(TFile & file)
{
  //printValue("HistogramSet::exportHistograms(TFile & file) groups.size()", groups.size());
  for (auto & group : groups) group->exportHistograms(file);
}

void HistogramSet::exportHistograms(ofstream & file)
{
  for (auto & group : groups) group->exportHistograms(file);
}

//!
//! Scale all histograms tby the given factor
//!
void HistogramSet::scaleHistograms(double factor)
{
  for (auto & group : groups) group->scaleHistograms(factor);
}

//!
//! Scale all histograms tby the given factorw
//!
void HistogramSet::scaleHistograms(vector<double> &  factors)
{
  unsigned int n = groups.size();
  for (unsigned int k=0; k<n; k++) groups[k]->scaleHistograms(factors[k]);
}
} //namespace CAP
