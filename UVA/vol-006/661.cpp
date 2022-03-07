/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 661
  Name: Blowing Fuses
  Problem: https://onlinejudge.org/external/6/661.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n, m, c, cse=1, f[100];
    bool state[100];
    while(cin>>n>>m>>c && (n||m||c)) {
        for (int i=0; i<n; i++) {
            state[i] = false;
            cin>>f[i];
        }

        int sum=0, maxs=0, oi;
        for (int i=0; i<m; i++) {
            cin >> oi;oi--;
            if (maxs<=c) {
                if (state[oi]) sum-=f[oi];
                else {
                    sum+=f[oi];
                    if (sum>maxs) maxs=sum;
                }

                state[oi] = !state[oi];
            }
        }

        cout << "Sequence " << (cse++) << endl;
        if (maxs>c) cout << "Fuse was blown.\n\n";
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", maxs);
    }
}
