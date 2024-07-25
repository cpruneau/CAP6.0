

void  FilterCreator::createPlusMinusHadronFilters(bool filteringOnPt,  double minPt,  double maxPt,
                                                  bool filteringOnEta, double minEta, double maxEta,
                                                  bool filteringOnY,   double minY,   double maxY)
{
  vector<ParticleFilter*> filters;

  ParticleFilter * filter;

  filter = new ParticleFilter();
  filter->setName("PiP");
  filter->setLongName("PiP");
  filter->setTitle("#pi^{+}");
  filter->setLongTitle("#pi^{+}");
  filter->addCondition(0, 1,  0.0, 0.0);  // live particles only
  filter->addCondition(2, 211, 0.0, 0.0);  // pi+
  if (filteringOnPt)   filter->addCondition(5, 1, minPt,  maxPt);
  if (filteringOnEta)  filter->addCondition(5, 7, minEta, maxEta);
  if (filteringOnY)    filter->addCondition(5, 8, minY,   maxY);
  filters.push_back(filter);



  filter = new ParticleFilter();
  filter->setName("KP");
  filter->setLongName("KP");
  filter->setTitle("K^{+}");
  filter->setLongTitle("K^{+}");
  filter->addCondition(0, 1,  0.0, 0.0);  // live particles only
  filter->addCondition(2, 321, 0.0, 0.0);  // K+
  if (filteringOnPt)   filter->addCondition(5, 1, minPt,  maxPt);
  if (filteringOnEta)  filter->addCondition(5, 7, minEta, maxEta);
  if (filteringOnY)    filter->addCondition(5, 8, minY,   maxY);
  filters.push_back(filter);

  filter = new ParticleFilter();
  filter->setName("PP");
  filter->setLongName("PP");
  filter->setTitle("p");
  filter->setLongTitle("p");
  filter->addCondition(0, 1,  0.0, 0.0);  // live particles only
  filter->addCondition(2, 2212, 0.0, 0.0);  // p+
  if (filteringOnPt)   filter->addCondition(5, 1, minPt,  maxPt);
  if (filteringOnEta)  filter->addCondition(5, 7, minEta, maxEta);
  if (filteringOnY)    filter->addCondition(5, 8, minY,   maxY);
  filters.push_back(filter);

  filter = new ParticleFilter();
  filter->setName("PiM");
  filter->setLongName("PiM");
  filter->setTitle("#pi^{-}");
  filter->setLongTitle("#pi^{-}");
  filter->addCondition(0, 1,  0.0, 0.0);  // live particles only
  filter->addCondition(2, -211, 0.0, 0.0);  // pi-
  if (filteringOnPt)   filter->addCondition(5, 1, minPt,  maxPt);
  if (filteringOnEta)  filter->addCondition(5, 7, minEta, maxEta);
  if (filteringOnY)    filter->addCondition(5, 8, minY,   maxY);
  filters.push_back(filter);

  filter = new ParticleFilter();
  filter->setName("KM");
  filter->setLongName("KM");
  filter->setTitle("K^{-}");
  filter->setLongTitle("K^{-}");
  filter->addCondition(0, 1,  0.0, 0.0);  // live particles only
  filter->addCondition(2, -321, 0.0, 0.0);  // K-
  if (filteringOnPt)   filter->addCondition(5, 1, minPt,  maxPt);
  if (filteringOnEta)  filter->addCondition(5, 7, minEta, maxEta);
  if (filteringOnY)    filter->addCondition(5, 8, minY,   maxY);
  filters.push_back(filter);



  filter = new ParticleFilter();
  filter->setName("PM");
  filter->setLongName("PM");
  filter->setTitle("#bar{p}");
  filter->setLongTitle("#bar{p}");
  filter->addCondition(0, 1,  0.0, 0.0);  // live particles only
  filter->addCondition(2, -2212, 0.0, 0.0);  // pi+
  if (filteringOnPt)   filter->addCondition(5, 1, minPt,  maxPt);
  if (filteringOnEta)  filter->addCondition(5, 7, minEta, maxEta);
  if (filteringOnY)    filter->addCondition(5, 8, minY,   maxY);
  filters.push_back(filter);
  return filters;
}

