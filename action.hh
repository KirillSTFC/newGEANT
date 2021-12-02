#ifndef ACTION_HH
#define ACTION_HH
#include "G4VUserActionInitialization.hh"
#include "generator.hh"
class MyActionInitialization : public G4VUserActionInitialization //my action is inhereted from this library called G4VUserActionInitialization
{
public:
MyActionInitialization(); //constructor
~MyActionInitialization(); //destructor
//************************************************************LIST OF FUNCTIONS (METHODS) IN USE ********************************************//
virtual void Build() const; //We using this function Build from the ActionInitialization class. It is runs the particle gun, computes stepping and so on. We can say that it is a main function of our programm. We can create it as constant.
virtual void BuildForMaster() const; //multithreading. The above is for master thread. and this one is for worker thread.
};


#endif
