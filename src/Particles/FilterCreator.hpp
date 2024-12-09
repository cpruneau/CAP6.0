
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
#ifndef CAP__FilterCreator
#define CAP__FilterCreator
#include "EventTask.hpp"
#include "Event.hpp"
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
  virtual void finalize();

protected:

  EventFilter *  createEventFilter(const String & name,
                         const String & title,
                         const vector<String>  & conditionTypes,
                         const vector<String>  & conditionSubypes,
                         const vector<double>  & conditionMinima,
                         const vector<double>  & conditionMaxima,
                         const vector<double>  & conditionMinima2,
                         const vector<double>  & conditionMaxima2);

  ParticleFilter * createParticleFilter(const String & name,
                            const String & title,
                            const vector<String>  & conditionTypes,
                            const vector<String>  & conditionSubypes,
                            const vector<double>  & conditionMinima,
                            const vector<double>  & conditionMaxima,
                            const vector<double>  & conditionMinima2,
                            const vector<double>  & conditionMaxima2);

  EfficiencyFilter *  createEfficiencyFilter(const String & name,
                              const String & title,
                              const vector<String>  & conditionTypes,
                              const vector<String>  & conditionSubypes,
                              const vector<double>  & conditionMinima,
                              const vector<double>  & conditionMaxima,
                              const vector<double>  & conditionMinima2,
                              const vector<double>  & conditionMaxima2);


  JetFilter *  createJetFilter(const String & name,
                         const String & title,
                         const vector<String>  & conditionTypes,
                         const vector<String>  & conditionSubypes,
                         const vector<double>  & conditionMinima,
                         const vector<double>  & conditionMaxima,
                         const vector<double>  & conditionMinima2,
                         const vector<double>  & conditionMaxima2);

  TH1 * setupEffVsPt(const String & histoName,
                     int nBins_pt,
                     double min_pt,
                     double max_pt,
                     const vector<double> & thres_pt,
                     const vector<double> & value_pt);
  TH2 * setupEffVsEtaPt(const String & histoName,
                        int nBins_eta,
                        double min_eta,
                        double max_eta,
                        int nBins_pt,
                        double min_pt,
                        double max_pt,
                        const vector<double> & thres_eta,
                        const vector<double> & value_eta,
                        const vector<double> & thres_pt,
                        const vector<double> & value_pt);


  ClassDef(FilterCreator,0)
};

}

#endif /* CAP_FilterCreator */


