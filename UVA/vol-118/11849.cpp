/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11849
  Name: CD
  Problem: https://onlinejudge.org/external/118/11849.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXN 1000001
int A[MAXN], B[MAXN];

int main(){
    int n, m;
    while (cin>>n>>m && (n || m)) {
        for (int i=0; i<n; i++)
            cin>>A[i];

        for (int j=0; j<m; j++)
            cin>>B[j];

        int cnt = 0;
        for (int i=0, j=0; i<n && j<m;)
            if (A[i]==B[j]) {
                cnt++;
                i++;
                j++;
            }
            else if (A[i] < B[j])
                 i++;
            else j++;

        cout << cnt << endl;
    }
}
