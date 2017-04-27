#include <stdio.h>
#include <iostream>
using namespace std;

#define EPS 1e-7

double sqr(double x) { return x*x; }

bool leftTurn(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1) > EPS;
}

struct Shape {
    char type;
    double x[3], y[3];

    bool has(double xx, double yy) {
        switch (type) {
            case 'c':
                return sqr(xx-x[0]) + sqr(yy-y[0]) < sqr(x[1]);

            case 'r':
                return xx>x[0] && xx<x[1] && yy>y[0] && yy<y[1];

            case 't':
                return leftTurn( x[0], y[0], x[1], y[1], xx, yy )
                    && leftTurn( x[1], y[1], x[2], y[2], xx, yy )
                    && leftTurn( x[2], y[2], x[0], y[0], xx, yy );
        }
        return false;
    }
};

Shape sh[100];

int main(){
    int n;
    char t;
    for (n=0; cin>>t && t!='*'; n++) {
        Shape &s = sh[n];
        s.type = t;

        cin >> s.x[0] >> s.y[0] >> s.x[1];
        if (t == 'r') {
            cin >> s.y[1];

            if (s.x[0]>s.x[1])
                swap(s.x[0], s.x[1]);

            if (s.y[0]>s.y[1])
                swap(s.y[0], s.y[1]);
        }

        else if (t == 't') {
            cin >> s.y[1] >> s.x[2] >> s.y[2];
            if (!leftTurn(s.x[0], s.y[0], s.x[1], s.y[1], s.x[2], s.y[2])) {
                swap(s.x[0], s.x[1]);
                swap(s.y[0], s.y[1]);
            }
        }
    }

    int cse = 0;
    double x, y;
    while (cin>>x>>y && (x!=9999.9 || y!=9999.9)) {
        cse++;
        bool outer = 1;
        for (int i=0; i<n; i++)
            if (sh[i].has(x, y)) {
                printf("Point %d is contained in figure %d\n", cse, i+1);
                outer = 0;
            }

        if (outer) printf("Point %d is not contained in any figure\n", cse);
    }
}

