
//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __VECT_H__
#define __VECT_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <math.h>


// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================






class Vect
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Vect(void);
    Vect(double x_to_give, double y_to_give);
    inline Vect(const Vect &model);
    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Vect(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline double Get_X (void) const;
    inline double Get_Y (void) const;
    inline double Get_Norm (void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    inline double Set_Norm (void);
    inline void Set_X (double x_to_give);
    inline void Set_Y (double y_to_give);
    // =======================================================================
    //                                Operators
    // =======================================================================
    friend inline Vect operator+ (Vect v1, Vect v2);
    friend inline Vect operator- (Vect v1, Vect v2);
    inline Vect operator/ (double v);
    inline Vect operator* (double v);
    
    
    // =======================================================================
    //                              Public Methods
    // =======================================================================
    inline void Print_Vector(void);
    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Vect(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================

    double x;
    double y;
    double norm;

};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline double Vect:: Get_X (void) const
{
    return x;
} 

inline double Vect:: Get_Y (void) const
{
    return y;
}

inline double Vect:: Get_Norm (void) const
{
    return norm;
}
// ===========================================================================
//                              Setters' definitions
// ===========================================================================
inline double Vect:: Set_Norm (void)
{
    
    return sqrt((x*x) + (y*y));
}
// ===========================================================================
//                             Operators' definitions
// ===========================================================================
inline Vect operator+(Vect v1, Vect v2)
{
  double a = v1.Get_X() + v2.Get_X();
  double b = v1.Get_Y() + v2.Get_Y();
  Vect res (a,b);
  return res;
  
}

inline Vect operator-(Vect v1, Vect v2)
{
  double a = v1.Get_X() - v2.Get_X();
  double b = v1.Get_Y() - v2.Get_Y();
  Vect res (a,b);
  return res;
  
}

inline Vect Vect::operator/ (double v)
{
  double a = x/v;
  double b = y/v;
  Vect res (a,b);
  return res;
  
}

inline Vect Vect::operator* (double v)
{
  double a = x*v;
  double b = y*v;
  Vect res (a,b);
  return res;
  
}

inline void Vect::Print_Vector(void)
{
  printf("\n x= %lf, y=%lf, norm=%lf \n", x,y,norm);
}

inline Vect::Vect(const Vect &model)
{
  x=model.x;
  y=model.y;
  norm=model.norm;
}

inline void Vect::Set_X (double x_to_give)
{
  x= x+x_to_give;
}

inline void Vect::Set_Y (double y_to_give)
{
  y=y+y_to_give;
}
// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __VECT_H__

