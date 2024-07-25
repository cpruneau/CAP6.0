#ifndef CAP__GlauberTask
#define CAP__GlauberTask
#include "Task.hpp"
#include "HistogramGroup.hpp"
#include "Histogramset.hpp"

namespace CAP
{

#define HAVE_MATHMORE

#if !defined(__CINT__) || defined(__MAKECINT__)
#include <Riostream.h>
#include <TBits.h>
#include <TEllipse.h>
#include <TF1.h>
#include <TF2.h>
#include <TFile.h>
#include <TH2.h>
#include <TLine.h>
#include <TMath.h>
#include <TNamed.h>
#include <TNtuple.h>
#include <TObjArray.h>
#include <TRandom.h>
#include <TRotation.h>
#include <String.h>
#include <TSystem.h>
#include <TVector3.h>
#ifdef HAVE_MATHMORE
 #include <Math/SpecFuncMathMore.h>
#endif
using namespace std;
#endif

#ifndef _runglauber_
#if !defined(__CINT__) || defined(__MAKECINT__)
#define _runglauber_ 3
#endif
#include "HistogramTask.hpp"

//!
//!Class implements Glauber MC generator
//!
class GlauberMC
{
  public:

  protected:
    GlauberNucleus  nucleusA;       //Nucleus A
    GlauberNucleus  nucleusB;       //Nucleus B
    Double_t      fXSect;          //Nucleon-nucleon cross section
    Double_t      fXSectOmega;     //StdDev of Nucleon-nucleon cross section
    Double_t      fXSectLambda;    //Jacobian from tot to inelastic (Strikman)
    Double_t      fXSectEvent;     //GlauberEventStat value of Nucleon-nucleon cross section
    TObjArray*    nucleonsA;      //Array of nucleons in nucleus A
    TObjArray*    nucleonsB;      //Array of nucleons in nucleus B
    TObjArray*    nucleonsAB;       //Array which joins Nucleus A & B
    Int_t         nucleonsA.size();             //Number of nucleons in nucleus A
    Int_t         nucleonsB.size();             //Number of nucleons in nucleus B
    TNtuple*      fNt;             //Ntuple for results (created, but not deleted)
    Int_t         eventStatsents;         //Number of events with at least one collision
    Int_t         nTotalEvents;    //All events within selected impact parameter range
    Double_t      minImpactPar;           //Minimum impact parameter to be generated
    Double_t      maxImpactPar;           //Maximum impact parameter to be generated
    Double_t      fHardFrac;       //Fraction of cross section used for nHardCollisions (def=0.65)
    Int_t         fDetail;         //Detail to store (99=all by default)
    Bool_t        fCalcArea;       //If true calculate overlap area via grid (slow, off by default)
    Bool_t        fCalcLength;     //If true calculate path length (slow, off by default)
    Bool_t        fDoCore;         //If true calculate area and eccentricy only for core participants (off by default)
    Bool_t        fDoAAGG;         //If true do Glauber Gribov also for AA
    Int_t         fMaxnParticipantsFound;  //Largest value of nParticipants obtained
    Double_t      fPsiN[10];       //Psi N
    Double_t      fEccN[10];       //Ecc N
    Double_t      f2Cx;            //Two-component x
    TF1          *fPTot;           //Cross section distribution
    TF1          *fNNProf;         //NN profile (hard-sphere == 0 by default)
    GlauberEventStat         eventStats;             //Glauber event (results of calculation stored in tree)
    Bool_t        fBC[999][999];   //Array to record binary collision
    Bool_t        CalcResults(Double_t impactPar);
    Bool_t        calculateEvent(Double_t impactPar);

  public:
  GlauberMC();
  GlauberMC(const char* NA = "Pb", const char* NB = "Pb", Double_t xsect = 42, Double_t xsectsigma=0);
  GlauberMC(const GlauberMC & glauberMC );
  GlauberMC operator=(const GlauberMC & glauberMC);


  virtual              ~GlauberMC() {delete fNt; fNt=0;}

