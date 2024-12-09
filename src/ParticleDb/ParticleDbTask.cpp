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
#include "ParticleDbTask.hpp"
#include "ParticleDbParser.hpp"
#include "PrintHelpers.hpp"
#include "StreamHelpers.hpp"


ClassImp(CAP::ParticleDbTask);


namespace CAP
{
using namespace std;


ParticleDbTask::ParticleDbTask()
:
Task(),
Manager<ParticleDb>(),
dbImport(true),
dbImportPath("ParticleData/"),
dbImportFile("particles.data"),
dbImportDecaysFile("decays.data"),
dbExport(false),
dbExportPath("ParticleData/"),
dbExportFile("newParticles.data"),
dbExportDecaysFile("newDecays.data"),
dbDisableNeutralParticles(false),
dbDisableChargedParticles(false),
dbDisableSelected(false),
dbEnableAllParticles(true),   // default value
dbEnableNeutralParticles(false),
dbEnableChargedParticles(false),
dbEnableSelected(false),
//
dbDisableNeutralDecays(false),
dbDisableChargedDecays(false),
dbDisableSelectedDecays(false),
dbDisableWeakDecays(true),
dbDisableLongLivedDecays(false),
dbDisableShortLivedDecays(false),
//
dbEnableAllDecays(true),  // default value
dbEnableNeutralDecays(false),
dbEnableChargedDecays(false),
dbEnableSelectedDecays(false),
dbEnableWeakDecays(false),
dbEnableLongLivedDecays(false),
dbEnableShortLivedDecays(false),
dbMaxLifeTime(0.0),
particleDb(nullptr)
{
  appendClassName("DbTask");
  setInstanceName("DbTask");
}

ParticleDbTask::ParticleDbTask(const ParticleDbTask & task)
:
Task(task),
Manager<ParticleDb>(task),
dbImport(task.dbImport),
dbImportPath(task.dbImportPath),
dbImportFile(task.dbImportFile),
dbImportDecaysFile(task.dbImportDecaysFile),
dbExport(task.dbExport),
dbExportPath(task.dbExportPath),
dbExportFile(task.dbExportFile),
dbExportDecaysFile(task.dbExportDecaysFile),
dbDisableNeutralParticles(task.dbDisableNeutralParticles),
dbDisableChargedParticles(task.dbDisableChargedParticles),
dbDisableSelected(task.dbDisableSelected),
dbEnableAllParticles(task.dbEnableAllParticles),   // default value
dbEnableNeutralParticles(task.dbEnableNeutralParticles),
dbEnableChargedParticles(task.dbEnableChargedParticles),
dbEnableSelected(task.dbEnableSelected),
//
dbDisableNeutralDecays(task.dbDisableNeutralDecays),
dbDisableChargedDecays(task.dbDisableChargedDecays),
dbDisableSelectedDecays(task.dbDisableSelectedDecays),
dbDisableWeakDecays(task.dbDisableWeakDecays),
dbDisableLongLivedDecays(task.dbDisableLongLivedDecays),
dbDisableShortLivedDecays(task.dbDisableShortLivedDecays),
//
dbEnableAllDecays(task.dbEnableAllDecays),  // default value
dbEnableNeutralDecays(task.dbEnableNeutralDecays),
dbEnableChargedDecays(task.dbEnableChargedDecays),
dbEnableSelectedDecays(task.dbEnableSelectedDecays),
dbEnableWeakDecays(task.dbEnableWeakDecays),
dbEnableLongLivedDecays(task.dbEnableLongLivedDecays),
dbEnableShortLivedDecays(task.dbEnableShortLivedDecays),
dbMaxLifeTime(task.dbMaxLifeTime),
particleDb(nullptr)
{  /* no ops */   }

ParticleDbTask ParticleDbTask::operator=(const ParticleDbTask & task)
{
  if (this!=&task)
    {
    Task::operator=(task);
    Manager<ParticleDb>::operator=(task);
    dbImport = task.dbImport;
    dbImportPath = task.dbImportPath;
    dbImportFile = task.dbImportFile;
    dbImportDecaysFile = task.dbImportDecaysFile;
    dbExport = task.dbExport;
    dbExportPath = task.dbExportPath;
    dbExportFile = task.dbExportFile;
    dbExportDecaysFile = task.dbExportDecaysFile;
    dbDisableNeutralParticles = task.dbDisableNeutralParticles;
    dbDisableChargedParticles = task.dbDisableChargedParticles;
    dbDisableSelected = task.dbDisableSelected;
    dbEnableAllParticles = task.dbEnableAllParticles;   // default value
    dbEnableNeutralParticles = task.dbEnableNeutralParticles;
    dbEnableChargedParticles = task.dbEnableChargedParticles;
    dbEnableSelected = task.dbEnableSelected;
    //
    dbDisableNeutralDecays = task.dbDisableNeutralDecays;
    dbDisableChargedDecays = task.dbDisableChargedDecays;
    dbDisableSelectedDecays = task.dbDisableSelectedDecays;
    dbDisableWeakDecays = task.dbDisableWeakDecays;
    dbDisableLongLivedDecays = task.dbDisableLongLivedDecays;
    dbDisableShortLivedDecays = task.dbDisableShortLivedDecays;
    //
    dbEnableAllDecays = task.dbEnableAllDecays;  // default value
    dbEnableNeutralDecays = task.dbEnableNeutralDecays;
    dbEnableChargedDecays = task.dbEnableChargedDecays;
    dbEnableSelectedDecays = task.dbEnableSelectedDecays;
    dbEnableWeakDecays = task.dbEnableWeakDecays;
    dbEnableLongLivedDecays = task.dbEnableLongLivedDecays;
    dbEnableShortLivedDecays = task.dbEnableShortLivedDecays;
    dbMaxLifeTime = task.dbMaxLifeTime;
    particleDb = task.particleDb;
    }
  return *this;
}


void ParticleDbTask::setDefaultConfiguration()
{
  Task::setDefaultConfiguration();
  addProperty("DbImport",            dbImport);
  addProperty("DbImportPath",        dbImportPath);
  addProperty("DbImportFile",        dbImportFile);
  addProperty("DbImportDecaysFile",  dbImportDecaysFile);
  addProperty("DbExport",            dbExport);
  addProperty("DbExportPath",        dbExportPath);
  addProperty("DbExportFile",        dbExportFile);
  addProperty("DbExportDecaysFile",  dbExportDecaysFile);

  addProperty("DbDisableNeutralParticles",dbDisableNeutralParticles);
  addProperty("DbDisableChargedParticles",dbDisableChargedParticles);
  addProperty("DbDisableSelected",        dbDisableSelected);
  addProperty("DbEnableAllParticles",     dbEnableAllParticles);
  addProperty("DbEnableNeutralParticles", dbEnableNeutralParticles);
  addProperty("DbEnableChargedParticles", dbEnableChargedParticles);
  addProperty("DbEnableSelected",         dbEnableSelected);

  addProperty("DbDisableNeutralDecays",   dbDisableNeutralDecays);
  addProperty("DbDisableChargedDecays",   dbDisableChargedDecays);
  addProperty("DbDisableSelectedDecays",  dbDisableSelectedDecays);
  addProperty("DbDisableWeakDecays",      dbDisableWeakDecays);
  addProperty("DbDisableLongLivedDecays", dbDisableLongLivedDecays);
  addProperty("DbDisableShortLivedDecays",dbDisableShortLivedDecays);

  addProperty("DbEnableAllDecays",        dbEnableAllDecays);
  addProperty("DbEnableNeutralDecays",    dbEnableNeutralDecays);
  addProperty("DbEnableChargedDecays",    dbEnableChargedDecays);
  addProperty("DbEnableSelectedDecays",   dbEnableSelectedDecays);
  addProperty("DbEnableWeakDecays",       dbEnableWeakDecays);
  addProperty("DbEnableLongLivedDecays",  dbEnableLongLivedDecays);
  addProperty("DbEnableShortLivedDecays", dbEnableShortLivedDecays);
  addProperty("DbMaxLifeTime",            dbMaxLifeTime);

  // Setup disabling selected particles
  String none("none");
  for (int k=0; k<40; k++)
    {
    String s = "DbDisable"; s += k;
    addProperty(s,none);
    }

  // Setup enabling selected particles
  for (int k=0; k<40; k++)
    {
    String s = "DbEnable"; s += k;
    addProperty(s,none);
    }

  // Setup decay disabling of selected particles
  for (int k=0; k<40; k++)
    {
    String s = "DbDisableDecay"; s += k;
    addProperty(s,none);
    }

  // Setup decay enabling of selected particles
  for (int k=0; k<40; k++)
    {
    String s = "DbEnableDecay"; s += k;
    addProperty(s,none);
    }
}


void ParticleDbTask::configure()
{
  Task::configure();
  printValue("ParticleDbTask::configure() Parent Name:", getParentName() );
  printValue("ParticleDbTask::configure() Name:", getName() );

  dbImport            = getValueBool(  "DbImport"           );
  dbImportPath        = getValueString("DbImportPath"       );
  dbImportFile        = getValueString("DbImportFile"       );
  dbImportDecaysFile  = getValueString("DbImportDecaysFile" );
  dbExport            = getValueBool(  "DbExport"           );
  dbExportPath        = getValueString("DbExportPath"       );
  dbExportFile        = getValueString("DbExportFile"       );
  dbExportDecaysFile  = getValueString("DbExportDecaysFile" );

  // dbDisableAllParticles     = getValueBool(  "DbDisableAllParticles"       );
  dbDisableNeutralParticles = getValueBool(  "DbDisableNeutralParticles"   );
  dbDisableChargedParticles = getValueBool(  "DbDisableChargedParticles"   );
  dbDisableSelected         = getValueBool(  "DbDisableSelected"           );

  dbEnableAllParticles      = getValueBool(  "DbEnableAllParticles"        );
  dbEnableNeutralParticles  = getValueBool(  "DbEnableNeutralParticles"    );
  dbEnableChargedParticles  = getValueBool(  "DbEnableChargedParticles"    );
  dbEnableSelected          = getValueBool(  "DbEnableSelected"            );

  dbDisableNeutralDecays    = getValueBool(  "DbDisableNeutralDecays"      );
  dbDisableChargedDecays    = getValueBool(  "DbDisableChargedDecays"      );
  dbDisableSelectedDecays   = getValueBool(  "DbDisableSelectedDecays"     );
  dbDisableWeakDecays       = getValueBool(  "DbDisableWeakDecays"         );
  dbDisableLongLivedDecays  = getValueBool(  "DbDisableLongLivedDecays"    );
  dbDisableShortLivedDecays = getValueBool(  "DbDisableShortLivedDecays"   );

  dbEnableAllDecays         = getValueBool(  "DbEnableAllDecays"           );
  dbEnableNeutralDecays     = getValueBool(  "DbEnableNeutralDecays"       );
  dbEnableChargedDecays     = getValueBool(  "DbEnableChargedDecays"       );
  dbEnableSelectedDecays    = getValueBool(  "DbEnableSelectedDecays"      );
  dbEnableWeakDecays        = getValueBool(  "DbEnableWeakDecays"          );
  dbEnableLongLivedDecays   = getValueBool(  "DbEnableLongLivedDecays"     );
  dbEnableShortLivedDecays  = getValueBool(  "DbEnableLongLivedDecays"     );
  dbMaxLifeTime             = getValueDouble("DbMaxLifeTime"               );

  if (reportDebug(__FUNCTION__))
    {
    cout << endl;
    printValue("DbImport"           ,dbImport);
    printValue("DbImportPath"       ,dbImportPath);
    printValue("DbImportFile"       ,dbImportFile);
    printValue("DbImportDecaysFile" ,dbImportDecaysFile);
    printValue("DbExport"           ,dbExport);
    printValue("DbExportPath"       ,dbExportPath);
    printValue("DbExportFile"       ,dbExportFile);
    printValue("DbExportDecaysFile" ,dbExportDecaysFile);


    printValue("DbEnableAllParticles"     ,dbEnableAllParticles);
    printValue("DbEnableNeutralParticles" ,dbEnableNeutralParticles);
    printValue("DbEnableChargedParticles" ,dbEnableChargedParticles);
    printValue("DbEnableSelected"         ,dbEnableSelected);
    printValue("DbDisableNeutralParticles",dbDisableNeutralParticles);
    printValue("DbDisableChargedParticles",dbDisableChargedParticles);
    printValue("DbDisableSelected"        ,dbDisableSelected);

    printValue("DbEnableAllDecays",        dbEnableAllDecays);
    printValue("DbEnableSelectedDecays"   ,dbEnableSelectedDecays);
    printValue("DbEnableNeutralDecays"    ,dbEnableNeutralDecays);
    printValue("DbEnableChargedDecays"    ,dbEnableChargedDecays);
    printValue("DbEnableWeakDecays"       ,dbEnableWeakDecays);
    printValue("DbEnableLongLivedDecays"  ,dbEnableLongLivedDecays);
    printValue("DbEnableShortLivedDecays" ,dbEnableShortLivedDecays);
    printValue("DbMaxLifeTime"            ,dbMaxLifeTime);
    printValue("DbDisableNeutralDecays"   ,dbDisableNeutralDecays);
    printValue("DbDisableChargedDecays"   ,dbDisableChargedDecays);
    printValue("DbDisableSelectedDecays"  ,dbDisableSelectedDecays);
    printValue("DbDisableWeakDecays"      ,dbDisableWeakDecays);
    printValue("DbDisableLongLivedDecays" ,dbDisableLongLivedDecays);
    printValue("DbDisableShortLivedDecays",dbDisableShortLivedDecays);
    for (int k=0; k<40; k++)
      {
      String s = "DbEnable"; s += k;
      cout << k << "   " << s << "  :  " << getValueString(s) << endl;;
      }
    for (int k=0; k<40; k++)
      {
      String s = "DbDisable"; s += k;
      cout << k << "   " << s << "  :  " << getValueString(s) << endl;;
      }
    for (int k=0; k<40; k++)
      {
      String s = "DbDisableDecay"; s += k;
      cout << k << "   " << s << "  :  " << getValueString(s) << endl;;
      }
    for (int k=0; k<40; k++)
      {
      String s = "DbEnableDecay"; s += k;
      cout << k << "   " << s << "  :  " << getValueString(s) << endl;;
      }
    cout << endl;
    }
}

void ParticleDbTask::execute()
{  }

void ParticleDbTask::initialize()
{
  Task::initialize();
  particleDb = Manager<ParticleDb>::getObjectAt(0);
  importParticleDb();

  if (dbEnableAllParticles)
    {
    enableAllParticles(); // default
    if (dbDisableNeutralParticles) disableNeutralParticles();
    if (dbDisableChargedParticles) disableChargedParticles();
    if (dbDisableSelected)         disableSelectedParticles();
    }
  else
    {
    disableAllParticles();
    if (dbEnableNeutralParticles) enableNeutralParticles();
    if (dbEnableChargedParticles) enableChargedParticles();
    if (dbEnableSelected)         enableSelectedParticles();
    }


  if (dbEnableAllDecays)
    {
    enableAllDecays(); // default
    if (dbDisableNeutralDecays)    disableNeutralDecays();
    if (dbDisableChargedDecays)    disableChargedDecays();
    if (dbDisableWeakDecays)       disableWeakDecays();
    if (dbDisableLongLivedDecays)  disableLongLivedWith(dbMaxLifeTime);
    if (dbDisableShortLivedDecays) disableShortLivedWith(dbMaxLifeTime);
    if (dbDisableSelectedDecays)   disableSelectedDecays(); // default
    }
  else
    {
    disableAllDecays();
    if (dbEnableNeutralDecays)    enableNeutralDecays();
    if (dbEnableChargedDecays)    enableChargedDecays();
    if (dbEnableWeakDecays)       enableWeakDecays();
    if (dbEnableLongLivedDecays)  enableLongLivedWith(dbMaxLifeTime);
    if (dbEnableShortLivedDecays) enableShortLivedWith(dbMaxLifeTime);
    if (dbEnableSelectedDecays)   enableSelectedDecays();
    }
  printString("Successfully initiated particleDb");

}

void ParticleDbTask::finalize()
{

}

//!
//!Import particle data from DB files.
//!mass, width are in GeV
//!The files were originally from Therminator
//!The files are assumed to be at:
//!    taskDbPath/dbImportPath
//! The variable taskDbPath is set as an environment variable
//! The variable dbImportPath is set in the project file
//!
void ParticleDbTask::importParticleDb()
{
  String dbPath = getEnvVariable("CAP_DATABASE_PATH");
  dbPath += "/";
  dbPath += dbImportPath;
  if (reportInfo(__FUNCTION__))
    {
    printCR();
    printLine();
    printValue("DB Path",dbPath);
    printValue("DB Particle File",dbImportFile);
    printValue("DB Decay File",dbImportDecaysFile);
    printLine();
    }
  ifstream & inputFile = openInputAsciiFile(dbPath,dbImportFile,".data");
  ifstream & inputFileDecays = openInputAsciiFile(dbPath,dbImportDecaysFile,".data");
  ParticleDbParser parser;
  parser.readDb(*particleDb,inputFile,inputFileDecays);
  inputFile.close();
  inputFileDecays.close();
  particleDb->mapAntiParticleIndices();
  particleDb->setupDecayGenerator();
  particleDb->setName("DefaultParticleDb");
  particleDb->setTitle("DefaultParticleDb");
  printValue("Successfully loaded particleDb",particleDb->getName());
}

void ParticleDbTask::exportParticleDb()
{
  // TO be developed...
}

void ParticleDbTask::dbAnalyzer()
{
  // check for charge, strangeness, and baryon number conservation...
  //ParticleDb * particleDb = getDefaultParticleDb();
  if (particleDb==nullptr) throw TaskException("particleDb==nullptr","DbTask::dbAnalyzer()");

  unsigned int nTypes = particleDb->size();
  // check for double pdg entries
  int count = 0;
  for (unsigned int iType=0; iType<nTypes; iType++)
    {

    ParticleType * particleType = particleDb->getParticleType(iType);
    int     pdg     = particleType->getPdgCode();
    //    double  charge  = particleType->getCharge();
    //    double  strange = particleType->getStrangeness();
    //    double  baryon  = particleType->getBaryonNumber();
    count = 0;
    for (unsigned int kType=0; kType<nTypes; kType++)
      {
      ParticleType * particleType2 = particleDb->getParticleType(kType);
      int     pdg2     = particleType2->getPdgCode();
      //      double  charge2  = particleType2->getCharge();
      //      double  strange2 = particleType2->getStrangeness();
      //      double  baryon2  = particleType2->getBaryonNumber();
      if (pdg == pdg2) count++;
      }
    if (count>1)
      {
      cout << "iType: " << iType << " Count: " << count << endl;
      cout << " name1: " << particleType->getName() << "   PDG:" <<pdg<< endl;
      //cout << " name2: " << particleType2->getName() << endl;
      }
    }

  for (unsigned int iType=0; iType<nTypes; iType++)
    {
    ParticleType * type = particleDb->getParticleType(iType);
    String  name    = type->getName();
    int     pdg     = type->getPdgCode();
    double  charge  = type->getCharge();
    double  strange = type->getStrangeness();
    double  baryon  = type->getBaryonNumber();
    bool    stable  = type->isStable();
    int     nModes  = type->getNDecayModes();
    if (stable) continue;
    if (nModes<1) throw TaskException("nModes<1 && !isStable()","DbTask::dbAnalyzer()");

    cout << "Analysing particle named: " << name << " PDG Index:" << pdg << endl;
    cout << "    Charge: " << charge << endl;
    cout << "   Strange: " << strange << endl;
    cout << "    Baryon: " << baryon << endl;
    cout << "    Stable: " << stable << endl;
    cout << "    nModes: " << nModes << endl;

    std::vector<ParticleDecayMode> decayModes =  type->getDecayModes();

    for (int iMode=0; iMode<nModes; iMode++)
      {
      ParticleDecayMode & decayMode = decayModes[iMode];
      int nChildren = decayMode.getNChildren();
      //cout << "Decay mode: " << iMode << "  nChildren: " << nChildren << endl;

      switch (nChildren)
        {
          case 1:
          {
          String s = "Single particle decay for ";
          s += name;
          throw TaskException(s,"DbTask::dbAnalyzer()");
          }

          case 2:
          {
          ParticleType  & childType1 = decayMode.getChildType(0);
          ParticleType  & childType2 = decayMode.getChildType(1);
          String name1 = childType1.getName();
          String name2 = childType2.getName();
          double sumCharge  = childType1.getCharge()          + childType2.getCharge();
          double sumStrange = childType1.getStrangeness() + childType2.getStrangeness();
          double sumBaryon  = childType1.getBaryonNumber()    + childType2.getBaryonNumber();
          if (charge!=sumCharge || strange!=sumStrange || baryon!=sumBaryon)
            {
            cout << "Check sanity!!!" << endl;
            cout << "Analysing particle named: " << name << " PDG Index:" << pdg << endl;
            //    cout << "    Charge: " << charge << endl;
            //    cout << "   Strange: " << strange << endl;
            //    cout << "    Baryon: " << baryon << endl;
            //    cout << "    Stable: " << stable << endl;
            //    cout << "    nModes: " << nModes << endl;
            cout << name << "  -->  " << name1 << "  +  " << name2 << endl;
            cout << " Charge: " << charge <<  "    sumCharge: " << sumCharge << endl;
            cout << "Strange: " << strange << "   sumStrange: " << sumStrange << endl;
            cout << " Baryon: " << baryon <<  "   sumBaryon: " << sumBaryon << endl;
            }
          break;
          }

          case 3:
          {
          ParticleType  & childType1 = decayMode.getChildType(0);
          ParticleType  & childType2 = decayMode.getChildType(1);
          ParticleType  & childType3 = decayMode.getChildType(2);
          String name1 = childType1.getName();
          String name2 = childType2.getName();
          String name3 = childType3.getName();
          double sumCharge  = childType1.getCharge()          + childType2.getCharge()+ childType3.getCharge();
          double sumStrange = childType1.getStrangeness() + childType2.getStrangeness()+ childType3.getStrangeness();
          double sumBaryon  = childType1.getBaryonNumber()    + childType2.getBaryonNumber()+ childType3.getBaryonNumber();
          if (charge!=sumCharge || strange!=sumStrange || baryon!=sumBaryon)
            {
            cout << "ERROR!!!!!!!!!!!" << endl;
            cout << "Analysing particle named: " << name << " PDG Index:" << pdg << endl;
            cout << name << "  -->  " << name1 << "  +  " << name2 << "  +  " << name3 << endl;
            cout << " Charge: " << charge <<  "    sumCharge: " << sumCharge << endl;
            cout << "Strange: " << strange << "   sumStrange: " << sumStrange << endl;
            cout << " Baryon: " << baryon <<  "   sumBaryon: " << sumBaryon << endl;
            }
          break;
          }
        }

      }
    }
}

void ParticleDbTask::enableAllParticles()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  const vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    {
    if (!particleType) particleType->enable();
    }
}

