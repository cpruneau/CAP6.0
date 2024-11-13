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
void loadBase(const TString & includeBasePath);
void loadPlotting(const TString & includeBasePath);

TH1 * cloneLoadH1(TFile & inputFile, TString histoName)
{
  TH1 * h = (TH1*) inputFile.Get(histoName);
  TH1 * clone = (TH1*) h->Clone();
  return clone;
}

TH1 * cloneLoadH2(TFile & inputFile, TString histoName)
{
  TH2 * h = (TH2*) inputFile.Get(histoName);
  TH2 * clone = (TH2*) h->Clone();
  return clone;
}

TH1 * cumulativeSum(TFile & inputFile, TString histoName, bool noWidth=true)
{
  TH1 * h = (TH1*) inputFile.Get(histoName);
  TH1 * clone = (TH1*) h->Clone();
  int n = clone->GetNbinsX();
  double v, ev, w, sum, eSum;
  v  = clone->GetBinContent(1);
  ev = clone->GetBinError(1);
  w  = clone->GetBinWidth(1);
  if (noWidth)
    {
    sum  = v;
    eSum = ev;
    }
  else
    {
    sum  = w*v;
    eSum = w*ev;
    }
  for (int k=2;k<=n; k++)
    {
    v  = clone->GetBinContent(k);
    ev = clone->GetBinError(k);
    w  = clone->GetBinWidth(k);
    if (noWidth)
      {
      sum  += v;;
      eSum += sqrt(eSum*eSum + ev*ev);
      }
    else
      {
      sum  = w*v;
      eSum = w*ev;
      }
    clone->SetBinContent(k,sum);
    clone->SetBinError(k,0.0);
    }
  return clone;
}

TH1 * computeHistoSum(const vector<TH1*> & histos, const TString & name)
{
  TH1 * histoSum = (TH1*) histos[0]->Clone();
  for (int k=1; k<histos.size(); k++)
    {
    histoSum->Add(histos[k]);
    }
  histoSum->SetName(name);
  return histoSum;
}

