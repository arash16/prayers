/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11223
  Name: O: dah dah dah!
  Problem: https://onlinejudge.org/external/112/11223.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


const char codes[143][17] = {
    "A", ".-",        "J", ".---",    "S", "...",        "1", ".----",    ".", ".-.-.-",    ":", "---...",
    "B", "-...",    "K", "-.-",        "T", "-",        "2", "..---",    ",", "--..--",    ";", "-.-.-.",
    "C", "-.-.",    "L", ".-..",    "U", "..-",        "3", "...--",    "?", "..--..",    "=", "-...-",
    "D", "-..",        "M", "--",        "V", "...-",    "4", "....-",    "'", ".----.",    "+", ".-.-.",
    "E", ".",        "N", "-.",        "W", ".--",        "5", ".....",    "!", "-.-.--",    "-", "-....-",
    "F", "..-.",    "O", "---",        "X", "-..-",    "6", "-....",    "/", "-..-.",    "_", "..--.-",
    "G", "--.",        "P", ".--.",    "Y", "-.--",    "7", "--...",    "(", "-.--.",    "\"", ".-..-.",
    "H", "....",    "Q", "--.-",    "Z", "--..",    "8", "---..",    ")", "-.--.-",    "@", ".--.-.",
    "I", "..",        "R", ".-.",        "0", "-----",    "9", "----.",    "&", ".-..."
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    map<string, string> C;
    for (int i=0; codes[i][0]; i += 2)
        C[codes[i+1]] = codes[i];

    int T; cin >> T;
    cin.ignore(100, '\n');
    for (int cse=1; cse<=T; ++cse) {
        if (cse > 1) cout << endl;
        cout << "Message #" << cse << endl;

        string line, s;
        getline(cin, line);
        int i=0;
        while (line[i] == ' ') ++i;
        for (; line[i]; ++i)
            if (line[i] == ' ') {
                cout << C[s];
                if (line[i+1] == ' ') {
                    cout << ' ';
                    while (line[i+1] == ' ')
                        ++i;
                }
                s = "";
            }
            else s += line[i];
        if (s.size() > 0)
            cout << C[s];
        cout << endl;
    }
}
