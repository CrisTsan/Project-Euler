
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


int num_of_digits(int n)
{
    return log10(n)+1;
}
int get_nth_digit(int number,int n)
{
    return (number/((int)pow(10,n-1)))%10;
}

int main () {
    long int sum=-3;
    int x[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    int dig[10] = {0},digs[10],temp,temp2;
    int total=0;
    bool checker=false;
    for (dig[0]=0; dig[0]<=MAX; dig[0]++) {
        for (dig[1]=0; dig[1]+dig[0]<=MAX; dig[1]++) {
            for (dig[2]=0; dig[1]+dig[0]+dig[2]<=MAX; dig[2]++) {
                
                for (dig[3]=0; dig[1]+dig[0]+dig[2]+dig[3]<=MAX; dig[3]++) {
                    
                    for (dig[4]=0; (dig[1]+dig[0]+dig[2]+dig[3]+dig[4])<=MAX; dig[4]++) {
                        
                        for (dig[5]=0;(dig[1]+dig[0]+dig[2]+dig[3]+dig[4]+dig[5])<=MAX; dig[5]++) {
                            
                            for (dig[6]=0; (dig[1]+dig[0]+dig[2]+dig[3]+dig[4]+dig[5]+dig[6])<=MAX; dig[6]++) {
                                
                                for (dig[7]=0;(dig[1]+dig[0]+dig[2]+dig[3]+dig[4]+dig[5]+dig[6]+dig[7])<=MAX; dig[7]++) {
                                    
                                    for (dig[8]=0; (dig[1]+dig[0]+dig[2]+dig[3]+dig[4]+dig[5]+dig[6]+dig[7]+dig[8])<=MAX; dig[8]++) {
                                        
                                        for (dig[9]=0;(dig[1]+dig[0]+dig[2]+dig[3]+dig[4]+dig[5]+dig[6]+dig[7]+dig[8]+dig[9])<=MAX; dig[9]++) {
                                            //cout << dig[0] << " " << dig[1]<< " "  << dig[2]<< " "  << dig[3]<< " "  <<dig[4]<< " " <<dig[5]<< " " <<dig[6]<< " " <<dig[7]<< " " <<dig[8]<< " " <<dig[9]<<endl;
                                            
                                            (temp=dig[0]*x[0]+dig[1]*x[1]+dig[2]*x[2]+dig[3]*x[3]+dig[4]*x[4]+dig[5]*x[5]+dig[6]*x[6]+dig[7]*x[7]+dig[8]*x[8]+dig[9]*x[9]);
                                            
                                            
                                            if ((temp2=num_of_digits(temp))==dig[1]+dig[0]+dig[2]+dig[3]+dig[4]+dig[5]+dig[6]+dig[7]+dig[8]+dig[9]){
                                                //  cout << temp << endl;
                                                for (int i=0; i<=9; i++ ) digs[i]=dig[i];
                                                
                                                for (int i=temp2; i>0 ; i--) {
                                                    
                                                    digs[get_nth_digit(temp,i)]--;
                                                }
                                                //
                                                checker=true;
                                                for (int i=0; i<=9; i++) {
                                                    if (digs[i]!=0) {
                                                        checker=false;
                                                        
                                                    }
                                                }
                                                if (checker) { sum+=temp;
                                                    cout<< temp <<endl;
                                                }
                                            }
                                            //  cout << temp <<endl;
                                        }
                                        
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
        }
        
    }
    cout <<sum;
    
}