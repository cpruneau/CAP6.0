#include "Exceptions.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "MathConstants.hpp"
#include "MathBasicFunctions.hpp"
#include "TROOT.h"
#include "TSystem.h"
#include "TParameter.h"
#include "TSystemDirectory.h"
#include "TRandom.h"

namespace CAP
{

//!
//!Open Root file at the given path and with the given file name
//!ioOption : OLD, NEW, RECREATE
//
TFile * openRootFile(const String & path,
                     const String & name,
                     const String & ioOption,
                     bool verbose)
{
  String fileName;
  if (name.BeginsWith("/"))
    fileName = name;
  else
    {
    String filePath = path;
    int slash = filePath.First('/');
    int len   = filePath.Length();
    if (len>0 && (len-1)!=slash) filePath += "/";
    fileName = filePath;
    fileName += name;
    }
  if (!fileName.EndsWith(".root")) fileName += ".root";
  if (verbose)
    {
    printCR();
    printValue("openRootFile(...) Opening file",fileName);
    printValue("ioOption",ioOption);
    }
  TFile * file = new TFile(fileName,ioOption);
  if (!file) throw  FileException(fileName,"File not found",__FUNCTION__);
  if (!file->IsOpen())  throw  FileException(fileName,"File not found/opened",__FUNCTION__);
  if (verbose) std::cout << "openRootFile(...) File opened successfully." << std::endl;
  return file;
}

TFile * openRootFile(const String & name,
                     const String & ioOption,
                     bool verbose)
{
  String fileName = name;
  if (!fileName.EndsWith(".root")) fileName += ".root";
  if (verbose)
    {
    printCR();
    printValue("openRootFile(...) Opening file",fileName);
    printValue("ioOption",ioOption);
    }
  TFile * file = new TFile(fileName,ioOption);
  if (!file) throw  FileException(fileName,"File not found","openRootFile()");
  if (!file->IsOpen())  throw  FileException(fileName,"File not found/opened",__FUNCTION__);
  if (verbose)
    {
    printCR();
    printValue("openRootFile(...) File opened successfully",fileName);
    }
  return file;
}

TFile * openOldRootFile(const String & name,
                        bool verbose)
{
  return openRootFile(name,"OLD",verbose);
}

TFile * openOldRootFile(const String & path,
                        const String & name,
                        bool verbose)
{
  return openRootFile(path,name,"OLD",verbose);
}

TFile * openNewRootFile(const String & name,
                        bool verbose)
{
  return openRootFile(name,"NEW",verbose);
}

TFile * openNewRootFile(const String & path,
                        const String & name,
                        bool verbose)
{
  return openRootFile(path,name,"NEW",verbose);
}

TFile * openRecreateRootFile(const String & name,
                             bool verbose)
{
  return openRootFile(name,"RECREATE",verbose);
}

TFile * openRecreateRootFile(const String & path,
                             const String & name,
                             bool verbose)
{
  return openRootFile(path,name,"RECREATE",verbose);
}

std::vector<TFile*> openRootFiles(std::vector<String> & names,
                                  const String   & ioOption,
                                  bool verbose)
{
  int nFiles = names.size();
  if (nFiles<1)  throw FileException("Empty file list","File not found/opened",__FUNCTION__);
  if (verbose)
    {
    printCR();
    printValue("openRootFiles(...) Opening N files",names.size());
    }
  std::vector<TFile*> files;
  for (auto & name : names)
    {
    files.push_back( openRootFile(name,ioOption,verbose));
    }
  if (verbose)
    {
    printCR();
    printString("openRootFiles(...) Completed successfully");
    }
  return files;
}

std::vector<TFile*> openRootFiles(const String & path,
                                  std::vector<String> & names,
                                  const String   & ioOption,
                                  bool verbose)
{
  int nFiles = names.size();
  if (nFiles<1)  throw  FileException("Empty file list","File not found/opened",__FUNCTION__);
  if (verbose)
    {
    printCR();
    printValue("openRootFiles(...) Opening N files",names.size());
    printValue("openRootFiles(...) Path",path);
    }
  std::vector<TFile*> files;
  for (auto & name : names)
    {
    files.push_back( openRootFile(path,name,ioOption,verbose));
    }
  if (verbose)  std::cout << "openRootInputFiles(...) Completed successfully" << std::endl;
  return files;
}

std::vector<TString> listDirsIn(const TString & pathname,
                                bool verbose)
{
  TString directoryName = pathname;
  std::vector<TString>  subdirectories;
  if (!directoryName.EndsWith("/")) directoryName += "/";
  if (verbose) printValue("listDirsIn() Search path",pathname);
  TSystemDirectory topDirectory(directoryName, directoryName);
  TList *files = topDirectory.GetListOfFiles();
  if (!files) throw FileException("TList* is a nullpointer","File not found/opened",__FUNCTION__);
  TSystemFile *file;
  TString fname;
  TIter next(files);
  while ((file=(TSystemFile*) next()) )
    {
    fname = file->GetName();
    if (file->IsDirectory()   && !fname.BeginsWith(".")  ) subdirectories.push_back(fname);
    }
  return subdirectories;
}


std::vector<String> listFilesInDir(const String & pathname,
                                   const String & ext,
                                   bool prependPath,
                                   bool verbose,
                                   int  maximumDepth,
                                   int  currentDepth)
{
  String dirname = pathname;
  int depth = currentDepth;
  if (!dirname.EndsWith("/")) dirname += "/";
  if (verbose)
    {
    printCR();
    printString("listFilesInDir() Searching files");
    printValue("listFilesInDir() MaximumDepth:",maximumDepth);
    printValue("listFilesInDir() CurrentDepth:",depth);
    }
  TSystemDirectory dir(dirname, dirname);
  TList *files = dir.GetListOfFiles();
  std::vector<String>  fileNames;
  std::vector<String>  subdirs;
  if (!files) throw FileException("Null TList","No files found", __FUNCTION__);
  TSystemFile *file;
  String fname;
  TIter next(files);
  while ((file=(TSystemFile*)next()))
    {
    fname = file->GetName();
    if (file->IsDirectory() &&  !fname.BeginsWith(".") )
      {
      subdirs.push_back(fname);
      }
    else if (fname.EndsWith(ext))
      {
      if (prependPath)
        fileNames.push_back(dirname+fname);
      else
        fileNames.push_back(fname);
      //std::cout << fname.Data() << std::endl;
      //if (verbose) std::cout << fname << std::endl;
      }
    }

  int nSubdirs = subdirs.size();
  ++depth;
  if (nSubdirs>0 && depth<=maximumDepth)
    {
    for (int iDir=0; iDir<nSubdirs; iDir++)
      {
      std::vector<String> additionalFiles;
      String  subdirname = dirname;
      subdirname += "/";
      subdirname += subdirs[iDir];
      subdirname += "/";
      additionalFiles = listFilesInDir(subdirname,ext,prependPath,verbose,maximumDepth,depth);
      int nAdditionalfiles = additionalFiles.size();
      for (int iFile=0;iFile<nAdditionalfiles;iFile++)
        fileNames.push_back(additionalFiles[iFile]);
      }
    }
  if (verbose)
    {
    printCR();
    printValue("listFilesInDir() Number of files found",fileNames.size());
    for (Size_t k=0; k<fileNames.size();k++)
      {
      String s = "File "; s += k;
      printValue(s,fileNames[k]);
      }
    printString("Returning up one level.... ");
    }
  return fileNames;
}

//!
//! Get file  names at the given location that match all  patterns in includePatterns and exclude patterns in excludePatterns
//!
std::vector<String>  listFilesInDir(const String & pathName,
                                    const std::vector<String> & includePatterns,
                                    const std::vector<String> & excludePatterns,
                                    bool prependPath,
                                    bool verbose,
                                    int  maximumDepth,
                                    int  currentDepth)
{
  std::vector<String> outputList;
  std::vector<String> fileList = listFilesInDir(pathName,".root",prependPath,verbose,maximumDepth,currentDepth);
  unsigned int nNames = fileList.size();
  if (verbose)
    {
    printCR();
    printValue("nNames",nNames);
    printValue("nIncludes",includePatterns.size());
    printValue("nExcludes",excludePatterns.size());
    }

  for (auto & name : fileList)
    {
    bool include = true;
    for (auto & pattern : includePatterns)
      if (!name.Contains(pattern)) { include = false; break;}
    if (!include) continue;
    for (auto & pattern : excludePatterns)
      if (!name.Contains(pattern)) { include = false; break;}
    if (include)
      {
      if (name.Contains(".root"))
        {
        int dot = name.First('.');
        int len = name.Length();
        if (dot==len-5 )
          name.Remove(dot,len-dot);
        }
      //String check = pathName+name;
      //std::cout << " CHECK:::: " << check << std::endl;
      outputList.push_back(name);
      }
    }
  return outputList;
}

//std::vector<String> getSelectedFileNamesFrom(const String & folder)
//{
//  std::vector<String> includePatterns;
//  std::vector<String> excludePatterns;
//  std::vector<String> selectedNames;
//  for (int k=0; k<20; k++)
//  {
//    String key = "IncludedPattern"; key += k;
//    String  value = getValueString(key);
//    if (!value.Contains("none")) includePatterns.push_back(value);
//  }
//  for (int k=0; k<20; k++)
//  {
//    String key = "ExcludedPattern"; key += k;
//    String  value = getValueString(key);
//    if (!value.Contains("none")) excludePatterns.push_back(value);
//  }
//  return listFilesInDir(folder,includePatterns,excludePatterns);
//}

String removeRootExtension(const String fileName)
{
  String name = fileName;
  int dot = name.Last('.');
  int len = name.Length();
  if (dot==len-5 ) name.Remove(dot,len-dot);
  return name;
}

void exportParameter(TFile & outputFile,
                     const String & parameterName,
                     long value,
                     bool verbose)
{
  if (verbose)
    {
    printCR();
    printValue("exportParameter() output file",outputFile.GetName());
    printValue("exportParameter() parameterName",parameterName);
    printValue("exportParameter() value",value);
    }
  outputFile.cd();
  TParameter<Long64_t>(parameterName,value,'+').Write();
}

long importParameter(TFile & inputFile,
                     const String & parameterName,
                     bool verbose)
{
  TParameter<Long64_t> *par = (TParameter<Long64_t> *) inputFile.Get(parameterName);
  if (!par)
    {
    if (verbose)
      {
      printCR();
      printValue("importParameter() input file",inputFile.GetName());
      printValue("importParameter() Property not found:",parameterName);
      }
    throw FileException(parameterName,"Property not found",__FUNCTION__);
    }
  double value = par->GetVal();
  delete par;
  if (verbose)
    {
    printCR();
    printValue("importParameter() parameterName",parameterName);
    printValue("importParameter() value",value);
    }
  return value;
}

CAP::String makeFileName(const String & inputPath,
                         const String & fileName,
                         const String & extension)
{
  String inputFileName = inputPath;
  // make sure that if an inputPath is given, it ends with '/'
  int slash = inputFileName.First('/');
  int len   = inputFileName.Length();
  //  std::cout << slash << std::endl;
  //  std::cout << len << std::endl;
  if (len>0 && (len-1)!=slash) inputFileName += "/";
  inputFileName += fileName;
  if (!inputFileName.EndsWith(extension)) inputFileName += extension;
  return inputFileName;
}

void createDirectory(const String path,
                     bool verbose)
{
  if (verbose)
    {
    printCR();
    printValue("createDirectory(const String path) Creating directory (if non-existing)",path);
    }
  gSystem->mkdir(path,1);
}

String substitute(const String & inputString,
                  const String & subString,
                  const String & newSubString)
{
  String outputString(inputString);
  outputString.ReplaceAll(subString,newSubString);
  return outputString;
}

TH1 * createNewHistogram(const String & name,
                         int n_x, double min_x, double max_x,
                         const String & title_x,
                         const String & title_y,
                         int storageOption,
                         bool verbose)
{
  if (verbose)  printHistoInfo(__FUNCTION__,name,n_x,min_x,max_x);
  TH1 * h;
  switch (storageOption)
    {
      case 0: h = new TH1I(name,name,n_x,min_x,max_x); break;
      case 1: h = new TH1F(name,name,n_x,min_x,max_x); break;
      case 2: h = new TH1D(name,name,n_x,min_x,max_x); break;
      default:
      throw HistogramException(name,"Invalid Storage Option (1D)",__FUNCTION__);
    }
  setTitles(h,title_x,title_y);
  return h;
}

//!
//! Create 1D histogram
//!
TH1 * createNewHistogram(const String & name,
                         int n_x, double * bins,
                         const String & title_x,
                         const String & title_y,
                         int storageOption,
                         bool verbose)
{
  if (verbose)  printHistoInfo(__FUNCTION__,name,n_x,bins[0],bins[1]);
  TH1 * h;
  switch (storageOption)
    {
      case 0: h = new TH1I(name,name,n_x,bins); break;
      case 1: h = new TH1F(name,name,n_x,bins); break;
      case 2: h = new TH1D(name,name,n_x,bins); break;
      default:
      throw HistogramException(name,"Invalid Storage Option (1DV)",__FUNCTION__);
    }
  setTitles(h,title_x,title_y);
  return h;
}

//!
//! Create 2D histogram
//!
TH2 * createNewHistogram(const String & name,
                         int n_x, double min_x, double max_x,
                         int n_y, double min_y, double max_y,
                         const String & title_x,
                         const String & title_y,
                         const String & title_z,
                         int storageOption,
                         bool verbose )
{
  if (verbose) printHistoInfo(__FUNCTION__,name,n_x,min_x,max_x,n_y,min_y,max_y);
  TH2 * h;
  switch (storageOption)
    {
      case 0: h = new TH2I(name,name,n_x,min_x,max_x,n_y,min_y,max_y);  break;
      case 1: h = new TH2F(name,name,n_x,min_x,max_x,n_y,min_y,max_y);  break;
      case 2: h = new TH2D(name,name,n_x,min_x,max_x,n_y,min_y,max_y);  break;
      default:
      throw HistogramException(name,"Invalid Storage Option (2D)",__FUNCTION__);
    }
  setTitles(h,title_x,title_y,title_z);
  return h;
}

//!
// Create 2D histogram
//!
TH2 * createNewHistogram(const String & name,
                         int n_x, double* xbins, int n_y, double min_y, double max_y,
                         const String & title_x,
                         const String & title_y,
                         const String & title_z,
                         int storageOption,
                         bool verbose)
{

  if (verbose) printHistoInfo(__FUNCTION__,name,n_x,xbins[0],xbins[1],n_y,min_y,max_y);
  TH2 * h;
  switch (storageOption)
    {
      case 0: h = new TH2I(name,name,n_x,xbins,n_y,min_y,max_y); break;
      case 1: h = new TH2F(name,name,n_x,xbins,n_y,min_y,max_y); break;
      case 2: h = new TH2D(name,name,n_x,xbins,n_y,min_y,max_y); break;
      default:
      throw HistogramException(name,"Invalid Storage Option (2DV)",__FUNCTION__);
    }
  setTitles(h,title_x,title_y,title_z);
  return h;
}


//!
// Create 3D histogram
//!
TH3 * createNewHistogram(const String & name,
                         int n_x, double min_x, double max_x,
                         int n_y, double min_y, double max_y,
                         int n_z, double min_z, double max_z,
                         const String & title_x,
                         const String & title_y,
                         const String & title_z,
                         const String & title_w,
                         int storageOption,
                         bool verbose)
{

  if (verbose) printHistoInfo(__FUNCTION__,name,n_x,min_x,max_x,n_y,min_y,max_y,n_z,min_z,max_z);
  TH3 * h;
  switch (storageOption)
    {
      case 0: h = new TH3I(name,name,n_x,min_x,max_x,n_y,min_y,max_y,n_z,min_z,max_z); break;
      case 1: h = new TH3F(name,name,n_x,min_x,max_x,n_y,min_y,max_y,n_z,min_z,max_z); break;
      case 2: h = new TH3D(name,name,n_x,min_x,max_x,n_y,min_y,max_y,n_z,min_z,max_z); break;
      default:
      throw HistogramException(name,"Invalid Storage Option (3D)",__FUNCTION__);
    }
  setTitles(h,title_x,title_y,title_z,title_w);
  return h;
}

//!
//! Create 1D profile histogram
//!
TProfile * createNewProfile(const String & name,
                            int n_x,double min_x,double max_x,
                            const String & title_x,
                            const String & title_y,
                            bool verbose)
{

  if (verbose) printHistoInfo(__FUNCTION__,name,n_x,min_x,max_x);
  TProfile * h = new TProfile(name,name,n_x,min_x,max_x);
  setTitles(h,title_x,title_y);
  return h;
}

//!
// Create 1D profile histogram
//!
TProfile * createNewProfile(const String & name,
                            int n_x,  double* bins,
                            const String & title_x,
                            const String & title_y,
                            bool verbose)
{
  if (verbose) printHistoInfo(__FUNCTION__,name,n_x,bins[0],bins[1]);
  TProfile * h = new TProfile(name,name,n_x,bins);
  setTitles(h,title_x,title_y);
  return h;
}

//!
//! Create 2D profile histogram
//!
TProfile2D * createNewProfile(const String & name,
                              int n_x, double min_x, double max_x,
                              int n_y, double min_y, double max_y,
                              const String & title_x,
                              const String & title_y,
                              const String & title_z,
                              bool verbose)
{

  if (verbose) printHistoInfo(__FUNCTION__,name,n_x,min_x,max_x,n_y,min_y,max_y);
  TProfile2D * h = new TProfile2D(name,name,n_x,min_x,max_x,n_y,min_y,max_y);
  setTitles(h,title_x,title_y,title_z);
  return h;
}





void squareDifferenceHistos(TH1 *h1, TH1 *h2, double sumWeights, double weight, int n)
{
//  if (n>0)
//    {
//    printCR();
//    printLine();
//    printValue("squareDifferenceHistos n",n);
//    }
  double vAvg, evAvg, evSqAvg;
  double v,  dv;
  double sum = weight + sumWeights;
  double rwn = weight/sum;
  double rw  = sumWeights/sum;
  double sqrtN = sqrt(double(abs(n)));
  if (h1->IsA()==TH1::Class() || h1->IsA()==TH1F::Class() || h1->IsA()==TH1D::Class() || h1->IsA()==TH1I::Class() )
    {
    int nx = h1->GetNbinsX();
    for (int ix=1; ix<=nx; ix++)
      {
      vAvg    = h1->GetBinContent(ix);
      evAvg   = h1->GetBinError(ix);
      v       = h2->GetBinContent(ix);
      evSqAvg = evAvg*evAvg;
      dv      = v - vAvg;
      vAvg    += rwn*dv;
      evSqAvg = rw*(evSqAvg + dv*dv*rwn);
      evAvg   = n>0 ? sqrt(evSqAvg)/sqrtN : sqrt(evSqAvg);
      h1->SetBinContent(ix, vAvg);
      h1->SetBinError(ix, evAvg);
      }
    }
  else if (h1->IsA()==TH2::Class() || h1->IsA()==TH2F::Class() || h1->IsA()==TH2D::Class() || h1->IsA()==TH2I::Class() )
    {
    int nx = h1->GetNbinsX();
    int ny = h1->GetNbinsY();
    for (int iy=1; iy<=ny; iy++)
      {
      for (int ix=1; ix<=nx; ix++)
        {
        vAvg    = h1->GetBinContent(ix,iy);
        evAvg   = h1->GetBinError(ix,iy);
        v       = h2->GetBinContent(ix,iy);
        evSqAvg = evAvg*evAvg;
        dv      = v - vAvg;
        vAvg    += rwn*dv;
        evSqAvg = rw*(evSqAvg + dv*dv*rwn);
        evAvg   = n>0 ? sqrt(evSqAvg)/sqrtN : sqrt(evSqAvg);
        h1->SetBinContent(ix,iy, vAvg);
        h1->SetBinError(ix,iy,evAvg);
        }
      }
    }
  else if (h1->IsA()==TH3::Class() || h1->IsA()==TH3F::Class() || h1->IsA()==TH3D::Class() || h1->IsA()==TH3I::Class() )
    {
    int nx = h2->GetNbinsX();
    int ny = h2->GetNbinsY();
    int nz = h2->GetNbinsZ();
    for (int iz=1; iz<=nz; iz++)
      {
      for (int iy=1; iy<=ny; iy++)
        {
        for (int ix=1; ix<=nx; ix++)
          {
          vAvg    = h1->GetBinContent(ix,iy,iz);
          evAvg   = h1->GetBinError(ix,iy,iz);
          v       = h2->GetBinContent(ix,iy,iz);
          evSqAvg = evAvg*evAvg;
          dv      = v - vAvg;
          vAvg    += rwn*dv;
          evSqAvg = rw*(evSqAvg + dv*dv*rwn);
          evAvg   = n>0 ? sqrt(evSqAvg)/sqrtN : sqrt(evSqAvg);
          h1->SetBinContent(ix,iy,iz, vAvg);
          h1->SetBinError(ix,iy,iz,evAvg);
          }
        }
      }
    }
  else if (h1->IsA()==TProfile::Class() )
    {
    int nx = h1->GetNbinsX();
    for (int ix=1; ix<=nx; ix++)
      {
      vAvg  = h1->GetBinContent(ix);
      evAvg = h1->GetBinError(ix);
      v     = h2->GetBinContent(ix);
      evSqAvg = evAvg*evAvg;
      evAvg   = n>0 ? sqrt(evSqAvg)/sqrtN : sqrt(evSqAvg);
      dv      = v - vAvg;
      vAvg    += rwn*dv;
      evSqAvg = rw*(evSqAvg + dv*dv*rwn);
      evAvg   = n>0 ? sqrt(evSqAvg)/sqrtN : sqrt(evSqAvg);
      h1->SetBinContent(ix, vAvg);
      h1->SetBinError(ix,evAvg);
      ((TProfile*)h1)->SetBinEntries(ix, 1.0);
      }
    }
  else if (h1->IsA()==TProfile2D::Class()  )
    {
    int nx = h1->GetNbinsX();
    int ny = h1->GetNbinsY();
    for (int iy=1; iy<=ny; iy++)
      {
      for (int ix=1; ix<=nx; ix++)
        {
        vAvg  = h1->GetBinContent(ix,iy);
        evAvg = h1->GetBinError(ix,iy);
        v     = h2->GetBinContent(ix,iy);
        evSqAvg = evAvg*evAvg;
        dv      = v - vAvg;
        vAvg    += rwn*dv;
        evSqAvg = rw*(evSqAvg + dv*dv*rwn);
        evAvg   = n>0 ? sqrt(evSqAvg)/sqrtN : sqrt(evSqAvg);
        h1->SetBinContent(ix,iy, vAvg);
        h1->SetBinError(ix,iy,evAvg);
        //((TProfile2D*)hAvg)->SetBinEntries(ix,iy, 1.0);
        }
      }
    }
}

//! Calculate External Product h_1 x h_2 and store into n1n1_12
//! Verify if dimensions are compatible, aborts if they are not.
//! The output is a 1D histogram packed according to the size of h_1 and h_2.
double calculateN1N1(const TH1 * h_1, const TH1 * h_2, TH1 * h_12, double a1, double a2)
{
  if (!ptrExist(__FUNCTION__,h_1,h_2,h_12)) throw NullPointerException(__FUNCTION__);
  int n1  = h_1->GetNbinsX();
  int n2  = h_2->GetNbinsX();
  int n3  = h_12->GetNbinsX();
  if (n3 != n1*n2 )throw HistogramException("3Histos","Incompatible histo dimensions",__FUNCTION__);
  double v1,ev1,v2,ev2,v,ev, r1,r2;
  double sum = 0.;
  double norm = 0.;
  int i3 = 1;
  for (int i1=1; i1<=n1;++i1)
    {
    v1  = a1*h_1->GetBinContent(i1);
    ev1 = a1*h_1->GetBinError(i1);
    for (int i2=1;i2<=n2;++i2)
      {
      v2  = a2*h_2->GetBinContent(i2);
      ev2 = a2*h_2->GetBinError(i2);
      v = v1*v2;
      if (v>0)
        {
        r1 = ev1/v1; r2 = ev2/v2;
        ev = v*sqrt(r1*r1+r2*r2);
        }
      else
        ev = 0.;
      h_12->SetBinContent(i3,v);
      h_12->SetBinError(i3,ev);
      sum  += v;
      norm += 1.;
      ++i3;
      }
    }
  //return average across bins
  return sum/norm;
}



//Calculate External Product n1_1 x n1_2 and store into n1n1_12
double calculateN1N1_H1H1H2(const TH1 * h_1, const TH1 * h_2, TH2 * h_12, double a1, double a2)
{
  if (!ptrExist(__FUNCTION__,h_1,h_2,h_12)) throw NullPointerException(__FUNCTION__);
  int n1   = h_1->GetNbinsX();
  int n2   = h_2->GetNbinsX();
  int n3x  = h_12->GetNbinsX();
  int n3y  = h_12->GetNbinsY();

  if (n3x!=n1 || n3y!=n2) throw HistogramException("3Histos","Incompatible histo dimensions",__FUNCTION__);
  double v1,ev1,v2,ev2,v,ev, r1,r2;
  double sum  = 0.;
  double norm = 0.;
  for (int i1=1; i1<=n1; ++i1)
    {
    v1  = a1*h_1->GetBinContent(i1);
    ev1 = a1*h_1->GetBinError(i1);
    for (int i2=1; i2<=n2; ++i2)
      {
      v2  = a2*h_2->GetBinContent(i2);
      ev2 = a2*h_2->GetBinError(i2);
      v = v1*v2;
      if (v>0)
        {
        r1 = ev1/v1;
        r2 = ev2/v2;
        ev = v*sqrt(r1*r1+r2*r2);
        }
      else
        ev = 0.;
      h_12->SetBinContent(i1,i2,v);
      h_12->SetBinError(i1,i2,ev);
      sum  += v;
      norm += 1.;
      }
    }
  //return average across bins
  return sum/norm;
}

//Calculate External Product n1_1 x n1_2 and store into n1n1_12
double calculateN1N1_H2H2H2(const TH2 *h_1, const TH2 * h_2, TH2 * h_12, double a1, double a2)
{
  if (!ptrExist(__FUNCTION__,h_1,h_2,h_12)) throw NullPointerException(__FUNCTION__);
  int n1x = h_1->GetNbinsX();
  int n1y = h_1->GetNbinsY();
  int n2x = h_2->GetNbinsX();
  int n2y = h_2->GetNbinsY();
  int n3x = h_12->GetNbinsX();
  int n3y = h_12->GetNbinsY();
  if (n3x!=(n1x*n1y) || n3y!=(n2x*n2y) ) throw HistogramException("3Histos","Incompatible histo dimensions",__FUNCTION__);
  double v1,ev1,v2,ev2,v,ev, r1,r2;
  double sum  = 0.;
  double norm = 0.;
  for (int i1x=0;i1x<n1x;++i1x)
    {
    for (int i1y=0;i1y<n1y;++i1y)
      {
      v1  = a1*h_1->GetBinContent(i1x+1,i1y+1);
      ev1 = a1*h_1->GetBinError(i1x+1,i1y+1);
      for (int i2x=0;i2x<n2x;++i2x)
        {
        for (int i2y=0;i2y<n2y;++i2y)
          {
          v2  = a2*h_2->GetBinContent(i2x+1,i2y+1);
          ev2 = a2*h_2->GetBinError(i2x+1,i2y+1);
          v = v1*v2;
          if (v>0)
            {
            r1 = ev1/v1;
            r2 = ev2/v2;
            ev = v*sqrt(r1*r1+r2*r2);
            }
          else
            ev = 0.;
          int i3x = i1x*n1y+i1y+1;
          int i3y = i2x*n2y+i2y+1;
          h_12->SetBinContent(i3x,i3y,v);
          h_12->SetBinError(i3x,i3y,ev);
          sum += v;
          norm = 1.;
          }
        }
      }
    }
  //return average across bins
  return sum/norm;
}


//External Product N1N1N1
double calculateN1N1N1(const TH1 * h_1, const TH1 * h_2, const TH1 * h_3, TH1 * h_123)
{
  if (!ptrExist(__FUNCTION__,h_1,h_2,h_3,h_123)) throw NullPointerException(__FUNCTION__);
  int n = h_1->GetNbinsX();
  double v1,ev1,v2,ev2,v3,ev3,v,ev,r1,r2,r3;
  double sum = 0.;
  int i4 = 1;
  for (int i1=1;i1<=n;++i1)
    {
    v1  = h_1->GetBinContent(i1);
    ev1 = h_1->GetBinError(i1);
    for (int i2=1;i2<=n;++i2)
      {
      v2  = h_2->GetBinContent(i2);
      ev2 = h_2->GetBinError(i2);
      for (int i3=1;i3<=n;++i3)
        {
        v3  = h_3->GetBinContent(i3);
        ev3 = h_3->GetBinError(i3);
        v = v1*v2*v3;
        if (v>0)
          {
          r1 = ev1/v1;
          r2 = ev2/v2;
          r3 = ev3/v3;
          ev = v*sqrt(r1*r1+r2*r2+r3*r3);
          }
        else
          ev = 0.;
        h_123->SetBinContent(i4,v);
        h_123->SetBinError(i4,ev);
        sum += v;
        ++i4;
        }
      }
    }
  //return average across bins
  return sum/n/n/n;
}


//External Product N1N1N1
double calculateN1N1N1(const TH1 * h_1, const TH1 * h_2, const TH1 * h_3, TH3 * h_123)
{
  if (!ptrExist(__FUNCTION__,h_1,h_2,h_3,h_123)) throw NullPointerException(__FUNCTION__);
  int n = h_1->GetNbinsX();
  double v1,ev1,v2,ev2,v3,ev3,v,ev,r1,r2,r3;
  double sum = 0.;
  for (int i1=1;i1<=n;++i1)
    {
    v1  = h_1->GetBinContent(i1);
    ev1 = h_1->GetBinError(i1);
    for (int i2=1;i2<=n;++i2)
      {
      v2  = h_2->GetBinContent(i2);
      ev2 = h_2->GetBinError(i2);
      for (int i3=1;i3<=n;++i3)
        {
        v3  = h_3->GetBinContent(i3);
        ev3 = h_3->GetBinError(i3);
        v = v1*v2*v3;
        if (v>0)
          {
          r1 = ev1/v1;
          r2 = ev2/v2; r3 = ev3/v3;
          ev = v*sqrt(r1*r1+r2*r2+r3*r3);
          }
        else
          ev = 0.;
        h_123->SetBinContent(i1,i2,i3,v);
        h_123->SetBinError(i1,i2,i3,ev);
        sum += v;
        }
      }
    }
  //return average across bins
  return sum/n/n/n;
}


void calculateN2N1(const TH2 * s2, const TH1* s1, TH2 * target, int single)
{
  if (!ptrExist(__FUNCTION__,s2,s1,target)) throw NullPointerException(__FUNCTION__);
  int n = s2->GetNbinsX();
  double v1,v2,v3,ev1,ev2,ev3,v,ev,r1,r2;
  int dPhi_xy;
  int dPhi_xz;
  int dPhi_yz;
  int dPhi12;
  int dPhi13;
  for (int i_x=0;i_x<n; ++i_x)
    {
    int i_x1 = i_x+1;
    for (int i_y=0;i_y<n; ++i_y)
      {
      int i_y1 = i_y+1;
      dPhi_xy = i_x-i_y; if (dPhi_xy<0) dPhi_xy += n; dPhi_xy+=1;
      for (int iz=0;iz<n; ++iz)
        {
        int iz1 = iz+1;
        dPhi_xz = i_x-iz; if (dPhi_xz<0) dPhi_xz += n; dPhi_xz+=1;
        dPhi_yz = i_y-iz; if (dPhi_yz<0) dPhi_yz += n; dPhi_yz+=1;
        v1   = s2->GetBinContent(i_x1,i_y1);
        ev1  = s2->GetBinError(i_x1,i_y1);
        v2   = s1->GetBinContent(iz1);
        ev2  = s1->GetBinError(iz1);
        switch (single)
          {
            case 3: dPhi12 = dPhi_xy; dPhi13 = dPhi_xz; break;
            case 2: dPhi13 = dPhi_xy; dPhi12 = dPhi_xz; break;
            case 1: dPhi12 = dPhi_xz; dPhi13 = dPhi_yz; break;
            default: return;//error("calculateN2N1()") << "invalid argument"<< endl; return;
          }
        v3   = target->GetBinContent(dPhi12,dPhi13);
        ev3  = target->GetBinError(dPhi12,dPhi13);
        v = v1*v2;
        if (v>0)
          {
          r1 = ev1/v1;
          r2 = ev2/v2;
          ev = v*v*(r1*r1+r2*r2);
          }
        else
          ev = 0.;
        v = v+v3;
        ev = sqrt(ev3*ev3+ev);
        target->SetBinContent(dPhi12,dPhi13,v);
        target->SetBinError(dPhi12,dPhi13,ev);
        }
      }
    }
}

//!
//! Fold s2 and s1 into target
//!
void calculateN2N1x(const TH2 * s2, const TH1* s1, TH3 * target, int single)
{
  if (!ptrExist(__FUNCTION__,s2,s1,target)) throw NullPointerException(__FUNCTION__);
  int n = s2->GetNbinsX();
  double v1,v2,v3,ev1,ev2,ev3,v,ev,r1,r2;
  for (int i_x=0;i_x<n; ++i_x)
    {
    int i_x1 = i_x+1;
    for (int i_y=0;i_y<n; ++i_y)
      {
      int i_y1 = i_y+1;
      for (int iz=0;iz<n; ++iz)
        {
        int iz1 = iz+1;
        v1   = s2->GetBinContent(i_x1,i_y1);
        ev1  = s2->GetBinError(i_x1,i_y1);
        v2   = s1->GetBinContent(iz1);
        ev2  = s1->GetBinError(iz1);

        v = v1*v2;
        if (v>0)
          {
          r1 = ev1/v1;
          r2 = ev2/v2;
          ev = v*v*(r1*r1+r2*r2);
          }
        else
          ev = 0.;

        switch (single)
          {
            case 3:
            v3   = target->GetBinContent(i_x1,i_y1,iz1);
            ev3  = target->GetBinError(i_x1,i_y1,iz1);
            break;
            case 2:
            v3   = target->GetBinContent(i_x1,iz1,i_y1);
            ev3  = target->GetBinError(i_x1,iz1,i_y1);
            break;
            case 1:
            v3   = target->GetBinContent(iz1,i_x1,i_y1);
            ev3  = target->GetBinError(iz1,i_x1,i_y1);
            break;
            default:  throw Exception("Invalid Option",__FUNCTION__);
            return;
          }

        v = v+v3;
        ev = sqrt(ev3*ev3+ev);
        switch (single)
          {
            case 3:
            target->SetBinContent(i_x1,i_y1,iz1,v);
            target->SetBinError(i_x1,i_y1,iz1,ev);
            break;
            case 2:
            target->SetBinContent(i_x1,iz1,i_y1,v);
            target->SetBinError(i_x1,iz1,i_y1,ev);
            break;
            case 1:
            target->SetBinContent(iz1,i_x1,i_y1,v);
            target->SetBinError(iz1,i_x1,i_y1,ev);
            break;
            default: 
            throw Exception("Invalid argument",__FUNCTION__);
          }
        }
      }
    }
}


//!
//! Check whether the given histograms have the same dimension and size.
//!
int   getDimension(const TH1* h)
{
  if (!ptrExist(__FUNCTION__,h)) throw NullPointerException(__FUNCTION__);
  int nDim = 0;
  if (h->IsA()==TH1::Class() ||
      h->IsA()==TH1F::Class() ||
      h->IsA()==TH1D::Class() ||
      h->IsA()==TH1I::Class() ||
      h->IsA()==TProfile::Class() )
    {
    nDim = 1;
    }
  else if (h->IsA()==TH2::Class() ||
           h->IsA()==TH2F::Class() ||
           h->IsA()==TH2D::Class() ||
           h->IsA()==TH2I::Class() ||
           h->IsA()==TProfile2D::Class() )
    {
    nDim = 2;
    }
  else if (h->IsA()==TH3::Class() || h->IsA()==TH3F::Class() || h->IsA()==TH3D::Class() || h->IsA()==TH3I::Class() )
    {
    nDim = 3;
    }
  return nDim;
}

void printDimensions(const TH1*h)
{
  cout << "Histo named:" << h->GetName() << " nx:" << h->GetNbinsX() << endl;
}

void printDimensions(const TH2*h)
{
  cout << "Histo named:" << h->GetName() << " nx:" << h->GetNbinsX() << " ny:" << h->GetNbinsY()<< endl;
}


void printDimensions(const TH3*h)
{
  cout << "Histo named:" << h->GetName() << " nx:" << h->GetNbinsX() << " ny:" << h->GetNbinsY() << " nz:" << h->GetNbinsZ()<< endl;
}

//!
//! Check whether the given histograms have the same dimension and size.
//!
bool  sameDimensions(const String & caller, const TH1* h1, const TH1* h2)
{
  if (!ptrExist(caller,h1,h2))  throw NullPointerException(__FUNCTION__);
  int nDim1 =  getDimension(h1);
  int nDim2 =  getDimension(h2);
  if ( nDim1==1 && nDim2==1 && (h1->GetNbinsX()==h2->GetNbinsX())) return true;
  if ( nDim1==2 && nDim2==2 && (h1->GetNbinsX()==h2->GetNbinsX()) && (h1->GetNbinsY()==h2->GetNbinsY())) return true;
  if ( nDim1==3 && nDim2==3 && (h1->GetNbinsX()==h2->GetNbinsX()) && (h1->GetNbinsY()==h2->GetNbinsY()) && (h1->GetNbinsZ()==h2->GetNbinsZ())) return true;
  printDimensions(h1);
  printDimensions(h2);
  return false;
}

bool  sameDimensions(const String & caller, const TH1* h1, const TH1* h2, const TH1* h3)
{
  if (!ptrExist(caller,h1,h2)) throw NullPointerException(__FUNCTION__);
  int nDim1 =  getDimension(h1);
  int nDim2 =  getDimension(h2);
  int nDim3 =  getDimension(h3);
  if ( nDim1==1 && nDim2==1 && nDim3==1
      && (h1->GetNbinsX()==h2->GetNbinsX())
      && (h1->GetNbinsX()==h3->GetNbinsX()) ) return true;
  if ( nDim1==2 && nDim2==2 && nDim3==2
      && (h1->GetNbinsX()==h2->GetNbinsX()) && (h1->GetNbinsY()==h2->GetNbinsY())
      && (h1->GetNbinsX()==h3->GetNbinsX()) && (h1->GetNbinsY()==h3->GetNbinsY())) return true;
  if ( nDim1==3 && nDim2==3 && nDim3==3
      && (h1->GetNbinsX()==h2->GetNbinsX()) && (h1->GetNbinsY()==h2->GetNbinsY()) && (h1->GetNbinsZ()==h2->GetNbinsZ())
      && (h1->GetNbinsX()==h3->GetNbinsX()) && (h1->GetNbinsY()==h3->GetNbinsY()) && (h1->GetNbinsZ()==h3->GetNbinsZ())) return true;
  printDimensions(h1);
  printDimensions(h2);
  printDimensions(h3);
  return false;
}

bool  sameDimensions(const String & caller, const TH1* h1, const TH1* h2, const TH1* h3, const TH1* h4)
{
  int nDim1 =  getDimension(h1);
  int nDim2 =  getDimension(h2);
  int nDim3 =  getDimension(h3);
  int nDim4 =  getDimension(h4);
  if ( nDim1==1 && nDim2==1 && nDim3==1 && nDim4==1
      && (h1->GetNbinsX()==h2->GetNbinsX())
      && (h1->GetNbinsX()==h3->GetNbinsX())
      && (h1->GetNbinsX()==h4->GetNbinsX()) ) return true;
  if ( nDim1==2 && nDim2==2 && nDim3==2 && nDim4==2
      && (h1->GetNbinsX()==h2->GetNbinsX()) && (h1->GetNbinsY()==h2->GetNbinsY())
      && (h1->GetNbinsX()==h3->GetNbinsX()) && (h1->GetNbinsY()==h3->GetNbinsY())
      && (h1->GetNbinsX()==h4->GetNbinsX()) && (h1->GetNbinsY()==h4->GetNbinsY()) ) return true;
  if ( nDim1==3 && nDim2==3 && nDim4==3 && nDim4==3
      && (h1->GetNbinsX()==h2->GetNbinsX()) && (h1->GetNbinsY()==h2->GetNbinsY()) && (h1->GetNbinsZ()==h2->GetNbinsZ())
      && (h1->GetNbinsX()==h3->GetNbinsX()) && (h1->GetNbinsY()==h3->GetNbinsY()) && (h1->GetNbinsZ()==h3->GetNbinsZ())
      && (h1->GetNbinsX()==h4->GetNbinsX()) && (h1->GetNbinsY()==h4->GetNbinsY()) && (h1->GetNbinsZ()==h4->GetNbinsZ()) ) return true;
  cout << endl;
  cout << "sameDimensions(...)  : " << caller << endl;
  cout << "Incompatible dimensions or sizes" << endl;
  printDimensions(h1);
  printDimensions(h2);
  printDimensions(h3);
  printDimensions(h4);
  return false;
}

//!
//! Check whether the given histograms have the same dimension and size.
//!
bool  sameDimensions(const String & caller, const TH1* h1, const TH1* h2, const TH1* h3, const TH1* h4, const TH1* h5)
{
  int nDim1 =  getDimension(h1);
  int nDim2 =  getDimension(h2);
  int nDim3 =  getDimension(h3);
  int nDim4 =  getDimension(h4);
  int nDim5 =  getDimension(h5);
  if ( nDim1==1 && nDim2==1 && nDim3==1 && nDim4==1 && nDim5==1
      && (h1->GetNbinsX()==h2->GetNbinsX())
      && (h1->GetNbinsX()==h3->GetNbinsX())
      && (h1->GetNbinsX()==h4->GetNbinsX())
      && (h1->GetNbinsX()==h5->GetNbinsX()) ) return true;
  if ( nDim1==2 && nDim2==2 && nDim3==2 && nDim4==2 && nDim5==2
      && (h1->GetNbinsX()==h2->GetNbinsX()) && (h1->GetNbinsY()==h2->GetNbinsY())
      && (h1->GetNbinsX()==h3->GetNbinsX()) && (h1->GetNbinsY()==h3->GetNbinsY())
      && (h1->GetNbinsX()==h4->GetNbinsX()) && (h1->GetNbinsY()==h4->GetNbinsY())
      && (h1->GetNbinsX()==h5->GetNbinsX()) && (h1->GetNbinsY()==h5->GetNbinsY())  ) return true;
  if ( nDim1==3 && nDim2==3 && nDim4==3 && nDim4==3 && nDim5==3
      && (h1->GetNbinsX()==h2->GetNbinsX()) && (h1->GetNbinsY()==h2->GetNbinsY()) && (h1->GetNbinsZ()==h2->GetNbinsZ())
      && (h1->GetNbinsX()==h3->GetNbinsX()) && (h1->GetNbinsY()==h3->GetNbinsY()) && (h1->GetNbinsZ()==h3->GetNbinsZ())
      && (h1->GetNbinsX()==h4->GetNbinsX()) && (h1->GetNbinsY()==h4->GetNbinsY()) && (h1->GetNbinsZ()==h4->GetNbinsZ())
      && (h1->GetNbinsX()==h5->GetNbinsX()) && (h1->GetNbinsY()==h5->GetNbinsY()) && (h1->GetNbinsZ()==h5->GetNbinsZ()) ) return true;
  cout << endl;
  cout << "sameDimensions(...)  : " << caller << endl;
  cout << "Incompatible dimensions or sizes" << endl;
  printDimensions(h1);
  printDimensions(h2);
  printDimensions(h3);
  printDimensions(h4);
  printDimensions(h5);
  return false;
}


//!
//! Calculate the G2 observable based on the given components
//!
void calculateDptDpt(const TH2 * spp, const TH2 * spn, const TH2 * snp, const TH2 * snn,
                     const TH2 * avgp1, const TH2 * avgp2,  TH2 * s2dptdpt,  TH2 * dptdpt,
                     bool ijNormalization, int nEta, int nPhi)
{
  if (!ptrExist(__FUNCTION__,spp,spn,snp,snn,avgp1,avgp2,s2dptdpt,dptdpt)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,spp,spn,snp,snn))  throw IncompatibleHistogramException(__FUNCTION__);
  int nEtaPhi = nEta*nPhi;
  double sumPt1 = 0;
  double sumPt2 = 0;
  for (int iEta1=0;iEta1<nEta;++iEta1)
    {
    for (int iPhi1=0;iPhi1<nPhi;++iPhi1)
      {
      //k = iEta1*nPhi + iPhi1 + 1;
      sumPt1 += avgp1->GetBinContent(iEta1+1, iPhi1+1);
      sumPt2 += avgp2->GetBinContent(iEta1+1, iPhi1+1);
      }
    }
  double p1 = sumPt1/double(nEtaPhi);
  double p2 = sumPt2/double(nEtaPhi);
  double v1,v2,v3,v4,v5,v6;
  double ev4,ev5,ev6;
  for (int iEta1=0;iEta1<nEta;++iEta1)
    {
    //p1  = ptAvg1[iEta1];
    for (int iPhi1=0;iPhi1<nPhi;++iPhi1)
      {
      int k1 = 1+ iEta1*nPhi + iPhi1;
      //c1 = avgp1->GetBinContent(k1+1)/p1;
      for (int iEta2=0;iEta2<nEta;++iEta2)
        {
        //p2  = ptAvg2[iEta2];
        for (int iPhi2=0;iPhi2<nPhi;++iPhi2)
          {
          int k2 = 1+ iEta2*nPhi + iPhi2;
          v1  = spp->GetBinContent(k1,k2); //ev1 = spp->GetBinError(k1,k2);
          v2  = spn->GetBinContent(k1,k2); //ev2 = spn->GetBinError(k1,k2);
          v3  = snp->GetBinContent(k1,k2); //ev3 = snp->GetBinError(k1,k2);
          v4  = snn->GetBinContent(k1,k2); ev4 = snn->GetBinError(k1,k2);
          //c2 = avgp2->GetBinContent(k2+1)/p2;

          if (v4!=0 ) // && ev4/v4<0.5)
            {
            if (ijNormalization)
              {
              v5  = 2*(v1 - v2*p2 - p1*v3 + p1*p2*v4);
              ev5 = v5*ev4/v4;
              v6  = v5/(2*v4);
              ev6 = v6*ev4/v4;
              }
            else
              {
              v5  = v1 - v2*p2 - p1*v3 + p1*p2*v4;
              ev5 = v5*ev4/v4;
              v6  = v5/v4;
              ev6 = v6*ev4/v4;
              }
            }
          else
            {
            v5 = v6 = ev5 = ev6 = 0;
            }
          if (s2dptdpt)
            ;
          //s2dptdpt->SetBinContent(k,v5); s2dptdpt->SetBinError(k,ev5);
          //dptdpt->SetBinContent(k,  v6); dptdpt->SetBinError(k,  ev6);
          //s2dptdpt->SetBinContent(k1, k2, v5); s2dptdpt->SetBinError(k1, k2, ev5);
          dptdpt->SetBinContent(  k1, k2, v6); dptdpt->SetBinError(  k1, k2, ev6);
          }
        }
      }
    }

}

