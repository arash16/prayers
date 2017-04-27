#include <stdio.h>
#include <iostream>
using namespace std;

// KMP
int lps[1001];
int find(const char str[], const char pat[]) {
    int pl, l=0;
    lps[0] = 0;
    for (pl=1; pat[pl];)
        if (pat[pl] == pat[l])
            lps[pl++] = ++l;
        else if (l>0)
            l = lps[l-1];
        else
            lps[pl++] = 0;


    int j=0;
    for (int i=0; str[i];)
        if (str[i] == pat[j]) {
            i++; j++;
            if (j == pl) return i-pl;
        }
        else if (j > 0) j = lps[j-1];
        else i++;

    return -1;
}


int main(){
    char s[100001], p[1001];
    int T, q;
    cin>>T;
    while (T--) {
        cin >> s >> q;
        for (int i=0; i<q; i++) {
            cin >> p;
            puts(find(s, p) < 0 ? "n" : "y");
        }
    }
}
