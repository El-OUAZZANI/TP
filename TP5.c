#include<stdio.h>
#include<stdlib.h>

typedef struct Noeud{
int valeur;
struct Noeud *suivant;
}Node;

void push(Node **top,int valeur){

    if( !(*top) ){
    (*top) = malloc(sizeof(Node));
    (*top) -> suivant = NULL;
    (*top) -> valeur = valeur ;
    }else{
     Node *P = malloc(sizeof(Node));
     P -> valeur = valeur;
     P -> suivant = (*top);
     (*top) = P ;
    }
}

void pop(Node **top){
    Node *P;
    P = (*top);
    (*top) = (*top) -> suivant ;
    free(P);
}

void peek(Node *top){
    if(!(top))
    printf("\n\tSOMMET N'EXISTE PAS\n");
    else
        printf("VALEUR : %d",top->valeur);
}

void afficherPile(Node *top){
    if(!top)
    printf("\n\tPILE VIDE\n");
    else{
        while(top){
            printf("VALEUR : %d\n",top->valeur);
            top = top->suivant;
        }
    }
}

int taille(Node *top){
    int taille = 0 ;

    while(top){
        taille++;
        top = top -> suivant;
    }
    return taille;
}

void Enfiler(Node **ptr,int value){
    
    if(!(*ptr)){
        (*ptr) = malloc(sizeof(Node));
        (*ptr) -> valeur = value ;
        (*ptr) -> suivant = NULL;
    }else{
        Node *p;
        p = (*ptr);
        while(p->suivant != NULL){
            p = p -> suivant;
        }
        p -> suivant = malloc(sizeof(Node));
        p-> suivant -> valeur = value;
       p-> suivant -> suivant = NULL;
    }
}

void Defiler(Node **ptr){

    if(!(*ptr))
    printf("\n\tLISTE VIDE\n");
    else{
        Node *p;
        p = (*ptr);
        (*ptr) = (*ptr) -> suivant;
        free(p);
    }
}

void afficherFile(Node *top){
    while(top){
        printf("VALEUR : %d\n",top->valeur);
        top = top -> suivant;
    }
    }

    void viderFile(Node **top){
        if(!(*top))
        printf("LISTE VIDE\n");
        else{
            Node *ptr;
            ptr = (*top);
            (*top) = (*top) -> suivant;
            free(ptr);

            while((*top)){
                ptr = (*top);
                (*top) = (*top) -> suivant;
                free(ptr);} }
              
    }

int main(){

//PILE
    Node *P = NULL ;
    push(&P,10);
    push(&P,20);
    push(&P,30);

    afficherPile(P);
    printf("Taille de la pile : %d\n",taille(P));
    pop(&P);
    pop(&P);
    afficherPile(P);


//FILE

Node *Start = NULL;
    Enfiler(&Start,10);
    Enfiler(&Start,20);
    Enfiler(&Start,30);

    afficherFile(Start);

    Defiler(&Start);

    afficherFile(Start);

    viderFile(&Start);

    afficherFile(Start);

    return 0 ;
}