    Double_t            CalcDens(TF1 &prof, Double_t xval, Double_t yval) const;
    void                Draw(Option_t* option="");
    Double_t            getB()                 const {return eventStats.B;}
    Double_t            getBNN()               const {return eventStats.BNN;}
    Double_t            getBmax()              const {return maxImpactPar;}
    Double_t            getBmin()              const {return minImpactPar;}
    Double_t            getEcc(Int_t i=2)      const {return fEccN[i];}
    Double_t            getHardFrac()          const {return fHardFrac;}
    Double_t            getmeanX()             const {return eventStats.meanX;}
    Double_t            getmeanXParts()        const {return eventStats.meanX;}
    Double_t            getmeanXSystem()       const {return eventStats.meanXSystem;}
    Double_t            getmeanY()             const {return eventStats.meanY;}
    Double_t            getmeanYParts()        const {return eventStats.meanY;}
    Double_t            getmeanYSystem()       const {return eventStats.meanYSystem;}
    Double_t            getPsi(Int_t i=2)      const {return fPsiN[i];}
    Double_t            getSx2()               const {return eventStats.VarX;}    
    Double_t            getSxy()               const {return eventStats.VarXY;}    
    Double_t            getSy2()               const {return eventStats.VarY;}    
    Double_t            getTotXSect()          const;
    Double_t            getTotXSectErr()       const;
    Double_t            getXSectEvent()        const {return fXSectEvent;}
    Int_t               getNBinaryCollisions()             const {return eventStats.nCollisions;}
    Int_t               getNBinaryCollisionsnn()           const {return eventStats.nCollisions_nn;}
    Int_t               getNBinaryCollisionspn()           const {return eventStats.nCollisions_pn;}
    Int_t               getNBinaryCollisionspp()           const {return eventStats.nCollisions_pp;}
    Int_t               getnParticipants()             const {return eventStats.nParticipants;}
    Int_t               getnParticipants0()            const {return eventStats.nParticipants0;}
    Int_t               getnParticipantsA()            const {return eventStats.nParticipantsA;}
    Int_t               getnParticipantsB()            const {return eventStats.nParticipantsB;}
    Int_t               getnParticipantsFound()        const {return fMaxnParticipantsFound;}
    TF1*                getXSectDist()         const {return fPTot;}
    GlauberNucleus*       getNucleusA()                {return &nucleusA;}
    GlauberNucleus*       getNucleusB()                {return &nucleusB;}
    TNtuple*            getNtuple()            const {return fNt;}
    TObjArray          *getAllNucleons();
    const GlauberEventStat        &getEvent()             const {return eventStats;}
    const GlauberEventStat        *getEvent()                   {return &eventStats;}
    const GlauberNucleus* getNucleusA()          const {return &nucleusA;}
    const GlauberNucleus* getNucleusB()          const {return &nucleusB;}
    Bool_t              IsBC(Int_t i, Int_t j) const {return fBC[i][j];}
    Bool_t              NextEvent(Double_t impactPar=-1);
    void                GlauberNucleon()                      {delete fNt; fNt=0; }
    Bool_t              readNextEvent(Bool_t calc=1, const char *fname=0);       
    void                run(Int_t nevents,Double_t b=-1);
    void                set2Cx(Double_t x)           {f2Cx = x;}
    void                setBmax(Double_t bmax)       {maxImpactPar = bmax;}
    void                setBmin(Double_t bmin)       {minImpactPar = bmin;}
    void                setCalcAAGG(Bool_t b)        {fDoAAGG = b;}
    void                setCalcArea(Bool_t b)        {fCalcArea = b;}
    void                setCalcCore(Bool_t b)        {fDoCore = b;}
    void                setCalcLength(Bool_t b)      {fCalcLength = b;}
    void                setDetail(Int_t d)           {fDetail = d;}
    void                setHardFrac(Double_t f)      {fHardFrac=f;}
    void                setLattice(Int_t i)          {nucleusA.setLattice(i); nucleusB.setLattice(i);}
    void                setMinDistance(Double_t d)   {nucleusA.setMinDist(d); nucleusB.setMinDist(d);}
    void                setNNProf(TF1 *f1)           {fNNProf = f1;}
    void                setNodeDistance(Double_t d)  {nucleusA.setNodeDist(d); nucleusB.setNodeDist(d);}
    void                setRecenter(Int_t b)         {nucleusA.setRecenter(b); nucleusB.setRecenter(b);}
    void                setShiftMax(Double_t s)      {nucleusA.setShiftMax(s); nucleusB.setShiftMax(s);}
    void                setSmearing(Double_t s)      {nucleusA.setSmearing(s); nucleusB.setSmearing(s);}
    const char         *Str()                  const {return Form("gmc-%s%s-snn%.1f-md%.1f-nd%.1f-rc%d-smax%.1f",nucleusA.getName(),nucleusB.getName(),fXSect,nucleusB.getMinDist(),nucleusB.getNodeDist(),nucleusB.getRecenter(),nucleusB.getShiftMax());}
    static void         PrintVersion()               {cout << "GlauberMC " << Version() << endl;}
    static const char  *Version()                    {return "v3.2";}

