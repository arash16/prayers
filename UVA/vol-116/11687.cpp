#include <bits/stdc++.h>
using namespace std;


int digits(int x) {
    int c = 1;
    while (x > 9)
        x /= 10,
        c++;
    return c;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string inp;
    while (cin >> inp && inp!="END") {
        if (inp == "1") cout << "1\n";
        else {
            int i = 2, x = inp.length();
            while (x != 1)
                x = digits(x),
                i++;
            cout << i << endl;
        }
    }
}