void ParticleDbTask::enableNeutralParticles()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes) 
    if (particleType->isNeutral()) particleType->enable();
}

void ParticleDbTask::enableChargedParticles()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    if (particleType->isCharged()) particleType->enable();
}

void ParticleDbTask::enableSelectedParticles()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  String none("none");
  for (int k=0; k<40; k++)
    {
    String s = "DbEnable"; s += k;
    String particleName = getValueString(s);
    if (particleName.EqualTo(none)) continue;
    ParticleType * type = particleDb->getParticleType(particleName);
    if (!type)
      {
      String except = "No Particle called ";
      except += particleName;
      throw TaskException(s,"DbTask::enableSelectedParticles()");
      }
    type->enable();
    }
}

void ParticleDbTask::disableAllParticles()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes) particleType->disable();
}

void ParticleDbTask::disableNeutralParticles()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    if (particleType->isNeutral()) particleType->disable();
}

void ParticleDbTask::disableChargedParticles()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    if (particleType->isCharged()) particleType->disable();
}

void ParticleDbTask::disableSelectedParticles()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  // Setup parameters to enable disabling selected particles
  String none("none");
  for (int k=0; k<40; k++)
    {
    String s = "DbDisable"; s += k;
    String particleName = getValueString(s);
    if (particleName.EqualTo(none)) continue;
    ParticleType * type = particleDb->getParticleType(particleName);
    type->disable();
    }
}

