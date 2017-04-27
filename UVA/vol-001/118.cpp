#include <stdio.h>
#include <iostream>
using namespace std;

bool scent[1000][1000];
char dirs[] = "NESW", L[90], R[90];

int main(){
    for (int i=0; i<4; i++) {
        L[dirs[i]] = dirs[(4+i-1)%4];
        R[dirs[i]] = dirs[(i+1)%4];
    }


    int maxx, maxy;
    cin >> maxx >> maxy;

    int x, y;
    char insts[300], cmd, d;
    while (cin >> x >> y >> d) {
        if (d>='a') d-=32;
        bool fall = false;
        cin >> insts;
        for (int i=0; !fall && (cmd = insts[i]); i++)
            if (cmd=='L' || cmd=='l') d=L[d];
            else if (cmd=='R' || cmd=='r') d=R[d];
            else if (d=='N')
                if (y<maxy) y++;
                else { if(!scent[x][y]) fall=true; }
            else if (d=='E')
                if (x<maxx) x++;
                else { if(!scent[x][y]) fall=true; }
            else if (d=='S')
                if (y>0) y--;
                else { if(!scent[x][y]) fall=true; }
            else if (d=='W')
                if (x>0) x--;
                else { if(!scent[x][y]) fall=true; }

        printf("%d %d %c", x, y, d);
        if (fall) {
            cout << " LOST\n";
            scent[x][y] = true;
        }
        else cout << endl;
    }
}
