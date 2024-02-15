#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 779
#define SCREEN_W 1433
#define Square 176


typedef struct
{

  SDL_Surface *imgbtn1;
  SDL_Surface *imgbtn1s;
  SDL_Surface *imgbtn2;
  SDL_Surface *imgbtn2s;
  SDL_Surface *imgbtn3;
  SDL_Surface *imgbtn3s;
  SDL_Surface *imgbtn4;
  SDL_Surface *imgbtn4s;
  SDL_Surface *imgtxt;
  SDL_Surface *imgbtnx;
  SDL_Surface *imgbtnxs;
  SDL_Surface *imgbtnfullscreen;
  SDL_Surface *imgbtnfullscreens;
  SDL_Surface *imgbtnwindowed;
  SDL_Surface *imgbtnwindoweds;
  SDL_Surface *imgbtnvolume;
  SDL_Surface *imgbtnvolumes;
  SDL_Surface *imgbtnback;
  SDL_Surface *imgbtnbacks;
  SDL_Rect pos_btn1_ecran;
  SDL_Rect pos_btn2_ecran;
  SDL_Rect pos_btn3_ecran;
  SDL_Rect pos_btn4_ecran;
  SDL_Rect pos_btntxt_ecran;
  SDL_Rect pos_btnx_ecran;
  SDL_Rect pos_btnfullscreen_ecran;
  SDL_Rect pos_btnwindowed_ecran;
  SDL_Rect pos_btnvolume_ecran;
  SDL_Rect pos_btnback_ecran;
  int SonBrefButtonNewGame;
  int SonBrefButtonContinue;
  int SonBrefButtonOptions;
  int SonBrefButtonVolume;
  int SonBrefButtonWindowed;
  int SonBrefButtonFullScreen;
  int SonBrefButtonX;
  int SonBrefButtonBack;
  int SonBrefButtonExit;
  
 
}
buttons;


typedef struct
{


  SDL_Surface *imgslider1;
  SDL_Surface *imgslider2;
  SDL_Surface *imgslider3;
  SDL_Surface *imgslider4;
  SDL_Surface *imgslider5;
  SDL_Surface *imgplus;
  SDL_Surface *imgpluss;
  SDL_Surface *imgmoins;
  SDL_Surface *imgmoinss;
  SDL_Rect pos_imgslider_ecran;
  SDL_Rect pos_imgslidercopy_ecran;
  SDL_Rect pos_plus_ecran;
  SDL_Rect pos_pluscopy_ecran;
  SDL_Rect pos_moins_ecran;
  SDL_Rect pos_moinscopy_ecran;
  
 
 





}Volume;


typedef struct
{
 SDL_Surface *volume_txt;
 SDL_Surface *music_txt;
 SDL_Surface *soundfx_txt;
 SDL_Surface *facts_txt;
 SDL_Colour color_txt;
 TTF_Font *volume_police;
 TTF_Font *music_soundfx_police;
 TTF_Font *facts_police;
 SDL_Rect pos_volumetxt_ecran;
 SDL_Rect pos_musictxt_ecran;
 SDL_Rect pos_soundfxtxt_ecran;
 SDL_Rect pos_factstxt_ecran;
 




}
texts;


typedef struct
{

  SDL_Surface *MenuBackground[9];
  SDL_Surface *OptionBackground;
  SDL_Rect pos_OptionBackground_ecran;
  int MenuState;
  int MenuKeyState;
  int OptionKeyState;
  int BackgroundAnimationTimer;
  int RandomNumber;
  int MusicSliderState;
  int SoundFXSliderState;
  int SonBrefControler;
  int KeyState;
  Mix_Music *music;
  Mix_Chunk *bref;
  buttons button;
  Volume volume;
  texts text;
  
 
  













 
}
menu;



typedef struct
{
SDL_Surface *TrailerFrames[16];
int DialogueShown;
int AnimationTimer;
int StartAnimation;
Mix_Music *music;














}
Trailer;
 
  

