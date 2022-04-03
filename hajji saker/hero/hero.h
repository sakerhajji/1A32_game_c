#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>

#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

typedef struct
{
    SDL_Rect position, PosHP;
    SDL_Surface *image[10], *HP;
    Mix_Chunk *Walk;
    Mix_Chunk *Jump;
    Mix_Chunk *Attack;
    int vie;
    int moving;    //0:Not moving 1:moving
    int direction; //0:right 1:left 2:attack
} Hero;


#endif // HERO_H_INCLUDED
