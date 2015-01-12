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
#include "Vect.h"




//############################################################################
//                                                                           #
//                           Class Vect                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Vect::Vect(void)
{
	x=NULL;
	y=NULL;
	norm=NULL;
}

Vect::Vect(int x_to_give, int y_to_give)
{
    x=x_to_give;
    y=y_to_give;
    norm= Set_Norm();
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Vect::~Vect(void)
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
