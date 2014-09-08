#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int thres = 1000,
        sum = 0,
        i;

    for (i=3; i<thres; i+=3) sum+=i;
    for (i=5; i<thres; i+=5) sum+=i;
    for (i=15; i<thres; i+=15) sum-=i;
    // insert code here...
    cout <<  sum;
    return 0;
}
