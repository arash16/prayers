#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n, d, ind;
    int seen[3001], p[100];
    while (cin>>n>>d) {
        for (int i=0; i<d; i++) seen[i]=-1;
        printf("%d/%d = %d.", n, d, n/d);
        n = n%d;


        for (ind=0; seen[n] < 0; ind++) {
            seen[n] = ind;

            n = n*10;
            if (ind < 50)
                p[ind] = n/d;
            n = n%d;
        }

        for (int i=0; i<seen[n]; i++)
            cout << p[i];
        cout << '(';

        for (int i=seen[n]; i<min(ind, 50); i++)
            cout << p[i];
        if (ind > 50)
            cout << "...";
        cout << ')' << endl;

        printf("   %d = number of digits in repeating cycle\n\n", ind-seen[n]);
    }
}
