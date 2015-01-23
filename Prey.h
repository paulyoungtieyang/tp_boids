//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __PREY_H__
#define __PREY_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================
#include "Agent.h"



// ===========================================================================
//                              Class declarations
// ===========================================================================






class Prey : public Agent
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Prey(void);
    Prey(double perception, double contact);
    Prey(const Prey &model);
    
    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Prey(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    
    

    inline void Print_Vect_Prey(void) ;

    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    

    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    /*Les gammas*/
    

};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================


inline void Prey:: Print_Vect_Prey(void) 
{
    Print_Vect();

    
    
}
// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __PREY_H__

