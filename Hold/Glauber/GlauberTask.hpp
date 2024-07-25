#ifndef CAP__GlauberTask
#define CAP__GlauberTask
#include "EventTask.hpp"
#include "HistogramGroup.hpp"
#include "Histogramset.hpp"

namespace CAP
{
using namespace std;

//---------------------------------------------------------------------------------
TF1 *getNNProf(Double_t snn=67.6, Double_t omega=0.4, Double_t G=1);

//---------------------------------------------------------------------------------
//void runAndSaveNtuple(const Int_t n,
//                      const char *sysA        = "Pb",
//                      const char *sysB        = "Pb",
//                      const Double_t signn    = 67.6,
//                      const Double_t sigwidth = -1,
//                      const Double_t mind     = 0.4,
//		      const Double_t omega    = -1,
//                      const Double_t noded    = -1,
//                      const char *fname       = 0);

//---------------------------------------------------------------------------------
//void runAndSaveNucleons(const Int_t n,
//                        const char *sysA        = "Pb",           
//                        const char *sysB        = "Pb",           
//                        const Double_t signn    = 67.6,           
//                        const Double_t sigwidth = -1,
//                        const Double_t mind     = 0.4,
//                        const Bool_t verbose    = 0,
//			const Double_t bmin     = 0.0,
//			const Double_t bmax     = 20.0,
//                        const char *fname       = 0);

//---------------------------------------------------------------------------------
//void runAndSmearNtuple(const Int_t n,
//                       const Double_t sigs  = 0.4,
//                       const char *sysA     = "p",
//                       const char *sysB     = "Pb",
//                       const Double_t signn = 67.6,
//                       const Double_t mind  = 0.4,
//		       const Double_t bmin  = 0.0,
//		       const Double_t bmax  = 20.0,
//                       const char *fname    = 0);


//---------------------------------------------------------------------------------
//void runAndOutputLemonTree(const Int_t n,
//			   const Double_t sigs  = 0.4,
//			   const char *sysA     = "p",
//			   const char *sysB     = "Pb",
//			   const Double_t signn = 67.6,
//			   const Double_t mind  = 0.4,
//			   const Double_t bmin  = 0.0,
//			   const Double_t bmax  = 20.0,
//			   const Bool_t   ogrid = 0,
//			   const char *fname    = 0);

//---------------------------------------------------------------------------------
//void runAndCalcDens(const Int_t n,
//		    const Double_t alpha = 0.1,
//		    const char *sysA     = "Pb",
//		    const char *sysB     = "Pb",
//		    const Double_t signn = 67.6,
//		    const Double_t mind  = 0.4,
//		    const char *fname    = "glau_dens_hists.root");


class InvalidOmegaGlauberException(double omega, const String & source);


//---------------------------------------------------------------------------------
TF1 *getNNProf(Double_t snn, Double_t omega, Double_t G) 
{
  // NN collision profile from https://arxiv.org/abs/1307.0636
  if ((omega<0) || (omega>1)) throw InvalidOmegaGlauberException(omega,__FUNCTION__);
  Double_t R2 = snn/10./CAP::Math::pi();
  TF1 *nnprof = new TF1("nnprofgamma","[2]*(1-TMath::Gamma([0],[1]*x^2))",0,3);
  nnprof->setParameters(1./omega,G/omega/R2,G);
  return nnprof;
}


//---------------------------------------------------------------------------------
void runAndSmearNtuple(const Int_t n,
                       const Double_t sigs,
                       const char *sysA,
                       const char *sysB,
                       const Double_t signn,
                       const Double_t mind,
		       const Double_t bmin,
		       const Double_t bmax,
                       const char *fname)
{
  // run Glauber and store ntuple with smeared eccentricities in file.

  GlauberMC *mcg = new GlauberMC(sysA,sysB,signn);
  mcg->setMinDistance(mind);
  mcg->setBmin(bmin);
  mcg->setBmax(bmax);
  
  TFile *out = TFile::Open(fname,"recreate",fname,9);
  if (!out)
    return;
  TNtuple *nt = new TNtuple("nt","nt",
      "nParticipants:nCollisions:B:Psi1P:Ecc1P:Psi2P:Ecc2P:Psi3P:Ecc3P:Psi4P:Ecc4P:Psi5P:Ecc5P:Psi1G:Ecc1G:Psi2G:Ecc2G:Psi3G:Ecc3G:Psi4G:Ecc4G:Psi5G:Ecc5G:Sx2P:Sy2P:Sx2G:Sy2G");
  nt->setDirectory(out);

  const Int_t NSAMP = 100;
  TF1 *rad = new TF1("rad","x*TMath::Exp(-x*x/(2.*[0]*[0]))",0.0,3*sigs);
  rad->setParameter(0,sigs);

  for (Int_t ievent=0; ievent<n; ++ievent) {
    while (!mcg->NextEvent()) {}

    const GlauberNucleus *nucA   = mcg->getNucleusA();
    const TObjArray *nucleonsA = nucA->getAllNucleons();
    const Int_t AN             = nucA->getN();
    const GlauberNucleus *nucB   = mcg-> getNucleusB();
    const TObjArray *nucleonsB = nucB->getAllNucleons();
    const Int_t BN             = nucB->getN();

    Double_t sinphi[10] = {0};
    Double_t cosphi[10] = {0};
    Double_t rn[10]     = {0};
    Double_t ecc[10]    = {0};
    Double_t psi[10]    = {0};
    Double_t sx2g       = 0;
    Double_t sy2g       = 0;

    for (Int_t s=0; s<NSAMP; ++s) {
      Int_t ni = 0;
      Double_t xvals[1000] = {0};
      Double_t yvals[1000] = {0};
      for (Int_t i = 0; i<AN; ++i) {
        GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(i));
        if (!nucleonA->isWounded())
          continue;
        Double_t sr = rad->getRandom();
        Double_t sp = gRandom->Uniform(-CAP::Math::pi(), +CAP::Math::pi());
        xvals[ni]   = nucleonA->getX() + sr*TMath::Cos(sp);
        yvals[ni]   = nucleonA->getY() + sr*TMath::Sin(sp);
        ++ni;
      }
      for (Int_t i = 0; i<BN; ++i) {
        GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(i));
        if (!nucleonB->isWounded())
          continue;
        Double_t sr = rad->getRandom();
        Double_t sp = gRandom->Uniform(-CAP::Math::pi(), +CAP::Math::pi());
        xvals[ni]   = nucleonB->getX() + sr*TMath::Cos(sp);
        yvals[ni]   = nucleonB->getY() + sr*TMath::Sin(sp);
        ++ni;
      }

      Double_t meanX  = 0;
      Double_t meanY  = 0;
      Double_t meanX2 = 0;
      Double_t meanY2 = 0;
      for (Int_t i = 0; i<ni; ++i) {
        meanX  += xvals[i];
        meanY  += yvals[i];
        meanX2 += xvals[i]*xvals[i];
        meanY2 += yvals[i]*yvals[i];
      }
      meanX  /= ni;
      meanY  /= ni;
      meanX2 /= ni;
      meanY2 /= ni;
      sx2g        += meanX2-meanX*meanX;
      sy2g        += meanY2-meanY*meanY;

      for (Int_t j = 1; j<9; ++j) {
        for (Int_t i = 0; i<ni; ++i) {
          Double_t x   = xvals[i] - meanX;
          Double_t y   = yvals[i] - meanY;
          Double_t r   = TMath::Sqrt(x*x+y*y);
          Double_t phi = TMath::ATan2(y,x);
          Double_t w = j;
          if (j==1)
            w = 3; // use r^3 weighting for Ecc1/Psi1
          cosphi[j] += TMath::Power(r,w)*TMath::Cos(j*phi);
          sinphi[j] += TMath::Power(r,w)*TMath::Sin(j*phi);
          rn[j]     += TMath::Power(r,w);
        }
      }
    }
    for (Int_t j = 1; j<9; ++j) {
      psi[j] = (TMath::ATan2(sinphi[j],cosphi[j]) + CAP::Math::pi())/j;
      ecc[j] = TMath::Sqrt(sinphi[j]*sinphi[j] + cosphi[j]*cosphi[j]) / rn[j];
    }

