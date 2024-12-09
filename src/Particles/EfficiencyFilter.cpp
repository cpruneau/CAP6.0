/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau, Victor Gonzalez   
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2024
 *
 * *********************************************************************/
#include "EfficiencyFilter.hpp"
#include "Manager.hpp"
#include "PrintHelpers.hpp"

ClassImp(CAP::Filter<CAP::Particle>);
ClassImp(CAP::EfficiencyFilter);

namespace CAP
{

EfficiencyFilter::EfficiencyFilter()
:
ParticleFilter()
{ /* no ops */}

EfficiencyFilter::EfficiencyFilter(const EfficiencyFilter & source)
:
ParticleFilter(source)
{ /* no ops */}

EfficiencyFilter & EfficiencyFilter::operator=(const EfficiencyFilter & source)
{
  if (this!=&source)
    {
    ParticleFilter::operator=(source);
    }
  return *this;
}


bool EfficiencyFilter::accept(const Particle & particle)
{
  if (getNConditions()<1) return true;
  bool   accepting = false;
  for (auto & condition : conditions)
    {
    int filterSubType = condition->conditionSubtype;
    switch (filterSubType)
      {
        case kPt:       accepting = condition->accept(particle.getMomentum().Pt());  break;
        case kPx:       accepting = condition->accept(particle.getMomentum().Px());  break;
        case kPy:       accepting = condition->accept(particle.getMomentum().Py());  break;
        case kPz:       accepting = condition->accept(particle.getMomentum().Pz());  break;
        case kEnergy:   accepting = condition->accept(particle.getMomentum().E());   break;
        case kEta:      accepting = condition->accept(particle.getMomentum().Eta()); break;
        case kRapidity: accepting = condition->accept(particle.getMomentum().Rapidity()); break;
        case kPhi:      accepting = condition->accept(particle.getMomentum().Phi()); break;
        case kPdg:      accepting = condition->accept(particle.getType().getPdgCode()); break;
        case kCharge:   accepting = condition->accept(particle.getType().getCharge()); break;
        case kStrange:  accepting = condition->accept(particle.getType().getStrangeness()); break;
        case kBaryon:   accepting = condition->accept(particle.getType().getBaryonNumber()); break;
        case kCharm:    accepting = condition->accept(particle.getType().getCharm()); break;
        //case kBeauty:   accepting = condition->accept(particle.getType().getBeauty()); break;
        case kLive:     accepting = condition->accept(particle.isLive()); break;
        case kEnabled:  accepting = condition->accept(particle.getType().isEnabled());
        case kEfficiency: accepting = efficiencyAccept(particle.getMomentum());
      }
    if (!accepting)  return false;
    }
  return true;
}

void EfficiencyFilter::setFilterType(EfficiencyFilter::EfficiencyFilterType type)
{
  efficiencyFilterType = type;
}

EfficiencyFilter::EfficiencyFilterType EfficiencyFilter::getFilterType() const
{
  return efficiencyFilterType;
}

void EfficiencyFilter::setEffHisto(TH1 * effHisto)
{
  efficiencyHisto = effHisto;
}

bool EfficiencyFilter::efficiencyAccept(const LorentzVector & momentum)
{
  bool accept = true;

  printString("EfficiencyFilter::efficiencyAccept() started");
  switch (efficiencyFilterType)
    {
      default:
      case kEffNone:
      printString("EfficiencyFilter::efficiencyAccept() case kEffNone");
      break;

      case kEffVsPt:
      {
      printString("EfficiencyFilter::efficiencyAccept() case kEffVsPt");
      printValue("momentum.Pt()",momentum.Pt());
      int    ix  = efficiencyHisto->GetXaxis()->FindBin(momentum.Pt());
      double eff = efficiencyHisto->GetBinContent(ix);
      double r = gRandom->Rndm();
      printValue("momentum.Pt()",momentum.Pt());
      printValue("eff",eff);
      printValue("gRandom->Rndm()",gRandom->Rndm());
      if (r>eff) accept = false;
      printValue("accept)",accept);
     break;
      }

      case kEffVsPtEta:
      {
      int    ix  = dynamic_cast<TH2*>(efficiencyHisto)->GetXaxis()->FindBin(momentum.Pt());
      int    iy  = dynamic_cast<TH2*>(efficiencyHisto)->GetYaxis()->FindBin(momentum.Eta());
      double eff   = efficiencyHisto->GetBinContent(ix,iy);
      double r = gRandom->Rndm();
      if (r>eff) accept = false;
      break;
      }
    }
  return accept;
}


} // namespace CAP
