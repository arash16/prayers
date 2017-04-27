#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int dsum(int x) {
    if (x<10)
        return x;
    else if (x<100)
        return (x/10) + (x%10);

    int sum = 0;
    for(; x; x/=10)
        sum += x%10;
    return sum;
}

bool isSmith(int x) {
    int n = x;
    int ds = dsum(x);
    int sq = sqrt(double(x));
    for (int i=2; i<=sq; i++)
        if (x%i == 0) {
            int ds0 = dsum(i);
            do {
                ds -= ds0;
                if (ds<0) return 0;
                x /= i;
            } while (x%i == 0);
            sq = sqrt(double(x));
        }

    if (x == n) return 0;
    if (x > 1) ds -= dsum(x);
    return !ds;
}


int main(){
    int T, n, x;
    cin>>T;
    while (T--) {
        cin >> n;
        for (x=n+1; !isSmith(x); x++);
        cout << x << endl;
    }
}
