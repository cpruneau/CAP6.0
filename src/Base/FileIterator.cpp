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
#include "FileIterator.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "Timer.hpp"

ClassImp(CAP::FileIterator);

namespace CAP
{

FileIterator::FileIterator()
:
HistogramTask()
{
  appendClassName("FileIterator");
  setName("FileIterator");
  setTitle("FileIterator");
}

FileIterator::FileIterator(const FileIterator & task)
:
HistogramTask(task)
{    }

FileIterator FileIterator::operator=(const FileIterator & task)
{
  if (this!=&task) HistogramTask::operator=(task);
  return *this;
}

void FileIterator::setDefaultConfiguration()
{
  String path = "Default";
  HistogramTask::setDefaultConfiguration();
  configuration.addProperty("FileIterator:nLevels",0);
}

void FileIterator::configure()
{
  HistogramTask::configure();
}

void FileIterator::initialize()
{
// initialization is done within the execute command...
}

void FileIterator::finalize()
{
  // finalize is done within the execute command...
}


void FileIterator::execute()
{
  if (reportStart(__FUNCTION__)) {  /* no ops */ };
  start();
  TaskAccountant::increment();
  std::vector<String> importPathNames;
  std::vector<String> exportPathNames;
  String importPath = getHistoImportPath();
  String exportPath = getHistoExportPath();
  printValue("FileIterator::execute()   importPath",importPath);
  int nLevels = configuration.getValueInt("FileIterator:nLevels");
  switch (nLevels)
    {
      case 0:
      {
      String name = importPath; name += "/";
      importPathNames.push_back(name);
      name = exportPath;  name += "/";
      exportPathNames.push_back(name);
      break;
      }

      case 1: // one folder with many subfolders
      {
      importPathNames = listDirsIn(importPath,true);
      exportPathNames = importPathNames;
      break;
      }
    }
  if (importPathNames.size()<1 )
    throw TaskException("Attempting to execute file iterator with no selected files",__FUNCTION__);
  unsigned int nPaths = importPathNames.size();
  printValue("FileIterator::execute() nPaths", nPaths);
  for (auto & subtask : subTasks)
    {
    String calculatorName = subtask->getName();
    calculatorName += ":";
    for (unsigned int iPath=0; iPath<nPaths; iPath++)
      {
      cout << "CalculatorName:" << calculatorName << endl;
      Configuration & conf = subtask->getConfiguration();
      conf.addProperty(calculatorName+"HistogramsImportPath",importPathNames[iPath]);
      conf.addProperty(calculatorName+"HistogramsExportPath",exportPathNames[iPath]);
      cout << "FileIterator finds HistogramsImportFile: " << conf.getValueString(calculatorName+"HistogramsImportFile") << endl;;
      cout << "FileIterator finds HistogramsExportFile: " << conf.getValueString(calculatorName+"HistogramsExportFile") << endl;;
      subtask->initialize();
      subtask->execute();
      subtask->finalize();
      subtask->reset();
      }
    }
  stop();
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printTimeInfo();
    printLine();
    }
}

} // namespace CAP
