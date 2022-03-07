/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10249
  Name: The Grand Dinner
  Problem: https://onlinejudge.org/external/102/10249.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, tm[100], otm[100], tb[100], Ar[100][100], readd[100];
bool comp1(int i, int j) { return tm[i] > tm[j]; }
bool comp2(int i, int j) { return tb[i] < tb[j]; }


int main(){
    while (cin>>m>>n && (m||n)) {
        for (int i=0; i<m; i++) {
            cin>>tm[i];
            otm[i] = i;
        }
        sort(otm, otm+m, comp1);

        priority_queue<int, vector<int>, bool(*)(int, int)> tbq(comp2);
        for (int i=0; i<n; i++) {
            cin >> tb[i];
            tbq.push(i);
        }

        int possible=1;
        for (int i=0; i<m; i++) {
            int tmi = otm[i];
            if (tbq.size() < tm[tmi]) {
                possible = 0;
                break;
            }

            int cnt=0;
            for (int j=0; j<tm[tmi]; j++) {
                int tbi = Ar[tmi][j] = tbq.top(); tbq.pop();
                if (--tb[tbi])
                    readd[cnt++] = tbi;
            }

            for (int i=0; i<cnt; i++)
                tbq.push(readd[i]);
        }

        if (!possible) puts("0");
        else {
            puts("1");
            for (int i=0; i<m; i++) {
                cout << Ar[i][0]+1;
                for (int j=1; j<tm[i]; j++)
                    printf(" %d", Ar[i][j]+1);
                cout << endl;
            }
        }
    }
}
