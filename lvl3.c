#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 


void initialiser_lvl3(Japan *japan)
{ 

japan->Map3=IMG_Load("./lvl3/Japan.png");
japan->Map3_Calque=IMG_Load("./lvl3/JapanMasqueTemporary.png");
japan->pos_flag_ecran.x=0;
japan->pos_flag_ecran.y=210;
japan->pos_flag_ecran.w=0;
japan->pos_flag_ecran.h=0;
japan->pos_flag_affiche.x=0;
japan->pos_flag_affiche.y=34;
japan->pos_flag_affiche.h=364;
japan->pos_flag_affiche.w=122;
japan->pos_map3_affiche.x=0;
japan->pos_map3_affiche.y=0;
japan->pos_map3_affiche.w=1280;
japan->pos_map3_affiche.h=720;    
japan->pos_heart_ecran.x=0;
japan->pos_heart_ecran.y=6;
japan->pos_heart_ecran.w=0;
japan->pos_heart_ecran.h=0;
japan->pos_coin1_ecran.x=0;
japan->pos_coin1_ecran.y=600;
japan->pos_coin1_ecran.w=0;
japan->pos_coin1_ecran.h=0;
japan->pos_coin2_ecran.x=0;  
japan->pos_coin2_ecran.y=213;
japan->pos_coin2_ecran.w=0;
japan->pos_coin2_ecran.h=0;
japan->pos_coin3_ecran.x=0;
japan->pos_coin3_ecran.y=560;
japan->pos_coin3_ecran.w=0;
japan->pos_coin3_ecran.h=0;
japan->spike1_dimension.x=1512;   
japan->spike1_dimension.y=602;
japan->spike1_dimension.w=116;
japan->spike1_dimension.h=46;
japan->spike2_dimension.x=3431;
japan->spike2_dimension.y=601;
japan->spike2_dimension.w=59;
japan->spike2_dimension.h=45;
japan->spike3_dimension.x=5646;
japan->spike3_dimension.y=452;
japan->spike3_dimension.w=58;
japan->spike3_dimension.h=46;
japan->FlagReached=0;
japan->IsSaveMenuClicked=0;
japan->music=Mix_LoadMUS("./Music/Japan.mp3");


  
} 


void reinizialitation_lvl3(Perso *perso,Japan *japan,EnigmeJapan *EnigmeLVL3,BossRoomJapan *Boss3,Fox *fox,Youkai *youkai)
{
japan->FlagReached=0;
japan->pos_map3_affiche.x=0;
japan->pos_flag_affiche.x=0;
japan->IsSaveMenuClicked=0;
perso->pos_perso_ecran.x=3;
perso->pos_perso_ecran.y=440; 
perso->vie=3;
perso->jump=0;
//perso->repere_imaginaire=0;
perso->JumpStart=0;
perso->CoinsSecured=0;
perso->ColidedWithCoin7=0;
perso->ColidedWithCoin8=0; 
perso->ColidedWithCoin9=0;
perso->NotMovingTimer=0;
perso->RunningTimer=0;
perso->JumpingTimer=0;
perso->MouvementTrajectory=0;
perso->EnnemiesKilled=0;
Boss3->DialogueShown=0;
Boss3->Enigme=0;
GenerateRandomNumberlvl3(EnigmeLVL3);
ReadQuestionFromFilelvl3(EnigmeLVL3);
EnigmeLVL3->click=0;
EnigmeLVL3->timer=1;
EnigmeLVL3->StartOfEnigmeTimer=0;
EnigmeLVL3->Win=0;
EnigmeLVL3->ScoreLVL3.IsShown=0;
fox->EnnemiState=1;
youkai->EnnemiState=1;





} 


