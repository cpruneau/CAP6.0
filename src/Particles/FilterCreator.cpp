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
#include "FilterCreator.hpp"
#include "EventFilter.hpp"
#include "ParticleFilter.hpp"
#include "PrintHelpers.hpp"

// using CAP::FilterCreator;

ClassImp(CAP::FilterCreator);


namespace CAP
{

FilterCreator::FilterCreator()
:
EventTask()
{
  appendClassName("FilterCreator");
  setInstanceName("FilterCreator");
  setName("FilterCreator");
  setTitle("FilterCreator");
}


FilterCreator::FilterCreator(const FilterCreator & task)
:
EventTask(task)
{   }

FilterCreator & FilterCreator::operator=(const FilterCreator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    }
  return *this;
}

void FilterCreator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  addProperty("EventFilter:N", 1);     // number of filters to create
  addProperty("EventFilter:Filter0:Name", "All");  // All is a generic filter
  addProperty("EventFilter:Filter0:Type", "All");  // All is a generic filter
  addProperty("ParticleFilter:Filter0:Name", "All");  // All is a generic filter
  addProperty("ParticleFilter:Filter0:Type", "All");  // All is a generic filter
}


void FilterCreator::configure()
{
  EventTask::configure();

  //  double minimum, minimum2, maximum, maximum2;
  //  vector<String>  conditionTypes;
  //  vector<String>  conditionSubtypes;
  //  vector<double>  conditionMinima;
  //  vector<double>  conditionMaxima;
  //  vector<double>  conditionMinima2;
  //  vector<double>  conditionMaxima2;
  //  int nEventFilters    = getValueInt("EventFilter:N");
  //  int nParticleFilters = getValueInt("ParticleFilter:N");
  //  int nConditions = 0;
  //  String keyword, base, condBase, filterName, filterTitle, filterType;
  //  String conditionType, conditionSubtype;
  //
  //  if (nEventFilters>0)
  //    {
  //    for (int iEventFilter=0; iEventFilter<nEventFilters; iEventFilter++)
  //      {
  //      base = "EventFilter:Filter"; base += iEventFilter;
  //      keyword =  base; keyword += ":Name";
  //      filterName = getValueString(keyword);
  //      keyword =  base; keyword += ":Title";
  //      filterTitle = getValueString(keyword);
  //      keyword =  base; keyword += ":Type";
  //      filterType = getValueString(keyword);
  //      keyword =  base; keyword += ":nConditions";
  //      nConditions = getValueInt(keyword);
  //      conditionTypes.clear();
  //      conditionSubtypes.clear();
  //      conditionMinima.clear();
  //      conditionMaxima.clear();
  //      conditionMinima2.clear();
  //      conditionMaxima2.clear();
  //      for (int iCondition=0; iCondition<nConditions; iCondition++)
  //        {
  //        condBase = base;
  //        condBase = base; condBase += ":Condition"; condBase += iCondition;
  //        keyword  = condBase; keyword += ":Type";
  //        conditionType = getValueString(keyword);
  //        keyword  = condBase; keyword += ":Subtype";
  //        conditionSubtype = getValueString(keyword);
  //        keyword  = condBase; keyword += ":Minimum";
  //        minimum = getValueDouble(keyword);
  //        keyword  = condBase; keyword += ":Maximum";
  //        maximum = getValueDouble(keyword);
  //        if (conditionType.EqualTo("TwoRanges"))
  //          {
  //          conditionSubtype = getValueString(keyword);
  //          keyword  = condBase; keyword += ":Minimum2";
  //          minimum2 = getValueDouble(keyword);
  //          keyword  = condBase; keyword += ":Maximum2";
  //          maximum2 = getValueDouble(keyword);
  //          }
  //        else
  //          {
  //          minimum2 = 0.0;
  //          maximum2 = 0.0;
  //          }
  //        conditionTypes.push_back(conditionType);
  //        conditionSubtypes.push_back(conditionSubtype);
  //        conditionMinima.push_back(minimum);
  //        conditionMaxima.push_back(maximum);
  //        conditionMinima2.push_back(minimum2);
  //        conditionMaxima2.push_back(maximum2);
  //        }
  //      printValue("filterName",filterName);
  //      printValue("filterTitle",filterTitle);
  //      printValue("filterType",filterType);
  //    createEventFilter(filterName, filterTitle,filterType,
  //                      conditionTypes,conditionSubtypes,
  //                      conditionMinima,conditionMaxima,
  //                      conditionMinima2,conditionMaxima2);
  //      }
  //    }
  //   if (nParticleFilters>0)
  //    {
  //    for (int iParticleFilter=0; iParticleFilter<nParticleFilters; iParticleFilter++)
  //      {
  //      base = "ParticleFilter:Filter"; base += iParticleFilter;
  //      keyword =  base; keyword += ":Name";
  //      filterName = getValueString(keyword);
  //      keyword =  base; keyword += ":Title";
  //      filterTitle = getValueString(keyword);
  //      keyword =  base; keyword += ":Type";
  //      filterType = getValueString(keyword);
  //      keyword =  base; keyword += ":nConditions";
  //      nConditions = getValueInt(keyword);
  //      conditionTypes.clear();
  //      conditionSubtypes.clear();
  //      conditionMinima.clear();
  //      conditionMaxima.clear();
  //      conditionMinima2.clear();
  //      conditionMaxima2.clear();
  //      for (int iCondition=0; iCondition<nConditions; iCondition++)
  //        {
  //        condBase = base;
  //        condBase = base; condBase += ":Condition"; condBase += iCondition;
  //        keyword  = condBase; keyword += ":Type";
  //        conditionType = getValueString(keyword);
  //        keyword  = condBase; keyword += ":Subtype";
  //        conditionSubtype = getValueString(keyword);
  //        keyword  = condBase; keyword += ":Minimum";
  //        minimum = getValueDouble(keyword);
  //        keyword  = condBase; keyword += ":Maximum";
  //        maximum = getValueDouble(keyword);
  //        if (conditionType.EqualTo("TwoRanges"))
  //          {
  //          conditionSubtype = getValueString(keyword);
  //          keyword  = condBase; keyword += ":Minimum2";
  //          minimum2 = getValueDouble(keyword);
  //          keyword  = condBase; keyword += ":Maximum2";
  //          maximum2 = getValueDouble(keyword);
  //          }
  //        else
  //          {
  //          minimum2 = 0.0;
  //          maximum2 = 0.0;
  //          }
  //        conditionTypes.push_back(conditionType);
  //        conditionSubtypes.push_back(conditionSubtype);
  //        conditionMinima.push_back(minimum);
  //        conditionMaxima.push_back(maximum);
  //        conditionMinima2.push_back(minimum2);
  //        conditionMaxima2.push_back(maximum2);
  //        }
  //      createParticleFilter(filterName, filterTitle,filterType,
  //                           conditionTypes,conditionSubtypes,
  //                           conditionMinima,conditionMaxima,
  //                           conditionMinima2,conditionMaxima2);
  //      }
  //    }
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

void FilterCreator::initialize()
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
  if (nParticleFilters<1) throw TaskException("nParticleFilters<1",__FUNCTION__);
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
    printString("Done Building Filters");
    }
}

