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
#include "TSystem.h"
#include "TROOT.h"
#include "TRint.h"
#include "TAxis.h"
#include "TKey.h"
#include "TRandom.h"
#include "TSystem.h"
#include "HistogramGroup.hpp"
#include "MathConstants.hpp"
#include "MathBasicFunctions.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "Task.hpp"

ClassImp(CAP::HistogramGroup);

namespace CAP
{

HistogramGroup::HistogramGroup()
:
NamedObject(),
MessageLogger(),
configuration(),
parent(nullptr),
histograms(),
ownership(false)
{
  setClassName("HistogramGroup");
  setInstanceName("HistogramGroup");
}

HistogramGroup::HistogramGroup(const HistogramGroup & group)
:
NamedObject(group),
MessageLogger(group),
configuration(group.configuration),
parent(group.parent),
histograms(),
ownership(group.ownership)
{
//  for (auto & histogram : group.histograms)
//    append( (TH1*) histogram->Clone());
}

HistogramGroup & HistogramGroup::operator=(const HistogramGroup & group)
{
  if (this!=&group)
    {
    NamedObject::operator=(group);
    MessageLogger::operator=(group);
    configuration =  group.configuration;
    parent        =  group.parent;
    ownership     =  group.ownership;
//    for (auto & histogram : group.histograms)
//      append( (TH1*) histogram->Clone());
    }
  return *this;
}

const vector<TH1*> & HistogramGroup::getHistograms() const
{
  return histograms;
}

vector<TH1*> & HistogramGroup::getHistograms()
{
  return histograms;
}

//!
//!Reset all histograms to zero
//!
void HistogramGroup::resetHistograms()
{
  for (auto & histogram : histograms) histogram->Reset();
}

//!
//!Clear all histograms
//!
void HistogramGroup::clearHistograms()
{
  for (auto & histogram : histograms) histogram->Clear();
  histograms.clear();
}

//!
//! Overload this class to create histograms.
//!
void HistogramGroup::createHistograms()
{
  throw Exception("Improper call to createHistograms() in base class", "HistogramGroup::createHistograms()");
}

//!
//! Overload this class to load histograms.
//!
void HistogramGroup::importHistograms(TFile & inputFile __attribute__((unused)))
{
  throw Exception("Improper call to HistogramGroup base class", "HistogramGroup::importHistograms(...)");
}

void HistogramGroup::exportHistograms(TFile & outputFile)
{
  outputFile.cd();
  for (auto & histogram : histograms) histogram->Write();
}

// needs to be implemented...
void HistogramGroup::exportHistograms(ofstream & outputFile __attribute__((unused)) )
{
  //for (auto & histogram : histograms) histogram->Write();
}

void HistogramGroup::scaleHistograms(double a)
{
  for (auto & histogram : histograms)
    {
    if ((histogram->IsA()==TProfile::Class()) ||
        (histogram->IsA()==TProfile2D::Class()) ) continue;
    histogram->Scale(a);
    }
}

void HistogramGroup::addHistogram(double a1, const TH1 * h1,
                                  double a2, TH1 * sum)
{
  if (!sameDimensions(__FUNCTION__,h1,sum)) throw IncompatibleHistogramException(__FUNCTION__);
  sum->Scale(a2);
  sum->Add(h1,a1);
}
void HistogramGroup::addHistogram(double a1, const TH1 * h1,
                                  double a2, const TH1 * h2,
                                  TH1 * sum)
{
  if (!sameDimensions(__FUNCTION__,h1,h2,sum)) throw IncompatibleHistogramException(__FUNCTION__);
  sum->Add(h1,h2,a1,a2);
}

void HistogramGroup::addHistogram(double a1, const TH1 * h1,
                                  double a2, const TH1 * h2,
                                  double a3, const TH1 * h3,
                                  TH1 * sum)
{
  if (!sameDimensions(__FUNCTION__,h1,h2,h3,sum)) throw IncompatibleHistogramException(__FUNCTION__);
  sum->Add(h1,h2,a1,a2);
  sum->Add(h3,a3);
}

void HistogramGroup::addHistogram(double a1, const TH1 * h1,
                                  double a2, const TH1 * h2,
                                  double a3, const TH1 * h3,
                                  double a4, const TH1 * h4,
                                  TH1 * sum)
{
  if (!sameDimensions(__FUNCTION__,h1,h2,h3,h4,sum)) throw IncompatibleHistogramException(__FUNCTION__);
  sum->Add(h1,h2,a1,a2);
  sum->Add(h3,a3);
  sum->Add(h4,a4);
}

void HistogramGroup::divideHistogram(const TH1 * h1,
                                     TH1 * ratio)
{
  if (!sameDimensions(__FUNCTION__,h1,ratio)) throw IncompatibleHistogramException(__FUNCTION__);
  ratio->Divide(h1);
}


void HistogramGroup::divideHistogram(const TH1 * h1,
                                     const TH1 * h2,
                                     TH1 * ratio)
{
  if (!sameDimensions(__FUNCTION__,h1,h2,ratio)) throw IncompatibleHistogramException(__FUNCTION__);
  ratio->Divide(h1,h2);
}

void HistogramGroup::differenceHistogram(const TH1 * h1,
                                         const TH1 * h2,
                                         TH1 * diff,
                                         bool correlatedUncertainties __attribute__(( unused)))
{
  if (!sameDimensions(__FUNCTION__,h1,h2,diff)) throw IncompatibleHistogramException(__FUNCTION__);
  diff->Add(h1,h2,1.0,-1.0);
}

void loadGroup(TFile & inputFile);

void HistogramGroup::addGroup(const HistogramGroup & g2,
                              double a1,
                              double a2)
{
  if (!sameSizeAs(g2)) throw IncompatibleGroupException(__FUNCTION__);
  for (unsigned int k=0; k<histograms.size(); k++)
    addHistogram(a2,g2.histograms[k],a1,histograms[k]);
}

void HistogramGroup::addGroup(const HistogramGroup & g2,
                              double a2)
{
  if (!sameSizeAs(g2)) throw IncompatibleGroupException(__FUNCTION__);
  for (unsigned int k=0; k<histograms.size(); k++)
    addHistogram(a2,g2.histograms[k],1.0,histograms[k]);
}

void HistogramGroup::addGroup(const HistogramGroup & g1,
                              const HistogramGroup & g2,
                              double a1,double a2)
{
  if (!sameSizeAs(g1,g2)) throw IncompatibleGroupException(__FUNCTION__);
  for (unsigned int k=0; k<histograms.size(); k++)
    addHistogram(a1,g1.histograms[k],a2,g2.histograms[k],histograms[k]);
}

//!
//! Add the histograms of the given groups and store results in this group
//!
void HistogramGroup::addGroup(const HistogramGroup & g1,
                              const HistogramGroup & g2,
                              const HistogramGroup & g3,
                              double a1, double a2, double a3)
{
  if (!sameSizeAs(g1,g2,g3)) throw IncompatibleGroupException(__FUNCTION__);
  for (unsigned int k=0; k<histograms.size(); k++)
    addHistogram(a1,g1.histograms[k],
                 a2,g2.histograms[k],
                 a3,g3.histograms[k],
                 histograms[k]);
}

//!
//! Add the histograms of the given groups and store results in this group
//! 
void HistogramGroup::addGroup(const HistogramGroup & g1,
                              const HistogramGroup & g2,
                              const HistogramGroup & g3,
                              const HistogramGroup & g4,
                              double a1, double a2, double a3, double a4)
{
  if (!sameSizeAs(g1,g2,g3,g4)) throw IncompatibleGroupException(__FUNCTION__);
  for (unsigned int k=0; k<histograms.size(); k++)
    addHistogram(a1,g1.histograms[k],
                 a2,g2.histograms[k],
                 a3,g3.histograms[k],
                 a4,g4.histograms[k],
                 histograms[k]);
}

//! 
//! Divide the histograms of this group by those of the given group
//! 
void HistogramGroup::divideGroup(const HistogramGroup & g1)
{
  if (!sameSizeAs(g1)) throw IncompatibleGroupException(__FUNCTION__);
  for (unsigned int k=0; k<histograms.size(); k++)
    divideHistogram(g1.histograms[k],histograms[k]);
}

//! 
//! Divide the histograms of  group g1 by those of group g2 and store
//! the result in this group
//!
void HistogramGroup::divideGroup(const HistogramGroup & g1,
                                 const HistogramGroup & g2)
{
  if (!sameSizeAs(g1,g2)) throw IncompatibleGroupException(__FUNCTION__);
  for (unsigned int k=0; k<histograms.size(); k++)
    divideHistogram(g1.histograms[k],g2.histograms[k],histograms[k]);
}

// HERE

void HistogramGroup::differenceGroup(const HistogramGroup & g1,
                                     const HistogramGroup & ref,
                                     bool correlatedUncertainties __attribute__((unused)) )
{

  printString("HistogramGroup::differenceGroup -1-");

  if (!g1.sameSizeAs(ref) )
    {
    printIncompatibleGroups(__FUNCTION__,g1,ref);
    throw IncompatibleGroupException(__FUNCTION__);
    }
  printString("HistogramGroup::differenceGroup -2-");
  for (unsigned int k=0; k<g1.histograms.size(); k++)
    {
    printValue("Computing k",k);
    TH1 * diff = (TH1 *) g1.histograms[k]->Clone();
    diff->Add(ref.histograms[k],-1.0);
    String name = diff->GetName();
    name.ReplaceAll("Reco","Diff");
    diff->SetName(name);
    diff->SetTitle(name);
    histograms.push_back(diff);
    }
}




Task * HistogramGroup::getParentTask() const
{
  return parent;
}

const String HistogramGroup::getParentName() const
{
  return parent->getName();
}

const String HistogramGroup::getParentPathName() const
{
  return parent->getFullTaskPath();
}

void  HistogramGroup::setParentTask(Task * parentTask)
{
  parent = parentTask;
}


void HistogramGroup::setConfiguration(const Configuration & config)
{
  configuration.addProperties(config);
}

void HistogramGroup::push_back(TH1* h)
{
  histograms.push_back(h);
}

TH1 * HistogramGroup::append(TH1* h)
{
  histograms.push_back(h);
  return h;
}

TH2 * HistogramGroup::append(TH2* h)
{
  histograms.push_back(h);
  return h;
}

TH3 * HistogramGroup::append(TH3* h)
{
  histograms.push_back(h);
  return h;
}

TProfile * HistogramGroup::append(TProfile* h)
{
  histograms.push_back(h);
  return h;
}

TProfile2D * HistogramGroup::append(TProfile2D * h)
{
  histograms.push_back(h);
  return h;
}



//!
//! Create 1D histogram
//!
TH1 * HistogramGroup::createHistogram(const String & name,
                                      int n_x, double min_x, double max_x,
                                      const String & title_x,
                                      const String & title_y,
                                      int storageOption)
{
  return append(createNewHistogram(name,n_x,min_x,max_x,title_x,title_y,storageOption));
}



//!
//! Create 1D histogram
//!
TH1 * HistogramGroup::createHistogram(const String & name,
                                      int n_x, double * bins,
                                      const String & title_x,
                                      const String & title_y,
                                      int storageOption)
{
  return append(createNewHistogram(name,n_x,bins,title_x,title_y,storageOption));
}

//!
//! Create 2D histogram
//!
TH2 * HistogramGroup::createHistogram(const String & name,
                                      int n_x, double min_x, double max_x,
                                      int n_y, double min_y, double max_y,
                                      const String & title_x,
                                      const String & title_y,
                                      const String & title_z,
                                      int storageOption)
{
  return append(createNewHistogram(name,n_x,min_x,max_x,n_y,min_y,max_y,title_x,title_y,title_z,storageOption));
}

//!
// Create 2D histogram
//!
TH2 * HistogramGroup::createHistogram(const String & name,
                                      int n_x, double* xbins, 
                                      int n_y, double min_y, double max_y,
                                      const String & title_x,
                                      const String & title_y,
                                      const String & title_z,
                                      int storageOption)

{
  return append(createNewHistogram(name,n_x,xbins,n_y,min_y,max_y,title_x,title_y,title_z,storageOption));
}


//!
// Create 3D histogram
//!
TH3 * HistogramGroup::createHistogram(const String & name,
                                      int n_x, double min_x, double max_x,
                                      int n_y, double min_y, double max_y,
                                      int n_z, double min_z, double max_z,
                                      const String & title_x,
                                      const String & title_y,
                                      const String & title_z,
                                      int storageOption)

{
  return append(createNewHistogram(name,n_x,min_x,max_x,n_y,min_y,max_y,n_z,min_z,max_z,title_x,title_y,title_z,storageOption));
}

//!
//! Create 1D profile histogram
//!
TProfile * HistogramGroup::createProfile(const String & name,
                                         int n_x,double min_x,double max_x,
                                         const String & title_x,
                                         const String & title_y)
{
  return append(createNewProfile(name,n_x,min_x,max_x,title_x,title_y));
}

//!
// Create 1D profile histogram
//!
TProfile * HistogramGroup::createProfile(const String & name,
                                         int n_x,  double* bins,
                                         const String & title_x,
                                         const String & title_y)
{
  return append(createNewProfile(name,n_x,bins,title_x,title_y));
}

//!
// Create 2D profile histogram
//!
TProfile2D * HistogramGroup::createProfile(const String & name,
                                           int n_x, double min_x, double max_x,
                                           int n_y, double min_y, double max_y,
                                           const String & title_x,
                                           const String & title_y,
                                           const String & title_z)
{
  return append(createNewProfile(name,n_x,min_x,max_x,n_y,min_y,max_y,title_x,title_y,title_z));
}

//!
//! Add HistogramGroup to an external list
//!
void HistogramGroup::addHistogramsToExtList(TList *list)
{
  for (auto & histogram : histograms) list->Add(histogram);
}

//!
//! Load histograms in the given file and add them to this group.
//!
void  HistogramGroup::loadGroup(TFile & inputFile)
{
  TIter keyList(inputFile.GetListOfKeys());
  TKey *key;
  while ((key = (TKey*)keyList()))
    {
    TClass *cl = gROOT->GetClass(key->GetClassName());
    if (!cl->InheritsFrom("TH1")) continue;
    TH1 *h = (TH1*)key->ReadObj();
    if (!h) throw HistogramException("Histogram","Histogram not read",__FUNCTION__);
    append(h);
    }
}


//! 
//! Add the histograms of the given group to those of this group
//!
HistogramGroup * HistogramGroup::clone() const
{
  HistogramGroup * newGroup = new HistogramGroup();
  for (auto & histogram : histograms) newGroup->append((TH1*) histogram->Clone());
  return newGroup;
}

CAP::Size_t HistogramGroup::size() const
{
  return histograms.size();
}

bool HistogramGroup::sameSizeAs(const HistogramGroup & g) const
{
  return size() == g.size();
}

bool HistogramGroup::sameSizeAs(const HistogramGroup & g1, const HistogramGroup & g2) const
{
  Size_t n = size();
  return n==g1.size() && n==g2.size();
}

bool HistogramGroup::sameSizeAs(const HistogramGroup & g1,
                                const HistogramGroup & g2,
                                const HistogramGroup & g3) const
{
  Size_t n = size();
  return n==g1.size() && n==g2.size() && n==g3.size();
}

bool HistogramGroup::sameSizeAs(const HistogramGroup & g1,
                                const HistogramGroup & g2,
                                const HistogramGroup & g3,
                                const HistogramGroup & g4) const
{
  Size_t n = size();
  return n==g1.size() && n==g2.size() && n==g3.size() && n==g4.size();
}


void HistogramGroup::printIncompatibleGroups(const String & caller, 
                                             const HistogramGroup & g1,
                                             const HistogramGroup & g2)
{
  printCR();
  printValue("Incompatible groups in call from",caller);
  printValue("Group 1 Name",g1.getName());
  printValue("Group 1 Size",g1.size());
  printValue("Group 2 Name",g2.getName());
  printValue("Group 2 Size",g2.size());
}

void HistogramGroup::printIncompatibleGroups(const String & caller,
                                             const HistogramGroup & g1,
                                             const HistogramGroup & g2,
                                             const HistogramGroup & g3)
{
  printCR();
  printValue("Incompatible groups in call from",caller);
  printValue("Group 1 Name",g1.getName());
  printValue("Group 1 Size",g1.size());
  printValue("Group 2 Name",g2.getName());
  printValue("Group 2 Size",g2.size());
  printValue("Group 3 Name",g3.getName());
  printValue("Group 3 Size",g3.size());
}


void HistogramGroup::printIncompatibleGroups(const String & caller,
                                             const HistogramGroup & g1,
                                             const HistogramGroup & g2,
                                             const HistogramGroup & g3,
                                             const HistogramGroup & g4)
{
  printCR();
  printValue("Incompatible groups in call from",caller);
  printValue("Group 1 Name",g1.getName());
  printValue("Group 1 Size",g1.size());
  printValue("Group 2 Name",g2.getName());
  printValue("Group 2 Size",g2.size());
  printValue("Group 3 Name",g3.getName());
  printValue("Group 3 Size",g3.size());
  printValue("Group 4 Name",g4.getName());
  printValue("Group 4 Size",g4.size());
}

void HistogramGroup::ratioGroup(const HistogramGroup & g1, const HistogramGroup & g2, bool correlatedUncertainties)
{
  if (!g1.sameSizeAs(g2))
    {
      printIncompatibleGroups(__FUNCTION__,g1,g2);
      throw IncompatibleGroupException(__FUNCTION__);
    }
  const vector<TH1*> & histograms1 = g1.getHistograms();
  const vector<TH1*> & histograms2 = g2.getHistograms();
  int k = 0;
  for (auto & h1 : histograms1)
    {
    TH1* h2 = histograms2[k++];
    if (!sameDimensions(__FUNCTION__,h1,h2))  throw IncompatibleHistogramException(__FUNCTION__);
    TH1* hRatio = (TH1*)  h1->Clone();
    String name = hRatio->GetName();
    name.ReplaceAll("Reco","Ratio");
    hRatio->SetName(name);
    hRatio->SetTitle(name);
    ratioHistos(h1,h2,hRatio,correlatedUncertainties);
    append(hRatio);
    }
}

//!
//! Calculate square difference (bin by bin) of all  histograms of the other  group relative to the
//! reference group and store the result in the histograms of  this group.
//! TProfile histograms have to be handled differently
//! This function is used for sub-sample analyses..
//! double sumWeights: sum of the weights of the n-1 group accumulated in this group
//!     double weight: weight of the current n-th group.
//! The means are store in the BinContent
//! The rms are store in the BinError parts of the histograms.
//!
void HistogramGroup::squareDifferenceGroup(const HistogramGroup & g1, double sumWeights, double weight, int n)
{
  if (!sameSizeAs(g1))
    {
    printIncompatibleGroups(__FUNCTION__,*this,g1);
    throw IncompatibleGroupException(__FUNCTION__);
    }

  int k = 0;
  const vector<TH1*> & histograms1 = g1.getHistograms();
  for (auto & h0 : histograms)
    {
    TH1* h1    = histograms1[k++];
    if (!sameDimensions(__FUNCTION__,h0,h1))  throw IncompatibleHistogramException(__FUNCTION__);
    squareDifferenceHistos(h0, h1, sumWeights, weight, n);
    }
}



TH1 * HistogramGroup::importH1(TFile & inputFile,const String & histoName)
{
  return append(loadH1(inputFile,histoName));
}

///Load the given 1D histogram (name) from the given TFile
///No test is //done to verify that the file is properly opened.

TH2 * HistogramGroup::importH2(TFile & inputFile,const String & histoName)
{
  return append(loadH2(inputFile,histoName));
}

///Load the given 3D histogram (name) from the given TFile
///No test is //done to verify that the file is properly opened.
TH3 * HistogramGroup::importH3(TFile & inputFile, const String & histoName)
{
  return append(loadH3(inputFile,histoName));
}

///Load the given 3D histogram (name) from the given TFile
///No test is //done to verify that the file is properly opened.
TProfile * HistogramGroup::importProfile(TFile & inputFile, const String & histoName)
{
  return append(loadProfile(inputFile,histoName));
}

TProfile2D * HistogramGroup::importProfile2D(TFile & inputFile, const String & histoName)
{
  return append(loadProfile2D(inputFile,histoName));
}

void HistogramGroup::importHistogramsInList(TFile & inputFile, HistogramGroup * group)
{
  const vector<TH1*> & histograms = group->getHistograms();
  for (auto & histogram : histograms) append(loadH1(inputFile,histogram->GetName()));
}

void HistogramGroup::sumw2All()
{
  for (auto & h : histograms)
    {
    TClass * c = h->IsA();
    if (c==TProfile::Class() || c==TProfile2D::Class()) continue;
    if (h->GetEntries()>0) h->Sumw2();
    }
}

void HistogramGroup::scaleAllHistoByBinWidth(double scale)
{
  for (auto & h : histograms)
    {
    TClass * c = h->IsA();
    if (c == TProfile::Class() || c == TProfile2D::Class()) continue;
    else if (c == TH1F::Class() || c == TH1D::Class()) scaleByBinWidth1D(h, scale);
    else if (c == TH2F::Class() || c == TH2D::Class()) scaleByBinWidth2D((TH2*) h, scale);
    }
}

void HistogramGroup::setOwnership(bool _own)
{
  ownership = _own;
}

bool HistogramGroup::isOwner()
{
  return ownership;
}

} // namespace CAP
