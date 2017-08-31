#include <bits/stdc++.h>
using namespace std;


int V[128];
bool check(char s[], int base) {
    int M = base - 1;
    int R = 0;
    for (int i=0; s[i]; ++i)
        R = (R*base + V[s[i]]) % M;

    return !R;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i='0'; i<='9'; ++i)
        V[i] = i-'0';
    for (int i='A'; i<='Z'; ++i)
        V[i] = 10+i-'A';
    for (int i='a'; i<='z'; ++i)
        V[i] = 36+i-'a';


    char s[100000];
    while (cin >> s) {
        int mnbase = 1;
        for (int i=0; s[i]; ++i)
            mnbase = max(mnbase, V[s[i]]);

        for (int i=mnbase+1; i<63; ++i)
            if (check(s, i)) {
                cout << i << endl;
                goto fin;
            }
        cout << "such number is impossible!\n";
        fin:;
    }
}
