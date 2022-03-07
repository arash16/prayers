/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 993
  Name: Product of digits
  Problem: https://onlinejudge.org/external/9/993.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n;
    int T;
    cin>>T;
    while (T--) {
        cin >> n;
        if (n<10) cout << n << endl;
        else {
            vector<int> result;
            for (int i=9; i>=2; i--)
                for (; n%i==0; n/=i)
                    result.push_back(i);

            if (n>1) puts("-1");
            else {
                for (int i=result.size()-1; i>=0; i--)
                    cout << result[i];
                cout << endl;
            }
        }
    }
}
