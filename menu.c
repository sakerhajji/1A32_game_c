
#include "image.h"

#define Texte_H



void load_image (img im [], int *n )
{
    /**********************************/
    im[1].m=IMG_Load("button/menu.jpg");
    im[1].p.x= 0 ;
    im[1].p.y=0 ;
    /**********************************/
    im[2].m=IMG_Load("button/play.png");
    im[2].p.x= 80,6784 ;
    im[2].p.y=150,000  ;
    /**********************************/
    im[3].m=IMG_Load ("button/op.png") ;
    im[3].p.x= 110 ;
    im[3].p.y= 300 ;
    /**************************************/
    im[4].m=IMG_Load ("button/ab.png") ;
    im[4].p.x= 95 ;
    im[4].p.y=400 ;
    /**************************************/
    im[5].m=IMG_Load ("button/qt.png") ;
    im[5].p.x= 135 ;
    im[5].p.y= 500;
    /*******************************************/
    *n= 5 ;
}
void load_imageb (img im [], int *n )
{

    im[1].m=IMG_Load("button/playc.png");
    im[1].p.x= 80,6784 ;
    im[1].p.y=150,000  ;
    /**********************************/
    im[2].m=IMG_Load ("button/opc.png") ;
    im[2].p.x= 110 ;
    im[2].p.y= 300 ;
    /**************************************/
    im[3].m=IMG_Load ("button/abc.png") ;
    im[3].p.x= 95 ;
    im[3].p.y=400 ;
    /**************************************/
    im[4].m=IMG_Load ("button/qtc.png") ;
    im[4].p.x= 135 ;
    im[4].p.y= 500;
    /*******************************************/
    *n= 4 ;
}
void setting_load_gg (img *bg  )
{
    bg->m=IMG_Load("button/setting.png") ;
    bg->p.x=0;
    bg->p.y=0 ;





}


void affichage(SDL_Surface *img,SDL_Surface *screen,SDL_Rect background_pos)
{
    SDL_BlitSurface(img,NULL,screen,&background_pos);
    SDL_Flip(screen);
}

void affiche_all (img mg [], SDL_Surface * ecran,int n )
{
    for (int i = 1 ; i <= n ; i ++ )
    {
        affichage(mg[i].m,ecran,mg[i].p);
    }
}

void afficherb (img p [], SDL_Surface *ecran, int n, int sof)
{
    for (int i = 1 ; i <= n ; i ++ )
    {
        if (i!=sof)
        {
            SDL_BlitSurface (p[i].m,NULL,ecran,&p[i].p) ;
            SDL_Flip(ecran) ;
        }
        else continue ;
    }

}

void librer (img im [],int n)
{
    for (int i = 1 ; i<= n ; i ++)
        SDL_FreeSurface(im[i].m) ;
}
