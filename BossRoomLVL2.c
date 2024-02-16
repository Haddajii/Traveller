#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

   
       
void initialiser_BossRoomEgypt(BossRoomEgypt *Boss2)
{  
  
  
Boss2->BossRoom[0]=IMG_Load("./lvl2/BossRoomEgypt1.png");
Boss2->BossRoom[1]=IMG_Load("./lvl2/BossRoomEgypt2.png");
Boss2->BossRoom[2]=IMG_Load("./lvl2/BossRoomEgypt3.png");
Boss2->BossRoom[3]=IMG_Load("./lvl2/BossRoomEgypt4.png");
Boss2->BossRoomDialogue[0]=IMG_Load("./lvl2/EgyptBossRoomDialogue1.png");
Boss2->BossRoomDialogue[1]=IMG_Load("./lvl2/EgyptBossRoomDialogue2.png");
Boss2->BossRoomDialogue[2]=IMG_Load("./lvl2/EgyptBossRoomDialogue3.png");
Boss2->BossRoomDialogue[3]=IMG_Load("./lvl2/EgyptBossRoomDialogue4.png");
Boss2->BossRoomDialogue[4]=IMG_Load("./lvl2/EgyptBossRoomDialogue5.png");
Boss2->BossRoomDialogue[5]=IMG_Load("./lvl2/EgyptBossRoomDialogue6.png");
Boss2->BossRoomDialogue[6]=IMG_Load("./lvl2/EgyptBossRoomDialogue7.png");
Boss2->BossRoomDialogue[7]=IMG_Load("./lvl2/EgyptBossRoomDialogue8.png");
Boss2->BossRoomDialogue_pos_ecran.x=140;
Boss2->BossRoomDialogue_pos_ecran.y=0;
Boss2->BossRoomDialogue_pos_ecran.w=0;
Boss2->BossRoomDialogue_pos_ecran.h=0;
Boss2->BossRoomAnimationTimer=0;
Boss2->DialogueShown=0; 
Boss2->Enigme=0;
Boss2->music=Mix_LoadMUS("./Music/BossEgypt.mp3");

                 
      
  
}  

void afficher_BossRoomEgypt(SDL_Surface *screen, BossRoomEgypt *Boss2,Perso *perso)
{


SDL_Delay(120);
if (Boss2->BossRoomAnimationTimer<4)
{
 
   SDL_BlitSurface(Boss2->BossRoom[Boss2->BossRoomAnimationTimer] , NULL , screen, NULL);
Boss2->BossRoomAnimationTimer++;
if (Boss2->BossRoomAnimationTimer==4)
{
  Boss2->BossRoomAnimationTimer=0;
}

}


switch (Boss2->DialogueShown)
{


    case 0:
      {
  afficher_SpaceBar(screen,perso);
  break;
      }


    case 1:
       {
            SDL_BlitSurface(Boss2->BossRoomDialogue[0] , NULL , screen, &Boss2->BossRoomDialogue_pos_ecran);
          break;
  
        }    
    case 2: 
       {
            SDL_BlitSurface(Boss2->BossRoomDialogue[1] , NULL , screen, &Boss2->BossRoomDialogue_pos_ecran);
       break;
        } 
    case 3: 
       {
            SDL_BlitSurface(Boss2->BossRoomDialogue[2] , NULL , screen, &Boss2->BossRoomDialogue_pos_ecran);
          break;
        }
    case 4:
       {
            SDL_BlitSurface(Boss2->BossRoomDialogue[3] , NULL , screen, &Boss2->BossRoomDialogue_pos_ecran);
        break;
        }
    case 5:
       {
            SDL_BlitSurface(Boss2->BossRoomDialogue[4] , NULL , screen, &Boss2->BossRoomDialogue_pos_ecran);
        break;
        }
   case 6:
       {
            SDL_BlitSurface(Boss2->BossRoomDialogue[5] , NULL , screen, &Boss2->BossRoomDialogue_pos_ecran);
          break;
        }
   case 7:
       {  
            SDL_BlitSurface(Boss2->BossRoomDialogue[6] , NULL , screen, &Boss2->BossRoomDialogue_pos_ecran);
          break;
        }
   case 8:
       {   
            SDL_BlitSurface(Boss2->BossRoomDialogue[7] , NULL , screen, &Boss2->BossRoomDialogue_pos_ecran);
         break;
        }
   case 9:
       {
             Boss2->Enigme=1;
          break;
        }   
     

       
        
 
 

 
}

  





}



void freeBossRoomEgypt(BossRoomEgypt *Boss2)
{


for (int i=0;i<4;i++)
{
SDL_FreeSurface(Boss2->BossRoom[i]);
}
for(int j=0;j<8;j++)
{
SDL_FreeSurface(Boss2->BossRoomDialogue[j]);
}
Mix_FreeMusic(Boss2->music);
free(Boss2);
}
