#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


struct Char {
	char ch; int cnt;
	Char(char ch, int cnt):ch(ch),cnt(cnt) {}
};

list<Char> lsc;

template <class Int>
void printKth(Int k, Int sz, int len) {
	char result[30];
	result[len] = 0;

	for (int i=0; i<len; i++)
		for (auto it=lsc.begin(); it!=lsc.end(); it++) {
			Int sz2 = sz * it->cnt / (len-i);
			if (k < sz2) {
				result[i] = it->ch;
				if (--it->cnt == 0)
					lsc.erase(it);

				sz = sz2;
				break;
			}
			else k -= sz2;
		}
	puts(result);
}


long long Facts[21]={1,1};
int main(){
	for (int i=2; i<21; i++)
		Facts[i] = Facts[i-1]*i;


	int T;
	long long k;
	char str[30];
	scanf("%d", &T);
	while (T--) {
		scanf("%s %lld", str, &k);
		int len = strlen(str);
		sort(str, str+len);

		lsc.clear();
		long long sz = Facts[len];
		for (int i=0, cr=0; i<len; i++) {
			++cr;
			if (str[i] != str[i+1]) {
				lsc.push_back(Char(str[i], cr));
				sz /= Facts[cr];
				cr = 0;
			}
		}

		if (sz < (1<<30))
			 printKth<unsigned int>(k, sz, len);
		else printKth<long long>(k, sz, len);
	}
}
