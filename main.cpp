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
#include "Obstacle.h"
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
 
  printf("Lancement de simulation\n");

  int nb_proies =8;
  int nb_obstacles = 15;
  int nb_predateurs=1;



  Area my_environnement(nb_proies,nb_predateurs,nb_obstacles,0.06);
  Prey* my_tab = my_environnement.Get_Tab_Prey();
  Obstacle* my_tab_obstacles = my_environnement.Get_Tab_Obstacle();
  Predator* my_tab_predateur= my_environnement.Get_Tab_Predator();
  
 
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
  win.draw_fsquare(400,400,440,440,0xFF00);

  win.draw_fsquare(0,0,640,480,0xFFFFFF);
*/
win.draw_fsquare(0,0,640,480,0xFFFFFF);

for (int i = 0; i < nb_obstacles; ++i)
{
  win.draw_fsquare(my_tab_obstacles[i].Get_Pos().Get_X()-4,my_tab_obstacles[i].Get_Pos().Get_Y()-4,my_tab_obstacles[i].Get_Pos().Get_X()+4,my_tab_obstacles[i].Get_Pos().Get_Y()+4, 0xFF0);
}



for(int i =0; i<nb_proies;i++)
{
      
  win.draw_fsquare(my_tab[i].Get_Pos().Get_X()-1.5, my_tab[i].Get_Pos().Get_Y()-1.5,my_tab[i].Get_Pos().Get_X()+1.5, my_tab[i].Get_Pos().Get_Y()+1.5, 0xFF0000);
}

for(int i =0; i<nb_predateurs;i++)
{      
  win.draw_fsquare(my_tab_predateur[i].Get_Pos().Get_X()-3, my_tab_predateur[i].Get_Pos().Get_Y()-3,my_tab_predateur[i].Get_Pos().Get_X()+3, my_tab_predateur[i].Get_Pos().Get_Y()+3, 0xFF0000);
}

  my_environnement.Update();
  
}

     

  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

