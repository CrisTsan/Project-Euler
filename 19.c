
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

#include <algorithm>

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

int prod6(int d1,int d2,int d3, int d4, int d5,int d6){
    return d1*100000+d2*10000+d3*1000+d4*100+d5*10+d6;
}
// There is a theorem stating that consecutive numbers have no common divisors other than 1.
void primeFactors(int u)
{
    int totaldivisors=1,total=0;
    int n=u;
    if (u%2==0) {
        n=u/2;
        // Print the number of 2s that divide n
        
        while (n%2 == 0)
        {
            total++;
            printf("%d ", 2);
            n = n/2;
        }
        if (total>0) totaldivisors*=(total+1);
        // n must be odd at this point.  So we can skip one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i+2)
        {
            // While i divides n, print i and divide n
            total=0;
            while (n%i == 0)
            {
                printf("%d ", i);
                n = n/i;
            }
            if (total>0) totaldivisors*=(total+1);
        }
        
        // This condition is to handle the case whien n is a prime number
        // greater than 2
        
        if (n > 2) {
            printf ("%d ", n);
            totaldivisors*=2;
        }
        n=u+1;
        // Print the number of 2s that divide n
        
        while (n%2 == 0)
        {
            total++;
            printf("%d ", 2);
            n = n/2;
        }
        if (total>0) totaldivisors*=(total+1);
        // n must be odd at this point.  So we can skip one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i+2)
        {
            // While i divides n, print i and divide n
            total=0;
            while (n%i == 0)
            {
                printf("%d ", i);
                n = n/i;
            }
            if (total>0) totaldivisors*=(total+1);
        }
        
        // This condition is to handle the case whien n is a prime number
        // greater than 2
        
        if (n > 2) {
            printf ("%d ", n);
            totaldivisors*=2;
        }
        
    }
    else {
        n=(u+1)/2;
        // Print the number of 2s that divide n
        
        while (n%2 == 0)
        {
            total++;
            printf("%d ", 2);
            n = n/2;
        }
        if (total>0) totaldivisors*=(total+1);
        // n must be odd at this point.  So we can skip one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i+2)
        {
            // While i divides n, print i and divide n
            total=0;
            while (n%i == 0)
            {
                printf("%d ", i);
                n = n/i;
            }
            if (total>0) totaldivisors*=(total+1);
        }
        
        // This condition is to handle the case whien n is a prime number
        // greater than 2
        
        if (n > 2) {
            printf ("%d ", n);
            totaldivisors*=2;
        }
        n=u+1;
        // Print the number of 2s that divide n
        
        while (n%2 == 0)
        {
            total++;
            printf("%d ", 2);
            n = n/2;
        }
        if (total>0) totaldivisors*=(total+1);
        // n must be odd at this point.  So we can skip one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i+2)
        {
            // While i divides n, print i and divide n
            total=0;
            while (n%i == 0)
            {
                printf("%d ", i);
                n = n/i;
            }
            if (total>0) totaldivisors*=(total+1);
        }
        
        // This condition is to handle the case whien n is a prime number
        // greater than 2
        
        if (n > 2) {
            printf ("%d ", n);
            totaldivisors*=2;
        }
    }
    cout<< endl << totaldivisors<<endl;
}
//30: 9,4,6,11
//31: 1,3,5,7,8,10,12
//28-29: 2
int main()
{
    // 1 (day)/1(month)/1900(year):1(day of the weak) (sunday as 0 being the first)
    // 2/1/1900 -> 2
    // n/1/1900 -> n%7
    int day_of_the_weak = 1;
    int identity_sum=0;
    for (int year=1900; year<=2000; year++){
        for (int month=1; month<=12; month++) {
            switch (month) {
                case 4:
                case 6:
                case 9:
                case 11:
                    for (int day=1; day<=30; day++) {
                        if ( ((day_of_the_weak++)%7)==0 && day==1 && (year>1900)) identity_sum++;
                    }
                    break;
                case 2:
                    if (year%4==0 && (year%100!=0 || year%400==0)) {
                        for (int day=1; day<=29; day++) {
                            if ( ((day_of_the_weak++)%7)==0 && day==1 && (year>1900)) identity_sum++;
                        }
                    }
                    else {
                        for (int day=1; day<=28; day++) {
                            if ( ((day_of_the_weak++)%7)==0 && day==1 && (year>1900)) identity_sum++;
                        }
                    }
                    break;
                default:
                    for (int day=1; day<=31; day++){
                        if ( ((day_of_the_weak++)%7)==0 && day==1 && (year>1900)) identity_sum++;
                    }
                    break;
            }
        }
    }
    cout << identity_sum<<endl;
    return 0;
}
