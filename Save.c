#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
 

void initialiser_Save_Quit(Save_Quit *Save)
{
 
Save->Menu=IMG_Load("./AllMaps/Menu.png");
Save->MenuSelected=IMG_Load("./AllMaps/MenuSelected.png");
Save->pos_Menu_ecran.x=1190;
Save->pos_Menu_ecran.y=5;
Save->pos_Menu_ecran.w=0;
Save->pos_Menu_ecran.h=0;
Save->Background=IMG_Load("./AllMaps/MenuBackground.png");
Save->pos_Background_ecran.x=260;
Save->pos_Background_ecran.y=128;
Save->pos_Background_ecran.w=0;
Save->pos_Background_ecran.h=0;
Save->Quit=IMG_Load("./AllMaps/Quit.png");
Save->QuitSelected=IMG_Load("./AllMaps/QuitSelected.png");
Save->pos_Quit_ecran.x=400;
Save->pos_Quit_ecran.y=385;
Save->pos_Quit_ecran.w=0;
Save->pos_Quit_ecran.h=0;
Save->Save=IMG_Load("./AllMaps/SaveGame.png");
Save->SaveSelected=IMG_Load("./AllMaps/SaveGameSelected.png");
Save->pos_Save_ecran.x=400;
Save->pos_Save_ecran.y=245;
Save->pos_Save_ecran.w=0;
Save->pos_Save_ecran.h=0;
}
     

void afficher_SaveMenuIcon(SDL_Surface *screen,Save_Quit *Save)
{
int x,y ;
 SDL_GetMouseState(&x , &y);
SDL_BlitSurface(Save->Menu, NULL, screen,  &Save->pos_Menu_ecran);



if ((y>=5 && y<=5+Save->Menu->h)&&(x>=1190 && x<=1190+Save->Menu->w))
{
SDL_BlitSurface(Save->MenuSelected,NULL,screen,&Save->pos_Menu_ecran);

}



}


void ClickSaveMenuRussiaIcon(SDL_Event event,Russia *russia,Save_Quit *Save)
{

if (russia->IsSaveMenuClicked==0)
{

if ((event.button.x>=1190 && event.button.x<=1190+Save->Menu->w) && (event.button.y>=5 && event.button.y<=5+Save->Menu->h))
  {
     russia->IsSaveMenuClicked=1;
  }



}



}



void ClickSaveMenuEgyptIcon(SDL_Event event,Egypt *egypt,Save_Quit *Save)
{

if (egypt->IsSaveMenuClicked==0)
{

if ((event.button.x>=1190 && event.button.x<=1190+Save->Menu->w) && (event.button.y>=5 && event.button.y<=5+Save->Menu->h))
  {
     egypt->IsSaveMenuClicked=1;
  }

}   

}


void ClickSaveMenuJapanIcon(SDL_Event event,Japan *japan,Save_Quit *Save)
{

if (japan->IsSaveMenuClicked==0)
{

if ((event.button.x>=1190 && event.button.x<=1190+Save->Menu->w) && (event.button.y>=5 && event.button.y<=5+Save->Menu->h))
  {
     japan->IsSaveMenuClicked=1;
  }

}   

}




void LeaveSaveMenuRussiaIcon(SDL_Event event ,Russia *russia)
{
if (event.key.keysym.sym==SDLK_ESCAPE && russia->IsSaveMenuClicked==1)
{

  russia->IsSaveMenuClicked=0;
}





}  

void LeaveSaveMenuEgyptIcon(SDL_Event event ,Egypt *egypt)
{
if (event.key.keysym.sym==SDLK_ESCAPE && egypt->IsSaveMenuClicked==1)
{

  egypt->IsSaveMenuClicked=0;
}





}


void LeaveSaveMenuJapanIcon(SDL_Event event ,Japan *japon)
{
if (event.key.keysym.sym==SDLK_ESCAPE && japon->IsSaveMenuClicked==1)
{

  japon->IsSaveMenuClicked=0;
}





}



 