int PlotBF(const TString & path="/Volumes/ClaudeDisc4/OutputFiles/pythiaTest3D/",
           const TString & fileName0="Pair3DGen.root",
           const TString & fileName1="Pair3DGenDerived.root",
           const TString & fileName2="Pair3DGenBF.root")
{
  //gROOT->SetWebDisplay();

  TString includeBasePath = getenv("CAP_SRC");
  loadBase(includeBasePath);
  loadPlotting(includeBasePath);

  using CAP::Configuration;
  using CAP::CanvasConfiguration;
  using CAP::GraphConfiguration;
  using CAP::Plotter;

  Configuration taskConfig;
  Plotter * plotter = new Plotter();
  plotter->setDefaultOptions(1);

  //enum CanvasFormat   { PortraitTight, Portrait, PortraitWide, SquareTight, Square, SquareWide, LandscapeTight, Landscape, LandscapeWide, LandscapeXtop };
  //enum CanvasAxes     { Linear, LogX, LogY, LogZ, LogXY, LogXZ, LogYZ, LogXYZ  };
  plotter->addCanvasConfiguartion(CanvasConfiguration::LandscapeWide,CanvasConfiguration::Linear);
  plotter->addCanvasConfiguartion(CanvasConfiguration::LandscapeWide,CanvasConfiguration::LogY);
  plotter->addGraphConfiguration(10,1);
  int linear = 0;
  int logY   = 1;
  try
  {

  TString inputFileName0 = path+fileName0;
  TString inputFileName1 = path+fileName1;
  TString inputFileName2 = path+fileName2;
  TFile * inputFile0 =  new TFile(inputFileName0,"OLD");
  TFile * inputFile1 =  new TFile(inputFileName1,"OLD");
  TFile * inputFile2 =  new TFile(inputFileName2,"OLD");

  ROOT::RBrowser * b = new ROOT::RBrowser();
  vector<TH1*>    histos;
  double legendSize = 0.3;

//  histos.push_back( cloneLoadH1(*inputFile0,"Pair3D_ALL_PiP_n1_pt") );
//  histos.push_back( cloneLoadH1(*inputFile0,"Pair3D_ALL_PiM_n1_pt"));
//  histos[0]->GetYaxis()->SetTitle("#rho_{1}(pT)");
//  histos[0]->SetTitle("#rho_{1}^{#pi^{+}}");
//  histos[1]->SetTitle("#rho_{1}^{#pi^{+}}");
//  plotter->plot("Pair3D_ALL_Pi_rho1_pT",histos,
//                TString("p_{T}"), 0.0, 8.0,
//                TString("#rho_{1}(pT)"),1.0E-7, 1.99,
//                true, 0.5, 0.7, 0.5, 0.7, 0.05,logY);
//  histos.clear();
//
//  histos.push_back( cumulativeSum(*inputFile0,"Pair3D_ALL_PiP_n1_pt"));
//  histos.push_back( cumulativeSum(*inputFile0,"Pair3D_ALL_PiM_n1_pt"));
//  histos[0]->GetYaxis()->SetTitle("#int #rho_{1}^{#pi^{+}}");
//  histos[0]->SetTitle("#rho_{1}^{#pi^{+}}");
//  histos[1]->SetTitle("#rho_{1}^{#pi^{-}}");
//  plotter->plot("Pair3D_ALL_Pi_int_rho1_pT",histos,
//                TString("p_{T}"), 0.0, 8.0,
//                TString("#rho_{1}(pT)"),-0.05, 29.99,
//                true, 0.5, 0.7, 0.2, 0.45, 0.05);
//  histos.clear();
//

//
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_PP_B21_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_PP_B12_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_PP_Bs_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("B(Q_{INV})");
//  histos[0]->SetTitle(" B^{21}(P,P)");
//  histos[1]->SetTitle(" B^{12}(P,P)");
//  histos[2]->SetTitle(" B^{s}(P,P)");
//  plotter->plot("Pair3D_ALL_PP_PP_B_Qinv",histos,TString("Q_{inv}"), 0.0, 5.0,
//                TString("B"),-0.002, 0.0199,
//                true, 0.5, 0.7, 0.4, 0.7, 0.5);
//  histos.clear();
//
//
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_KP_PiP_B21_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_KP_PiP_B12_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_KP_PiP_Bs_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("B(Q_{INV})");
//  histos[0]->SetTitle(" B^{21}(K,#pi)");
//  histos[1]->SetTitle(" B^{12}(K,#pi)");
//  histos[2]->SetTitle(" B^{s}(K,#pi)");
//  plotter->plot("Pair3D_ALL_KP_PiP_B_Qinv",histos,TString("Q_{inv}"), 0.0, 5.0,
//                TString("B"),-0.002, 0.0899,
//                true, 0.5, 0.7, 0.4, 0.7, 0.5);
//  histos.clear();
//
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_PiP_B21_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_PiP_B12_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_PiP_Bs_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("B(Q_{INV})");
//  histos[0]->SetTitle(" B^{21}(P,#pi)");
//  histos[1]->SetTitle(" B^{12}(P,#pi)");
//  histos[2]->SetTitle(" B^{s}(P,#pi)");
//  plotter->plot("Pair3D_ALL_PP_PiP_B_Qinv",histos,TString("Q_{inv}"), 0.0, 5.0,
//                TString("B"),-0.002, 0.0199,
//                true, 0.5, 0.7, 0.4, 0.7, 0.5);
//  histos.clear();
//
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_KP_B21_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_KP_B12_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_KP_Bs_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("B(Q_{INV})");
//  histos[0]->SetTitle(" B^{21}(P,K)");
//  histos[1]->SetTitle(" B^{12}(P,K)");
//  histos[2]->SetTitle(" B^{s}(P,K)");
//  plotter->plot("Pair3D_ALL_PP_KP_B_Qinv",histos,TString("Q_{inv}"), 0.0, 5.0,
//                TString("B"),-0.0005, 0.00499,
//                true, 0.5, 0.7, 0.4, 0.7, 0.5);
//  histos.clear();
//
//
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PiP_PiP_Bs_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_KP_PiP_Bs_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_PiP_Bs_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("B(Q_{INV})");
//  histos[0]->SetTitle(" B^{s}(#pi,#pi)");
//  histos[1]->SetTitle(" B^{s}(K,#pi)");
//  histos[2]->SetTitle(" B^{s}(P,#pi)");
//  plotter->plot("Pair3D_ALL_Mix_PiP_B_Qinv",histos,
//                TString("Q_{inv}"), 0.0, 5.0,
//                TString("B"),-0.05, 0.599,
//                true, 0.5, 0.7, 0.4, 0.7, 0.5);
//  histos.clear();
//
//  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_PiP_PiP_Bs_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_PiP_KP_Bs_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_PiP_PP_Bs_Qinv"));
//  histos.push_back( computeHistoSum(histos,"Pair3D_ALL_PiP_All_Bs_Qinv"));
//
//  histos[0]->GetYaxis()->SetTitle("I(Q_{INV})");
//  histos[0]->SetTitle(" I^{s}(#pi,#pi)");
//  histos[1]->SetTitle(" I^{s}(K,#pi)");
//  histos[2]->SetTitle(" I^{s}(P,#pi)");
//  histos[3]->SetTitle(" I^{s}(All,#pi)");
//  plotter->plot("Pair3D_ALL_Mix_PiP_B_Qinv_Integral",histos,
//                TString("Q_{inv}"), 0.0, 10.0,
//                TString("B"),-0.05, 1.1,
//                true, 0.5, 0.7, 0.4, 0.7, 0.5);
//  histos.clear();
//
//
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PiP_KP_Bs_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_KP_KP_Bs_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_KP_Bs_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("B(Q_{INV})");
//  histos[0]->SetTitle(" B^{s}(#pi,K)");
//  histos[1]->SetTitle(" B^{s}(K,K)");
//  histos[2]->SetTitle(" B^{s}(P,K)");
//  plotter->plot("Pair3D_ALL_Mix_KP_B_Qinv",histos,
//                TString("Q_{inv}"), 0.0, 5.0,
//                TString("B"),-0.05, 0.599,
//                true, 0.5, 0.7, 0.4, 0.7, 0.5);
//  histos.clear();
//
//  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_KP_PiP_Bs_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_KP_KP_Bs_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_KP_PP_Bs_Qinv"));
//  histos.push_back( computeHistoSum(histos,"Pair3D_ALL_KP_All_Bs_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("I(Q_{INV})");
//  histos[0]->SetTitle(" I^{s}(#pi,K)");
//  histos[1]->SetTitle(" I^{s}(K,K)");
//  histos[2]->SetTitle(" I^{s}(P,K)");
//  histos[3]->SetTitle(" I^{s}(All,K)");
//  plotter->plot("Pair3D_ALL_Mix_KP_B_Qinv_Integral",histos,
//                TString("Q_{inv}"), 0.0, 10.0,
//                TString("B"),-0.05, 1.1,
//                true, 0.5, 0.7, 0.4, 0.7, 0.5);
//  histos.clear();
//
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PiP_PP_Bs_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_KP_PP_Bs_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PP_PP_Bs_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("B(Q_{INV})");
//  histos[0]->SetTitle(" B^{s}(#pi,P)");
//  histos[1]->SetTitle(" B^{s}(K,P)");
//  histos[2]->SetTitle(" B^{s}(P,P)");
//  plotter->plot("Pair3D_ALL_Mix_PP_B_Qinv",histos,
//                TString("Q_{inv}"), 0.0, 5.0,
//                TString("B"),-0.05, 0.599,
//                true, 0.5, 0.7, 0.4, 0.7, 0.5);
//  histos.clear();
//
//  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_PiP_PP_Bs_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_KP_PP_Bs_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_PP_PP_Bs_Qinv"));
//  histos.push_back( computeHistoSum(histos,"Pair3D_ALL_PP_All_Bs_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("I(Q_{INV})");
//  histos[0]->SetTitle(" I^{s}(#pi,P)");
//  histos[1]->SetTitle(" I^{s}(K,P)");
//  histos[2]->SetTitle(" I^{s}(P,P)");
//  histos[3]->SetTitle(" I^{s}(All,P)");
//  plotter->plot("Pair3D_ALL_Mix_PP_B_Qinv_Integral",histos,
//                TString("Q_{inv}"), 0.0, 10.0,
//                TString("B"),-0.05, 1.1,
//                true, 0.5, 0.7, 0.4, 0.7, 0.5);
//  histos.clear();
//

//  histos.push_back( cloneLoadH1(*inputFile0,"Pair3D_ALL_PiM_PiM_n2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile0,"Pair3D_ALL_PiP_PiM_n2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile0,"Pair3D_ALL_PiM_PiP_n2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile0,"Pair3D_ALL_PiP_PiP_n2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiM_PiM_n1n1_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiP_PiM_n1n1_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiM_PiP_n1n1_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiP_PiP_n1n1_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("#rho_{2}(Q_{INV})");
//  histos[0]->SetTitle(" #rho_{2}(#pi^{-},#pi^{-})");
//  histos[1]->SetTitle(" #rho_{2}(#pi^{+},#pi^{-})");
//  histos[2]->SetTitle(" #rho_{2}(#pi^{-},#pi^{+})");
//  histos[3]->SetTitle(" #rho_{2}(#pi^{+},#pi^{+})");
//  histos[4]->SetTitle(" #rho_{1}#otimes #rho_{1}(#pi^{-},#pi^{-})");
//  histos[5]->SetTitle(" #rho_{1}#otimes #rho_{1}(#pi^{+},#pi^{-})");
//  histos[6]->SetTitle(" #rho_{1}#otimes #rho_{1}(#pi^{-},#pi^{+})");
//  histos[7]->SetTitle(" #rho_{1}#otimes #rho_{1}(#pi^{+},#pi^{+})");
//  plotter->plot("Pair3D_ALL_Pi_RHO2_Qinv",histos,
//                TString("Q_{inv}"), 0.0, 4.0,
//                TString("#rho_{2}"),-0.05, 5.99,
//                true, 0.6, 0.8,  0.4, 0.9, 0.2);
//  histos.clear();
//
//  histos.push_back( cloneLoadH1(*inputFile0,"Pair3D_ALL_KM_KM_n2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile0,"Pair3D_ALL_KP_KM_n2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile0,"Pair3D_ALL_KM_KP_n2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile0,"Pair3D_ALL_KP_KP_n2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KM_KM_n1n1_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KP_KM_n1n1_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KM_KP_n1n1_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KP_KP_n1n1_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("#rho_{2}(Q_{INV})");
//  histos[0]->SetTitle(" #rho_{2}(K^{-},K^{-})");
//  histos[1]->SetTitle(" #rho_{2}(K^{+},K^{-})");
//  histos[2]->SetTitle(" #rho_{2}(K^{-},K^{+})");
//  histos[3]->SetTitle(" #rho_{2}(K^{+},K^{+})");
//  histos[4]->SetTitle(" #rho_{1}#otimes #rho_{1}(K^{-},K^{-})");
//  histos[5]->SetTitle(" #rho_{1}#otimes #rho_{1}(K^{+},K^{-})");
//  histos[6]->SetTitle(" #rho_{1}#otimes #rho_{1}(K^{-},K^{+})");
//  histos[7]->SetTitle(" #rho_{1}#otimes #rho_{1}(K^{+},K^{+})");
//  plotter->plot("Pair3D_ALL_K_RHO2_Qinv",histos,
//                TString("Q_{inv}"), 0.0, 2.0,
//                TString("#rho_{2}"),-0.02, 0.2,
//                true, 0.6, 0.8, 0.45, 0.87, 0.2);
//  histos.clear();


//
//  histos.push_back( cumulativeSum(*inputFile0,"Pair3D_ALL_PiP_PiP_n2_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile0,"Pair3D_ALL_PiP_PiM_n2_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile0,"Pair3D_ALL_PiM_PiM_n2_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile1,"Pair3D_ALL_PiP_PiP_n1n1_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile1,"Pair3D_ALL_PiP_PiM_n1n1_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile1,"Pair3D_ALL_PiM_PiM_n1n1_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("#int f(Q_{INV})");
//  histos[0]->SetTitle("#rho_{2}(#pi^{+},#pi^{+})");
//  histos[1]->SetTitle("#rho_{2}(#pi^{+},#pi^{-})");
//  histos[2]->SetTitle("#rho_{2}(#pi^{-},#pi^{-})");
//  histos[3]->SetTitle("#rho_{1}#otimes #rho_{1}(#pi^{+},#pi^{+})");
//  histos[4]->SetTitle("#rho_{1}#otimes #rho_{1}(#pi^{+},#pi^{-})");
//  histos[5]->SetTitle("#rho_{1}#otimes #rho_{1}(#pi^{-},#pi^{-})");
//  plotter->plot("Pair3D_ALL_PiP_PiP_IntRHO2_Qinv",histos,
//                TString("Q_{inv}"), 0.0, 10.0,
//                TString("#rho_{2}"),-0.05, 499.99,
//                true, 0.5, 0.7, 0.2, 0.4, 0.3);
//  histos.clear();
//


//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiM_PiM_c2_Qinv") );
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiP_PiM_c2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiM_PiP_c2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiP_PiP_c2_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("C_{2}(Q_{INV})");
//  histos[0]->SetTitle("C_{2}(#pi^{-},#pi^{-})");
//  histos[1]->SetTitle("C_{2}(#pi^{+},#pi^{-})");
//  histos[2]->SetTitle("C_{2}(#pi^{-},#pi^{+})");
//  histos[3]->SetTitle("C_{2}(#pi^{+},#pi^{+})");
//  plotter->plot("Pair3D_ALL_Pi_Pi_C2_Qinv",histos,
//                TString("Q_{inv}"), 0.0, 3.0,
//                TString("B"),-0.05, 3.99,
//                true, 0.5, 0.7, 0.5, 0.7, 0.2);
//  histos.clear();
//
//
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KM_KM_c2_Qinv") );
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KP_KM_c2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KP_KP_c2_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KP_KP_c2_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("C_{2}(Q_{INV})");
//  histos[0]->SetTitle("C_{2}(K^{-},K^{-})");
//  histos[1]->SetTitle("C_{2}(K^{+},K^{-})");
//  histos[2]->SetTitle("C_{2}(K^{-},K^{+})");
//  histos[3]->SetTitle("C_{2}(K^{+},K^{+})");
//  plotter->plot("Pair3D_ALL_K_K_C2_Qinv",histos,
//                TString("Q_{inv}"), 0.0, 3.0,
//                TString("B"),-0.01, 0.075,
//                true, 0.5, 0.7, 0.5, 0.7, 0.2);
//  histos.clear();

//
//  histos.push_back( cumulativeSum(*inputFile1,"Pair3D_ALL_PiM_PiM_c2_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile1,"Pair3D_ALL_PiP_PiM_c2_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile1,"Pair3D_ALL_PiM_PiP_c2_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile1,"Pair3D_ALL_PiP_PiP_c2_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("#int C_{2}(Q_{INV})");
//  histos[0]->SetTitle("C_{2}(#pi^{-},#pi^{-})");
//  histos[1]->SetTitle("C_{2}(#pi^{+},#pi^{-})");
//  histos[2]->SetTitle("C_{2}(#pi^{-},#pi^{+})");
//  histos[3]->SetTitle("C_{2}(#pi^{+},#pi^{+})");
//  plotter->plot("Pair3D_ALL_Pi_Pi_INT_C2_Qinv",histos,
//                TString("Q_{inv}"), 0.0, 10.0,
//                TString("B"),-0.05, 50.00,
//                true, 0.5, 0.7, 0.4, 0.7, 0.2);
//  histos.clear();

//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiM_PiM_A12_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiP_PiM_A12_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiM_PiP_A12_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_PiP_PiP_A21_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("A_{12}(Q_{INV})");
//  histos[0]->SetTitle("A_{12}(#pi^{-},#pi^{-})");
//  histos[1]->SetTitle("A_{12}(#pi^{+}#pi^{-})");
//  histos[2]->SetTitle("A_{21}(#pi^{-}#pi^{+})");
//  histos[3]->SetTitle("A_{21}(#pi^{+},#pi^{+})");
//  plotter->plot("Pair3D_Pi_Pi_A12_Qinv",histos,
//                TString("Q_{inv}"), 0.0, 3.0,
//                TString("B"),-0.02, 0.20,
//                true, 0.5, 0.7, 0.5, 0.75, 0.2);
//  histos.clear();
//
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KM_KM_A12_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KP_KM_A12_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KM_KP_A12_Qinv"));
//  histos.push_back( cloneLoadH1(*inputFile1,"Pair3D_ALL_KP_KP_A21_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("A_{12}(Q_{INV})");
//  histos[0]->SetTitle("A_{12}(K^{-},K^{-})");
//  histos[1]->SetTitle("A_{12}(K^{+},K^{-})");
//  histos[2]->SetTitle("A_{21}(K^{-},K^{+})");
//  histos[3]->SetTitle("A_{21}(K^{+},K^{+})");
//  plotter->plot("Pair3D_K_K_A12_Qinv",histos,
//                TString("Q_{inv}"), 0.0, 3.0,
//                TString("B"),-0.02, 0.10,
//                true, 0.5, 0.7, 0.5, 0.75, 0.2);
//  histos.clear();

//  histos.push_back( cumulativeSum(*inputFile1,"Pair3D_ALL_PiM_PiM_A12_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile1,"Pair3D_ALL_PiP_PiM_A12_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile1,"Pair3D_ALL_PiM_PiP_A12_Qinv"));
//  histos.push_back( cumulativeSum(*inputFile1,"Pair3D_ALL_PiP_PiP_A21_Qinv"));
//  histos[0]->GetYaxis()->SetTitle("A_{12}(Q_{INV})");
//  histos[0]->SetTitle("A_{12}(#pi^{-},#pi^{-})");
//  histos[1]->SetTitle("A_{12}(#pi^{+}#pi^{-})");
//  histos[2]->SetTitle("A_{21}(#pi^{-}#pi^{+})");
//  histos[3]->SetTitle("A_{21}(#pi^{+},#pi^{+})");
//  plotter->plot("Pair3D_Pi_Pi_A12_Qinv_INT",histos,
//                TString("Q_{inv}"), 0.0, 10.0,
//                TString("B"),-0.05, 15.00,
//                true, 0.5, 0.7, 0.3, 0.6, 0.2);
//  histos.clear();


//
//  plotter->printAllCanvas(path);


//    histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PiP_PiP_B21_Qinv") );
//    histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PiP_PiP_B12_Qinv"));
//    histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_PiP_PiP_Bs_Qinv"));
//    histos[0]->GetYaxis()->SetTitle("B(Q_{INV})");
//    histos[0]->SetTitle(" B^{21}(#pi,#pi)");
//    histos[1]->SetTitle(" B^{12}(#pi,#pi)");
//    histos[2]->SetTitle(" B^{s}(#pi,#pi)");
//    plotter->plot("Pair3D_ALL_Pi_Pi_B_Qinv",histos,
//                  TString("Q_{inv}"), 0.0, 5.0,
//                  TString("B"),-0.005, 0.03,
//                  true, 0.5, 0.7, 0.4, 0.7, 0.5);
//    histos.clear();

  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_PiP_PiP_B12_Qinv"));
  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_PiP_PiP_B21_Qinv"));
  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_PiP_PiP_Bs_Qinv"));
  histos[0]->GetYaxis()->SetTitle("#int B(Q_{INV})");
  histos[0]->SetTitle(" B^{21}(#pi,#pi)");
  histos[1]->SetTitle(" B^{12}(#pi,#pi)");
  histos[2]->SetTitle(" B^{s}(#pi,#pi)");
  plotter->plot("Pair3D_Pi_Pi_B_Qinv_INT",histos,
                TString("Q_{inv}"), 0.0, 10.0,
                TString("B"),-0.05, 1.80,
                true, 0.5, 0.7, 0.5, 0.8, 0.2);
  histos.clear();

    histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_KP_KP_B21_Qinv"));
    histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_KP_KP_B12_Qinv"));
    histos.push_back( cloneLoadH1(*inputFile2,"Pair3D_ALL_KP_KP_Bs_Qinv"));
    histos[0]->GetYaxis()->SetTitle("B(Q_{INV})");
    histos[0]->SetTitle(" B^{21}(K,K)");
    histos[1]->SetTitle(" B^{12}(K,K)");
    histos[2]->SetTitle(" B^{s}(K,K)");
    plotter->plot("Pair3D_ALL_K_K_B_Qinv",histos,
                  TString("Q_{inv}"), 0.0, 5.0,
                  TString("B"),-0.005, 0.03,
                  true, 0.5, 0.7, 0.4, 0.7, 0.5);
    histos.clear();

  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_KP_KP_B12_Qinv"));
  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_KP_KP_B21_Qinv"));
  histos.push_back( cumulativeSum(*inputFile2,"Pair3D_ALL_KP_KP_Bs_Qinv"));
  histos[0]->GetYaxis()->SetTitle("#int B(Q_{INV})");
  histos[0]->SetTitle(" B^{21}(K,K)");
  histos[1]->SetTitle(" B^{12}(K,K)");
  histos[2]->SetTitle(" B^{s}(K,K)");
  plotter->plot("Pair3D_K_K_B_Qinv_INT",histos,
                TString("Q_{inv}"), 0.0, 10.0,
                TString("B"),-0.05, 1.10,
                true, 0.5, 0.7, 0.6, 0.8, 0.2);
  histos.clear();


  plotter->printAllCanvas(path);

  }
  catch (CAP::PropertyException & e)
  {
  e.print();
  }
  return 0;
}

void loadBase(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/Base/";
//  gSystem->Load(includePath+"Exceptions.hpp");
//  gSystem->Load(includePath+"Timer.hpp");
//  gSystem->Load(includePath+"MessageLogger.hpp");
//  gSystem->Load(includePath+"Task.hpp");
//  gSystem->Load(includePath+"Collection.hpp");
//  gSystem->Load(includePath+"HistogramCollection.hpp");
//  gSystem->Load(includePath+"HistogramGroup.hpp");
  gSystem->Load("libBase.dylib");
}

void loadPlotting(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/Plotting/";
//  gSystem->Load(includePath+"CanvasCollection.hpp");
//  gSystem->Load(includePath+"GraphConfiguration.hpp");
//  gSystem->Load(includePath+"CanvasConfiguration.hpp");
//  gSystem->Load(includePath+"Plotter.hpp");
//  gSystem->Load(includePath+"BalFctPlotter.hpp");
  gSystem->Load("libPlotting.dylib");
}

