
#define max 50
int main () {
    int counter=0,temp1,temp2,temp3;
    for ( int x1=0; x1<= max; x1++) {
        for (int y1=0; y1<=max; y1++) {
            for (int x2=0; x2<=max; x2++) {
                for (int y2=0; y2<=max; y2++) {
                    if (
                        (temp1= distSquareMin(x1, y1))+(temp2=distSquareMin(x2, y2)) == (temp3=distSquare(x1,y1,x2,y2)) || temp1+temp3==temp2 || temp2+temp3==temp1
                        )
                    {
                        if (x1*y2-x2*y1==0) continue; //checking if collinear
                        counter++;
                        cout<< "(" << x1 << ","<<y1<<"), ("<<x2<<","<<y2<<")"<< endl;
                    }
                }
            }
        }
        
    }
    
    cout <<counter/2;
}

