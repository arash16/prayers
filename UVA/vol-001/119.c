/*
  >>~~ ACM PROBLEM ~~<<

  ID: 119
  Name: Greedy Gift Givers
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

struct per {
       char name[15];
       int money;
} persons[10];
int n;
void addmoney(char *name,int money)
{
  int i;
  for(i=0;i<n;i++)
    if(!strcmp(name,persons[i].name))
    {
      persons[i].money+=money;
      break;
    }
}

int main()
{
 int i,j,sum,c,t,p;
 char name[15];
 p=0;
 while (scanf("%d",&n)!=-1)
 {
   if(p++)printf("\n");
   for(i=0;i<n;i++)
   {
     scanf("%s",persons[i].name);
     persons[i].money=0;
   }
   for(j=0;j<n;j++)
   {
       scanf("%s%d%d",&name,&sum,&c);
       if(!c)continue;
       t=(int)(sum/c);
       addmoney(name,-c*t);
       for(i=0;i<c;i++)
       {
         scanf("%s",&name);
         addmoney(name,t);
       }
   }

   for(i=0;i<n;i++)
     printf("%s %d\n",persons[i].name,persons[i].money);
 }
 return 0;
}
