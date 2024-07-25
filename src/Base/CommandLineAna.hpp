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
#ifndef CAP__CommandLineAna
#define CAP__CommandLineAna
#include <iostream>
#include <vector>
#include "TClass.h"
#include "TFile.h"
#include "Aliases.hpp"
#include "Exceptions.hpp"
#include "ConfigurationManager.hpp"
#include "NamedObject.hpp"
#include "FileManager.hpp"
#include "Timer.hpp"

namespace CAP
{

class Task
:
public ConfigurationManager,
public NamedObject,
public FileManager,
public TaskAccountant,
public Timer,
public EnvironmentVariables
{
protected:
  //!
  //! Pointer to parent task if any
  //!
  Task * parent;

  //!
  //! Array of pointers to subTasks called by this task instance, once per event analyzed (or iteration generated by EventIterator task). If this instance carries out
  //! initialize, finalize, execute type operations, these are performed BEFORE the corresponding operations by the subTasks.
  //!
  std::vector<Task*> subTasks;

public:

  Task();
  Task(const Task & task);
  Task & operator=(const Task & task);
  virtual ~Task() {}

  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void partial();
  virtual void finalize();
  virtual void reset();
  virtual void clear();
  virtual void print(std::ostream & output=std::cout,  int style=0, int size=50) const;

  void configureSubTasks();
  void initializeSubTasks();
  void executeSubTasks();
  void finalizeSubTasks();
  void partialSubTasks();
  void resetSubTasks();
  void clearSubTasks();
  bool hasSubTasks()  const
  {
  return subTasks.size()>0;
  }

  unsigned int getNSubTasks() const
  {
  return subTasks.size();
  }

  Task * getSubTaskAt(unsigned int index)
  {
  return subTasks[index];
  }

  Task *  addSubTask(Task * task);

  virtual void setDefaultConfiguration();



  inline String getParentTaskName() const
  {
  String bn =  getValueString("HistoBaseName");
  return bn;
  }

 
  bool hasParent() const
  {
  return parent!=nullptr;
  }

  Task * getParent() const
  {
  return parent;
  }

  void setParent(Task * _parent)
  {
  parent = _parent;
  }

  String getParentName() const
  {
  if (parent!=nullptr) return parent->getName();
  else
    return String("");
  }

  Task * getTaskAt(int depth);
  const Task * getTaskAt(int depth) const;
  String getReverseTaskPath(int depth=0) const;
  VectorString getTaskPathTokens() const;
  String getTaskPath(int depth=0) const;
  String getFullTaskPath() const;
  int getNAncestors() const;
  virtual void printIntroMessage(const String & option) const;
  virtual void printHelp(const String & option) const;
  virtual void printVersion(const String & option) const;

  ClassDef(Task,0)
};

}

#endif /* CAP__Task */