void SaveGameRussia(Perso *perso,Russia *russia,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1,Hunter *hunter,IceMob *Mob,int *GameState)
{

FILE *f;
f=fopen("./lvl1/RussiaSave.txt","w");
if (f==NULL)
  printf("failed to open file\n");
else
{
 
 fprintf(f,"GameState:%d\n",*GameState);
 fprintf(f,"FlagReached:%d pos_map1_affiche:%d pos_flag_affiche:%d IsSaveMenuClicked:%d pos_perso_ecran.x:%d pos_perso_ecran.y:%d vie:%d jump:%d JumpStart:%d CoinsSecured:%d ColidedWithCoin:%d ColidedWithCoin2:%d ColidedWithCoin3:%d  MouvementTrajectory:%d EnnemiesKilled:%d HunterEnnemiState:%d MobEnnemiState:%d",russia->FlagReached,russia->pos_map1_affiche.x,russia->pos_flag_affiche.x,0,perso->pos_perso_ecran.x,perso->pos_perso_ecran.y,perso->vie,perso->jump,perso->JumpStart,perso->CoinsSecured,perso->ColidedWithCoin,perso->ColidedWithCoin2,perso->ColidedWithCoin3,perso->MouvementTrajectory,perso->EnnemiesKilled,hunter->EnnemiState,Mob->EnnemiState);
fclose(f);

 
}



}



void SaveGameEgypt(Perso *perso,Egypt *egypt,int *GameState)
{

FILE *f;
f=fopen("./lvl1/RussiaSave.txt","w");
if (f==NULL)
  printf("failed to open file\n");
else
{
 
 fprintf(f,"GameState:%d\n",*GameState);
 fprintf(f,"FlagReached:%d pos_map2_affiche:%d pos_flag_affiche:%d IsSaveMenuClicked:%d pos_perso_ecran.x:%d pos_perso_ecran.y:%d vie:%d jump:%d JumpStart:%d CoinsSecured:%d ColidedWithCoin4:%d ColidedWithCoin5:%d ColidedWithCoin6:%d  MouvementTrajectory:%d EnnemiesKilled:%d ",egypt->FlagReached,egypt->pos_map2_affiche.x,egypt->pos_flag_affiche.x,0,perso->pos_perso_ecran.x,perso->pos_perso_ecran.y,perso->vie,perso->jump,perso->JumpStart,perso->CoinsSecured,perso->ColidedWithCoin4,perso->ColidedWithCoin5,perso->ColidedWithCoin6,perso->MouvementTrajectory,perso->EnnemiesKilled);
fclose(f);

 
}



}



void SaveGameJapan(Perso *perso,Japan *japan,int *GameState)
{

FILE *f;
f=fopen("./lvl1/RussiaSave.txt","w");
if (f==NULL)
  printf("failed to open file\n");
else
{
 
 fprintf(f,"GameState:%d\n",*GameState);
 fprintf(f,"FlagReached:%d pos_map3_affiche:%d pos_flag_affiche:%d IsSaveMenuClicked:%d pos_perso_ecran.x:%d pos_perso_ecran.y:%d vie:%d jump:%d JumpStart:%d CoinsSecured:%d ColidedWithCoin7:%d ColidedWithCoin8:%d ColidedWithCoin9:%d  MouvementTrajectory:%d EnnemiesKilled:%d ",japan->FlagReached,japan->pos_map3_affiche.x,japan->pos_flag_affiche.x,0,perso->pos_perso_ecran.x,perso->pos_perso_ecran.y,perso->vie,perso->jump,perso->JumpStart,perso->CoinsSecured,perso->ColidedWithCoin7,perso->ColidedWithCoin8,perso->ColidedWithCoin9,perso->MouvementTrajectory,perso->EnnemiesKilled);
fclose(f);

 
}



}





void ClickToSaveOrQuitMenuRussia(SDL_Event event,Save_Quit *Save,int *GameState,Perso *perso,Russia *russia,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1,Hunter *hunter,IceMob *Mob)
{

 if ((event.button.x>=400 && event.button.x<=400+Save->Quit->w) && (event.button.y>=385 && event.button.y<=385+Save->Quit->h) && russia->IsSaveMenuClicked==1)
  {
     *GameState=0;
  }

 else if ((event.button.x>=400 && event.button.x<=400+Save->Save->w) && (event.button.y>=245 && event.button.y<=245+Save->Save->h) && russia->IsSaveMenuClicked==1)
 {
  SaveGameRussia(perso,russia,EnigmeLVL1,Boss1,hunter,Mob,GameState);


  }

      






} 


