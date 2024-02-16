#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
       


int GenerateRandomNumberlvl1(EnigmeRussia *EnigmeLVL1)
{ 
  
  srand(time(NULL));
do
 {
  EnigmeLVL1->Random_Number=rand()% 15+1;
 }
while(EnigmeLVL1->Random_Number!=1 && EnigmeLVL1->Random_Number!=6 && EnigmeLVL1->Random_Number!=11);
 
}




void ReadQuestionFromFilelvl1(EnigmeRussia *EnigmeLVL1)
{
  FILE *f;
  int length;
  char line[256];
  char CorrectAnswer[2];
  f=fopen("./lvl1Enigme/RussiaQuestions.txt","r");
  if (f==NULL)
   {
     printf("failed to open file");
     
   }
else
{
 for (int j=1;j<(EnigmeLVL1->Random_Number);j++)
 {
  fgets(line,sizeof(line),f);

 }
 fgets(line,sizeof(line),f);

 

 strcpy(EnigmeLVL1->question,line);

for (int k=0;k<3;k++)
{
 fgets(line,sizeof(line),f);

 strcpy(EnigmeLVL1->answer[k],line);

}
 fgets(CorrectAnswer,sizeof(CorrectAnswer),f);
 EnigmeLVL1->CorrectAnswer=atoi(CorrectAnswer);

fclose(f);
}
}




