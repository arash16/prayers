/*
  >>~~ ACM PROBLEM ~~<<

  ID: 10106
  Name: Product
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/
char m1[260],m2[260];
int readnum(char n[])
{
  int i;
  memset(n,0,sizeof(n));
  gets(n);
  for(i=0;n[i] && n[i]!='\n';)i++;
  return i;
}
int main()
{
  int r[510];
  int i,j,l1,l2;
  
  l1=readnum(m1);  l2=readnum(m2);
  while(l1 && l2)
  {
    memset(r,0,sizeof(r));
    for(i=0;i<l1;i++)
      for(j=0;j<l2;j++)
        r[j+i]+=(m1[i]-'0')*(m2[j]-'0');
        
    for(i=l1+l2;i>0;i--)
    {
      r[i-1]+=r[i]/10;
      r[i]%=10;
    }
    for(i=0;!r[i];)i++;
    if(i>l1+l2-2)printf("0");
    for(;i<l1+l2-1;i++)
      printf("%d",r[i]);
      printf("\n");
    
    l1=readnum(m1);  l2=readnum(m2);
  }
  
  return 0;
}
