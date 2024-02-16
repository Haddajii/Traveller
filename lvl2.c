#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 

void initialiser_lvl2(Egypt *egypt)
{

egypt->Map2=IMG_Load("./lvl2/Egypt2.png");
egypt->Map2_Calque=IMG_Load("./lvl2/EgyptMasque2.png");
egypt->pos_flag_ecran.x=0;
egypt->pos_flag_ecran.y=164;
egypt->pos_flag_ecran.w=0;
egypt->pos_flag_ecran.h=0;
egypt->pos_flag_affiche.x=0;
egypt->pos_flag_affiche.y=34;
egypt->pos_flag_affiche.h=364;
egypt->pos_flag_affiche.w=122;
egypt->pos_map2_affiche.x=0;
egypt->pos_map2_affiche.y=0;
egypt->pos_map2_affiche.w=1280;
egypt->pos_map2_affiche.h=720;
egypt->pos_heart_ecran.x=0;
egypt->pos_heart_ecran.y=6;
egypt->pos_heart_ecran.w=0;
egypt->pos_heart_ecran.h=0;
egypt->pos_coin1_ecran.x=0;
egypt->pos_coin1_ecran.y=550; 
egypt->pos_coin1_ecran.w=0;
egypt->pos_coin1_ecran.h=0;
egypt->pos_coin2_ecran.x=0;  
egypt->pos_coin2_ecran.y=550;
egypt->pos_coin2_ecran.w=0;
egypt->pos_coin2_ecran.h=0;            
egypt->pos_coin3_ecran.x=0;     
egypt->pos_coin3_ecran.y=388;
egypt->pos_coin3_ecran.w=0;
egypt->pos_coin3_ecran.h=0;
egypt->spike1_dimension.x=863;
egypt->spike1_dimension.y=621;
egypt->spike1_dimension.w=59;
egypt->spike1_dimension.h=44;
egypt->spike2_dimension.x=3071;
egypt->spike2_dimension.y=544;
egypt->spike2_dimension.w=114;
egypt->spike2_dimension.h=48;
egypt->spike3_dimension.x=6929;
egypt->spike3_dimension.y=544;
egypt->spike3_dimension.w=114;
egypt->spike3_dimension.h=48;
egypt->FlagReached=0;
egypt->IsSaveMenuClicked=0;
egypt->music=Mix_LoadMUS("./Music/Egypt.mp3");




 
}

void reinizialitation_lvl2(Perso *perso,Egypt *egypt,EnigmeEgypt *EnigmeLVL2,BossRoomEgypt *Boss2,Fly *fly,Anubis *anubis)
{ 
egypt->FlagReached=0;
egypt->pos_map2_affiche.x=0;
egypt->pos_flag_affiche.x=0;
egypt->IsSaveMenuClicked=0;
perso->pos_perso_ecran.x=3;
perso->pos_perso_ecran.y=440;
perso->vie=3;
perso->jump=0;
//perso->repere_imaginaire=0;
perso->JumpStart=0;
perso->CoinsSecured=0;
perso->ColidedWithCoin4=0;
perso->ColidedWithCoin5=0; 
perso->ColidedWithCoin6=0;
perso->NotMovingTimer=0;
perso->RunningTimer=0;
perso->JumpingTimer=0;
perso->MouvementTrajectory=0;
perso->EnnemiesKilled=0;
Boss2->DialogueShown=0;
Boss2->Enigme=0;
GenerateRandomNumberlvl2(EnigmeLVL2);
ReadQuestionFromFilelvl2(EnigmeLVL2);
EnigmeLVL2->click=0;
EnigmeLVL2->timer=1;
EnigmeLVL2->StartOfEnigmeTimer=0;
EnigmeLVL2->Win=0;
EnigmeLVL2->ScoreLVL2.IsShown=0;
anubis->EnnemiState=1;
fly->EnnemiState=1;





} 

