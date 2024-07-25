#include "GlauberNucleus.hpp"

ClassImp(CAP::GlauberNucleus)

namespace CAP
{

GlauberNucleus::GlauberNucleus()
:
{   }

GlauberNucleus::GlauberNucleus(const GlauberNucleus & nucleus)
:
{   }

GlauberNucleus GlauberNucleus::operator=(const GlauberNucleus & nucleus);
:
{   }

GlauberNucleus::GlauberNucleus(const char* iname,
                               Int_t iN, double iR, double ia, double iw, TF1* ifunc) :
TNamed(iname,""),
nNucleons(iN),radiusPar(iR),widthPar(ia),wPar(iw),radiusPar2(0),widthPar2(0),fW2(0),beta2(0),beta4(0),
fMinDist(0.4),fNodeDist(0.0),fSmearing(0.0),recenteringMode(1),latticeMode(0),maxShift(99),
radialDistType(0),nTrials(0),nNonSmearedNodes(0),function1(ifunc),function2(0),function3(0),nucleons(0),
phiRotation(0),thetaRotation(0),fNucCounter(-1),isUsed(0),maxRadius(14)
{  }

GlauberNucleus::~GlauberNucleus()
{
  clear();
}

const vector<GlauberNucleon*> getAllNucleons() const
{
  return nucleons;

}
vector<GlauberNucleon*> getAllNucleons()
{
  return nucleons;
}


void GlauberNucleus::resetNucleons()
{
  for (auto & nucleon : nucleons) nucleon->reset();
}

void GlauberNucleus::clearNucleons()
{
  for (auto & nucleon : nucleons) delete nucleon;
  nucleons.clear();
}

void GlauberNucleus::reset()
{
  resetNucleons();
  nWounded = 0;
  nHard    = 0;
}

void GlauberNucleus::clear()
{
  clearNucleons();
  if (isUsed)    delete isUsed;
  if (function1) delete function1;
  if (function2) delete function2;
  if (function3) delete function3;
}

// Create the required array of nucleons
// which will be used and reused.
void GlauberNucleus::generateNucleons()
{
  for (unsigned int i=0; i<nNucleons; ++i)
    {
    GlauberNucleon * nucleon = new GlauberNucleon();
    nucleon->setNucleonType(i<nProtons);
    nucleons.push_back(nucleon);
    }
}


void GlauberNucleus::positionNucleons()
{
  using CAP::Math::pi();
  using CAP::Math::twoPi();
  bool done = false;

  double radius;
  double phi;
  double cphi;
  double sphi;
  double theta;
  double ctheta;
  double sthetaP;

  if (nNucleons==1)
    {
    //special treatment for proton
    radius  = function1->getRandom();
    phi     = gRandom->Rndm()*twoPi();
    cphi    = TMath::Cos(phi);
    sphi    = TMath::Sin(phi);
    ctheta  = 2.0*gRandom->Rndm() - 1.0;
    sthetaP = radius * TMath::Sqrt(1.0-ctheta*ctheta);
    nucleons[0].setXYZ(sthetaP*cphi,sthetaP*sphi,radius*ctheta);
    done = true;
    continue;
    }
  else if (nNucleons==2)
    {
    // && useHulthen
    //special treatment for Hulten
    radius  = 0.5*function1->getRandom();
    phi     = gRandom->Rndm()*twoPi();
    cphi    = TMath::Cos(phi);
    sphi    = TMath::Sin(phi);
    ctheta  = 2.0*gRandom->Rndm() - 1.0;
    sthetaP = radius * TMath::Sqrt(1.0-ctheta*ctheta);
    nucleons[0].setXYZ(sthetaP*cphi,sthetaP*sphi,radius*ctheta);
    if (radialDistType==4)
      { // place opposite of 0
        nucleons[1].setXYZ(-position);
      }
    else
      {
      radius  = 0.5*function1->getRandom();
      phi     = gRandom->Rndm()*twoPi();
      cphi    = TMath::Cos(phi);
      sphi    = TMath::Sin(phi);
      ctheta  = 2.0*gRandom->Rndm() - 1.0;
      sthetaP = radius * TMath::Sqrt(1.0-ctheta*ctheta);
      nucleons[1].setXYZ(sthetaP*cphi,sthetaP*sphi,radius*ctheta);
      }
    done = true;
    continue;
    }
  //    else if (nNucleons > 2 && nNucleons < 20 && useNucleonsFromFile)
  //      {
  //      // if the first call, then read in the file configurations
  //      if (fNucCounter == -1)
  //        {
  //        // read in the ascii file into the array and step through the counter
  //        char filename[100] = "foo.dat";
  //        if (tmpname=="He3") {
  //          sprintf(filename,"he3_plaintext.dat");
  //        } else if (tmpname=="H3") {
  //          sprintf(filename,"h3_plaintext.dat");
  //        } else if (tmpname=="He4") {
  //          sprintf(filename,"he4_plaintext.dat");
  //        } else if (tmpname=="C") {
  //          sprintf(filename,"carbon_plaintext.dat");
  //        } else if (tmpname=="O") {
  //          sprintf(filename,"oxygen_plaintext.dat");
  //        }
  //
  //        fNucCounter=0;
  //        } // done reading in the file the first time
  //      if (fNucCounter > 5999) fNucCounter = 0;
  //      // change to loop over nNucleons nucleons!
  //      for (auto & nucleon : nucleons)
  //        {
  //        nucleon->setXYZ(fNucArr[fNucCounter][i][0],
  //                        fNucArr[fNucCounter][i][1],
  //                        fNucArr[fNucCounter][i][2]);
  //        nucleon->rotateXYZ(phiRotation,thetaRotation);
  //        }
  //      ++fNucCounter;
  //      nTrials = 1;
  //      }
  else
    { // all other nuclei
      int  nTrials = 0;
      const double startingEdge  = 20; // throw nucleons within a cube of this size (fm)
      const double startingEdgeX = startingEdge + fNodeDist*gRandom->Rndm() - 0.5*fNodeDist;
      const double startingEdgeY = startingEdge + fNodeDist*gRandom->Rndm() - 0.5*fNodeDist;
      const double startingEdgeZ = startingEdge + fNodeDist*gRandom->Rndm() - 0.5*fNodeDist;
      const Int_t nslots = 2*startingEdge/fNodeDist+1;
      if (fNodeDist>0)
        {
        if (fMinDist>fNodeDist)
          {
          cout << "Minimum distance (nucleon hard core diameter) ["
          << fMinDist << "] cannot be larger than the nodal spacing of the grid ["
          << fNodeDist << "]." << endl;
          cout << "Quitting...." << endl;
          throw GlauberException("Node Distance Issue", __FUNCTION__);
          }
        if (!isUsed)
          isUsed = new TBits(nslots*nslots*nslots);
        else
          isUsed->GlauberNucleonAllBits();
        }

      for (auto & nucleon : nucleons)
        {
        nucleon->reset();
        while (1)
          {
          ++nTrials;
          Bool_t nucleon_inside = 0;
          Vector3 smeared(999.0,999.0,999.0);
          Vector3 position(999.0,999.0,999.0);
          double x=999, xsmeared=999;
          double y=999, ysmeared=999;
          double z=999, zsmeared=999;
          if (radialDistType==5||
              radialDistType==7)
            { // the extended way, throw in a box and test the weight
              while (!nucleon_inside)
                {
                position.setXYZ(gRandom->Rndm(),gRandom->Rndm(),gRandom->Rndm());
                position *= 2.0;
                position -= 1.0;
                position *= (2.0*radiusPar);
                double perp     = position.perp();
                double theta    = position.theta();
                double cosTheta = position.cosTheta();
                double R        = position.modulus();
                double Rtheta   = radiusPar;
                if (radialDistType==5) Rtheta= radiusPar + wPar*cosTheta*cosTheta;
                if (radialDistType==7)
                  Rtheta = radiusPar*(1+beta2*ROOT::Math::sph_legendre(2,0,theta)+beta4*ROOT::Math::sph_legendre(4,0,theta));
                double prob = 1/(1+TMath::Exp((R-Rtheta)/widthPar));
                if (gRandom->Rndm()<prob) nucleon_inside=1;
                }
            }
          else if ((radialDistType==8) ||
                   (radialDistType==14))
            { // use TF2
              function3->getRandom2(radius,theta);
              phi     = gRandom->Rndm()*twoPi();
              cphi    = TMath::Cos(phi);
              sphi    = TMath::Sin(phi);
              ctheta  = TMath::Cos(theta);;
              stheta  = TMath::Sin(theta);;
              x = radius*stheta*cphi;
              y = radius*stheta*sphi;
              z = radius*ctheta;
            }
          else
            { // all other types
              TF1 *radialDistType = function1;
              if ((function2) && (nucleon->getNucleonType()==0))
                radialDistType = function2;
              if (fNodeDist<=0)
                { // "continuous" mode
                  radius  = radialDistType->getRandom();
                  phi     = gRandom->Rndm()*twoPi();
                  cphi    = TMath::Cos(phi);
                  sphi    = TMath::Sin(phi);
                  ctheta  = 2*gRandom->Rndm() - 1 ;
                  sthetaP = TMath::Sqrt(1-ctheta*ctheta);
                  x = radius*sthetaP*cphi;
                  y = radius*sthetaP*sphi;
                  z = radius*ctheta;
                }
              else
                { // "grid/lattice" mode
                  Int_t iNode = Int_t((2*startingEdge/fNodeDist)*gRandom->Rndm());
                  Int_t jNode = Int_t((2*startingEdge/fNodeDist)*gRandom->Rndm());
                  Int_t kNode = Int_t((2*startingEdge/fNodeDist)*gRandom->Rndm());
                  Int_t index=iNode*nslots*nslots+jNode*nslots+kNode;
                  if (isUsed->TestBitNumber(index))
                    continue;
                  if (latticeMode==1)
                    {       // Primitive cubic system (PCS) -> https://en.wikipedia.org/wiki/Cubic_crystal_system
                      x = fNodeDist*(iNode) - startingEdgeX;
                      y = fNodeDist*(jNode) - startingEdgeY;
                      z = fNodeDist*(kNode) - startingEdgeZ;
                    }
                  else if (latticeMode==2)
                    { //Body centered cubic (BCC) -> http://mathworld.wolfram.com/CubicClosePacking.html
                      x = 0.5*fNodeDist*(-iNode+jNode+kNode) - 0.5*startingEdgeX;
                      y = 0.5*fNodeDist*(+iNode-jNode+kNode) - 0.5*startingEdgeY;
                      z = 0.5*fNodeDist*(+iNode+jNode-kNode) - 0.5*startingEdgeZ;
                    }
                  else if (latticeMode==3)
                    { //Face Centered Cubic (FCC) -> http://mathworld.wolfram.com/CubicClosePacking.html
                      x = 0.5*fNodeDist*(jNode+kNode) - startingEdgeX;
                      y = 0.5*fNodeDist*(iNode+kNode) - startingEdgeY;
                      z = 0.5*fNodeDist*(iNode+jNode) - startingEdgeZ;
                    }
                  else
                    {                  //Hexagonal close packing (HCP) -> https://en.wikipedia.org/wiki/Close-packing_of_equal_spheres
                      x = 0.5*fNodeDist*(2*iNode+((jNode+kNode)%2))          - startingEdgeX;
                      y = 0.5*fNodeDist*(TMath::Sqrt(3)*(jNode+(kNode%2)/3)) - startingEdgeY;
                      z = 0.5*fNodeDist*(kNode*2*TMath::Sqrt(6)/3)           - startingEdgeZ;
                    }
                  const double r2 = x*x + y*y + z*z;
                  const double r  = TMath::Sqrt(r2);
                  if ((r>maxRadius)||(r2*gRandom->Rndm()>radialDistType->Eval(r))) continue;
                  if (fSmearing>0.0) 
                    {
                    Int_t nAttemptsToSmear = 0;
                    while (1) 
                      {
                      xsmeared = x*gRandom->Gaus(1.0,fSmearing);
                      ysmeared = y*gRandom->Gaus(1.0,fSmearing);
                      zsmeared = z*gRandom->Gaus(1.0,fSmearing);
                      nAttemptsToSmear++;
                      if (testMinDistance(i,xsmeared,ysmeared,zsmeared))
                        {
                        x = xsmeared;
                        y = ysmeared;
                        z = zsmeared;
                        break;
                        }
                      if (nAttemptsToSmear>=99)
                        {
                        cerr << "Could not place on this node :: [" << x <<","<< y <<","<< z <<"] r = " << TMath::Sqrt(x*x+y*y+z*z) << " fm; "
                        << "Node (" << iNode << "," << jNode << "," << kNode << ") not smeared !!!" << endl;
                        ++nNonSmearedNodes;
                        break;
                        }
                    }
                  }
                  isUsed->setBitNumber(index);
                } /* end "grid/lattice mode" */
            }
          nucleon->setXYZ(x,y,z);
          if (radialDistType==5||
              radialDistType==7||
              radialDistType==8||
              radialDistType==14)
            nucleon->rotateXYZ(phiRotation,thetaRotation); // Uranium etc.
          if (fNodeDist>0)
            {
            nucleon->rotateXYZ_3D(xRotation,yRotation,zRotation);
            break;
            }
          if (testMinDistance(i,x,y,z)) break;
          }
        }
    }
  nTrials++;
  if (nTrials >= nMaxTrials) throw Exception("To Many Iterations",__FUNCTION__);


  // calculate center of mass
  Vector3 sumXYZ = 0.0;
  for (auto & nucleon : nucleons) sumXYZ += nucleon->getPosition();
  sumXYZ /= double(nNucleons);
  Vector shift;
  Vector finalShift(xshift, 0.0, 0.0);
  if (sumXYZ.modulus()<maxShift) done = true;
  switch (recenteringMode)
    {
      case 1:
      {
      shift  = sumXYZ;
      break;
      }
      case 2:
      {
      GlauberNucleon & nucleon= *(nucleons[nNucleons-1]);
      Vector & position = nucleon.getPosition();
      position += sumXYZ;
      shift  = 0;
      break;
      }
      case 3:
      case 4:
      {
//      Vector3 zVec(0,0,1);
//      Vector shift(sumx,sumy,sumz);
//      Vector3 orthVec;
//      orthVec = shiftVec.Cross(zVec);
//      Rotation myRot;
//      myRot.Rotate(shiftVec.angle(zVec),orthVec);
//      Vector3 myNuc;
//      for (auto & nucleon : nucleons)
//        {
//        Vector3 & position = nucleon->position();
//        position.transform(myRot);
//        }
//      if (recenteringMode==3) fsumz = shiftVec.Mag();
      break;
      }
    }
  finalShift -= shift;
  for (auto & nucleon : nucleons)
    {
    Vector3 & position = nucleon->position();
    position += finalShift;
    }
  return finalShift;
}

void GlauberNucleus::selectType()
{

}

void GlauberNucleus::initialize()
{
  useHulthen = (radialDistType==3||radialDistType==4); // put that in the init
  String tmpname(getName());
  Bool_t useNucleonsFromFile = false;
  if ((tmpname=="He3") || (tmpname=="H3") ||
      (tmpname=="He4") || (tmpname=="C")   ||
      (tmpname=="O"))
    useNucleonsFromFile = true;
}

void GlauberNucleus::Draw(double xs, Int_t colp, Int_t cols)
{
  double r = 0.5*TMath::Sqrt(xs/CAP::Math::pi()/10.);
  TEllipse ellipse;
  ellipse.SetLineStyle(1);
  ellipse.SetLineWidth(1);
  ellipse.SetFillStyle(1001);
  for (auto & nucleon : nucleons)
  {
    if (nucleon->isSpectator())
    {
      ellipse.setFillColor(cols);
      ellipse.setFillStyle(1000);
      Vector3 & pos = nucleon->position;
      ellipse.DrawEllipse(pos.x(),pos.y(),r,r,0,360,0,"");
    }
    else
    {
      ellipse.setFillColor(colp);
      ellipse.DrawEllipse(pos.x(),pos.y(),r,r,0,360,0,"");
    }
  }
}

void GlauberNucleusDb::findNucleus(const String & name)
{
  setName(name);
  double r0=0, r1=0, r2=0;

  if      (name.EqualTo( "p" ))      {nNucleons = 1;   radiusPar = 0.234;      widthPar = 0;      wPar =  0;       radialDistType = 0;  nProtons=1;}
  else if (name.EqualTo( "pg" ))     {nNucleons = 1;   radiusPar = 0.514;      widthPar = 0;      wPar =  0;       radialDistType = 9;  nProtons=1;}
  else if (name.EqualTo( "pdg" ))    {nNucleons = 1;   radiusPar = 1;          widthPar = 0;      wPar =  0;       radialDistType = 10; nProtons=1;} // from arXiv:1101.5953
  else if (name.EqualTo( "dpf" ))    {nNucleons = 2;   radiusPar = 0.01;       widthPar = 0.5882; wPar =  0;       radialDistType = 1;  nProtons=1;} // deuteron 2pf (tuned to useHulthen)
  else if (name.EqualTo( "dh" ))     {nNucleons = 2;   radiusPar = 0.2283;     widthPar = 1.1765; wPar =  0;       radialDistType = 3;  nProtons=1;} // deuteron useHulthen free
  else if (name.EqualTo( "d" ))      {nNucleons = 2;   radiusPar = 0.2283;     widthPar = 1.1765; wPar =  0;       radialDistType = 4;  nProtons=1;} // deuteron useHulthen constrained
  else if (name.EqualTo( "He3" ))    {nNucleons = 3;   radiusPar = 0.00;       widthPar = 0.0000; wPar =  0;       radialDistType = 6;  nProtons=1;} // read configurations from file
  else if (name.EqualTo( "H3" ))     {nNucleons = 3;   radiusPar = 0.00;       widthPar = 0.0000; wPar =  0;       radialDistType = 6;  nProtons=2;} // read configurations from file
  else if (name.EqualTo( "He4" ))    {nNucleons = 4;   radiusPar = 0.00;       widthPar = 0.0000; wPar =  0;       radialDistType = 6;  nProtons=2;} // read configurations from file
  else if (name.EqualTo( "C" ))      {nNucleons = 12;  radiusPar = 2.608;      widthPar = 0.513;  wPar = -0.051;   radialDistType = 6;  nProtons=6;} // read configurations from file
  else if (name.EqualTo( "O"))       {nNucleons = 16;  radiusPar = 2.608;      widthPar = 0.513;  wPar = -0.051;   radialDistType = 6;  nProtons=8;} // read configurations from file
  else if (name.EqualTo( "Opar"))    {nNucleons = 16;  radiusPar = 2.608;      widthPar = 0.513;  wPar = -0.051;   radialDistType = 1;  nProtons=8;} // WS parameterization
  else if (name.EqualTo( "Oho" ))    {nNucleons = 16;  radiusPar = 1.833;      widthPar = 1.544;  wPar =  0;       radialDistType = 15; nProtons=8;} // Harmonic oscillator parameterization
  else if (name.EqualTo( "Al" ))     {nNucleons = 27;  radiusPar = 3.34;       widthPar = 0.580;  wPar = 0.0;      radialDistType = 8;  nProtons=13; beta2=-0.448; beta4=0.239;}
  else if (name.EqualTo( "Si" ))     {nNucleons = 28;  radiusPar = 3.34;       widthPar = 0.580;  wPar = -0.233;   radialDistType = 1;  nProtons=14;}
  else if (name.EqualTo( "Si2"))     {nNucleons = 28;  radiusPar = 3.34;       widthPar = 0.580;  wPar =  0;       radialDistType = 8;  nProtons=14; beta2=-0.478; beta4=0.250;}
  else if (name.EqualTo( "S" ))      {nNucleons = 32;  radiusPar = 2.54;       widthPar = 2.191;  wPar =  0.16;    radialDistType = 2;  nProtons=16;}
  else if (name.EqualTo( "Ar"))      {nNucleons = 40;  radiusPar = 3.53;       widthPar = 0.542;  wPar =  0;       radialDistType = 1;  nProtons=18;}
  else if (name.EqualTo( "Ca"))      {nNucleons = 40;  radiusPar = 3.766;      widthPar = 0.586;  wPar = -0.161;   radialDistType = 1;  nProtons=20;}
  else if (name.EqualTo( "Ni"))      {nNucleons = 58;  radiusPar = 4.309;      widthPar = 0.517;  wPar = -0.1308;  radialDistType = 1;  nProtons=28;}
  else if (name.EqualTo( "Cu"))      {nNucleons = 63;  radiusPar = 4.20;       widthPar = 0.596;  wPar =  0;       radialDistType = 1;  nProtons=29;}
  else if (name.EqualTo( "Curw"))    {nNucleons = 63;  radiusPar = 4.20;       widthPar = 0.596;  wPar =  0;       radialDistType = 12; nProtons=29; r0=1.00898; r1=-0.000790403; r2=-0.000389897;}
  else if (name.EqualTo( "Cu2"))     {nNucleons = 63;  radiusPar = 4.20;       widthPar = 0.596;  wPar =  0;       radialDistType = 8;  nProtons=29; beta2=0.162; beta4=-0.006;}
  else if (name.EqualTo( "Cu2rw"))   {nNucleons = 63;  radiusPar = 4.20;       widthPar = 0.596;  wPar =  0;       radialDistType = 14; nProtons=29; beta2=0.162; beta4=-0.006; r0=1.01269; r1=-0.00298083; r2=-9.97222e-05;}
  else if (name.EqualTo( "CuHN"))    {nNucleons = 63;  radiusPar = 4.28;       widthPar = 0.5;    wPar =  0;       radialDistType = 1;  nProtons=29;} // from arXiv:0904.4080v1
  else if (name.EqualTo( "Xe"))      {nNucleons = 129; radiusPar = 5.36;       widthPar = 0.59;   wPar =  0;       radialDistType = 1;  nProtons=54;} // adapted from arXiv:1703.04278
  else if (name.EqualTo( "Xes"))     {nNucleons = 129; radiusPar = 5.42;       widthPar = 0.57;   wPar =  0;       radialDistType = 1;  nProtons=54;} // scale from Sb (Antimony, A=122, r=5.32) by 1.019 = (129/122)**0.333
  else if (name.EqualTo( "Xe2"))     {nNucleons = 129; radiusPar = 5.36;       widthPar = 0.59;   wPar =  0;       radialDistType = 8;  nProtons=54; beta2=0.161; beta4=-0.003;} // adapted from arXiv:1703.04278 and Z. Physik (1974) 270: 113
  else if (name.EqualTo( "Xe2a"))    {nNucleons = 129; radiusPar = 5.36;       widthPar = 0.59;   wPar =  0;       radialDistType = 8;  nProtons=54; beta2=0.18; beta4=0;} // ALICE parameters (see public note from 2018 at https://cds.cern.ch/collection/ALICE%20Public%20Notes?ln=en)
  else if (name.EqualTo( "Xerw"))    {nNucleons = 129; radiusPar = 5.36;       widthPar = 0.59;   wPar =  0;       radialDistType = 12; nProtons=54; r0=1.00911; r1=-0.000722999; r2=-0.0002663;}
  else if (name.EqualTo( "Xesrw"))   {nNucleons = 129; radiusPar = 5.42;       widthPar = 0.57;   wPar =  0;       radialDistType = 12; nProtons=54; r0=1.0096; r1=-0.000874123; r2=-0.000256708;}
  else if (name.EqualTo( "Xe2arw"))  {nNucleons = 129; radiusPar = 5.36;       widthPar = 0.59;   wPar =  0;       radialDistType = 14; nProtons=54; beta2=0.18; beta4=0; r0=1.01246; r1=-0.0024851; r2=-5.72464e-05;}
  else if (name.EqualTo( "W"))       {nNucleons = 186; radiusPar = 6.58;       widthPar = 0.480;  wPar =  0;       radialDistType = 1;  nProtons=74;}
  else if (name.EqualTo( "Au"))      {nNucleons = 197; radiusPar = 6.38;       widthPar = 0.535;  wPar =  0;       radialDistType = 1;  nProtons=79;}
  else if (name.EqualTo( "Aurw"))    {nNucleons = 197; radiusPar = 6.38;       widthPar = 0.535;  wPar =  0;       radialDistType = 12; nProtons=79; r0=1.00899; r1=-0.000590908; r2=-0.000210598;}
  else if (name.EqualTo( "Au2"))     {nNucleons = 197; radiusPar = 6.38;       widthPar = 0.535;  wPar =  0;       radialDistType = 8;  nProtons=79; beta2=-0.131; beta4=-0.031; }
  else if (name.EqualTo( "Au2rw"))   {nNucleons = 197; radiusPar = 6.38;       widthPar = 0.535;  wPar =  0;       radialDistType = 14; nProtons=79; beta2=-0.131; beta4=-0.031; r0=1.01261; r1=-0.00225517; r2=-3.71513e-05;}
  else if (name.EqualTo( "AuHN"))    {nNucleons = 197; radiusPar = 6.42;       widthPar = 0.44;   wPar =  0;       radialDistType = 1;  nProtons=79;} // from arXiv:0904.4080v1
  else if (name.EqualTo( "Pb"))      {nNucleons = 208; radiusPar = 6.62;       widthPar = 0.546;  wPar =  0;       radialDistType = 1;  nProtons=82;}
  else if (name.EqualTo( "Pbrw"))    {nNucleons = 208; radiusPar = 6.62;       widthPar = 0.546;  wPar =  0;       radialDistType = 12; nProtons=82; r0=1.00863; r1=-0.00044808; r2=-0.000205872;} //only Pb 207 was tested but should be the same for 208
  else if (name.EqualTo( "Pb*"))     {nNucleons = 208; radiusPar = 6.624;      widthPar = 0.549;  wPar =  0;       radialDistType = 1;  nProtons=82;}
  else if (name.EqualTo( "PbHN"))    {nNucleons = 208; radiusPar = 6.65;       widthPar = 0.460;  wPar =  0;       radialDistType = 1;  nProtons=82;}
  else if (name.EqualTo( "Pbpn"))    {nNucleons = 208; radiusPar = 6.68;       widthPar = 0.447;  wPar =  0;       radialDistType = 11; nProtons=82; radiusPar2=6.69; widthPar2=0.56; fW2=0;}
  else if (name.EqualTo( "Pbpnrw"))  {nNucleons = 208; radiusPar = 6.68;       widthPar = 0.447;  wPar =  0;       radialDistType = 13; nProtons=82; radiusPar2=6.69; widthPar2=0.56; fW2=0;}
  // Uranium description taken from Heinz & Kuhlman, nucl-th/0411054.  In this code, radiusPar is defined as 6.8*0.91, wPar=6.8*0.26
  else if (name.EqualTo( "U"))       {nNucleons = 238; radiusPar = 6.188;      widthPar = 0.54;   wPar =  1.77;    radialDistType = 5;  nProtons=92;}
  else if (name.EqualTo( "U2"))      {nNucleons = 238; radiusPar = 6.67;       widthPar = 0.44;   wPar =  0;       radialDistType = 8;  nProtons=92; beta2=0.280; beta4=0.093;}
  else
    throw NucleusNotFoundGlauberException(name,__FUNCTION__);

  switch (radialDistType)
  {
    case 0: // Proton exp
      function1 = new TF1(name,"x*x*exp(-x/[0])",0,5);
      function1->setParameter(0,radiusPar);
      break;
    case 1: // 3pF
      function1 = new TF1(name,"x*x*(1+[2]*(x/[0])**2)/(1+exp((x-[0])/[1]))",0,maxRadius);
      function1->setParameters(radiusPar,widthPar,wPar);
      break;
    case 2: // 3pG
      function1 = new TF1(name,"x*x*(1+[2]*(x/[0])**2)/(1+exp((x**2-[0]**2)/[1]**2))",0,maxRadius);
      function1->setParameters(radiusPar,widthPar,wPar);
      break;
    case 3: // useHulthen (see nucl-ex/0603010)
    case 4: // same but constrain the neutron opposite to the proton event-by-event
      function1 = new TF1(name,"x*x*([0]*[1]*([0]+[1]))/(2*pi*(pow([0]-[1],2)))*pow((exp(-[0]*x)-exp(-[1]*x))/x,2)",0,maxRadius);
      function1->setParameters(radiusPar,widthPar);
      break;
    case 5: // Ellipsoid (Uranium)
      function1 = new TF1(name,"x*x*(1+[2]*(x/[0])**2)/(1+exp((x-[0])/[1]))",0,maxRadius);
      function1->setParameters(radiusPar,widthPar,0); // same as 3pF but setting W to zero
      break;
    case 6: // He3/H3
      function1 = 0; // read in file instead
      break;
    case 7: // Deformed nuclei, box method
#ifndef HAVE_MATHMORE
      throw NoMathMoreGlauberException(__FUNCTION__);;
#endif
      function1 = 0; // no func: only need beta parameters and use uniform box distribution
      break;
    case 8: // Deformed nuclei, TF2 method
      function3 = new TF2(name,"x*x*TMath::Sin(y)/(1+exp((x-[0]*(1+[2]*0.315*(3*pow(cos(y),2)-1.0)+[3]*0.105*(35*pow(cos(y),4)-30*pow(cos(y),2)+3)))/[1]))",0,maxRadius,0.0,CAP::Math::pi());
      function3->setNpx(120);
      function3->setNpy(120);
      function3->setParameters(radiusPar,widthPar,beta2,beta4);
      break;
    case 9: // Proton gaus
      function1 = new TF1(name,"x*x*exp(-x*x/[0]/[0]/2)",0,5);
      function1->setParameter(0,radiusPar);
      break;
    case 10: // Proton dgaus
      function1 = new TF1(name,"x*x*((1-[0])/[1]^3*exp(-x*x/[1]/[1])+[0]/(0.4*[1])^3*exp(-x*x/(0.4*[1])^2))",0,5);
      function1->setParameter(0,0.5);
      function1->setParameter(1,radiusPar);
      break;
    case 11: // 3pF for proton and neutrons
      function1 = new TF1(name,"x*x*(1+[2]*(x/[0])**2)/(1+exp((x-[0])/[1]))",0,maxRadius);
      function1->setParameters(radiusPar,widthPar,wPar);
      function2 = new TF1(name,"x*x*(1+[2]*(x/[0])**2)/(1+exp((x-[0])/[1]))",0,maxRadius);
      function2->setParameters(radiusPar2,widthPar2,fW2);
      break;
    case 12: // reweighted
      function1 = new TF1(name,"x*x*(1+[2]*(x/[0])**2)/(1+exp((x-[0])/[1]))/([3]+[4]*x+[5]*x^2)",0,maxRadius);
      function1->setParameters(radiusPar,widthPar,wPar,r0,r1,r2);
      recenteringMode=1;
      maxShift=0.1;
      break;
    case 13: // Pb for proton and neutrons reweighted
      function1 = new TF1(Form("%s_prot",name),"x*x*(1+[2]*(x/[0])**2)/(1+exp((x-[0])/[1]))/([3]+[4]*x+[5]*x^2)",0,maxRadius);
      function1->setParameters(radiusPar,widthPar,wPar,1.00866,-0.000461484,-0.000203571);
      function2 = new TF1(Form("%s_neut",name),"x*x*(1+[2]*(x/[0])**2)/(1+exp((x-[0])/[1]))/([3]+[4]*x+[5]*x^2)",0,maxRadius);
      function2->setParameters(radiusPar2,widthPar2,fW2,1.00866,-0.000461484,-0.000203571);
      recenteringMode=1;
      maxShift=0.1;
      break;
    case 14: // Deformed nuclei, TF2 method, reweighted
      function3 = new TF2(name,"x*x*TMath::Sin(y)/(1+exp((x-[0]*(1+[2]*0.315*(3*pow(cos(y),2)-1.0)+[3]*0.105*(35*pow(cos(y),4)-30*pow(cos(y),2)+3)))/[1]))/([4]+[5]*x+[6]*x^2)",0,maxRadius,0.0,CAP::Math::pi());
      function3->setNpx(120);
      function3->setNpy(120);
      function3->setParameters(radiusPar,widthPar,beta2,beta4,r0,r1,r2);
      recenteringMode=1;
      maxShift=0.1;
      break;
    case 15: // harmonic oscillator model
      function1 = new TF1(name,"x^2*(1+[0]*(x^2/[1]^2))*exp(-x^2/[1]^2)",0,maxRadius);
      function1->setParameters(radiusPar,widthPar);
      break;
    default:
    throw RadialTypeGlauberException(radialDistType,__FUNCTION__);
  }
  return;
}

void GlauberNucleusDb::setWidthPar(double _widthPar, double _widthPar2)
{
  widthPar  = _widthPar;
  widthPar2 = _widthPar2;
  switch (radialDistType)
  {
    case 1:  // 3pF
    case 12: // 3pF with pol2 normalization
    case 2:  // 3pG
    case 5:  // Ellipsoid (Uranium)
      function1->setParameter(1,widthPar);
      break;
    case 8:
      function3->setParameter(1,widthPar);
      break;
    case 11: //p&n
      function1->setParameter(1,widthPar);//proton
      function2->setParameter(1,widthPar2);//neutron
      break;
    default:
      throw ProfileGlauberException("widthPar not needed for function",__FUNCTION__);
  }
}

void GlauberNucleusDb::setBeta(double _beta2, double _beta4)
{
  beta2=_beta2;
  beta4=_beta4;
  if (function3) {
    function3->setParameter(2,beta2);
    function3->setParameter(3,beta4);
  }
}

void GlauberNucleusDb::setRadiusPar(double _radiusPar, double _radiusPar2)
{
  radiusPar  = _radiusPar;
  radiusPar2 = _radiusPar2;
  switch (radialDistType) {
    case 0:  // Proton exp
    case 9:  // Proton gaus
    case 1:  // 3pF
    case 12: // 3pF with pol2 normalization
    case 2:  // 3pG
    case 5:  // Ellipsoid (Uranium)
      function1->setParameter(0,radiusPar);
      break;
    case 8:
      function3->setParameter(0,radiusPar);
      break;
    case 10: // Proton
      function1->setParameter(1,radiusPar);
      break;
    case 11: // p&n
      function1->setParameter(0,radiusPar);//proton
      function2->setParameter(0,radiusPar2);//neutron
      break;
    default:
      throw ProfileGlauberException("radiusPar not needed for function",__FUNCTION__);
  }
}

void GlauberNucleusDb::setWPar(double _wPar)
{
  wPar = _wPar;
  switch (radialDistType) {
    case 1: // 3pF
    case 2: // 3pG
      function1->setParameter(2,wPar);
      break;
    default:
      throw ProfileGlauberException("wPar not needed for function",__FUNCTION__);
  }
}

Bool_t GlauberNucleus::testMinDistance(Int_t n, double x, double y, double z) const
{
  if (fMinDist<=0) return kTRUE;
  const double md2 = fMinDist*fMinDist;
  Vector3 reference(x,y,z);
  for (Int_t j = 0; j<n; ++j)
    {
    GlauberNucleon & nucleon = *(nucleons[j]);
    Vector3 position = nucleon.getPosition();
    position -= reference;
    if (position.modulusSquare()<md2) return kFALSE;
    }
  return kTRUE;
}

Bool_t GlauberNucleus::testMinDistance(Int_t n, const Vector3 & reference) const
{
  if (fMinDist<=0) return kTRUE;
  const double md2 = fMinDist*fMinDist;
  for (Int_t j = 0; j<n; ++j)
    {
    GlauberNucleon & nucleon = *(nucleons[j]);
    Vector3 position = nucleon.getPosition();
    position -= reference;
    if (position.modulusSquare()<md2) return kFALSE;
    }
  return kTRUE;
}


{
  cout << "Reading in " << filename << " for nucleon configurations with nNucleons = " << nNucleons << endl;
  ifstream myfile;
  myfile.open(filename);
  if (!myfile) throw NoNucleonConfigGlauberException(filename,__FUNCTION__);

  Int_t inputcounter = 0;
  while (myfile) {
    if (inputcounter > 5999) break;
    double foo;
    if (nNucleons == 3) {
      myfile >> fNucArr[inputcounter][0][0] >> fNucArr[inputcounter][0][1] >> fNucArr[inputcounter][0][2]
      >> fNucArr[inputcounter][1][0] >> fNucArr[inputcounter][1][1] >> fNucArr[inputcounter][1][2]
      >> fNucArr[inputcounter][2][0] >> fNucArr[inputcounter][2][1] >> fNucArr[inputcounter][2][2]
      >> foo >> foo >> foo >> foo;
    } else if (nNucleons == 4) {
      // no extra data with isospin information at the end of the nucleon configurations
      myfile >> fNucArr[inputcounter][0][0] >> fNucArr[inputcounter][0][1] >> fNucArr[inputcounter][0][2]
      >> fNucArr[inputcounter][1][0] >> fNucArr[inputcounter][1][1] >> fNucArr[inputcounter][1][2]
      >> fNucArr[inputcounter][2][0] >> fNucArr[inputcounter][2][1] >> fNucArr[inputcounter][2][2]
      >> fNucArr[inputcounter][3][0] >> fNucArr[inputcounter][3][1] >> fNucArr[inputcounter][3][2];
    } else if (nNucleons == 12) {
      // no extra data with isospin information at the end of the nucleon configurations
      // two extra words at the beginning --> foo foo
      myfile >> foo >> foo
      >> fNucArr[inputcounter][0][0] >> fNucArr[inputcounter][0][1] >> fNucArr[inputcounter][0][2]
      >> fNucArr[inputcounter][1][0] >> fNucArr[inputcounter][1][1] >> fNucArr[inputcounter][1][2]
      >> fNucArr[inputcounter][2][0] >> fNucArr[inputcounter][2][1] >> fNucArr[inputcounter][2][2]
      >> fNucArr[inputcounter][3][0] >> fNucArr[inputcounter][3][1] >> fNucArr[inputcounter][3][2]
      >> fNucArr[inputcounter][4][0] >> fNucArr[inputcounter][4][1] >> fNucArr[inputcounter][4][2]
      >> fNucArr[inputcounter][5][0] >> fNucArr[inputcounter][5][1] >> fNucArr[inputcounter][5][2]
      >> fNucArr[inputcounter][6][0] >> fNucArr[inputcounter][6][1] >> fNucArr[inputcounter][6][2]
      >> fNucArr[inputcounter][7][0] >> fNucArr[inputcounter][7][1] >> fNucArr[inputcounter][7][2]
      >> fNucArr[inputcounter][8][0] >> fNucArr[inputcounter][8][1] >> fNucArr[inputcounter][8][2]
      >> fNucArr[inputcounter][9][0] >> fNucArr[inputcounter][9][1] >> fNucArr[inputcounter][9][2]
      >> fNucArr[inputcounter][10][0] >> fNucArr[inputcounter][10][1] >> fNucArr[inputcounter][10][2]
      >> fNucArr[inputcounter][11][0] >> fNucArr[inputcounter][11][1] >> fNucArr[inputcounter][11][2];
    } else if (nNucleons == 16) {
      // no extra data with isospin information at the end of the nucleon configurations
      myfile >> fNucArr[inputcounter][0][0] >> fNucArr[inputcounter][0][1] >> fNucArr[inputcounter][0][2]
      >> fNucArr[inputcounter][1][0] >> fNucArr[inputcounter][1][1] >> fNucArr[inputcounter][1][2]
      >> fNucArr[inputcounter][2][0] >> fNucArr[inputcounter][2][1] >> fNucArr[inputcounter][2][2]
      >> fNucArr[inputcounter][3][0] >> fNucArr[inputcounter][3][1] >> fNucArr[inputcounter][3][2]
      >> fNucArr[inputcounter][4][0] >> fNucArr[inputcounter][4][1] >> fNucArr[inputcounter][4][2]
      >> fNucArr[inputcounter][5][0] >> fNucArr[inputcounter][5][1] >> fNucArr[inputcounter][5][2]
      >> fNucArr[inputcounter][6][0] >> fNucArr[inputcounter][6][1] >> fNucArr[inputcounter][6][2]
      >> fNucArr[inputcounter][7][0] >> fNucArr[inputcounter][7][1] >> fNucArr[inputcounter][7][2]
      >> fNucArr[inputcounter][8][0] >> fNucArr[inputcounter][8][1] >> fNucArr[inputcounter][8][2]
      >> fNucArr[inputcounter][9][0] >> fNucArr[inputcounter][9][1] >> fNucArr[inputcounter][9][2]
      >> fNucArr[inputcounter][10][0] >> fNucArr[inputcounter][10][1] >> fNucArr[inputcounter][10][2]
      >> fNucArr[inputcounter][11][0] >> fNucArr[inputcounter][11][1] >> fNucArr[inputcounter][11][2]
      >> fNucArr[inputcounter][12][0] >> fNucArr[inputcounter][12][1] >> fNucArr[inputcounter][12][2]
      >> fNucArr[inputcounter][13][0] >> fNucArr[inputcounter][13][1] >> fNucArr[inputcounter][13][2]
      >> fNucArr[inputcounter][14][0] >> fNucArr[inputcounter][14][1] >> fNucArr[inputcounter][14][2]
      >> fNucArr[inputcounter][15][0] >> fNucArr[inputcounter][15][1] >> fNucArr[inputcounter][15][2];
    }
    ++inputcounter;
  }
  myfile.close();
}

#endif



} // namespace CAP
