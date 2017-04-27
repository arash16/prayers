#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


int P[] = {2, 3, 5, 7, 11, 13, 17, 19};
int F[22][8];

unsigned long long int numberize(int r[]) {
    unsigned long long result = 1;
    for (int i=0; i<8; i++)
        if (r[i])
            result *= pow(P[i], r[i]);
    return result;
}

int main(){
    for (int i=2; i<=20; i++) {
        int k = i;
        for (int j=0; j<8; j++)
            for (F[i][j]=F[i-1][j]; k%P[j]==0; k/=P[j])
                F[i][j]++;
    }

    int T;
    cin>>T;
    for (int cse = 1; cse<=T; cse++) {
        char word[22];
        cin>>word;

        int res[8],
            len = strlen(word);
        sort(word, word+len);

        for (int i=0; i<8; i++)
            res[i] = F[len][i];

        int c = 1, i=1;
        do {
            if (word[i] == word[i-1]) c++;
            else if (c>1) {
                for (int j=0; j<8 && P[j]<=c; j++)
                    res[j] -= F[c][j];
                c = 1;
            }
        } while (word[i++]);

        printf("Data set %d: %llu\n", cse, numberize(res));
    }
}
