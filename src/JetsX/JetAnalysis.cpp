0#include <iostream>
#include "Pythia8/Pythia.h"
#include "fastjet/ClusterSequence.hh"
#include <cmath>
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2.h"
#include "TF1.h"
#include "TMath.h"
#include <cstdlib>
#include "TCanvas.h"
#include "TLatex.h"
#include <map>
#include <stdexcept>
#include "class_charge.hpp"

using namespace fastjet;
using namespace std;
using namespace Pythia8;

class JetAnalysis
{
	public:
		int no_of_events = 10;

		JetAnalysis(int N);
		~JetAnalysis(); 

		void Generator_and_JetAnalysis();
		void Clustering(vector<PseudoJet> &in);

		//void Clustering(vector <PseudoJet> &in);
		void Z_JetAnalysis(std::shared_ptr<ClusterSequence> CS);
		void Renormalization();


	private:

		// creating a member pointer which points to the clusteringSequence object which got clustered.
		std::shared_ptr<ClusterSequence> clusterSequencePtr;  

		int count_0to50, count_50to100, count_100to150, count_150to200, count_200to250, count_250to300, count_300andmore;

		void Store(Event &event_array);
		Pythia pythia; // This the object of Pythia which carry all the generated data.
		vector <PseudoJet> clustering_input; // We store the particle generated in eacgh event here temporarily.
		vector<PseudoJet> jets; // in this vector we store the clusterd jets in an accending pt order.

		/* Here afe the root Canvas files */
		TFile *output;
		
		// pointers for +ve particle z-distribution
		TH1D *h_zP_0_50Gev;
    	TH1D *h_zP_50_100Gev;
    	TH1D *h_zP_100_150Gev;
    	TH1D *h_zP_150_200Gev;
    	TH1D *h_zP_200_250Gev;
    	TH1D *h_zP_250_300Gev;
    	TH1D *h_zP_more_300Gev;

    	// pointers for -ve particle z-distribution
    	TH1D *h_zN_0_50Gev;
    	TH1D *h_zN_50_100Gev;
    	TH1D *h_zN_100_150Gev;
    	TH1D *h_zN_150_200Gev;
    	TH1D *h_zN_200_250Gev;
    	TH1D *h_zN_250_300Gev;
    	TH1D *h_zN_more_300Gev;

    	// pointers for +ve & -ve pairs z-distribution
    	TH2D *h_zPN_0_50Gev;
    	TH2D *h_zPN_50_100Gev;
    	TH2D *h_zPN_100_150Gev;
    	TH2D *h_zPN_150_200Gev;
    	TH2D *h_zPN_200_250Gev;
    	TH2D *h_zPN_250_300Gev;
    	TH2D *h_zPN_more_300Gev;

    	// pointers for -ve & +ve pairs z-distribution
    	TH2D *h_zNP_0_50Gev;
    	TH2D *h_zNP_50_100Gev;
    	TH2D *h_zNP_100_150Gev;
    	TH2D *h_zNP_150_200Gev;
    	TH2D *h_zNP_200_250Gev;
    	TH2D *h_zNP_250_300Gev;
    	TH2D *h_zNP_more_300Gev;

    	// pointers for +ve & +ve pairs z-distribution
    	TH2D *h_zPP_0_50Gev;
    	TH2D *h_zPP_50_100Gev;
    	TH2D *h_zPP_100_150Gev;
    	TH2D *h_zPP_150_200Gev;
    	TH2D *h_zPP_200_250Gev;
    	TH2D *h_zPP_250_300Gev;
    	TH2D *h_zPP_more_300Gev;

    	// pointers for -ve & -ve pairs z-distribution
    	TH2D *h_zNN_0_50Gev;
    	TH2D *h_zNN_50_100Gev;
    	TH2D *h_zNN_100_150Gev;
    	TH2D *h_zNN_150_200Gev;
    	TH2D *h_zNN_200_250Gev;
    	TH2D *h_zNN_250_300Gev;
    	TH2D *h_zNN_more_300Gev;

};