void  FilterCreator::createChargedHadronFilters(bool filteringOnPt,  double minPt,  double maxPt,
                                                bool filteringOnEta, double minEta, double maxEta,
                                                bool filteringOnY,   double minY,   double maxY)
{
  vector<ParticleFilter*> filters;

  ParticleFilter * filter;

  filter = new ParticleFilter();
  filter->setName("HP");
  filter->setLongName("HP");
  filter->setTitle("h^{+}");
  filter->setLongTitle("h^{+}");
  filter->addCondition(0, 1,  0.0, 0.0);  // live particles only
  filter->addCondition(4, 1103, 0.0, 0.0);   // positive low mass hadron
  if (filteringOnPt)   filter->addCondition(5, 1, minPt,  maxPt);
  if (filteringOnEta)  filter->addCondition(5, 7, minEta, maxEta);
  if (filteringOnY)    filter->addCondition(5, 8, minY,   maxY);
  filters.push_back(filter);

  filter = new ParticleFilter();
  filter->setName("HM");
  filter->setLongName("HM");
  filter->setTitle("h^{-}");
  filter->setLongTitle("h^{+}");
  filter->addCondition(0, 1,  0.0, 0.0);  // live particles only
  filter->addCondition(4, 1104, 0.0, 0.0);   // negative low mass hadron
  if (filteringOnPt)   filter->addCondition(5, 1, minPt,  maxPt);
  if (filteringOnEta)  filter->addCondition(5, 7, minEta, maxEta);
  if (filteringOnY)    filter->addCondition(5, 8, minY,   maxY);
  filters.push_back(filter);
  return filters;
}



ParticleFilter *  FilterCreator::createHadronFilter(int pdg, const String & name, const String  & title,
                                                    bool filteringOnPt,  double minPt,  double maxPt,
                                                    bool filteringOnEta, double minEta, double maxEta,
                                                    bool filteringOnY,   double minY,   double maxY)
{
  ParticleFilter * filter = new ParticleFilter();
  filter->setName(name);
  filter->setLongName(name);
  filter->setTitle(title);
  filter->setLongTitle(title);
  filter->addCondition(0, 1,  0.0, 0.0);  // live particles only
  filter->addCondition(2, pdg,  double(pdg), double(pdg));
  if (filteringOnPt)   filter->addCondition(5, 1, minPt,  maxPt);
  if (filteringOnEta)  filter->addCondition(5, 7, minEta, maxEta);
  if (filteringOnY)    filter->addCondition(5, 8, minY,   maxY);
  return filter;
}

ParticleFilter *  FilterCreator::createIndexFilter(int pdgCode, const String & name, const String  & title,
                                                   bool filteringOnPt,  double minPt,  double maxPt,
                                                   bool filteringOnEta, double minEta, double maxEta,
                                                   bool filteringOnY,   double minY,   double maxY)
{
  ParticleFilter * filter = new ParticleFilter();
  filter->setName(name);
  filter->setLongName(name);
  filter->setTitle(title);
  filter->setLongTitle(title);
  filter->addCondition(0, 1,  0.0, 0.0);  // live particles only
  filter->addCondition(2, pdgCode,  double(pdgCode), double(pdgCode));   // accept particles w/ given pdg code
  if (filteringOnPt)   filter->addCondition(5, 1, minPt,  maxPt);
  if (filteringOnEta)  filter->addCondition(5, 7, minEta, maxEta);
  if (filteringOnY)    filter->addCondition(5, 8, minY,   maxY);
  return filter;
}

