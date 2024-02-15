#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

 
 
  
    

 
 
   
 

void initialiser_Personnage(Perso *perso)
{
perso->afficher_perso=IMG_Load("./perso/ahmed22.png");
if (perso->afficher_perso == NULL) {
    printf("Error loading image: %s\n", IMG_GetError());
    // Handle error
} 
perso->GameOver=IMG_Load("./perso/GameOver.png");
perso->TryAgain=IMG_Load("./perso/TryAgain.png");
perso->TryAgainSelected=IMG_Load("./perso/TryAgainSelected.png");
perso->pos_TryAgain_ecran.x=496;
perso->pos_TryAgain_ecran.y=590;
perso->pos_TryAgain_ecran.w=0;
perso->pos_TryAgain_ecran.h=0;
perso->QuitGame=IMG_Load("./perso/QuitGame.png");
perso->QuitGameSelected=IMG_Load("./perso/QuitGameSelected.png");
perso->pos_QuitGame_ecran.x=496;
perso->pos_QuitGame_ecran.y=650;
perso->pos_QuitGame_ecran.w=0;
perso->pos_QuitGame_ecran.h=0;
perso->pos_perso_ecran.x=3; 
perso->pos_perso_ecran.y=440;
perso->pos_perso_ecran.w=0;
perso->pos_perso_ecran.h=0;
perso->pos_perso_affiche.x=0;
perso->pos_perso_affiche.y=238;
perso->pos_perso_affiche.h=162;
perso->pos_perso_affiche.w=93;
perso->SpaceBar[0]=IMG_Load("./perso/SpaceBar1.png");
perso->SpaceBar[1]=IMG_Load("./perso/SpaceBar2.png");
perso->pos_SpaceBar_ecran.x=1000;
perso->pos_SpaceBar_ecran.y=50;
perso->pos_SpaceBar_ecran.w=0;
perso->pos_SpaceBar_ecran.h=0;
perso->SpaceBarAnimationTimer=0;
perso->acceleration=0;
perso->Vitesse_Forward=0.3;
perso->Vitesse_Backward=-(0.3);
perso->gravity=0.092;
perso->vie=3;
perso->jump=0;
perso->repere_imaginaire=0;
perso->JumpStart=0;
perso->CoinsSecured=0;
perso->ColidedWithCoin=0;
perso->ColidedWithCoin2=0;
perso->ColidedWithCoin3=0; 
perso->ColidedWithCoin4=0;
perso->ColidedWithCoin5=0;
perso->ColidedWithCoin6=0;
perso->ColidedWithCoin7=0;
perso->ColidedWithCoin8=0;
perso->ColidedWithCoin9=0;
perso->NotMovingTimer=0;
perso->RunningTimer=0;
perso->JumpingTimer=0;
perso->MouvementTrajectory=0;
perso->EnnemiesKilled=0;



  
   



}


void afficher_SpaceBar(SDL_Surface *screen, Perso *perso)
{

if (perso->SpaceBarAnimationTimer<2)
{
 
   SDL_BlitSurface(perso->SpaceBar[perso->SpaceBarAnimationTimer] , NULL , screen, &perso->pos_SpaceBar_ecran);
perso->SpaceBarAnimationTimer++;
if (perso->SpaceBarAnimationTimer==2)
{
  perso->SpaceBarAnimationTimer=0;
}

}




}




void afficher_PersoMap(SDL_Surface *screen, Perso *perso)
{

SDL_BlitSurface(perso->afficher_perso, &perso->pos_perso_affiche, screen,  &perso->pos_perso_ecran);

}



void AnimatePersoWhileNotMoving(Perso *perso)
{
 if (SDL_GetTicks() - perso->NotMovingTimer >=140)
{
if (perso->MouvementTrajectory==1)
{
perso->pos_perso_affiche.y=238;
  if (perso->pos_perso_affiche.x>=300)
{
  perso->pos_perso_affiche.x=0;
}
else
{ 
  perso->pos_perso_affiche.x=perso->pos_perso_affiche.x+100;
}
}
else if (perso->MouvementTrajectory==2)
{
perso->pos_perso_affiche.y=837;
  if (perso->pos_perso_affiche.x>=300)
{
  perso->pos_perso_affiche.x=0;
}
else
{ 
  perso->pos_perso_affiche.x=perso->pos_perso_affiche.x+100;
}




}
perso->NotMovingTimer=SDL_GetTicks();
}
    
} 