    ClassDef(GlauberMC,6) // GlauberMC class
};

//---------------------------------------------------------------------------------
TF1 *getNNProf(Double_t snn, Double_t omega, Double_t G) 
{ // NN collisoin profile from https://arxiv.org/abs/1307.0636
  if ((omega<0) || (omega>1))
    return 0;
  Double_t R2 = snn/10./CAP::Math::pi();
  TF1 *nnprof = new TF1("nnprofgamma","[2]*(1-TMath::Gamma([0],[1]*x^2))",0,3);
  nnprof->setParameters(1./omega,G/omega/R2,G);
  return nnprof;
}



ClassImp(GlauberMC)
  ClassImp(GlauberMC::GlauberEventStat)
//---------------------------------------------------------------------------------

GlauberMC::GlauberMC(const char* NA, const char* NB, Double_t xsect, Double_t xsectsigma) :
  nucleusA(NA),nucleusB(NB),
  fXSect(xsect),fXSectOmega(0),fXSectLambda(0),fXSectEvent(0),
  nucleonsA(0),nucleonsB(0),nucleonsAB(0),
  nucleonsA.size()(0),nucleonsB.size()(0),fNt(0),
  eventStatsents(0),nTotalEvents(0),minImpactPar(0),maxImpactPar(20),fHardFrac(0.65),
  fDetail(99),fCalcArea(0),fCalcLength(0), fDoCore(0), fDoAAGG(1),
  fMaxnParticipantsFound(0),f2Cx(0),fPTot(0),fNNProf(0),
  eventStats()
{
  if (xsectsigma>0) {
    fXSectOmega = xsectsigma;
    fXSectLambda = 1;
    fPTot = new TF1("fPTot","((x/[2])/(x/[2]+[0]))*exp(-(((x/[2])/[0]-1 )**2)/([1]*[1]))/[2]",0,300);
    fPTot->setParameters(fXSect,fXSectOmega,fXSectLambda);
    fPTot->setNpx(1000);
    fXSectLambda = fXSect/fPTot->getHistogram()->getmean();
    cout << "final lambda=" << fXSectLambda << endl;
    fPTot->setParameters(fXSect,fXSectOmega,fXSectLambda);
    cout << "final <sigma>=" << fPTot->getHistogram()->getmean() << endl;
  }

  String name(Form("Glauber_%s_%s",nucleusA.getName(),nucleusB.getName()));
  String title(Form("Glauber %s+%s Version",nucleusA.getName(),nucleusB.getName()));
  setName(name);
  setTitle(title);
}

Bool_t GlauberMC::calculateEvent(Double_t impactPar)
{
  // calc next event
  if (!nucleonsA) {
    nucleonsA = nucleusA.getAllNucleons();
    nucleonsA.size() = nucleusA.getN();
    for (Int_t i = 0; i<nucleonsA.size(); ++i) {
      GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(i));
      nucleonA->setInNucleusA();
    }
  }

  if (!nucleonsB) {
    nucleonsB = nucleusB.getAllNucleons();
    nucleonsB.size() = nucleusB.getN();
    for (Int_t i = 0; i<nucleonsB.size(); ++i) {
      GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(i));
      nucleonB->setInNucleusB();
    }
  }

  Double_t xsecA[999] = {0};
  Double_t xsecB[999] = {0};
  if (fPTot) {
    fXSectEvent = fPTot->getRandom();
    if (fDoAAGG) {
      for (Int_t i = 0; i<nucleonsA.size(); ++i)
	xsecA[i] = fPTot->getRandom();
      for (Int_t i = 0; i<nucleonsB.size(); ++i)
	xsecB[i] = fPTot->getRandom();
    }
  } else 
    fXSectEvent = fXSect;

  // "ball" diameter = distance at which two balls interact
  Double_t d2 = (Double_t)fXSectEvent/(CAP::Math::pi()*10); // in fm^2
  Double_t bh = TMath::Sqrt(d2*fHardFrac);
  if (fNNProf) {
    Double_t xmin=0,xmax=0;
    fNNProf->getRange(xmin,xmax);
    d2 = xmax*xmax;
  }

  eventStats.GlauberNucleon();
  memset(fBC,0,sizeof(Bool_t)*999*999);
  Int_t nc=0,nh=0;
  for (Int_t i = 0; i<nucleonsB.size(); ++i) {
    GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(i));
    Bool_t tB=nucleonB->getNucleonType();
    for (Int_t j = 0; j<nucleonsA.size(); ++j) {
      GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(j));
      Double_t dx = nucleonB->getX()-nucleonA->getX();
      Double_t dy = nucleonB->getY()-nucleonA->getY();
      Double_t dij = dx*dx+dy*dy;
      if (fDoAAGG && fPTot)
	d2 = 0.5*(xsecA[j]+xsecB[i])/(CAP::Math::pi()*10);
      if (dij>d2) 
        continue;
      Double_t bij = TMath::Sqrt(dij);
      if (fNNProf) {
        Double_t val = fNNProf->Eval(bij);
        Double_t ran = gRandom->Uniform();
        if (ran>val)
          continue;
      }
      nucleonB->collide();
      nucleonA->collide();
      fBC[i][j] = 1;
      eventStats.BNN  += bij;
      ++nc;
      if (bij<bh)
        ++nh;
      Bool_t tA=nucleonA->getNucleonType();
      if (tA!=tB)
        ++eventStats.nCollisions_pn;
      else if (tA==1)
        ++eventStats.nCollisions_pp;
      else
        ++eventStats.nCollisions_nn;
      if (nc==1) {
        eventStats.X0 = (nucleonA->getX()+nucleonB->getX())/2;
        eventStats.Y0 = (nucleonA->getY()+nucleonB->getY())/2;
      }
    }
  }
  eventStats.B = impactPar;
  ++nTotalEvents;
  if (nc>0) {
    ++eventStatsents;
    eventStats.nCollisions     = nc;
    eventStats.nHardCollisions     = nh;
    eventStats.BNN      /= nc;
    return CalcResults(impactPar);
  }
  return kFALSE;
}

