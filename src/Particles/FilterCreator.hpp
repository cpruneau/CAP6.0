
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
#ifndef CAP__FilterCreator
#define CAP__FilterCreator
#include "EventTask.hpp"
#include "Event.hpp"
#include "EventFilter.hpp"
#include "ParticleType.hpp"
#include "ParticleDb.hpp"

namespace CAP
{
class FilterCreator 
:
public EventTask
{

public:
  
  FilterCreator();
  FilterCreator(const FilterCreator & task);
  FilterCreator & operator=(const FilterCreator & task);
  virtual ~FilterCreator() {}

  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();

protected:

  void createEventFilter(const String & name,
                         const String & title,
                         const String & typeName,
                         const vector<String>  & conditionTypes,
                         const vector<String>  & conditionSubypes,
                         const vector<double>  & conditionMinima,
                         const vector<double>  & conditionMaxima,
                         const vector<double>  & conditionMinima2,
                         const vector<double>  & conditionMaxima2);

  void createParticleFilter(const String & name,
                            const String & title,
                            const String & typeName,
                            const vector<String>  & conditionTypes,
                            const vector<String>  & conditionSubypes,
                            const vector<double>  & conditionMinima,
                            const vector<double>  & conditionMaxima,
                            const vector<double>  & conditionMinima2,
                            const vector<double>  & conditionMaxima2);

  ClassDef(FilterCreator,0)
};

}

#endif /* CAP_FilterCreator */


