#include "ennemi.h"
void initEnnemi(Ennemi *e)
{
int i,j;
  char filename[12],filenem[23];
;
for(i=0;i<11;i++)
{
sprintf(filename,"mouvement/R/%d.png",i);
e->enemr[i] = IMG_Load(filename);

sprintf(filename,"mouvement/L/%d.png",i);
e->eneml[i] = IMG_Load(filename);


e->posenemy.x=895;
e->posenemy.y=423;
}
  for(j=1;j<=23;j++)
{
 sprintf(filenem,"attack/%d.png",j);
e->enemat[j] = IMG_Load(filenem);
}
}
void afficherEnnemi(Ennemi e, SDL_Surface * screen)
{
SDL_BlitSurface(e.enem[],NULL,&screen,&e.posenemy);
SDL_Flip(screen);

}
void animerEnnemi( Ennemi * e,SDL_Rect posp)
{int i=1;
  if((posenemy.x+50 >= posp.x + posp.w)||(posenemy.x+50 + posenemy.w+50 <= posp.x)||(posenemy.y+50 >= posp.y + posp.h)||(posenemy.y+50 + posenemy.h+50 <= posp.y))
  {

{
SDL_BlitSurface(e->enemat[i],NULL,screen,&e->posenemy);
SDL_Delay(100);
SDL_Flip(screen);
  if (i==23) i=1;
     else i++;
  SDL_Flip(screen);

  }
  }
}
void deplacer( Ennemi * e)
{ienem=0;
if(e->posenemy.x>e->posenemy.x-500)
{
SDL_BlitSurface(e->eneml[ienem],NULL,screen,&e->posenemy);
SDL_Delay(100);
SDL_Flip(screen);
e->posenemy.x=e->posenemy.x-5;
  if (ienem==11) ienem=0;
     else ienem ++;
  SDL_Flip(screen);
  }
  else if(e->posenemy.x>=e->posenemy.x-500)
  {
  e->posenemy.x=e->posenemy.x+5;
  SDL_BlitSurface(e->enemr[ienem],NULL,screen,&e->posenemy);
SDL_Delay(100);
SDL_Flip(screen);
  if (ienem==11) ienem=0;
     else ienem ++;
  SDL_Flip(screen);

  }

}
int collisionBB( SDL_Rect posp, SDL_Rect pose);
{
   if((pose.x >= posp.x + posp.w)
	|| (pose.x + pose.w <= posp.x)
	|| (pose.y >= posp.y + posp.h)
	|| (pose.y + pose.h <= posp.y))
          return 0;
   else
          return 1;
}
