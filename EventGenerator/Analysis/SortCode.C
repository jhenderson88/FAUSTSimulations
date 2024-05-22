#define SortCode_cxx
#include "SortCode.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void SortCode::Loop(const char *outfilename)
{
	//   In a ROOT session, you can do:
	//      root> .L SortCode.C
	//      root> SortCode t
	//      root> t.GetEntry(12); // Fill t data members with entry number 12
	//      root> t.Show();       // Show values of entry 12
	//      root> t.Show(16);     // Read and show values of entry 16
	//      root> t.Loop();       // Loop on all entries
	//

	//     This is the loop skeleton where:
	//    jentry is the global entry number in the chain
	//    ientry is the entry number in the current Tree
	//  Note that the argument to GetEntry must be:
	//    jentry for TChain::GetEntry
	//    ientry for TTree::GetEntry and TBranch::GetEntry
	//
	//       To read only selected branches, Insert statements like:
	// METHOD1:
	//    fChain->SetBranchStatus("*",0);  // disable all branches
	//    fChain->SetBranchStatus("branchname",1);  // activate branchname
	// METHOD2: replace line
	//    fChain->GetEntry(jentry);       //read all branches
	//by  b_branchname->GetEntry(ientry); //read only this branch
	if (fChain == 0) return;

	Long64_t nentries = fChain->GetEntriesFast();

	TFile	*outfile = new TFile(outfilename,"RECREATE");
	TH2F	*hE_Theta = new TH2F("E_Theta","E_Theta",1800,0,180,4196,0,256);
	TH2F	*hpE_pTheta = new TH2F("pE_Theta","pE_Theta",1800,0,180,4196,0,256);

	TH2F	*hExc_Theta = new TH2F("Exc_Theta","Exc_Theta",180,0,180,8192,0,64);

	Kinematics	*kin = new Kinematics(21,10,2,1,1,1,0);
	kin->SetReactionEnergy(1000.);

	std::cout	<< "Begin sort of "
			<< nentries
			<< " events"
			<< std::endl;

	Long64_t nbytes = 0, nb = 0;
	for (Long64_t jentry=0; jentry<nentries;jentry++) {
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) 
			break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;
		// if (Cut(ientry) < 0) continue;
		//
	
		double	Energy = 0;
		double	theta = -1;
		for(size_t i=0;i<Edep->size();i++){
			Energy += Edep->at(i); 
			if(DetID->at(i) == 1)
				theta = Theta->at(i); 
		}
		hpE_pTheta->Fill(PrimT * TMath::RadToDeg(),PrimE);
		hE_Theta->Fill(theta * TMath::RadToDeg(),Energy);

		if(theta > 0){
			double	excE	= kin->Reconstruct(PrimE,PrimT); 

			hExc_Theta->Fill(theta * TMath::RadToDeg(), excE);
		}

		if(jentry%100000 == 0)
                	std::cout << std::setiosflags(std::ios::fixed) << "Entry " << jentry << " of " << nentries << ", " << 100 * (double)jentry/((double)nentries) << "% complete" << "\r" << std::flush;
	}
	std::cout << "Entry " << nentries << " of " << nentries << ", 100.00% complete" << std::endl; 
	outfile->cd();
	hE_Theta->Write();
	hpE_pTheta->Write();
	hExc_Theta->Write();
	outfile->Write();
	outfile->Close();
}