//!
//! Calculate the G2 observable based on the given components
//!
void calculateDptDpt(const TH2 * spp, const TH2 * spn, const TH2 * snp, const TH2 * snn,
                     const TH1 * avgp1, const TH1 * avgp2,
                     TH2 * dptdpt,
                     bool ijNormalization, int nBins)
{
  if (!ptrExist(__FUNCTION__,spp,spn,snp,snn,avgp1,avgp2,dptdpt)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,spp,spn,snp,snn))  throw IncompatibleHistogramException(__FUNCTION__);

  double v1,v2,v3,v4,v5,v6,p1,p2;
  double ev4,ev5,ev6;
  for (int i1=1;i1<=nBins;++i1)
    {
    p1 = avgp1->GetBinContent(i1);
    for (int i2=1;i2<=nBins;++i2)
      {
      p2 = avgp2->GetBinContent(i2);
      v1  = spp->GetBinContent(i1,i2); //ev1 = spp->GetBinError(i1,i2);
      v2  = spn->GetBinContent(i1,i2); //ev2 = spn->GetBinError(i1,i2);
      v3  = snp->GetBinContent(i1,i2); //ev3 = snp->GetBinError(i1,i2);
      v4  = snn->GetBinContent(i1,i2); ev4 = snn->GetBinError(i1,i2);
      if (v4!=0) // && ev4/v4<0.5)
        {
        if (ijNormalization)
          {
          v5  = 2*(v1 - v2*p2 - p1*v3 + p1*p2*v4);
          ev5 = v5*ev4/v4;
          v6  = v5/(2*v4);
          ev6 = v6*ev4/v4;
          }
        else
          {
          v5  = v1 - v2*p2 - p1*v3 + p1*p2*v4;
          ev5 = v5*ev4/v4;
          v6  = v5/v4;
          ev6 = v6*ev4/v4;
          }
        }
      else
        {
        v5 = v6 = ev5 = ev6 = 0;
        }
      dptdpt->SetBinContent(i1,i2, v6);
      dptdpt->SetBinError(i1,i2, ev6);
      }
    }
}


