#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool ifpath(vector<int> g[],int src,int des,vector<bool> visited)
{
if(src==des)
return true;
visited[src]=true;
for(int i:g[src])
{   if(visited[i]==false)
    if(ifpath(g,i,des,visited))
    return true;
}
return false;
}

int main()
{
int v,e;
cin>>v>>e;
vector<int> graph[v+1];
vector<bool> visited(v+1,false);

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

int src,des;
cin>>src>>des;
bool ans=ifpath(graph,src,des,visited);

cout<<endl<<ans;

    return 0;
}