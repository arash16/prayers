#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int d[127];

int main() {
	char wd[]="ABCDEFGHIJKLMNOPRSTUVWXY";
	for (int i=0; i<24; i++)
		d[wd[i]] = '0' + (i/3) + 2;

	for (int i=0; i<10; i++)
		d['0'+i] = '0' + i;

	char num[20], snum[9]="000-0000";
	int sid[]={0,1,2,4,5,6,7};

	int T, n;
	cin>>T;
	while (T--) {
		map<string, int> uses;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin>>num;
			int c=0;
			for (int i=0; c<7 && num[i]; i++)
				if (d[num[i]])
					snum[sid[c++]]=d[num[i]];

			uses[snum]++;
		}
		
		bool nodups=1;
		for (auto &s: uses)
			if (s.second > 1) {
				cout << s.first << " " << s.second << endl;
				nodups=0;
			}
		
		if (nodups) puts("No duplicates.");
		if (T) cout << endl;
	}
}