Kinematics::Kinematics(const Kinematics& v){
			
	f_beamA		= v.f_beamA;
	f_beamZ		= v.f_beamZ;
	f_targetA	= v.f_targetA;
	f_targetZ	= v.f_targetZ;

	f_ejecA		= v.f_ejecA;
	f_ejecZ		= v.f_ejecZ;
	f_recoilA	= v.f_recoilA;
	f_recoilZ	= v.f_recoilZ;

	fEx		= v.fEx;

	f_KE		= v.f_KE;
	f_Ecm		= v.f_Ecm;

	fM[0]		= v.fM[0];
	fM[1]		= v.fM[1];
	fM[2]		= v.fM[2];
	fM[3]		= v.fM[3];

	fQVal		= v.fQVal; 
	fS		= v.fS; 
	fInvariantMass	= v.fInvariantMass;
	fCmTi		= v.fCmTi;
	fCmTf		= v.fCmTf;
	fCmE		= v.fCmE;
	fCmV		= v.fCmV;
	fCmP		= v.fCmP;
	fCmG		= v.fCmG;

	fTCm[0]		= v.fTCm[0];
	fTCm[1]		= v.fTCm[1];
	fTCm[2]		= v.fTCm[2];
	fTCm[3]		= v.fTCm[3];

	fECm[0]		= v.fECm[0];
	fECm[1]		= v.fECm[1];
	fECm[2]		= v.fECm[2];
	fECm[3]		= v.fECm[3];

	fPCm[0]		= v.fPCm[0];
	fPCm[1]		= v.fPCm[1];
	fPCm[2]		= v.fPCm[2];
	fPCm[3]		= v.fPCm[3];

	fVCm[0]		= v.fVCm[0];
	fVCm[1]		= v.fVCm[1];
	fVCm[2]		= v.fVCm[2];
	fVCm[3]		= v.fVCm[3];

	fGCm[0]		= v.fGCm[0];
	fGCm[1]		= v.fGCm[1];
	fGCm[2]		= v.fGCm[2];
	fGCm[3]		= v.fGCm[3];


	fTLab[0]		= v.fTLab[0];
	fTLab[1]		= v.fTLab[1];

	fELab[0]		= v.fELab[0];
	fELab[1]		= v.fELab[1];

	fPLab[0]		= v.fPLab[0];
	fPLab[1]		= v.fPLab[1];

	fVLab[0]		= v.fVLab[0];
	fVLab[1]		= v.fVLab[1];

	fGLab[0]		= v.fGLab[0];
	fGLab[1]		= v.fGLab[1];

	fThetaMax[0]		= v.fThetaMax[0]; 
	fThetaMax[1]		= v.fThetaMax[1]; 
	fThetaMax[2]		= v.fThetaMax[2]; 
	fThetaMax[3]		= v.fThetaMax[3]; 

	fLab_1		= v.fLab_1;
	fLab_2         	= v.fLab_2;
	fLab_3         	= v.fLab_3;
	fLab_4         	= v.fLab_4;
                        
	fCM_1          	= v.fCM_1;
	fCM_2          	= v.fCM_2;
	fCM_3          	= v.fCM_3;
	fCM_4          	= v.fCM_4;
                        
	totalEnergyCM  	= v.totalEnergyCM;
	totalEnergyLab 	= v.totalEnergyLab;
                        
	fLabVec_1      	= v.fLabVec_1;
	fLabVec_2      	= v.fLabVec_2;
	fLabVec_3      	= v.fLabVec_3;
	fLabVec_4      	= v.fLabVec_4;
                        
	fCMVec_1       	= v.fCMVec_1;
	fCMVec_2       	= v.fCMVec_2;
	fCMVec_3       	= v.fCMVec_3;
	fCMVec_4       	= v.fCMVec_4;

}
Kinematics& Kinematics::operator = (const Kinematics& v){
		
	f_beamA		= v.f_beamA;
	f_beamZ		= v.f_beamZ;
	f_targetA	= v.f_targetA;
	f_targetZ	= v.f_targetZ;

	f_ejecA		= v.f_ejecA;
	f_ejecZ		= v.f_ejecZ;
	f_recoilA	= v.f_recoilA;
	f_recoilZ	= v.f_recoilZ;

	fEx		= v.fEx;

	f_KE		= v.f_KE;
	f_Ecm		= v.f_Ecm;

	fM[0]		= v.fM[0];
	fM[1]		= v.fM[1];
	fM[2]		= v.fM[2];
	fM[3]		= v.fM[3];

	fQVal		= v.fQVal; 
	fS		= v.fS; 
	fInvariantMass	= v.fInvariantMass;
	fCmTi		= v.fCmTi;
	fCmTf		= v.fCmTf;
	fCmE		= v.fCmE;
	fCmV		= v.fCmV;
	fCmP		= v.fCmP;
	fCmG		= v.fCmG;

	fTCm[0]		= v.fTCm[0];
	fTCm[1]		= v.fTCm[1];
	fTCm[2]		= v.fTCm[2];
	fTCm[3]		= v.fTCm[3];

	fECm[0]		= v.fECm[0];
	fECm[1]		= v.fECm[1];
	fECm[2]		= v.fECm[2];
	fECm[3]		= v.fECm[3];

	fPCm[0]		= v.fPCm[0];
	fPCm[1]		= v.fPCm[1];
	fPCm[2]		= v.fPCm[2];
	fPCm[3]		= v.fPCm[3];

	fVCm[0]		= v.fVCm[0];
	fVCm[1]		= v.fVCm[1];
	fVCm[2]		= v.fVCm[2];
	fVCm[3]		= v.fVCm[3];

	fGCm[0]		= v.fGCm[0];
	fGCm[1]		= v.fGCm[1];
	fGCm[2]		= v.fGCm[2];
	fGCm[3]		= v.fGCm[3];


	fTLab[0]		= v.fTLab[0];
	fTLab[1]		= v.fTLab[1];

	fELab[0]		= v.fELab[0];
	fELab[1]		= v.fELab[1];

	fPLab[0]		= v.fPLab[0];
	fPLab[1]		= v.fPLab[1];

	fVLab[0]		= v.fVLab[0];
	fVLab[1]		= v.fVLab[1];

	fGLab[0]		= v.fGLab[0];
	fGLab[1]		= v.fGLab[1];

	fThetaMax[0]		= v.fThetaMax[0]; 
	fThetaMax[1]		= v.fThetaMax[1]; 
	fThetaMax[2]		= v.fThetaMax[2]; 
	fThetaMax[3]		= v.fThetaMax[3]; 

	fLab_1		= v.fLab_1;
	fLab_2         	= v.fLab_2;
	fLab_3         	= v.fLab_3;
	fLab_4         	= v.fLab_4;
                        
	fCM_1          	= v.fCM_1;
	fCM_2          	= v.fCM_2;
	fCM_3          	= v.fCM_3;
	fCM_4          	= v.fCM_4;
                        
	totalEnergyCM  	= v.totalEnergyCM;
	totalEnergyLab 	= v.totalEnergyLab;
                        
	fLabVec_1      	= v.fLabVec_1;
	fLabVec_2      	= v.fLabVec_2;
	fLabVec_3      	= v.fLabVec_3;
	fLabVec_4      	= v.fLabVec_4;
                        
	fCMVec_1       	= v.fCMVec_1;
	fCMVec_2       	= v.fCMVec_2;
	fCMVec_3       	= v.fCMVec_3;
	fCMVec_4       	= v.fCMVec_4;

	return *this;

}

