#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int findSet(map<int, int> &ids, int ind, int &cnt) {
    auto it = ids.find(ind);
    if (it == ids.end())
        return ids[ind] = cnt++;

    return it->second;
}

int main(){
    int en, x, y, s, ttl, cse=1;
    unsigned int ar[30][30];
    while (cin>>en && en) {
        map<int, int> ids;
        int cnt = 0;

        for (int i=0; i<30; i++) {
            ar[i][i]=0;
            for (int j=i+1; j<30; j++)
                ar[i][j]=ar[j][i]=1000;
        }

        for (int i=0; i<en; i++) {
            cin>>x>>y;
            int xi = findSet(ids, x, cnt),
                yi = findSet(ids, y, cnt);

            ar[xi][yi]=ar[yi][xi]=1;
        }

        for (int k=0; k<cnt; k++)
            for (int i=0; i<cnt; i++)
                for (int j=0; j<cnt; j++)
                    ar[i][j] = min(ar[i][j], ar[i][k] + ar[k][j]);

        while(cin>>s>>ttl && (s||ttl)) {
            int result = 0;
            auto it = ids.find(s);

            if (it == ids.end()) result = cnt;
            else {
                int sid = it->second;
                for (int i=0; i<cnt; i++)
                    if (sid!=i && ar[sid][i] > ttl)
                        result++;
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cse++, result, s, ttl);
        }
    }
}
