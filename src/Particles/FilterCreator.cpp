/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Victor Gonzalez
 * ALL rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
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
  addProperty("EventFilter:N",1);     // number of filters to create
  addProperty("EventFilter:Filter0:Name", "ALL");  // ALL is a generic filter
  addProperty("EventFilter:Filter0:Type", "ALL");  // ALL is a generic filter
  addProperty("ParticleFilter:N",1);  // ALL is a generic filter
  addProperty("ParticleFilter:Filter0:Name", "ALL");  // ALL is a generic filter
  addProperty("ParticleFilter:Filter0:Type", "ALL");  // ALL is a generic filter
  addProperty("EfficiencyFilter:N",0);  // ALL is a generic filter
  addProperty("EfficiencyFilter:Filter0:Name", "ALL");  // ALL is a generic filter
  addProperty("EfficiencyFilter:Filter0:Type", "ALL");  // ALL is a generic filter
  addProperty("JetFilter:N", 0);     // number of filters to create
  addProperty("JetFilter:Filter0:Name", "ALL");  // ALL is a generic filter
  addProperty("JetFilter:Filter0:Type", "ALL");  // ALL is a generic filter
}


void FilterCreator::configure()
{
  EventTask::configure();
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

  printCR();
  printLine();
  printString("FilterCreator::initialize()");

  int nEventFilters      = configuration.getValueInt("EventFilter:N",1,0);
  int nParticleFilters   = configuration.getValueInt("ParticleFilter:N",1,0);
  int nEfficiencyFilters = configuration.getValueInt("EfficiencyFilter:N",1,0);
  int nJetFilters        = configuration.getValueInt("JetFilter:N",1,0);

  //if (nEventFilters<1)    throw TaskException("nEventFilters<1",__FUNCTION__);
  //if (nParticleFilters<1) throw TaskException("nParticleFilters<1",__FUNCTION__);
  //if (nJetFilters<1)      throw TaskException("nJetFilters<1",__FUNCTION__);
  if (true) // reportDebug(__FUNCTION__))
    {
    printCR();
    printLine();
    printString("Building filters");
    printValue("nEventFilters",nEventFilters);
    printValue("nParticleFilters",nParticleFilters);
    printValue("nEfficiencyFilters",nEfficiencyFilters);
    printValue("nJetFilters",nJetFilters);
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
    name = configuration.getValueString(keyword);
    keyword = createName("EventFilter:Filter",iEventFilter,":Title");
    title = configuration.getValueString(keyword);
    keyword = createName("EventFilter:Filter",iEventFilter,":nConditions");
    nConditions = configuration.getValueInt(keyword,1,0);
    for (int iCondition=0; iCondition<nConditions; iCondition++)
      {
      keyword = createName("EventFilter:Filter",iEventFilter,":Condition",iCondition,":Type");
      conditionType  = configuration.getValueString(keyword);
      conditionTypes.push_back(conditionType);
      keyword = createName("EventFilter:Filter",iEventFilter,":Condition",iCondition,":Subtype");
      conditionSubtype  = configuration.getValueString(keyword);
      conditionSubtypes.push_back(conditionSubtype);
      keyword = createName("EventFilter:Filter",iEventFilter,":Condition",iCondition,":Minimum");
      minimum  = configuration.getValueDouble(keyword);
      conditionMinima.push_back(minimum);
      keyword = createName("EventFilter:Filter",iEventFilter,":Condition",iCondition,":Maximum");
      maximum  = configuration.getValueDouble(keyword);
      conditionMaxima.push_back(maximum);
      conditionMinima2.push_back(0.0);
      conditionMaxima2.push_back(0.0);
      }
    createEventFilter(name,title,
                      conditionTypes, conditionSubtypes,
                      conditionMinima, conditionMaxima,
                      conditionMinima2, conditionMaxima2);
    }
  if (true)
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
    name = configuration.getValueString(keyword);
    keyword = createName("ParticleFilter:Filter",iParticleFilter,":Title");
    title = configuration.getValueString(keyword);
    keyword = createName("ParticleFilter:Filter",iParticleFilter,":nConditions");
    nConditions = configuration.getValueInt(keyword,1,0);

    printValue("ParticleFilter:Filter:Name",name);
    printValue("ParticleFilter:Filter:Title",title);
    printValue("ParticleFilter:Filter:nConditions",nConditions);

    for (int iCondition=0; iCondition<nConditions; iCondition++)
      {
      keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Type");
      conditionType  = configuration.getValueString(keyword);
      conditionTypes.push_back(conditionType);
      keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Subtype");
      conditionSubtype  = configuration.getValueString(keyword);
      conditionSubtypes.push_back(conditionSubtype);
      keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Minimum");
      minimum  = configuration.getValueDouble(keyword);
      conditionMinima.push_back(minimum);
      keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Maximum");
      maximum  = configuration.getValueDouble(keyword);
      conditionMaxima.push_back(maximum);
      if (conditionType.EqualTo("DoubleDualRange"))
        {
        keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Minimum2");
        minimum2  = configuration.getValueDouble(keyword);
        conditionMinima2.push_back(minimum2);
        keyword = createName("ParticleFilter:Filter",iParticleFilter,":Condition",iCondition,":Maximum2");
        maximum2  = configuration.getValueDouble(keyword);
        conditionMaxima2.push_back(maximum2);
        }
      else
        {
        conditionMinima2.push_back(0.0);
        conditionMaxima2.push_back(0.0);
        }

      }
    createParticleFilter(name,title,
                         conditionTypes, conditionSubtypes,
                         conditionMinima, conditionMaxima,
                         conditionMinima2, conditionMaxima2);
    }

  if (true)
    {
    printCR();
    printLine();
    printString("Building efficiency filters");
    }
  std::vector<double> thres_pt;
  std::vector<double> value_pt;
  std::vector<double> thres_eta;
  std::vector<double> value_eta;
  String histoName;

  for (int iEfficiencyFilter=0; iEfficiencyFilter<nEfficiencyFilters; iEfficiencyFilter++)
    {
    conditionTypes.clear();
    conditionSubtypes.clear();
    conditionMinima.clear();
    conditionMaxima.clear();
    conditionMinima2.clear();
    conditionMaxima2.clear();
    keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Name");
    name = configuration.getValueString(keyword);
    keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Title");
    title = configuration.getValueString(keyword);
    keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":nConditions");
    nConditions = configuration.getValueInt(keyword,1,0);

    keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":nBins_pt");
    int nBins_pt   = configuration.getValueInt(keyword);
    keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Min_pt");
    double min_pt  = configuration.getValueDouble(keyword);
    keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Max_pt");
    double max_pt  = configuration.getValueDouble(keyword);
    keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":nBins_eta");
    int nBins_eta  = configuration.getValueInt(keyword);
    keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Min_eta");
    double min_eta = configuration.getValueDouble(keyword);
    keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Max_eta");
    double max_eta = configuration.getValueDouble(keyword);

    printValue("EfficiencyFilter:Filter:Name",name);
    printValue("EfficiencyFilter:Filter:Title",title);
    printValue("EfficiencyFilter:Filter:nBins_pt",nBins_pt);
    printValue("EfficiencyFilter:Filter:Min_pt",min_pt);
    printValue("EfficiencyFilter:Filter:Max_pt",max_pt);
    printValue("EfficiencyFilter:Filter:nBins_eta",nBins_eta);
    printValue("EfficiencyFilter:Filter:Min_eta",min_eta);
    printValue("EfficiencyFilter:Filter:Max_eta",max_eta);


    printValue("EfficiencyFilter:Filter:nConditions",nConditions);

    for (int iCondition=0; iCondition<nConditions; iCondition++)
      {
      keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Condition",iCondition,":Type");
      conditionType  = configuration.getValueString(keyword);
      conditionTypes.push_back(conditionType);
      keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Condition",iCondition,":Subtype");
      conditionSubtype  = configuration.getValueString(keyword);
      conditionSubtypes.push_back(conditionSubtype);
      keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Condition",iCondition,":Minimum");
      minimum  = configuration.getValueDouble(keyword);
      conditionMinima.push_back(minimum);
      keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Condition",iCondition,":Maximum");
      maximum  = configuration.getValueDouble(keyword);
      conditionMaxima.push_back(maximum);
      if (conditionType.EqualTo("DoubleDualRange"))
        {
        keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Condition",iCondition,":Minimum2");
        minimum2  = configuration.getValueDouble(keyword);
        conditionMinima2.push_back(minimum2);
        keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Condition",iCondition,":Maximum2");
        maximum2  = configuration.getValueDouble(keyword);
        conditionMaxima2.push_back(maximum2);
        }
      else
        {
        conditionMinima2.push_back(0.0);
        conditionMaxima2.push_back(0.0);
        }

      }
    EfficiencyFilter * filter = createEfficiencyFilter(name,title,
                                                  conditionTypes, conditionSubtypes,
                                                  conditionMinima, conditionMaxima,
                                                  conditionMinima2, conditionMaxima2);

    if (!filter) throw NullPointerException("EfficiencyFilter * is null",__FUNCTION__);

    switch (filter->getFilterType())
      {
        default:
        case EfficiencyFilter::kEffNone: break;

        case EfficiencyFilter::kEffVsPt:
        {
        thres_pt.clear();
        value_pt.clear();
        keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":nPtPoints");
        int nPtPoints = configuration.getValueInt(keyword);
        for (int k=0;k<nPtPoints;k++)
          {
          keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Pt");
          keyword += k;
          thres_pt.push_back(configuration.getValueDouble(keyword));
          keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":PtEff");
          keyword += k;
          value_pt.push_back(configuration.getValueDouble(keyword));
          }
        histoName = createName("EfficiencyFilter_Filter",iEfficiencyFilter,"_histo");
        TH1 * h = setupEffVsPt(histoName,nBins_pt,min_pt,max_pt,thres_pt,value_pt);
        filter->setEffHisto(h);

        break;
        }

        case EfficiencyFilter::kEffVsPtEta:
        {
        thres_pt.clear();
        value_pt.clear();
        thres_eta.clear();
        value_eta.clear();
        keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":nPtPoints");
        int nPtPoints = configuration.getValueInt(keyword);
        for (int k=0;k<nPtPoints;k++)
          {
          keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Pt");
          keyword += k;
          thres_pt.push_back(configuration.getValueDouble(keyword));
          keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":PtEff");
          keyword += k;
          value_pt.push_back(configuration.getValueDouble(keyword));
          }
        keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":nEtaPoints");
        int nEtaPoints = configuration.getValueInt(keyword);
        for (int k=0;k<nEtaPoints;k++)
          {
          keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":Eta");
          keyword += k;
          thres_eta.push_back(configuration.getValueDouble(keyword));
          keyword = createName("EfficiencyFilter:Filter",iEfficiencyFilter,":EtaEff");
          keyword += k;
          value_eta.push_back(configuration.getValueDouble(keyword));
          }
        histoName = createName("EfficiencyFilter_Filter",iEfficiencyFilter,"_histo2");
        TH1 * h = setupEffVsEtaPt(histoName,nBins_eta,min_eta,max_eta,nBins_pt,min_pt,max_pt,thres_eta,value_eta,thres_pt,value_pt);
        filter->setEffHisto(h);
        break;
        }
      }
    }

  if (true)
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
    name = configuration.getValueString(keyword);
    keyword = createName("JetFilter:Filter",iJetFilter,":Title");
    title = configuration.getValueString(keyword);
    keyword = createName("JetFilter:Filter",iJetFilter,":nConditions");
    nConditions = configuration.getValueInt(keyword,1,0);
    for (int iCondition=0; iCondition<nConditions; iCondition++)
      {
      keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Type");
      conditionType  = configuration.getValueString(keyword);
      conditionTypes.push_back(conditionType);
      keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Subtype");
      conditionSubtype  = configuration.getValueString(keyword);
      conditionSubtypes.push_back(conditionSubtype);
      keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Minimum");
      minimum  = configuration.getValueDouble(keyword);
      conditionMinima.push_back(minimum);
      keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Maximum");
      maximum  = configuration.getValueDouble(keyword);
      conditionMaxima.push_back(maximum);

      if (conditionType.EqualTo("DoubleDualRange"))
        {
        keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Minimum2");
        minimum2  = configuration.getValueDouble(keyword);
        conditionMinima2.push_back(minimum2);
        keyword = createName("JetFilter:Filter",iJetFilter,":Condition",iCondition,":Maximum2");
        maximum2  = configuration.getValueDouble(keyword);
        conditionMaxima2.push_back(maximum2);
        }
      else
        {
        conditionMinima2.push_back(0.0);
        conditionMaxima2.push_back(0.0);
        }
      createJetFilter(name,title,
                      conditionTypes, conditionSubtypes,
                      conditionMinima, conditionMaxima,
                      conditionMinima2, conditionMaxima2);
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

void FilterCreator::finalize()
{
  // do nothing...
}


EventFilter *  FilterCreator::createEventFilter(const String & name,
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

  return filter;
}


ParticleFilter *  FilterCreator::createParticleFilter(const String & name,
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
  return filter;
}

EfficiencyFilter *  FilterCreator::createEfficiencyFilter(const String & name,
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
    printValue("FilterCreator::createEfficiencyFilter() name",name);
    printValue("FilterCreator::createEfficiencyFilter() title",title);
    for (unsigned int k=0; k<conditionTypes.size(); k++)
      {
      printValue("FilterCreator::createEfficiencyFilter() condition index",k);
      printValue("FilterCreator::createEfficiencyFilter() conditionTypes",   conditionTypes[k]);
      printValue("FilterCreator::createEfficiencyFilter() conditionSubtypes",conditionSubtypes[k]);
      printValue("FilterCreator::createEfficiencyFilter() conditionMinima",  conditionMinima[k]);
      printValue("FilterCreator::createEfficiencyFilter() conditionMaxima",  conditionMaxima[k]);
      printValue("FilterCreator::createEfficiencyFilter() conditionMinima2", conditionMinima2[k]);
      printValue("FilterCreator::createEfficiencyFilter() conditionMaxima2", conditionMaxima2[k]);
      }
    printLine();
    }
  EfficiencyFilter * filter = Manager<EfficiencyFilter>::getStoreObjectNamed(name);
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
  return filter;
}


