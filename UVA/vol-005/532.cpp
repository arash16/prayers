#include <stdio.h>
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

struct cell{
	int x,y,z;
	int step;
} sp,ep;
deque<struct cell> st;
int map[50][50][50];
int m,n,p;

bool good(struct cell u){
	if(u.z<0 || u.y<0 || u.x<0)return 0;
	if(u.z>=m || u.y>=n || u.x>=p)return 0;
	if(map[u.z][u.y][u.x]!=0)return 0;
	map[u.z][u.y][u.x]=1;
	return 1;
}
void pushh(int x,int y,int z,int s){
	struct cell u;
	u.x=x;u.y=y;u.z=z;u.step=s+1;
	if(good(u))st.push_back(u);
}
void bfs(){
	struct cell t,u;

	st.push_back(sp);
	map[sp.z][sp.y][sp.x]=1;
	while(!st.empty()){
		t=st.front();st.pop_front();
		if(t.x==ep.x && t.y==ep.y && t.z==ep.z){
			printf("Escaped in %d minute(s).\n",t.step);
			return;
		}
		pushh(t.x+1,t.y,t.z,t.step);
		pushh(t.x,t.y+1,t.z,t.step);
		pushh(t.x,t.y,t.z+1,t.step);
		pushh(t.x-1,t.y,t.z,t.step);
		pushh(t.x,t.y-1,t.z,t.step);
		pushh(t.x,t.y,t.z-1,t.step);
	}
	printf("Trapped!\n");
}

int main(){
	int i,j,k;
	char ch;

	while(scanf("%d%d%d",&m,&n,&p) && m+n+p){
		memset(map,0,sizeof(map));
		st.clear();
		for(i=0;i<m;i++){
			getchar();
			for(j=0;j<n;j++){
				for(k=0;k<p;k++){
					ch=getchar();
					if(ch=='#')map[i][j][k]=1;
					else if(ch=='s' || ch=='S'){
						sp.x=k;sp.y=j;sp.z=i;sp.step=0;}
					else if(ch=='e' || ch=='E'){
						ep.x=k;ep.y=j;ep.z=i;}
				}
				getchar();
			}
		}
		bfs();
	}
	return 0;
}