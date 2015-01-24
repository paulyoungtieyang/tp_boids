//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __AREA_H__
#define __AREA_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================
#include "Predator.h"
#include "Prey.h"
#include "Obstacle.h"

// ===========================================================================
//                              Class declarations
// ===========================================================================






class Area
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Area(void);
    Area(int Nb_prey, int Nb_pred, int Nb_obstacle, double step);
    
    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Area(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline double get_Step (void);
    inline int get_Height (void);
    inline int get_Width (void);
    inline void Display(void);

    inline Prey* Get_Tab_Prey(void) const;
    inline Obstacle* Get_Tab_Obstacle(void) const;
    inline Predator* Get_Tab_Predator(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    double Get_K (int index);
    double Get_K_Prime (int index);

    void Update_Pos (int index);
    void Update_Speed (int index);

    void Speed_All(void);
    void Pos_All(void);
    void Update(void);
    
    void Speed_All_Predator(void);
    void Pos_All_Predator(void);
  
    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Area(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    Area(const Area &model)
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
    int Width;
    int Height;

    double TIME_STEP;

    int Nb_Prey;
    int Nb_Predator;
    int Nb_Obstacle;

    Prey* tab_Prey;
    Predator* tab_Predator;
    Obstacle* tab_Obstacle;

    //Obstacle* borders;
    
    static const double y1;
    static const double y2;
    static const double y3;
    static const double y4;
    

};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================
inline double Area::get_Step (void) {
    return TIME_STEP;
}

inline int Area::get_Height (void) {
    return Height;
}

inline int Area::get_Width (void) {
    return Width;
}

inline void Area::Display(void) {
    printf("Width = %d , Height = %d , TIME_STEP= %lf , Nb_Predator = %d, Nb_Prey = %d \n", Width, Height, TIME_STEP, Nb_Predator, Nb_Prey );
}

inline Prey* Area::Get_Tab_Prey(void) const
{
    return tab_Prey;
}

inline Obstacle* Area::Get_Tab_Obstacle(void) const
{

    return tab_Obstacle;
}

inline Predator* Area::Get_Tab_Predator(void) const
{
    return tab_Predator;
}


// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __AREA_H__

