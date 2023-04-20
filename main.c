#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"

int main()
{
    SDL_Surface *screen = NULL;
    int continuer = 1;
    SDL_Event event;

   
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

   
    screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(screen == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir la fenetre : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

   
    TTF_Init();
    TTF_Font *police = NULL;
    police = TTF_OpenFont("arial.ttf", 32);
    if(police == NULL)
    {
        fprintf(stderr, "Impossible de charger la police : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Surface *victoire = IMG_Load("victoire.png");
    SDL_Surface *defaite = IMG_Load("defaite.png");

   
    Enigme e;
    genererEnigme(&e, "eni.txt");


    while(continuer)
    {
       
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    continuer = 0;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            continuer = 0;
                            break;
                        case SDLK_RETURN:
                  
                            if(strcmp(e.reponse, e.propositions[e.indiceReponse]) == 0)
                            {
                               
                                SDL_Rect positionVictoire;
                                positionVictoire.x = 200;
                                positionVictoire.y = 200;
                                SDL_BlitSurface(victoire, NULL, screen, &positionVictoire);
                                SDL_Flip(screen);
                                SDL_Delay(3000);


                                libererEnigme(&e);

                                
                                genererEnigme(&e, "enigme.txt");
                            }
                            else
                            {
                                SDL_Rect positionDefaite;
                                positionDefaite.x = 200;
                                positionDefaite.y = 200;
                                SDL_BlitSurface(defaite, NULL, screen, &positionDefaite);
                                SDL_Flip(screen);
                                SDL_Delay(3000);

                             
                                libererEnigme(&e);

                        
                                genererEnigme(&e, "enigme.txt");
                            }
                            break;
                    }
                    break;
            }
        }
    }

  
    SDL_FreeSurface(victoire);
    SDL_FreeSurface(defaite
}
