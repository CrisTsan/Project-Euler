#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// 0 Για άγνωστο
// 1 Για Σύνθετο
// 5 Για Πρώτο

int main(){
    char PRIME[2000001]={0};
    int BEGG,i,l;
    unsigned long int sum=0;
    PRIME[0]=1;
    PRIME[1]=1;
    BEGG=2;
    while (BEGG<=2000000){
        while (PRIME[BEGG]!=0) BEGG++;
        PRIME[BEGG]=5;
        for (i=BEGG+BEGG; i<=2000000; i+=BEGG) PRIME[i]=1;
        BEGG++;
    }
    for (l=0; l<=2000000; l++) {
        if ( PRIME[l]==5) sum+=l;
    }
    printf("%lu",sum);

}
