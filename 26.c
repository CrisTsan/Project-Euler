
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
    int divisors=1,times=0;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        times++;
        n = n/2;
    }
    if (times>0) divisors*= times+1;
    
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        times=0;
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            times++;
            
            n = n/i;
        }
        if (times>0) divisors*= times+1;
    }
    
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2) {
        
        divisors*=2;
    }
    return divisors;
}

int reciprocal_cyrcle(int number) {
    double tester;
    
    
    return 1;
}



int division ( int divider, int divident) {
    short int digits[10000]={0};
    int store_k_for_later;
    cout << divident << " \\ " << divider <<endl ;
    int times =0;
    int residents=divident;
    int iterations=0;
    int cycles,begin,end;
    while (1==1) {
        times=0;
        iterations++;
        while (residents>divider) {
            residents = residents-divider;
            times++;
        }
        //   cout <<times;
        residents *=10;
        //if (iterations==1) cout << "." ;
        
        
        digits[iterations-1]=times;
        
        
        
        if (iterations==10000) {
            
            for (int i=1; i<iterations; i++) {
                if ( digits[i]==0 ) continue;
                for (int j=i+1; j<iterations; j++) {
                    bool what=true;
                    store_k_for_later=j-i;
                    for (int k=j-i; k>0; k--) {
                        
                        if (! (digits[i+k-1]==digits[j+k-1]))
                        {
                            what=false;
                            
                            break;
                            
                        }
                    }
                    if (what) {
                        cout<<endl<< store_k_for_later<<endl;
                        goto exit;
                    }
                }
            }
        }
        
    }
exit:;
    return store_k_for_later;
}
/* Driver program to test above function */
int main()
{
    int i,max=-1,max_i;
    for (i=2; i<=1000;i++) {
        if (max<division( i,1)) {
            max=division(i, 1);
            max_i=i;
        }
    }
    cout <<max_i<< " " <<max;
}


