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
#include "BalanceFunctionCalculator.hpp"
#include "HistogramGroup.hpp"
#include "MathConstants.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"

ClassImp(CAP::BalanceFunctionCalculator)

namespace CAP
{

BalanceFunctionCalculator::BalanceFunctionCalculator()
:
EventTask(),
sObsNames(),
pObsNames(),
allFilesToAnalyze(),
appendedString("BalFct"),
calculateCI(true),
calculateCD(true),
calculateBF(true),
calculateDiffs(false)
{
  appendClassName("BalanceFunctionCalculator");
  setInstanceName("BF");
}

BalanceFunctionCalculator::BalanceFunctionCalculator(const BalanceFunctionCalculator & task)
:
EventTask(task),
sObsNames(task.sObsNames),
pObsNames(task.pObsNames),
allFilesToAnalyze(task.allFilesToAnalyze),
calculateCI(task.calculateCI),
calculateCD(task.calculateCD),
calculateBF(task.calculateBF),
calculateDiffs(task.calculateDiffs)
{   }

BalanceFunctionCalculator & BalanceFunctionCalculator::operator=(const BalanceFunctionCalculator & task)
{
  if (this!=&task)
    {
    EventTask::operator=(task);
    sObsNames = task.sObsNames;
    pObsNames = task.pObsNames;
    allFilesToAnalyze = task.allFilesToAnalyze;
    calculateCI = task.calculateCI;
    calculateCD = task.calculateCD;
    calculateBF = task.calculateBF;
    calculateDiffs = task.calculateDiffs;
    }
  return *this;
}


void BalanceFunctionCalculator::setDefaultConfiguration()
{
  EventTask::setDefaultConfiguration();
  String null("null");
  addProperty("HistogramsCreate",       true);
  addProperty("HistogramsImport",       true);
  addProperty("HistogramsExport",       true);
  addProperty("HistogramsForceRewrite", true);
  addProperty("AppendedString",         String("BalFct"));
  addProperty("calculateCI",            true);
  addProperty("calculateCD",            true);
  addProperty("calculateBF",            true);
  addProperty("calculateDiffs",         false);
  addProperty("FillEta",                true);
  addProperty("FillY",                  false);
  addProperty("FillP2",                 false);
  addProperty("nBins_n2",     100);
  addProperty("Min_n2",       0.0);
  addProperty("Max_n2",       100.0);
  addProperty("nBins_eTot",   100);
  addProperty("Min_eTot",     0.0);
  addProperty("Max_eTot",     100.0);
  addProperty("nBins_pt",     18);
  addProperty("Min_pt",       0.20);
  addProperty("Max_pt",       2.00);
  addProperty("nBins_phi",    72);
  addProperty("Min_phi",      0.0);
  addProperty("Max_phi",      CAP::Math::twoPi());
  addProperty("nBins_eta",    20);
  addProperty("Min_eta",      -1.0);
  addProperty("Max_eta",      1.0);
  addProperty("nBins_y",      20);
  addProperty("Min_y",        -1.0);
  addProperty("Max_y",        1.0);
  addProperty("nBins_phiEta",      720);
  addProperty("nBins_phiEtaPt",    7200);
  addProperty("nBins_phiY",        720);
  addProperty("nBins_phiYPt",      7200);
  addProperty("nBins_n2",          100);
  addProperty("Min_n2",            0.0);
  addProperty("Max_n2",            1000.0);
  addProperty("nBins_DeltaPlong",  10);
  addProperty("Min_DeltaPlong",    -1.0);
  addProperty("Max_DeltaPlong",    1.0);
  addProperty("nBins_DeltaPside",  10);
  addProperty("Min_DeltaPside",    -1.0);
  addProperty("Max_DeltaPside",    1.0);
  addProperty("range_DeltaPside",  2.0);
  addProperty("nBins_DeltaPout",   10);
  addProperty("Min_DeltaPout",     -1.0);
  addProperty("Max_DeltaPout",     1.0);
  addProperty("range_DeltaPout",   2.0);
  addProperty("nBins_Dphi",        36);
  addProperty("Min_Dphi",          0.0);
  addProperty("Max_Dphi",          CAP::Math::twoPi());
  addProperty("Width_Dphi",        CAP::Math::twoPi());
  addProperty("nBins_Dphi_shft",   36);
  addProperty("Min_Dphi_shft",     0.0);
  addProperty("Max_Dphi_shft",     0.0);
  addProperty("nBins_Deta",        39);
  addProperty("Min_Deta",          -2.0);
  addProperty("Max_Deta",          2.0);
  addProperty("Width_Deta",        4.0/39.0);
  addProperty("nBins_Dy",          39);
  addProperty("Min_Dy",            -2.0);
  addProperty("Max_Dy",            2.0);
  addProperty("Width_Dy",          4.0/39.0);
}


TH2* BalanceFunctionCalculator::calculate_CI(const String & histoBaseName,
                                             const String & en,
                                             const String & pn1,
                                             const String & pn2,
                                             const String & obsName,
                                             TH2* obs_1_2,
                                             TH2* obs_1Bar_2,
                                             TH2* obs_1_2Bar,
                                             TH2* obs_1Bar_2Bar,
                                             HistogramGroup * hGroup)
{
  String name = CAP::createName(getName(),en,pn1,pn2,obsName, "CI" );
  TH2 * obs;
  TH1 * obs_x;
  TH1 * obs_y;
  obs = (TH2*) obs_1Bar_2->Clone();
  obs->SetName(name);
  obs->SetTitle(name);
  obs->Add(obs_1_2Bar);
  obs->Add(obs_1_2);
  obs->Add(obs_1Bar_2Bar);
  obs->Scale(0.25);
  hGroup->push_back(obs);

  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,"CI_x");
  obs_x = obs->ProjectionX();
  obs_x->SetName(name);
  obs_x->SetTitle(name);
  hGroup->push_back(obs_x);

  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,"CI_y");
  obs_y = obs->ProjectionY();
  obs_y->SetName(name);
  obs_y->SetTitle(name);
  hGroup->push_back(obs_y);

  return obs;
}

