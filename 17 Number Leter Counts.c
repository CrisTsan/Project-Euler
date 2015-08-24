#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AND 3

int main(void)

{
    int i1,i2,i3 ,mnum=0, num;
    char *ps[]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen"
        ,"fifteen", "sixteen","seventeen","eighteen","nineteen"};
    char *dek[]={"" , "" , "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};


    for ( i1=0; i1<= 9 ; i1++) {
        for (i2=0; i2<= 9 ; i2++) {
            for (i3=0; i3<=9 ; i3++ ) {
                
                num = 100*i1+10*i2+i3;
                mnum=10*i2+i3;
                if (num==0) continue;
                //Εκατοντάδα
                if ( num%100 == 0 ) { printf("%s hundred\n",ps[i1-1]); continue; }
                if (num>100) { printf("%s hundred and ",ps[i1-1]); }
                
                //Δεκάδα
                if (mnum>=10 && mnum<=19) { printf("%s\n",ps[mnum-1]); continue; }
                if ( num%10 == 0 ) { printf("%s\n",dek[i2]); continue; }
                if (i2>=2) { printf("%s ", dek[i2]); }
                
                //Μονάδα
                //Ειδικές Κατηγορίες
            
                
               
                printf("%s\n", ps[i3-1]);
            }
        }
    }
    
}