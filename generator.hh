#ifndef GENERATOR_HH
#define GENERATOR_HH
#include "G4VUserPrimaryGeneratorAction.hh"                       //including main generator library.
#include "G4ParticleGun.hh"//including gun library
#include "G4SystemOfUnits.hh"                                     //this class contains system of units (MeV etc)
#include "G4ParticleTable.hh"                                    //This class contains all information about prticles, like mass, charge an so on.
#include "G4GeneralParticleSource.hh"                            //This is particular particle source which we will use, there are therts, like G4ParticleGun.hh
class MyPrimaryGenerator: public G4VUserPrimaryGeneratorAction   //We inherite this from G4VUserPrimaryGeneratorAction abstract class.
{public:
MyPrimaryGenerator(); //constructor
~MyPrimaryGenerator(); //destructor
//************************************************************LIST OF FUNCTIONS (METHODS) IN USE ********************************************//
virtual void GeneratePrimaries(G4Event*); //We will use function GeneratePrimaries, which should have as parameter(argument) G4Event - this is a class.
//*G4Event is a class which represents an event. This class is constructed and
// deleted by G4RunManager (or its derived class). When G4Event object is passed
// to G4EventManager, G4Event must have one or more primary vertexes and primary
// particle(s) associated to the vertex(es) as an input of simulating an event.
// As the consequences of simulating an event, G4Event has trajectories, hits
// collections, and/or digi collections.
//************************************************************LIST OF POINTERS AND VARIABLES IN USE ********************************************//
private:
G4GeneralParticleSource *fParticleGun; //pointer to G4GeneralParticleSource class
//G4ParticleTable *particleTable;       //pointer to ParticleTable class
};


#endif
