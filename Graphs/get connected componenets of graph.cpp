#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

vector<int> visited(100);

void components(vector<int> g[],int src, vector<int>& psf)
{
 visited[src]=1;
 psf.push_back(src);

 for(int i=0;i<g[src].size();i++)
 {
     if(visited[g[src][i]]==0)
     components(g,g[src][i],psf);
 }
}


int main()
{


int v,e;
cin>>v>>e;
vector<int> g[v+1];

int x,y;
for(int i=0;i<e;i++)
{
  cin>>x>>y;
  g[x].push_back(y);
  g[y].push_back(x);
}

for(int i=1;i<v+1;i++)
{   cout<<i<<"-->";
    
    for(int j=0;j<g[i].size();j++)
    cout<<g[i][j]<<" ";
    cout<<endl;
}

vector<vector<int>> parts;
for(int i=1;i<v+1;i++)
{   if(visited[i]==0)
   { vector<int> psf;
    components(g,i,psf);
    parts.push_back(psf);}
}



for(int i=0;i<parts.size();i++)
{
    for(int j=0;j<parts[i].size();j++)
    cout<<parts[i][j]<<" ";
    cout<<endl;
}

    return 0;
}