void initialiser_EnigmeRussia(EnigmeRussia *EnigmeLVL1)
{
 

EnigmeLVL1->EnigmeRussiaBackground=IMG_Load("./lvl1Enigme/BackgroundEnigmeRussia.png");
EnigmeLVL1->pos_background_ecran.x=220;
EnigmeLVL1->pos_background_ecran.y=100;
EnigmeLVL1->pos_background_ecran.w=0;
EnigmeLVL1->pos_background_ecran.h=0;
EnigmeLVL1->boxes=IMG_Load("./lvl1Enigme/Box.png");
EnigmeLVL1->pos_boxes_ecran.x=320;
EnigmeLVL1->pos_boxes_ecran.y=240;
EnigmeLVL1->pos_boxes_ecran.w=0;
EnigmeLVL1->pos_boxes_ecran.h=0;
EnigmeLVL1->RightCheck=IMG_Load("./lvl1Enigme/RightEnigme.png");
EnigmeLVL1->WrongCheck=IMG_Load("./lvl1Enigme/WrongEnigme.png");
EnigmeLVL1->pos_Checks_ecran.x=328;
EnigmeLVL1->pos_Checks_ecran.y=0;
EnigmeLVL1->pos_Checks_ecran.w=0;
EnigmeLVL1->pos_Checks_ecran.h=0;
EnigmeLVL1->QuestionSurface=NULL;
EnigmeLVL1->pos_question_ecran.x=280;
EnigmeLVL1->pos_question_ecran.y=180;
EnigmeLVL1->pos_question_ecran.w=0;
EnigmeLVL1->pos_question_ecran.h=0;
EnigmeLVL1->AnswerSurface1=NULL;
EnigmeLVL1->AnswerSurface2=NULL;
EnigmeLVL1->AnswerSurface3=NULL;
EnigmeLVL1->pos_answer_ecran.x=440;
EnigmeLVL1->pos_answer_ecran.y=0;
EnigmeLVL1->pos_answer_ecran.w=0;   
EnigmeLVL1->pos_answer_ecran.h=0;
EnigmeLVL1->TimerSurface=NULL;   
EnigmeLVL1->pos_timer_ecran.x=900;
EnigmeLVL1->pos_timer_ecran.y=300;
EnigmeLVL1->pos_timer_ecran.w=0; 
EnigmeLVL1->pos_timer_ecran.h=0;
EnigmeLVL1->color_txt.r=255;
EnigmeLVL1->color_txt.g=255; 
EnigmeLVL1->color_txt.b=255;
EnigmeLVL1->police_question=TTF_OpenFont("./lvl1Enigme/GravityBold8.ttf",17); 
EnigmeLVL1->police_answer=TTF_OpenFont("./lvl1Enigme/GravityBold8.ttf",16); 
GenerateRandomNumberlvl1(EnigmeLVL1);
ReadQuestionFromFilelvl1(EnigmeLVL1);
EnigmeLVL1->click=0;
EnigmeLVL1->timer=1;
EnigmeLVL1->StartOfEnigmeTimer=0;
EnigmeLVL1->Win=0;
EnigmeLVL1->ScoreLVL1.LoseBackground=IMG_Load("./lvl1Enigme/BackgroundLose.png");
EnigmeLVL1->ScoreLVL1.AdvanceBackground=IMG_Load("./lvl1Enigme/BackgroundAdvance.png");
EnigmeLVL1->ScoreLVL1.Next=IMG_Load("./lvl1Enigme/next.png");
EnigmeLVL1->ScoreLVL1.pos_ButtonNext_ecran.x=620;
EnigmeLVL1->ScoreLVL1.pos_ButtonNext_ecran.y=440;
EnigmeLVL1->ScoreLVL1.pos_ButtonNext_ecran.w=0;
EnigmeLVL1->ScoreLVL1.pos_ButtonNext_ecran.h=0;
EnigmeLVL1->ScoreLVL1.Retry=IMG_Load("./lvl1Enigme/retry.png");
EnigmeLVL1->ScoreLVL1.pos_ButtonRetry_ecran.x=620;
EnigmeLVL1->ScoreLVL1.pos_ButtonRetry_ecran.y=440;
EnigmeLVL1->ScoreLVL1.pos_ButtonRetry_ecran.w=0;
EnigmeLVL1->ScoreLVL1.pos_ButtonRetry_ecran.h=0;
EnigmeLVL1->ScoreLVL1.score_police=TTF_OpenFont("./lvl1Enigme/GravityRegular5.ttf",25); 
EnigmeLVL1->ScoreLVL1.color_score.r=255;
EnigmeLVL1->ScoreLVL1.color_score.g=255;
EnigmeLVL1->ScoreLVL1.color_score.b=255;
EnigmeLVL1->ScoreLVL1.SurfaceCoinsSecured=NULL;
EnigmeLVL1->ScoreLVL1.pos_SurfaceCoins_ecran.x=660;
EnigmeLVL1->ScoreLVL1.pos_SurfaceCoins_ecran.y=350;
EnigmeLVL1->ScoreLVL1.pos_SurfaceCoins_ecran.w=0;
EnigmeLVL1->ScoreLVL1.pos_SurfaceCoins_ecran.h=0;
EnigmeLVL1->ScoreLVL1.SurfaceEnnemiesKilled=NULL;
EnigmeLVL1->ScoreLVL1.pos_SurfaceEnnemies_ecran.x=730;
EnigmeLVL1->ScoreLVL1.pos_SurfaceEnnemies_ecran.y=296;
EnigmeLVL1->ScoreLVL1.pos_SurfaceEnnemies_ecran.w=0;
EnigmeLVL1->ScoreLVL1.pos_SurfaceEnnemies_ecran.h=0;
EnigmeLVL1->ScoreLVL1.SurfaceTime=NULL;
EnigmeLVL1->ScoreLVL1.pos_SurfaceTime_ecran.x=650;
EnigmeLVL1->ScoreLVL1.pos_SurfaceTime_ecran.y=400;
EnigmeLVL1->ScoreLVL1.pos_SurfaceTime_ecran.w=0;
EnigmeLVL1->ScoreLVL1.pos_SurfaceTime_ecran.h=0;
EnigmeLVL1->ScoreLVL1.SurfaceFinalScore=NULL;
EnigmeLVL1->ScoreLVL1.pos_SurfaceFinalScore_ecran.x=590;
EnigmeLVL1->ScoreLVL1.pos_SurfaceFinalScore_ecran.y=244;
EnigmeLVL1->ScoreLVL1.pos_SurfaceFinalScore_ecran.w=0;
EnigmeLVL1->ScoreLVL1.pos_SurfaceFinalScore_ecran.h=0;
EnigmeLVL1->ScoreLVL1.IsShown=0;






                     

          
}
 