void calculateSc(const TH1 * spp, const TH1 * n1n1, const TH1 * pt1pt1, TH1 * g2, bool ijNormalization)
{
  if (!ptrExist(__FUNCTION__,spp,n1n1,pt1pt1,g2)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,spp,n1n1,pt1pt1,g2))  throw IncompatibleHistogramException(__FUNCTION__);
  int n1 = spp->GetNbinsX();
  double v1,v2,v3,v4;
  double ev1,ev4;
  for (int i1=1;i1<=n1;++i1)
    {
    v1  = spp->GetBinContent(i1);    ev1 = spp->GetBinError(i1);
    v2  = n1n1->GetBinContent(i1);   //ev2 = n1n1->GetBinError(i1);
    v3  = pt1pt1->GetBinContent(i1); //ev3 = pt1pt1->GetBinError(i1);
    if (v2>0)
      {
      if (ijNormalization)
        v4  = 2*v1/v2 - v3;
      else
        v4  = v1/v2 - v3;
      ev4 = v1>0 ? v4*ev1/v1 : 0;
      }
    else
      {
      v4 = ev4 = 0;
      }
    g2->SetBinContent(i1,v4); g2->SetBinError(i1,ev4);
    }
}

void calculateG2_H2H2H2H2(const TH2 * spp, const TH2 * n1n1, const TH2 * pt1pt1, TH2 * g2, bool ijNormalization, double a1, double a2)
{
  if (!ptrExist(__FUNCTION__,spp,n1n1,pt1pt1,g2))  throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,spp,n1n1,pt1pt1,g2))  throw IncompatibleHistogramException(__FUNCTION__);

  int n2x = n1n1->GetNbinsX();
  int n2y = n1n1->GetNbinsY();
  double v1,v2,v3,v4;
  double ev1,ev4;
  for (int i1=1;i1<=n2x;++i1)
    {
    for (int i2=1;i2<=n2y;++i2)
      {
      v1  = a1*spp->GetBinContent(i1,i2);       ev1 = a1*spp->GetBinError(i1,i2);
      v2  = a2*n1n1->GetBinContent(i1,i2);      //ev2 = a2*n1n1->GetBinError(i1,i2);
      v3  = pt1pt1->GetBinContent(i1,i2);       //ev3 = pt1pt1->GetBinError(i1,i2);
      if (v2>0)
        {
        if (ijNormalization)
          v4  = 2*v1/v2 - v3;
        else
          v4  = v1/v2 - v3;
        ev4 = v1>0 ? v4*ev1/v1 : 0;
        }
      else
        {
        v4 = ev4 = 0;
        }
      g2->SetBinContent(i1,i2,v4); g2->SetBinError(i1,i2,ev4);
      }
    }
}

/* calculate the balance functions components associated to the current pair */
/* independent of R2, two components are alway computed, for LS they will match but don't for US */
void calculateBf(const TH2 *n2, const TH2 *n1_1, const TH2 *n1_2, TH2 *bf_12, TH2 *bf_21)
{
  if (!ptrExist(__FUNCTION__,n2,n1_1,n1_2,bf_12,bf_21)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n1_1,n1_2))  throw IncompatibleHistogramException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n2,bf_12,bf_21))  throw IncompatibleHistogramException(__FUNCTION__);
  int nbinsx = n2->GetNbinsX();
  int nbinsy = n2->GetNbinsY();

  bf_12->Reset();
  bf_21->Reset();
  double n11_inte = 0.0;
  double n11_int = n1_1->IntegralAndError(1,n1_1->GetNbinsX(),1,n1_1->GetNbinsY(),n11_inte);
  double n11_inter = n11_inte/n11_int;

  double n12_inte = 0.0;
  double n12_int = n1_2->IntegralAndError(1,n1_2->GetNbinsX(),1,n1_2->GetNbinsY(),n12_inte);
  double n12_inter = n12_inte/n12_int;

  for (int ix = 0; ix < nbinsx; ++ix)
    {
    for (int iy = 0; iy < nbinsy; ++iy)
      {
      double v = n2->GetBinContent(ix+1,iy+1);
      double ve = n2->GetBinError(ix+1,iy+1);

      double v12 = v/n12_int;
      double v12e = v12*sqrt(ve/v*ve/v+n12_inter*n12_inter);
      double v21 = v/n11_int;
      double v21e = v21*sqrt(ve/v*ve/v+n11_inter*n11_inter);

      bf_12->SetBinContent(ix+1,iy+1,v12);
      bf_12->SetBinError(ix+1,iy+1,v12e);
      bf_21->SetBinContent(iy+1,ix+1,v21);
      bf_21->SetBinError(iy+1,ix+1,v21e);
      }
    }
  bf_12->SetEntries(n2->GetEntries());
  bf_21->SetEntries(n2->GetEntries());
}

void calculateG2_H1H2H2H2(const TH1 * spp, const TH2 * n1n1, const TH2 * pt1pt1, TH2 * g2, bool ijNormalization, double a1, double a2)
{

  if (!ptrExist(__FUNCTION__,spp,n1n1,pt1pt1,g2)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n1n1,pt1pt1,g2)) throw IncompatibleHistogramException(__FUNCTION__);
  int n1  = spp->GetNbinsX();
  int n2x = n1n1->GetNbinsX();
  int n2y = n1n1->GetNbinsY();
  int n3x = pt1pt1->GetNbinsX();
  // int n3y = pt1pt1->GetNbinsY();
  int n4x = g2->GetNbinsX();
  //int n4y = g2->GetNbinsY();
  if (n1!=n2x*n2y || n2x!=n3x || n2x!=n4x)
    throw IncompatibleHistogramException(__FUNCTION__);
  int index;
  double v1,v2,v3,v4;
  double ev1, ev4;
  index = 1;
  for (int i1=1;i1<=n2x;++i1)
    {
    for (int i2=1;i2<=n2y;++i2)
      {
      v1  = a1*spp->GetBinContent(index);   ev1 = a1*spp->GetBinError(index);
      v2  = a2*n1n1->GetBinContent(i1,i2);  // ev2 = a2*n1n1->GetBinError(i1,i2);
      v3  = pt1pt1->GetBinContent(i1,i2);   // ev3 = pt1pt1->GetBinError(i1,i2);
      if (v2>0)
        {
        if (ijNormalization)
          v4  = 2*v1/v2 - v3;
        else
          v4  = v1/v2 - v3;
        ev4 = v1>0 ? v4*ev1/v1 : 0;
        }
      else
        {
        v4 = ev4 = 0;
        }
      g2->SetBinContent(i1,i2,v4); g2->SetBinError(i1,i2,ev4);
      index++;
      }
    }
}


int  calculateQ3DwPtPhiEta(double pt1, double phi1, double eta1,
                           double pt2, double phi2, double eta2,
                           double & Qlong, double & Qout, double & Qside)
{

  LorentzVector p1;
  LorentzVector p2;
  p1.SetPtEtaPhiM(pt1,eta1,phi1,0.13957);
  p2.SetPtEtaPhiM(pt2,eta2,phi2,0.13957);
  if (p1.P()>p1.E()) return 1;
  if (p2.P()>p2.E()) return 2;

  double px1   = p1.Px();
  double py1   = p1.Py();
  double pz1   = p1.Pz();
  double e1    = p1.E();

  double px2   = p2.Px();
  double py2   = p2.Py();
  double pz2   = p2.Pz();
  double e2    = p2.E();

  double pt,s,Mlong,roots;
  double ptot[4],q[4];
  //const int g[4]={1,-1,-1,-1};
  //int alpha;
  s=0.0;
  ptot[0] = e1  + e2;
  ptot[1] = px1 + px2;
  ptot[2] = py1 + py2;
  ptot[3] = pz1 + pz2;
  q[0] = e1  - e2;
  q[1] = px1 - px2;
  q[2] = py1 - py2;
  q[3] = pz1 - pz2;
  s = ptot[0]*ptot[0] - ptot[1]*ptot[1] - ptot[2]*ptot[2] - ptot[3]*ptot[3];
  pt=sqrt(ptot[1]*ptot[1]+ptot[2]*ptot[2]);
  Mlong=sqrt(s+pt*pt);
  roots=sqrt(s);

  if ((p1+p2).P()>(p1+p2).E()) return 3;

  if (pt>0)
    {
    Qside = (ptot[1]*q[2]-ptot[2]*q[1])/pt;
    Qlong = (ptot[0]*q[3]-ptot[3]*q[0])/Mlong;
    Qout  = (roots/Mlong)*(ptot[1]*q[1]+ptot[2]*q[2])/pt;
    }
  else
    {
    Qlong = q[3];
    Qside = q[2];
    Qout  = q[1];
    }

  return 0;
}

int  calculateQ3DwPtPhiY(double pt1, double phi1, double y1,
                         double pt2, double phi2, double y2,
                         double & Qlong, double & Qout, double & Qside)
{
  LorentzVector p1;
  LorentzVector p2;
  double mPart = 0.13957;
  double mSq   = mPart*mPart;
  double mt1   = sqrt(mSq + pt1*pt1);
  double p1z   = mt1 * sinh(y1);
  double mt2   = sqrt(mSq + pt2*pt2);
  double p2z   = mt2 * sinh(y2);
  p1.SetPtEtaPhiM(pt1*cos(phi1),pt1*sin(phi1),p1z,mPart);
  p2.SetPtEtaPhiM(pt2*cos(phi2),pt2*sin(phi2),p2z,mPart);

  if (p1.P()>p1.E()) return 1;
  if (p2.P()>p2.E()) return 2;

  double px1   = p1.Px();
  double py1   = p1.Py();
  double pz1   = p1.Pz();
  double e1    = p1.E();

  double px2   = p2.Px();
  double py2   = p2.Py();
  double pz2   = p2.Pz();
  double e2    = p2.E();

  double pt,s,Mlong,roots;
  double ptot[4],q[4];
  //const int g[4]={1,-1,-1,-1};
  //int alpha;
  s=0.0;
  ptot[0] = e1  + e2;
  ptot[1] = px1 + px2;
  ptot[2] = py1 + py2;
  ptot[3] = pz1 + pz2;
  q[0] = e1  - e2;
  q[1] = px1 - px2;
  q[2] = py1 - py2;
  q[3] = pz1 - pz2;
  s = ptot[0]*ptot[0] - ptot[1]*ptot[1] - ptot[2]*ptot[2] - ptot[3]*ptot[3];
  pt=sqrt(ptot[1]*ptot[1]+ptot[2]*ptot[2]);
  Mlong=sqrt(s+pt*pt);
  roots=sqrt(s);

  if ((p1+p2).P()>(p1+p2).E()) return 3;

  if (pt>0)
    {
    Qside = (ptot[1]*q[2]-ptot[2]*q[1])/pt;
    Qlong = (ptot[0]*q[3]-ptot[3]*q[0])/Mlong;
    Qout  = (roots/Mlong)*(ptot[1]*q[1]+ptot[2]*q[2])/pt;
    }
  else
    {
    Qlong = q[3];
    Qside = q[2];
    Qout  = q[1];
    }

  return 0;
}


// Calculate n1n1 Q3D based on h2(y,pt) x h2(y,pt)
void calculateN1N1H2H2_Q3D_MCY(TH2 * n1_1, TH2 * n1_2, TH3 * n1n1_Q3D, double a1 __attribute__((unused)), double a2 __attribute__((unused)))
{
  if (!ptrExist(__FUNCTION__,n1_1,n1_2,n1n1_Q3D)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n1_1,n1_2))  throw IncompatibleHistogramException(__FUNCTION__);

  double Qlong, Qout, Qside;
  double pt1, phi1, y1;
  double pt2, phi2, y2;
  int nIter = 100000000;

  //double ss = 2.0/double(n1n1_Q3D->GetNbinsX());
  double avgN1 = n1_1->Integral();
  double avgN2 = n1_2->Integral();
  double scalingFactor = avgN1*avgN2/double(nIter);

  for (int k=0;k<nIter;k++)
    {
    n1_1->GetRandom2 (y1, pt1);
    n1_2->GetRandom2 (y2, pt2);
    phi1 = 2.0*CAP::Math::pi() * gRandom->Rndm();
    phi2 = 2.0*CAP::Math::pi() * gRandom->Rndm();
    bool status = calculateQ3DwPtPhiY(pt1, phi1, y1, pt2, phi2, y2, Qlong, Qout, Qside);
    if (status==0)
      {
      n1n1_Q3D->Fill(Qlong, Qside, Qout, 1.0);
      }
    }
  n1n1_Q3D->Scale(scalingFactor);
}

// Calculate n1n1 Q3D based on h2(eta,pt) x h2(eta,pt)
void calculateN1N1H2H2_Q3D_MCEta(TH2 * n1_1, TH2 * n1_2, TH3 * n1n1_Q3D, double a1 __attribute__((unused)), double a2 __attribute__((unused)))
{

  if (!ptrExist(__FUNCTION__,n1_1,n1_2,n1n1_Q3D)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n1_1,n1_2)) throw IncompatibleHistogramException(__FUNCTION__);

  double Qlong, Qout, Qside;
  double pt1, phi1, eta1;
  double pt2, phi2, eta2;
  int nIter = 10000000;

  double avgN1 = n1_1->Integral();
  double avgN2 = n1_2->Integral();
  double scalingFactor = avgN1*avgN2/double(nIter);

  for (int k=0;k<nIter;k++)
    {
    n1_1->GetRandom2 (eta1, pt1);
    n1_2->GetRandom2 (eta2, pt2);
    phi1 = 2.0*CAP::Math::pi() * gRandom->Rndm();
    phi2 = 2.0*CAP::Math::pi() * gRandom->Rndm();
    bool status = calculateQ3DwPtPhiEta(pt1, phi1, eta1, pt2, phi2, eta2, Qlong, Qout, Qside);
    if (status==0)
      {
      n1n1_Q3D->Fill(Qlong, Qside, Qout, 1.0);
      }
    }
  n1n1_Q3D->Scale(scalingFactor);
}

// Calculate n1n1 Q3D based on h2(eta,pt) x h2(eta,pt)
void calculateN1N1H2H2_Q3D(const TH2 * n1_1, const TH2 * n1_2, TH3 * n1n1_Q3D, double a1 __attribute__((unused)), double a2 __attribute__((unused)))
{

  if (!ptrExist(__FUNCTION__,n1_1,n1_2,n1n1_Q3D)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n1_1,n1_2))  throw IncompatibleHistogramException(__FUNCTION__);
  int nx = n1_1->GetNbinsX();
  int ny = n1_1->GetNbinsY();
  double v1;
  double v2;
  double v3;
  double Qlong, Qout, Qside;
  double pt1, phi1, eta1;
  double pt2, phi2, eta2;

  for (int i1x=1;i1x<=nx;++i1x)
    {
    for (int i1y=1;i1y<=ny;++i1y)
      {
      for (int i2x=1;i2x<=nx;++i2x)
        {
        for (int i2y=1;i2y<=ny;++i2y)
          {
          v1  = a1*n1_1->GetBinContent(i1x,i1y); //ev1 = a1*n1_1->GetBinError(i1x,i1y,i1z);
          v2  = a2*n1_2->GetBinContent(i2x,i2y); //ev2 = a2*n1_2->GetBinError(i2x,i2y,i2z);
          if (v1>0 && v2>0)
            {
            v3  = v1*v2;
            for (int k=0;k<100000;k++)
              {
              phi1 = 2.0*CAP::Math::pi() * gRandom->Rndm();
              phi2 = 2.0*CAP::Math::pi() * gRandom->Rndm();
              eta1 = n1_1->GetXaxis()->GetBinCenter(i1x);
              pt1  = n1_1->GetZaxis()->GetBinCenter(i1y);
              eta2 = n1_2->GetXaxis()->GetBinCenter(i2x);
              pt2  = n1_2->GetZaxis()->GetBinCenter(i2y);
              bool status = calculateQ3DwPtPhiEta(pt1, phi1, eta1, pt2, phi2, eta2, Qlong, Qout, Qside);
              if (status==0)
                {
                //cout << " i1x:" << i1x << " i1y: " << i1y << " i1z: " << i1z << " i2x:" << i1x << " i2y: " << i2y << " i2z: " << i2z << " v1: " << v1 << " v2: " << v2 << endl;
                //cout << " pt1:" << pt1 << " phi1: " << phi1 << " eta1: " << eta1 << " pt2:" << pt2 << " phi2: " << phi2 << " eta2: " << eta2 << " Qlong:" << Qlong << " Qout:" << Qout << " Qside:" << Qside << " v3:" << v3 << endl;
                n1n1_Q3D->Fill(Qlong, Qside, Qout, v3);
                }
              }
            }
          }
        }
      }
    }

}


