#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

#include <SDL.h>

typedef struct {
    char* question;
    char* reponse1;
    char* reponse2;
    char* reponse3;
    int numbr;
    SDL_Surface* surface_question;
    SDL_Surface* surface_reponse1;
    SDL_Surface* surface_reponse2;
    SDL_Surface* surface_reponse3;
    SDL_Rect pos_question;
    SDL_Rect pos_reponse1;
    SDL_Rect pos_reponse2;
    SDL_Rect pos_reponse3;
    int etat;
} Enigme;

Enigme genererEnigme(char* nomfichier);
void afficherEnigme(Enigme e, SDL_Surface* screen);
void animerEnigme(Enigme* e);
void libererEnigmeTexte(EnigmeTexte* e) 

#endif
