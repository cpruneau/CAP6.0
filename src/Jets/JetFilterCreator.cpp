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
#include "JetFilterCreator.hpp"
#include "EventFilter.hpp"
#include "ParticleFilter.hpp"
#include "JetFilter.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::JetFilterCreator);


namespace CAP
{

JetFilterCreator::JetFilterCreator()
:
FilterCreator()
{
  appendClassName("JetFilterCreator");
  setInstanceName("JetFilterCreator");
  setName("JetFilterCreator");
  setTitle("JetFilterCreator");
}


JetFilterCreator::JetFilterCreator(const JetFilterCreator & task)
:
FilterCreator(task)
{   }

JetFilterCreator & JetFilterCreator::operator=(const JetFilterCreator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}

void JetFilterCreator::setDefaultConfiguration()
{
  FilterCreator::setDefaultConfiguration();
  addProperty("JetFilter:N", 1);     // number of filters to create
  addProperty("JetFilter:Filter0:Name", "All");  // All is a generic filter
  addProperty("JetFilter:Filter0:Type", "All");  // All is a generic filter
}


void JetFilterCreator::configure()
{
  FilterCreator::configure();
}

String createName(const String & s0, int k, const String & s1)
{
  String s = s0;
  s += k;
  s += s1;
  return s;
}

String createName(const String & s0, int k0, const String & s1, int k1, const String & s2)
{
  String s = s0;
  s += k0;
  s += s1;
  s += k1;
  s += s2;
  return s;
}

void JetFilterCreator::initialize()
{
  TaskAccountant::reset();
  String keyword;
  String name;
  String title;
  String conditionType;
  String conditionSubtype;
  double minimum;
  double maximum;
  double minimum2;
  double maximum2;
  int    nConditions;
  vector<String> conditionTypes;
  vector<String> conditionSubtypes;
  vector<double> conditionMinima;
  vector<double> conditionMaxima;
  vector<double> conditionMinima2;
  vector<double> conditionMaxima2;

  int nEventFilters = getValueInt("EventFilter:N");
  if (nEventFilters<1) throw TaskException("nEventFilters<1",__FUNCTION__);
  int nParticleFilters = getValueInt("ParticleFilter:N");
  int nJetFilters = getValueInt("JetFilter:N");
  if (nParticleFilters<1) throw TaskException("nParticleFilters<1",__FUNCTION__);
  if (nJetFilters<1) throw TaskException("nJetFilters<1",__FUNCTION__);

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printLine();
    printString("Building filters");
    printValue("nEventFilters",nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    }
  for (int iEventFilter=0; iEventFilter<nEventFilters; iEventFilter++)
    {
    conditionTypes.clear();
    conditionSubtypes.clear();
    conditionMinima.clear();
    conditionMaxima.clear();
    conditionMinima2.clear();
    conditionMaxima2.clear();
    keyword = createName("EventFilter:Filter",iEventFilter,":Name");
    name = getValueString(keyword);
    keyword = createName("EventFilter:Filter",iEventFilter,":Title");
    title = getValueString(keyword);
    keyword = createName("EventFilter:Filter",iEventFilter,":nConditions");
    nConditions = getValueInt(keyword);
    for (int iCondition=0; iCondition<nConditions; iCondition++)
      {
      keyword = createName("EventFilter:Filter",iEventFilter,":Condition",iCondition,":Type");
      conditionType  = getValueString(keyword);
      conditionTypes.push_back(conditionType);
      keyword = createName("EventFilter:Filter",iEventFilter,":Condition",iCondition,":Subtype");
      conditionSubtype  = getValueString(keyword);
      conditionSubtypes.push_back(conditionSubtype);
      keyword = createName("EventFilter:Filter",iEventFilter,":Condition",iCondition,":Minimum");
      minimum  = getValueDouble(keyword);
      conditionMinima.push_back(minimum);
      keyword = createName("EventFilter:Filter",iEventFilter,":Condition",iCondition,":Maximum");
      maximum  = getValueDouble(keyword);
      conditionMaxima.push_back(maximum);
      conditionMinima2.push_back(0.0);
      conditionMaxima2.push_back(0.0);
      }
    createEventFilter(name,title,
                      conditionTypes, conditionSubtypes,
                      conditionMinima, conditionMaxima,
                      conditionMinima2, conditionMaxima2);
    }
  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printLine();
    printString("Building particle filters");
    }
  for (int iParticleFilter=0; iParticleFilter<nParticleFilters; iParticleFilter++)
    {
    conditionTypes.clear();
    conditionSubtypes.clear();
    conditionMinima.clear();
    conditionMaxima.clear();
    conditionMinima2.clear();
    conditionMaxima2.clear();
    keyword = createName("ParticleFilter:Filter",iParticleFilter,":Name");
    name = getValueString(keyword);
    keyword = createName("ParticleFilter:Filter",iParticleFilter,":Title");
    title = getValueString(keyword);
    keyword = createName("ParticleFilter:Filter",iParticleFilter,":nConditions");
    nConditions = getValueInt(keyword);
    for (int iCondition=0; iCondition<nConditions; iCondition++)
      {
      keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Type");
      conditionType  = getValueString(keyword);
      conditionTypes.push_back(conditionType);
      keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Subtype");
      conditionSubtype  = getValueString(keyword);
      conditionSubtypes.push_back(conditionSubtype);
      keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Minimum");
      minimum  = getValueDouble(keyword);
      conditionMinima.push_back(minimum);
      keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Maximum");
      maximum  = getValueDouble(keyword);
      conditionMaxima.push_back(maximum);

      if (conditionType.EqualTo("DoubleDualRange"))
        {
        keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Minimum2");
        minimum2  = getValueDouble(keyword);
        conditionMinima2.push_back(minimum2);
        keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Maximum2");
        maximum2  = getValueDouble(keyword);
        conditionMaxima2.push_back(maximum2);
        }
      else
        {
        conditionMinima2.push_back(0.0);
        conditionMaxima2.push_back(0.0);
        }
//      printValue("iCondition",iCondition);
//      printValue("conditionType",conditionType);
//      printValue("conditionSubtype",conditionSubtype);
//      printValue("minimum",minimum);
//      printValue("maximum",maximum);
//      printValue("minimum2",minimum2);
//      printValue("maximum2",maximum2);

      }
    createParticleFilter(name,title,
                         conditionTypes, conditionSubtypes,
                         conditionMinima, conditionMaxima,
                         conditionMinima2, conditionMaxima2);
    }
  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printLine();
    printString("Building jet filters");
    }
  for (int iJetFilter=0; iJetFilter<nJetFilters; iJetFilter++)
    {
    conditionTypes.clear();
    conditionSubtypes.clear();
    conditionMinima.clear();
    conditionMaxima.clear();
    conditionMinima2.clear();
    conditionMaxima2.clear();
    keyword = createName("JetFilter:Filter",iJetFilter,":Name");
    name = getValueString(keyword);
    keyword = createName("JetFilter:Filter",iJetFilter,":Title");
    title = getValueString(keyword);
    keyword = createName("JetFilter:Filter",iJetFilter,":nConditions");
    nConditions = getValueInt(keyword);
    for (int iCondition=0; iCondition<nConditions; iCondition++)
      {
      keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Type");
      conditionType  = getValueString(keyword);
      conditionTypes.push_back(conditionType);
      keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Subtype");
      conditionSubtype  = getValueString(keyword);
      conditionSubtypes.push_back(conditionSubtype);
      keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Minimum");
      minimum  = getValueDouble(keyword);
      conditionMinima.push_back(minimum);
      keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Maximum");
      maximum  = getValueDouble(keyword);
      conditionMaxima.push_back(maximum);

      if (conditionType.EqualTo("DoubleDualRange"))
        {
        keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Minimum2");
        minimum2  = getValueDouble(keyword);
        conditionMinima2.push_back(minimum2);
        keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Maximum2");
        maximum2  = getValueDouble(keyword);
        conditionMaxima2.push_back(maximum2);
        }
      else
        {
        conditionMinima2.push_back(0.0);
        conditionMaxima2.push_back(0.0);
        }
      }
    createJetFilter(name,title,
                         conditionTypes, conditionSubtypes,
                         conditionMinima, conditionMaxima,
                         conditionMinima2, conditionMaxima2);
    }

  if (reportDebug(__FUNCTION__))
    {
    printCR();
    printLine();
    printString("Done Building Filters");
    }
}

