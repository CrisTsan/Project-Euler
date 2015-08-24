int main()
{
    //28433×2^7830457+1.
    long long int num=2;
    
    for (int i=1; i<=7830456; i++) {
        num= num<<1;
        if (num>10000000000) num=num-10000000000;
        
    }
    num *= 28433;
    num +=1;
    cout <<num;
}