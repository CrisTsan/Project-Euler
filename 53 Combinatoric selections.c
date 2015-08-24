//
//  main.c
//  PEULER
//
//  Created by Χρήστος Τσανικίδης on 5/7/13.
//  Copyright (c) 2013 Chris Tsanikidis. All rights reserved.
//

#include <stdio.h>
#define WTD 600851475143
#include <stdbool.h>

bool greaterANAmili ( int ano, int kato) {
    int temp,i;
    float ginomeno=1;
    
    if ( ano == kato || kato==0 ) return false;
   
    if ( kato > (temp=ano-kato))
    {
        for (i=0; i<=temp-1 ; i++) {
            ginomeno *= (ano-i)*(1.0/(1+i));
        }
    }
    else {
        for (i=0; i<=kato-1 ; i++) {
            ginomeno *= (ano-i)*(1.0/(1+i));
        }
    }
    if (ginomeno>1000000) return true;
    else return false;
}


int main (void) {
    int n,pl=0;
    for (n=1; n<=100; n++)
    {
            int j=0;
            while (j<=n)
            {
                    if (greaterANAmili(n, j)) pl++;
                    j++;
            }
    }
    printf("%d",pl);
}