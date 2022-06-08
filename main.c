
#include "image.h"


int main()
{
    img mg [6];
    img mgc [5];
    img aux,bg ;
    aux.m=NULL ;

    int n,nc, start = 1,sof = 0, x=0,st;
    SDL_Event event;
//    SDL_Event event2;
    SDL_Surface *ecran ;
    SDL_Surface *setting ;
    //SDL_Surface * menu;
    ecran=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
    SDL_WM_SetCaption("carthage the lost empire",NULL);
    /*****************************************************/
    load_image ( mg,&n) ;
    affiche_all ( mg, ecran, n);
    load_imageb (mgc,&nc) ;




    /**********************************************/
    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf( "%s",Mix_GetError()) ;
    }
    Mix_Music * music ;

    music = Mix_LoadMUS("music/m.mp3") ;
    Mix_PlayMusic(music,-1) ;
    /**********************************************/
    Mix_Chunk *son;//declaration +changement de son bref
    son= Mix_LoadWAV("music/cc.wav");
    if (son==NULL)
    {
        printf("xxxxxx:%s",Mix_GetError());
    }
//Mix_PlayChannel(-1,son,0);
    /***********************************************/

    /*********************************************/

    while(start)
    {
        SDL_WaitEvent(&event);


        switch(event.type)
        {

        case SDL_QUIT:
            start = 0 ;
            break ;
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
            case SDLK_DOWN :

                if (sof == 4 ) sof = 0 ;
                sof ++ ;
                switch (sof)
                {
                case 1 :
                    mg[x]=aux ;
                    x = sof+1;
                    aux = mg[x];
                    mg[sof+1] = mgc[sof] ;
                    Mix_PlayChannel(-1,son,0);
                    affiche_all ( mg, ecran, n);
                    SDL_Flip(ecran) ;

                    break;
                case 2 :
                    mg[x]=aux ;
                    x = sof+1;
                    aux = mg[x];
                    mg[sof+1] = mgc[sof] ;
                    Mix_PlayChannel(-1,son,0);
                    affiche_all ( mg, ecran, n);
                    SDL_Flip(ecran) ;

                    break;
                case 3 :

                    mg[x]=aux ;
                    x = sof+1;
                    aux = mg[x];
                    mg[sof+1] = mgc[sof] ;
                    Mix_PlayChannel(-1,son,0);
                    affiche_all ( mg, ecran, n);
                    SDL_Flip(ecran) ;

                    break;
                case 4 :
                    mg[x]=aux ;
                    x = sof+1;
                    aux = mg[x];
                    mg[sof+1] = mgc[sof] ;
                    Mix_PlayChannel(-1,son,0);
                    affiche_all ( mg, ecran, n);
                    SDL_Flip(ecran) ;

                    break;

                }
                break;
            case SDLK_RETURN :
                if (sof==4)start = 0 ;
                if (sof==2)
                {

                    setting=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
                    SDL_WM_SetCaption("setting",NULL);
                    setting_load_gg( &bg ) ;
                    affichage(bg.m,ecran,bg.p);
                    SDL_Flip(ecran) ;
                    st = 1 ;
                    while(st)
                    {
                    SDL_BlitSurface(bg.m,NULL,ecran,&bg.p);
                    SDL_Flip(ecran) ;
                        /*********************/
                        SDL_WaitEvent(&event);


                        switch(event.type)
                        {


                        case SDL_KEYDOWN :
                            switch(event.key.keysym.sym)
                            {
                            case SDLK_ESCAPE :
                                st=0;
                                break ;
                            }
                           
                            /********************/
 

                            break ;
                        }

                    }
                     SDL_FreeSurface(setting) ;
                      ecran=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
    SDL_WM_SetCaption("carthage the lost empire",NULL);
    SDL_Flip(ecran) ;
                     
        
    affiche_all ( mg, ecran, n);


                }
                if (sof == 1 ) {
                ecran=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
                SDL_WM_SetCaption("game",NULL);
  game(ecran) ;
                     ecran=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
    SDL_WM_SetCaption("carthage the lost empire",NULL);
    SDL_Flip(ecran) ;
   affiche_all ( mg, ecran, n);
  }
                break;

            case SDLK_ESCAPE:
                start =  0 ;
                break ;
            case SDLK_UP :

                if (sof == 1 ) sof = 5 ;
                sof -- ;
                switch (sof)
                {
                case 1 :
                    mg[x]=aux ;
                    x = sof+1;
                    aux = mg[x];
                    mg[sof+1] = mgc[sof] ;
                    Mix_PlayChannel(-1,son,0);
                    affiche_all ( mg, ecran, n);
                    SDL_Flip(ecran) ;

                    break;
                case 2 :
                    mg[x]=aux ;
                    x = sof+1;
                    aux = mg[x];
                    mg[sof+1] = mgc[sof] ;
                    Mix_PlayChannel(-1,son,0);
                    affiche_all ( mg, ecran, n);
                    SDL_Flip(ecran) ;

                    break;
                case 3 :

                    mg[x]=aux ;
                    x = sof+1;
                    aux = mg[x];
                    mg[sof+1] = mgc[sof] ;
                    Mix_PlayChannel(-1,son,0);
                    affiche_all ( mg, ecran, n);
                    SDL_Flip(ecran) ;

                    break;
                case 4 :
                    mg[x]=aux ;
                    x = sof+1;
                    aux = mg[x];
                    mg[sof+1] = mgc[sof] ;
                    Mix_PlayChannel(-1,son,0);
                    affiche_all ( mg, ecran, n);
                    SDL_Flip(ecran) ;

                    break;

                }
                break;

            }

            break ;
        }


    }

    librer ( mg,n) ;
    librer ( mgc,nc) ;
    SDL_FreeSurface(aux.m) ;
    SDL_FreeSurface(bg.m);
    Mix_FreeMusic(music) ;
    SDL_FreeSurface(ecran) ;
    Mix_FreeChunk(son);
    SDL_QUIT;
    return EXIT_SUCCESS;

}
