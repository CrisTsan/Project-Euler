#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1020
using namespace std;

int main() {
    long long int counter=0;
    
    // 1+8(1+n)n/2
    // 1+8(1+n)n/2-2n
    // 1+8(..  -4n
    // .. -6n
    
    for (int i=1; i<=500; i++ )
    {
        counter+=4+32*(1+i)*i/2-12*i;
    }
    cout<<counter+1<<endl;
}

