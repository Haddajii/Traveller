#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>


              
void initialiser_Menu(menu *menu)
{  
   menu->MenuBackground[0]=IMG_Load("./image/1.png");
   menu->MenuBackground[1]=IMG_Load("./image/2.png");
   menu->MenuBackground[2]=IMG_Load("./image/3.png");
   menu->MenuBackground[3]=IMG_Load("./image/4.png");
   menu->MenuBackground[4]=IMG_Load("./image/5.png");
   menu->MenuBackground[5]=IMG_Load("./image/6.png");
   menu->MenuBackground[6]=IMG_Load("./image/7.png");
   menu->MenuBackground[7]=IMG_Load("./image/8.png");
   menu->MenuBackground[8]=IMG_Load("./image/9.png");
   menu->OptionBackground=IMG_Load("./option/screen.png");
   menu->button.imgbtn1=IMG_Load("./buttons/b1.png");
   menu->button.imgbtn1s=IMG_Load("./buttons/b1-bis.png");
   menu->button.imgbtn2=IMG_Load("./buttons/b2.png");
   menu->button.imgbtn2s=IMG_Load("./buttons/b2-bis.png");
   menu->button.imgbtn3=IMG_Load("./buttons/b3.png");
   menu->button.imgbtn3s=IMG_Load("./buttons/b3-bis.png");
   menu->button.imgbtn4=IMG_Load("./buttons/b4.png");
   menu->button.imgbtn4s=IMG_Load("./buttons/b4-bis.png");
   menu->button.imgtxt=IMG_Load("logo.png");
   menu->button.imgbtnx=IMG_Load("./option/x.png");
   menu->button.imgbtnxs=IMG_Load("./option/x-bis.png");
   menu->button.imgbtnfullscreen=IMG_Load("./option/fullscreen.png");
   menu->button.imgbtnfullscreens=IMG_Load("./option/fullscreen-bis.png");
   menu->button.imgbtnwindowed=IMG_Load("./option/windowed.png");
    menu->button.imgbtnwindoweds=IMG_Load("./option/windowed-bis.png");
   menu->button.imgbtnvolume=IMG_Load("./option/volume.png");
   menu->button.imgbtnvolumes=IMG_Load("./option/volume-bis.png");
   menu->button.imgbtnback=IMG_Load("./option/back.png");
   menu->button.imgbtnbacks=IMG_Load("./option/back-bis.png");
    menu->volume.imgslider1=IMG_Load("./option/slider1.png");
    menu->volume.imgslider2=IMG_Load("./option/slider2.png");
   menu->volume.imgslider3=IMG_Load("./option/slider3.png");
   menu->volume.imgslider4=IMG_Load("./option/slider4.png");
   menu->volume.imgslider5=IMG_Load("./option/slider5.png");                  
    menu->volume.imgplus=IMG_Load("./option/plus1.png");   
   menu->volume.imgpluss=IMG_Load("./option/plus2.png");
   menu->volume.imgmoins=IMG_Load("./option/minus1.png");
   menu->volume.imgmoinss=IMG_Load("./option/minus2.png");
   menu->pos_OptionBackground_ecran.x=SCREEN_W/7.96111;
   menu->pos_OptionBackground_ecran.y=SCREEN_H/8.6555;
   menu->button.pos_btn1_ecran.x=SCREEN_W/4.34242;
   menu->button.pos_btn1_ecran.y=SCREEN_H/1.18569;
   menu->button.pos_btn2_ecran.x=SCREEN_W/2.38833;
   menu->button.pos_btn2_ecran.y=SCREEN_H/1.17851;
   menu->button.pos_btn3_ecran.x=SCREEN_W/1.64712;
   menu->button.pos_btn3_ecran.y=SCREEN_H/1.18389;
   menu->button.pos_btn4_ecran.x=SCREEN_W/1.25701;
   menu->button.pos_btn4_ecran.y=SCREEN_H/1.189312;
   menu->button.pos_btntxt_ecran.x=SCREEN_W/28.66;
   menu->button.pos_btntxt_ecran.y=SCREEN_H/14.16363;
   menu->button.pos_btnx_ecran.x=SCREEN_W/1.38454;
   menu->button.pos_btnx_ecran.y=SCREEN_H/7.41904;
   menu->button.pos_btnfullscreen_ecran.x=SCREEN_W/2.38833;
   menu->button.pos_btnfullscreen_ecran.y=SCREEN_H/2.22571;
   menu->button.pos_btnwindowed_ecran.x=SCREEN_W/2.38833;
   menu->button.pos_btnwindowed_ecran.y=SCREEN_H/1.58;
   menu->button.pos_btnvolume_ecran.x=SCREEN_W/2.38833;
   menu->button.pos_btnvolume_ecran.y=SCREEN_H/3.7;
   menu->button.pos_btnback_ecran.x=SCREEN_W/2.25;
   menu->button.pos_btnback_ecran.y=SCREEN_H/1.33;
   menu->volume.pos_imgslider_ecran.x=SCREEN_W/2.5;
   menu->volume.pos_imgslider_ecran.y=SCREEN_H/2.5;
   menu->volume.pos_imgslidercopy_ecran.x=SCREEN_W/2.5;
   menu->volume.pos_imgslidercopy_ecran.y=SCREEN_H/1.75;
   menu->volume.pos_plus_ecran.x=SCREEN_W/1.43;
   menu->volume.pos_plus_ecran.y=SCREEN_H/2.55;
   menu->volume.pos_pluscopy_ecran.x=SCREEN_W/1.43;
   menu->volume.pos_pluscopy_ecran.y=SCREEN_H/1.75;
    menu->volume.pos_moins_ecran.x=SCREEN_W/1.6;
   menu->volume.pos_moins_ecran.y=SCREEN_H/2.38;
   menu->volume.pos_moinscopy_ecran.x=SCREEN_W/1.6; 
   menu->volume.pos_moinscopy_ecran.y=SCREEN_H/1.67;
   menu->text.color_txt.r=90;
   menu->text.color_txt.g=0;
   menu->text.color_txt.b=0;
   menu->text.volume_police=TTF_OpenFont("./fonts/VT323-Regular.ttf",90);
   menu->text.music_soundfx_police=TTF_OpenFont("./fonts/VT323-Regular.ttf",70);
   menu->text.facts_police=TTF_OpenFont("./fonts/VT323-Regular.ttf",36);
  menu->text.pos_volumetxt_ecran.x=SCREEN_W/3.42;
  menu->text.pos_volumetxt_ecran.y=SCREEN_H/5,564285;
  menu->text.pos_musictxt_ecran.x=SCREEN_W/4.5;
  menu->text.pos_musictxt_ecran.y=SCREEN_H/2.5;
  menu->text.pos_soundfxtxt_ecran.x=SCREEN_W/5.1;
  menu->text.pos_soundfxtxt_ecran.y=SCREEN_H/1.75;
  menu->text.pos_factstxt_ecran.x=SCREEN_W/6.3;
  menu->text.pos_factstxt_ecran.y=SCREEN_H/1.22;
  menu->MenuState=0;
  menu->MenuKeyState=0;            
  menu->OptionKeyState=0;
  menu-> MusicSliderState=0;
  menu-> SoundFXSliderState=0;
  menu->BackgroundAnimationTimer=0;
  menu->SonBrefControler=6;
  menu->button.SonBrefButtonNewGame=0;
  menu->button.SonBrefButtonContinue=0;
  menu->button.SonBrefButtonOptions=0;
  menu->button.SonBrefButtonVolume=0;
  menu->button.SonBrefButtonWindowed=0;
  menu->button.SonBrefButtonFullScreen=0; 
  menu->button.SonBrefButtonExit=0;
  menu->button.SonBrefButtonX=0;
  menu->button.SonBrefButtonBack=0;
  menu->KeyState=0;
  srand(time(NULL));
  menu->RandomNumber=rand()% 10+1;
  menu->text.volume_txt=TTF_RenderText_Blended(menu->text.volume_police,"Volume Control",menu->text.color_txt);
  menu->text.music_txt=TTF_RenderText_Blended(menu->text.music_soundfx_police,"Music",menu->text.color_txt);
  menu->text.soundfx_txt=TTF_RenderText_Blended(menu->text.music_soundfx_police,"SoundFX",menu->text.color_txt);
  //Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
  menu->music=Mix_LoadMUS("song.mp3");
 // Mix_PlayMusic(menu->music,-1);
  //Mix_VolumeMusic(MIX_MAX_VOLUME/3);
  //Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024);
  menu->bref = Mix_LoadWAV("menus.wav");

   

}

