
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
#define max 99994934
bool sieve[max] = {0};
int numbers=0;

void remove_first(int &num) {
    num %= static_cast<int>(pow(10, static_cast<size_t>(log10(num))));
}


bool trunc(int num) {
    remove_first(num);
    if (num==0) return true;
    if ( sieve[num]==false) return trunc(num);
    else return false;
}

void rec (int num ) {
    if (numbers==12 || num*10>max) return;
    if ( sieve[ num * 10 + 1 ]==false ) {
        if (trunc(num*10+1)) {
            printf ("%d\n", num*10+1);
            numbers++;
        }
        rec (num*10+1);
        
        
    }
    if ( sieve[ num * 10 + 3 ]==false ) {
        if (trunc(num*10+3)) {
            printf ("%d\n", num*10+3);
            numbers++;
        }
        rec (num*10+3);
    }
    if ( sieve[ num * 10 + 7 ]==false ) {
        if (trunc(num*10+7)) {
            printf ("%d\n", num*10+7);
            numbers++;
        }
        
        rec (num*10+7);
    }
    if ( sieve[ num * 10 + 9 ]==false ) {
        if (trunc(num*10+9)) {
            printf ("%d\n", num*10+9);
            numbers++;
        }
        rec (num*10+9);
    }
}


int main () {
    
    sieve[0]=true; sieve[1]=true;
    
    
    int multiplier = 2,i;
    
    for (multiplier=2; multiplier<max ; multiplier++) {
        for ( i=2; i*multiplier<max; i++){
            sieve[i*multiplier]=true;
        }
    }
    rec(3);
    rec(7);
    rec(2);
    rec(5);
    //    rec(7);
    //rec(1);
    //    cout << trunc (3797);
}

