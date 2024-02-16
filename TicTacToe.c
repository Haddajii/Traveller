#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

                                  

  
void initialiser_TicTacToe(TicTacToe *tictactoe)
{
 
tictactoe->Menu=IMG_Load("./TicTacToe/xo.png");
tictactoe->MenuSelected=IMG_Load("./TicTacToe/xoSelected.png");
tictactoe->pos_Menu_ecran.x=1350;
tictactoe->pos_Menu_ecran.y=2;
tictactoe->pos_Menu_ecran.w=0;
tictactoe->pos_Menu_ecran.h=0;
tictactoe->Background=IMG_Load("./TicTacToe/xoBackground.png");
tictactoe->pos_Background_ecran.x=800;
tictactoe->pos_Background_ecran.y=80;
tictactoe->pos_Background_ecran.w=0;
tictactoe->pos_Background_ecran.h=0;
tictactoe->BackgroundBox=IMG_Load("./TicTacToe/xoBackgroundBox.png");  
tictactoe->pos_BackgroundBox_ecran.x=787;
tictactoe->pos_BackgroundBox_ecran.y=66;
tictactoe->pos_BackgroundBox_ecran.w=0;
tictactoe->pos_BackgroundBox_ecran.h=0;
tictactoe->BackgroundWinLose=IMG_Load("./TicTacToe/xoBackgroundWinLose.png");
tictactoe->pos_BackgroundWinLose_ecran.x=880;
tictactoe->pos_BackgroundWinLose_ecran.y=4;
tictactoe->pos_BackgroundWinLose_ecran.w=0;
tictactoe->pos_BackgroundWinLose_ecran.h=0;
tictactoe->X=IMG_Load("./TicTacToe/X.png");
tictactoe->pos_X_ecran.x=0;
tictactoe->pos_X_ecran.y=0;
tictactoe->pos_X_ecran.w=0;
tictactoe->pos_X_ecran.h=0;
tictactoe->O=IMG_Load("./TicTacToe/O.png");
tictactoe->pos_O_ecran.x=0;
tictactoe->pos_O_ecran.y=0;
tictactoe->pos_O_ecran.w=0;
tictactoe->pos_O_ecran.h=0; 
tictactoe->Win_txt=NULL;
tictactoe->pos_Win_ecran.x=925;
tictactoe->pos_Win_ecran.y=24;
tictactoe->pos_Win_ecran.w=0;
tictactoe->pos_Win_ecran.h=0;  
tictactoe->Lose_txt=NULL;
tictactoe->pos_Lose_ecran.x=916;
tictactoe->pos_Lose_ecran.y=24;
tictactoe->pos_Lose_ecran.w=0;
tictactoe->pos_Lose_ecran.h=0;
tictactoe->Draw_txt=NULL;
tictactoe->pos_Draw_ecran.x=980; 
tictactoe->pos_Draw_ecran.y=24;
tictactoe->pos_Draw_ecran.w=0;
tictactoe->pos_Draw_ecran.h=0;
tictactoe->txt_police=TTF_OpenFont("./lvl1Enigme/GravityRegular5.ttf",22); 
tictactoe->txt_color.r=160;
tictactoe->txt_color.g=0;
tictactoe->txt_color.b=0;  
for(int i=0;i<3;i++)
{
 for(int j=0;j<3;j++)
   {
    tictactoe->board[i][j]=' ';
   }   
} 
tictactoe->winner=' ';
tictactoe->IsTicTacToeClicked=0;
tictactoe->PlayerHasMoved=0;
tictactoe->FreeSpaces=9;




}




void afficher_TicTacToeIcon(SDL_Surface *screen,TicTacToe *tictactoe)
{
int x,y ;
 SDL_GetMouseState(&x , &y);
SDL_BlitSurface(tictactoe->Menu, NULL, screen,  &tictactoe->pos_Menu_ecran);



if ((y>=2 && y<=2+tictactoe->Menu->h)&&(x>=1350 && x<=1350+tictactoe->Menu->w))
{
SDL_BlitSurface(tictactoe->MenuSelected,NULL,screen,&tictactoe->pos_Menu_ecran);

}

}
 


