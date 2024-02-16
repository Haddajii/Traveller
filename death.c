#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
   
         
void FallOutsideMapRussia(Perso *perso,Russia *russia)
{
  if (perso->pos_perso_ecran.y>=700)
  {
     Perso_DeathRussia(perso,russia);
  }
 
}  


void FallOutsideMapEgypt(Perso *perso,Egypt *egypt)
{
  if (perso->pos_perso_ecran.y>=700)
  {
     Perso_DeathEgypt(perso,egypt);
  }
 
}    


void FallOutsideMapJapan(Perso *perso,Japan *japan)
{
  if (perso->pos_perso_ecran.y>=700)
  {
     Perso_DeathJapan(perso,japan);
  }
 
}                                  
 

void GameOver(SDL_Surface *screen,Perso *perso)
{
int x,y ;

SDL_GetMouseState(&x , &y);
if (perso->vie==0)
{

SDL_BlitSurface(perso->GameOver,NULL,screen,NULL);
SDL_BlitSurface(perso->TryAgain,NULL,screen,&perso->pos_TryAgain_ecran);
if ((y>=590 && y<=590+perso->TryAgain->h)&&(x>=496 && x<=496+perso->TryAgain->w))
{
SDL_BlitSurface(perso->TryAgainSelected,NULL,screen,&perso->pos_TryAgain_ecran);

}
SDL_BlitSurface(perso->QuitGame,NULL,screen,&perso->pos_QuitGame_ecran);
if ((y>=650 && y<=650+perso->QuitGame->h)&&(x>=496 && x<=496+perso->QuitGame->w))
{
SDL_BlitSurface(perso->QuitGameSelected,NULL,screen,&perso->pos_QuitGame_ecran);

}

} 

        
}                        


void ClickWhileGameOverRussia(SDL_Event event,Perso *perso,int *GameState,int *Reinitialisation_lvl1)
{

if (perso->vie==0)
{ 
  
     
    if ((event.button.x>=496 && event.button.x<=496+perso->TryAgain->w) && (event.button.y>=590 && event.button.y<=590+perso->TryAgain->h))
  {
     *Reinitialisation_lvl1=0;
  }
   if ((event.button.x>=496 && event.button.x<=496+perso->QuitGame->w) && (event.button.y>=650 && event.button.y<=650+perso->QuitGame->h))
  {
     *GameState=0;
  }



}


}



void ClickWhileGameOverEgypt(SDL_Event event,Perso *perso,int *GameState,int *Reinitialisation_lvl2)
{

if (perso->vie==0)
{ 
  
                                      
    if ((event.button.x>=496 && event.button.x<=496+perso->TryAgain->w) && (event.button.y>=590 && event.button.y<=590+perso->TryAgain->h))
  {
     *Reinitialisation_lvl2=0;
  }
   if ((event.button.x>=496 && event.button.x<=496+perso->QuitGame->w) && (event.button.y>=650 && event.button.y<=650+perso->QuitGame->h))
  {
     *GameState=0;
  }


}
}


void ClickWhileGameOverJapan(SDL_Event event,Perso *perso,int *GameState,int *Reinitialisation_lvl3)
{

if (perso->vie==0)
{ 
  
     
    if ((event.button.x>=496 && event.button.x<=496+perso->TryAgain->w) && (event.button.y>=590 && event.button.y<=590+perso->TryAgain->h))
  {
     *Reinitialisation_lvl3=0;
  }
   if ((event.button.x>=496 && event.button.x<=496+perso->QuitGame->w) && (event.button.y>=650 && event.button.y<=650+perso->QuitGame->h))
  {
     *GameState=0;
  }


}
}
