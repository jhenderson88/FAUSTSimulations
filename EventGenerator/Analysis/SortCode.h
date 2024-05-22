//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May 21 15:00:34 2024 by ROOT version 6.22/09
// from TTree DataTree/DataTree
// found on file: Data.root
//////////////////////////////////////////////////////////

#ifndef SortCode_h
#define SortCode_h

#include "TLorentzVector.h"
#include "TVector3.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "TMath.h"
#include <iostream>
#include <iomanip>

class SortCode {
public :
	TTree          *fChain;   //!pointer to the analyzed TTree or TChain
	Int_t           fCurrent; //!current Tree number in a TChain

	// Fixed size dimensions of array or collections stored in the TTree if any.

	// Declaration of leaf types
	Double_t        PrimE;
	Double_t        PrimT;
	Double_t        PrimP;
	Double_t        ThetaCM;
	Double_t        Etot;
	vector<double>  *Edep;
	vector<double>  *EdepP;
	vector<double>  *ToF;
	vector<int>     *DetID;
	vector<double>  *Theta;
	vector<double>  *X;
	vector<double>  *Y;
	vector<double>  *Z;
	vector<double>  *R;
	vector<bool>    *DetectorHit;

	// List of branches
	TBranch        *b_PrimE;   //!
	TBranch        *b_PrimT;   //!
	TBranch        *b_PrimP;   //!
	TBranch        *b_ThetaCM;   //!
	TBranch        *b_Etot;   //!
	TBranch        *b_Edep;   //!
	TBranch        *b_EdepP;   //!
	TBranch        *b_ToF;   //!
	TBranch        *b_DetID;   //!
	TBranch        *b_Theta;   //!
	TBranch        *b_X;   //!
	TBranch        *b_Y;   //!
	TBranch        *b_Z;   //!
	TBranch        *b_R;   //!
	TBranch        *b_DetectorHit;   //!

	SortCode(const char*);
	SortCode(TTree *tree=0);
	virtual ~SortCode();
	virtual Int_t    Cut(Long64_t entry);
	virtual Int_t    GetEntry(Long64_t entry);
	virtual Long64_t LoadTree(Long64_t entry);
	virtual void     Init(TTree *tree);
	virtual void     Loop(const char*);
	virtual Bool_t   Notify();
	virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SortCode_cxx

SortCode::SortCode(const char *infilename){
	TFile 	*f = (TFile*)gROOT->GetListOfFiles()->FindObject(infilename);
	TTree	*tree;
	if (!f || !f->IsOpen()) {
		f = new TFile("Data.root");
	}
	f->GetObject("DataTree",tree);
	Init(tree);
}

SortCode::SortCode(TTree *tree) : fChain(0) 
{
	if (tree == 0) {
		TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Data.root");
		if (!f || !f->IsOpen()) {
			f = new TFile("Data.root");
		}
		f->GetObject("DataTree",tree);

	}
	Init(tree);
}

SortCode::~SortCode()
{
	if (!fChain) return;
	delete fChain->GetCurrentFile();
}

Int_t SortCode::GetEntry(Long64_t entry)
{
	if (!fChain) return 0;
	return fChain->GetEntry(entry);
}
Long64_t SortCode::LoadTree(Long64_t entry)
{
	// Set the environment to read one entry
	if (!fChain) 
		return -5;
	Long64_t centry = fChain->LoadTree(entry);
	if (centry < 0) 
		return centry;
	if (fChain->GetTreeNumber() != fCurrent) {
		fCurrent = fChain->GetTreeNumber();
		Notify();
	}
	return centry;
}

void SortCode::Init(TTree *tree)
{
	// The Init() function is called when the selector needs to initialize
	// a new tree or chain. Typically here the branch addresses and branch
	// pointers of the tree will be set.
	// It is normally not necessary to make changes to the generated
	// code, but the routine can be extended by the user if needed.
	// Init() will be called many times when running on PROOF
	// (once per file to be processed).

	// Set object pointer
	Edep = 0;
	EdepP = 0;
	ToF = 0;
	DetID = 0;
	Theta = 0;
	X = 0;
	Y = 0;
	Z = 0;
	R = 0;
	DetectorHit = 0;
	// Set branch addresses and branch pointers
	if (!tree) 
		return;
	fChain = tree;
	fCurrent = -1;
	fChain->SetMakeClass(1);

	fChain->SetBranchAddress("PrimE", &PrimE, &b_PrimE);
	fChain->SetBranchAddress("PrimT", &PrimT, &b_PrimT);
	fChain->SetBranchAddress("PrimP", &PrimP, &b_PrimP);
	fChain->SetBranchAddress("ThetaCM", &ThetaCM, &b_ThetaCM);
	fChain->SetBranchAddress("Etot", &Etot, &b_Etot);
	fChain->SetBranchAddress("Edep", &Edep, &b_Edep);
	fChain->SetBranchAddress("EdepP", &EdepP, &b_EdepP);
	fChain->SetBranchAddress("ToF", &ToF, &b_ToF);
	fChain->SetBranchAddress("DetID", &DetID, &b_DetID);
	fChain->SetBranchAddress("Theta", &Theta, &b_Theta);
	fChain->SetBranchAddress("X", &X, &b_X);
	fChain->SetBranchAddress("Y", &Y, &b_Y);
	fChain->SetBranchAddress("Z", &Z, &b_Z);
	fChain->SetBranchAddress("R", &R, &b_R);
	fChain->SetBranchAddress("DetectorHit", &DetectorHit, &b_DetectorHit);
	Notify();
}

Bool_t SortCode::Notify()
{
	// The Notify() function is called when a new file is opened. This
	// can be either for a new TTree in a TChain or when when a new TTree
	// is started when using PROOF. It is normally not necessary to make changes
	// to the generated code, but the routine can be extended by the
	// user if needed. The return value is currently not used.

	return kTRUE;
}

void SortCode::Show(Long64_t entry)
{
	// Print contents of entry.
	// If entry is not specified, print current entry
	if (!fChain) 
		return;
	fChain->Show(entry);
}
Int_t SortCode::Cut(Long64_t entry)
{
	// This function may be called from Loop.
	// returns  1 if entry is accepted.
	// returns -1 otherwise.
	return 1;
}
#endif 
       

#ifndef Kinematics_h
#define Kinematics_h

// Kinematics code largely based on / duplicated from GRSISort: https://github.com/GRIFFINCollaboration/GRSISort/blob/main/include/TReaction.h

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <tgmath.h>

#ifndef PI
#define PI (3.14159265358979)
#endif

#ifndef R2D
#define R2D (5.72957795130823229e+01)
#endif

#ifndef D2R
#define D2R (1.74532925199432955e-02)
#endif 

class Kinematics {