void scrollingEgypt(Egypt *egypt , Perso *perso,float deltaTime,const Uint8 *keys)  
{
 if ((perso->pos_perso_ecran.x>=((1280/2)-46) && keys[SDLK_RIGHT]) && (egypt->pos_map2_affiche.x<(8960-1280)))
{
             
   egypt->pos_map2_affiche.x = egypt->pos_map2_affiche.x+(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Forward)*(deltaTime);

}  


if ((perso->pos_perso_ecran.x<=((1280/3)-46) && keys[SDLK_LEFT]) && (egypt->pos_map2_affiche.x>0) )
{

      egypt->pos_map2_affiche.x = egypt->pos_map2_affiche.x+(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Backward)*(deltaTime);

} 


}   




void afficher_lvl2(SDL_Surface *screen,Egypt *egypt,Russia *russia,Perso *perso)
{     
  SDL_BlitSurface(egypt->Map2 , &egypt->pos_map2_affiche , screen, NULL);
  
  switch (perso->vie)
{
   case 3:
      {
       egypt->pos_heart_ecran.x=10;
       SDL_BlitSurface(russia->heart, NULL, screen,  &egypt->pos_heart_ecran);		
       egypt->pos_heart_ecran.x=46;
       SDL_BlitSurface(russia->heart, NULL, screen,  &egypt->pos_heart_ecran);	
       egypt->pos_heart_ecran.x=82;
       SDL_BlitSurface(russia->heart, NULL, screen,  &egypt->pos_heart_ecran);	
       break;
      }  
  case 2:
     { egypt->pos_heart_ecran.x=10;
       SDL_BlitSurface(russia->heart, NULL, screen,  &egypt->pos_heart_ecran);		
       egypt->pos_heart_ecran.x=46;
       SDL_BlitSurface(russia->heart, NULL, screen,  &egypt->pos_heart_ecran);	
	break;
     }
  case 1:
      { egypt->pos_heart_ecran.x=10;
        SDL_BlitSurface(russia->heart, NULL, screen,  &egypt->pos_heart_ecran);
	break;			
 
      }
 
            
}
   egypt->pos_flag_ecran.x=7825-egypt->pos_map2_affiche.x;
switch (egypt->FlagReached)
 
 {
 case 0:
  {
              SDL_BlitSurface(russia->flag, &egypt->pos_flag_affiche , screen, &egypt->pos_flag_ecran);
             break;
 }
 case 1:      
   { 
      egypt->pos_flag_affiche.x=150;
      SDL_BlitSurface(russia->flag, &egypt->pos_flag_affiche , screen, &egypt->pos_flag_ecran);
      egypt->pos_flag_affiche.x=300;
       SDL_BlitSurface(russia->flag, &egypt->pos_flag_affiche , screen, &egypt->pos_flag_ecran);
      russia->FlagReached=2;
      break;
 
 
   }
 case 2:
  {
       egypt->pos_flag_affiche.x=450;
       SDL_BlitSurface(russia->flag, &egypt->pos_flag_affiche , screen, &egypt->pos_flag_ecran);
             break;

   }
}
      AnimateCoin(russia);
  if (perso->ColidedWithCoin4==0)
     { 
	egypt->pos_coin1_ecran.x=1550-egypt->pos_map2_affiche.x;
	SDL_BlitSurface(russia->coin , &russia->pos_coin_affiche , screen, &egypt->pos_coin1_ecran);
     }
  if (perso->ColidedWithCoin5==0)
     {
	egypt->pos_coin2_ecran.x=4000-egypt->pos_map2_affiche.x;
	SDL_BlitSurface(russia->coin , &russia->pos_coin_affiche , screen, &egypt->pos_coin2_ecran);
     }
  if (perso->ColidedWithCoin6==0)
     {
	egypt->pos_coin3_ecran.x=5240-egypt->pos_map2_affiche.x;
	SDL_BlitSurface(russia->coin , &russia->pos_coin_affiche , screen, &egypt->pos_coin3_ecran);
     }
 





}



void free_lvl2(Egypt *egypt)
{
SDL_FreeSurface(egypt->Map2);
SDL_FreeSurface(egypt->Map2_Calque);
Mix_FreeMusic(egypt->music);
free(egypt);







}
