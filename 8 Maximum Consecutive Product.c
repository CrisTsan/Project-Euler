#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#define NUMBER 600851475143



int main(){
    int i,max=0,prod;
    char ps[1000],c;
    
    for (i=0; i<=999; i++) {
        while ((c=getchar())=='\n');
        ps[i]=c-'0';
    }
    for (i=0; i<=995; i++) {
        if ( (prod=ps[i]*ps[i+1]*ps[i+2]*ps[i+3]*ps[i+4]) > max)
            max = prod;
    
    }
    printf("%d",max);

}