void AnimatePersoWhileRunningForward(Perso *perso)
{
  if (SDL_GetTicks() - perso->RunningTimer >=80)
{
if (perso->MouvementTrajectory==1)
{
 perso->pos_perso_affiche.y=36;
 if (perso->pos_perso_affiche.x==500)
{
  perso->pos_perso_affiche.x=0;
}
else
{ 
  perso->pos_perso_affiche.x=perso->pos_perso_affiche.x+100;
}
}
else if (perso->MouvementTrajectory==2)
{
perso->pos_perso_affiche.y=637;
 if (perso->pos_perso_affiche.x==500)
{
  perso->pos_perso_affiche.x=0;
}
else
{ 
  perso->pos_perso_affiche.x=perso->pos_perso_affiche.x+100;
}




}
perso->RunningTimer = SDL_GetTicks();
}


}


void AnimatePersoWhileJump(Perso *perso)
{
 if (SDL_GetTicks() - perso->JumpingTimer >=150)
{
  if (perso->MouvementTrajectory==1)
  {

 perso->pos_perso_affiche.y=437;
  perso->pos_perso_affiche.x=0;

}
  
else if (perso->MouvementTrajectory==2)
{
  perso->pos_perso_affiche.y=1039;
  perso->pos_perso_affiche.x=0;

}


perso->JumpingTimer = SDL_GetTicks();            
}


}
 
void Perso_DeathRussia(Perso *perso,Russia *russia)
{
   perso->vie--;
   perso->pos_perso_ecran.x=3;
   perso->pos_perso_ecran.y=300;
   russia->pos_map1_affiche.x=0;
   perso->jump=0;


 
}
void Perso_DeathEgypt(Perso *perso,Egypt *egypt)
{
   perso->vie--;
   perso->pos_perso_ecran.x=3;
   perso->pos_perso_ecran.y=300;
   egypt->pos_map2_affiche.x=0;
   perso->jump=0;


  
}


void Perso_DeathJapan(Perso *perso,Japan *japan)
{
   perso->vie--;
   perso->pos_perso_ecran.x=3;
   perso->pos_perso_ecran.y=300; 
   japan->pos_map3_affiche.x=0;
   perso->jump=0;



} 
  

void Move_PersoForwardRussia(Perso *perso , Russia *russia, float deltaTime)
{
 if ((perso->pos_perso_ecran.x <(1280/2)-46 || russia->pos_map1_affiche.x>=(8960-1280)) && perso->pos_perso_ecran.x<=1280-46)
{
   perso->pos_perso_ecran.x+=(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Forward)*(deltaTime);

}

}

 
void Move_PersoBackwardsRussia(Perso *perso , Russia *russia, float deltaTime)
{
  if ((perso->pos_perso_ecran.x>=0 && russia->pos_map1_affiche.x<=0) || perso->pos_perso_ecran.x >(1280/3)-46)
{
   perso->pos_perso_ecran.x+=(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Backward)*(deltaTime);

}

}



void Move_PersoForwardEgypt(Perso *perso , Egypt *egypt, float deltaTime)
{
 if ((perso->pos_perso_ecran.x <(1280/2)-46 || egypt->pos_map2_affiche.x>=(8960-1280)) && perso->pos_perso_ecran.x<=1280-46)
{
   perso->pos_perso_ecran.x+=(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Forward)*(deltaTime);

}

}

 
void Move_PersoBackwardsEgypt(Perso *perso , Egypt *egypt, float deltaTime)
{
  if ((perso->pos_perso_ecran.x>=0 && egypt->pos_map2_affiche.x<=0) || perso->pos_perso_ecran.x >(1280/3)-46)
{
   perso->pos_perso_ecran.x+=(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Backward)*(deltaTime);

}

}


