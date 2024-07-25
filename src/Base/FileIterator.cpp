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
#include "FileIterator.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "Timer.hpp"

ClassImp(CAP::FileIterator);

namespace CAP
{

FileIterator::FileIterator()
:
HistogramTask(),
isGrid(0),
nBunches(0),
nSubBunches(0),
bunchLabel("BUNCH"),
subBunchLabel("SUBBUNCH")
{
  appendClassName("FileIterator");
  setName("FileIterator");
  setTitle("FileIterator");
}

FileIterator::FileIterator(const FileIterator & task)
:
HistogramTask(task),
isGrid(task.isGrid),
nBunches(task.nBunches),
nSubBunches(task.nSubBunches),
bunchLabel(task.bunchLabel),
subBunchLabel(task.subBunchLabel)
{    }

FileIterator FileIterator::operator=(const FileIterator & task)
{
  if (this!=&task)
    {
    HistogramTask::operator=(task),
    isGrid            = task.isGrid;
    nBunches          = task.nBunches;
    nSubBunches       = task.nSubBunches;
    bunchLabel        = task.bunchLabel;
    subBunchLabel     = task.subBunchLabel;
    }
  return *this;
}

void FileIterator::setDefaultConfiguration()
{
  HistogramTask::setDefaultConfiguration();
  addProperty("isGrid",isGrid);
  addProperty("nBunches",nBunches);
  addProperty("nSubBunches",nSubBunches);
  addProperty("bunchLabel",bunchLabel);
  addProperty("subBunchLabel",subBunchLabel);
}

void FileIterator::configure()
{
  HistogramTask::configure();
  isGrid        = getValueBool("isGrid");
  nBunches      = getValueInt("nBunches");
  nSubBunches   = getValueInt("nSubBunches");
  bunchLabel    = getValueString("BunchLabel");
  subBunchLabel = getValueString("SubBunchLabel");
}

void FileIterator::execute()
{
  if (reportStart(__FUNCTION__)) {  /* no ops */ };
  start();
  TaskAccountant:increment();
  VectorString  importPathNames;
  VectorString  exportPathNames;
  String importPath = getHistoImportPath();
  String exportPath = getHistoExportPath();
  if (isGrid)
    {
    for (int iBunch=0;iBunch<nBunches;iBunch++)
      {
      for (int iSubBunch=0;iSubBunch<nSubBunches;iSubBunch++)
        {
        String name = importPath;
        name += "/";
        name += bunchLabel;
        name += iBunch;
        name += "/";
        name += subBunchLabel;
        name += iSubBunch;
        name += "/";
        importPathNames.push_back(name);
        name = exportPath;
        name += "/";
        name += bunchLabel;
        name += "/";
        name += subBunchLabel;
        name += "/";
        exportPathNames.push_back(name);
        }
      }
    }
  else
    {
    String name = importPath;
    name += "/";
    importPathNames.push_back(name);
    name = exportPath;
    name += "/";
    exportPathNames.push_back(name);
    }
  if (importPathNames.size()<1 )
    throw TaskException("Attempting to execute file iterator with no selected files",__FUNCTION__);

    unsigned int nPaths = importPathNames.size();
    for (unsigned int iPath=0; iPath<nPaths; iPath++)
      {
      configuration.addProperty("HistogramsImportPath",importPathNames[iPath]);
      configuration.addProperty("HistogramsExportPath",exportPathNames[iPath]);
      for (auto & subtask : subTasks)
        {
      subtask->setRequestedConfiguration(configuration);
      subtask->configure();
      subtask->initialize();
      subtask->execute();
      subtask->finalize();
      subtask->clear();
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
//
//void FileIterator::addFileName(const String &  name)
//{
//  if (name.Length()<5) throw TaskException("Invalid file name", __FUNCTION__);
//  selectedFileNames.push_back(name);
//}
//
////!
////! Add several  file  templates for use by this task iterator
////!
//void FileIterator::addFileNames(const vector<String> &  names)
//{
//  if (reportStart(__FUNCTION__)) {  /* no ops */ };
//  if (names.size()<1) throw TaskException("Given Vector<String> is empty", __FUNCTION__);
//  for (auto & name : names)
//    {
//    if (reportInfo(__FUNCTION__))
//      {
//      printCR();
//      printValue("Adding file",name);
//      }
//    if (name.Length()<5) throw TaskException("Invalid file name", __FUNCTION__);
//    selectedFileNames.push_back(name);
//    }
//  if (reportEnd(__FUNCTION__)){  /* no ops */ };
//}
//
////!
////! Add several  file  templates for use by this task iterator
////!
//void FileIterator::addFileNames(const String pathName,
//                                std::vector<String>   includePatterns,
//                                std::vector<String>   excludePatterns)
//{
//  if (reportStart(__FUNCTION__)) {  /* no ops */ };
//  std::vector<String>   fileList = listFilesInDir(pathName,".root");
//  unsigned int nNames = fileList.size();
//  if (reportDebug(__FUNCTION__))
//    {
//    CAP::printCR();
//    CAP::printValue("fileList.size()",nNames);
//    CAP::printValue("includePatterns.size()",includePatterns.size());
//    CAP::printValue("excludePatterns.size()",excludePatterns.size());
//    }
//  for (auto & name : fileList)
//    {
//    bool include = true;
//    for (unsigned int kInclude=0; kInclude<includePatterns.size(); kInclude++)
//      {
//      String pattern = includePatterns[kInclude];
//      if (!name.Contains(pattern)) { include = false; break;}
//      }
//    if (!include) continue;
//    for (unsigned int kExclude=0; kExclude<excludePatterns.size(); kExclude++)
//      {
//      String pattern = excludePatterns[kExclude];
//      if (name.Contains(pattern))
//        {
//        include = false;
//        break;
//        }
//      }
//    if (include)
//      {
//      String name2  = removeRootExtension(name);
//      String check = pathName+name2;
//      selectedFileNames.push_back(pathName+name2);
//      }
//    }
//  if (reportEnd(__FUNCTION__)) {  /* no ops */ };
//}
//
//unsigned int FileIterator::getNSelectedFileNames() const
//{
//  return selectedFileNames.size();
//}
//
//unsigned int FileIterator::getCurrentFileIndex() const
//{
//  return currentFileIndex;
//}
//
//VectorString  & FileIterator::getSelectedFileNames()
//{
//  return selectedFileNames;
//}
//
//const VectorString  & FileIterator::getSelectedFileNames() const
//{
//  return selectedFileNames;
//}


} // namespace CAP