JetAnalysis::JetAnalysis(int N) {
	no_of_events = N;
	int h_bincount = 200;

	output = new TFile("JetAnalysis Normalised version for 5,00,000.root", "recreate");

	// -ve particles z distribution 
	h_zP_0_50Gev = new TH1D("zPluse 0 - 50Gev", "zPluse 0 - 50Gev", h_bincount, 0, 1);
	h_zP_50_100Gev = new TH1D("zPluse 50 - 100Gev", "zPluse 50 - 100Gev", h_bincount, 0, 1);
	h_zP_100_150Gev = new TH1D("zPluse 100 - 150Gev", "zPluse 100 - 150Gev", h_bincount, 0, 1);
	h_zP_150_200Gev = new TH1D("zPluse 150 - 200Gev", "zPluse 150 - 200Gev", h_bincount, 0, 1);
	h_zP_200_250Gev = new TH1D("zPluse 200 - 250Gev", "zPluse 200 - 250Gev", h_bincount, 0, 1);
	h_zP_250_300Gev = new TH1D("zPluse 250 - 300Gev", "zPluse 250 - 300Gev", h_bincount, 0, 1);
	h_zP_more_300Gev = new TH1D("zPluse more than 300Gev", "zPluse 300Gev and higher", h_bincount, 0, 1);

	// -ve particles z dirstribition
	h_zN_0_50Gev = new TH1D("z negative 0 - 50Gev", "z negative 0 - 50Gev", h_bincount, 0, 1);
	h_zN_50_100Gev = new TH1D("z negative 50 - 100Gev", "z negative 50 - 100Gev", h_bincount, 0, 1);
	h_zN_100_150Gev = new TH1D("z negative 100 - 150Gev", "z negative 100 - 150Gev", h_bincount, 0, 1);
	h_zN_150_200Gev = new TH1D("z negative 150 - 200Gev", "z negative 150 - 200Gev", h_bincount, 0, 1);
	h_zN_200_250Gev = new TH1D("z negative 200 - 250Gev", "z negative 200 - 250Gev", h_bincount, 0, 1);
	h_zN_250_300Gev = new TH1D("z negative 250 - 300Gev", "z negative 250 - 300Gev", h_bincount, 0, 1);
	h_zN_more_300Gev = new TH1D("z negative more than 300Gev", "z negative 300Gev and higher", h_bincount, 0, 1);

	// +ve and -ve pairs
	h_zPN_0_50Gev = new TH2D("+ & - charge pairs in 0-50Gev of Jets pT", "+ & - Charge pairs in range 0-50 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPN_50_100Gev = new TH2D("+ & - charge pairs in 50-100Gev of Jets pT", "+ & - Charge pairs in range 50-100 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPN_100_150Gev = new TH2D("+ & - charge pairs in 100-150Gev of Jets pT", "+ & - Charge pairs in range 100-150 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPN_150_200Gev = new TH2D("+ & - charge pairs in 150-2000Gev of Jets pT", "+ & - Charge pairs in range 150-200 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPN_200_250Gev = new TH2D("+ & - charge pairs in 200-250Gev of Jets pT", "+ & - Charge pairs in range 200-250 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPN_250_300Gev = new TH2D("+ & - charge pairs in 250-300Gev of Jets pT", "+ & - Charge pairs in range 250-300 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPN_more_300Gev = new TH2D("+ & - charge pairs in 300 and more ev of Jets pT", "+ & - Charge pairs in range 300 and more Gev", h_bincount, 0, 1, h_bincount, 0, 1);


	// -ve and +ve pairs
	h_zNP_0_50Gev = new TH2D("- & + charge pairs in 0-50Gev of Jets pT", "- & + Charge pairs in range 0-50 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNP_50_100Gev = new TH2D("- & + charge pairs in 50-100Gev of Jets pT", "- & + Charge pairs in range 50-100 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNP_100_150Gev = new TH2D("- & + charge pairs in 100-150Gev of Jets pT", "- & + Charge pairs in range 100-150 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNP_150_200Gev = new TH2D("- & + charge pairs in 150-2000Gev of Jets pT", "- & + Charge pairs in range 150-200 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNP_200_250Gev = new TH2D("- & + charge pairs in 200-250Gev of Jets pT", "- & + Charge pairs in range 200-250 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNP_250_300Gev = new TH2D("- & + charge pairs in 250-300Gev of Jets pT", "- & + Charge pairs in range 250-300 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNP_more_300Gev = new TH2D("- & + charge pairs in 300 and more ev of Jets pT", "- & + Charge pairs in range 300 and more Gev", h_bincount, 0, 1, h_bincount, 0, 1);


	// +ve and +ve pairs
	h_zPP_0_50Gev = new TH2D("+ & + charge pairs in 0-50Gev of Jets pT", "+ & + Charge pairs in range 0-50 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPP_50_100Gev = new TH2D("+ & + charge pairs in 50-100Gev of Jets pT", "+ & + Charge pairs in range 50-100 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPP_100_150Gev = new TH2D("+ & + charge pairs in 100-150Gev of Jets pT", "+ & + Charge pairs in range 100-150 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPP_150_200Gev = new TH2D("+ & + charge pairs in 150-2000Gev of Jets pT", "+ & + Charge pairs in range 150-200 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPP_200_250Gev = new TH2D("+ & + charge pairs in 200-250Gev of Jets pT", "+ & + Charge pairs in range 200-250 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPP_250_300Gev = new TH2D("+ & + charge pairs in 250-300Gev of Jets pT", "+ & + Charge pairs in range 250-300 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zPP_more_300Gev = new TH2D("+ & + charge pairs in 300 and more ev of Jets pT", "+ & + Charge pairs in range 300 and more Gev", h_bincount, 0, 1, h_bincount, 0, 1);

	// -ve and -ve pairs
	h_zNN_0_50Gev = new TH2D("- & - charge pairs in 0-50Gev of Jets pT", "- & - Charge pairs in range 0-50 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNN_50_100Gev = new TH2D("- & - charge pairs in 50-100Gev of Jets pT", "- & - Charge pairs in range 50-100 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNN_100_150Gev = new TH2D("- & - charge pairs in 100-150Gev of Jets pT", "- & - Charge pairs in range 100-150 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNN_150_200Gev = new TH2D("- & - charge pairs in 150-2000Gev of Jets pT", "- & - Charge pairs in range 150-200 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNN_200_250Gev = new TH2D("- & - charge pairs in 200-250Gev of Jets pT", "- & - Charge pairs in range 200-250 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNN_250_300Gev = new TH2D("- & - charge pairs in 250-300Gev of Jets pT", "- & - Charge pairs in range 250-300 Gev", h_bincount, 0, 1, h_bincount, 0, 1);
	h_zNN_more_300Gev = new TH2D("- & - charge pairs in 300 and more ev of Jets pT", "- & - Charge pairs in range 300 and more Gev", h_bincount, 0, 1, h_bincount, 0, 1);


}

JetAnalysis::~JetAnalysis() {
    output->Write(); // Save all histograms to the file
    
    //freeing memory of +ve particle z-distribution
    delete h_zP_0_50Gev;
    delete h_zP_50_100Gev;
    delete h_zP_100_150Gev;
    delete h_zP_150_200Gev;
    delete h_zP_200_250Gev;
    delete h_zP_250_300Gev;
    delete h_zP_more_300Gev;

    // freeing memory of -ve particle z-distribution
    delete h_zN_0_50Gev;
    delete h_zN_50_100Gev;
    delete h_zN_100_150Gev;
    delete h_zN_150_200Gev;
    delete h_zN_200_250Gev;
    delete h_zN_250_300Gev;
    delete h_zN_more_300Gev;

    //freeing memory of +ve and -ve particles z-distribution
    delete h_zPN_0_50Gev;
    delete h_zPN_50_100Gev;
    delete h_zPN_100_150Gev;
    delete h_zPN_150_200Gev;
    delete h_zPN_200_250Gev;
    delete h_zPN_250_300Gev;
    delete h_zPN_more_300Gev;

    //freeing memory of -ve and +ve particles z-distribution
    delete h_zNP_0_50Gev;
    delete h_zNP_50_100Gev;
    delete h_zNP_100_150Gev;
    delete h_zNP_150_200Gev;
    delete h_zNP_200_250Gev;
    delete h_zNP_250_300Gev;
    delete h_zNP_more_300Gev;

	//freeing memory of +ve and +ve particles z-distribution
    delete h_zPP_0_50Gev;
    delete h_zPP_50_100Gev;
    delete h_zPP_100_150Gev;
    delete h_zPP_150_200Gev;
    delete h_zPP_200_250Gev;
    delete h_zPP_250_300Gev;
    delete h_zPP_more_300Gev;

	//freeing memory of +ve and +ve particles z-distribution
    delete h_zNN_0_50Gev;
    delete h_zNN_50_100Gev;
    delete h_zNN_100_150Gev;
    delete h_zNN_150_200Gev;
    delete h_zNN_200_250Gev;
    delete h_zNN_250_300Gev;
    delete h_zNN_more_300Gev;


    delete output; // Close the file
}

void JetAnalysis :: Generator_and_JetAnalysis(){
	/* Configurtion setting of the Collision events*/
	pythia.readString("Beams:idA = 2212");
    pythia.readString("Beams:idB = 2212");
    pythia.readString("Beams:eCM = 13000");
    pythia.readString("SoftQCD:all = on");
    pythia.readString("HardQCD:all = on");

    pythia.init();// Initializing

    if (!pythia.init()) {// Checking the Initialization succedd or not
        cerr << "Pythia initialization failed!" << endl; 
        }

    for (int i = 0; i < no_of_events; i++) {

    	// Clear the event
        pythia.event.clear();

        // Generate next event
        if (!pythia.next()) continue;

        double entries = pythia.event.size();
        cout<<"sucessful "<< i <<endl;

        /* storing these particles for clustering */
        Store(pythia.event);
        Clustering(clustering_input);
        Z_JetAnalysis(clusterSequencePtr);
       
    }
    Renormalization();
}

void JetAnalysis:: Store(Event &event_array){
	/* we should clear the vector before storing new data */

//  vector<TString> myNames;
//  myNames.clear();
//
//  vector<TString*> myOtherNames;
//  for (auto & name : myOtherNames) delete name;
//  myOtherNames.clear();

	clustering_input.clear();

	int no_of_particles_in_an_event = event_array.size();
	cout<< "no_of_particles_in_an_event "<<no_of_particles_in_an_event<<endl;

        for (int i = 0; i < no_of_particles_in_an_event; ++i)
        {
        	double px, py, pz, E;
        	int id;

        	id = event_array[i].id();

        	px = event_array[i].px();
        	py = event_array[i].py();
        	pz = event_array[i].py();
        	E = event_array[i].e();

        	PseudoJet particles (px, py, pz, E);
        	particles.set_user_index(id);

        	clustering_input.push_back(particles);
        }

}

 void JetAnalysis::Clustering(vector<PseudoJet> &input){

	// we have to make sure the clustering object pointer is cleared befor we repurpose it for new event
		clusterSequencePtr.reset();

	// jet definition
       double R = 0.5;


   // where is defined?????
    // antikt_algorithm
       JetDefinition jet_def(antikt_algorithm, R);

      
       // Create a shared pointer to a new ClusterSequence object
		clusterSequencePtr  = std::make_shared<ClusterSequence>(input, jet_def);
}

/* This function does JetAnalysis with z distribution within the jets */
void JetAnalysis :: Z_JetAnalysis(std::shared_ptr<ClusterSequence> CS){

	// now using the shared_ptr creat jets

	/* Before storing the clustered jets in the vector jets we cshould clear the jets vector*/

  // ====================================================================================
  // this clears the vector but does not necessarily delete the objects pointed at...
  // ====================================================================================
  jets.clear();

    /* Now store the clustered jets in the vector jets*/
       jets = sorted_by_pt( CS->inclusive_jets() );
       int No_of_Jets = jets.size();// histogram for this.

       // This loop runs over each jets one-by-one
       for (int i = 0; i < No_of_Jets; ++i)
       {
       		int Jets_pT = jets[i].pt();

       		vector<PseudoJet> Constituents_of_jet = jets[i].constituents();
       		int number_of_particle_in_jet = Constituents_of_jet.size();

       		// This following loop scans all the constituent particle in the ith jet one by one
       		for (int j = 0; j < number_of_particle_in_jet; ++j)
       		{
       			//retrive the pdgid of the jth constituent particle in the ith jets
       			int pdgid = Constituents_of_jet[j].user_index();
       			cout<<"pdgid 1st particle : "<<pdgid<<endl; 

       			// creat an object for class_charge to retrive the chareg of the particle
       			class_charge q;
		 		double charge1 = q.GetCharge(pdgid);

		 		double z1 = Constituents_of_jet[j].pt() / Jets_pT;  

		 			if (Jets_pT>=0 && Jets_pT<50){

		 				count_0to50++;
		 				if(charge1>0){h_zP_0_50Gev->Fill(z1);}else if(charge1<0){ h_zN_0_50Gev->Fill(z1);}
		 				
									
					}else if(Jets_pT>=50 && Jets_pT<100){

						count_50to100++;
						if(charge1>0){h_zP_50_100Gev->Fill(z1);}else if(charge1<0){ h_zN_50_100Gev->Fill(z1);}

	
					}else if(Jets_pT<=100 && Jets_pT>150){

						count_100to150++;
						if(charge1>0){h_zP_100_150Gev->Fill(z1);}else if(charge1<0){ h_zN_100_150Gev->Fill(z1);}


					}else if(Jets_pT>=150 && Jets_pT<200){

						count_150to200++;
						if(charge1>0){h_zP_150_200Gev->Fill(z1);}else if(charge1<0){ h_zN_150_200Gev->Fill(z1);}


					}else if(Jets_pT>=200 && Jets_pT<250){

						count_200to250++;
						if(charge1>0){h_zP_200_250Gev->Fill(z1);}else if(charge1<0){ h_zN_200_250Gev->Fill(z1);}

					}else if(Jets_pT>=250 && Jets_pT<300){

						count_250to300++;
						if(charge1>0){h_zP_250_300Gev->Fill(z1);}else if(charge1<0){ h_zN_250_300Gev->Fill(z1);}


					}else{
						
						count_300andmore++;
						if(charge1>0){h_zP_more_300Gev->Fill(z1);}else if(charge1<0){ h_zN_more_300Gev->Fill(z1);}
					}


					for ( int k = 0; k <number_of_particle_in_jet ; ++k)
		 			{
		 			if( j == k){ continue;
		 			}else{

		 				int pdgid_2 = Constituents_of_jet[k].user_index();
		 				cout<< "pdgid of particle 2 : "<<pdgid_2<<endl;

		 				double z2 = Constituents_of_jet[k].pt()/Jets_pT;

		 				class_charge q1;
		 				double charge2 = q1.GetCharge(pdgid_2);

		 					if (charge1 >0 && charge2>0){ //PP
		 					
		 						if (Jets_pT>=0 && Jets_pT<50){
									h_zPP_0_50Gev->Fill(z1,z2);
								}else if(Jets_pT>=50 && Jets_pT<100){
									h_zPP_50_100Gev->Fill(z1,z2);
								}else if(Jets_pT<=100 && Jets_pT>150){
									h_zPP_100_150Gev->Fill(z1,z2);
								}else if(Jets_pT>=150 && Jets_pT<200){
									h_zPP_150_200Gev->Fill(z1,z2);
								}else if(Jets_pT>=200 && Jets_pT<250){
									h_zPP_200_250Gev->Fill(z1,z2);
								}else if(Jets_pT>=250 && Jets_pT<300){
									h_zPP_250_300Gev->Fill(z1,z2);
								}else{
									h_zPP_more_300Gev->Fill(z1,z2);
								}

		 					}else if(charge1 >0 && charge2 <0){ //PN

		 						if (Jets_pT>=0 && Jets_pT<50){
									h_zPN_0_50Gev->Fill(z1,z2);
								}else if(Jets_pT>=50 && Jets_pT<100){
									h_zPN_50_100Gev->Fill(z1,z2);
								}else if(Jets_pT<=100 && Jets_pT>150){
									h_zPN_100_150Gev->Fill(z1,z2);
								}else if(Jets_pT>=150 && Jets_pT<200){
									h_zPN_150_200Gev->Fill(z1,z2);
								}else if(Jets_pT>=200 && Jets_pT<250){
									h_zPN_200_250Gev->Fill(z1,z2);
								}else if(Jets_pT>=250 && Jets_pT<300){
									h_zPN_250_300Gev->Fill(z1,z2);
								}else{
									h_zPN_more_300Gev->Fill(z1,z2);
								}

		 					}else if(charge1<0 && charge2>0){ //NP

		 						if (Jets_pT>=0 && Jets_pT<50){
									h_zNP_0_50Gev->Fill(z1,z2);
								}else if(Jets_pT>=50 && Jets_pT<100){
									h_zNP_50_100Gev->Fill(z1,z2);
								}else if(Jets_pT<=100 && Jets_pT>150){
									h_zNP_100_150Gev->Fill(z1,z2);
								}else if(Jets_pT>=150 && Jets_pT<200){
									h_zNP_150_200Gev->Fill(z1,z2);
								}else if(Jets_pT>=200 && Jets_pT<250){
									h_zNP_200_250Gev->Fill(z1,z2);
								}else if(Jets_pT>=250 && Jets_pT<300){
									h_zNP_250_300Gev->Fill(z1,z2);
								}else{
									h_zNP_more_300Gev->Fill(z1,z2);
								}

		 					}else if (charge1<0 && charge2<0 ){ //NN

		 						if (Jets_pT>=0 && Jets_pT<50){
									h_zNN_0_50Gev->Fill(z1,z2);
								}else if(Jets_pT>=50 && Jets_pT<100){
									h_zNN_50_100Gev->Fill(z1,z2);
								}else if(Jets_pT<=100 && Jets_pT>150){
									h_zNN_100_150Gev->Fill(z1,z2);
								}else if(Jets_pT>=150 && Jets_pT<200){
									h_zNN_150_200Gev->Fill(z1,z2);
								}else if(Jets_pT>=200 && Jets_pT<250){
									h_zNN_200_250Gev->Fill(z1,z2);
								}else if(Jets_pT>=250 && Jets_pT<300){
									h_zNN_250_300Gev->Fill(z1,z2);
								}else{
									h_zNN_more_300Gev->Fill(z1,z2);
								}
		 						}
		 				}

       				}


		 	}


		 		
       	
       }

}
// ====================================================================================
// Renormalization??? Why? It is simply a normalization...
// ====================================================================================

void JetAnalysis :: Renormalization(){

	if (count_0to50!=0)
	{
		// Re-normalizing for pT 0-50Gev   1.0/double(count_0to50) do this to rescale.
	h_zP_0_50Gev->Scale(1.0 / double(count_0to50) ); 
	h_zN_0_50Gev->Scale(1.0 / double(count_0to50));
	h_zPP_0_50Gev->Scale(1.0 / double(count_0to50));
	h_zPN_0_50Gev->Scale(1.0 / double(count_0to50));
	h_zNP_0_50Gev->Scale(1.0 / double(count_0to50));
	h_zNN_0_50Gev->Scale(1.0 / double(count_0to50));
	}

	if (count_50to100!=0)
	{
		//Re-normalizing for pT 50-100Gev
	h_zP_50_100Gev->Scale(1.0 / double(count_50to100)); 
	h_zN_50_100Gev->Scale(1.0 / double(count_50to100));
	h_zPP_50_100Gev->Scale(1.0 / double(count_50to100));
	h_zPN_50_100Gev->Scale(1.0 / double(count_50to100));
	h_zNP_50_100Gev->Scale(1.0 / double(count_50to100));
	h_zNN_50_100Gev->Scale(1.0 / double(count_50to100));
	}

	if (count_100to150!=0)
	{
		//Re-normalizing for pT 100-150Gev
	h_zP_100_150Gev->Scale(1.0 / double(count_100to150)); 
	h_zN_100_150Gev->Scale(1.0 / double(count_100to150));
	h_zPP_100_150Gev->Scale(1.0 / double(count_100to150));
	h_zPN_100_150Gev->Scale(1.0 / double(count_100to150));
	h_zNP_100_150Gev->Scale(1.0 / double(count_100to150));
	h_zNN_100_150Gev->Scale(1.0 / double(count_100to150));
	}

	if (count_150to200!=0)
	{
		//Re-normalizing for pT 150-200Gev
	h_zP_150_200Gev->Scale(1.0 / double(count_150to200)); 
	h_zN_150_200Gev->Scale(1.0 / double(count_150to200));
	h_zPP_150_200Gev->Scale(1.0 / double(count_150to200));
	h_zPN_150_200Gev->Scale(1.0 / double(count_150to200));
	h_zNP_150_200Gev->Scale(1.0 / double(count_150to200));
	h_zNN_150_200Gev->Scale(1.0 / double(count_150to200));
	}

	if (count_200to250!=0)
	{
		//Re-normalizing for pT 200-250Gev
	h_zP_200_250Gev->Scale(1.0 / double(count_200to250)); 
	h_zN_200_250Gev->Scale(1.0 / double(count_200to250));
	h_zPP_200_250Gev->Scale(1.0 / double(count_200to250));
	h_zPN_200_250Gev->Scale(1.0 / double(count_200to250));
	h_zNP_200_250Gev->Scale(1.0 / double(count_200to250));
	h_zNN_200_250Gev->Scale(1.0 / double(count_200to250));
	}

	if (count_250to300!=0)
	{
		//Re-normalizing for pT 250-300Gev
	h_zP_250_300Gev->Scale(1.0 / double(count_250to300)); 
	h_zN_250_300Gev->Scale(1.0 / double(count_250to300));
	h_zPP_250_300Gev->Scale(1.0 / double(count_250to300));
	h_zPN_250_300Gev->Scale(1.0 / double(count_250to300));
	h_zNP_250_300Gev->Scale(1.0 / double(count_250to300));
	h_zNN_250_300Gev->Scale(1.0 / double(count_250to300));
	}

	if(count_300andmore!=0){
		//Renormalizing for pT 300+Gev
	h_zP_more_300Gev->Scale(1.0/ double(count_300andmore));
	h_zN_more_300Gev->Scale(1.0/ double(count_300andmore));
	h_zPP_more_300Gev->Scale(1.0/ double(count_300andmore));
	h_zPN_more_300Gev->Scale(1.0/ double(count_300andmore));
	h_zNP_more_300Gev->Scale(1.0/ double(count_300andmore));
	h_zNN_more_300Gev->Scale(1.0/ double(count_300andmore));
	}

}


int main()
{
	/* Passing the no of events into the constructor */
	JetAnalysis Jets (500000);
	Jets.Generator_and_JetAnalysis();


	return 0;
}


// ====================================================================================
// ideas ....
// ====================================================================================


class SingleParticleJetAnalysis
{
protected:

  TString baseJetClassName;
  unsigned int nJets;      // number of jets used
  unsigned int nParticles; // number of particles in the jet
  unsigned int nSelectedParticles; // number of selected particles in the jet
  int selectionOption;   // what kind of particles are used to fill the jet

  TH1 * h_nParticles;
  TH1 * h_nSelectedParticles;
  TH1 * h_jetE;   // spectrum of the jet energy
  TH1 * h_jetPt;  // spectrum of the jet pT
  TH1 * h_jetPhi; // spectrum of the jet phi angle
  TH1 * h_jetY;   // spectrum of the jet rapidity or pseudo rapidity

  TH1 * h_pt;     // spectrum of the particles pT in the jet
  TH1 * h_jt;     // spectrum of the particles jT in the jet
  TH1 * h_z;

  public:

  SingleParticleJetAnalysis(const TString baseJetClassName & _baseJetClassName);
  virtual ~SingleParticleJetAnalysis();
  virtual void createHistograms();
  virtual void fillHistograms();
  virtual void scaleHistograms();
  virtual void saveHistograms();

}

SingleParticleJetAnalysis::SingleParticleJetAnalysis(const TString baseJetClassName & _baseJetClassName, int _selectionOption)
:
baseJetClassName("NAME"),
nJets(0),
nParticles(0),
nSelectedParticles(_selectionOption),
selectionOption(0),
h_nParticles(nullptr),
h_nSelectedParticles(nullptr),
h_jetE(nullptr),
h_jetPt(nullptr),
h_jetPhi(nullptr),
h_jetY(nullptr),
h_pt(nullptr),
h_jt(nullptr),
h_z(nullptr)
{
  createHistograms();
}

SingleParticleJetAnalysis::~JetAnalysis()
{
  // delte stuff here
  }

SingleParticleJetAnalysis::createHistograms()
{
  TString hName;
  TString bn = baseJetClassName; // base name of histograms
  bn += "_";
  hName = bn; hName += "nParticles";
  h_nParticles = new TH1D(hName,hName,50,0.0,50.0);
  hName = bn; hName += "nSelectedParticles";
  h_nSelectedParticles = new TH1D(hName,hName,50,0.0,50.0);
  hName = bn; hName += "jetE";
  h_jetE = new TH1D(hName,hName,50,0.0,200.0);
  hName = bn; hName += "jetPt";
  h_jetPt = new TH1D(hName,hName,50,0.0,200.0);
  hName = bn; hName += "jetPhi";
  h_jetPhi = new TH1D(hName,hName,36,0.0,2.0*3.1415927);
  hName = bn; hName += "jetY";
  h_jetY = new TH1D(hName,hName,20,-5.0,5.0);
  hName = bn; hName += "pt";
  h_pt = new TH1D(hName,hName,50,0.0,50.0);
  hName = bn; hName += "jt";
  h_jt = new TH1D(hName,hName,50,0.0,10.0);
  hName = bn; hName += "z";
  h_z = new TH1D(hName,hName,100,0.0,1.0);

}


SingleParticleJetAnalysis::fillHistograms(Jet & jet);
{
  nJets++;
  nParticles = jet.size();

  h_jetE->Fill(jet.E());
  h_jetPt->Fill(jet.Pt());
  h_jetPhi->Fill(jet.Phi());
  h_jetY->Fill(jet.Y());


  nSelectedParticles = 0;
  vector<PseudoJet> particles = jets.constituents();
  for (auto & particle : particles+)
    {
    bool selected = false;
    switch (selectionOption)
      {
        case  0: selected = true; break;
        case  1: if (particle->charge > 0) selected = true; break;
        case -1: if (particle->charge < 0) selected = true; break;
        // could also use pT criteria here....
      }
    if (selected)
      {
      h_pt->Fill(particle.Pt());
      h_jt->Fill(particle.Jt());
      h_z->Fill(particle.z());
      nSelectedParticles++;
      }
    }


  h_nParticles->fill(double(nParticles));
  h_nSelectedParticles->fill(double(nSelectedParticles));
}


void SingleParticleJetAnalysis::scaleHistograms()
{
  double scalingFactor = 1.0/double(nJets);
  h_jetE->Scale(scalingFactor);
  h_jetPt->Scale(scalingFactor);
  h_jetPhi->Scale(scalingFactor);
  h_jetY->Scale(scalingFactor);
  h_pt->Scale(scalingFactor);
  h_jt->Scale(scalingFactor);
  h_z->Scale(scalingFactor);
  h_nParticles->Scale(scalingFactor);
  h_nSelectedParticles->Scale(scalingFactor);
}

void SingleParticleJetAnalysis::saveHistograms(TFile & outputFile)
{
  outputFile.cd();
  h_jetE->Write();
  h_jetPt->Write();
  h_jetPhi->Write();
  h_jetY->Write();
  h_pt->Write();
  h_jt->Write();
  h_z->Write();
  h_nParticles->Write();
  h_nSelectedParticles->Write();
}

void SingleParticleJetAnalysis::resetHistograms()
{
  h_jetE->Reset();
  h_jetPt->Reset();
  h_jetPhi->Reset();
  h_jetY->Reset();
  h_pt->Reset();
  h_jt->Reset();
  h_z->Reset();
  h_nParticles->Reset();
  h_nSelectedParticles->Reset();
}



void createHistograms()
{
  vector<SingleParticleJetAnalysis*> singleJetHistograms;
  vector<PairParticleJetAnalysis*> pairJetHistograms;

  jetHistograms.push_back(new SingleParticleJetAnalysis("All_10_20GeV",0));  all particles in jets in the 10 - 20 GeV range
  jetHistograms.push_back(new SingleParticleJetAnalysis("All_20_40GeV",0));
  jetHistograms.push_back(new SingleParticleJetAnalysis("All_40_200GeV",0));
  jetHistograms.push_back(new SingleParticleJetAnalysis("Neg_10_20GeV",-1));  all negative particles jets in the 10 - 20 GeV range
  jetHistograms.push_back(new SingleParticleJetAnalysis("Neg_20_40GeV",-1));
  jetHistograms.push_back(new SingleParticleJetAnalysis("Neg_40_200GeV",-1));

  jetHistograms.push_back(new SingleParticleJetAnalysis("Pos_10_20GeV", 1));  all positive particles jets in the 10 - 20 GeV range
  jetHistograms.push_back(new SingleParticleJetAnalysis("Pos_20_40GeV", 1));
  jetHistograms.push_back(new SingleParticleJetAnalysis("Pos_40_200GeV", 1));

  /// bla bla bla
  ///
  ///

  vector<double> minima;
  vector<double> maxima;
  for (int k=0; k<nClasses; k+)


  here you have a jet
  // all charges
  if (jetEnergy>= minima[k]  && maxima[k]>= 20)
    jetHistograms[0]->fill(jet);
  else if (jetEnergy>= 20  && jetEnergy>= 40)
    jetHistograms[1]->fill(jet);
  else
    jetHistograms[2]->fill(jet);

  // negative particles only
  if (jetEnergy>= 10  && jetEnergy>= 20)
    jetHistograms[3]->fill(jet);
  else if (jetEnergy>= 20  && jetEnergy>= 40)
    jetHistograms[4]->fill(jet);
  else
    jetHistograms[5]->fill(jet);

  // positive particles only
  if (jetEnergy>= 10  && jetEnergy>= 20)
    jetHistograms[6]->fill(jet);
  else if (jetEnergy>= 20  && jetEnergy>= 40)
    jetHistograms[7]->fill(jet);
  else
    jetHistograms[8]->fill(jet);



    }