void Move_PersoForwardJapan(Perso *perso , Japan *japan, float deltaTime)
{
 if ((perso->pos_perso_ecran.x <(1280/2)-46 || japan->pos_map3_affiche.x>=(8960-1280)) && perso->pos_perso_ecran.x<=1280-46)
{
   perso->pos_perso_ecran.x+=(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Forward)*(deltaTime);

}

}

 
void Move_PersoBackwardsJapan(Perso *perso , Japan *japan, float deltaTime)
{
  if ((perso->pos_perso_ecran.x>=0 && japan->pos_map3_affiche.x<=0) || perso->pos_perso_ecran.x >(1280/3)-46)
{
   perso->pos_perso_ecran.x+=(0.5*(perso->acceleration)*(deltaTime)*(deltaTime))+(perso->Vitesse_Backward)*(deltaTime);

}

}

 

          

void Perso_Fall(Perso *perso)
{
  
  perso->pos_perso_ecran.y+=9;

}



void initialize_Jump(Perso *perso)
{
perso->jump=1;
perso->repere_imaginaire=-50;
perso->JumpStart=perso->pos_perso_ecran.y;
}
 
void Perso_Jump(Perso *perso,float deltaTime)
{
  
  perso->repere_imaginaire+=(perso->gravity)*deltaTime;
     perso->pos_perso_ecran.y=(0.08*(perso->repere_imaginaire)*(perso->repere_imaginaire))+(perso->JumpStart-200);

}

void PersoMouvementControlRussia(Russia *russia,Perso *perso,float  deltaTime,const Uint8 *keys)
{
        
if (perso->jump==1)
{

AnimatePersoWhileJump(perso);
Perso_Jump(perso,deltaTime);

}

if (CollisionPerfectPixelRussia(russia,perso)==0 && perso->jump==0 )
{

 Perso_Fall(perso);
}

if (keys[SDLK_RIGHT])
{
  perso->MouvementTrajectory=1;
if (perso->jump==0)
{
 AnimatePersoWhileRunningForward(perso);
}
 Move_PersoForwardRussia(perso,russia,deltaTime);
}
else if (keys[SDLK_LEFT])
{  
   perso->MouvementTrajectory=2;
if (perso->jump==0)
{ 
   AnimatePersoWhileRunningForward(perso);
}
   Move_PersoBackwardsRussia(perso,russia,deltaTime);
}
else
{
if (perso->jump==0)
{  

  	AnimatePersoWhileNotMoving(perso);
}

} 







}







void PersoMouvementControlEgypt(Egypt *egypt,Perso *perso,float  deltaTime,const Uint8 *keys)
{

if (perso->jump==1)
{

AnimatePersoWhileJump(perso);
Perso_Jump(perso,deltaTime);

}

if (CollisionPerfectPixelEgypt(egypt,perso)==0 && perso->jump==0 )
{

 Perso_Fall(perso);
}

if (keys[SDLK_RIGHT])
{
  perso->MouvementTrajectory=1;
if (perso->jump==0)
{
 AnimatePersoWhileRunningForward(perso);
}
 Move_PersoForwardEgypt(perso,egypt,deltaTime);
}
else if (keys[SDLK_LEFT])
{  
   perso->MouvementTrajectory=2;
if (perso->jump==0)
{ 
   AnimatePersoWhileRunningForward(perso);
}
   Move_PersoBackwardsEgypt(perso,egypt,deltaTime);
}
else
{
if (perso->jump==0)
{  

  	AnimatePersoWhileNotMoving(perso);
}

} 







}




