#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h> //on implémente le fichier h correspondant a la bibilio SDL
#include <SDL2/SDL_image.h>

#define TailleChaines 5
#define TailleCar 15

//SDL Window
#define TAILLE_IMAGE 256 //256px par 256px
#define WINDOW_WIDTH  TAILLE_IMAGE
#define WINDOW_HEIGHT TAILLE_IMAGE
//SDL declaration pointeurs :
SDL_Window *pWindow; //pointeur pointant sur paramètres window
SDL_Renderer *pRenderer;//pointeur pointant sur paramètres renderer
SDL_Event events;
SDL_bool isOpen;

//images utilisées pour l'affichage:
#define SDL_IMAGE_Test1 "images/imagesSDL/suiteDeChiffres/chiffre1.png"
#define SDL_IMAGE_Test2 "images/imagesSDL/suiteDeChiffres/chiffre2.png"
#define SDL_IMAGE_Test3 "images/imagesSDL/suiteDeChiffres/chiffre3.png"
#define SDL_IMAGE_Test4 "images/imagesSDL/suiteDeChiffres/chiffre4.png"
#define SDL_IMAGE_Test5 "images/imagesSDL/suiteDeChiffres/chiffre5.png"







//PROTOTYPES PROCEDURES & FONCTIONS


typedef struct Element{

    SDL_Texture* texture2D;
    struct Element* p_before;

}Element;

 typedef struct Pile{
    struct Element* p_beginning;
    struct Element* p_Ending;

    int n_taille;

}Pile;


extern void SDL_Initialisation(int window_width, int window_height);
extern void SDL_InitImg();
extern void SDL_NettoieEcran();

extern Pile* init();
extern int insertPileVide(Pile* file, SDL_Texture* texture2D);
extern void empiler(Pile* file, SDL_Texture* texture2D);
extern int depiler(Pile* file);
extern int displayPile(Pile* file, SDL_Renderer* pRenderer);
extern int displayElement_Selected(SDL_Texture* textureElmt, SDL_Renderer* pRenderer);
extern int getTailleFile(Pile* file);
extern SDL_Texture* getFirstElement(Pile* file);
extern SDL_Texture* getLastElement(Pile* file);



#endif // HEADER_H_INCLUDED
