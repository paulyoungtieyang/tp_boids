//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __AGENT_H__
#define __AGENT_H__



// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================
#include "Vect.h"
#include "Area.h"

// ===========================================================================
//                              Class declarations
// ===========================================================================






class Agent
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Agent(void);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Agent(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline unsigned int Get_y1 (void) const; 
    inline unsigned int Get_y2 (void) const; 
    inline unsigned int Get_y3 (void) const; 

    inline unsigned int Get_Perception (void) const;
    inline unsigned int Get_Contact (void) const;

    inline void Print_Vect(void) const;

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    void next_pos_calc(double dt);

    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Template_class(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    Agent(const Agent &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    
    int index;
    
    
    unsigned int PERCEPTION;
    unsigned int CONTACT;
    
    unsigned int y1;
    unsigned int y2;
    unsigned int y3;

    Vect* pos;
    Vect* speed;
    
    Vect* next_pos;
    Vect* next_speed;

  
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================


inline unsigned int Agent:: Get_y1 (void) const
{
    return y1;
} 

inline unsigned int Agent:: Get_y2 (void) const
{
    return y2;
} 

inline unsigned int Agent:: Get_y3 (void) const
{
    return y3;
} 

inline unsigned int Agent:: Get_Perception (void) const
{
    return PERCEPTION;
}

inline unsigned int Agent:: Get_Contact (void) const
{
    return CONTACT;
}

inline void Agent:: Print_Vect(void) const
{
    printf("x pos = %ld \n", pos->Get_X() );
    printf("y pos = %ld \n", pos->Get_Y() );
    printf("norm pos = %lf \n", pos->Get_Norm() );

    printf("x speed = %ld \n", speed->Get_X() );
    printf("y speed = %ld \n", speed->Get_Y() );
    printf("norm speed = %lf \n", speed->Get_Norm() );
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


#endif // __AGENT_H__

