/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau, 05/16/2024
 *
 * *********************************************************************/
#include "ParticleDbParser.hpp"
#include "PrintHelpers.hpp"
#include <iostream>

using CAP::ParticleDbParser;

ClassImp(CAP::ParticleDbParser);


namespace CAP
{


const double factorials[7] = {1.0, 1.0, 2.0, 6.0, 24.0, 120.0, 720.0 };



ParticleDbParser::ParticleDbParser()
:
PropertiesParser()
{ }

//!
//!Therminator Particle Db Parser
//!
//! @param particleDb Database to be loaded by this parse
//! @param inputFile Input stream for particles
//! @param inputFileDecays Input stream for decays
//!
//!
void  ParticleDbParser::readDb(ParticleDb   & particleDb,
                               ifstream & inputFile,
                               ifstream & inputFileDecays)
{
  char   buff[300];
  char   name[20];
  double mass, width, spin, isospin, isospin3, Nq, Ns, Naq, Nas, Nc, Nac, pdgCode;
  int    index = 0;
  ParticleType * particleType;

  //
  // read particles
  //
  while (!inputFile.eof())
    {
    inputFile.getline(buff,300);
    if (!(*buff) || (*buff == '#')) continue;
    istringstream * iss = new istringstream(buff);
    (*iss) >> name >> mass >> width >> spin >> isospin >> isospin3 >> Nq >> Ns >> Naq >> Nas >> Nc >> Nac >> pdgCode;
    index++;
    particleType = new ParticleType();
    particleType->setIndex(index);
    particleType->setName(name);
    particleType->setTitle(name);
    particleType->setMass(mass);
    particleType->setWidth(width);
    particleType->setSpin(spin);
    particleType->setIsospin(isospin);
    particleType->setIsospin3(isospin3);
    particleType->setNumberQ(static_cast<int>  (Nq));
    particleType->setNumberAQ(static_cast<int> (Naq));
    particleType->setNumberS(static_cast<int>  (Ns));
    particleType->setNumberAS(static_cast<int> (Nas));
    particleType->setNumberC(static_cast<int>  (Nc));
    particleType->setNumberAC(static_cast<int> (Nac));
    particleType->setNumberB(static_cast<int>  (0));
    particleType->setNumberAB(static_cast<int> (0));
    double netS   = Nas - Ns;
    double netC   = Nc  - Nac;
    double baryon = (Nq + Ns + Nc)/3.0 - (Naq + Nas + Nac)/3.0;
    double charge = isospin3 +(baryon +netS)/2.0;
    particleType->setCharge( static_cast<int> ( charge ));
    particleType->setBaryonNumber( static_cast<int> ( baryon ));
    particleType->setStrangeness(static_cast<int> ( netS   ));
    particleType->setCharm(  static_cast<int> ( netC   ));
    particleType->setBottomNumber( 0 );
    particleType->setPdgCode(static_cast<int> ( pdgCode));
    particleType->setStable(true);
    particleType->disableDecay();
    particleType->enable();
    particleDb.addParticleType(particleType);
    delete iss;
    }


  //
  // read decays
  //
  double tBRatio, tRatio;
  int    CGcoeff; // complete branching ratio by Clebsch-Gordan coefficient: 0-no 1-yes
  ParticleType * parentType = nullptr;
  ParticleType * childType1 = nullptr;
  ParticleType * childType2 = nullptr;
  ParticleType * childType3 = nullptr;
  ParticleType * childType4 = nullptr;
  double mass0 = 0;
  double mass1 = 0;
  double mass2 = 0;
  double mass3 = 0;
  double mass4 = 0;

  while (!inputFileDecays.eof())
    {
    inputFileDecays.getline(buff,300);
    if (!(*buff) || (*buff == '#')) continue;
    char parentName[20];
    char childName1[20];
    char childName2[20];
    char childName3[20];
    char childName4[20];
    istringstream * isss = new istringstream(buff);
    *isss >> parentName >> childName1 >> childName2 >> childName3 >> childName4 >> tBRatio >> CGcoeff;;
    //cout << parentName << "  " << childName1 << "  " << childName2 << "  " << childName3 << "  " <<  childName4 <<"  " << tBRatio << "  " <<CGcoeff <<  endl;;
    delete isss;
    parentType = nullptr;
    childType1 = nullptr;
    childType2 = nullptr;
    childType3 = nullptr;
    childType4 = nullptr;
    mass0 = 0;
    mass1 = 0;
    mass2 = 0;
    mass3 = 0;
    mass4 = 0;
    parentType = particleDb.getParticleType(parentName);
    mass0 = parentType->getMass();
    childType1 = particleDb.getParticleType(childName1);
    mass1 = childType1->getMass();
    childType2 = particleDb.getParticleType(childName2);
    mass2 = childType2->getMass();
    String name3(childName3);
    if (!name3.EqualTo("none"))
      {
      childType3 = particleDb.getParticleType(childName3);
      mass3 = childType3->getMass();
      }
    String name4(childName4);
    if (!name4.EqualTo("none"))
      {
      childType4 = particleDb.getParticleType(childName4);
      mass4 = childType4->getMass();
      }
    double massDiff = mass1+mass2+mass3+mass4-mass0;
    if (massDiff>0 && isVerbose())
      {
      printCR();
      printValue("Mass exception: parentName",parentName);
      printValue("Mass exception: childName1",childName1);
      printValue("Mass exception: childName2",childName2);
      printValue("Mass exception: childName3",childName3);
      }
    continue;
    }
  if (CGcoeff)
    {// complete branching ratio by Clebsch-Gordan coefficient
      double j1, m1, j2, m2, J, M, CB;
      J  = parentType->getIsospin();
      M  = parentType->getIsospin3();
      j1 = childType1->getIsospin();
      m1 = childType1->getIsospin3();
      j2 = childType2->getIsospin();
      m2 = childType2->getIsospin3();
      CB = clebschGordan(J, M, j1, m1, j2, m2);
      tRatio = CB*CB * tBRatio;
      // Multiply the Clebsh by two?
      // The same spin, ampss, strangeness (charm?)
      // and different I3?
      if (  (TMath::Abs(childType1->getSpin()  - childType2->getSpin()) < 0.01)
          && (TMath::Abs(childType1->getMass() - childType2->getMass()) < 0.01)
          && (TMath::Abs(childType1->getIsospin3()-childType2->getIsospin3())   > 0.01)
          && (childType1->getStrangeness()-childType2->getStrangeness() == 0)
          && (childType1->getCharm()- childType2->getCharm() == 0)        )
        {
        tRatio *= 2.0;
        }
    }
  else
    {
    tRatio = tBRatio;
    }
  //if (flag) cout << "Creating decay mode" << endl;

  ParticleDecayMode decayMode;
  decayMode.setBranchingRatio(tRatio);
  decayMode.addChild(childType1);
  decayMode.addChild(childType2);
  if (childType3) decayMode.addChild(childType3);
  if (childType4) decayMode.addChild(childType3);
  parentType->addDecayMode(decayMode);

  if (isVerbose())
    {
    printCR();
    printValue("Total index of particles read",particleDb.size());
    }
  inputFileDecays.close();
  particleDb.mapAntiParticleIndices();
  particleDb.setupDecayGenerator();
}

double ParticleDbParser::clebschGordan(double aJot,  double aEm,
                                       double aJot1, double aEm1,
                                       double aJot2, double aEm2)
{
  int mint, maxt;
  double cgc = 0.0;
  int tIter;
  double coef;

  maxt = lrint(aJot1 + aJot2 - aJot);
  mint = 0;
  if (lrint(aJot1 - aEm1)  < maxt) maxt = lrint(aJot1 - aEm1);
  if (lrint(aJot2 + aEm2)  < maxt) maxt = lrint(aJot2 + aEm2);
  if (lrint(-(aJot-aJot2+aEm1))  > mint) mint = lrint(-(aJot-aJot2+aEm1));
  if (lrint(-(aJot-aJot1-aEm2))  > mint) mint = lrint(-(aJot-aJot1-aEm2));

  //  // PRINT_DEBUG_3("\t\t\tmint " << mint << " j1 " <<  aJot1 << " m1 " << aEm1);
  //  // PRINT_DEBUG_3("\t\t\tampxt " << maxt << " j2 " <<  aJot2 << " m2 " << aEm2);

  for (tIter = mint; tIter<=maxt; tIter ++)
    {
    coef = TMath::Power(-1, tIter);
    // PRINT_DEBUG_3("\t\t\tcoef1 " << coef);
    coef *= sqrt( (2*aJot+1)
                 * factorials[lrint(aJot1+aEm1)]
                 * factorials[lrint(aJot1-aEm1)]
                 * factorials[lrint(aJot2+aEm2)]
                 * factorials[lrint(aJot2-aEm2)]
                 * factorials[lrint(aJot+aEm)]
                 * factorials[lrint(aJot-aEm)]
                 );
    // PRINT_DEBUG_3("\t\t\tcoef2 " << coef);
    coef /= factorials[tIter]
    * factorials[lrint(aJot1+aJot2-aJot-tIter)]
    * factorials[lrint(aJot1-aEm1-tIter)]
    * factorials[lrint(aJot2+aEm2-tIter)]
    * factorials[lrint(aJot-aJot2+aEm1+tIter)]
    * factorials[lrint(aJot-aJot1-aEm2+tIter)];
    // PRINT_DEBUG_3("\t\t\tcoef3 " << coef);
    cgc += coef;
    }
  cgc *= deltaJ(aJot1, aJot2, aJot);

  return cgc;
}

double ParticleDbParser::deltaJ(double aJot1, double aJot2, double aJot)
{
  double res = sqrt( 1.0
                    * factorials[lrint( aJot1 + aJot2 - aJot)]
                    * factorials[lrint( aJot1 - aJot2 + aJot)]
                    * factorials[lrint(-aJot1 + aJot2 + aJot)]
                    / factorials[lrint( aJot1 + aJot2 + aJot + 1)]
                    );
  return res;
}





}
