#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 1000
#define SCREEN_H 600

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

void InitHero(Hero *A);
void MoveHero(Hero *A);
void FreeHero(Hero *A);



#endif
