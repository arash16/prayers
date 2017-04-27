#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string list[200];
int main(){
	int n;
	while (cin>>n) {
		puts("------------------------------------------------------------");
		int maxlen=0;
		for (int i=0; i<n; i++) {
			cin>>list[i];
			maxlen=max(maxlen, (int)list[i].length());
		}
		sort(list, list+n);
		
		int cols = (60-maxlen)/(maxlen+2) + 1,
			rows = ceil((double)n/cols);

		for (int i=0; i<rows; i++)
			for (int j=0; j<cols; j++) {
				if (rows*j + i>=n) {
					cout<<endl;
					break;
				}

				string &s = list[rows*j + i];
				cout << s;
				
				for (int k=maxlen - s.length(); k>0; k--)
					putchar(' ');
				
				if (rows*(j+1) + i<n) cout << "  ";

				if (j==cols-1)
					cout << endl;
			}
	}
}
