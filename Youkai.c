#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
 
   


void initialiser_Youkai(Youkai *youkai)
{
   
youkai->afficher_Youkai=IMG_Load("./lvl3Ennemies/Youkai.png");
youkai->pos_Youkai_ecran.x=0;
youkai->pos_Youkai_ecran.y=525;
youkai->pos_Youkai_ecran.w=0;
youkai->pos_Youkai_ecran.h=0;
youkai->pos_Youkai_affiche.x=0;
youkai->pos_Youkai_affiche.y=676;
youkai->pos_Youkai_affiche.h=123;
youkai->pos_Youkai_affiche.w=117;
youkai->PositionInitiale=2900;
youkai->MouvementTimer=0;
youkai->EnnemiState=1;
youkai->Mouvement=0;
youkai->Trajectory=0;


    
}



void AnimateYoukaiWhileRunning(Youkai *youkai)
{

if (SDL_GetTicks() - youkai->MouvementTimer >=240)
  {

switch (youkai->Trajectory)
{
   case 1: 
       {

         youkai->pos_Youkai_affiche.y=672;

          if (youkai->pos_Youkai_affiche.x==600)
        {
             youkai->pos_Youkai_affiche.x=0;
         }
            else
        { 
             youkai->pos_Youkai_affiche.x=youkai->pos_Youkai_affiche.x+150;
         }
       break;
       }

  case -1: 
       {

        youkai->pos_Youkai_affiche.y=272;

          if (youkai->pos_Youkai_affiche.x==600)
        {
             youkai->pos_Youkai_affiche.x=0;
         }
            else
        { 
             youkai->pos_Youkai_affiche.x=youkai->pos_Youkai_affiche.x+150;
         }

       break;
       }

}

youkai->MouvementTimer=SDL_GetTicks();
}

}



void Move_Youkai(Youkai *youkai, Japan *japan)
{
if (youkai->pos_Youkai_ecran.x>=2900-japan->pos_map3_affiche.x)
  {
           youkai->Trajectory=-1;
           youkai->Mouvement=-3;
 }
if (youkai->pos_Youkai_ecran.x<2420-japan->pos_map3_affiche.x)
  {
      youkai->Trajectory=1;
      youkai->Mouvement=3;
  }

      
}    
 
  
       
void CheckForCollisionWithYoukai(SDL_Surface *screen,Youkai *youkai,Perso *perso,Japan *japan) 
{

if (CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,youkai->pos_Youkai_ecran,youkai->pos_Youkai_affiche)==1)
{
 if (perso->pos_perso_ecran.y+(perso->pos_perso_affiche.h-10)<=youkai->pos_Youkai_ecran.y)
  {
 //Mob->pos_IceMob_affiche.x=39;
 //Mob->pos_IceMob_affiche.y=233;
 //SDL_BlitSurface(ennemi->afficher_ennemi, &ennemi->pos_IceMob_affiche, screen,  &ennemi->pos_IceMob_ecran);
  youkai->EnnemiState=0;
  perso->EnnemiesKilled++; 
  //SDL_FreeSurface(ennemi->afficher_ennemi);

  }
else  
  {
   Perso_DeathJapan(perso,japan);

  }
  
}        
} 





void afficher_Youkai(SDL_Surface *screen,Youkai *youkai , Japan *japan,Perso *perso)
{
if (youkai->EnnemiState==1)
{

youkai->pos_Youkai_ecran.x=youkai->PositionInitiale-japan->pos_map3_affiche.x;
youkai->PositionInitiale=youkai->PositionInitiale+youkai->Mouvement;
AnimateYoukaiWhileRunning(youkai);
Move_Youkai(youkai,japan);

SDL_BlitSurface(youkai->afficher_Youkai, &youkai->pos_Youkai_affiche, screen,  &youkai->pos_Youkai_ecran);
CheckForCollisionWithYoukai(screen,youkai,perso,japan);
}


}


void free_Youkai(Youkai *youkai)
{


SDL_FreeSurface(youkai->afficher_Youkai);
free(youkai);
}
