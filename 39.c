
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

int main () {
    
    InfInt temp;
    int p, b,a, max, num, p_max;
    for (p=10; p<=1000; p++) {
        num=0;
        for (a=p/2; a>=p/4 ; a--){
            for (b=1; b<=a; b++ ){
                if (a*2*p+b*2*p-2*a*b-p*p==0) num++;
            }
        }
        if (num>max) {
            max=num;
            p_max = p;
        }
    }
    cout<< p_max;
}