#include "action.hh"
 MyActionInitialization::MyActionInitialization() //constructor
{}
MyActionInitialization::~MyActionInitialization() //destructor
{}
void MyActionInitialization::BuildForMaster() const //here will be more once we will add more actions.
{}
void MyActionInitialization::Build() const
{
MyPrimaryGenerator *generator = new MyPrimaryGenerator();
SetUserAction(generator);
}
