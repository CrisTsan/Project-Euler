#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1020
using namespace std;


int find_the_digit(int n) {
    int temp=n;
    if (n<=9){
        return n;
    }
    else if (n<=189){
        n = n-10;
        cout<<  "digit:" << n%2 <<endl;
        return (n/2)+10;
        
    }
    else if (n<=2889){
        n = n-190;
        cout<<  "digit:" << n%3 <<endl;
        return (n/3)+100;
    }
    else if (n<=38899){
        n = n-2890;
        cout<<  "digit:" << n%4 <<endl;
        return (n/4)+1000;
    }
    else if (n<=488899){
        n = n-38900;
        cout<<  "digit:" << n%5 <<endl;
        return (n/5)+10000;
    }
    else if (n<=5888899){
        n = n-488900;
        cout<<  "digit:" << n%6 <<endl;
        return (n/6)+100000;
    }
    return n;
}
int main() {
    //    cout<<    find_the_digit(2890)<<endl;
    
    //    for (int i=1; i<1000000; i++) {
    //        cout<<    find_the_digit(i)<<endl;
    //
    //    }
    //    long long int counter=0;
    cout<<    find_the_digit(1)<<endl;
    cout<<    find_the_digit(10)<<endl;
    cout<<    find_the_digit(100)<<endl;
    cout<<    find_the_digit(1000)<<endl;
    cout<<    find_the_digit(10000)<<endl;
    cout<<    find_the_digit(100000)<<endl;
    cout<<    find_the_digit(1000000)<<endl;
    
}

