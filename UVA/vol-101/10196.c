/*
  >>~~ ACM PROBLEM ~~<<

  ID: 10196
  Name: Check The Check
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

char board[9][9],c;

char check(int x,int y);

int main()
{
 int i,j,exit,n;
 short bkx,bky,wkx,wky;

 n=1;
 while (n)
 {
   exit=0;
   for(i=1;i<=8;i++)
   {
     for(j=1;j<=8;j++)
     {
       board[j][i]=getchar();
       if(board[j][i]=='.')exit++;

       if(board[j][i]=='k')
       {
         bkx=j;bky=i;
       };
       if(board[j][i]=='K')
       {
         wkx=j;wky=i;
       }
     }
     getchar();
   }
   getchar();
   if(exit==64)break;

   if (check(bkx,bky)==1)
     printf("Game #%d: black king is in check.\n",n);
   else if(check(wkx,wky)==1)
     printf("Game #%d: white king is in check.\n",n);
   else
     printf("Game #%d: no king is in check.\n",n);

   n++;
 }
 return 0;
}

char cp(int x,int y)
{
 if(x<1 || x>8 || y<1 || y>8)
   return 0;
 if(board[x][y]==c)
   return 1;
 else
   return 0;
}

char rec(int x,int y,int dx,int dy)
{
  if(x<1 || x>8 || y<1 || y>8)
    return 0;
  if(board[x][y]==c)
    return 1;
  if(board[x][y]!='.')
    return 0;

  if (rec(x+dx,y+dy,dx,dy))
    return 1;
  return 0;
}

char check(int x,int y)
{
  //knight
  if(board[x][y]=='k')c='N';else c='n';
  if(cp(x+1,y+2) || cp(x-1,y+2) || cp(x+1,y-2) || cp(x-1,y-2) ||
     cp(x+2,y+1) || cp(x-2,y+1) || cp(x+2,y-1) || cp(x-2,y-1))
     return 1;

  //Pawn
  if(board[x][y]=='k')
  {
    c='P';
    if(cp(x+1,y+1) || cp(x-1,y+1))
      return 1;
  }
  else
  {
    c='p';
    if(cp(x+1,y-1) || cp(x-1,y-1))
      return 1;
  }

  //Rook
  if(board[x][y]=='k')c='R';else c='r';
  if (rec(x+1,y,1,0) || rec(x-1,y,-1,0) || rec(x,y+1,0,1) || rec(x,y-1,0,-1))
    return 1;

  //Bishop
  if(board[x][y]=='k')c='B';else c='b';
  if (rec(x+1,y+1,1,1)==1  || rec(x-1,y+1,-1,1)==1 ||
      rec(x+1,y-1,1,-1)==1 || rec(x-1,y-1,-1,-1)==1)
    return 1;

  //Queen
  if(board[x][y]=='k')c='Q';else c='q';
  if (rec(x+1,y,1,0) || rec(x-1,y,-1,0) || rec(x,y+1,0,1) || rec(x,y-1,0,-1))
    return 1;
  if (rec(x+1,y+1,1,1)  || rec(x-1,y+1,-1,1) ||
      rec(x+1,y-1,1,-1) || rec(x-1,y-1,-1,-1))
    return 1;

  return 0;
}
