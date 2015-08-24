#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200
using namespace std;

class superint {
    
    int digits[MAX];
    int total_digits=0;
    
public:
    
    // Overloaded
    superint operator + (superint);             //  superint + superint
    superint operator + (long unsigned);        //  superint + number
    superint & operator = (const superint&);    //  superint = superint
    superint & operator = (long unsigned );     //  superint = number
    
    superint operator * (int);             //  superint * superint

    //Constructors
    superint () ;
    
    //Methods
    void fix();
    void countdigits();
    void tozero();
    void print();
    unsigned int sumofdigits();
};


superint :: superint () {
    tozero();
}


superint superint::operator+ (superint param) {
    superint temp;
    int helper;
    for (int i=0; i<MAX-1; i++) {
        temp.digits[i] += (helper=this->digits[i]+param.digits[i])%10;
        temp.digits[i+1] = helper/10;
    }

    return (temp);
}

superint superint::operator+ (long unsigned x) {
    superint temp,result;
    temp = x;
    result = temp+*this;
    return result;
}

superint superint::operator* (int x) {
    superint temp;
    temp=0;
    for (int i=0; i<x; i++) {
        temp= temp+(*this);
    }
    return temp;
}

superint& superint::operator= (const superint& param)
{
    for (int i=0; i<MAX; i++) {
        this->digits[i] = param.digits[i];
    }
    return *this;
}

superint& superint::operator= (long unsigned x)
{
    int pl=0;
    while (x>0) {
        
        this->digits[pl]= x%10;
        x /= 10;
        pl++;
    }
    total_digits=pl;
    
    return *this;
}

void superint::print() {
    this->fix();
    this->countdigits();
    
    if (total_digits==0) cout << 0;
    for (int i=total_digits-1; i>=0; i--) cout << digits[i];
    cout << endl;
}

void superint::tozero() {
    for (int i=0; i<MAX; i++) digits[i]=0;
}

void superint::countdigits() {
    int x = MAX-1;
    for ( ; digits[x]==0; x--);
    total_digits = x+1;
}

void superint::fix() {
    countdigits();
    for ( int i=0; i<total_digits; i++ ) {
        if ( digits[i]>=10)
        {
            digits[i+1] += digits[i]/10;
            digits[i]%=10;
        }
        
    }
}

unsigned int superint::sumofdigits()
{
    unsigned int XX=0;
    countdigits();
    for ( int i=0; i<total_digits; i++ ) {
        XX+=digits[i];
    }
    return XX;
}



int main() {
    superint y,sum;
    y=1; sum=0;
    
    for (int i=2; i<=100; i++)
    {
        y = y*i;
    
    }
    y.print();
    cout << endl << y.sumofdigits();
}

