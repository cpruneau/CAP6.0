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
#include "TSystem.h"
#include "TSystemDirectory.h"
#include "TSystemFile.h"
#include "TParameter.h"
#include "Task.hpp"


ClassImp(CAP::Task);

namespace CAP
{

Task::Task()
:
ConfigurationManager     (),
NamedObject              (),
FileManager              (),
TaskAccountant           (),
Timer                    (),
EnvironmentVariables     (),
parent                   (nullptr),
subTasks                 ()
{
  setClassName("Task");
  setInstanceName("Task");
  setName("Task");
  setTitle("Task");
  setVersion("1.0");
  setConfigurationPath("Task");
}

Task::Task(const Task & task)
: 
ConfigurationManager     (task),
NamedObject              (task),
FileManager              (task),
TaskAccountant           (task),
Timer                    (task),
EnvironmentVariables     (task),
parent                   (task.parent),
subTasks                 (task.subTasks)
{     }

Task & Task::operator=(const Task & task)
{
  if (this!=&task)
    {
    ConfigurationManager::operator=(task);
    NamedObject::operator=(task);
    FileManager::operator=(task);
    TaskAccountant::operator=(task);
    Timer::operator=(task);
    EnvironmentVariables::operator=(task);
    parent    = task.parent;
    subTasks  = task.subTasks;
    }
  return *this;
}

void Task::setDefaultConfiguration()
{
  setConfigurationPath(getFullTaskPath());
}

void Task::configure()
{
  ConfigurationManager::configure();
}


void Task::initialize()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  initializeTaskExecuted();
  if (hasSubTasks())  initializeSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void Task::execute()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  incrementTaskExecuted();
  if (hasSubTasks()) executeSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void Task::finalize()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  closeRootInputFiles();
  closeRootOutputFiles();
  closeStreamInputFiles();
  closeStreamOutputFiles();
  if (hasSubTasks()) finalizeSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void Task::partial()
{
  if (reportInfo(__FUNCTION__))  { /* */ };
  if (hasSubTasks()) partialSubTasks();
  if (reportEnd(__FUNCTION__))  { /* */ };
}

void Task::reset()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  resetTaskExecuted();
  if (hasSubTasks()) resetSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void Task::clear()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  resetTaskExecuted();
  if (hasSubTasks()) clearSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void Task::print(std::ostream & output,  int style, int size) const
{
  printLine();
  NamedObject::print(output,style,size);
  ConfigurationManager::print(output,style,size);
  printValue("FullTaskPath", getFullTaskPath());
  TaskAccountant::print(output,style,size);
  printValue("nSubTasks",subTasks.size());
  for (auto & subTask : subTasks)
    subTask->print(output,style,size);
  printLine();
}


void Task::configureSubTasks()
{
  for (auto & subtask : subTasks) subtask->configure();
}

void Task::initializeSubTasks()
{
  for (auto & subtask : subTasks) subtask->initialize();
}

void Task::executeSubTasks()
{
  for (auto & subtask : subTasks) subtask->execute();
}

void Task::finalizeSubTasks()
{
  for (auto & subtask : subTasks) subtask->finalize();
}

void Task::partialSubTasks()
{
  for (auto & subtask : subTasks) subtask->partial();
}

void Task::resetSubTasks()
{
  for (auto & subtask : subTasks) subtask->reset();
}

void Task::clearSubTasks()
{
  for (auto & subtask : subTasks) subtask->clear();
}

Task * Task::addSubTask(Task * task)
{
  if (!task)  throw TaskException("Given task pointer is null.", "Task::addSubTask(Task * task)");
  if (task==this) throw TaskException("Given task pointer is self.", "Task::addSubTask(Task * task)");
  subTasks.push_back( task );
  if (task->parent == nullptr)  task->setParent(this);
  if (reportDebug(__FUNCTION__)) std::cout << "Added task " << task->getName() << " to task " << getName() << std::endl;
  return task;
}

Task * Task::getTaskAt(int depth)
{
  //if (depth == 0) return this;
  Task * task = this;
  Task * parentTask = task->getParent();
  for (int k=0; k<depth; k++)
  {
    task = parentTask;
    if (task==nullptr) break;
    parentTask = task->getParent();
  }
  return task;
}


const Task * Task::getTaskAt(int depth) const
{
  //if (depth == 0) return this;
  const Task * task = this;
  const Task * parentTask = task->getParent();
  //std::cout <<  "0 : name: " << task->getName();
  for (int k=0; k<depth; k++)
  {
    task = parentTask;
    if (task==nullptr) break;
    //std::cout << k <<  " : name: " << task->getName();
    parentTask = task->getParent();
  }
  return task;
}

String Task::getReverseTaskPath(int depth) const
{
  String result;
  String work;
  String colon = String(":");
  for (int k=0; k<=depth; k++)
  {
    const Task * task = getTaskAt(k);
    if (task!=nullptr)
    {
      work = task->getName();
      work += colon;
      if (result.Length()>0)
      {
        result = work + result;
      }
      else
      {
        result = work;
      }
    }
  }
  return result;
}

std::vector<String> Task::getTaskPathTokens() const
{
  std::vector<String> paths;
  int n = getNAncestors();
  for (int k=n; k>=0; k--)
  {
    const Task * task= getTaskAt(k);
    if (task==nullptr)
    {
    String s="task==nullptr at k="; s+=k;
    throw TaskException(s,"Task::getTaskPathTokens()");
    }
    else
    {
      paths.push_back(task->getName());
    }
  }
  return paths;
}


String Task::getTaskPath(int depth) const
{
  String path = "";
  std::vector<String> paths = getTaskPathTokens();
  for (int k=0; k<=depth; k++)
  {
    path += paths[k];
    path += ":";
  }
  return path;
}


String Task::getFullTaskPath() const
{
  String path;
  int n = getNAncestors();
  path = getReverseTaskPath(n);
  return path;
}


int Task::getNAncestors() const
{
  int count = 0;
  if (parent==nullptr) return count;
  Task * parentTask = parent;
  while (parentTask!=nullptr)
  {
    count++;
    if (parentTask!=nullptr)
      parentTask = parentTask->getParent();
    else
      break;
  }
  return count;
}


//void Task::printIntroMessage(const String & option __attribute__ (( unused )) ) const
//{
//  if (reportInfo(__FUNCTION__))
//    {
//    std::cout << "No intro message available for this task. Sorry!" << std::endl;
//    }
//}
//
//void Task::printHelp(const String & option __attribute__ (( unused )) ) const
//{
//  if (reportInfo(__FUNCTION__))
//    {
//    std::cout << "No help message available for this task. Sorry!" << std::endl;
//    }
//}
//
//void Task::printVersion(const String & option __attribute__ (( unused )) ) const
//{
//  if (reportInfo(__FUNCTION__))
//    {
//    std::cout << "Version:" << getVersion() << std::endl;
//    }
//}

///  ///  




} // namespace CAP


