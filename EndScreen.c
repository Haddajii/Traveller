#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

      
 

void initialiser_EndScreen(EndScreen *end)
{  

  
end->EndScreen=IMG_Load("./EndScreen/EndScreen.png");
end->QuitGame=IMG_Load("./EndScreen/QuitGame.png");
end->QuitGameSelected=IMG_Load("./EndScreen/QuitGameSelected.png");
end->pos_QuitGame_ecran.x=480;
end->pos_QuitGame_ecran.y=620;
end->pos_QuitGame_ecran.w=0;
end->pos_QuitGame_ecran.h=0;
end->music=Mix_LoadMUS("./Music/EndScreen.mp3");


}      
 


void afficher_EndScreen(SDL_Surface *screen,EndScreen *end)
{
int x,y ;
 SDL_GetMouseState(&x , &y);
 SDL_BlitSurface(end->EndScreen, NULL, screen,  NULL);
  SDL_BlitSurface(end->QuitGame, NULL, screen,  &end->pos_QuitGame_ecran);
 if ((y>=620 && y<=620+end->QuitGame->h)&&(x>=480 && x<=480+end->QuitGame->w))
{
SDL_BlitSurface(end->QuitGameSelected,NULL,screen,&end->pos_QuitGame_ecran);

}
  
 
  
}
 


void ClickToQuitEndScreen(SDL_Event event,EndScreen *end,int *GameState)
{

if ((event.button.x>=480 && event.button.x<=480+end->QuitGame->w) && (event.button.y>=620 && event.button.y<=620+end->QuitGame->h))
  {
     *GameState=0;
  }





}












void freeEndScreen(EndScreen *end)
{

SDL_FreeSurface(end->EndScreen);
SDL_FreeSurface(end->QuitGame);
SDL_FreeSurface(end->QuitGameSelected);
Mix_FreeMusic(end->music);
free(end);
}
