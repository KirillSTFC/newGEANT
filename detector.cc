#include "detector.hh"
MySensitiveDetector::MySensitiveDetector(G4String name): G4VSensitiveDetector(name)
{}
MySensitiveDetector::~MySensitiveDetector()
{}
G4bool MySensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory *) //aStep is the variable for each step
{
  G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID(); //we can get event number from this classes and function.
G4ThreeVector posPhoton = aStep->GetPreStepPoint()->GetPosition();          // photon position
G4double finalEnergy = aStep->GetPostStepPoint()->GetKineticEnergy();       // energy of the photon
G4double Edep = aStep->GetTotalEnergyDeposit();                             //energy deposited by the photon
G4AnalysisManager *man = G4AnalysisManager::Instance();

man -> FillNtupleIColumn(0,0,evt);           //filling arrays
man -> FillNtupleDColumn(0,1,posPhoton[0]); //detector position will give us x,y,z.
man -> FillNtupleDColumn(0,2,posPhoton[1]);
man -> FillNtupleDColumn(0,3,posPhoton[2]);
man->FillNtupleFColumn(0,4, finalEnergy);  //energy of the photon
man->FillNtupleDColumn(0,5, Edep);        //energy deposited by the photon
man->AddNtupleRow(0);
return true;
}
