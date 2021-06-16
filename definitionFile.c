#include "header.h"


//BUT : initialiser et allouer de la m�moire au pointeur file
//ENTREE: Rien
//SORTIE : m�moire allou�e
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

//BUT:Initiailiser les pointeurs p_beginning et p_ending, et ins�rer le premier �l�ment de la pile
//ENTREE : file et l'�l�ment � ins�rer
//SORTIE: entier qui permet de savoir si l'initialisation s'ets bien pass�e ou non
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


//BUT:ins�rer un �l�ment dans la file, toujours par dessus le pr�c�dent afin de cr�er un effet d'empilation
//ENTREE: file & �l�ment � ins�rer
//SORTIE:RAS
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

//BUT: Afficher l'ensemble de la file en partant d ela fin vers le d�but
//ENTREE: la file
//SORTIE:RAS
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


//BUT:Obtenir la taille de la file
//ENTREE:file
//SORTIE: entier repr�sentant la taille
int getTailleFile(Pile* file){
    int n_taille;
    n_taille=file->n_taille;

    return n_taille;
}

//BUT:R�cup�rer le premier �l�ment de la file
//ENTREE: file
//SORTIE:pointeur char
char* getFirstElement(Pile* file){
    return file->p_beginning->donnee;
}

//BUT:R�cup�rer le dernier �l�ment de la file
//ENTREE: file
//SORTIE:pointeur char
char* getLastElement(Pile* file){
    return file->p_Ending->donnee;
}


//BUT:lib�rer la m�moire allou�e par chaque �l�ment de la file+ la file en elle-m�me
//ENTREE: la file
//SORTIE: entier qui permet de savoir si la fil est bien d�pil�e ou non
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
            //free(elementDepile);
            file->n_taille--;
        }
    }
    free(file);
    return 1;
}

