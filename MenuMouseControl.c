#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>   
  

 
void SoundFXSliderControl(menu *menu,SDL_Event event) 
{
   if ( menu->MenuState==2)
 {
     if((event.button.button==SDL_BUTTON_LEFT && ((event.motion.y>=SCREEN_H/1.75 && event.motion.y<=(SCREEN_H/1.75)+menu->volume.imgplus->h) && (event.motion.x>SCREEN_W/1.43 && event.motion.x<=(SCREEN_W/1.43)+menu->volume.imgplus->w))))
 {
   switch(menu->SoundFXSliderState)
   {

      case 0:
           {
             menu->SoundFXSliderState=1;
             menu->SonBrefControler=9;
 	     break;
           }
	case 1:
           {
            menu->SoundFXSliderState=2;
	    menu->SonBrefControler=12;
 	     break;
           }
 	case -2:
           {
            menu->SoundFXSliderState=-1;
	     	    menu->SonBrefControler=3;
 	     break;
           }
 	case -1:
           {
             menu->SoundFXSliderState=0;

 	     break;
           }
     }
 	   
 	
   }

if((event.button.button==SDL_BUTTON_LEFT && ((event.motion.y>=SCREEN_H/1.67 && event.motion.y<=(SCREEN_H/1.67)+menu->volume.imgmoins->h) && (event.motion.x>SCREEN_W/1.6 && event.motion.x<=(SCREEN_W/1.6)+menu->volume.imgmoins->w))))
{

switch(menu->SoundFXSliderState)
   { 

      case 0:
           {
             menu->SoundFXSliderState=-1;
            	    menu->SonBrefControler=3;
 	     break;
           }
	case 1:
           {
            menu->SoundFXSliderState=0;

 	     break;
           }
 	case 2:
           {
            menu->SoundFXSliderState=1;
	    menu->SonBrefControler=9;
 	     break;
           }
 	case -1:
           {
             menu->SoundFXSliderState=-2;
	    menu->SonBrefControler=0;
 	     break;
           }
     }






}
Mix_VolumeChunk(menu->bref,menu->SonBrefControler*10);

  }




}



void MusicSliderControl(menu *menu,SDL_Event event)
{

if ( menu->MenuState==2)
 {
     if((event.button.button==SDL_BUTTON_LEFT && ((event.motion.y>=SCREEN_H/2.55 && event.motion.y<=(SCREEN_H/2.55)+menu->volume.imgplus->h) && (event.motion.x>SCREEN_W/1.43 && event.motion.x<=(SCREEN_W/1.43)+menu->volume.imgplus->w)) ))
 {
   switch(menu->MusicSliderState)
   {

      case 0:
           {
             menu->MusicSliderState=1;
	     Mix_VolumeMusic(MIX_MAX_VOLUME/2);
 	     break;
           }
	case 1:
           {
            menu->MusicSliderState=2;
	    Mix_VolumeMusic(MIX_MAX_VOLUME);
 	     break;
           }
 	case -2:
           {
            menu->MusicSliderState=-1;
	     Mix_VolumeMusic(MIX_MAX_VOLUME/4);
 	     break;
           }
 	case -1:
           {
             menu->MusicSliderState=0;
	     Mix_VolumeMusic(MIX_MAX_VOLUME/3);
 	     break;
           }
     }
 	
 	
   }

if((event.button.button==SDL_BUTTON_LEFT && ((event.motion.y>=SCREEN_H/2.38 && event.motion.y<=(SCREEN_H/2.38)+menu->volume.imgmoins->h) && (event.motion.x>SCREEN_W/1.6 && event.motion.x<=(SCREEN_W/1.6)+menu->volume.imgmoins->w))))
{

switch(menu->MusicSliderState)
   {

      case 0:
           {
             menu->MusicSliderState=-1;
            Mix_VolumeMusic(MIX_MAX_VOLUME/4);
 	     break;
           }
	case 1:
           {
            menu->MusicSliderState=0;
           Mix_VolumeMusic(MIX_MAX_VOLUME/3);
 	     break;
           }
 	case 2:
           {
            menu->MusicSliderState=1;
           Mix_VolumeMusic(MIX_MAX_VOLUME/2);
 	     break;
           }
 	case -1:
           {
             menu->MusicSliderState=-2;
          Mix_VolumeMusic(0);
 	     break;
           }
     }






}

  }

}



