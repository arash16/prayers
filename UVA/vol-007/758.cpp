#include <bits/stdc++.h>
using namespace std;

int H[17], LL[17], RR[17], C[11][17], CI[17];
char M[11][17];


bool D[11][17], K[11][17];
int dcn, Y[200], X[200];
void dfs(int r, int c) {
	if (D[r][c] || r > H[c]) return;
		D[r][c] = 1;

	Y[dcn] = r; X[dcn] = c; ++dcn;
	char ch = M[r][c];

	if (r > 1		&& ch==M[r-1][c])
		dfs(r-1, c);

	if (r < H[c]	&& ch==M[r+1][c])
		dfs(r+1, c);

	if (LL[c] > 0	&& ch==M[r][LL[c]])
		dfs(r, LL[c]);

	if (RR[c] < 16	&& ch==M[r][RR[c]])
		dfs(r, RR[c]);
}

// -------------------------------------------------

void updateCounts(int s, int e) {
	if (s < 1) s = 1;
	if (e >15) e = 15;
	for (int c=s; c<=e; c=RR[c])
		for (int r=H[c]; r>0; --r)
			if (!C[r][c]) {
				dfs(r, c);
				for (int i=0; i<dcn; ++i) {
					C[Y[i]][X[i]] = dcn;
					D[Y[i]][X[i]] = 0;
				}
				dcn = 0;
			}
}

void markComp(int r, int c) {
	dfs(r, c);
	for (int i=0; i<dcn; ++i) {
		K[Y[i]][X[i]] = 1;
		D[Y[i]][X[i]] = 0;
	}
	dcn = 0;
}

void removeMarks() {
	int mnc=16, mxc=-1;
	for (int c=RR[0]; c<16; c=RR[c]) {
		int h = 0;
		bool rs = 0;
		for (int r=1; r<=H[c]; ++r) {
			if (!K[r][c])
				M[++h][c] = M[r][c];
			else {
				rs = 1;
				K[r][c] = 0;
				if (c < mnc) mnc = c;
				if (c > mxc) mxc = c;
			}

			if (rs)
				C[r][c] =
				C[r][LL[c]] =
				C[r][RR[c]] = 0;
		}

		// remove column if necessary
		if (!(H[c] = h)) {
			for (int r=min(H[LL[c]], H[RR[c]]); r>0; --r)
				C[r][LL[c]] = C[r][RR[c]] = 0;

			LL[RR[c]] = LL[c];
			RR[LL[c]] = RR[c];
			for (int k=c+1; k<16; ++k)
				--CI[k];
		}
	}

	// update counts of moved balls
	if (mxc>0) updateCounts(LL[mnc], RR[mxc]);
}

void printState() {
	for (int r=10; r>0; --r) {
		for (int c=RR[0]; c<16; c=RR[c])
			putchar(H[c] < r ? ' ' : M[r][c]);
		putchar('\n');
	}
	putchar('\n');
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T; cin>>T;
	for (int cse=1; cse<=T; ++cse) {
		if (cse>1) cout << endl;
		cout << "Game " << cse << ":\n\n";

		memset(C, 0, sizeof(C));
		for (int c=0; c<17; ++c) {
			CI[c] = c;
			LL[c] = c-1;
			RR[c] = c+1;
			H[c] = 10;
		}

		for (int r=10; r>0; --r)
			cin >> (M[r]+1);

		updateCounts(0, 16);
		
		int sum = 0;
		bool hasMove = 1;
		for (int i=1; hasMove; ++i) {
			int bn = 1, br=0, bc=0;
			
			for (int c=RR[0]; c<16; c=RR[c])
				for (int r=1; r<=H[c]; ++r)
					if (C[r][c] > bn){
						bn = C[r][c];
						br = r;
						bc = c;
					}

			if ((hasMove = br)) {
				int sco = (bn-2)*(bn-2);
				//printState();
				cout << "Move " << i << " at (" << br << ',' << CI[bc]
					 << "): removed " << bn << " balls of color " << M[br][bc] 
					 << ", got " << sco << " points.\n";
				markComp(br, bc);
				removeMarks();
				sum += sco;
			}
		}

		int rem = 0;
		for (int c=RR[0]; c<16; c=RR[c])
			rem += H[c];

		if (!rem) sum += 1000;
		cout << "Final score: " << sum << ", with " << rem << " balls remaining.\n";
	}
}
