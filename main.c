#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
     
              
int main()    
{  
SDL_Surface *screen; 
 SDL_Event event;
int boucle=1,GameState=0,GameScreenLoaded=0,MenuScreenLoaded=0,currentTime=0,lastTime=0,MenuFreed=0,Reinitialisation_trailer=1,Reinitialisation_lvl1=1,Continue_lvl1=1,Reinitialisation_lvl2=1,Continue_lvl2=1,Reinitialisation_lvl3=1,Continue_lvl3=1,MusicMenu=0,MusicGame=0;
float deltaTime=0;
const Uint8* keys = SDL_GetKeyState(NULL);
menu *Menu=malloc(sizeof(menu)); 
Russia *Rousia=malloc(sizeof(Russia));
Perso *Ahmed=malloc(sizeof(Perso));
IceMob *Mob=malloc(sizeof(IceMob));
Hunter *chasseur=malloc(sizeof(Hunter));
BossRoomRussia *WitchBoss=malloc(sizeof(BossRoomRussia));
EnigmeRussia *Enigmelvl1=malloc(sizeof(EnigmeRussia));
Save_Quit *Save=malloc(sizeof(Save_Quit));
Egypt *Masr=malloc(sizeof(Egypt)); 
Anubis *Nasus=malloc(sizeof(Anubis));
Fly *Khazix=malloc(sizeof(Fly));
TicTacToe *XO=malloc(sizeof(TicTacToe));
BossRoomEgypt *EgyptBoss=malloc(sizeof(BossRoomEgypt));
EnigmeEgypt *Enigmelvl2=malloc(sizeof(EnigmeEgypt));
Japan *Kouria=malloc(sizeof(Japan));
Youkai *Twitch=malloc(sizeof(Youkai));
Fox *Ahri=malloc(sizeof(Fox));
BossRoomJapan *JapanBoss=malloc(sizeof(BossRoomJapan));
EnigmeJapan *Enigmelvl3=malloc(sizeof(EnigmeJapan));
BossRoomSpace *SpaceBoss=malloc(sizeof(BossRoomSpace));
EndScreen *end=malloc(sizeof(EndScreen));
Trailer *Bideya=malloc(sizeof(Trailer));
TTF_Init();
 Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
initialiser_Menu(Menu);
initialiser_lvl1(Rousia);
initialiser_Personnage(Ahmed);
initialiser_IceMob(Mob); 
initialiser_Hunter(chasseur);
initialiser_BossRoomRussia(WitchBoss);
initialiser_EnigmeRussia(Enigmelvl1);
initialiser_Save_Quit(Save);
initialiser_lvl2(Masr);
initialiser_Anubis(Nasus);
initialiser_Fly(Khazix);
initialiser_TicTacToe(XO);
initialiser_BossRoomEgypt(EgyptBoss);
initialiser_EnigmeEgypt(Enigmelvl2);
initialiser_lvl3(Kouria);
initialiser_Youkai(Twitch);
initialiser_Fox(Ahri);
initialiser_BossRoomJapan(JapanBoss);
initialiser_EnigmeJapan(Enigmelvl3);
initialiser_BossRoomSpace(SpaceBoss);
initialiser_EndScreen(end);
initialiser_Trailer(Bideya);
load_RandomFact(Menu);
if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
 printf("could not initialize SDL : %s. \n", SDL_GetError());
 return -1;
}
screen=SDL_SetVideoMode(1433,779,32,SDL_SWSURFACE|SDL_DOUBLEBUF);

