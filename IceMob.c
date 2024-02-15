#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

 


void initialiser_IceMob(IceMob *Mob)
{
 
Mob->afficher_IceMob=IMG_Load("./lvl1Ennemies/IceMob.png");
Mob->pos_IceMob_ecran.x=0;
Mob->pos_IceMob_ecran.y=525;
Mob->pos_IceMob_ecran.w=0;
Mob->pos_IceMob_ecran.h=0;
Mob->pos_IceMob_affiche.x=0;
Mob->pos_IceMob_affiche.y=277;
Mob->pos_IceMob_affiche.h=124;
Mob->pos_IceMob_affiche.w=96;
Mob->PositionInitiale=1880;
Mob->MouvementTimer=0;
Mob->EnnemiState=1;
Mob->Mouvement=0;
Mob->Trajectory=0;




}



void AnimateMobWhileRunning(IceMob *Mob)
{

if (SDL_GetTicks() - Mob->MouvementTimer >=140)
  {

switch (Mob->Trajectory)
{
   case 1: 
       {

         Mob->pos_IceMob_affiche.y=277;

          if (Mob->pos_IceMob_affiche.x==600)
        {
             Mob->pos_IceMob_affiche.x=0;
         }
            else
        { 
             Mob->pos_IceMob_affiche.x=Mob->pos_IceMob_affiche.x+150;
         }

       break;
       }

  case -1: 
       {

         Mob->pos_IceMob_affiche.y=676;

          if (Mob->pos_IceMob_affiche.x==600)
        {
             Mob->pos_IceMob_affiche.x=0;
         }
            else
        { 
             Mob->pos_IceMob_affiche.x=Mob->pos_IceMob_affiche.x+150;
         }

       break;
       }








}

Mob->MouvementTimer=SDL_GetTicks();
}
 
 
}

void Move_Mob(IceMob *Mob, Russia *russia)
{
if (Mob->pos_IceMob_ecran.x>=1880-russia->pos_map1_affiche.x)
  {
           Mob->Trajectory=-1;
           Mob->Mouvement=-3;
 }
if (Mob->pos_IceMob_ecran.x<1630-russia->pos_map1_affiche.x)
  {
      Mob->Trajectory=1;
      Mob->Mouvement=3;
  }

      
}

                                    

void CheckForCollisionWithMob(SDL_Surface *screen,IceMob *Mob,Perso *perso,Russia *russia)
{

if (CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,Mob->pos_IceMob_ecran,Mob->pos_IceMob_affiche)==1)
{
 if (perso->pos_perso_ecran.y+(perso->pos_perso_affiche.h-7)<=Mob->pos_IceMob_ecran.y)
  {
 //Mob->pos_IceMob_affiche.x=39;
 //Mob->pos_IceMob_affiche.y=233;
 //SDL_BlitSurface(ennemi->afficher_ennemi, &ennemi->pos_IceMob_affiche, screen,  &ennemi->pos_IceMob_ecran);
  Mob->EnnemiState=0;
  perso->EnnemiesKilled++;
  //SDL_FreeSurface(ennemi->afficher_ennemi);

  }
else
  {
   Perso_DeathRussia(perso,russia);


  }

 

}
 
                                                           
}  



    

 
   
void afficher_IceMob(SDL_Surface *screen,IceMob *Mob , Russia *russia,Perso *perso)
{
if (Mob->EnnemiState==1)
{

Mob->pos_IceMob_ecran.x=Mob->PositionInitiale-russia->pos_map1_affiche.x;
Mob->PositionInitiale=Mob->PositionInitiale+Mob->Mouvement;
AnimateMobWhileRunning(Mob);
Move_Mob(Mob,russia);

SDL_BlitSurface(Mob->afficher_IceMob, &Mob->pos_IceMob_affiche, screen,  &Mob->pos_IceMob_ecran);
CheckForCollisionWithMob(screen,Mob,perso,russia);
}



}




void free_IceMob(IceMob *Mob)
{


SDL_FreeSurface(Mob->afficher_IceMob);
free(Mob);
}
