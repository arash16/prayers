#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    string str;
    while (T-- && cin >> str) {
        int s1=0, s2=0;
        for (int i=0; i<3; ++i)
            s1 = s1*26 + str[i]-'A';
        for (int i=4; i<8; ++i)
            s2 = s2*10 + str[i]-'0';

        cout << (abs(s1-s2)<=100 ? "nice\n" : "not nice\n");
    }
}
