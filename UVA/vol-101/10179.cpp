#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int n;
	while (cin>>n && n) {
		int t = n;
		int sq = sqrt((double)n);
		for (int i=2; i<=sq; i++)
			if (n%i == 0) {
				while (n%i==0) n/=i;
				t = (t/i) * (i-1);
				sq = sqrt((double)n);
			}
		if (n>1) t = (t/n)*(n-1);

		cout << t << endl;
	}
}
