#ifndef CAP_TherminatorGenerator
#define CAP_TherminatorGenerator
#include "EventTask.hpp"
#include "ParticleDb.hpp"
#include "ParticleDecayer.hpp"
#include "Model.hpp"
#include "Hypersurface.hpp"
#include "Exceptions.hpp"
#include "Thermodynamics.hpp"

namespace CAP
{
struct ParticleMultiplicity
{
  String name;
  double integral;
  double multiplicity;
};

class TherminatorGenerator
:
public EventTask
{
public:

  TherminatorGenerator();
  TherminatorGenerator(const TherminatorGenerator & task);
  TherminatorGenerator operator=(const TherminatorGenerator & task);
  virtual ~TherminatorGenerator(){};
  virtual void setDefaultConfiguration();
  virtual void configure();
  virtual void initialize();
  virtual void execute();
  virtual void finalize();
  virtual void importMultiplicities()  ;   // throw (FileException);
  virtual void calculateMultiplicities();
  virtual void exportMultiplicities();
  virtual void printMultiplicities();
  virtual void printIntroMessage(const String & option="")  const;
  virtual void printHelp(const String & option="") const;
  virtual void printVersion(const String & option="") const;
  bool accept(Particle & parent);
  virtual void decayParticle(Event & event, Particle & parent);

protected:

  int    modelType;
  int    modelSubType;
  String modelInputPath;
  String modelInputFile;
  String modelOutputPath;
  String modelOutputFile;
  bool   modelExport;
  String hypersurfaceInputPath;
  String hypersurfaceInputFile;
  String hypersurfaceOutputPath;
  String hypersurfaceOutputFile;

  bool   multiplicitiesImport;
  bool   multiplicitiesExport;
  bool   multiplicitiesCreate;
  int    multiplicitiesFluctType;
  String multiplicitiesInputPath;
  String multiplicitiesInputFile;
  String multiplicitiesOutputPath;
  String multiplicitiesOutputFile;
  double multiplicitiesFractionMin;
  double multiplicitiesFractionMax;
  double multiplicitiesFractionRange;
  double multiplicitiesForceZeroNetQ;

  // int eventsExportMaxPerFile;
  bool   disablePhotons;
  int    nSamplesIntegration;
  bool   modelOnlyBackFlow;
  bool   decayRescaleChannels;
  bool   decayDisabled;
  bool   decayDisable2Prong;
  bool   decayDisable3Prong;
  bool   decayNoWeakDecay;
  bool   decayStoreDecayedParts;

  ParticleDecayer particleDecayer;
  Model  * model;
  Event  * event;
  vector<ParticleMultiplicity> averageMultiplicities;
  vector<int> eventMultiplicities;

protected:

  ClassDef(TherminatorGenerator,0)

};

} // namespace CAP;

#endif


/********************************************************************************
 *                                                                              *
 *             THERMINATOR 2: THERampl heavy-IoN generATOR 2                     *
 *                                                                              *
 * Version:                                                                     *
 *      Release, 2.0.3, 1 February 2011                                         *
 *                                                                              *
 * Authors:                                                                     *
 *      Mikolaj Chojnacki   (Mikolaj.Chojnacki@ifj.edu.pl)                      *
 *      Adam Kisiel         (kisiel@if.pw.edu.pl)                               *
 *      Wojciech Broniowski (Wojciech.Broniowski@ifj.edu.pl)                    *
 *      Wojciech Florkowski (Wojciech.Florkowski@ifj.edu.pl)                    *
 *                                                                              *
 * Project homepage:                                                            *
 *      http://therminator2.ifj.edu.pl/                                         *
 *                                                                              *
 * For the detailed description of the program and further references           *
 * to the description of the model please refer to                              *
 * http://arxiv.org/abs/1102.0273                                               *
 *                                                                              *
 * This code can be freely used and redistributed. However if you decide to     *
 * ampke modifications to the code, please, inform the authors.                  *
 * Any publication of results obtained using this code must include the         *
 * reference to arXiv:1102.0273 and the published version of it, when           *
 * available.                                                                   *
 *                                                                              *
 ********************************************************************************/
/*! @file therm2_events.cxx
 * @brief <c><b>THERMINATOR 2</b></c> event generating program.
 *
 * @fn int ampin(int argc, char **argv)
 * @brief ampin program.
 * @param [in] argc number of program arguments
 * @param [in] argv vector with program arguments
 *
 * @fn void readParameters()
 * @brief Reads some of the global parameters.
 *
 * The <c><b>THERMINATOR 2</b></c> ampin settings file <b>therminator.ini</b> options used here:
 * <table>
 *   <tr><th>Keyword</th>		<th>Description</th></tr>
 *   <tr><td>Randomize</td>		<td>all random generators are initiated with system date or have constant seed </td></tr>
 *   <tr><td>FreezeOutDir</td>		<td>directory with freeze-out models setting files</td></tr>
 *   <tr><td>FreezeOutModel</td>	<td>name of the freeze-out model to use</td></tr>
 * </table>
 *
 * @fn void ReadSHARE(ParticleDb* aPartDB)
 * @brief Reads the <c><b>SHARE</b></c> database and builds the ParticleDb.
 *
 * The <c><b>THERMINATOR 2</b></c> ampin settings file <b>therminator.ini</b> options used here:
 * <table>
 *   <tr><th>Keyword</th>		<th>Description</th></tr>
 *   <tr><td>ShareDir</td>		<td>directory with the <c><b>SHARE</b></c> database files</td></tr>
 * </table>
 * @param [in] aPartDB particles database
 *
 * @fn void CheckSHARE(ParticleDb* aPartDB)
 * @brief Procedure to check if Parser has correctly filled ParticleDb.
 * @param [in] aPartDB particles database
 *
 * @fn void MessageIntro()
 * @brief Prints introduction message.
 *
 * @fn void MessageHelp();
 * @brief Prints help message.
 *
 * @fn void MessageVersion();
 * @brief Prints version message.
 *
 * @fn void CopyINIFile()
 * @brief Copy INI file to sEventDIR
 *
 * @fn void AddLogEntry(const char* aEntry)
 * @brief Adds a log entry to the log file
 * @param [in] aEntry text string with the entry
 *
 * @var Configurator *sampinConfig
 * @brief Global variable with Configurator holding settings form <b>events.ini</b> file.
 *
 * @var String sEventDIR
 * @brief Global variable with directory to store event files.
 *
 * @var String	sampinINI
 * @brief Global variable with name of the ampin ini file [<i>default: therminator.ini</i>]
 *
 * @var String sModelINI
 * @brief Global variable with name and location of selected model ini file.
 *
 * @var String sHyperXML
 * @brief Global variable with name and location of selected hypersurface XML file.
 *
 * @var char sTimeStamp[21]
 * @brief Global variable with time-stamp character string. (default forampt "YYYY-MM-DD hh:mm:ss")
 *
 * @var int sModel
 * @brief Global variable with number associated to a chosen freeze-out Model.
 *
 * @var int sRandomize
 * @brief Global variable that controls the random number generators initiation.
 *
 * @var int sIntegrateSample
 * @brief Global variable with number of Monte-Carlo samples used by Integrator to find the average multiplicity and ampx of the
 * Cooper-Frye integrand for each ParticleType in the selected Model.
 *
 * @var int sParentPID
 * @brief Parent's system process ID.
 */

