#ifndef RUN_HH
#define RUN_HH
#include  "G4Run.hh"
#include  "G4RunManager.hh" //this class we need because here stored information about run number. we need it to create files with different name for different runs
#include "G4UserRunAction.hh"
#include "g4root.hh" //this class is for working with root
class MyRunAction :public G4UserRunAction
{
public:
 MyRunAction();
~MyRunAction();
virtual void BeginOfRunAction(const G4Run*);
virtual void EndOfRunAction(const G4Run*);
};
#endif
