#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Noeud{
    int valeur;
    struct Noeud *suivant ;
}Noeud ;

Noeud* cree(int valeur){
    Noeud *New ;
    New = malloc(sizeof(Noeud));
    New -> suivant = NULL ;
    New -> valeur =  valeur ;
    return New ;
}
void affiche(Noeud *debut){
    if(debut == NULL){
        printf("Liste vide\n");
        return ;
    }
    while(debut){
        printf("\t%d\n",debut->valeur);
        debut = debut -> suivant ;
    }
}
Noeud *ajouterD(Noeud *debut,int valeur){

    Noeud *New ;
    New = cree(valeur) ;
    New -> suivant = debut ;
    debut = New;
    return debut ;
}
Noeud* ajouterF(Noeud *debut,int valeur){

    Noeud *New , *temp ;
    temp = debut ;
    New = cree(valeur);
    if(debut == NULL){
       return ajouterD(debut,valeur);
    }
    while(temp->suivant != NULL) {
        temp = temp -> suivant ;
    }

    temp -> suivant = New ;
    return debut ;

}
int taille(Noeud *debut){
    if(!debut)
    return 0 ;
    int c = 0 ; 
    while(debut!= NULL){
        c++ ;
        debut = debut -> suivant ;
    }
    return c ;
}

Noeud* insertion(Noeud *debut, int pos, int valeur){
    if(pos == 1)
    return ajouterD(debut,valeur) ;

if(debut == NULL){
printf("liste vide\n");
return NULL ;}

Noeud *prev,*next ;
prev = debut ;
next = debut -> suivant ;


for(int a = 2 ; a < pos ; a ++){
    if(next == NULL){
        printf("nombre de noeuds < %d\n",pos) ;
        return debut ;
    }
    prev = next ;
    next = next -> suivant ;
}

prev -> suivant = cree(valeur) ;
prev -> suivant -> suivant = next ;

return debut ;
}

void rechercher(Noeud *debut,int valeur){
    if(debut == NULL){
    printf("liste vide\n");
    return ; }
    int c = 0 ;
    while(debut != NULL) {
        if(valeur == debut->valeur)
        c++;
        debut = debut -> suivant ;

    }

    printf("Nombre d'occurence de %d = %d\n",valeur,c);

}
Noeud* suppressionD(Noeud *debut){
    if(debut == NULL)
    return NULL;

    Noeud *temp;
    temp = debut ;
    debut = debut -> suivant ;

    free(temp);

    return debut ;
}

Noeud* supressionF(Noeud *debut){
    Noeud *P;
    P = debut ;
    while(P->suivant->suivant != NULL){
        P = P->suivant;
    }

    free(P->suivant) ;
    P -> suivant = NULL ;
    return debut ;

}

Noeud *suppressionP(Noeud *debut, int pos){

    if( taille(debut) < pos ||  pos <=0 ){
    printf("Position invalide\n");
    return debut ;}

    if(pos == 1)
    return suppressionD(debut) ;

    if( taille(debut) == pos )  // savoir si la position, si oui on se suffit de supprimer juste la fin
    return supressionF(debut) ;

    Noeud *P1 , *P2;

    P1 = debut ;
    P2 = debut -> suivant ;

    for(int c = 2 ; c < pos ; c++){
        P1 = P2 ;
        P2 = P2 -> suivant ;
    }
        P1 -> suivant = P2 -> suivant ;
        free(P2);

        return debut ;
}
void modifierD( Noeud *debut , int valeur){

    debut -> valeur = valeur ;

}

void modifierF(Noeud *debut,int valeur){

    while(debut -> suivant != NULL){
        debut = debut -> suivant ;
    }

    debut -> valeur = valeur ;
}

void modifierP(Noeud *debut, int pos , int valeur){

    if(debut == NULL){
    printf("Liste vide\n");
    return ; }

    if(pos == 1){
        modifierD( debut , valeur);
    return ; }

    if(pos > taille(debut)){
    printf("Position plus grand a la taille de la liste\n");
    return ;}

    if (taille(debut) == pos){
    modifierF(debut,valeur);
    return ;}

    for( int c = 2 ; c <= pos ; debut = debut -> suivant , c++);

    debut -> valeur = valeur ;

    return ;

}

void remplissageAuto(Noeud *debut){
    if (debut == NULL)
    return ;
    srand(time(NULL));

    while(debut != NULL){
    debut -> valeur = rand() ;
    debut = debut -> suivant ; 
    }

}

void remplissageManuel(Noeud *debut){
    int c = 1 ;
    if (debut == NULL)
    return ;

    while(debut != NULL){
    printf("Entrez une valeur pour noeud %d :\n",c) ;
    scanf("%d",&debut->valeur);
    debut = debut->suivant ;
    c++ ;
    
    }
    
}

int position(){

    int p ;
    printf("Entrez la position\n");

    do{
    scanf("%d",&p);
    if(p <= 0)
    printf("Position invalide, entrez a nouveau\n");
    }while(p<=0);

    return p ;
}
int valeur(){

    int v;
    printf("Entrez une valeur\n");
    scanf("%d",&v);

    return v ;

}
Noeud* creerListe(Noeud *debut){
    int taille ;
    Noeud *P , *temp ;

    printf("Entrez la taille de la liste:\n");

    do{
    scanf("%d",&taille);
    if(taille<=0)
    printf("Taille invalide entrez a nouveau:\n");
    }while(taille <= 0);

    P = malloc(sizeof(Noeud)) ;
    P -> suivant = NULL ;
    temp = P ;
    for(int a = 1 ; a < taille ; a++){
        temp -> suivant = malloc(sizeof(Noeud));
        temp->suivant->suivant = NULL ;
        temp = temp -> suivant ;
    }

    return P ;

}



int main(){

    Noeud *Start ;
    Start = NULL ;
    int x , y ;

    do{
        printf("\n-------Menu-------\n\n");
        printf("0-Sortir\n");
        printf("1-Creer une liste avec des valeurs initials\n");
        printf("2-Inserer un noeud a une position\n");
        printf("3-Supprimer un noeud a une position\n");
        printf("4-Modifier une valeur a une position\n");
        printf("5-Rechercher l'occurence d'une valeur\n");
        printf("6-Afficher les valeurs\n");
        printf("7-Afficher la taille de la liste\n");
        scanf("%d",&x);

    switch (x) {
        case 1 :
        do{

        Start = creerListe(Start);
        printf("1-Remplissage Auto\n");
        printf("2-Remplissage Manuel\n");
        scanf("%d",&y);

            switch (y) {
                case 1 :
                remplissageAuto(Start);
                       break ;
                case 2 :
                remplissageManuel(Start);
                        break ;
                }

        }while( y < 1 || y > 2) ;
             
            break ;
        
        case 2 :
            Start = insertion(Start,position(), valeur() ) ;
            break ;
        case 3 :
            Start = suppressionP(Start,position() ) ;
            break ;
        case 4 :
            modifierP(Start, position() , valeur()) ;
            break ;
        case 5 :
            rechercher(Start,valeur()) ;

            break ;
        case 6 :
            affiche(Start) ;

            break ;
        case 7 :
           printf("\t%d\n",taille(Start)) ;
           break ;

            
        }


    }while(x > 0 && x <= 7);
    free(Start) ;



}
