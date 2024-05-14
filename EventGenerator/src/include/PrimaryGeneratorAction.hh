//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: B1PrimaryGeneratorAction.hh 90623 2015-06-05 09:24:30Z gcosmo $
//
/// \file B1PrimaryGeneratorAction.hh
/// \brief Definition of the B1PrimaryGeneratorAction class

#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "PrimaryGeneratorMessenger.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"
#include "globals.hh"
#include "CalcVertex.hh"
#include "Kinematics.hh"
#include <chrono>

class G4ParticleGun;
class G4GeneralParticleSource;
class G4Event;
class G4Box;
class PrimaryGeneratorMessenger;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
	public:
		PrimaryGeneratorAction();    
		virtual ~PrimaryGeneratorAction();

		PrimaryGeneratorMessenger	*messenger;

		// method from the base class
		virtual void GeneratePrimaries(G4Event*);         

		// method to access particle gun
		const G4ParticleGun* 		GetParticleGun() 	const { return fParticleGun; }
		const G4GeneralParticleSource* 	GetParticleSource() 	const { return fParticleSource; }

		double	GetParticleEnergy()	const	{
			return 	eEnergy;
		}	
		double	GetParticleTheta()	const	{
			return 	eTheta;
		}
		double	GetParticlePhi()	const	{
			return 	ePhi;
		}

		void	SetBeamSpotSize(double bs)	{ beamSpotSize		= bs;	}
		void	SetBeamEnergy(double e)		{ beamEnergy		= e;	}
		void	SetBeamEnergyLoss(double el)	{ beamEnergyLoss	= el;	}

		void	SetBeamA(int a)			{ beamA			= a;	}
		void	SetBeamZ(int z)			{ beamZ			= z;	}
		void	SetTargetA(int a)		{ targetA		= a;	}
		void	SetTargetZ(int z)		{ targetZ		= z;	}
		void	SetEjectileA(int a)		{ ejectileA		= a;	}
		void	SetEjectileZ(int z)		{ ejectileZ		= z;	}

		void	SetExcitationEnergy(int e)	{ ExcE			= e;	}

	private:
		G4ParticleGun*  		fParticleGun; // pointer a to G4 gun class
		G4GeneralParticleSource*  	fParticleSource; // pointer a to G4 gun class
		Kinematics			fKin;
		CalcVertex			vert;

		double	rEnergy;
		double	rTheta;
		double	rPhi;
		double	eEnergy;
		double	eTheta;
		double	ePhi;

		double	beamSpotSize;
		double	beamEnergy;
		double	beamEnergyLoss;

		double	ExcE;

		int	beamA;
		int	beamZ;
		int	targetA;
		int	targetZ;
		int	ejectileA;
		int	ejectileZ;

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