JetFilter *  FilterCreator::createJetFilter(const String & name,
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
    printValue("FilterCreator::createJetFilter() name",name);
    printValue("FilterCreator::createJetFilter() title",title);
    for (unsigned int k=0; k<conditionTypes.size(); k++)
      {
      printValue("FilterCreator::createJetFilter() condition index",  k);
      printValue("FilterCreator::createJetFilter() conditionTypes",   conditionTypes[k]);
      printValue("FilterCreator::createJetFilter() conditionSubtypes",conditionSubtypes[k]);
      printValue("FilterCreator::createJetFilter() conditionMinima",  conditionMinima[k]);
      printValue("FilterCreator::createJetFilter() conditionMaxima",  conditionMaxima[k]);
      printValue("FilterCreator::createJetFilter() conditionMinima2", conditionMinima2[k]);
      printValue("FilterCreator::createJetFilter() conditionMaxima2", conditionMaxima2[k]);
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
  return filter;
}

TH1 * FilterCreator::setupEffVsPt(const String & histoName,
                                  int nBins_pt,
                                  double min_pt,
                                  double max_pt,
                                  const vector<double> & thres_pt,
                                  const vector<double> & value_pt)
{
  TH1 * h = new TH1D(histoName,histoName,nBins_pt,min_pt,max_pt);
  double width_pt = (max_pt-min_pt)/double(nBins_pt);
  //int nSteps = thres_pt.size();
  int iStep  = 0;
  //double lastEff = 0.0;
  double eff = 0.0;
  int ipt;
  double pt = min_pt+width_pt/2.0;
  while (pt<max_pt)
    {
    ipt = h->GetXaxis()->FindBin(pt);
    if (pt<thres_pt[0])
      {
      eff = 0.0;
      //lastEff = eff;
      h->SetBinContent(ipt,eff);
      pt += width_pt;
      }
    else if (pt<=thres_pt[iStep])
      {
      double a = (value_pt[iStep] - value_pt[iStep-1])/(thres_pt[iStep] - thres_pt[iStep-1]);
      eff = value_pt[iStep-1] + a * (pt-thres_pt[iStep-1]);
      //if (pt<1) cout << "iStep:" << iStep << "  pt:" << pt << "   a:" << a << "  eff:" << eff << "  last eff:" << lastEff << endl;
      if (eff>1)
        eff = 1.0;
      else if (eff<0)
        eff = 0.0;
      //lastEff = eff;
      h->SetBinContent(ipt,eff);
      pt += width_pt;
      }
    else
      iStep++;
    }
  return h;
}

TH2 * FilterCreator::setupEffVsEtaPt(const String & histoName,
                                     int nBins_eta,
                                     double min_eta,
                                     double max_eta,
                                     int nBins_pt,
                                     double min_pt,
                                     double max_pt,
                                     const vector<double> & thres_eta,
                                     const vector<double> & value_eta,
                                     const vector<double> & thres_pt,
                                     const vector<double> & value_pt)
{
  TH2 * h = new TH2D(histoName,histoName,nBins_eta,min_eta,max_eta,nBins_pt,min_pt,max_pt);
  double width_pt  = (max_pt-min_pt)/double(nBins_pt);
  double width_eta = (max_eta-min_eta)/double(nBins_eta);
  //int nSteps_pt = thres_pt.size();
  int iStep_pt  = 0;
  //int nSteps_eta = thres_eta.size();
  int iStep_eta  = 0;
  //double lastEff_eta = 0.0;
  double eff_eta = 0.0;
  //double lastEff_pt = 0.0;
  double eff_pt = 0.0;
  int ipt;
  int ieta;
  double pt  = min_pt+width_pt/2.0;
  double eta = min_eta+width_eta/2.0;
  double a_eta;
  double a_pt;
  while (eta<max_eta)
    {
    ieta = h->GetXaxis()->FindBin(eta);
    pt  = min_pt+width_pt/2.0;
    if (eta<thres_eta[0])
      {
      eff_eta = 0.0;
      //lastEff_eta = eff_eta;
      for (ipt=0; ipt<nBins_pt; ipt++) h->SetBinContent(ieta,ipt,eff_eta);
      eta += width_eta;
      }
    else  if (eta<thres_eta[iStep_eta])
      {
      a_eta = (value_eta[iStep_eta] - value_eta[iStep_eta-1])/(thres_eta[iStep_eta] - thres_eta[iStep_eta-1]);
      eff_eta = value_eta[iStep_eta-1] + a_eta * (eta-thres_eta[iStep_eta-1]);
      if (eff_eta>1)
        eff_eta = 1.0;
      else if (eff_eta<0)
        eff_eta = 0.0;
      //lastEff_eta = eff_eta;
      pt  = min_pt+width_pt/2.0;
      while (pt<max_pt)
        {
        ipt  = h->GetYaxis()->FindBin(pt);
        if (pt<thres_pt[0])
          {
          eff_pt = 0.0;
          //  lastEff_pt = eff_pt;
          h->SetBinContent(ieta,ipt,eff_pt);
          pt += width_pt;
          }
        else if (pt<=thres_pt[iStep_pt])
          {
          a_pt = (value_pt[iStep_pt] - value_pt[iStep_pt-1])/(thres_pt[iStep_pt] - thres_pt[iStep_pt-1]);
          eff_pt = value_pt[iStep_pt-1] + a_pt * (pt-thres_pt[iStep_pt-1]);
          if (eff_pt>1)
            eff_pt = 1.0;
          else if (eff_pt<0)
            eff_pt = 0.0;
          //lastEff_pt = eff_pt;
          h->SetBinContent(ieta,ipt,eff_eta*eff_pt);
          pt += width_pt;
          }
        else
          iStep_pt++;
        }
      eta += width_eta;
      }
    else
      iStep_eta++;
    }
  return h;
}




} // namespace CAP
