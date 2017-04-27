#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;

#define MAXL 10000

int n, c[10000];
long long f(int x) {
    long long r = 0;
    for (int i=0; i<n; i++)
        r = r*x + c[i];

    return r;
}

int main(){
    int x, fr1=1;
    char line1[MAXL], line2[MAXL];
    while (cin.getline(line1, MAXL) && cin.getline(line2, MAXL)) {
        stringstream sin1(line1);
        stringstream sin2(line2);
        for (n=0; sin1>>c[n]; n++);

        bool fr=1;
        while (sin2>>x) {
            if (fr) fr=0;
            else putchar(' ');
            cout << f(x);
        }
        putchar('\n');
    }
}
