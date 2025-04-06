#include<stdio.h>
int main(){
    int t2=0,c1,t1=0,co=0,i=-1,temp=0,l,l1,c,t3,t4,T[100][100],j=0;
    do{
        printf("Entrez les lignes:\n");
        scanf("%d",&l);
    }while(l<=0);
    do{
        printf("Entrez les collones:\n");
        scanf("%d",&c);
    }while(c<=0);
    l1=l;
    c1=c;
    while(co!= l*c){
    for(t2;t2<c1 && co!= l*c ; t2++){
        co++;
        T[t1][t2]=co;
    }t2--;
    t1++;
    for(t1;t1<l1 && co != l*c ; t1++){
        co++;
            T[t1][t2] = co;}
            i++;
            t1--;
            for(t3=t2-1; t3 >=i && co!=l*c;t3--){
                co++;
                T[t1][t3]=co;
            }j++;
            t3++;
            for(t4=t1-1;t4>=j && co!= l*c ; t4--){
                co++;
                T[t4][t3]=co;
            }temp++;
            t2=temp;
            t1=temp;
            l1--;
            c1--;
    }
    for(t1=0;t1<l;t1++){
        for(t2=0;t2<c;t2++){
            printf("%d\t",T[t1][t2]);
        }printf("\n");
    }
    return 0;
}
