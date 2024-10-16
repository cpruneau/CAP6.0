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
#include "ParticlePair3DDerivedHistos.hpp"
ClassImp(ParticlePair3DDerivedHistos);

ParticlePair3DDerivedHistos::ParticlePair3DDerivedHistos(Task * _parent,
                                                         const String & _name,
                                                         const Configuration & _configuration)
:
HistogramGroup(_parent,_name,_configuration),
h_n1n1_Qinv(nullptr),
h_n1n1_DeltaP(nullptr),
h_r2_Qinv(nullptr),
h_r2_DeltaP(nullptr),
h_r2_DeltaPs(nullptr),
h_r2_DeltaPo(nullptr),
h_r2_DeltaPl(nullptr)
{
  appendClassName("ParticlePair3DDerivedHistos");
}

void ParticlePair3DDerivedHistos::HistogramsCreate()
{
  int    nBins_Qinv     = configuration.getValueInt(ptn,   "nBins_Qinv");
  double min_Qinv       = configuration.getValueDouble(ptn,"Min_Qinv");
  double max_Qinv       = configuration.getValueDouble(ptn,"Max_Qinv");
  int    nBins_DeltaPs  = configuration.getValueInt(ptn,   "nBins_DeltaPs");
  double min_DeltaPs    = configuration.getValueDouble(ptn,"Min_DeltaPs");
  double max_DeltaPs    = configuration.getValueDouble(ptn,"Max_DeltaPs");
  int    nBins_DeltaPo  = configuration.getValueInt(ptn,   "nBins_DeltaPo");
  double min_DeltaPo    = configuration.getValueDouble(ptn,"Min_DeltaPo");
  double max_DeltaPo    = configuration.getValueDouble(ptn,"Max_DeltaPo");
  int    nBins_DeltaPl  = configuration.getValueInt(ptn,   "nBins_DeltaPl");
  double min_DeltaPl    = configuration.getValueDouble(ptn,"Min_DeltaPl");
  double max_DeltaPl    = configuration.getValueDouble(ptn,"Max_DeltaPl");

  h_n1n1_Qinv   = createHistogram(makeName(bn,"n1n1_Qinv"),nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","n_{1}n_{1}");
  h_r2_Qinv     = createHistogram(makeName(bn,"r2_Qinv"),  nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","n_{1}n_{1}");

  h_n1n1_DeltaP   = createHistogram(makeName(bn,"n2_DeltaP"),
                                   nBins_DeltaPs,  min_DeltaPs, max_DeltaPs,
                                   nBins_DeltaPo,  min_DeltaPo, max_DeltaPo,
                                   nBins_DeltaPl,  min_DeltaPl, max_DeltaPl,
                                   "p_{s}","p_{o}", "p_{l}","n_{2}");
  h_n1n1_Qinv(nullptr),
  h_n1n1_DeltaP(nullptr),
  h_r2_Qinv(nullptr),
  h_r2_DeltaP(nullptr),
  h_r2_DeltaPs(nullptr),
  h_r2_DeltaPo(nullptr),
  h_r2_DeltaPl(nullptr)

  h_n1n1_DyDphi       = createHistogram(makeName(bn,"n1n1_Qinv"),  nBins_Dy,  min_Dy,  max_Dy,  nBins_Dphi,  min_Dphi,      max_Dphi,     "#Delta y",  "#Delta#varphi", "<n_{1}><n_{1}>");
}

void ParticlePair3DDerivedHistos::HistogramsImport(TFile & inputFile)
{
  String fct = "HistogramsImport(TFile & inputFile)";
  if (reportDebug(__FUNCTION__))
    ;
  if (ptrFileExist(fct,inputFile)) return;
  
  String bn = getParentTaskName();
  if (false)
    {
    h_n1n1_phiPhi          = loadH2(inputFile, makeName(bn,"n1n1_phiPhi"));
    h_R2_phiPhi            = loadH2(inputFile, makeName(bn,"R2_phiPhi"));
    
    h_n1n1_ptpt            = loadH2(inputFile, makeName(bn,"n1n1_ptpt"));
    h_R2_ptpt              = loadH2(inputFile, makeName(bn,"R2_ptpt"));
    
    if (fillP2)
      {
      h_pt1pt1_phiPhi      = loadH2(inputFile, makeName(bn,"pt1pt1_phiPhi"));
      h_DptDpt_phiPhi      = loadH2(inputFile, makeName(bn,"DptDpt_phiPhi"));
      h_P2_phiPhi          = loadH2(inputFile, makeName(bn,"P2_phiPhi"));
      h_G2_phiPhi          = loadH2(inputFile, makeName(bn,"G2_phiPhi"));
      }
    
    if (fillEta)
      {
      h_n1n1_etaEta        = loadH2(inputFile, makeName(bn,"n1n1_etaEta"));
      h_R2_etaEta          = loadH2(inputFile, makeName(bn,"R2_etaEta"));
      
      h_n1n1_DetaDphi      = loadH2(inputFile, makeName(bn,"n1n1_DetaDphi"));
      h_rho2_DetaDphi      = loadH2(inputFile, makeName(bn,"rho2_DetaDphi"));
      h_B2AB_DetaDphi      = loadH2(inputFile, makeName(bn,"B2AB_DetaDphi"));
      h_B2BA_DetaDphi      = loadH2(inputFile, makeName(bn,"B2BA_DetaDphi"));
      h_R2_DetaDphi        = loadH2(inputFile, makeName(bn,"R2_DetaDphi"));
      h_rho2_DetaDphi_shft = loadH2(inputFile, makeName(bn,"rho2_DetaDphi_shft"));
      h_B2AB_DetaDphi_shft = loadH2(inputFile, makeName(bn,"B2AB_DetaDphi_shft"));
      h_B2BA_DetaDphi_shft = loadH2(inputFile, makeName(bn,"B2BA_DetaDphi_shft"));
      h_R2_DetaDphi_shft   = loadH2(inputFile, makeName(bn,"R2_DetaDphi_shft"));
      
      
      if (fillP2)
        {
        h_pt1pt1_etaEta        = loadH2(inputFile, makeName(bn,"pt1pt1_etaEta"));
        h_DptDpt_etaEta        = loadH2(inputFile, makeName(bn,"DptDpt_etaEta"));
        h_P2_etaEta            = loadH2(inputFile, makeName(bn,"P2_etaEta"));
        h_G2_etaEta            = loadH2(inputFile, makeName(bn,"G2_etaEta"));
        
        h_pt1pt1_DetaDphi      = loadH2(inputFile, makeName(bn,"pt1pt1_DetaDphi"));
        h_DptDpt_DetaDphi      = loadH2(inputFile, makeName(bn,"DptDpt_DetaDphi"));
        h_P2_DetaDphi          = loadH2(inputFile, makeName(bn,"P2_DetaDphi"));
        h_G2_DetaDphi          = loadH2(inputFile, makeName(bn,"G2_DetaDphi"));
        h_DptDpt_DetaDphi_shft = loadH2(inputFile, makeName(bn,"DptDpt_DetaDphi_shft"));
        h_P2_DetaDphi_shft     = loadH2(inputFile, makeName(bn,"P2_DetaDphi_shft"));
        h_G2_DetaDphi_shft     = loadH2(inputFile, makeName(bn,"G2_DetaDphi_shft"));
        }
      }
    
    if (fillY)
      {
      h_n1n1_yY           = loadH2(inputFile, makeName(bn,"n1n1_yY"));
      h_R2_yY             = loadH2(inputFile, makeName(bn,"R2_yY"));
      
      h_n1n1_DyDphi       = loadH2(inputFile, makeName(bn,"n1n1_DyDphi"));
      h_rho2_DyDphi       = loadH2(inputFile, makeName(bn,"rho2_DyDphi"));
      h_B2AB_DyDphi       = loadH2(inputFile, makeName(bn,"B2AB_DyDphi"));
      h_B2BA_DyDphi       = loadH2(inputFile, makeName(bn,"B2BA_DyDphi"));
      h_R2_DyDphi         = loadH2(inputFile, makeName(bn,"R2_DyDphi"));
      h_rho2_DyDphi_shft  = loadH2(inputFile, makeName(bn,"rho2_DyDphi_shft"));
      h_B2AB_DyDphi_shft  = loadH2(inputFile, makeName(bn,"B2AB_DyDphi_shft"));
      h_B2BA_DyDphi_shft  = loadH2(inputFile, makeName(bn,"B2BA_DyDphi_shft"));
      h_R2_DyDphi_shft    = loadH2(inputFile, makeName(bn,"R2_DyDphi_shft"));
      
      if (fillP2)
        {
        h_pt1pt1_yY         = loadH2(inputFile, makeName(bn,"pt1pt1_yY"));
        h_DptDpt_yY         = loadH2(inputFile, makeName(bn,"DptDpt_yY"));
        h_P2_yY             = loadH2(inputFile, makeName(bn,"P2_yY"));
        h_G2_yY             = loadH2(inputFile, makeName(bn,"G2_yY"));
        
        h_pt1pt1_DyDphi     = loadH2(inputFile, makeName(bn,"pt1pt1_DyDphi"));
        h_DptDpt_DyDphi     = loadH2(inputFile, makeName(bn,"DptDpt_DyDphi"));
        h_P2_DyDphi         = loadH2(inputFile, makeName(bn,"P2_DyDphi"));
        h_G2_DyDphi         = loadH2(inputFile, makeName(bn,"G2_DyDphi"));
        
        h_DptDpt_DyDphi_shft= loadH2(inputFile, makeName(bn,"DptDpt_DyDphi_shft"));
        h_P2_DyDphi_shft    = loadH2(inputFile, makeName(bn,"P2_DyDphi_shft"));
        h_G2_DyDphi_shft    = loadH2(inputFile, makeName(bn,"G2_DyDphi_shft"));
        }
      }
    }
  
}

void quickCopy(TH2 * source, TH2 * target)
{
  int sNx = source->GetNbinsX();
  int sNy = source->GetNbinsY();
  int tNx = target->GetNbinsX();
  int tNy = target->GetNbinsY();


  if (sNx!=tNx || sNy!=tNy)
    {
    cout << "You are out of luck body" << endl;
    return;

    }
  for (int iX=1; iX<sNx; iX++)
    {
    for (int iY=1; iY<sNy; iY++)
      {
      double v  = source->GetBinContent(iX,iY);
      double ev = source->GetBinError(iX,iY);
      target->SetBinContent(iX,iY,v);
      target->SetBinError(iX,iY,v);
      }
    }
}


// HistogramGroup from ParticlePair3DDerivedHistos must be normalized "per event" before calling this function
void ParticlePair3DDerivedHistos::calculatePairDerivedHistograms(ParticleHistos         & part1BaseHistos,
                                                               ParticleHistos         & part2BaseHistos,
                                                               ParticleDerivedHistos  & part1DerivedHistos,
                                                               ParticleDerivedHistos  & part2DerivedHistos,
                                                               ParticlePair3DHistos     & pairHistos,
                                                               double bincorrection)
{
  String fct = "calculatePairDerivedHistograms(..)";
  if (reportStart(__FUNCTION__))
    ;
  MessageLogger::Severity store = getSeverityLevel();
  //getSeverityLevel(MessageLogger::Debug);
  
  
  double avgPt1Phi;
  double avgPt2Phi;
  double scalingFactorPhi;
  double avgPt1Eta;
  double avgPt2Eta;
  double avgPt1Y;
  double avgPt2Y;
  double scalingFactorEta;
  double scalingFactorY;
  int ijNormalization = 0;
  
  if (reportDebug(__FUNCTION__))  cout << " Calculate R2 vs ptpt" << endl;
  if (reportDebug(__FUNCTION__))  cout << " part1BaseHistos.h_n1_pt:" << part1BaseHistos.h_n1_pt << endl;
  if (reportDebug(__FUNCTION__))  cout << " part2BaseHistos.h_n1_pt:" << part2BaseHistos.h_n1_pt << endl;
  if (reportDebug(__FUNCTION__)) cout << endl<< endl<< endl<< endl;
  calculateN1N1_H1H1H2( part1BaseHistos.h_n1_pt,   part2BaseHistos.h_n1_pt,  h_n1n1_ptpt,1.0, 1.0);
  
  if (reportDebug(__FUNCTION__))  cout << " pairHistos.h_n2_ptpt:" << pairHistos.h_n2_ptpt <<endl;
  if (reportDebug(__FUNCTION__))  cout << "          h_n1n1_ptpt:" << h_n1n1_ptpt <<endl;
  if (reportDebug(__FUNCTION__))  cout << "            h_R2_ptpt:" << h_R2_ptpt <<endl;
  
  calculateR2_H2H2H2(   pairHistos.h_n2_ptpt,  h_n1n1_ptpt,          h_R2_ptpt,0, 1.0, 1.0);
  
  if (reportDebug(__FUNCTION__))  cout << " Calling calculateN1N1_H1H1H2() " << endl;
  calculateN1N1_H1H1H2( part1DerivedHistos.h_n1_phi,  part2DerivedHistos.h_n1_phi, h_n1n1_phiPhi,1.0, 1.0);

  if (reportDebug(__FUNCTION__))  cout << " Calling calculateR2_H2H2H2() for phiPhi " << endl;
  if (reportDebug(__FUNCTION__))  cout << " pairHistos.h_n2_phiPhi:" << pairHistos.h_n2_phiPhi <<endl;
  if (reportDebug(__FUNCTION__))  cout << "          h_n1n1_phiPhi:" << h_n1n1_phiPhi <<endl;
  if (reportDebug(__FUNCTION__))  cout << "            h_R2_phiPhi:" << h_R2_phiPhi <<endl;

  calculateR2_H2H2H2(   pairHistos.h_n2_phiPhi,h_n1n1_phiPhi,h_R2_phiPhi,0, 1.0, 1.0);
  
  
  if (fillP2)
    {
    if (reportDebug(__FUNCTION__))  cout << " Calculate P2 vs phiPhi" << endl;
    avgPt1Phi = avgValue(part1DerivedHistos.h_pt_phi);
    avgPt2Phi = avgValue(part2DerivedHistos.h_pt_phi);
    scalingFactorPhi = 1.0/avgPt1Phi/avgPt2Phi;
    h_P2_phiPhi->Add(h_DptDpt_phiPhi,h_DptDpt_phiPhi,1.0,0.0);
    h_P2_phiPhi->Scale(scalingFactorPhi);
    }
  
  
  if (fillEta)
    {
    if (reportDebug(__FUNCTION__))  cout <<  " calculateN1N1_H1H1H2(part1Histos.h_n1_eta,part2Histos.h_n1_eta,h_n1n1_etaEta,1.0, 1.0)" << endl;
    
    calculateN1N1_H1H1H2(part1DerivedHistos.h_n1_eta,part2DerivedHistos.h_n1_eta,h_n1n1_etaEta,1.0, 1.0);
    
    if (reportDebug(__FUNCTION__))  cout << " Calling calculateR2_H2H2H2() for etaEta " << endl;
    if (reportDebug(__FUNCTION__))  cout << " pairHistos.h_n2_etaEta:" << pairHistos.h_n2_etaEta <<endl;
    if (reportDebug(__FUNCTION__))  cout << "          h_n1n1_etaEta:" << h_n1n1_etaEta <<endl;
    if (reportDebug(__FUNCTION__))  cout << "            h_R2_etaEta:" << h_R2_etaEta <<endl;
    calculateR2_H2H2H2(pairHistos.h_n2_etaEta,h_n1n1_etaEta,h_R2_etaEta,0,1.0,1.0);
   
    reduce_n1EtaPhiN1EtaPhiOntoN1N1DetaDphi(part1BaseHistos.h_n1_phiEta,part2BaseHistos.h_n1_phiEta,h_n1n1_DetaDphi,nBins_Deta,nBins_Dphi);
    if (reportDebug(__FUNCTION__))  cout <<  " calculateR2_H2H2H2(pairHistos.h_n2_DetaDphi,h_n1n1_DetaDphi,h_R2_DetaDphi,0,1.0,1.0)" << endl;
    
    double yieldA = part1DerivedHistos.h_n1_eta->Integral("Width");
    double yieldB = part2DerivedHistos.h_n1_eta->Integral("Width");

    double low  = part1DerivedHistos.h_n1_eta->GetXaxis()->GetXmin();
    double high = part1DerivedHistos.h_n1_eta->GetXaxis()->GetXmax();
    yieldA = yieldA/(high-low)/CAP::Math::twoPi();
    yieldB = yieldB/(high-low)/CAP::Math::twoPi();

//    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
//    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
//    cout << "  h_rho2_DetaDphi    nx:" << h_rho2_DetaDphi->GetXaxis()->GetNbins() << " xMin:" << h_rho2_DetaDphi->GetXaxis()->GetXmin()<< " xMax:" << h_rho2_DetaDphi->GetXaxis()->GetXmax()<< endl;
//    cout << "                     ny:" << h_rho2_DetaDphi->GetYaxis()->GetNbins() << " yMin:" << h_rho2_DetaDphi->GetYaxis()->GetXmin()<< " yMax:" << h_rho2_DetaDphi->GetYaxis()->GetXmax() << endl;
//    cout << "     h_n2_DetaDphi   nx:" << pairHistos.h_n2_DetaDphi->GetXaxis()->GetNbins() << " xMin:" << pairHistos.h_n2_DetaDphi->GetXaxis()->GetXmin()<< " xMax:"<< pairHistos.h_n2_DetaDphi->GetXaxis()->GetXmax() << endl;
//    cout << "                     ny:" << h_rho2_DetaDphi->GetYaxis()->GetNbins() << " yMin:" << h_rho2_DetaDphi->GetYaxis()->GetXmin()<< " yMax:" << pairHistos.h_n2_DetaDphi->GetYaxis()->GetXmax() << endl;
//    quickCopy(pairHistos.h_n2_DetaDphi,h_rho2_DetaDphi);
//    quickCopy(pairHistos.h_n2_DetaDphi,h_B2AB_DetaDphi);
//    quickCopy(pairHistos.h_n2_DetaDphi,h_B2BA_DetaDphi);

    h_rho2_DetaDphi->Add(pairHistos.h_n2_DetaDphi);
//    h_B2AB_DetaDphi->Add(pairHistos.h_n2_DetaDphi);
//    h_B2BA_DetaDphi->Add(pairHistos.h_n2_DetaDphi);
    calculateR2_H2H2H2(pairHistos.h_n2_DetaDphi,h_n1n1_DetaDphi,h_R2_DetaDphi,0,1.0,1.0);

    h_B2AB_DetaDphi->Add(h_R2_DetaDphi);
    h_B2BA_DetaDphi->Add(h_R2_DetaDphi);
    h_B2AB_DetaDphi->Scale(yieldA);
    h_B2BA_DetaDphi->Scale(yieldB);

    if (reportDebug(__FUNCTION__))  cout <<  " shiftY(*h_R2_DetaDphi,*h_R2_DetaDphi_shft,nBins_Dphi_shft)" << endl;
    shiftY(*h_rho2_DetaDphi,*h_rho2_DetaDphi_shft,nBins_Dphi_shft);
    shiftY(*h_B2AB_DetaDphi,*h_B2AB_DetaDphi_shft,nBins_Dphi_shft);
    shiftY(*h_B2BA_DetaDphi,*h_B2BA_DetaDphi_shft,nBins_Dphi_shft);
    shiftY(*h_R2_DetaDphi,*h_R2_DetaDphi_shft,nBins_Dphi_shft);
    
    if (fillP2)
      {
      avgPt1Eta = avgValue(part1DerivedHistos.h_pt_eta);
      avgPt2Eta = avgValue(part2DerivedHistos.h_pt_eta);
      scalingFactorEta = 1.0/avgPt1Eta/avgPt2Eta;
      h_P2_etaEta->Add(h_DptDpt_etaEta,h_DptDpt_etaEta,1.0,0.0);
      h_P2_etaEta->Scale(scalingFactorEta);
      
      if (reportDebug(__FUNCTION__))  cout <<  " shiftY(*h_R2_DetaDphi,*h_R2_DetaDphi_shft,nBins_Dphi_shft)" << endl;
      
      shiftY(*h_DptDpt_DetaDphi, *h_DptDpt_DetaDphi_shft,nBins_Dphi_shft);
      
      /// calculate average pt base on h_pt_eta histograms
      h_P2_DetaDphi->Add(h_DptDpt_DetaDphi,h_DptDpt_DetaDphi,1.0,0.0);
      h_P2_DetaDphi->Scale(scalingFactorEta);
      //symmetrizeDeltaEtaDeltaPhi(h_P2_DetaDphi,ijNormalization);
      shiftY(*h_P2_DetaDphi,*h_P2_DetaDphi_shft, nBins_Dphi_shft);
      
      calculateG2_H2H2H2H2( h_DptDpt_etaEta,   h_n1n1_etaEta,   h_pt1pt1_etaEta,   h_G2_etaEta,   ijNormalization, bincorrection, 1.0);
      calculateG2_H2H2H2H2( h_DptDpt_phiPhi,   h_n1n1_phiPhi,   h_pt1pt1_phiPhi,   h_G2_phiPhi,   ijNormalization, bincorrection, 1.0);
      calculateG2_H2H2H2H2( h_DptDpt_DetaDphi, h_n1n1_DetaDphi, h_pt1pt1_DetaDphi, h_G2_DetaDphi, ijNormalization, bincorrection, 1.0);
      shiftY(*h_G2_DetaDphi,*h_G2_DetaDphi_shft,nBins_Dphi_shft);
      }
    }
  
  if (fillY)
    {
    if (reportDebug(__FUNCTION__))  cout <<  " calculateN1N1_H1H1H2(part1Histos.h_n1_y,part2Histos.h_n1_y,h_n1n1_yY,1.0, 1.0)" << endl;
    
    calculateN1N1_H1H1H2(part1DerivedHistos.h_n1_y,part2DerivedHistos.h_n1_y,h_n1n1_yY,1.0, 1.0);
    calculateR2_H2H2H2(pairHistos.h_n2_yY,h_n1n1_yY,h_R2_yY,0,1.0,1.0);
    reduce_n1EtaPhiN1EtaPhiOntoN1N1DetaDphi(part1BaseHistos.h_n1_phiY,part1BaseHistos.h_n1_phiY,h_n1n1_DyDphi,nBins_Dy,nBins_Dphi);
    if (reportDebug(__FUNCTION__))  cout <<  " calculateR2_H2H2H2(pairHistos.h_n2_DyDphi,h_n1n1_DyDphi,h_R2_DyDphi,0,1.0,1.0)" << endl;
    
    double yieldA = part1DerivedHistos.h_n1_y->Integral("Width");
    double yieldB = part2DerivedHistos.h_n1_y->Integral("Width");
    
    h_rho2_DyDphi->Add(pairHistos.h_n2_DyDphi);
//    h_B2AB_DyDphi->Add(pairHistos.h_n2_DyDphi);
//    h_B2BA_DyDphi->Add(pairHistos.h_n2_DyDphi);

    calculateR2_H2H2H2(pairHistos.h_n2_DyDphi,h_n1n1_DyDphi,h_R2_DyDphi,0,1.0,1.0);
    h_B2AB_DyDphi->Add(h_R2_DyDphi);
    h_B2BA_DyDphi->Add(h_R2_DyDphi);
    h_B2AB_DyDphi->Scale(yieldA);
    h_B2BA_DyDphi->Scale(yieldB);


    if (reportDebug(__FUNCTION__))  cout <<  " shiftY(*h_R2_DetaDphi,*h_R2_DyDphi_shft,nBins_Dphi_shft)" << endl;
    shiftY(*h_rho2_DyDphi,*h_rho2_DyDphi_shft,nBins_Dphi_shft);
    shiftY(*h_B2AB_DyDphi,*h_B2AB_DyDphi_shft,nBins_Dphi_shft);
    shiftY(*h_B2BA_DyDphi,*h_B2BA_DyDphi_shft,nBins_Dphi_shft);
    shiftY(*h_R2_DyDphi,*h_R2_DyDphi_shft,nBins_Dphi_shft);
    
    if (fillP2)
      {
      avgPt1Y = avgValue(part1DerivedHistos.h_pt_y);
      avgPt2Y = avgValue(part2DerivedHistos.h_pt_y);
      scalingFactorY = 1.0/avgPt1Y/avgPt2Y;
      h_P2_yY->Add(h_DptDpt_yY,h_DptDpt_yY,1.0,0.0);
      h_P2_yY->Scale(scalingFactorY);
      
      if (reportDebug(__FUNCTION__))  cout <<  " shiftY(*h_R2_DyDphi,*h_R2_DyDphi_shft,nBins_Dphi_shft)" << endl;
      
      shiftY(*h_DptDpt_DyDphi, *h_DptDpt_DyDphi_shft,nBins_Dphi_shft);
      
      /// calculate average pt base on h_pt_eta histograms
      h_P2_DyDphi->Add(h_DptDpt_DyDphi,h_DptDpt_DyDphi,1.0,0.0);
      h_P2_DyDphi->Scale(scalingFactorY);
      //symmetrizeDeltaEtaDeltaPhi(h_P2_DetaDphi,ijNormalization);
      shiftY(*h_P2_DyDphi,*h_P2_DyDphi_shft, nBins_Dphi_shft);
      
      calculateG2_H2H2H2H2( h_DptDpt_yY,       h_n1n1_yY,       h_pt1pt1_yY,       h_G2_yY,       ijNormalization, bincorrection, 1.0);
      calculateG2_H2H2H2H2( h_DptDpt_phiPhi,   h_n1n1_phiPhi,   h_pt1pt1_phiPhi,   h_G2_phiPhi,   ijNormalization, bincorrection, 1.0);
      calculateG2_H2H2H2H2( h_DptDpt_DetaDphi, h_n1n1_DetaDphi, h_pt1pt1_DetaDphi, h_G2_DetaDphi, ijNormalization, bincorrection, 1.0);
      shiftY(*h_G2_DetaDphi,*h_G2_DetaDphi_shft,nBins_Dphi_shft);
      }
    }
  
  
  if (reportEnd(__FUNCTION__))
    ;
  getSeverityLevel(store);
}
