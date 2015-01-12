//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <stdio.h>


// ===========================================================================
//                             Include Project Files
// ===========================================================================
#include "Agent.h"
#include "Vect.h"
#include "Prey.h"
#include "Predator.h"
//#include "Area.h"
// ===========================================================================
//                               Static Attributes
// ===========================================================================





// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================




// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  printf("Hello World !\n");

  Agent* Agent_1 = new Agent();
  printf("\nAgent 1\n");
  Agent_1->Print_Vect();

  Agent* Agent_2 = new Agent(50,50,50);
  printf("\nAgent 2\n");
  Agent_2->Print_Vect();

  Prey* Prey_1= new Prey();
  printf("\nProie 1\n");
  Prey_1->Print_Vect_Prey();

  Prey* Prey_2 = new Prey(12,12,12,12,12,12);
  printf("\nProie 2\n");
  Prey_2->Print_Vect_Prey();

  Predator* Predator_1= new Predator (20,20);
  printf("\nPredator 1\n");
  Predator_1->Print_Vect_Predator();
  
  Prey* Prey_3= new Prey(*Prey_2, 5);
  printf("\nProie 3\n");
  Prey_3->Print_Vect_Prey();

  Predator* Predator_2= new Predator (*Predator_1,1);
  printf("\nPredator 2\n");
  Predator_2->Print_Vect_Predator();

  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