TH2* BalanceFunctionCalculator::calculate_CD(const String & histoBaseName,
                                             const String & en,
                                             const String & pn1,
                                             const String & pn2,
                                             const String & obsName,
                                             TH2* obs_1_2,
                                             TH2* obs_1Bar_2,
                                             TH2* obs_1_2Bar,
                                             TH2* obs_1Bar_2Bar,
                                             HistogramGroup * hGroup)
{
  String name = CAP::createName(histoBaseName,en,pn1,pn2,obsName, "CD" );
  TH2 * obs;
  TH1 * obs_x;
  TH1 * obs_y;
  obs = (TH2*) obs_1Bar_2->Clone();
  obs->SetName(name);
  obs->SetTitle(name);
  obs->Add(obs_1_2Bar);
  obs->Add(obs_1_2, -1.0);
  obs->Add(obs_1Bar_2Bar, -1.0);
  obs->Scale(0.5);
  hGroup->push_back(obs);

  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,"CD_x");
  obs_x = obs->ProjectionX();
  obs_x->SetName(name);
  obs_x->SetTitle(name);
  hGroup->push_back(obs_x);

  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,"CD_y");
  obs_y = obs->ProjectionY();
  obs_y->SetName(name);
  obs_y->SetTitle(name);
  hGroup->push_back(obs_y);

  return obs;
}

TH2* BalanceFunctionCalculator::calculate_BalFct(const String & histoBaseName,
                                                 const String & en,
                                                 const String & pn1,
                                                 const String & pn2,
                                                 const String & obsName,
                                                 const String & comboName,
                                                 TH1* rho1_2,
                                                 TH2* obs_US,
                                                 TH2* obs_LS,
                                                 HistogramGroup * hGroup)
{
  String name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName);
  TH2 * obs;
  TH1 * obs_x;
  TH1 * obs_y;
  obs = (TH2*) obs_US->Clone();
  obs->SetName(name);
  obs->SetTitle(name);
  obs->Add(obs_LS, -1.0);

  double wx = obs->GetXaxis()->GetBinWidth(1);
  //double wy = obs->GetYaxis()->GetBinWidth(1);
  obs->Scale(1.0/wx); // make this a function of delta y
  double rho1Integral = rho1_2->Integral();
  printValue("rho1Integral",rho1Integral);
  //obs->Scale(1.0/rho1Integral);
  hGroup->push_back(obs);

  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName+"_x");
  obs_x = obs->ProjectionX();
  obs_x->SetName(name);
  obs_x->SetTitle(name);
  hGroup->push_back(obs_x);

  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName+"_y");
  obs_y = obs->ProjectionY();
  obs_y->SetName(name);
  obs_y->SetTitle(name);
  hGroup->push_back(obs_y);

  return obs;
}