void SonBrefControlButtonNewGame(SDL_Event event,menu *menu)
{
if (((event.motion.y>=SCREEN_H/1.18569 && event.motion.y<= (SCREEN_H/1.18569)+menu->button.imgbtn1->h)&&(event.motion.x>=SCREEN_W/4.34242 && event.motion.x<=(SCREEN_W/4.34242)+menu->button.imgbtn1->w)) && menu->button.SonBrefButtonNewGame==0)
 {

  Mix_PlayChannel(-1,menu->bref,0);
  menu->button.SonBrefButtonNewGame=1;
 }

   if(!((event.motion.y>=SCREEN_H/1.18569 && event.motion.y<= (SCREEN_H/1.18569)+menu->button.imgbtn1->h)&&(event.motion.x>=SCREEN_W/4.34242 && event.motion.x<=(SCREEN_W/4.34242)+menu->button.imgbtn1->w)))
	menu->button.SonBrefButtonNewGame=0;
    

}

void SonBrefControlButtonContinue(SDL_Event event,menu *menu)
{

if((event.motion.y>=SCREEN_H/1.17851 && event.motion.y<= (SCREEN_H/1.17851)+menu->button.imgbtn2->h)&&(event.motion.x>=SCREEN_W/2.38833 && event.motion.x<=(SCREEN_W/2.38833)+menu->button.imgbtn2->w) && menu->button.SonBrefButtonContinue==0 )
 {
  Mix_PlayChannel(-1,menu->bref,0);
  menu->button.SonBrefButtonContinue=1;

 }
if(!((event.motion.y>=SCREEN_H/1.17851 && event.motion.y<= (SCREEN_H/1.17851)+menu->button.imgbtn2->h)&&(event.motion.x>=SCREEN_W/2.38833 && event.motion.x<=(SCREEN_W/2.38833)+menu->button.imgbtn2->w)))
	menu->button.SonBrefButtonContinue=0;

}
void SonBrefControlButtonOptions(SDL_Event event,menu *menu)
{

if((event.motion.y>=SCREEN_H/1.18389 && event.motion.y<= (SCREEN_H/1.18389)+menu->button.imgbtn3->h)&&(event.motion.x>=SCREEN_W/1.64712 && event.motion.x<=(SCREEN_W/1.64712)+menu->button.imgbtn3->w) && menu->button.SonBrefButtonOptions==0 )
 {
  Mix_PlayChannel(-1,menu->bref,0);
  menu->button.SonBrefButtonOptions=1;

 }
if(!((event.motion.y>=SCREEN_H/1.18389 && event.motion.y<= (SCREEN_H/1.18389)+menu->button.imgbtn3->h)&&(event.motion.x>=SCREEN_W/1.64712 && event.motion.x<=(SCREEN_W/1.64712)+menu->button.imgbtn3->w)))
	menu->button.SonBrefButtonOptions=0;

}
void SonBrefControlButtonExit(SDL_Event event,menu *menu)
{

if((event.motion.y>=SCREEN_H/1.189312 && event.motion.y<=(SCREEN_H/1.189312)+menu->button.imgbtn4->h)&&(event.motion.x>=SCREEN_W/1.25701 && event.motion.x<=(SCREEN_W/1.25701)+menu->button.imgbtn4->w) && menu->button.SonBrefButtonExit==0)
 {
  Mix_PlayChannel(-1,menu->bref,0);
  menu->button.SonBrefButtonExit=1;

 }
if(!((event.motion.y>=SCREEN_H/1.189312 && event.motion.y<=(SCREEN_H/1.189312)+menu->button.imgbtn4->h)&&(event.motion.x>=SCREEN_W/1.25701 && event.motion.x<=(SCREEN_W/1.25701)+menu->button.imgbtn4->w)))
	menu->button.SonBrefButtonExit=0;

}

void SonBrefControlButtonVolume(SDL_Event event,menu *menu)
{
if((event.motion.y>=SCREEN_H/3.7 && event.motion.y<=(SCREEN_H/3.7)+menu->button.imgbtnvolume->h)&&(event.motion.x>=SCREEN_W/2.38833 && event.motion.x<=(SCREEN_W/2.38833)+menu->button.imgbtnvolume->w) && menu->button.SonBrefButtonVolume==0)
{
Mix_PlayChannel(-1,menu->bref,0);
  menu->button.SonBrefButtonVolume=1;

}

if (!((event.motion.y>=SCREEN_H/3.7 && event.motion.y<= (SCREEN_H/3.7)+menu->button.imgbtnvolume->h)&&(event.motion.x>=SCREEN_W/2.38833 && event.motion.x<=(SCREEN_W/2.38833)+menu->button.imgbtnvolume->w)))
	menu->button.SonBrefButtonVolume=0;





}

