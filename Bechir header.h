#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 1000
#define SCREEN_H 600 
typedef struct 
{

};
typedef struct Background Background ; 

void initBack(Background *b) ;
void afficherBack(Background b , SDL_Surface *screen );
void animerBackground(Background * e);
int collisionPP(Personne p , SDL_Surface * Masque );
void scrolling( Background *b , int direction,int pasAvancement);
// ou bien 
// void scrolling(SDL_Rect *b , int direction , int pasAvancement );  
#endif

