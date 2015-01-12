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
#include "Prey.h"




//############################################################################
//                                                                           #
//                           Class Prey                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Prey::Prey(void):Agent()
{
	y1=0;
	y2=0;
	y3=0;
}

Prey::Prey(int perception, int contact, int index_to_give, 
	         double gam1, double gam2, double gam3): Agent(index_to_give, perception, contact)
{
	
	y1= gam1;
	y2= gam2;
	y3= gam3;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Prey::Prey(const Prey &model, int index_to_give)
{
	y1=model.y1;
	y2=model.y2;
	y3=model.y3;

    index=index_to_give;
    PERCEPTION=model.PERCEPTION;
    CONTACT=model.CONTACT;

    pos=model.pos;
    speed=model.speed;

    next_pos=model.next_pos;
    next_speed=model.next_speed;
}


Prey::~Prey(void)
{

}


// ===========================================================================
//                                 Public Methods
// ===========================================================================

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
