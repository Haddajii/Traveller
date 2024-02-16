#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
     


void initialiser_BossRoomJapan(BossRoomJapan *Boss3)
{           
  
  
Boss3->BossRoom[0]=IMG_Load("./lvl3/BossRoomJapon1.png");
Boss3->BossRoom[1]=IMG_Load("./lvl3/BossRoomJapon2.png");
Boss3->BossRoom[2]=IMG_Load("./lvl3/BossRoomJapon3.png");
Boss3->BossRoom[3]=IMG_Load("./lvl3/BossRoomJapon4.png");
Boss3->BossRoomDialogue[0]=IMG_Load("./lvl3/JaponBossRoomDialogue1.png");
Boss3->BossRoomDialogue[1]=IMG_Load("./lvl3/JaponBossRoomDialogue2.png");
Boss3->BossRoomDialogue[2]=IMG_Load("./lvl3/JaponBossRoomDialogue3.png");
Boss3->BossRoomDialogue[3]=IMG_Load("./lvl3/JaponBossRoomDialogue4.png");
Boss3->BossRoomDialogue[4]=IMG_Load("./lvl3/JaponBossRoomDialogue5.png");
Boss3->BossRoomDialogue[5]=IMG_Load("./lvl3/JaponBossRoomDialogue6.png");
Boss3->BossRoomDialogue[6]=IMG_Load("./lvl3/JaponBossRoomDialogue7.png");
Boss3->BossRoomDialogue[7]=IMG_Load("./lvl3/JaponBossRoomDialogue8.png");
Boss3->BossRoomDialogue_pos_ecran.x=140;
Boss3->BossRoomDialogue_pos_ecran.y=0;
Boss3->BossRoomDialogue_pos_ecran.w=0;
Boss3->BossRoomDialogue_pos_ecran.h=0;
Boss3->BossRoomAnimationTimer=0;
Boss3->DialogueShown=0; 
Boss3->Enigme=0;
Boss3->music=Mix_LoadMUS("./Music/BossJapan.mp3");

  
} 


   

void afficher_BossRoomJapan(SDL_Surface *screen, BossRoomJapan *Boss3,Perso *perso)
{


SDL_Delay(120);
if (Boss3->BossRoomAnimationTimer<4)
{
 
   SDL_BlitSurface(Boss3->BossRoom[Boss3->BossRoomAnimationTimer] , NULL , screen, NULL);
Boss3->BossRoomAnimationTimer++;
if (Boss3->BossRoomAnimationTimer==4)
{
  Boss3->BossRoomAnimationTimer=0;
}

}


switch (Boss3->DialogueShown)
{


    case 0: 
      {
  afficher_SpaceBar(screen,perso);
  break;
      }

    case 1:
       {
            SDL_BlitSurface(Boss3->BossRoomDialogue[0] , NULL , screen, &Boss3->BossRoomDialogue_pos_ecran);
          break;
  
        }    
    case 2:
       {
            SDL_BlitSurface(Boss3->BossRoomDialogue[1] , NULL , screen, &Boss3->BossRoomDialogue_pos_ecran);
       break;
        } 
    case 3:
       {
            SDL_BlitSurface(Boss3->BossRoomDialogue[2] , NULL , screen, &Boss3->BossRoomDialogue_pos_ecran);
          break;
        }
    case 4:
       {
            SDL_BlitSurface(Boss3->BossRoomDialogue[3] , NULL , screen, &Boss3->BossRoomDialogue_pos_ecran);
        break;
        }
    case 5:
       {
            SDL_BlitSurface(Boss3->BossRoomDialogue[4] , NULL , screen, &Boss3->BossRoomDialogue_pos_ecran);
        break;
        }  
   case 6:
       {
            SDL_BlitSurface(Boss3->BossRoomDialogue[5] , NULL , screen, &Boss3->BossRoomDialogue_pos_ecran);
          break;
        }
   case 7:
       {
            SDL_BlitSurface(Boss3->BossRoomDialogue[6] , NULL , screen, &Boss3->BossRoomDialogue_pos_ecran);
          break;
        }
   case 8:
       {
            SDL_BlitSurface(Boss3->BossRoomDialogue[7] , NULL , screen, &Boss3->BossRoomDialogue_pos_ecran);
         break;
        }
   case 9:
       {
             Boss3->Enigme=1;
          break;
        }        
  

}   







}
 


void freeBossRoomJapan(BossRoomJapan *Boss3)
{


for (int i=0;i<4;i++)
{
SDL_FreeSurface(Boss3->BossRoom[i]);
}
for(int j=0;j<8;j++)
{
SDL_FreeSurface(Boss3->BossRoomDialogue[j]);
}
Mix_FreeMusic(Boss3->music);
free(Boss3);
}
