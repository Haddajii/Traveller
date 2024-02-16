#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

        
void initialiser_Fox(Fox *fox)
{
   
fox->afficher_Fox=IMG_Load("./lvl3Ennemies/Fox.png");
fox->pos_Fox_ecran.x=0;
fox->pos_Fox_ecran.y=505;
fox->pos_Fox_ecran.w=0;
fox->pos_Fox_ecran.h=0;
fox->pos_Fox_affiche.x=0;
fox->pos_Fox_affiche.y=495;
fox->pos_Fox_affiche.h=105;
fox->pos_Fox_affiche.w=190;
fox->PositionInitiale=6200;
fox->MouvementTimer=0;
fox->EnnemiState=1;
fox->Mouvement=0;
fox->Trajectory=0;
fox->Following=0;


    
} 



void AnimateFoxWhileRunning(Fox *fox)
{

if (SDL_GetTicks() - fox->MouvementTimer >=180)
  {

switch (fox->Trajectory)
{
   case 1: 
       {

         fox->pos_Fox_affiche.y=495;

          if (fox->pos_Fox_affiche.x==880)
        {
             fox->pos_Fox_affiche.x=0;
         }
            else
        { 
             fox->pos_Fox_affiche.x=fox->pos_Fox_affiche.x+220;
         }
       break;
       }

  case -1: 
       {

        fox->pos_Fox_affiche.y=198;

          if (fox->pos_Fox_affiche.x==880)
        {
             fox->pos_Fox_affiche.x=0;
         }
            else
        { 
             fox->pos_Fox_affiche.x=fox->pos_Fox_affiche.x+220;
         }

       break;
       }

}

fox->MouvementTimer=SDL_GetTicks();
}

}




void Fox_States(Fox *fox,Japan *japan,Perso *perso)
{
 if (205<(perso->pos_perso_ecran.x-fox->pos_Fox_ecran.x) && (perso->pos_perso_ecran.x-fox->pos_Fox_ecran.x)<320)
{
    fox->Following=1;

}
else 
{

   fox->Following=0;

}






}




void Move_Fox(Fox *fox, Japan *japan)
{
switch(fox->Following)
{
  case 0: 
   {

        if (fox->pos_Fox_ecran.x>=6200-japan->pos_map3_affiche.x)
            {
                fox->Trajectory=-1;
                 fox->Mouvement=-3;
             }
        if (fox->pos_Fox_ecran.x<5920-japan->pos_map3_affiche.x)
         {
            fox->Trajectory=1;
            fox->Mouvement=3;
        }
           break;
     }
   case 1:
     {
                            
        if (fox->pos_Fox_ecran.x<=6600-japan->pos_map3_affiche.x)
           {
             fox->Trajectory=1;
             fox->Mouvement=5;

           }
        else
            {
             fox->Trajectory=0;
             fox->Mouvement=0;

            }

      }


}       
}        



void CheckForCollisionWithFox(SDL_Surface *screen,Fox *fox,Perso *perso,Japan *japan)
{

if (CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,fox->pos_Fox_ecran,fox->pos_Fox_affiche)==1)
{
 if (perso->pos_perso_ecran.y+(perso->pos_perso_affiche.h-10)<=fox->pos_Fox_ecran.y)
  {
 //Mob->pos_IceMob_affiche.x=39;
 //Mob->pos_IceMob_affiche.y=233;
 //SDL_BlitSurface(ennemi->afficher_ennemi, &ennemi->pos_IceMob_affiche, screen,  &ennemi->pos_IceMob_ecran);
  fox->EnnemiState=0;
  perso->EnnemiesKilled++;
  //SDL_FreeSurface(ennemi->afficher_ennemi);

  }
else
  {
   Perso_DeathJapan(perso,japan);         

  }
 
}        
} 


void afficher_Fox(SDL_Surface *screen,Fox *fox , Japan *japan,Perso *perso)
{
if (fox->EnnemiState==1)
{

fox->pos_Fox_ecran.x=fox->PositionInitiale-japan->pos_map3_affiche.x;
fox->PositionInitiale=fox->PositionInitiale+fox->Mouvement;
Fox_States(fox,japan,perso);
AnimateFoxWhileRunning(fox);
Move_Fox(fox,japan);

SDL_BlitSurface(fox->afficher_Fox, &fox->pos_Fox_affiche, screen,  &fox->pos_Fox_ecran);
CheckForCollisionWithFox(screen,fox,perso,japan);
}


}









void free_Fox(Fox *fox)
{


SDL_FreeSurface(fox->afficher_Fox);
free(fox);
}
