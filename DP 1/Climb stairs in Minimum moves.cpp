#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
int t[n+1];
t[n]=0;

for(int i=n-1;i>0;i--)
{t[i]=INT_MAX;
for(int j=1;j<=a[i-1];j++)
t[i]=min(t[i+j],t[i]);

if(a[i-1]>0)     //t[i]!= INT_MAX
t[i]++;
}
cout<<t[1];

return 0;
}