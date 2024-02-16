#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

   

int GenerateRandomNumberlvl3(EnigmeJapan *EnigmeLVL3)
{ 
  
  srand(time(NULL));
do
 {
  EnigmeLVL3->Random_Number=rand()% 15+1;
 }
while(EnigmeLVL3->Random_Number!=1 && EnigmeLVL3->Random_Number!=6 && EnigmeLVL3->Random_Number!=11);
 
}




void ReadQuestionFromFilelvl3(EnigmeJapan *EnigmeLVL3)
{
  FILE *f;
  int length;
  char line[256];
  char CorrectAnswer[2];
  f=fopen("./lvl3Enigme/JapanQuestions.txt","r");
  if (f==NULL)
   {
     printf("failed to open file");
     
   }
else
{
 for (int j=1;j<(EnigmeLVL3->Random_Number);j++)
 { 
  fgets(line,sizeof(line),f);

 }
 fgets(line,sizeof(line),f);

 

 strcpy(EnigmeLVL3->question,line);

for (int k=0;k<3;k++)
{
 fgets(line,sizeof(line),f);

 strcpy(EnigmeLVL3->answer[k],line);

}
 fgets(CorrectAnswer,sizeof(CorrectAnswer),f);
 EnigmeLVL3->CorrectAnswer=atoi(CorrectAnswer);

fclose(f);
}
}  






