#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
using namespace std;

char word[100];
bool isp(int s, int e) {
	for (int i=s, j=e; i<j; i++,j--)
		if (word[i] != word[j])
			return false;

	return true;
}

int main(){
	while (cin>>word) {
		set<string> s;
		int l = strlen(word);
		for (int i=0; i<l; i++)
			for (int j=i; j<l; j++)
				if (isp(i, j)) {
					char t = word[j+1];
					word[j+1]=0;
					s.insert(word+i);
					word[j+1]=t;
				}
		printf("The string '%s' contains %lu palindromes.\n", word, s.size());
	}
}