typedef struct
{
 SDL_Surface *Map1;
 SDL_Surface *Map1_Calque;
 SDL_Surface *flag;
 SDL_Surface *heart; 
 SDL_Surface *coin;
 SDL_Rect pos_flag_ecran;
 SDL_Rect pos_flag_affiche;
 SDL_Rect pos_map1_affiche;
 SDL_Rect pos_heart_ecran;
 SDL_Rect pos_coin_ecran;
 SDL_Rect pos_coin2_ecran;
 SDL_Rect pos_coin3_ecran;
 SDL_Rect pos_coin_affiche;
 SDL_Rect spike1_dimension;
 SDL_Rect spike2_dimension;
 SDL_Rect spike3_dimension;
 SDL_Rect spike4_dimension;
 int FlagReached;
 int CoinTimer;
 int IsSaveMenuClicked;
 Mix_Music *music;
 
 
    

 
     

}Russia;
 
  
typedef struct
{
 SDL_Surface *afficher_perso;
 SDL_Surface *GameOver;
 SDL_Surface *TryAgain;
 SDL_Surface *TryAgainSelected;
 SDL_Rect pos_TryAgain_ecran; 
 SDL_Surface *QuitGame;
 SDL_Surface *QuitGameSelected;
 SDL_Rect pos_QuitGame_ecran;
 SDL_Rect pos_perso_ecran;
 SDL_Rect pos_perso_affiche;
 SDL_Surface *SpaceBar[2];
 SDL_Rect pos_SpaceBar_ecran;
 int SpaceBarAnimationTimer;
 float acceleration;
 float Vitesse_Forward;
 float Vitesse_Backward;
 float gravity;
 int vie;
 int jump;
 int repere_imaginaire;
 int JumpStart;
 int CoinsSecured;
 int ColidedWithCoin;
 int ColidedWithCoin2;
 int ColidedWithCoin3;
 int ColidedWithCoin4; 
 int ColidedWithCoin5;
 int ColidedWithCoin6;
 int ColidedWithCoin7; 
 int ColidedWithCoin8;
 int ColidedWithCoin9;
 int NotMovingTimer;
 int RunningTimer;
 int JumpingTimer;
 int MouvementTrajectory;
 int EnnemiesKilled;
 
  
 
 


 
 

}Perso;



typedef struct
{

SDL_Surface *afficher_IceMob;
 SDL_Rect pos_IceMob_ecran;
 SDL_Rect pos_IceMob_affiche;
 int PositionInitiale;
 int EnnemiState;
 int MouvementTimer;
 int Mouvement;
 int Trajectory;
 





 


}
IceMob;



typedef struct
{

SDL_Surface *afficher_Hunter;
 SDL_Rect pos_Hunter_ecran;
 SDL_Rect pos_Hunter_affiche;
 int PositionInitiale;
 int EnnemiState;
 int MouvementTimer;
 int Mouvement;
 int Trajectory;
 int Following;


   


 
 


}
Hunter;


typedef struct
{

 SDL_Surface *BossRoom[4];
 SDL_Surface *BossRoomDialogue[14];
 SDL_Rect BossRoomDialogue_pos_ecran;
  int BossRoomAnimationTimer;
  int DialogueShown;
  int Enigme; 
  Mix_Music *music;
 
  


  
 

 
}
BossRoomRussia;

 

typedef struct
{
SDL_Surface *LoseBackground;
SDL_Surface *AdvanceBackground;
SDL_Surface *Next;
SDL_Rect pos_ButtonNext_ecran;
SDL_Surface *Retry;
SDL_Rect pos_ButtonRetry_ecran;
TTF_Font *score_police;
char CoinsSecured[10];
char EnnemiesKilled[10];
char Time[10];
char FinalScore[10];
SDL_Color color_score;
SDL_Surface *SurfaceCoinsSecured;
SDL_Rect pos_SurfaceCoins_ecran;
SDL_Surface *SurfaceEnnemiesKilled;
SDL_Rect pos_SurfaceEnnemies_ecran;
SDL_Surface *SurfaceTime;
SDL_Rect pos_SurfaceTime_ecran;
SDL_Surface *SurfaceFinalScore;
SDL_Rect pos_SurfaceFinalScore_ecran;
int IsShown;









}
score;


