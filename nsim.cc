#include <iostream> //includes standart commands like cout
#include "G4RunManager.hh" // include run library
#include "G4UImanager.hh" //include UI lib
#include "G4VisManager.hh" // include vis li
#include "G4VisExecutive.hh" //include vis lib2
#include "G4UIExecutive.hh" //include ui lib u2
#include "construction.cc" //include detector
#include "physics.cc" //include physics
#include "action.cc"
//#include "action.hh"
#include "generator.cc"
//#include "detector.hh"
#include "detector.cc"
//#include "run.hh"
#include "run.cc"
//#include "event.hh"
//#include "event.cc"
//#include "stepping.hh"
//#include "stepping.cc"
#include "G4MTRunManager.hh"

int main(int argc, char** argv)//This declaration is used when your program must take command-line arguments.
{
G4MTRunManager *run = new G4MTRunManager();
run -> SetNumberOfThreads(8);
run->SetUserInitialization(new MyDetectorConstruction());//we putting initialization classes to the run class. (setting initizalization).
run->SetUserInitialization(new MyPhysicsList());
run->SetUserInitialization(new MyActionInitialization());
run->Initialize();
G4UIExecutive *ui = new G4UIExecutive(argc, argv); //FOR UI. some input parameter i dont know for.
G4VisManager *visManager = new G4VisExecutive(); //for VIS
visManager->Initialize();//VIS initialization
G4UImanager *UImanager = G4UImanager::GetUIpointer();//something for UI
//UImanager->ApplyCommand("/control/execute vis.mac");
UImanager->ApplyCommand("/control/foreach vis.mac thick 1 25 50 75 100");
ui->SessionStart(); //Start UI session
return 0;
}
