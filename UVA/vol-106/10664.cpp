#include <stdio.h>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

#define MAXL 10000

int A[22], n;
bool memo[414][22];
bool mindiff(int dif, int ind) {
    if (ind>=n) return !dif;

    int mid = 202+dif;
    if (memo[mid][ind]) return false;
    memo[mid][ind] = 1;

    if (mindiff(dif-A[ind], ind+1) || mindiff(dif+A[ind], ind+1))
        return true;

    return false;
}



int main(){
    int T;
    cin>>T;

    char line[MAXL];
    cin.getline(line, MAXL);
    while (T--) {
        cin.getline(line, MAXL);
        stringstream sin(line);

        for (n=0; sin>>A[n]; n++);
        memset(memo, 0, sizeof(memo));
        puts(mindiff(0, 0) ? "YES" : "NO");
    }
}