void PersoMouvementControlJapan(Japan *japan,Perso *perso,float  deltaTime,const Uint8 *keys)
{

if (perso->jump==1)
{

AnimatePersoWhileJump(perso);
Perso_Jump(perso,deltaTime);

}

if (CollisionPerfectPixelJapan(japan,perso)==0 && perso->jump==0 )
{

 Perso_Fall(perso);
}

if (keys[SDLK_RIGHT])
{
  perso->MouvementTrajectory=1;
if (perso->jump==0)
{
 AnimatePersoWhileRunningForward(perso);
}
 Move_PersoForwardJapan(perso,japan,deltaTime);
}
else if (keys[SDLK_LEFT])
{  
   perso->MouvementTrajectory=2;
if (perso->jump==0)
{ 
   AnimatePersoWhileRunningForward(perso);
}
   Move_PersoBackwardsJapan(perso,japan,deltaTime);
}
else
{
if (perso->jump==0)
{  

  	AnimatePersoWhileNotMoving(perso);
}

} 







}




void PersoCollisionControlRussia(Russia *russia,Perso *perso)
{


if (CollisionPerfectPixelRussia(russia,perso)==1)
{
  perso->jump=0;

}
if (CollisionPerfectPixelRightRussia(russia,perso)==1)
{
 perso->Vitesse_Forward=0;

}
else 
{
perso->Vitesse_Forward=0.3;
}

if (CollisionPerfectPixelLeftRussia(russia,perso)==1)
{
 perso->Vitesse_Backward=0;
 
}
else
{
perso->Vitesse_Backward=-(0.3);
}

if (CollisionPerfectPixelUpRussia(russia,perso)==1)
{
  perso->jump=0;
   Perso_Fall(perso);
 
} 
if(CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,russia->pos_coin_ecran,russia->pos_coin_affiche)==1 &&    perso->ColidedWithCoin==0)
{
   perso->CoinsSecured++;
   perso->ColidedWithCoin=1;

  
}
if(CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,russia->pos_coin2_ecran,russia->pos_coin_affiche)==1 &&    perso->ColidedWithCoin2==0)
{
  perso->CoinsSecured++;
   perso->ColidedWithCoin2=1;


}  
if(CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,russia->pos_coin3_ecran,russia->pos_coin_affiche)==1 &&    perso->ColidedWithCoin3==0)
{
  perso->CoinsSecured++;
   perso->ColidedWithCoin3=1;

 
}

if(CollisionBoundingBoxSpikes(perso->pos_perso_ecran,perso->pos_perso_affiche,russia->pos_map1_affiche,russia->spike1_dimension)==1 || CollisionBoundingBoxSpikes(perso->pos_perso_ecran,perso->pos_perso_affiche,russia->pos_map1_affiche,russia->spike3_dimension)==1 || CollisionBoundingBoxSpikes(perso->pos_perso_ecran,perso->pos_perso_affiche,russia->pos_map1_affiche,russia->spike2_dimension)==1 || CollisionBoundingBoxSpikes(perso->pos_perso_ecran,perso->pos_perso_affiche,russia->pos_map1_affiche,russia->spike4_dimension)==1)
{

      Perso_DeathRussia(perso,russia);

}

if (perso->pos_perso_ecran.x>=russia->pos_flag_ecran.x )
{
  russia->FlagReached=2;

} 
 
   
                      


}




void PersoCollisionControlEgypt(Egypt *egypt,Russia *russia,Perso *perso)
{
 

if (CollisionPerfectPixelEgypt(egypt,perso)==1)
{
  perso->jump=0;

}
if (CollisionPerfectPixelRightEgypt(egypt,perso)==1)
{
 perso->Vitesse_Forward=0;

}
else 
{
perso->Vitesse_Forward=0.3;
}

if (CollisionPerfectPixelLeftEgypt(egypt,perso)==1)
{
 perso->Vitesse_Backward=0;
 
}
else
{
perso->Vitesse_Backward=-(0.3);
}

if (CollisionPerfectPixelUpEgypt(egypt,perso)==1)
{
  perso->jump=0;
   Perso_Fall(perso);
 
} 
if(CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,egypt->pos_coin1_ecran,russia->pos_coin_affiche)==1 &&    perso->ColidedWithCoin4==0)
{
   perso->CoinsSecured++;
   perso->ColidedWithCoin4=1;

  
}
if(CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,egypt->pos_coin2_ecran,russia->pos_coin_affiche)==1 &&    perso->ColidedWithCoin5==0)
{
  perso->CoinsSecured++;
   perso->ColidedWithCoin5=1;
 

}  
if(CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,egypt->pos_coin3_ecran,russia->pos_coin_affiche)==1 &&    perso->ColidedWithCoin6==0)
{
  perso->CoinsSecured++;
   perso->ColidedWithCoin6=1;

 
}

