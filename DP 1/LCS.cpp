#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
string s1,s2;
cin>>s1>>s2;



int t[s1.size()+1][s2.size()+1];
memset(t,0,sizeof(t));




for(int i=1;i<s1.size()+1;i++)
for(int j=1;j<s2.size()+1;j++)
{
    if(s1[i-1]==s2[j-1])
    t[i][j]=t[i-1][j-1]+1;
    
    else 
    t[i][j]=max(t[i-1][j],t[i][j-1]);    
    
}

cout<<t[s1.size()][s2.size()];
    return 0;
}