void JetFilterCreator::finalize()
{
// do nothing...
}

void JetFilterCreator::createJetFilter(const String & name,
                                       const String & title,
                                       const vector<String>  & conditionTypes,
                                       const vector<String>  & conditionSubtypes,
                                       const vector<double>  & conditionMinima,
                                       const vector<double>  & conditionMaxima,
                                       const vector<double>  & conditionMinima2,
                                       const vector<double>  & conditionMaxima2)
{
  bool verbose = false;
  if (verbose)
    {
    printCR();
    printLine();
    printValue("JetFilterCreator::createJetFilter() name",name);
    printValue("JetFilterCreator::createJetFilter() title",title);
    for (unsigned int k=0; k<conditionTypes.size(); k++)
      {
      printValue("JetFilterCreator::createJetFilter() condition index",  k);
      printValue("JetFilterCreator::createJetFilter() conditionTypes",   conditionTypes[k]);
      printValue("JetFilterCreator::createJetFilter() conditionSubtypes",conditionSubtypes[k]);
      printValue("JetFilterCreator::createJetFilter() conditionMinima",  conditionMinima[k]);
      printValue("JetFilterCreator::createJetFilter() conditionMaxima",  conditionMaxima[k]);
      printValue("JetFilterCreator::createJetFilter() conditionMinima2", conditionMinima2[k]);
      printValue("JetFilterCreator::createJetFilter() conditionMaxima2", conditionMaxima2[k]);
      }
    printLine();
    }
  JetFilter * filter = Manager<JetFilter>::getStoreObjectNamed(name);
  filter->setTitle(title);
  filter->setName(name);

  for (unsigned int k=0; k<conditionTypes.size();k++)
    {
    String conditionType    = conditionTypes[k];
    String conditionSubtype = conditionSubtypes[k];
    //int type;
    int subtype;

    // kNone, kP, kPt, kEta, kMult

    if (conditionType.EqualTo("DoubleRange"))
      {
      if (conditionSubtype.EqualTo("P"))
        subtype = JetFilter::kP;
      else if (conditionSubtype.EqualTo("PT"))
        subtype = JetFilter::kPt;
      else if (conditionSubtype.EqualTo("ETA"))
        subtype = JetFilter::kEta;
      else if (conditionSubtype.EqualTo("MULT"))
        subtype = JetFilter::kMult;
      else
        throw FilterException(conditionSubtype,__FUNCTION__);
      filter->addCondition(subtype,conditionMinima[k],conditionMaxima[k]);
      }
    else if (conditionType.EqualTo("DoubleDualRange"))
      {
      if (conditionSubtype.EqualTo("P"))
        subtype = JetFilter::kP;
      else if (conditionSubtype.EqualTo("PT"))
        subtype = JetFilter::kPt;
      else if (conditionSubtype.EqualTo("ETA"))
        subtype = JetFilter::kEta;
      else if (conditionSubtype.EqualTo("MMULT"))
        subtype = JetFilter::kMult;
      else
        throw FilterException(conditionSubtype,__FUNCTION__);
      filter->addCondition(subtype,
                           conditionMinima[k],conditionMaxima[k],
                           conditionMinima2[k],conditionMaxima2[k]);
      }
    else
      throw FilterException(conditionType,__FUNCTION__);
    }
}



} // namespace CAP