void calculateN1N1H3H3_Q3D(const TH3 * n1_1, const TH3 * n1_2, TH3 * n1n1_Q3D, double a1, double a2)
{

  if (!ptrExist(__FUNCTION__,n1_1,n1_2,n1n1_Q3D)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n1_1,n1_2))  throw IncompatibleHistogramException(__FUNCTION__);
  int nx = n1_1->GetNbinsX();
  int ny = n1_1->GetNbinsY();
  int nz = n1_1->GetNbinsX();

  double v1;
  double v2;
  double v3;
  double Qlong, Qout, Qside;
  double pt1, phi1, eta1;
  double pt2, phi2, eta2;

  for (int i1x=1;i1x<=nx;++i1x)
    {
    for (int i1y=1;i1y<=ny;++i1y)
      {
      for (int i1z=1;i1z<=nz;++i1z)
        {
        for (int i2x=1;i2x<=nx;++i2x)
          {
          for (int i2y=1;i2y<=ny;++i2y)
            {
            for (int i2z=1;i2z<=nz;++i2z)
              {
              v1  = a1*n1_1->GetBinContent(i1x,i1y,i1z); //ev1 = a1*n1_1->GetBinError(i1x,i1y,i1z);
              v2  = a2*n1_2->GetBinContent(i2x,i2y,i2z); //ev2 = a2*n1_2->GetBinError(i2x,i2y,i2z);
              if (v1>0 && v2>0)
                {
                //er1 = ev1/v1;
                //er2 = ev2/v2;
                //if (er1< 10.5 && er2<10.5)
                //  {
                v3  = v1*v2;
                //ev3 = v3*sqrt(er1*er1 + er2*er2);

                eta1 = n1_1->GetXaxis()->GetBinCenter(i1x);
                phi1 = n1_1->GetYaxis()->GetBinCenter(i1y);
                pt1  = n1_1->GetZaxis()->GetBinCenter(i1z);
                eta2 = n1_2->GetXaxis()->GetBinCenter(i2x);
                phi2 = n1_2->GetYaxis()->GetBinCenter(i2y);
                pt2  = n1_2->GetZaxis()->GetBinCenter(i2z);
                bool status = calculateQ3DwPtPhiEta(pt1, phi1, eta1, pt2, phi2, eta2, Qlong, Qout, Qside);
                if (status==0)
                  {
                  //cout << " i1x:" << i1x << " i1y: " << i1y << " i1z: " << i1z << " i2x:" << i1x << " i2y: " << i2y << " i2z: " << i2z << " v1: " << v1 << " v2: " << v2 << endl;
                  //cout << " pt1:" << pt1 << " phi1: " << phi1 << " eta1: " << eta1 << " pt2:" << pt2 << " phi2: " << phi2 << " eta2: " << eta2 << " Qlong:" << Qlong << " Qout:" << Qout << " Qside:" << Qside << " v3:" << v3 << endl;
                  n1n1_Q3D->Fill(Qlong, Qside, Qout, v3);
                  }
                // }
                }
              }
            }
          }
        }}}

}

void calculateR2_Q3D(const TH3 * n2_Q3D, const TH3 * n1n1_Q3D, TH3 * R2_Q3D, double a1, double a2)
{

  if (!ptrExist(__FUNCTION__,n2_Q3D,n1n1_Q3D,R2_Q3D)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n2_Q3D,n1n1_Q3D))  throw IncompatibleHistogramException(__FUNCTION__);
  int nx = n2_Q3D->GetNbinsX();
  int ny = n2_Q3D->GetNbinsY();
  int nz = n2_Q3D->GetNbinsX();
  double v1,ev1,er1;
  double v2,ev2,er2;
  double v3,ev3;
  for (int i1=1;i1<=nx;++i1)
    {
    for (int i2=1;i2<=ny;++i2)
      {
      for (int i3=1;i3<=nz;++i3)
        {
        v1  = a1*n2_Q3D->GetBinContent(i1,i2,i3);   ev1 = a1*n2_Q3D->GetBinError(i1,i2,i3);
        v2  = a2*n1n1_Q3D->GetBinContent(i1,i2,i3); ev2 = a2*n1n1_Q3D->GetBinError(i1,i2,i3);
        if (v1>0 && v2>0)
          {
          if (v1)
            er1 = ev1/v1;
          else
            er1 = 0;
          if (v2)
            er2 = ev2/v2;
          else
            er2 = 0;
          if (er1< 0.5 && er2<0.5)
            {
            v3  = v1/v2 - 1;
            ev3 = v3*sqrt(er1*er1 + er2*er2);
            }
          else
            {
            v3 = 0.0;
            ev3 = 0.0;
            }
          }
        else
          {
          v3 = 0.0;
          ev3 = 0.0;
          }
        R2_Q3D->SetBinContent(i1,i2,i3,v3);
        R2_Q3D->SetBinError(i1,i2,i3,ev3);
        }
      }
    }
}

// Return the average bin content of the given 1D histogram
double avgValue(TH1 * h)
{
  if (!ptrExist(__FUNCTION__,h)) throw NullPointerException(__FUNCTION__);
  int nx = h->GetNbinsX();
  if (nx<1) return 0.0;
  double nnx = nx;
  double sum = 0.0;
  for (int k=1; k<=nx; k++)
    {
    sum += h->GetBinContent(k);
    }
  return sum/nnx;
}


//!
//! Set all bins of the given histogram to the given value and error.
//!
void setHistogram(TH1 * h, double v, double ev)
{

  if (!ptrExist(__FUNCTION__,h)) throw NullPointerException(__FUNCTION__);
  int n = h->GetNbinsX();
  for (int i1=1;i1<=n;++i1)
    {
    h->SetBinContent(i1,v);
    h->SetBinError(i1,ev);
    }
}

//!
//! Set all bins of the given histogram to the given value and error.
//!
void setHistogram(TH2 * h, double v, double ev)
{

  if (!ptrExist(__FUNCTION__,h)) throw NullPointerException(__FUNCTION__);
  int n_x = h->GetNbinsX();
  int n_y = h->GetNbinsY();
  for (int i1=1;i1<=n_x;++i1)
    {
    for (int i2=1;i2<=n_y;++i2)
      {
      h->SetBinContent(i1,i2,v);
      h->SetBinError(i1,i2,ev);
      }
    }
}

//!
//! Set all bins of the given histogram to the given value and error.
//!
void setHistogram(TH3 * h, double v, double ev)
{
  if (!ptrExist(__FUNCTION__,h)) throw NullPointerException(__FUNCTION__);
  int n_x = h->GetNbinsX();
  int n_y = h->GetNbinsY();
  int n_z = h->GetNbinsZ();
  for (int i1=1;i1<=n_x;++i1)
    {
    for (int i2=1;i2<=n_y;++i2)
      {
      for (int i3=1;i3<=n_z;++i3)
        {
        h->SetBinContent(i1,i2,i3,v);
        h->SetBinError(i1,i2,i3,ev);
        }
      }
    }
}



///Clone the given histogram, and set the clone's name to the given name.
/////throws a HistogramException if the histogram does not exist (null pointer).
TH1 * clone(const TH1 * h1, const String & histoName)
{
  if (!h1) throw NullPointerException(__FUNCTION__);
  TH1 * h = (TH1*) h1->Clone();
  if (!h) throw HistogramException(histoName,"Histogram not cloned",__FUNCTION__);
  h->SetName(histoName);
  return h;
}

void cloneHistoVector(const vector<TH1*> & source, vector<TH1*> & target)
{
  for (auto & h : source) target.push_back( (TH1*) h->Clone() );
}

void cloneHistoVector(const vector<TH2*> & source, vector<TH2*> & target)
{
  for (auto & h : source) target.push_back( (TH2*) h->Clone() );
}

void cloneHistoVector(const vector<TH3*> & source, vector<TH3*> & target)
{
  for (auto & h : source) target.push_back( (TH3*) h->Clone() );
}

void cloneHistoVector(const vector<TProfile*> & source, vector<TProfile*> & target)
{
  for (auto & h : source) target.push_back( (TProfile*) h->Clone() );
}

void cloneHistoVector(const vector<TProfile2D*> & source, vector<TProfile2D*> & target)
{
  for (auto & h : source) target.push_back( (TProfile2D*) h->Clone() );
}

void findMaximum(TH1 * h, int & xMaxValueBin, double & maxValue, int xFirstBin, int xLastBin)
{
  if (!h) throw NullPointerException(__FUNCTION__);
  int n = h->GetNbinsX();
  if (xFirstBin<1) xFirstBin = 1;
  if (xLastBin<1 || xLastBin>n)  xLastBin = n;
  for (int i=xFirstBin;i<=xLastBin;++i)
    {
    double v = h->GetBinContent(i);
    if (v>maxValue)
      {
      xMaxValueBin = i;
      maxValue = v;
      }
    }
}

void findMinimum(TH1 * h, int & xMinValueBin, double  & minValue, int xFirstBin, int xLastBin)
{
  if (!h) throw NullPointerException(__FUNCTION__);
  int n = h->GetNbinsX();
  if (xFirstBin<1) xFirstBin = 1;
  if (xLastBin<1 || xLastBin>n)  xLastBin = n;
  for (int i=xFirstBin;i<=xLastBin;++i)
    {
    double v = h->GetBinContent(i);
    if (v<minValue)
      {
      xMinValueBin = i;
      minValue = v;
      }
    }
}

void findMinMax (TH1 * h,
                 int & xMinValueBin, double & minValue,
                 int & xMaxValueBin, double & maxValue,
                 int xFirstBin, int xLastBin)
{
  if (!h) throw NullPointerException(__FUNCTION__);
  int n = h->GetNbinsX();
  if (xFirstBin<1) xFirstBin = 1;
  if (xLastBin<1 || xLastBin>n)  xLastBin = n;
  for (int i=xFirstBin;i<=xLastBin;++i)
    {
    double v = h->GetBinContent(i);
    if (v<minValue)
      {
      xMinValueBin = i;
      minValue = v;
      }
    if (v>maxValue)
      {
      xMaxValueBin = i;
      maxValue = v;
      }
    }
}

void findMinMax (std::vector<TH1*> histograms,
                 int & xMinValueBin, double & minValue,
                 int & xMaxValueBin, double & maxValue,
                 int xFirstBin, int xLastBin)
{
  for (auto & histogram : histograms)
    {
    findMinMax (histogram,xMinValueBin,minValue,xMaxValueBin,maxValue,xFirstBin,xLastBin);
    }
}



void findMinimum(TH2 * h, int & xMinValueBin, int & yMinValueBin, double & minValue, int xFirstBin, int xLastBin, int yFirstBin, int yLastBin)
{
  if (!h) throw NullPointerException(__FUNCTION__);
  int nx = h->GetNbinsX();
  int ny = h->GetNbinsY();
  if (xFirstBin<1) xFirstBin = 1;
  if (xLastBin<1 || xLastBin>nx)  xLastBin = nx;
  if (yFirstBin<1) yFirstBin = 1;
  if (yLastBin<1 || yLastBin>ny)  yLastBin = ny;
  for (int ix=xFirstBin;ix<=xLastBin;++ix)
    {
    for (int iy=yFirstBin;iy<=yLastBin;++iy)
      {
      double v = h->GetBinContent(ix,iy);
      if (v<minValue)
        {
        xMinValueBin = ix;
        yMinValueBin = iy;
        minValue = v;
        }
      }
    }
}

void findMaximum(TH2 * h, int & xMaxValueBin, int & yMaxValueBin, double & maxValue, int xFirstBin, int xLastBin, int yFirstBin, int yLastBin)
{
  if (!h) throw NullPointerException(__FUNCTION__);
  int nx = h->GetNbinsX();
  int ny = h->GetNbinsY();
  if (xFirstBin<1) xFirstBin = 1;
  if (xLastBin<1 || xLastBin>nx)  xLastBin = nx;
  if (yFirstBin<1) yFirstBin = 1;
  if (yLastBin<1 || yLastBin>ny)  yLastBin = ny;
  for (int ix=xFirstBin;ix<=xLastBin;++ix)
    {
    for (int iy=yFirstBin;iy<=yLastBin;++iy)
      {
      double v = h->GetBinContent(ix,iy);
      if (v>maxValue)
        {
        xMaxValueBin = ix;
        yMaxValueBin = iy;
        maxValue = v;
        }
      }
    }
}

void findMinMax (TH2 * h,
                 int & xMinValueBin, int & yMinValueBin, double & minValue,
                 int & xMaxValueBin, int & yMaxValueBin, double & maxValue,
                 int xFirstBin, int xLastBin,
                 int yFirstBin, int yLastBin)
{
  if (!h) throw NullPointerException(__FUNCTION__);
  int nx = h->GetNbinsX();
  int ny = h->GetNbinsY();
  if (xFirstBin<1) xFirstBin = 1;
  if (xLastBin<1 || xLastBin>nx)  xLastBin = nx;
  if (yFirstBin<1) yFirstBin = 1;
  if (yLastBin<1 || yLastBin>ny)  yLastBin = ny;
  for (int ix=xFirstBin;ix<=xLastBin;++ix)
    {
    for (int iy=yFirstBin;iy<=yLastBin;++iy)
      {
      double v = h->GetBinContent(ix,iy);
      if (v<minValue)
        {
        xMinValueBin = ix;
        yMinValueBin = iy;
        minValue = v;
        }
      if (v>maxValue)
        {
        xMaxValueBin = ix;
        yMaxValueBin = iy;
        maxValue = v;
        }
      }
    }
  }

void findMinMax (std::vector<TH2*> histograms,
                 int & xMinValueBin, int & yMinValueBin, double & minValue,
                 int & xMaxValueBin, int & yMaxValueBin, double & maxValue,
                 int xFirstBin, int xLastBin,
                 int yFirstBin, int yLastBin)
{
  for (auto & histogram : histograms)
    {
    findMinMax (histogram,xMinValueBin,yMinValueBin,minValue,xMaxValueBin,yMaxValueBin,maxValue,xFirstBin,xLastBin,yFirstBin,yLastBin);
    }
}



void scaleByBinWidth1D(TH1 * h, double scale)
{
  if (!ptrExist(__FUNCTION__,h)) throw NullPointerException(__FUNCTION__);
  int n_x = h->GetNbinsX();
  double width_x, v, ev;
  for (int i_x=1; i_x<=n_x; ++i_x)
    {
    v = h->GetBinContent(i_x);
    ev = h->GetBinError(i_x);
    width_x = h->GetBinWidth(i_x);
    h->SetBinContent(i_x,v*scale/width_x);
    h->SetBinError(i_x,ev*scale/width_x);
    }
}

void scaleByBinWidth2D(TH2 * h, double scale)
{

  if (!ptrExist(__FUNCTION__,h)) throw NullPointerException(__FUNCTION__);

  TAxis * xAxis = h->GetXaxis();
  TAxis * yAxis = h->GetYaxis();
  int n_x = h->GetNbinsX();
  int n_y = h->GetNbinsY();
  double width_x,width_y, v, ev, w;
  for (int i_x=1; i_x<=n_x; ++i_x)
    {
    width_x = xAxis->GetBinWidth(i_x);
    for (int i_y=1; i_y<=n_y; ++i_y)
      {
      v  = h->GetBinContent(i_x,i_y);
      ev = h->GetBinError(i_x,i_y);
      width_y = yAxis->GetBinWidth(i_y);
      w = scale/(width_x*width_y);
      h->SetBinContent(i_x,i_y,v*w);
      h->SetBinError(i_x,i_y,ev*w);
      }
    }
}

void scaleByBinWidth3D(TH3 * h, double scale)
{
  if (!ptrExist(__FUNCTION__,h))  throw NullPointerException(__FUNCTION__);
  TAxis * xAxis = h->GetXaxis();
  TAxis * yAxis = h->GetYaxis();
  TAxis * zAxis = h->GetZaxis();
  int n_x = h->GetNbinsX();
  int n_y = h->GetNbinsY();
  int n_z = h->GetNbinsZ();
  double width_x,width_y, width_z, v, ev, w;
  for (int i_x=1; i_x<=n_x; ++i_x)
    {
    width_x = xAxis->GetBinWidth(i_x);
    for (int i_y=1; i_y<=n_y; ++i_y)
      {
      width_y = yAxis->GetBinWidth(i_y);
      for (int i_z=1; i_z<=n_z; ++i_z)
        {
        width_z = zAxis->GetBinWidth(i_z);
        v  = h->GetBinContent(i_x, i_y, i_z);
        ev = h->GetBinError(  i_x, i_y, i_z);
        w = scale/(width_x*width_y*width_z);
        h->SetBinContent(i_x, i_y, i_z,  v*w);
        h->SetBinError(  i_x, i_y, i_z,  ev*w);
        }
      }
    }
}

void scaleByBinWidth(TH1 * h, double scale)
{
  if (!ptrExist(__FUNCTION__,h)) throw NullPointerException(__FUNCTION__);
  TClass * c = h->IsA();
  if (c == TProfile::Class() || c == TProfile2D::Class()) return;
  else if (c == TH1F::Class() || c == TH1D::Class())
    scaleByBinWidth1D(h, scale);
  else if (c == TH2F::Class() || c == TH2D::Class())
    scaleByBinWidth2D((TH2*) h, scale);
  else if (c == TH3F::Class() || c == TH3D::Class())
    scaleByBinWidth3D((TH3*) h, scale);
}

void unpack_vsXY_to_vsXVsY(const TH1 * source, TH2 * target)
{

  if (!ptrExist(__FUNCTION__,source)) throw NullPointerException(__FUNCTION__);
  // Unpack 1D source histogram into a 2D histogram
  int k = 1;
  double v;
  int n  = source->GetNbinsX();
  int n_x = target->GetNbinsX();
  int n_y = target->GetNbinsY();
  if (n!=n_x*n_y)
   throw IncompatibleHistogramException(__FUNCTION__);

  for (int i_x=1; i_x<=n_x; ++i_x)
    {
    for (int i_y=1; i_y<=n_y; ++i_y)
      {
      v  = source->GetBinContent(k);
      //ev = source->GetBinError(k);
      target->SetBinContent(i_x,i_y,v);
      target->SetBinError(i_x,i_y,v);
      k++;
      }
    }
}

void correctMerging(TH1 * h, int nEta, int nPhi, bool reverse)
{

  if (!ptrExist(__FUNCTION__,h)) throw NullPointerException(__FUNCTION__);
  double v, ev;
  int iEta, iPhi, iDphi, iPhiA, iPhiB;
  int ij1, ij2;
  int nEtaPhi = nEta*nPhi;
  for (iEta=0; iEta<nEta; iEta++)
    {
    for (iPhi=0; iPhi<nPhi; iPhi++)
      {
      for (iDphi=1; iDphi<7; iDphi++)
        {
        iPhiA = iPhi+iDphi;  if (iPhiA>=nPhi) iPhiA -= nPhi; // Dphi12 = iPhi-iPhiA < 0
        iPhiB = iPhi-iDphi;  if (iPhiB< 0) iPhiB += nPhi; // Dphi12 = iPhi-iPhiB > 0
        //Deta==0
        ij1 = nEtaPhi*(iEta*nPhi+iPhi) + iEta*nPhi+iPhiA;
        ij2 = nEtaPhi*(iEta*nPhi+iPhi) + iEta*nPhi+iPhiB;
        if (reverse)
          {
          v  = h->GetBinContent(ij1);
          ev = h->GetBinError(ij1);
          h->SetBinContent(ij2,v);
          h->SetBinError(ij2,ev);
          }
        else
          {
          v  = h->GetBinContent(ij2);
          ev = h->GetBinError(ij2);
          h->SetBinContent(ij1,v);
          h->SetBinError(ij1,ev);
          }
        if (iEta>0)   //Deta==1
          {
          ij1 = nEtaPhi*(iEta*nPhi+iPhi) + (iEta-1)*nPhi+iPhiA;
          ij2 = nEtaPhi*(iEta*nPhi+iPhi) + (iEta-1)*nPhi+iPhiB;
          if (reverse)
            {
            v  = h->GetBinContent(ij1);
            ev = h->GetBinError(ij1);
            h->SetBinContent(ij2,v);
            h->SetBinError(ij2,ev);
            }
          else
            {
            v  = h->GetBinContent(ij2);
            ev = h->GetBinError(ij2);
            h->SetBinContent(ij1,v);
            h->SetBinError(ij1,ev);
            }

          }
        if (iEta<nEta)   //Deta==1
          {
          ij1 = nEtaPhi*(iEta*nPhi+iPhi) + (iEta+1)*nPhi+iPhiA;
          ij2 = nEtaPhi*(iEta*nPhi+iPhi) + (iEta+1)*nPhi+iPhiB;
          if (reverse)
            {
            v  = h->GetBinContent(ij1);
            ev = h->GetBinError(ij1);
            h->SetBinContent(ij2,v);
            h->SetBinError(ij2,ev);
            }
          else
            {
            v  = h->GetBinContent(ij2);
            ev = h->GetBinError(ij2);
            h->SetBinContent(ij1,v);
            h->SetBinError(ij1,ev);
            }

          }

        }
      }
    }
}