void reinizialitation_lvl1(Perso *perso,Russia *russia,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1,Hunter *hunter,IceMob *Mob)
{
     
russia->FlagReached=0;
russia->pos_map1_affiche.x=0;
 russia->pos_flag_affiche.x=0;
russia->IsSaveMenuClicked=0;
perso->pos_perso_ecran.x=3;
perso->pos_perso_ecran.y=440;
perso->vie=3;
perso->jump=0;
//perso->repere_imaginaire=0;
perso->JumpStart=0;
perso->CoinsSecured=0;
perso->ColidedWithCoin=0;
perso->ColidedWithCoin2=0; 
perso->ColidedWithCoin3=0;
perso->NotMovingTimer=0;
perso->RunningTimer=0;
perso->JumpingTimer=0;
perso->MouvementTrajectory=0;
perso->EnnemiesKilled=0;
Boss1->DialogueShown=0;
Boss1->Enigme=0;
GenerateRandomNumberlvl1(EnigmeLVL1);
ReadQuestionFromFilelvl1(EnigmeLVL1);
EnigmeLVL1->click=0;
EnigmeLVL1->timer=1;
EnigmeLVL1->StartOfEnigmeTimer=0;
EnigmeLVL1->Win=0;
EnigmeLVL1->ScoreLVL1.IsShown=0;
hunter->EnnemiState=1;
Mob->EnnemiState=1;
















}



void calculate_TimeEnigmeRussia(EnigmeRussia *EnigmeLVL1)
{
  if (EnigmeLVL1->StartOfEnigmeTimer==0)
  {
     
    EnigmeLVL1->StartOfEnigmeTimer=SDL_GetTicks()/1000;
    
  }
if (EnigmeLVL1->timer>0 &&  EnigmeLVL1->click==0 )
{
EnigmeLVL1->timer=(EnigmeLVL1->StartOfEnigmeTimer+15)-(SDL_GetTicks()/1000);
}
 /*printf("%d\n",enigme->timer);*/
sprintf(EnigmeLVL1->Txt_Timer,"%d",EnigmeLVL1->timer);


}
 

void afficher_EnigmeRussia(SDL_Surface *screen,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1)
{
SDL_BlitSurface(Boss1->BossRoom[0] , NULL , screen, NULL);
SDL_BlitSurface(EnigmeLVL1->EnigmeRussiaBackground,NULL,screen,&EnigmeLVL1->pos_background_ecran);
   for(int i=0;i<3;i++)
  {
   
    EnigmeLVL1->pos_boxes_ecran.y=240+(107*i);
    SDL_BlitSurface(EnigmeLVL1->boxes,NULL,screen,&EnigmeLVL1->pos_boxes_ecran);

 }
EnigmeLVL1->QuestionSurface=TTF_RenderText_Blended(EnigmeLVL1->police_question,EnigmeLVL1->question,EnigmeLVL1->color_txt);
	SDL_BlitSurface(EnigmeLVL1->QuestionSurface,NULL,screen,&EnigmeLVL1->pos_question_ecran);
EnigmeLVL1->AnswerSurface1=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL1->answer[0],EnigmeLVL1->color_txt);
EnigmeLVL1->pos_answer_ecran.y=270;
SDL_BlitSurface(EnigmeLVL1->AnswerSurface1,NULL,screen,&EnigmeLVL1->pos_answer_ecran);
EnigmeLVL1->AnswerSurface2=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL1->answer[1],EnigmeLVL1->color_txt);
EnigmeLVL1->pos_answer_ecran.y=377;
SDL_BlitSurface(EnigmeLVL1->AnswerSurface2,NULL,screen,&EnigmeLVL1->pos_answer_ecran);
EnigmeLVL1->AnswerSurface3=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL1->answer[2],EnigmeLVL1->color_txt);
EnigmeLVL1->pos_answer_ecran.y=484;
SDL_BlitSurface(EnigmeLVL1->AnswerSurface3,NULL,screen,&EnigmeLVL1->pos_answer_ecran);

EnigmeLVL1->TimerSurface=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL1->Txt_Timer,EnigmeLVL1->color_txt);
       SDL_BlitSurface(EnigmeLVL1->TimerSurface,NULL,screen,&EnigmeLVL1->pos_timer_ecran);
}
  
 
void Click_answer(SDL_Event event, EnigmeRussia *EnigmeLVL1)
{
 
 
    if ((event.button.x>=320 && event.button.x<=320+EnigmeLVL1->boxes->w) && (event.button.y>=240 && event.button.y<=240+EnigmeLVL1->boxes->h))
  {
     EnigmeLVL1->click=1;
  }
else if ((event.button.x>=320 && event.button.x<=320+EnigmeLVL1->boxes->w) && (event.button.y>=347 && event.button.y<=347+EnigmeLVL1->boxes->h))
 {
     EnigmeLVL1->click=2;
  }
else if ((event.button.x>=320 && event.button.x<=320+EnigmeLVL1->boxes->w) && (event.button.y>=454 && event.button.y<=454+EnigmeLVL1->boxes->h))
 {
     EnigmeLVL1->click=3;
  }








}
 


