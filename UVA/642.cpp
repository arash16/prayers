#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
using namespace std;


int primes[] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 
	37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 
	79, 83, 89, 97, 101, 103, 107, 109, 113
};




map<long long, set<string> > words;
long long conv(const char word[]) {
	long long r=1;
	for (int i=0; word[i]; i++)
		r *= primes[word[i]-'a'];
	return r;
}

int main(){
	char word[10];
	while (cin>>word && word[0]!='X')
		words[conv(word)].insert(word);
	
	while (cin>>word && word[0]!='X') {
		auto it = words.find(conv(word));
		if (it == words.end())
			puts("NOT A VALID WORD");

		else for (string s: it->second)
			cout << s << endl;

		puts("******");
	}
}
