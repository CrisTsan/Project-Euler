
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

int P[MAX][MAX]={0},SUM[MAX][MAX]={0};

int below_max_sum (int i, int j) {
    if (i==MAX-1) {
        return P[i][j];
    }
    else {
        return max(SUM[i+1][j]+P[i][j],P[i][j]+SUM[i+1][j+1]);
    }
}
int main() {
    
    
    int i,j;
    
    string line,dumb;
    ifstream myfile ("/Users/SubtleX/Documents/Apps Development/obj-C/Projects/ΗυπνοΝερδ/CPP_Programs_ProjectEuler/CPP_Programs_ProjectEuler/file.txt");
    if (myfile.is_open())
    {
        for (i=0; i<=MAX-1; i++) {
            for (j=0; j<=i; j++) {
                if (j==i) getline (myfile,dumb,'\n');
                else getline (myfile,dumb,' ');
                P[i][j]=stoi(dumb);
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    
    
    for (i=MAX-1; i>=0; i--){
        for (j=0; j<=i; j++) {
            SUM[i][j]=below_max_sum(i, j);
        }
    }
    cout<<SUM[0][0];
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

