#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

  

int GenerateRandomNumberlvl2(EnigmeEgypt *EnigmeLVL2)
{ 
  
  srand(time(NULL));
do
 {
  EnigmeLVL2->Random_Number=rand()% 15+1;
 }
while(EnigmeLVL2->Random_Number!=1 && EnigmeLVL2->Random_Number!=6 && EnigmeLVL2->Random_Number!=11);
 
}



void ReadQuestionFromFilelvl2(EnigmeEgypt *EnigmeLVL2)
{
  FILE *f;
  int length;
  char line[256];
  char CorrectAnswer[2];
  f=fopen("./lvl2Enigme/EgyptQuestions.txt","r");
  if (f==NULL)
   {
     printf("failed to open file");
     
   }
else
{
 for (int j=1;j<(EnigmeLVL2->Random_Number);j++)
 { 
  fgets(line,sizeof(line),f);

 }
 fgets(line,sizeof(line),f);

 

 strcpy(EnigmeLVL2->question,line);

for (int k=0;k<3;k++)
{
 fgets(line,sizeof(line),f);

 strcpy(EnigmeLVL2->answer[k],line);

}
 fgets(CorrectAnswer,sizeof(CorrectAnswer),f);
 EnigmeLVL2->CorrectAnswer=atoi(CorrectAnswer);

fclose(f);
}
}



