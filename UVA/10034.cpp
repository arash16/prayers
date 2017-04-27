#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


double X[102], Y[102], M[102][102];
double dist(int i, int j) {
	double x = X[i] - X[j],
		y = Y[i] - Y[j];
	return sqrt(x*x + y*y);
}


struct Edge {
	int i, j;
	double dist;
	bool operator < (const Edge& o) const {
		return dist < o.dist;
	}
};

Edge edges[102*102];
bool tr[102][102];

int main(){
	int N;
	cin>>N;
	while(N--) {
		int n;
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>X[i]>>Y[i];
		
		int l = 0;
		for (int i=0; i<n; i++) {
			M[i][i] = 0;
			tr[i][i] = true;
			for (int j=i+1; j<n; j++) {
				Edge& e = edges[l++];
				e.i=i; e.j=j;
				e.dist = M[i][j] = M[j][i] = dist(i, j);
				tr[i][j] = tr[j][i] = false;
			}
		}
		
		sort(edges, edges+l);

		int c = 0, k = 0;
		double res = 0;
		while (c < n-1) {
			Edge& e = edges[k++];
			if (!tr[e.i][e.j]) {
				c++;
				res += e.dist;
				
				tr[e.i][e.j] = tr[e.j][e.i] = true;
				for (int i=0; i<n; i++)
					if (tr[i][e.i])
						for (int j=0; j<n; j++)
							if (tr[e.j][j])
								tr[i][j] = tr[j][i] = true;
			}
		}
		
		printf("%.2f\n", res);
		if (N) cout<<endl;
	}
}
