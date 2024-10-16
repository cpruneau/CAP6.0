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
#include "Task.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::Task);

namespace CAP
{

Task::Task()
:
ConfigurationManager     (),
NamedObject              (),
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
}

Task::Task(const Task & task)
: 
ConfigurationManager     (task),
NamedObject              (task),
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
  setConfigurationPath(getName());
//  setConfigurationPath(getFullTaskPath());
}

void Task::configure()
{
  ConfigurationManager::configure();
}


void Task::initialize()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  EnvironmentVariables::initialize();
  TaskAccountant::reset();
  if (hasSubTasks())  initializeSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void Task::execute()
{
  /* no ops */
}

void Task::finalize()
{
  if (reportStart(__FUNCTION__))  { /* */ };
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
  TaskAccountant::reset();
  if (hasSubTasks()) resetSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void Task::clear()
{
  if (reportStart(__FUNCTION__))  { /* */ };
  TaskAccountant::clear();
  if (hasSubTasks()) clearSubTasks();
  if (reportEnd(__FUNCTION__)) { /* */ };
}

void Task::print(std::ostream & output,  int style, int size) const
{
  printLine();
  NamedObject::print(output,style,size);
  ConfigurationManager::print(output,style,size);
  EnvironmentVariables::print(output,style,size);
  TaskAccountant::print(output,style,size);
  printSubTasks(output,style,size);
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

void Task::printSubTasks(std::ostream & output,
                         int style,
                         int size) const
{
  printValue("nSubTasks",subTasks.size());
  for (auto & subTask : subTasks) subTask->print(output,style,size);
}


Task * Task::addSubTask(Task * task)
{
  if (!task)  throw TaskException("Given task pointer is null.", "Task::addSubTask(Task * task)");
  if (task==this) throw TaskException("Given task pointer is self.", "Task::addSubTask(Task * task)");
  subTasks.push_back( task );
  if (task->parent == nullptr)  task->setParent(this);
  if (reportDebug(__FUNCTION__)) std::cout << std::endl << "Added task " << task->getName() << " to task " << getName() << std::endl;
  return task;
}

std::vector<Task*> & Task::getSubTaks()
{
  return subTasks;
}

const std::vector<Task*> & Task::getSubTaks() const
{
  return subTasks;
}

bool Task::hasSubTasks()  const
{
  return subTasks.size()>0;
}

unsigned int Task::getNSubTasks() const
{
  return subTasks.size();
}

Task * Task::getSubTaskAt(unsigned int index)
{
  return subTasks[index];
}


String Task::getParentTaskName() const
{
  String bn =  parent->getName();
  return bn;
}


bool Task::hasParent() const
{
  return parent!=nullptr;
}

Task * Task::getParent() const
{
  return parent;
}

void Task::setParent(Task * _parent)
{
  parent = _parent;
}

String Task::getParentName() const
{
  if (parent!=nullptr) return parent->getName();
  else
    return String("");
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

} // namespace CAP