while(boucle)
{ 
 
//Calculating Time Per Frame
currentTime = SDL_GetTicks();
deltaTime = (currentTime - lastTime);
lastTime = currentTime;
printf("%f\n",deltaTime);
printf("aa %d\n",Masr->Map2->format->BitsPerPixel);


switch(GameState)
{ 
 
 

case 0:
  {
if (MenuScreenLoaded==0)
{
screen=SDL_SetVideoMode(1433,779,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
MenuScreenLoaded=1;
 
} 
if (MusicMenu==0)
{
Mix_HaltMusic();
 Mix_PlayMusic(Menu->music,-1);
 Mix_VolumeMusic(MIX_MAX_VOLUME/3);
MusicMenu=1;

}

if (XO->IsTicTacToeClicked==0)
{

afficher_menu(screen,Menu);
afficher_TicTacToeIcon(screen,XO);
}
else
{
afficher_TicTacToeBackground(screen,XO);
affichage_PlayerXO(screen,XO); 
printwinner(screen,XO); 
ComputerMove(XO);
affichage_ComputerXO(screen,XO);


}
while(SDL_PollEvent(&event))
{
 
   
 switch(event.type)
 {
  case (SDL_QUIT):
   {
     boucle=0;
     break; 
   } 
   case (SDL_MOUSEBUTTONDOWN):
    {
         MusicSliderControl(Menu,event);
	 SoundFXSliderControl(Menu,event);
         PressControlAllButtons(event,Menu,&boucle,&GameState,&MenuScreenLoaded,&GameScreenLoaded,&Reinitialisation_lvl1,&Continue_lvl1,&Continue_lvl2,&Continue_lvl3,&MusicMenu,&MusicGame,&Reinitialisation_trailer);
        ClickTicTacToeIcon(event,XO);
        playerXOMove(event,XO);
	  break;
	  
    } 
   case (SDL_MOUSEMOTION):
   {
     SonBrefControlAllButtons(event,Menu);
     break;
   }
  case (SDL_KEYDOWN):
  {  
   KeyboardHandling(event , Menu,&boucle,&GameState,&MenuScreenLoaded,&GameScreenLoaded,&Reinitialisation_lvl1,&Continue_lvl1,&Continue_lvl2,&Continue_lvl3,&MusicMenu,&MusicGame);
     LeaveTicTacToe(event ,XO);
     break;
   }  
 }
}
break;
} 






case 10:
{


if (GameScreenLoaded==0)
{
screen=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
GameScreenLoaded=1;
}

if (Reinitialisation_trailer==0)
{
reinitialiser_Trailer(Bideya);
Reinitialisation_trailer=1;

}

if (MusicGame==0)
{
Mix_HaltMusic();
 Mix_PlayMusic(Bideya->music,-1);
 Mix_VolumeMusic(MIX_MAX_VOLUME/3);
MusicGame=1;
}

if (Bideya->StartAnimation==0)
{
afficher_Trailer(screen,Bideya,Ahmed);
}
else
{

afficher_AnimationTrailer(screen,Bideya,&GameState,&MusicGame,&Reinitialisation_lvl1);

}
 
 



while(SDL_PollEvent(&event))
{
 
  
 switch(event.type)
 {
  case (SDL_QUIT):
   {
     boucle=0;
     break; 
   } 
   case(SDL_KEYDOWN) :
    {
     if (event.key.keysym.sym==SDLK_SPACE)
        {
         Bideya->DialogueShown++;
         }
      break;
    }


   
  }
}



break;
}
    
    
case 1:
{
/*if (MenuFreed==0)
{
FreeMenu(Menu); 
MenuFreed=1; 
 
}*/ 
if (GameScreenLoaded==0)
{
screen=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
GameScreenLoaded=1;

}

if (Reinitialisation_lvl1==0)
{  
   reinizialitation_lvl1(Ahmed,Rousia,Enigmelvl1,WitchBoss,chasseur,Mob);
   Reinitialisation_lvl1=1;
}
if (Continue_lvl1==0)
{  
   ContinueGameRussia(Ahmed,Rousia,Enigmelvl1,WitchBoss,chasseur,Mob,&GameState);
   Continue_lvl1=1;
}
if (MusicGame==0)
{
Mix_HaltMusic();
 Mix_PlayMusic(Rousia->music,-1);
 Mix_VolumeMusic(MIX_MAX_VOLUME/3);
MusicGame=1;

}

if (Rousia->IsSaveMenuClicked==0)
{
afficher_lvl1(screen,Rousia,Ahmed); 
afficher_SaveMenuIcon(screen,Save);
afficher_PersoMap(screen,Ahmed);
afficher_IceMob(screen,Mob , Rousia,Ahmed);
afficher_Hunter(screen,chasseur , Rousia,Ahmed);
scrollingRussia(Rousia , Ahmed,deltaTime,keys);
PersoMouvementControlRussia(Rousia,Ahmed,deltaTime,keys);
PersoCollisionControlRussia(Rousia,Ahmed);
FallOutsideMapRussia(Ahmed,Rousia);
GameOver(screen,Ahmed);
}
else
{
afficher_SaveMenuBackground(screen,Save);
}
if (Ahmed->pos_perso_ecran.x>=650)
{
 MusicGame=0;
 GameState=2;
}
while(SDL_PollEvent(&event))
{
  
  
 switch(event.type)
 {
  case (SDL_QUIT):
   {
     boucle=0;
     break; 
   } 
  case(SDL_KEYDOWN) :
  {
   

  if ((event.key.keysym.sym==SDLK_UP && Ahmed->jump==0) )
    {

      initialize_Jump(Ahmed);
    } 
   LeaveSaveMenuRussiaIcon(event,Rousia);
     
  break;
 
  }
   case(SDL_MOUSEBUTTONDOWN):
        {
     if (event.button.button == SDL_BUTTON_LEFT) 
         { 
            ClickWhileGameOverRussia(event,Ahmed,&GameState,&Reinitialisation_lvl1);
           ClickSaveMenuRussiaIcon(event,Rousia,Save);
  ClickToSaveOrQuitMenuRussia(event,Save,&GameState,Ahmed,Rousia,Enigmelvl1,WitchBoss,chasseur,Mob);
           
          }
         break;
         }
      
       }
    } 

break;
 
}
 
case 2: 
   {  
   
  
   if (MusicGame==0)
   {
     Mix_HaltMusic();
     Mix_PlayMusic(WitchBoss->music,-1);
      Mix_VolumeMusic(MIX_MAX_VOLUME/3);
      MusicGame=1;
    }

   switch (WitchBoss->Enigme)
  {
     case 0:
   {
    afficher_BossRoomRussia(screen, WitchBoss,Ahmed);
    break;
   }
    case 1:
      {
       calculate_TimeEnigmeRussia(Enigmelvl1);
       afficher_EnigmeRussia(screen,Enigmelvl1,WitchBoss);
       Correct_answer(screen,Enigmelvl1,WitchBoss); 
       break;
       }
    case 2: 
       { 
     SDL_Delay(1500);
      WitchBoss->Enigme=3;
      break;


       }
     case 3:  
       {
         Scorelvl1Calculations(Enigmelvl1,Ahmed);
         afficher_Backgroundscore(screen,Enigmelvl1);
         break;
       }
    }
       while(SDL_PollEvent(&event))
        {
          switch(event.type)
       {
           case (SDL_QUIT):
       {
         boucle=0;
         break; 
        } 

     case(SDL_KEYDOWN) :
       {
        if (event.key.keysym.sym==SDLK_SPACE)
            {
              WitchBoss->DialogueShown++;
            }
          break;
       }
     case(SDL_MOUSEBUTTONDOWN):
        {
     if (event.button.button == SDL_BUTTON_LEFT) 
         { 
            Click_answer(event, Enigmelvl1);
            Click_AfterAnsweringRussia(event,&GameState,Enigmelvl1,WitchBoss,&Reinitialisation_lvl1,&Reinitialisation_lvl2,&MusicGame);
         
          } 

 
         break;
         }
        }
        }
    break;
   }
 
  case 4:
     {
    if (GameScreenLoaded==0)
       {
    screen=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
     GameScreenLoaded=1;

       }
    if (Reinitialisation_lvl2==0)
     {
        reinizialitation_lvl2(Ahmed,Masr,Enigmelvl2,EgyptBoss,Khazix,Nasus);
        Reinitialisation_lvl2=1;
   
     }
   if (Continue_lvl2==0)
    {
      ContinueGameEgypt(Ahmed,Masr,&GameState);
        Continue_lvl2=1;
     }


   if (MusicGame==0)
   {
     Mix_HaltMusic();
     Mix_PlayMusic(Masr->music,-1);
      Mix_VolumeMusic(MIX_MAX_VOLUME/3);
      MusicGame=1;
    }
   if (Masr->IsSaveMenuClicked==0)
 {
   afficher_lvl2(screen,Masr,Rousia,Ahmed);
   afficher_SaveMenuIcon(screen,Save);
   afficher_PersoMap(screen,Ahmed);
   afficher_Anubis(screen,Nasus,Masr,Ahmed);
   afficher_Fly(screen,Khazix,Masr,Ahmed);
   scrollingEgypt(Masr,Ahmed,deltaTime,keys);
   PersoMouvementControlEgypt(Masr,Ahmed,deltaTime,keys);
   PersoCollisionControlEgypt(Masr,Rousia,Ahmed);
   FallOutsideMapEgypt(Ahmed,Masr);
   GameOver(screen,Ahmed);
}
else
{
  afficher_SaveMenuBackground(screen,Save);
}
if (Ahmed->pos_perso_ecran.x>=760)
{
 MusicGame=0;
 GameState=5;
}


 


    
  

     while(SDL_PollEvent(&event))
       {
 
  
     switch(event.type)
         {
        case (SDL_QUIT):
             {
       boucle=0;
       break; 
       
             }  
     
       case(SDL_KEYDOWN) :
           {

          if ((event.key.keysym.sym==SDLK_UP && Ahmed->jump==0) )
               {
                 initialize_Jump(Ahmed);
                } 
           LeaveSaveMenuEgyptIcon(event ,Masr);
     
                break;
 
             }
      
        case(SDL_MOUSEBUTTONDOWN):
        {
         if (event.button.button == SDL_BUTTON_LEFT) 
         { 
              ClickWhileGameOverEgypt(event,Ahmed,&GameState,&Reinitialisation_lvl2);
              ClickSaveMenuEgyptIcon(event,Masr,Save);
             ClickToSaveOrQuitMenuEgypt(event,Save,&GameState,Ahmed,Masr);
           
          }
         break;
         }

               }
             }
 


 
 
      break;
     }
  case 5:
   {

   if (MusicGame==0)
   {
     Mix_HaltMusic();
     Mix_PlayMusic(EgyptBoss->music,-1);
      Mix_VolumeMusic(MIX_MAX_VOLUME/3);
      MusicGame=1;
    }

   switch (EgyptBoss->Enigme)
 {
 case 0:
 {
   afficher_BossRoomEgypt(screen,EgyptBoss,Ahmed);
   break;
 } 
 
 case 1:
  {
     calculate_TimeEnigmeEgypt(Enigmelvl2);
     afficher_EnigmeEgypt(screen,Enigmelvl2,Enigmelvl1,EgyptBoss);
     Correct_answerEgypt(screen,Enigmelvl2,EgyptBoss);
    break;
   }
  case 2: 
       { 
     SDL_Delay(1500);
      EgyptBoss->Enigme=3;
      break;

       }
  case 3:
      {
     Scorelvl2Calculations(Enigmelvl2,Ahmed);
     afficher_BackgroundEgyptscore(screen,Enigmelvl2,Enigmelvl1);


       break;
      }
  




  

  }



  while(SDL_PollEvent(&event))
       {
 
  
     switch(event.type)
         {
        case (SDL_QUIT):
             {
       boucle=0;
       break; 
             }
         case(SDL_KEYDOWN) :
         {
        if (event.key.keysym.sym==SDLK_SPACE)
            {
              EgyptBoss->DialogueShown++;
            }
          break;
          }
        case(SDL_MOUSEBUTTONDOWN):
        {
         if (event.button.button == SDL_BUTTON_LEFT) 
         { 
            Click_answerEgypt(event, Enigmelvl2);
                Click_AfterAnsweringEgypt(event,&GameState,Enigmelvl2,EgyptBoss,&Reinitialisation_lvl2,&Reinitialisation_lvl3,&MusicGame);
          }
           break;
         }

 
          }
        }


 


   break;




   }
    
  case 6:
    {
   if (GameScreenLoaded==0)
       {
    screen=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
     GameScreenLoaded=1;

       }
   if (Reinitialisation_lvl3==0)
     {
   reinizialitation_lvl3(Ahmed,Kouria,Enigmelvl3,JapanBoss,Ahri,Twitch);
        Reinitialisation_lvl3=1;
   
     }

    if (Continue_lvl3==0)
    {
    ContinueGameJapan(Ahmed,Kouria,&GameState); 
        Continue_lvl3=1;
     }
    if (MusicGame==0)
   {
     Mix_HaltMusic();
     Mix_PlayMusic(Kouria->music,-1);
      Mix_VolumeMusic(MIX_MAX_VOLUME/3);
      MusicGame=1;
    }
  if (Kouria->IsSaveMenuClicked==0)
 {
  afficher_lvl3(screen,Kouria,Rousia,Ahmed);
  afficher_SaveMenuIcon(screen,Save);
  afficher_PersoMap(screen,Ahmed);
  afficher_Youkai(screen,Twitch,Kouria,Ahmed);
  afficher_Fox(screen,Ahri,Kouria,Ahmed); 
  scrollingJapan(Kouria,Ahmed,deltaTime,keys);
  PersoMouvementControlJapan(Kouria,Ahmed,deltaTime,keys);
  PersoCollisionControlJapan(Kouria,Rousia,Ahmed);
  FallOutsideMapJapan(Ahmed,Kouria);
     GameOver(screen,Ahmed);
  }
else
 {

 afficher_SaveMenuBackground(screen,Save);

  }

if (Ahmed->pos_perso_ecran.x>=910)
{
 MusicGame=0;
 GameState=7;
}


 







    while(SDL_PollEvent(&event))
       {
 
  
     switch(event.type)
         {
        case (SDL_QUIT):
             {
       boucle=0;
       break; 
             }
       case(SDL_KEYDOWN) :
           {

          if ((event.key.keysym.sym==SDLK_UP && Ahmed->jump==0) )
               {
                 initialize_Jump(Ahmed);
                }          
            LeaveSaveMenuJapanIcon(event ,Kouria);
             break;
 
          }
        case(SDL_MOUSEBUTTONDOWN):
        {
         if (event.button.button == SDL_BUTTON_LEFT) 
         { 
              ClickWhileGameOverJapan(event,Ahmed,&GameState,&Reinitialisation_lvl3);
              ClickSaveMenuJapanIcon(event,Kouria,Save);
              ClickToSaveOrQuitMenuJapan(event,Save,&GameState,Ahmed,Kouria); 
           
          }
         break;
         }


 
         }
   
       }


 
    break;

    }
 

 case 7:
    { 

   if (MusicGame==0)
   {
     Mix_HaltMusic();
     Mix_PlayMusic(JapanBoss->music,-1);
      Mix_VolumeMusic(MIX_MAX_VOLUME/3);
      MusicGame=1;
    }
   switch (JapanBoss->Enigme)
   {
    case 0:
   {

     afficher_BossRoomJapan(screen, JapanBoss,Ahmed);
      break;
   }
    case 1:
    {
       calculate_TimeEnigmeJapan(Enigmelvl3);
       afficher_EnigmeJapan(screen,Enigmelvl3,Enigmelvl1,JapanBoss);
       Correct_answerJapan(screen,Enigmelvl3,JapanBoss);

       break;
    }
    case 2: 
       { 
     SDL_Delay(1500);
      JapanBoss->Enigme=3;
      break;

       }
    case 3:
      {
      Scorelvl3Calculations(Enigmelvl3,Ahmed);
      afficher_BackgroundJapanscore(screen,Enigmelvl3,Enigmelvl1);
 

       break;
      }




  }

    




    while(SDL_PollEvent(&event))
       {
 
  
     switch(event.type)
         {
        case (SDL_QUIT):
             {
       boucle=0;
       break; 
             }
    
         case(SDL_KEYDOWN) :
         {
        if (event.key.keysym.sym==SDLK_SPACE)
            {
              JapanBoss->DialogueShown++;
            }
          break;
          }
  
         case(SDL_MOUSEBUTTONDOWN):
        {
         if (event.button.button == SDL_BUTTON_LEFT) 
         { 
            Click_answerJapan(event, Enigmelvl3);
    Click_AfterAnsweringJapan(event,&GameState,Enigmelvl3,JapanBoss,&Reinitialisation_lvl3,&MusicGame);
          }
           break;
         }



         
          }

       }

 
 
     break;
     }

  case 8:
    {

    if (MusicGame==0)
   {
     Mix_HaltMusic();
     Mix_PlayMusic(SpaceBoss->music,-1);
      Mix_VolumeMusic(MIX_MAX_VOLUME/3);
      MusicGame=1;
    }
    afficher_BossRoomSpace(screen, SpaceBoss,Ahmed,&GameState,&MusicGame);



while(SDL_PollEvent(&event))
       {
 
  
     switch(event.type)
         {
        case (SDL_QUIT):
             {
       boucle=0;
       break; 
             }
    
         case(SDL_KEYDOWN) :
         {
        if (event.key.keysym.sym==SDLK_SPACE)
            {
              SpaceBoss->DialogueShown++;
            }
          break;
          }
         

        }
       
         }




   

    

   break;
    }



 

  case 9:
    {

  if (MusicGame==0)
   {
     Mix_HaltMusic();
     Mix_PlayMusic(end->music,-1);
      Mix_VolumeMusic(MIX_MAX_VOLUME/3);
      MusicGame=1;
    }

    afficher_EndScreen(screen,end);
  

     while(SDL_PollEvent(&event))
       {
 
  
     switch(event.type)
         {
        case (SDL_QUIT):
             {
       boucle=0;
       break; 
             }

         case(SDL_MOUSEBUTTONDOWN):
        {
         if (event.button.button == SDL_BUTTON_LEFT) 
         { 
            ClickToQuitEndScreen(event,end,&GameState);
           
          }
         break;
         }



   
          }
       }


     

     break;
    }


 
   



}








SDL_Delay(4);
SDL_Flip(screen);

}
if (MenuFreed==0)
{

FreeMenu(Menu);
}
free_lvl1(Rousia); 
free_Perso(Ahmed);
free_IceMob(Mob);
free_Hunter(chasseur);
freeBossRoomRussia(WitchBoss);
Free_EnigmeRussia(Enigmelvl1);
free_Save_Quit(Save);
free_lvl2(Masr);
free_Anubis(Nasus);
free_Fly(Khazix);
free_TicTacToe(XO);
freeBossRoomEgypt(EgyptBoss); 
Free_EnigmeEgypt(Enigmelvl2);
free_lvl3(Kouria);
free_Youkai(Twitch);
free_Fox(Ahri); 
freeBossRoomJapan(JapanBoss);
Free_EnigmeJapan(Enigmelvl3);
freeBossRoomSpace(SpaceBoss);
freeEndScreen(end); 
freeTrailer(Bideya);
SDL_Quit(); 
return 0;

  

 
 

 
















}
