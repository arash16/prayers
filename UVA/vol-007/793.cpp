#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 10000000

int ids[MAXN];
int find(int i) {
    if (ids[i] == i) return i;
    return ids[i] = find(ids[i]);
}

void connect(int x, int y) {
    ids[find(x)] = find(y);
}

int main(){
    char line[100], tp;
    int T, n, x, y;
    cin>>T;
    while (T--) {
        cin>>n; cin.getline(line, 100);
        for (int i=0; i<=n+1; i++)
            ids[i] = i;

        int succ=0, fail=0;
        while (cin.getline(line, 100) && sscanf(line, "%c %d %d", &tp, &x, &y) == 3)
            if (tp=='q')
                if (find(x) == find(y))
                    succ++;
                else
                    fail++;
            else connect(x, y);
        cout<<succ<<","<<fail<<endl;
        if (T) cout << endl;
    }
}
