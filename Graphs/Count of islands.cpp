#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int visited[100][100];

void drawisland(vector<int> map[],int r,int c,int i,int j)
{
if(i<0||j<0||i>=r||j>=c||visited[i][j]==1||map[i][j]==1)
return ;


visited[i][j]=1;
drawisland(map,r,c,i,j-1);
drawisland(map,r,c,i-1,j);
drawisland(map,r,c,i,j+1);
drawisland(map,r,c,i+1,j);

}


int main()
{
memset(visited,0,sizeof(visited));

int r,c;
cin>>r>>c;
vector<int> map[r];
for(int i=0;i<r;i++)
{vector<int> temp(c);
for(int j=0;j<c;j++)
cin>>temp[j];    

map[i]=temp;
}

int count=0;

for(int i=0;i<r;i++)
for(int j=0;j<c;j++)
{
    if(visited[i][j]==0 && map[i][j]==0)
    {drawisland(map,r,c,i,j);
    count++;
    }
}
cout<<count;

    return 0;
}