Bool_t GlauberMC::CalcResults(Double_t impactPar)
{
  // calc results for the given event
  Double_t sumW=0;
  Double_t sumWA=0;
  Double_t sumWB=0;

  Double_t sinphi[10] = {0};
  Double_t cosphi[10] = {0};
  Double_t rn[10]     = {0};

  const Int_t kNc = fDoCore; // used later for core/corona

  for (Int_t i = 0; i<nucleonsA.size(); ++i) {
    GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(i));
    Double_t xA=nucleonA->getX();
    Double_t yA=nucleonA->getY();
    eventStats.meanXSystem  += xA;
    eventStats.meanYSystem  += yA;
    eventStats.meanXA  += xA;
    eventStats.meanYA  += yA;
    if (nucleonA->isWounded()) {
      Double_t w = nucleonA->get2CWeight(f2Cx);
      ++eventStats.nParticipants;
      if (nucleonA->getNBinaryCollisions()==1)
	++eventStats.nParticipants0;
      ++eventStats.nParticipantsA;
      sumW   += w;
      sumWA  += w;
      eventStats.meanX  += xA * w;
      eventStats.meanY  += yA * w;
      eventStats.meanX2 += xA * xA * w;
      eventStats.meanY2 += yA * yA * w;
      eventStats.meanXY += xA * yA * w;
    }
  }

  for (Int_t i = 0; i<nucleonsB.size(); ++i) {
    GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(i));
    Double_t xB=nucleonB->getX();
    Double_t yB=nucleonB->getY();
    eventStats.meanXSystem  += xB;
    eventStats.meanYSystem  += yB;
    eventStats.meanXB  += xB;
    eventStats.meanYB  += yB;
    if (nucleonB->isWounded()) {
      Double_t w = nucleonB->get2CWeight(f2Cx);
      ++eventStats.nParticipants;
      if (nucleonB->getNBinaryCollisions()==1)
	++eventStats.nParticipants0;
      ++eventStats.nParticipantsB;
      sumW   += w;
      sumWB  += w;
      eventStats.meanX  += xB * w;
      eventStats.meanY  += yB * w;
      eventStats.meanX2 += xB * xB * w;
      eventStats.meanY2 += yB * yB * w;
      eventStats.meanXY += xB * yB * w;
    }
  }
  if (eventStats.nParticipants>0) {
    eventStats.meanX  /= sumW;
    eventStats.meanY  /= sumW;
    eventStats.meanX2 /= sumW;
    eventStats.meanY2 /= sumW;
    eventStats.meanXY /= sumW;
  } else {
    eventStats.meanX = 0;
    eventStats.meanY  = 0;
    eventStats.meanX2 = 0;
    eventStats.meanY2 = 0;
    eventStats.meanXY = 0;
  }

  if (nucleonsA.size()+nucleonsB.size()>0) {
    eventStats.meanXSystem /= (nucleonsA.size() + nucleonsB.size());
    eventStats.meanYSystem /= (nucleonsA.size() + nucleonsB.size());
  } else {
    eventStats.meanXSystem = 0;
    eventStats.meanYSystem = 0;
  }
  if (nucleonsA.size()>0) {
    eventStats.meanXA /= nucleonsA.size();
    eventStats.meanYA /= nucleonsA.size();
  } else {
    eventStats.meanXA = 0;
    eventStats.meanYA = 0;
  }
  if (nucleonsB.size()>0) {
    eventStats.meanXB /= nucleonsB.size();
    eventStats.meanYB /= nucleonsB.size();
  } else {
    eventStats.meanXB = 0;
    eventStats.meanYB = 0;
  }

  eventStats.VarX  = eventStats.meanX2-(eventStats.meanX*eventStats.meanX);
  eventStats.VarY  = eventStats.meanY2-(eventStats.meanY*eventStats.meanY);
  eventStats.VarXY = eventStats.meanXY-eventStats.meanX*eventStats.meanY;
  Double_t tmpa = eventStats.VarX*eventStats.VarY-eventStats.VarXY*eventStats.VarXY;
  if (tmpa<0) 
    eventStats.AreaW = -1;
  else 
    eventStats.AreaW = TMath::Sqrt(tmpa);

  if (eventStats.nParticipants>0) {
    // do full moments relative to meanX and meanY
    for (Int_t n = 1; n<10; ++n) {
      for (Int_t ia = 0; ia<nucleonsA.size(); ++ia) {
        GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(ia));
	if (nucleonA->getNBinaryCollisions()<=kNc) 
	  continue;
	Double_t xA=nucleonA->getX() - eventStats.meanX;
	Double_t yA=nucleonA->getY() - eventStats.meanY;
	Double_t r = TMath::Sqrt(xA*xA+yA*yA);
	Double_t phi = TMath::ATan2(yA,xA);
	Double_t w = n;
	if (n==1) 
	  w = 3; // use r^3 weighting for Ecc1/Psi1
	Double_t rw = TMath::Power(r,w);
	cosphi[n] += rw*TMath::Cos(n*phi);
	sinphi[n] += rw*TMath::Sin(n*phi);
	rn[n] += rw;
      }
      for (Int_t ib = 0; ib<nucleonsB.size(); ++ib) {
        GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(ib));
	if (nucleonB->getNBinaryCollisions()<=kNc) 
	  continue;
	Double_t xB=nucleonB->getX() - eventStats.meanX;
	Double_t yB=nucleonB->getY() - eventStats.meanY;
	Double_t r = TMath::Sqrt(xB*xB+yB*yB);
	Double_t phi = TMath::ATan2(yB,xB);
	Double_t w = n;
	if (n==1)
	  w = 3; // use r^3 weighting for Ecc1/Psi1
	Double_t rw = TMath::Power(r,w);
	cosphi[n] += rw*TMath::Cos(n*phi);
	sinphi[n] += rw*TMath::Sin(n*phi);
	rn[n] += rw;
      }
      cosphi[n] /= eventStats.nParticipants;
      sinphi[n] /= eventStats.nParticipants;
      rn[n] /= eventStats.nParticipants;
      if (rn[n]>0) {
	fPsiN[n] = (TMath::ATan2(sinphi[n],cosphi[n]) + CAP::Math::pi())/n;
	fEccN[n] = TMath::Sqrt(sinphi[n]*sinphi[n]+cosphi[n]*cosphi[n])/rn[n];
      } else {
	fPsiN[n] = -1;
	fEccN[n] = -1;
      }
    }
    if (!kNc) { //silly test but useful to catch errors 
      Double_t t=TMath::Sqrt(TMath::Power(eventStats.VarY-eventStats.VarX,2)+4.*eventStats.VarXY*eventStats.VarXY)/(eventStats.VarY+eventStats.VarX)/fEccN[2];
      if (t<0.99||t>1.01)
        cout << "Error: Expected t=1 but found t=" << t << endl;
    }
  }

  eventStats.B      = impactPar;
  eventStats.PhiA   = nucleusA.getPhiRot();
  eventStats.ThetaA = nucleusA.getThetaRot();
  eventStats.PhiB   = nucleusB.getPhiRot();
  eventStats.ThetaB = nucleusB.getThetaRot();
  eventStats.Psi1   = fPsiN[1];
  eventStats.Ecc1   = fEccN[1];
  eventStats.Psi2   = fPsiN[2];
  eventStats.Ecc2   = fEccN[2];
  eventStats.Psi3   = fPsiN[3];
  eventStats.Ecc3   = fEccN[3];
  eventStats.Psi4   = fPsiN[4];
  eventStats.Ecc4   = fEccN[4];
  eventStats.Psi5   = fPsiN[5];
  eventStats.Ecc5   = fEccN[5];

  if (fCalcArea) {
    const Int_t nbins=200;
    const Double_t ell=10;
    const Double_t da=2*ell*2*ell/nbins/nbins;
    const Double_t d2 = (Double_t)fXSectEvent/(CAP::Math::pi()*10); // in fm^2
    const Double_t r2 = d2/4.;
    const Double_t mx = eventStats.meanX;
    const Double_t my = eventStats.meanY;
    TH2D areaA("hAreaA",";x (fm);y (fm)",nbins,-ell,ell,nbins,-ell,ell);
    TH2D areaB("hAreaB",";x (fm);y (fm)",nbins,-ell,ell,nbins,-ell,ell);
    for (Int_t i = 0; i<nucleonsA.size(); ++i) {
      GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(i));
      if (!nucleonA->isWounded())
        continue;
      if (nucleonA->getNBinaryCollisions()==kNc)
        continue;
      Double_t x = nucleonA->getX()-mx;
      Double_t y = nucleonA->getY()-my;
      for (Int_t xi=1; xi<=nbins; ++xi) {
        for (Int_t yi=1; yi<=nbins; ++yi) {
          Int_t bin = areaA.getBin(xi,yi);
          Double_t val=areaA.getBinContent(bin);
          if (val>0)
            continue;
          Double_t dx=x-areaA.getXaxis()->getBinCenter(xi);
          Double_t dy=y-areaA.getYaxis()->getBinCenter(yi);
          if (dx*dx+dy*dy<r2)
            areaA.setBinContent(bin,1);
        }
      }
    }
    for (Int_t i = 0; i<nucleonsB.size(); ++i) {
      GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(i));
      if (!nucleonB->isWounded())
        continue;
      if (nucleonB->getNBinaryCollisions()==kNc)
        continue;
      Double_t x = nucleonB->getX()-mx;
      Double_t y = nucleonB->getY()-my;
      for (Int_t xi=1; xi<=nbins; ++xi) {
        for (Int_t yi=1; yi<=nbins; ++yi) {
          Int_t bin = areaB.getBin(xi,yi);
          Double_t val=areaB.getBinContent(bin);
          if (val>0)
            continue;
          Double_t dx=x-areaB.getXaxis()->getBinCenter(xi);
          Double_t dy=y-areaB.getYaxis()->getBinCenter(yi);
          if (dx*dx+dy*dy<r2)
            areaB.setBinContent(bin,1);
        }
      }
    }
    Double_t overlap1=0;
    Double_t overlap2=0;
    for (Int_t xi=1; xi<=nbins; ++xi) {
      for (Int_t yi=1; yi<=nbins; ++yi) {
        Int_t bin = areaA.getBin(xi,yi);
        Double_t vA=areaA.getBinContent(bin);
        Double_t vB=areaB.getBinContent(bin);
        if (vA>0&&vB>0)
          ++overlap1;
        if (vA>0||vB>0)
          ++overlap2;
      }
    }
    eventStats.AreaO = overlap1*da;
    eventStats.AreaA = overlap2*da;
  }

  if (fCalcLength) {
    const Double_t krhs = TMath::Sqrt(fXSectEvent/40./CAP::Math::pi());
    const Double_t ksg  = krhs/TMath::Sqrt(5);
    const Double_t kDL  = 0.1;
    TF1 rad("rad","2*pi/[0]/[0]*TMath::Exp(-x*x/(2.*[0]*[0]))",0.0,5*ksg); 
    rad.setParameter(0,ksg);
    const Double_t minval = rad.Eval(5*ksg);
    eventStats.Phi0         = gRandom->Uniform(0,TMath::TwoPi());
    Double_t kcphi0  = TMath::Cos(eventStats.Phi0);
    Double_t ksphi0  = TMath::Sin(eventStats.Phi0);
    Double_t x       = eventStats.X0;
    Double_t y       = eventStats.Y0;
    Double_t i0a     = 0;
    Double_t i1a     = 0;
    Double_t l       = 0;
    Double_t val     = CalcDens(rad,x,y);
    while (val>minval) {
      x     += kDL * kcphi0;
      y     += kDL * ksphi0;
      i0a   += val;
      i1a   += l*val;
      l+=kDL;
      val    = CalcDens(rad,x,y);
    }
    eventStats.Length = 2*i1a/i0a;
  }

  if (eventStats.nParticipants > fMaxnParticipantsFound) 
    fMaxnParticipantsFound = eventStats.nParticipants;

  return kTRUE;
}

