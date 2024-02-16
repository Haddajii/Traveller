#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
        

void initialiser_BossRoomRussia(BossRoomRussia *Boss1)
{   
             
 
Boss1->BossRoom[0]=IMG_Load("./lvl1/BossRoomRussia1.png");
 Boss1->BossRoom[1]=IMG_Load("./lvl1/BossRoomRussia2.png");
 Boss1->BossRoom[2]=IMG_Load("./lvl1/BossRoomRussia3.png");
Boss1->BossRoom[3]=IMG_Load("./lvl1/BossRoomRussia4.png");
Boss1->BossRoomDialogue[0]=IMG_Load("./lvl1/RussiaBossRoomDialogue1.png");
Boss1->BossRoomDialogue[1]=IMG_Load("./lvl1/RussiaBossRoomDialogue2.png");
Boss1->BossRoomDialogue[2]=IMG_Load("./lvl1/RussiaBossRoomDialogue3.png");
Boss1->BossRoomDialogue[3]=IMG_Load("./lvl1/RussiaBossRoomDialogue4.png");
Boss1->BossRoomDialogue[4]=IMG_Load("./lvl1/RussiaBossRoomDialogue5.png");
Boss1->BossRoomDialogue[5]=IMG_Load("./lvl1/RussiaBossRoomDialogue6.png");
Boss1->BossRoomDialogue[6]=IMG_Load("./lvl1/RussiaBossRoomDialogue7.png");
Boss1->BossRoomDialogue[7]=IMG_Load("./lvl1/RussiaBossRoomDialogue8.png");
Boss1->BossRoomDialogue[8]=IMG_Load("./lvl1/RussiaBossRoomDialogue9.png");
Boss1->BossRoomDialogue[9]=IMG_Load("./lvl1/RussiaBossRoomDialogue10.png");
Boss1->BossRoomDialogue[10]=IMG_Load("./lvl1/RussiaBossRoomDialogue11.png");
Boss1->BossRoomDialogue[11]=IMG_Load("./lvl1/RussiaBossRoomDialogue12.png");
Boss1->BossRoomDialogue[12]=IMG_Load("./lvl1/RussiaBossRoomDialogue13.png");
Boss1->BossRoomDialogue[13]=IMG_Load("./lvl1/RussiaBossRoomDialogue14.png");
Boss1->BossRoomDialogue_pos_ecran.x=140;
Boss1->BossRoomDialogue_pos_ecran.y=0;
Boss1->BossRoomDialogue_pos_ecran.w=0;
Boss1->BossRoomDialogue_pos_ecran.h=0; 
   Boss1->BossRoomAnimationTimer=0;
   Boss1->DialogueShown=0; 
   Boss1->Enigme=0;
   Boss1->music=Mix_LoadMUS("./Music/BossRussia.mp3");   

               
     
 
}
void afficher_BossRoomRussia(SDL_Surface *screen, BossRoomRussia *Boss1,Perso *perso)
{
SDL_Delay(160);
if (Boss1->BossRoomAnimationTimer<4)
{
 
   SDL_BlitSurface(Boss1->BossRoom[Boss1->BossRoomAnimationTimer] , NULL , screen, NULL);
Boss1->BossRoomAnimationTimer++;

if (Boss1->BossRoomAnimationTimer==4)
{
  Boss1->BossRoomAnimationTimer=0;
}

}



switch (Boss1->DialogueShown)
{


    case 0:
      {
  afficher_SpaceBar(screen,perso);
  break;
      }


    case 1:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[0] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
          break;
  
        }    
    case 2:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[1] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
       break;
        } 
    case 3:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[2] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
          break;
        }
    case 4:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[3] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
        break;
        }
    case 5:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[4] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
        break;
        }
   case 6:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[5] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
          break;
        }
   case 7:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[6] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
          break;
        }
   case 8:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[7] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
         break;
        }
   case 9:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[8] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
          break;
        }   
   case 10: 
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[9] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
        break;
        }
    case 11:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[10] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
        break;
        }
     case 12:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[11] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
        break;
        }
      case 13:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[12] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
           break;
        }
       case 14:
       {
            SDL_BlitSurface(Boss1->BossRoomDialogue[13] , NULL , screen, &Boss1->BossRoomDialogue_pos_ecran);
         break;
        }
      case 15:
     {

     Boss1->Enigme=1;
     break;

     }

   
  
  
 
  



   




}

 
}

void freeBossRoomRussia(BossRoomRussia *Boss1)
{


for (int i=0;i<4;i++)
{
SDL_FreeSurface(Boss1->BossRoom[i]);
}
for(int j=0;j<14;j++)
{
SDL_FreeSurface(Boss1->BossRoomDialogue[j]);
}
Mix_FreeMusic(Boss1->music);
free(Boss1);





}


