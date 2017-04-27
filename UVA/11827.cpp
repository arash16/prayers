#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;

#define MAXL 100000


int gcd(int a, int b) {
	if (b==0) return a;
	return gcd(b, a%b);
}

char line[MAXL];
int x[101];

int main(){
	int T;
	cin >> T;
	cin.getline(line, 100000);
	while (T--) {
		cin.getline(line, 100000);
		stringstream sin(line);
		
		int mx=1;
		for (int i=0; sin>>x[i]; i++)
			for (int j=0; j<i; j++) {
				int g = gcd(x[i], x[j]);
				if (g > mx) mx = g;
			}
		
		cout << mx << endl;
	}
}
