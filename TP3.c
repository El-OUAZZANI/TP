#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Noeud{
int valeur;
struct Noeud *suivant;
struct Noeud *precedent;
}Noeud;
Noeud *cree(int valeur){
    Noeud *P;
    P = (Noeud*)(malloc(sizeof(Noeud)));
    P -> precedent = NULL;
    P -> suivant = NULL ;
    P -> valeur = valeur ;

    return P ;
}
void affiche(Noeud *debut){
    if (!debut)
    printf("\n\nListe vide\n");
    else{
        printf("\n\t---Affichage Normal---\n");
        while(debut){
            printf("\t\n%d\n",debut->valeur);
            debut = debut -> suivant;
        }
    }
}
void afficherInverse(Noeud *debut){
    if(!debut){
    printf("Liste vide\n");
    return ;}

    while(debut -> suivant != NULL){
        debut = debut -> suivant ;
    }
    printf("\t\n---Affichage Inverse---\n");

    while( debut != NULL){
        
        printf("\n\t%d\n",debut -> valeur);
        debut = debut -> precedent ;
        
        
        
    }
}
Noeud *ajouterD(Noeud *debut,int valeur){
    if(debut == NULL)
    return cree(valeur) ;
    Noeud *P ;
    P = cree(valeur) ;
    P -> suivant = debut ;
    P -> suivant -> precedent = P ;
    return P ;
}

Noeud* ajouterF(Noeud *debut , int valeur){
    if(!debut)
    return cree(valeur) ;

    Noeud *temp = debut ;
    while(temp -> suivant != NULL)
    temp = temp -> suivant ;
    temp -> suivant = cree(valeur);

    return debut ;
}

int taille(Noeud *debut){
    int c = 0 ;
    while(debut != NULL){
        c++; 
        debut = debut -> suivant ;  
        }
    return c ;
}
Noeud *insertion(int position,Noeud *debut, int valeur){

    if(!debut)
        
        return cree(valeur);
    
    if( position == 1 )
        return ajouterD(debut,valeur) ;

    int t = taille(debut) ;

    if(position == t);
    return ajouterF(debut,valeur);
    

            //cas si la position existe dans le milieu
    Noeud *P = debut ;
    for( int a = 2 ; a < position && P->suivant != NULL ; a++ , P = P -> suivant );
     

     Noeud *temp ;
     temp = P -> suivant ;
     P -> suivant = cree(valeur);
     P -> suivant -> suivant = temp ;
     P -> suivant -> precedent = P ;
     temp -> precedent = P -> suivant ;


    return debut ;
 }

Noeud * rechercher(Noeud *debut,int valeur){
if(!debut){
printf("\n\tListe vide");
return debut ;}

Noeud *temp = debut ;
    while(temp != NULL){
        if(temp -> valeur == valeur){
            printf("\n\tValeur trouve !\n");
            return debut;
        }
        temp = temp -> suivant ;
    }

    printf("\n\tValeur non trouve!");
 }

Noeud *suppressionD(Noeud *debut){

       if(!debut){
       printf("\n\tListe vide\n");
       return debut ;}

      Noeud *temp = debut ;
      debut = debut -> suivant ;
      debut -> precedent = NULL ;
      free(temp) ;

      return debut ;
}

Noeud *suppressionF(Noeud *debut){
    if(!debut){
        printf("\n\tListe vide\n");
        return debut ;}

        Noeud *temp = debut ;
    while(temp -> suivant  != NULL){
        temp = temp -> suivant;
    }

    if(temp == debut){
    free(temp);
    return NULL ;}

     temp -> precedent -> suivant = NULL ;
    free(temp) ;
    return debut ;
}

Noeud* suppressionP(Noeud *debut, int pos){
    if(pos > taille(debut))
    printf("\n\tPosition Invalide!\n\n");

    if(pos == 1)
    return suppressionD(debut) ;
     
    int c = taille(debut) ;

    if(pos == c )
    return suppressionF(debut) ;
        
    Noeud *temp = debut ->suivant ;

    for( int a = 2 ; a < c ; a++ , temp = temp -> suivant ) ;
    temp -> precedent -> suivant = temp -> suivant ;
    temp -> suivant -> precedent = temp -> precedent ;
    free(temp) ;
    return debut ;
}

