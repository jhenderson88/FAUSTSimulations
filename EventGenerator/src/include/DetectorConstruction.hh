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
// $Id: B5DetectorConstruction.hh 76474 2013-11-11 10:36:34Z gcosmo $
//
/// \file B5DetectorConstruction.hh
/// \brief Definition of the B5DetectorConstruction class

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4RotationMatrix.hh"
#include "G4FieldManager.hh"
#include "G4Box.hh"
#include "G4Sphere.hh"

#include <vector>


class G4VPhysicalVolume;
class G4Material;
class G4Isotope;
class G4Element;
class G4VSensitiveDetector;
class G4VisAttributes;
class G4GenericMessenger;

/// Detector construction

class DetectorConstruction : public G4VUserDetectorConstruction
{
	public:
	
	    	DetectorConstruction();
	    	virtual ~DetectorConstruction();
	
	    	virtual G4VPhysicalVolume* Construct();

	private:

		virtual void 	DefineMaterials();
		virtual void	DefineMiscGeometry();

		G4String	fMaterial;
		G4String	fDetectorType;
		G4double	fDistance;
		G4double	fThickness;
		G4double	fRadius;
		
	private:
	
	protected:


	// Elements
	private:

	// Materials
	private:
		G4Material	*world_mat;

	// Euler angles and position vectors
	private:

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#endif
