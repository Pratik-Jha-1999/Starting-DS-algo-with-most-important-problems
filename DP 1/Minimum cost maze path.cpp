#include<iostream>
using namespace std;

int main()
{
int r,c;
cin>>r>>c;
int maze[r][c];
for(int i=0;i<r;i++)
for(int j=0;j<c;j++)
cin>>maze[i][j];

int t[r][c];

for(int i=r-1;i>=0;i--)
for(int j=c-1;j>=0;j--)
{ 
if(i==r-1&&j==c-1)
t[i][j]=maze[i][j];
else if(i==r-1)
t[i][j]=t[i][j+1]+maze[i][j];
else if(j==c-1)
t[i][j]=t[i+1][j]+maze[i][j];
else 
t[i][j]=maze[i][j]+min(t[i+1][j],t[i][j+1]);
}

cout<<t[0][0] ;
   return 0;
}