void initialiser_EnigmeJapan(EnigmeJapan *EnigmeLVL3)
{

EnigmeLVL3->EnigmeJapanBackground=IMG_Load("./lvl3Enigme/BackgroundEnigmeJapan.png");
EnigmeLVL3->pos_background_ecran.x=220;
EnigmeLVL3->pos_background_ecran.y=100;
EnigmeLVL3->pos_background_ecran.w=0;
EnigmeLVL3->pos_background_ecran.h=0;
EnigmeLVL3->boxes=IMG_Load("./lvl3Enigme/Box.png");
EnigmeLVL3->pos_boxes_ecran.x=320;
EnigmeLVL3->pos_boxes_ecran.y=240;
EnigmeLVL3->pos_boxes_ecran.w=0;
EnigmeLVL3->pos_boxes_ecran.h=0;
EnigmeLVL3->RightCheck=IMG_Load("./lvl3Enigme/RightEnigme.png");
EnigmeLVL3->WrongCheck=IMG_Load("./lvl3Enigme/WrongEnigme.png");
EnigmeLVL3->pos_Checks_ecran.x=328;
EnigmeLVL3->pos_Checks_ecran.y=0;
EnigmeLVL3->pos_Checks_ecran.w=0;
EnigmeLVL3->pos_Checks_ecran.h=0;
EnigmeLVL3->QuestionSurface=NULL;
EnigmeLVL3->pos_question_ecran.x=280;
EnigmeLVL3->pos_question_ecran.y=180;
EnigmeLVL3->pos_question_ecran.w=0;
EnigmeLVL3->pos_question_ecran.h=0;
EnigmeLVL3->AnswerSurface1=NULL;
EnigmeLVL3->AnswerSurface2=NULL;
EnigmeLVL3->AnswerSurface3=NULL;
EnigmeLVL3->pos_answer_ecran.x=440;
EnigmeLVL3->pos_answer_ecran.y=0;
EnigmeLVL3->pos_answer_ecran.w=0;   
EnigmeLVL3->pos_answer_ecran.h=0;
EnigmeLVL3->TimerSurface=NULL;   
EnigmeLVL3->pos_timer_ecran.x=900;
EnigmeLVL3->pos_timer_ecran.y=300;
EnigmeLVL3->pos_timer_ecran.w=0;
EnigmeLVL3->pos_timer_ecran.h=0;
EnigmeLVL3->color_txt.r=255;
EnigmeLVL3->color_txt.g=255; 
EnigmeLVL3->color_txt.b=255;
GenerateRandomNumberlvl3(EnigmeLVL3);
ReadQuestionFromFilelvl3(EnigmeLVL3);
EnigmeLVL3->click=0;
EnigmeLVL3->timer=1;
EnigmeLVL3->StartOfEnigmeTimer=0;
EnigmeLVL3->Win=0;
EnigmeLVL3->ScoreLVL3.LoseBackground=IMG_Load("./lvl3Enigme/BackgroundLose.png");
EnigmeLVL3->ScoreLVL3.AdvanceBackground=IMG_Load("./lvl3Enigme/BackgroundAdvance.png");
EnigmeLVL3->ScoreLVL3.Next=IMG_Load("./lvl3Enigme/next.png");
EnigmeLVL3->ScoreLVL3.pos_ButtonNext_ecran.x=620;
EnigmeLVL3->ScoreLVL3.pos_ButtonNext_ecran.y=440;
EnigmeLVL3->ScoreLVL3.pos_ButtonNext_ecran.w=0;
EnigmeLVL3->ScoreLVL3.pos_ButtonNext_ecran.h=0;
EnigmeLVL3->ScoreLVL3.Retry=IMG_Load("./lvl3Enigme/retry.png");
EnigmeLVL3->ScoreLVL3.pos_ButtonRetry_ecran.x=620;
EnigmeLVL3->ScoreLVL3.pos_ButtonRetry_ecran.y=440;
EnigmeLVL3->ScoreLVL3.pos_ButtonRetry_ecran.w=0;
EnigmeLVL3->ScoreLVL3.pos_ButtonRetry_ecran.h=0;
//EnigmeLVL2->ScoreLVL2.score_police=TTF_OpenFont("./lvl1Enigme/GravityRegular5.ttf",25); 
EnigmeLVL3->ScoreLVL3.color_score.r=255;
EnigmeLVL3->ScoreLVL3.color_score.g=255;
EnigmeLVL3->ScoreLVL3.color_score.b=255;
EnigmeLVL3->ScoreLVL3.SurfaceCoinsSecured=NULL;
EnigmeLVL3->ScoreLVL3.pos_SurfaceCoins_ecran.x=660;
EnigmeLVL3->ScoreLVL3.pos_SurfaceCoins_ecran.y=350;
EnigmeLVL3->ScoreLVL3.pos_SurfaceCoins_ecran.w=0;
EnigmeLVL3->ScoreLVL3.pos_SurfaceCoins_ecran.h=0;
EnigmeLVL3->ScoreLVL3.SurfaceEnnemiesKilled=NULL;
EnigmeLVL3->ScoreLVL3.pos_SurfaceEnnemies_ecran.x=730;
EnigmeLVL3->ScoreLVL3.pos_SurfaceEnnemies_ecran.y=296;
EnigmeLVL3->ScoreLVL3.pos_SurfaceEnnemies_ecran.w=0;
EnigmeLVL3->ScoreLVL3.pos_SurfaceEnnemies_ecran.h=0;
EnigmeLVL3->ScoreLVL3.SurfaceTime=NULL;
EnigmeLVL3->ScoreLVL3.pos_SurfaceTime_ecran.x=650;
EnigmeLVL3->ScoreLVL3.pos_SurfaceTime_ecran.y=400;
EnigmeLVL3->ScoreLVL3.pos_SurfaceTime_ecran.w=0;
EnigmeLVL3->ScoreLVL3.pos_SurfaceTime_ecran.h=0;
EnigmeLVL3->ScoreLVL3.SurfaceFinalScore=NULL;
EnigmeLVL3->ScoreLVL3.pos_SurfaceFinalScore_ecran.x=590;
EnigmeLVL3->ScoreLVL3.pos_SurfaceFinalScore_ecran.y=244;
EnigmeLVL3->ScoreLVL3.pos_SurfaceFinalScore_ecran.w=0;
EnigmeLVL3->ScoreLVL3.pos_SurfaceFinalScore_ecran.h=0;
EnigmeLVL3->ScoreLVL3.IsShown=0;

}  

