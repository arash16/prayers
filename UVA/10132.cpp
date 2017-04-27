#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main() {
	int T, n;
	string line;
	scanf("%d", &T);
	getline(cin,line);
	getline(cin,line);
	while (T--) {
		int totalLen = 0;
		vector<string> strs[300], allstr;
		for (n=0; getline(cin,line) && line.length()>0; ++n) {
			totalLen += line.length();
			strs[line.length()].push_back(line);
			allstr.push_back(line);
		}
		
		int bcnt = 0;
		string bstr;

		int resLen = totalLen/(n>>1);
		map<string, int> lens;
		for (string &s1: allstr) {
			int sl = s1.length();

			if (bcnt) {
				size_t pos = bstr.find(s1);
				if (pos==string::npos || (pos!=0 && pos!=bstr.length()-sl)) {
					lens[bstr] = bcnt = 0;
				}
			}

			for (string &s2: strs[resLen - sl]) {
				string ss = s1 + s2;
				int cnt = ++lens[ss];
				if (cnt > bcnt) {
					bcnt = cnt;
					bstr = ss;
				}
			}
		}

		cout << bstr << endl;
		if (T) putchar('\n');
	}
}
