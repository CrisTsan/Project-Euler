#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int current=2,
        previus=1,
        sum=0;
    
    while (current<=4000000) {
        if ( current%2==0) {
            sum+=current;
        }
        current=previus+current;
        previus=current-previus;
    }
    cout << sum;
    return 0;
}
