#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while (T--) {
		map<string, string> mp;
		char key[200], val[200];

		scanf(" %*c");
		char ch = ',';
		while (ch != '}') {
			if (scanf("%[a-z]:%[0-9]%c", key, val, &ch) != 3) { getchar(); break; }
			mp[key] = val;
		}

		scanf(" %*c");
		ch = ',';
		while (ch!='}') {
			if (scanf("%[a-z]:%[0-9]%c", key, val, &ch) != 3) { getchar(); break; }
			auto it = mp.find(key);
			if (it == mp.end())
				mp[key] = "+";

			else if (it->second != val)
				it->second = "*";

			else mp.erase(it);
		}


		vector<string> ins, rem, chg;
		for (auto p: mp)
			if (p.second == "+")
				ins.push_back(p.first);

			else if (p.second=="*") 
				chg.push_back(p.first);

			else rem.push_back(p.first);

		if (ins.empty() && rem.empty() && chg.empty())
			puts("No changes");

		else {
			if (ins.size()) {
				cout << '+' << ins[0];
				for (int i=1; i<ins.size(); ++i)
					cout << ',' << ins[i];
				putchar('\n');
			}
			if (rem.size()) {
				cout << '-' << rem[0];
				for (int i=1; i<rem.size(); ++i)
					cout << ',' << rem[i];
				putchar('\n');
			}
			if (chg.size()) {
				cout << '*' << chg[0];
				for (int i=1; i<chg.size(); ++i)
					cout << ',' << chg[i];
				putchar('\n');
			}
		}

		putchar('\n');
	}
}