Noeud * modifierD(Noeud *debut, int valeur){
    if(!debut)
    printf("\n\tListe vide\n\n");
    debut -> valeur = valeur ;

    return debut ;
}

Noeud * modifierF(Noeud *debut , int valeur){
    if(!debut)
    printf("\n\tListe vide\n\n");

    while(debut -> suivant != NULL)
    debut = debut -> suivant ;

    debut -> valeur = valeur ;

}

Noeud* modifierP(Noeud *debut, int pos , int valeur){

    if(pos == 1 )
    return  modifierD(debut,valeur);
    int c = taille(debut) ;
    if(pos == c )
    return modifierF(debut,valeur);

        
        Noeud *temp = debut -> suivant ;
    for( int a = 2 ; a < c ; a++ , temp = temp -> suivant ) ;
     temp -> valeur = valeur ;

     return debut ;
}

Noeud *tri(Noeud *debut){
       
    if(!debut){
    printf("\n\tListe vide!\n");
    return NULL ;}

    int min ;
    Noeud *Pmin ,*ptr, *Head = debut ;

    min = debut -> valeur ;
    ptr = debut ;

    while(debut != NULL){

        Pmin = debut ;
        min = Pmin -> valeur ;
        ptr = debut -> suivant ;

        while(ptr != NULL){

            if(ptr -> valeur < min){
                min = ptr -> valeur ;
                Pmin = ptr ;
            }
            ptr = ptr -> suivant ;
        }

        if(Pmin != debut){
            Pmin  -> valeur = debut -> valeur ;
            debut -> valeur = min ;
        }
    debut = debut -> suivant ;

    }
return Head ;
}
int position(Noeud *debut){
    int a,t = taille(debut) ;
    printf("Entrez une position:");

    do{
     scanf("%d",&a);
     if( t == 0)
     return 0 ;
     if( a > t || a < 0 ){
     if(a > t )
     printf("position > %d plus grand que la taille!\n",t);
     if(a<=0)
     printf("Position negative!\n ");
     printf("Entrez a nouveau:");
     } 
    }while(a > t || a < 0 );
    printf("\n");
    return a ;
}

void remplissageMan(Noeud *debut){
    if(!debut)
    printf("\t\nListe vide\n");
    int a = 1 ;
    while(debut != NULL){
        printf("Entrez une valeur pour position %d:\n",a);
        scanf("%d",&debut->valeur);
        a++ ;
        debut = debut -> suivant ;
    }
}
void remplissageAuto(Noeud *debut){
    srand(time(NULL));
    while(debut){
        debut -> valeur = rand()/10;
        debut = debut -> suivant ;
    }
}

int valeur(){
    int valeur ;
    printf("Entrez une valeur:\n");
    scanf("%d",&valeur);
    return valeur ;
}

int main(){

int x,y ;
Noeud *Start = NULL ;
do{

    printf("\t0-exit\n");
    printf("\t1-Ajouter un noeud vers une position\n");
    printf("\t2-Supprimer un noeud vers une position\n");
    printf("\t3-Modifier une valeur vers une position \n");
    printf("\t4-Trier la liste en ordre croissant\n");
    printf("\t5-Taille de la liste\n");
    printf("\t6-Affichage \n");
    printf("\t7-Modifier une valeur a une position donne \n\n");
    scanf("%d",&x);
    switch(x){
        case 0 :
           exit(0);
           break ;
        case 1 :
            Start = insertion(position(Start),Start, valeur()) ;
           break ;

        case 2 :
            Start = suppressionP(Start, position(Start));
           break ;
        
        case 3 :
           Start = modifierP(Start, position(Start) ,valeur());
           break ;
        
        case 4 :
        Start = tri(Start) ;
           break ;

        

        case 5 :
              printf("\t\t\t\n\n\n%d\n\n\n\n",taille(Start));
           break ;

        case 6 : 
              printf("1-Affichage normal\n");
              printf("2-Affichage inverse\n");
              do{
              scanf("%d",&y);
              if(y < 1 || y > 2)
              printf("Entrez a nouveau:");
              }while(y < 1 || y > 2);
              switch(y){

            case 1 :
                affiche(Start) ;
                break ;
                case 2 :
                afficherInverse(Start);
              }
          break ;

        case 7 :
        Start = modifierP(Start, position(Start) , valeur()) ;
          break ;


    }


}while(1) ;


}