//!
//! Calculate the 'triangle' normalization
//! target will be divided by bin widths and scaleFactor
//!
void calculateAvgH2H2(const TH2 * source, TH2 * target, double scaleFactor)
{
  if (!ptrExist(__FUNCTION__,source,target)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,source,target))  throw IncompatibleHistogramException(__FUNCTION__);
  int nDeta = source->GetNbinsX();
  int nDphi = source->GetNbinsY();
  vector<double> denominator(nDeta,0.0);
  for (int iEta=0;iEta<(nDeta+1)/2; ++iEta)
    {
    denominator[iEta] = iEta+1;
    denominator[nDeta-1-iEta] = iEta+1;
    }
  double v1, ev1;
  for (int iEta=1;iEta<=nDeta; ++iEta)
    {
    for (int iPhi=1;iPhi<=nDphi; ++iPhi)
      {
      v1   = source->GetBinContent(iEta,iPhi);
      ev1  = source->GetBinError(  iEta,iPhi);
      v1   = v1/denominator[iEta-1];
      ev1  = ev1/denominator[iEta-1];
      target->SetBinContent(iEta,iPhi,v1);
      target->SetBinError  (iEta,iPhi,ev1);
      }
    }
  double wx = target->GetXaxis()->GetBinWidth(1);
  double wy = target->GetYaxis()->GetBinWidth(1);
  double factor = 1.0/(wx*wy*scaleFactor);
  target->Scale(factor);
}



void calculateAverageVsDeta(const TH2 * obs_12, TH2 * avgObs_12, int n)
{
  if (!ptrExist(__FUNCTION__,obs_12,avgObs_12)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,obs_12,avgObs_12))  throw IncompatibleHistogramException(__FUNCTION__);
  int n_x = obs_12->GetNbinsX();
  int n_y = obs_12->GetNbinsY();
  vector<double> denom(n_x,1.0);
  int off = (n_x - (2*n-1))/2;
  for (int i_x=0; i_x<n; ++i_x)
    {
    if (i_x==0)
      {
      denom[off + n] = n;
      }
    else
      {
      denom[off + n + i_x] = n-i_x;
      denom[off + n - i_x] = n-i_x;
      }
    }
  for (int i_x=0; i_x<n; ++i_x)
    {
    for (int i_y=1;i_y<=n_y;++i_y)
      {
      double v  = obs_12->GetBinContent(i_x,i_y);
      double ev = obs_12->GetBinError(i_x,i_y);
      v  = v/denom[i_x];
      ev = ev/denom[i_x];
      avgObs_12->SetBinContent(i_x,i_y,v);
      avgObs_12->SetBinError(i_x,i_y,ev);
      }
    }
}

//!
//! Calculate C2 = N2 - N1*N1
//!
void calculateC2_H1H1H1(const TH1 * n2_12, const TH1 * n1n1_12, TH1 * c2_12, bool ijNormalization, double a1, double a2)
{
  if (!ptrExist(__FUNCTION__,n2_12,n1n1_12,c2_12))  throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n2_12,n1n1_12,c2_12))  throw IncompatibleHistogramException(__FUNCTION__);
  int n2_12_n_x = n2_12->GetNbinsX();
  double v1,ev1,v2,ev2,v,ev;
  for (int i1=1;i1<=n2_12_n_x;++i1)
    {
    v1  = a1*n2_12->GetBinContent(i1);    ev1 = a1*n2_12->GetBinError(i1);
    v2  = a2*n1n1_12->GetBinContent(i1);  ev2 = a2*n1n1_12->GetBinError(i1);
    v  = v1-v2;
    ev = sqrt(ev1*ev1+ev2*ev2);
    c2_12->SetBinContent(i1,v); c2_12->SetBinError(i1,ev);
    }
}

//!
//! Calculate C2 = N2 - N1*N1
//!
void calculateC2_H2H2H2(const TH2 * n2_12, const TH2 * n1n1_12, TH2 * c2_12, bool ijNormalization, double a1, double a2)
{
  if (!ptrExist(__FUNCTION__,n2_12,n1n1_12,c2_12))  throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n2_12,n1n1_12,c2_12))  throw IncompatibleHistogramException(__FUNCTION__);
  int n2_12_n_x = n2_12->GetNbinsX();
  int n2_12_n_y = n2_12->GetNbinsY();
  double v1,ev1,v2,ev2,v,ev;
  for (int i1=1;i1<=n2_12_n_x;++i1)
    {
    for (int i2=1;i2<=n2_12_n_y;++i2)
      {
      v1  = a1*n2_12->GetBinContent(i1,i2);    ev1 = a1*n2_12->GetBinError(i1,i2);
      v2  = a2*n1n1_12->GetBinContent(i1,i2);  ev2 = a2*n1n1_12->GetBinError(i1,i2);
      v  = v1-v2;
      ev = sqrt(ev1*ev1+ev2*ev2);
      c2_12->SetBinContent(i1,i2,v); c2_12->SetBinError(i1,i2,ev);
      }
    }
}

//!
//! Calculate C2 = N2 - N1*N1
//!
void calculateC2_H3H3H3(const TH3 * n2_12, const TH3 * n1n1_12, TH3 * c2_12, bool ijNormalization, double a1, double a2)
{
  if (!ptrExist(__FUNCTION__,n2_12,n1n1_12,c2_12))  throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n2_12,n1n1_12,c2_12))  throw IncompatibleHistogramException(__FUNCTION__);
  int n2_12_n_x   = n2_12->GetNbinsX();
  int n2_12_n_y   = n2_12->GetNbinsY();
  int n2_12_n_z   = n2_12->GetNbinsZ();
  double v1,ev1,v2,ev2,v,ev;
  for (int i1=1;i1<=n2_12_n_x;++i1)
    {
    for (int i2=1;i2<=n2_12_n_y;++i2)
      {
      for (int i3=1;i2<=n2_12_n_y;++i2)
        {
        v1  = a1*n2_12->GetBinContent(i1,i2,i3);    ev1 = a1*n2_12->GetBinError(i1,i2,i3);
        v2  = a2*n1n1_12->GetBinContent(i1,i2,i3);  ev2 = a2*n1n1_12->GetBinError(i1,i2,i3);
        v  = v1-v2;
        ev = sqrt(ev1*ev1+ev2*ev2);
        c2_12->SetBinContent(i1,i2,i3,v); c2_12->SetBinError(i1,i2,i3,ev);
        }
      }
    }
}

//!
//! Calculate R2 = binCorrection*N2/N1/N1 - 1
//!
void calculateR2_H1H1H1(const TH1 * n2_12, const TH1 * n1n1_12, TH1 * r2_12, bool ijNormalization, double a1, double a2)
{
  if (!ptrExist(__FUNCTION__,n2_12,n1n1_12,r2_12))  throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n2_12,n1n1_12,r2_12))  throw IncompatibleHistogramException(__FUNCTION__);
  int n2_12_n_x = n2_12->GetNbinsX();
  double v1,ev1,v2,ev2,v,ev, re1,re2;
  for (int i1=1;i1<=n2_12_n_x;++i1)
    {
    v1  = a1*n2_12->GetBinContent(i1);    ev1 = a1*n2_12->GetBinError(i1);
    v2  = a2*n1n1_12->GetBinContent(i1);  ev2 = a2*n1n1_12->GetBinError(i1);
    if (v1>0 && v2>0 && ev1/v1<0.5  && ev2/v2<0.5 )
      {
      if (ijNormalization) //account for the fact only half the pairs were counted
        {
        v   = 2*v1/v2;
        }
      else // all pairs counted - no need to multiply by 2
        {
        v   = v1/v2;
        }
      re1 = ev1/v1;
      re2 = ev2/v2;
      ev  = v*sqrt(re1*re1+re2*re2);
      v   -= 1.;
      }
    else
      {
      v = 0.;
      ev = 0;
      }
    r2_12->SetBinContent(i1,v); r2_12->SetBinError(i1,ev);
    }
}

//!
//! Calculate R2 = binCorrection*N2/N1/N1 - 1
//!
void calculateR2_H2H2H2(const TH2 * n2_12, const TH2 * n1n1_12, TH2 * r2_12, bool ijNormalization, double a1, double a2)
{
  if (!ptrExist(__FUNCTION__,n2_12,n1n1_12,r2_12)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n2_12,n1n1_12,r2_12))  throw IncompatibleHistogramException(__FUNCTION__);
  int n2_12_n_x = n2_12->GetNbinsX();
  int n2_12_n_y = n2_12->GetNbinsY();
  double v1,ev1,v2,ev2,v,ev, re1,re2;
  for (int i_x=1;i_x<=n2_12_n_x;++i_x)
    {
    for (int i_y=1;i_y<=n2_12_n_y;++i_y)
      {
      v1  = a1*n2_12->GetBinContent(i_x,i_y);    ev1 = a1*n2_12->GetBinError(i_x,i_y);
      v2  = a2*n1n1_12->GetBinContent(i_x,i_y);  ev2 = a2*n1n1_12->GetBinError(i_x,i_y);
      if (v1>0 && v2>0) //   && ev1/v1<0.5  && ev2/v2<0.5)
        {
        if (ijNormalization) //account for the fact only half the pairs were counted
          v   = 2*v1/v2;
        else // all pairs counted - no need to multiply by 2
          v   = v1/v2;
        re1 = ev1/v1;
        re2 = ev2/v2;
        ev  = v*sqrt(re1*re1+re2*re2);
        v   -= 1.;
        }
      else
        {
        v = 0.;
        ev = 0;
        }
      r2_12->SetBinContent(i_x,i_y,v); r2_12->SetBinError(i_x,i_y,ev);
      }
    }
}

//!
//! Calculate R2 = binCorrection*N2/N1/N1 - 1
//!
void calculateR2_H3H3H3(const TH3 * n2_12, const TH3 * n1n1_12, TH3 * r2_12, bool ijNormalization, double a1, double a2)
{
  if (!ptrExist(__FUNCTION__,n2_12,n1n1_12,r2_12)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,n2_12,n1n1_12,r2_12))  throw IncompatibleHistogramException(__FUNCTION__);
  int n2_12_n_x = n2_12->GetNbinsX();
  int n2_12_n_y = n2_12->GetNbinsY();
  int n2_12_n_z = n2_12->GetNbinsZ();
  double v1,ev1,v2,ev2,v,ev, re1,re2;
  for (int i_x=1;i_x<=n2_12_n_x;++i_x)
    {
    for (int i_y=1;i_y<=n2_12_n_y;++i_y)
      {
      for (int i_z=1;i_z<=n2_12_n_z;++i_z)
        {
        v1  = a1*n2_12->GetBinContent(i_x,i_y,i_z);    ev1 = a1*n2_12->GetBinError(i_x,i_y,i_z);
        v2  = a2*n1n1_12->GetBinContent(i_x,i_y,i_z);  ev2 = a2*n1n1_12->GetBinError(i_x,i_y,i_z);
        if (v1>0 && v2>0) //   && ev1/v1<0.5  && ev2/v2<0.5)
          {
          if (ijNormalization) //account for the fact only half the pairs were counted
            v   = 2*v1/v2;
          else // all pairs counted - no need to multiply by 2
            v   = v1/v2;
          re1 = ev1/v1;
          re2 = ev2/v2;
          ev  = v*sqrt(re1*re1+re2*re2);
          v   -= 1.;
          }
        else
          {
          v = 0.;
          ev = 0;
          }
        r2_12->SetBinContent(i_x,i_y,i_z,v); r2_12->SetBinError(i_x,i_y,i_z,ev);
        }
      }
    }
}


//Calculate R2 = N2/N1/N1 - 1
void calculateR2_H1H2H2(const TH1 * n2_12, const TH2 * n1n1_12, TH2 * r2_12, bool ijNormalization, double a1, double a2)
{
  if (!ptrExist(__FUNCTION__,n2_12,n1n1_12,r2_12)) throw NullPointerException(__FUNCTION__);
  int n2_12_n_x    = n2_12->GetNbinsX();
  int n1n1_12_n_x  = n1n1_12->GetNbinsX();
  int n1n1_12_n_y  = n1n1_12->GetNbinsY();
  int r2_12_n_x    = r2_12->GetNbinsX();
  int r2_12_n_y    = r2_12->GetNbinsY();
  if (n2_12_n_x!=(n1n1_12_n_x*n1n1_12_n_y) || n1n1_12_n_x!=r2_12_n_x || n1n1_12_n_y!=r2_12_n_y )
    throw IncompatibleHistogramException(__FUNCTION__);
  double v1,ev1,v2,ev2,v,ev, re1,re2;
  int i = 1;
  for (int i_x=1;i_x<=n1n1_12_n_x;++i_x)
    {
    for (int i_y=1;i_y<=n1n1_12_n_y;++i_y)
      {
      v1  = a1*n2_12->GetBinContent(i);        ev1 = a1*n2_12->GetBinError(i);
      v2  = a2*n1n1_12->GetBinContent(i_x,i_y);  ev2 = a2*n1n1_12->GetBinError(i_x,i_y);
      if (v1>0 && v2>0  && ev1/v1<0.5  && ev2/v2<0.5)
        {
        if (ijNormalization) //account for the fact only half the pairs were counted
          v   = 2*v1/v2;
        else // all pairs counted - no need to multiply by 2
          v   = v1/v2;
        re1 = ev1/v1;
        re2 = ev2/v2;
        ev  = v*sqrt(re1*re1+re2*re2);
        v   -= 1.;
        }
      else
        {
        v = 0.;
        ev = 0;
        }
      r2_12->SetBinContent(i_x,i_y,v); r2_12->SetBinError(i_x,i_y,ev);
      i++;
      }
    }
}



void calculateR2VsM(const TProfile * h1, const TProfile * h2, const TProfile * h12, TH1 * r2VsM, TH1 * intR2, bool sameFilter)
{
  if (!ptrExist(__FUNCTION__,h1,h2,h12,r2VsM,intR2)) throw NullPointerException(__FUNCTION__);
  int n1, n2, n3, n4, n5;
  n1   = h1->GetNbinsX();
  if (sameFilter) n2 = n1; else n2   = h2->GetNbinsX();
  n3   = h12->GetNbinsX();
  n4   = r2VsM->GetNbinsX();
  n5   = intR2->GetNbinsX();
  if (n1!=n2 || n1!=n3 || n1!=n4 || n5!=1)throw IncompatibleHistogramException(__FUNCTION__);
  double n, nSum, vSum, v1,v2,v12,ev12, r, er;
  nSum = vSum = 0;
  for (int i=1;i<=n1;++i)
    {
    n    = h1->GetBinEntries(i);
    v1   = h1->GetBinContent(i);  //ev1  = h1->GetBinError(i);
    if (sameFilter)
      {
      v2   = v1;  //ev2  = ev1;
      }
    else
      {
      v2   = h2->GetBinContent(i);  //ev2  = h2->GetBinError(i);
      }
    v12  = h12->GetBinContent(i); ev12 = h12->GetBinError(i);
    if (v1>0 && v2>0 && v12>0)
      {
      r = v12/(v1*v2);
      er = r*ev12/v12; // under estimate errors.
      nSum += n;
      vSum += n*r;
      }
    else
      {
      r  = 1;
      er = 0;
      }
    r2VsM->SetBinContent(i,r);
    r2VsM->SetBinError(i,er);
    }
  if (nSum>0)
    {
    intR2->SetBinContent(1,vSum/nSum);
    intR2->SetBinError(1,0.);
    }
  else
    {
    intR2->SetBinContent(1,0.);
    intR2->SetBinError(1,0.);
    }
}

void calculateBinCorr(const TProfile * h1, const TProfile * h2, TH1 * intBinCorrVsM1, bool sameFilter)
{
  if (!ptrExist(__FUNCTION__,h1,h2,intBinCorrVsM1))  throw NullPointerException(__FUNCTION__);
  int n1, n2, n3;
  n1   = h1->GetNbinsX();
  if (sameFilter) n2 = n1; else n2   = h2->GetNbinsX();
  n3   = intBinCorrVsM1->GetNbinsX();
  if (n1!=n2 || n3!=1) throw IncompatibleHistogramException(__FUNCTION__);
  double n, nSum, sum1, sum2, sum12, v1,v2;
  sum1 = sum2 = sum12 = nSum = 0;
  for (int i=1;i<=n1;++i)
    {
    n    = h1->GetBinEntries(i);
    v1   = h1->GetBinContent(i);
    if (sameFilter) v2 = v1; else v2 = h2->GetBinContent(i);
    if (n>0)
      {
      nSum += n;
      sum1 += n*v1;
      sum2 += n*v2;
      sum12 += n*v1*v2;
      }
    }
  if (nSum>0 && sum1>0 && sum2>0)
    {
    sum1 /= nSum;
    sum2 /= nSum;
    sum12 /= nSum;
    intBinCorrVsM1->SetBinContent(1,sum12/(sum1*sum2));
    intBinCorrVsM1->SetBinError(1,0.);
    }
  else
    {
    intBinCorrVsM1->SetBinContent(1,1.); //no stat - so set correction factor to unity
    intBinCorrVsM1->SetBinError(1,0.);
    }

}

//!
//! Compute the average density of particles based on the given dN/dx histogram.
//! The histogram is assumed to be a yield per event per bin vs. eta
//! The average value is thus divided by the bin width to make it into a density.
//! This yields a density integrated over 2pi. So to use this number, one must also
//! divide by 2pi.
//!
void calculateAverage(TH1* h, double & avgDensity, double & eAvgDensity)
{

  int n = h->GetNbinsX();
  double v, ev, width, sum, esum, avgValue;
  sum  = 0.0;
  esum = 0.0;
  //  int first = 9;
  //  int last  = 32;
  int first = 1;
  int last  = n;
  int norm  = last - first + 1;
  for (int i=first; i<=last; i++)
    {
    v     = h->GetBinContent(i);
    ev    = h->GetBinError(i);
    width = h->GetBinWidth(i);
    sum  += v/width;
    esum += ev*ev/width/width;
    }
  avgValue    = sum/norm;
  avgDensity  = avgValue/Math::twoPi();
  eAvgDensity = sqrt(esum)/norm/Math::twoPi();
}

void calculateIntegral(TH1 * h, double xMin, double xMax, double  & result, double & resultError, int option)
{

  int xFirst = h->GetXaxis()->FindBin(xMin);
  int xLast  = h->GetXaxis()->FindBin(xMax);

  double sum, sumError;
  double integral, integralError;
  sum      = h->IntegralAndError(xFirst,xLast, sumError);
  integral = h->IntegralAndError(xFirst,xLast, integralError, "Width");
  switch (option)
    {
      case 0: result = sum; resultError = sumError; break;
      case 1: result = integral; resultError = integralError; break;
    }
}

void calculateIntegral(TH2 * h, double xMin, double xMax, double yMin, double yMax, double  & result, double & resultError, int option)
{
  int xFirst = h->GetXaxis()->FindBin(xMin);
  int xLast  = h->GetXaxis()->FindBin(xMax);
  int yFirst = h->GetYaxis()->FindBin(yMin);
  int yLast  = h->GetYaxis()->FindBin(yMax);

  double sum, sumError;
  double integral, integralError;
  sum      = h->IntegralAndError(xFirst,xLast, yFirst, yLast, sumError);
  integral = h->IntegralAndError(xFirst,xLast, yFirst, yLast, integralError, "Width");
  switch (option)
    {
      case 0: result = sum; resultError = sumError; break;
      case 1: result = integral; resultError = integralError; break;
    }
}

void calculateAveragePt(const TH1 * h1, const TH1 * h2, TH1 * h3)
{
  if (!ptrExist(__FUNCTION__,h1,h2,h3))  throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,h1,h2,h3))  throw IncompatibleHistogramException(__FUNCTION__);

  int n1 = h1->GetNbinsX();
  double v1,ev1,v2,ev2,v,ev, re1,re2;
  for (int i1=1;i1<=n1;++i1)
    {
    v1  = h1->GetBinContent(i1);  ev1 = h1->GetBinError(i1);
    v2  = h2->GetBinContent(i1);  ev2 = h2->GetBinError(i1);
    if (v1>0 && v2>0)
      {
      v = v1/v2;
      re1 = ev1/v1;
      re2 = ev2/v2;
      ev = v*sqrt(re1*re1+re2*re2);
      }
    else
      {
      v = 0.;
      ev = 0;
      }
    h3->SetBinContent(i1,v); h3->SetBinError(i1,ev);
    }
}

//Calculate average pt by dividing sPt contained in h1 by n1 contained in h2. Store in h3.

void calculateAveragePtH2(const TH2 * h1, const TH2 * h2, TH2 * h3)
{
  if (!ptrExist(__FUNCTION__,h1,h2,h3))  throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,h1,h2,h3))  throw IncompatibleHistogramException(__FUNCTION__);
  int n1x   = h1->GetNbinsX();
  int n1y   = h1->GetNbinsY();
  double v1,ev1,v2,ev2,v,ev, re1,re2;
  for (int i_x=1;i_x<=n1x;++i_x)
    {
    for (int i_y=1;i_y<=n1y;++i_y)
      {
      v1  = h1->GetBinContent(i_x,i_y);  ev1 = h1->GetBinError(i_x,i_y);
      v2  = h2->GetBinContent(i_x,i_y);  ev2 = h2->GetBinError(i_x,i_y);
      if (v1>0 && v2>0)
        {
        v = v1/v2;
        re1 = ev1/v1;
        re2 = ev2/v2;
        ev = v*sqrt(re1*re1+re2*re2);
        }
      else
        {
        v = 0.;
        ev = 0;
        }
      h3->SetBinContent(i_x,i_y,v); h3->SetBinError(i_x,i_y,ev);
      }
    }
}

