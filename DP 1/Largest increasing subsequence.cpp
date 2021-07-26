#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];

int t[n];
t[0]=1;
int ans=1,maxi;
for(int i=1;i<n;i++)
{   
    maxi=INT_MIN;

    for(int j=0;j<i;j++)
    if(a[i]>=a[j])
    { 
        maxi=max(maxi,t[j]);      
    }
    if(maxi==INT_MIN)
    t[i]=1;
    else
    t[i]=maxi+1;
    ans=max(ans,t[i]);
}
if(n!=0)
cout<<ans;
    return 0;
}