void scrollingJapan(Japan *japan , Perso *perso,float deltaTime,const Uint8 *keys)  
{
 if ((perso->pos_perso_ecran.x>=((1280/2)-46) && keys[SDLK_RIGHT]) && (japan->pos_map3_affiche.x<(8960-1280)))
{
             
   japan->pos_map3_affiche.x = japan->pos_map3_affiche.x+(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Forward)*(deltaTime);

}  


if ((perso->pos_perso_ecran.x<=((1280/3)-46) && keys[SDLK_LEFT]) && (japan->pos_map3_affiche.x>0) )
{

      japan->pos_map3_affiche.x = japan->pos_map3_affiche.x+(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Backward)*(deltaTime);

} 


}   




void afficher_lvl3(SDL_Surface *screen,Japan *japan,Russia *russia,Perso *perso)
{     
  SDL_BlitSurface(japan->Map3 , &japan->pos_map3_affiche , screen, NULL);  
  
  switch (perso->vie)
{
   case 3:
      {
       japan->pos_heart_ecran.x=10;
       SDL_BlitSurface(russia->heart, NULL, screen,  &japan->pos_heart_ecran);		
       japan->pos_heart_ecran.x=46;
       SDL_BlitSurface(russia->heart, NULL, screen,  &japan->pos_heart_ecran);	
       japan->pos_heart_ecran.x=82;
       SDL_BlitSurface(russia->heart, NULL, screen,  &japan->pos_heart_ecran);	
       break;
      }
  case 2:
     { japan->pos_heart_ecran.x=10;
       SDL_BlitSurface(russia->heart, NULL, screen,  &japan->pos_heart_ecran);		
       japan->pos_heart_ecran.x=46;
       SDL_BlitSurface(russia->heart, NULL, screen,  &japan->pos_heart_ecran);	
	break;
     }
  case 1:
      { japan->pos_heart_ecran.x=10;
        SDL_BlitSurface(russia->heart, NULL, screen,  &japan->pos_heart_ecran);
	break;			
 
      }
 
      
}
   japan->pos_flag_ecran.x=7945-japan->pos_map3_affiche.x;
switch (japan->FlagReached)
 
 {
 case 0:      
  {
              SDL_BlitSurface(russia->flag, &japan->pos_flag_affiche , screen, &japan->pos_flag_ecran);
             break;
 }
 case 1:      
   { 
      japan->pos_flag_affiche.x=150;
      SDL_BlitSurface(russia->flag, &japan->pos_flag_affiche , screen, &japan->pos_flag_ecran);
      japan->pos_flag_affiche.x=300;
       SDL_BlitSurface(russia->flag, &japan->pos_flag_affiche , screen, &japan->pos_flag_ecran);
      japan->FlagReached=2;
      break;
 
 
   }
 case 2:
  {
       japan->pos_flag_affiche.x=450;
       SDL_BlitSurface(russia->flag, &japan->pos_flag_affiche , screen, &japan->pos_flag_ecran);
             break;

   }
}          
     AnimateCoin(russia);
  if (perso->ColidedWithCoin7==0)
     { 
	japan->pos_coin1_ecran.x=2800-japan->pos_map3_affiche.x;
	SDL_BlitSurface(russia->coin , &russia->pos_coin_affiche , screen, &japan->pos_coin1_ecran);
     }
  if (perso->ColidedWithCoin8==0)
     {
	japan->pos_coin2_ecran.x=5550-japan->pos_map3_affiche.x;
	SDL_BlitSurface(russia->coin , &russia->pos_coin_affiche , screen, &japan->pos_coin2_ecran);
     }
  if (perso->ColidedWithCoin9==0)
     {
	japan->pos_coin3_ecran.x=6400-japan->pos_map3_affiche.x;
	SDL_BlitSurface(russia->coin , &russia->pos_coin_affiche , screen, &japan->pos_coin3_ecran);
     }
 
 

}




void free_lvl3(Japan *japan)
{
SDL_FreeSurface(japan->Map3);
SDL_FreeSurface(japan->Map3_Calque);
Mix_FreeMusic(japan->music);
free(japan);







}
