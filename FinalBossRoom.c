#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



void initialiser_BossRoomSpace(BossRoomSpace *Boss4)
{  
      
   
Boss4->BossRoom[0]=IMG_Load("./lvl4/BossRoomSpace1.png");
Boss4->BossRoom[1]=IMG_Load("./lvl4/BossRoomSpace2.png");
Boss4->BossRoom[2]=IMG_Load("./lvl4/BossRoomSpace3.png");
Boss4->BossRoom[3]=IMG_Load("./lvl4/BossRoomSpace4.png");
Boss4->BossRoom[4]=IMG_Load("./lvl4/BossRoomSpace5.png");
Boss4->BossRoom[5]=IMG_Load("./lvl4/BossRoomSpace6.png");
Boss4->BossRoom[6]=IMG_Load("./lvl4/BossRoomSpace7.png");
Boss4->BossRoom[7]=IMG_Load("./lvl4/BossRoomSpace8.png");
Boss4->BossRoom[8]=IMG_Load("./lvl4/BossRoomSpace9.png");
Boss4->BossRoomDialogue[0]=IMG_Load("./lvl4/SpaceBossRoomDialogue1.png");
Boss4->BossRoomDialogue[1]=IMG_Load("./lvl4/SpaceBossRoomDialogue2.png");
Boss4->BossRoomDialogue[2]=IMG_Load("./lvl4/SpaceBossRoomDialogue3.png");
Boss4->BossRoomDialogue[3]=IMG_Load("./lvl4/SpaceBossRoomDialogue4.png");
Boss4->BossRoomDialogue[4]=IMG_Load("./lvl4/SpaceBossRoomDialogue5.png");
Boss4->BossRoomDialogue[5]=IMG_Load("./lvl4/SpaceBossRoomDialogue6.png");
Boss4->BossRoomDialogue[6]=IMG_Load("./lvl4/SpaceBossRoomDialogue7.png");
Boss4->BossRoomDialogue[7]=IMG_Load("./lvl4/SpaceBossRoomDialogue8.png");
Boss4->BossRoomDialogue[8]=IMG_Load("./lvl4/SpaceBossRoomDialogue9.png");
Boss4->BossRoomDialogue[9]=IMG_Load("./lvl4/SpaceBossRoomDialogue10.png");
Boss4->BossRoomDialogue[10]=IMG_Load("./lvl4/SpaceBossRoomDialogue11.png");
Boss4->BossRoomDialogue_pos_ecran.x=140;
Boss4->BossRoomDialogue_pos_ecran.y=0;
Boss4->BossRoomDialogue_pos_ecran.w=0;
Boss4->BossRoomDialogue_pos_ecran.h=0;
Boss4->BossRoomAnimationTimer=0;
Boss4->DialogueShown=0; 
//Boss4->Enigme=0;
Boss4->music=Mix_LoadMUS("./Music/BossSpace.mp3");
    

}        
 



void afficher_BossRoomSpace(SDL_Surface *screen, BossRoomSpace *Boss4,Perso *perso,int *GameState,int *MusicGame)
{


SDL_Delay(120);
if (Boss4->BossRoomAnimationTimer<9)
{
 
   SDL_BlitSurface(Boss4->BossRoom[Boss4->BossRoomAnimationTimer] , NULL , screen, NULL);
Boss4->BossRoomAnimationTimer++;
if (Boss4->BossRoomAnimationTimer==9)
{
  Boss4->BossRoomAnimationTimer=0;
}

}


switch (Boss4->DialogueShown)
{


    case 0:
      {
  afficher_SpaceBar(screen,perso);
  break;

       }
    case 1:
       {
            SDL_BlitSurface(Boss4->BossRoomDialogue[0] , NULL , screen, &Boss4->BossRoomDialogue_pos_ecran);
          break;
  
        }    
    case 2:
       {
            SDL_BlitSurface(Boss4->BossRoomDialogue[1] , NULL , screen, &Boss4->BossRoomDialogue_pos_ecran);
       break;
        } 
    case 3:
       {
            SDL_BlitSurface(Boss4->BossRoomDialogue[2] , NULL , screen, &Boss4->BossRoomDialogue_pos_ecran);
          break;
        }
    case 4:
       {
            SDL_BlitSurface(Boss4->BossRoomDialogue[3] , NULL , screen, &Boss4->BossRoomDialogue_pos_ecran);
        break;
        }
    case 5:
       {
            SDL_BlitSurface(Boss4->BossRoomDialogue[4] , NULL , screen, &Boss4->BossRoomDialogue_pos_ecran);
        break;
        }
   case 6:
       {
            SDL_BlitSurface(Boss4->BossRoomDialogue[5] , NULL , screen, &Boss4->BossRoomDialogue_pos_ecran);
          break;
        }
   case 7:
       {  
            SDL_BlitSurface(Boss4->BossRoomDialogue[6] , NULL , screen, &Boss4->BossRoomDialogue_pos_ecran);
          break;
        }
   case 8:
       {   
            SDL_BlitSurface(Boss4->BossRoomDialogue[7] , NULL , screen, &Boss4->BossRoomDialogue_pos_ecran);
         break;
        }
   case 9:
       {   
            SDL_BlitSurface(Boss4->BossRoomDialogue[8] , NULL , screen, &Boss4->BossRoomDialogue_pos_ecran);
         break;
        }
  case 10:
       {   
            SDL_BlitSurface(Boss4->BossRoomDialogue[9] , NULL , screen, &Boss4->BossRoomDialogue_pos_ecran);
         break;
        }
  case 11:
       {   
            SDL_BlitSurface(Boss4->BossRoomDialogue[10] , NULL , screen, &Boss4->BossRoomDialogue_pos_ecran);
         break;
        }
  case 12:
      { 
         *MusicGame=0;
         *GameState=9;
         break;
      }
     
     

  
   
 
 
 

}







}



void freeBossRoomSpace(BossRoomSpace *Boss4)
{


for (int i=0;i<9;i++)
{
SDL_FreeSurface(Boss4->BossRoom[i]);
}
for(int j=0;j<11;j++)
{
SDL_FreeSurface(Boss4->BossRoomDialogue[j]);
}
Mix_FreeMusic(Boss4->music);
free(Boss4);
}