void calculateAveragePtH1H2(const TH1 * h1, const TH1 * h2, TH2 * h3)
{
  if (!ptrExist(__FUNCTION__,h1,h2,h3))  throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,h1,h2)) throw IncompatibleHistogramException(__FUNCTION__);
  //Calculate average pt by dividing sPt contained in h1 by n1 contained in h2. Store in h3.
  int n3x  = h3->GetNbinsX();
  int n3y  = h3->GetNbinsY();
  double v1,ev1,v2,ev2,v,ev, re1,re2;
  int i = 1;
  for (int i_x=1;i_x<=n3x;++i_x)
    {
    for (int i_y=1;i_y<=n3y;++i_y)
      {
      v1  = h1->GetBinContent(i);  ev1 = h1->GetBinError(i);
      v2  = h2->GetBinContent(i);  ev2 = h2->GetBinError(i);
      if (v1>0 && v2>0)
        {
        v = v1/v2;
        re1 = ev1/v1;
        re2 = ev2/v2;
        ev = v*sqrt(re1*re1+re2*re2);
        }
      else
        {
        v = 0.;
        ev = 0;
        }
      h3->SetBinContent(i_x,i_y,v); h3->SetBinError(i_x,i_y,ev);
      i++;
      }
    }
}

void calculateAveragePt(const TProfile * h1, const TProfile * h2, TH1 * h3)
{
  if (!ptrExist(__FUNCTION__,h1,h2,h3))  throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,h1,h2,h3))  throw IncompatibleHistogramException(__FUNCTION__);
  double v1,ev1,v2,ev2,v,ev, re1,re2;
  int n1 = h1->GetNbinsX();
  for (int i1=1;i1<=n1;++i1)
    {
    v1  = h1->GetBinContent(i1);  ev1 = h1->GetBinError(i1);
    v2  = h2->GetBinContent(i1);  ev2 = h2->GetBinError(i1);
    if (v2>0)
      {
      v = v1/v2;
      re1 = ev1/v1;
      re2 = ev2/v2;
      ev = v*sqrt(re1*re1+re2*re2);
      }
    else
      {
      v = 0.;
      ev = 0;
      }
    h3->SetBinContent(i1,v);  h3->SetBinError(i1,ev);
    }
}

void symmetrize3D(TH3* h)
{
  if (!ptrExist(__FUNCTION__,h))  throw NullPointerException(__FUNCTION__);
  int n = h->GetNbinsX();
  int nc = n/2;
  int nf = nc + 1;
  double v1, v2, v3, v4, v5, v6, v7, v8;
  double ev1, ev2, ev3, ev4, ev5, ev6, ev7, ev8;
  double v, ev;
  for (int i1=1; i1<=nc; i1++)
    {
    for (int i2=1; i2<=nc; i2++)
      {
      for (int i3=1; i3<=nc; i3++)
        {
        v1 = h->GetBinContent(nc+i1,nc+i2,nc+i3);  ev1 = h->GetBinError(nc+i1,nc+i2,nc+i3);
        v2 = h->GetBinContent(nc+i1,nc+i2,nf-i3);  ev2 = h->GetBinError(nc+i1,nc+i2,nf-i3);
        v3 = h->GetBinContent(nc+i1,nf-i2,nc+i3);  ev3 = h->GetBinError(nc+i1,nf-i2,nc+i3);
        v4 = h->GetBinContent(nc+i1,nf-i2,nf-i3);  ev4 = h->GetBinError(nc+i1,nf-i2,nf-i3);
        v5 = h->GetBinContent(nf-i1,nc+i2,nc+i3);  ev5 = h->GetBinError(nf-i1,nc+i2,nc+i3);
        v6 = h->GetBinContent(nf-i1,nc+i2,nf-i3);  ev6 = h->GetBinError(nf-i1,nc+i2,nf-i3);
        v7 = h->GetBinContent(nf-i1,nf-i2,nc+i3);  ev7 = h->GetBinError(nf-i1,nf-i2,nc+i3);
        v8 = h->GetBinContent(nf-i1,nf-i2,nf-i3);  ev8 = h->GetBinError(nf-i1,nf-i2,nf-i3);

        v = (v1+v2+v3+v4+v5+v6+v7+v8)/8.0;
        ev = sqrt(ev1*ev1+ev2*ev2+ev3*ev3+ev4*ev4+ev5*ev5+ev6*ev6+ev7*ev7+ev8*ev8)/8.0;

        h->SetBinContent(nc+i1,nc+i2,nc+i3,v);  h->SetBinError(nc+i1,nc+i2,nc+i3,ev);
        h->SetBinContent(nc+i1,nc+i2,nf-i3,v);  h->SetBinError(nc+i1,nc+i2,nf-i3,ev);
        h->SetBinContent(nc+i1,nf-i2,nc+i3,v);  h->SetBinError(nc+i1,nf-i2,nc+i3,ev);
        h->SetBinContent(nc+i1,nf-i2,nf-i3,v);  h->SetBinError(nc+i1,nf-i2,nf-i3,ev);
        h->SetBinContent(nf-i1,nc+i2,nc+i3,v);  h->SetBinError(nf-i1,nc+i2,nc+i3,ev);
        h->SetBinContent(nf-i1,nc+i2,nf-i3,v);  h->SetBinError(nf-i1,nc+i2,nf-i3,ev);
        h->SetBinContent(nf-i1,nf-i2,nc+i3,v);  h->SetBinError(nf-i1,nf-i2,nc+i3,ev);
        h->SetBinContent(nf-i1,nf-i2,nf-i3,v);  h->SetBinError(nf-i1,nf-i2,nf-i3,ev);

        }
      }
    }
}



// h must be writtable otherwise this does not work..
// x axis is DeltaEta. It must have an odd number of bins
// y axis is DeltaPhi. It must have an even number of bins
void symmetrizeDeltaEtaDeltaPhi(TH2 * h, bool ijNormalization)
{
  if (!ptrExist(__FUNCTION__,h))  throw NullPointerException(__FUNCTION__);
  double v1, v2, v3, v4;
  double ev1, ev2, ev3, ev4;
  double sv, esv;
  int nEta = h->GetNbinsX(); //DeltaEta
  int nPhi = h->GetNbinsY(); //DeltaPhi
  int nEtaHalf = (nEta-1)/2;
  int nPhiHalf = (nPhi-2)/2;
  int iEta, iPhi, iPhi1, iEta1;
  double * v = new double[nEta*nPhi];
  double * ev = new double[nEta*nPhi];
  for (int iPhi=0;iPhi<nPhi;iPhi++)
    {
    for (int iEta=0;iEta<nEta;iEta++)
      {
      iPhi1 = iPhi+1;
      iEta1 = iEta+1;
      v[ iEta+iPhi*nEta]  = h->GetBinContent(iEta1,iPhi1);
      ev[iEta+iPhi*nEta]  = h->GetBinError(  iEta1,iPhi1);
      }
    }
  for (iEta=0;iEta<nEtaHalf;iEta++)
    {
    iEta1 = iEta+1;
    for (iPhi=0; iPhi<nPhiHalf;iPhi++)
      {
      iPhi1 = iPhi+1;
      v1 = v[  nEta-iEta1+(nPhi-iPhi1)*nEta];
      v2 = v[  nEta-iEta1+(     iPhi1)*nEta];
      v3 = v[        iEta+(nPhi-iPhi1)*nEta];
      v4 = v[        iEta+(     iPhi1)*nEta];
      ev1 = ev[nEta-iEta1+(nPhi-iPhi1)*nEta];
      ev2 = ev[nEta-iEta1+(     iPhi1)*nEta];
      ev3 = ev[      iEta+(nPhi-iPhi1)*nEta];
      ev4 = ev[      iEta+(     iPhi1)*nEta];
      if (ijNormalization)
        {
        sv = (v1+v2+v3+v4)/2.;
        esv = sqrt(ev1*ev1+ev2*ev2+ev3*ev3+ev4*ev4)/2.;
        }
      else
        {
        sv = (v1+v2+v3+v4)/4.;
        esv = sqrt(ev1*ev1+ev2*ev2+ev3*ev3+ev4*ev4)/4.;
        }
      h->SetBinContent( nEta-iEta, nPhi-iPhi, sv);
      h->SetBinContent( nEta-iEta,   iPhi1+1, sv);
      h->SetBinContent(     iEta1, nPhi-iPhi, sv);
      h->SetBinContent(     iEta1,   iPhi1+1, sv);
      h->SetBinError(   nEta-iEta, nPhi-iPhi, esv);
      h->SetBinError(   nEta-iEta,   iPhi1+1, esv);
      h->SetBinError(       iEta1, nPhi-iPhi, esv);
      h->SetBinError(       iEta1,   iPhi1+1, esv);
      }
    }
  iEta  = nEtaHalf;
  iEta1 = iEta+1;
  for (iPhi=0; iPhi<nPhiHalf;iPhi++) // iEta center bin
    {
    iPhi1 = iPhi+1;
    v3 = v[        iEta+(nPhi-iPhi1)*nEta];
    v4 = v[        iEta+(     iPhi1)*nEta];
    ev3 = ev[      iEta+(nPhi-iPhi1)*nEta];
    ev4 = ev[      iEta+(     iPhi1)*nEta];
    if (ijNormalization)
      {
      sv = (v3+v4);
      esv = sqrt(ev3*ev3+ev4*ev4);
      }
    else
      {
      sv = (v3+v4)/2.;
      esv = sqrt(ev3*ev3+ev4*ev4)/2.;
      }
    h->SetBinContent(     iEta1, nPhi-iPhi, sv);
    h->SetBinContent(     iEta1,   iPhi1+1, sv);
    h->SetBinError(       iEta1, nPhi-iPhi, esv);
    h->SetBinError(       iEta1,   iPhi1+1, esv);
    }
  iPhi = 0;
  iPhi1 = iPhi+1;
  for (iEta=0;iEta<nEtaHalf;iEta++)
    {
    iEta1 = iEta+1;
    v1 = v[  nEta-iEta1];
    v3 = v[        iEta];
    ev1 = ev[nEta-iEta1];
    ev3 = ev[      iEta];
    if (ijNormalization)
      {
      sv = (v1+v3);
      esv = sqrt(ev1*ev1+ev3*ev3);
      }
    else
      {
      sv = (v1+v3)/2.;
      esv = sqrt(ev1*ev1+ev3*ev3)/2.;
      }
    h->SetBinContent( nEta-iEta, 1, sv);
    h->SetBinContent(     iEta1, 1, sv);
    h->SetBinError(   nEta-iEta, 1, esv);
    h->SetBinError(       iEta1, 1, esv);

    iPhi  = nPhi/2;
    iPhi1 = iPhi+1;
    v1 = v[  nEta-iEta1 + iPhi*nEta];
    v3 = v[        iEta + iPhi*nEta];
    ev1 = ev[nEta-iEta1 + iPhi*nEta];
    ev3 = ev[      iEta + iPhi*nEta];
    if (ijNormalization)
      {
      sv = (v1+v3);
      esv = sqrt(ev1*ev1+ev3*ev3);
      }
    else
      {
      sv = (v1+v3)/2.;
      esv = sqrt(ev1*ev1+ev3*ev3)/2.;
      }
    h->SetBinContent( nEta-iEta, iPhi1, sv);
    h->SetBinContent(     iEta1, iPhi1, sv);
    h->SetBinError(   nEta-iEta, iPhi1, esv);
    h->SetBinError(       iEta1, iPhi1, esv);
    }
  delete[] v;
}

void symmetrizeXX(TH2 * h, bool ijNormalization)
{
  if (!ptrExist(__FUNCTION__,h))  throw NullPointerException(__FUNCTION__);
  double v1, v2;
  double ev1, ev2;
  double sv, esv;
  int n_x = h->GetNbinsX(); //DeltaEta
  int n_y = h->GetNbinsY(); //DeltaPhi
  int i_x, i_y, i_x1, i_y1;
  double * v  = new double[n_x*n_y];
  double * ev = new double[n_x*n_y];
  for (i_x=0; i_x<n_x; i_x++)
    {
    i_x1 = i_x+1;
    for (i_y=0; i_y<n_y; i_y++)
      {
      i_y1 = i_y+1;
      v[ i_x+i_y*n_x]  = h->GetBinContent(i_x1,i_y1);
      ev[i_x+i_y*n_x]  = h->GetBinError(  i_x1,i_y1);
      }
    }
  for (i_x=0; i_x<n_x; i_x++)
    {
    i_x1 = i_x+1;
    for (i_y=0; i_y<n_y; i_y++)
      {
      i_y1 = i_y+1;
      v1 = v[  i_x+i_y*n_x ];
      v2 = v[  i_y+i_x*n_x ];
      ev1 = ev[ i_x+i_y*n_x ];
      ev2 = ev[ i_y+i_x*n_x];
      if (ijNormalization)
        {
        sv = (v1+v2);
        esv = sqrt(ev1*ev1+ev2*ev2);
        }
      else
        {
        sv = (v1+v2)/2.;
        esv = sqrt(ev1*ev1+ev2*ev2)/2.;
        }
      h->SetBinContent( i_x1, i_y1, sv);
      h->SetBinContent( i_y1, i_x1, sv);
      h->SetBinError(   i_x1, i_y1, esv);
      h->SetBinError(   i_y1, i_x1, esv);
      }
    }
  delete[] v;
}


void reduce_n2xEtaPhi_n2DetaDphi(const TH2 * source, TH2 * target,int nEtaBins,int nPhiBins)
{
  if (!ptrExist(__FUNCTION__,source,target))  throw NullPointerException(__FUNCTION__);
  double v1,v2,ev1;
  int dPhi,dEta, iPhi,iEta,jPhi,jEta, i, j;
  //int nBins = nEtaBins*nPhiBins;
  int nWrk  = nPhiBins*(2*nEtaBins-1);
  int index;
  double * numerator    = new double[nWrk];
  double * numeratorErr = new double[nWrk];
  double * denominator  = new double[nWrk];
  for (int k=0;k<nWrk;++k)
    {
    numerator[k]    = 0;
    numeratorErr[k] = 0;
    denominator[k]  = 0;
    }

  String name = target->GetName();

  i=1;
  for (iEta=0;iEta<nEtaBins; ++iEta)
    {
    for (iPhi=0;iPhi<nPhiBins; ++iPhi)
      {
      j=1;
      for (jEta=0;jEta<nEtaBins; ++jEta)
        {
        for (jPhi=0;jPhi<nPhiBins; ++jPhi)
          {
          dPhi = iPhi-jPhi; if (dPhi<0) dPhi += nPhiBins; dPhi+=1;
          dEta = iEta-jEta + nEtaBins;
          v1   = source->GetBinContent(i, j);
          ev1  = source->GetBinError(  i, j);
          index = (dEta-1)*nPhiBins + dPhi-1;
          numerator[index]    += v1;
          numeratorErr[index] += ev1*ev1;
          denominator[index]  += 1.;
          //cout << " " << name << "  iEta:" << iEta << " iPhi:" << iPhi << " jEta:" << jEta << " jPhi:" << jPhi << " v1:" << v1 << " ev1:" << ev1 << endl;
          ++j;
          }
        }
      ++i;
      }
    }
  for (dEta=0;dEta<2*nEtaBins-1;++dEta)
    {
    for (dPhi=0;dPhi<nPhiBins;++dPhi)
      {
      //v1   = target->GetBinContent(dEta+1,dPhi+1);
      //ev1  = target->GetBinError(dEta+1,dPhi+1);
      index = dEta*nPhiBins + dPhi;
      v1    = numerator[index];
      ev1   = numeratorErr[index];
      v2    = denominator[index];
      target->SetBinContent(dEta+1,dPhi+1,v1/v2);
      target->SetBinError(  dEta+1,dPhi+1,sqrt(ev1)/v2);
      }
    }
  delete [] numerator;
  delete [] numeratorErr;
  delete [] denominator;
}

//!
//! Calculate the external product of n_1(eta,phi) by n_2(eta,phi) and project onto n1n1_12(Deta,Dphi)
//! First create a 4D external product of h_1 and h_2 using a 1D vector
//! than project it onto DeltaEta(x-axis) DeltaPhi (y-axis)
//! Errors are neglected and must be accounted for using a sub-sample analysis.
//!
void reduce_n1EtaPhiN1EtaPhiOntoN1N1DetaDphi(const TH2 * h_1, TH2 * h_2, TH2 * h_12, int nDeta,int nDphi)
{
  { /* no ops */};
  if (!ptrExist(__FUNCTION__,h_1,h_2,h_12)) throw NullPointerException(__FUNCTION__);
  if (!sameDimensions(__FUNCTION__,h_1,h_2)) throw IncompatibleHistogramException(__FUNCTION__);
  vector<double> numerator(nDeta*nDphi,0.0);
  vector<double> denominator(nDeta*nDphi,0.0);
  int nEta = h_1->GetNbinsX();
  int nPhi = h_1->GetNbinsY();
  nDeta = h_12->GetNbinsX();
  nDphi = h_12->GetNbinsY();

  int index;
  int iDeta, iDphi;
  double v1, v2, v, r;
  for (int iPhi1=1; iPhi1<=nPhi; iPhi1++)
    {
    for (int iEta1=1; iEta1<=nEta; iEta1++)
      {
      v1 = h_1->GetBinContent(iEta1,iPhi1);
      for (int iPhi2=1; iPhi2<=nPhi; iPhi2++)
        {
        for (int iEta2=1; iEta2<=nEta; iEta2++)
          {
          v2 = h_2->GetBinContent(iEta2,iPhi2);
          v  = v1 * v2;
          iDphi = iPhi1-iPhi2; if (iDphi<0) iDphi += nDphi; //dPhi+=1;
          iDeta = iEta1-iEta2 + nEta - 1;
          // if (iDphi<0 || )
          index = iDphi*nDeta + iDeta;
          if (index<0)
            {
            throw HistogramException("LOGIC","index<0","reduce_n1EtaPhiN1EtaPhiOntoN1N1DetaDphi()");
            }
          if (index>=nDeta*nDphi)
            {
            throw HistogramException("LOGIC","index>=nDeta*nDphi","reduce_n1EtaPhiN1EtaPhiOntoN1N1DetaDphi()");
            }
          numerator[index]    += v;
          denominator[index]  += 1.0;
          }
        }
      }
    }
  double zero = 0.0;
  for (iDphi=0; iDphi<nDphi; iDphi++)
    {
    for (iDeta=0; iDeta<nDeta; iDeta++)
      {
      index = iDphi*nDeta + iDeta;
      double num = numerator[index];
      double den = denominator[index];
      if (den>0) r = num;
      else  r = zero;
      h_12->SetBinContent(iDeta+1,iDphi+1,r);
      h_12->SetBinError(iDeta+1,iDphi+1,zero);
      }
    }
}


void reduce_n2xEtaPhi_n2EtaEta(const TH1 * source, TH2 * target,int nEtaBins,int nPhiBins)
{
  if (!ptrExist(__FUNCTION__,source,target)) throw NullPointerException(__FUNCTION__);
  double v1,v2,ev1,ev2,v,ev;
  int iPhi,iEta,jPhi,jEta, i, j;
  int nBins = nEtaBins*nPhiBins;
  int nEtaEta = nEtaBins*nEtaBins;
  double * work = new double[nEtaEta];
  for (int k=0;k<nEtaEta;++k) work[k]=0;
  i=0;
  for (iEta=0;iEta<nEtaBins; ++iEta)
    {
    for (iPhi=0;iPhi<nPhiBins; ++iPhi)
      {
      j=0;
      for (jEta=0;jEta<nEtaBins; ++jEta)
        {
        for (jPhi=0;jPhi<nPhiBins; ++jPhi)
          {
          v1   = source->GetBinContent(i*nBins+j+1);
          ev1  = source->GetBinError(i*nBins+j+1);
          if (v1> -0.9999999)
            {
            v2   = target->GetBinContent(iEta+1,jEta+1);
            ev2  = target->GetBinError(iEta+1,jEta+1);
            v = v1+v2;
            ev = sqrt(ev1*ev1+ev2*ev2);
            target->SetBinContent(iEta+1,jEta+1,v);
            target->SetBinError(iEta+1,jEta+1,ev);
            work[ iEta*nEtaBins+jEta] += 1;
            }
          ++j;
          }
        }
      ++i;
      }
    }
  for (iEta=0;iEta<nEtaBins; ++iEta)
    {
    for (jEta=0;jEta<nEtaBins; ++jEta)
      {
      v1   = target->GetBinContent(iEta+1,jEta+1);
      ev1  = target->GetBinError(iEta+1,jEta+1);
      v2   = work[ iEta*nEtaBins+jEta ];
      if (v2<=0)throw HistogramException("LOGIC","v2<=0","reduce_n1EtaPhiN1EtaPhiOntoN1N1DetaDphi() index>nDeta*nDphi");
      target->SetBinContent(iEta+1,jEta+1,v1/v2);
      target->SetBinError(iEta+1,jEta+1,ev1/v2);
      }
    }
  delete [] work;
}

void project_n2XYXY_n2XX(const TH2 * source, TH2 * target,int nXBins,int nYBins)
{
  if (!ptrExist(__FUNCTION__,source,target)) throw NullPointerException(__FUNCTION__);

  double v1,v2,ev1,ev2,v,ev;

  /* sanity checks */
  if ((source->GetNbinsX() != nXBins*nYBins)
      or (source->GetNbinsY() != nXBins*nYBins)
      or (target->GetNbinsX() != nXBins)
      or (target->GetNbinsY() != nXBins)) throw IncompatibleHistogramException(__FUNCTION__);
  target->Reset();
  int i=0;
  for (int iX=0;iX<nXBins; ++iX)
    {
    for (int iY=0;iY<nYBins; ++iY)
      {
      int j=0;
      for (int jX=0;jX<nXBins; ++jX)
        {
        for (int jY=0;jY<nYBins; ++jY)
          {
          v1   = source->GetBinContent(i+1,j+1);
          ev1  = source->GetBinError(i+1,j+1);
          v2   = target->GetBinContent(iX+1,jX+1);
          ev2  = target->GetBinError(iX+1,jX+1);
          v = v1+v2;
          ev = sqrt(ev1*ev1+ev2*ev2);
          target->SetBinContent(iX+1,jX+1,v);
          target->SetBinError(iX+1,jX+1,ev);
          ++j;
          }
        }
      ++i;
      }
    }
  target->SetEntries(source->GetEntries());
}

