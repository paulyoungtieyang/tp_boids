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
    inline unsigned int Get_posX (void) const; 
    inline unsigned int Get_posY (void) const;
    inline unsigned int Get_spX (void) const; 
    inline unsigned int Get_spY (void) const;

    inline unsigned int Get_y1 (void) const; 
    inline unsigned int Get_y2 (void) const; 
    inline unsigned int Get_y3 (void) const; 

    inline unsigned int Get_Perception (void) const;
    inline unsigned int Get_Contact (void) const;

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
    int index;
    unsigned int pos_x;
    unsigned int pos_y;
    unsigned int sp_x;
    unsigned int sp_y;
    
    static unsigned int PERCEPTION;
    static unsigned int CONTACT;
    
    unsigned int y1;
    unsigned int y2;
    unsigned int y3;
   
    
  
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline unsigned int Agent:: Get_posX (void) const
{
    return pos_x;
} 

inline unsigned int Agent:: Get_posY (void) const
{
    return pos_y;
}

inline unsigned int Agent:: Get_spX (void) const
{
    return sp_x;
} 

inline unsigned int Agent:: Get_spY (void) const
{
    return sp_y;
}

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