void ClickTicTacToeIcon(SDL_Event event,TicTacToe *tictactoe)
{
if (event.button.button==SDL_BUTTON_LEFT)
{
if (tictactoe->IsTicTacToeClicked==0)
{

if ((event.button.x>=1350 && event.button.x<=1350+tictactoe->Menu->w) && (event.button.y>=2 && event.button.y<=2+tictactoe->Menu->h))
  {
     tictactoe->IsTicTacToeClicked=1;
  }

}
}

}


void LeaveTicTacToe(SDL_Event event ,TicTacToe *tictactoe)
{
if (event.key.keysym.sym==SDLK_ESCAPE && tictactoe->IsTicTacToeClicked==1)
{

  tictactoe->IsTicTacToeClicked=0;
}

}

 
 
void afficher_TicTacToeBackground(SDL_Surface *screen,TicTacToe *tictactoe)
{

 SDL_BlitSurface(tictactoe->Background, NULL, screen,  &tictactoe->pos_Background_ecran);
SDL_BlitSurface(tictactoe->BackgroundBox, NULL, screen,  &tictactoe->pos_BackgroundBox_ecran);
SDL_BlitSurface(tictactoe->BackgroundWinLose, NULL, screen,  &tictactoe->pos_BackgroundWinLose_ecran);

}



int CheckFreeSpaces(TicTacToe *tictactoe)
{   int freeSpaces=9;
      for(int i=0;i<3;i++)
     {
      for(int j=0;j<3;j++)
         {
            if (tictactoe->board[i][j]!=' ')
              {

                 freeSpaces=freeSpaces-1;

              }
         }    
     
     } 
      
 return(freeSpaces);
}





void playerXOMove(SDL_Event event,TicTacToe *tictactoe)
{

  if (tictactoe->IsTicTacToeClicked==1 && tictactoe->winner==' ')
{
if (event.button.button==SDL_BUTTON_LEFT)
{
   if((event.button.y>=80 && event.button.y<=80+Square) && (event.button.x>=800 && event.button.x<=800+Square) && tictactoe->board[0][0]==' ')
{
   tictactoe->PlayerHasMoved=1;
   tictactoe->board[0][0]='X';
}
   if((event.button.y>=80 && event.button.y<=80+Square) && (event.button.x>=800+Square && event.button.x<=800+(Square*2)) && tictactoe->board[0][1]==' ')
{
   tictactoe->PlayerHasMoved=1;
   tictactoe->board[0][1]='X';
}
   if((event.button.y>=80 && event.button.y<=80+Square) && (event.button.x>=800+(Square*2) && event.button.x<=800+(Square*3)) && tictactoe->board[0][2]==' ')
{
   tictactoe->PlayerHasMoved=1;
   tictactoe->board[0][2]='X';
}
   if((event.button.y>=80+Square && event.button.y<=80+(Square*2)) && (event.button.x>=800 && event.button.x<=800+Square) && tictactoe->board[1][0]==' ')
{
   tictactoe->PlayerHasMoved=1;
   tictactoe->board[1][0]='X';
}
   if((event.button.y>=80+Square && event.button.y<=80+(Square*2)) && (event.button.x>=800+Square && event.button.x<=800+(Square*2)) && tictactoe->board[1][1]==' ')
{
   tictactoe->PlayerHasMoved=1;
   tictactoe->board[1][1]='X';
}
   if((event.button.y>=80+Square && event.button.y<=80+(Square*2)) && (event.button.x>=800+(Square*2) && event.button.x<=800+(Square*3)) && tictactoe->board[1][2]==' ')
{
   tictactoe->PlayerHasMoved=1;
   tictactoe->board[1][2]='X';
}
   if((event.button.y>=80+(Square*2) && event.button.y<=80+(Square*3)) && (event.button.x>=800 && event.button.x<=800+Square) && tictactoe->board[2][0]==' ')
{
   tictactoe->PlayerHasMoved=1;
   tictactoe->board[2][0]='X';
}
if((event.button.y>=80+(Square*2) && event.button.y<=80+(Square*3)) && (event.button.x>=800+Square && event.button.x<=800+(Square*2)) && tictactoe->board[2][1]==' ')
{
   tictactoe->PlayerHasMoved=1;
   tictactoe->board[2][1]='X';
}
if((event.button.y>=80+(Square*2) && event.button.y<=80+(Square*3)) && (event.button.x>=800+(Square*2) && event.button.x<=800+(Square*3)) && tictactoe->board[2][2]==' ')
{
   tictactoe->PlayerHasMoved=1;
   tictactoe->board[2][2]='X';
}
}
}

}

 

