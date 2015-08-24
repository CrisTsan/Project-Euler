
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
// if the prime is abo 7021, is p_n <= n ln n + n (ln ln n - 0.9385)
// so for 10001 we have upper bound 104933.
InfInt power(int number, int power) {
    InfInt temp=1;
    
    for (int i=1 ; i<=power; i++) {
        temp*=number;
    }
    return temp;
}

InfInt nextPower(InfInt number, int base) {
    return number*base;
}

int main () {
    int i,last=1,sum=0;
    size_t temp2;
    InfInt temp;
    for (i=1; i>-1 ;i++) {
        for (int k=last; k<=9 ; k++) {
            temp=power(k,i);
            if ((temp2=temp.numberOfDigits())==i) {
                last=i;
                sum += 10-k;
                if (i==10) i=-2;
                break;
                
            }
        }
    }
    
    temp=power(9,10);
    for ( i=11;; i++) {
        temp=nextPower(temp,9);
        if (temp.numberOfDigits()==i);
        else break;
        
    }
    sum += i-10;
    cout<<sum << endl;
    
}

