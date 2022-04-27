#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "enigme.h"

void initEnigme( enigme * e , char *nomfichier)
{
 FILE *fic= NULL ; 
  FILE *ficrep = NULL ; 

int char_lu , ligne=1 ;  
TTF_Font *Police=NULL;
TTF_Font *Pquest=NULL;
SDL_Color ColorBlack={0,0,0} ;

e->Quest= NULL; 
e->Choice1= NULL ; 
e->Choice2=NULL ;
e->Choice3=NULL ;  
e->Fond= IMG_Load("fond.png");
e->posFond.x=0 ;
e->posFond.y=0 ;
e->posFond.w=(SCREEN_W ) ;
e->posFond.h= (SCREEN_H); 


Police=TTF_OpenFont("Outrun future.otf",30);
Pquest=TTF_OpenFont("Outrun future.otf",50);

    e->posQuest.x=200; e->posQuest.y=200;
   e->posAns1.x=200; e->posAns1.y=350; // a)
    e->posAns2.x= 400; e->posAns2.y= 450; // b) 
e->posAns3.x= 600 ; e->posAns3.y= 350 ; // c) 


srand(time(NULL)); 


do {
		e->nb_enigme = (rand () %2)+ 1  ;
	}while ( e->nb_enigme <1 || e->nb_enigme > 2 );


fic=fopen("quest.txt","r");
ficrep=fopen("NumCorreAnswr.txt","r");
if  (ficrep != NULL)
     {  
           if (fic!= NULL )  
             {  
         while ( char_lu != EOF && ligne < e->nb_enigme ) 
       {  char_lu= fgetc(fic)  ;
  if (char_lu == " \n " )
              { ligne ++ ;}
       } 
   fscanf(fic," %s  %s %s %s ",  e->quest, e->answ1, e->answ2, e->answ3); 
   fscanf(ficrep,"%d" ,&e->numCorrAnsw ) ;


fclose(fic) ;  fclose(ficrep); 
             }  

     } 

e->Quest=TTF_RenderText_Blended(Pquest, e->quest,ColorBlack);
e->Choice1 =TTF_RenderText_Blended(Police , e->answ1 ,ColorBlack);
e->Choice2 =TTF_RenderText_Blended(Police, e->answ2 ,ColorBlack);
e->Choice3 = TTF_RenderText_Blended(Police, e->answ3 ,ColorBlack);
} 


void afficherEnigme(enigme e, SDL_Surface *screen )
{

SDL_BlitSurface(e.Fond,NULL, screen,  &e.posFond );
SDL_BlitSurface(e.Quest,NULL, screen, &e.posQuest);
SDL_BlitSurface(e.Choice1,NULL, screen, &e.posAns1);
SDL_BlitSurface(e.Choice2,NULL, screen, &e.posAns2);
SDL_BlitSurface(e.Choice3,NULL, screen, &e.posAns3);

SDL_Flip(screen); 
} 
void free_surface_enigme( enigme *e )
{SDL_FreeSurface(e->Fond);
SDL_FreeSurface(correct);
SDL_FreeSurface(faux);
SDL_FreeSurface(e->Choice1);
SDL_FreeSurface(e->Choice2);
SDL_FreeSurface(e->Choice3);
SDL_FreeSurface(e->Quest); 
}


//void initialiseEntity(enigme *e ) 
//{
//(*e).an.(*sprite)=IMG_Load("h1.png");

//(*e).an.posSprite.x=0 ;
//(*e).an.posSprite.y=0;
//posSprite.w=1707/4 ;
//posSprite.h=812/2 ; 
//}


//void animateEntity(enigme *e )
//{ 
//(*e).an.posSprite.y=direc* ( (*e).an.posSprite ) ;

//if ((*e).an.posSprite.x)==(1707-(*e).an.posSprite.w  ) ) //if dernier frame atteint 
//{ (*e).an.posSPrite.x=0 ;  // revenir au premier frame 

//else { (*e).an.posSprite.x=(*e).an.posSprite.x+ (*e).an.posSprite.w ; }
//}   // avancer au frame suivant 





















