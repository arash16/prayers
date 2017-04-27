#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int X[20002];
int main(){
    int T, n;
    cin>>T;
    while (T--) {
        cin>>n;
        for (int i=0; i<n; i++)
            cin>>X[i];
        sort(X, X+n);

        int sum = 0;
        for (int i=n%3; i<n; i+=3)
            sum += X[i];

        cout << sum << endl;
    }
}
