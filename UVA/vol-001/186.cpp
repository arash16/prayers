#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

int n, D[143][143], P[143][143];
string names[143], rid[143][143];
unordered_map<string, int> ids;
int readId(char delim=',') {
	if (getline(cin, names[n], delim)) {
		auto r = ids.emplace(names[n], n);
		if (r.second) ++n;
		return r.first->second;
	}
	return -1;
}

void printFlight(int i, int j) {
	cout 	<< setw(20) << left << names[i]	<< ' '
			<< setw(20) << left << names[j]	<< ' '
			<< setw(10) << left << rid[i][j]<< ' '
			<< setw( 5) << right<< D[i][j]	<< endl;
}

void printPath(int u, int v) {
	if (P[u][v] == u) {
		printFlight(u, v);
		return;
	}
	
	printPath(u, P[u][v]);
	printPath(P[u][v], v);
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	for (int i=0; i<143; ++i) {
		for (int j=0; j<143; ++j) {
			D[i][j] = INF;
			P[i][j] = i;
		}
		D[i][i] = 0;
	}

	while (cin.peek()!='\n') {
		int u = readId(),
			v = readId(),
			d; string sid;
		getline(cin, sid, ',');
		cin >> d;
		if (d < D[u][v]) {
			rid[u][v] = rid[v][u] = sid;
			D[u][v] = D[v][u] = d;
		}
		cin.ignore(100, '\n');
	}
	cin.ignore(100, '\n');

	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
		if (i!=k && D[i][k]!=INF)
			for (int j=0; j<n; ++j) {
				int d = D[i][k] + D[k][j];
				if (d < D[i][j]) {
					D[i][j] = d;
					P[i][j] = k;
				}
			}

	for (int u; (u=readId())!=-1; ) {
		int v = readId('\n');
		cout	<< "\n\n"
				<< "From                 To                   Route      Miles\n"
				<< "-------------------- -------------------- ---------- -----\n";
		printPath(u, v);
		cout	<< "                                                     -----\n"
				<< "                                          Total      "
				<< setw(5) << D[u][v] << endl;
	}
}
