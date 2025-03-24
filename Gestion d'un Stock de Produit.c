#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Date{
    char jour[3];
    char mois[3];
    char annee[5];
}date;

typedef struct Produit{
    char *Nom_produit;
    char Reference[100];
    float Montant;
    date DateAchat;
}produit;

typedef struct Liste{
    produit cellule;
    struct Liste *psuiv;
}liste;

liste* creer_liste_produits(){
    liste *P;
    P = (liste*)malloc(sizeof(liste));
    P -> psuiv = NULL ;
    return P ;
}

int est_vide(liste *tete){
if (tete)
return 1 ;
else 
return 0 ;
}

liste* creer_produit(){
    liste *P;
    P = creer_liste_produits();
    char temp[21] ; int longueur;

    printf("Entrez le nom de produit:\n");
    fflush(stdin);
    fgets(temp, 21 , stdin);
    longueur  = strlen(temp) ; //logeur recoit le nombre de caracteres saisit par l'utlisateur
    P->cellule.Nom_produit = (char*)malloc( longueur * sizeof(char)) ; //allocation dynamique de nom de produit en fonction longueur
    strcpy(P->cellule.Nom_produit , temp) ;
    printf("Entrez la reference :\n");
    fflush(stdin);
    fgets(P->cellule.Reference,100,stdin);
    printf("Entrez le montant:\n");
    do{
    scanf("%f",&P->cellule.Montant);
    if(P->cellule.Montant < 0 )
    printf("----Entrez un montant raisonable:----\n");
    }while(P->cellule.Montant < 0);
    printf("Entrez la date : JJ MM AA :\n");
    printf("Jour : ");
    fflush(stdin);
    fgets(P->cellule.DateAchat.jour,3,stdin);
    fflush(stdin);
    printf("Mois : ");
    fgets(P->cellule.DateAchat.mois,3,stdin);
    fflush(stdin);
    printf("Annee: ");
    fgets(P->cellule.DateAchat.annee,5,stdin);
    fflush(stdin);
    printf("\n\n");
    return P ;

} 
void afficher_produit(liste *produit){

    if(est_vide(produit) == 0){
    printf("\n\tListe vide\n\n");

    return ; }

    printf("Entrez le nom de produit:\n");
    char *tab; 
    tab = (char*)malloc(21 *sizeof(char)) ;
    fflush(stdin);
    fgets(tab,21,stdin);
    while(produit != NULL && strcasecmp(produit->cellule.Nom_produit,tab) != 0 ){
    produit = produit -> psuiv ;
    }
    
    if(produit == NULL){
    printf("\n\n\tProduit n'existe pas\n");
    return ;}

        printf("-----Nom produit : %s-----\n",produit->cellule.Nom_produit);
        printf("1-Reference: %s\n",produit->cellule.Reference);
        printf("2-Montant : %f\n",produit->cellule.Montant);
        printf("3-Date d'achat :\n");
        printf(" %s/%s/%s",produit->cellule.DateAchat.jour,produit->cellule.DateAchat.mois,produit->cellule.DateAchat.annee);
        printf("\n\n");
        
    
}

