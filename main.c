#include "header.h"


int main()
{
    int n_i=0;

    //pointeur de pointeur de caract�res : premier tableau -> pointeurs de caract�res  et deuxi�me tableau -> caract�res d'une chaine

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

    //insert du premier �l�ment quand la pile est vide ------------------------------------------------:
    if(insertPileVide(myFile, tabChaines[0])){
        printf("insertPileVide OK\n\n");
    }

    //empiler ----------------------------------------------------------------------------------------:
    for (n_i=1; n_i<TailleChaines; n_i++){
        empiler(myFile,tabChaines[n_i]);
    }




    //Afficher la pile en partant du dernier �l�ment entr� --------------------------------------------;
    printf("Liste de la file :\n");
    displayPile(myFile);


    //Afficher la taille de la file------------------------------------------------------------------- :
    printf("\n La taille de la file est de : %d\n\n",getTailleFile(myFile));


    //consulter le premier et dernier �l�ment de la file------------------------------------------------:
    char* donnee=NULL;
    donnee=getFirstElement(myFile);
    printf("Le premier element de la file est : %s\n",donnee);
    donnee=getLastElement(myFile);
    printf("Le dernier element de la file est : %s\n\n",donnee);





    //D�piler (lib�rer la m�moire)--------------------------------------------------------------------
    if(depiler(myFile)==1){
        printf("File depilee OK\n");
    }

    //lib�rer les pointeurs restants----------------------------------------------------------------- :

    free(tabChaines);





    return 0;
}


