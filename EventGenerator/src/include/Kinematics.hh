#ifndef Kinematics_h
#define Kinematics_h

// Kinematics code largely based on / duplicated from GRSISort: https://github.com/GRIFFINCollaboration/GRSISort/blob/main/include/TReaction.h

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <tgmath.h>
#include "G4IonTable.hh"

#include "CalcVertex.hh"

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
		Kinematics(double bA, double bZ, double tA, double tZ, double A, double Z, bool eject = true)	{
			f_beamA		= bA;
			f_beamZ		= bZ;
			f_targetA	= tA;
			f_targetZ	= tZ;
//			f_beamM		= mass[beamZ][beamA];
//			f_targetM	= mass[targetZ][targetA];
			f_beamM		= f_beamA;
			f_targetM	= f_targetA;
			if(eject){
				f_ejecA	= A;
				f_ejecZ	= Z;		
				f_recoilA	= f_beamA + f_targetA - f_ejecA;
				f_recoilZ	= f_beamZ + f_targetZ - f_ejecZ;
				f_ejecM		= f_ejecA;
				f_recoilM	= f_recoilA;
//				f_ejecM		= mass[f_ejecZ][f_ejecA];
//				f_recoilM	= mass[f_recoilZ][f_recoilA];
			}
			else{
				f_recoilA	= A;
				f_recoilZ	= Z;		
				f_ejecA		= f_beamA + f_targetA - f_ejecA;
				f_ejecZ		= f_beamZ + f_targetZ - f_ejecZ;
				f_ejecM		= f_ejecA;
				f_recoilM	= f_recoilA;
//				f_ejecM		= mass[f_ejecZ][f_ejecA];
//				f_recoilM	= mass[recoilZ][recoilA];

			}	
		};
		~Kinematics()	{;}

		Kinematics(const Kinematics& );
		Kinematics& operator = (const Kinematics&);

		void	SetReactionEnergy(double e){ 
			f_KE 	= e;	
			f_Ecm	= e * (f_targetM / (f_targetM + f_beamM));
		}

		void	CalculateKinematics(double Ex=0);

		CalcVertex	CreateVertex(double tCm);

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

	private:
			
		double	f_beamA;
		double	f_beamZ;
		double	f_targetA;
		double	f_targetZ;
		double	f_beamM;
		double	f_targetM;

		double	f_ejecA;
		double	f_ejecZ;
		double	f_recoilA;
		double	f_recoilZ;
		double	f_recoilM;
		double	f_ejecM;

		double	f_KE;
		double	f_Ecm;

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
		

};

#endif
