#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	map<string, string> dic;
	char line[1000], wf[500], wen[500];
	while (cin.getline(line, 1000) && line[0]) {
		sscanf(line, "%s %s", wen, wf);
		dic[wf] = wen;
	}
	
	while (cin >> wf) {
		auto it = dic.find(wf);
		if (it == dic.end())
			cout << "eh\n";
		else
			cout << (it->second) << endl;
	}
}
