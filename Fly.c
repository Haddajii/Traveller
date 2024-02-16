#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
                       
               
              
void initialiser_Fly(Fly *fly)
{
 
fly->afficher_Fly=IMG_Load("./lvl2Ennemies/fly.png");
fly->pos_Fly_ecran.x=0;
fly->pos_Fly_ecran.y=440;
fly->pos_Fly_ecran.w=0;
fly->pos_Fly_ecran.h=0;
fly->pos_Fly_affiche.x=0;
fly->pos_Fly_affiche.y=667;
fly->pos_Fly_affiche.h=132;
fly->pos_Fly_affiche.w=173;
fly->PositionInitiale=4160;
fly->MouvementTimer=0;
fly->EnnemiState=1;
fly->Mouvement=0;
fly->Trajectory=0;



}



void AnimateFlyWhileRunning(Fly *fly)
{

if (SDL_GetTicks() - fly->MouvementTimer >=190)
  {

switch (fly->Trajectory)
{
   case 1: 
       {

         fly->pos_Fly_affiche.y=667;

          if (fly->pos_Fly_affiche.x==600)
        {
             fly->pos_Fly_affiche.x=0;
         }
            else
        { 
             fly->pos_Fly_affiche.x=fly->pos_Fly_affiche.x+200;
         }

       break;
       }

  case -1: 
       {

        fly->pos_Fly_affiche.y=267;

          if (fly->pos_Fly_affiche.x==600)
        {
             fly->pos_Fly_affiche.x=0;
         }
            else
        { 
             fly->pos_Fly_affiche.x=fly->pos_Fly_affiche.x+200;
         }

       break;
       }


}

fly->MouvementTimer=SDL_GetTicks();
}
 
 
}


void Move_Fly(Fly *fly, Egypt *egypt)
{
if (fly->pos_Fly_ecran.x>=4160-egypt->pos_map2_affiche.x)
  {
           fly->Trajectory=-1;
           fly->Mouvement=-3;
 }
if (fly->pos_Fly_ecran.x<3800-egypt->pos_map2_affiche.x)
  {
      fly->Trajectory=1;
      fly->Mouvement=3;
  }

     
}



void CheckForCollisionWithFly(SDL_Surface *screen,Fly *fly,Perso *perso,Egypt *egypt)
{

if (CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,fly->pos_Fly_ecran,fly->pos_Fly_affiche)==1)
{
 if (perso->pos_perso_ecran.y+(perso->pos_perso_affiche.h-7)<=fly->pos_Fly_ecran.y)
  {
 //Mob->pos_IceMob_affiche.x=39;
 //Mob->pos_IceMob_affiche.y=233;
 //SDL_BlitSurface(ennemi->afficher_ennemi, &ennemi->pos_IceMob_affiche, screen,  &ennemi->pos_IceMob_ecran);
  fly->EnnemiState=0;
  perso->EnnemiesKilled++;
  //SDL_FreeSurface(ennemi->afficher_ennemi);

  }
else
  {
   Perso_DeathEgypt(perso,egypt);

  }

}       
} 


void afficher_Fly(SDL_Surface *screen,Fly *fly,  Egypt *egypt,Perso *perso)
{
if (fly->EnnemiState==1)
{

fly->pos_Fly_ecran.x=fly->PositionInitiale-egypt->pos_map2_affiche.x;
fly->PositionInitiale=fly->PositionInitiale+fly->Mouvement;
AnimateFlyWhileRunning(fly);
Move_Fly(fly,egypt);

SDL_BlitSurface(fly->afficher_Fly, &fly->pos_Fly_affiche, screen,  &fly->pos_Fly_ecran);
CheckForCollisionWithFly(screen,fly,perso,egypt);
}


}


void free_Fly(Fly *fly)
{


SDL_FreeSurface(fly->afficher_Fly);
free(fly);
}