void initialiser_EnigmeEgypt(EnigmeEgypt *EnigmeLVL2)
{
 

EnigmeLVL2->EnigmeEgyptBackground=IMG_Load("./lvl2Enigme/BackgroundEnigmeEgypt.png");
EnigmeLVL2->pos_background_ecran.x=220;
EnigmeLVL2->pos_background_ecran.y=100;
EnigmeLVL2->pos_background_ecran.w=0;
EnigmeLVL2->pos_background_ecran.h=0;
EnigmeLVL2->boxes=IMG_Load("./lvl2Enigme/Box.png");
EnigmeLVL2->pos_boxes_ecran.x=320;
EnigmeLVL2->pos_boxes_ecran.y=240;
EnigmeLVL2->pos_boxes_ecran.w=0;
EnigmeLVL2->pos_boxes_ecran.h=0;
EnigmeLVL2->RightCheck=IMG_Load("./lvl2Enigme/RightEnigme.png");
EnigmeLVL2->WrongCheck=IMG_Load("./lvl2Enigme/WrongEnigme.png");
EnigmeLVL2->pos_Checks_ecran.x=328;
EnigmeLVL2->pos_Checks_ecran.y=0;
EnigmeLVL2->pos_Checks_ecran.w=0;
EnigmeLVL2->pos_Checks_ecran.h=0;
EnigmeLVL2->QuestionSurface=NULL;
EnigmeLVL2->pos_question_ecran.x=280;
EnigmeLVL2->pos_question_ecran.y=180;
EnigmeLVL2->pos_question_ecran.w=0;
EnigmeLVL2->pos_question_ecran.h=0;
EnigmeLVL2->AnswerSurface1=NULL;
EnigmeLVL2->AnswerSurface2=NULL;
EnigmeLVL2->AnswerSurface3=NULL;
EnigmeLVL2->pos_answer_ecran.x=440;
EnigmeLVL2->pos_answer_ecran.y=0;
EnigmeLVL2->pos_answer_ecran.w=0;   
EnigmeLVL2->pos_answer_ecran.h=0;
EnigmeLVL2->TimerSurface=NULL;   
EnigmeLVL2->pos_timer_ecran.x=900;
EnigmeLVL2->pos_timer_ecran.y=300;
EnigmeLVL2->pos_timer_ecran.w=0;
EnigmeLVL2->pos_timer_ecran.h=0;
EnigmeLVL2->color_txt.r=255;
EnigmeLVL2->color_txt.g=255; 
EnigmeLVL2->color_txt.b=255;
GenerateRandomNumberlvl2(EnigmeLVL2);
ReadQuestionFromFilelvl2(EnigmeLVL2);
EnigmeLVL2->click=0;
EnigmeLVL2->timer=1;
EnigmeLVL2->StartOfEnigmeTimer=0;
EnigmeLVL2->Win=0;
EnigmeLVL2->ScoreLVL2.LoseBackground=IMG_Load("./lvl2Enigme/BackgroundLose.png");
EnigmeLVL2->ScoreLVL2.AdvanceBackground=IMG_Load("./lvl2Enigme/BackgroundAdvance.png");
EnigmeLVL2->ScoreLVL2.Next=IMG_Load("./lvl2Enigme/next.png");
EnigmeLVL2->ScoreLVL2.pos_ButtonNext_ecran.x=620;
EnigmeLVL2->ScoreLVL2.pos_ButtonNext_ecran.y=440;
EnigmeLVL2->ScoreLVL2.pos_ButtonNext_ecran.w=0;
EnigmeLVL2->ScoreLVL2.pos_ButtonNext_ecran.h=0;
EnigmeLVL2->ScoreLVL2.Retry=IMG_Load("./lvl2Enigme/retry.png");
EnigmeLVL2->ScoreLVL2.pos_ButtonRetry_ecran.x=620;
EnigmeLVL2->ScoreLVL2.pos_ButtonRetry_ecran.y=440;
EnigmeLVL2->ScoreLVL2.pos_ButtonRetry_ecran.w=0;
EnigmeLVL2->ScoreLVL2.pos_ButtonRetry_ecran.h=0;
//EnigmeLVL2->ScoreLVL2.score_police=TTF_OpenFont("./lvl1Enigme/GravityRegular5.ttf",25); 
EnigmeLVL2->ScoreLVL2.color_score.r=255;
EnigmeLVL2->ScoreLVL2.color_score.g=255;
EnigmeLVL2->ScoreLVL2.color_score.b=255;
EnigmeLVL2->ScoreLVL2.SurfaceCoinsSecured=NULL;
EnigmeLVL2->ScoreLVL2.pos_SurfaceCoins_ecran.x=660;
EnigmeLVL2->ScoreLVL2.pos_SurfaceCoins_ecran.y=350;
EnigmeLVL2->ScoreLVL2.pos_SurfaceCoins_ecran.w=0;
EnigmeLVL2->ScoreLVL2.pos_SurfaceCoins_ecran.h=0;  
EnigmeLVL2->ScoreLVL2.SurfaceEnnemiesKilled=NULL;
EnigmeLVL2->ScoreLVL2.pos_SurfaceEnnemies_ecran.x=730;
EnigmeLVL2->ScoreLVL2.pos_SurfaceEnnemies_ecran.y=296;
EnigmeLVL2->ScoreLVL2.pos_SurfaceEnnemies_ecran.w=0;
EnigmeLVL2->ScoreLVL2.pos_SurfaceEnnemies_ecran.h=0;
EnigmeLVL2->ScoreLVL2.SurfaceTime=NULL;
EnigmeLVL2->ScoreLVL2.pos_SurfaceTime_ecran.x=650;
EnigmeLVL2->ScoreLVL2.pos_SurfaceTime_ecran.y=400;
EnigmeLVL2->ScoreLVL2.pos_SurfaceTime_ecran.w=0;
EnigmeLVL2->ScoreLVL2.pos_SurfaceTime_ecran.h=0;
EnigmeLVL2->ScoreLVL2.SurfaceFinalScore=NULL;
EnigmeLVL2->ScoreLVL2.pos_SurfaceFinalScore_ecran.x=590;
EnigmeLVL2->ScoreLVL2.pos_SurfaceFinalScore_ecran.y=244;
EnigmeLVL2->ScoreLVL2.pos_SurfaceFinalScore_ecran.w=0;
EnigmeLVL2->ScoreLVL2.pos_SurfaceFinalScore_ecran.h=0;
EnigmeLVL2->ScoreLVL2.IsShown=0;

}       