void ParticleDbTask::disableAllDecays()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes) particleType->disableDecay();
}

void ParticleDbTask::disableNeutralDecays()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes) 
    {
    if (particleType->isNeutral())
      particleType->disableDecay();
    else
      particleType->enableDecay();
    }
}

void ParticleDbTask::disableChargedDecays()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    {
    if (particleType->isCharged())
      particleType->disableDecay();
    else
      particleType->enableDecay();
    }
}


void ParticleDbTask::disableWeakDecays()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<String> selectedParticles;
  // kaons
  selectedParticles.push_back( String("Ka0492zer")); // 311);   // neutral kaons
  selectedParticles.push_back( String("Ka0492zrb")); // -311);
  // lambda
  selectedParticles.push_back( String("Lm1115zer")); //  3122); // lambda
  selectedParticles.push_back( String("Lm1115zrb")); // -3122);
  // sigma
  selectedParticles.push_back( String("Sg1189min")); //  3112); // sigmas
  selectedParticles.push_back( String("Sg1189mnb")); // -3112);
  selectedParticles.push_back( String("Sg1192zer")); //  3212);
  selectedParticles.push_back( String("Sg1192zrb")); // -3212);
  selectedParticles.push_back( String("Sg1189plu")); //  3222);
  selectedParticles.push_back( String("Sg1189plb")); // -3222);
  // xi (cascade)
  selectedParticles.push_back( String("Xi1321min")); //  3312);  // cascades
  selectedParticles.push_back( String("Xi1321mnb")); // -3312);
  selectedParticles.push_back( String("Xi1321zer")); //  3322);
  selectedParticles.push_back( String("Xi1321zrb")); // -3322);
  // Omega
  selectedParticles.push_back( String("UM1672min")); //  3334);  // Omegas
  selectedParticles.push_back( String("UM1672mnb")); // -3334);

  for (auto & selectedParticle : selectedParticles)
    {
    ParticleType * type = particleDb->getParticleType(selectedParticle);
    type->disableDecay();
    }
}

