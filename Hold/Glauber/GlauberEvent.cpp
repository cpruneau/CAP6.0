#include "Glauber.hpp"

ClassImp(CAP::GlauberEventStat)

namespace CAP
{


Moments2D::Moments2D()
:
sum(0.0),
xSum(0.0),
ySum(0.0),
x2Sum(0.0),
y2Sum(0.0),
xySum(0.0),
meanX(0.0),
meanY(0.0),
meanX2(0.0),
meanY2(0.0),
meanXY(0.0),
varX(0.0),
varY(0.0),
varXY(0.0)
{    }

Moments2D::Moments2D(const Moments2D & source)
:
sum(source.sum),
xSum(source.xSum),
ySum(source.ySum),
x2Sum(source.x2Sum),
y2Sum(source.y2Sum),
xySum(source.xySum),
meanX(source.meanX),
meanY(source.meanY),
meanX2(source.meanX2),
meanY2(source.meanY2),
meanXY(source.meanXY),
varX(source.varX),
varY(source.varY),
varXY(source.varXY)
{    }

Moments2D Moments2D::operator=(const Moments2D & source)
{
  if (this!=&source)
    {
    sum    =  source.sum;
    xSum   =  source.xSum;
    ySum   =  source.ySum;
    x2Sum  =  source.x2Sum;
    y2Sum  =  source.y2Sum;
    xySum  =  source.xySum;
    meanX  =  source.meanX;
    meanY  =  source.meanY;
    meanX2 =  source.meanX2;
    meanY2 =  source.meanY2;
    meanXY =  source.meanXY;
    varX   =  source.varX;
    varY   =  source.varY;
    varXY  =  source.varXY;
    }
  return *this;
}


Moments2D::~Moments2D()
{ }

void Moments2D::fill(double x, double y, double weight)
{
  sum   +=  weight;
  xSum  +=  x*weight;
  ySum  +=  y*weight;
  x2Sum +=  x*x*weight;
  y2Sum +=  y*y*weight;
  xySum +=  x*y*weight;
}

void Moments2D::calculateMoments()
{
  if (sum>0)
    {
    meanX  =  xSum/sum;
    meanY  =  xSum/sum;
    meanX2 =  x2Sum/sum;
    meanY2 =  y2Sum/sum;
    meanXY =  xySum/sum;
    varX   =  meanX2 - meanX*meanX;
    varY   =  meanX2 - meanY*meanY;
    varXY  =  meanXY - meanX*meanY;
    }
}



GlauberEventStat::GlauberEventStat()
:
nParticipants(0),
nCollisions(0),
nHardCollisions(0),
B(0),
BNN(0),
nCollisions_pp(0),
nCollisions_pn(0),
nCollisions_nn(0),
VarX(0),
VarY(0),
VarXY(0),
nParticipantsA(0),
nParticipantsB(0),
nParticipants0(0),
AreaW(0),
Psi1(0),
Ecc1(0),
Psi2(0),
Ecc2(0),
Psi3(0),
Ecc3(0),
Psi4(0),
Ecc4(0),
Psi5(0),
Ecc5(0),
AreaA(0),
AreaO(0),
X0(0),
Y0(0),
Phi0(0),
Length(0),
meanX(0),
meanY(0),
meanX2(0),
meanY2(0),
meanXY(0),
meanXSystem(0),
meanYSystem(0),
meanXA(0),
meanYA(0),
meanXB(0),
meanYB(0),
PhiA(0),
ThetaA(0),
PhiB(0),
ThetaB(0)
{  }

GlauberEventStat::GlauberEventStat(const GlauberEventStat & event)
:
nParticipants(event.nParticipants ),
nCollisions(event.nCollisions ),
nHardCollisions(event.nHardCollisions ),
B(event.B ),
BNN(event.BNN ),
nCollisions_pp(event.nCollisions_pp ),
nCollisions_pn(event.nCollisions_pn ),
nCollisions_nn(event.nCollisions_nn ),
VarX(event.VarX ),
VarY(event.VarY ),
VarXY(event.VarXY ),
nParticipantsA(event.nParticipantsA ),
nParticipantsB(event.nParticipantsB ),
nParticipants0(event.nParticipants0 ),
AreaW(event.AreaW ),
Psi1(event.Psi1 ),
Ecc1(event.Ecc1 ),
Psi2(event.Psi2 ),
Ecc2(event.Ecc2 ),
Psi3(event.Psi3 ),
Ecc3(event.Ecc3 ),
Psi4(event.Psi4 ),
Ecc4(event.Ecc4 ),
Psi5(event.Psi5 ),
Ecc5(event.Ecc5 ),
AreaA(event.AreaA ),
AreaO(event.AreaO ),
X0(event.X0 ),
Y0(event.Y0 ),
Phi0(event.Phi0 ),
Length(event.Length ),
meanX(event.meanX ),
meanY(event.meanY ),
meanX2(event.meanX2 ),
meanY2(event.meanY2 ),
meanXY(event.meanXY ),
meanXSystem(event.meanXSystem ),
meanYSystem(event.meanYSystem ),
meanXA(event.meanXA ),
meanYA(event.meanYA ),
meanXB(event.meanXB ),
meanYB(event.meanYB ),
PhiA(event.PhiA ),
ThetaA(event.ThetaA ),
PhiB(event.PhiB ),
ThetaB(event.ThetaB)
{  }


GlauberEventStat & GlauberEventStat::operator=const GlauberEventStat & event)
{
  if (this!=&event)
  {
    nParticipants =   event.nParticipants;
    nCollisions =   event.nCollisions;
    nHardCollisions =   event.nHardCollisions;
    B =   event.B;
    BNN =   event.BNN;
    nCollisions_pp =   event.nCollisions_pp;
    nCollisions_pn =   event.nCollisions_pn;
    nCollisions_nn =   event.nCollisions_nn;
    VarX =   event.VarX;
    VarY =   event.VarY;
    VarXY =   event.VarXY;
    nParticipantsA =   event.nParticipantsA;
    nParticipantsB =   event.nParticipantsB;
    nParticipants0 =   event.nParticipants0;
    AreaW =   event.AreaW;
    Psi1 =   event.Psi1;
    Ecc1 =   event.Ecc1;
    Psi2 =   event.Psi2;
    Ecc2 =   event.Ecc2;
    Psi3 =   event.Psi3;
    Ecc3 =   event.Ecc3;
    Psi4 =   event.Psi4;
    Ecc4 =   event.Ecc4;
    Psi5 =   event.Psi5;
    Ecc5 =   event.Ecc5;
    AreaA =   event.AreaA;
    AreaO =   event.AreaO;
    X0 =   event.X0;
    Y0 =   event.Y0;
    Phi0 =   event.Phi0;
    Length =   event.Length;
    meanX =   event.meanX;
    meanY =   event.meanY;
    meanX2 =   event.meanX2;
    meanY2 =   event.meanY2;
    meanXY =   event.meanXY;
    meanXSystem =   event.meanXSystem;
    meanYSystem =   event.meanYSystem;
    meanXA =   event.meanXA;
    meanYA =   event.meanYA;
    meanXB =   event.meanXB;
    meanYB =   event.meanYB;
    PhiA =   event.PhiA;
    ThetaA =   event.ThetaA;
    PhiB =   event.PhiB;
    ThetaB =   event.ThetaB;
  }
}