    Float_t v[27]; Int_t i=0;
    v[i++] = mcg->getnParticipants();
    v[i++] = mcg->getNBinaryCollisions();
    v[i++] = mcg->getB();
    v[i++] = mcg->getPsi(1); // point-like calculation values
    v[i++] = mcg->getEcc(1);
    v[i++] = mcg->getPsi(2);
    v[i++] = mcg->getEcc(2);
    v[i++] = mcg->getPsi(3);
    v[i++] = mcg->getEcc(3);
    v[i++] = mcg->getPsi(4);
    v[i++] = mcg->getEcc(4);
    v[i++] = mcg->getPsi(5);
    v[i++] = mcg->getEcc(5);
    v[i++] = psi[1];         // Gaussian smeared values
    v[i++] = ecc[1];
    v[i++] = psi[2];
    v[i++] = ecc[2];
    v[i++] = psi[3];
    v[i++] = ecc[3];
    v[i++] = psi[4];
    v[i++] = ecc[4];
    v[i++] = psi[5];
    v[i++] = ecc[5];
    v[i++] = mcg->getSx2();
    v[i++] = mcg->getSy2();
    v[i++] = sx2g/NSAMP;
    v[i++] = sy2g/NSAMP;
    nt->Fill(v);
  }

  out->Write();
  out->Close();
  delete out;
}




#endif



