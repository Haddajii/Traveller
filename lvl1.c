#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

  
  
 

void initialiser_lvl1(Russia *russia)
{ 
 
    russia->Map1=IMG_Load("./lvl1/Russia.png");
    russia->Map1_Calque=IMG_Load("./lvl1/RussiaMasque.png");
    russia->flag=IMG_Load("./lvl1/flag.png");
    russia->heart=IMG_Load("./lvl1/hearts.png");
    russia->coin=IMG_Load("./lvl1/coin.png");
    russia->pos_flag_ecran.x=0;
   russia->pos_flag_ecran.y=207;
   russia->pos_flag_ecran.w=0;
   russia->pos_flag_ecran.h=0;
   russia->pos_flag_affiche.x=0;
   russia->pos_flag_affiche.y=34;
   russia->pos_flag_affiche.h=364;
   russia->pos_flag_affiche.w=122;
   russia->pos_map1_affiche.x=0;
   russia->pos_map1_affiche.y=0;
   russia->pos_map1_affiche.w=1280;
   russia->pos_map1_affiche.h=720;
   russia->pos_heart_ecran.x=0;
   russia->pos_heart_ecran.y=6;
   russia->pos_heart_ecran.w=0;              
   russia->pos_heart_ecran.h=0;
   russia->pos_coin_ecran.x=0;
   russia->pos_coin_ecran.y=600;
   russia->pos_coin_ecran.w=0;
   russia->pos_coin_ecran.h=0;
   russia->pos_coin2_ecran.x=0;
   russia->pos_coin2_ecran.y=600;
   russia->pos_coin2_ecran.w=0; 
   russia->pos_coin2_ecran.h=0;
   russia->pos_coin3_ecran.x=0;   
   russia->pos_coin3_ecran.y=252; 
   russia->pos_coin3_ecran.w=0;
   russia->pos_coin3_ecran.h=0; 
   russia->pos_coin_affiche.x=0;
   russia->pos_coin_affiche.y=0;
   russia->pos_coin_affiche.h=36;
   russia->pos_coin_affiche.w=44;
   russia->spike1_dimension.x=1282;
   russia->spike1_dimension.y=592;
   russia->spike1_dimension.w=112;
   russia->spike1_dimension.h=45; 
   russia->spike2_dimension.x=4601;
   russia->spike2_dimension.y=598;
   russia->spike2_dimension.w=58;
   russia->spike2_dimension.h=48;
   russia->spike3_dimension.x=2958;
   russia->spike3_dimension.y=447;
   russia->spike3_dimension.w=58;
   russia->spike3_dimension.h=46;
   russia->spike4_dimension.x=6084;
   russia->spike4_dimension.y=523;
   russia->spike4_dimension.w=57;
   russia->spike4_dimension.h=42;
   russia->FlagReached=0;
   russia->CoinTimer=0;
   russia->IsSaveMenuClicked=0;
   russia->music=Mix_LoadMUS("./Music/Russia.mp3");
   
        
     

}




void AnimateCoin(Russia *russia)
{

 if (SDL_GetTicks() - russia->CoinTimer >=200)
{
  if (russia->pos_coin_affiche.x==132)
{
 russia->pos_coin_affiche.x=0;
}
else
{ 
  russia->pos_coin_affiche.x=russia->pos_coin_affiche.x+44;
}
  russia->CoinTimer = SDL_GetTicks();
}
}

 


void scrollingRussia(Russia *russia , Perso *perso,float deltaTime,const Uint8 *keys)
{
 if ((perso->pos_perso_ecran.x>=((1280/2)-46) && keys[SDLK_RIGHT]) && (russia->pos_map1_affiche.x<(8960-1280)))
{

   russia->pos_map1_affiche.x = russia->pos_map1_affiche.x+(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Forward)*(deltaTime);

}

             

if ((perso->pos_perso_ecran.x<=((1280/3)-46) && keys[SDLK_LEFT]) && (russia->pos_map1_affiche.x>0) )
{

      russia->pos_map1_affiche.x = russia->pos_map1_affiche.x+(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Backward)*(deltaTime);

}

}
  
  
  
  


