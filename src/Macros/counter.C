#include <iostream>
#include <fstream>
#include <vector>
#include <TStyle.h>
#include <TROOT.h>

void loadBase(const TString & includeBasePath);

int counter()
{
  TString includeBasePath = getenv("CAP_SRC");
  loadBase(includeBasePath);
  CAP::Counter c;
  vector<long> v = {5, 5, 5, -1};
  c.initialize(v);
  cout << "Maxima:" << endl;
  c.printMaxima();
  cout << endl;
  cout << "Counter:" << endl;
  for (int k=0; k<1070; k++)
    {
    c.print();
    cout << "  :  " << c.counterValue()<< endl;
    c.increment();
    }
  return 0;
}


void loadBase(const TString & includeBasePath)
{
  TString includePath = includeBasePath + "/Base/";
  gSystem->Load(includePath+"CAP::Timer.hpp");
  gSystem->Load(includePath+"CAP::Counter.hpp");
  gSystem->Load("libBase.dylib");
}
