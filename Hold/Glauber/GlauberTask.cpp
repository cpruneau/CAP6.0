#ifndef CAP__GlauberTask
#define CAP__GlauberTask
#include "Task.hpp"
#include "HistogramGroup.hpp"
#include "HistogramSet.hpp"

namespace CAP
{
#include "EventTask.hpp"

//---------------------------------------------------------------------------------
TF1 *getNNProf(Double_t snn=67.6, Double_t omega=0.4, Double_t G=1);

void runAndSaveNucleons(const Int_t n,
                        const char *sysA,
                        const char *sysB,           
                        const Double_t signn,
                        const Double_t sigwidth,
                        const Double_t mind,
                        const Bool_t verbose,
			const Double_t bmin,
			const Double_t bmax,
			const char *fname)
{
  GlauberMC *mcg=new GlauberMC(sysA,sysB,signn,sigwidth);
  mcg->SetMinDistance(mind);
  mcg->SetBmin(bmin);
  mcg->SetBmax(bmax);
  TFile *out=0;
  if (fname) out=new TFile(fname,"recreate",fname,9);

  for (Int_t ievent=0; ievent<n; ++ievent) {
    //get an event with at least one collision
    mcg->run(1);
    if (ievent%100==0) cout << "\r" << 100.*ievent/n << "% done" << flush;

    vector<GlauberNucleons*> & allNucleons = mcg->getAllNucleons();

    if (verbose) 
      {
      cout<<endl<<endl<<"EVENT NO: "<<ievent<<endl;
      cout<<"B = "<<mcg->getB()<<"  nParticipants = "<<mcg->getnParticipants()<<endl<<endl;
      printf("Nucleus\t X\t Y\t Z\tnCollisions\n");
      for (auto & nucleon : allNucleons) nucleon->print(cout);
      }
  }
  cout << endl << "Done!" << endl;
  if (out) {
    TNtuple *nt = mcg->getNtuple();
    nt->Write();
    if (verbose)
      out->ls();
    delete out;
  }
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
  mcg->SetMinDistance(mind);
  mcg->SetBmin(bmin);
  mcg->SetBmax(bmax);
  
  TFile *out = TFile::Open(fname,"recreate",fname,9);
  if (!out)
    return;
  TNtuple *nt = new TNtuple("nt","nt",
      "nParticipants:nCollisions:B:Psi1P:Ecc1P:Psi2P:Ecc2P:Psi3P:Ecc3P:Psi4P:Ecc4P:Psi5P:Ecc5P:Psi1G:Ecc1G:Psi2G:Ecc2G:Psi3G:Ecc3G:Psi4G:Ecc4G:Psi5G:Ecc5G:Sx2P:Sy2P:Sx2G:Sy2G");
  nt->SetDirectory(out);

  const Int_t NSAMP = 100;
  TF1 *rad = new TF1("rad","x*TMath::Exp(-x*x/(2.*[0]*[0]))",0.0,3*sigs);
  rad->SetParameter(0,sigs);

  for (Int_t ievent=0; ievent<n; ++ievent) {
    while (!mcg->NextEvent()) {}

    const GlauberNucleus *nucA   = mcg->getNucleusA();
    const vector<GlauberNucleon*> &nucleonsA = nucA->getAllNucleons();
    const Int_t AN             = nucA->getN();
    const GlauberNucleus *nucB   = mcg-> getNucleusB();
    const vector<GlauberNucleon*> &nucleonsB = nucB->getAllNucleons();
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
        if (!nucleonA->IsWounded())
          continue;
        Double_t sr = rad->getRandom();
        Double_t sp = gRandom->Uniform(-Math::pi(), +Math::pi());
        xvals[ni]   = nucleonA->getX() + sr*TMath::Cos(sp);
        yvals[ni]   = nucleonA->getY() + sr*TMath::Sin(sp);
        ++ni;
      }
      for (Int_t i = 0; i<BN; ++i) {
        GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(i));
        if (!nucleonB->IsWounded())
          continue;
        Double_t sr = rad->getRandom();
        Double_t sp = gRandom->Uniform(-Math::pi(), +Math::pi());
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
      psi[j] = (TMath::ATan2(sinphi[j],cosphi[j]) + Math::pi())/j;
      ecc[j] = TMath::Sqrt(sinphi[j]*sinphi[j] + cosphi[j]*cosphi[j]) / rn[j];
    }

