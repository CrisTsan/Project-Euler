
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


int main () {
    
    InfInt temp;
    int i,k,num,i_2,j_2,k_2,num2,num3;
    int digits[10]={0};
    bool okay=false;
    int sum=0;
    //    for (i=1; i<=9; i++) {
    //
    //        for (k=1; k<=9; k++) {
    //            if (k==i) continue;
    //            num = 10*i+k;
    //
    //            for (i_2=1; i_2<= (int)(10000/(num*100));  i_2++){
    //                if (i_2 == i || i_2==k) continue;
    //
    //
    //                for (j_2=1; j_2<10; j_2++){
    //                    if (j_2 == i || j_2==k || j_2==i_2) continue;
    //
    //                    for (k_2=1; k_2<10; k_2++){
    //                        if (k_2 == i || k_2==k || k_2==i_2 || k_2==j_2) continue;
    //                        num2=i_2*100+j_2*10+k_2;
    //
    //                        //                        cout << num2 << " " << num <<endl;
    //                        num3=num2*num;
    //                        if (dinstict_digits_after_concatenation(num3,num2) && dinstict_digits_after_concatenation(num3, num) && !has_zeros(num3))
    //                            cout<< num3 << " "<<num << "*" <<num2<<endl;
    //                    }
    //
    //                }
    //
    //            }
    //
    //        }
    //    }
    
    
    for (i=11; i<=99;i++) {
        if ( i%10 == i/10 || has_zeros(i)) continue;
        for (int j=10000/(i); j>=100; j--) {
            if (!distinct_digits(j) || has_zeros(j)) continue;
            
            if (dinstict_digits_after_concatenation(i, j) &&  dinstict_digits_after_concatenation(i*j, i) && dinstict_digits_after_concatenation(i*j, j) && !has_zeros(i*j) )
            {
                cout << i << " " << j << " " << i*j <<endl;
                
            }
        }
    }
    
    for (i=1; i<=9;i++) {
        for (int j=10000/(i); j>=1000; j--) {
            if (!distinct_digits(j) || has_zeros(j)) continue;
            
            if (dinstict_digits_after_concatenation(i, j) &&  dinstict_digits_after_concatenation(i*j, i) && dinstict_digits_after_concatenation(i*j, j) && !has_zeros(i*j) )
            {
                cout << i << " " << j << " " << i*j <<endl;
            }
        }
    }
    
    cout << sum;
    
}