void Correct_answer(SDL_Surface *screen,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1)
{

if (EnigmeLVL1->click!=0 || EnigmeLVL1->timer==0)
{
if (EnigmeLVL1->CorrectAnswer==1 )
 {
        EnigmeLVL1->pos_Checks_ecran.y=248;
    SDL_BlitSurface(EnigmeLVL1->RightCheck, NULL, screen,  &EnigmeLVL1->pos_Checks_ecran);
    for (int i=0;i<2;i++)
    {
      
      EnigmeLVL1->pos_Checks_ecran.y=355+(107*i);
      SDL_BlitSurface(EnigmeLVL1->WrongCheck, NULL, screen, &EnigmeLVL1->pos_Checks_ecran);
   
    }
   

  }
else if (EnigmeLVL1->CorrectAnswer==2 )
 {
   
    EnigmeLVL1->pos_Checks_ecran.y=355;
    SDL_BlitSurface(EnigmeLVL1->RightCheck, NULL, screen,  &EnigmeLVL1->pos_Checks_ecran);
    for (int i=0;i<2;i++)
    {
      
      EnigmeLVL1->pos_Checks_ecran.y=248+(214*i);
      SDL_BlitSurface(EnigmeLVL1->WrongCheck, NULL, screen, &EnigmeLVL1->pos_Checks_ecran);
   
    }
  }
else if (EnigmeLVL1->CorrectAnswer==3 )
{
    EnigmeLVL1->pos_Checks_ecran.y=462;
    SDL_BlitSurface(EnigmeLVL1->RightCheck, NULL, screen,  &EnigmeLVL1->pos_Checks_ecran);
    for (int i=0;i<2;i++)
    {
      
      EnigmeLVL1->pos_Checks_ecran.y=248+(107*i);
      SDL_BlitSurface(EnigmeLVL1->WrongCheck, NULL, screen, &EnigmeLVL1->pos_Checks_ecran);
   }
}
if (EnigmeLVL1->CorrectAnswer==EnigmeLVL1->click)
{
EnigmeLVL1->Win=1;

}
 
Boss1->Enigme=2;
}


}


void Scorelvl1Calculations(EnigmeRussia *EnigmeLVL1,Perso *perso)
{
if (EnigmeLVL1->ScoreLVL1.IsShown==0)
{
int Time,Score;

Time=SDL_GetTicks()/1000;
Score=(8000+(perso->CoinsSecured*200)+(perso->EnnemiesKilled*500))-(Time*2);
sprintf(EnigmeLVL1->ScoreLVL1.Time,"%d",Time);
sprintf(EnigmeLVL1->ScoreLVL1.CoinsSecured,"%d",perso->CoinsSecured);
sprintf(EnigmeLVL1->ScoreLVL1.EnnemiesKilled,"%d",perso->EnnemiesKilled);
sprintf(EnigmeLVL1->ScoreLVL1.FinalScore,"%d",Score);

EnigmeLVL1->ScoreLVL1.IsShown++;
}


 

 
 




} 

 
void afficher_Backgroundscore(SDL_Surface *screen,EnigmeRussia *EnigmeLVL1)
{

if (EnigmeLVL1->Win==1)
{
SDL_BlitSurface(EnigmeLVL1->ScoreLVL1.AdvanceBackground,NULL,screen,&EnigmeLVL1->pos_background_ecran);
SDL_BlitSurface(EnigmeLVL1->ScoreLVL1.Next,NULL,screen,&EnigmeLVL1->ScoreLVL1.pos_ButtonNext_ecran);

}
else
{
SDL_BlitSurface(EnigmeLVL1->ScoreLVL1.LoseBackground,NULL,screen,&EnigmeLVL1->pos_background_ecran);
SDL_BlitSurface(EnigmeLVL1->ScoreLVL1.Retry,NULL,screen,&EnigmeLVL1->ScoreLVL1.pos_ButtonRetry_ecran);
} 

EnigmeLVL1->ScoreLVL1.SurfaceCoinsSecured=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL1->ScoreLVL1.CoinsSecured,EnigmeLVL1->ScoreLVL1.color_score);
SDL_BlitSurface(EnigmeLVL1->ScoreLVL1.SurfaceCoinsSecured,NULL,screen,&EnigmeLVL1->ScoreLVL1.pos_SurfaceCoins_ecran);
EnigmeLVL1->ScoreLVL1.SurfaceEnnemiesKilled=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL1->ScoreLVL1.EnnemiesKilled,EnigmeLVL1->ScoreLVL1.color_score);
SDL_BlitSurface(EnigmeLVL1->ScoreLVL1.SurfaceEnnemiesKilled,NULL,screen,&EnigmeLVL1->ScoreLVL1.pos_SurfaceEnnemies_ecran);
EnigmeLVL1->ScoreLVL1.SurfaceTime=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL1->ScoreLVL1.Time,EnigmeLVL1->ScoreLVL1.color_score);
SDL_BlitSurface(EnigmeLVL1->ScoreLVL1.SurfaceTime,NULL,screen,&EnigmeLVL1->ScoreLVL1.pos_SurfaceTime_ecran);
EnigmeLVL1->ScoreLVL1.SurfaceFinalScore=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL1->ScoreLVL1.FinalScore,EnigmeLVL1->ScoreLVL1.color_score);
SDL_BlitSurface(EnigmeLVL1->ScoreLVL1.SurfaceFinalScore,NULL,screen,&EnigmeLVL1->ScoreLVL1.pos_SurfaceFinalScore_ecran);


 
         
}

