/**
hero task created by MR Hajji Saker
* @file prso_function.c
* @brief testin program
* @author saker
* @version 1.0.0
* @date year 2022

*/
#include "image.h"
/**
* @brief To show hero .
* @param scren the screen
* @param b the background
* @return Nothing
*/

/* !
* ... load of all pictures  ...
*/
void InitHero(Hero *A)
{

    int i;
    char WalkRight[50];
    char walkR0[] = "IMG/perso/R/preso"; // hero derction left pictures
    char png[] = ".png";
    for (i = 0; i < 12; i++)
    {
        sprintf(WalkRight, "%s%d%s", walkR0, i+1, png);
        A->image[i] = IMG_Load(WalkRight);
    }

    A->position.x = 14;
    A->position.y = 409 ;

    char Walkleft [50] ;
    char walkR1[] = "IMG/perso/L/preso" ;
    for  (i=0 ; i< 12  ; i ++)
    {

        sprintf(Walkleft,"%s%d%s",walkR1, i+1, png ) ;
        A->pic[i]=IMG_Load(Walkleft) ;// hero derction right   pictures

    }
    A->vie = 3 ;
    A->moving = 0 ;
    A->direction = 0 ;

    char attack [50];
    char attck3[]="IMG/perso/A/effect-10" ;
    for (i=0; i<23; i++)
    {
        sprintf(attack,"%s%d%s",attck3,i,png) ;
        A->att[i] = IMG_Load(attack) ; // hero derction attck   pictures
    }

}
/**
* @brief To show live of hero .
* @param scren the screen
* @param b the background
* @return Nothing
*/

/* !
* ... live of hero   ...
*/
void InitHero_2(Hero *A)
{

    int i;
    char WalkRight[50];
    char walkR0[] = "IMG/perso1/R/Layer "; // hero derction left pictures
    char png[] = ".png";
    for (i = 0; i < 26; i++)
    {
        sprintf(WalkRight, "%s%d%s", walkR0, i+1, png);
        A->image[i] = IMG_Load(WalkRight);
    }

    A->position.x = 855;
    A->position.y = 391 ;

    char Walkleft [50] ;
    char walkR1[] = "IMG/perso1/L/Layer ";
    for  (i=0 ; i< 26  ; i ++)
    {

        sprintf(Walkleft,"%s%d%s",walkR1, i+1, png ) ;
        A->pic[i]=IMG_Load(Walkleft) ;// hero derction right   pictures

    }
    A->vie = 3 ;
    A->moving = 0 ;
    A->direction = 1 ;

       char attack [50];
    char attck3[]="IMG/perso1/A/MAIN" ;
    for (i=0; i<18; i++)
    {
        sprintf(attack,"%s%d%s",attck3,i,png) ;
        A->att[i] = IMG_Load(attack) ; // hero derction attck   pictures
    }

}

