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

// ===========================================================================
//                               Static Attributes
// ===========================================================================


unsigned int Agent::PERCEPTION = 0;
unsigned int Agent::CONTACT = 0;


// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================
void test_getters_agent(Agent& my_test_agent);




// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  printf("Hello World !\n");

  Agent* Agent_1 = new Agent();
  
  //test des getters sur Agent
  test_getters_agent(*Agent_1);

  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

void test_getters_agent(Agent& my_test_agent){
	printf("Posx %ld \n", my_test_agent.Get_posX());
	printf("Posy%ld \n", my_test_agent.Get_posY());
	
	printf("Spx %ld \n", my_test_agent.Get_spX());
	printf("Spy %ld \n", my_test_agent.Get_spY());

	printf("y1 %ld \n", my_test_agent.Get_y1());
	printf("y2 %ld \n", my_test_agent.Get_y2());
    printf("y3 %ld \n", my_test_agent.Get_y3());

    printf("Perception %ld \n", my_test_agent.Get_Perception());
    printf("Contact %ld \n", my_test_agent.Get_Contact());

}