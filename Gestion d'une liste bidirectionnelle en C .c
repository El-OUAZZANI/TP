#include<stdio.h>
#include<stdlib.h>
#include<time.h>

 typedef struct Noeud{
    struct Noeud *next;
    struct Noeud *prev ;
    int valeur ;
 }Noeud;
  Noeud *cree(){
    Noeud *P = (Noeud*)malloc(sizeof(Noeud));
    P -> next = NULL ;
    P -> prev = NULL ;
    printf ("Entrez un valeur :\n");
    scanf("%d",&P->valeur);
    return P ;
  }
  Noeud *creeAuto(){
    int x; 
    Noeud *P = (Noeud*)malloc(sizeof(Noeud));
    P -> next = NULL ;
    P -> prev = NULL ;
    P -> valeur =  rand() / 1000;
     
    return P ;
  }
 Noeud *Ajouterdebut(Noeud *debut){
    if( !debut)
    return cree() ;
    debut -> prev = cree() ;
    debut -> prev -> next = debut ;
    debut = debut -> prev ;
    return debut ;
 }

 Noeud *Ajouterfin(Noeud *debut){
    if(!debut)
    return cree() ;
    Noeud *temp = debut ;
    while(temp->next ){
        temp = temp -> next ;
    }
    temp -> next = cree() ;
    temp -> next -> prev = temp ;
    return debut;
 }

Noeud* AjouterNoeud(Noeud *debut){
    if(!debut)
    return Ajouterdebut(debut) ;

    return Ajouterfin(debut);
}


Noeud * AjoutNoeudAuto(Noeud *debut){
    if(!debut)
    return creeAuto(debut) ;

    Noeud *temp = debut ;
    while( temp -> next != NULL){
    temp = temp -> next ;
    }
    temp -> next = creeAuto(debut) ;
    temp -> next -> prev = temp ;
    return debut ;
}

Noeud* CreationNoeudAuto(Noeud *debut , int occ){
    int x;
    do{
    printf("1-Remplissage auto\n");
    printf("2-Remplissage manuel\n");
    scanf("%d",&x);
    }while(x < 1 || x > 2);

    if( x == 1){
        
        for(occ;occ>0;occ--){
            debut =  AjoutNoeudAuto(debut) ;
        }

    }
    else{

for(occ;occ>0;occ--){
    debut = AjouterNoeud(debut);
}

}
return debut ;
}
 Noeud *AjouterPosition(int position,Noeud *debut){
    int a ;
    
    if( position == 1 )
        return Ajouterdebut(debut) ;
        if(!debut){
            printf("Liste vide!\n");
            return NULL;}
    Noeud *P = debut ;
    for( a = 2 ; a < position && P->next != NULL ; a++ , P = P -> next );

    if( P -> next != NULL ){

     Noeud *temp ;
     temp = P -> next ;
     P -> next = cree();
     P -> next -> next = temp ;
     P -> next -> prev = P ;
     temp -> prev = P -> next ;

    }else if(P -> next == NULL){
      return Ajouterfin(debut) ;
    }else printf("Position invalide\n");

    return debut ;
 }
 int position(){
    int a ;
    printf("Entrez une position:\n");
    do{
     scanf("%d",&a);
     if(a < 1)
     printf("Entrez une position valide :\n");
    }while(a < 1);
    return a ;
 }
 void affichage(Noeud *debut){
    if(!debut)
    printf("\tListe vide !\n\n");
    while (debut != NULL){
        printf("\t%d\n",debut->valeur);
        debut = debut -> next ;
    }
    printf("\n\n");

 }

 int occ() {
    int x ;
    do{
    printf("Entrez le nombre de noeud:\n");
    scanf("%d",&x);
    }while( x <= 0) ;

    return x ;
 }

 int main(){
Noeud *Start = NULL ;
int x ;
srand(time(NULL)) ;
do{
    printf("0-Sortir\n");
    printf("1-Ajouter un noeud\n");
    printf("2-Ajouter plusieurs noeuds a la fois\n");
    printf("3-Ajouter un noeud en debut\n");
    printf("4-Ajouter un noeud a la  fin\n");
    printf("5-Ajouter una noeud a une position\n");
    printf("6-Affichage\n");
    scanf("%d",&x);
    switch(x){
        case 0 :
            exit(1);
    case 1 :
            Start = AjouterNoeud(Start) ;
        break;

    case 2 :
            Start = CreationNoeudAuto(Start ,occ()) ;
        break;

    case 3 :
            Start = Ajouterdebut(Start) ;
        break;

    case 4 : 
            Start = Ajouterfin(Start) ;
        break ;
    case 5 :
            Start = AjouterPosition(position(), Start);
            break ;
    case 6 :
            affichage(Start) ;
            break ;
    }


}while(1);

 }
