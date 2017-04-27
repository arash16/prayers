#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int urow[20],udi1[20],udi2[20];
int row[8],ans[100][8];
int cnt=0;

bool check(int i, int j)
{
	return !urow[j] && !udi1[i+j]  && !udi2[i+8-j];
}

void BT(int i)
{
	if(i==8)
		memcpy(ans[cnt++],row,sizeof(row));
	else
		for(int j=0; j<8; j++)
			if(check(i,j)){
				urow[j]=udi1[i+j]=udi2[i+8-j]=1;
				row[i]=j;
				BT(i+1);
				urow[j]=udi1[i+j]=udi2[i+8-j]=0;
			}
}

int main()
{
	int cse,col,row,i,j,sln;
	BT(0);


	cin>>cse;
	while(cse--)
	{
		puts("SOLN       COLUMN");
		puts(" #      1 2 3 4 5 6 7 8\n");
		cin>>row>>col;
		sln=1;
		for(i=0; i<cnt; i++)
			if(ans[i][col-1]==row-1)
			{
				printf("%2d     ",sln++);
				for(j=0; j<8; j++)
					printf(" %d", ans[i][j]+1);
				cout<<endl;
			}
		if(cse)cout<<endl;
	}
}