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
const double Area:: y1=0.1;
const double Area:: y2=0.04;
const double Area:: y3=2;
const double Area:: y4=1;
    
// ===========================================================================
//                                  Constructors
// ===========================================================================
Area::Area(void)
{
	
    TIME_STEP=0;

    Nb_Prey=0;
    Nb_Predator=0;
    Nb_Obstacle=0;

    tab_Prey=NULL;
    tab_Predator=NULL;
    tab_Obstacle=NULL;


}

Area::Area(int Nb_prey, int Nb_pred, int Nb_obstacle, double step)
{
	
	Nb_Prey=Nb_prey;
	Nb_Predator=Nb_pred;
        Nb_Obstacle=Nb_obstacle;

	TIME_STEP=step;

	tab_Prey= new Prey [Nb_Prey];
	tab_Predator= new Predator [Nb_Predator];
  tab_Obstacle= new Obstacle [Nb_Obstacle];

    

}





// ===========================================================================
//                                  Destructor
// ===========================================================================
Area::~Area(void)
{
	delete [] tab_Prey ;
	delete [] tab_Predator;
  delete [] tab_Obstacle;
	tab_Predator=NULL;
	tab_Prey=NULL;
  tab_Obstacle=NULL;
  printf("Hello\n");
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================


void Area::Speed_All(void)
{
  
  for (int i=0; i<Nb_Prey; i++)
  {
    
    double K=0;
    double K_Prime=0;
    double O=0;
    
    Vect Speed_2(0,0);
    Vect Speed_1(0,0);
    Vect Speed_3(0,0);
    Vect Speed_3_Prime(0,0);
    Vect Speed_4(0,0);

    for(int j=0; j<Nb_Prey;j++)
    {
      Vect test=tab_Prey[i].Get_Pos() -tab_Prey[j].Get_Pos();
            
      if (test.Get_Norm()<tab_Prey[i].Get_Perception() && j!= i)
      {   
        Speed_2= Speed_2 + tab_Prey[j].Get_Pos() - tab_Prey[i].Get_Pos(); 
        Speed_1= Speed_1 + tab_Prey[j].Get_Speed() - tab_Prey[i].Get_Speed(); 

        K++;
        
      }
  
    }


    if (K!=0)
    {
      
      Speed_2= Speed_2/K;
      Speed_1= Speed_1/K;

    }
    
    
    for (int j=0; j<Nb_Prey;j++)
    {
      Vect test=tab_Prey[j].Get_Pos() -tab_Prey[i].Get_Pos();
      
      

      if (test.Get_Norm()<tab_Prey[i].Get_Contact() && j!= i)
      {
        Speed_3=Speed_3 + tab_Prey[j].Get_Pos() - tab_Prey[i].Get_Pos(); 
        K_Prime++;
      }

    } 

    for (int j=0; j<Nb_Obstacle;j++)
    {
      Vect test=tab_Obstacle[j].Get_Pos() -tab_Prey[i].Get_Pos();
      
      

      if (test.Get_Norm()<tab_Prey[i].Get_Contact())
      {
        O++; 
        Speed_3_Prime = Speed_3_Prime + tab_Obstacle[j].Get_Pos() - tab_Prey[i].Get_Pos(); 
      }

    } 
    


    if (O!=0)
    {
      Speed_3_Prime = Speed_3_Prime/O;
    }
    if (K_Prime!=0)
    { 
      Speed_3=Speed_3/(K_Prime); 
    }

    /* mise a jour vitesse du prédateur */

    for(int j=0; i< Nb_Predator; i++)
    {
    
     Vect test=tab_Predator[j].Get_Pos()-tab_Prey[i].Get_Pos();

      if (test.Get_Norm()< tab_Prey[i].Get_Perception() )
       {
        Speed_4= Speed_4 + test/(test.Get_Norm());
      }

    }



    
    Vect V1=Speed_1*TIME_STEP;    
    Vect V2=Speed_2*TIME_STEP;
    Vect V3=Speed_3*TIME_STEP;
    Vect V3_Prime =Speed_3_Prime*TIME_STEP;
    Vect V4= Speed_4*TIME_STEP;

    
      V1=V1*y1;
      
      V2=V2*y2;
      
      V3=V3*y3;
      
      V3_Prime=V3_Prime*y3;

      V4=V4*y4;

      Vect Final_Speed =V1+V2-V3-V3_Prime-V4;

      Final_Speed =tab_Prey[i].Get_Speed()+ Final_Speed;
      //printf("Valeur de V : ");
      //V.afficheVect();

     
     if(tab_Prey[i].Get_Pos().Get_Y()<20)
     {
      Final_Speed.Set_Y(0.02);
     } 

      else if(tab_Prey[i].Get_Pos().Get_Y()>460)
     {
      Final_Speed.Set_Y(-0.02);
     } 


     if(tab_Prey[i].Get_Pos().Get_X()<20)
     {
      Final_Speed.Set_X(0.02);
     } 

      else if(tab_Prey[i].Get_Pos().Get_X()>620)
     {
      Final_Speed.Set_X(-0.02);
     } 

     tab_Prey[i].Set_Speed(Final_Speed);

  }
}


void Area::Pos_All(void)
{ 
  for (int i=0; i<Nb_Prey;i++)
  {
    tab_Prey[i].Set_Pos(tab_Prey[i].Get_Pos()+tab_Prey[i].Get_Speed()*TIME_STEP);
  }
}

void Area::Speed_All_Predator(void)
{
  for (int i = 0; i < Nb_Predator; ++i)
  {
    Vect Speed_Pred(0,0);

    for (int j=0; j<Nb_Prey;j++)
    {
      Vect test=tab_Predator[i].Get_Pos()-tab_Prey[j].Get_Pos();

      if (test.Get_Norm()< tab_Prey[j].Get_Perception() )
      {
        Speed_Pred= Speed_Pred + test/(test.Get_Norm());
      }
    } 


  Speed_Pred= Speed_Pred*TIME_STEP*y4;

  if(tab_Predator[i].Get_Pos().Get_Y()<20)
     {
      Speed_Pred.Set_Y(0.02);
     } 

      else if(tab_Predator[i].Get_Pos().Get_Y()>460)
     {
      Speed_Pred.Set_Y(-0.02);
     } 


     if(tab_Predator[i].Get_Pos().Get_X()<20)
     {
      Speed_Pred.Set_X(0.02);
     } 

      else if(tab_Predator[i].Get_Pos().Get_X()>620)
     {
      Speed_Pred.Set_X(-0.02);
     } 

  tab_Predator[i].Set_Speed(Speed_Pred);

  }
}

void Area::Pos_All_Predator(void)
{
  for (int i=0; i<Nb_Predator;i++)
  {
    tab_Predator[i].Set_Pos(tab_Predator[i].Get_Pos()+tab_Predator[i].Get_Speed()*TIME_STEP);
  }
}

void Area::Update(void)
{
  for(int i=0; i<Nb_Prey;i++)
  {
    
    Speed_All();
    Pos_All();
  }

  for (int i = 0; i <Nb_Predator; ++i)
  {
    Speed_All_Predator();
    Pos_All_Predator();
  }
}



