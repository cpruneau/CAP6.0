#include "Glauber.hpp"

//!
//!Class implements MC Glauber generator
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
    Double_t      fXSectEvent;     //eventStat value of Nucleon-nucleon cross section
  vector<GlauberNucleon> nucleonsA;
  vector<GlauberNucleon> nucleonsB;
  vector<GlauberNucleon> nucleonsAB;
   // TNtuple*      fNt;             //Ntuple for results (created, but not deleted)
    Int_t         eventStatents;         //Number of events with at least one collision
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
    eventStat         eventStat;  //Glauber event (results of calculation stored in tree)
    Bool_t        fBC[999][999];   //Array to record binary collision
    Bool_t        CalcResults(Double_t impactPar);
    Bool_t        calculateEvent(Double_t impactPar);

  public:
    GlauberMC(const char* NA = "Pb", const char* NB = "Pb", Double_t xsect = 42, Double_t xsectsigma=0);
//  virtual              ~GlauberMC() {delete fNt; fNt=0;}

    Double_t            CalcDens(TF1 &prof, Double_t xval, Double_t yval) const;
    void                Draw(Option_t* option="");
    Double_t            getB()                 const {return eventStat.B;}
    Double_t            getBNN()               const {return eventStat.BNN;}
    Double_t            getBmax()              const {return maxImpactPar;}
    Double_t            getBmin()              const {return minImpactPar;}
    Double_t            getEcc(Int_t i=2)      const {return fEccN[i];}
    Double_t            getHardFrac()          const {return fHardFrac;}
    Double_t            getmeanX()             const {return eventStat.meanX;}
    Double_t            getmeanXParts()        const {return eventStat.meanX;}
    Double_t            getmeanXSystem()       const {return eventStat.meanXSystem;}
    Double_t            getmeanY()             const {return eventStat.meanY;}
    Double_t            getmeanYParts()        const {return eventStat.meanY;}
    Double_t            getmeanYSystem()       const {return eventStat.meanYSystem;}
    Double_t            getPsi(Int_t i=2)      const {return fPsiN[i];}
    Double_t            getSx2()               const {return eventStat.VarX;}
    Double_t            getSxy()               const {return eventStat.VarXY;}
    Double_t            getSy2()               const {return eventStat.VarY;}
    Double_t            getTotXSect()          const;
    Double_t            getTotXSectErr()       const;
    Double_t            getXSectEvent()        const {return fXSectEvent;}
    Int_t               getNBinaryCollisions()             const {return eventStat.nCollisions;}
    Int_t               getNBinaryCollisionsnn()           const {return eventStat.nCollisions_nn;}
    Int_t               getNBinaryCollisionspn()           const {return eventStat.nCollisions_pn;}
    Int_t               getNBinaryCollisionspp()           const {return eventStat.nCollisions_pp;}
    Int_t               getnParticipants()             const {return eventStat.nParticipants;}
    Int_t               getnParticipants0()            const {return eventStat.nParticipants0;}
    Int_t               getnParticipantsA()            const {return eventStat.nParticipantsA;}
    Int_t               getnParticipantsB()            const {return eventStat.nParticipantsB;}
    Int_t               getnParticipantsFound()        const {return fMaxnParticipantsFound;}
    TF1*                getXSectDist()         const {return fPTot;}
    GlauberNucleus*       getNucleusA()                {return &nucleusA;}
    GlauberNucleus*       getNucleusB()                {return &nucleusB;}
  //  TNtuple*            getNtuple()            const {return fNt;}
  vector<GlauberNucleons*> & throwNucleons();
  vector<GlauberNucleons*> & getAllNucleons();
    const eventStat        &getEvent()             const {return eventStat;}
    const eventStat        *getEvent()                   {return &eventStat;}
    const GlauberNucleus* getNucleusA()          const {return &nucleusA;}
    const GlauberNucleus* getNucleusB()          const {return &nucleusB;}
    Bool_t              IsBC(Int_t i, Int_t j) const {return fBC[i][j];}
    //Bool_t              NextEvent(Double_t impactPar=-1);
