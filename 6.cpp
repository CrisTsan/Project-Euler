#include <iostream>
#include <math.h>       /* pow */

using namespace std;
typedef unsigned long long int BIIG;



int main(int argc, const char * argv[])
{
    BIIG sum1=0,
         sum2=((1+100)*100/2)*((1+100)*100/2);
    for (int i=1; i<=100; i++) {
        sum1 += i*i;
    }
    cout << sum1-sum2;
    return 0;
}