Double_t GlauberMC::CalcDens(TF1 &prof, Double_t xval, Double_t yval) const
{
  Double_t rmin=0,rmax=0;
  prof.getRange(rmin,rmax);
  Double_t r2max = rmax*rmax;
  Double_t ret = 0;
  for (Int_t i = 0; i<nucleonsA.size(); ++i) {
    GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(i));
    if (!nucleonA->isWounded())
      continue;
    Double_t x = nucleonA->getX();
    Double_t y = nucleonA->getY();
    Double_t r2=(xval-x)*(xval-x)+(yval-y)*(yval-y);
    if (r2>r2max)
      continue;
    ret += prof.Eval(TMath::Sqrt(r2));
  }
  for (Int_t i = 0; i<nucleonsB.size(); ++i) {
    GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(i));
    if (!nucleonB->isWounded())
      continue;
    Double_t x = nucleonB->getX();
    Double_t y = nucleonB->getY();
    Double_t r2=(xval-x)*(xval-x)+(yval-y)*(yval-y);
    if (r2>r2max)
      continue;
    ret += prof.Eval(TMath::Sqrt(r2));
  }
  return ret;
}

void GlauberMC::Draw(Option_t* option)
{
  static TH2F *h2f = new TH2F("hGlauberMC",";x (fm);y(fm)",1,-18,18,1,-12,12);

  h2f->GlauberNucleon();
  h2f->setStats(0);
  h2f->Draw();

  TEllipse e;
  e.setFillColor(0);
  e.setFillStyle(0);
  e.setLineColor(1);
  e.setLineStyle(2);
  e.setLineWidth(1);
  e.DrawEllipse(getB()/2,0,nucleusB.getR(),nucleusB.getR(),0,360,0);
  e.DrawEllipse(-getB()/2,0,nucleusA.getR(),nucleusA.getR(),0,360,0);
  nucleusA.Draw(fXSect, kMagenta, kYellow);
  nucleusB.Draw(fXSect, kMagenta, kOrange);

  String opt(option);
  if (opt.IsNull())
    return;

  Double_t sy2 = getSy2();
  Double_t sx2 = getSx2();
  Double_t phase = 0;
  if (sy2<sx2) {
    Double_t d = sx2;
    sx2 = sy2;
    sy2 = d;
    phase = CAP::Math::pi()/2.;
  }
  Double_t x1 = (0.5*(sy2-sx2)+TMath::Sqrt(TMath::Power(sy2-sx2,2.)-4*TMath::Power(getSxy(),2)));
  Double_t ang = TMath::ATan2(-getSxy(),x1)+phase;
  TLine l;
  l.setLineWidth(3);
  l.DrawLine(-10*TMath::Cos(ang),-10*TMath::Sin(ang),10*TMath::Cos(ang),10*TMath::Sin(ang));
}

