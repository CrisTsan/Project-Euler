
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include "InfInt.h"
#include <assert.h>
#define MAX  8

using namespace std;

char limit[1000]={0};


int num_of_digits(int n)
{
    return log10(n)+1;
}
int get_nth_digit(int number,int n)
{
    return (number/((int)pow(10,n-1)))%10;
    
}

int convergence(int num){
    int temp1=0,temp2=0,temp3=0;
    if (limit[num]==0) {
        temp1= get_nth_digit(num,1);
        if (num<100) {
            temp2= get_nth_digit(num,2);
        }
        else if (num<1000) {
            temp2= get_nth_digit(num,2);
            temp3= get_nth_digit(num,3);
        }
        
        return convergence( temp1*temp1+temp2*temp2+temp3*temp3 );
        
    }
    else if (limit[num]==1) return 1;
    else if (limit[num]==89) return 89;
    else return 0;
}

int main () {
    int i,j,k,l,m,n,o,sum=0;
    limit[0]=0;
    limit[1]=1;
    limit[89]=89;
    //    for (i=0; i<=9; i++) {
    //        for (j=0; j<=9; j++) {
    //            for (k=0; k<=9; k++) {
    //                i+j*10+k*100;
    //            }
    //        }
    //    }
    for (i=1; i<=999; i++) {
        limit[i]=convergence(i);
    }
    //     cout << get_nth_digit(179, 3);
    
    for (i=0; i<=9 ; i++) {
        for (j=0; j<=9 ; j++) {
            for (k=0; k<=9 ; k++) {
                for (l=0; l<=9 ; l++) {
                    for (o=0; o<=9 ; o++) {
                        for (m=0; m<=9 ; m++) {
                            for (n=0; n<=9 ; n++) {
                                //i+10*j+100*k+1000*l+10000*o+100000*m+1000000*n;
                                if (limit[i*i+j*j+k*k+l*l+o*o+m*m+n*n]==89) sum++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << sum<<endl;
}