void Kinematics::CalculateKinematics(){

	fM[0] 		= 19550.5; //G4IonTable::GetIonTable()->GetIon(f_beamZ,f_beamA,0)->GetPDGMass();
	fM[1]		= 1875.61;//G4IonTable::GetIonTable()->GetIon(f_targetZ,f_targetA,0)->GetPDGMass();
	fM[2]		= 938.272;//G4IonTable::GetIonTable()->GetIon(f_ejecZ,f_ejecA,0)->GetPDGMass();
	fM[3] 		= 20479.7;//G4IonTable::GetIonTable()->GetIon(f_recoilZ,f_recoilA,0)->GetPDGMass() + fEx;
	fM[3]		+= fEx;

	fQVal		= fM[0] + fM[1] - fM[2] - fM[3];

	fS		= pow(fM[0],2) + pow(fM[1],2) + (2 * fM[1] * (f_KE + fM[0]));
	totalEnergyCM	= TLorentzVector(0,0,0,sqrt(fS));
	fCmE		= sqrt(fS) - fM[0] - fM[1];

	fECm[0]		= (fS + pow(fM[0],2) - pow(fM[1],2)) / (2 * sqrt(fS));
	fECm[1]		= (fS + pow(fM[1],2) - pow(fM[0],2)) / (2 * sqrt(fS));
	fECm[2]		= (fS + pow(fM[2],2) - pow(fM[3],2)) / (2 * sqrt(fS));
	fECm[3]		= (fS + pow(fM[3],2) - pow(fM[2],2)) / (2 * sqrt(fS));

	fPCm[0]		= sqrt(pow(fECm[0],2) - pow(fM[0],2));
	fPCm[1]		= sqrt(pow(fECm[1],2) - pow(fM[1],2));
	fPCm[2]		= sqrt(pow(fECm[2],2) - pow(fM[2],2));
	fPCm[3]		= sqrt(pow(fECm[3],2) - pow(fM[3],2));

	fLabVec_1	= TVector3(0,0,sqrt(pow(f_KE,2) + 2 * f_KE * fM[0]));
	fLabVec_2	= TVector3(0,0,0);

	fLab_1		= TLorentzVector(fLabVec_1, fM[0] + f_KE);
	fLab_2		= TLorentzVector(fLabVec_2, fM[1]);

	totalEnergyLab	= fLab_1 + fLab_2;

	fCmV		= totalEnergyLab.Beta();

	fCM_1		= fLab_1;
	fCM_1.Boost(0,0,-fCmV);
	fCM_2		= fLab_2;
	fCM_2.Boost(0,0,-fCmV);


}

double Kinematics::Reconstruct(double energy, double tLab){

	double	E3 	= fM[2] + energy;
	double	pLab3	= sqrt(pow(E3,2) - pow(fM[2],2));

	fLab_3	= TLorentzVector(pLab3 * sin(tLab),0,pLab3 * cos(tLab), E3);
	fLab_4	= totalEnergyLab - fLab_3;

	return	fLab_4.Mag() - 20479.7;

}