void GlauberEventStat::print(std::ofstream &output, int option)
{
  printItem("nParticipants",nParticipants,output,option);
  printItem("nCollisions",nCollisions,output,option);
  printItem("nHardCollisions",nHardCollisions,output,option);
  printItem("B",B,output,option);
  printItem("BNN",BNN,output,option);
  printItem("nCollisions_pp",nCollisions_pp,output,option);
  printItem("nCollisions_pn",nCollisions_pn,output,option);
  printItem("nCollisions_nn",nCollisions_nn,output,option);
  printItem("VarX",VarX,output,option);
  printItem("VarY",VarY,output,option);
  printItem("VarXY",VarXY,output,option);
  printItem("nParticipantsA",nParticipantsA,output,option);
  printItem("nParticipantsB",nParticipantsB,output,option);
  printItem("nParticipants0",nParticipants0,output,option);
  printItem("AreaW",AreaW,output,option);
  printItem("Psi1",Psi1,output,option);
  printItem("Ecc1",Ecc1,output,option);
  printItem("Psi2",Psi2,output,option);
  printItem("Ecc2",Ecc2,output,option);
  printItem("Psi3",Psi3,output,option);
  printItem("Ecc3",Ecc3,output,option);
  printItem("Psi4",Psi4,output,option);
  printItem("Ecc4",Ecc4,output,option);
  printItem("Psi5",Psi5,output,option);
  printItem("Ecc5",Ecc5,output,option);
  printItem("AreaA",AreaA,output,option);
  printItem("AreaO",AreaO,output,option);
  printItem("X0",X0,output,option);
  printItem("Y0",Y0,output,option);
  printItem("Phi0",Phi0,output,option);
  printItem("Length",Length,output,option);
  printItem("meanX",meanX,output,option);
  printItem("meanY",meanY,output,option);
  printItem("meanX2",meanX2,output,option);
  printItem("meanY2",meanY2,output,option);
  printItem("meanXY",meanXY,output,option);
  printItem("meanXSystem",meanXSystem,output,option);
  printItem("meanYSystem",meanYSystem,output,option);
  printItem("meanXA",meanXA,output,option);
  printItem("meanYA",meanYA,output,option);
  printItem("meanXB",meanXB,output,option);
  printItem("meanYB",meanYB,output,option);
  printItem("PhiA",PhiA,output,option);
  printItem("ThetaA",ThetaA,output,option);
  printItem("PhiB",PhiB,output,option);
  printItem("ThetaB",ThetaB,output,option);
}
