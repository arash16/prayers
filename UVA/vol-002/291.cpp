#include <stdio.h>
#include <iostream>
using namespace std;

int mp[5][5], seen[5][5], sel[9];
void rec(int id) {
    if (id==9) {
        for(int i=0; i<9; i++)
            cout<<sel[i]+1;
        cout<<endl;
        return;
    }

    int last = sel[id-1];
    for (int j=0; j<5; j++)
        if (mp[last][j] && !seen[last][j]) {
            seen[last][j] = seen[j][last] = 1;
            sel[id] = j;
            rec(id + 1);
            seen[last][j] = seen[j][last] = 0;
        }
}


int main(){
    mp[0][1]=mp[0][2]=mp[0][4]=mp[1][2]=mp[1][4]=mp[2][3]=mp[2][4]=mp[3][4]=1;
    for (int i=0; i<5; i++)
        for (int j=i+1; j<5; j++)
            mp[j][i]=mp[i][j];

    rec(1);
}
