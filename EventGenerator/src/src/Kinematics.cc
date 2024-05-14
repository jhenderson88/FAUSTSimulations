#include "Kinematics.hh"

Kinematics::Kinematics(const Kinematics& v){
			
	f_beamA		= v.f_beamA;
	f_beamZ		= v.f_beamZ;
	f_targetA	= v.f_targetA;
	f_targetZ	= v.f_targetZ;
	f_beamM		= v.f_beamM;
	f_targetM	= v.f_targetM;

	f_ejecA		= v.f_ejecA;
	f_ejecZ		= v.f_ejecZ;
	f_recoilA	= v.f_recoilA;
	f_recoilZ	= v.f_recoilZ;
	f_recoilM	= v.f_recoilM;
	f_ejecM		= v.f_ejecM;

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

}
Kinematics& Kinematics::operator = (const Kinematics& v){
		
	f_beamA		= v.f_beamA;
	f_beamZ		= v.f_beamZ;
	f_targetA	= v.f_targetA;
	f_targetZ	= v.f_targetZ;
	f_beamM		= v.f_beamM;
	f_targetM	= v.f_targetM;

	f_ejecA		= v.f_ejecA;
	f_ejecZ		= v.f_ejecZ;
	f_recoilA	= v.f_recoilA;
	f_recoilZ	= v.f_recoilZ;
	f_recoilM	= v.f_recoilM;
	f_ejecM		= v.f_ejecM;

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

	return *this;

}

void Kinematics::CalculateKinematics(double Ex){

	fM[0] 		= G4IonTable::GetIonTable()->GetIon(f_beamZ,f_beamA,0)->GetPDGMass();
	fM[1]		= G4IonTable::GetIonTable()->GetIon(f_targetZ,f_targetA,0)->GetPDGMass();
	fM[2]		= G4IonTable::GetIonTable()->GetIon(f_ejecZ,f_ejecA,0)->GetPDGMass();
	fM[3] 		= G4IonTable::GetIonTable()->GetIon(f_recoilZ,f_recoilA,0)->GetPDGMass();

	fQVal		= fM[0] + fM[1] - fM[2] - fM[3] - Ex;
	double	fEx	= Ex;

	fTLab[0]	= f_KE;
       	fELab[0]	= fTLab[0] + fM[0];
	fPLab[0]	= sqrt(pow(fTLab[0],2) + 2 * fTLab[0] * fM[0]);
	fVLab[0]	= fPLab[0] / fELab[0];
	fGLab[0]	= 1 / sqrt(1 - pow(fVLab[0],2));	

	fTLab[1]	= 0;
       	fELab[1]	= fM[1];
	fPLab[1]	= 0; 
	fVLab[1]	= 0;
	fGLab[1]	= 1;

	fS		= pow(fM[0],2) + pow(fM[1],2) + 2 * fELab[0] * fM[1];
	fInvariantMass	= sqrt(fS);

	fCmE		= fInvariantMass;

	fCmTi		= fCmE - fM[0] - fM[1];
	fCmTf		= fCmTi + fQVal;
	fCmV		= fPLab[0] / (fELab[0] + fM[1]);
	fCmP		= fCmV * fCmE;
	fCmG		= 1 / sqrt(1 - pow(fCmV,2));

	fPCm[0]		= sqrt((fS - pow(fM[0] - fM[1],2)) * (fS - pow(fM[0] + fM[1],2))) / (2 * sqrt(fS));
	fPCm[1]		= fPCm[0];
	fPCm[2]		= sqrt((fS - pow(Ex + fM[2] - fM[3],2)) * (fS - pow(Ex + fM[2] + fM[3],2))) / (2 * sqrt(fS));
	fPCm[3]		= fPCm[2];

	for(int i=0;i<4;i++){
		fECm[i]		= sqrt(pow(fM[i],2) + pow(fPCm[i],2));
		fTCm[i]		= fECm[i] - fM[i];
		fVCm[i]		= fPCm[i] / fECm[i];
		fGCm[i]		= 1. / sqrt(1. - pow(fVCm[i],2));

		if(i < 2){
			fThetaMax[i]	= 0;
		}
		else{
			double	val = fPCm[i] / (fM[i] * fCmV * fCmG);
			if(val < 1)
				fThetaMax[i] 	= asin(val);
			else if(val < 1.00001)
				fThetaMax[i]	= PI / 2.;
			else
				fThetaMax[i]	= PI;
		}

	}

}

CalcVertex Kinematics::CreateVertex(double tCm){

	CalcVertex	vert;

	vert.SetEjecKinE(fCmG * (fECm[2] - fCmV * fPCm[2] * cos(tCm)) - fM[2]);
	vert.SetRecoilKinE(fCmG * (fECm[3] - fCmV * fPCm[3] * cos(tCm)) - fM[3]);

	double	theta_cm = PI - tCm;
	double	theta_lab;

	theta_lab = atan2(sin(theta_cm),fCmG * (cos(theta_cm) + fCmV / fVCm[2]));

	if(theta_lab > fThetaMax[2])
		theta_lab = fThetaMax[2];
	vert.SetEjecTheta(theta_lab);
	theta_lab = atan2(sin(theta_cm),fCmG * (cos(theta_cm) + fCmV / fVCm[3]));
	if(theta_lab > fThetaMax[3])
		theta_lab = fThetaMax[3];
	vert.SetRecoilTheta(theta_lab);

	return vert;

}
