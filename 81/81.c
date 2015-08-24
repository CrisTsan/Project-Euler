
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include "InfInt.h"
#include <assert.h>
#define MAX 80

using namespace std;

int P[MAX][MAX]={0},SUM[MAX][MAX]={0};

int below_min_sum (int i, int j) {
    if (i==MAX-1) {
        return P[i][j];
    }
    else {
        return min(SUM[i+1][j]+P[i][j],P[i][j]+SUM[i+1][j+1]);
    }
}
int main() {
    
    
    int i,j;
    string line,dumb;
    ifstream myfile ("/Users/SubtleX/Dropbox/Project Euler/81/p081_matrix.txt");
    string delimiter = ",";
    if (myfile.is_open())
    {
        for (i=0; i<=MAX-1; i++) {
            getline (myfile,line,'\n');
            for (j=0; j<=MAX-1; j++) {
                string token = line.substr(0, line.find(delimiter)); // token is "scott"
                P[i][j]=stoi(token);
                line.erase(0, token.length()+delimiter.length());
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    
    SUM[MAX-1][MAX-1] = P[MAX-1][MAX-1];
    
    //    for (i=MAX-1; i>=0; i--){
    //        for (j=0; j<=i; j++) {
    //            SUM[i][j]=below_max_sum(i, j);
    //        }
    //    }
    for (int sumoflines = 2*79; sumoflines>=0 ; sumoflines--) {
        for (i = 79; i>=0 && (sumoflines-i)<=79; i--) {
            j=sumoflines-i;
            if (j==79) {
                if (i==79) SUM[j][i] = P[j][i];
                else SUM[j][i] = P[j][i] + SUM[j][i+1];
            }
            else if (i==79) SUM[j][i] = P[j][i] +SUM[j+1][i];
            else SUM[j][i] = min( SUM[j+1][i] , SUM[j][i+1] )+P[j][i] ;
        }
    }
    cout<<SUM[0][0];
    
}

