#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
 
       

 
void initialiser_Hunter(Hunter *hunter)
{
 
hunter->afficher_Hunter=IMG_Load("./lvl1Ennemies/Hunter.png");
hunter->pos_Hunter_ecran.x=0;
hunter->pos_Hunter_ecran.y=511;
hunter->pos_Hunter_ecran.w=0;
hunter->pos_Hunter_ecran.h=0;
hunter->pos_Hunter_affiche.x=0;
hunter->pos_Hunter_affiche.y=660;
hunter->pos_Hunter_affiche.h=140;
hunter->pos_Hunter_affiche.w=93;
hunter->PositionInitiale=3700;
hunter->MouvementTimer=0;
hunter->EnnemiState=1;
hunter->Mouvement=0;
hunter->Trajectory=0;
hunter->Following=0;




}


void AnimateHunterWhileRunning(Hunter *hunter)
{

if (SDL_GetTicks() - hunter->MouvementTimer >=140)
  {

switch (hunter->Trajectory)
{
   case 1: 
       {

         hunter->pos_Hunter_affiche.y=660;

          if (hunter->pos_Hunter_affiche.x==600)
        {
             hunter->pos_Hunter_affiche.x=0;
         }
            else
        { 
             hunter->pos_Hunter_affiche.x=hunter->pos_Hunter_affiche.x+150;
         }

       break;
       }

  case -1: 
       {

         hunter->pos_Hunter_affiche.y=260;

          if (hunter->pos_Hunter_affiche.x==600)
        {
             hunter->pos_Hunter_affiche.x=0;
         }
            else
        { 
             hunter->pos_Hunter_affiche.x=hunter->pos_Hunter_affiche.x+150;
         }

       break;
       }



    


     

}

hunter->MouvementTimer=SDL_GetTicks();
}
 
 
}


void Hunter_States(Hunter *hunter,Russia *russia,Perso *perso)
{
 if (93<(perso->pos_perso_ecran.x-hunter->pos_Hunter_ecran.x) && (perso->pos_perso_ecran.x-hunter->pos_Hunter_ecran.x)<200)
{
    hunter->Following=1;

}
else 
{

   hunter->Following=0;

}






}
 
 
void Move_Hunter(Hunter *hunter, Russia *russia)
{
switch(hunter->Following)
{
  case 0: 
   {

        if (hunter->pos_Hunter_ecran.x>=3700-russia->pos_map1_affiche.x)
            {
                hunter->Trajectory=-1;
                 hunter->Mouvement=-2;
             }
        if (hunter->pos_Hunter_ecran.x<3450-russia->pos_map1_affiche.x)
         {
            hunter->Trajectory=1;
            hunter->Mouvement=2;
        }
           break;
     }
   case 1:
     {
                            
        if (hunter->pos_Hunter_ecran.x<=4130-russia->pos_map1_affiche.x)
           {
             hunter->Trajectory=1;
             hunter->Mouvement=3;

           }
        else
            {
             hunter->Trajectory=0;
             hunter->Mouvement=0;

            }



      }


} 
} 
 

void CheckForCollisionWithHunter(SDL_Surface *screen,Hunter *hunter,Perso *perso,Russia *russia)
{

if (CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,hunter->pos_Hunter_ecran,hunter->pos_Hunter_affiche)==1)
{
 if (perso->pos_perso_ecran.y+(perso->pos_perso_affiche.h-7)<=hunter->pos_Hunter_ecran.y)
  {
 //Mob->pos_IceMob_affiche.x=39;
 //Mob->pos_IceMob_affiche.y=233;
 //SDL_BlitSurface(ennemi->afficher_ennemi, &ennemi->pos_IceMob_affiche, screen,  &ennemi->pos_IceMob_ecran);
  hunter->EnnemiState=0;
  perso->EnnemiesKilled++;
  //SDL_FreeSurface(ennemi->afficher_ennemi);

  }     
else              
  {
    Perso_DeathRussia(perso,russia);

  }

 
          
}               


}    
   
 
void afficher_Hunter(SDL_Surface *screen,Hunter *hunter , Russia *russia,Perso *perso)
{
if (hunter->EnnemiState==1)
{

hunter->pos_Hunter_ecran.x=hunter->PositionInitiale-russia->pos_map1_affiche.x;
hunter->PositionInitiale=hunter->PositionInitiale+hunter->Mouvement;
Hunter_States(hunter,russia,perso);
AnimateHunterWhileRunning(hunter);
Move_Hunter(hunter,russia);

SDL_BlitSurface(hunter->afficher_Hunter, &hunter->pos_Hunter_affiche, screen,  &hunter->pos_Hunter_ecran);
CheckForCollisionWithHunter(screen,hunter,perso,russia);
}



}


void free_Hunter(Hunter *hunter)
{


SDL_FreeSurface(hunter->afficher_Hunter);
free(hunter);
}
