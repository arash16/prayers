/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 822
  Name: Queue and A
  Problem: https://onlinejudge.org/external/8/822.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int pid[7], lastSchedule[7], finJob[7];
bool comp(int i, int j) {
    return lastSchedule[i] != lastSchedule[j]
        ? lastSchedule[i] < lastSchedule[j]
        : pid[i] < pid[j];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int serv[23], n, m, id, cnt, offs, per;
    for (int cse=1; cin >> n && n; ++cse) {
        priority_queue<int, vector<int>, greater<int> > tms;
        queue<int> jobs[23];

        map<int, int> ids;
        for (int i=0; i<n; ++i) {
            cin >> id >> cnt >> offs >> serv[i] >> per;
            ids[id] = i;

            for (int j=0; j<cnt; ++j)
                jobs[i].push(offs),
                tms.push(offs),
                offs += per;
        }

        cin >> m;
        vector<int> pr[7];
        for (int i=0; i<m; ++i) {
            finJob[i] = lastSchedule[i] = 0;
            cin >> pid[i] >> cnt;

            pr[i].resize(cnt);
            for (int j=0; j<cnt; ++j) {
                cin >> id;
                pr[i][j] = ids[id];
            }
        }


        int lastTm = -1;
        while (!tms.empty()) {
            int tm = tms.top(); tms.pop();
            if (tm == lastTm) continue;
            lastTm = tm;

            int P[7], psz=0;
            for (int i=0; i<m; ++i)
                if (finJob[i] <= tm)
                    P[psz++] = i;
            sort(P, P+psz, comp);

            for (int i=0; i<psz; ++i) {
                int pi = P[i];
                for (int ji: pr[pi])
                    if (!jobs[ji].empty() && jobs[ji].front() <= tm) {
                        lastSchedule[pi] = tm;
                        finJob[pi] = tm + serv[ji];
                        jobs[ji].pop();
                        tms.push(finJob[pi]);
                        break;
                    }
            }
        }
        cout << "Scenario " << cse << ": All requests are serviced within " << lastTm << " minutes.\n";
    }
}
