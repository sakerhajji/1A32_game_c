#include <stdio.h>
#include <stdlib.h>
#include "hero.h"


int main()
{
    SDL_Surface *ecran, *image, *prs ;
    int tmp = 175, a = 0 ;
    ecran = SDL_SetVideoMode(1000,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF ) ;
    SDL_WM_SetCaption("preso tache",NULL) ;
    //image = IMG_Load("cc.jpg") ;
    image = IMG_Load ("bg.jpg") ;
    SDL_Rect posimg ;
    posimg.x = 0;
    posimg.y = 0 ;
    SDL_BlitSurface (image,NULL,ecran,&posimg) ;
    SDL_Flip(ecran) ;
    prs = IMG_Load("Layer 1.png") ;
    SDL_Rect posp ;
    posp.y = 400;
    posp.x = 20;
    int paly = 1 ;
    SDL_Event event ;
    SDL_Flip(ecran) ;
    int aux_saut =0 ;

    while (paly)
    {
        SDL_BlitSurface (image,NULL,ecran,&posimg) ;
        SDL_Flip(ecran) ;
        SDL_BlitSurface (prs,NULL,ecran,&posp) ;
        SDL_Flip(ecran) ;
        SDL_WaitEvent(&event) ;
        switch (event.type)
        {
        case SDL_QUIT :
            paly=0 ;
            break ;
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
            case  SDLK_RIGHT :
                posp.x+=60 ;
                if (posp.x>=1021) posp.x = 20 ;
                break ;
            case SDLK_LEFT  :
                posp.x -= 60 ;
                break ;
            case SDLK_UP  :
                aux_saut=posp.y ;
                for (int  i = 0 ; i<30; i ++ )
                {
                    posp.y -= 10 ;
                    SDL_BlitSurface (image,NULL,ecran,&posimg) ;
                    SDL_BlitSurface (prs,NULL,ecran,&posp) ;
                    SDL_Flip(ecran) ;
                }
                //if (SDLK_RIGHT) posp.x+=60 ;
                while (posp.y != aux_saut)
                {
                    posp.y  += 10 ;
                    SDL_BlitSurface (prs,NULL,ecran,&posp) ;
                    SDL_Flip(ecran) ;
                }
                break ;

            }


        }

    }
    printf( " x= %d  y = %d  \n ",posp.x, posp.y) ;
    SDL_FreeSurface(prs) ;
    SDL_FreeSurface(image) ;
    SDL_FreeSurface(ecran) ;
}
