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
#include "ParticlePair3DHistos.hpp"

ClassImp(ParticlePair3DHistos);

ParticlePair3DHistos::ParticlePair3DHistos()
:
HistogramGroup()
{
  appendClassName("ParticlePair3DHistos");
}

void ParticlePair3DHistos::createHistograms()
{
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  const String & bn = ptn;

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

  h_n2_Qinv   = createHistogram(makeName(bn,"n2_Qinv"),nBins_Qinv,min_Qinv,max_Qinv, "Q_{inv}","n_{2}");
  h_n2_DeltaP = createHistogram(makeName(bn,"n2_DeltaP"),
                                   nBins_DeltaPs,  min_DeltaPs, max_DeltaPs,
                                   nBins_DeltaPo,  min_DeltaPo, max_DeltaPo,
                                   nBins_DeltaPl,  min_DeltaPl, max_DeltaPl,
                                   "p_{s}","p_{o}", "p_{l}","n_{2}");
}

//________________________________________________________________________
void ParticlePair3DHistos::importHistograms(TFile & inputFile)
{
  const String & ptn = getParentName();
  const String & ppn = getParentPathName();
  const String & bn = ptn;
  h_n2_DeltaP = loadH2(inputFile, makeName(bn,"n2_DeltaP"));
}

void ParticlePair3DHistos::fill(Particle & particle1, Particle & particle2, double weight)
{
  LorentzVector & momentum1 = particle1.getMomentum();
  double pt1   = momentum1.Pt();        iPt1 = getPtBinFor(pt1);
  double phi1  = momentum1.Phi();       if (phi1<0.0) phi1 += CAP::Math::twoPi(); iPhi1 = getPhiBinFor(phi1);
  double eta1  = momentum1.Eta();       iEta1 = fillEta ? getEtaBinFor(eta1) : 0;
  double y1    = momentum1.Rapidity();  iY1   = fillY   ? getYBinFor(y1)     : 0;

  LorentzVector & momentum2 = particle2.getMomentum();
  double pt2   = momentum2.Pt();        iPt2 = getPtBinFor(pt2);
  double phi2  = momentum2.Phi();       if (phi2<0.0) phi2 += CAP::Math::twoPi(); iPhi2 = getPhiBinFor(phi2);
  double eta2  = momentum2.Eta();       iEta2 = fillEta ? getEtaBinFor(eta2) : 0;
  double y2    = momentum2.Rapidity();  iY2   = fillY   ? getYBinFor(y2)     : 0;



        //decompose(double *pa,double *pb,double &qlong,double &qout,double &qside,double &qinv)
        // ====================================================================================
        // Method from Scott Pratt to do three dimensional qinv components
        // ====================================================================================
        double pt,s,Mlong,roots;
        double ptot[4],q[4];
        const int g[4]={1,-1,-1,-1};
        int alpha;
        qinv=0.0;
        s=0.0;
        for(alpha=0;alpha<4;alpha++)
          {
          ptot[alpha]=pa[alpha]+pb[alpha];
          s+=g[alpha]*ptot[alpha]*ptot[alpha];
          q[alpha]=pa[alpha]-pb[alpha];
          qinv-=g[alpha]*q[alpha]*q[alpha];
          }
        pt=sqrt(ptot[1]*ptot[1]+ptot[2]*ptot[2]);
        Mlong=sqrt(s+pt*pt);
        roots=sqrt(s);

        qside=(ptot[1]*q[2]-ptot[2]*q[1])/pt;
        qlong=(ptot[0]*q[3]-ptot[3]*q[0])/Mlong;
        qout=(roots/Mlong)*(ptot[1]*q[1]+ptot[2]*q[2])/pt;
        qinv=sqrt(qinv);
        }
      }
    }

}

