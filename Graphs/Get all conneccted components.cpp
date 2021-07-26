#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> visited(100);

void find_component(vector<int> g[],int src, vector<int>& psf)
{
visited[src]=1;
psf.push_back(src);
for(int i=0;i<g[src].size();i++)
{
    if(visited[g[src][i]]==0)
    {
        find_component(g,g[src][i],psf);
    }
}
}

int main()
{

int v,e;
cin>>v>>e;
int x,y;
vector<int> graph[v+1];
for(int i=0;i<e;i++)
{
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
    
}

for(int i=1;i<=v;i++)
{
    cout<<i<<"-->";
    for(int j=0;j<graph[i].size();j++)
    cout<<graph[i][j]<<" ";
    cout<<endl;
}
vector<vector<int>> ans;
for(int i=1;i<v+1;i++)
{if(visited[i]==0)
 {
 vector<int> psf;
 find_component(graph, i, psf);
 ans.push_back(psf);
 }
 }
 
for(int i=0;i<ans.size();i++)
{
    for(int j=0;j<ans[i].size();j++)
    cout<<ans[i][j]<<" ";
    cout<<endl;
}
    return 0;
}