
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "InfInt.h"

#include <assert.h>

#define MAXD 21// 21
#define MAX 80

using namespace std;

InfInt Paths[MAXD][MAXD]={0};


InfInt ways(int i,int j) {
    if (j==0 || i==0) {
        return 1;
    }
    else {
        if (Paths[i][j]!=0) return Paths[i][j];
        else return ways(i-1,j)+ways(i,j-1);
    }
    
}


int main() {
    
    for (int i=0; i<=MAXD; i++ ) {
        for (int j=0; j<=MAXD; j++) {
            Paths[i][j] = ways(i,j);
        }
    }
    
    cout << Paths[20][20].toString() <<endl;
    
    //    string test1,test2;
    //    long double number[1000];
    //
    //    for (int i=0; i<999; i++) {
    //        getline(cin,test1,',');
    //        getline(cin,test2);
    //
    //        number[i]=log(stoi(test1))*stoi(test2);
    //        cout<< log(stoi(test1))*stoi(test2) <<endl;
    //    }
    
    //    cout << (log(632382)*518061>log(519432)*525806)<<endl;
}