Double_t GlauberMC::getTotXSect() const
{
  return (1.*eventStatsents/nTotalEvents)*CAP::Math::pi()*maxImpactPar*maxImpactPar/100;
}

Double_t GlauberMC::getTotXSectErr() const
{
  return getTotXSect()/TMath::Sqrt((Double_t)eventStatsents) * TMath::Sqrt(Double_t(1.-eventStatsents/nTotalEvents));
}

TObjArray *GlauberMC::getAllNucleons()
{

  nucleonsA->setOwner(0);
  nucleonsB->setOwner(0);
  TObjArray *allNucleons=new TObjArray(nucleonsA.size()+nucleonsB.size());
  allNucleons->setOwner();
  for (Int_t i = 0; i<nucleonsA.size(); ++i) {
    allNucleons->Add(nucleonsA->At(i));
  }
  for (Int_t i = 0; i<nucleonsB.size(); ++i) {
    allNucleons->Add(nucleonsB->At(i));
  }
  nucleonsAB = allNucleons;
  return allNucleons;
}

Bool_t GlauberMC::nextEvent(Double_t impactPar)
{
  if (impactPar<0) 
    impactPar = TMath::Sqrt((maxImpactPar*maxImpactPar-minImpactPar*minImpactPar)*gRandom->Rndm()+minImpactPar*minImpactPar);

  nucleusA.generateNucleons(-impactPar/2.);
  nucleusB.generateNucleons(impactPar/2.);
  return calculateEvent(impactPar);
}

