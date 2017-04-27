#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define INF 536870912
#define MAXN 5001
#define MAXL 20000


int graph[MAXN][MAXN], adj[MAXN][MAXN], deg[MAXN];
int d[MAXN], q[MAXN], inq[MAXN], qs;

#define CLR( x, v ) memset( x, v, sizeof( x ) )
#define BUBL { \
    t = q[i]; q[i] = q[j]; q[j] = t; \
    t = inq[q[i]]; inq[q[i]] = inq[q[j]]; inq[q[j]] = t; }

int dijkstra( int n, int s, int t ) {
    CLR( d, 9 ); CLR( inq, -1 );
    d[s] = qs = 0;
    inq[q[qs++] = s] = 0;

    while( qs ) {
        // get the minimum from the q
        int u = q[0]; inq[u] = -1;

        // bubble down
        q[0] = q[--qs];
        if( qs ) inq[q[0]] = 0;
        for( int i = 0, j = 2*i + 1, t; j < qs; i = j, j = 2*i + 1 ) {
            if( j + 1 < qs && d[q[j + 1]] < d[q[j]] ) j++;
            if( d[q[j]] >= d[q[i]] ) break;
            BUBL;
        }

        // relax neighbours
        for( int k = 0, v = adj[u][k]; k < deg[u]; v = adj[u][++k] ) {
            int newd = d[u] + graph[u][v];
            if( newd < d[v] ) {
                d[v] = newd;
                if( inq[v] < 0 ) { inq[q[qs] = v] = qs; qs++; }

                // bubble up
                for( int i = inq[v], j = ( i - 1 )/2, t;
                     d[q[i]] < d[q[j]]; i = j, j = ( i - 1 )/2 )
                     BUBL;
            }
        }
    }

    return d[t];
}














char line[MAXL];
int ex[MAXN*MAXN],
    ey[MAXN*MAXN];

int main(){
    int T, p, n;
    cin>>T;
    for(int cse=1; cse<=T; cse++) {
        int cnt = 0, ec = 0;
        map<string, int> ids;
        ids["Erdos, P."] = cnt++;


        cin>>p>>n;
        while(getchar()!='\n');

        for (int i=0; i<p; i++) {
            cin.getline(line, MAXL);

            char *e = strchr(line, ':');
            e[0] = 0;

            vector<int> cur;

            string name;
            bool ff = false;
            for (char* s=strtok(line, " ,"); s; s=strtok(NULL, " ,")) {
                if (ff) {
                    ff = false;
                    name = name + ", " + s;

                    int id = 0;
                    if (name != "Erdos, P.") {
                        id = ids[name];
                        if (id == 0)
                            id = ids[name] = cnt++;
                    }

                    for (int j=cur.size()-1; j>=0; j--) {
                        int k = cur[j];
                        if (k!=id) {
                            ex[ec] = k;
                            ey[ec++] = id;
                        }
                    }

                    cur.push_back(id);
                }

                else {
                    ff = true;
                    name = s;
                }
            }
        }


        for (int i=0; i<cnt; i++) {
            deg[i] = 0;
            for (int j=i+1; j<cnt; j++)
                graph[i][j] = graph[j][i] = INF;
        }

        for (int k=0; k<ec; k++) {
            int i = ex[k], j = ey[k];
            graph[i][j] = graph[j][i] = 1;
            adj[i][deg[i]++] = j;
            adj[j][deg[j]++] = i;
        }


        printf("Scenario %d\n", cse);
        for (int i=0; i<n; i++) {
            cin.getline(line, MAXL);
            auto it = ids.find(line);
            int res = (it == ids.end()) ? INF : dijkstra(cnt, 0, it->second);
            cout << line << " ";
            if (res >= cnt) cout << "infinity\n";
            else cout << res << endl;
        }
    }
}
