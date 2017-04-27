#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	for (int cse=1; cse<=T; cse++) {
		int n, bi=1, bj=0, bs=0,
		       ci=1, cj=0, cs=0;

		cin>>n;
		for (int i=1; i<n; i++) {
			int x;
			cin>>x;
			
			cs+=x; cj=i+1;
			if (cs<0) {
				ci=i+1;
				cs=0;
			}

			if (cs>bs || (cs==bs && cj-ci>bj-bi)) {
				bi=ci;
				bj=cj;
				bs=cs;
			}
		}
		
		if (bs<=0) printf("Route %d has no nice parts\n", cse);
		else printf("The nicest part of route %d is between stops %d and %d\n", cse, bi, bj);
	}
}