TH2* BalanceFunctionCalculator::calculate_BalFctSum(const String & histoBaseName,
                                                    const String & en,
                                                    const String & pn1,
                                                    const String & pn2,
                                                    const String & obsName,
                                                    const String & comboName,
                                                    TH2* obs_12Bar,
                                                    TH2* obs_1Bar2,
                                                    HistogramGroup * hGroup)
{
  String name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName);
  TH2 * obs;
  TH1 * obs_x;
  TH1 * obs_y;
  obs = (TH2*) obs_12Bar->Clone();
  obs->SetName(name);
  obs->SetTitle(name);
  obs->Add(obs_1Bar2, 1.0);

  //double rho1Integral = rho1_2->Integral();
  //obs->Scale(0.5/wx);
  obs->Scale(0.5);
  hGroup->push_back(obs);

  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName+"_x");
  obs_x = obs->ProjectionX();
  obs_x->SetName(name);
  obs_x->SetTitle(name);
  hGroup->push_back(obs_x);

  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName+"_y");
  obs_y = obs->ProjectionY();
  obs_y->SetName(name);
  obs_y->SetTitle(name);
  hGroup->push_back(obs_y);

  return obs;
}

//TH2* BalanceFunctionCalculator::calculate_BalFct2(const String & histoBaseName,
//                                                  const String & en,
//                                                  const String & pn1,
//                                                  const String & pn2,
//                                                  const String & obsName,
//                                                  const String & comboName,
//                                                  TH1* rho1_1,
//                                                  TH1* rho1_2,
//                                                  TH2* obs_US,
//                                                  TH2* obs_LS,
//                                                  HistogramGroup * hGroup)
//{
//  String name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName);
//  TH2 * obs;
//  TH1 * obs_x;
//  TH1 * obs_y;
//  double rho1_1_Integral = rho1_1->Integral();
//  //double rho1_2_Integral = rho1_2->Integral();
//
////  double low  = rho1_1->GetXaxis()->GetXmin();
////  double high = rho1_1->GetXaxis()->GetXmax();
////  double yieldA = yieldA/(high-low)/CAP::Math::twoPi();
////  double yieldB = yieldB/(high-low)/CAP::Math::twoPi();
//
//
//  obs = (TH2*) obs_US->Clone();
//  obs->SetName(name);
//  obs->SetTitle(name);
//  obs->Add(obs_LS, -1.0);
//  obs->Scale(rho1_1_Integral);
//  hGroup->push_back(obs);
//
//  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName+"_x");
//  obs_x = obs->ProjectionX();
//  obs_x->SetName(name);
//  obs_x->SetTitle(name);
//  hGroup->push_back(obs_x);
//
//  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName+"_y");
//  obs_y = obs->ProjectionY();
//  obs_y->SetName(name);
//  obs_y->SetTitle(name);
//  hGroup->push_back(obs_y);
//
//  return obs;
//}

//TH2* BalanceFunctionCalculator::calculate_BalFct3(const String & histoBaseName,
//                                                  const String & en,
//                                                  const String & pn1,
//                                                  const String & pn2,
//                                                  const String & obsName,
//                                                  const String & comboName,
//                                                  TH1* rho1_2 __attribute__((unused)),
//                                                  TH2* obs_US,
//                                                  TH2* obs_LS,
//                                                  HistogramGroup * hGroup)
//{
//  String name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName);
//  TH2 * obs;
//  TH1 * obs_x;
//  TH1 * obs_y;
//  obs = (TH2*) obs_US->Clone();
//  obs->SetName(name);
//  obs->SetTitle(name);
//  obs->Add(obs_LS, -1.0);
////  double rho1Integral = rho1_2->Integral("Width");
////  obs->Scale(rho1Integral);
//  hGroup->push_back(obs);
//
//  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName+"_x");
//  obs_x = obs->ProjectionX();
//  obs_x->SetName(name);
//  obs_x->SetTitle(name);
//  hGroup->push_back(obs_x);
//
//  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName+"_y");
//  obs_y = obs->ProjectionY();
//  obs_y->SetName(name);
//  obs_y->SetTitle(name);
//  hGroup->push_back(obs_y);
//
//  return obs;
//}