//Bool_t GlauberMC::readNextEvent(Bool_t calc, const char *fname)
//{
//  static TFile *inf = 0;
//  static Int_t iev  = 0;
//  if (fname) {
//    cout << "readNextEvent: setting up file " << fname << endl;
//    delete inf;
//    inf = TFile::Open(fname);
//    if (!inf)
//      return 0;
//    if (!nucleonsA) {
//      nucleusA.generateNucleons();
//      nucleonsA = nucleusA.getAllNucleons();
//      nucleonsA.size() = nucleusA.getN();
//      for (Int_t i = 0; i<nucleonsA.size(); ++i) {
//	GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(i));
//	nucleonA->setInNucleusA();
//      }
//    }
//    if (!nucleonsB) {
//      nucleusB.generateNucleons();
//      nucleonsB = nucleusB.getAllNucleons();
//      nucleonsB.size() = nucleusB.getN();
//      for (Int_t i = 0; i<nucleonsB.size(); ++i) {
//	GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(i));
//	nucleonB->setInNucleusB();
//      }
//    }
//    if (calc)
//      return 1;
//    fNt = dynamic_cast<TNtuple*>(inf->get(Form("nt_%s_%s",nucleusA.getName(),nucleusB.getName())));
//    if (!fNt) {
//      cerr << "readNextEvent: Could not find ntuple!" << endl;
//      inf->ls();
//      return 0;
//    }
//    fNt->setBranchAddress("nParticipants",&eventStats.nParticipants);
//    fNt->setBranchAddress("nCollisions",&eventStats.nCollisions);
//    fNt->setBranchAddress("B",&eventStats.B);
//    fNt->setBranchAddress("BNN",&eventStats.BNN);
//    fNt->setBranchAddress("VarX",&eventStats.VarX);
//    fNt->setBranchAddress("VarY",&eventStats.VarY);
//    fNt->setBranchAddress("VarXY",&eventStats.VarXY);
//    fNt->setBranchAddress("nParticipantsA",&eventStats.nParticipantsA);
//    fNt->setBranchAddress("nParticipantsB",&eventStats.nParticipantsB);
//    fNt->setBranchAddress("nParticipants0",&eventStats.nParticipants0);
//    fNt->setBranchAddress("Psi1",&eventStats.Psi1);
//    fNt->setBranchAddress("Ecc1",&eventStats.Ecc1);
//    fNt->setBranchAddress("Psi2",&eventStats.Psi2);
//    fNt->setBranchAddress("Ecc2",&eventStats.Ecc2);
//    fNt->setBranchAddress("Psi3",&eventStats.Psi3);
//    fNt->setBranchAddress("Ecc3",&eventStats.Ecc3);
//    fNt->setBranchAddress("Psi4",&eventStats.Psi4);
//    fNt->setBranchAddress("Ecc4",&eventStats.Ecc4);
//    fNt->setBranchAddress("Psi5",&eventStats.Psi5);
//    fNt->setBranchAddress("Ecc5",&eventStats.Ecc5);
//    return 1;
//  }
//  if ((!inf)||(!fNt&&!calc)) {
//    cerr << "readNextEvent was not initialized" <<endl;
//    return 0;
//  }
//  TObjArray *arr = dynamic_cast<TObjArray*>(inf->get(Form("nucleonarray%d",iev)));
//  if (!arr) {
//    if (iev==0) {
//      cerr << "readNextEvent could not read nucleon array for event " << iev << endl;
//      return 0;
//    }
//    iev = 0;
//    cerr << "readNextEvent GlauberNucleonting to first event" << endl;
//    arr = dynamic_cast<TObjArray*>(inf->get(Form("nucleonarray%d",iev)));
//  }
//
//  Double_t impactParA=0, impactParB=0;
//  Int_t inA=0, inB=0;
//  const Int_t nNucls = arr->getEntries();
//  for (Int_t iNucl=0; iNucl<nNucls; ++iNucl) {
//    GlauberNucleon *nuclinp = static_cast<GlauberNucleon*>(arr->At(iNucl));
//    GlauberNucleon *nuclout = 0;
//    if (nuclinp->isInNucleusB()) {
//      nuclout = static_cast<GlauberNucleon*>(nucleonsB->At(inB));
//      impactParB += nuclinp->getX();
//      ++inB;
//    } else {
//      nuclout = static_cast<GlauberNucleon*>(nucleonsA->At(inA));
//      impactParA += nuclinp->getX();
//      ++inA;
//    }
//    nuclout->GlauberNucleon();
//    nuclout->setXYZ(nuclinp->getX(),nuclinp->getY(),nuclinp->getZ());
//    nuclout->setNucleonType(nuclinp->getNucleonType());
//    nuclout->setEnergy(nuclinp->getEnergy());
//    if (!calc)
//      nuclout->setNBinaryCollisions(nuclinp->getNBinaryCollisions());
//  }
//  delete arr;
//  Double_t impactPar = impactParB/inB-impactParA/inA;
//  if (calc) {
//    Bool_t ret = calculateEvent(impactPar);
//    if (0)
//      cout << iev << ": " << eventStats.B << " " << eventStats.nParticipants << " " << eventStats.nCollisions << " " << eventStats.nParticipants0 << endl;
//    ++iev;
//    return ret;
//  }
//  Int_t ret = fNt->getEntry(iev);
//  if (ret<=0)
//    return 0;
//  fEccN[1]=eventStats.Ecc1;
//  fEccN[2]=eventStats.Ecc2;
//  fEccN[3]=eventStats.Ecc3;
//  fEccN[4]=eventStats.Ecc4;
//  fEccN[5]=eventStats.Ecc5;
//  if (0)
//    cout << iev << ": " << eventStats.B << " " << eventStats.nParticipants << " " << eventStats.nCollisions << " " << eventStats.nParticipants0 << endl;
//  if (0) { // test ntuple values vs re-calculated values
//    Double_t nParticipants = eventStats.nParticipants;
//    Double_t nCollisions = eventStats.nCollisions;
//    Double_t ecc2  = eventStats.Ecc2;
//    calculateEvent(impactPar);
//    if (nParticipants!=eventStats.nParticipants)
//      cout << iev << " differ in nParticipants " << nParticipants << " " << eventStats.nParticipants << endl;
//    if (nCollisions!=eventStats.nCollisions)
//      cout << iev << " differ in nCollisions " << nCollisions << " " << eventStats.nCollisions << endl;
//    if (TMath::Abs(ecc2-eventStats.Ecc2)>0.001)
//      cout << iev << " differ in ecc2 " << ecc2 << " " << eventStats.Ecc2 << endl;
//  }
//  ++iev;
//  return 1;
//}

