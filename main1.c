#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
#include <time.h>

void main()
{
	SDL_Surface* screen;
	enigme e;
	SDL_Event event;
	int boucle = 1;
        int interface=4; //interface=4 si enigme;
    	SDL_Init(SDL_INIT_EVERYTHING);
    	SDL_WM_SetCaption("ENIGME", NULL);
    	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	initialiserEnigme(&e);
	genererEnigme(&e);
	Mix_PlayMusic(e.musique_enigme, -1);
	while (boucle==1)
	{
                if(interface==4) //interface de l'enigme
                { 
			animerEnigme(&e);
			afficherEnigme(e,screen);
                }
		if(interface==5) //interface dans le cas de victoire
		{
			interface_win(screen,&boucle,e);
		}
		if(interface==6) //interface dans le cas de l'echec
		{
			interface_lose(screen,&boucle,e);
		}
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT :
					boucle = 0;
					break;
				case SDL_KEYDOWN:
				{
					switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE :
							boucle = 0;
							break;
						case SDLK_p :
							if (e.ReponseCorrecte==0) interface=5;
							else interface=6;
							break;
						case SDLK_a :
							if (e.ReponseCorrecte==1) interface=5;
							else interface=6;
							break;
						case SDLK_z :
							if (e.ReponseCorrecte==2) interface=5;
							else interface=6;
							break;
						case SDLK_e :
							if (e.ReponseCorrecte==3) interface=5;
							else interface=6;
							break;
						case SDLK_r :
							if (e.ReponseCorrecte==4) interface=5;
							else interface=6;
							break;
						case SDLK_t :
							if (e.ReponseCorrecte==5) interface=5;
							else interface=6;
							break;
						case SDLK_y:
							if (e.ReponseCorrecte==6) interface=5;
							else interface=6;
							break;
						case SDLK_u :
							if (e.ReponseCorrecte==7) interface=5;
							else interface=6;
							break;
						case SDLK_i :
							if (e.ReponseCorrecte==8) interface=5;
							else interface=6;
							break;
						case SDLK_o :
							if (e.ReponseCorrecte==9) interface=5;
							else interface=6;
							break;
						
					}

				}
			} 
                }
		SDL_Flip(screen);
		SDL_Delay(40);
	}
	freeEnigme(e);
}