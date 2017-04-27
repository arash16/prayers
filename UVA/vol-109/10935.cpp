#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n, ar[50];
    while (cin>>n && n) {
        cout << "Discarded cards:";

        for (int i=0; i<n; i++)
            ar[i] = (i+1)%n;

        int ind = 0, prev = n-1;
        for (int i=0; i<n-1; i++) {
            cout << (i ? ", " : " ") << ind+1;
            ar[prev] = ar[ind];
            ind = ar[prev = ar[ind]];
        }
        cout << "\nRemaining card: " << ind+1 << endl;
    }
}
