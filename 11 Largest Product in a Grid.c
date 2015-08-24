#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// 0 Για άγνωστο
// 1 Για Σύνθετο
// 5 Για Πρώτο

int main(){
    int P[20][20];
    int i,j,max1=0,max2=0,max3=0,max4=0,new;
    
    for (i=0; i<=19; i++ )
        for (j=0; j<=19; j++)
          scanf("%d",&P[i][j]); 
   
    //Αναζήτηση Γινομένων Διαγωνίων
    for (i=0; i<=16; i++)
        for (j=0; j<=16; j++)
            if ( (new=P[i][j]*P[i+1][j+1]*P[i+2][j+2]*P[i+3][j+3])>max1) max1=new;
    printf("%d", max1);
    //Αναζήτηση Γινομένων Αντιθετων Διαγωνίων
    for (i=0; i<=16; i++)
        for (j=0; j<=16; j++)
            if ( (new=P[i][j+3]*P[i+1][j+2]*P[i+2][j+1]*P[i+3][j])>max4) max1=new;
    printf("%d", max4);
    //Αναζήτηση Γινομένων Οριζοντίων
    for (i=0; i<=19; i++)
        for (j=0; j<=16; j++)
            if ( (new=P[i][j]*P[i][j+1]*P[i][j+2]*P[i][j+3])>max2) max2=new;
    printf("%d", max2);

    //Αναζήτηση Κάθετων Γινομένων
    for (i=0; i<=16; i++)
        for (j=0; j<=19; j++)
            if ( (new=P[i][j]*P[i+1][j]*P[i+2][j]*P[i+3][j])>max2) max3=new;
    printf("%d", max3);

    
}
