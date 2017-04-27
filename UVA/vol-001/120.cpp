#include <stdio.h>
#include <iostream>
using namespace std;

int a[31];
void flip(int l) {
	for (int i = l/2; i>=0; i--) {
		int t = a[i];
		a[i] = a[l-i];
		a[l-i] = t;
	}
}

int main() {
	char line[300];
	while (cin.getline(line, 300)) {
		int n = sscanf(line, "%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",a,a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,a+9,a+10,a+11,a+12,a+13,a+14,a+15,a+16,a+17,a+18,a+19,a+20,a+21,a+22,a+23,a+24,a+25,a+26,a+27,a+28,a+29,a+30);
		
		cout << a[0];
		for(int i=1; i<n; i++)
			cout << " " << a[i];
		cout<<endl;
		
		for (int i=0; i<n; i++) {
			int mxi=0;
			for (int j=1; j<n-i; j++)
				if(a[j]>a[mxi])
					mxi=j;
			
			if (mxi != n-i-1) {
				if (mxi) {
					cout << n-mxi << " ";
					flip(mxi);
				}
				
				cout << i+1 << " ";
				flip(n-i-1);
			}
		}
		cout<<"0\n";
	}
}

