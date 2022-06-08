#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
typedef struct
{
    SDL_Surface *m ;
    SDL_Rect p ;
} img ;
/********************************************************************************/
typedef struct
{
    SDL_Rect position,patt ;/*!< postion of pic. */
    SDL_Surface *image[13],* pic[13] , *pvie[5] ; /*!< 3 surface array of move left ,right and jumb . */
    SDL_Surface *att [24] ; /*!< surface arry of pictures attck */
    int vie; /*!< live of hero. */
    int moving;    /*!< 0:Not moving 1:moving. */
    int direction;  /*!< 0:right 1:left 2:attack. */
} Hero;
/**
* @struct live
* @brief struct for live
*/
typedef struct
{
SDL_Surface *vie [5] ;/*!< live of hero. */
SDL_Rect posv ; /*!< postion of pic. */
}vies ;
/**
* @struct score
* @brief struct for score
*/
typedef struct
{
TTF_Font *font ;/*!< font declaration. */
SDL_Surface *score ; /*!< surface. */
SDL_Rect posc ; /*!< postion of pic. */
SDL_Color cl ;/*!< colore of pic. */
}scoregame ;
/**********************************************************************************************/
typedef struct
{

SDL_Surface * quest_bg;
SDL_Rect quest;
int rep ,n;
SDL_Surface *option[2] ,*optionc[2] ;
SDL_Rect  op[2] ;

}enigme;
/*******************************************************************************************************************/
typedef struct
{
SDL_Surface * bg[4] ;
SDL_Rect  posbg ;
}Background ;
/*******************************************************************************************************************/

void initBack(Background * b) ;
void aficherBack(Background b, SDL_Surface * screen,int x) ;
void animerBackground( Background * e) ;
void bgtask(SDL_Surface *ecran ,int x )   ;
void freebg(Background e);
/*******************************************************************************************************************/

void load_image (img im [], int *n ) ;
void afficher (img *ma, SDL_Surface *ecran ) ;
void affichage(SDL_Surface *img,SDL_Surface *screen,SDL_Rect background_pos) ;
void librer (img im [],int n) ;
void load_imageb (img im [], int *n ) ;
void afficherb (img p [], SDL_Surface *ecran, int nc, int soft) ;
void affiche_all (img mg [], SDL_Surface * ecran,int n) ;
void setting_load_gg (img *bg  ) ;
/**************************************************************************************************************************/
void score_gale (Hero a , scoregame *sc) ;
void vieaffiche  ( Hero a , vies *p , SDL_Surface *ecran) ;
void InitHero(Hero *A);
void InitHero_2(Hero *A);
void MoveHero(Hero *A);
void FreeHero(Hero *A , vies *p);
void jumb (Hero *A, int x );
void game (SDL_Surface *ecran) ;
/**************************************************************************************************************************/
void InitEnigme(enigme * e, char *nomfichier ) ;
void afficherEnigme(enigme e, SDL_Surface * ecran,int x) ;
void freesurface (enigme e) ;
void animer (enigme * e);
void enigmetask (SDL_Surface * ecran) ;
/*******************************************************************************************************************************/
int arduinoWriteData(int x);
int arduinoReadData(int *x);
int checkColli(SDL_Rect a, SDL_Rect b);


#endif // IMAGE_H_INCLUDED