typedef struct
{
SDL_Surface *EnigmeRussiaBackground;
SDL_Rect pos_background_ecran;
SDL_Surface *boxes;
SDL_Rect pos_boxes_ecran;
SDL_Surface *RightCheck;
SDL_Surface *WrongCheck;
SDL_Rect pos_Checks_ecran;
SDL_Surface *QuestionSurface;
SDL_Rect pos_question_ecran;
SDL_Surface *AnswerSurface1; 
SDL_Surface *AnswerSurface2;
SDL_Surface *AnswerSurface3;
SDL_Rect pos_answer_ecran;
SDL_Surface *TimerSurface;
SDL_Rect pos_timer_ecran; 
SDL_Color color_txt;
TTF_Font *police_question;
TTF_Font *police_answer;
int Random_Number;
char question[256];
 char answer[3][256];
int CorrectAnswer;
int click;
int timer;
int StartOfEnigmeTimer;
char Txt_Timer[2];
int Win;
score ScoreLVL1;







}
EnigmeRussia;


typedef struct
{
SDL_Surface *Menu;
SDL_Surface *MenuSelected;
SDL_Rect pos_Menu_ecran;
SDL_Surface *Background;
SDL_Rect pos_Background_ecran;
SDL_Surface *Quit;
SDL_Surface *QuitSelected;
SDL_Rect pos_Quit_ecran;
SDL_Surface *Save;
SDL_Surface *SaveSelected;
SDL_Rect pos_Save_ecran;










}
Save_Quit;




typedef struct
{
 SDL_Surface *Map2;
 SDL_Surface *Map2_Calque;
 SDL_Rect pos_flag_ecran;
 SDL_Rect pos_flag_affiche;
 SDL_Rect pos_map2_affiche;
 SDL_Rect pos_heart_ecran;
 SDL_Rect pos_coin1_ecran;
 SDL_Rect pos_coin2_ecran;
 SDL_Rect pos_coin3_ecran;
 SDL_Rect spike1_dimension;
 SDL_Rect spike2_dimension;
 SDL_Rect spike3_dimension; 
 int FlagReached;
 int IsSaveMenuClicked;
 Mix_Music *music; 
 
 
   

 
     

}Egypt;



typedef struct
{

SDL_Surface *afficher_Anubis;
 SDL_Rect pos_Anubis_ecran;
 SDL_Rect pos_Anubis_affiche;
 int PositionInitiale;
 int EnnemiState;
 int MouvementTimer;
 int Mouvement;
 int Trajectory;
 





 


}
Anubis;



typedef struct
{

SDL_Surface *afficher_Fly;
 SDL_Rect pos_Fly_ecran;
 SDL_Rect pos_Fly_affiche;
 int PositionInitiale;
 int EnnemiState;
 int MouvementTimer;
 int Mouvement;
 int Trajectory;
 

 



 


}
Fly;
 


typedef struct
{

 SDL_Surface *BossRoom[4];
 SDL_Surface *BossRoomDialogue[8];
  SDL_Rect BossRoomDialogue_pos_ecran;
  int BossRoomAnimationTimer;
  int DialogueShown;
  int Enigme; 
  Mix_Music *music;
 
 

  
 

 
}
BossRoomEgypt;


 
typedef struct
{
SDL_Surface *LoseBackground;
SDL_Surface *AdvanceBackground;
SDL_Surface *Next;
SDL_Rect pos_ButtonNext_ecran;
SDL_Surface *Retry;
SDL_Rect pos_ButtonRetry_ecran;
//TTF_Font *score_police;
char CoinsSecured[10];
char EnnemiesKilled[10];
char Time[10];
char FinalScore[10];
SDL_Color color_score;
SDL_Surface *SurfaceCoinsSecured;
SDL_Rect pos_SurfaceCoins_ecran;
SDL_Surface *SurfaceEnnemiesKilled;
SDL_Rect pos_SurfaceEnnemies_ecran;
SDL_Surface *SurfaceTime;
SDL_Rect pos_SurfaceTime_ecran;
SDL_Surface *SurfaceFinalScore;
SDL_Rect pos_SurfaceFinalScore_ecran;
int IsShown;









}
scoreEgypt;


