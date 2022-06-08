#include "image.h"

void initBack(Background * b)
{
b->bg[0] = IMG_Load("IMG/bg1.jpg") ;
b->bg[1] = IMG_Load("IMG/bg2.jpg") ;
b->bg[2] = IMG_Load("IMG/bg3.jpg") ;
b->posbg.x = 0 ;
b->posbg.y = 0 ;
}
void aficherBack(Background b, SDL_Surface * screen , int x )
{
SDL_BlitSurface(b.bg[x],NULL , screen , &b.posbg) ;
SDL_Flip(screen) ;
}
void animerBackground( Background * e) ;
//int collisionPP( Personne p, SDL_Surface * Masque) ;
//void scrolling (background * b, int direction, int pasAvancement); soit void scrolling (SDL_Rect * b, int direction ,int pasAvancement);
void bgtask(SDL_Surface *ecran , int x  )
{Background b ;
initBack (&b) ;

//scanf("%d",&x) ;
aficherBack(b,ecran,x);
int paly = 1 ;
    SDL_Event event ;

     while (paly)
    {


        SDL_Flip(ecran) ;
        SDL_WaitEvent(&event) ;
        switch (event.type)
        {
        case SDL_QUIT :
            paly=0 ;
            break ;



        }
    }
    freebg (b) ;
    }

    void freebg(Background e)
    {
    for (int i = 0 ; i <3 ; i ++)
    {
    SDL_FreeSurface(e.bg[i]) ;
    }
    }
