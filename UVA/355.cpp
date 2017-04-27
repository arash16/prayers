#include <stdio.h>
#include <iostream>
using namespace std;

int val(char ch) {
	return ch>='A' ? ch-'A'+10 : ch-'0';
}

int main(){
	long long s, t, res[200];
	char num[200];

	while (cin>>s>>t>>num) {
		bool e = false;
		long long x = 0;
		for (int i=0; !e && num[i]; i++) {
			int d = val(num[i]);
			if (d>=s) e = true;
			else x = x*s + d;
		}
		if (e) printf("%s is an illegal base %lld number\n", num, s);
		else {
			printf("%s base %lld = ", num, s);
			if (t==10 || !x) cout << x;
			else {
				int i;
				for (i=0; x; i++) {
					res[i] = x%t;
					x /= t;
				}
				
				while (i--)
					putchar(res[i]>=10 ? 'A'+res[i]-10 : '0'+res[i]);
			}
			printf(" base %lld\n", t);
		}
	}
}
