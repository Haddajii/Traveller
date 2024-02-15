#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

 
   
SDL_Color GetPixelRussia(Russia *russia,int x,int y)
{
SDL_Color color;

Uint32 col=0;
Uint8 *pixel = (Uint8 *)russia->Map1_Calque->pixels + (y * russia->Map1_Calque->pitch) + (x * russia->Map1_Calque->format->BytesPerPixel);
memcpy(&col,pixel,russia->Map1_Calque->format->BytesPerPixel);
SDL_GetRGB(col,russia->Map1_Calque->format,&color.r,&color.g,&color.b);
return(color);
}


int CollisionPerfectPixelRussia(Russia *russia,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               X[0]=perso->pos_perso_ecran.x+23+russia->pos_map1_affiche.x;
              X[1]=perso->pos_perso_ecran.x+46+russia->pos_map1_affiche.x;
		X[2]=perso->pos_perso_ecran.x+80+russia->pos_map1_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+162+russia->pos_map1_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+162+russia->pos_map1_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+162+russia->pos_map1_affiche.y;
		
    while ( i<3 && collision==0)
     {
       color=GetPixelRussia(russia,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else
           i++;


      }
      if (collision==0) 
       {
 
         return(0);
       }
  
}
    
     
int CollisionPerfectPixelRightRussia(Russia *russia,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               
              X[0]=perso->pos_perso_ecran.x+93+russia->pos_map1_affiche.x;
              X[1]=perso->pos_perso_ecran.x+93+russia->pos_map1_affiche.x;
              X[2]=perso->pos_perso_ecran.x+93+russia->pos_map1_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+140+russia->pos_map1_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+81+russia->pos_map1_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+12+russia->pos_map1_affiche.y;
		
       while ( i<3 && collision==0)
     {
       color=GetPixelRussia(russia,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else
           i++;


      }
      if (collision==0) 
       {
 
         return(0);
       }
}


    


int CollisionPerfectPixelLeftRussia(Russia *russia,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               
              X[0]=perso->pos_perso_ecran.x+russia->pos_map1_affiche.x;
              X[1]=perso->pos_perso_ecran.x+russia->pos_map1_affiche.x;
              X[2]=perso->pos_perso_ecran.x+russia->pos_map1_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+140+russia->pos_map1_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+81+russia->pos_map1_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+12+russia->pos_map1_affiche.y;
		
       while ( i<3 && collision==0)
     {
       color=GetPixelRussia(russia,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else
           i++;
  
         
      }
      if (collision==0) 
       {
 
         return(0);
       }
        
                                  
}
 
int CollisionPerfectPixelUpRussia(Russia *russia,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               
              X[0]=perso->pos_perso_ecran.x+russia->pos_map1_affiche.x;
              X[1]=perso->pos_perso_ecran.x+46+russia->pos_map1_affiche.x;
              X[2]=perso->pos_perso_ecran.x+93+russia->pos_map1_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+russia->pos_map1_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+russia->pos_map1_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+russia->pos_map1_affiche.y;
		
       while ( i<3 && collision==0)
     {
       color=GetPixelRussia(russia,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else
           i++;


      }
      if (collision==0) 
       {
 
         return(0);
       }

    
}





SDL_Color GetPixelEgypt(Egypt *egypt,int x,int y)
{
SDL_Color color;

Uint32 col=0;
Uint8 *pixel = (Uint8 *)egypt->Map2_Calque->pixels + (y * egypt->Map2_Calque->pitch) + (x * egypt->Map2_Calque->format->BytesPerPixel);
memcpy(&col,pixel,egypt->Map2_Calque->format->BytesPerPixel);
SDL_GetRGB(col,egypt->Map2_Calque->format,&color.r,&color.g,&color.b);
return(color);
}



int CollisionPerfectPixelEgypt(Egypt *egypt,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               X[0]=perso->pos_perso_ecran.x+23+egypt->pos_map2_affiche.x;
              X[1]=perso->pos_perso_ecran.x+46+egypt->pos_map2_affiche.x;
		X[2]=perso->pos_perso_ecran.x+80+egypt->pos_map2_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+162+egypt->pos_map2_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+162+egypt->pos_map2_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+162+egypt->pos_map2_affiche.y;
		
    while ( i<3 && collision==0)
     {
       color=GetPixelEgypt(egypt,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else
           i++;


      }
      if (collision==0) 
       {
 
         return(0);
       }
  
}
    
     
int CollisionPerfectPixelRightEgypt(Egypt *egypt,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               
              X[0]=perso->pos_perso_ecran.x+93+egypt->pos_map2_affiche.x;
              X[1]=perso->pos_perso_ecran.x+93+egypt->pos_map2_affiche.x;
              X[2]=perso->pos_perso_ecran.x+93+egypt->pos_map2_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+140+egypt->pos_map2_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+81+egypt->pos_map2_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+12+egypt->pos_map2_affiche.y;
		
       while ( i<3 && collision==0)
     {
       color=GetPixelEgypt(egypt,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else
           i++;


      }
      if (collision==0) 
       {
 
         return(0);
       }
}


          


int CollisionPerfectPixelLeftEgypt(Egypt *egypt,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               
              X[0]=perso->pos_perso_ecran.x+egypt->pos_map2_affiche.x;
              X[1]=perso->pos_perso_ecran.x+egypt->pos_map2_affiche.x;
              X[2]=perso->pos_perso_ecran.x+egypt->pos_map2_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+140+egypt->pos_map2_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+81+egypt->pos_map2_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+12+egypt->pos_map2_affiche.y;
		
       while ( i<3 && collision==0)
     {
       color=GetPixelEgypt(egypt,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else
           i++;
  
         
      }
      if (collision==0) 
       {
 
         return(0);
       }
         
                                  
}                        
 
int CollisionPerfectPixelUpEgypt(Egypt *egypt,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               
              X[0]=perso->pos_perso_ecran.x+egypt->pos_map2_affiche.x;
              X[1]=perso->pos_perso_ecran.x+46+egypt->pos_map2_affiche.x;
              X[2]=perso->pos_perso_ecran.x+93+egypt->pos_map2_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+egypt->pos_map2_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+egypt->pos_map2_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+egypt->pos_map2_affiche.y;
		
       while ( i<3 && collision==0)
     {
       color=GetPixelEgypt(egypt,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else
           i++;


      }
      if (collision==0) 
       {
 
         return(0);
       }

    
}


SDL_Color GetPixelJapan(Japan *japan,int x,int y)
{
SDL_Color color;

Uint32 col=0;
Uint8 *pixel = (Uint8 *)japan->Map3_Calque->pixels + (y * japan->Map3_Calque->pitch) + (x * japan->Map3_Calque->format->BytesPerPixel);
memcpy(&col,pixel,japan->Map3_Calque->format->BytesPerPixel);
SDL_GetRGB(col,japan->Map3_Calque->format,&color.r,&color.g,&color.b);
return(color);
}



int CollisionPerfectPixelJapan(Japan *japan,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               X[0]=perso->pos_perso_ecran.x+23+japan->pos_map3_affiche.x;
              X[1]=perso->pos_perso_ecran.x+46+japan->pos_map3_affiche.x;
		X[2]=perso->pos_perso_ecran.x+80+japan->pos_map3_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+162+japan->pos_map3_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+162+japan->pos_map3_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+162+japan->pos_map3_affiche.y;
		
    while ( i<3 && collision==0)
     {
       color=GetPixelJapan(japan,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else
           i++;


      }
      if (collision==0) 
       {
 
         return(0);
       }
  
}
    
     
int CollisionPerfectPixelRightJapan(Japan *japan,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               
              X[0]=perso->pos_perso_ecran.x+93+japan->pos_map3_affiche.x;
              X[1]=perso->pos_perso_ecran.x+93+japan->pos_map3_affiche.x;
              X[2]=perso->pos_perso_ecran.x+93+japan->pos_map3_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+140+japan->pos_map3_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+81+japan->pos_map3_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+12+japan->pos_map3_affiche.y;
		
       while ( i<3 && collision==0)
     {
       color=GetPixelJapan(japan,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else
           i++;


      }
      if (collision==0) 
       {
 
         return(0);
       }
}
          

    


int CollisionPerfectPixelLeftJapan(Japan *japan,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               
              X[0]=perso->pos_perso_ecran.x+japan->pos_map3_affiche.x;
              X[1]=perso->pos_perso_ecran.x+japan->pos_map3_affiche.x;
              X[2]=perso->pos_perso_ecran.x+japan->pos_map3_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+140+japan->pos_map3_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+81+japan->pos_map3_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+12+japan->pos_map3_affiche.y;
		
       while ( i<3 && collision==0)
     {
       color=GetPixelJapan(japan,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else
           i++;
  
         
      }
      if (collision==0) 
       {
 
         return(0);
       }
         
                                  
}                         
 
int CollisionPerfectPixelUpJapan(Japan *japan,Perso *perso)
{  int collision=0,i=0,X[3],Y[3];
   SDL_Color color;
                //little change for collision with background
               
              X[0]=perso->pos_perso_ecran.x+japan->pos_map3_affiche.x;
              X[1]=perso->pos_perso_ecran.x+46+japan->pos_map3_affiche.x;
              X[2]=perso->pos_perso_ecran.x+93+japan->pos_map3_affiche.x;
		Y[0]=perso->pos_perso_ecran.y+japan->pos_map3_affiche.y;
		Y[1]=perso->pos_perso_ecran.y+japan->pos_map3_affiche.y;
		Y[2]=perso->pos_perso_ecran.y+japan->pos_map3_affiche.y;
		
       while ( i<3 && collision==0)
     {
       color=GetPixelJapan(japan,X[i],Y[i]);
     
       if (color.r==50 && color.g==0  && color.b==0 )
        {
           return 1;
           collision=1;

        }
         else                
           i++;


      }
      if (collision==0) 
       {
 
         return(0);
       }

    
}





