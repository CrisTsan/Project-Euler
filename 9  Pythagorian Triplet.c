#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// Ελάχιστο C=335, με B=334, C=333
// C= sqrt( B*B + A*A)
// A+B+C=1000

int main(){
    int c,b,a=0;
    
    for (c=3; c<=997 ; c++)
    {
        for (b=2; b<c ; b++) {
            if (!((a=1000-b-c)<b && a>0 ) ) continue;
            if (c*c == b*b+a*a) break;
        }
        if (c*c == b*b+a*a) break;
    }
    printf("%d %d %d \n",a,b,c);
    printf("%d",a*b*c);
    
}