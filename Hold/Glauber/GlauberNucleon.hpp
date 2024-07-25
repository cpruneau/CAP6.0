#include "GlauberExceptions.hpp"
#include "MathConstants.hpp"
#include "Vector3.hpp"

namespace CAP
{

//!
//! Class defines  a nucleon for the purpose of MC Glauber simulations
//!
class GlauberNucleon
{
protected:
  Vector3    position;
  bool       nucleonType;        //! 0 = neutron, 1 = proton
  Bool_t     inNucleusA;         //! =1 from nucleus A, =0 from nucleus B
  Int_t      nBinaryCollisions;  //! Number of binary collisions
  Double32_t energy;             //! Energy
public:

  GlauberNucleon();
  GlauberNucleon(const GlauberNucleon & nucleon);
  GlauberNucleon operator=(const GlauberNucleon & nucleon);
  virtual   ~GlauberNucleon() {}

  void       collide()                                  {++nBinaryCollisions;}
  Double_t   get2CWeight(Double_t x) const              {return 2.*(0.5*(1-x)+0.5*x*nBinaryCollisions);}
  Double_t   getEnergy()             const              {return energy;}
  Int_t      getNBinaryCollisions()  const              {return nBinaryCollisions;}
  Int_t      getNucleonType()        const              {return nucleonType;}
  Bool_t     isNeutron()             const              {return (nucleonType==0);}
  Bool_t     isInNucleusA()          const              {return inNucleusA;}
  Bool_t     isInNucleusB()          const              {return !inNucleusA;}
  Bool_t     isProton()              const              {return (nucleonType==1);}
  Bool_t     isSpectator()           const              {return !nBinaryCollisions;}
  Bool_t     isWounded()             const              {return nBinaryCollisions>0;}
  const Vector3 & getPosition() const;
  Vector3 & getPosition();
  void       rotateXYZ(Double_t phi, Double_t theta);
  void       rotateXYZ_3D(Double_t psiX, Double_t psiY, Double_t psiZ);
  void       setEnergy(Double_t en)                     {energy = en;}
  void       setInNucleusA()                            {inNucleusA=1;}
  void       setInNucleusB()                            {inNucleusA=0;}
  void       setNBinaryCollisions(Int_t nc)             {nBinaryCollisions = nc;}
  void       setNucleonType(Bool_t b)                   {nucleonType = b;}
  void       setPosition(const Vector3 & position);
  void       reset();

  ClassDef(GlauberNucleon,1) // GlauberNucleon class
};

}


#endif



