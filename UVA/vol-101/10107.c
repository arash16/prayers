/*
  >>~~ ACM PROBLEM ~~<<

  ID: 10107
  Name: What is the Median?
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/
#include <math.h>
#include <stdio.h>
int main()
{
  int nums[10005],len=0,n,i,m,c;
  memset(nums,0,sizeof(nums));
  while(scanf("%d",&n)!=-1)
  {
    for(i=0;nums[i]>n;)i++;
    memcpy(&nums[i+1],&nums[i],sizeof(int)*(len-i));
    nums[i]=n;
    c=(int)floor(len/2);
    len++;
    if(len%2==0)
      m=(nums[c]+nums[c+1])/2;
    else
      m=nums[c];
    printf("%d\n",m);
  }
  return 0;
}
