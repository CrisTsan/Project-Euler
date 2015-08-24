#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int main() {
    int a[6],i,j,k,num,max=0;
    for (k=999; k>=100; k--) {
        for (j=999; j>=100 && (num=k*j)>99999 ; j--)
        {
            for (i=5; i>=0 ; i--) {
                a[i]= num / pow(10,i);
                num = num % ((int)pow (10,i));
            }
            bool pal=true; // DHLWSH
            for (i=0; i<=2; i++) if ( a[i] != a[5-i]) pal=false;
            if (pal==true && k*j>max) max=k*j;
        }
    }
    printf("%d",max);


}