void load_RandomFact(menu *menu)
{
    FILE *f;
    char line[100]; 
     int i;
 
   f=fopen("Facts.txt","r");
   if (f!=NULL) 
    {
    for (i=1;i<(menu->RandomNumber);i++)
    {
     fgets(line, sizeof(line), f) ;
    }
      fgets(line, sizeof(line), f) ;  
    menu->text.facts_txt=TTF_RenderText_Blended(menu->text.facts_police,line,menu->text.color_txt);
      fclose(f);
   }
   else
      {
         printf("impossible d'ouvrir fichier\n");
      }
  
     




  
}

void afficher_menu(SDL_Surface *screen,menu *menu)
{

int x,y ;

SDL_GetMouseState(&x , &y);

if (menu->BackgroundAnimationTimer<9)
{
SDL_BlitSurface(menu->MenuBackground[menu->BackgroundAnimationTimer], NULL, screen, NULL);
menu->BackgroundAnimationTimer++;

}
else
{
menu->BackgroundAnimationTimer=0;

}
switch (menu->MenuState)
{
   case 0:
          { 
              
           SDL_BlitSurface( menu->button.imgbtn1, NULL, screen,  &menu->button.pos_btn1_ecran);
         if (((y>=SCREEN_H/1.18569 && y<= (SCREEN_H/1.18569)+menu->button.imgbtn1s->h)&&(x>=SCREEN_W/4.34242 && x<=(SCREEN_W/4.34242)+menu->button.imgbtn1s->w)) || menu->KeyState==1 )
      {
	SDL_BlitSurface(menu->button.imgbtn1s, NULL, screen,  &menu->button.pos_btn1_ecran);
    
      }
        SDL_BlitSurface( menu->button.imgbtn2, NULL, screen,  &menu->button.pos_btn2_ecran);
  if (((y>=SCREEN_H/1.17851 && y<= (SCREEN_H/1.17851)+menu->button.imgbtn2s->h)&&(x>=SCREEN_W/2.38833 && x<=(SCREEN_W/2.38833)+menu->button.imgbtn2s->w)) || menu->KeyState==2)
      {
        SDL_BlitSurface(menu->button.imgbtn2s, NULL, screen,  &menu->button.pos_btn2_ecran);
      }
   
         SDL_BlitSurface( menu->button.imgbtn3, NULL, screen,  &menu->button.pos_btn3_ecran);
 if (((y>=SCREEN_H/1.18389 && y<= (SCREEN_H/1.18389)+menu->button.imgbtn3s->h)&&(x>=SCREEN_W/1.64712 && x<=(SCREEN_W/1.64712)+menu->button.imgbtn3s->w)) || menu->KeyState==3)
 {
     SDL_BlitSurface(menu->button.imgbtn3s, NULL, screen,   &menu->button.pos_btn3_ecran);
 }
   SDL_BlitSurface( menu->button.imgbtn4, NULL, screen,  &menu->button.pos_btn4_ecran);
 if (((y>=SCREEN_H/1.189312 && y<= (SCREEN_H/1.189312)+menu->button.imgbtn4s->h)&&(x>=SCREEN_W/1.25701 && x<=(SCREEN_W/1.25701)+menu->button.imgbtn4s->w)) || menu->KeyState==4)
 {
     SDL_BlitSurface( menu->button.imgbtn4s, NULL, screen,  &menu->button.pos_btn4_ecran);
 }

SDL_BlitSurface(menu->button.imgtxt, NULL, screen,  &menu->button.pos_btntxt_ecran);
break;
   }

case 1:
   {
       SDL_BlitSurface(menu->OptionBackground, NULL, screen,  &menu->pos_OptionBackground_ecran);
     SDL_BlitSurface( menu->button.imgbtnx, NULL, screen,  &menu->button.pos_btnx_ecran);
  if((y>=SCREEN_H/7.41904 && y<=(SCREEN_H/7.41904)+menu->button.imgbtnx->h)&&(x>=SCREEN_W/1.38454 && x<=(SCREEN_W/1.38454)+menu->button.imgbtnx->w))
  {
 SDL_BlitSurface( menu->button.imgbtnxs, NULL, screen,  &menu->button.pos_btnx_ecran);
    
 }
SDL_BlitSurface( menu->button.imgbtnfullscreen, NULL, screen,  &menu->button.pos_btnfullscreen_ecran);
if(((y>=SCREEN_H/2.22571 && y<=(SCREEN_H/2.22571)+menu->button.imgbtnfullscreen->h)&&(x>=SCREEN_W/2.38833 && x<=(SCREEN_W/2.38833)+menu->button.imgbtnfullscreen->w)) || menu->OptionKeyState==2 )
{
SDL_BlitSurface( menu->button.imgbtnfullscreens, NULL, screen,  &menu->button.pos_btnfullscreen_ecran);

}
SDL_BlitSurface( menu->button.imgbtnwindowed, NULL, screen,  &menu->button.pos_btnwindowed_ecran);
  if(((y>=SCREEN_H/1.58 && y<=(SCREEN_H/1.58)+menu->button.imgbtnwindowed->h)&&(x>=SCREEN_W/2.38833 && x<=(SCREEN_W/2.38833)+menu->button.imgbtnwindowed->w)) || menu->OptionKeyState==3 )
  {
  SDL_BlitSurface( menu->button.imgbtnwindoweds, NULL, screen,  &menu->button.pos_btnwindowed_ecran);

  }
SDL_BlitSurface( menu->button.imgbtnvolume, NULL, screen,  &menu->button.pos_btnvolume_ecran);

if(((y>=SCREEN_H/3.7 && y<=(SCREEN_H/3.7)+menu->button.imgbtnvolume->h)&&(x>=SCREEN_W/2.38833 && x<=(SCREEN_W/2.38833)+menu->button.imgbtnvolume->w)) || menu->OptionKeyState==1 )
  {
   SDL_BlitSurface( menu->button.imgbtnvolumes, NULL, screen,  &menu->button.pos_btnvolume_ecran);

  }
  SDL_BlitSurface(menu->text.facts_txt, NULL, screen,  &menu->text.pos_factstxt_ecran);
 break;

    }


case 2 :
{

SDL_BlitSurface(menu->OptionBackground, NULL, screen,  &menu->pos_OptionBackground_ecran);
     SDL_BlitSurface( menu->button.imgbtnx, NULL, screen,  &menu->button.pos_btnx_ecran);
  if((y>=SCREEN_H/7.41904 && y<=(SCREEN_H/7.41904)+menu->button.imgbtnx->h)&&(x>=SCREEN_W/1.38454 && x<=(SCREEN_W/1.38454)+menu->button.imgbtnx->w))
  {
 SDL_BlitSurface( menu->button.imgbtnxs, NULL, screen,  &menu->button.pos_btnx_ecran);
    
 }

SDL_BlitSurface(menu->text.volume_txt,NULL,screen,&menu->text.pos_volumetxt_ecran);
SDL_BlitSurface(menu->text.music_txt,NULL,screen,&menu->text.pos_musictxt_ecran);
SDL_BlitSurface(menu->text.soundfx_txt,NULL,screen,&menu->text.pos_soundfxtxt_ecran);
SDL_BlitSurface(menu->button.imgbtnbacks, NULL, screen,  &menu->button.pos_btnback_ecran);
if ((y>=SCREEN_H/1.33 && y<= (SCREEN_H/1.33)+menu->button.imgbtnback->h)&&(x>=SCREEN_W/2.25 && x<=(SCREEN_W/2.25)+menu->button.imgbtnback->w))
{
SDL_BlitSurface(menu->button.imgbtnback, NULL, screen,  &menu->button.pos_btnback_ecran);
}
SDL_BlitSurface(menu->volume.imgplus,NULL,screen,&menu->volume.pos_plus_ecran);
if ((y>=SCREEN_H/2.55 && y<= (SCREEN_H/2.55)+menu->volume.imgplus->h)&&(x>=SCREEN_W/1.43 && x<=(SCREEN_W/1.43)+menu->volume.imgplus->w))
{
SDL_BlitSurface(menu->volume.imgpluss,NULL,screen,&menu->volume.pos_plus_ecran);
}
SDL_BlitSurface(menu->volume.imgplus,NULL,screen,&menu->volume.pos_pluscopy_ecran);
if ((y>=SCREEN_H/1.75 && y<= (SCREEN_H/1.75)+menu->volume.imgplus->h)&&(x>=SCREEN_W/1.43 && x<=(SCREEN_W/1.43)+menu->volume.imgplus->w))
{
SDL_BlitSurface(menu->volume.imgpluss,NULL,screen,&menu->volume.pos_pluscopy_ecran);

}
SDL_BlitSurface(menu->volume.imgmoins,NULL,screen,&menu->volume.pos_moins_ecran);
if ((y>=SCREEN_H/2.38 && y<= (SCREEN_H/2.38)+menu->volume.imgmoins->h)&&(x>=SCREEN_W/1.6 && x<=(SCREEN_W/1.6)+menu->volume.imgmoins->w))
{
SDL_BlitSurface(menu->volume.imgmoinss,NULL,screen,&menu->volume.pos_moins_ecran);
}
SDL_BlitSurface(menu->volume.imgmoins,NULL,screen,&menu->volume.pos_moinscopy_ecran);
if ((y>=SCREEN_H/1.67 && y<= (SCREEN_H/1.67)+menu->volume.imgmoins->h)&&(x>=SCREEN_W/1.6 && x<=(SCREEN_W/1.6)+menu->volume.imgmoins->w))
{
SDL_BlitSurface(menu->volume.imgmoinss,NULL,screen,&menu->volume.pos_moinscopy_ecran);
}
switch(menu->MusicSliderState)
{
 case 0:
    {  
          SDL_BlitSurface(menu->volume.imgslider3, NULL, screen,  &menu->volume.pos_imgslider_ecran);
    break;

     }
 case 1:
   {
      SDL_BlitSurface(menu->volume.imgslider4, NULL, screen,  &menu->volume.pos_imgslider_ecran);
    break;

   }
 case 2:
  {
   SDL_BlitSurface(menu->volume.imgslider5, NULL, screen,  &menu->volume.pos_imgslider_ecran);
    break;

   }
 case -1:
 {
SDL_BlitSurface(menu->volume.imgslider2, NULL, screen,  &menu->volume.pos_imgslider_ecran);
    break;
  
 }
case -2:
 {
SDL_BlitSurface(menu->volume.imgslider1, NULL, screen,  &menu->volume.pos_imgslider_ecran);
    break;

  
 }



}

switch(menu->SoundFXSliderState)
{
  case 0:
    {  
          SDL_BlitSurface(menu->volume.imgslider3, NULL, screen,  &menu->volume.pos_imgslidercopy_ecran);
    break;

     }
 case 1:
   {
      SDL_BlitSurface(menu->volume.imgslider4, NULL, screen,  &menu->volume.pos_imgslidercopy_ecran);
    break;

   }
 case 2:
  {
   SDL_BlitSurface(menu->volume.imgslider5, NULL, screen,  &menu->volume.pos_imgslidercopy_ecran);
    break;

   }
 case -1:
 {
SDL_BlitSurface(menu->volume.imgslider2, NULL, screen,  &menu->volume.pos_imgslidercopy_ecran);
    break;
  
 }
case -2:
 {
SDL_BlitSurface(menu->volume.imgslider1, NULL, screen,  &menu->volume.pos_imgslidercopy_ecran);
    break;

 }

}

}

}


}
   
   







