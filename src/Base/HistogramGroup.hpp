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
#ifndef CAP__HistogramGroup
#define CAP__HistogramGroup
#include "TFile.h"
#include "TH1.h"
#include "TProfile2D.h"
#include "Aliases.hpp"
#include "Configuration.hpp"
#include "NamedObject.hpp"
#include "MessageLogger.hpp"
#include "Exceptions.hpp"
#include "Task.hpp"

namespace CAP
{
class HistogramGroup
:
public NamedObject,
public MessageLogger
{
protected:

  Configuration configuration;
  Task * parent;
  std::vector<TH1*> histograms;
  bool ownership;
public:

  HistogramGroup();
  HistogramGroup(const HistogramGroup & group);
  HistogramGroup & operator=(const HistogramGroup & group);
  ~HistogramGroup() {}
  const std::vector<TH1*> & getHistograms() const;
  std::vector<TH1*> & getHistograms();
  virtual void resetHistograms();
  virtual void clearHistograms();
  virtual void createHistograms();
  virtual void importHistograms(TFile & file);
  virtual void exportHistograms(TFile & file);
  virtual void exportHistograms(ofstream & outputFile);
  virtual void scaleHistograms(double a);

  void setOwnership(bool _own);
  bool isOwner();
  
  //!
  //! Sets the configuration of this task instance.
  //!
  void setConfiguration(const Configuration & config);

  virtual void cloneHistoVector(const std::vector<TH1*> & source, std::vector<TH1*> & target);
  virtual void cloneHistoVector(const std::vector<TH2*> & source, std::vector<TH2*> & target);
  virtual void cloneHistoVector(const std::vector<TH3*> & source, std::vector<TH3*> & target);
  virtual void cloneHistoVector(const std::vector<TProfile*> & source, std::vector<TProfile*> & target);
  virtual void cloneHistoVector(const std::vector<TProfile2D*> & source, std::vector<TProfile2D*> & target);

  Task * getParentTask() const;
  const String getParentName() const;
  const String getParentPathName() const;
  void  setParentTask(Task * parentTask);

  
  void push_back(TH1* h);
  TH1 * append(TH1* h);
  TH2 * append(TH2* h);
  TH3 * append(TH3* h);
  TProfile * append(TProfile* h);
  TProfile2D * append(TProfile2D* h);
  TH1 * createHistogram(const String & name,
                        int n, double min_x, double max_x,
                        const String & title_x="",
                        const String & title_y="",
                        int storageOption=1);
  TH1 * createHistogram(const String & name,
                        int n, double * bins,
                        const String & title_x="",
                        const String & title_y="",
                        int storageOption=1);
  TH2 * createHistogram(const String & name,
                        int n_x, double min_x, double max_x,
                        int n_y, double min_y, double max_y,
                        const String & title_x="",
                        const String & title_y="",
                        const String & title_z="",
                        int storageOption=1);
  TH2 * createHistogram(const String & name,
                        int n_x, double* xbins, int n_y, double min_y, double max_y,
                        const String & title_x="",
                        const String & title_y="",
                        const String & title_z="",
                        int storageOption=1);
  TH3 * createHistogram(const String & name,
                        int n_x, double min_x, double max_x,
                        int n_y, double min_y, double max_y,
                        int n_z, double min_z, double max_z,
                        const String & title_x="",
                        const String & title_y="",
                        const String & title_z="",
                        int storageOption=1);
  TProfile * createProfile(const String & _name,
                           int n_x,double min_x,double max_x,
                           const String & title_x,
                           const String & title_y);

  TProfile * createProfile(const String & name,
                           int n_x,  double* bins,
                           const String & title_x,
                           const String & title_y);

  TProfile2D * createProfile(const String & title,
                             int n_x, double min_x, double max_x,
                             int n_y, double min_y, double max_y,
                             const String & title_x,
                             const String & title_y,
                             const String & title_z);

  void addHistogramsToExtList(TList *list);


  Size_t size() const;
  bool sameSizeAs(const HistogramGroup & g) const;
  bool sameSizeAs(const HistogramGroup & g1, const HistogramGroup & g2) const;
  bool sameSizeAs(const HistogramGroup & g1, const HistogramGroup & g2, const HistogramGroup & g3) const;
  bool sameSizeAs(const HistogramGroup & g1, const HistogramGroup & g2, const HistogramGroup & g3, const HistogramGroup & g4) const;


//
  virtual void addHistogram(double a1, const TH1 * h1,
                            double a2, TH1 * sum);
  virtual void addHistogram(double a1, const TH1 * h1,
                            double a2, const TH1 * h2,
                            TH1 * sum);
  virtual void addHistogram(double a1, const TH1 * h1,
                            double a2, const TH1 * h2,
                            double a3, const TH1 * h3,
                            TH1 * sum);
  virtual void addHistogram(double a1, const TH1 * h1,
                            double a2, const TH1 * h2,
                            double a3, const TH1 * h3,
                            double a4, const TH1 * h4,
                            TH1 * sum);
  virtual void divideHistogram(const TH1 * h1,
                               TH1 * ratio);
  virtual void divideHistogram(const TH1 * h1,
                               const TH1 * h2,
                               TH1 * ratio);
  virtual void differenceHistogram(const TH1 * h1,
                                   const TH1 * h2,
                                   TH1 * diff,
                                   bool correlatedUncertainties);
  //
  void loadGroup(TFile & inputFile);

  virtual void addGroup(const HistogramGroup & g2,
                        double a1=1.0,
                        double a2=1.0);
  virtual void addGroup(const HistogramGroup & g2,
                        double a2=1.0);
  virtual void addGroup(const HistogramGroup & g1,
                        const HistogramGroup & g2, 
                        double a1=1.0,double a2=1.0);
  virtual void addGroup(const HistogramGroup & g1,
                        const HistogramGroup & g2,
                        const HistogramGroup & g3,
                        double a1=1.0, double a2=1.0, double a3=1.0);
  virtual void addGroup(const HistogramGroup & g1,
                        const HistogramGroup & g2,
                        const HistogramGroup & g3,
                        const HistogramGroup & g4,
                        double a1=1.0, double a2=1.0, double a3=1.0, double a4=1.0);
  virtual void divideGroup(const HistogramGroup & c1);
  virtual void divideGroup(const HistogramGroup & c1,
                           const HistogramGroup & c2);
  virtual void ratioGroup(const HistogramGroup & g1,
                          const HistogramGroup & g2,
                          bool correlatedUncertainties=0);

  virtual void differenceGroup(const HistogramGroup & g1,
                               const HistogramGroup & ref,
                               bool correlatedUncertainties=0);
  void squareDifferenceGroup(const HistogramGroup & group,
                             double sumWeights, double weight, int n);
  void squareDifferenceCollection(const HistogramGroup & g1,
                                  double sumWeights, double weight, int n);
  HistogramGroup * clone() const;


  void printIncompatibleGroups(const String & caller, const HistogramGroup & g1, const HistogramGroup & g2);
  void printIncompatibleGroups(const String & caller, const HistogramGroup & g1, const HistogramGroup & g2, const HistogramGroup & g3);
  void printIncompatibleGroups(const String & caller, const HistogramGroup & g1, const HistogramGroup & g2, const HistogramGroup & g3, const HistogramGroup & g4);

  void sumw2All();
  void scaleAllHistoByBinWidth(double scale);
  TH1 * importH1(TFile & inputFile,const String & histoName);
  TH2 * importH2(TFile & inputFile,const String & histoName);
  TH3 * importH3(TFile & inputFile, const String & histoName);
  TProfile * importProfile(TFile & inputFile, const String & histoName);
  TProfile2D * importProfile2D(TFile & inputFile, const String & histoName);
  void importHistogramsInList(TFile & inputFile, HistogramGroup * group);
  ClassDef(HistogramGroup,0)
};

} // namespace CAP

#endif /* CAP__Histograms */