typedef struct
{
SDL_Surface *EnigmeEgyptBackground;
SDL_Rect pos_background_ecran;
SDL_Surface *boxes;
SDL_Rect pos_boxes_ecran;
SDL_Surface *RightCheck;
SDL_Surface *WrongCheck;
SDL_Rect pos_Checks_ecran;
SDL_Surface *QuestionSurface;
SDL_Rect pos_question_ecran;
SDL_Surface *AnswerSurface1; 
SDL_Surface *AnswerSurface2;
SDL_Surface *AnswerSurface3;
SDL_Rect pos_answer_ecran;
SDL_Surface *TimerSurface;
SDL_Rect pos_timer_ecran; 
SDL_Color color_txt;
int Random_Number;
char question[256];
 char answer[3][256];
int CorrectAnswer;
int click;
int timer;
int StartOfEnigmeTimer;
char Txt_Timer[2];
int Win;
scoreEgypt ScoreLVL2;







}
EnigmeEgypt;



typedef struct
{
 SDL_Surface *Map3;
 SDL_Surface *Map3_Calque;
 SDL_Rect pos_flag_ecran;
 SDL_Rect pos_flag_affiche;
 SDL_Rect pos_map3_affiche;
 SDL_Rect pos_heart_ecran;
 SDL_Rect pos_coin1_ecran;
 SDL_Rect pos_coin2_ecran;
 SDL_Rect pos_coin3_ecran;
 SDL_Rect spike1_dimension;
 SDL_Rect spike2_dimension;
 SDL_Rect spike3_dimension;  
 int FlagReached;
 int IsSaveMenuClicked;
 Mix_Music *music; 
 
 
   

 
     

}Japan;




typedef struct
{

SDL_Surface *afficher_Youkai;
 SDL_Rect pos_Youkai_ecran;
 SDL_Rect pos_Youkai_affiche;
 int PositionInitiale;
 int EnnemiState;
 int MouvementTimer;
 int Mouvement;
 int Trajectory;
 





 


}
Youkai;


typedef struct
{

SDL_Surface *afficher_Fox;
 SDL_Rect pos_Fox_ecran;
 SDL_Rect pos_Fox_affiche;
 int PositionInitiale;
 int EnnemiState;
 int MouvementTimer;
 int Mouvement;
 int Trajectory;
 int Following; 
 





 


}
Fox;



typedef struct
{

 SDL_Surface *BossRoom[4];
 SDL_Surface *BossRoomDialogue[8];
  SDL_Rect BossRoomDialogue_pos_ecran;
  int BossRoomAnimationTimer;
  int DialogueShown;
  int Enigme;
  Mix_Music *music;   
 


  
 

 
}
BossRoomJapan;




typedef struct
{
SDL_Surface *LoseBackground;
SDL_Surface *AdvanceBackground;
SDL_Surface *Next;
SDL_Rect pos_ButtonNext_ecran;
SDL_Surface *Retry;
SDL_Rect pos_ButtonRetry_ecran;
//TTF_Font *score_police;
char CoinsSecured[10];
char EnnemiesKilled[10];
char Time[10];
char FinalScore[10];
SDL_Color color_score;
SDL_Surface *SurfaceCoinsSecured;
SDL_Rect pos_SurfaceCoins_ecran;
SDL_Surface *SurfaceEnnemiesKilled;
SDL_Rect pos_SurfaceEnnemies_ecran;
SDL_Surface *SurfaceTime;
SDL_Rect pos_SurfaceTime_ecran;
SDL_Surface *SurfaceFinalScore;
SDL_Rect pos_SurfaceFinalScore_ecran;
int IsShown;









}
scoreJapan;



typedef struct
{
SDL_Surface *EnigmeJapanBackground;
SDL_Rect pos_background_ecran;
SDL_Surface *boxes;
SDL_Rect pos_boxes_ecran;
SDL_Surface *RightCheck;
SDL_Surface *WrongCheck;
SDL_Rect pos_Checks_ecran;
SDL_Surface *QuestionSurface;
SDL_Rect pos_question_ecran;
SDL_Surface *AnswerSurface1; 
SDL_Surface *AnswerSurface2;
SDL_Surface *AnswerSurface3;
SDL_Rect pos_answer_ecran;
SDL_Surface *TimerSurface;
SDL_Rect pos_timer_ecran; 
SDL_Color color_txt;
int Random_Number;
char question[256];
 char answer[3][256];
int CorrectAnswer;
int click;
int timer;
int StartOfEnigmeTimer;
char Txt_Timer[2];
int Win;
scoreJapan ScoreLVL3;



 



}
EnigmeJapan;