void ParticleDbTask::disableLongLivedWith(double lifeTime)
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    {
    if (!particleType->isStable())
      {
      double tau = particleType->getLifeTime();
      if (tau>lifeTime) particleType->disableDecay();
      }
    }
}

void ParticleDbTask::disableShortLivedWith(double lifeTime)
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    {
    if (!particleType->isStable())
      {
      double tau = particleType->getLifeTime();
      if (tau<=lifeTime) particleType->disableDecay();
      }
    }
}


void ParticleDbTask::disableSelectedDecays()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  // Setup parameters to enable decay disable of selected particles
  String none("none");
  for (int k=0; k<40; k++)
    {
    String s = "DbDisableDecay"; s += k;
    String particleName = getValueString(s);
    if (particleName.EqualTo(none)) continue;
    ParticleType * type = particleDb->getParticleType(particleName);
    type->disableDecay();
    }
}

void ParticleDbTask::enableAllDecays()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes) particleType->enableDecay();
}

void ParticleDbTask::enableNeutralDecays()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    if (particleType->isNeutral())
      particleType->enableDecay();
    else
      particleType->disableDecay();
}

void ParticleDbTask::enableChargedDecays()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    if (particleType->isCharged())
      particleType->enableDecay();
    else
      particleType->disableDecay();
}

