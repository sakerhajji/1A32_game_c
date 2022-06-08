#include "image.h"

void InitEnigme(enigme * e, char *nomfichier )
{
    strcpy(nomfichier, "text.txt") ;
    FILE *f=NULL, *f1=NULL,*f2=NULL,*f3=NULL, *f4 = NULL ;
    srand(time(0));
    f = fopen(nomfichier,"r");
    f1 = fopen("textop.txt","r");
    f2 = fopen("textopc.txt","r");
    f3 = fopen("textorect.txt","r");
    f4 = fopen("textrep.txt","r");
    e->n= rand() % 3 ;
int x1,x2,y1,y2 ;
    char ch [50], ch1[50], ch2[50],ch2c[50],ch1c[50] ;
    for (int  i = 0 ; i<= e->n ; i ++ )
    {
        fscanf(f,"%s\n",ch) ;
        fscanf(f1,"%s%s\n",ch1,ch2) ;
        fscanf(f2,"%s%s\n",ch1c,ch2c) ;
        fscanf(f3,"%d%d%d%d\n",&x1,&y1,&x2,&y2) ;
        fscanf(f4,"%d\n",&e->rep) ;


    }
    e->quest_bg=IMG_Load(ch) ;
    e->quest.x =0;
    e->quest.y=0 ;
    e->option[0]=IMG_Load(ch1) ;
    e->option[1]=IMG_Load(ch2) ;
    e->optionc[0]=IMG_Load(ch1c) ;
    e->optionc[1]=IMG_Load(ch2c) ;
    e->op[0].x=x1 ;
    e->op[0].y=y1;
    e->op[1].x=x2;
    e->op[1].y=y2 ;
    fclose(f) ;
    fclose(f1) ;
    fclose(f2) ;
    fclose(f3) ;
    fclose(f4) ;
    e->quest_bg=IMG_Load(ch) ;
    e->quest.x =0;
    e->quest.y=0 ;
    e->option[0]=IMG_Load(ch1) ;
    e->option[1]=IMG_Load(ch2) ;
    e->optionc[0]=IMG_Load(ch1c) ;
    e->optionc[1]=IMG_Load(ch2c) ;
    }
    void afficherEnigme(enigme e, SDL_Surface * ecran , int x)
    {
     switch (x)
     {
case 0 :
        SDL_BlitSurface (e.quest_bg, NULL, ecran, &e.quest) ;
        SDL_Flip(ecran) ;
        SDL_BlitSurface (e.option[0], NULL, ecran, &e.op[0]) ;
        SDL_Flip(ecran) ;
        SDL_BlitSurface (e.option[1], NULL, ecran, &e.op[1]) ;
        SDL_Flip(ecran) ;
        break ;
case 1 :
        SDL_BlitSurface (e.quest_bg, NULL, ecran, &e.quest) ;
        SDL_Flip(ecran) ;
        SDL_BlitSurface (e.optionc[0], NULL, ecran, &e.op[0]) ;
        SDL_Flip(ecran) ;
        SDL_BlitSurface (e.option[1], NULL, ecran, &e.op[1]) ;
        SDL_Flip(ecran) ;
        break ;
case 2 :
        SDL_BlitSurface (e.quest_bg, NULL, ecran, &e.quest) ;
        SDL_Flip(ecran) ;
        SDL_BlitSurface (e.option[0], NULL, ecran, &e.op[0]) ;
        SDL_Flip(ecran) ;
        SDL_BlitSurface (e.optionc[1], NULL, ecran, &e.op[1]) ;
        SDL_Flip(ecran) ;
        break ;


    }
}

void freesurface (enigme e)
{
SDL_FreeSurface(e.quest_bg) ;
for (int i = 0 ; i < 2 ; i ++)
{
SDL_FreeSurface(e.option[i]) ;
SDL_FreeSurface(e.optionc[i]) ;
}
}
void enigmetask(SDL_Surface *ecran)
{
enigme e ;
    char nom [50] ;
    int paly = 1 ,  x = 0 ;
    SDL_Event event ;
    //ecran = SDL_SetVideoMode(1000,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF ) ;
    InitEnigme (&e, nom) ;
    afficherEnigme( e,  ecran , x) ;
    while (paly)
    {

    SDL_PollEvent(&event) ;
        switch (event.type)
        {
        case SDL_QUIT :
            paly=0 ;
            break ;
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
            case  SDLK_LEFT :
            x= 1 ;
            afficherEnigme( e,  ecran , x) ;
            break ;
            case  SDLK_RIGHT :
            x= 2 ;
            afficherEnigme( e,  ecran , x) ;
            break ;
            case SDLK_RETURN :
            if (e.rep == x) printf("correct answer \n") , paly = 0  ;
            else printf(" not correct answer \n") ;
            break ;

    }


}
}

 freesurface ( e) ;
 SDL_FreeSurface(ecran) ;


}
