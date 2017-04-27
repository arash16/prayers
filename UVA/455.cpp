#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

char str[100];
int l;

bool check(int p) {
	int c = l/p;//3
	for (int i=0; i<p; i++) {
		char ch = str[i];
		for (int j=1; j<c; j++)
			if (str[j*p + i] != ch)
				return false;
	}
	return true;
}

int minPeriod() {
	l = strlen(str);
	int half = l>>1;
	for (int i=1; i<=half; i++)
		if (l%i==0 && check(i))
			return i;
	return l;
}

int main(){
	int T;
	cin>>T;
	while (T--) {
		cin>>str;
		cout << minPeriod() << endl;
		if (T) cout << endl;
	}
}
