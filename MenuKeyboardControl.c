#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



void KeyMenuBoardHandling(SDL_Event event , menu *menu)
{
switch(menu->KeyState)
{
case 0:
  {
    if ((event.key.keysym.sym==SDLK_RIGHT) || (event.key.keysym.sym==SDLK_LEFT))
           {
              Mix_PlayChannel(-1,menu->bref,0);
              menu->KeyState=1;
                

            }
      break;
  }
case 1 :
   {
      if (event.key.keysym.sym==SDLK_RIGHT)
          {
           Mix_PlayChannel(-1,menu->bref,0);
           menu->KeyState=2;
           
          }
      else if (event.key.keysym.sym==SDLK_LEFT) 
          {
          Mix_PlayChannel(-1,menu->bref,0);
           menu->KeyState=4;
            

           }
   break;


   }

case 2 :
   {
      if (event.key.keysym.sym==SDLK_RIGHT)
          {
           Mix_PlayChannel(-1,menu->bref,0);
           menu->KeyState=3;
           
          }
      else if (event.key.keysym.sym==SDLK_LEFT) 
          {
            Mix_PlayChannel(-1,menu->bref,0);
           menu->KeyState=1;
         

           }

      break;

   }

case 3 :
   {
      if (event.key.keysym.sym==SDLK_RIGHT)
          {
           Mix_PlayChannel(-1,menu->bref,0);
           menu->KeyState=4;
         
          }
      else if (event.key.keysym.sym==SDLK_LEFT) 
          {
            Mix_PlayChannel(-1,menu->bref,0);
           menu->KeyState=2;
        

           }
       break;

   }

case 4 :
   {
      if (event.key.keysym.sym==SDLK_RIGHT)
          {
             Mix_PlayChannel(-1,menu->bref,0);
           menu->KeyState=1;
           
          }
      else if (event.key.keysym.sym==SDLK_LEFT) 
          {
           Mix_PlayChannel(-1,menu->bref,0);
           menu->KeyState=3;
       

           }
     break;



   }





}


}


void KeyBoardOptionHandling(SDL_Event event , menu *menu)
{
switch(menu->OptionKeyState)
{
case 0:
  {
    if ((event.key.keysym.sym==SDLK_UP) || (event.key.keysym.sym==SDLK_DOWN))
           {
              Mix_PlayChannel(-1,menu->bref,0);
              menu->OptionKeyState=1;
                

            }
      break;
  }
case 1 :
   {
      if (event.key.keysym.sym==SDLK_DOWN)
          {
           Mix_PlayChannel(-1,menu->bref,0);
           menu->OptionKeyState=2;
           
          }
      else if (event.key.keysym.sym==SDLK_UP) 
          {
          Mix_PlayChannel(-1,menu->bref,0);
           menu->OptionKeyState=3;
            

           }
   break;


   }

case 2 :
   {
      if (event.key.keysym.sym==SDLK_DOWN)
          {
           Mix_PlayChannel(-1,menu->bref,0);
           menu->OptionKeyState=3;
           
          }
      else if (event.key.keysym.sym==SDLK_UP) 
          {
            Mix_PlayChannel(-1,menu->bref,0);
           menu->OptionKeyState=1;
         

           }

      break;

   }

case 3 :
   {
      if (event.key.keysym.sym==SDLK_DOWN)
          {
           Mix_PlayChannel(-1,menu->bref,0);
           menu->OptionKeyState=1;
         
          }
      else if (event.key.keysym.sym==SDLK_UP) 
          {
            Mix_PlayChannel(-1,menu->bref,0);
           menu->OptionKeyState=2;
        

           }
       break;

   }


       




}

  
}

void PressToEnterGame(SDL_Event event,menu *menu,int *GameState,int *MenuScreenLoaded,int *GameScreenLoaded,int *Reinitialisation_lvl1,int *MusicMenu,int *MusicGame)
{
  if (event.key.keysym.sym==SDLK_RETURN && menu->KeyState==1)
  {		 
      
      *GameState=10;   
      *MenuScreenLoaded=0;
      *GameScreenLoaded=0;
      *Reinitialisation_lvl1=0;
       *MusicMenu=0;
       *MusicGame=0;
      
  }
      
 
}

void PressToContinueGame(SDL_Event event,menu *menu,int *GameState,int *MenuScreenLoaded,int *GameScreenLoaded,int *Continue_lvl1,int *Continue_lvl2,int *Continue_lvl3,int *MusicMenu,int *MusicGame)
{
  if (event.key.keysym.sym==SDLK_RETURN && menu->KeyState==2)
  {		 
      FILE *f;
    f=fopen("./lvl1/RussiaSave.txt","r");
     if (f==NULL)
        printf("failed to open file\n");
     else
     { 
       fscanf(f,"GameState:%d\n",GameState);
       fclose(f);
   
     }
     *MenuScreenLoaded=0;
      *GameScreenLoaded=0;
    if (*GameState==1) 
       {
      *Continue_lvl1=0;
       }
    else if (*GameState==4)
        {
        *Continue_lvl2=0;
        }
    else if (*GameState==6)
        {

          *Continue_lvl3=0;
         }
     *MusicMenu=0;
     *MusicGame=0;
                        
      
  }
 

} 

void PressToQuitGame(SDL_Event event,menu *menu,int *boucle)
{
 if (event.key.keysym.sym==SDLK_RETURN && menu->KeyState==4)
  {		
      *boucle=0;
  }

}

void PressToEnterOptions(SDL_Event event, menu *menu)
{

 if (event.key.keysym.sym==SDLK_RETURN && menu->KeyState==3)
       menu->MenuState=1;
  
}
void PressToEnterVolume(SDL_Event event, menu *menu)
{
 if (event.key.keysym.sym==SDLK_RETURN && menu->OptionKeyState==1)
      menu->MenuState=2;

}
void PressToQuitOptions(SDL_Event event, menu *menu)
{
if (event.key.keysym.sym==SDLK_ESCAPE)
   menu->MenuState=0;
    

}

void PressToQuitVolume(SDL_Event event, menu *menu)
{
if (event.key.keysym.sym==SDLK_ESCAPE)
   menu->MenuState=1;
    
  
} 


void KeyboardHandling(SDL_Event event , menu *menu,int *boucle,int *GameState,int *MenuScreenLoaded,int *GameScreenLoaded,int *Reinitialisation_lvl1,int *Continue_lvl1,int *Continue_lvl2,int *Continue_lvl3,int *MusicMenu,int *MusicGame)
{
switch (menu->MenuState)
{ 
case 0:
   {
  PressToEnterGame(event,menu,GameState,MenuScreenLoaded,GameScreenLoaded,Reinitialisation_lvl1,MusicMenu,MusicGame);
PressToContinueGame(event,menu,GameState,MenuScreenLoaded,GameScreenLoaded,Continue_lvl1,Continue_lvl2,Continue_lvl3,MusicMenu,MusicGame);
  PressToQuitGame(event,menu,boucle);
  PressToEnterOptions(event, menu);
  KeyMenuBoardHandling(event , menu);
     break;
   }
case 1:
  {                 
   PressToQuitOptions(event,menu);
   PressToEnterVolume(event, menu);
   KeyBoardOptionHandling(event ,menu);
   break;


 }
case 2:
   {


      PressToQuitVolume(event, menu);
     break;
   }





}
}







