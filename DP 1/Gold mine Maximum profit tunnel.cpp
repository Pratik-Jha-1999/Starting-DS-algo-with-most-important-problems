#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
int r,c;
cin>>r>>c;
int gm[r][c];
for(int i=0;i<r;i++)
for(int j=0;j<c;j++)
cin>>gm[i][j];

int t[r][c];

for(int i=0;i<r;i++)
t[i][c-1]=gm[i][c-1];

for(int j=c-2;j>=0;j--)
for(int i=0;i<r;i++)
{  
     if(i==0)
     t[i][j]=max(t[i][j+1],t[i+1][j+1])+gm[i][j];

     else if(i==r-1)
      t[i][j]=max(t[i-1][j+1],t[i][j+1])+gm[i][j];

      else {
      t[i][j]=max(max(t[i-1][j+1],t[i][j+1]),t[i+1][j+1])+gm[i][j];
      }

}
int m=t[0][0];
for(int i=1;i<r;i++)
m=max(m,t[i][0]);
cout<<m;


    return 0;
}