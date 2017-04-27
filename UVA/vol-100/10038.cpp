#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int sub(int a, int b) {
    return a<b ? b-a : a-b;
}

bool bl[3001];
int main(){
    int n;
    while(cin>>n) {
        int cnt=0;
        if (!n) cout << "Jolly\n";
        else {
            for (int i=1; i<=n; i++)
                bl[i]=false;

            int x, y;
            cin >> x;
            for(int i=1; i<n; i++) {
                cin>>y;
                int d = sub(x, y);
                if (d>0 && d<n && !bl[d])
                    bl[d] = ++cnt;
                x = y;
            }
        }
        cout << ((cnt==n-1)?"Jolly\n":"Not jolly\n");
    }
}
