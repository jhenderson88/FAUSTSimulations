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
// $Id: B5DetectorConstruction.cc 77656 2013-11-27 08:52:57Z gcosmo $
//
/// \file B5DetectorConstruction.cc
/// \brief Implementation of the B5DetectorConstruction class


#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4Tubs.hh"
#include "G4VSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//#include "G4GDMLParser.hh"

#include "DetectorConstruction.hh"
    
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
: 	G4VUserDetectorConstruction()
{
 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{

	DefineMiscGeometry();
	DefineMaterials();

	// Envelope parameters
	//
	G4double env_sizeXY = 1*m, env_sizeZ = 1*m;

	//     
	// World
	//
	G4double world_sizeXY = 1.2*env_sizeXY;
	G4double world_sizeZ  = 1.2*env_sizeZ;

	// Option to switch on/off checking of volumes overlaps
	//
	G4bool checkOverlaps = true;
	
  	G4Box	*solidWorld =    
    		new G4Box("World",                       //its name
	       	0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size
      
  	G4LogicalVolume	*logicWorld =                         
    		new G4LogicalVolume(solidWorld,         //its solid
                world_mat,           		 	//its material
                "World");  			        //its name
                                   
  	G4VPhysicalVolume	*physWorld
    		= new G4PVPlacement(0,          //no rotation
                G4ThreeVector(),       		//at (0,0,0)
                logicWorld,            		//its logical volume
                "World",               		//its name
                0,                     		//its mother  volume
                false,                 		//no boolean operation
                0,                     		//copy number
                checkOverlaps);        		//overlaps checking

	G4Box *box;
	G4Tubs	*tub1, *tub2;


	// Get nist material manager
	G4NistManager* nist = G4NistManager::Instance();
	G4Material *si = nist->FindOrBuildMaterial("G4_Si");	
	G4Material *csi = nist->FindOrBuildMaterial("G4_CESIUM_IODIDE");	

	tub1		= new G4Tubs("Detector_1",
			40 * mm,
			40.2 * mm,
			4. * cm,
			0,
			360 * degree);

	tub2		= new G4Tubs("Detector_2",
			41 * mm,
			45 * mm,
			4. * cm,
			0,
			360 * degree);

	G4LogicalVolume	*si_log		= new G4LogicalVolume(
//			box,
			tub1,
			si,
			"Detector_1");

	G4LogicalVolume	*csi_log	= new G4LogicalVolume(
//			box,
			tub2,
			csi,
			"Detector_2");
	
	new G4PVPlacement(0,
			G4ThreeVector(0,0,0 * cm),
			si_log,
			"Detector_1",
			logicWorld,
			false,
			0);  	
	
	new G4PVPlacement(0,
			G4ThreeVector(0,0,0 * cm),
			csi_log,
			"Detector_2",
			logicWorld,
			false,
			0);  	

  	return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::DefineMaterials(){

	// Get nist material manager
	G4NistManager* nist = G4NistManager::Instance();

	world_mat = nist->FindOrBuildMaterial("G4_Galactic");

}


void DetectorConstruction::DefineMiscGeometry(){

}
