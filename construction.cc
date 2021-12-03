	#include "construction.hh"
	//******************************************************************CONSTRUCTOR*****************************************************//
	// here we declaring variable which will be used in macro file. in our case name of the variable is LeadThick. We define it via G4GenericMessenger class.
MyDetectorConstruction::MyDetectorConstruction()
{fMessenger = new G4GenericMessenger (this, "/detector/", "Detector Construction");
fMessenger->DeclareProperty("LeadThick", LeadThick, "lead thickness") ;
LeadThick = 100;
DefineMaterials();}
	//******************************************************************DESTRUCTOR*****************************************************//
MyDetectorConstruction::~MyDetectorConstruction()				//call destructor
{}
//************************************************************DEFINE MATERIALS FUNCTION*****************************************************//
// here we define materials which will be used in this world. it can be done inside main part, but we will rewrite the geometry several times and for some reason it should be initialized as a separate function, otherwise there will be bugs.
void MyDetectorConstruction::DefineMaterials()
{G4NistManager*nist = G4NistManager::Instance();  				//in NIST manager there are parameter predefined for different materials. :: - is to define constructor ouside the class. that what we
lead_mat = nist->FindOrBuildMaterial("G4_Pb");   					//we found lead
worldMat = nist -> FindOrBuildMaterial("G4_Galactic");  //we found vacuum
}
//************************************************************ CONSTRUCT FUNCTION - BUILDING A DESCRIPTION OF THE PHYSiCAL WORLD and return physWorld which will be used during initialization*****************************************************//
G4VPhysicalVolume* MyDetectorConstruction::Construct() //call again.
{
//VACUUM BOX:
solidWorld   = new G4Box("solidWorld",1*m,1*m,1.5*m);//Box is the class to create a volume. Every volume which we create in G4 has to contain 3 parts: 1 is the solid - which defines the size, then we need a Logicalvolume that includes a material, then we need physical volume which creates object and give him option for rotation, translation(position it seems). 0.5,0.5,0.5 - iit is the half size in x,y,z directions.
logicWorld = new G4LogicalVolume (solidWorld, worldMat, "logicWorld"); // we have put here volume, material and gave it a name - logicWorld.
physWorld = new G4PVPlacement (0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false,0, true);  //it is positioning as i understant. First parameter is always rotation,in our case it is 0. Second is position - and position is defined by the class G4TreeVector. in our case position is in centre - 0,0,0. The we put a logic volume - logicWorld. Then we giving a name for this construction. Then we can define wether is is a main (mother) volume or not. Volumes should not overlap. false is for some kind of boolean operations. Next 0 - is a copy number for several logical volumes. Nextr true - is the question wether it should check for overlaps. we should keep it yes to have a warning.
//LEAD BOX WHICH IS ALSO DETECTO (WE PLANNING TO LOOK FOR ACTIVATION INSIDE IT):
float det_thick=10000;
lead_v= new G4Box("lead_v", det_thick*um , det_thick*um, LeadThick*um);
logicDetector = new G4LogicalVolume(lead_v, lead_mat,"lead");//volume, material, name.
fScoringVolume = logicDetector;
lead_phys = new G4PVPlacement (0,G4ThreeVector(0,0,0),logicDetector,"lead_phys",logicWorld,false,0, false);
return physWorld; // we must return highest mother volume.
}
//************************************************************SOME SPECIFIC FUNCTION FOR SENSITIVE DETECTOR OR MULTITHREADING, I AM NOT SURE*****************************************************//
void MyDetectorConstruction::ConstructSDandField()
{MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");//this is object of sensitive class
logicDetector->SetSensitiveDetector(sensDet);}
