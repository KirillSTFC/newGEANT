#include "action.hh"
 MyActionInitialization::MyActionInitialization() //constructor
{}
MyActionInitialization::~MyActionInitialization() //destructor
{}
void MyActionInitialization::BuildForMaster() const //here will be more once we will add more actions.
{
  MyRunAction *runAction = new MyRunAction();
  SetUserAction(runAction);
}
void MyActionInitialization::Build() const
{
MyPrimaryGenerator *generator = new MyPrimaryGenerator();
SetUserAction(generator);
MyRunAction *runAction = new MyRunAction();
SetUserAction(runAction); //We dont use any default RUN action from geant4 libs, but we implemented our own.
}
