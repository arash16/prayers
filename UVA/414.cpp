#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int n;
	char line[50];
	while(cin>>n && n) {
		cin.getline(line, 50);
		
		int ms = 100, total = 0;
		for (int i=0; i<n; i++) {
			cin.getline(line, 50);

			int cnt = 0;
			for (int i=0; i<25; i++)
				if (line[i]!='X')
					cnt++;
			
			if (cnt<ms) ms = cnt;
			total += cnt;
		}
		
		cout << (total - ms*n) << endl;
	}
}

