#include "ennemi.h"
void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

int main (void)
{Ennemi e;
int col;
SDL_Surface *screen =NULL;
SDL_Surface *background=NULL;
SDL_Rect posbackground;
SDL_Rect posp;
SDL_Init(SDL_INIT_VIDEO);

screen = SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
background=IMG_Load("bg.png");

initEnnemi(&e);

posbackground.x=0;
posbackground.y=0;

posp.x=500;
posp.y=423;

SDL_BlitSurface(background,NULL,screen,&posbackground);
SDL_Flip(screen);

afficherEnnemi(e,&screen);
animerEnnemi(&e);
deplacer(&e);
col=collisionBB(posp,e.posenemy);



liberer(background);
SDL_Quit();
return 0;
}

