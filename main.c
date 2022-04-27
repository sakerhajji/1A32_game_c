#include "enigme.h"
#include "stdio.h"
#include "string.h"
#define SCREEN_W 1000
#define SCREEN_H 600
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>




char nomfichier[10]; 
int main( int argc, char *args[] )
{

 SDL_Surface *correct= NULL ,*faux= NULL ; 
SDL_Rect pos_correct , pos_faux ; 
SDL_Surface *screen=NULL ; 
enigme e ;
char nomfichier[10];  
strcpy(nomfichier,"quest.txt");

correct=IMG_Load("true.png");
faux=IMG_Load("false.png");
pos_correct.x= 250 ;
pos_correct.y= 80 ;

pos_faux.x= 250 ;
pos_faux.y= 80 ; 

SDL_Event event ; 
int  answer=-1 ;
int Result ; 
 int end=1;

SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
screen=SDL_SetVideoMode(1000 ,600 ,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
TTF_Init();

initEnigme( &e ,&nomfichier) ;
afficherEnigme( e, &screen ); 

    while(end == 1)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
  case SDL_QUIT:
            end=0;

            break;
  case SDL_KEYDOWN : 
  { switch (event.key.keysym.sym)
    {   
      case SDLK_a: 
          answer=1 ;
           break ; 
      case SDLK_b: 
          answer=2 ; 
           break ; 
      case SDLK_c: 
          answer= 3 ; 
           break ; 
   } 
      break ; } 
   
       } 
afficherEnigme(&e,&screen ); 
if (answer == e.numCorrAnsw) 
{    Result = 1 ; } 
  else 
{Result =0  ; } 

if ( Result == 1 )
  { SDL_BlitSurface( correct, NULL, screen , &pos_correct) ;
    SDL_Flip(screen) ; 
    end= 0 ; 
  } 
else if (Result ==0 ) 
 {  SDL_BlitSurface(faux , NULL , screen ,&pos_faux ) ;
    SDL_Flip(screen) ;
    end = 0 ;
 }  

//case SDL_MOUSEBUTTONDOWN:
        //{
          //  switch(event.button.button)
            //{
            //case SDL_BUTTON_LEFT:
//if ( event.button.x>200 && event.button.x<200+w && event.button.y>350 && event.button.y<350+H)//je pointe sur la 1ere reponse
free_surface_enigme( &e ) ; 



TTF_Quit() ; 
SDL_Quit() ;
return  EXIT_SUCCESS ;
} 



