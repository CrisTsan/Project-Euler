
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
    int index=0,word_sum,i=1;
    int is_it_triangular[391]={0};
    InfInt sum=0;
    string line,dumb;
    
    
    
    
    
    ifstream myfile ("/Users/SubtleX/Documents/Apps Development/obj-C/Projects/ΗυπνοΝερδ/CPP_Programs_ProjectEuler/CPP_Programs_ProjectEuler/ordered_file.txt");
    
    while ( (i*i+i)/2<391 ) {
        is_it_triangular[(i*i+i)/2]=1;
        i++;
    }
    
    
    if (myfile.is_open())
    {
        while (getline (myfile,dumb)){
            word_sum=0;
            index++;
            for (i=0; i<dumb.length(); i++) {
                word_sum += dumb[i]-'A'+1;
            }
            //            cout<<index<<":"<<dumb << " " << word_sum<<endl;
            if (is_it_triangular[word_sum]) sum++;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    string some=sum.toString();
    cout<< some;
}