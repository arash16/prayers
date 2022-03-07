/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 492
  Name: Pig-Latin
  Problem: https://onlinejudge.org/external/4/492.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

int main()
{
  char word[100],ctr[100],t;
  int i;
  while(scanf("%[a-zA-Z]",&word)!=-1)
  {
    scanf("%[^a-zA-Z]",&ctr);
    t=word[0];
    if(t!='a' && t!='e' && t!='o' && t!='i' && t!='u' &&
       t!='A' && t!='E' && t!='O' && t!='I' && t!='U')
    {
      for(i=1;word[i];i++)
        word[i-1]=word[i];
      word[i-1]=t;
    }
    printf("%say%s",word,ctr);
  }
  return 0;
}