void calculate_TimeEnigmeJapan(EnigmeJapan *EnigmeLVL3)
{
  if (EnigmeLVL3->StartOfEnigmeTimer==0)
  {
     
    EnigmeLVL3->StartOfEnigmeTimer=SDL_GetTicks()/1000;
    
  }
if (EnigmeLVL3->timer>0 &&  EnigmeLVL3->click==0 )
{
EnigmeLVL3->timer=(EnigmeLVL3->StartOfEnigmeTimer+15)-(SDL_GetTicks()/1000);
}
 /*printf("%d\n",enigme->timer);*/
sprintf(EnigmeLVL3->Txt_Timer,"%d",EnigmeLVL3->timer);

}

 

void afficher_EnigmeJapan(SDL_Surface *screen,EnigmeJapan *EnigmeLVL3,EnigmeRussia *EnigmeLVL1,BossRoomJapan *Boss3)
{
SDL_BlitSurface(Boss3->BossRoom[0] , NULL , screen, NULL);
SDL_BlitSurface(EnigmeLVL3->EnigmeJapanBackground,NULL,screen,&EnigmeLVL3->pos_background_ecran);
   for(int i=0;i<3;i++)
  {
   
    EnigmeLVL3->pos_boxes_ecran.y=240+(107*i);
    SDL_BlitSurface(EnigmeLVL3->boxes,NULL,screen,&EnigmeLVL3->pos_boxes_ecran);

 }
EnigmeLVL3->QuestionSurface=TTF_RenderText_Blended(EnigmeLVL1->police_question,EnigmeLVL3->question,EnigmeLVL3->color_txt);
	SDL_BlitSurface(EnigmeLVL3->QuestionSurface,NULL,screen,&EnigmeLVL3->pos_question_ecran);
EnigmeLVL3->AnswerSurface1=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL3->answer[0],EnigmeLVL3->color_txt);
EnigmeLVL3->pos_answer_ecran.y=270;
SDL_BlitSurface(EnigmeLVL3->AnswerSurface1,NULL,screen,&EnigmeLVL3->pos_answer_ecran);
EnigmeLVL3->AnswerSurface2=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL3->answer[1],EnigmeLVL3->color_txt);
EnigmeLVL3->pos_answer_ecran.y=377;
SDL_BlitSurface(EnigmeLVL3->AnswerSurface2,NULL,screen,&EnigmeLVL3->pos_answer_ecran);
EnigmeLVL3->AnswerSurface3=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL3->answer[2],EnigmeLVL3->color_txt);
EnigmeLVL3->pos_answer_ecran.y=484;
SDL_BlitSurface(EnigmeLVL3->AnswerSurface3,NULL,screen,&EnigmeLVL3->pos_answer_ecran);

EnigmeLVL3->TimerSurface=TTF_RenderText_Blended(EnigmeLVL1->police_answer,EnigmeLVL3->Txt_Timer,EnigmeLVL3->color_txt);
       SDL_BlitSurface(EnigmeLVL3->TimerSurface,NULL,screen,&EnigmeLVL3->pos_timer_ecran);
}


void Click_answerJapan(SDL_Event event, EnigmeJapan *EnigmeLVL3)
{
 
 
    if ((event.button.x>=320 && event.button.x<=320+EnigmeLVL3->boxes->w) && (event.button.y>=240 && event.button.y<=240+EnigmeLVL3->boxes->h))
  {
     EnigmeLVL3->click=1;
  }
else if ((event.button.x>=320 && event.button.x<=320+EnigmeLVL3->boxes->w) && (event.button.y>=347 && event.button.y<=347+EnigmeLVL3->boxes->h))
 {
     EnigmeLVL3->click=2;
  }
else if ((event.button.x>=320 && event.button.x<=320+EnigmeLVL3->boxes->w) && (event.button.y>=454 && event.button.y<=454+EnigmeLVL3->boxes->h))
 {
     EnigmeLVL3->click=3;
  }



}



