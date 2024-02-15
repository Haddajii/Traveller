#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
              
  
void FreeMenu(menu *menu)
{
for (int i=0;i<9;i++)
{
SDL_FreeSurface(menu->MenuBackground[i]);

}
SDL_FreeSurface(menu->OptionBackground);
SDL_FreeSurface(menu->button.imgbtn1);
SDL_FreeSurface(menu->button.imgbtn1s);
SDL_FreeSurface(menu->button.imgbtn2);
SDL_FreeSurface(menu->button.imgbtn2s);
SDL_FreeSurface(menu->button.imgbtn3);
SDL_FreeSurface(menu->button.imgbtn3s);
SDL_FreeSurface(menu->button.imgbtn4);
SDL_FreeSurface(menu->button.imgbtn4s);
SDL_FreeSurface(menu->button.imgtxt);
SDL_FreeSurface(menu->button.imgbtnx);
SDL_FreeSurface(menu->button.imgbtnxs);
SDL_FreeSurface(menu->button.imgbtnfullscreen);
SDL_FreeSurface(menu->button.imgbtnfullscreens);
SDL_FreeSurface(menu->button.imgbtnwindowed);
SDL_FreeSurface(menu->button.imgbtnwindoweds);
SDL_FreeSurface(menu->button.imgbtnvolume);
SDL_FreeSurface(menu->button.imgbtnvolumes);
SDL_FreeSurface(menu->button.imgbtnback);
SDL_FreeSurface(menu->button.imgbtnbacks);            
SDL_FreeSurface(menu->volume.imgslider1);
SDL_FreeSurface(menu->volume.imgslider2);
SDL_FreeSurface(menu->volume.imgslider3);
SDL_FreeSurface(menu->volume.imgslider4);
SDL_FreeSurface(menu->volume.imgslider5);
SDL_FreeSurface(menu->volume.imgplus);
SDL_FreeSurface(menu->volume.imgpluss);
SDL_FreeSurface(menu->volume.imgmoins);
SDL_FreeSurface(menu->volume.imgmoinss);
SDL_FreeSurface(menu->text.facts_txt);
SDL_FreeSurface(menu->text.volume_txt);
SDL_FreeSurface(menu->text.music_txt);
SDL_FreeSurface(menu->text.soundfx_txt);

TTF_CloseFont(menu->text.volume_police);
TTF_CloseFont(menu->text.music_soundfx_police);
TTF_CloseFont(menu->text.facts_police);
Mix_FreeMusic(menu->music);
Mix_FreeChunk(menu->bref);
free(menu);
 


 











}
