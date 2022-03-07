/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10113
  Name: Exchange Rates
  Problem: https://onlinejudge.org/external/101/10113.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int gcd(int a, int b) {
    if (a==0) return b;
    return gcd(b%a, a);
}


int gr[100], den[100], num[100];
int find(int u) {
    if (gr[u] == u) return u;

    int v = find(gr[u]);
    if (gr[u] != v) {
        num[u] *= num[gr[u]];
        den[u] *= den[gr[u]];
        int gc = gcd(num[u], den[u]);
        num[u] /= gc;
        den[u] /= gc;
        gr[u] = v;
    }
    return v;
}

void join(int x, int u, int y, int v) {
    int ug = find(u);
    gr[ug] = find(v);

    int nu = num[v] * den[u] * x,
        de = num[u] * den[v] * y,
        gc = gcd(nu, de);
    num[ug] = nu/gc;
    den[ug] = de/gc;

}



int cnt=0;
map<string, int> ids;
int getId(string name) {
    auto it = ids.find(name);
    if (it != ids.end())
        return it->second;
    return ids[name] = cnt++;
}


int main(){
    for (int i=0; i<100; i++) {
        den[i] = num[i] = 1;
        gr[i] = i;
    }

    int x, y, u, v;
    char cm, xs[30], ys[30];
    while (cin>>cm && cm!='.')
        if (cm == '!') {
            cin>>x>>xs >> cm >> y>>ys;
            join(x, getId(xs), y, getId(ys));
        }

        else {
            cin>>xs >>cm>> ys;
            int u = getId(xs),
                v = getId(ys);

            if (find(u) != find(v))
                printf("? %s = ? %s\n", xs, ys);
            else {
                int gc = gcd( x = num[u]*den[v],
                              y = num[v]*den[u] );
                printf("%d %s = %d %s\n", x/gc, xs, y/gc, ys);
            }
        }
}
