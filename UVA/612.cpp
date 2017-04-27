#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct DNA {
	char seq[55];
	int score;
	bool operator <(const DNA& d) const {
		return score < d.score;
	}
};

DNA ar[110];


int main(){
	int cse, n, m;
	int A,C,G,T, score;

	cin>>cse;
	while(cse--) {
		cin>>n>>m;
		for (int i=0; i<m; i++) {
			char* s = ar[i].seq;
			cin>>s;
			A=C=G=T=0;
			score = 0;
			for (int i=0; i<n; i++) {
				switch(s[i]) {
					case 'A':
						score+=C+G+T;
						A++;
						break;
					case 'C':
						score+=G+T;
						C++;
						break;
					case 'G':
						score+=T;
						G++;
						break;
					case 'T': T++;
				}
			}
			ar[i].score = score;
		}
		
		stable_sort(ar, ar+m);
		for (int i=0; i<m; i++)
			cout << ar[i].seq << endl;

		if (cse) cout<<endl;
	}
}
