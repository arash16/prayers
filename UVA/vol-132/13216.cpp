#include <bits/stdc++.h>
using namespace std;


int X[] = { 56, 96, 36, 76, 16 };
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    string S;
    while (T-- && cin >> S) {
        if (S == "0") cout << "1\n";
        else if (S == "1") cout << "66\n";
        else cout << X[(S[S.length()-1]-'0'+8)%5] << endl;
    }
}
