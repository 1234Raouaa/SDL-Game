#include "enigme.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void genererEnigme(Enigme *p, char *nomfichier) {
    
    FILE *f = fopen(nomfichier, "r");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n",enigme);
        exit(1);
    }
    int nb_lignes = 0;
    char c;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            nb_lignes++;
        }
    }
    rewind(f);

    
    srand(time(NULL));
    int ligne_aleatoire = rand() % nb_lignes + 1;

    
    char ligne[256];
    for (int i = 0; i < ligne_aleatoire; i++) {
        fgets(ligne, 256, f);
    }


    fclose(f);

   
    char *token = strtok(ligne, ";");
    strcpy(p->question, token);
    token = strtok(NULL, ";");
    strcpy(p->reponse_juste, token);

  
    p->etat = 0;

    
    p->police = TTF_OpenFont("arial.ttf", 24);
    p->couleur = {255, 255, 255}; 

    p->surface_question = TTF_RenderText_Solid(p->police, p->question, p->couleur);
    p->surface_reponse_juste = TTF_RenderText_Solid(p->police, p->reponse_juste, p->couleur);

 
    p->position_question.x = 100;
    p->position_question.y = 100;
    p->position_reponse_juste.x = 100;
    p->position_reponse_juste.y = 150;
}

void animerEnigme(Enigme * e) {
    SDL_Surface *background = IMG_Load("fond.jpg"); 
    SDL_Surface *texte_question = NULL;
    SDL_Rect position_background;
    SDL_Rect position_question;
    SDL_Event event;
    int continuer = 1;
    position_background.x = 0;
    position_background.y = 0;
    position_question.x = 50;
    position_question.y = 50;

    TTF_Font *police = TTF_OpenFont("arial.ttf", 25);
    char question[100];
    sprintf(question, "Question : %s", e->question);
    SDL_Color color = {255, 255, 255}; 
    texte_question = TTF_RenderText_Blended(police, question, color);
    SDL_BlitSurface(texte_question, NULL, background, &position_question);
    SDL_BlitSurface(background, NULL, ecran, &position_background);
    SDL_Flip(ecran);
    while (continuer) {
        SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE) {
                    continuer = 0;
                }
                break;
        }
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(texte_question);
    TTF_CloseFont(police);
}
void afficherEnigme(Enigme e, SDL_Surface * screen) {
    SDL_Event event;
    TTF_Font *font;
    SDL_Color color;
    SDL_Surface *question_surface = NULL, *reponse_surface1 = NULL, *reponse_surface2 = NULL, *reponse_surface3 = NULL, *reponse_surface4 = NULL;
    SDL_Rect question_position, reponse1_position, reponse2_position, reponse3_position, reponse4_position;
    int continuer = 1, reponse = 0;
    
   
    font = TTF_OpenFont("arial.ttf", 30);
    color.r = 255;
    color.g = 255;
    color.b = 255;

 
    question_surface = TTF_RenderText_Solid(font, e.question, color);
    reponse_surface1 = TTF_RenderText_Solid(font, e.reponses[0], color);
    reponse_surface2 = TTF_RenderText_Solid(font, e.reponses[1], color);
    reponse_surface3 = TTF_RenderText_Solid(font, e.reponses[2], color);
    reponse_surface4 = TTF_RenderText_Solid(font, e.reponses[3], color);

   
    question_position.x = 100;
    question_position.y = 100;
    reponse1_position.x = 100;
    reponse1_position.y = 200;
    reponse2_position.x = 300;
    reponse2_position.y = 200;
    reponse3_position.x = 100;
    reponse3_position.y = 250;
    reponse4_position.x = 300;
    reponse4_position.y = 250;

  
    while (continuer) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_1:
                        reponse = 1;
                        continuer = 0;
                        break;
                    case SDLK_2:
                        reponse = 2;
                        continuer = 0;
                        break;
                    case SDLK_3:
                        reponse = 3;
                        continuer = 0;
                        break;
                    case SDLK_4:
                        reponse = 4;
                        continuer = 0;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }

        SDL_BlitSurface(question_surface, NULL, screen, &question_position);
        SDL_BlitSurface(reponse_surface1, NULL, screen, &reponse1_position);
        SDL_BlitSurface(reponse_surface2, NULL, screen, &reponse2_position);
        SDL_BlitSurface(reponse_surface3, NULL, screen, &reponse3_position);
        SDL_BlitSurface(reponse_surface4, NULL, screen, &reponse4_position);
        SDL_Flip(screen);
    }

  
    if (reponse == e.reponse_juste) {
        printf("Bonne réponse !\n");
    }
void libererEnigmeTexte(EnigmeTexte* e) {
    if (e != NULL) {
        if (e->question != NULL) {
            free(e->question);
            e->question = NULL;
        }
        if (e->reponses != NULL) {
            for (int i = 0; i < e->nbReponses; i++) {
                if (e->reponses[i] != NULL) {
                    free(e->reponses[i]);
                    e->reponses[i] = NULL;
                }
            }
            free(e->reponses);
            e->reponses = NULL;
        }
        free(e);
        e = NULL;
    }
}
