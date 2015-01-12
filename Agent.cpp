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
	PERCEPTION = 0;
    CONTACT = 0;
    index =0;

	pos= new Vect();
	speed= new Vect();

	next_pos= new Vect();
	next_speed= new Vect();
}

Agent::Agent(int index_to_give, int perception, int contact) {
	
    PERCEPTION = perception ;
    CONTACT = contact;

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
/*void Agent:: next_pos_calc(double dt){
	next_pos->x= pos->x + dt*speed->x;
	next_pos->y= pos->y + dt*speed->y;
	next_pos->Set_Norm();
}

/*int Agent:: get_K (Agent* tab, int nb_agent) {
	int K=0;

	for(int i=0; i< index; i++) {
		Agent my_agent= tab[i];
		Vect* my_vect= my_agent.pos;

		int new_x= my_vect->x;
		int new_y=my_vect->y;

	    new_x= this->pos->x - new_x;
	    new_y= this->pos->y - new_y;

	    Vect* vect_to_test= new Vect(new_x, new_y);

	    if( vect_to_test->Get_Norm() < (double)(PERCEPTION)){
	    	K++;
	    }
    }

	for(int i=index+1; i<nb_agent; i++) {
		Agent my_agent= tab[i];
		Vect* my_vect= my_agent.pos;

		int new_x= my_vect->x;
		int new_y=my_vect->y;

	    new_x= this->pos->x - new_x;
	    new_y= this->pos->y - new_y;

	    Vect* vect_to_test= new Vect(new_x, new_y);

	    if( vect_to_test->Get_Norm() <(double)(PERCEPTION)){
	    	K++;
	    }
	}

	return K;
}

/*Vect Agent:: speed_1 (Agent* tab, int nb_agent) {
	int K= get_K(tab, nb_agent);
	
	if(K=0) {
      return ret= new Vect(0,0);
	}

    for(int i=0; i< index; i++) {
		Agent my_agent= tab[i];
		Vect my_vect= my_agent.speed;

		int new_x= my_agent->x;
		int new_y=my_agent->y;



	}


}*/

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
