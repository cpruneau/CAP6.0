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
#include "CalibrationManager.hpp"

ClassImp(CAP::CalibrationManager);

namespace CAP
{

CalibrationManager:: CalibrationManager()
:
EventTask(),
calibsCreate             (false),
calibsReset              (false),
calibsClear              (false),
calibsForceRewrite       (false),
calibsImport             (false),
calibsImportPath         (""),
calibsImportFile         (""),
calibsExport             (false),
calibsExportAsRoot       (false),
calibsExportAsText       (false),
calibsExportPath         (""),
calibsExportFile         ("")
{
  appendClassName("CalibrationManager");
}

void CalibrationManager::setDefaultConfiguration()
{
  addProperty("CalibrationsCreate",          calibsCreate);
  addProperty("CalibrationsReset",           calibsReset);
  addProperty("CalibrationsClear",           calibsClear);
  addProperty("CalibrationsForceRewrite",    calibsForceRewrite);
  addProperty("CalibrationsImport",          calibsImport);
  addProperty("CalibrationsImportPath",      calibsImportPath);
  addProperty("CalibrationsImportFile",      calibsImportFile);
  addProperty("CalibrationsExport",          calibsExport);
  addProperty("CalibrationsExportAsRoot",    calibsExportAsRoot);
  addProperty("CalibrationsExportAsText",    calibsExportAsText);
  addProperty("CalibrationsExportPath",      calibsExportPath);
  addProperty("CalibrationsExportFile",      calibsExportFile);

}

void CalibrationManager::configure
{
  EventTask::configure();
  calibsCreate       = getValueBool("CalibrationsCreate");
  calibsReset        = getValueBool("CalibrationsReset");
  calibsClear        = getValueBool("CalibrationsClear");
  calibsForceRewrite = getValueBool("CalibrationsForceRewrite");
  calibsImport       = getValueBool("CalibrationsImport");
  calibsImportPath   = getValueString("CalibrationsImportPath");
  calibsImportFile   = getValueString("CalibrationsImportFile");
  calibsExport       = getValueBool("CalibrationsExport");
  calibsExportAsRoot = getValueBool("CalibrationsExportAsRoot");
  calibsExportAsText = getValueBool("CalibrationsExportAsText");
  calibsExportPath   = getValueString("CalibrationsExportPath");
  calibsExportFile   = getValueString("CalibrationsExportFile");
}

void CalibrationManager::execute()
{
  if (reportStart(__FUNCTION__))
    ;
  incrementTaskExecuted();
  if (calibsImport)  importCalibration();
  if (calibsExport)  exportCalibration();
  if (reportEnd(__FUNCTION__))
    ;
}

void CalibrationManager::importCalibration()
{
}

void CalibrationManager::exportCalibration()
{
}