void project_n2XYXY_n2YY(const TH2 * source, TH2 * target,int nXBins,int nYBins)
{
  if (!ptrExist(__FUNCTION__,source,target)) throw NullPointerException(__FUNCTION__);
  double v1,v2,ev1,ev2,v,ev;

  /* sanity checks */
  if ((source->GetNbinsX() != nXBins*nYBins) ||
      (source->GetNbinsY() != nXBins*nYBins) ||
      (target->GetNbinsX() != nYBins) ||
      (target->GetNbinsY() != nYBins)) throw IncompatibleHistogramException(__FUNCTION__);
  target->Reset();
  int i=0;
  for (int iX=0;iX<nXBins; ++iX)
    {
    for (int iY=0;iY<nYBins; ++iY)
      {
      int j=0;
      for (int jX=0;jX<nXBins; ++jX)
        {
        for (int jY=0;jY<nYBins; ++jY)
          {
          v1   = source->GetBinContent(i+1,j+1);
          ev1  = source->GetBinError(i+1,j+1);
          v2   = target->GetBinContent(iY+1,jY+1);
          ev2  = target->GetBinError(iY+1,jY+1);
          v = v1+v2;
          ev = sqrt(ev1*ev1+ev2*ev2);
          target->SetBinContent(iY+1,jY+1,v);
          target->SetBinError(iY+1,jY+1,ev);
          ++j;
          }
        }
      ++i;
      }
    }
  target->SetEntries(source->GetEntries());
}


//! Shift the given source to the target vertically by nbins
void shiftY(const TH2 & source, TH2 & target, int nbins)
{
  int i_x, i_y;
  int n_x = source.GetNbinsX();
  int n_y = source.GetNbinsY();

  //shift the 1st area
  for (i_x=1;i_x<=n_x;++i_x)
    {
    for (i_y=1;i_y<=n_y-nbins;++i_y)
      {
      double v  = source.GetBinContent(i_x,i_y);
      double ev = source.GetBinError(i_x,i_y);
      target.SetBinContent(i_x,  i_y+nbins, v);
      target.SetBinError(i_x,    i_y+nbins, ev);
      }
    for (i_y=n_y-nbins+1;i_y<=n_y;++i_y)
      {
      double v  = source.GetBinContent(i_x,i_y);
      double ev = source.GetBinError(i_x,i_y);
      target.SetBinContent(i_x, i_y-(n_y-nbins),v);
      target.SetBinError(i_x,   i_y-(n_y-nbins),ev);
      }
    }
}


float * getFloatArray(int size, float v)
{
  /// Allocate an array of type float with n values
  /// Initialize the array to the given value
  float * array = new float [size];
  for (int i=0;i<size;++i) array[i]=v;
  return array;
}



double * getDoubleArray(int size, double v)
{
  /// Allocate an array of type double with n values
  /// Initialize the array to the given value
  double * array = new double [size];
  for (int i=0;i<size;++i) array[i]=v;
  return array;
}

void resetDoubleArray(int n, double * array, double value)
{
  /// Set all n values of the given array to the given value
  double * ptr;
  double * ptrEnd = array+n;
  for (ptr=array; ptr<ptrEnd; ++ptr)
    {
    *ptr = value;
    }
}

void calculateF1(TH1* h_f1_1, TH1* h_F1_1)
{
  if (!ptrExist(__FUNCTION__,h_f1_1, h_F1_1)) throw NullPointerException(__FUNCTION__);
  double f1_1, ef1_1;
  int nBins = h_f1_1->GetNbinsX();
  for (int iBin = 1; iBin <=nBins; iBin++)
    {
    f1_1  = h_f1_1->GetBinContent(iBin);
    ef1_1 = h_f1_1->GetBinError(iBin);
    h_F1_1->SetBinContent(iBin, f1_1);
    h_F1_1->SetBinError(iBin,   ef1_1);
    }
}


void calculateF2R2(TH1* h_f1_1, TH1* h_f1_2, TH1* h_f2_12, TH1* h_F2_12, TH1* h_R2_12)
{
  if (!ptrExist(__FUNCTION__,h_f1_1, h_f1_2, h_f2_12, h_F2_12, h_R2_12)) throw NullPointerException(__FUNCTION__);
  double f1_1, ef1_1, f1_2, ef1_2;
  double f2_12, ef2_12;
  double F2_12, eF2_12, R2_12, eR2_12;
  int nBins = h_f1_1->GetNbinsX();
  for (int iBin = 1; iBin <=nBins; iBin++)
    {
    f1_1   = h_f1_1->GetBinContent(iBin);   ef1_1 =   h_f1_1->GetBinError(iBin);
    f1_2   = h_f1_2->GetBinContent(iBin);   ef1_2  =  h_f1_2->GetBinError(iBin);
    f2_12  = h_f2_12->GetBinContent(iBin);  ef2_12 =  h_f2_12->GetBinError(iBin);
    calculateF2R2(f1_1,ef1_1,f1_2,ef1_2,f2_12,ef2_12, F2_12,eF2_12,R2_12,eR2_12);
    h_F2_12->SetBinContent(iBin, F2_12);
    h_F2_12->SetBinError(iBin,   0.0);
    h_R2_12->SetBinContent(iBin, R2_12);
    h_R2_12->SetBinError(iBin,   0.0);
    }
}

void calculateNudyn(TH1* h_R2_11,
                    TH1* h_R2_12,
                    TH1* h_R2_21,
                    TH1* h_R2_22,
                    TH1* h_nudyn_12)
{
  if (!ptrExist(__FUNCTION__,h_R2_11, h_R2_12, h_R2_21, h_R2_22, h_nudyn_12)) throw NullPointerException(__FUNCTION__);
  double R2_11, eR2_11, R2_12, eR2_12, R2_21, eR2_21, R2_22, eR2_22, nudyn, enudyn;
  int nBins = h_R2_11->GetNbinsX();
  for (int iBin = 1; iBin <=nBins; iBin++)
    {
    R2_11   = h_R2_11->GetBinContent(iBin);  eR2_11  =  h_R2_11->GetBinError(iBin);
    R2_12   = h_R2_12->GetBinContent(iBin);  eR2_12  =  h_R2_12->GetBinError(iBin);
    R2_21   = h_R2_21->GetBinContent(iBin);  eR2_21  =  h_R2_21->GetBinError(iBin);
    R2_22   = h_R2_22->GetBinContent(iBin);  eR2_22  =  h_R2_22->GetBinError(iBin);
    calculateNudyn(R2_11, eR2_11, R2_12, eR2_12, R2_21, eR2_21, R2_22, eR2_22, nudyn, enudyn);
    h_nudyn_12->SetBinContent(iBin, nudyn);
    h_nudyn_12->SetBinError(iBin,   0.0);
    }
}


void calculateF3R3(TH1* h_f1_1, TH1* h_f1_2, TH1* h_f1_3,
                   TH1* h_f2_12, TH1* h_f2_13, TH1* h_f2_23,
                   TH1* h_f3_123,
                   TH1* h_F3_123, TH1* h_R3_123)
{

  if (!ptrExist(__FUNCTION__,h_f1_1, h_f1_2, h_f1_3, h_f2_12, h_f2_13, h_f2_23, h_f3_123, h_F3_123, h_R3_123))  throw NullPointerException(__FUNCTION__);

  double f1_1, ef1_1, f1_2, ef1_2, f1_3, ef1_3;
  double f2_12, ef2_12, f2_13, ef2_13, f2_23, ef2_23;
  double f3_123, ef3_123;
  double F3_123, eF3_123, R3_123, eR3_123;
  int nBins = h_f1_1->GetNbinsX();
  for (int iBin = 1; iBin <=nBins; iBin++)
    {
    f1_1   = h_f1_1->GetBinContent(iBin);    ef1_1 =   h_f1_1->GetBinError(iBin);
    f1_2   = h_f1_2->GetBinContent(iBin);    ef1_2  =  h_f1_2->GetBinError(iBin);
    f1_3   = h_f1_3->GetBinContent(iBin);    ef1_3  =  h_f1_2->GetBinError(iBin);
    f2_12  = h_f2_12->GetBinContent(iBin);   ef2_12 =  h_f2_12->GetBinError(iBin);
    f2_13  = h_f2_13->GetBinContent(iBin);   ef2_13 =  h_f2_13->GetBinError(iBin);
    f2_23  = h_f2_23->GetBinContent(iBin);   ef2_23 =  h_f2_23->GetBinError(iBin);
    f3_123 = h_f3_123->GetBinContent(iBin);  ef3_123 =  h_f3_123->GetBinError(iBin);
    calculateF3R3(f1_1,ef1_1,f1_2,ef1_2,f1_3,ef1_3,
                  f2_12,ef2_12,f2_13,ef2_13,f2_23,ef2_23,
                  f3_123,ef3_123,
                  F3_123,eF3_123,R3_123,eR3_123);
    h_F3_123->SetBinContent(iBin, F3_123);
    h_F3_123->SetBinError(iBin,   0.0);
    h_R3_123->SetBinContent(iBin, R3_123);
    h_R3_123->SetBinError(iBin,   0.0);
    }
}

void calculateF4R4(TH1* h_f1_1, TH1* h_f1_2, TH1* h_f1_3, TH1* h_f1_4,
                   TH1* h_f2_12, TH1* h_f2_13, TH1* h_f2_14,
                   TH1* h_f2_23, TH1* h_f2_24, TH1* h_f2_34,
                   TH1* h_f3_123, TH1* h_f3_124, TH1* h_f3_134, TH1* h_f3_234,
                   TH1* h_f4_1234,
                   TH1* h_F4_1234, TH1* h_R4_1234)
{

  if (!ptrExist(__FUNCTION__,h_f1_1, h_f1_2, h_f1_3, h_f1_4, h_f2_12,  h_f2_13,  h_f2_14)) throw NullPointerException(__FUNCTION__);
  if (!ptrExist(__FUNCTION__,h_f2_23,h_f2_24,h_f2_34,h_f3_123,h_f3_124,h_f3_134,h_f3_234)) throw NullPointerException(__FUNCTION__);
  if (!ptrExist(__FUNCTION__,h_f4_1234,h_F4_1234,h_R4_1234)) throw NullPointerException(__FUNCTION__);
  double f1_1, ef1_1, f1_2, ef1_2, f1_3, ef1_3, f1_4, ef1_4;
  double f2_12, ef2_12, f2_13, ef2_13, f2_14, ef2_14, f2_23, ef2_23, f2_24, ef2_24, f2_34, ef2_34;
  double f3_123, ef3_123, f3_124, ef3_124, f3_134, ef3_134, f3_234, ef3_234;
  double f4_1234, ef4_1234;
  double F4_1234, eF4_1234, R4_1234, eR4_1234;
  int nBins = h_f1_1->GetNbinsX();
  for (int iBin = 1; iBin <=nBins; iBin++)
    {
    f1_1    = h_f1_1->GetBinContent(iBin);   ef1_1   =  h_f1_1->GetBinError(iBin);
    f1_2    = h_f1_2->GetBinContent(iBin);   ef1_2   =  h_f1_2->GetBinError(iBin);
    f1_3    = h_f1_3->GetBinContent(iBin);   ef1_3   =  h_f1_3->GetBinError(iBin);
    f1_4    = h_f1_4->GetBinContent(iBin);   ef1_4   =  h_f1_4->GetBinError(iBin);
    f2_12   = h_f2_12->GetBinContent(iBin);  ef2_12  =  h_f2_12->GetBinError(iBin);
    f2_13   = h_f2_13->GetBinContent(iBin);  ef2_13  =  h_f2_13->GetBinError(iBin);
    f2_14   = h_f2_14->GetBinContent(iBin);  ef2_14  =  h_f2_14->GetBinError(iBin);
    f2_23   = h_f2_23->GetBinContent(iBin);  ef2_23  =  h_f2_23->GetBinError(iBin);
    f2_24   = h_f2_24->GetBinContent(iBin);  ef2_24  =  h_f2_24->GetBinError(iBin);
    f2_34   = h_f2_34->GetBinContent(iBin);  ef2_34  =  h_f2_34->GetBinError(iBin);
    f3_123  = h_f3_123->GetBinContent(iBin); ef3_123 =  h_f3_123->GetBinError(iBin);
    f3_124  = h_f3_124->GetBinContent(iBin); ef3_124 =  h_f3_124->GetBinError(iBin);
    f3_134  = h_f3_134->GetBinContent(iBin); ef3_134 =  h_f3_134->GetBinError(iBin);
    f3_234  = h_f3_234->GetBinContent(iBin); ef3_234 =  h_f3_234->GetBinError(iBin);
    f4_1234 = h_f4_1234->GetBinContent(iBin);ef4_1234 =  h_f4_1234->GetBinError(iBin);
    calculateF4R4(f1_1,ef1_1,f1_2,ef1_2,f1_3,ef1_3,f1_4,ef1_4,
                  f2_12,ef2_12, f2_13,ef2_13, f2_14,ef2_14,
                  f2_23,ef2_23, f2_24,ef2_24, f2_34,ef2_34,
                  f3_123,ef3_123, f3_124,ef3_124, f3_134,ef3_134, f3_234,ef3_234,
                  f4_1234,ef4_1234,
                  F4_1234,eF4_1234,R4_1234,eR4_1234);
    h_F4_1234->SetBinContent(iBin, F4_1234);
    h_F4_1234->SetBinError(iBin,   0.0);
    h_R4_1234->SetBinContent(iBin, R4_1234);
    h_R4_1234->SetBinError(iBin,   0.0);
    }
}


void calculateF2R2(double f1_1,double ef1_1,
                   double f1_2,double ef1_2,
                   double f2_12,double ef2_12,
                   double & F2_12,double & eF2_12, 
                   double &  R2_12,double & eR2_12)
{

  double ref1_1, ref1_2, ref2_12;
  if (f1_1<1E-20 || f1_2<1E-20)
    {
    F2_12  = 0.0;
    eF2_12 = 0.0;
    R2_12  = 0.0;
    eR2_12 = 0.0;
    }
  else
    {
    F2_12     = f2_12 - f1_1*f1_2;
    ref1_1    = ef1_1/f1_1;
    ref1_2    = ef1_2/f1_2;
    ref2_12   = ef2_12/f2_12;
    eF2_12    = sqrt(f1_1*f1_2*f1_1*f1_2*(ref1_1*ref1_1 + ref1_2*ref1_2) + eF2_12*eF2_12);
    R2_12     = F2_12/(f1_1*f1_2);
    eR2_12    = R2_12*sqrt(ref1_1*ref1_1 + ref1_2*ref1_2 + ref2_12*ref2_12);
    }
}


void calculateF3R3(double f1_1,double ef1_1,double f1_2,double ef1_2, double f1_3,double ef1_3,
                   double f2_12,double ef2_12,double f2_13,double ef2_13,double f2_23,double ef2_23,
                   double f3_123, double ef3_123,
                   double & F3_123,double & eF3_123, double &  R3_123,double & eR3_123)
{

  double ref1_1, ref1_2, ref1_3, ref2_12, ref2_13, ref2_23, reF3_123;
  if (f1_1<1E-20 || f1_2<1E-20 || f1_3<1E-20)
    {
    F3_123   = 0.0;
    eF3_123  = 0.0;
    R3_123   = 0.0;
    eR3_123  = 0.0;
    }
  else
    {
    F3_123    = f3_123 - f2_12*f1_3 - f2_13*f1_2 - f2_23*f1_1 + 2.0*f1_1*f1_2*f1_3;
    ref1_1    = ef1_1/f1_1;
    ref1_2    = ef1_2/f1_2;
    ref1_3    = ef1_3/f1_3;
    ref2_12   = ef2_12/f2_12;
    ref2_13   = ef2_13/f2_13;
    ref2_23   = ef2_23/f2_23;
    eF3_123   = ef3_123*ef3_123;
    eF3_123   += f2_12*f2_12*f1_3*f1_3*(ref2_12*ref2_12 + ref1_3*ref1_3);
    eF3_123   += f2_13*f2_13*f1_2*f1_2*(ref2_13*ref2_13 + ref1_2*ref1_2);
    eF3_123   += f2_23*f2_23*f1_1*f1_1*(ref2_23*ref2_23 + ref1_1*ref1_1);
    eF3_123   += 4.0*f1_1*f1_1*f1_2*f1_2*f1_3*f1_3*sqrt(ref1_1*ref1_1+ref1_2*ref1_2+ref1_3*ref1_3);
    eF3_123   = sqrt(eF3_123);
    reF3_123   = eF3_123/F3_123;
    R3_123     = F3_123/(f1_1*f1_2*f1_3);
    eR3_123    = R3_123*reF3_123;
    }
}

void calculateF4R4(double f1_1,double ef1_1,double f1_2,double ef1_2, double f1_3,double ef1_3, double f1_4,double ef1_4,
                   double f2_12,double ef2_12,double f2_13,double ef2_13,double f2_14,double ef2_14,double f2_23,double ef2_23,
                   double f2_24,double ef2_24,double f2_34,double ef2_34,
                   double f3_123, double ef3_123,double f3_124, double ef3_124, double f3_134, double ef3_134,double f3_234, double ef3_234,
                   double f4_1234, double ef4_1234,
                   double &F4_1234,double &eF4_1234, double &  R4_1234,double & eR4_1234)
{
  double ref1_1,  ref1_2,  ref1_3; //,  ref1_4;
  double ref2_12, ref2_13, ref2_14;
  double ref3_123, ref3_124, ref3_134, ref3_234;
  if (f1_1<1E-20 || f1_2<1E-20 || f1_3<1E-20 || f1_4<1E-20)
    {
    F4_1234   = 0.0;
    eF4_1234  = 0.0;
    R4_1234   = 0.0;
    eR4_1234  = 0.0;
    }
  else
    {

    F4_1234   = f4_1234 - f3_123*f1_4 - f3_124*f1_3 - f3_134*f1_2 - f3_234*f1_1
    - f2_12*f2_34 - f2_13*f2_24 - f2_14*f2_23
    + 4.0*(f2_12*f1_3*f1_4 + f2_13*f1_2*f1_4 + f2_14*f1_2*f1_3)
    - 6.0*f1_1*f1_2*f1_3*f1_4;
    ref1_1    = ef1_1/f1_1;
    ref1_2    = ef1_2/f1_2;
    ref1_3    = ef1_3/f1_3;
    //ref1_4    = ef1_4/f1_4;
    ref2_12   = ef2_12/f2_12;
    ref2_13   = ef2_13/f2_13;
    ref2_14   = ef2_14/f2_14;
    //ref2_23   = ef2_23/f2_23;
    //ref2_24   = ef2_24/f2_24;
    //ref2_34   = ef2_34/f2_34;
    ref3_123  = ef3_123/f3_123;
    ref3_124  = ef3_124/f3_124;
    ref3_134  = ef3_134/f3_134;
    ref3_234  = ef3_234/f3_234;
    //ref4_1234 = ef4_1234/f4_1234;

    eF4_1234   = ef4_1234*ef4_1234
    + f3_123*f3_123*f1_4*f1_4*(ref3_123*ref3_123 + ef1_4*ef1_4)
    + f3_124*f3_124*f1_3*f1_3*(ref3_124*ref3_124 + ref1_3*ref1_3)
    + f3_134*f3_134*f1_2*f1_2*(ref3_134*ref3_134 + ref1_2*ref1_2)
    + f3_234*f3_234*f1_1*f1_1*(ref3_234*ref3_234 + ref1_1*ref1_1)
    + 16.0*f2_12*f2_12*f2_34*f2_34*(ref2_12*ref2_12 + ef2_34*ef2_34)
    + 16.0*f2_13*f2_13*f2_24*f2_24*(ref2_13*ref2_13 + ef2_24*ef2_24)
    + 16.0*f2_14*f2_14*f2_23*f2_23*(ref2_14*ref2_14 + ef2_23*ef2_23);
    // neglect singles term for now..
    eF4_1234   = sqrt(eF4_1234);
    //reF4_1234  = 0.0; //eF4_1234/F4_1234;
    R4_1234    = F4_1234/(f1_1*f1_2*f1_3*f1_4);
    eR4_1234   = 0.0; //R4_1234*reF4_1234;
    }
}


void calculateNudyn(double r2_11,double er2_11,
                    double r2_12,double er2_12,
                    double r2_21,double er2_21,
                    double r2_22,double er2_22,
                    double & nudyn,double & enudyn)
{
  nudyn = r2_11 + r2_22 - r2_12 - r2_21;
  enudyn = sqrt(er2_11*er2_11 + er2_22*er2_22 + er2_12*er2_12 + er2_21*er2_21);
}

// sanity check functions

bool ptrExist(const String &  caller, const TH1 * h1)
{
  if (!h1) throw NullPointerException(caller);
  return true;
}

bool ptrFileExist(const String &  caller, const TFile * f)
{
  if (!f) throw NullPointerException(caller);
  return true;
}

bool ptrExist(const String &  caller, const TH1 * h1, const TH1 * h2)
{
  if (!h1) throw NullPointerException("Function first argument is a null ptr",caller);
  if (!h2) throw NullPointerException("Function second argument is a null ptr",caller);
  return true;
}

bool ptrExist(const String &  caller, const TH1 * h1, const TH1 * h2, const TH1 * h3)
{
  if (!h1) throw NullPointerException("Function first argument is a null ptr",caller);
  if (!h2) throw NullPointerException("Function second argument is a null ptr",caller);
  if (!h3) throw NullPointerException("Function third argument is a null ptr",caller);
  return true;
}


