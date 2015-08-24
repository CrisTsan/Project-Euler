
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include "InfInt.h"
#include <assert.h>
#define MAX  600851475143

using namespace std;





int main () {
    
    long long int num = MAX,divisor=2,B;
    while (divisor<=num/2){
        if (num % divisor == 0) {
            num /= divisor;
            B=divisor;
            divisor=2;
        }
        else divisor++;
    }
    B = num;
    cout << B <<endl;
}