    Float_t v[27]; Int_t i=0;
    v[i++] = mcg->getnParticipants();
    v[i++] = mcg->getnCollisions();
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


//---------------------------------------------------------------------------------
void GlauberMC::runAndCalcDens(const Int_t n,
		    const Double_t alpha,
		    const char *sysA,
		    const char *sysB,
		    const Double_t signn,
		    const Double_t mind,
		    const char *fname)
{
  // run Glauber and store per event a density profile in x and y, calculated from participant and binary positions
  // with relative weight given by alpha.

  GlauberMC *mcg = new GlauberMC(sysA,sysB,signn);
  mcg->SetMinDistance(mind);

  TFile *out = 0;
  TCanvas *c1 = 0;
  if (fname) {
    out = TFile::Open(fname,"recreate",fname,9);
    if (!out)
      return;
  } else {
    c1 = new TCanvas;
  }

  const Int_t NSAMP = 100;
  const Double_t wp = (1-alpha)/2;
  const Double_t wb = alpha;
  const Double_t sigs = TMath::Sqrt(signn/20/Math::pi()); //from arXiv::0711.3724


  TF1 *rad = new TF1("rad","x*TMath::Exp(-x*x/(2.*[0]*[0]))",0.0,3*sigs);
  rad->SetParameter(0,sigs);

  TH2F *h2f = new TH2F("h2f",";x (fm);y (fm)",121,-15.5,15.5,121,-15.5,15.5);
  h2f->SetStats(0);
  
  for (Int_t ievent=0; ievent<n; ++ievent) {
    while (!mcg->NextEvent()) {}
    h2f->GlauberNucleon();
    h2f->SetName(Form("Event_%d",ievent));
    h2f->SetTitle(Form("nParticipants=%d, nCollisions=%d",mcg->getnParticipants(), mcg->getnCollisions()));

    const GlauberNucleus *nucA   = mcg->getNucleusA();
    const vector<GlauberNucleon*> &nucleonsA = nucA->getAllNucleons();
    const Int_t AN             = nucA->getN();
    const GlauberNucleus *nucB   = mcg-> getNucleusB();
    const vector<GlauberNucleon*> &nucleonsB = nucB->getAllNucleons();
    const Int_t BN             = nucB->getN();

    for (Int_t i = 0; i<AN; ++i) {
      GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(i));
      if (!nucleonA->IsWounded())
	continue;
      Double_t xA=nucleonA->getX();
      Double_t yA=nucleonA->getY();
      for (Int_t s=0; s<NSAMP; ++s) {
	Double_t sr = rad->getRandom();
	Double_t sp = gRandom->Uniform(-Math::pi(), +Math::pi());
	h2f->Fill(xA+sr*TMath::Cos(sp),yA+sr*TMath::Sin(sp),wp);
      }
    }

    for (Int_t j = 0; j<BN; ++j) {
      GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(j));
      if (!nucleonB->IsWounded())
	continue;
      Double_t xB=nucleonB->getX();
      Double_t yB=nucleonB->getY();
      for (Int_t s=0; s<NSAMP; ++s) {
	Double_t sr = rad->getRandom();
	Double_t sp = gRandom->Uniform(-Math::pi(), +Math::pi());
	h2f->Fill(xB+sr*TMath::Cos(sp),yB+sr*TMath::Sin(sp),wp);
      }
    }

