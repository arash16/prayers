/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10033
  Name: Interpreter
  Problem: https://onlinejudge.org/external/100/10033.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
unsigned short ram[1000],reg[10];

int main()
{
 int n,i,j;
 int result;
 int eip,tt;
 char t[10],c,p1,p2;
 scanf("%d\n",&n);
 while(n--)
 {
    memset(ram,0,sizeof(ram));
    memset(reg,0,sizeof(reg));
    result=1;

    i=0;
    while ((t[0]=getchar()) != '\n')
    {
      t[1]=getchar();
      t[2]=getchar();
      t[3]='\0';
      ram[i++]=atoi(t);
      if(getchar()==EOF)break;
    }

    eip=0;
    while((int)floor(ram[eip]/100) != 1)
    {
      result++;
      c=(int)floor(ram[eip]/100);
      p1=(int)floor(ram[eip]/10) % 10;
      p2=ram[eip]%10;

      switch(c)
      {
        case 2:
          reg[p1]=p2;
          break;
        case 3:
          reg[p1]+=p2;
          break;
        case 4:
          reg[p1]*=p2;
          break;
        case 5:
          reg[p1]=reg[p2];
          break;
        case 6:
          reg[p1]+=reg[p2];
          break;
        case 7:
          tt=reg[p1]*reg[p2];
          while(tt>999)tt-=1000;
          reg[p1]=tt;
          break;
        case 8:
          reg[p1]=ram[reg[p2]];
          break;
        case 9:
          ram[reg[p2]]=reg[p1];
          break;
        case 0:
          if(reg[p2]!=0)eip=reg[p1]-1;
          break;
      }
      while(reg[p1]>999)
        reg[p1]-=1000;

      eip++;
    }
    printf("%d\n",result);
    if(n!=0)
      printf("\n");
 }
 getchar();
 return 0;
}
