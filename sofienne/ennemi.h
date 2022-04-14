#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"


typedef struct
{SDL_Surface *enemr[12];
SDL_Surface *enemrl[12];
SDL_Surface *enemat[23];
SDL_Rect posenemy;

}Ennemi;


void initEnnemi(Ennemi*e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
int collisionBB( SDL_Rect posp, SDL_Rect pose);
void deplacerIA( Ennemi * e, SDL_Rect posPerso);




