#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "perso.h"

typedef struct 
{
	SDL_Surface *pause,*sure,*quit,*quit1,*save,*save1,*quit_and_save,*quit_no_save,*quit_sous_menu;
	SDL_Rect pos_pause,pos_quit,pos_save,position[3];
}saving;

void sauvegarder (hero c,int b,char fich[],SDL_Surface *screen);
int charger (hero *c,int *b,char save[],SDL_Surface *screen);