//    Bool_t              readNextEvent(Bool_t calc=1, const char *fname=0);
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


ClassImp(GlauberMC)

GlauberM::GlauberMC()
{

}

GlauberMC::GlauberMC(const char* NA, const char* NB, Double_t xsect, Double_t xsectsigma)
:
nucleusA(NA),
nucleusB(NB),
fXSect(xsect),
fXSectOmega(0),
fXSectLambda(0),
fXSectEvent(0),
nucleonsA(0),
nucleonsB(0),
nucleonsAB(0),
fNt(0),
eventStatents(0),
nTotalEvents(0),
minImpactPar(0),
maxImpactPar(20),
fHardFrac(0.65),
fDetail(99),
fCalcArea(0),
fCalcLength(0),
fDoCore(0),
fDoAAGG(1),
fMaxnParticipantsFound(0),
f2Cx(0),
fPTot(0),
fNNProf(0),
eventStat()
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
}

GlauberMC::GlauberMC(const GlauberMC & glauberMC )
{

}

GlauberMC GlauberMC::operator=(const GlauberMC & glauberMC)
{
  if (this!=&glauberMC)
  {

  }
  return *this;
}


Bool_t GlauberMC::calculateEvent(Double_t impactPar)
{
  if (fNNProf) throw NNProfGlauberException("No NNProf defined",__FUNCTION__);

  for (auto & nucleonA : nucleonsA) nucleonA->setInNucleusA();
  for (auto & nucleonB : nucleonsB) nucleonB->setInNucleusB();
  vector<double> xsecA; xsecA.assigned(900,0.0);
  vector<double> xsecB; xsecB.assigned(900,0.0);
  Double_t xsecB[999] = {0};
  if (fPTot)
  {
    fXSectEvent = fPTot->getRandom();
    if (fDoAAGG)
    {
      for (auto vA : xsecA) vA = fPTot->getRandom();
      for (auto vB : xsecB) vB = fPTot->getRandom();
    }
    else
      fXSectEvent = fXSect;
  }
  // "ball" diameter = distance at which two balls interact
  Double_t d2 = (Double_t)fXSectEvent/(CAP::Math::pi()*10); // in fm^2
  Double_t bh = TMath::Sqrt(d2*fHardFrac);

    Double_t xmin=0,xmax=0;
    fNNProf->getRange(xmin,xmax);
    d2 = xmax*xmax;


  eventStat eventStat;
  memset(fBC,0,sizeof(Bool_t)*999*999);
  Int_t nc=0,nh=0;
  for (auto & nucleonB : nucleonsB)
  {
    Bool_t tB=nucleonB->getNucleonType();
    for (auto & nucleonA : nucleonsA)
    {

      Double_t dx = nucleonB->getX()-nucleonA->getX();
      Double_t dy = nucleonB->getY()-nucleonA->getY();
      Double_t dij = dx*dx+dy*dy;
      if (fDoAAGG && fPTot)	d2 = 0.5*(xsecA[j]+xsecB[i])/(CAP::Math::pi()*10);
      if (dij>d2) continue;
      Double_t bij = TMath::Sqrt(dij);
      Double_t val = fNNProf->Eval(bij);
      Double_t ran = gRandom->Uniform();
      if (ran>val) continue;
      nucleonB->collide();
      nucleonA->collide();
      fBC[i][j] = 1;
      eventStat.BNN  += bij;
      ++nc;
      if (bij<bh) ++nh;
      Bool_t tA=nucleonA->getNucleonType();
      if (tA!=tB)
        ++eventStat.nCollisions_pn;
      else if (tA==1)
        ++eventStat.nCollisions_pp;
      else
        ++eventStat.nCollisions_nn;
      if (nc==1)
      {
        eventStat.X0 = (nucleonA->getX()+nucleonB->getX())/2;
        eventStat.Y0 = (nucleonA->getY()+nucleonB->getY())/2;
      }
    }
  }
  eventStat.B = impactPar;
  ++nTotalEvents;
  if (nc>0)
  {
    ++eventStatents;
    eventStat.nCollisions     = nc;
    eventStat.nHardCollisions     = nh;
    eventStat.BNN      /= nc;
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

  for (auto & nucleonA : nucleonsA)
  {
    Double_t xA=nucleonA->position.x();
    Double_t yA=nucleonA->position.y();
    eventStat.meanXSystem  += xA;
    eventStat.meanYSystem  += yA;
    eventStat.meanXA  += xA;
    eventStat.meanYA  += yA;
    if (nucleonA->isWounded())
    {
      Double_t w = nucleonA->get2CWeight(f2Cx);
      ++eventStat.nParticipants;
      if (nucleonA->getNBinaryCollisions()==1)
        ++eventStat.nParticipants0;
      ++eventStat.nParticipantsA;
      sumW   += w;
      sumWA  += w;
      eventStat.meanX  += xA * w;
      eventStat.meanY  += yA * w;
      eventStat.meanX2 += xA * xA * w;
      eventStat.meanY2 += yA * yA * w;
      eventStat.meanXY += xA * yA * w;
    }
  }

  for (auto & nucleonB : nucleonsB)
  {
    Double_t xB=nucleonB->position.x();
    Double_t yB=nucleonB->position.y();
    Double_t xB=nucleonB->getX();
    Double_t yB=nucleonB->getY();
    eventStat.meanXSystem  += xB;
    eventStat.meanYSystem  += yB;
    eventStat.meanXB  += xB;
    eventStat.meanYB  += yB;
    if (nucleonB->isWounded()) {
      Double_t w = nucleonB->get2CWeight(f2Cx);
      ++eventStat.nParticipants;
      if (nucleonB->getNBinaryCollisions()==1) ++eventStat.nParticipants0;
      ++eventStat.nParticipantsB;
      sumW   += w;
      sumWB  += w;
      eventStat.meanX  += xB * w;
      eventStat.meanY  += yB * w;
      eventStat.meanX2 += xB * xB * w;
      eventStat.meanY2 += yB * yB * w;
      eventStat.meanXY += xB * yB * w;
    }
  }
  if (eventStat.nParticipants>0)
  {
    eventStat.meanX  /= sumW;
    eventStat.meanY  /= sumW;
    eventStat.meanX2 /= sumW;
    eventStat.meanY2 /= sumW;
    eventStat.meanXY /= sumW;
  } else {
    eventStat.meanX = 0;
    eventStat.meanY  = 0;
    eventStat.meanX2 = 0;
    eventStat.meanY2 = 0;
    eventStat.meanXY = 0;
  }

  if (nucleonsA.size()+nucleonsB.size()>0) {
    eventStat.meanXSystem /= (nucleonsA.size() + nucleonsB.size());
    eventStat.meanYSystem /= (nucleonsA.size() + nucleonsB.size());
  } else {
    eventStat.meanXSystem = 0;
    eventStat.meanYSystem = 0;
  }
  if (nucleonsA.size()>0) {
    eventStat.meanXA /= nucleonsA.size();
    eventStat.meanYA /= nucleonsA.size();
  } else {
    eventStat.meanXA = 0;
    eventStat.meanYA = 0;
  }
  if (nucleonsB.size()>0) {
    eventStat.meanXB /= nucleonsB.size();
    eventStat.meanYB /= nucleonsB.size();
  } else {
    eventStat.meanXB = 0;
    eventStat.meanYB = 0;
  }

  eventStat.VarX  = eventStat.meanX2-(eventStat.meanX*eventStat.meanX);
  eventStat.VarY  = eventStat.meanY2-(eventStat.meanY*eventStat.meanY);
  eventStat.VarXY = eventStat.meanXY-eventStat.meanX*eventStat.meanY;
  Double_t tmpa = eventStat.VarX*eventStat.VarY-eventStat.VarXY*eventStat.VarXY;
  if (tmpa<0) 
    eventStat.AreaW = -1;
  else 
    eventStat.AreaW = TMath::Sqrt(tmpa);

  if (eventStat.nParticipants>0)
  {
    // do full moments relative to meanX and meanY
    for (Int_t n = 1; n<10; ++n)
    {
      for (Int_t ia = 0; ia<nucleonsA.size(); ++ia) {
        GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(ia));
	if (nucleonA->getNBinaryCollisions()<=kNc) 
	  continue;
	Double_t xA=nucleonA->getX() - eventStat.meanX;
	Double_t yA=nucleonA->getY() - eventStat.meanY;
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
	Double_t xB=nucleonB->getX() - eventStat.meanX;
	Double_t yB=nucleonB->getY() - eventStat.meanY;
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
      cosphi[n] /= eventStat.nParticipants;
      sinphi[n] /= eventStat.nParticipants;
      rn[n] /= eventStat.nParticipants;
      if (rn[n]>0) {
	fPsiN[n] = (TMath::ATan2(sinphi[n],cosphi[n]) + CAP::Math::pi())/n;
        fEccN[n] = TMath::Sqrt(sinphi[n]*sinphi[n]+cosphi[n]*cosphi[n])/rn[n];
      } else {
	fPsiN[n] = -1;
	fEccN[n] = -1;
      }
    }
    if (!kNc) { //silly test but useful to catch errors 
      Double_t t=TMath::Sqrt(TMath::Power(eventStat.VarY-eventStat.VarX,2)+4.*eventStat.VarXY*eventStat.VarXY)/(eventStat.VarY+eventStat.VarX)/fEccN[2];
      if (t<0.99||t>1.01)
        cout << "Error: Expected t=1 but found t=" << t << endl;
    }
  }

  eventStat.B      = impactPar;
  eventStat.PhiA   = nucleusA.getPhiRot();
  eventStat.ThetaA = nucleusA.getThetaRot();
  eventStat.PhiB   = nucleusB.getPhiRot();
  eventStat.ThetaB = nucleusB.getThetaRot();
  eventStat.Psi1   = fPsiN[1];
  eventStat.Ecc1   = fEccN[1];
  eventStat.Psi2   = fPsiN[2];
  eventStat.Ecc2   = fEccN[2];
  eventStat.Psi3   = fPsiN[3];
  eventStat.Ecc3   = fEccN[3];
  eventStat.Psi4   = fPsiN[4];
  eventStat.Ecc4   = fEccN[4];
  eventStat.Psi5   = fPsiN[5];
  eventStat.Ecc5   = fEccN[5];

  if (fCalcArea) {
    const Int_t nbins=200;
    const Double_t ell=10;
    const Double_t da=2*ell*2*ell/nbins/nbins;
    const Double_t d2 = (Double_t)fXSectEvent/(CAP::Math::pi()*10); // in fm^2
    const Double_t r2 = d2/4.;
    const Double_t mx = eventStat.meanX;
    const Double_t my = eventStat.meanY;
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
    eventStat.AreaO = overlap1*da;
    eventStat.AreaA = overlap2*da;
  }

  if (fCalcLength) {
    const Double_t krhs = TMath::Sqrt(fXSectEvent/40./CAP::Math::pi());
    const Double_t ksg  = krhs/TMath::Sqrt(5);
    const Double_t kDL  = 0.1;
    TF1 rad("rad","2*pi/[0]/[0]*TMath::Exp(-x*x/(2.*[0]*[0]))",0.0,5*ksg); 
    rad.setParameter(0,ksg);
    const Double_t minval = rad.Eval(5*ksg);
    eventStat.Phi0         = gRandom->Uniform(0,TMath::TwoPi());
    Double_t kcphi0  = TMath::Cos(eventStat.Phi0);
    Double_t ksphi0  = TMath::Sin(eventStat.Phi0);
    Double_t x       = eventStat.X0;
    Double_t y       = eventStat.Y0;
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
    eventStat.Length = 2*i1a/i0a;
  }

  if (eventStat.nParticipants > fMaxnParticipantsFound)
    fMaxnParticipantsFound = eventStat.nParticipants;

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
  return (1.*eventStatents/nTotalEvents)*CAP::Math::pi()*maxImpactPar*maxImpactPar/100;
}

Double_t GlauberMC::getTotXSectErr() const
{
  return getTotXSect()/TMath::Sqrt((Double_t)eventStatents) * TMath::Sqrt(Double_t(1.-eventStatents/nTotalEvents));
}

TObjArray *GlauberMC::getAllNucleons()
{
  if (!nucleonsA || !nucleonsB) return 0;
  if (nucleonsAB) return nucleonsAB;

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
  if (impactPar<0) impactPar = TMath::Sqrt((maxImpactPar*maxImpactPar-minImpactPar*minImpactPar)*gRandom->Rndm()+minImpactPar*minImpactPar);
  nucleusA.generateNucleons(-impactPar/2.);
  nucleusB.generateNucleons(impactPar/2.);
  return calculateEvent(impactPar);
}

Bool_t GlauberMC::readNextEvent(Bool_t calc, const char *fname)
{
  static TFile *inf = 0;
  static Int_t iev  = 0;
  if (fname) {
    cout << "readNextEvent: setting up file " << fname << endl;
    delete inf;
    inf = TFile::Open(fname);
    if (!inf) 
      return 0;
    if (!nucleonsA) {
      nucleusA.generateNucleons();
      nucleonsA = nucleusA.getAllNucleons();
      nucleonsA.size() = nucleusA.getN();
      for (Int_t i = 0; i<nucleonsA.size(); ++i) {
	GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(i));
	nucleonA->setInNucleusA();
      }
    }
    if (!nucleonsB) {
      nucleusB.generateNucleons();
      nucleonsB = nucleusB.getAllNucleons();
      nucleonsB.size() = nucleusB.getN();
      for (Int_t i = 0; i<nucleonsB.size(); ++i) {
	GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(i));
	nucleonB->setInNucleusB();
      }
    }
    if (calc)
      return 1;
    fNt = dynamic_cast<TNtuple*>(inf->get(Form("nt_%s_%s",nucleusA.getName(),nucleusB.getName())));
    if (!fNt) {
      cerr << "readNextEvent: Could not find ntuple!" << endl;
      inf->ls();
      return 0;
    }
    fNt->setBranchAddress("nParticipants",&eventStat.nParticipants);
    fNt->setBranchAddress("nCollisions",&eventStat.nCollisions);
    fNt->setBranchAddress("B",&eventStat.B);
    fNt->setBranchAddress("BNN",&eventStat.BNN);
    fNt->setBranchAddress("VarX",&eventStat.VarX);
    fNt->setBranchAddress("VarY",&eventStat.VarY);
    fNt->setBranchAddress("VarXY",&eventStat.VarXY);
    fNt->setBranchAddress("nParticipantsA",&eventStat.nParticipantsA);
    fNt->setBranchAddress("nParticipantsB",&eventStat.nParticipantsB);
    fNt->setBranchAddress("nParticipants0",&eventStat.nParticipants0);
    fNt->setBranchAddress("Psi1",&eventStat.Psi1);
    fNt->setBranchAddress("Ecc1",&eventStat.Ecc1);
    fNt->setBranchAddress("Psi2",&eventStat.Psi2);
    fNt->setBranchAddress("Ecc2",&eventStat.Ecc2);
    fNt->setBranchAddress("Psi3",&eventStat.Psi3);
    fNt->setBranchAddress("Ecc3",&eventStat.Ecc3);
    fNt->setBranchAddress("Psi4",&eventStat.Psi4);
    fNt->setBranchAddress("Ecc4",&eventStat.Ecc4);
    fNt->setBranchAddress("Psi5",&eventStat.Psi5);
    fNt->setBranchAddress("Ecc5",&eventStat.Ecc5);
    return 1;
  }
  if ((!inf)||(!fNt&&!calc)) {
    cerr << "readNextEvent was not initialized" <<endl;
    return 0;
  }
  TObjArray *arr = dynamic_cast<TObjArray*>(inf->get(Form("nucleonarray%d",iev)));
  if (!arr) {
    if (iev==0) {
      cerr << "readNextEvent could not read nucleon array for event " << iev << endl;
      return 0;
    }
    iev = 0;
    cerr << "readNextEvent GlauberNucleonting to first event" << endl;
    arr = dynamic_cast<TObjArray*>(inf->get(Form("nucleonarray%d",iev)));
  }

  Double_t impactParA=0, impactParB=0;
  Int_t inA=0, inB=0;
  const Int_t nNucls = arr->getEntries();
  for (Int_t iNucl=0; iNucl<nNucls; ++iNucl) {
    GlauberNucleon *nuclinp = static_cast<GlauberNucleon*>(arr->At(iNucl));
    GlauberNucleon *nuclout = 0;
    if (nuclinp->isInNucleusB()) { 
      nuclout = static_cast<GlauberNucleon*>(nucleonsB->At(inB));
      impactParB += nuclinp->getX();
      ++inB;
    } else {
      nuclout = static_cast<GlauberNucleon*>(nucleonsA->At(inA));
      impactParA += nuclinp->getX();
      ++inA;
    }
    nuclout->GlauberNucleon();
    nuclout->setXYZ(nuclinp->getX(),nuclinp->getY(),nuclinp->getZ());
    nuclout->setNucleonType(nuclinp->getNucleonType());
    nuclout->setEnergy(nuclinp->getEnergy());
    if (!calc)
      nuclout->setNBinaryCollisions(nuclinp->getNBinaryCollisions());
  }
  delete arr;
  Double_t impactPar = impactParB/inB-impactParA/inA;
  if (calc) {
    Bool_t ret = calculateEvent(impactPar);
    if (0) 
      cout << iev << ": " << eventStat.B << " " << eventStat.nParticipants << " " << eventStat.nCollisions << " " << eventStat.nParticipants0 << endl;
    ++iev;
    return ret;
  }
  Int_t ret = fNt->getEntry(iev);
  if (ret<=0) 
    return 0;
  fEccN[1]=eventStat.Ecc1;
  fEccN[2]=eventStat.Ecc2;
  fEccN[3]=eventStat.Ecc3;
  fEccN[4]=eventStat.Ecc4;
  fEccN[5]=eventStat.Ecc5;
  if (0) 
    cout << iev << ": " << eventStat.B << " " << eventStat.nParticipants << " " << eventStat.nCollisions << " " << eventStat.nParticipants0 << endl;
  if (0) { // test ntuple values vs re-calculated values
    Double_t nParticipants = eventStat.nParticipants;
    Double_t nCollisions = eventStat.nCollisions;
    Double_t ecc2  = eventStat.Ecc2;
    calculateEvent(impactPar);
    if (nParticipants!=eventStat.nParticipants)
      cout << iev << " differ in nParticipants " << nParticipants << " " << eventStat.nParticipants << endl;
    if (nCollisions!=eventStat.nCollisions)
      cout << iev << " differ in nCollisions " << nCollisions << " " << eventStat.nCollisions << endl;
    if (TMath::Abs(ecc2-eventStat.Ecc2)>0.001)
      cout << iev << " differ in ecc2 " << ecc2 << " " << eventStat.Ecc2 << endl;
  }
  ++iev;
  return 1;
}

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
      if (br) br->setCompressionLevel(9);
    }
  }

  for (Int_t i = 0; i<nevents; ++i) {
    while (!NextEvent(b)) {}
    fNt->Fill((Float_t*)(&eventStat.nParticipants));
    if ((i>0)&&(i%100)==0) 
      cout << "eventStat # " << i << " x-sect = " << getTotXSect() << " +- " << getTotXSectErr() << " b        \r" << flush;
  }
  if (nevents>99)
    cout << endl << "Done!" << endl;
}





