#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXN 10000
#define MAXL 200
char tl[MAXL];
char names[MAXN][MAXL];
double p[MAXN];
int fc[MAXN];

int main(){
    int cse = 1, n, f;
    bool f1 = true;
    while (cin>>f>>n && (f||n)) {
        for (int i=0; i<=f; i++)
            cin.getline(tl, MAXL);

        int maxf = 0;
        for (int i=0; i<n; i++) {
            cin.getline(names[i], MAXL);
            cin >> p[i] >> fc[i];
            if (fc[i] > maxf) maxf=fc[i];
            for (int j=0; j<=fc[i]; j++)
                cin.getline(tl, MAXL);
        }

        int si=-1;
        for (int i=0; i<n; i++)
            if (fc[i] == maxf)
                if (si<0 || p[i]<p[si])
                    si = i;

        if (f1) f1 = false;
        else cout << endl;
        printf("RFP #%d\n%s\n", cse++, names[si]);
    }
}