void ClickToSaveOrQuitMenuEgypt(SDL_Event event,Save_Quit *Save,int *GameState,Perso *perso,Egypt *egypt) 
{

 if ((event.button.x>=400 && event.button.x<=400+Save->Quit->w) && (event.button.y>=385 && event.button.y<=385+Save->Quit->h) && egypt->IsSaveMenuClicked==1)
  {
     *GameState=0;
  }

 else if ((event.button.x>=400 && event.button.x<=400+Save->Save->w) && (event.button.y>=245 && event.button.y<=245+Save->Save->h) && egypt->IsSaveMenuClicked==1)
 {
  SaveGameEgypt(perso,egypt,GameState);


  }

        

} 



void ClickToSaveOrQuitMenuJapan(SDL_Event event,Save_Quit *Save,int *GameState,Perso *perso,Japan *japan) 
{

 if ((event.button.x>=400 && event.button.x<=400+Save->Quit->w) && (event.button.y>=385 && event.button.y<=385+Save->Quit->h) && japan->IsSaveMenuClicked==1)
  {
     *GameState=0;
  }

 else if ((event.button.x>=400 && event.button.x<=400+Save->Save->w) && (event.button.y>=245 && event.button.y<=245+Save->Save->h) && japan->IsSaveMenuClicked==1)
 {
  SaveGameJapan(perso,japan,GameState);


  }



} 

void ContinueGameRussia(Perso *perso,Russia *russia,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1,Hunter *hunter,IceMob *Mob,int *GameState)
{

FILE *f;
f=fopen("./lvl1/RussiaSave.txt","r");
if (f==NULL)
  printf("failed to open file\n");
else
{
  fscanf(f,"GameState:%d\n",GameState);
 fscanf(f,"FlagReached:%d pos_map1_affiche:%hd pos_flag_affiche:%hd IsSaveMenuClicked:%d pos_perso_ecran.x:%hd pos_perso_ecran.y:%hd vie:%d jump:%d JumpStart:%d CoinsSecured:%d ColidedWithCoin:%d ColidedWithCoin2:%d ColidedWithCoin3:%d  MouvementTrajectory:%d EnnemiesKilled:%d HunterEnnemiState:%d MobEnnemiState:%d",&russia->FlagReached,&russia->pos_map1_affiche.x,&russia->pos_flag_affiche.x,&russia->IsSaveMenuClicked,&perso->pos_perso_ecran.x,&perso->pos_perso_ecran.y,&perso->vie,&perso->jump,&perso->JumpStart,&perso->CoinsSecured,&perso->ColidedWithCoin,&perso->ColidedWithCoin2,&perso->ColidedWithCoin3,&perso->MouvementTrajectory,&perso->EnnemiesKilled,&hunter->EnnemiState,&Mob->EnnemiState);
fclose(f);



 
}









}

 

void ContinueGameEgypt(Perso *perso,Egypt *egypt,int *GameState)
{

FILE *f; 
f=fopen("./lvl1/RussiaSave.txt","r");
if (f==NULL)
  printf("failed to open file\n");
else
{ 
  fscanf(f,"GameState:%d\n",GameState);
 fscanf(f,"FlagReached:%d pos_map2_affiche:%hd pos_flag_affiche:%hd IsSaveMenuClicked:%d pos_perso_ecran.x:%hd pos_perso_ecran.y:%hd vie:%d jump:%d JumpStart:%d CoinsSecured:%d ColidedWithCoin4:%d ColidedWithCoin5:%d ColidedWithCoin6:%d  MouvementTrajectory:%d EnnemiesKilled:%d ",&egypt->FlagReached,&egypt->pos_map2_affiche.x,&egypt->pos_flag_affiche.x,&egypt->IsSaveMenuClicked,&perso->pos_perso_ecran.x,&perso->pos_perso_ecran.y,&perso->vie,&perso->jump,&perso->JumpStart,&perso->CoinsSecured,&perso->ColidedWithCoin4,&perso->ColidedWithCoin5,&perso->ColidedWithCoin6,&perso->MouvementTrajectory,&perso->EnnemiesKilled);
fclose(f);

 
        }
              

}
      
  

