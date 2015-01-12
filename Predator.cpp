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
#include "Predator.h"




//############################################################################
//                                                                           #
//                           Class Predator                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Predator::Predator(void)
{
	Agent();
}

Predator::Predator(int perception, int index_to_give):Agent(index_to_give, perception, 0)
{
	
}

Predator::Predator(const Predator &model, int index_to_give)
{
	index=index_to_give;
    PERCEPTION=model.PERCEPTION;
    CONTACT=model.CONTACT;

    pos=model.pos;
    speed=model.speed;

    next_pos=model.next_pos;
    next_speed=model.next_speed;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Predator::~Predator(void)
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