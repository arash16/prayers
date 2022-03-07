/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 486
  Name: English-Number Translator
  Problem: https://onlinejudge.org/external/4/486.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char words[][10] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
        "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };
    int nums[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18,
        19, 20, 30, 40, 50, 60, 70, 80, 90
    };

    map<string, int> values;
    for (int i=0; i<28; ++i)
        values[words[i]] = nums[i];


    string line, word;
    while (getline(cin, line)) {
        stringstream sin(line);
        int sgn = 1, a=0, b=0, c=0, d=0;
        while (sin >> word) {
            if (word == "negative") sgn = -1;
            else {
                auto it = values.find(word);
                if (it == values.end()) {
                    if (word == "hundred") {
                        b = a;
                        a = 0;
                    }
                    else if (word == "thousand") {
                        c = b*100 + a;
                        b = a = 0;
                    }
                    else if (word == "million") {
                        d = c*1000 + b*100 + a;
                        c = b = a = 0;
                    }
                }
                else a += it->second;
            }
        }

        cout << sgn * (d*1000000 + c*1000 + b*100 + a) << endl;
    }
}
