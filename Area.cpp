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
#include "Area.h"




//############################################################################
//                                                                           #
//                           Class Area                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Area::Area(void)
{
	
	Width=0;
    Height=0;

    TIME_STEP=0;

    Nb_Prey=0;
    Nb_Predator=0;

    tab_Prey=NULL;
    tab_Predator=NULL;

}

Area::Area(int H, int W, int Nb_prey, int Nb_pred, double step)
{
	Width=W;
	Height=H;
	Nb_Prey=Nb_prey;
	Nb_Predator=Nb_pred;
	TIME_STEP=step;

	tab_Prey= new Prey [Nb_Prey];
	tab_Predator= new Predator [Nb_Predator];


}


Area::Area(int H, int W, int Nb_prey, Prey* tab_prey, int Nb_pred, double step)
{
  Width=W;
	Height=H;
	Nb_Prey=Nb_prey;
	Nb_Predator=Nb_pred;
	TIME_STEP=step;

	tab_Prey= tab_prey;
	tab_Predator= new Predator [Nb_Predator];
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Area::~Area(void)
{
	delete [] tab_Prey ;
	delete [] tab_Predator;
	tab_Predator=NULL;
	tab_Prey=NULL;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
int Area::Get_K (int index)
{
    int K=0;
    Prey* my_prey = new Prey (tab_Prey [index],index);

    for( int i=0; i< Nb_Prey; i++) {
   	
   	  Prey* prey_to_test = new Prey (tab_Prey[i], i);
    
      Vect tmp= (my_prey->Get_Pos())-(prey_to_test->Get_Pos());
    
      if(tmp.Get_Norm()<my_prey->Get_Perception()) {
        K++;
      } 
    }
  return K-1;
}



int Area::Get_K_Prime (int index)
{
    int K=0;
    Prey* my_prey = new Prey (tab_Prey [index],index);

    for( int i=0; i< Nb_Prey; i++) {
   	
   	  Prey* prey_to_test = new Prey (tab_Prey[i], i);
    
      Vect tmp= (my_prey->Get_Pos())-(prey_to_test->Get_Pos());
    
      if(tmp.Get_Norm()<my_prey->Get_Contact()) {
      K++;
      } 
    }
  return K-1;
}



Vect Area::Speed_1 (int index)
{
	int K=Get_K(index);
	Prey* my_prey = new Prey (tab_Prey [index],index);
	
	if(K==0){
		return Vect(0,0);
	}

	if (K>0){
		Vect* ret = new Vect(0,0);
		for(int i=0; i< Nb_Prey; i++){          
          
   	      Prey* prey_to_test = new Prey (tab_Prey[i], i);
          Vect test = my_prey->Get_Pos()- prey_to_test->Get_Pos(); 
          
          if(test.Get_Norm()<my_prey->Get_Perception()) {
          	*ret= *ret + (prey_to_test->Get_Speed() - my_prey->Get_Speed());
          }
		}
        return *ret/K;
	}
}



Vect Area::Speed_2 (int index) 
{
    int K=Get_K(index);
	Prey* my_prey = new Prey (tab_Prey [index],index);
	
	if(K==0){
		return Vect(0,0);
	}

	if (K>0){
		Vect* ret = new Vect(0,0);
		for(int i=0; i< Nb_Prey; i++){          
          
   	      Prey* prey_to_test = new Prey (tab_Prey[i], i);
          Vect test = my_prey->Get_Pos()- prey_to_test->Get_Pos(); 
          
          if(test.Get_Norm()<my_prey->Get_Perception()) {
          	*ret= *ret + (prey_to_test->Get_Pos() - my_prey->Get_Pos());
          }
		}
        return *ret/K;
	}
}


Vect Area::Speed_3 (int index)
{
    int K=Get_K_Prime(index);
    K= (-1)*K;
	Prey* my_prey = new Prey (tab_Prey [index],index);
	
	if(K==0){
		return Vect(0,0);
	}

	if (K>0){
		Vect* ret = new Vect(0,0);
		for(int i=0; i< Nb_Prey; i++){          
          
   	      Prey* prey_to_test = new Prey (tab_Prey[i], i);
          Vect test = my_prey->Get_Pos()- prey_to_test->Get_Pos(); 
          
          if(test.Get_Norm()<my_prey->Get_Contact()) {
          	*ret= *ret + (prey_to_test->Get_Pos() - my_prey->Get_Pos());
          }
		}

  return *ret/K;
	}
}


Vect* Area::Speed_All (int index)
{
   Prey* my_prey = new Prey(tab_Prey[index],index);
   Vect* ret = new Vect (0,0);
   
   double y1= my_prey->Get_y1();
   double y2= my_prey->Get_y2();
   double y3= my_prey->Get_y3();

   *ret= my_prey->Get_Speed() + ((Speed_1(index)*y1) + (Speed_2(index)*y2) + (Speed_3(index)*y3))*TIME_STEP;
   delete my_prey;
   
   return ret;
}


Vect* Area::Pos_All (int index)
{
   Prey* my_prey = new Prey(tab_Prey[index],index);
   Vect* ret = new Vect (0,0);

   *ret= my_prey->Get_Pos() + ((my_prey->Get_Speed())*TIME_STEP); 
   delete my_prey;

   return ret; 
}


void Area::Update_Pos (int index)
{
  Vect* New_pos= Pos_All(index);
  tab_Prey[index].Set_Pos(*New_pos);
}

void Area::Update_Speed (int index)
{
  Vect* New_speed= Speed_All(index);
  tab_Prey[index].Set_Speed(*New_speed);
}


// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
