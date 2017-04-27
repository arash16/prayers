#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n, x, cse=1;
    while(cin>>n && n) {
        int c = 0;
        for (int i=0; i<n; i++) {
            cin>>x;
            if (x==0) c++;
        }

        printf("Case %d: %d\n", cse++, n - 2*c);
    }
}