void affichage_PlayerXO(SDL_Surface *screen,TicTacToe *tictactoe)
{
    for(int i=0;i<3;i++)
     {
      for(int j=0;j<3;j++)
        {
      SDL_Rect rect={800+(Square*j)+36,80+(Square*i)+36,0,0};
        if (tictactoe->board[i][j]=='X')
         {
            SDL_BlitSurface(tictactoe->X,NULL,screen,&rect);

         } 
       }
     }
}


void ComputerMove(TicTacToe *tictactoe)
{

if (tictactoe->winner==' ' && CheckFreeSpaces(tictactoe)!=0 && tictactoe->PlayerHasMoved==1)
{

 srand(time(0));
  int x,y;

 
  do
    { 
       x=rand()%3;
       y=rand()%3;
     }
   while(tictactoe->board[x][y]!=' ');
  
 
   
   tictactoe->board[x][y]='O';
    tictactoe->PlayerHasMoved=0;
}
 


}


void affichage_ComputerXO(SDL_Surface *screen,TicTacToe *tictactoe)
{
    for(int i=0;i<3;i++)
     {
      for(int j=0;j<3;j++)
        {
      SDL_Rect rect={800+(Square*j)+36,80+(Square*i)+36,0,0};
        if (tictactoe->board[i][j]=='O')
         {
            SDL_BlitSurface(tictactoe->O,NULL,screen,&rect);

         } 
       }
     }
} 




void checkWinner(TicTacToe *tictactoe)
{
 for(int i=0;i<3;i++)
 {
   if (tictactoe->board[i][0]==tictactoe->board[i][1] && tictactoe->board[i][0] == tictactoe->board[i][2])
     {
         tictactoe->winner=tictactoe->board[i][0];
   
     }
 }
  for(int j=0;j<3;j++)
 {
  if (tictactoe->board[0][j]==tictactoe->board[1][j] && tictactoe->board[0][j] == tictactoe->board[2][j])
     {
                  tictactoe->winner=tictactoe->board[0][j];
   
     } 
  }
  if (tictactoe->board[0][0]==tictactoe->board[1][1] && tictactoe->board[0][0] == tictactoe->board[2][2])
     {
                           tictactoe->winner=tictactoe->board[0][0];
   
     }
  if (tictactoe->board[0][2]==tictactoe->board[1][1] && tictactoe->board[0][2] == tictactoe->board[2][0])
     {
        tictactoe->winner=tictactoe->board[0][2];
   
     }
  

}

void printwinner(SDL_Surface *screen,TicTacToe *tictactoe)
{

checkWinner(tictactoe);
 if (tictactoe->winner=='O')
{
tictactoe->Lose_txt=TTF_RenderText_Blended(tictactoe->txt_police,"You Lose",tictactoe->txt_color);
	SDL_BlitSurface(tictactoe->Lose_txt,NULL,screen,&tictactoe->pos_Lose_ecran);


}
else if (tictactoe->winner=='X')
{

tictactoe->Win_txt=TTF_RenderText_Blended(tictactoe->txt_police,"You Win",tictactoe->txt_color);
	SDL_BlitSurface(tictactoe->Win_txt,NULL,screen,&tictactoe->pos_Win_ecran);
}
else if (CheckFreeSpaces(tictactoe)==0)
{

tictactoe->Draw_txt=TTF_RenderText_Blended(tictactoe->txt_police,"Tie",tictactoe->txt_color);
	SDL_BlitSurface(tictactoe->Draw_txt,NULL,screen,&tictactoe->pos_Draw_ecran);
}


}





void free_TicTacToe(TicTacToe *tictactoe)
{
 SDL_FreeSurface(tictactoe->Menu);
 SDL_FreeSurface(tictactoe->MenuSelected);
 SDL_FreeSurface(tictactoe->Background);
 SDL_FreeSurface(tictactoe->BackgroundBox);
 SDL_FreeSurface(tictactoe->BackgroundWinLose);
 SDL_FreeSurface(tictactoe->X); 
 SDL_FreeSurface(tictactoe->O);
 SDL_FreeSurface(tictactoe->Win_txt);
 SDL_FreeSurface(tictactoe->Lose_txt);
 SDL_FreeSurface(tictactoe->Draw_txt);
 TTF_CloseFont(tictactoe->txt_police);
 free(tictactoe);








}
