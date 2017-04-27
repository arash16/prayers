/*
  >>~~ ACM PROBLEM ~~<<

  ID: 10189
  Name: Minesweeper
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

#include <stdio.h>

int main()
{
     int x,y,i,j,i2,j2,t,n;
     char A[101][101];

     n=1;

     scanf("%d %d\n",&y,&x);
     while (1)
     {
        for(i=0;i<101;i++)
         for(j=0;j<101;j++)
          A[i][j]=0;


        for(i=1;i<=y;i++)
        {
          for(j=1;j<=x;j++)
          {
            A[i][j]=getchar();

            if (A[i][j]==46)
              A[i][j]=0;
          }
          getchar();
        }

        for(i=1;i<=y;i++)
          for(j=1;j<=x;j++)
            if(A[i][j]==0)
            {
              for(i2=i-1;i2<=i+1;i2++)
                for(j2=j-1;j2<=j+1;j2++)
                  if(A[i2][j2]==42)
                    A[i][j]++;
            }

        printf("Field #%d:\n",n);
        for(i=1;i<=y;i++)
        {
          for(j=1;j<=x;j++)
            if(A[i][j]==42)
              printf("*");
            else
              printf("%1d",A[i][j]);
          printf("\n");
        }
        n++;
        scanf("%d %d\n",&y,&x);
        if(x==0 && y==0)
          break;
        printf("\n");
     }
     return 0;
}
