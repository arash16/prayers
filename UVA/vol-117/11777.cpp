#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T, g[10];
    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        for (int i=0; i<7; i++)
            cin>>g[i];
        sort(g+4, g+7);
        double r = g[0]+g[1]+g[2]+g[3]+(g[5]+g[6])/2.0;
        printf("Case %d: ", cse);
        if (r>=90) cout << "A\n";
        else if (r>=80) cout << "B\n";
        else if (r>=70) cout << "C\n";
        else if (r>=60) cout << "D\n";
        else cout << "F\n";
    }
}
