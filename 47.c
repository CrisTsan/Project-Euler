
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <cstring>
#include <algorithm>

#include <fstream>
#include "InfInt.h"
#include <assert.h>
#define MAX  8

using namespace std;
//We assume that the biggest word is of 15 letters, so the upper limit is 15*26=390


int n_th_digit( int num,int n) {
    return (num%((int)pow(10,n)))/((int)pow(10,n-1));
}

int length_of_number(int num) {
    return int(log10(num))+1;
}
bool distinct_digits(int number) {
    int numbers[10]={0};
    for ( int i= length_of_number(number); i>0 ; i--) {
        numbers[ n_th_digit(number, i)]++;
    }
    for (int i=1; i<=9; i++) if ( numbers[i]>1) return false;
    return true;
}

bool dinstict_digits_after_concatenation(int number, int number2) {
    if ( distinct_digits(number+ number2*(int)(pow(10,(length_of_number(number)+1))))) return true;
    return false;
}

bool has_zeros(int num) {
    for ( int i= length_of_number(num); i>0 ; i--) {
        if (n_th_digit(num, i) ==0 ) return true;
    }
    return false;
}



int primeFactors(int n)
{
    int dist=0,times;
    // Print the number of 2s that divide n
    times=0;
    while (n%2 == 0)
    {
        times++;
        //        printf("%d ", 2);
        n = n/2;
    }
    if (times>0) {
        dist++;
        times=0;
    }
    
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            //  printf("%d ", i);
            n = n/i;
            times++;
        }
        if (times>0) {
            dist++;
            times=0;
        }
    }
    
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2) {
        //        printf ("%d ", n);
        dist++;
    }
    return dist;
}

struct divisors {
    int number;
    int howMany;
    divisors *next;
};

int main () {
    int cont=0,prev1,prev2,prev3,curr,i;
    
    prev1=primeFactors(13);
    prev2=primeFactors(12);
    prev3=primeFactors(11);
    for ( i=14; i<1000000; i++) {
        curr=primeFactors(i);
        if (curr==prev1 && prev1==prev2 && prev2==prev3 && curr==4) {
            
            i=i-3;
            break;
        }
        prev3=prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<i<<endl;
}

