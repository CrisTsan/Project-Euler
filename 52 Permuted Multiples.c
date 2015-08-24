#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1020
using namespace std;

int binary_bits(long int binary) {
    return floor(log2(binary))+1;
}

bool value_of_nth_bit(long int binary,int bit) {
    return binary & (1 << (bit));
}

bool binary_palindrome(int binary) {
    int bits = binary_bits(binary);
    
    if (bits%2==0) {
        for (int i=1; i<=bits/2; i++) {
            if (value_of_nth_bit(binary, i-1)!=value_of_nth_bit(binary, bits-i)) return false;
        }
        return true;
    }
    else {
        for (int i=1; i<=bits/2; i++) {
            if (value_of_nth_bit(binary, i-1)!=value_of_nth_bit(binary, bits-i)) return false;
        }
        return true;
    }
}

bool check_palindrome(int n){
    int reverse=0, rem,temp;
    temp=n;
    while(temp!=0)
    {
        rem=temp%10;
        reverse=reverse*10+rem;
        temp/=10;
    }
    /* Checking if number entered by user and it's reverse number is equal. */
    if(reverse==n)
        return true;
    else
        return false;
}
int main() {
    long int counter=0;
    cout << binary_palindrome(2) << endl;
    cout << binary_palindrome(5) << endl;
    cout << binary_palindrome(4) << endl;
    for (int i=1; i<1000000; i++){
        if (binary_palindrome(i) && check_palindrome(i)) {
            counter+=i;
        }
    }
    cout<<counter<<endl;
}

