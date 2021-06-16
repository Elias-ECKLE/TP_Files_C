#include <stdio.h>
#include <stdlib.h>
#define TailleChaines 5
#define TailleCar 20


typedef struct Element{

    char* donnee;
    struct Element* p_before;

}Element;

typedef struct Pile{
    struct Element* p_beginning;
    struct Element* p_Ending;

    int n_taille;

}Pile;


Pile* init();
int insertPileVide(Pile* file, char* donnee);
void empiler(Pile* file, char* donnee);
void depiler();
void displayPile(Pile* file);
int getTailleFile(Pile* file);
void getFirstElement();
void getLastElement();




int main()
{
    int n_i=0;

    //pointeur de pointeur de caractères : premier tableau -> pointeurs de caractères  et deuxième tableau -> caractères d'une chaine

    char** tabChaines=(char**)malloc(TailleChaines*sizeof(char*));
    if(tabChaines!=NULL){
        for(n_i=0; n_i<TailleChaines; n_i++){
            tabChaines[n_i]=(char*)malloc(TailleCar*sizeof(char));
        }
    }
    strcpy(tabChaines[0],"Test1");
    strcpy(tabChaines[1],"Test2");
    strcpy(tabChaines[2],"Test3");
    strcpy(tabChaines[3],"Test4");
    strcpy(tabChaines[4],"Test5");




    //init et declaration file ------------------------------------------------------------------:

    Pile* myFile=init();
    if(myFile!=NULL){
        printf("init ok\n");
    }

    //insert du premier élément quand la pile est vide ------------------------------------------------:
    if(insertPileVide(myFile, tabChaines[0])){
        printf("insertPileVide OK\n\n");
    }

    //empiler ----------------------------------------------------------------------------------------:
    for (n_i=1; n_i<TailleChaines; n_i++){
        empiler(myFile,tabChaines[n_i]);
    }



    //Afficher la pile en partant du dernier élément entré --------------------------------------------;
    printf("Liste de la file :\n");
    displayPile(myFile);


    //Afficher la taille de la file :
    printf("\n La taille de la file est de : %d\n",getTailleFile(myFile));


    //Dépiler (libérer la mémoire)--------------------------------------------------------------------






    return 0;
}



Pile* init(){

    Pile* file=NULL;
    file=(Pile*)malloc(sizeof(Pile*));

    if(file){
        file->p_beginning=NULL;
        file->p_Ending=NULL;
        file->n_taille=0;
    }
    return file;
}

int insertPileVide(Pile* file, char* donnee){
    Element* elmt=NULL;
    elmt=(Element*)malloc(sizeof(Element*));

    if(file!=NULL && elmt!=NULL){

        elmt->donnee=donnee;
        elmt->p_before=NULL;
        file->p_beginning=elmt;
        file->p_Ending=elmt;
        file->n_taille++;

        return 1;
    }
    else{
        return 0;
    }
}

void empiler(Pile* file, char* donnee){

    Element* elmt=NULL;
    elmt=(Element*)malloc(sizeof(Element*));

    if(file==NULL || elmt==NULL){
        exit(EXIT_FAILURE);
    }
    else{
        elmt->donnee=donnee;
        // printf(" file->ending : %d\n",file->p_Ending);
        elmt->p_before=file->p_Ending;
        file->p_Ending=elmt;
        file->n_taille++;
        //printf(" elmt->donnee : %d\n",elmt->donnee);

       // printf("elmt->p_before : %d\n",elmt->p_before);
        //printf(" file->ending : %d\n",file->p_Ending);
    }
}


void displayPile(Pile* file){

    if(file!=NULL){
        Element* elmtTemp=file->p_Ending;

        while(elmtTemp!=NULL){
            printf("%s\n", elmtTemp->donnee);
            elmtTemp = elmtTemp->p_before;
        }
    }
    else{
        exit(EXIT_FAILURE);
    }
}


int getTailleFile(Pile* file){
    int n_taille;
    n_taille=file->n_taille;

    return n_taille;
}
/*
void depiler(Pile* file){
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element* elementDepile = file->p_Ending;

    if (file != NULL && file->p_Ending != NULL)
    {
        file->sommet = elementDepile->p_before;
        free(elementDepile);
        pile->taille--;
    }
}
*/