liste* ajouter_debut(liste* tete){
    if(est_vide(tete) == 0)
       return creer_produit() ;
    liste *ptr ;
    ptr = creer_produit();
    ptr -> psuiv = tete ;
    return ptr ;
}
liste* ajouter_fin(liste* tete){
    if(est_vide(tete) == 0)
    return ajouter_debut(tete) ;
    liste *Head = tete ;
    while(tete -> psuiv != NULL ){
        tete = tete -> psuiv ;
    }
    tete -> psuiv = creer_produit();
    return Head ;
    printf("\n\n");
}
void afficher_produits(liste* tete){
    if(est_vide(tete) == 0){
    printf("\t\nListe vide\n\n");
    return ;}
    
    while(tete != NULL){
        
        
        printf("%s",tete->cellule.Nom_produit);
        printf(" -Reference: %s\n",tete->cellule.Reference);
        fflush(stdin);
        printf(" -Montant : %f\n",tete->cellule.Montant);
        printf(" -Date d'achat :\n");
        printf("  %s/%s/%s",tete->cellule.DateAchat.jour,tete->cellule.DateAchat.mois,tete->cellule.DateAchat.annee);
        printf("\n\n");
        tete = tete -> psuiv ;
        
    }

    printf("\n\n");
 
}
int longueur(liste *tete){
    int a ;
    for( a =  0 ; tete != NULL ; a++ , tete = tete -> psuiv);
    return a ;
}
void filtrer_date(liste * tete, date dt){
    int a = 0 ;
    while(tete != NULL){
    if(strcasecmp(dt.annee , tete->cellule.DateAchat.annee)
    ==0 && strcasecmp(dt.mois , tete->cellule.DateAchat.mois)
    ==0 && strcasecmp(dt.jour , tete->cellule.DateAchat.jour) ==0){
         a++;
        printf("-----Nom produit : %s-----\n",tete->cellule.Nom_produit);
        printf("1-Reference: %s\n",tete->cellule.Reference);
        printf("2-Montant : %f\n",tete->cellule.Montant);
        printf("3-Date d'achat :\n");
        printf(" %s/%s/%s",tete->cellule.DateAchat.jour,tete->cellule.DateAchat.mois,tete->cellule.DateAchat.annee);
        printf("\n\n");
      }
      tete = tete -> psuiv ;
    }
    if(!a)
    printf("Aucun produit avec cette date existe\n\n");

}liste *supprimer_debut(liste *tete){
    
    liste *temp;
    temp = tete;
    tete = tete -> psuiv ;
    free(temp);
    return tete;
}
void supprimer__fin(liste *tete){
    liste *temp ;
    temp = tete ;
    while(temp -> psuiv -> psuiv != NULL){
        temp = temp -> psuiv ;
    }
    free(temp -> psuiv);
    temp -> psuiv = NULL ;
}

liste *rembourser(liste* Liste,char* refer){

     if(est_vide(Liste) == 0){
     printf("\n\tListe vide\n\n");
     return Liste ;}

    liste *P ,*prev ;
    P = Liste  ;

    while(  P != NULL && strcasecmp(refer , P->cellule.Reference ) !=0){

        prev = P ;
        P = P -> psuiv ;
    }

    if( P != NULL){ 

        if(P == Liste)
            return supprimer_debut(Liste) ;

        else if( P->psuiv == NULL)
            supprimer__fin(Liste) ;
            
        else{ 
         prev -> psuiv = P -> psuiv ;
         free(P);
        }
        
       }

    else
    printf("\t\nProduit n'existe pas\n");
    return Liste ;
}


date saisir_Date(){
    date dt ;
    printf("Jour:\n");
    fflush(stdin);
    fgets(dt.jour,3,stdin);
    fflush(stdin);
    printf("Mois:\n");
    fgets(dt.mois,3,stdin);
    fflush(stdin);
    printf("Annee:\n");
    fgets(dt.annee,5,stdin);
    fflush(stdin);

return dt ;
}
char * saisirRef(){
    char *ref ;
    ref = (char*)malloc(100 * sizeof(char)) ;
    printf("Entrez la reference:\n");
    fflush(stdin);
    fgets(ref,100,stdin);

return ref ;
}


int main(){
  
    liste *Start ;
    Start = NULL ;
    int x ;
    
    do{
        printf("0-Sortir\n");
       printf("1-Ajouter un produit\n");
       printf("2-Afficher un produit specifique\n");
       printf("3-Afficher tous les produits\n");
       printf("4-Afficher le nombre de produits\n");
       printf("5-Afficher les produits d'une date\n");
       printf("6-Supprimer un produit\n");
       scanf("%d",&x);

       switch(x){
        case 0 :
        free(Start) ;
             exit(0) ;
             
        case 1 : 
              Start = ajouter_fin(Start) ;
              break ; 
        case 2 : 
              afficher_produit(Start) ;
              break ;
        case 3 : 
             afficher_produits(Start) ;
             break ;
        case 4  :
            printf ("\t%d\n\n\n",longueur(Start)) ;
            break ;
        case 5 :
            filtrer_date(Start,saisir_Date()) ;
            break ;
        case 6 :
            Start = rembourser(Start,saisirRef()) ;
            break ;
       }

    }while(1) ;


}