void FilterCreator::finalize()
{
// do nothing...
}


void FilterCreator::createEventFilter(const String & name,
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
    printValue("FilterCreator::createEventFilter() name",name);
    printValue("FilterCreator::createEventFilter() title",title);
    for (unsigned int k=0; k<conditionTypes.size(); k++)
      {
      printValue("FilterCreator::createEventFilter() condition index",  k);
      printValue("FilterCreator::createEventFilter() conditionTypes",   conditionTypes[k]);
      printValue("FilterCreator::createEventFilter() conditionSubtypes",conditionSubtypes[k]);
      printValue("FilterCreator::createEventFilter() conditionMinima",  conditionMinima[k]);
      printValue("FilterCreator::createEventFilter() conditionMaxima",  conditionMaxima[k]);
      printValue("FilterCreator::createEventFilter() conditionMinima2", conditionMinima2[k]);
      printValue("FilterCreator::createEventFilter() conditionMaxima2", conditionMaxima2[k]);
      }
    printLine();
    }
  EventFilter * filter = Manager<EventFilter>::getStoreObjectNamed(name);
  filter->setTitle(title);
  filter->setName(name);

  for (unsigned int k=0; k<conditionTypes.size();k++)
    {
    String conditionType    = conditionTypes[k];
    String conditionSubtype = conditionSubtypes[k];
    //int type;
    int subtype;
    if (conditionType.EqualTo("DoubleRange"))
      {
      //type = Condition::kConditionDoubleRange;
      if (conditionSubtype.EqualTo("CL_0"))
        subtype = EventFilter::kCl0;
      else if (conditionSubtype.EqualTo("CL_1"))
        subtype = EventFilter::kCl1;
      else if (conditionSubtype.EqualTo("CL_2"))
        subtype = EventFilter::kCl2;
      else if (conditionSubtype.EqualTo("CL_3"))
        subtype = EventFilter::kCl3;
      else if (conditionSubtype.EqualTo("CL_4"))
        subtype = EventFilter::kCl4;
      else if (conditionSubtype.EqualTo("MULT_0"))
        subtype = EventFilter::kMult0;
      else if (conditionSubtype.EqualTo("MULT_1"))
        subtype = EventFilter::kMult1;
      else if (conditionSubtype.EqualTo("MULT_2"))
        subtype = EventFilter::kMult2;
      else if (conditionSubtype.EqualTo("MULT_3"))
        subtype = EventFilter::kMult3;
      else if (conditionSubtype.EqualTo("MULT_4"))
        subtype = EventFilter::kMult4;
      else if (conditionSubtype.EqualTo("SPHERO_0"))
        subtype = EventFilter::kSphero0;
      else if (conditionSubtype.EqualTo("SPHERO_1"))
        subtype = EventFilter::kSphero1;
      else if (conditionSubtype.EqualTo("SPHERO_2"))
        subtype = EventFilter::kSphero2;
      else if (conditionSubtype.EqualTo("SPHERO_3"))
        subtype = EventFilter::kSphero3;
      else if (conditionSubtype.EqualTo("SPHERO_4"))
        subtype = EventFilter::kSphero4;
      else if (conditionSubtype.EqualTo("ENERGY_0"))
        subtype = EventFilter::kEnergy0;
      else if (conditionSubtype.EqualTo("ENERGY_1"))
        subtype = EventFilter::kEnergy1;
      else if (conditionSubtype.EqualTo("ENERGY_2"))
        subtype = EventFilter::kEnergy2;
      else if (conditionSubtype.EqualTo("ENERGY_3"))
        subtype = EventFilter::kEnergy3;
      else if (conditionSubtype.EqualTo("ENERGY_4"))
        subtype = EventFilter::kEnergy4;
      else
        throw FilterException(conditionSubtype,__FUNCTION__);
      filter->addCondition(subtype,conditionMinima[k],conditionMaxima[k]);
      }
    else if (conditionType.EqualTo("DoubleDualRange"))
      {
      //type = type = Condition::kConditionDoubleDualRange;;
      if (conditionSubtype.EqualTo("CL_0"))
        subtype = EventFilter::kCl0;
      else if (conditionSubtype.EqualTo("CL_1"))
        subtype = EventFilter::kCl1;
      else if (conditionSubtype.EqualTo("CL_2"))
        subtype = EventFilter::kCl2;
      else if (conditionSubtype.EqualTo("CL_3"))
        subtype = EventFilter::kCl3;
      else if (conditionSubtype.EqualTo("CL_4"))
        subtype = EventFilter::kCl4;
      else if (conditionSubtype.EqualTo("MULT_0"))
        subtype = EventFilter::kMult0;
      else if (conditionSubtype.EqualTo("MULT_1"))
        subtype = EventFilter::kMult1;
      else if (conditionSubtype.EqualTo("MULT_2"))
        subtype = EventFilter::kMult2;
      else if (conditionSubtype.EqualTo("MULT_3"))
        subtype = EventFilter::kMult3;
      else if (conditionSubtype.EqualTo("MULT_4"))
        subtype = EventFilter::kMult4;
      else if (conditionSubtype.EqualTo("SPHERO_0"))
        subtype = EventFilter::kSphero0;
      else if (conditionSubtype.EqualTo("SPHERO_1"))
        subtype = EventFilter::kSphero1;
      else if (conditionSubtype.EqualTo("SPHERO_2"))
        subtype = EventFilter::kSphero2;
      else if (conditionSubtype.EqualTo("SPHERO_3"))
        subtype = EventFilter::kSphero3;
      else if (conditionSubtype.EqualTo("SPHERO_4"))
        subtype = EventFilter::kSphero4;
      else if (conditionSubtype.EqualTo("ENERGY_0"))
        subtype = EventFilter::kEnergy0;
      else if (conditionSubtype.EqualTo("ENERGY_1"))
        subtype = EventFilter::kEnergy1;
      else if (conditionSubtype.EqualTo("ENERGY_2"))
        subtype = EventFilter::kEnergy2;
      else if (conditionSubtype.EqualTo("ENERGY_3"))
        subtype = EventFilter::kEnergy3;
      else if (conditionSubtype.EqualTo("ENERGY_4"))
        subtype = EventFilter::kEnergy4;
      else
        throw FilterException(conditionSubtype,__FUNCTION__);
      filter->addCondition(subtype,
                           conditionMinima[k],conditionMaxima[k],
                           conditionMinima2[k],conditionMaxima2[k]);
      }
    else
      throw FilterException(conditionSubtypes[k],__FUNCTION__);
    }
}


