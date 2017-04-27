#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n, k, x;
    while (cin>>n>>k) {
        int result = 1;
        for (int i=2; i<=n; i++)
            result *= i;

        for (int i=0; i<k; i++) {
            cin >> x;
            for (int j=2; j<=x; j++)
                result /= j;
        }
        cout << result << endl;
    }
}
