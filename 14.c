#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AND 3

int main(void)

{
    int i;
    long unsigned int max=0,snumber=0,PLITHOS[1000001]={0},n;
    
    for (i=2; i<= 1000000 ; i++) {
        n=i;
        PLITHOS[i]=1;
        while (n>1) {
            if ( n%2 ) n=n*3+1; // Monos
            else n/=2 ; // Zygos
            if (n<1000000 && PLITHOS[n]!=0) //ΣΕ περιπτωση που εχουμε υπολογισει ηδη τον αριθμο των αριθμων
            {
                PLITHOS[i]+=PLITHOS[n];
                break;
            }
            PLITHOS[i]+=1;
        
        }
        if (PLITHOS[i]>max) { max=PLITHOS[i]; snumber=i; }
       
    }
    printf("ARITHMOS %lu, SYNOLO %lu \n",max,snumber );
}