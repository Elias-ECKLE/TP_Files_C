#include "header.h"


int main(int argc,char *argv[])
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


    //Afficher la taille de la file------------------------------------------------------------------- :
    printf("\n La taille de la file est de : %d\n\n",getTailleFile(myFile));


    //consulter le premier et dernier élément de la file------------------------------------------------:
    char* donnee=NULL;
    donnee=getFirstElement(myFile);
    printf("Le premier element de la file est : %s\n",donnee);
    donnee=getLastElement(myFile);
    printf("Le dernier element de la file est : %s\n\n",donnee);





    //Dépiler (libérer la mémoire)--------------------------------------------------------------------
    if(depiler(myFile)==1){
        printf("File depilee OK\n");
    }

    //libérer les pointeurs restants----------------------------------------------------------------- :
    free(donnee);
    for(n_i=0; n_i<TailleChaines; n_i++){
        free(tabChaines[n_i]);
    }
    free(tabChaines);





    return 0;
}
int depiler(Pile* file){
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element* elementDepile = file->p_Ending;

    for(int n_i=0; n_i<TailleChaines; n_i++){
        if (file != NULL && file->p_Ending != NULL)
        {
            file->p_Ending = elementDepile->p_before;
            free(elementDepile);
            file->n_taille--;
        }
    }
    free(file);
    return 1;
}

