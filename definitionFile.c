#include "header.h"




//PROCEDURES & FONCTIONS SDL 2-------------------------------------------------------------------------------------------------------------

   //Init SDL---------------------------------------------------------------


void SDL_Initialisation(int window_width, int window_height){

    //INIT SDL________________________________________________________________________________________________________________
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){

        SDL_Log("Unable to initialize : %s",SDL_GetError());
        return 1; //il y a un probleme on retourne 1
    }
    else{ //creation de la fenetre : afficher fenetre graphique : 0,0 position coin gauche, ensuite taille et enfin l'afficher

        pWindow=SDL_CreateWindow("Map du jeu graphique",10,50,window_width,window_height,SDL_WINDOW_OPENGL);
        if(pWindow){ //creation du rendu : si la fenetre est bien crée alors
            pRenderer=SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
        }
    }
}


void SDL_InitImg(){
        //initialisation des flags (comme au dessus) avec les img
    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
        int initted=IMG_Init(flags);
        if((initted&flags)!=flags){
             SDL_Log("IMG_Init:Failed to init required jpg and png support !\n");
             SDL_Log("IMG_Init: %s\n", IMG_GetError());
             return 1;
        }
}


void SDL_NettoieEcran(){

    SDL_RenderClear(pRenderer);
    SDL_SetRenderDrawColor(pRenderer,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderPresent(pRenderer);

}











//PROCEDURES & FONCTIONS FILE--------------------------------------------------------------------------------------------------------------
//BUT : initialiser et allouer de la mémoire au pointeur file
//ENTREE: Rien
//SORTIE : mémoire allouée
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

//BUT:Initiailiser les pointeurs p_beginning et p_ending, et insérer le premier élément de la pile
//ENTREE : file et l'élément à insérer
//SORTIE: entier qui permet de savoir si l'initialisation s'ets bien passée ou non
int insertPileVide(Pile* file, SDL_Texture* texture2D){
    Element* elmt=NULL;
    elmt=(Element*)malloc(sizeof(Element*));

    if(file!=NULL && elmt!=NULL){

        elmt->texture2D=texture2D;
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





//BUT:insérer un élément dans la file, toujours par dessus le précédent afin de créer un effet d'empilation
//ENTREE: file & élément à insérer
//SORTIE:RAS

void empiler(Pile* file, SDL_Texture* texture2D){

    Element* elmt=NULL;
    elmt=(Element*)malloc(sizeof(Element*));

    if(file==NULL || elmt==NULL){
        exit(EXIT_FAILURE);
    }
    else{
        elmt->texture2D=texture2D;
        // printf(" file->ending : %d\n",file->p_Ending);
        elmt->p_before=file->p_Ending;
        file->p_Ending=elmt;
        file->n_taille++;
        //printf(" elmt->donnee : %d\n",elmt->donnee);

       // printf("elmt->p_before : %d\n",elmt->p_before);
        //printf(" file->ending : %d\n",file->p_Ending);
    }
}






//BUT: Afficher l'ensemble de la file en partant d ela fin vers le début
//ENTREE: la file
//SORTIE:RAS
int displayPile(Pile* file, SDL_Renderer* pRenderer){

    if(file!=NULL){
        Element* elmtTemp=file->p_Ending;
        SDL_NettoieEcran();
        while(elmtTemp!=NULL && SDL_PollEvent(&events)){

            SDL_Rect dst_Img={0,0,TAILLE_IMAGE,TAILLE_IMAGE};
            SDL_RenderCopy(pRenderer,elmtTemp->texture2D,NULL,&dst_Img);
            SDL_RenderPresent(pRenderer);
            SDL_Delay(1000);
            SDL_NettoieEcran();
            elmtTemp = elmtTemp->p_before;


                switch (events.type)
                {
                    case SDL_QUIT:
                        isOpen = SDL_FALSE ;
                        break;
                    }

        }
        return 1;
    }
    else{
        exit(EXIT_FAILURE);
    }
}

int displayElement_Selected(SDL_Texture* textureElmt, SDL_Renderer* pRenderer){
    if(textureElmt!=NULL){
        SDL_NettoieEcran();
        SDL_Rect dst_Img={0,0,TAILLE_IMAGE,TAILLE_IMAGE};
        SDL_RenderCopy(pRenderer,textureElmt,NULL,&dst_Img);
        SDL_RenderPresent(pRenderer);

        SDL_Delay(3000);
        SDL_NettoieEcran();
        return 1;

    }
}





//BUT:Obtenir la taille de la file
//ENTREE:file
//SORTIE: entier représentant la taille

int getTailleFile(Pile* file){
    int n_taille;
    n_taille=file->n_taille;

    return n_taille;
}

//BUT:Récupérer le premier élément de la file
//ENTREE: file
//SORTIE:pointeur char
SDL_Texture* getFirstElement(Pile* file){
    return file->p_beginning->texture2D;
}

//BUT:Récupérer le dernier élément de la file
//ENTREE: file
//SORTIE:pointeur char
SDL_Texture* getLastElement(Pile* file){
    return file->p_Ending->texture2D;
}







//BUT:libérer la mémoire allouée par chaque élément de la file+ la file en elle-même
//ENTREE: la file
//SORTIE: entier qui permet de savoir si la fil est bien dépilée ou non
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
            SDL_DestroyTexture(elementDepile->texture2D);
            //free(elementDepile);
            file->n_taille--;
        }
    }
    free(file);


    if(pRenderer){
        SDL_DestroyRenderer(pRenderer);
    }
    if(pWindow){
      SDL_DestroyWindow(pWindow);
    }


    return 1;
}

