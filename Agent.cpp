//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Agent.h"




//############################################################################
//                                                                           #
//                           Class Template_class                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Agent::Agent(void)
{
	y1=0;
	y2=0;
	y3=0;

    PERCEPTION = 0;
    CONTACT = 0;
    index =NULL;

	pos= new Vect();
	speed= new Vect();

	next_pos= new Vect();
	next_speed= new Vect();
}

Agent::Agent(int index_to_give) {
	y1=1;
	y2=1;
	y3=1;

    PERCEPTION = 1 ;
    CONTACT = 1;

    index=index_to_give;

	pos= new Vect();
	speed= new Vect();

	next_pos= new Vect();
	next_speed= new Vect();

}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Agent::~Agent(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
void Agent:: next_pos_calc(double dt){
	next_pos->x= pos->x + dt*speed->x;
	next_pos->y= pos->y + dt*speed->y;
	next_pos->Set_Norm();
}

int Agent:: get_K (Agent* tab, int nb_agent) {
	int K=0;

	for(int i=0; i< index; i++) {
		Agent my_agent= tab[i];
		Vect my_vect= my_agent.pos;

		int new_x= my_agent->x;
		int new_y=my_agent->y;

	    new_x= x- new_x;
	    new_y= y- new_y;

	    Vect vect_to_test= new Vect(new_x, new_y);

	    if( vect_to_test.Get_Norm() < PERCEPTION){
	    	K++;
	    }
    }

	for(int i=index+1; i<nb_agent; i++) {
		Agent my_agent= tab[i];
		Vect my_vect= my_agent.pos;

		int new_x= my_agent->x;
		int new_y=my_agent->y;

	    new_x= x- new_x;
	    new_y= y- new_y;

	    Vect vect_to_test= new Vect(new_x, new_y);

	    if( vect_to_test.Get_Norm() < PERCEPTION){
	    	K++;
	    }
	}

	return K;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
