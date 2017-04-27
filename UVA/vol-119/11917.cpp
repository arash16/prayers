#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int T, n, x;
    char str[100];
    scanf("%d", &T);
    for (int cse=1; cse<=T; ++cse) {
        printf("Case %d: ", cse);

        scanf("%d", &n);
        map<string, int> mp;
        for (int i=0; i<n; ++i) {
            scanf("%s%d", str, &x);
            mp[str] = x;
        }

        scanf("%d%s", &x, str);
        auto it = mp.find(str);
        if (it==mp.end() || it->second > x+5)
            puts("Do your own homework!");

        else if (it->second <= x) puts("Yesss");

        else puts("Late");
    }
}
