#include <stdio.h>
#include <iostream>
using namespace std;

int insts[110];

int main(){
    int T, n, x;
    char cm[20];
    cin>>T;
    while (T--) {
        cin>>n;
        int p = 0;
        for (int i=0; i<n; i++) {
            cin>>cm;
            if (cm[0]=='R' || cm[0]=='r')
                p += (insts[i] = 1);
            else if (cm[0]=='L' || cm[0]=='l')
                p += (insts[i] = -1);
            else {
                cin >> cm >> x;
                p += (insts[i] = insts[x - 1]);
            }
        }
        cout << p << endl;
    }
}
