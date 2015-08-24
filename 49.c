
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
#define max 100000
bool sieve[max] = {0};
int numbers=0;

void remove_first(int &num) {
    num %= static_cast<int>(pow(10, static_cast<size_t>(log10(num))));
}

bool are_each_other_permutation (int num1, int num2) {
    int digits1[10]={0},digits2[10]={0};
    while (num1>0) {
        digits1 [ num1%10 ] +=1;
        num1 /= 10;
        digits2 [ num2%10 ] +=1;
        num2 /= 10;
    }
    for (int i=0; i<=9;i++) {
        if (digits1[i] != digits2[i]) return false;
    }
    return true;
}

#define limit 3339
int main () {
    
    sieve[0]=true; sieve[1]=true;
    
    
    int multiplier = 2,i;
    
    for (multiplier=2; multiplier<max ; multiplier++) {
        for ( i=2; i*multiplier<max; i++){
            sieve[i*multiplier]=true;
        }
    }
    for (i=1000; i<=9999; i++) {
        if ( (!sieve[i]) && (!sieve[i+3330]) && (!sieve[i+6660]) &&
            are_each_other_permutation(i, i+3330)
            && are_each_other_permutation(i, i+6660)) cout<< i<<endl ;
    }
    
}

