#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{

    string s1,s2;
    cin>>s1>>s2;
    int t[s1.size()+1][s2.size()+1];
    memset(t,0,sizeof(t));

    int m=INT_MIN;
    int cr=0,cc=0;
    for(int i=1;i<s1.size()+1;i++)
    for(int j=1;j<s2.size()+1;j++)
    {
      if(s1[i-1]==s2[j-1])
      t[i][j]=1+t[i-1][j-1];
      else
      t[i][j]=0;
    
      if(t[i][j]>m)
      { 
          cr=i;cc=j;
          m=t[i][j];
      }

    }

   string ans="";
   while(t[cr][cc]!=0)
   {
     ans=ans+s1[cr-1];
     --cr;--cc;
   }

   reverse(ans.begin(),ans.end());
   cout<<ans;

    return 0;
}