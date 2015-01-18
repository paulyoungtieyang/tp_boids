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
    Agent(int index_to_give, int perception, int contact);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Agent(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    

    inline int Get_Perception (void) const;
    inline int Get_Contact (void) const;
    inline int Get_Index (void) const;



    inline void Print_Vect(void) const;


    inline Vect Get_Pos (void);
    inline Vect Get_Speed (void);

    inline void Set_Pos (Vect new_pos); 
    inline void Set_Speed (Vect new_speed); 
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
   

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
    
    
    int PERCEPTION;
    int CONTACT;
    
    

    int index;

    Vect* pos;
    Vect* speed;
    
    
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================




inline int Agent:: Get_Perception (void) const
{
    return PERCEPTION;
}

inline int Agent:: Get_Contact (void) const
{
    return CONTACT;
}

inline int Agent:: Get_Index (void) const
{
    return index;
}

inline Vect Agent:: Get_Pos (void) 
{
    return *pos;
}

inline Vect Agent:: Get_Speed (void)
{
    return *speed;
}

inline void Agent:: Set_Pos (Vect new_pos)
{
    


    printf("old pos =%lf %lf\n", pos->Get_X(), pos->Get_Y() );
    delete pos;
    *pos = new_pos;
    printf("new pos=%lf %lf\n", pos->Get_X(), pos->Get_Y()  );
} 
    

inline void Agent:: Set_Speed (Vect new_speed)
{
    printf("old speed =%lf %lf\n", speed->Get_X(), speed->Get_Y() );
    delete speed;
    *speed=new_speed;
    printf("new speed=%lf %lf\n", speed->Get_X(), speed->Get_Y()  );
} 


inline void Agent:: Print_Vect(void) const
{
    pos->Print_Vector();
    speed->Print_Vector();
    
    
    printf(" Index= %d\n", Get_Index());
    printf(" PERCEPTION= %d\n", Get_Perception());
    printf(" CONTACT= %d\n", Get_Contact());
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

