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
#ifndef CAP__FileIterator
#define CAP__FileIterator
#include "HistogramTask.hpp"

namespace CAP
{

//!
//! File  Iterator designed to repeat the same series of tasks on many files/directories
//!
class FileIterator : public HistogramTask
{
public:

  FileIterator();
  FileIterator(const FileIterator & task);
  FileIterator operator=(const FileIterator & task);
  virtual ~FileIterator() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void execute();

//  void addFileName(const String &  name);
//  void addFileNames(const vector<String> &  names);
//  void addFileNames(unsigned int n, String** names);
//  void addFileNames(const String pathName,
//                    VectorString  includePatterns,
//                    VectorString  excludePatterns);
//  unsigned int getNSelectedFileNames() const;
//  unsigned int getCurrentFileIndex() const;
//  VectorString  & getSelectedFileNames();
//  const VectorString  & getSelectedFileNames() const;

protected:

  bool isGrid;
  int nBunches;
  int nSubBunches;
  String bunchLabel;
  String subBunchLabel;

  ClassDef(FileIterator,0)
};

} // namespace CAP

#endif /* CAP__FileIterator */
