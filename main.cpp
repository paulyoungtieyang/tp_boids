//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <stdio.h>


// ===========================================================================
//                             Include Project Files
// ===========================================================================
#include "Agent.h"
#include "Vect.h"
#include "Prey.h"
#include "Predator.h"
#include "Area.h"
#include "bwindow.h"
// ===========================================================================
//                               Static Attributes
// ===========================================================================





// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================




// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  //printf("Hello World !\n");

  /*Vect* tmp = new Vect (5,12);
  double  a= tmp->Get_Y();
  printf("%lf\n",a );*/


  /*Agent* Agent_1 = new Agent();
  printf("\nAgent 1\n");
  Agent_1->Print_Vect();*/

  /*Agent* Agent_2 = new Agent(50,50,50);
  printf("\nAgent 2\n");
  Agent_2->Print_Vect();*/

  /*Prey* Prey_1= new Prey();
  printf("\nProie 1\n");
  Prey_1->Print_Vect_Prey();

  Prey* Prey_2 = new Prey(12,12,12,12,12,12);
  printf("\nProie 2\n");
  Prey_2->Print_Vect_Prey();

  Predator* Predator_1= new Predator (20,20);
  printf("\nPredator 1\n");
  Predator_1->Print_Vect_Predator();
  
  Prey* Prey_3= new Prey(*Prey_2, 5);
  printf("\nProie 3\n");
  Prey_3->Print_Vect_Prey();

  Predator* Predator_2= new Predator (*Predator_1,1);
  printf("\nPredator 2\n");
  Predator_2->Print_Vect_Predator();*/

  //Area* my_Area= new Area();
  /*Area* Environnement = new Area (5,5,5,5,5);
  Environnement->Display();

  Vect* my_vect = new Vect(2,2);
  my_vect->Print_Vect();*/

  int nb_proies = 5;

  Prey* my_tab = new Prey [nb_proies];
  Prey* Sample = new Prey (1,1,1,1,1,1);
  
  for(int i=0; i<nb_proies; i++)
  {
    Prey* my_prey_i = new Prey (*Sample, i+1);
    my_tab[i]= *my_prey_i;
    //Vect test = my_tab[i].Get_Speed();
    //test.Print_Vect();
    //my_prey_i->Print_Vect_Prey(); 
  }
  

   
  Area* my_environnement = new Area (600,480, nb_proies, my_tab,0,0.1);
  
  for(int i=0; i<nb_proies;i++)
  {
    my_environnement->Update_Speed(i);
    my_environnement->Update_Pos(i);

    
  }

  /*double tmp =my_tab[1].Get_Pos().Get_X()-2;
  printf("x =%lf \n", tmp );*/













  bwindow win(640,480);
    printf("%d\n",win.init());
    win.map();
    for(;;)
    {
  int ev = win.parse_event();
  switch(ev)
  {
      case BKPRESS :
    printf("keypressed\n"); 
    printf("key : %s\n",win.get_lastkey());
    
    win.draw_fsquare(0,0,640,480,0xFF00);
    for(int i =0; i<nb_proies;i++){
     my_environnement->Update_Speed(i);
     my_environnement->Update_Pos(i);
     win.draw_fsquare(my_tab[i].Get_Pos().Get_X()-2, my_tab[i].Get_Pos().Get_Y()-2,my_tab[i].Get_Pos().Get_X()+2, my_tab[i].Get_Pos().Get_Y()+2, 0xFF0000);
    }
     


    break;
      case BBPRESS:
    printf("buttonpressed\n"); break;
      case BEXPOSE:
    printf("expose\n"); break;
      case BCONFIGURE:
    printf("configure\n"); break;
  }
  /*win.draw_point(100,100,0xFF00);
  win.draw_line(100,100,200,200,0xFF0000);
  win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));
  win.draw_square(200,200,220,220,0xFF00);
  win.draw_fsquare(400,400,440,440,0xFF00);*/
    }


  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

