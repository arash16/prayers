#include <stdio.h>
#include <iostream>
using namespace std;

struct CR {
    bool R;
    double x1, y1, r;
    double x2, y2;

    bool includes (double x, double y) {
        if (R) return x>x1 && x<x2 && y>y1 && y<y2;

        double xx = x1-x, yy = y1-y;
        return xx*xx + yy*yy < r*r;
    }
};

CR figures[10];

int main(){
    int n;
    char t;
    for (n=0; cin>>t && t!='*'; n++) {
        cin >> figures[n].x1 >> figures[n].y1;
        if (t=='r') {
            figures[n].R = true;
            cin >> figures[n].x2 >> figures[n].y2;

            if (figures[n].x2 < figures[n].x1)
                swap(figures[n].x2, figures[n].x1);

            if (figures[n].y2 < figures[n].y1)
                swap(figures[n].y2, figures[n].y1);
        }
        else cin >> figures[n].r;
    }

    double x, y;
    for (int p=1; cin>>x>>y && (x!=9999.9 || y!=9999.9); p++) {
        bool inSome=false;
        for (int i=0; i<n; i++)
            if (figures[i].includes(x, y)) {
                printf("Point %d is contained in figure %d\n", p, i+1);
                inSome = true;
            }

        if (!inSome) printf("Point %d is not contained in any figure\n", p);
    }
}

