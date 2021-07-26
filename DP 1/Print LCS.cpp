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

for(int i=1;i<s1.size()+1;i++)
for(int j=1;j<s2.size()+1;j++)
{
    if(s1[i-1]==s2[j-1])
    t[i][j]=1+t[i-1][j-1];

    else
    t[i][j]=max(t[i-1][j],t[i][j-1]);

}
string ans;
int i=s1.size(),j=s2.size();
while(i>0||j>0)
{
    if(s1[i-1]==s2[j-1])
    {ans=ans+s1[i-1];
    i--;j--;
    }
    else 
    {
        if(t[i][j-1]>t[i-1][j])
        j--;
        else
        i--;
    }
}

reverse(ans.begin(),ans.end());
cout<<ans;





    return 0;
}