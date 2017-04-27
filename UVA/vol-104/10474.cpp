#include <stdio.h>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int ar[10001];
int main(){
    int n, q, x;
    for(int cse=1; cin>>n>>q && (n||q); cse++) {
        for (int i=0; i<n; i++)
            cin>>ar[i];
        sort(ar, ar+n);

        cout<<"CASE# "<<cse<<":\n";
        for (int i=0; i<q; i++) {
            cin>>x;
            auto tt = equal_range(ar, ar+n, x);
            if (tt.first<tt.second)
                printf("%d found at %d\n", x, 1+(tt.first - ar));
            else
                printf("%d not found\n", x);
        }
    }
}