if(CollisionBoundingBoxSpikes(perso->pos_perso_ecran,perso->pos_perso_affiche,egypt->pos_map2_affiche,egypt->spike1_dimension)==1 || CollisionBoundingBoxSpikes(perso->pos_perso_ecran,perso->pos_perso_affiche,egypt->pos_map2_affiche,egypt->spike2_dimension)==1 || CollisionBoundingBoxSpikes(perso->pos_perso_ecran,perso->pos_perso_affiche,egypt->pos_map2_affiche,egypt->spike3_dimension)==1 )
{

      Perso_DeathEgypt(perso,egypt);

}

if (perso->pos_perso_ecran.x>=egypt->pos_flag_ecran.x )
{
  egypt->FlagReached=2;

} 
 
   
 


}

 



void PersoCollisionControlJapan(Japan *japan,Russia *russia,Perso *perso)
{
 

if (CollisionPerfectPixelJapan(japan,perso)==1)
{
  perso->jump=0;

}
if (CollisionPerfectPixelRightJapan(japan,perso)==1)
{
 perso->Vitesse_Forward=0;

}
else 
{
perso->Vitesse_Forward=0.3;
}

if (CollisionPerfectPixelLeftJapan(japan,perso)==1)
{
 perso->Vitesse_Backward=0;
 
}
else
{
perso->Vitesse_Backward=-(0.3);
}

if (CollisionPerfectPixelUpJapan(japan,perso)==1)
{
  perso->jump=0;
   Perso_Fall(perso);
 
} 
if(CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,japan->pos_coin1_ecran,russia->pos_coin_affiche)==1 &&    perso->ColidedWithCoin7==0)
{
   perso->CoinsSecured++;
   perso->ColidedWithCoin7=1;

  
}
if(CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,japan->pos_coin2_ecran,russia->pos_coin_affiche)==1 &&    perso->ColidedWithCoin8==0)
{
  perso->CoinsSecured++;
   perso->ColidedWithCoin8=1;

  
}  
if(CollisionBoundingBox(perso->pos_perso_ecran,perso->pos_perso_affiche,japan->pos_coin3_ecran,russia->pos_coin_affiche)==1 &&    perso->ColidedWithCoin9==0)
{
  perso->CoinsSecured++;
   perso->ColidedWithCoin9=1;
 
 
}

if(CollisionBoundingBoxSpikes(perso->pos_perso_ecran,perso->pos_perso_affiche,japan->pos_map3_affiche,japan->spike1_dimension)==1 || CollisionBoundingBoxSpikes(perso->pos_perso_ecran,perso->pos_perso_affiche,japan->pos_map3_affiche,japan->spike2_dimension)==1 || CollisionBoundingBoxSpikes(perso->pos_perso_ecran,perso->pos_perso_affiche,japan->pos_map3_affiche,japan->spike3_dimension)==1 )
{

      Perso_DeathJapan(perso,japan);

}

if (perso->pos_perso_ecran.x>=japan->pos_flag_ecran.x )
{
  japan->FlagReached=2;

} 
 
   
 

 
}






void free_Perso(Perso *perso)
{
SDL_FreeSurface(perso->afficher_perso);
SDL_FreeSurface(perso->GameOver);
SDL_FreeSurface(perso->TryAgain);
SDL_FreeSurface(perso->TryAgainSelected);
SDL_FreeSurface(perso->QuitGame);
SDL_FreeSurface(perso->QuitGameSelected);
for (int i=0;i<2;i++)
{
SDL_FreeSurface(perso->SpaceBar[i]);
}


free(perso);








}