TH2* BalanceFunctionCalculator::calculate_Diff(const String & histoBaseName,
                                                 const String & en,
                                                 const String & pn1,
                                                 const String & pn2,
                                                 const String & obsName,
                                                 const String & comboName,
                                                 TH2* obs_first,
                                               TH2* obs_second,
                                               HistogramGroup * hGroup)
{
  String name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName);
  TH2 * obs;
  TH1 * obs_x;
  TH1 * obs_y;
  obs = (TH2*) obs_first->Clone();
  obs->SetName(name);
  obs->SetTitle(name);
  obs->Add(obs_second, -1.0);
  hGroup->push_back(obs);

  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName+"_x");
  obs_x = obs->ProjectionX();
  obs_x->SetName(name);
  obs_x->SetTitle(name);
  hGroup->push_back(obs_x);

  name = CAP::createName(histoBaseName,en,pn1,pn2,obsName,comboName+"_y");
  obs_y = obs->ProjectionY();
  obs_y->SetName(name);
  obs_y->SetTitle(name);
  hGroup->push_back(obs_y);

  return obs;
}

void BalanceFunctionCalculator::configure()
{
  EventTask::configure();

  printString("BalanceFunctionCalculator::configure()");
  exit(1);

  histogramImportPath    = getValueString("HistogramsImportPath");
  histogramImportFile    = getValueString("HistogramsImportFile");
  histogramExportPath    = getValueString("HistogramsExportPath");
  histogramExportFile    = getValueString("HistogramsExportFile");
  histogramForceRewrite  = getValueBool(  "HistogramsForceRewrite");
  appendedString      = getValueString("AppendedString");
  calculateCI         = getValueBool("calculateCI" );
  calculateCD         = getValueBool("calculateCD" );
  calculateBF         = getValueBool("calculateBF" );
  calculateDiffs      = getValueBool("calculateDiffs" );

  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Task name",             getName());
    printValue("HistogramsImportPath",  histogramImportPath);
    printValue("HistogramsImportFile",  histogramImportFile);
    printValue("HistogramsExportPath",  histogramExportPath);
    printValue("HistogramsExportFile",  histogramExportFile);
    printValue("HistogramsForceRewrite",histogramForceRewrite);
    printValue("AppendedString",        appendedString);
    printValue("calculateCI",           calculateCI);
    printValue("calculateCD",           calculateCD);
    printValue("calculateBF",           calculateBF);
    printValue("calculateDiffs",        calculateDiffs);
    printCR();
    }
}

void BalanceFunctionCalculator::initialize()
{
  if (reportStart(__FUNCTION__)) {/* no ops */}
  EventTask::initialize();
  if (reportEnd(__FUNCTION__)) {/* no ops */}
}



