#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
int v,e;
cin>>v>>e;
vector<int> graph[v+1];

for(int i=0;i<e;i++)
{
int x,y;
cin>>x>>y;
graph[x].push_back(y);
graph[y].push_back(x);
}


for(int j=1;j<=v;j++)
{
    cout<<j<<"-->";
    for(int i=0;i<graph[j].size();i++)
    cout<<graph[j][i]<<" ";
    cout<<endl;
}

    return 0;
}