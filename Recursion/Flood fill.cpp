#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printpath(vector<vector<int>> maze,int cr,int cc,int fr,int fc,vector<vector<int>> v,string s)
{   
    if(cc<0||cr<0|| cc==fc+1||cr==fr+1||maze[cr][cc]==1||v[cc][cr]==1)
    return ;

    if(cr==fr&&cc==fc)
    {
        cout<<s<<endl;
        return ;
    }

   
   v[cc][cr]=1;
   printpath(maze,cr+1,cc,fr,fc,v,s+'d');
   
   printpath(maze,cr-1,cc,fr,fc,v,s+'t');

   printpath(maze,cr,cc+1,fr,fc,v,s+'r');

   printpath(maze,cr,cc-1,fr,fc,v,s+'l');
   v[cc][cr]=0;

}
int main()
{
int n,m;
cin>>n>>m;

vector<vector<int>> maze(n,vector<int>(m));
vector<vector<int>> v(n,vector<int>(m));;

for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
{cin>>maze[i][j];
v[i][j]=0;
}

printpath(maze,0,0,n-1,m-1,v,"");

    return 0;
}