void SonBrefControlButtonFullScreen(SDL_Event event,menu *menu)
{
if((event.motion.y>=SCREEN_H/2.22571 && event.motion.y<=(SCREEN_H/2.22571)+ menu->button.imgbtnfullscreen->h)&&(event.motion.x>=SCREEN_W/2.38833 && event.motion.x<=(SCREEN_W/2.38833)+ menu->button.imgbtnfullscreen->w)&& menu->button.SonBrefButtonFullScreen==0)
{
Mix_PlayChannel(-1,menu->bref,0);
  menu->button.SonBrefButtonFullScreen=1;

}

if(!((event.motion.y>=SCREEN_H/2.22571 && event.motion.y<= (SCREEN_H/2.22571)+ menu->button.imgbtnfullscreen->h)&&(event.motion.x>=SCREEN_W/2.38833 && event.motion.x<=(SCREEN_W/2.38833)+ menu->button.imgbtnfullscreen->w)))
	menu->button.SonBrefButtonFullScreen=0;


}

void SonBrefControlButtonWindowed(SDL_Event event,menu *menu)
{
if((event.motion.y>=SCREEN_H/1.58 && event.motion.y<=(SCREEN_H/1.58)+ menu->button.imgbtnwindowed->h)&&(event.motion.x>=SCREEN_W/2.38833 && event.motion.x<=(SCREEN_W/2.38833)+menu->button.imgbtnwindowed->w)&& menu->button.SonBrefButtonWindowed==0)
{
Mix_PlayChannel(-1,menu->bref,0);
  menu->button.SonBrefButtonWindowed=1;

}

if(!((event.motion.y>=SCREEN_H/1.58 && event.motion.y<= (SCREEN_H/1.58)+ menu->button.imgbtnwindowed->h)&&(event.motion.x>=SCREEN_W/2.38833 && event.motion.x<=(SCREEN_W/2.38833)+ menu->button.imgbtnwindowed->w)))
	menu->button.SonBrefButtonWindowed=0;


}

void SonBrefControlButtonX(SDL_Event event,menu *menu)
{
if((event.motion.y>=SCREEN_H/7.41904 && event.motion.y<=(SCREEN_H/7.41904)+ menu->button.imgbtnx->h)&&(event.motion.x>=SCREEN_W/1.38454 && event.motion.x<=(SCREEN_W/1.38454)+menu->button.imgbtnx->w)&& menu->button.SonBrefButtonX==0)
{
Mix_PlayChannel(-1,menu->bref,0);
  menu->button.SonBrefButtonX=1;

}

if(!((event.motion.y>=SCREEN_H/7.41904 && event.motion.y<= (SCREEN_H/7.41904)+ menu->button.imgbtnx->h)&&(event.motion.x>=SCREEN_W/1.38454 && event.motion.x<=(SCREEN_W/1.38454)+ menu->button.imgbtnx->w)))
	menu->button.SonBrefButtonX=0;
 

}
void SonBrefControlButtonBack(SDL_Event event,menu *menu)
{
if((event.motion.y>=SCREEN_H/1.33 && event.motion.y<=(SCREEN_H/1.33)+ menu->button.imgbtnback->h)&&(event.motion.x>=SCREEN_W/2.25 && event.motion.x<=(SCREEN_W/2.25)+menu->button.imgbtnback->w)&& menu->button.SonBrefButtonBack==0)
{
Mix_PlayChannel(-1,menu->bref,0);
  menu->button.SonBrefButtonBack=1;

}

if(!((event.motion.y>=SCREEN_H/1.33 && event.motion.y<= (SCREEN_H/1.33)+ menu->button.imgbtnback->h)&&(event.motion.x>=SCREEN_W/2.25 && event.motion.x<=(SCREEN_W/2.25)+ menu->button.imgbtnback->w)))
	menu->button.SonBrefButtonBack=0;


}

void SonBrefControlAllButtons(SDL_Event event,menu *menu)
{
switch (menu->MenuState)
{
case 0:
    {
       SonBrefControlButtonNewGame(event,menu);
       SonBrefControlButtonContinue(event,menu);
      SonBrefControlButtonOptions(event,menu);
       SonBrefControlButtonExit( event,menu);
      break;

    }
case 1:
    {
      SonBrefControlButtonVolume(event,menu);
      SonBrefControlButtonFullScreen(event,menu);
      SonBrefControlButtonWindowed(event,menu);
      SonBrefControlButtonX(event ,menu);
     break;
    }
case 2:
     {
        SonBrefControlButtonX(event,menu);
       SonBrefControlButtonBack(event,menu);
       break;

     }

}


}

void Press_NewGameButton(SDL_Event event,menu *menu,int *GameState,int *MenuScreenLoaded,int *GameScreenLoaded,int *Reinitialisation_trailer,int *MusicMenu,int *MusicGame)
{
  if( (event.motion.y>=SCREEN_H/1.18569 && event.motion.y<=(SCREEN_H/1.18569)+menu->button.imgbtn1->h)&&(event.motion.x>=SCREEN_W/4.34242 && event.motion.x<=(SCREEN_W/4.34242)+menu->button.imgbtn1->w) )
  {
    *GameState=10;  
    *MenuScreenLoaded=0;
    *GameScreenLoaded=0;
    *Reinitialisation_trailer=0;
    *MusicMenu=0;
    *MusicGame=0;
  }


}
 
