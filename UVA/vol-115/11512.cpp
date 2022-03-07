/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11512
  Name: GATTACA
  Problem: https://onlinejudge.org/external/115/11512.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


const char DNA[] = "ACGT";
int D[128];


int S[1000143][4], C[1000143], Sc;
bool addWord(const char w[]) {
    int cur = 0;
    for (int i=0; w[i]; ++i) {
        int wi = D[w[i]];
        if (!S[cur][wi]) {
            C[Sc] = 0;
            memset(S[Sc], 0, 4*sizeof(int));
            S[cur][wi] = Sc++;
        }
        cur = S[cur][wi];
        C[cur]++;
    }
    return C[cur] > 1;
}

int bestl, bestr;
char best[1024], path[1024];
void findBest(int l, int cur) {
    if (C[cur] > 1 && l > bestl) {
        path[l] = 0;
        strcpy(best, path);
        bestl = l;
        bestr = C[cur];
    }

    for (int i=0; i<4; ++i)
        if (S[cur][i]) {
            path[l] = DNA[i];
            findBest(l+1, S[cur][i]);
        }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i=0; DNA[i]; ++i)
        D[DNA[i]] = i;

    int n;
    cin >> n;
    cin.ignore(100, '\n');
    while (n--) {
        char word[1024];
        cin.getline(word, 1024);
        memset(S, C[0]=0, 100*sizeof(int));
        Sc = 1;

        int len = strlen(word);
        for (int i=0; word[i]; ++i)
            if (addWord(word+i))
                break;

        bestl = bestr = 0;
        findBest(0, 0);
        if (bestl)
            cout << best << ' ' << bestr << endl;
        else
            cout << "No repetitions found!\n";
    }
}
