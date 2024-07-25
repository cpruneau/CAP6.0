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
#ifndef CAP__ParticleDbTask
#define CAP__ParticleDbTask
#include "Task.hpp"
#include "Manager.hpp"
#include "ParticleDb.hpp"

namespace CAP
{

//!
//! Task used for the single purpose of loading a particle type table. The particle type and properties are loaded from a specially formatted file.
//! The task can optionally output a copy or reduced copy of the file to a location and file name to a user specified location.
//!
//! Configuration parameters include the input file path and name of the file containing the data to be read. If the task is meant to output a copy of the file,
//! the file path and name of the output file should also be specified. Configuration parameters are as follows
//!
//! - EventsImport [true] : whether paddPropertyarticle type data will be read from file
//! - EventsImportPath [getenv("CAP_DATA") : folder (file path) where to find  the file to be read.
//! - EventsImportFileName ["ParticleTypeData.dat"] : name of the file containing particle type PDG data to be read in.
//! - EventsExport [true] : whether particle type data will be written to file
//! - EventsExportPath [getenv("CAP_DATA") : folder (file path) where to write a particle type PDG data file.
//! - EventsExportFileName ["NewParticleTypeData.dat"] : name of the file containing on output particle type PDG data.
//!
//!
class ParticleDbTask 
: 
public Task,
public Manager<ParticleDb>
{
public:
  
  ParticleDbTask();
  ParticleDbTask(const ParticleDbTask & task);
  ParticleDbTask operator=(const ParticleDbTask & task);
  virtual ~ParticleDbTask() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void importParticleDb();
  virtual void exportParticleDb();
  virtual void dbAnalyzer();

  virtual void enableAllParticles();
  virtual void enableNeutralParticles();
  virtual void enableChargedParticles();
  virtual void enableSelectedParticles();
  virtual void disableAllParticles();
  virtual void disableNeutralParticles();
  virtual void disableChargedParticles();
  virtual void disableSelectedParticles();

  virtual void disableAllDecays();
  virtual void disableNeutralDecays();
  virtual void disableChargedDecays();
  virtual void disableWeakDecays();
  virtual void disableLongLivedWith(double lifeTime);
  virtual void disableShortLivedWith(double lifeTime);
  virtual void disableSelectedDecays();

  virtual void enableAllDecays();
  virtual void enableNeutralDecays();
  virtual void enableChargedDecays();
  virtual void enableWeakDecays();
  virtual void enableLongLivedWith(double lifeTime);
  virtual void enableShortLivedWith(double lifeTime);
  virtual void enableSelectedDecays();
  virtual void listParticleStatus();

protected:

  bool   dbImport;
  String dbImportPath;
  String dbImportFile;
  String dbImportDecaysFile;
  bool   dbExport;
  String dbExportPath;
  String dbExportFile;
  String dbExportDecaysFile;

  bool dbDisableNeutralParticles;
  bool dbDisableChargedParticles;
  bool dbDisableSelected;

  bool dbEnableAllParticles;
  bool dbEnableNeutralParticles;
  bool dbEnableChargedParticles;
  bool dbEnableSelected;

  bool dbDisableNeutralDecays;
  bool dbDisableChargedDecays;
  bool dbDisableSelectedDecays;
  bool dbDisableWeakDecays;
  bool dbDisableLongLivedDecays;
  bool dbDisableShortLivedDecays;

  bool dbEnableAllDecays;
  bool dbEnableNeutralDecays;
  bool dbEnableChargedDecays;
  bool dbEnableSelectedDecays;
  bool dbEnableWeakDecays;
  bool dbEnableLongLivedDecays;
  bool dbEnableShortLivedDecays;
  double dbMaxLifeTime;

  ParticleDb * particleDb;

  ClassDef(ParticleDbTask,0)
};

}

#endif /* CAP__ParticleDbTask */