typedef struct
{

 SDL_Surface *BossRoom[9];
 SDL_Surface *BossRoomDialogue[11];
  SDL_Rect BossRoomDialogue_pos_ecran;
  int BossRoomAnimationTimer;
  int DialogueShown;
  Mix_Music *music; 
  //int Enigme; 
 


  
 
 
 
}
BossRoomSpace;






typedef struct
{

 SDL_Surface *EndScreen;
 SDL_Surface *QuitGame;
 SDL_Surface *QuitGameSelected;
  SDL_Rect pos_QuitGame_ecran;
 Mix_Music *music;
 


  
 

 
}
EndScreen;




typedef struct
{

SDL_Surface *Menu;
SDL_Surface *MenuSelected;
SDL_Rect pos_Menu_ecran;
SDL_Surface *Background;
SDL_Rect pos_Background_ecran; 
SDL_Surface *BackgroundBox;
SDL_Rect pos_BackgroundBox_ecran;
SDL_Surface *BackgroundWinLose;
SDL_Rect pos_BackgroundWinLose_ecran;
SDL_Surface *X;
SDL_Rect pos_X_ecran; 
SDL_Surface *O;
SDL_Rect pos_O_ecran; 
SDL_Surface *Win_txt;
SDL_Rect pos_Win_ecran;
SDL_Surface *Lose_txt;
SDL_Rect pos_Lose_ecran;
SDL_Surface *Draw_txt;
SDL_Rect pos_Draw_ecran;
TTF_Font *txt_police;
SDL_Color txt_color; 
char board[3][3];
char winner;
int IsTicTacToeClicked;
int PlayerHasMoved;
int FreeSpaces;








}
TicTacToe;





 




 

 
   
  
      
     
void initialiser_Menu(menu *menu);
void initialiser_lvl1(Russia *russia);
void initialiser_Personnage(Perso *perso);
void initialiser_IceMob(IceMob *Mob);
void initialiser_Hunter(Hunter *hunter);
void initialiser_BossRoomRussia(BossRoomRussia *Boss1);
void initialiser_EnigmeRussia(EnigmeRussia *enigmeLVL1);
void initialiser_Save_Quit(Save_Quit *Save);
void initialiser_lvl2(Egypt *egypt);
void initialiser_Anubis(Anubis *anubis);
void initialiser_Fly(Fly *fly);
void initialiser_TicTacToe(TicTacToe *tictactoe);
void initialiser_BossRoomEgypt(BossRoomEgypt *Boss2);
int GenerateRandomNumberlvl2(EnigmeEgypt *EnigmeLVL2);
void ReadQuestionFromFilelvl2(EnigmeEgypt *EnigmeLVL2);
void initialiser_EnigmeEgypt(EnigmeEgypt *EnigmeLVL2);
void initialiser_lvl3(Japan *japan);
void initialiser_Youkai(Youkai *youkai);
void initialiser_Fox(Fox *fox);
void initialiser_BossRoomJapan(BossRoomJapan *Boss3);
int GenerateRandomNumberlvl3(EnigmeJapan *EnigmeLVL3);
void ReadQuestionFromFilelvl3(EnigmeJapan *EnigmeLVL3);
void initialiser_EnigmeJapan(EnigmeJapan *EnigmeLVL3);
void initialiser_BossRoomSpace(BossRoomSpace *Boss4);
void initialiser_EndScreen(EndScreen *end);
void initialiser_Trailer(Trailer *trailer); 
void load_RandomFact(menu *menu);
void afficher_SpaceBar(SDL_Surface *screen, Perso *perso);
void afficher_menu(SDL_Surface *screen,menu *menu);
void afficher_TicTacToeIcon(SDL_Surface *screen,TicTacToe *tictactoe);
void afficher_TicTacToeBackground(SDL_Surface *screen,TicTacToe *tictactoe);
void affichage_PlayerXO(SDL_Surface *screen,TicTacToe *tictactoe);
void printwinner(SDL_Surface *screen,TicTacToe *tictactoe); 
void ComputerMove(TicTacToe *tictactoe);
void affichage_ComputerXO(SDL_Surface *screen,TicTacToe *tictactoe);
void load_RandomFact(menu *menu);
void SoundFXSliderControl(menu *menu,SDL_Event event); 
void MusicSliderControl(menu *menu,SDL_Event event);
void SonBrefControlAllButtons(SDL_Event event,menu *menu);
void PressControlAllButtons(SDL_Event event,menu *menu,int *boucle,int *GameState,int *MenuScreenLoaded,int *GameScreenLoaded,int *Reinitialisation_lvl1,int *Continue_lvl1,int *Continue_lvl2,int *Continue_lvl3,int *MusicMenu,int *MusicGame,int *Reinitialisation_trailer);
void ClickTicTacToeIcon(SDL_Event event,TicTacToe *tictactoe);
void playerXOMove(SDL_Event event,TicTacToe *tictactoe);
void KeyboardHandling(SDL_Event event , menu *menu,int *boucle,int *GameState,int *MenuScreenLoaded,int *GameScreenLoaded,int *Reinitialisation_lvl1,int *Continue_lvl1,int *Continue_lvl2,int *Continue_lvl3,int *MusicMenu,int *MusicGame);
void reinitialiser_Trailer(Trailer *trailer);
void afficher_Trailer(SDL_Surface *screen,Trailer *trailer,Perso *perso);
void afficher_AnimationTrailer(SDL_Surface *screen,Trailer *trailer,int *GameState,int *MusicGame,int *Reinitialisation_lvl1);
void LeaveTicTacToe(SDL_Event event ,TicTacToe *tictactoe);
void reinizialitation_lvl1(Perso *perso,Russia *russia,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1,Hunter *hunter,IceMob *Mob);
void ContinueGameRussia(Perso *perso,Russia *russia,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1,Hunter *hunter,IceMob *Mob,int *GameState);
void afficher_lvl1(SDL_Surface *screen,Russia *russia,Perso *perso);
void afficher_SaveMenuIcon(SDL_Surface *screen,Save_Quit *Save);
void afficher_PersoMap(SDL_Surface *screen, Perso *perso);
void afficher_IceMob(SDL_Surface *screen,IceMob *Mob , Russia *russia,Perso *perso);
void afficher_Hunter(SDL_Surface *screen,Hunter *hunter , Russia *russia,Perso *perso);
void AnimateCoin(Russia *russia);
void scrollingRussia(Russia *russia , Perso *perso,float deltaTime,const Uint8 *keys);
void PersoMouvementControlRussia(Russia *russia,Perso *perso,float  deltaTime,const Uint8 *keys); 
void PersoCollisionControlRussia(Russia *russia,Perso *perso);
void Perso_DeathRussia(Perso *perso,Russia *russia);
void Perso_DeathEgypt(Perso *perso,Egypt *egypt);
void Perso_DeathJapan(Perso *perso,Japan *japan);
void afficher_SaveMenuBackground(SDL_Surface *screen,Save_Quit *Save);
void initialize_Jump(Perso *perso);
void LeaveSaveMenuRussiaIcon(SDL_Event event,Russia *russia);
void ClickWhileGameOverRussia(SDL_Event event,Perso *perso,int *GameState,int *Reinitialisation_lvl1);
void ClickSaveMenuRussiaIcon(SDL_Event event,Russia *russia,Save_Quit *Save);
void ClickToSaveOrQuitMenuRussia(SDL_Event event,Save_Quit *Save,int *GameState,Perso *perso,Russia *russia,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1,Hunter *hunter,IceMob *Mob);
int CollisionPerfectPixelRussia(Russia *russia,Perso *perso);
int CollisionPerfectPixelRightRussia(Russia *russia,Perso *perso);
int CollisionPerfectPixelLeftRussia(Russia *russia,Perso *perso);
int CollisionPerfectPixelUpRussia(Russia *russia,Perso *perso);
int CollisionPerfectPixelEgypt(Egypt *egypt,Perso *perso);
int CollisionPerfectPixelRightEgypt(Egypt *egypt,Perso *perso);
int CollisionPerfectPixelLeftEgypt(Egypt *egypt,Perso *perso);
int CollisionPerfectPixelUpEgypt(Egypt *egypt,Perso *perso);
int CollisionPerfectPixelJapan(Japan *japan,Perso *perso); 
int CollisionPerfectPixelRightJapan(Japan *japan,Perso *perso);
int CollisionPerfectPixelLeftJapan(Japan *japan,Perso *perso);
int CollisionPerfectPixelUpJapan(Japan *japan,Perso *perso);
int CollisionBoundingBox(SDL_Rect obstacle1_ecran, SDL_Rect obstacle1_affiche,SDL_Rect obstacle2_ecran, SDL_Rect obstacle2_affiche);
int CollisionBoundingBoxSpikes(SDL_Rect obstacle1_ecran, SDL_Rect obstacle1_affiche,SDL_Rect Map,SDL_Rect obstacle2);
void FallOutsideMapRussia(Perso *perso,Russia *russia);
void GameOver(SDL_Surface *screen,Perso *perso);
void afficher_BossRoomRussia(SDL_Surface *screen, BossRoomRussia *Boss1,Perso *perso);
void calculate_TimeEnigmeRussia(EnigmeRussia *EnigmeLVL1);
void afficher_EnigmeRussia(SDL_Surface *screen,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1);
void Click_answer(SDL_Event event, EnigmeRussia *EnigmeLVL1);
void Correct_answer(SDL_Surface *screen,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1);
void Scorelvl1Calculations(EnigmeRussia *EnigmeLVL1,Perso *perso);
void afficher_Backgroundscore(SDL_Surface *screen,EnigmeRussia *EnigmeLVL1);
void Click_AfterAnsweringRussia(SDL_Event event,int *GameState,EnigmeRussia *EnigmeLVL1,BossRoomRussia *Boss1,int *Reinitialisation_lvl1,int *Reinitialisation_lvl2,int *MusicGame);
void reinizialitation_lvl2(Perso *perso,Egypt *egypt,EnigmeEgypt *EnigmeLVL2,BossRoomEgypt *Boss2,Fly *fly,Anubis *anubis);
void ContinueGameEgypt(Perso *perso,Egypt *egypt,int *GameState);
void afficher_lvl2(SDL_Surface *screen,Egypt *egypt,Russia *russia,Perso *perso);
void afficher_Anubis(SDL_Surface *screen,Anubis *anubis ,  Egypt *egypt,Perso *perso);
void afficher_Fly(SDL_Surface *screen,Fly *fly,  Egypt *egypt,Perso *perso);
void scrollingEgypt(Egypt *egypt , Perso *perso,float deltaTime,const Uint8 *keys); 
void PersoMouvementControlEgypt(Egypt *egypt,Perso *perso,float  deltaTime,const Uint8 *keys);  
void PersoCollisionControlEgypt(Egypt *egypt,Russia *russia,Perso *perso);
void FallOutsideMapEgypt(Perso *perso,Egypt *egypt);
void LeaveSaveMenuEgyptIcon(SDL_Event event ,Egypt *egypt);
void ClickWhileGameOverEgypt(SDL_Event event,Perso *perso,int *GameState,int *Reinitialisation_lvl2);
void ClickSaveMenuEgyptIcon(SDL_Event event,Egypt *egypt,Save_Quit *Save);
void ClickToSaveOrQuitMenuEgypt(SDL_Event event,Save_Quit *Save,int *GameState,Perso *perso,Egypt *egypt);
void afficher_BossRoomEgypt(SDL_Surface *screen, BossRoomEgypt *Boss2,Perso *perso);
void calculate_TimeEnigmeEgypt(EnigmeEgypt *EnigmeLVL2);
void afficher_EnigmeEgypt(SDL_Surface *screen,EnigmeEgypt *EnigmeLVL2,EnigmeRussia *EnigmeLVL1,BossRoomEgypt *Boss2);
void Correct_answerEgypt(SDL_Surface *screen,EnigmeEgypt *EnigmeLVL2,BossRoomEgypt *Boss2);
void Scorelvl2Calculations(EnigmeEgypt *EnigmeLVL2,Perso *perso);
void afficher_BackgroundEgyptscore(SDL_Surface *screen,EnigmeEgypt *EnigmeLVL2,EnigmeRussia *EnigmeLVL1); 
void Click_answerEgypt(SDL_Event event, EnigmeEgypt *EnigmeLVL2);
void Click_AfterAnsweringEgypt(SDL_Event event,int *GameState,EnigmeEgypt *EnigmeLVL2,BossRoomEgypt *Boss2,int *Reinitialisation_lvl2,int *Reinitialisation_lvl3,int *MusicGame);
void reinizialitation_lvl3(Perso *perso,Japan *japan,EnigmeJapan *EnigmeLVL3,BossRoomJapan *Boss3,Fox *fox,Youkai *youkai);
void ContinueGameJapan(Perso *perso,Japan *japan,int *GameState);
void afficher_lvl3(SDL_Surface *screen,Japan *japan,Russia *russia,Perso *perso);
void afficher_Youkai(SDL_Surface *screen,Youkai *youkai , Japan *japan,Perso *perso);
void afficher_Fox(SDL_Surface *screen,Fox *fox , Japan *japan,Perso *perso);
void scrollingJapan(Japan *japan , Perso *perso,float deltaTime,const Uint8 *keys)  ;
void PersoMouvementControlJapan(Japan *japan,Perso *perso,float  deltaTime,const Uint8 *keys);
void PersoCollisionControlJapan(Japan *japan,Russia *russia,Perso *perso);
void FallOutsideMapJapan(Perso *perso,Japan *japan);
void LeaveSaveMenuJapanIcon(SDL_Event event ,Japan *japon);
void ClickWhileGameOverJapan(SDL_Event event,Perso *perso,int *GameState,int *Reinitialisation_lvl3);
void ClickSaveMenuJapanIcon(SDL_Event event,Japan *japan,Save_Quit *Save);
void ClickToSaveOrQuitMenuJapan(SDL_Event event,Save_Quit *Save,int *GameState,Perso *perso,Japan *japan) ;
void afficher_BossRoomJapan(SDL_Surface *screen, BossRoomJapan *Boss3,Perso *perso);
void calculate_TimeEnigmeJapan(EnigmeJapan *EnigmeLVL3);
void afficher_EnigmeJapan(SDL_Surface *screen,EnigmeJapan *EnigmeLVL3,EnigmeRussia *EnigmeLVL1,BossRoomJapan *Boss3);
void Correct_answerJapan(SDL_Surface *screen,EnigmeJapan *EnigmeLVL3,BossRoomJapan *Boss3);
void Scorelvl3Calculations(EnigmeJapan *EnigmeLVL3,Perso *perso);
void afficher_BackgroundJapanscore(SDL_Surface *screen,EnigmeJapan *EnigmeLVL3,EnigmeRussia *EnigmeLVL1);
void Click_answerJapan(SDL_Event event, EnigmeJapan *EnigmeLVL3);
void Click_AfterAnsweringJapan(SDL_Event event,int *GameState,EnigmeJapan *EnigmeLVL3,BossRoomJapan *Boss3,int *Reinitialisation_lvl3,int *MusicGame);
void afficher_BossRoomSpace(SDL_Surface *screen, BossRoomSpace *Boss4,Perso *perso,int *GameState,int *MusicGame);
void afficher_EndScreen(SDL_Surface *screen,EndScreen *end);
void ClickToQuitEndScreen(SDL_Event event,EndScreen *end,int *GameState);
void FreeMenu(menu *menu);
void free_lvl1(Russia *russia);
void free_Perso(Perso *perso);
void free_IceMob(IceMob *Mob); 
void free_Hunter(Hunter *hunter);
void freeBossRoomRussia(BossRoomRussia *Boss1);
void Free_EnigmeRussia(EnigmeRussia *enigmeLVL1);
void free_Save_Quit(Save_Quit *Save);
void free_lvl2(Egypt *egypt);
void free_Anubis(Anubis *anubis); 
void free_Fly(Fly *fly);
void free_TicTacToe(TicTacToe *tictactoe);
void freeBossRoomEgypt(BossRoomEgypt *Boss2); 
void Free_EnigmeEgypt(EnigmeEgypt *EnigmeLVL2);
void free_lvl3(Japan *japan);
void free_Youkai(Youkai *youkai);
void free_Fox(Fox *fox);
void freeBossRoomJapan(BossRoomJapan *Boss3);
void Free_EnigmeJapan(EnigmeJapan *EnigmeLVL3);
void freeBossRoomSpace(BossRoomSpace *Boss4);
void freeEndScreen(EndScreen *end);
void freeTrailer(Trailer *trailer);

   
      
 
  
    









#endif