void Press_ContinueButton(SDL_Event event,menu *menu,int *GameState,int *MenuScreenLoaded,int *GameScreenLoaded,int *Continue_lvl1,int *Continue_lvl2,int *Continue_lvl3,int *MusicMenu,int *MusicGame)
{
if((event.motion.y>=SCREEN_H/1.17851 && event.motion.y<= (SCREEN_H/1.17851)+menu->button.imgbtn2->h)&&(event.motion.x>=SCREEN_W/2.38833 && event.motion.x<=(SCREEN_W/2.38833)+menu->button.imgbtn2->w))
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



void Press_ExitButton(SDL_Event event,menu *menu,int *boucle)
{
  if( (event.motion.y>=SCREEN_H/1.189312 && event.motion.y<=(SCREEN_H/1.189312)+menu->button.imgbtn4->h)&&(event.motion.x>=SCREEN_W/1.25701 && event.motion.x<=(SCREEN_W/1.25701)+menu->button.imgbtn4->w) )
    *boucle=0;


} 

void Press_OptionButton(SDL_Event event,menu *menu)
{
 if(((event.motion.y>=SCREEN_H/1.18389 && event.motion.y<=(SCREEN_H/1.18389)+menu->button.imgbtn3->h) && (event.motion.x>=SCREEN_W/1.64712 && event.motion.x<=(SCREEN_W/1.64712)+menu->button.imgbtn3->w)))
    menu->MenuState=1;


}

void Press_XButton(SDL_Event event,menu *menu)
{
 if(event.button.button==SDL_BUTTON_LEFT && ((event.motion.y>=SCREEN_H/7.41904 && event.motion.y<=(SCREEN_H/7.41904)+menu->button.imgbtnx->h) && (event.motion.x>=SCREEN_W/1.38454 && event.motion.x<=(SCREEN_W/1.38454)+menu->button.imgbtnx->w)))
    menu->MenuState=0;

 
}

void Press_FullScreenButton(SDL_Event event,menu *menu)
{
 if(((event.motion.y>=SCREEN_H/2.22571 && event.motion.y<=(SCREEN_H/2.22571)+menu->button.imgbtnfullscreen->h) && (event.motion.x>=SCREEN_W/2.38833 && event.motion.x<=(SCREEN_W/2.38833)+menu->button.imgbtnfullscreen->w)) )
    menu->MenuState=3;


}

void Press_VolumeButton(SDL_Event event,menu *menu)
{
 if ( ((event.motion.y>=SCREEN_H/3.7 && event.motion.y<=(SCREEN_H/3.7)+menu->button.imgbtnvolume->h) && (event.motion.x>=SCREEN_W/2.38833 && event.motion.x<=(SCREEN_W/2.38833)+menu->button.imgbtnvolume->w)))
    menu->MenuState=2;

 
}
void Press_BackButton(SDL_Event event,menu *menu)
{
 if (((event.motion.y>=SCREEN_H/1.33 && event.motion.y<=(SCREEN_H/1.33)+menu->button.imgbtnback->h) && (event.motion.x>=SCREEN_W/2.25 && event.motion.x<=(SCREEN_W/2.25)+menu->button.imgbtnback->w)))
    menu->MenuState=1;

    
}        
 
void PressControlAllButtons(SDL_Event event,menu *menu,int *boucle,int *GameState,int *MenuScreenLoaded,int *GameScreenLoaded,int *Reinitialisation_lvl1,int *Continue_lvl1,int *Continue_lvl2,int *Continue_lvl3,int *MusicMenu,int *MusicGame,int *Reinitialisation_trailer )
{
if (event.button.button==SDL_BUTTON_LEFT)
{      
switch (menu->MenuState)
{
 case 0:
    { Press_NewGameButton(event,menu,GameState,MenuScreenLoaded,GameScreenLoaded,Reinitialisation_trailer,MusicMenu,MusicGame);
  Press_ContinueButton(event,menu,GameState,MenuScreenLoaded,GameScreenLoaded,Continue_lvl1,Continue_lvl2,Continue_lvl3,MusicMenu,MusicGame);
      Press_ExitButton(event,menu,boucle);
      Press_OptionButton(event,menu);
      break;
       }
  case 1:   
    {
      Press_XButton(event,menu);
      Press_FullScreenButton(event,menu);
      Press_VolumeButton(event,menu);
     break;


    }
  case 2:
   {
        Press_XButton(event,menu);
   Press_BackButton(event,menu);
    break;


   }



}




}
}



