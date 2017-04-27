#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int   cse = 0;
	int cum[1000003];
	char line[1000003];

	while (cin.getline(line, 1000003) && line[0]) {
		printf("Case %d:\n", ++cse);
		cum[0]=line[0] - '0';
		for (int i=1; line[i]; i++)
			cum[i] = cum[i-1] + line[i] - '0';
		
		int n; 
		cin>>n;
		while (n--) {
			int a, b;
			cin >> a >> b;
			if (a>b) swap (a, b);
			int sum = cum[b] - (a>0 ? cum[a-1] : 0);
			cout<< (sum==0 || sum==b-a+1 ? "Yes\n" : "No\n");
		}
		cin.getline(line, 1000000);
	}
}
