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
 int ans=INT_MIN;
 for(int i=1;i<s1.size()+1;i++)
 for(int j=1;j<s2.size()+1;j++)
 {
     if(s1[i-1]==s2[j-1])
     t[i][j]=t[i-1][j-1]+1;
    
     else
     t[i][j]=0;
     
     ans=max(ans,t[i][j]);
 }
 

cout<<ans;

    return 0;
}