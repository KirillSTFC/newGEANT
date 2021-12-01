#include "physics.hh"
MyPhysicsList::MyPhysicsList() //call the methods which are using for initialization of different physics
{
	RegisterPhysics (new G4EmStandardPhysics()); //adding physics from package. we will want to build cherenkov detector. so this lib is for EM waves
	RegisterPhysics (new G4OpticalPhysics()); //this lib works with optical photons. dont know what is the difference between this two yet.
}
MyPhysicsList::~MyPhysicsList()
{}
