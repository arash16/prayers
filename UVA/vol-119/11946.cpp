#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(100, '\n');

    char ch;
    char D[] = "OIZEASGTBP";
    while ( (ch=getchar()) != EOF )
        putchar(ch>='0' && ch<='9' ? D[ch-'0'] : ch);
}
