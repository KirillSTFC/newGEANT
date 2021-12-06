#include  "run.hh"
MyRunAction::MyRunAction()
{G4AnalysisManager *man = G4AnalysisManager::Instance();
  //man->SetNtupleMerging(true);
  G4cout<<"AAAAAAAAAAAAAAAAAA"<<G4endl;
  man->CreateNtuple("Photons","Photons"); //These are RAWS which we created.
  man->CreateNtupleIColumn("fEvent");   //These will create COLUMS. I stands for integer. First column will be a number of EVENT. As i understand a number of cases when particle hits our detector array.
  man->CreateNtupleDColumn("fX");
  man->CreateNtupleDColumn("fY");
  man->CreateNtupleDColumn("fZ"); //position of the detector
  man->CreateNtupleFColumn("E2");
  man->CreateNtupleDColumn("Edep");
  man->FinishNtuple(0);
}
MyRunAction::~MyRunAction()
{delete G4AnalysisManager::Instance();}
char fileName[65];
void MyRunAction::BeginOfRunAction(const G4Run*)//this is just a frame and we will write here whatt information we want to store in our output file. We should think do we want to create a file as soon as we run a program? in the constructor above^, or may be we should create it new for every run.
{
G4AnalysisManager *man = G4AnalysisManager::Instance(); //so here what happens is we called an analysis manager during our RUN process. and created a root. and now trying to fill it up.

G4int a = G4RunManager::GetRunManager()->GetCurrentRun()->GetRunID();
sprintf(fileName, "Energy%d",a); //The name for the file will be according to Scan we want to implement and the number of simulation. For example: Energy01, Energy02. Then it is easy to read it all together by something eternal.
man->OpenFile(G4String(fileName)); //Creating a file
}
void MyRunAction::EndOfRunAction(const G4Run*)
{
G4AnalysisManager *man = G4AnalysisManager::Instance();

man->Write(); //we should write file before we close it, otherwise it can be damaged.
man->CloseFile(G4String(fileName)); //we nead to close stream with this file

}
