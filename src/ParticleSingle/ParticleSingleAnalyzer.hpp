/* **********************************************************************
 * Copyright (C) 2019-2022, Claude Pruneau, Victor Gonzalez, Sumit Basu
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2022
 *
 * *********************************************************************/
#ifndef CAP__ParticleSingleAnalyzer
#define CAP__ParticleSingleAnalyzer
#include "EventTask.hpp"
#include "ParticleSingleExceptions.hpp"
#include "ParticleDigit.hpp"
#include <vector>

namespace CAP
{
//!
//! Task used for the analysis of single particle distributions. As for other tasks classes of this package, use event filters and particle filters to determine the
//! event selection and particle types and kinematic ranges across which single particle distributions are studied. Single particle distributions are computed
//! (histogrammed) with instances of the ParticleSingleHistos class. The behavior of the class, i.e., what type and the range of filled histograms are determined by
//! class configuration provided at task object construction.
//!
//! The following configuration parameters determine what types of histograms are filled (default values in brackets):
//! - fillEta [true]: whether to fill histograms  vs. pseudorapidity "eta"
//! - fillY [false]: whether to fill histograms  vs. rapidity "y"
//! - fillP2 [false]: whether to fill histograms used in the determination of P2 and G2 pT correlators
//!
//! The following parameters specify  the configuration of histograms filled by this task (default values in brackets):
//!
//! - Multiplicity histogram
//!  + nBins_n1 [100]: Number of bins
//!  + min_n1 [0.0]: Minimum multiplicity
//!  + max_n1 [100]: Maximum multiplicity
//! - Particle energy histogram
//!  + nBins_eTot [100]: Number of bins
//!  + min_eTot [0.0]: Minimum value
//!  + max_eTot [100]: Maximum value
//! - Particle transverse momemtum
//!  + nBins_pt [100]: Number of bins
//!  + min_pt [0.0]: Minimum value
//!  + max_pt [100.0]: Maximum value
//! - Particle pseudorapidity
//!  + nBins_eta [20]: Number of bins
//!  + min_eta [-1.0]: Minimum value
//!  + max_eta [1.0]: Maximum value
//! - Particle rapidity
//!  + nBins_y [20]: Number of bins
//!  + min_y [-1.0]: Minimum value
//!  + max_y [1.0]: Maximum value
//! - Particle azimuthal angle
//!  + nBins_phi [36]: Number of bins
//!  + min_phi [0.0]: Minimum value
//!  + max_phi [2pi]: Maximum value
//!
class ParticleSingleAnalyzer : public EventTask
{
public:
  
  ParticleSingleAnalyzer();
  ParticleSingleAnalyzer(const ParticleSingleAnalyzer & analyzer);
  ParticleSingleAnalyzer & operator=(const ParticleSingleAnalyzer & analyzer);
  virtual ~ParticleSingleAnalyzer() {}
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void scaleHistograms();

protected:
  


  ClassDef(ParticleSingleAnalyzer,0)
};

} // namespace CAP

#endif /* CAP__ParticleSingleAnalyzer */
