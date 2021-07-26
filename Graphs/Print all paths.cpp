#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void printpath(vector<int> g[],int src,int des,vector<bool> visited,vector<int> psf)
{
if(src==des)
{
    for(int i:psf)
    cout<<i<<" ";
    cout<<endl;
return ;
}

visited[src]=true;
for(int i:g[src])
{   if(visited[i]==false)
    {psf.push_back(i);
    printpath(g,i,des,visited,psf);
    psf.pop_back();}
}
visited[src]=false;
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
vector<int> psf;
psf.push_back(src);
printpath(graph,src,des,visited,psf);

    return 0;
}