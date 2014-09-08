#include <iostream>
#include <math.h>       /* pow */

using namespace std;
typedef unsigned long long int BIIG;



short numDigits(BIIG numb) {
    BIIG i=1;
    short sz=1;
    while (numb/(i*=10)) sz++;
    return sz;
}
short getDigitInPosition(BIIG numb,int pos) {
    return (numb%((BIIG) pow(10,pos))-numb%((BIIG) pow(10,pos-1)))/(((BIIG) pow(10,pos-1)));
}

bool checkIfPalindrome(BIIG numb) {
    short dig = numDigits(numb),temp=dig;
    while ( temp>=(dig/2)) {
        if ( getDigitInPosition(numb, temp) != getDigitInPosition(numb, dig-temp+1)) return false;
        temp--;
    }
    return true;
}

int main(int argc, const char * argv[])
{
    BIIG max=1;
    // 999,999 -> 999, 998 -> 998,998 -> 998, 997 --> 997,997
    for (int i=999; i>100; i--){
        for (int j=999; j>100; j--){
            if (checkIfPalindrome(j*i) && j*i>max) {
                max = j*i;
            }
        }
    }
    cout << max;
    return 0;
}