void Click_AfterAnsweringRussia(SDL_Event event,int *GameState,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1,int *Reinitialisation_lvl1,int *Reinitialisation_lvl2,int *MusicGame)
{

if (Boss1->Enigme==3 &&  EnigmeLVL1->Win==1)
{
   if ((event.button.x>=620 && event.button.x<=620+EnigmeLVL1->ScoreLVL1.Next->w) && (event.button.y>=440 && event.button.y<=440+EnigmeLVL1->ScoreLVL1.Next->h))
  {
     *GameState=4;
     *Reinitialisation_lvl2=0;
     *MusicGame=0;
  }
   
  
}
else if (Boss1->Enigme==3 &&  EnigmeLVL1->Win==0)
{


   if ((event.button.x>=620 && event.button.x<=620+EnigmeLVL1->ScoreLVL1.Retry->w) && (event.button.y>=440 && event.button.y<=440+EnigmeLVL1->ScoreLVL1.Retry->h))
 
 {
      *MusicGame=0;
     *GameState=1;
     *Reinitialisation_lvl1=0;
  }
     


} 


}
 
   
void Free_EnigmeRussia(EnigmeRussia *EnigmeLVL1)
{
SDL_FreeSurface(EnigmeLVL1->EnigmeRussiaBackground);
SDL_FreeSurface(EnigmeLVL1->boxes);
SDL_FreeSurface(EnigmeLVL1->RightCheck);
SDL_FreeSurface(EnigmeLVL1->WrongCheck);
SDL_FreeSurface(EnigmeLVL1->QuestionSurface);
SDL_FreeSurface(EnigmeLVL1->AnswerSurface1);
SDL_FreeSurface(EnigmeLVL1->AnswerSurface2);
SDL_FreeSurface(EnigmeLVL1->AnswerSurface3);
SDL_FreeSurface(EnigmeLVL1->TimerSurface);
 TTF_CloseFont(EnigmeLVL1->police_question);
 TTF_CloseFont(EnigmeLVL1->police_answer);  
SDL_FreeSurface(EnigmeLVL1->ScoreLVL1.LoseBackground);
SDL_FreeSurface(EnigmeLVL1->ScoreLVL1.AdvanceBackground);
SDL_FreeSurface(EnigmeLVL1->ScoreLVL1.Next);
SDL_FreeSurface(EnigmeLVL1->ScoreLVL1.Retry);
TTF_CloseFont(EnigmeLVL1->ScoreLVL1.score_police);
SDL_FreeSurface(EnigmeLVL1->ScoreLVL1.SurfaceCoinsSecured);
SDL_FreeSurface(EnigmeLVL1->ScoreLVL1.SurfaceEnnemiesKilled);
SDL_FreeSurface(EnigmeLVL1->ScoreLVL1.SurfaceTime);
SDL_FreeSurface(EnigmeLVL1->ScoreLVL1.SurfaceFinalScore);


free(EnigmeLVL1);









}
