#include <bits/stdc++.h>
using namespace std;


bool isVowel[127];
map<string, string> irr;
string makePlural(const string &str) {
    int len = str.length();
    char last = str[len-1];

    auto it = irr.find(str);
    if (it != irr.end())
        return it->second;

    else if (len>=2 && last=='y' && !isVowel[str[len-2]])
        return str.substr(0, len-1) + "ies";

    else if (last=='o' || last=='s' || last=='x' ||
            (len>=2 && last=='h' && (str[len-2]=='c' || str[len-2]=='s')))
        return str + "es";

    else return str + "s";
}

int main() {
    isVowel['a'] = isVowel['e'] =
    isVowel['o'] = isVowel['i'] =
    isVowel['u'] = true;

    int n, m;
    cin >> m >> n;

    string str, str2;
    while (m--) {
        cin >> str >> str2;
        irr[str] = str2;
    }

    while (n--) {
        cin >> str;
        cout << makePlural(str) << endl;
    }
}