void GlauberMC::run(Int_t nevents, Double_t b)
{
  if (fNt == 0) {
    String name(Form("nt_%s_%s",nucleusA.getName(),nucleusB.getName()));
    String title(Form("%s + %s (x-sect = %.1f mb) str %s",nucleusA.getName(),nucleusB.getName(),fXSect,Str()));
    String vars("nParticipants:nCollisions:nHardCollisions:B:BNN:nCollisions_pp:nCollisions_pn:nCollisions_nn:VarX:VarY:VarXY:nParticipantsA:nParticipantsB:nParticipants0:AreaW");
    if (fDetail>1)
      vars+=":Psi1:Ecc1:Psi2:Ecc2:Psi3:Ecc3:Psi4:Ecc4:Psi5:Ecc5";
    if (fDetail>2)
      vars+=":AreaO:AreaA:X0:Y0:Phi0:Length";
    if (fDetail>3)
      vars+=":meanX:meanY:meanX2:meanY2:meanXY:meanXSystem:meanYSystem:meanXA:meanYA:meanXB:meanYB";
    if (fDetail>4)
      vars+=":PhiA:ThetaA:PhiB:ThetaB";
    fNt = new TNtuple(name,title,vars);
    fNt->setDirectory(0);
    TObjArray *l = fNt->getListOfBranches();
    for (Int_t i=0; i<l->getEntries(); ++i) {
      TBranch *br = dynamic_cast<TBranch*>(l->At(i));
      if (br)
        br->setCompressionLevel(9);
    }
  }

  for (Int_t i = 0; i<nevents; ++i) {
    while (!NextEvent(b)) {}
    fNt->Fill((Float_t*)(&eventStats.nParticipants));
    if ((i>0)&&(i%100)==0) 
      cout << "GlauberEventStat # " << i << " x-sect = " << getTotXSect() << " +- " << getTotXSectErr() << " b        \r" << flush;
  }
  if (nevents>99)
    cout << endl << "Done!" << endl;
}
#endif



