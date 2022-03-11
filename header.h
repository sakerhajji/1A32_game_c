#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 1000
#define SCREEN_H 600
typedef struct 
{


};
typedef struct enigme enigme ; 
void afficherEnigme(enigme e , SDL_Surface * screen);
void initEnigme( enigme *e , char * nomfichier ) ;
void animer(enigme * e);
void sauvegarder(personne p , background b , char * nomfichier );
int charger(personne *p , background * b , char *nomfichier);
#endif 