#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	int n, cse = 1;
	int secret[1002], gs, cs[10], cg[10];
	while(cin>>n && n) {
		memset(cs, 0, sizeof(cs));
		for (int i=0; i<n; i++) {
			cin>>secret[i];
			cs[secret[i]]++;
		}
		
		printf("Game %d:\n", cse++);
		for(;;) {
			int exact=0, mm=0;
			memset(cg, 0, sizeof(cg));
			for (int i=0; i<n; i++) {
				cin>>gs;
				cg[gs]++;
				if (secret[i] == gs)
					exact++;
			}
			
			if (!gs) break;
			for (int i=1; i<10; i++)
				mm += min(cg[i], cs[i]);
			
			printf("    (%d,%d)\n", exact, mm-exact);
		}
	}
}
