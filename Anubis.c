#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
         
       
void initialiser_Anubis(Anubis *anubis)
{
   
anubis->afficher_Anubis=IMG_Load("./lvl2Ennemies/anubis.png");
anubis->pos_Anubis_ecran.x=0;
anubis->pos_Anubis_ecran.y=290;
anubis->pos_Anubis_ecran.w=0;
anubis->pos_Anubis_ecran.h=0;
anubis->pos_Anubis_affiche.x=0;
anubis->pos_Anubis_affiche.y=658;
anubis->pos_Anubis_affiche.h=141;
anubis->pos_Anubis_affiche.w=93;
anubis->PositionInitiale=5340;
anubis->MouvementTimer=0;
anubis->EnnemiState=1;
anubis->Mouvement=0;
anubis->Trajectory=0;


    
}

void AnimateAnubisWhileRunning(Anubis *anubis)
{

if (SDL_GetTicks() - anubis->MouvementTimer >=240)
  {

switch (anubis->Trajectory)
{
   case 1: 
       {

         anubis->pos_Anubis_affiche.y=658;

          if (anubis->pos_Anubis_affiche.x==600)
        {
             anubis->pos_Anubis_affiche.x=0;
         }
            else
        { 
             anubis->pos_Anubis_affiche.x=anubis->pos_Anubis_affiche.x+150;
         }

       break;
       }

  case -1: 
       {

        anubis->pos_Anubis_affiche.y=258;

          if (anubis->pos_Anubis_affiche.x==600)
        {
             anubis->pos_Anubis_affiche.x=0;
         }
            else
        { 
             anubis->pos_Anubis_affiche.x=anubis->pos_Anubis_affiche.x+150;
         }

       break;
       }


}

anubis->MouvementTimer=SDL_GetTicks();
}
 
            
}

 



void Move_Anubis(Anubis *anubis, Egypt *egypt)
{
if (anubis->pos_Anubis_ecran.x>=5337-egypt->pos_map2_affiche.x)
  {
           anubis->Trajectory=-1;
           anubis->Mouvement=-3;
 }
if (anubis->pos_Anubis_ecran.x<5066-egypt->pos_map2_affiche.x)
  {
      anubis->Trajectory=1;
      anubis->Mouvement=3;
  }

      
} 


void CheckForCollisionWithAnubis(SDL_Surface *screen,Anubis *anubis,Perso *perso,Egypt *egypt)
{

if (CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,anubis->pos_Anubis_ecran,anubis->pos_Anubis_affiche)==1)
{
 if (perso->pos_perso_ecran.y+(perso->pos_perso_affiche.h-7)<=anubis->pos_Anubis_ecran.y)
  {
 //Mob->pos_IceMob_affiche.x=39;
 //Mob->pos_IceMob_affiche.y=233;
 //SDL_BlitSurface(ennemi->afficher_ennemi, &ennemi->pos_IceMob_affiche, screen,  &ennemi->pos_IceMob_ecran);
  anubis->EnnemiState=0;
  perso->EnnemiesKilled++;
  //SDL_FreeSurface(ennemi->afficher_ennemi);

  }
else
  {
   Perso_DeathEgypt(perso,egypt);

  }
 
}       
} 
   


void afficher_Anubis(SDL_Surface *screen,Anubis *anubis ,  Egypt *egypt,Perso *perso)
{
if (anubis->EnnemiState==1)
{

anubis->pos_Anubis_ecran.x=anubis->PositionInitiale-egypt->pos_map2_affiche.x;
anubis->PositionInitiale=anubis->PositionInitiale+anubis->Mouvement;
AnimateAnubisWhileRunning(anubis);
Move_Anubis(anubis,egypt);

SDL_BlitSurface(anubis->afficher_Anubis, &anubis->pos_Anubis_affiche, screen,  &anubis->pos_Anubis_ecran);
CheckForCollisionWithAnubis(screen,anubis,perso,egypt);
}


}


void free_Anubis(Anubis *anubis)
{


SDL_FreeSurface(anubis->afficher_Anubis);
free(anubis);
}