vector<ParticleFilter*> FilterCreator::createIndexFilters(ParticleDb & particleDb,
                                                          bool filteringOnPt,  double minPt,  double maxPt,
                                                          bool filteringOnEta, double minEta, double maxEta,
                                                          bool filteringOnY,   double minY,   double maxY)
{
  vector<ParticleFilter*> filters;
  int    pdgCode;
  String name;
  String title;
  int nTypes = particleDb.size();
  if (reportDebug(__FUNCTION__)) printValue("particleDb::nTypes",nTypes);
  for (int k=0; k<nTypes; k++)
    {
    ParticleType * particleType = particleDb.getParticleType(k);
    if (!particleType) throw TaskException("particleType==nullptr","FilterCreator::createIndexFilters(...)");
    pdgCode = particleType->getPdgCode();
    name    = particleType->getName();
    title   = particleType->getTitle();
    ParticleFilter * filter = createIndexFilter(pdgCode,name,title,
                                                filteringOnPt,minPt,maxPt,
                                                filteringOnEta,minEta,maxEta,
                                                filteringOnY,minY,maxY);
    if (reportDebug(__FUNCTION__)) printValue("Created index filter named",filter->getName());
    filters.push_back(filter);
    }
  return filters;
}




void FilterCreator::createBaryonFilters(bool filteringOnPt,  double minPt,  double maxPt,
                                        bool filteringOnEta, double minEta, double maxEta,
                                        bool filteringOnY,   double minY,   double maxY)
{

  // proton  : 2212
  // neutron : 2112
  // lambda  : 3122
  // Sigma+  : 3222
  // Sigma0  : 3212
  // Sigma-  : 3112
  // Xi0     : 3322
  // XiM     : 3312
  // Omega-  : 3334
  // ===========================

  filters.push_back(createHadronFilter(2212,"P",       "p",          filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(2112,"N",       "n",          filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3122,"Lambda0", "#Lambda^{0}",filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3222,"SigmaP",  "#Sigma^{+}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3212,"Sigma0",  "#Sigma^{0}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3112,"SigmaM",  "#Sigma^{-}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3322,"Xi0",     "#Xi^{0}",    filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3312,"XiM",     "#Xi^{-}",    filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3334,"OmegaM",  "#Omega^{-}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));

  filters.push_back(createHadronFilter(-2212,"Pbar",       "#bar{p}",          filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-2112,"Nbar",       "#bar{n}",          filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3122,"Lambda0bar", "#bar{#Lambda}^{0}",filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3222,"SigmaPbar",  "#bar{#Sigma}^{-}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3212,"Sigma0bar",  "#bar{#Sigma}^{0}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3112,"SigmaMbar",  "#bar{#Sigma}^{+}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3322,"Xi0bar",     "#bar{#Xi}^{0}",    filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3312,"XiMbar",     "#bar{#Xi}^{+}",    filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3334,"OmegaMbar",  "#bar{#Omega}^{+}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
}



void FilterCreator::createStrangeHadronFilters(bool filteringOnPt,  double minPt,  double maxPt,
                                               bool filteringOnEta, double minEta, double maxEta,
                                               bool filteringOnY,   double minY,   double maxY)
{

  // lambda  : 3122
  // Sigma+  : 3222
  // Sigma0  : 3212
  // Sigma-  : 3112
  // Xi0     : 3322
  // XiM     : 3312
  // Omega-  : 3334
  // ===========================

  filters.push_back(createHadronFilter(321, "KP",      "K^{+}",      filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3122,"Lambda0", "#Lambda^{0}",filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3222,"SigmaP",  "#Sigma^{+}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3212,"Sigma0",  "#Sigma^{0}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3112,"SigmaM",  "#Sigma^{-}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3322,"Xi0",     "#Xi^{0}",    filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3312,"XiM",     "#Xi^{-}",    filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(3334,"OmegaM",  "#Omega^{-}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));

  filters.push_back(createHadronFilter(-321, "KM",         "K^{-}",            filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3122,"Lambda0bar", "#bar{#Lambda}^{0}",filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3222,"SigmaPbar",  "#bar{#Sigma}^{-}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3212,"Sigma0bar",  "#bar{#Sigma}^{0}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3112,"SigmaMbar",  "#bar{#Sigma}^{+}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3322,"Xi0bar",     "#bar{#Xi}^{0}",    filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3312,"XiMbar",     "#bar{#Xi}^{+}",    filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
  filters.push_back(createHadronFilter(-3334,"OmegaMbar",  "#bar{#Omega}^{+}", filteringOnPt,minPt,maxPt,filteringOnEta,minEta,maxEta,filteringOnY,minY,maxY));
}

// EventFilter
//  filterType  filterSubtype  Observable/Variable
//     10          any            ImpactParameter
//     11          0              AliceMBEvent  v0 multiplicity
//     11          1              AliceMBEvent  TPC multiplicity
//     12          0              V0Multiplicity
//     13          1              TpcMultiplicity

void FilterCreator::createOpenEventFilter()
{
  EventFilter * filter = new EventFilter();
  filter->setName("All");
  filter->setLongName("All");
  filter->setTitle("All");
  filter->setLongTitle("All");
  filters.push_back(filter);
}


void FilterCreator::createImpactParameterFilters(vector<double> & bounds)
{
  EventFilter* filter;
  int n = bounds.size();
  if (reportInfo(__FUNCTION__))
    {
    cout << endl;
    printValue("bounds.size()",n);
    }
  for (int k=0; k<n-1; k++)
    {
    double low  = bounds[k];
    double high = bounds[k+1];
    String name = "b";
    name += int(1000*low);
    name +="To";
    name += int(1000*high);
    String title;
    title = low;
    title += "#LT b <";
    title += high;
    filter = new EventFilter();
    filter->setName(name);
    filter->setLongName(name);
    filter->setTitle(title);
    filter->setLongTitle(title);
    filter->addCondition(10, 0, low, high); // meant to cut on b
    filters.push_back(filter);
    }
}


void FilterCreator::createAliceMBEventFilter()
{
  EventFilter* filter  = new EventFilter();
  filter->setName("AliceMB");
  filter->setLongName("AliceMB");
  filter->setTitle("AliceMB");
  filter->setLongTitle("AliceMB");
  filter->addCondition(11, 0, 1.0, 1.0E10); // v0 multiplicity
  filter->addCondition(11, 1, 1.0, 1.0E10); // TPC multiplicity
  filters.push_back(filter);
}


void FilterCreator::createV0MultiplicityFilters(vector<double> & bounds)
{
  int n = bounds.size();
  if (reportInfo(__FUNCTION__))
    {
    cout << endl;
    printValue("bounds.size()",n);
    }
  EventFilter* filter;
  for (int k=0; k<n-1; k++)
    {
    double low  = bounds[k];
    double high = bounds[k+1];
    String name = "V0M";
    name += int(1000*low);
    name +="To";
    name += int(1000*high);
    String title;
    title = low;
    title += "#LT V0M <";
    title += high;
    filter = new EventFilter();
    filter->setName(name);
    filter->setLongName(name);
    filter->setTitle(title);
    filter->setLongTitle(title);
    filter->addCondition(11, 0, low, high); // meant to cut on V0M
    filters.push_back(filter);
    }
  return filters;
}


void FilterCreator::createTpcMultiplicityFilters(vector<double> & bounds)
{
  EventFilter* filter;
  int n = bounds.size();
  if (reportInfo(__FUNCTION__))
    {
    cout << endl;
    printValue("bounds.size()",n);
    }
  for (int k=0; k<n-1; k++)
    {
    double low  = bounds[k];
    double high = bounds[k+1];
    String name = "TPCMult";
    name += int(1000*low);
    name +="To";
    name += int(1000*high);
    String title;
    title = low;
    title += "#LT TPCMult <";
    title += high;
    filter = new EventFilter();
    filter->setName(name);
    filter->setLongName(name);
    filter->setTitle(title);
    filter->setLongTitle(title);
    filter->addCondition(11, 1, low, high); // meant to cut on V0M
    filters.push_back(filter);
    }
}