void calculate_TimeEnigmeEgypt(EnigmeEgypt *EnigmeLVL2)
{
  if (EnigmeLVL2->StartOfEnigmeTimer==0)
  {
     
    EnigmeLVL2->StartOfEnigmeTimer=SDL_GetTicks()/1000;
    
  }
if (EnigmeLVL2->timer>0 &&  EnigmeLVL2->click==0 )
{
EnigmeLVL2->timer=(EnigmeLVL2->StartOfEnigmeTimer+15)-(SDL_GetTicks()/1000);
}
 /*printf("%d\n",enigme->timer);*/
sprintf(EnigmeLVL2->Txt_Timer,"%d",EnigmeLVL2->timer);

} 


void afficher_EnigmeEgypt(SDL_Surface *screen,EnigmeEgypt *EnigmeLVL2,EnigmeRussia *EnigmeLVL1,BossRoomEgypt *Boss2)
{
SDL_BlitSurface(Boss2->BossRoom[0] , NULL , screen, NULL);
SDL_BlitSurface(EnigmeLVL2->EnigmeEgyptBackground,NULL,screen,&EnigmeLVL2->pos_background_ecran);
   for(int i=0;i<3;i++)
  {
   
    EnigmeLVL2->pos_boxes_ecran.y=240+(107*i);
    SDL_BlitSurface(EnigmeLVL2->boxes,NULL,screen,&EnigmeLVL2->pos_boxes_ecran);

 }
EnigmeLVL2->QuestionSurface=TTF_RenderText_Blended(EnigmeLVL1->police_question,EnigmeLVL2->question,EnigmeLVL2->color_txt);
	SDL_BlitSurface(EnigmeLVL2->QuestionSurface,NULL,screen,&EnigmeLVL2->pos_question_ecran);
EnigmeLVL2->AnswerSurface1=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL2->answer[0],EnigmeLVL2->color_txt);
EnigmeLVL2->pos_answer_ecran.y=270;
SDL_BlitSurface(EnigmeLVL2->AnswerSurface1,NULL,screen,&EnigmeLVL2->pos_answer_ecran);
EnigmeLVL2->AnswerSurface2=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL2->answer[1],EnigmeLVL2->color_txt);
EnigmeLVL2->pos_answer_ecran.y=377;
SDL_BlitSurface(EnigmeLVL2->AnswerSurface2,NULL,screen,&EnigmeLVL2->pos_answer_ecran);
EnigmeLVL2->AnswerSurface3=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL2->answer[2],EnigmeLVL2->color_txt);
EnigmeLVL2->pos_answer_ecran.y=484;
SDL_BlitSurface(EnigmeLVL2->AnswerSurface3,NULL,screen,&EnigmeLVL2->pos_answer_ecran);

EnigmeLVL2->TimerSurface=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL2->Txt_Timer,EnigmeLVL2->color_txt);
       SDL_BlitSurface(EnigmeLVL2->TimerSurface,NULL,screen,&EnigmeLVL2->pos_timer_ecran);
}



void Click_answerEgypt(SDL_Event event, EnigmeEgypt *EnigmeLVL2)
{
 
 
    if ((event.button.x>=320 && event.button.x<=320+EnigmeLVL2->boxes->w) && (event.button.y>=240 && event.button.y<=240+EnigmeLVL2->boxes->h))
  {
     EnigmeLVL2->click=1;
  }
else if ((event.button.x>=320 && event.button.x<=320+EnigmeLVL2->boxes->w) && (event.button.y>=347 && event.button.y<=347+EnigmeLVL2->boxes->h))
 {
     EnigmeLVL2->click=2;
  }
else if ((event.button.x>=320 && event.button.x<=320+EnigmeLVL2->boxes->w) && (event.button.y>=454 && event.button.y<=454+EnigmeLVL2->boxes->h))
 {
     EnigmeLVL2->click=3;
  }








}


