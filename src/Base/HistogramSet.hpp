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
#ifndef CAP__HistogramSet
#define CAP__HistogramSet
#include "Aliases.hpp"
#include "HistogramGroup.hpp"

namespace CAP
{

//!
//! A histogram set is vector of HistogramGroups
//!
class HistogramSet
{
protected:

  String name;
  std::vector<HistogramGroup*> groups;

public:

  HistogramSet();
  HistogramSet(const String & name);
  HistogramSet(const HistogramSet & set);
  virtual ~HistogramSet() {}
  HistogramSet operator=(const HistogramSet & set);
  Size_t size() const;
  void addGroup(HistogramGroup* group);
  HistogramGroup & getGroupAt(unsigned int index);

  void setParentTask(Task * parentTask);
  void setConfiguration(const Configuration & config);
  std::vector<HistogramGroup*> & getGroups();
  const std::vector<HistogramGroup*> & getGroups() const;

  virtual void resetHistograms();
  virtual void clearHistograms();
  virtual void createHistograms();
  virtual void importHistograms(TFile & file);
  virtual void exportHistograms(TFile & file);
  virtual void exportHistograms(std::ofstream & file);
  virtual void scaleHistograms(double factor);
  virtual void scaleHistograms(std::vector<double> &  factors);

  ClassDef(HistogramSet,0)
};


} // namespace CAP

#endif /* CAP__Histograms */
