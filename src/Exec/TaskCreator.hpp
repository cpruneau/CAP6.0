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
#ifndef CAP__TaskCreator
#define CAP__TaskCreator
#include "Task.hpp"
using std::vector;

namespace CAP
{
class TaskCreator : public Task
{
public:
  
  TaskCreator();
  TaskCreator(const TaskCreator & task);
  virtual ~TaskCreator() {}
  TaskCreator & operator=(const TaskCreator & task);
  virtual void setDefaultConfiguration();
  virtual void configure();
  void execute();
  void setTargetTaskName(const String & _targetTaskName);
  Task * getCreatedTask();

protected:

  String targetTaskName;
  Task * targetTask;

  virtual void configureDbs(Task * task,
                            const String  & taskReferenceName,
                            Configuration & requestedConfiguration);
  virtual void configureEventsStreams(Task * task,
                                      const String  & taskReferenceName,
                                      Configuration & requestedConfiguration);
  virtual void configureEventFilters(Task * task,
                                     const String  & taskReferenceName,
                                     Configuration & requestedConfiguration);
  virtual void configureParticleFilters(Task * task,
                                        const String  & taskReferenceName,
                                        Configuration & requestedConfiguration);
  virtual void configureEfficiencyFilters(Task * _task,
                                          const String  & taskReferenceName,
                                          Configuration & requestedConfiguration);
  virtual void configureJetFilters(Task * task,
                                   const String  & taskReferenceName,
                                   Configuration & requestedConfiguration);

  virtual void configureSubtasks(Task * task,
                                 const String  & taskReferenceName,
                                 Configuration & requestedConfiguration);

  virtual Task * createTask(const String & taskTypeName);

  virtual Task * createTask(Task *parentTask,
                            const String & baseName,
                            Configuration & requestedConfiguration);

protected:

  ClassDef(TaskCreator,0)
};

}

#endif /* CAP_TaskCreator */