void Correct_answerJapan(SDL_Surface *screen,EnigmeJapan *EnigmeLVL3,BossRoomJapan *Boss3)
{

if (EnigmeLVL3->click!=0 || EnigmeLVL3->timer==0)
{
if (EnigmeLVL3->CorrectAnswer==1 )
 {
        EnigmeLVL3->pos_Checks_ecran.y=248;
    SDL_BlitSurface(EnigmeLVL3->RightCheck, NULL, screen,  &EnigmeLVL3->pos_Checks_ecran);
    for (int i=0;i<2;i++)
    {
      
      EnigmeLVL3->pos_Checks_ecran.y=355+(107*i);
      SDL_BlitSurface(EnigmeLVL3->WrongCheck, NULL, screen, &EnigmeLVL3->pos_Checks_ecran);
   
    }
   

  }
else if (EnigmeLVL3->CorrectAnswer==2 )
 {
   
    EnigmeLVL3->pos_Checks_ecran.y=355;
    SDL_BlitSurface(EnigmeLVL3->RightCheck, NULL, screen,  &EnigmeLVL3->pos_Checks_ecran);
    for (int i=0;i<2;i++)
    {
      
      EnigmeLVL3->pos_Checks_ecran.y=248+(214*i);
      SDL_BlitSurface(EnigmeLVL3->WrongCheck, NULL, screen, &EnigmeLVL3->pos_Checks_ecran);
   
    }
  }
else if (EnigmeLVL3->CorrectAnswer==3 )
{
    EnigmeLVL3->pos_Checks_ecran.y=462;
    SDL_BlitSurface(EnigmeLVL3->RightCheck, NULL, screen,  &EnigmeLVL3->pos_Checks_ecran);
    for (int i=0;i<2;i++)
    {
      
      EnigmeLVL3->pos_Checks_ecran.y=248+(107*i);
      SDL_BlitSurface(EnigmeLVL3->WrongCheck, NULL, screen, &EnigmeLVL3->pos_Checks_ecran);
   }
}
if (EnigmeLVL3->CorrectAnswer==EnigmeLVL3->click)
{
EnigmeLVL3->Win=1;

}
 
Boss3->Enigme=2;
}

    
}




void Scorelvl3Calculations(EnigmeJapan *EnigmeLVL3,Perso *perso)
{
if (EnigmeLVL3->ScoreLVL3.IsShown==0)
{
int Time,Score;

Time=SDL_GetTicks()/1000;
Score=(8000+(perso->CoinsSecured*200)+(perso->EnnemiesKilled*500))-(Time*2);
sprintf(EnigmeLVL3->ScoreLVL3.Time,"%d",Time);
sprintf(EnigmeLVL3->ScoreLVL3.CoinsSecured,"%d",perso->CoinsSecured);
sprintf(EnigmeLVL3->ScoreLVL3.EnnemiesKilled,"%d",perso->EnnemiesKilled);
sprintf(EnigmeLVL3->ScoreLVL3.FinalScore,"%d",Score);

EnigmeLVL3->ScoreLVL3.IsShown++;
}

}  



void afficher_BackgroundJapanscore(SDL_Surface *screen,EnigmeJapan *EnigmeLVL3,EnigmeRussia *EnigmeLVL1)
{

if (EnigmeLVL3->Win==1)
{
SDL_BlitSurface(EnigmeLVL3->ScoreLVL3.AdvanceBackground,NULL,screen,&EnigmeLVL3->pos_background_ecran);
SDL_BlitSurface(EnigmeLVL3->ScoreLVL3.Next,NULL,screen,&EnigmeLVL3->ScoreLVL3.pos_ButtonNext_ecran);

}
else
{
SDL_BlitSurface(EnigmeLVL3->ScoreLVL3.LoseBackground,NULL,screen,&EnigmeLVL3->pos_background_ecran);
SDL_BlitSurface(EnigmeLVL3->ScoreLVL3.Retry,NULL,screen,&EnigmeLVL3->ScoreLVL3.pos_ButtonRetry_ecran);
} 

EnigmeLVL3->ScoreLVL3.SurfaceCoinsSecured=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL3->ScoreLVL3.CoinsSecured,EnigmeLVL3->ScoreLVL3.color_score);
SDL_BlitSurface(EnigmeLVL3->ScoreLVL3.SurfaceCoinsSecured,NULL,screen,&EnigmeLVL3->ScoreLVL3.pos_SurfaceCoins_ecran);
EnigmeLVL3->ScoreLVL3.SurfaceEnnemiesKilled=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL3->ScoreLVL3.EnnemiesKilled,EnigmeLVL3->ScoreLVL3.color_score);
SDL_BlitSurface(EnigmeLVL3->ScoreLVL3.SurfaceEnnemiesKilled,NULL,screen,&EnigmeLVL3->ScoreLVL3.pos_SurfaceEnnemies_ecran);
EnigmeLVL3->ScoreLVL3.SurfaceTime=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL3->ScoreLVL3.Time,EnigmeLVL3->ScoreLVL3.color_score);
SDL_BlitSurface(EnigmeLVL3->ScoreLVL3.SurfaceTime,NULL,screen,&EnigmeLVL3->ScoreLVL3.pos_SurfaceTime_ecran);
EnigmeLVL3->ScoreLVL3.SurfaceFinalScore=TTF_RenderText_Blended(EnigmeLVL1->ScoreLVL1.score_police,EnigmeLVL3->ScoreLVL3.FinalScore,EnigmeLVL3->ScoreLVL3.color_score);
SDL_BlitSurface(EnigmeLVL3->ScoreLVL3.SurfaceFinalScore,NULL,screen,&EnigmeLVL3->ScoreLVL3.pos_SurfaceFinalScore_ecran);


}
        


