/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 116
  Name: Unidirectional TSP
  Problem: https://onlinejudge.org/external/1/116.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

inline int readchar(bool skip=true) {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    bool fin = 0;
    if (fin) return EOF;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) {
            fin = 1;
            return EOF;
        }
        p = buf;
    }
    int result = *p;
    if (skip) ++p;
    return result;
}
inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline bool readInt(int &r) {
    char ch;
    int sgn=1; r=0;
    while (!isdigit(ch=readchar()) && ch!='-')
        if (ch == EOF) return 0;
    if (ch == '-') sgn = -1;
    else r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';
    r *= sgn;
    return 1;
}

// ----------------------------------------------------------------


int Mat[12][102], m, n;
int DP[12][102];
int P[12][102];
int y[3];

int mod(int x, int y){
    return (x + y) % y;
}

bool les(int y,int x,int z){
    return DP[y][z] <= DP[x][z];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (readInt(m) && readInt(n)) {
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                readInt(Mat[i][j]);

        for (int i=0; i<m; i++)
            DP[i][n]=0;

        for (int j=n-1; j>=0; j--)
            for (int i=0; i<m; i++) {
                DP[i][j] = Mat[i][j];
                y[0] = mod(i-1,m);    //upper square
                y[1] = mod(i  ,m);    //right square
                y[2] = mod(i+1,m);    //lower square
                sort(y, y+3);

                if (les(y[0],y[1],j+1) && les(y[0],y[2],j+1)){
                    DP[i][j] += DP[y[0]][j+1];
                    P[i][j] = y[0];
                }
                else if (les(y[1],y[2],j+1) && les(y[1],y[0],j+1)){
                    DP[i][j] += DP[y[1]][j+1];
                    P[i][j] = y[1];
                }
                else if (les(y[2],y[1],j+1) && les(y[2],y[0],j+1)){
                    DP[i][j] += DP[y[2]][j+1];
                    P[i][j] = y[2];
                }
            }

        int my = 0;
        for (int i=1; i<m; i++)
            if (DP[i][0] < DP[my][0])
                my = i;
        int ans = DP[my][0];

        cout << my+1;
        for (int j=0; j<n-1; j++){
            my = P[my][j];
            cout << " " << my+1;
        }
        cout << "\n" << ans << "\n";
    }
}