void FilterCreator::createParticleFilter(const String & name,
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
    printValue("FilterCreator::createParticleFilter() name",name);
    printValue("FilterCreator::createParticleFilter() title",title);
    for (unsigned int k=0; k<conditionTypes.size(); k++)
      {
      printValue("FilterCreator::createParticleFilter() condition index",k);
      printValue("FilterCreator::createParticleFilter() conditionTypes",conditionTypes[k]);
      printValue("FilterCreator::createParticleFilter() conditionSubtypes",conditionSubtypes[k]);
      printValue("FilterCreator::createParticleFilter() conditionMinima",  conditionMinima[k]);
      printValue("FilterCreator::createParticleFilter() conditionMaxima",  conditionMaxima[k]);
      printValue("FilterCreator::createParticleFilter() conditionMinima2", conditionMinima2[k]);
      printValue("FilterCreator::createParticleFilter() conditionMaxima2", conditionMaxima2[k]);
      }
    printLine();
    }
  ParticleFilter * filter = Manager<ParticleFilter>::getStoreObjectNamed(name);
  filter->setTitle(title);
  filter->setName(name);

  for (unsigned int k=0; k<conditionTypes.size();k++)
    {
    String conditionType    = conditionTypes[k];
    String conditionSubtype = conditionSubtypes[k];
    //int type;
    int subtype;
    if (conditionType.EqualTo("DoubleRange"))
      {
      if (conditionSubtype.EqualTo("PT"))
        subtype = ParticleFilter::kPt;
      else if (conditionSubtype.EqualTo("PX"))
        subtype = ParticleFilter::kPx;
      else if (conditionSubtype.EqualTo("PY"))
        subtype = ParticleFilter::kPy;
      else if (conditionSubtype.EqualTo("PZ"))
        subtype = ParticleFilter::kPz;
      else if (conditionSubtype.EqualTo("ENERGY"))
        subtype = ParticleFilter::kEnergy;
      else if (conditionSubtype.EqualTo("ETA"))
        subtype = ParticleFilter::kEta;
      else if (conditionSubtype.EqualTo("RAPIDITY"))
        subtype = ParticleFilter::kRapidity;
      else if (conditionSubtype.EqualTo("PHI"))
        subtype = ParticleFilter::kPhi;
      else
        throw FilterException(conditionSubtype,__FUNCTION__);
      filter->addCondition(subtype,conditionMinima[k],conditionMaxima[k]);
      }
    else if (conditionType.EqualTo("DoubleDualRange"))
      {
      if (conditionSubtype.EqualTo("PT"))
        subtype = ParticleFilter::kPt;
      else if (conditionSubtype.EqualTo("PX"))
        subtype = ParticleFilter::kPx;
      else if (conditionSubtype.EqualTo("PY"))
        subtype = ParticleFilter::kPy;
      else if (conditionSubtype.EqualTo("PZ"))
        subtype = ParticleFilter::kPz;
      else if (conditionSubtype.EqualTo("ENERGY"))
        subtype = ParticleFilter::kEnergy;
      else if (conditionSubtype.EqualTo("ETA"))
        subtype = ParticleFilter::kEta;
      else if (conditionSubtype.EqualTo("RAPIDITY"))
        subtype = ParticleFilter::kRapidity;
      else if (conditionSubtype.EqualTo("PHI"))
        subtype = ParticleFilter::kPhi;
      else
        throw FilterException(conditionSubtype,__FUNCTION__);
      filter->addCondition(subtype,
                           conditionMinima[k],conditionMaxima[k],
                           conditionMinima2[k],conditionMaxima2[k]);}
    else if (conditionType.EqualTo("Integer"))
      {
      if (conditionSubtype.EqualTo("PDG"))
        subtype = ParticleFilter::kPdg;
      else if (conditionSubtype.EqualTo("CHARGE"))
        subtype = ParticleFilter::kCharge;
      else if (conditionSubtype.EqualTo("BARYON"))
        subtype = ParticleFilter::kBaryon;
      else if (conditionSubtype.EqualTo("STRANGE"))
        subtype = ParticleFilter::kStrange;
      else if (conditionSubtype.EqualTo("CHARM"))
        subtype = ParticleFilter::kCharm;
      else if (conditionSubtype.EqualTo("CHARM"))
        subtype = ParticleFilter::kCharm;
//      else if (conditionSubtype.EqualTo("BEAUTY"))
//        subtype = ParticleFilter::kBeauty;
      else
        throw FilterException(conditionSubtype,__FUNCTION__);
      filter->addCondition(subtype,int(conditionMinima[k]));
      }
    else if (conditionType.EqualTo("Bool"))
      {
      if (conditionSubtype.EqualTo("LIVE"))
        subtype = ParticleFilter::kLive;
      else if (conditionSubtype.EqualTo("ENABLED"))
        subtype = ParticleFilter::kEnabled;
      else
        throw FilterException(conditionSubtype,__FUNCTION__);
      filter->addCondition(subtype,bool(conditionMinima[k]));
    }
    else
      throw FilterException(conditionType,__FUNCTION__);
    }
}



} // namespace CAP
