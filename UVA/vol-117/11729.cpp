#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int B[1001], J[1001], ord[1001];
bool comp(int i, int j) {
    return J[i] != J[j] ? J[i] > J[j] : B[i] < B[j];
}

int main(){
    int cse=1, n;
    while (cin>>n && n) {
        for (int i=0; i<n; i++) {
            cin>> B[i] >> J[i];
            ord[i] = i;
        }
        sort(ord, ord+n, comp);

        int s=0, mx=0;
        for (int i=0; i<n; i++) {
            int j = ord[i];
            s += B[j];
            mx = max(mx, s + J[j]);
        }
        printf("Case %d: %d\n", cse++, mx);
    }
}
