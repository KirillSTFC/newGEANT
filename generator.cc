#include "generator.hh"
MyPrimaryGenerator::MyPrimaryGenerator()              //constructor
{fParticleGun = new G4GeneralParticleSource; //enheritance from G4GeneralParticleSource class
}
MyPrimaryGenerator::~MyPrimaryGenerator()
{delete fParticleGun;}                                             //In destructor we should delete old particle source, to launch a new one i think
void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent) //now we filling the class body
{
fParticleGun->GeneratePrimaryVertex(anEvent); //Setting up association between GPS source and primary generator. i.e. via anEvent pointer we pointed that we want to generate this particular event.
//we can pass another pointers there with different parameters. as i understand, when macro file updates with new gps parameters - this update goes via anEvent pointer.
}
//*G4Event is a class which represents an event. This class is constructed and
// deleted by G4RunManager (or its derived class). When G4Event object is passed
// to G4EventManager, G4Event must have one or more primary vertexes and primary
// particle(s) associated to the vertex(es) as an input of simulating an event.
// As the consequences of simulating an event, G4Event has trajectories, hits
// collections, and/or digi collections.
