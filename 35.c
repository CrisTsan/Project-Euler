
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
    int divisors=1,times;
    // Print the number of 2s that divide n
    times=0;
    while (n%2 == 0)
    {
        times++;
        //        printf("%d ", 2);
        n = n/2;
    }
    if (times>0) {
        divisors*=times+1;
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
            divisors*=times+1;
            times=0;
        }
    }
    
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2) {
        // printf ("%d ", n);
        divisors*=2;
    }
    return divisors;
}

struct divisors {
    int number;
    int howMany;
    divisors *next;
};

#define max 1000000

int main () {
    int circ[6][6],num=654321,digits,sum=0;
    
    bool sieve[max] = {0},found;
    sieve[0]=true; sieve[1]=true;
    
    int multiplier = 2;
    
    for (multiplier=2; multiplier<max ; multiplier++) {
        for ( int i=2; i*multiplier<max; i++){
            sieve[i*multiplier]=true;
        }
    }
    
    int temp=0,power=1;
    for (int k=1; k<=999999; k++) {
        found=true;
        digits=length_of_number(k);
        for (int i=0; i<digits; i++) {
            temp=0;
            for (int j=0; j<digits; j++) {
                circ[i][j]= n_th_digit(k,(j+i)%digits+1);
                temp += circ[i][j]*power;
                power*=10;
            }
            power=1;
            if (sieve[temp]!=0) {
                found=false;
                break;
            }
        }
        
        if (found) { cout<<temp<<endl; sum++;}
    }
    cout<< endl<<sum <<endl;
}