    if (alpha>0) {
      for (Int_t i = 0; i<AN; ++i) {
	GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(i));
	if (!nucleonA->IsWounded())
	  continue;
	Double_t xA=nucleonA->getX();
	Double_t yA=nucleonA->getY();
	for (Int_t j = 0; j<BN; ++j) {
	  GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(j));
	  if (!mcg->IsBC(i,j))
	    continue;
	  Double_t xB=nucleonB->getX();
	  Double_t yB=nucleonB->getY();
	  Double_t dX=(xA+xB)/2;
	  Double_t dY=(yA+yB)/2;
	  for (Int_t s=0; s<NSAMP; ++s) {
	    Double_t sr = rad->getRandom();
	    Double_t sp = gRandom->Uniform(-Math::pi(), +Math::pi());
	    h2f->Fill(dX+sr*TMath::Cos(sp),dY+sr*TMath::Sin(sp),wb);
	  }
	}
      }
    }
    h2f->Scale(1./h2f->Integral());
    if (out) {
      h2f->Write();
    } else {
      h2f->Draw("colz");
      c1->Update();
      gSystem->Sleep(1000);
    }
  }
  if (out) {
    out->Write();
    out->Close();
    delete out;
  }
}


//---------------------------------------------------------------------------------
  ClassImp(GlauberMC)

GlauberMC::GlauberMC(const char* NA, const char* NB, Double_t xsect, Double_t xsectsigma) :
  nucleusA(NA),nucleusB(NB),
  fXSect(xsect),fXSectOmega(0),fXSectLambda(0),fXSectEvent(0),
  nucleonsA(0),nucleonsB(0),fNucleons(0),
  nNucleonsA(0),nNucleonsB(0),fNt(0),
  eventStatsents(0),nTotalEvents(0),minImpactPar(0),maxImpactPar(20),fHardFrac(0.65),
  fDetail(99),fCalcArea(0),fCalcLength(0), fDoCore(0), fDoAAGG(1),
  fMaxnParticipantsFound(0),f2Cx(0),fPTot(0),fNNProf(0),
  eventStats()
{
  if (xsectsigma>0) {
    fXSectOmega = xsectsigma;
    fXSectLambda = 1;
    fPTot = new TF1("fPTot","((x/[2])/(x/[2]+[0]))*exp(-(((x/[2])/[0]-1 )**2)/([1]*[1]))/[2]",0,300);
    fPTot->SetParameters(fXSect,fXSectOmega,fXSectLambda);
    fPTot->SetNpx(1000);
    fXSectLambda = fXSect/fPTot->getHistogram()->getmean();
    cout << "final lambda=" << fXSectLambda << endl;
    fPTot->SetParameters(fXSect,fXSectOmega,fXSectLambda);
    cout << "final <sigma>=" << fPTot->getHistogram()->getmean() << endl;
  }

  String name(Form("Glauber_%s_%s",nucleusA.getName(),nucleusB.getName()));
  String title(Form("Glauber %s+%s Version",nucleusA.getName(),nucleusB.getName()));
  SetName(name);
  SetTitle(title);
}

