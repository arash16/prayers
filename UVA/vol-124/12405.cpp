#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char line[200];
    int T, n;
    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        cin >> n >> line;

        int rs=0, res=0;
        for (int i=0; i<n; i++)
            if (line[i] == '.' || (rs>0 && i>0 && i<n-1 && line[i-1]=='.' && line[i+1]=='.')) {
                if (3 == ++rs) {
                    rs = 0;
                    res++;
                }
            }
            else if (rs) {
                rs = 0;
                res++;
            }

        if (rs>0) res++;
        printf("Case %d: %d\n", cse, res);
    }
}
