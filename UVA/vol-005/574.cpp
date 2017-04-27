#include <stdio.h>
#include <iostream>
using namespace std;

int t, n, cnt, nu[20], nuc[20], chosen[20], chcnt, ppp;
void rec(int sum, int ind) {
    if (sum<=0 || ind>=cnt) {
        if (!sum) {
            for (int i=0; i<chcnt; i++) {
                if (i) cout << '+';
                cout << chosen[i];
            }
            cout << endl;
            ppp++;
        }
        return;
    }

    for (int i=0; i<nuc[ind]; i++)
        chosen[chcnt+i] = nu[ind];

    int oldch = chcnt;
    for (int i=nuc[ind]; i>=0; i--) {
        chcnt = oldch + i;
        rec(sum - i*nu[ind], ind+1);
    }
}


int main(){
    while (cin>>t>>n && n) {
        cin >> nu[0];
        nuc[0] = 1;
        cnt = 1;
        for (int i=1; i<n; i++) {
            cin>>nu[cnt];
            if (nu[cnt] != nu[cnt-1])
                nuc[cnt++] = 1;
            else nuc[cnt-1]++;
        }

        printf("Sums of %d:\n", t);
        chcnt = ppp = 0;
        rec(t, 0);
        if (!ppp) puts("NONE");
    }
}