void Correct_answerEgypt(SDL_Surface *screen,EnigmeEgypt *EnigmeLVL2,BossRoomEgypt *Boss2)
{

if (EnigmeLVL2->click!=0 || EnigmeLVL2->timer==0)
{
if (EnigmeLVL2->CorrectAnswer==1 )
 {
        EnigmeLVL2->pos_Checks_ecran.y=248;
    SDL_BlitSurface(EnigmeLVL2->RightCheck, NULL, screen,  &EnigmeLVL2->pos_Checks_ecran);
    for (int i=0;i<2;i++)
    {
      
      EnigmeLVL2->pos_Checks_ecran.y=355+(107*i);
      SDL_BlitSurface(EnigmeLVL2->WrongCheck, NULL, screen, &EnigmeLVL2->pos_Checks_ecran);
   
    }
   

  }
else if (EnigmeLVL2->CorrectAnswer==2 )
 {
   
    EnigmeLVL2->pos_Checks_ecran.y=355;
    SDL_BlitSurface(EnigmeLVL2->RightCheck, NULL, screen,  &EnigmeLVL2->pos_Checks_ecran);
    for (int i=0;i<2;i++)
    {
      
      EnigmeLVL2->pos_Checks_ecran.y=248+(214*i);
      SDL_BlitSurface(EnigmeLVL2->WrongCheck, NULL, screen, &EnigmeLVL2->pos_Checks_ecran);
   
    }
  }
else if (EnigmeLVL2->CorrectAnswer==3 )
{
    EnigmeLVL2->pos_Checks_ecran.y=462;
    SDL_BlitSurface(EnigmeLVL2->RightCheck, NULL, screen,  &EnigmeLVL2->pos_Checks_ecran);
    for (int i=0;i<2;i++)
    {
      
      EnigmeLVL2->pos_Checks_ecran.y=248+(107*i);
      SDL_BlitSurface(EnigmeLVL2->WrongCheck, NULL, screen, &EnigmeLVL2->pos_Checks_ecran);
   }
}
if (EnigmeLVL2->CorrectAnswer==EnigmeLVL2->click)
{
EnigmeLVL2->Win=1;

}
 
Boss2->Enigme=2;
}
  

}
  

void Scorelvl2Calculations(EnigmeEgypt *EnigmeLVL2,Perso *perso)
{
if (EnigmeLVL2->ScoreLVL2.IsShown==0)
{
int Time,Score;

Time=SDL_GetTicks()/1000;
Score=(8000+(perso->CoinsSecured*200)+(perso->EnnemiesKilled*500))-(Time*2);
sprintf(EnigmeLVL2->ScoreLVL2.Time,"%d",Time);
sprintf(EnigmeLVL2->ScoreLVL2.CoinsSecured,"%d",perso->CoinsSecured);
sprintf(EnigmeLVL2->ScoreLVL2.EnnemiesKilled,"%d",perso->EnnemiesKilled);
sprintf(EnigmeLVL2->ScoreLVL2.FinalScore,"%d",Score);

EnigmeLVL2->ScoreLVL2.IsShown++;
}

} 




void afficher_BackgroundEgyptscore(SDL_Surface *screen,EnigmeEgypt *EnigmeLVL2,EnigmeRussia *EnigmeLVL1)
{

if (EnigmeLVL2->Win==1)
{
SDL_BlitSurface(EnigmeLVL2->ScoreLVL2.AdvanceBackground,NULL,screen,&EnigmeLVL2->pos_background_ecran);
SDL_BlitSurface(EnigmeLVL2->ScoreLVL2.Next,NULL,screen,&EnigmeLVL2->ScoreLVL2.pos_ButtonNext_ecran);
 
}
else
{
SDL_BlitSurface(EnigmeLVL2->ScoreLVL2.LoseBackground,NULL,screen,&EnigmeLVL2->pos_background_ecran);
SDL_BlitSurface(EnigmeLVL2->ScoreLVL2.Retry,NULL,screen,&EnigmeLVL2->ScoreLVL2.pos_ButtonRetry_ecran);
} 

EnigmeLVL2->ScoreLVL2.SurfaceCoinsSecured=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL2->ScoreLVL2.CoinsSecured,EnigmeLVL2->ScoreLVL2.color_score);
SDL_BlitSurface(EnigmeLVL2->ScoreLVL2.SurfaceCoinsSecured,NULL,screen,&EnigmeLVL2->ScoreLVL2.pos_SurfaceCoins_ecran);
EnigmeLVL2->ScoreLVL2.SurfaceEnnemiesKilled=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL2->ScoreLVL2.EnnemiesKilled,EnigmeLVL2->ScoreLVL2.color_score);
SDL_BlitSurface(EnigmeLVL2->ScoreLVL2.SurfaceEnnemiesKilled,NULL,screen,&EnigmeLVL2->ScoreLVL2.pos_SurfaceEnnemies_ecran);
EnigmeLVL2->ScoreLVL2.SurfaceTime=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL2->ScoreLVL2.Time,EnigmeLVL2->ScoreLVL2.color_score);
SDL_BlitSurface(EnigmeLVL2->ScoreLVL2.SurfaceTime,NULL,screen,&EnigmeLVL2->ScoreLVL2.pos_SurfaceTime_ecran);
EnigmeLVL2->ScoreLVL2.SurfaceFinalScore=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL2->ScoreLVL2.FinalScore,EnigmeLVL2->ScoreLVL2.color_score);
SDL_BlitSurface(EnigmeLVL2->ScoreLVL2.SurfaceFinalScore,NULL,screen,&EnigmeLVL2->ScoreLVL2.pos_SurfaceFinalScore_ecran);

  
         
  
}
 

