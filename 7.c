
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

// according to a mathematical journal the upper bound for the n_th prime
// if the prime is above 7021, is p_n <= n ln n + n (ln ln n - 0.9385)
// so for 10001 we have upper bound 104933.
#define max 104934
int main () {
    
    bool sieve[max] = {0};
    sieve[0]=true; sieve[1]=true;
    
    
    int multiplier = 2,i;
    
    for (multiplier=2; multiplier<max ; multiplier++) {
        for ( i=2; i*multiplier<max; i++){
            sieve[i*multiplier]=true;
        }
    }
    int sum=0;
    for (i=2; i<max;i++){
        if (sieve[i]==0) sum++;
        if (sum==10001) {
            cout<< i<<endl;
            break;
        }
    }
}