void ParticleDbTask::enableWeakDecays()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<String> selectedParticles;
  // kaons
  selectedParticles.push_back( String("Ka0492zer")); // 311);   // neutral kaons
  selectedParticles.push_back( String("Ka0492zrb")); // -311);
  // lambda
  selectedParticles.push_back( String("Lm1115zer")); //  3122); // lambda
  selectedParticles.push_back( String("Lm1115zrb")); // -3122);
  // sigma
  selectedParticles.push_back( String("Sg1189min")); //  3112); // sigmas
  selectedParticles.push_back( String("Sg1189mnb")); // -3112);
  selectedParticles.push_back( String("Sg1192zer")); //  3212);
  selectedParticles.push_back( String("Sg1192zrb")); // -3212);
  selectedParticles.push_back( String("Sg1189plu")); //  3222);
  selectedParticles.push_back( String("Sg1189plb")); // -3222);
  // xi (cascade)
  selectedParticles.push_back( String("Xi1321min")); //  3312);  // cascades
  selectedParticles.push_back( String("Xi1321mnb")); // -3312);
  selectedParticles.push_back( String("Xi1321zer")); //  3322);
  selectedParticles.push_back( String("Xi1321zrb")); // -3322);
  // Omega
  selectedParticles.push_back( String("UM1672min")); //  3334);  // Omegas
  selectedParticles.push_back( String("UM1672mnb")); // -3334);

  for (auto & selectedParticle : selectedParticles)
    {
    ParticleType * type = particleDb->getParticleType(selectedParticle);
    type->enableDecay();
    }
}

