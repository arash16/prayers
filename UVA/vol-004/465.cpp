/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 465
  Name: Overflow
  Problem: https://onlinejudge.org/external/4/465.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXINT 2147483647

int len(char *s) {
    int i=0, l=0;
    for (; s[i] && s[i]=='0'; i++);
    for (; s[i]; i++) l++;
    return l;
}

int main(){
    long long int x1, x2;
    char line[100000], w1[10000], w2[10000], op;

    while (cin.getline(line, 100000) && line[0]) {
        if (sscanf(line, "%s %c %s", w1, &op, w2) == 3) {
            cout<<line<<endl;
            int l1 = len(w1),
                l2 = len(w2);

            sscanf(w1, "%lld", &x1);
            sscanf(w2, "%lld", &x2);

            bool f = false;
            if (l1>10 || x1>MAXINT)
                cout<<"first number too big\n", f=1;

            if (l2>10 || x2>MAXINT)
                cout<<"second number too big\n", f=1;

            if (!f)
                if (
                    (op=='*' && l1+l2>11) ||
                    (op=='+' ? x1+x2 : x1*x2)>MAXINT
                ) f=1;

            if (f && op=='*' && (!l1 || !l2)) f=0;
            if (f) cout << "result too big\n";
        }
    }
}
