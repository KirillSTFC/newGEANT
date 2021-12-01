#include <iostream> //includes standart commands like cout
#include "G4RunManager.hh" // include run library
#include "G4UImanager.hh" //include UI lib
#include "G4VisManager.hh" // include vis li
#include "G4VisExecutive.hh" //include vis lib2
#include "G4UIExecutive.hh" //include ui lib u2
#include "construction.cc" //include detector
#include "physics.cc" //include physics
//#include "action.cc"
//#include "action.hh"
#include "generator.cc"
//#include "detector.hh"
//#include "detector.cc"
//#include "run.hh"
//#include "run.cc"
//#include "event.hh"
//#include "event.cc"
//#include "stepping.hh"
//#include "stepping.cc"
#include "G4MTRunManager.hh"

int main(int argc, char** argv)//This declaration is used when your program must take command-line arguments.
{
//#ifdef G4MULTITHREADED
//G4MTRunManager *run = new G4MTRunManager();
//#else
G4RunManager *run = new G4RunManager(); //Run manager is the heart of geant 4. R4run manager takes care of all run actions, event actions, stepping actions. run is a new name(reference) for a class. Run itself is a CORE, KERNEL.
//#endif
run -> SetNumberOfThreads(8);
	run->SetUserInitialization(new MyDetectorConstruction());//we putting initialization classes to the run class. (setting initizalization).
  run->SetUserInitialization(new MyPhysicsList());
	run->SetUserAction(new MyPrimaryGenerator());
	//run->SetUserInitialization(new MyActionInitialization());
	G4UIExecutive *ui = new G4UIExecutive(argc, argv); //FOR UI. some input parameter i dont know for.
	G4VisManager *visManager = new G4VisExecutive(); //for VIS
	visManager->Initialize();//VIS initialization
	G4UImanager *UImanager = G4UImanager::GetUIpointer();//something for UI
	UImanager->ApplyCommand("/control/execute vis.mac");
	ui->SessionStart(); //Start UI session
return 0;
}
