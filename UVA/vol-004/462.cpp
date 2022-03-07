/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 462
  Name: Bridge Hand Evaluator
  Problem: https://onlinejudge.org/external/4/462.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


string c[13];
int so[127], cnt[4];
int rule1234() {
    int points = 0;
    for (int i=0; i<13; ++i) {
        int cc = cnt[so[c[i][1]]];
        switch(c[i][0]) {
            case 'A': points += 4; break;
            case 'K': points += 3 - (cc==1); break;
            case 'Q': points += 2 - (cc<=2); break;
            case 'J': points += 1 - (cc<=3); break;
        }
    }
    return points;
}

int rule567() {
    int points = 0;
    for (int i=0; i<4; ++i)
        switch (cnt[i]) {
            case 0:
            case 1: points += 2; break;
            case 2: points++;
        }
    return points;
}

int stops() {
    bool ss[4] = {};
    for (int i=0; i<13; ++i) {
        int suit = so[c[i][1]],
            cc = cnt[suit];
        switch (c[i][0]) {
            case 'A':
                ss[suit] = true;
                break;
            case 'K':
                if (cc >= 2)
                    ss[suit] = true;
                break;
            case 'Q':
                if (cc >= 3)
                    ss[suit] = true;
        }
    }
    return ss[0] + ss[1] + ss[2] + ss[3];
}

char bidSuit() {
    if (cnt[0] >= cnt[1] && cnt[0] >= cnt[2] && cnt[0] >= cnt[3])
        return 'S';

    if (cnt[1] >= cnt[2] && cnt[1] >= cnt[3])
        return 'H';

    if (cnt[2] >= cnt[3])
        return 'D';

    return 'C';
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    so['S'] = 0; so['H'] = 1;
    so['D'] = 2; so['C'] = 3;

    while (cin >> c[0]) {
        for (int i=1; i<13; ++i)
            cin >> c[i];

        memset(cnt, 0, sizeof(cnt));
        for (int i=0; i<13; ++i)
            cnt[so[c[i][1]]]++;

        int points = rule1234();
        if (points >= 16 && stops() == 4)
            cout << "BID NO-TRUMP\n";

        else if (points + rule567() >= 14)
            cout << "BID " << bidSuit() << '\n';

        else cout << "PASS\n";
    }
}
