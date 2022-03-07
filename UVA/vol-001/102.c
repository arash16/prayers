/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 102
  Name: Ecological Bin Packing
  Problem: https://onlinejudge.org/external/1/102.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>

int main()
{
 unsigned int A[3][3],mini;
 int k,i,j,moves;
 char mins[4];
 char BGC[]="BGC";
 char str[][4]={"BCG","BGC","CBG","CGB","GBC","GCB"};

 while (scanf("%d%d%d%d%d%d%d%d%d",&A[0][0],&A[0][1],&A[0][2]
                                  ,&A[1][0],&A[1][1],&A[1][2]
                                  ,&A[2][0],&A[2][1],&A[2][2])!=EOF)
 {
   mini=-1;

   for(k=0;k<6;k++)
   {
     moves=0;
     for(i=0;i<3;i++)
      for(j=0;j<3;j++)
       if (str[k][i]!=BGC[j])
        moves+=A[i][j];

     if(moves<mini || mini==-1)
     {
       mini=moves;
       strcpy(mins,str[k]);
     }
   }
   printf("%s %d\n",mins,mini);
 }
 return 0;
}