void BalanceFunctionCalculator::execute()
{
  if (reportStart(__FUNCTION__)) {/* no ops */}
  if (histogramImportFile.Contains("DEFAULT") ||
      histogramImportFile.Contains("none") ||
      histogramImportFile.Contains("null") ||
      histogramImportFile.Contains("nil") ||
      histogramImportFile.IsNull() )
    {
    if (reportInfo(__FUNCTION__))
      {
      printCR();
      printString("Generating a list of files!");
      }
    vector<String> includePatterns = getSelectedValues("IncludedPattern", "none");
    vector<String> excludePatterns = getSelectedValues("ExcludedPattern", "none");
    for (unsigned int k=0;k<includePatterns.size();k++) cout << " k:" << k << "  Include: " << includePatterns[k] << endl;
    for (unsigned int k=0;k<excludePatterns.size();k++) cout << " k:" << k << "  Exclude: " << excludePatterns[k] << endl;
    printLine();
    bool prependPath = true;
    bool verbose     = true;
    int  maximumDepth = 2;
    allFilesToAnalyze = listFilesInDir(histogramImportPath,includePatterns,excludePatterns,
                                       prependPath, verbose, maximumDepth,0);
    }
  else
    {
    if (reportInfo(__FUNCTION__))
      {
      printLine();
      printString("Using a fixed file!");
      printValue("HistogramsImportPath",histogramImportPath);
      printValue("HistogramsImportFile",histogramImportFile);
      }
    allFilesToAnalyze.push_back(histogramImportPath+histogramImportFile);
    }
  int nFilesToAnalyze = allFilesToAnalyze.size();
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printValue("Task name",             getName());
    printValue("HistogramsImportPath",  histogramImportPath);
    printValue("HistogramsImportFile",  histogramImportFile);
    printValue("HistogramsExportPath",  histogramExportPath);
    printValue("HistogramsExportFile",  histogramExportFile);
    printValue("HistogramsForceRewrite",histogramForceRewrite);
    printValue("AppendedString",        appendedString);
    printValue("calculateCI",           calculateCI);
    printValue("calculateCD",           calculateCD);
    printValue("calculateBF",           calculateBF);
    printValue("calculateDiffs",        calculateDiffs);
    printValue("nFilesToAnalyze",       nFilesToAnalyze);
    printCR();
    }
  if (nFilesToAnalyze<1) throw FileException(histogramImportPath,"*","No files found",__FUNCTION__);
  std::vector<EventFilter*> & eventFilters = Manager<EventFilter>::getObjects();
  std::vector<ParticleFilter*> & particleFilters = Manager<ParticleFilter>::getObjects();

  for (auto & histogramImportFile : allFilesToAnalyze)
    {
    histogramExportFile  = removeRootExtension(histogramImportFile);
    histogramExportFile.ReplaceAll(String("Derived"),appendedString);
    TFile & inputFile = *openRootFile("",histogramImportFile,"OLD");
    String option = "NEW";
    if (histogramForceRewrite) option = "RECREATE";
    TFile & outputFile = *openRootFile("",histogramExportFile,option);
    if (reportInfo(__FUNCTION__))
      {
      printCR();
      printLine();
      printValue("From",histogramImportFile);
      printValue("Saved to",histogramExportFile);
      }
    // Use hGroup  as helper to load and calculate histograms, etc.
    HistogramGroup * hGroup  = new HistogramGroup();
    //hGroup ->setOwnership(false);
    hGroup ->setName(getName());
    hGroup ->setParentTask(this);
    hGroup ->setConfiguration(configuration);
    importNEexecutedTask(inputFile);
    EventAccountant::importEventsAccepted(inputFile);

    unsigned int nSpecies = particleFilters.size()/2;
    vector<String>  sObsNames;
    vector<String>  pObsNames;
    int observableSelection = 5;
    switch (observableSelection)
      {
        default:
        case 0: // eta based observables, full complement
        sObsNames.push_back("n1_eta");
        sObsNames.push_back("n1_phi");
        pObsNames.push_back("R2_ptpt");
        pObsNames.push_back("R2_phiPhi");
        pObsNames.push_back("R2_etaEta");
        pObsNames.push_back("R2_DetaDphi_shft");
        break;

        case 1: // eta based observables, only DeltaEta vs DeltaPhi
        sObsNames.push_back("n1_eta");
        sObsNames.push_back("n1_phi");
        pObsNames.push_back("rho2_DetaDphi_shft");
        break;

        case 2: // y based observables, full complement
        sObsNames.push_back("n1_y");
        sObsNames.push_back("n1_phi");
        pObsNames.push_back("R2_ptpt");
        pObsNames.push_back("R2_phiPhi");
        pObsNames.push_back("R2_yY");
        pObsNames.push_back("R2_DyDphi_shft");
        break;

        case 3: // y based observables, only DeltaY vs DeltaPhi
        sObsNames.push_back("n1_y");
        sObsNames.push_back("n1_phi");
        pObsNames.push_back("R2_DyDphi_shft");
        break;

        case 4: // eta based observables, only DeltaEta vs DeltaPhi
        sObsNames.push_back("n1_eta");
        sObsNames.push_back("n1_phi");
        pObsNames.push_back("rho2_DetaDphi_shft");
        pObsNames.push_back("R2_DetaDphi_shft");
        //pObsNames.push_back("B2AB_DetaDphi_shft");
        //pObsNames.push_back("B2BA_DetaDphi_shft");
        //        pObsNames.push_back("n2_phiPhi");
        break;

        case 5: // y based observables
        sObsNames.push_back("n1_y");
        sObsNames.push_back("n1_phi");
        pObsNames.push_back("A2_DyDphi_shft");
        pObsNames.push_back("B2_DyDphi_shft");
        pObsNames.push_back("C2_DyDphi_shft");
        pObsNames.push_back("D2_DyDphi_shft");
        pObsNames.push_back("R2_DyDphi_shft");
        pObsNames.push_back("B2_yY");
        //pObsNames.push_back("B2_phiPhi");
        break;
      }
    if (reportInfo(__FUNCTION__))
      {
      cout << endl;
      printValue("nSpecies",nSpecies);
      for (unsigned int iPart1=0; iPart1<nSpecies; iPart1++)
        {
        cout << "iPart1:" <<  iPart1 << "  named: "<< particleFilters[iPart1]->getName() << endl;
        }
      printValue("sObsNames.size()",int(sObsNames.size()));
      for (unsigned int k=0; k<sObsNames.size(); k++)
        printValue("   ",sObsNames[k]);
      printValue("pObsNames.size()",int(pObsNames.size()));
      for (unsigned int k=0; k<pObsNames.size(); k++)
        printValue("   ",pObsNames[k]);
      }
    for (auto & pObsName : pObsNames)
      {
      for (auto & particleFilter1 : particleFilters)
        {
        for (auto & particleFilter2 : particleFilters)
          {
          for (auto & eventFilter : eventFilters)
            {
            // load histogram and compute derived files.
            String en     = eventFilter->getName();
            String pn1    = particleFilter1->getName();
            String pn1Bar = (particleFilter1+nSpecies)->getName();
            String pn2    = particleFilter2->getName();
            String pn2Bar = (particleFilter2+nSpecies)->getName();
            //TH1 * rho1_1         = hGroup ->importH1(inputFile,createName(getName(),en,pn1,   sObsNames[0]));
            //TH1 * rho1_1Bar      = hGroup ->importH1(inputFile,createName(getName(),en,pn1Bar,sObsNames[0]));
            TH1 * rho1_2         = hGroup ->importH1(inputFile,createName(getName(),en,pn2,   sObsNames[0]));
            TH1 * rho1_2Bar      = hGroup ->importH1(inputFile,createName(getName(),en,pn2Bar,sObsNames[0]));
            TH2 * obs_1_2        = hGroup ->importH2(inputFile,createName(getName(),en,pn1,    pn2,    pObsName));
            TH2 * obs_1Bar_2     = hGroup ->importH2(inputFile,createName(getName(),en,pn1Bar, pn2,    pObsName));
            TH2 * obs_1_2Bar     = hGroup ->importH2(inputFile,createName(getName(),en,pn1,    pn2Bar, pObsName));
            TH2 * obs_1Bar_2Bar  = hGroup ->importH2(inputFile,createName(getName(),en,pn1Bar, pn2Bar, pObsName));

            if (calculateCI)
              calculate_CI(getName(),en,pn1,pn2, pObsName,obs_1_2,obs_1Bar_2,obs_1_2Bar,obs_1Bar_2Bar,hGroup );

            if (calculateCD)
              calculate_CD(getName(),en,pn1,pn2, pObsName,obs_1_2,obs_1Bar_2,obs_1_2Bar,obs_1Bar_2Bar,hGroup );

            if (calculateBF)
              {
              TH2* bfa = calculate_BalFct(getName(),en,pn1,pn2, pObsName, "B2_1_2Bar",rho1_2Bar, obs_1_2Bar, obs_1Bar_2Bar,hGroup );
              TH2* bfb = calculate_BalFct(getName(),en,pn1,pn2, pObsName, "B2_1Bar_2",rho1_2,    obs_1Bar_2, obs_1_2,hGroup );
              calculate_BalFctSum(getName(),en,pn1,pn2, pObsName, "B2_12Sum",bfa,bfb,hGroup );
              }
            if (calculateDiffs)
              {
              calculate_Diff(getName(),en,pn1,pn2, pObsName, "Diff_US",   obs_1Bar_2,    obs_1_2Bar,hGroup );
              calculate_Diff(getName(),en,pn1,pn2, pObsName, "Diff_LS",   obs_1Bar_2Bar, obs_1_2,hGroup );
              }
            }
          }
        }
      }
    outputFile.cd();
    hGroup->exportHistograms(outputFile);
    EventAccountant::exportEventsAccepted(outputFile);
    TaskAccountant::exportNEexecutedTask(outputFile);
    inputFile.Close();
    outputFile.Close();
    hGroup->clearHistograms();
    delete hGroup ;
    }
  if (reportEnd(__FUNCTION__)) {/* no ops */}
}

}  // namespace CAP