void ParticleDbTask::enableLongLivedWith(double lifeTime)
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    {
    if (particleType->isStable())
      {
      double tau = particleType->getLifeTime();
      if (tau>lifeTime) particleType->enableDecay();
      }
    }
}

void ParticleDbTask::enableShortLivedWith(double lifeTime)
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    {
    if (particleType->isStable())
      {
      double tau = particleType->getLifeTime();
      if (tau<lifeTime) particleType->enableDecay();
      }
    }
}


void ParticleDbTask::enableSelectedDecays()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  // Setup parameters to enable decay disable of selected particles
  String none("none");
  for (int k=0; k<40; k++)
    {
    String s = "DbEnableDecay"; s += k;
    String particleName = getValueString(s);
    if (particleName.EqualTo(none)) continue;
    ParticleType * type = particleDb->getParticleType(particleName);
    type->disableDecay();
    }
}

void ParticleDbTask::listParticleStatus()
{
  if (!particleDb) throw NoSelectedParticleDbException(__FUNCTION__);
  vector<ParticleType*> & particleTypes = particleDb->getParticleTypes();
  for (auto & particleType : particleTypes)
    {
    std::cout << particleType->getName();
    if (particleType->isEnabled())
      std::cout << "  Enabled: ";
    else
      std::cout << "  Disabled:";
    if (particleType->isStable())
      std::cout << "  Stable:  ";
    else
      std::cout << "  Unstable:";
    if (particleType->isDecayEnabled())
      std::cout << "  DecayEnabled";
    else
      std::cout << "  DecayDisabled";
    std::cout << std::endl;
    }
}

}
