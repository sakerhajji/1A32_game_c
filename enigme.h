#ifndef HEADER_H_
#define HEADER_H_
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

typedef struct enigme
{
	char quest[20] ;
	char answ1[20];
	char answ2[20];
	char answ3[20];
	int numCorrAnsw;
        SDL_Surface  *Quest ,*Choice1 ,*Choice2, *Choice3 ,  *Fond ; 
        SDL_Rect posQuest,posAns1,posAns2,posAns3, posFond; 
        int nb_enigme; 
       



}enigme; 


void afficherEnigme(enigme e , SDL_Surface * screen );
void initEnigme(enigme *e , char *nomfichier );
void animer(enigme *e );



#endif