Bool_t GlauberMC::calculateEvent(Double_t impactPar)
{
  vector<GlauberNucleons*> nucleonsA = nucleusA.getAllNucleons();
  vector<GlauberNucleons*> nucleonsB = nucleusB.getAllNucleons();
  for (auto & nucleonA : nucleonsA) nucleonA->SetInNucleusA();
  for (auto & nucleonB : nucleonsB) nucleonB->SetInNucleusB();
  vector<double> xsecA; xsecA.assign(nucleonsA.size(),0.0);
  vector<double> xsecB; xsecB.assign(nucleonsB.size(),0.0);

  if (fPTot) 
    {
    fXSectEvent = fPTot->getRandom();
    if (fDoAAGG) {
      for (auto value : xsecA) value = fPTot->getRandom();
      for (auto value : xsecB) value = fPTot->getRandom();
    }
  } else 
    fXSectEvent = fXSect;

  // "ball" diameter = distance at which two balls interact
  Double_t d2 = (Double_t)fXSectEvent/(Math::pi()*10); // in fm^2
  Double_t bh = TMath::Sqrt(d2*fHardFrac);
  if (fNNProf) {
    Double_t xmin=0,xmax=0;
    fNNProf->getRange(xmin,xmax);
    d2 = xmax*xmax;
  }
 memset(fBC,0,sizeof(Bool_t)*999*999);
  Int_t nCollisionsisions=0,nHardCollisions=0;

  for (auto & nucleonB : nucleonsB)
    {
    Bool_t tB = nucleonB->getType();
    for (auto & nucleonA : nucleonsA)
      {
      Bool_t tA = nucleonA->getType();
      Double_t dx = nucleonB->getX()-nucleonA->getX();
      Double_t dy = nucleonB->getY()-nucleonA->getY();
      Double_t dij = dx*dx+dy*dy;
      if (fDoAAGG && fPTot)
        d2 = 0.5*(xsecA[j]+xsecB[i])/(Math::pi()*10);
      if (dij>d2) continue;
      Double_t bij = TMath::Sqrt(dij);
      if (fNNProf) {
        Double_t val = fNNProf->Eval(bij);
        Double_t ran = gRandom->Uniform();
        if (ran>val) continue;
      }
      nucleonB->Collide();
      nucleonA->Collide();
      fBC[i][j] = 1;
      eventStats.BNN  += bij;
      ++nCollisionsisions;
      if (bij<bh) ++nHardCollisions;
      if (tA!=tB)
        ++eventStats.nCollisions_pn;
      else if (tA==1)
        ++eventStats.nCollisions_pp;
      else
        ++eventStats.nCollisions_nn;
      if (nCollisionsisions==1) {
        eventStats.X0 = (nucleonA->getX()+nucleonB->getX())/2;
        eventStats.Y0 = (nucleonA->getY()+nucleonB->getY())/2;
      }
    }
  }
  eventStats.B = impactPar;
  ++nTotalEvents;
  if (nCollisionsisions>0) 
    {
    ++eventStatsents;
    eventStats.nCollisions     = nCollisionsisions;
    eventStats.nHardCollisions     = nHardCollisions;
    eventStats.BNN      /= nCollisionsisions;
    return calcResults(impactPar);
  }
  return kFALSE;
}

Bool_t GlauberMC::calcResults(Double_t impactPar)
{
  // calc results for the given event
  Double_t sumW=0;
  Double_t sumWA=0;
  Double_t sumWB=0;

  Double_t sinphi[10] = {0};
  Double_t cosphi[10] = {0};
  Double_t rn[10]     = {0};

  const Int_t kNc = fDoCore; // used later for core/corona

  for (auto & nucleonA : nucleusA.getAllNucleons())
    {
    Vector3 & positionA = nucleonA->getPosition();
    eventStats.fillA(positionA.x(),positionA.y(),nucleonA->IsWounded(),nucleonA->getNCollisions(),nucleonA->get2CWeight(f2Cx))
    }
  for (auto & nucleonB : nucleusB.getAllNucleons())
    {
    Vector3 & positionB = nucleonB->getPosition();
    eventStats.fillB(positionB.x(),positionB.y(),nucleonB->IsWounded(),nucleonB->getNCollisions(),nucleonB->get2CWeight(f2Cx))
    }

}

  GlauberEventStat::fillA(double x, double y, bool wounded, int nColl, double weight)
  {
  meanXSystem  += x;
  meanYSystem  += y;
  meanXA  += x;
  meanYA  += y;
  if (wounded)
    {
    nParticipants0++;
    nParticipantsA++;
    sumW   += weight;
    sumWA  += weight;
    meanX  += x * weight;
    meanY  += y * w;
    meanX2 += x * x * weight;
    meanY2 += y * y * weight;
    meanXY += x * y * weight;
    }
  }

  GlauberEventStat::fillB(double x, double y, bool wounded, int nColl, double weight)
  {
  meanXSystem  += x;
  meanYSystem  += y;
  meanXB  += x;
  meanYB  += y;
  if (wounded)
    {
    nParticipants0++;
    nParticipantsB++;
    sumW   += weight;
    sumWB  += weight;
    meanX  += x * weight;
    meanY  += y * w;
    meanX2 += x * x * weight;
    meanY2 += y * y * weight;
    meanXY += x * y * weight;
    }
  }

