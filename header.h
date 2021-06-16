#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define TailleChaines 5
#define TailleCar 20

//PROTOTYPES PROCEDURES & FONCTIONS


typedef struct Element{

    char* donnee;
    struct Element* p_before;

}Element;

 typedef struct Pile{
    struct Element* p_beginning;
    struct Element* p_Ending;

    int n_taille;

}Pile;


extern Pile* init();
extern int insertPileVide(Pile* file, char* donnee);
extern void empiler(Pile* file, char* donnee);
extern int depiler(Pile* file);
extern void displayPile(Pile* file);
extern int getTailleFile(Pile* file);
extern char* getFirstElement(Pile* file);
extern char* getLastElement(Pile* file);



#endif // HEADER_H_INCLUDED
