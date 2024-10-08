/* **********************************************************************
 * Copyright (C) 2019-2022, Claude Pruneau, Victor Gonzalez, Sumit Basu
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Victor Gonzalez
 *
 * *********************************************************************/

#ifndef CAP__MomentumGenerator
#define CAP__MomentumGenerator
#include <vector>
#include <iostream>
#include <TF1.h>
#include <TH1.h>
#include <TRandom.h>
#include "ParticleType.hpp"
using std::vector;
using std::cout;
using std::endl;

namespace CAP
{


class MomentumGenerator
{
public:

  enum GeneratorType
  {
    IsotropicGaussP, IsotropicExpP, IsotropicUniformP, IsotropicUniformDensity, IsotropicMaxwellP,
    CylindricalGaussPtUniformY, CylindricalExpPtUniformY, CylindricalMaxwellPtUniformY
  };

  //! stat : 1 Fermi Dirac
  //!     -1 : bose einstein
  MomentumGenerator(int _generatorType,
                    ParticleType * _particleType,
                    vector<double> _parameters);
  virtual ~MomentumGenerator() {}
  virtual void   generate(LorentzVector & momentum);

protected:
  int            generatorType;
  ParticleType * particleType;
  double         mass;
  double         stat;
  vector<double> parameters;
  vector<TH1*>   histograms;

  ClassDef(MomentumGenerator,0)
};

} // namespace CAP

#endif /* CAP__MomentumGenerator */

