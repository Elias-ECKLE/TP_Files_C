#include "header.h"


int main(int argc,char *argv[])
{
    int n_i=0;



     //INIT et declaration file ------------------------------------------------------------------:
    Pile* myFile=init();

    if(myFile!=NULL){
        printf("init ok\n");
    }



    //INIT SDL___________________________________________________________
    pWindow=NULL; //pointeur pointant sur paramètres window
    pRenderer=NULL;//pointeur pointant sur paramètres renderer
    isOpen=SDL_TRUE; //global
    SDL_Initialisation(WINDOW_WIDTH,WINDOW_HEIGHT);
    SDL_InitImg();

    char imageTest1[]=SDL_IMAGE_Test1;
    char imageTest2[]=SDL_IMAGE_Test2;
    char imageTest3[]=SDL_IMAGE_Test3;
    char imageTest4[]=SDL_IMAGE_Test4;
    char imageTest5[]=SDL_IMAGE_Test5;
    int tailleImage=TAILLE_IMAGE;

    SDL_Surface *pSurfaceTest1=NULL;
    SDL_Surface *pSurfaceTest2=NULL;
    SDL_Surface *pSurfaceTest3=NULL;
    SDL_Surface *pSurfaceTest4=NULL;
    SDL_Surface *pSurfaceTest5=NULL;

    SDL_Texture *pTextureTest1=NULL;
    SDL_Texture *pTextureTest2=NULL;
    SDL_Texture *pTextureTest3=NULL;
    SDL_Texture *pTextureTest4=NULL;
    SDL_Texture *pTextureTest5=NULL;

                //LOad images :
    pSurfaceTest1 = IMG_Load(imageTest1);
    pSurfaceTest2= IMG_Load(imageTest2);
    pSurfaceTest3=IMG_Load(imageTest3);
    pSurfaceTest4= IMG_Load(imageTest4);
    pSurfaceTest5= IMG_Load(imageTest5);

    //Si pas de reference
    if((!pSurfaceTest1)||(!pSurfaceTest2)||(!pSurfaceTest3)||(!pSurfaceTest4)|| (!pSurfaceTest5)){
            SDL_Log("Unable to set surface: %s", SDL_GetError());
            return 1;
    }
    else{
        pTextureTest1=SDL_CreateTextureFromSurface(pRenderer,pSurfaceTest1);
        pTextureTest2=SDL_CreateTextureFromSurface(pRenderer,pSurfaceTest2);
        pTextureTest3=SDL_CreateTextureFromSurface(pRenderer,pSurfaceTest3);
        pTextureTest4=SDL_CreateTextureFromSurface(pRenderer,pSurfaceTest4);
        pTextureTest5=SDL_CreateTextureFromSurface(pRenderer,pSurfaceTest5);

        SDL_FreeSurface(pSurfaceTest1);
        SDL_FreeSurface(pSurfaceTest2);
        SDL_FreeSurface(pSurfaceTest3);
        SDL_FreeSurface(pSurfaceTest4);
        SDL_FreeSurface(pSurfaceTest5);
    }







    //insert du premier élément quand la pile est vide ------------------------------------------------:
    if(insertPileVide(myFile, pTextureTest1)){
        printf("insertPileVide OK\n\n");
    }


    //empiler ----------------------------------------------------------------------------------------:

    empiler(myFile,pTextureTest2);
    empiler(myFile,pTextureTest3);
    empiler(myFile,pTextureTest4);
    empiler(myFile,pTextureTest5);






    //consulter le premier et dernier élément de la file------------------------------------------------:
    SDL_Texture* textureNeutre=NULL;
    textureNeutre=getFirstElement(myFile);

    if(textureNeutre!=NULL){

         if(displayElement_Selected(textureNeutre,pRenderer)){
            printf("Le premier element de la file affiche : OK\n");
            }
         textureNeutre=getLastElement(myFile);

         if(displayElement_Selected(textureNeutre,pRenderer)){
            printf("Le dernier element de la file affiche : OK\n");
            }
    }



    //Afficher la pile en partant du dernier élément entré --------------------------------------------;
    if(displayPile((myFile),pRenderer)){
        printf("Toutes les textures de la file se sont bien affichees\n");
    }

    //Afficher la taille de la file------------------------------------------------------------------- :
    printf("\n La taille de la file est de : %d\n\n",getTailleFile(myFile));







    //Dépiler (libérer la mémoire)--------------------------------------------------------------------
    if(depiler(myFile)==1){
        printf("File depilee OK\n");
    }

    //libérer la mémoire allouée restante :
    if(textureNeutre){
        SDL_DestroyTexture(textureNeutre);
    }
    if(pTextureTest1){
        SDL_DestroyTexture(pTextureTest1);
    }
    if(pTextureTest2){
        SDL_DestroyTexture(pTextureTest2);
    }
    if(pTextureTest3){
        SDL_DestroyTexture(pTextureTest3);
    }
    if(pTextureTest4){
        SDL_DestroyTexture(pTextureTest4);
    }
    if(pTextureTest5){
        SDL_DestroyTexture(pTextureTest5);
    }

    IMG_Quit();
    SDL_Quit();




    return 0;
}