void afficher_lvl1(SDL_Surface *screen,Russia *russia,Perso *perso)
{     
  SDL_BlitSurface(russia->Map1 , &russia->pos_map1_affiche , screen, NULL);
        AnimateCoin(russia);
  if (perso->ColidedWithCoin==0)
     {
	russia->pos_coin_ecran.x=1700-russia->pos_map1_affiche.x;
	SDL_BlitSurface(russia->coin , &russia->pos_coin_affiche , screen, &russia->pos_coin_ecran);
     }
  if (perso->ColidedWithCoin2==0)
     {
	russia->pos_coin2_ecran.x=4000-russia->pos_map1_affiche.x;
	SDL_BlitSurface(russia->coin , &russia->pos_coin_affiche , screen, &russia->pos_coin2_ecran);
     }
  if (perso->ColidedWithCoin3==0)
     {
	russia->pos_coin3_ecran.x=7270-russia->pos_map1_affiche.x;
	SDL_BlitSurface(russia->coin , &russia->pos_coin_affiche , screen, &russia->pos_coin3_ecran);
     }
 
   russia->pos_flag_ecran.x=7805-russia->pos_map1_affiche.x;
 switch (russia->FlagReached)
 
 {
 case 0:
  {
              SDL_BlitSurface(russia->flag, &russia->pos_flag_affiche , screen, &russia->pos_flag_ecran);
             break;
 }
 case 1:      
   { 
      russia->pos_flag_affiche.x=150;
      SDL_BlitSurface(russia->flag, &russia->pos_flag_affiche , screen, &russia->pos_flag_ecran);
      russia->pos_flag_affiche.x=300;
       SDL_BlitSurface(russia->flag, &russia->pos_flag_affiche , screen, &russia->pos_flag_ecran);
      russia->FlagReached=2;
      break;

 
   }
 case 2:
  {
       russia->pos_flag_affiche.x=450;
       SDL_BlitSurface(russia->flag, &russia->pos_flag_affiche , screen, &russia->pos_flag_ecran);
             break;

   }
}
   

  switch (perso->vie)
{
   case 3:
      {
       russia->pos_heart_ecran.x=10;
       SDL_BlitSurface(russia->heart, NULL, screen,  &russia->pos_heart_ecran);		
       russia->pos_heart_ecran.x=46;
       SDL_BlitSurface(russia->heart, NULL, screen,  &russia->pos_heart_ecran);	
       russia->pos_heart_ecran.x=82;
       SDL_BlitSurface(russia->heart, NULL, screen,  &russia->pos_heart_ecran);	
       break;
      }
  case 2:
     { russia->pos_heart_ecran.x=10;
       SDL_BlitSurface(russia->heart, NULL, screen,  &russia->pos_heart_ecran);		
       russia->pos_heart_ecran.x=46;
       SDL_BlitSurface(russia->heart, NULL, screen,  &russia->pos_heart_ecran);	
	break;
     }
  case 1:
      { russia->pos_heart_ecran.x=10;
        SDL_BlitSurface(russia->heart, NULL, screen,  &russia->pos_heart_ecran);
	break;			
 
      }
 
  
}

}





int CollisionBoundingBox(SDL_Rect obstacle1_ecran, SDL_Rect obstacle1_affiche,SDL_Rect obstacle2_ecran, SDL_Rect obstacle2_affiche)
{
  
if((obstacle1_ecran.x  + obstacle1_affiche.w < obstacle2_ecran.x) || (obstacle1_ecran.x >  obstacle2_ecran.x+ obstacle2_affiche.w) || (obstacle1_ecran.y + obstacle1_affiche.h< obstacle2_ecran.y) || (obstacle1_ecran.y>  obstacle2_ecran.y + obstacle2_affiche.h) ) 
{
            return(0);   
}   // pas de collision
else
            return(1);


}                        
 

int CollisionBoundingBoxSpikes(SDL_Rect obstacle1_ecran, SDL_Rect obstacle1_affiche,SDL_Rect Map,SDL_Rect obstacle2)
{
  
if((obstacle1_ecran.x  + obstacle1_affiche.w + Map.x < obstacle2.x) || (obstacle1_ecran.x + Map.x >  obstacle2.x+ obstacle2.w) || (obstacle1_ecran.y + obstacle1_affiche.h< obstacle2.y) || (obstacle1_ecran.y>  obstacle2.y + obstacle2.h) ) 
{
            return(0);   
}   // pas de collision
else
            return(1);
 
  
}     

  
 

void free_lvl1(Russia *russia)
{
SDL_FreeSurface(russia->Map1);
SDL_FreeSurface(russia->Map1_Calque);
SDL_FreeSurface(russia->flag);
SDL_FreeSurface(russia->heart);
SDL_FreeSurface(russia->coin);
Mix_FreeMusic(russia->music);
free(russia);





 


}