void vieaffiche ( Hero a, vies *p, SDL_Surface *ecran)
{
    char viech [50] ;
    char viadd []="IMG/vie/v" ; // pictures of live
    char png[] = ".png";
    int i ;

    for (i=0 ; i<4 ; i ++ )
    {
        sprintf(viech,"%s%d%s",viadd,i,png) ;
        p->vie[i] = IMG_Load(viech);
    }
    p->posv.x= 50;
    p->posv.y=35 ;

}
/**
* @brief To show move hero and attack .
* @param scren the screen
* @param b the background
* @return Nothing
*/
/* !
* ... mouve her left right and attack   ...
*/
void MoveHero(Hero *A)
{
    if (A->direction == 0 )
    {
        A->position.x+=1 ;
        if (A->position.x >=1021)
        {
            A->position.x = 20 ;    // left move
            A->vie --  ;
            if (A->vie == 0 ) A->vie=3 ;
        }
    }
    if (A->direction == 1 )
    {
        A->position.x-=1 ;
        if (A->position.x < -3 ) A->position.x = 20 ; // right move
    }

}
/**
* @brief To jumb hero .
* @param scren the screen
* @param b the background
* @return Nothing
*/
/* !
* ... jumb of hero   ...
*/
void jumb (Hero *A, int x ) // jumb move
{

    if (x==1 && A->direction == 0 )
    {
        A->position.y-=10 ;
    }
    if (x==2 && A->direction == 0 )
    {
        A->position.y  += 2 ;
        if (A->position.x<1000)  A->position.x +=3 ;
    }
    if (x==1 && A->direction == 1 )
    {
        A->position.y-=10 ;
    }
    if (x==2 && A->direction == 1 )
    {
        A->position.y  += 2 ;
        if (A->position.x<1000)  A->position.x -=3 ;
    }
}
/**
* @brief To free all surfaces of game .
* @param scren the screen
* @param b the background
* @return Nothing
*/
/* !
* ... free surface of all variables   ...
*/
void FreeHero(Hero *A, vies *p)
{
    for (int i = 0 ; i<12 ;  i ++ )
    {
        SDL_FreeSurface(A->image[i]) ;
        SDL_FreeSurface(A->pic [i]) ;
    }
    for (int  i = 0 ; i < 22 ; i ++)
    {
        SDL_FreeSurface(A->att[i]) ;
    }
    for (int i = 0 ; i< 4 ; i ++)
    {
        SDL_FreeSurface(p->vie[i]) ;
    }
    A->patt.x = 0;
    A->patt.y = 0 ;

}
/**
* @brief To show all task .
* @param scren the screen
* @param b the background
* @return Nothing
*/
/* !
* ... score here game   ...
*/
void score_gale (Hero a, scoregame *sc)
{
    sc->font = TTF_OpenFont("font.ttf",30 )  ;
    sc->posc.x=750;
    sc->posc.y=35 ;
    sc->cl.b=255;
    sc->cl.r=255;
    sc->cl.g=255;

    int x = 0 ;
    char ch [50] ;
    switch (a.vie)
    {
    case 0 :
        x=0 ;
        break ;
    case 1 :
        x=100 ;
        break ;
    case 2 :
        x = 500 ;
        break ;
    case 3 :
        x= 1000 ;
        break ;
    }
    char ch1[] = "scoure : " ;
    sprintf(ch,"%s%d",ch1,x) ;

    sc->score=TTF_RenderText_Solid(sc->font,ch,sc->cl) ;


}

/* !
* ... game main   ...
*/
int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}

int arduinoReadData(int *x)
{
int y ;
    char chemin[]="/dev/ttyUSB0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x  );

    fclose(f);

    return(*x);
}

int checkColli(SDL_Rect a, SDL_Rect b)
{
if ( (a.x >=b.x-100) && (a.x <=b.x-50) ) return 1 ;
else if ( (a.x >= b.x+50) &&  (a.x <=b.x+100) ) return 2 ;
else return 0 ;



}
/*************************************preso game ******************/

