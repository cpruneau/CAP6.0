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
#include "ModelManager.hpp"
using CAP::ModelManager;
using namespace std;

ClassImp(ModelManager);

ModelManager::ModelManager()
:
EventTask(_name,_configuration),
modelTypeId              (0),
modelTypeName            (""),
modelIniImport           (false),
modelIniImportPath       (""),
modelIniImportFile       (""),
modelIniExport           (false),
modelIniExportPath       (""),
modelIniExportFile       (""),
modelXmlImport           (false),
modelXmlImportPath       (""),
modelXmlImportFile       (""),
modelXmlExport           (false),
modelXmlExportPath       (""),
modelXmlExportFile       ("")
{
  appendClassName("ModelManager");
  setInstanceName("ModelManager");
  setName("ModelManager");
  setTitle("ModelManager");
  setVersion("1.0");
}

ModelManager::ModelManager(const String & _name,
                            const Configuration & _configuration)
:
EventTask(_name,_configuration),
modelTypeId              (0),
modelTypeName            (""),
modelIniImport           (false),
modelIniImportPath       (""),
modelIniImportFile       (""),
modelIniExport           (false),
modelIniExportPath       (""),
modelIniExportFile       (""),
modelXmlImport           (false),
modelXmlImportPath       (""),
modelXmlImportFile       (""),
modelXmlExport           (false),
modelXmlExportPath       (""),
modelXmlExportFile       (""),
{
  appendClassName("ModelManager");
  setInstanceName("ModelManager");
  setName("ModelManager");
  setTitle("ModelManager");
  setVersion("1.0");
}

ModelManager::ModelManager(const ModelManager & task)
:
EventTask(task),
modelTypeId              (task.modelTypeId),
modelTypeName            (task.modelTypeName),
modelIniImport           (task.modelIniImport),
modelIniImportPath       (task.modelIniImportPath),
modelIniImportFile       (task.modelIniImportFile),
modelIniExport           (task.modelIniExport),
modelIniExportPath       (task.modelIniExportPath),
modelIniExportFile       (task.modelIniExportFile),
modelXmlImport           (task.modelXmlImport),
modelXmlImportPath       (task.modelXmlImportPath),
modelXmlImportFile       (task.modelXmlImportFile),
modelXmlExport           (task.modelXmlExport),
modelXmlExportPath       (task.modelXmlExportPath),
modelXmlExportFile       (task.modelXmlExportFile)
{   }


ModelManager & ModelManager::operator=(const ModelManager & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    modelTypeId           =   task.modelTypeId;
    modelTypeName         =   task.modelTypeName;
    modelIniImport        =   task.modelIniImport;
    modelIniImportPath    =   task.modelIniImportPath;
    modelIniImportFile    =   task.modelIniImportFile;
    modelIniExport        =   task.modelIniExport;
    modelIniExportPath    =   task.modelIniExportPath;
    modelIniExportFile    =   task.modelIniExportFile;
    modelXmlImport        =   task.modelXmlImport;
    modelXmlImportPath    =   task.modelXmlImportPath;
    modelXmlImportFile    =   task.modelXmlImportFile;
    modelXmlExport        =   task.modelXmlExport;
    modelXmlExportPath    =   task.modelXmlExportPath;
    modelXmlExportFile    =   task.modelXmlExportFile;
    }
  return *this;
}


void ModelManager::setDefaultConfiguration()
{
  addProperty("ModelTypeId",       modelTypeId);
  addProperty("ModelTypeName",     modelTypeName);
  addProperty("ModelIniImport",    modelIniImport);
  addProperty("ModelIniImportPath",modelIniImportPath);
  addProperty("ModelIniImportFile",modelIniImportFile);
  addProperty("ModelIniExport",    modelIniExport );
  addProperty("ModelIniExportPath",modelIniExportPath);
  addProperty("ModelIniExportFile",modelIniExportFile);
  addProperty("ModelXmlImport",    modelXmlImport);
  addProperty("ModelXmlImportPath",modelXmlImportPath);
  addProperty("ModelXmlImportFile",modelXmlImportFile);
  addProperty("ModelXmlExport",    modelXmlExport);
  addProperty("ModelXmlExportPath",modelXmlExportPath);
  addProperty("ModelXmlExportFile",modelXmlExportFile);
}

void ModelManager::configure()
{
  EventTask::configure();
  modelTypeId              = getValueInt("ModelTypeId"                  );
  modelTypeName            = getValueString("ModelTypeName"             );
  modelIniImport           = getValueBool("ModelIniImport"              );
  modelIniImportPath       = getValueString("ModelIniImportPath"        );
  modelIniImportFile       = getValueString("ModelIniImportFile"        );
  modelIniExport           = getValueBool("ModelIniExport"              );
  modelIniExportPath       = getValueString("ModelIniExportPath"        );
  modelIniExportFile       = getValueString("ModelIniExportFile"        );
  modelXmlImport           = getValueBool("ModelXmlImport"              );
  modelXmlImportPath       = getValueString("ModelXmlImportPath"        );
  modelXmlImportFile       = getValueString("ModelXmlImportFile"        );
  modelXmlExport           = getValueBool("ModelXmlExport"              );
  modelXmlExportPath       = getValueString("ModelXmlExportPath"        );
  modelXmlExportFile       = getValueString("ModelXmlExportFile"        );
  setSeverity();
}

void ModelManager::execute()
{
  if (reportStart(__FUNCTION__))
    ;
  incrementTaskExecuted();
  if (modelIniImport)  importModel();
  if (modelIniExport)  exportModel();
  if (reportEnd(__FUNCTION__))
    ;
}

void ModelManager::importModel()
{
}

void ModelManager::exportModel()
{
}
