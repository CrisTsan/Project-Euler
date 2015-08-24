#include <stdio.h>

int main() {

    int P[100][50],sums[100]={0},NewD[100]={0},i,j,k,c;

    for (i=0; i<=99; i++)
    { //1
      
        for (j=0; j<=49; j++)
        { // 1.1
            while ((c=getchar())=='\n');
            P[i][j]= c-'0';
            sums[49-j] = P[i][j]+sums[49-j];
            
            /* πχ το sum[0] αναπαριστά
             το άθροισμα των τελευταίων
             ψηφίων. */
            
        } // 1.1
        
    } //1
    int ypol  = 0 ;
    for (i=0; i<=99 ; i++)
    { //2
       
        NewD[i]= (sums[i]+ypol)%10;
        ypol = (sums[i]+ypol)/10 ;
        if (i>49 && ypol==0) break;
        
    } //2
    for (k=i; k>=0 ; k--) printf("%d",NewD[k]);
}