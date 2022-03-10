#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 1000
#define SCREEN_H 600

struct minimap
{
	SDL_Surface* mini_map;
	SDL_Rect pos_minimap;
	SDL_Surface* mini_hero;
	SDL_Rect pos_minihero;
	
	
};
typedef struct minimap minimap; 


void init_minimap(minimap* mp);
void blit_minimap( minimap* mp,SDL_Surface *screen);
void dep_mini_hero (SDL_Rect* pos_perso,minimap mp , SDL_Rect camera,int redimensionnement,int sens);
void free_minimap(minimap* mp);


#endif