	public:
		Kinematics()	{;}
		Kinematics(int bA, int bZ, int tA, int tZ, int A, int Z, double Ex = 0, bool eject = true)	{
			fEx		= Ex;
			f_beamA		= bA;
			f_beamZ		= bZ;
			f_targetA	= tA;
			f_targetZ	= tZ;
			if(eject){
				f_ejecA	= A;
				f_ejecZ	= Z;		
				f_recoilA	= f_beamA + f_targetA - f_ejecA;
				f_recoilZ	= f_beamZ + f_targetZ - f_ejecZ;
			}
			else{
				f_recoilA	= A;
				f_recoilZ	= Z;		
				f_ejecA		= f_beamA + f_targetA - f_ejecA;
				f_ejecZ		= f_beamZ + f_targetZ - f_ejecZ;

			}	
		};
		~Kinematics()	{;}

		Kinematics(const Kinematics& );
		Kinematics& operator = (const Kinematics&);

		void	SetReactionEnergy(double e){ 
			f_KE 	= e;
			CalculateKinematics();
		}

		void	CalculateKinematics();

		void	Print(){
			std::cout	<< f_beamA << std::endl;
			std::cout	<< f_beamZ << std::endl;
			std::cout	<< f_targetA << std::endl;
			std::cout	<< f_targetZ << std::endl;
			std::cout	<< f_ejecA << std::endl;
			std::cout	<< f_ejecZ << std::endl;
			std::cout	<< f_recoilA << std::endl;
			std::cout	<< f_recoilZ << std::endl;

		}

		double	Reconstruct(double,double);

		double GetExcEnergy(double ekin = 0.00, double theta_lab = 0.00, int part = 2);

	private:
			
		int	f_beamA;
		int	f_beamZ;
		int	f_targetA;
		int	f_targetZ;

		int	f_ejecA;
		int	f_ejecZ;
		int	f_recoilA;
		int	f_recoilZ;

		double	f_KE;
		double	f_Ecm;

		double	fEx;

		double	fM[4];

		// CM FRAME MOTION
		double fQVal; // effective Q value (includes excitation)
		double fS;  // 'S' = M^2
		double fInvariantMass;
		double fCmTi;
		double fCmTf;
		double fCmE;
		double fCmV;
		double fCmP;
		double fCmG;

		// PARTICLES IN CM FRAME
		double fTCm[4];
		double fECm[4];
		double fPCm[4];
		double fVCm[4];
		double fGCm[4];

		// PARTICLE IN LAB FRAME
		// Note that in the lab frame only the initial state (beam/targ) is fixed in the reaction
		double fTLab[2];
		double fELab[2];
		double fPLab[2];
		double fVLab[2];
		double fGLab[2];
		double fThetaMax[4]; // only nonzero for ejectile and recoil

		TLorentzVector	fLab_1;
		TLorentzVector	fLab_2;
		TLorentzVector	fLab_3;
		TLorentzVector	fLab_4;

		TLorentzVector	fCM_1;
		TLorentzVector	fCM_2;
		TLorentzVector	fCM_3;
		TLorentzVector	fCM_4;

		TLorentzVector	totalEnergyCM;
		TLorentzVector	totalEnergyLab;

		TVector3	fLabVec_1;
		TVector3	fLabVec_2;
		TVector3	fLabVec_3;
		TVector3	fLabVec_4;

		TVector3	fCMVec_1;
		TVector3	fCMVec_2;
		TVector3	fCMVec_3;
		TVector3	fCMVec_4;
		

};

#endif