GlauberEventStat::calculateMoments()
{
  if (nParticipants>0) {
    meanX  /= sumW;
    meanY  /= sumW;
    meanX2 /= sumW;
    meanY2 /= sumW;
    meanXY /= sumW;
  } else {
    meanX = 0;
    meanY  = 0;
    meanX2 = 0;
    meanY2 = 0;
    meanXY = 0;
  }

  if (nNucleonsA+nNucleonsB>0) {
    meanXSystem /= (nNucleonsA + nNucleonsB);
    meanYSystem /= (nNucleonsA + nNucleonsB);
  } else {
    meanXSystem = 0;
    meanYSystem = 0;
  }
  if (nNucleonsA>0) {
    meanXA /= nNucleonsA;
    meanYA /= nNucleonsA;
  } else {
    meanXA = 0;
    meanYA = 0;
  }
  if (nNucleonsB>0) {
    meanXB /= nNucleonsB;
    meanYB /= nNucleonsB;
  } else {
    meanXB = 0;
    eventStats.meanYB = 0;
  }

  VarX  = meanX2-(meanX*meanX);
  VarY  = meanY2-(meanY*meanY);
  VarXY = meanXY-meanX*meanY;
  Double_t tmpa = VarX*VarY-VarXY*VarXY;
  if (tmpa<0) 
    AreaW = -1;
  else 
    AreaW = TMath::Sqrt(tmpa);

  if (nParticipants>0) {
    // do full moments relative to meanX and meanY
    for (Int_t n = 1; n<10; ++n) {
      for (Int_t ia = 0; ia<nNucleonsA; ++ia) {
        GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(ia));
	if (nucleonA->getnCollisions()<=kNc) 
	  continue;
	Double_t xA=nucleonA->getX() - meanX;
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
      for (Int_t ib = 0; ib<nNucleonsB; ++ib) {
        GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(ib));
	if (nucleonB->getnCollisions()<=kNc) 
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
	fPsiN[n] = (TMath::ATan2(sinphi[n],cosphi[n]) + Math::pi())/n;
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
    const Double_t d2 = (Double_t)fXSectEvent/(Math::pi()*10); // in fm^2
    const Double_t r2 = d2/4.;
    const Double_t mx = eventStats.meanX;
    const Double_t my = eventStats.meanY;
    TH2D areaA("hAreaA",";x (fm);y (fm)",nbins,-ell,ell,nbins,-ell,ell);
    TH2D areaB("hAreaB",";x (fm);y (fm)",nbins,-ell,ell,nbins,-ell,ell);
    for (Int_t i = 0; i<nNucleonsA; ++i) {
      GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(i));
      if (!nucleonA->IsWounded())
        continue;
      if (nucleonA->getnCollisions()==kNc)
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
            areaA.SetBinContent(bin,1);
        }
      }
    }
    for (Int_t i = 0; i<nNucleonsB; ++i) {
      GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(i));
      if (!nucleonB->IsWounded())
        continue;
      if (nucleonB->getnCollisions()==kNc)
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
            areaB.SetBinContent(bin,1);
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
    const Double_t krhs = TMath::Sqrt(fXSectEvent/40./Math::pi());
    const Double_t ksg  = krhs/TMath::Sqrt(5);
    const Double_t kDL  = 0.1;
    TF1 rad("rad","2*pi/[0]/[0]*TMath::Exp(-x*x/(2.*[0]*[0]))",0.0,5*ksg); 
    rad.SetParameter(0,ksg);
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
  for (Int_t i = 0; i<nNucleonsA; ++i) {
    GlauberNucleon *nucleonA=(GlauberNucleon*)(nucleonsA->At(i));
    if (!nucleonA->IsWounded())
      continue;
    Double_t x = nucleonA->getX();
    Double_t y = nucleonA->getY();
    Double_t r2=(xval-x)*(xval-x)+(yval-y)*(yval-y);
    if (r2>r2max)
      continue;
    ret += prof.Eval(TMath::Sqrt(r2));
  }
  for (Int_t i = 0; i<nNucleonsB; ++i) {
    GlauberNucleon *nucleonB=(GlauberNucleon*)(nucleonsB->At(i));
    if (!nucleonB->IsWounded())
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
  h2f->SetStats(0);
  h2f->Draw();
  TEllipse e;
  e.SetFillColor(0);
  e.SetFillStyle(0);
  e.SetLineColor(1);
  e.SetLineStyle(2);
  e.SetLineWidth(1);
  e.DrawEllipse(getB()/2,0,nucleusB.getR(),nucleusB.getR(),0,360,0);
  e.DrawEllipse(-getB()/2,0,nucleusA.getR(),nucleusA.getR(),0,360,0);
  nucleusA.Draw(fXSect, kMagenta, kYellow);
  nucleusB.Draw(fXSect, kMagenta, kOrange);

  String opt(option);
  if (opt.IsNull()) return;

  Double_t sy2 = getSy2();
  Double_t sx2 = getSx2();
  Double_t phase = 0;
  if (sy2<sx2) {
    Double_t d = sx2;
    sx2 = sy2;
    sy2 = d;
    phase = Math::pi()/2.;
  }
  Double_t x1 = (0.5*(sy2-sx2)+TMath::Sqrt(TMath::Power(sy2-sx2,2.)-4*TMath::Power(getSxy(),2)));
  Double_t ang = TMath::ATan2(-getSxy(),x1)+phase;
  TLine l;
  l.SetLineWidth(3);
  l.DrawLine(-10*TMath::Cos(ang),-10*TMath::Sin(ang),10*TMath::Cos(ang),10*TMath::Sin(ang));
}

