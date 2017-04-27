#include <stdio.h>
#include <iostream>
using namespace std;

#define isset(n,i) (((n)>>(i))&1)

int automaton,n;
bool nstate[40],bstate[40];

bool BT(int i)
{
	if(i==n)
	{
		int t1=4*bstate[n-2] + 2*bstate[n-1] + bstate[0];
		int t2=4*bstate[n-1] + 2*bstate[0] + bstate[1];
		if(nstate[n-1] == isset(automaton,t1)  &&  nstate[0]==isset(automaton,t2))
			return true;
		else
			return false;
	}

	bool ans=false;

	int t1=4*bstate[i-2] + 2*bstate[i-1] + 1;
	if(isset(automaton,t1) == nstate[i-1])
	{
		bstate[i]=1;
		ans|= BT(i+1);
	}


	int t2=4*bstate[i-2] + 2*bstate[i-1] + 0;
	if(isset(automaton,t2) == nstate[i-1])
	{
		bstate[i]=0;
		ans|= BT(i+1);
	}

	return ans;
}


bool answer()
{
	int i;
	for(i=0; i<8; i++)
		if( isset(automaton,i) == nstate[1] )
		{
			bstate[0]= isset(i,2);
			bstate[1]= isset(i,1);
			bstate[2]= isset(i,0);
			if(BT(3))
				return true;
		}

	return false;
}


int main()
{
	char s[40];
	int i;

	while(cin>>automaton>>n>>s)
	{
		for(i=0; s[i]; i++)
			if(s[i]=='1')
				nstate[i]=1;
			else
				nstate[i]=0;

		if(answer())
			puts("REACHABLE");
		else
			puts("GARDEN OF EDEN");
	}
}