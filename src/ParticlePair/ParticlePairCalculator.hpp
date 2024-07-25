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
#ifndef CAP__ParticlePairCalculator
#define CAP__ParticlePairCalculator
#include "EventTask.hpp"
#include "ParticlePairExceptions.hpp"

namespace CAP
{


//! Task used for the analysis of particle  pair distributions and correlations. As for other tasks classes of this package, use event filters and particle filters to determine the
//! event selection and particle types and kinematic ranges across which  particle pair  distributions are studied. Particle particle distributions are computed
//! (histogrammed) with instances of the ParticlePairHistos class. The behavior of the class, i.e., what type and the range of filled histograms are determined by
//! class configuration provided at task (object) construction.
//!
//! The following configuration parameters determine what types of histograms are filled (default values in brackets):
//! - fillEta [true]: whether to fill histograms  vs. pseudorapidity "eta"
//! - fillY [false]: whether to fill histograms  vs. rapidity "y"
//! - fillP2 [false]: whether to fill histograms used in the determination of P2 and G2 pT correlators
//!
//! The following parameters specify  the configuration of histograms filled by this task (default values in brackets):
//!
//! - Multiplicity of pair histogram
//!  + nBins_n2 [100]: Number of bins
//!  + min_n2 [0.0]: Minimum multiplicity
//!  + max_n2 [100]: Maximum multiplicity
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
class ParticlePairCalculator : public EventTask
{
public:

  ParticlePairCalculator();
  ParticlePairCalculator(const ParticlePairCalculator & task);
  virtual ~ParticlePairCalculator() {}
  ParticlePairCalculator & operator=(const ParticlePairCalculator & task);
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void createHistograms();
  virtual void importHistograms(TFile & inputFile);
  
protected:
  
  bool fillEta; //!< whether to fill pseudorapidity histograms (set from configuration at initialization)
  bool fillY;   //!< whether to fill rapidity histograms (set from configuration at initialization)
  bool fillP2;  //!< whether to fill P2 and G2 related histograms  (set from configuration at initialization)
  
   ClassDef(ParticlePairCalculator,0)
};

} // namespace CAP

#endif /* CAP__ParticlePairCalculator */