void Click_AfterAnsweringJapan(SDL_Event event,int *GameState,EnigmeJapan *EnigmeLVL3,BossRoomJapan *Boss3,int *Reinitialisation_lvl3,int *MusicGame)
{

if (Boss3->Enigme==3 &&  EnigmeLVL3->Win==1)
{
   if ((event.button.x>=620 && event.button.x<=620+EnigmeLVL3->ScoreLVL3.Next->w) && (event.button.y>=440 && event.button.y<=440+EnigmeLVL3->ScoreLVL3.Next->h))
  {
     *MusicGame=0;
     *GameState=8;
    
  }
   

}
else if (Boss3->Enigme==3 &&  EnigmeLVL3->Win==0)
{


   if ((event.button.x>=620 && event.button.x<=620+EnigmeLVL3->ScoreLVL3.Retry->w) && (event.button.y>=440 && event.button.y<=440+EnigmeLVL3->ScoreLVL3.Retry->h))
 
 {
     *MusicGame=0;
     *GameState=6;
     *Reinitialisation_lvl3=0;
  }
  


} 

 
}







void Free_EnigmeJapan(EnigmeJapan *EnigmeLVL3)
{
SDL_FreeSurface(EnigmeLVL3->EnigmeJapanBackground);
SDL_FreeSurface(EnigmeLVL3->boxes);
SDL_FreeSurface(EnigmeLVL3->RightCheck);
SDL_FreeSurface(EnigmeLVL3->WrongCheck);
SDL_FreeSurface(EnigmeLVL3->QuestionSurface);
SDL_FreeSurface(EnigmeLVL3->AnswerSurface1);
SDL_FreeSurface(EnigmeLVL3->AnswerSurface2);
SDL_FreeSurface(EnigmeLVL3->AnswerSurface3);
SDL_FreeSurface(EnigmeLVL3->TimerSurface);  
SDL_FreeSurface(EnigmeLVL3->ScoreLVL3.LoseBackground);
SDL_FreeSurface(EnigmeLVL3->ScoreLVL3.AdvanceBackground);
SDL_FreeSurface(EnigmeLVL3->ScoreLVL3.Next);
SDL_FreeSurface(EnigmeLVL3->ScoreLVL3.Retry);
//TTF_CloseFont(EnigmeLVL1->ScoreLVL1.score_police);
SDL_FreeSurface(EnigmeLVL3->ScoreLVL3.SurfaceCoinsSecured);
SDL_FreeSurface(EnigmeLVL3->ScoreLVL3.SurfaceEnnemiesKilled);
SDL_FreeSurface(EnigmeLVL3->ScoreLVL3.SurfaceTime); 
SDL_FreeSurface(EnigmeLVL3->ScoreLVL3.SurfaceFinalScore);


free(EnigmeLVL3);









}