void Click_AfterAnsweringEgypt(SDL_Event event,int *GameState,EnigmeEgypt *EnigmeLVL2,BossRoomEgypt *Boss2,int *Reinitialisation_lvl2,int *Reinitialisation_lvl3,int *MusicGame)
{

if (Boss2->Enigme==3 &&  EnigmeLVL2->Win==1)
{
   if ((event.button.x>=620 && event.button.x<=620+EnigmeLVL2->ScoreLVL2.Next->w) && (event.button.y>=440 && event.button.y<=440+EnigmeLVL2->ScoreLVL2.Next->h))
  {
     *MusicGame=0;
     *GameState=6;
     *Reinitialisation_lvl3=0;
  }
   

}
else if (Boss2->Enigme==3 &&  EnigmeLVL2->Win==0)
{


   if ((event.button.x>=620 && event.button.x<=620+EnigmeLVL2->ScoreLVL2.Retry->w) && (event.button.y>=440 && event.button.y<=440+EnigmeLVL2->ScoreLVL2.Retry->h))
 
 {
     *MusicGame=0;
     *GameState=4;
     *Reinitialisation_lvl2=0;
  }
  
    

} 

 
}

 
void Free_EnigmeEgypt(EnigmeEgypt *EnigmeLVL2)
{
SDL_FreeSurface(EnigmeLVL2->EnigmeEgyptBackground);
SDL_FreeSurface(EnigmeLVL2->boxes);
SDL_FreeSurface(EnigmeLVL2->RightCheck);
SDL_FreeSurface(EnigmeLVL2->WrongCheck);
SDL_FreeSurface(EnigmeLVL2->QuestionSurface);
SDL_FreeSurface(EnigmeLVL2->AnswerSurface1);
SDL_FreeSurface(EnigmeLVL2->AnswerSurface2);
SDL_FreeSurface(EnigmeLVL2->AnswerSurface3);
SDL_FreeSurface(EnigmeLVL2->TimerSurface);  
SDL_FreeSurface(EnigmeLVL2->ScoreLVL2.LoseBackground);
SDL_FreeSurface(EnigmeLVL2->ScoreLVL2.AdvanceBackground);
SDL_FreeSurface(EnigmeLVL2->ScoreLVL2.Next);
SDL_FreeSurface(EnigmeLVL2->ScoreLVL2.Retry);
//TTF_CloseFont(EnigmeLVL1->ScoreLVL1.score_police);
SDL_FreeSurface(EnigmeLVL2->ScoreLVL2.SurfaceCoinsSecured);
SDL_FreeSurface(EnigmeLVL2->ScoreLVL2.SurfaceEnnemiesKilled);
SDL_FreeSurface(EnigmeLVL2->ScoreLVL2.SurfaceTime);
SDL_FreeSurface(EnigmeLVL2->ScoreLVL2.SurfaceFinalScore);


free(EnigmeLVL2);









}

