#include<stdio.h>
int main(){
    char T[100],B[100],first;
    int a,b,c,d=0,f,g,C[50],i1,i2,e,ic=0,v=0,z=0,max,h;
    do{
        printf("Entrez la taille de tableau :\n");
        scanf("%d",&a);
    }while(a<=0 || a>100);
    printf("Entrez une chaine de caractere de %d caracteres:  ",a);
    for(b=0;b<a;b++){
        
        scanf(" %c",T+b);
    }for(b=a-1;b>=0;b--){
        *(B+b)=*(T+(a-1-b));
    }e=a;
    for(c=0;c<a-1;c++){
        for(d;d<e-1;d++){
            if(*(T+c)==*(B+d)){
                i1=c;
                first=*(T+c);
            for(f=c,g=d;f<a && g<e;f++,g++){
                if(*(T+f)==*(B+g)){
                    v++;
                    if(((f+1==a) || (g+1) == e ) && (first == *(T+f)) && v>1 )
                    z++;  
                    } 
                    if(v>1 && (first==*(T+f)) || z==1){
                        i2 = f;
                        *(C+ic) = i1 ;
                        *(C+ic +1 ) = i2 ;
                        ic+=2;
                        for( h = g -(i2-i1); h< e-(i2 -i1)-1 ; h++){
                            *(B+h)=*(B+g+1);
                            g++;
                        } 
                        e-= i2-i1 +1 ;
                        break ;
                    }
            }
        } v=0 ; z=0;
    } d = 0 ; v = 0 ; z = 0; }
    if(ic == 0)
    printf("Votre chaine de caracteres ne contient aucun palindrome :");
    else{
        i1=*(C);
        i2=*(C+1);
        max=*(C+1) - *(C) + 1;
        for(a=2 ; a<ic ; a+=2){
            if((*(C+a+1) - *(C+a) +1) < max){
                max = *(C+a+1) - *(C+a) + 1;
                i1 = *(C+a);
                i2 = * (C + a + 1 );
            }
        }printf(" le plus petit palendrome se compose de %d caracteres  :\n",max);
        printf("\t");
        for ( i1 ; i1<=i2 ; i1++){
        printf("%c",*(T+i1));
    } }printf("\n\n");
    printf("Tous les caracteres palendromes trouve:\n");
    for(a=0;a<ic;a=a+2){
        for(b=*(C+a);b<=*(C+a+1);b++){
            printf("%c",*(T+b));
        }printf("\t");
    }
    printf("\n");
    
    return 0;
}