void  game (SDL_Surface *ecran) //game main
{
system("stty -F /dev/ttyUSB0 9600 -parenb cs8 -cstopb");
    /***********************declartion***************************/
    SDL_Surface  *bg = NULL ;
    SDL_Rect posbg ;
    Hero p, pr ;
    int paly = 1 ;
    SDL_Event event ;
    const Uint8 *state = SDL_GetKeyState(NULL);
    int  i = 0,aux_saut = 0,j=0 , test =0;
    vies a,b;
    int cal ;
    scoregame sc;
    TTF_Init() ;
    Background bg1 ;
    initBack (&bg1) ;
    int np=0 ;
    int test1 =0,m,test2=0;
    /***************************************************/
    ecran = SDL_SetVideoMode(1000,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF ) ;
    SDL_WM_SetCaption("preso tache",NULL) ;
    InitHero( &p);
    initBack (&bg1) ;
    aficherBack(bg1,ecran,np);
    SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
    SDL_Flip(ecran) ;
    vieaffiche  ( p, &a,  ecran) ;
    InitHero_2( &pr);
    SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
    SDL_Flip(ecran) ;

    while (paly)
    {
    SDL_PollEvent(&event) ;
      score_gale ( p, &sc) ;
        SDL_BlitSurface (sc.score,NULL, ecran,&sc.posc) ;
        SDL_Flip(ecran) ;
        SDL_BlitSurface (sc.score,NULL, ecran,&sc.posc) ;
        SDL_Flip(ecran) ;
        SDL_BlitSurface (a.vie[3-p.vie],NULL, ecran,&a.posv) ;
        SDL_Flip(ecran) ;
         pr.patt.x = pr.position.x +12  ;
test1 = arduinoReadData(&test1) ;
test2 = checkColli(p.position,pr.position) ;
SDL_WaitEvent(&event) ;
switch (test1)
{
case 1 :
p.direction= 0  ;
 m = 10 ;


MoveHero( &p) ;

aficherBack(bg1,ecran,np);
    SDL_Flip(ecran) ;
    SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
    SDL_Flip(ecran) ;
    vieaffiche  ( p, &a,  ecran) ;
    SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
    SDL_Flip(ecran) ;



break ;
case 2 :
p.direction= 1  ;
 m = 10 ;


MoveHero( &p) ;

aficherBack(bg1,ecran,np);
    SDL_Flip(ecran) ;
    SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
    SDL_Flip(ecran) ;
    vieaffiche  ( p, &a,  ecran) ;

    SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
    SDL_Flip(ecran) ;
break ;
case 0 :
break ;


}
arduinoWriteData(test2) ;


        //pr.patt.x = pr.position.x +12  ;


        switch (event.type)
        {
        case SDL_QUIT :
            paly=0 ;
            break ;
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE :
            paly = 0  ;
            break ;
            case  SDLK_RIGHT :
                i++ ;
                if (i==12) i=0 ;
                while(state[SDLK_RIGHT] )
                {
                    i++ ;
                    if (i==12) i=0 ;
                    SDL_PumpEvents() ;
                    p.direction= 0  ;
                    //pr.direction=0 ;
                    SDL_PumpEvents() ;
                    if (state [SDLK_e])
                    {
                        MoveHero( &p) ;
                        if (p.position.x== 1000)
                        {test = 1 ; np ++ ;if (np==3) np = 0 ; }

                        MoveHero( &p) ;
                        if (p.position.x==1000)
                        {test = 1 ; np ++; if (np==3) np = 0 ; }
                        if (test)
                {
                ecran = SDL_SetVideoMode(1000,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF ) ;
                enigmetask (ecran) ;
                test = 0 ;
                     aficherBack(bg1,ecran,np);
    SDL_Flip(ecran) ;
    SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
    SDL_Flip(ecran) ;
    vieaffiche  ( p, &a,  ecran) ;
    SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
    SDL_Flip(ecran) ;
                }

                    }
                    else
                    {
                        MoveHero( &p) ;
                        if (p.position.x== 1000)
                        {test = 1 ; np ++; if (np==3) np = 0 ; }
                        if (test)
                {
                ecran = SDL_SetVideoMode(1000,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF ) ;
                enigmetask (ecran) ;
                test = 0 ;
                    aficherBack(bg1,ecran,np);
    SDL_Flip(ecran) ;
    SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
    SDL_Flip(ecran) ;
    vieaffiche  ( p, &a,  ecran) ;
    SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
    SDL_Flip(ecran) ;
                }
                        // MoveHero( &pr ) ;
                    }
                    aficherBack(bg1,ecran,np);
                    SDL_Flip(ecran) ;
                    SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
                    SDL_Flip(ecran) ;
                    if (pr.direction == 1 )SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
                    else SDL_BlitSurface (pr.image[j],NULL,ecran,&pr.position) ;
                    SDL_Flip(ecran) ;
                    SDL_Flip(ecran) ;

                }
                break ;
            case  SDLK_LEFT :
                i++ ;
                if (i==12) i=0 ;
                while(state[SDLK_LEFT])
                {
                    i++ ;
                    if (i==12) i=0 ;
                    p.direction=1 ;


                    SDL_PumpEvents() ;
                    if (state [SDLK_e])
                    {
                        MoveHero( &p) ;
                        MoveHero( &p) ;
                    }
                    else
                    {
                        MoveHero( &p) ;
                        //MoveHero( &pr ) ;
                    }    ;
                    aficherBack(bg1,ecran,np);
                    SDL_Flip(ecran) ;
                    SDL_BlitSurface (p.pic[i],NULL,ecran,&p.position) ;
                    SDL_Flip(ecran) ;
                    if (pr.direction == 1 )SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
                    else SDL_BlitSurface (pr.image[j],NULL,ecran,&pr.position) ;
                    SDL_Flip(ecran) ;
                    SDL_Flip(ecran) ;

                }
                break ;


            case  SDLK_q :
                j++ ;
                if (j==12) j=0 ;
                while(state[SDLK_q])
                {
                    j++ ;
                    if (j==12) j=0 ;

                    pr.direction=1 ;

                    SDL_PumpEvents() ;
                    if (state [SDLK_a])
                    {
                        MoveHero( &pr) ;
                        MoveHero( &pr) ;
                    }
                    else
                    {

                        MoveHero( &pr ) ;
                    }
                    aficherBack(bg1,ecran,np);
                    SDL_Flip(ecran) ;
                    if (p.direction==1)SDL_BlitSurface (p.pic[i],NULL,ecran,&p.position) ;
                    else SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
                    SDL_Flip(ecran) ;
                    SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
                    SDL_Flip(ecran) ;
                    SDL_Flip(ecran) ;

                }
                break ;

            case SDLK_d :
                j++ ;
                if (j==12) j=0 ;
                while(state[SDLK_d])
                {
                    j++ ;
                    if (j==12) j=0 ;

                    pr.direction=0 ;

                    SDL_PumpEvents() ;
                    if (state [SDLK_a])
                    {
                        MoveHero( &pr) ;
                        MoveHero( &pr) ;
                    }
                    else
                    {

                        MoveHero( &pr ) ;
                    }
                    aficherBack(bg1,ecran,np);
                    SDL_Flip(ecran) ;
                    if (p.direction==1)SDL_BlitSurface (p.pic[i],NULL,ecran,&p.position) ;
                    else SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
                    SDL_Flip(ecran) ;
                    SDL_BlitSurface (pr.image[j],NULL,ecran,&pr.position) ;
                    SDL_Flip(ecran) ;
                    SDL_Flip(ecran) ;

                }
                break ;


            case SDLK_UP  :
                aux_saut=p.position.y ;
                while(state[SDLK_UP] )
                {
                    SDL_PumpEvents() ;
                    jumb ( &p, 1 );
                    if(p.position.y<=200) break ;
                    // if (state [SDLK_RIGHT]) p.position.y += 10 ;

                    aficherBack(bg1,ecran,np);
                    SDL_Flip(ecran) ;
                    if (p.direction == 0 )  SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
                    else SDL_BlitSurface (p.pic[i],NULL,ecran,&p.position) ;
                    SDL_Flip(ecran) ;
                    if (pr.direction == 1 )SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
                    else SDL_BlitSurface (pr.image[j],NULL,ecran,&pr.position) ;
                    SDL_Flip(ecran) ;

                }

                while (p.position.y != aux_saut)
                {
                    jumb ( &p, 2 );

                    aficherBack(bg1,ecran,np);
                    SDL_Flip(ecran) ;
                    if (p.direction == 0 )  SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
                    else SDL_BlitSurface (p.pic[i],NULL,ecran,&p.position) ;
                    SDL_Flip(ecran) ;
                    if (pr.direction == 1 )SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
                    else SDL_BlitSurface (pr.image[j],NULL,ecran,&pr.position) ;
                    SDL_Flip(ecran) ;

                }
                break ;
            case SDLK_z  :
                aux_saut=pr.position.y ;
                while(state[SDLK_z] )
                {
                    SDL_PumpEvents() ;
                    jumb ( &pr, 1 );
                    if(pr.position.y<=200) break ;
                    // if (state [SDLK_RIGHT]) p.position.y += 10 ;

                    aficherBack(bg1,ecran,np);
                    SDL_Flip(ecran) ;
                    if (pr.direction == 0 )  SDL_BlitSurface (pr.image[i],NULL,ecran,&pr.position) ;
                    else SDL_BlitSurface (pr.pic[i],NULL,ecran,&pr.position) ;
                    SDL_Flip(ecran) ;
                    if (p.direction == 1 )SDL_BlitSurface (p.pic[j],NULL,ecran,&p.position) ;
                    else SDL_BlitSurface (p.image[j],NULL,ecran,&p.position) ;
                    SDL_Flip(ecran) ;

                }

                while (pr.position.y != aux_saut)
                {
                    jumb ( &pr, 2 );

                    aficherBack(bg1,ecran,np);
                    SDL_Flip(ecran) ;
                    if (pr.direction == 0 )  SDL_BlitSurface (pr.image[i],NULL,ecran,&pr.position) ;
                    else SDL_BlitSurface (pr.pic[i],NULL,ecran,&pr.position) ;
                    SDL_Flip(ecran) ;
                    if (p.direction == 1 )SDL_BlitSurface (p.pic[j],NULL,ecran,&p.position) ;
                    else SDL_BlitSurface (p.image[j],NULL,ecran,&p.position) ;
                    SDL_Flip(ecran) ;

                }
                break ;

            case SDLK_SPACE   :
                p.patt.x = p.position.x -12  ;
                p.patt.y=-30   ;


                int j = 0 ;

                while (j<13)
                {
                    aficherBack(bg1,ecran,np);
                    SDL_Flip(ecran) ;
                    if (pr.direction == 1 )SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
                    else SDL_BlitSurface (pr.image[j],NULL,ecran,&pr.position) ;
                    SDL_Flip(ecran) ;
                    SDL_BlitSurface (p.att[j], NULL, ecran, &p.patt) ;

                    SDL_Flip (ecran) ;
                    SDL_Flip (ecran) ;
                    SDL_Delay(25);
                    j++ ;
                }
                aficherBack(bg1,ecran,np);
                SDL_Flip(ecran) ;
                if (pr.direction == 1 )SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
                    else SDL_BlitSurface (pr.image[j],NULL,ecran,&pr.position) ;
                    SDL_Flip(ecran) ;
                SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
                SDL_Flip(ecran) ;
                break ;
                case SDLK_s   :
          p.patt.x = p.position.x -12  ;
                p.patt.y=-30   ;

                int w = 0 ;

                while (w<18)
                {
                    aficherBack(bg1,ecran,np);
                    SDL_Flip(ecran) ;
                    if (pr.direction == 1 )SDL_BlitSurface (p.pic[i],NULL,ecran,&p.position) ;
                    else SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
                    SDL_Flip(ecran) ;
                    SDL_BlitSurface (pr.att[w], NULL, ecran, &pr.patt) ;

                    SDL_Flip (ecran) ;
                    SDL_Flip (ecran) ;
                    SDL_Delay(25);
                    w++ ;
                }
                aficherBack(bg1,ecran,np);
                SDL_Flip(ecran) ;
                if (pr.direction == 1 )SDL_BlitSurface (p.pic[i],NULL,ecran,&p.position) ;
                    else SDL_BlitSurface (p.image[i],NULL,ecran,&p.position) ;
                    SDL_Flip(ecran) ;
                SDL_BlitSurface (pr.pic[j],NULL,ecran,&pr.position) ;
                SDL_Flip(ecran) ;

                break ;



            }
            break ;


        }

    }

    SDL_FreeSurface(bg) ;
    FreeHero(&p,&a);
    FreeHero(&pr,&b);


}
