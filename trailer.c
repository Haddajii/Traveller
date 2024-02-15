#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

void initialiser_Trailer(Trailer *trailer)
{     
    
  
trailer->TrailerFrames[0]=IMG_Load("./trailer/trailer1.png");
trailer->TrailerFrames[1]=IMG_Load("./trailer/trailer2.png");
trailer->TrailerFrames[2]=IMG_Load("./trailer/trailer3.png");
trailer->TrailerFrames[3]=IMG_Load("./trailer/trailer4.png");
trailer->TrailerFrames[4]=IMG_Load("./trailer/trailer5.png");
trailer->TrailerFrames[5]=IMG_Load("./trailer/trailer6.png");
trailer->TrailerFrames[6]=IMG_Load("./trailer/trailer7.png");
trailer->TrailerFrames[7]=IMG_Load("./trailer/trailer8.png");
trailer->TrailerFrames[8]=IMG_Load("./trailer/trailer9.png");
trailer->TrailerFrames[9]=IMG_Load("./trailer/trailer10.png");
trailer->TrailerFrames[10]=IMG_Load("./trailer/trailer11.png");
trailer->TrailerFrames[11]=IMG_Load("./trailer/trailer12.png");
trailer->TrailerFrames[12]=IMG_Load("./trailer/trailer13.png");
trailer->TrailerFrames[13]=IMG_Load("./trailer/trailer14.png");
trailer->TrailerFrames[14]=IMG_Load("./trailer/trailer15.png");
trailer->TrailerFrames[15]=IMG_Load("./trailer/trailer16.png");
trailer->DialogueShown=0; 
trailer->AnimationTimer=3;
trailer->StartAnimation=0; 
trailer->music=Mix_LoadMUS("./Music/Trailer.mp3");

                 
      
  
} 



void reinitialiser_Trailer(Trailer *trailer)
{
trailer->DialogueShown=0; 
trailer->AnimationTimer=3;
trailer->StartAnimation=0; 


}


void afficher_Trailer(SDL_Surface *screen,Trailer *trailer,Perso *perso)
{


SDL_Delay(160);


switch (trailer->DialogueShown)
{


    case 0:
      {
  SDL_BlitSurface(trailer->TrailerFrames[0] , NULL , screen,NULL);
  afficher_SpaceBar(screen,perso);
  break;
      }


    case 1:
       {
              SDL_BlitSurface(trailer->TrailerFrames[1] , NULL , screen,NULL);
          break;
  
        }    
    case 2: 
       {
              SDL_BlitSurface(trailer->TrailerFrames[2] , NULL , screen,NULL);
       break;
        } 
    case 3: 
       {
            trailer->StartAnimation=1;
          break;
        }
    

 
}


}

 


void afficher_AnimationTrailer(SDL_Surface *screen,Trailer *trailer,int *GameState,int *MusicGame,int *Reinitialisation_lvl1)
{


if (trailer->AnimationTimer<16)
{
   SDL_Delay(800);
   SDL_BlitSurface(trailer->TrailerFrames[trailer->AnimationTimer] , NULL , screen, NULL);
trailer->AnimationTimer++;
if (trailer->AnimationTimer==16)
{
  *GameState=1;
  *MusicGame=0;
  *Reinitialisation_lvl1=0;
  
}

}


}





void freeTrailer(Trailer *trailer)
{


for (int i=0;i<16;i++)
{
SDL_FreeSurface(trailer->TrailerFrames[i]);
}
Mix_FreeMusic(trailer->music);
free(trailer);
}
