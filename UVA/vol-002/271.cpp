#include <bits/stdc++.h>
using namespace std;


bool check(const char s[]) {
    int toSee = 1;
    for (int i=0; s[i]; ++i) {
        if (!toSee) return 0;

        char ch = s[i];
        if (ch>='p' && ch<='z') --toSee;
        else if (ch=='C' || ch=='D' || ch=='E' || ch=='I') ++toSee;
        else if (ch!='N') return 0;
    }
    return !toSee;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char str[1024];
    while (cin >> str)
        cout << (check(str) ? "YES\n" : "NO\n");
}
