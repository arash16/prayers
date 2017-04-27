#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define MAXL 500

int readNum() {
    int x; cin>>x;
    while (getchar()!='\n');

    return x;
}


struct Team {
    char name[40];
    int wins, ties, loses, goali, goalj;
    Team(const char nm[]) {
        strcpy(name, nm);
        wins=ties=loses=goali=goalj=0;
    }

    bool operator < (const Team& t) const {
        int p1 = wins*3 + ties,
            p2 = t.wins*3 + t.ties;
        if (p1 != p2)
            return p1 > p2;

        if (wins != t.wins)
            return wins > t.wins;

        int gd1 = goali - goalj,
            gd2 = t.goali - t.goalj;
        if (gd1 != gd2)
            return gd1 > gd2;

        if (goali != t.goali)
            return goali > t.goali;

        int gp1 = wins + ties + loses,
            gp2 = t.wins + t.ties + t.loses;
        if (gp1 != gp2)
            return gp1 < gp2;


        int i;
        for (i=0; name[i] && t.name[i]; i++) {
            int dif = tolower(name[i]) - tolower(t.name[i]);
            if (dif) return dif < 0;
        }
        return name[i] < t.name[i];
    }
};




int main(){
    char tname[MAXL];
    int T = readNum();
    while (T--) {
        cin.getline(tname, MAXL);
        puts(tname);

        map<string, int> ids;
        vector<Team> teams;

        int n = readNum();
        for (int i=0; i<n; i++) {
            cin.getline(tname, MAXL);
            ids[tname] = i;
            teams.push_back(Team(tname));
        }

        int m = readNum();
        for (int i=0; i<m; i++) {
            cin.getline(tname, MAXL);
            int pos[3], cnt=0;
            for (int j=0; tname[j]; j++)
                if (tname[j]=='#') {
                    pos[cnt++] = j+1;
                    tname[j]=0;
                }

            int u=ids[tname], v=ids[tname+pos[1]], us, vs;
            sscanf(tname+pos[0], "%d@%d", &us, &vs);
            teams[u].goali+=us; teams[u].goalj+=vs;
            teams[v].goali+=vs; teams[v].goalj+=us;

            if (us < vs) {
                teams[u].loses++;
                teams[v].wins++;
            }
            else if (us > vs) {
                teams[u].wins++;
                teams[v].loses++;
            }
            else {
                teams[u].ties++;
                teams[v].ties++;
            }
        }

        sort(teams.begin(), teams.end());
        for (int i=0; i<n; i++) {
            Team& t = teams[i];
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                    i+1, t.name, t.wins*3+t.ties, t.wins+t.loses+t.ties,
                    t.wins, t.ties, t.loses, t.goali-t.goalj, t.goali, t.goalj);
        }

        if (T) putchar('\n');
    }
}
