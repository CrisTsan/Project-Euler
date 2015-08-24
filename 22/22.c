
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


int main () {
    int index=0,word_sum;
    InfInt sum=0;
    string line,dumb;
    ifstream myfile ("/Users/SubtleX/Documents/Apps Development/obj-C/Projects/ΗυπνοΝερδ/CPP_Programs_ProjectEuler/CPP_Programs_ProjectEuler/ordered_file.txt");
    if (myfile.is_open())
    {
        while (getline (myfile,dumb)){
            word_sum=0;
            index++;
            for (int i=0; i<dumb.length(); i++) {
                word_sum += dumb[i]-'A'+1;
            }
            //            cout<<index<<":"<<dumb << " " << word_sum<<endl;
            sum += index*word_sum;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    string some=sum.toString();
    cout<< some;
}