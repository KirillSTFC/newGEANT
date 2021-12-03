#ifndef DETECTOR_HH
#define DETECTOR_HH
#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
class MySensitiveDetector : public G4VSensitiveDetector
{public:
 MySensitiveDetector(G4String);
~MySensitiveDetector();
//************************************************************LIST OF FUNCTIONS (METHODS) IN USE ********************************************//
using G4VSensitiveDetector::ProcessHits; //Here i fixed the warning Woverloaded-virtual. https://stackoverflow.com/questions/16505092/confused-about-virtual-overloaded-functions
virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
};
#endif
