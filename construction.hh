#ifndef CONSTRUCTION_HH //make sure not to use it several times
#define CONSTRUCTION_HH //define
//******************************************************************LIST OF CLASSES IN USE *****************************************************//
#include <G4SystemOfUnits.hh>               //include system of units. we can use meters, gigaelectron volts, degrees, etc
#include <G4VUserDetectorConstruction.hh>  //abstract class existing only to be filled with another class. (this one - which we creating)
#include <G4VPhysicalVolume.hh>            //The world physical volume represents all out geometry setup. Here
#include <G4Box.hh>												// this is class for rectangular discription
#include <G4PVPlacement.hh>								//this class fr location sicription
#include <G4NistManager.hh>								//this class for material properties discription
#include <G4LogicalVolume.hh>							//this class for world structure discription
//#include "detector.hh"										//this is to connect it with sensitive detector, where we will fill the root files
#include "G4GenericMessenger.hh"					//this is to use variables in macro file later
class MyDetectorConstruction : public G4VUserDetectorConstruction //We inherite it from G4VUserDetectorConstruction abstract class.
{
public:
//************************************************************LIST OF FUNCTIONS (METHODS) IN USE ********************************************//
	MyDetectorConstruction(); //constructor
	~MyDetectorConstruction(); //destructor
G4LogicalVolume *GetScoringVolume() const {return fScoringVolume;} 	//this method should return a pointer of a scoringvolume. This is basically the same as the one bellow and we initialized return in brackets here.
	virtual G4VPhysicalVolume* Construct(); 													// This method should return a pointer of PhysicalWorld
	//virtual void ConstructSDandField();   														//SOME SPECIFIC FOR SENSITIVE DETECTOR OR MULTITHREADING, I AM NOT SURE
	void DefineMaterials(); //this is here because we declared this function in cc file. This is needed for loops and rewriting geometry without errors

//********************************************************LIST OF POINTERS AND VARIABLES IN USE ********************************************//
G4double LeadThick;																									//This is variable to control thickness and use it in macro file
G4GenericMessenger *fMessenger;  																		//this is pointer to use genericmessenger (also to control thickness and use it in macro file)
G4Box *solidWorld, *lead_v;																					//these are pointers to control shape of the world and target in G4Box class
G4LogicalVolume   *logicWorld, *logicDetector, *fScoringVolume; 		//this are pointers to control logical structure of world, detector and scoring volume in G4LogicalVolume class. in our case detector and scoring volume is kind of a same thing.
G4VPhysicalVolume *physWorld,  *lead_phys;													//these are pointers to control physical volume in G4VPhysicalVolume class
G4Material *worldMat, *lead_mat;																		// these are pointers to control world material (vacuum) and target material (lead).
};

#endif