void ContinueGameJapan(Perso *perso,Japan *japan,int *GameState)
{

FILE *f; 
f=fopen("./lvl1/RussiaSave.txt","r");
if (f==NULL)
  printf("failed to open file\n");
else
{ 
  fscanf(f,"GameState:%d\n",GameState);
 fscanf(f,"FlagReached:%d pos_map3_affiche:%hd pos_flag_affiche:%hd IsSaveMenuClicked:%d pos_perso_ecran.x:%hd pos_perso_ecran.y:%hd vie:%d jump:%d JumpStart:%d CoinsSecured:%d ColidedWithCoin7:%d ColidedWithCoin8:%d ColidedWithCoin9:%d  MouvementTrajectory:%d EnnemiesKilled:%d ",&japan->FlagReached,&japan->pos_map3_affiche.x,&japan->pos_flag_affiche.x,&japan->IsSaveMenuClicked,&perso->pos_perso_ecran.x,&perso->pos_perso_ecran.y,&perso->vie,&perso->jump,&perso->JumpStart,&perso->CoinsSecured,&perso->ColidedWithCoin7,&perso->ColidedWithCoin8,&perso->ColidedWithCoin9,&perso->MouvementTrajectory,&perso->EnnemiesKilled);
fclose(f);

/*fprintf(f,"GameState:%d\n",*GameState);
 fprintf(f,"FlagReached:%d pos_map3_affiche:%d pos_flag_affiche:%d IsSaveMenuClicked:%d pos_perso_ecran.x:%d pos_perso_ecran.y:%d vie:%d jump:%d JumpStart:%d CoinsSecured:%d ColidedWithCoin7:%d ColidedWithCoin8:%d ColidedWithCoin9:%d  MouvementTrajectory:%d EnnemiesKilled:%d ",japan->FlagReached,japan->pos_map3_affiche.x,japan->pos_flag_affiche.x,0,perso->pos_perso_ecran.x,perso->pos_perso_ecran.y,perso->vie,perso->jump,perso->JumpStart,perso->CoinsSecured,perso->ColidedWithCoin7,perso->ColidedWithCoin8,perso->ColidedWithCoin9,perso->MouvementTrajectory,perso->EnnemiesKilled);*/

 
}







  

}





void afficher_SaveMenuBackground(SDL_Surface *screen,Save_Quit *Save)
{
int x,y ;
 SDL_GetMouseState(&x , &y);
 SDL_BlitSurface(Save->Background, NULL, screen,  &Save->pos_Background_ecran);
  SDL_BlitSurface(Save->Quit, NULL, screen,  &Save->pos_Quit_ecran);
 if ((y>=385 && y<=385+Save->Quit->h)&&(x>=400 && x<=400+Save->Quit->w))
{
SDL_BlitSurface(Save->QuitSelected,NULL,screen,&Save->pos_Quit_ecran);

}
        
   SDL_BlitSurface(Save->Save, NULL, screen,  &Save->pos_Save_ecran);
if ((y>=245 && y<=245+Save->Save->h)&&(x>=400 && x<=400+Save->Save->w))
{
SDL_BlitSurface(Save->SaveSelected,NULL,screen,&Save->pos_Save_ecran);

}
 



  
}




void free_Save_Quit(Save_Quit *Save)
{
 SDL_FreeSurface(Save->Menu);
 SDL_FreeSurface(Save->MenuSelected);
 SDL_FreeSurface(Save->Background);
 SDL_FreeSurface(Save->Quit);
 SDL_FreeSurface(Save->QuitSelected);
 SDL_FreeSurface(Save->Save);
 SDL_FreeSurface(Save->SaveSelected);
 free(Save);







}
