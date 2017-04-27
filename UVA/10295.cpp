#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<string, int> vals;
	char word[100];

	int n, c;
	cin>>n>>c;
	for (int i=0; i<n; i++) {
		cin >> word;
		cin >> vals[word];
	}
	
	for (int i=0; i<c; i++) {
		int sum = 0;
		while (cin>>word && word[0]!='.')
			sum += vals[word];
		
		cout << sum << endl;
	}
}
