#ifndef PHYSICS_HH
#define PHYSICS_HH
#include <G4VModularPhysicsList.hh>
#include <G4EmStandardPhysics.hh>
#include <G4OpticalPhysics.hh>
class MyPhysicsList : public G4VModularPhysicsList //Inherits publically from G4VModularPhysics
{public:
MyPhysicsList();//constructor
~MyPhysicsList(); //destructor
};
#endif