bool ptrExist(const String &  caller, const TH1 * h1, const TH1 * h2, const TH1 * h3, const TH1 * h4)
{
  if (!h1) throw NullPointerException("Function first argument is a null ptr",caller);
  if (!h2) throw NullPointerException("Function second argument is a null ptr",caller);
  if (!h3) throw NullPointerException("Function third argument is a null ptr",caller);
  if (!h4) throw NullPointerException("Function fourth argument is a null ptr",caller);
  return true;
}

bool ptrExist(const String &  caller, const TH1 * h1, const TH1 * h2, const TH1 * h3, const TH1 * h4, const TH1 * h5)
{
  if (!h1) throw NullPointerException("Function first argument is a null ptr",caller);
  if (!h2) throw NullPointerException("Function second argument is a null ptr",caller);
  if (!h3) throw NullPointerException("Function third argument is a null ptr",caller);
  if (!h4) throw NullPointerException("Function fourth argument is a null ptr",caller);
  if (!h5) throw NullPointerException("Function fifth argument is a null ptr",caller);
  return true;
}


bool ptrExist(const String &  caller, const TH1 * h1, const TH1 * h2, const TH1 * h3, const TH1 * h4, const TH1 * h5, const TH1 * h6)
{
  if (!h1) throw NullPointerException("Function first argument is a null ptr",caller);
  if (!h2) throw NullPointerException("Function second argument is a null ptr",caller);
  if (!h3) throw NullPointerException("Function third argument is a null ptr",caller);
  if (!h4) throw NullPointerException("Function fourth argument is a null ptr",caller);
  if (!h5) throw NullPointerException("Function fifth argument is a null ptr",caller);
  if (!h6) throw NullPointerException("Function sixth argument is a null ptr",caller);
  return true;
}

bool ptrExist(const String &  caller, const TH1 * h1, const TH1 * h2, const TH1 * h3, const TH1 * h4, const TH1 * h5, const TH1 * h6, const TH1 * h7)
{
  if (!h1) throw NullPointerException("Function first argument is a null ptr",caller);
  if (!h2) throw NullPointerException("Function second argument is a null ptr",caller);
  if (!h3) throw NullPointerException("Function third argument is a null ptr",caller);
  if (!h4) throw NullPointerException("Function fourth argument is a null ptr",caller);
  if (!h5) throw NullPointerException("Function fifth argument is a null ptr",caller);
  if (!h6) throw NullPointerException("Function sixth argument is a null ptr",caller);
  if (!h7) throw NullPointerException("Function seventh argument is a null ptr",caller);
  return true;
}

bool ptrExist(const String &  caller, const TH1 * h1, const TH1 * h2, const TH1 * h3,
              const TH1 * h4, const TH1 * h5, const TH1 * h6, const TH1 * h7, const TH1 * h8)
{
  if (!h1) throw NullPointerException("Function first argument is a null ptr",caller);
  if (!h2) throw NullPointerException("Function second argument is a null ptr",caller);
  if (!h3) throw NullPointerException("Function third argument is a null ptr",caller);
  if (!h4) throw NullPointerException("Function fourth argument is a null ptr",caller);
  if (!h5) throw NullPointerException("Function fifth argument is a null ptr",caller);
  if (!h6) throw NullPointerException("Function sixth argument is a null ptr",caller);
  if (!h7) throw NullPointerException("Function seventh argument is a null ptr",caller);
  if (!h8) throw NullPointerException("Function eight argument is a null ptr",caller);
  return true;
}

bool ptrExist(const String &  caller, const TH1 * h1, const TH1 * h2, const TH1 * h3,
              const TH1 * h4, const TH1 * h5, const TH1 * h6, const TH1 * h7,
              const TH1 * h8, const TH1 * h9)
{
  if (!h1) throw NullPointerException("Function first argument is a null ptr",caller);
  if (!h2) throw NullPointerException("Function second argument is a null ptr",caller);
  if (!h3) throw NullPointerException("Function third argument is a null ptr",caller);
  if (!h4) throw NullPointerException("Function fourth argument is a null ptr",caller);
  if (!h5) throw NullPointerException("Function fifth argument is a null ptr",caller);
  if (!h6) throw NullPointerException("Function sixth argument is a null ptr",caller);
  if (!h7) throw NullPointerException("Function seventh argument is a null ptr",caller);
  if (!h8) throw NullPointerException("Function eight argument is a null ptr",caller);
  if (!h9) throw NullPointerException("Function nineth argument is a null ptr",caller);
  return true;
}

bool ptrExist(const String &  caller, const TH1 * h1, const TH1 * h2, const TH1 * h3,
              const TH1 * h4, const TH1 * h5, const TH1 * h6, const TH1 * h7,
              const TH1 * h8, const TH1 * h9, const TH1 * h10)
{
  if (!h1) throw NullPointerException("Function first argument is a null ptr",caller);
  if (!h2) throw NullPointerException("Function second argument is a null ptr",caller);
  if (!h3) throw NullPointerException("Function third argument is a null ptr",caller);
  if (!h4) throw NullPointerException("Function fourth argument is a null ptr",caller);
  if (!h5) throw NullPointerException("Function fifth argument is a null ptr",caller);
  if (!h6) throw NullPointerException("Function sixth argument is a null ptr",caller);
  if (!h7) throw NullPointerException("Function seventh argument is a null ptr",caller);
  if (!h8) throw NullPointerException("Function eight argument is a null ptr",caller);
  if (!h9) throw NullPointerException("Function nineth argument is a null ptr",caller);
  if (!h10) throw NullPointerException("Function tenth argument is a null ptr",caller);
  return true;
}

bool ptrExist(const String &  caller, const TH1 * h1, const TH1 * h2, const TH1 * h3,
              const TH1 * h4, const TH1 * h5, const TH1 * h6, const TH1 * h7,
              const TH1 * h8, const TH1 * h9, const TH1 * h10, const TH1 * h11)
{
  if (!h1) throw NullPointerException("Function first argument is a null ptr",caller);
  if (!h2) throw NullPointerException("Function second argument is a null ptr",caller);
  if (!h3) throw NullPointerException("Function third argument is a null ptr",caller);
  if (!h4) throw NullPointerException("Function fourth argument is a null ptr",caller);
  if (!h5) throw NullPointerException("Function fifth argument is a null ptr",caller);
  if (!h6) throw NullPointerException("Function sixth argument is a null ptr",caller);
  if (!h7) throw NullPointerException("Function seventh argument is a null ptr",caller);
  if (!h8) throw NullPointerException("Function eight argument is a null ptr",caller);
  if (!h9) throw NullPointerException("Function nineth argument is a null ptr",caller);
  if (!h10) throw NullPointerException("Function tenth argument is a null ptr",caller);
  if (!h11) throw NullPointerException("Function eleventh argument is a null ptr",caller);
  return true;
}

bool ptrExist(const String &  caller, const TH1 * h1, const TH1 * h2, const TH1 * h3,
              const TH1 * h4, const TH1 * h5, const TH1 * h6, const TH1 * h7,
              const TH1 * h8, const TH1 * h9, const TH1 * h10, const TH1 * h11, const TH1 * h12)
{
  if (!h1) throw NullPointerException("Function first argument is a null ptr",caller);
  if (!h2) throw NullPointerException("Function second argument is a null ptr",caller);
  if (!h3) throw NullPointerException("Function third argument is a null ptr",caller);
  if (!h4) throw NullPointerException("Function fourth argument is a null ptr",caller);
  if (!h5) throw NullPointerException("Function fifth argument is a null ptr",caller);
  if (!h6) throw NullPointerException("Function sixth argument is a null ptr",caller);
  if (!h7) throw NullPointerException("Function seventh argument is a null ptr",caller);
  if (!h8) throw NullPointerException("Function eight argument is a null ptr",caller);
  if (!h9) throw NullPointerException("Function nineth argument is a null ptr",caller);
  if (!h10) throw NullPointerException("Function tenth argument is a null ptr",caller);
  if (!h11) throw NullPointerException("Function eleventh argument is a null ptr",caller);
  if (!h12) throw NullPointerException("Function twelveth argument is a null ptr",caller);
  return true;
}



TH1 * loadH1(TFile & inputFile,const String & histoName)
{
  TH1* h = (TH1*) inputFile.Get(histoName);
  if (!h) throw HistogramException(histoName,"Histogram not found/loaded","importH1");
  return h;
}

TH2 * loadH2(TFile & inputFile,const String & histoName)
{
  TH2* h = (TH2*) inputFile.Get(histoName);
  if (!h) throw HistogramException(histoName,"Histogram not found/loaded","importH2");
  return h;
}

TH3 * loadH3(TFile & inputFile, const String & histoName)
{
  TH3* h = (TH3*) inputFile.Get(histoName);
  if (!h) throw HistogramException(histoName,"Histogram not found/loaded","importH3");
  return h;
}

TProfile * loadProfile(TFile & inputFile, const String & histoName)
{
  TProfile* h = (TProfile*) inputFile.Get(histoName);
  if (!h) throw HistogramException(histoName,"Histogram not found/loaded","importProfile");
  return h;
}

TProfile2D * loadProfile2D(TFile & inputFile, const String & histoName)
{
  TProfile2D* h = (TProfile2D*) inputFile.Get(histoName);
  if (!h) throw HistogramException(histoName,"Histogram not found/loaded","importProfile2D");
  return h;
}

void printHistoInfo(const String & source,
                    const String & histoName,
                    int nBins_x, double min_x, double max_x,
                    int nBins_y, double min_y, double max_y,
                    int nBins_z, double min_z, double max_z)
{
  printValue("Caller",source);
  printValue("Histogram Name",histoName);
  printValue("nBins_x",nBins_x);
  printValue("min_x",min_x);
  printValue("max_x",max_x);
  if (nBins_y<1) return;
  printValue("nBins_y",nBins_y);
  printValue("min_y",min_y);
  printValue("max_y",max_y);
  if (nBins_z<1) return;
  printValue("nBins_z",nBins_z);
  printValue("min_z",min_z);
  printValue("max_z",max_z);
}

void setTitles(TH1 * histogram,
               const String & title_x,
               const String & title_y)
{
  if (title_x.Sizeof()>0)  histogram->GetXaxis()->SetTitle(title_x);
  if (title_y.Sizeof()>0)  histogram->GetYaxis()->SetTitle(title_y);
}

void setTitles(TH2 * histogram,
               const String & title_x,
               const String & title_y,
               const String & title_z)
{
  if (title_x.Sizeof()>0)  histogram->GetXaxis()->SetTitle(title_x);
  if (title_y.Sizeof()>0)  histogram->GetYaxis()->SetTitle(title_y);
  if (title_z.Sizeof()>0)  histogram->GetZaxis()->SetTitle(title_z);
}

void setTitles(TH3 * histogram,
               const String & title_x,
               const String & title_y,
               const String & title_z,
               const String & title_w __attribute__((unused)) )
{
  if (title_x.Sizeof()>0)  histogram->GetXaxis()->SetTitle(title_x);
  if (title_y.Sizeof()>0)  histogram->GetYaxis()->SetTitle(title_y);
  if (title_z.Sizeof()>0)  histogram->GetZaxis()->SetTitle(title_z);
}

void differenceHistos(TH1 *h, TH1 *hRef, TH1 *hDiff, bool correlatedUncertainties)
{
  if (!ptrExist(__FUNCTION__,h,hRef,hDiff)) return;
  double v,  ev;
  double vRef,  evRef;
  double vDiff, evDiff, evDiffSq;

  if (h->IsA()==TH1::Class() || h->IsA()==TH1F::Class() || h->IsA()==TH1D::Class() || h->IsA()==TH1I::Class() )
    {
    int nx = h->GetNbinsX();
    for (int ix=1; ix<=nx; ix++)
      {
      v        = h->GetBinContent(ix);
      ev       = h->GetBinError(ix);
      vRef     = hRef->GetBinContent(ix);
      evRef    = hRef->GetBinError(ix);
      vDiff    = v - vRef;
      evDiffSq = correlatedUncertainties ?  Math::absolute(ev*ev - evRef*evRef) : ev*ev + evRef*evRef;
      evDiff   = sqrt(evDiffSq);
      hDiff->SetBinContent(ix, vDiff);
      hDiff->SetBinError(ix, evDiff);
      }
    }
  else if (h->IsA()==TH2::Class() || h->IsA()==TH2F::Class() || h->IsA()==TH2D::Class() || h->IsA()==TH2I::Class() )
    {
    int nx = h->GetNbinsX();
    int ny = h->GetNbinsY();
    for (int iy=1; iy<=ny; iy++)
      {
      for (int ix=1; ix<=nx; ix++)
        {
        v        = h->GetBinContent(ix,iy);
        ev       = h->GetBinError(ix,iy);
        vRef     = hRef->GetBinContent(ix,iy);
        evRef    = hRef->GetBinError(ix,iy);
        vDiff    = v - vRef;
        evDiffSq = correlatedUncertainties ?  Math::absolute(ev*ev - evRef*evRef) : ev*ev + evRef*evRef;
        evDiff   = sqrt(evDiffSq);
        hDiff->SetBinContent(ix,iy, vDiff);
        hDiff->SetBinError(ix,iy, evDiff);
        }
      }
    }
  else if (h->IsA()==TH3::Class() || h->IsA()==TH3F::Class() || h->IsA()==TH3D::Class() || h->IsA()==TH3I::Class() )
    {
    int nx = h->GetNbinsX();
    int ny = h->GetNbinsY();
    int nz = h->GetNbinsZ();
    for (int iz=1; iz<=nz; iz++)
      {
      for (int iy=1; iy<=ny; iy++)
        {
        for (int ix=1; ix<=nx; ix++)
          {
          v        = h->GetBinContent(ix,iy,iz);
          ev       = h->GetBinError(ix,iy,iz);
          vRef     = hRef->GetBinContent(ix,iy,iz);
          evRef    = hRef->GetBinError(ix,iy,iz);
          vDiff    = v - vRef;
          evDiffSq = correlatedUncertainties ?  Math::absolute(ev*ev - evRef*evRef) : ev*ev + evRef*evRef;
          evDiff   = sqrt(evDiffSq);
          hDiff->SetBinContent(ix,iy,iz, vDiff);
          hDiff->SetBinError(ix,iy,iz, evDiff);
          }
        }
      }
    }
  else if (h->IsA()==TProfile::Class() )
    {
    int nx = h->GetNbinsX();
    for (int ix=1; ix<=nx; ix++)
      {
      v        = h->GetBinContent(ix);
      ev       = h->GetBinError(ix);
      vRef     = hRef->GetBinContent(ix);
      evRef    = hRef->GetBinError(ix);
      vDiff    = v - vRef;
      evDiffSq = correlatedUncertainties ?  Math::absolute(ev*ev - evRef*evRef) : ev*ev + evRef*evRef;
      evDiff   = sqrt(evDiffSq);
      hDiff->SetBinContent(ix, vDiff);
      hDiff->SetBinError(ix, evDiff);
      ((TProfile*)hDiff)->SetBinEntries(ix, 1.0);
      }
    }
  else if (h->IsA()==TProfile2D::Class()  )
    {
    int nx = h->GetNbinsX();
    int ny = h->GetNbinsY();
    for (int iy=1; iy<=ny; iy++)
      {
      for (int ix=1; ix<=nx; ix++)
        {
        v        = h->GetBinContent(ix,iy);
        ev       = h->GetBinError(ix,iy);
        vRef     = hRef->GetBinContent(ix,iy);
        evRef    = hRef->GetBinError(ix,iy);
        vDiff    = v - vRef;
        evDiffSq = correlatedUncertainties ?  Math::absolute(ev*ev - evRef*evRef) : ev*ev + evRef*evRef;
        evDiff   = sqrt(evDiffSq);
        hDiff->SetBinContent(ix,iy, vDiff);
        hDiff->SetBinError(ix,iy, evDiff);
        //((TProfile*)hDiff)->SetBinEntries(ix,iy, 1.0);
        }
      }
    }
}


void ratioHistos(TH1 *h, TH1 *hRef, TH1 *hRatio, bool correlatedUncertainties)
{
  if (!ptrExist(__FUNCTION__,h,hRef,hRatio)) return;
  double v,  ev, rev;
  double vRef,  evRef, revRef;
  double vRatio, evRatio, revRatio, revRatioSq;

  if (h->IsA()==TH1::Class() || h->IsA()==TH1F::Class() || h->IsA()==TH1D::Class() || h->IsA()==TH1I::Class() )
    {
    int nx = h->GetNbinsX();
    for (int ix=1; ix<=nx; ix++)
      {
      v        = h->GetBinContent(ix);
      ev       = h->GetBinError(ix);
      rev      = (v!=0) ? ev/v : 0.0;
      vRef     = hRef->GetBinContent(ix);
      evRef    = hRef->GetBinError(ix);
      revRef   = (vRef!=0) ? evRef/vRef : 0.0;
      if (vRef)
        {
        vRatio     = v/vRef;
        revRatioSq = correlatedUncertainties ? Math::absolute(rev*rev - revRef*revRef) : rev*rev + revRef*revRef;
        revRatio   = sqrt(revRatioSq);
        evRatio    = revRatio*vRatio;
        hRatio->SetBinContent(ix, vRatio);
        hRatio->SetBinError(ix, evRatio);
        }
      }
    }
  else if (h->IsA()==TH2::Class() || h->IsA()==TH2F::Class() || h->IsA()==TH2D::Class() || h->IsA()==TH2I::Class() )
    {
    int nx = h->GetNbinsX();
    int ny = h->GetNbinsY();
    for (int iy=1; iy<=ny; iy++)
      {
      for (int ix=1; ix<=nx; ix++)
        {
        v        = h->GetBinContent(ix,iy);
        ev       = h->GetBinError(ix,iy);
        rev      = (v!=0) ? ev/v : 0.0;
        vRef     = hRef->GetBinContent(ix,iy);
        evRef    = hRef->GetBinError(ix,iy);
        revRef   = (vRef!=0) ? evRef/vRef : 0.0;
        if (vRef)
          {
          vRatio     = v/vRef;
          revRatioSq = correlatedUncertainties ? Math::absolute(rev*rev - revRef*revRef) : rev*rev + revRef*revRef;
          revRatio   = sqrt(revRatioSq);
          evRatio    = revRatio*vRatio;
          hRatio->SetBinContent(ix,iy, vRatio);
          hRatio->SetBinError(ix,iy, evRatio);
          }
        }
      }
    }
  else if (h->IsA()==TH3::Class() || h->IsA()==TH3F::Class() || h->IsA()==TH3D::Class() || h->IsA()==TH3I::Class() )
    {
    int nx = h->GetNbinsX();
    int ny = h->GetNbinsY();
    int nz = h->GetNbinsZ();
    for (int iz=1; iz<=nz; iz++)
      {
      for (int iy=1; iy<=ny; iy++)
        {
        for (int ix=1; ix<=nx; ix++)
          {
          v        = h->GetBinContent(ix,iy,iz);
          ev       = h->GetBinError(ix,iy,iz);
          rev      = (v!=0) ? ev/v : 0.0;
          vRef     = hRef->GetBinContent(ix,iy,iz);
          evRef    = hRef->GetBinError(ix,iy,iz);
          revRef   = (vRef!=0) ? evRef/vRef : 0.0;
          if (vRef)
            {
            vRatio     = v/vRef;
            revRatioSq = correlatedUncertainties ? Math::absolute(rev*rev - revRef*revRef) : rev*rev + revRef*revRef;
            revRatio   = sqrt(revRatioSq);
            evRatio    = revRatio*vRatio;
            hRatio->SetBinContent(ix,iy,iz, vRatio);
            hRatio->SetBinError(ix,iy,iz, evRatio);
            }
          }
        }
      }
    }
  else if (h->IsA()==TProfile::Class() )
    {
    int nx = h->GetNbinsX();
    for (int ix=1; ix<=nx; ix++)
      {
      v        = h->GetBinContent(ix);
      ev       = h->GetBinError(ix);
      rev      = (v!=0) ? ev/v : 0.0;
      vRef     = hRef->GetBinContent(ix);
      evRef    = hRef->GetBinError(ix);
      revRef   = (vRef!=0) ? evRef/vRef : 0.0;
      if (vRef)
        {
        vRatio     = v/vRef;
        revRatioSq = correlatedUncertainties ? Math::absolute(rev*rev - revRef*revRef) : rev*rev + revRef*revRef;
        revRatio   = sqrt(revRatioSq);
        evRatio    = revRatio*vRatio;
        hRatio->SetBinContent(ix, vRatio);
        hRatio->SetBinError(ix, evRatio);
        ((TProfile*)hRatio)->SetBinEntries(ix, 1.0);
        }
      }
    }
  else if (h->IsA()==TProfile2D::Class()  )
    {
    int nx = h->GetNbinsX();
    int ny = h->GetNbinsY();
    for (int iy=1; iy<=ny; iy++)
      {
      for (int ix=1; ix<=nx; ix++)
        {
        v        = h->GetBinContent(ix,iy);
        ev       = h->GetBinError(ix,iy);
        rev      = (v!=0) ? ev/v : 0.0;
        vRef     = hRef->GetBinContent(ix,iy);
        evRef    = hRef->GetBinError(ix,iy);
        revRef   = (vRef!=0) ? evRef/vRef : 0.0;
        if (vRef)
          {
          vRatio     = v/vRef;
          revRatioSq = correlatedUncertainties ? Math::absolute(rev*rev - revRef*revRef) : rev*rev + revRef*revRef;
          revRatio   = sqrt(revRatioSq);
          evRatio    = revRatio*vRatio;
          hRatio->SetBinContent(ix, vRatio);
          hRatio->SetBinError(ix, evRatio);
          //((TProfile*)hRatio)->SetBinEntries(ix,iy, 1.0);
          }
        }
      }
    }
}




} // namespace CAP
