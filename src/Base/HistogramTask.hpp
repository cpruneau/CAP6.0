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
#ifndef CAP__HistogramTask
#define CAP__HistogramTask
#include "Task.hpp"

namespace CAP
{

class HistogramGroup;
class HistogramSet;


//!
//!HistogramTask manages several sets (vectors) of HistogramGroup objects.
//!Each set is an array (implemented as a vector) of Histogram groups. This enables
//!the management of several groups for each set and the managerment of several sets.
//!Example: In single particle analyses, one can have basic and derived histogram groups. The groups
//!can be design to work with specific collision centrality and particle species. It would then be
//!convenient to have two sets: basic and derived, with the same number of groups, i.e., with a one-to-one mapping
//!of the basic and derived groups, for an arbitrary number of collision centralities and particle species.
//!Evidently, other clustering can also be used. This class is typically used by Analyzer type classes to
//!facilitate the mangement of histogram groups.
//!
class HistogramTask : public Task
{
protected:

  bool   histosScale;
  bool   histosForceRewrite;
  String histosImportPath;
  String histosImportFile;
  String histosExportPath;
  String histosExportFile;
  bool   histosExportPartial;
  long   histosExportPartialCount;
  long   histosExportMaxPerPartial;
  vector<HistogramSet*> histogramSets;

  TFile * rootInputFile;
  TFile * rootOutputFile;

public:

  HistogramTask();
  HistogramTask(const HistogramTask & task);
  HistogramTask operator=(const HistogramTask & task);
  virtual ~HistogramTask() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void finalize();
  virtual void reset();
  virtual void clear();
  virtual void createHistograms();
  virtual void importHistograms();
  virtual void importHistograms(TFile & inputFile);
  virtual void exportHistograms();
  virtual void exportHistograms(const String & exportPath, const String & exportFile);
  virtual void exportHistograms(TFile & outputFile);
  virtual void exportHistograms(ofstream & out);

  inline int getNSets()
  {
  return histogramSets.size();
  }

  HistogramSet & getSetAt(unsigned int index);

  HistogramGroup & getGroupAt(unsigned int iSet, unsigned int iGroup);

  //!
  //! Scale histogram
  //!
  virtual void scaleHistograms();
  virtual void scaleHistograms(double factor);
  virtual void scaleHistograms(vector<double> factor);


//  virtual void plotHistograms();
   virtual void printHistograms();


  //!
  //! Loads histogram groups used by this task. This method opens the root file identified in the Configuration object owned by this task. If the file exists,
  //! it calls the  HistogramsImport(TFile & inputFile) to actually load the relevant groups.
  //!
  //virtual void importDerivedHistograms();

  //!
  //! Calls the reset method of all the histogram groups owned by this task.
  //!
  virtual void resetHistograms();
  //!
  //! Calls the clear method of all the histogram groups owned by this task. This effectively delete the histogram groups. Only call this method if you know
  //! what you are doing..
  //!
  virtual void clearHistograms();


  //virtual void partial(const String & outputPathBase);

  void clearSets();

  void addSet(const String & name);

  HistogramSet * getSetAt(int index);

  void addGroupInSet(unsigned int index, HistogramGroup * group);


//  void setHistogramFileNames(const String inputName, const String outputName)
//  {
//  addProperty("FileFromParent", true);
//  addProperty("HistogramImportFileName", inputName);
//  addProperty("HistogramOuputFileName", outputName);
//  }

  String getHistosImportPath() const { return histosImportPath; }
  String getHistosExportPath() const { return histosExportPath; }
  String getHistosImportFile() const { return histosImportFile; }
  String getHistosExportFile() const { return histosExportFile; }

  void setHistosImportPath(const String & s)  { histosImportPath = s; }
  void setHistosExportPath(const String & s)  { histosExportPath = s; }
  void setHistosImportFile(const String & s)  { histosImportFile = s; }
  void setHistosExportFile(const String & s)  { histosExportFile = s; }

  void setHistosScale(bool v)         {  histosScale = v;}
  void setHistosForceRewrite(bool v)  {  histosForceRewrite = v;}
 
  virtual String getHistoImportPath();
  virtual String getHistoExportPath();


  ClassDef(HistogramTask,0)
};

} // namespace CAP

#endif /* CAP__HistogramTask */