Double_t GlauberMC::getTotXSect() const
{
  return (1.0*eventStatsents/nTotalEvents)*Math::pi()*maxImpactPar*maxImpactPar/100;
}

Double_t GlauberMC::getTotXSectErr() const
{
  return getTotXSect()/TMath::Sqrt((Double_t)eventStatsents) * TMath::Sqrt(Double_t(1.-eventStatsents/nTotalEvents));
}

vector<GlauberNucleon*> &GlauberMC::getAllNucleons() 
{
  allNucleons.clear();
  for (auto & nucleonA : nucleonsA) allNucleons.push_back(nucleonA);
  for (auto & nucleonB : nucleonsB) allNucleons.push_back(nucleonB);
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

Bool_t GlauberMC::readNextEvent(Bool_t calc, const char *fname)
{
  static TFile *inf = 0;
  static Int_t iev  = 0;
  if (fname) {
    cout << "readNextEvent: Setting up file " << fname << endl;
    delete inf;
    inf = TFile::Open(fname);
    if (!inf) return 0;
      nucleusA.generateNucleons();
      nucleonsA = nucleusA.getNucleons();
      for (auto & nucleonA : nucleonsA)	nucleonA->SetInNucleusA();
      nucleonsB = nucleusB.getNucleons();
      for (auto & nucleonA : nucleonsA) nucleonB->SetInNucleusB();
      }
    }
    if (calc) return 1;
    fNt = dynamic_cast<TNtuple*>(inf->get(Form("nt_%s_%s",nucleusA.getName(),nucleusB.getName())));
    if (!fNt) {
      cerr << "readNextEvent: Could not find ntuple!" << endl;
      inf->ls();
      return 0;
    }
    fNt->SetBranchAddress("nParticipants",&eventStats.nParticipants);
    fNt->SetBranchAddress("nCollisions",&eventStats.nCollisions);
    fNt->SetBranchAddress("B",&eventStats.B);
    fNt->SetBranchAddress("BNN",&eventStats.BNN);
    fNt->SetBranchAddress("VarX",&eventStats.VarX);
    fNt->SetBranchAddress("VarY",&eventStats.VarY);
    fNt->SetBranchAddress("VarXY",&eventStats.VarXY);
    fNt->SetBranchAddress("nParticipantsA",&eventStats.nParticipantsA);
    fNt->SetBranchAddress("nParticipantsB",&eventStats.nParticipantsB);
    fNt->SetBranchAddress("nParticipants0",&eventStats.nParticipants0);
    fNt->SetBranchAddress("Psi1",&eventStats.Psi1);
    fNt->SetBranchAddress("Ecc1",&eventStats.Ecc1);
    fNt->SetBranchAddress("Psi2",&eventStats.Psi2);
    fNt->SetBranchAddress("Ecc2",&eventStats.Ecc2);
    fNt->SetBranchAddress("Psi3",&eventStats.Psi3);
    fNt->SetBranchAddress("Ecc3",&eventStats.Ecc3);
    fNt->SetBranchAddress("Psi4",&eventStats.Psi4);
    fNt->SetBranchAddress("Ecc4",&eventStats.Ecc4);
    fNt->SetBranchAddress("Psi5",&eventStats.Psi5);
    fNt->SetBranchAddress("Ecc5",&eventStats.Ecc5);
    return 1;
  }
  if ((!inf)||(!fNt&&!calc)) {
    cerr << "readNextEvent was not initialized" <<endl;
    return 0;
  }
  vector<GlauberNucleon*> &arr = dynamic_cast<TObjArray*>(inf->get(Form("nucleonarray%d",iev)));
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
    if (nuclinp->IsInNucleusB()) { 
      nuclout = static_cast<GlauberNucleon*>(nucleonsB->At(inB));
      impactParB += nuclinp->getX();
      ++inB;
    } else {
      nuclout = static_cast<GlauberNucleon*>(nucleonsA->At(inA));
      impactParA += nuclinp->getX();
      ++inA;
    }
    nuclout->SetXYZ(nuclinp->getX(),nuclinp->getY(),nuclinp->getZ());
    nuclout->SetType(nuclinp->getType());
    nuclout->SetEnergy(nuclinp->getEnergy());
    if (!calc) nuclout->setNCollisions(nuclinp->getnCollisions());
  }
  delete arr;
  Double_t impactPar = impactParB/inB-impactParA/inA;
  if (calc) {
    Bool_t ret = calculateEvent(impactPar);
    if (0) 
      cout << iev << ": " << eventStats.B << " " << eventStats.nParticipants << " " << eventStats.nCollisions << " " << eventStats.nParticipants0 << endl;
    ++iev;
    return ret;
  }
  Int_t ret = fNt->getEntry(iev);
  if (ret<=0) 
    return 0;
  fEccN[1]=eventStats.Ecc1;
  fEccN[2]=eventStats.Ecc2;
  fEccN[3]=eventStats.Ecc3;
  fEccN[4]=eventStats.Ecc4;
  fEccN[5]=eventStats.Ecc5;
  if (0) 
    cout << iev << ": " << eventStats.B << " " << eventStats.nParticipants << " " << eventStats.nCollisions << " " << eventStats.nParticipants0 << endl;
  if (0) { // test ntuple values vs re-calculated values
    Double_t nParticipants = eventStats.nParticipants;
    Double_t nCollisions = eventStats.nCollisions;
    Double_t ecc2  = eventStats.Ecc2;
    calculateEvent(impactPar);
    if (nParticipants!=eventStats.nParticipants) 
      cout << iev << " differ in nParticipants " << nParticipants << " " << eventStats.nParticipants << endl;
    if (nCollisions!=eventStats.nCollisions) 
      cout << iev << " differ in nCollisions " << nCollisions << " " << eventStats.nCollisions << endl;
    if (TMath::Abs(ecc2-eventStats.Ecc2)>0.001) 
      cout << iev << " differ in ecc2 " << ecc2 << " " << eventStats.Ecc2 << endl;
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
    fNt->SetDirectory(0);
    vector<GlauberNucleon*> &l = fNt->getListOfBranches();
    for (Int_t i=0; i<l->getEntries(); ++i) {
      TBranch *br = dynamic_cast<TBranch*>(l->At(i));
      if (br)
        br->SetCompressionLevel(9);
    }
  }

  for (Int_t i = 0; i<nevents; ++i) {
    while (!NextEvent(b)) {}
    fNt->Fill((Float_t*)(&eventStats.nParticipants));
    if ((i>0)&&(i%100)==0) 
      cout << "GlauberEvent # " << i << " x-sect = " << getTotXSect() << " +- " << getTotXSectErr() << " b        \r" << flush;
  }
  if (nevents>99)
    cout << endl << "Done!" << endl;
}
#endif



