/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11239
  Name: Open Source
  Problem: https://onlinejudge.org/external/112/11239.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


int main() {
    map<string, int>::iterator pit;
    map<string, int> projs;

    unordered_map<string, string> users;

    string line;
    while (getline(cin, line) && line[0]!='0') {
        if (line[0] == '1') {
            map<int, vector<string> > pp;
            for (auto tt: projs)
                pp[tt.second].push_back(tt.first);

            for (auto it=pp.rbegin(); it!=pp.rend(); ++it) {
                int sz = it->first;
                for (string &s: it->second)
                    cout << s << ' ' << sz << endl;
            }

            projs.clear();
            users.clear();
            continue;
        }

        if (line[0] <= 'Z') {
            projs[line] = 0;
            pit = projs.find(line);
        }

        else {
            auto uit = users.find(line);
            if (uit == users.end()) {
                users[line] = pit->first;
                ++pit->second;
            }
            else if (uit->second[0] && (uit->second != pit->first)) {
                --projs[uit->second];
                uit->second[0] = 0;
            }
        }
    }
}
