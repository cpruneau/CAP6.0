#include "Aliases.hpp"
#include "GlauberNucleon.hpp"

class GlauberNucleus
{
  protected:
  unsigned int  nNucleons;
  unsigned int  nProtons;
  unsigned int  nNeutrons;
  unsigned int  nWounded;
  unsigned int  nHard;

  Double_t   radiusPar;                   //Parameters of function
    Double_t   widthPar;                   //Parameters of function (widthPar+nProtons=nNucleons)
    Double_t   wPar;                   //Parameters of function
    Double_t   radiusPar2;                  //Parameters of function (for p and n separately)
    Double_t   widthPar2;                  //Parameters of function (for p and n separately)
    Double_t   fW2;                  //Parameters of function (for p and n separately)
    Double_t   beta2;               //Beta2 (deformed nuclei)
    Double_t   beta4;               //Beta4 (deformed nuclei)
    Double_t   fMinDist;             //Minimum separation distance
    Double_t   fNodeDist;            //Average node distance (set to <=0 if you do not want the "crystal lattice")
    Double_t   fSmearing;            //Node smearing (relevant if fNodeDist>0)
    Int_t      recenteringMode;            //=1 by default (0=no recentering, 1=recenter all, 2=recenter displacing only one nucleon, 3=recenter by rotation)
    Int_t      latticeMode;             //=0 use HCP by default (1=PCS, 2=BCC, 3=FCC)
    Double_t   maxShift;                //Maximum magnitude of cms shift tolerated (99, ie all by default) 
    Int_t      radialDistType;                   //Type of radial distribution
    Int_t      nTrials;              //Store trials needed to complete nucleus
    Int_t      nNonSmearedNodes;          //Store number of non-smeared-node nucleons
    TF1*       function1;               //!Probability density function rho(r)
    TF1*       function2;               //!Probability density function rho(r) -> if set 1 is for p, 2 is for n
    TF2*       function3;               //!Probability density function rho(r,theta) for deformed nuclei
    vector<GlauberNucleon*> nucleons;            //!Array of nucleons
   
  Double_t   phiRotation;              //!Angle phi for nucleus
  Double_t   cosThetaRot;            //!Angle theta for nucleus
  Double_t   thetaRotation;            //!Angle theta for nucleus
  Double_t   xRotation;                //!Angle around X axis for nucleus
    Double_t   yRotation;                //!Angle around Y axis for nucleus
    Double_t   zRotation;                //!Angle around Z axis for nucleus
 //   Double_t   fNucArr[6000][20][3]; //!Array of events (max 6000), up to 20 nucleons (only for small nuclei), 3 coordinates
    Int_t      fNucCounter;          //!GlauberEventStat counter
    TBits     *isUsed;              //!Bits for lattice use
    Double_t   maxRadius;                //!maximum radius (15fm)
  Bool_t useHulthen;
    void       findNucleus(const char* name);
  Bool_t     testMinDistance(Int_t n, Double_t x, Double_t y, Double_t z) const;
  Bool_t     testMinDistance(Int_t n, const Vector3 & reference) const;

  public:
  GlauberNucleus();
  GlauberNucleus(const GlauberNucleus & nucleus);
  GlauberNucleus operator=(const GlauberNucleus & nucleus);
    GlauberNucleus(const char* iname="Pb", Int_t iN=0,
                   Double_t iR=0, Double_t ia=0,
                   Double_t iw=0, TF1* ifunc=0);
    virtual ~GlauberNucleus();
  
  using      TObject::Draw;

    void       Draw(Double_t xs, Int_t colp, Int_t cols);

  Double_t   getA()             const {return widthPar;}
    TF1*       getFunc1()         const {return getFuncP();}
    TF1*       getFunc2()         const {return getFuncN();}
    TF2*       getFunc3()         const {return getFuncDef();}
    TF1*       getFuncP()         const {return function1;}
    TF1*       getFuncN()         const {return function2;}
    TF2*       getFuncDef()       const {return function3;}
    Double_t   getMinDist()       const {return fMinDist;}
    Int_t      getN()             const {return nNucleons;}
    Double_t   getNodeDist()      const {return fNodeDist;}
  Int_t      getRecenter()      const {return recenteringMode;}
  Double_t   getR()             const {return radiusPar;}
  Double_t   getPhiRot()        const {return phiRotation;}
  Double_t   getThetaRot()      const {return thetaRotation;}
  Int_t      getTrials()        const {return nTrials;}
  Int_t      getNonSmeared()    const {return nNonSmearedNodes;}
  Double_t   getShiftMax()      const {return maxShift;}
  Double_t   getW()             const {return wPar;}
  Double_t   getXRot()          const {return xRotation;}
  Double_t   getYRot()          const {return yRotation;}
  Double_t   getZRot()          const {return zRotation;}

  const vector<GlauberNucleon*> getAllNucleons() const;
  vector<GlauberNucleon*> getAllNucleons();

    void       setWidthPar(Double_t ia, Double_t ia2=-1);
    void       setBeta(Double_t b2, Double_t b4); 
    void       setLattice(Int_t i)               {latticeMode=i;}
    void       setMinDist(Double_t min)          {fMinDist=min;}
    void       setN(Int_t in)                    {nNucleons=in;}
    void       setNodeDist(Double_t nd)          {fNodeDist=nd;}
    void       setRadiusPar(Double_t ir, Double_t ir2=-1);
    void       setRecenter(Int_t b)              {recenteringMode=b;}
    void       setShiftMax(Double_t s)           {maxShift=s;}
    void       setSmearing(Double_t s)           {fSmearing=s;}
    void       setWPar(Double_t iw);

  void selectType();
  void initialize();
  void generateNucleons();
  void positionNucleons();
  void resetNucleons();
  void clearNucleons();
  void reset();
  void clear();

  ClassDef(GlauberNucleus,1) // GlauberNucleus class
};


class GlauberNucleusDb
{
protected:

public:
};


#endif



