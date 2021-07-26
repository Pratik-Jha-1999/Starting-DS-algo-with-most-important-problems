#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{int n;
cin>>n;
int a[n];

for(int i=0;i<n;i++)
cin>>a[i];

int l=a[0];
int r[n];
r[n-1]=a[n-1];

for(int i=n-2;i>=0;i--)
r[i]=a[i]*r[i+1];

int ans[n];
for(int i=0;i<n;i++)
{
    if(i==0){
    ans[i]=r[i+1];
        l=a[i];
    }
    else if(i==n-1)
    ans[i]=l;
    
    else
    {
        ans[i]=l*r[i+1];
        l=l*a[i];
    }
}
    
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
    
    return 0;
}