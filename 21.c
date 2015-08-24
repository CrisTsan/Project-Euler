
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include "InfInt.h"
#include <assert.h>
#define MAX 100

using namespace std;

int divisors(int i) {
    int k,sum=0;
    
    for (k=1; k<=i/2; k++) {
        if (i%k==0) sum+=k;
    }
    return sum;
}

int main() {
    int i,sum=0;
    for (i=1; i<=10000; i++) {
        if (divisors(divisors(i))==i && divisors(i) != i) sum+=i;
    }
    cout << sum;
    
    
}

