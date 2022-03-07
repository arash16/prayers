/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11417
  Name: GCD
  Problem: https://onlinejudge.org/external/114/11417.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int GCD[502][502];
int gcd(int a, int b) {
    if (!b) return a;
    if (GCD[a][b]) return GCD[a][b];
    return GCD[a][b] = gcd(b, a%b);
}

int main(){
    int n;
    while(cin>>n && n) {
        int sum=0;
        for (int i=1; i<n; i++)
            for(int j=i+1; j<=n; j++)
                sum+=gcd(i, j);

        cout<<sum<<endl;
    }
}
