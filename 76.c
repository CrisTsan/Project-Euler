
#define goal 100

int globCounter = 0;

void rec (int state,int max) {
    int i=1;
    if (goal == state) { globCounter++; return; }
    else if (goal < state) return;
    else {
        for (; i<=max;i++) {
            rec(state+i,i);
        }
    }
}
int main () {
    rec (0,goal);
    cout<<globCounter-1;
    
}

