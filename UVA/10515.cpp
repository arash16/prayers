#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int rr[] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
int main(){
	char w1[200], w2[200];

	while (cin>>w1>>w2 && (w1[0]!='0' || w2[0]!='0')) {
		if (w2[0]=='0' && !w2[1]) puts("1");
		else {
			int m = w1[strlen(w1)-1] - '0';
			if (rr[m] == 1) cout << m << endl;
			else {
				int n = 0;
				for (int i=0; w2[i]; i++)
					n = (n*10 + w2[i] - '0') % rr[m];
				if (!n) n = rr[m];

				int x = 1;
				while (n--) x *= m;
				cout << (x%10) << endl;
			}
		}
	}
}
